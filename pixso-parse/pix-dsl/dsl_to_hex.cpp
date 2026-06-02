#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <set>
#include <sys/stat.h>

// =============================================================================
// 文件 I/O
// =============================================================================

static std::vector<uint8_t> readFile(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "cannot open: %s\n", path); return {}; }
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> buf(sz);
    fread(buf.data(), 1, sz, f); fclose(f);
    return buf;
}

static bool writeFile(const char *path, const std::vector<uint8_t> &d) {
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write: %s\n", path); return false; }
    fwrite(d.data(), 1, d.size(), f); fclose(f);
    return true;
}

// =============================================================================
// .pix 格式工具
// =============================================================================

static const char   PIX_MAGIC[] = "pixso-kw";
static const uint8_t PIX_VER[2] = {0x00, 0x02};
static const char   PIX_META[]  = "compress:zstd";

static std::vector<uint8_t> compressToPix(const std::vector<uint8_t> &kiwiBin) {
    size_t bound = ZSTD_compressBound(kiwiBin.size());
    std::vector<uint8_t> comp(bound);
    size_t r = ZSTD_compress(comp.data(), bound, kiwiBin.data(), kiwiBin.size(), 3);
    if (ZSTD_isError(r)) { fprintf(stderr, "zstd compress error\n"); return {}; }
    comp.resize(r);

    std::vector<uint8_t> out;
    out.insert(out.end(), PIX_MAGIC, PIX_MAGIC + 8);
    out.push_back(PIX_VER[0]); out.push_back(PIX_VER[1]);
    uint8_t ml = (uint8_t)strlen(PIX_META);
    out.push_back(ml);
    out.insert(out.end(), PIX_META, PIX_META + ml);
    out.insert(out.end(), comp.begin(), comp.end());
    return out;
}

static size_t parsePixHeader(const std::vector<uint8_t> &d) {
    if (d.size() < 12) return 0;
    if (memcmp(d.data(), PIX_MAGIC, 8) != 0) return 0;
    size_t pos = 8 + 2;
    uint8_t metaLen = d[pos++];
    pos += metaLen;
    return (pos < d.size()) ? pos : 0;
}

static std::vector<uint8_t> decompressZstd(const uint8_t *src, size_t sz) {
    unsigned long long cs = ZSTD_getFrameContentSize(src, sz);
    if (cs == ZSTD_CONTENTSIZE_ERROR) { fprintf(stderr, "bad zstd frame\n"); return {}; }
    size_t dstSz = (cs == ZSTD_CONTENTSIZE_UNKNOWN) ? sz * 8 : (size_t)cs;
    std::vector<uint8_t> dst(dstSz);
    size_t r = ZSTD_decompress(dst.data(), dstSz, src, sz);
    if (ZSTD_isError(r)) { fprintf(stderr, "zstd error: %s\n", ZSTD_getErrorName(r)); return {}; }
    dst.resize(r); return dst;
}

static std::string bytesToHex(const std::vector<uint8_t> &d) {
    static const char H[] = "0123456789abcdef";
    std::string r; r.reserve(d.size() * 2);
    for (uint8_t b : d) { r += H[b >> 4]; r += H[b & 0xF]; }
    return r;
}

// =============================================================================
// 组件集加载工具
// =============================================================================

static std::vector<uint8_t> hexToBytes(const std::string &hex) {
    std::vector<uint8_t> out;
    out.reserve(hex.size() / 2);
    for (size_t i = 0; i + 1 < hex.size(); i += 2) {
        auto hv = [](char c) -> uint8_t {
            if (c >= '0' && c <= '9') return (uint8_t)(c - '0');
            if (c >= 'a' && c <= 'f') return (uint8_t)(c - 'a' + 10);
            if (c >= 'A' && c <= 'F') return (uint8_t)(c - 'A' + 10);
            return 0;
        };
        out.push_back((hv(hex[i]) << 4) | hv(hex[i + 1]));
    }
    return out;
}

struct CompSetData {
    kiwi::MemoryPool pool;
    PixsoMsg         msg;
};

static bool loadCompSet(const char *path, CompSetData &cs) {
    auto raw = readFile(path);
    if (raw.empty()) return false;

    std::vector<uint8_t> pixBytes;
    std::string p(path);
    if (p.size() >= 4 && p.substr(p.size() - 4) == ".txt") {
        std::string hex;
        hex.reserve(raw.size());
        bool inComment = false;
        for (uint8_t c : raw) {
            if (c == '#' || c == '<') { inComment = true; continue; }
            if (c == '\n')            { inComment = false; continue; }
            if (inComment) continue;
            if ((c >= '0' && c <= '9') ||
                (c >= 'a' && c <= 'f') ||
                (c >= 'A' && c <= 'F'))
                hex += (char)c;
        }
        pixBytes = hexToBytes(hex);
    } else {
        pixBytes = std::move(raw);
    }

    size_t off = parsePixHeader(pixBytes);
    if (!off) { fprintf(stderr, "  [ERROR] %s: bad pix header\n", path); return false; }

    auto dec = decompressZstd(pixBytes.data() + off, pixBytes.size() - off);
    if (dec.empty()) { fprintf(stderr, "  [ERROR] %s: decompress failed\n", path); return false; }

    kiwi::ByteBuffer bb(dec.data(), dec.size());
    if (!cs.msg.decode(bb, cs.pool)) {
        fprintf(stderr, "  [ERROR] %s: kiwi decode failed\n", path);
        return false;
    }
    return true;
}

// =============================================================================
// 简单 JSON 解析器（递归下降）
// =============================================================================

struct JVal {
    enum Type { Null, Bool, Int, Dbl, Str, Arr, Obj } type = Null;
    bool        b   = false;
    int64_t     i   = 0;
    double      d   = 0.0;
    std::string s;
    std::vector<JVal>              arr;
    std::vector<std::pair<std::string, JVal>> obj;  // 保序

    bool isNull() const { return type == Null; }
    bool asBool() const { return type==Bool ? b : (type==Int ? i!=0 : false); }
    double asDouble() const { return type==Dbl ? d : (type==Int ? (double)i : 0.0); }
    float  asFloat()  const { return (float)asDouble(); }
    const std::string& asStr() const { static std::string e; return type==Str ? s : e; }

    bool has(const std::string &k) const {
        if (type != Obj) return false;
        for (auto &kv : obj) if (kv.first == k) return true;
        return false;
    }
    const JVal& get(const std::string &k) const {
        static JVal e;
        if (type != Obj) return e;
        for (auto &kv : obj) if (kv.first == k) return kv.second;
        return e;
    }
    size_t size() const { return type==Arr ? arr.size() : 0; }
    const JVal& operator[](size_t idx) const {
        static JVal e;
        return (type==Arr && idx < arr.size()) ? arr[idx] : e;
    }
};

struct JsonParser {
    const char *p, *e;
    JsonParser(const char *data, size_t len) : p(data), e(data + len) {}

    void ws() { while (p < e && ((uint8_t)*p <= 32)) p++; }

    JVal parse() {
        ws();
        if (p >= e) return {};
        switch (*p) {
            case '{': return parseObj();
            case '[': return parseArr();
            case '"': return parseStr();
            case 't': { p += 4; JVal v; v.type=JVal::Bool; v.b=true;  return v; }
            case 'f': { p += 5; JVal v; v.type=JVal::Bool; v.b=false; return v; }
            case 'n': { p += 4; return {}; }
            default:  return parseNum();
        }
    }

    JVal parseObj() {
        JVal v; v.type = JVal::Obj;
        p++; ws();
        while (p < e && *p != '}') {
            JVal key = parseStr(); ws();
            if (p < e && *p == ':') p++; ws();
            JVal val = parse();
            v.obj.emplace_back(key.s, std::move(val));
            ws();
            if (p < e && *p == ',') { p++; ws(); }
        }
        if (p < e) p++;
        return v;
    }

    JVal parseArr() {
        JVal v; v.type = JVal::Arr;
        p++; ws();
        while (p < e && *p != ']') {
            v.arr.push_back(parse()); ws();
            if (p < e && *p == ',') { p++; ws(); }
        }
        if (p < e) p++;
        return v;
    }

    JVal parseStr() {
        JVal v; v.type = JVal::Str;
        p++;  // skip '"'
        while (p < e && *p != '"') {
            if (*p == '\\' && p + 1 < e) {
                p++;
                switch (*p) {
                    case '"':  v.s += '"';  break;
                    case '\\': v.s += '\\'; break;
                    case '/':  v.s += '/';  break;
                    case 'n':  v.s += '\n'; break;
                    case 't':  v.s += '\t'; break;
                    case 'r':  v.s += '\r'; break;
                    default:   v.s += *p;   break;
                }
            } else {
                v.s += *p;
            }
            p++;
        }
        if (p < e) p++;  // skip '"'
        return v;
    }

    JVal parseNum() {
        const char *start = p;
        bool isFloat = false;
        if (p < e && (*p == '-' || *p == '+')) p++;
        while (p < e && *p >= '0' && *p <= '9') p++;
        if (p < e && *p == '.') {
            isFloat = true; p++;
            while (p < e && *p >= '0' && *p <= '9') p++;
        }
        if (p < e && (*p == 'e' || *p == 'E')) {
            isFloat = true; p++;
            if (p < e && (*p == '+' || *p == '-')) p++;
            while (p < e && *p >= '0' && *p <= '9') p++;
        }
        std::string ns(start, p - start);
        JVal v;
        if (isFloat) { v.type = JVal::Dbl; v.d = std::stod(ns); }
        else         { v.type = JVal::Int; v.i = std::stoll(ns); }
        return v;
    }
};

// =============================================================================
// DSL 数据结构
// =============================================================================

struct DslBox { float x=0, y=0, w=0, h=0; };

struct DslFill {
    std::string type    = "solid";
    std::string color   = "#000000FF";
    float       opacity = 1.0f;
    bool        visible = true;
};

struct DslLayer {
    std::string id, name, type;
    bool        visible     = true;
    float       opacity     = 1.0f;
    std::string blendMode   = "normal";
    DslBox      box;
    float       cornerRadius = 0.0f;
    std::vector<DslFill>  fills;
    std::vector<DslLayer> children;
    // instance 字段（type=="instance" 时有效）
    std::string symbolId, variantKey, componentSetKey;
    // text 字段（type=="text" 时有效）
    std::string textContent;
    std::string textFontFamily = "PingFang SC";
    std::string textFontStyle  = "Regular";
    float       textFontSize   = 14.0f;
    std::string textColor      = "#0F172AFF";
};

struct DslPage { std::string id, name; std::vector<DslLayer> layers; };
struct DslDoc  { std::vector<DslPage> pages; };

// =============================================================================
// DSL JSON 解析
// =============================================================================

static DslFill parseFill(const JVal &j) {
    DslFill f;
    if (j.has("type"))    f.type    = j.get("type").asStr();
    if (j.has("color"))   f.color   = j.get("color").asStr();
    if (j.has("opacity")) f.opacity = j.get("opacity").asFloat();
    if (j.has("visible")) f.visible = j.get("visible").asBool();
    return f;
}

static DslLayer parseLayer(const JVal &j) {
    DslLayer l;
    if (j.has("id"))            l.id           = j.get("id").asStr();
    if (j.has("name"))          l.name         = j.get("name").asStr();
    if (j.has("type"))          l.type         = j.get("type").asStr();
    if (j.has("visible"))       l.visible      = j.get("visible").asBool();
    if (j.has("opacity"))       l.opacity      = j.get("opacity").asFloat();
    if (j.has("blend_mode"))    l.blendMode    = j.get("blend_mode").asStr();
    if (j.has("corner_radius")) l.cornerRadius = j.get("corner_radius").asFloat();

    if (j.has("box")) {
        const JVal &b = j.get("box");
        l.box = { b.get("x").asFloat(), b.get("y").asFloat(),
                  b.get("width").asFloat(), b.get("height").asFloat() };
    }
    if (j.has("fills")) {
        const JVal &fills = j.get("fills");
        for (size_t i = 0; i < fills.size(); i++)
            l.fills.push_back(parseFill(fills[i]));
    }
    if (j.has("children")) {
        const JVal &children = j.get("children");
        for (size_t i = 0; i < children.size(); i++)
            l.children.push_back(parseLayer(children[i]));
    }
    if (j.has("instance")) {
        const JVal &inst = j.get("instance");
        if (inst.has("symbol_id"))         l.symbolId        = inst.get("symbol_id").asStr();
        if (inst.has("variant_key"))        l.variantKey      = inst.get("variant_key").asStr();
        if (inst.has("component_set_key"))  l.componentSetKey = inst.get("component_set_key").asStr();
    }
    if (j.has("text_content")) l.textContent = j.get("text_content").asStr();
    if (j.has("text_style")) {
        const JVal &ts = j.get("text_style");
        if (ts.has("font_family")) l.textFontFamily = ts.get("font_family").asStr();
        if (ts.has("font_style"))  l.textFontStyle  = ts.get("font_style").asStr();
        if (ts.has("font_size"))   l.textFontSize   = ts.get("font_size").asFloat();
        if (ts.has("color"))       l.textColor      = ts.get("color").asStr();
    }
    return l;
}

static DslDoc parseDoc(const JVal &j) {
    DslDoc doc;
    if (!j.has("pages")) return doc;
    const JVal &pages = j.get("pages");
    for (size_t i = 0; i < pages.size(); i++) {
        const JVal &pj = pages[i];
        DslPage page;
        if (pj.has("id"))   page.id   = pj.get("id").asStr();
        if (pj.has("name")) page.name = pj.get("name").asStr();
        if (pj.has("layers")) {
            const JVal &layers = pj.get("layers");
            for (size_t k = 0; k < layers.size(); k++)
                page.layers.push_back(parseLayer(layers[k]));
        }
        doc.pages.push_back(std::move(page));
    }
    return doc;
}

// =============================================================================
// GUID / ParentIndex 构造辅助
// =============================================================================

struct GK { uint32_t s = 0, l = 0; };

static GK parseGK(const std::string &id) {
    auto pos = id.find(':');
    if (pos == std::string::npos) return {};
    try {
        return { (uint32_t)std::stoul(id.substr(0, pos)),
                 (uint32_t)std::stoul(id.substr(pos + 1)) };
    } catch (...) { return {}; }
}

static GUID* makeGUID(kiwi::MemoryPool &pool, uint32_t s, uint32_t l) {
    GUID *g = pool.allocate<GUID>(); new(g) GUID();
    g->set_sessionID(s); g->set_localID(l);
    return g;
}

static ParentIndex* makeParent(kiwi::MemoryPool &pool,
                                uint32_t ps, uint32_t pl,
                                const std::string &pos) {
    ParentIndex *pi = pool.allocate<ParentIndex>(); new(pi) ParentIndex();
    pi->set_guid(makeGUID(pool, ps, pl));
    pi->set_position(pool.string(pos.c_str()));
    return pi;
}

// 生成子节点位置字符串，保证字典序与插入序一致
static std::string makePos(int idx) {
    char buf[16]; snprintf(buf, sizeof(buf), "a%08x", (unsigned)idx);
    return buf;
}

// =============================================================================
// 类型映射
// =============================================================================

static NodeType mapLayerType(const std::string &t) {
    if (t == "frame")     return NodeType::FRAME;
    if (t == "group")     return NodeType::GROUP;
    if (t == "rectangle") return NodeType::RECTANGLE;
    if (t == "ellipse")   return NodeType::ELLIPSE;
    if (t == "vector")    return NodeType::VECTOR;
    if (t == "star")      return NodeType::STAR;
    if (t == "line")      return NodeType::LINE;
    if (t == "boolean")   return NodeType::BOOLEAN_OPERATION;
    if (t == "text")      return NodeType::TEXT;
    if (t == "instance")  return NodeType::INSTANCE;
    return NodeType::RECTANGLE;
}

static BlendMode mapBlendMode(const std::string &s) {
    if (s == "normal")      return BlendMode::NORMAL;
    if (s == "multiply")    return BlendMode::MULTIPLY;
    if (s == "screen")      return BlendMode::SCREEN;
    if (s == "overlay")     return BlendMode::OVERLAY;
    if (s == "darken")      return BlendMode::DARKEN;
    if (s == "lighten")     return BlendMode::LIGHTEN;
    if (s == "color_dodge") return BlendMode::COLOR_DODGE;
    if (s == "color_burn")  return BlendMode::COLOR_BURN;
    if (s == "hard_light")  return BlendMode::HARD_LIGHT;
    if (s == "soft_light")  return BlendMode::SOFT_LIGHT;
    if (s == "difference")  return BlendMode::DIFFERENCE;
    if (s == "exclusion")   return BlendMode::EXCLUSION;
    if (s == "hue")         return BlendMode::HUE;
    if (s == "saturation")  return BlendMode::SATURATION;
    if (s == "color")       return BlendMode::COLOR;
    if (s == "luminosity")  return BlendMode::LUMINOSITY;
    return BlendMode::NORMAL;
}

// =============================================================================
// 颜色解析 "#RRGGBBAA"
// =============================================================================

static Color* parseColor(kiwi::MemoryPool &pool, const std::string &hex) {
    if (hex.empty() || hex[0] != '#') return nullptr;
    auto hv = [](char c) -> uint8_t {
        if (c >= '0' && c <= '9') return (uint8_t)(c - '0');
        if (c >= 'a' && c <= 'f') return (uint8_t)(c - 'a' + 10);
        if (c >= 'A' && c <= 'F') return (uint8_t)(c - 'A' + 10);
        return 0;
    };
    uint8_t r=0, g=0, b=0, a=255;
    if (hex.size() >= 7) {
        r = hv(hex[1])*16 + hv(hex[2]);
        g = hv(hex[3])*16 + hv(hex[4]);
        b = hv(hex[5])*16 + hv(hex[6]);
    }
    if (hex.size() >= 9) a = hv(hex[7])*16 + hv(hex[8]);

    Color *c = pool.allocate<Color>(); new(c) Color();
    // Pixso 的 Color 通道范围是 [0, 255]，不是 [0, 1]
    c->set_r((float)r);
    c->set_g((float)g);
    c->set_b((float)b);
    c->set_a((float)a);
    return c;
}

// =============================================================================
// 节点数量统计（用于预分配数组）
// =============================================================================

static uint32_t countLayerNodes(const DslLayer &layer) {
    if (layer.type == "instance") return 1;
    uint32_t n = 1;
    for (auto &child : layer.children) n += countLayerNodes(child);
    return n;
}

static uint32_t countTotal(const DslDoc &doc, uint32_t compNodeCount = 0) {
    uint32_t n = (uint32_t)doc.pages.size(); // 每个 page 对应一个可见 CANVAS
    n += 1;                                  // 隐藏 CANVAS {0,2}
    for (auto &page : doc.pages)
        for (auto &layer : page.layers)
            n += countLayerNodes(layer);
    n += compNodeCount;                      // 组件集全量节点
    return n;
}

// =============================================================================
// SymbolMap + derivedSymbolData 计数
// =============================================================================

// GUID → (CompSetData*, PixsoNode*) 的查找表，用于定位 DSL INSTANCE 引用的 SYMBOL
using SymbolMap     = std::map<std::string, std::pair<CompSetData*, const PixsoNode*>>;
// GUID → 直接子节点列表（在一个 CompSetData 内部）
using ChildrenMap   = std::map<std::string, std::vector<const PixsoNode*>>;

static std::string gkStr(uint32_t s, uint32_t l) {
    return std::to_string(s) + ":" + std::to_string(l);
}

static ChildrenMap buildChildrenMap(const CompSetData &cs) {
    ChildrenMap m;
    auto *nodes = cs.msg.pixsoNodes();
    if (!nodes) return m;
    for (uint32_t i = 0; i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        auto *pi = n.parentIndex();
        if (!pi || !pi->guid()) continue;
        uint32_t ps = pi->guid()->sessionID() ? *pi->guid()->sessionID() : 0;
        uint32_t pl = pi->guid()->localID()   ? *pi->guid()->localID()   : 0;
        m[gkStr(ps, pl)].push_back(&n);
    }
    return m;
}

// 递归计算 derivedSymbolData 数组大小：
//   - 非 INSTANCE 子节点: 1 + recurse(children)
//   - INSTANCE 子节点: 1 + 该节点已有的 derivedSymbolData.size()（来自组件库原始数据）
static uint32_t computeDerivedCount(const PixsoNode &node,
                                     const ChildrenMap &cm) {
    if (!node.guid()) return 0;
    uint32_t s = node.guid()->sessionID() ? *node.guid()->sessionID() : 0;
    uint32_t l = node.guid()->localID()   ? *node.guid()->localID()   : 0;
    auto it = cm.find(gkStr(s, l));
    if (it == cm.end()) return 0;

    uint32_t count = 0;
    for (const PixsoNode *child : it->second) {
        count++;  // 计入子节点本身
        uint32_t t = child->type() ? (uint32_t)*child->type() : 0;
        if (t == 17 /* INSTANCE */) {
            // 用组件库里该 INSTANCE 已有的 derivedCount（不再递归展开）
            count += child->derivedSymbolData()
                     ? (uint32_t)child->derivedSymbolData()->size() : 0;
        } else {
            // 普通节点递归统计子节点
            count += computeDerivedCount(*child, cm);
        }
    }
    return count;
}

// =============================================================================
// DSL 图层 → PixsoNode（直接写入预分配数组的槽位）
// =============================================================================
// 注意：pool 持有所有 Matrix/Vector/ParentIndex/Color 等指针对象的内存，
//       arr[idx] 是 pool 内的 PixsoNode，其指针字段指向同一个 pool，
//       只要 pool 生命周期覆盖 encode 过程，数据就不会失效。

static void fillLayerNode(kiwi::MemoryPool &pool,
                          kiwi::Array<PixsoNode> &arr,
                          uint32_t &idx,
                          const DslLayer &layer,
                          uint32_t parentS, uint32_t parentL,
                          int childPos,
                          const SymbolMap &symMap,
                          const std::map<CompSetData*, ChildrenMap> &childMaps) {
    if (layer.type == "instance") {
        if (layer.symbolId.empty()) {
            fprintf(stderr, "  [WARN] INSTANCE \"%s\" (%s) symbol_id 为空，跳过\n",
                    layer.name.c_str(), layer.id.c_str());
            return;
        }
        auto gk  = parseGK(layer.id);
        auto sgk = parseGK(layer.symbolId);
        PixsoNode &n = arr[idx++];

        n.set_type(NodeType::INSTANCE);
        n.set_phase(NodePhase::CREATED);
        n.set_guid(makeGUID(pool, gk.s, gk.l));
        n.set_name(pool.string(layer.name.c_str()));
        n.set_parentIndex(makeParent(pool, parentS, parentL, makePos(childPos)));

        Matrix *mat = pool.allocate<Matrix>(); new(mat) Matrix();
        mat->set_m00(1.f); mat->set_m01(0.f); mat->set_m02(layer.box.x);
        mat->set_m10(0.f); mat->set_m11(1.f); mat->set_m12(layer.box.y);
        n.set_transform(mat);

        // 尺寸优先使用 SYMBOL 本身的 size，DSL box 的 width/height 仅作兜底
        float sizeW = layer.box.w, sizeH = layer.box.h;
        {
            auto smSz = symMap.find(layer.symbolId);
            if (smSz != symMap.end()) {
                const PixsoNode *sym = smSz->second.second;
                if (sym->size()) {
                    if (sym->size()->x()) sizeW = *sym->size()->x();
                    if (sym->size()->y()) sizeH = *sym->size()->y();
                }
            }
        }
        Vector *sz = pool.allocate<Vector>(); new(sz) Vector();
        sz->set_x(sizeW); sz->set_y(sizeH);
        n.set_size(sz);

        SymbolData *sd = pool.allocate<SymbolData>(); new(sd) SymbolData();
        sd->set_symbolID(makeGUID(pool, sgk.s, sgk.l));
        n.set_symbolData(sd);

        // derivedSymbolData：全空槽位（无覆写），数量由 SYMBOL 子树结构决定
        auto smIt = symMap.find(layer.symbolId);
        if (smIt != symMap.end()) {
            CompSetData *csData = smIt->second.first;
            const PixsoNode *symNode = smIt->second.second;
            auto cmIt = childMaps.find(csData);
            if (cmIt != childMaps.end()) {
                uint32_t cnt = computeDerivedCount(*symNode, cmIt->second);
                if (cnt > 0) {
                    n.set_derivedSymbolData(pool, cnt);
                    // 各槽位保持 kiwi 默认空值，表示无覆写
                }
            }
        }
        return;
    }

    auto gk = parseGK(layer.id);
    PixsoNode &n = arr[idx++];

    n.set_type(mapLayerType(layer.type));
    n.set_phase(NodePhase::CREATED);
    n.set_guid(makeGUID(pool, gk.s, gk.l));
    n.set_name(pool.string(layer.name.c_str()));
    n.set_visible(layer.visible);
    n.set_opacity(layer.opacity);
    n.set_blendMode(mapBlendMode(layer.blendMode));
    n.set_parentIndex(makeParent(pool, parentS, parentL, makePos(childPos)));

    // 位置变换矩阵（平移到 box.x, box.y）
    Matrix *mat = pool.allocate<Matrix>(); new(mat) Matrix();
    mat->set_m00(1.f); mat->set_m01(0.f); mat->set_m02(layer.box.x);
    mat->set_m10(0.f); mat->set_m11(1.f); mat->set_m12(layer.box.y);
    n.set_transform(mat);

    // 尺寸
    Vector *sz = pool.allocate<Vector>(); new(sz) Vector();
    sz->set_x(layer.box.w); sz->set_y(layer.box.h);
    n.set_size(sz);

    if (layer.cornerRadius != 0.0f)
        n.set_cornerRadius(layer.cornerRadius);

    // 填充（非 text 节点，text 颜色由下方单独处理）
    if (!layer.fills.empty()) {
        auto &paints = n.set_fillPaints(pool, (uint32_t)layer.fills.size());
        for (size_t i = 0; i < layer.fills.size(); i++) {
            const DslFill &f = layer.fills[i];
            Paint &p = paints[i];
            PaintType pt = PaintType::SOLID;
            if      (f.type == "gradient_linear") pt = PaintType::GRADIENT_LINEAR;
            else if (f.type == "gradient_radial")  pt = PaintType::GRADIENT_RADIAL;
            else if (f.type == "image")            pt = PaintType::IMAGE;
            p.set_type(pt);
            p.set_visible(f.visible);
            p.set_opacity(f.opacity);
            p.set_blendMode(BlendMode::NORMAL);
            if (!f.color.empty()) {
                Color *c = parseColor(pool, f.color);
                if (c) p.set_color(c);
            }
        }
    }

    // TEXT 节点：字体 + 文字颜色 + textData
    if (layer.type == "text") {
        // fontName on node
        FontName *fn = pool.allocate<FontName>(); new(fn) FontName();
        fn->set_family(pool.string(layer.textFontFamily.c_str()));
        fn->set_style(pool.string(layer.textFontStyle.c_str()));
        fn->set_postscript(pool.string(""));
        n.set_fontName(fn);

        // fontSize on node
        n.set_fontSize(layer.textFontSize);

        // 文字颜色 → fillPaints（与图层填充相同字段）
        if (!layer.textColor.empty()) {
            Color *tc = parseColor(pool, layer.textColor);
            if (tc) {
                auto &fp = n.set_fillPaints(pool, 1);
                fp[0].set_type(PaintType::SOLID);
                fp[0].set_visible(true);
                fp[0].set_opacity(1.0f);
                fp[0].set_blendMode(BlendMode::NORMAL);
                fp[0].set_color(tc);
            }
        }

        // textData：characters + characterStyleIDs + styleOverrideTable
        if (!layer.textContent.empty()) {
            TextData *td = pool.allocate<TextData>(); new(td) TextData();
            td->set_characters(pool.string(layer.textContent.c_str()));

            // 统计 Unicode codepoint 数（UTF-8 解码）
            uint32_t charCount = 0;
            const uint8_t *sp = (const uint8_t*)layer.textContent.c_str();
            size_t slen = layer.textContent.size();
            for (size_t bi = 0; bi < slen; ) {
                uint8_t c = sp[bi];
                if      (c < 0x80)           bi += 1;
                else if ((c & 0xE0) == 0xC0) bi += 2;
                else if ((c & 0xF0) == 0xE0) bi += 3;
                else                         bi += 4;
                charCount++;
            }
            if (charCount > 0) {
                auto &ids = td->set_characterStyleIDs(pool, charCount);
                for (uint32_t i = 0; i < charCount; i++) ids[i] = 0;
            }

            // styleOverrideTable[0]：字号 + 字体 + 文字颜色
            auto &table = td->set_styleOverrideTable(pool, 1);
            TextStyleData &tsd = table[0];
            tsd.set_styleID(0);
            tsd.set_fontSize(layer.textFontSize);

            FontName *fn2 = pool.allocate<FontName>(); new(fn2) FontName();
            fn2->set_family(pool.string(layer.textFontFamily.c_str()));
            fn2->set_style(pool.string(layer.textFontStyle.c_str()));
            fn2->set_postscript(pool.string(""));
            tsd.set_fontName(fn2);

            Color *tc2 = parseColor(pool, layer.textColor);
            if (tc2) {
                auto &fp2 = tsd.set_fillPaints(pool, 1);
                fp2[0].set_type(PaintType::SOLID);
                fp2[0].set_visible(true);
                fp2[0].set_opacity(1.0f);
                fp2[0].set_blendMode(BlendMode::NORMAL);
                fp2[0].set_color(tc2);
            }

            n.set_textData(td);
        }
        // TODO: text_style.align_h / align_v → TextAlignHorizontal / TextAlignVertical
        // TODO: text_style.letter_spacing → TextStyleData::set_letterSpacing
        // TODO: text_style.line_height    → TextStyleData::set_lineHeight
    }

    // 递归子节点
    for (size_t i = 0; i < layer.children.size(); i++)
        fillLayerNode(pool, arr, idx, layer.children[i], gk.s, gk.l, (int)i,
                      symMap, childMaps);
}

// =============================================================================
// 目录检测 + 组件 key 收集
// =============================================================================

static bool isDirectory(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISDIR(st.st_mode);
}

static void collectCompSetKeys(const DslLayer &layer, std::set<std::string> &keys) {
    if (layer.type == "instance" && !layer.componentSetKey.empty())
        keys.insert(layer.componentSetKey);
    for (auto &child : layer.children)
        collectCompSetKeys(child, keys);
}

// =============================================================================
// Blob 辅助：收集 / 重映射（与 pix-split 保持一致）
// =============================================================================

static void collectBlobsFromNode(const PixsoNode &n, std::set<int32_t> &out) {
    auto addPaths = [&](const kiwi::Array<Path> *arr) {
        if (!arr) return;
        for (uint32_t i = 0; i < arr->size(); i++)
            if ((*arr)[i].blobIndex()) out.insert(*(*arr)[i].blobIndex());
    };
    addPaths(n.fillGeometry());
    addPaths(n.strokeGeometry());
    if (n.vectorData() && n.vectorData()->vectorNetworkBlob())
        out.insert(*n.vectorData()->vectorNetworkBlob());
    if (n.textData() && n.textData()->glyphs()) {
        const auto *g = n.textData()->glyphs();
        for (uint32_t i = 0; i < g->size(); i++)
            if ((*g)[i].blobIndex()) out.insert(*(*g)[i].blobIndex());
    }
    if (n.symbolData() && n.symbolData()->symbolOverrides()) {
        const auto *ov = n.symbolData()->symbolOverrides();
        for (uint32_t i = 0; i < ov->size(); i++) collectBlobsFromNode((*ov)[i], out);
    }
    if (n.derivedSymbolData()) {
        const auto *ds = n.derivedSymbolData();
        for (uint32_t i = 0; i < ds->size(); i++) collectBlobsFromNode((*ds)[i], out);
    }
}

static void remapBlobsInNode(PixsoNode &n, const std::map<int32_t, int32_t> &remap) {
    if (remap.empty()) return;
    auto fixPaths = [&](kiwi::Array<Path> *arr) {
        if (!arr) return;
        for (uint32_t i = 0; i < arr->size(); i++) {
            Path &p = (*arr)[i];
            if (p.blobIndex()) {
                auto it = remap.find(*p.blobIndex());
                if (it != remap.end()) p.set_blobIndex(it->second);
            }
        }
    };
    fixPaths(n.fillGeometry());
    fixPaths(n.strokeGeometry());
    if (n.vectorData() && n.vectorData()->vectorNetworkBlob()) {
        auto it = remap.find(*n.vectorData()->vectorNetworkBlob());
        if (it != remap.end()) n.vectorData()->set_vectorNetworkBlob(it->second);
    }
    if (n.textData() && n.textData()->glyphs()) {
        auto *g = n.textData()->glyphs();
        for (uint32_t i = 0; i < g->size(); i++) {
            Glyph &gl = (*g)[i];
            if (gl.blobIndex()) {
                auto it = remap.find(*gl.blobIndex());
                if (it != remap.end()) gl.set_blobIndex(it->second);
            }
        }
    }
    if (n.symbolData() && n.symbolData()->symbolOverrides()) {
        auto *ov = n.symbolData()->symbolOverrides();
        for (uint32_t i = 0; i < ov->size(); i++) remapBlobsInNode((*ov)[i], remap);
    }
    if (n.derivedSymbolData()) {
        auto *ds = n.derivedSymbolData();
        for (uint32_t i = 0; i < ds->size(); i++) remapBlobsInNode((*ds)[i], remap);
    }
}

// =============================================================================
// 构建完整 PixsoMsg
//
// 节点顺序：
//   [0]  CANVAS {0,1}  ← 可见页（每个 DSL page 一个，GUID 依次为 {0,1},{0,3},{0,4}...）
//   [1+] 该 page 下的所有图层节点（DFS 前序）
//   [n]  CANVAS {0,2}  ← 隐藏页（internalOnly=true）
//   [n+] 组件集全量节点
// =============================================================================

static std::vector<uint8_t> buildMsg(
        kiwi::MemoryPool &pool,
        const DslDoc &doc,
        std::vector<std::unique_ptr<CompSetData>> &compSets) {

    // 统计所有组件集节点总数（全局 GUID 去重，与写入逻辑保持一致）
    uint32_t compNodeCount = 0;
    {
        std::set<std::string> seenGuids;
        for (auto &cs : compSets) {
            auto *nodes = cs->msg.pixsoNodes();
            if (!nodes) continue;
            for (uint32_t i = 0; i < nodes->size(); i++) {
                const PixsoNode &n = (*nodes)[i];
                uint32_t s = (n.guid() && n.guid()->sessionID()) ? *n.guid()->sessionID() : 0;
                uint32_t l = (n.guid() && n.guid()->localID())   ? *n.guid()->localID()   : 0;
                if (seenGuids.insert(gkStr(s, l)).second) compNodeCount++;
            }
        }
    }

    uint32_t total = countTotal(doc, compNodeCount);

    // 构建 SymbolMap 和各 CompSetData 的 ChildrenMap
    SymbolMap symMap;
    std::map<CompSetData*, ChildrenMap> childMaps;
    for (auto &cs : compSets) {
        childMaps[cs.get()] = buildChildrenMap(*cs);
        auto *nodes = cs->msg.pixsoNodes();
        if (!nodes) continue;
        for (uint32_t i = 0; i < nodes->size(); i++) {
            const PixsoNode &n = (*nodes)[i];
            if (!n.type() || *n.type() != NodeType::SYMBOL || !n.guid()) continue;
            uint32_t s = n.guid()->sessionID() ? *n.guid()->sessionID() : 0;
            uint32_t l = n.guid()->localID()   ? *n.guid()->localID()   : 0;
            symMap[gkStr(s, l)] = {cs.get(), &n};
        }
    }

    PixsoMsg out;
    out.set_type(PixsoMsgType::FIC_DOCUMENT);
    auto &arr = out.set_pixsoNodes(pool, total);
    uint32_t idx = 0;

    // ── 合并 blobs（顺序拼接，不去重）+ 建每个 CompSetData 的下标重映射表 ──
    // 每个 CompSet 的 blob 按顺序追加到 mergedBlobs，
    // 用起始偏移量建立 oldIdx → newIdx 映射，保证 blobIndex 准确。
    std::vector<std::vector<uint8_t>>               mergedBlobs;
    std::map<CompSetData*, std::map<int32_t,int32_t>> blobRemaps;

    for (auto &cs : compSets) {
        auto *blobs = cs->msg.blobs();
        if (!blobs || blobs->size() == 0) continue;
        auto &remap = blobRemaps[cs.get()];
        int32_t offset = (int32_t)mergedBlobs.size();
        for (uint32_t i = 0; i < blobs->size(); i++) {
            remap[(int32_t)i] = offset + (int32_t)i;
            const auto *bytes = (*blobs)[i].bytes();
            if (bytes && bytes->size() > 0) {
                mergedBlobs.push_back(
                    std::vector<uint8_t>(&(*bytes)[0], &(*bytes)[0] + bytes->size()));
            } else {
                mergedBlobs.push_back({});   // 保留空槽，维持下标对齐
            }
        }
    }

    // 将合并后的 blobs 写入输出 PixsoMsg
    if (!mergedBlobs.empty()) {
        auto &outBlobs = out.set_blobs(pool, (uint32_t)mergedBlobs.size());
        for (size_t i = 0; i < mergedBlobs.size(); i++) {
            if (!mergedBlobs[i].empty()) {
                auto &dstB = outBlobs[i].set_bytes(pool, (uint32_t)mergedBlobs[i].size());
                for (size_t j = 0; j < mergedBlobs[i].size(); j++)
                    dstB[j] = mergedBlobs[i][j];
            }
            // 空槽：不调用 set_bytes，保留默认值
        }
        printf("  merged blobs: %zu 条（顺序合并，不去重）\n", mergedBlobs.size());
    }

    // ── 可见 CANVAS + 图层（每个 DSL page）──────────────────────────────────
    // CANVAS GUID 固定为 {0,1},{0,3},{0,4},... 跳过 {0,2}（隐藏页专用）
    for (size_t pi = 0; pi < doc.pages.size(); pi++) {
        const DslPage &page = doc.pages[pi];
        uint32_t canvasL = (pi == 0) ? 1u : (uint32_t)(pi + 2);

        PixsoNode &cv = arr[idx++];
        cv.set_type(NodeType::CANVAS);
        cv.set_phase(NodePhase::CREATED);
        cv.set_guid(makeGUID(pool, 0, canvasL));
        cv.set_name(pool.string(page.name.c_str()));
        cv.set_parentIndex(makeParent(pool, 0, 0, "!"));

        for (size_t li = 0; li < page.layers.size(); li++)
            fillLayerNode(pool, arr, idx, page.layers[li], 0, canvasL, (int)li,
                          symMap, childMaps);
    }

    // ── 隐藏 CANVAS {0,2}（供组件库节点挂载，internalOnly=true）──────────
    {
        PixsoNode &hv = arr[idx++];
        hv.set_type(NodeType::CANVAS);
        hv.set_phase(NodePhase::CREATED);
        hv.set_guid(makeGUID(pool, 0, 2));
        hv.set_name(pool.string("Internal Only Canvas"));
        hv.set_internalOnly(true);
        hv.set_parentIndex(makeParent(pool, 0, 0, "~"));
    }

    // ── 组件集全量节点（parent 不在集合内的根节点改挂到 {0,2}）───────────
    // writtenGuids: 全局跨组件集的 GUID 去重集合。
    // 多个组件集可能内嵌同一份子组件（如 3.Icon Button），导致相同 GUID 重复出现；
    // 重复节点的 blobIndex 会被映射到错误偏移范围，造成渲染异常，故只写第一次出现的版本。
    std::set<std::string> writtenGuids;

    for (auto &cs : compSets) {
        auto *nodes = cs->msg.pixsoNodes();
        if (!nodes) continue;
        uint32_t N = nodes->size();

        // 收集本组件集所有 GUID（含未去重的全量），用于判断孤根
        std::set<std::pair<uint32_t, uint32_t>> guidSet;
        for (uint32_t i = 0; i < N; i++) {
            const PixsoNode &n = (*nodes)[i];
            if (n.guid() && n.guid()->sessionID() && n.guid()->localID())
                guidSet.insert({*n.guid()->sessionID(), *n.guid()->localID()});
        }

        auto brmIt = blobRemaps.find(cs.get());
        const std::map<int32_t,int32_t> *csRemap =
            (brmIt != blobRemaps.end() && !brmIt->second.empty())
            ? &brmIt->second : nullptr;

        for (uint32_t i = 0; i < N; i++) {
            const PixsoNode &orig = (*nodes)[i];

            // 全局 GUID 去重：已写过的节点直接跳过
            uint32_t gs = (orig.guid() && orig.guid()->sessionID()) ? *orig.guid()->sessionID() : 0;
            uint32_t gl = (orig.guid() && orig.guid()->localID())   ? *orig.guid()->localID()   : 0;
            std::string nodeKey = gkStr(gs, gl);
            if (!writtenGuids.insert(nodeKey).second) continue;  // already written

            // 判断是否孤根（用本组件集全量 guidSet 判断，不修改原始节点）
            bool parentInSet = false;
            if (orig.parentIndex() && orig.parentIndex()->guid()) {
                auto *pg = orig.parentIndex()->guid();
                uint32_t ps = pg->sessionID() ? *pg->sessionID() : 0;
                uint32_t pl = pg->localID()   ? *pg->localID()   : 0;
                parentInSet = guidSet.count({ps, pl}) > 0;
            }

            arr[idx] = orig;

            if (!parentInSet)
                arr[idx].set_parentIndex(makeParent(pool, 0, 2, "a0"));

            if (csRemap)
                remapBlobsInNode(arr[idx], *csRemap);

            idx++;
        }
    }

    if (idx != total) {
        fprintf(stderr, "[ERROR] 节点计数不一致: 预期 %u，实际 %u\n", total, idx);
    }

    kiwi::ByteBuffer bb;
    if (!out.encode(bb)) { fprintf(stderr, "encode failed\n"); return {}; }
    return std::vector<uint8_t>(bb.data(), bb.data() + bb.size());
}

// =============================================================================
// 验证：重新解析生成的 .pix 数据
// =============================================================================

static void verifyPix(const std::vector<uint8_t> &pixData) {
    size_t off = parsePixHeader(pixData);
    if (!off) { fprintf(stderr, "  verify: bad pix header\n"); return; }
    auto dec = decompressZstd(pixData.data() + off, pixData.size() - off);
    if (dec.empty()) { fprintf(stderr, "  verify: decompress failed\n"); return; }

    kiwi::ByteBuffer bb(dec.data(), dec.size());
    kiwi::MemoryPool pool;
    PixsoMsg msg;
    if (!msg.decode(bb, pool)) { fprintf(stderr, "  verify: decode failed\n"); return; }

    auto *nodes = msg.pixsoNodes();
    uint32_t cnt = nodes ? nodes->size() : 0;
    printf("  [OK] 节点总数: %u\n\n", cnt);

    static const char *TYPE_NAME[] = {
        "?",        // 0
        "NONE",     // 1
        "DOCUMENT", // 2
        "CANVAS",   // 3
        "GROUP",    // 4
        "FRAME",    // 5
        "BOOL_OP",  // 6
        "VECTOR",   // 7
        "STAR",     // 8
        "LINE",     // 9
        "ELLIPSE",  // 10
        "RECT",     // 11
        "REG_POLY", // 12
        "ROUND_R",  // 13
        "TEXT",     // 14
        "SLICE",    // 15
        "SYMBOL",   // 16
        "INSTANCE", // 17
    };
    auto typeName = [](uint32_t t) -> std::string {
        if (t < 18) return TYPE_NAME[t];
        char buf[16]; snprintf(buf, sizeof(buf), "type(%u)", t);
        return buf;
    };

    for (uint32_t i = 0; nodes && i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        uint32_t t  = n.type() ? (uint32_t)*n.type() : 0;
        uint32_t gs = (n.guid() && n.guid()->sessionID()) ? *n.guid()->sessionID() : 0;
        uint32_t gl = (n.guid() && n.guid()->localID())   ? *n.guid()->localID()   : 0;
        uint32_t ps = 0, pl = 0;
        if (n.parentIndex() && n.parentIndex()->guid()) {
            auto *pg = n.parentIndex()->guid();
            ps = pg->sessionID() ? *pg->sessionID() : 0;
            pl = pg->localID()   ? *pg->localID()   : 0;
        }
        const char *nm  = n.name()        ? n.name()->c_str()        : "";
        bool iInternal  = n.internalOnly() && *n.internalOnly();
        uint32_t nFills = (n.fillPaints() ? n.fillPaints()->size() : 0);

        printf("  [%2u] %-8s guid={%u,%u} parent={%u,%u}%s  fills=%u  \"%s\"\n",
               i, typeName(t).c_str(), gs, gl, ps, pl,
               iInternal ? " [internal]" : "", nFills, nm);

        // 打印 INSTANCE 的 symbolID
        if (n.symbolData() && n.symbolData()->symbolID()) {
            const GUID *sg = n.symbolData()->symbolID();
            printf("       symbolID={%u,%u}\n",
                   sg->sessionID() ? *sg->sessionID() : 0,
                   sg->localID()   ? *sg->localID()   : 0);
        }

        // 打印每个 fill 的颜色/透明度
        if (n.fillPaints()) {
            for (uint32_t fi = 0; fi < nFills; fi++) {
                const Paint &p = (*n.fillPaints())[fi];
                printf("       fill[%u] type=%u visible=%d opacity=%.4f\n",
                       fi,
                       p.type()    ? (uint32_t)*p.type() : 99,
                       p.visible() ? (int)*p.visible()   : -1,
                       p.opacity() ? *p.opacity()        : -1.0f);
                if (p.color()) {
                    const Color *c = p.color();
                    printf("         rgba=(%.4f, %.4f, %.4f, %.4f)\n",
                           c->r() ? *c->r() : -1.0f,
                           c->g() ? *c->g() : -1.0f,
                           c->b() ? *c->b() : -1.0f,
                           c->a() ? *c->a() : -1.0f);
                } else {
                    printf("         color=NULL\n");
                }
            }
        }
    }
}

// =============================================================================
// main
// =============================================================================

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr,
            "Usage:\n"
            "  %s <dsl.json> <out.txt>                      # 无实例\n"
            "  %s <dsl.json> <out.txt> <component_dir>      # 目录模式：按 component_set_key 自动查找\n"
            "  %s <dsl.json> <out.txt> comp1.txt comp2.txt  # 文件模式：逐个指定组件集 hex\n\n"
            "Example:\n"
            "  %s ../dsl-instance-demo.json instance_out.txt ../pix-split/harmony_out/component\n",
            argv[0], argv[0], argv[0], argv[0]);
        return 1;
    }

    printf("=== DSL → hex ===\n");

    // ── 先解析 DSL（组件集加载需要 component_set_key）──────────────────────
    auto raw = readFile(argv[1]);
    if (raw.empty()) return 1;
    printf("  DSL 大小: %zu bytes\n", raw.size());

    JsonParser jp((const char *)raw.data(), raw.size());
    JVal root = jp.parse();
    if (root.isNull()) { fprintf(stderr, "JSON 解析失败\n"); return 1; }

    DslDoc doc = parseDoc(root);
    printf("  页面数: %zu\n", doc.pages.size());
    for (auto &page : doc.pages) {
        uint32_t nc = 0;
        for (auto &l : page.layers) nc += countLayerNodes(l);
        printf("    page [%s] \"%s\"  顶层图层: %zu  节点总计: %u\n",
               page.id.c_str(), page.name.c_str(), page.layers.size(), nc);
    }

    // ── 加载组件集 hex（compSets 生命周期须覆盖 encode）──────────────────
    std::vector<std::unique_ptr<CompSetData>> compSets;

    if (argc >= 4 && isDirectory(argv[3])) {
        // 目录模式：从 DSL 收集所有 component_set_key，按 {dir}/{key}.txt 加载
        std::string dir = argv[3];
        if (!dir.empty() && dir.back() != '/') dir += '/';

        std::set<std::string> keys;
        for (auto &page : doc.pages)
            for (auto &layer : page.layers)
                collectCompSetKeys(layer, keys);

        printf("\n  目录模式: %s  (共 %zu 个唯一 component_set_key)\n",
               argv[3], keys.size());
        for (auto &key : keys) {
            std::string path = dir + key + ".txt";
            auto cs = std::make_unique<CompSetData>();
            if (loadCompSet(path.c_str(), *cs)) {
                auto *nodes = cs->msg.pixsoNodes();
                printf("  组件集 [%.16s...]: %u 节点\n", key.c_str(),
                       nodes ? nodes->size() : 0u);
                compSets.push_back(std::move(cs));
            }
        }
    } else {
        // 文件模式：逐个加载 argv[3..n]
        for (int i = 3; i < argc; i++) {
            auto cs = std::make_unique<CompSetData>();
            if (loadCompSet(argv[i], *cs)) {
                auto *nodes = cs->msg.pixsoNodes();
                printf("  组件集 [%s]: %u 节点\n", argv[i],
                       nodes ? nodes->size() : 0u);
                compSets.push_back(std::move(cs));
            }
        }
    }

    // 去重后的组件节点数（与 buildMsg 内部逻辑一致）
    uint32_t compNodeCount = 0;
    {
        std::set<std::string> seenGuids;
        for (auto &cs : compSets) {
            auto *nodes = cs->msg.pixsoNodes();
            if (!nodes) continue;
            for (uint32_t i = 0; i < nodes->size(); i++) {
                const PixsoNode &n = (*nodes)[i];
                uint32_t s = (n.guid() && n.guid()->sessionID()) ? *n.guid()->sessionID() : 0;
                uint32_t l = (n.guid() && n.guid()->localID())   ? *n.guid()->localID()   : 0;
                std::string key = std::to_string(s) + ":" + std::to_string(l);
                if (seenGuids.insert(key).second) compNodeCount++;
            }
        }
    }
    printf("  预期总节点数（含结构节点，GUID去重后）: %u\n\n", countTotal(doc, compNodeCount));

    // 构建 PixsoMsg（pool + compSets 生命周期覆盖 encode，保证所有指针有效）
    kiwi::MemoryPool pool;
    auto kiwiBin = buildMsg(pool, doc, compSets);
    if (kiwiBin.empty()) return 1;
    printf("  kiwi 编码大小: %zu bytes\n", kiwiBin.size());

    // zstd 压缩 + .pix 格式封装
    auto pixData = compressToPix(kiwiBin);
    if (pixData.empty()) return 1;
    printf("  pix 大小: %zu bytes\n", pixData.size());

    // 转 hex → 写 txt 文件
    std::string hexStr = bytesToHex(pixData);
    std::string outStr = "<!-- pixso binary data -->\n" + hexStr;
    std::vector<uint8_t> outBytes(outStr.begin(), outStr.end());
    if (!writeFile(argv[2], outBytes)) return 1;
    printf("  已写入: %s  (%zu hex chars)\n\n", argv[2], hexStr.size());

    // 验证：重新解析输出文件
    printf("=== 验证（重新解析）===\n");
    verifyPix(pixData);

    return 0;
}
