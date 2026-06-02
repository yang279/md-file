#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include <emscripten/bind.h>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <set>

// NODERAWFS=1 使 fopen/fread 等系统调用直接路由到 Node.js fs，
// 无需挂载虚拟文件系统，也不需要把文件内容传进 WASM。

// =============================================================================
// 文件 I/O（NODERAWFS 下等同于 native）
// =============================================================================

static std::vector<uint8_t> readFile(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "cannot open: %s\n", path); return {}; }
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> buf(sz);
    fread(buf.data(), 1, sz, f); fclose(f);
    return buf;
}

// =============================================================================
// .pix 格式工具
// =============================================================================

static const char    PIX_MAGIC[] = "pixso-kw";
static const uint8_t PIX_VER[2]  = {0x00, 0x02};
static const char    PIX_META[]  = "compress:zstd";

static std::vector<uint8_t> compressToPix(const std::vector<uint8_t> &kiwiBin) {
    size_t bound = ZSTD_compressBound(kiwiBin.size());
    std::vector<uint8_t> comp(bound);
    size_t r = ZSTD_compress(comp.data(), bound, kiwiBin.data(), kiwiBin.size(), 3);
    if (ZSTD_isError(r)) return {};
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
    if (cs == ZSTD_CONTENTSIZE_ERROR) return {};
    size_t dstSz = (cs == ZSTD_CONTENTSIZE_UNKNOWN) ? sz * 8 : (size_t)cs;
    std::vector<uint8_t> dst(dstSz);
    size_t r = ZSTD_decompress(dst.data(), dstSz, src, sz);
    if (ZSTD_isError(r)) return {};
    dst.resize(r); return dst;
}

static std::string bytesToHex(const std::vector<uint8_t> &d) {
    static const char H[] = "0123456789abcdef";
    std::string r; r.reserve(d.size() * 2);
    for (uint8_t b : d) { r += H[b >> 4]; r += H[b & 0xF]; }
    return r;
}

// =============================================================================
// 组件集加载（从 .txt hex 文件路径）
// =============================================================================

static std::vector<uint8_t> hexToBytes(const std::string &hex) {
    std::vector<uint8_t> out;
    out.reserve(hex.size() / 2);
    for (size_t i = 0; i + 1 < hex.size(); i += 2) {
        auto hv = [](char c) -> uint8_t {
            if (c >= '0' && c <= '9') return (uint8_t)(c - '0');
            if (c >= 'a' && c <= 'f') return (uint8_t)(c - 'a' + 10);
            return (uint8_t)(c - 'A' + 10);
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
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
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
    std::vector<JVal>                         arr;
    std::vector<std::pair<std::string, JVal>> obj;

    bool isNull()  const { return type == Null; }
    bool asBool()  const { return type==Bool ? b : (type==Int ? i!=0 : false); }
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
        ws(); if (p >= e) return {};
        switch (*p) {
            case '{': return parseObj();  case '[': return parseArr();
            case '"': return parseStr();
            case 't': { p+=4; JVal v; v.type=JVal::Bool; v.b=true;  return v; }
            case 'f': { p+=5; JVal v; v.type=JVal::Bool; v.b=false; return v; }
            case 'n': { p+=4; return {}; }
            default:  return parseNum();
        }
    }
    JVal parseObj() {
        JVal v; v.type=JVal::Obj; p++; ws();
        while (p<e && *p!='}') {
            JVal key=parseStr(); ws();
            if (p<e && *p==':') p++; ws();
            JVal val=parse(); v.obj.emplace_back(key.s, std::move(val));
            ws(); if (p<e && *p==',') { p++; ws(); }
        }
        if (p<e) p++; return v;
    }
    JVal parseArr() {
        JVal v; v.type=JVal::Arr; p++; ws();
        while (p<e && *p!=']') {
            v.arr.push_back(parse()); ws();
            if (p<e && *p==',') { p++; ws(); }
        }
        if (p<e) p++; return v;
    }
    JVal parseStr() {
        JVal v; v.type=JVal::Str; p++;
        while (p<e && *p!='"') {
            if (*p=='\\' && p+1<e) {
                p++;
                switch (*p) {
                    case '"': v.s+='"'; break; case '\\': v.s+='\\'; break;
                    case '/': v.s+='/'; break; case 'n': v.s+='\n'; break;
                    case 't': v.s+='\t'; break; case 'r': v.s+='\r'; break;
                    default: v.s+=*p; break;
                }
            } else { v.s+=*p; }
            p++;
        }
        if (p<e) p++; return v;
    }
    JVal parseNum() {
        const char *start=p; bool isFloat=false;
        if (p<e && (*p=='-'||*p=='+')) p++;
        while (p<e && *p>='0' && *p<='9') p++;
        if (p<e && *p=='.') { isFloat=true; p++; while (p<e && *p>='0' && *p<='9') p++; }
        if (p<e && (*p=='e'||*p=='E')) {
            isFloat=true; p++; if (p<e && (*p=='+'||*p=='-')) p++;
            while (p<e && *p>='0' && *p<='9') p++;
        }
        std::string ns(start, p-start); JVal v;
        if (isFloat) { v.type=JVal::Dbl; v.d=std::stod(ns); }
        else         { v.type=JVal::Int; v.i=std::stoll(ns); }
        return v;
    }
};

// =============================================================================
// DSL 数据结构 + 解析
// =============================================================================

struct DslBox  { float x=0, y=0, w=0, h=0; };
struct DslFill { std::string type="solid", color="#000000FF"; float opacity=1.f; bool visible=true; };
struct DslLayer {
    std::string id, name, type; bool visible=true; float opacity=1.f;
    std::string blendMode="normal"; DslBox box; float cornerRadius=0.f;
    std::vector<DslFill> fills; std::vector<DslLayer> children;
    std::string symbolId, variantKey, componentSetKey;
};
struct DslPage { std::string id, name; std::vector<DslLayer> layers; };
struct DslDoc  { std::vector<DslPage> pages; };

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
    if (j.has("fills"))    { const JVal&fs=j.get("fills");    for(size_t i=0;i<fs.size();i++) l.fills.push_back(parseFill(fs[i])); }
    if (j.has("children")) { const JVal&cs=j.get("children"); for(size_t i=0;i<cs.size();i++) l.children.push_back(parseLayer(cs[i])); }
    if (j.has("instance")) {
        const JVal &inst = j.get("instance");
        if (inst.has("symbol_id"))        l.symbolId        = inst.get("symbol_id").asStr();
        if (inst.has("variant_key"))       l.variantKey      = inst.get("variant_key").asStr();
        if (inst.has("component_set_key")) l.componentSetKey = inst.get("component_set_key").asStr();
    }
    return l;
}
static DslDoc parseDoc(const JVal &j) {
    DslDoc doc;
    if (!j.has("pages")) return doc;
    const JVal &pages = j.get("pages");
    for (size_t i = 0; i < pages.size(); i++) {
        const JVal &pj = pages[i]; DslPage page;
        if (pj.has("id"))   page.id   = pj.get("id").asStr();
        if (pj.has("name")) page.name = pj.get("name").asStr();
        if (pj.has("layers")) { const JVal&ls=pj.get("layers"); for(size_t k=0;k<ls.size();k++) page.layers.push_back(parseLayer(ls[k])); }
        doc.pages.push_back(std::move(page));
    }
    return doc;
}

// =============================================================================
// GUID / ParentIndex / 位置
// =============================================================================

struct GK { uint32_t s=0, l=0; };
static GK parseGK(const std::string &id) {
    auto pos = id.find(':'); if (pos==std::string::npos) return {};
    try { return {(uint32_t)std::stoul(id.substr(0,pos)),(uint32_t)std::stoul(id.substr(pos+1))}; }
    catch(...) { return {}; }
}
static GUID* makeGUID(kiwi::MemoryPool &pool,uint32_t s,uint32_t l) {
    GUID*g=pool.allocate<GUID>();new(g)GUID();g->set_sessionID(s);g->set_localID(l);return g;
}
static ParentIndex* makeParent(kiwi::MemoryPool &pool,uint32_t ps,uint32_t pl,const std::string &pos) {
    ParentIndex*pi=pool.allocate<ParentIndex>();new(pi)ParentIndex();
    pi->set_guid(makeGUID(pool,ps,pl));pi->set_position(pool.string(pos.c_str()));return pi;
}
static std::string makePos(int idx) { char buf[16];snprintf(buf,sizeof(buf),"a%08x",(unsigned)idx);return buf; }

// =============================================================================
// 类型映射 / 颜色
// =============================================================================

static NodeType mapLayerType(const std::string &t) {
    if(t=="frame")     return NodeType::FRAME;     if(t=="group")    return NodeType::GROUP;
    if(t=="rectangle") return NodeType::RECTANGLE; if(t=="ellipse")  return NodeType::ELLIPSE;
    if(t=="vector")    return NodeType::VECTOR;    if(t=="star")     return NodeType::STAR;
    if(t=="line")      return NodeType::LINE;      if(t=="boolean")  return NodeType::BOOLEAN_OPERATION;
    if(t=="text")      return NodeType::TEXT;      if(t=="instance") return NodeType::INSTANCE;
    return NodeType::RECTANGLE;
}
static BlendMode mapBlendMode(const std::string &s) {
    if(s=="multiply")    return BlendMode::MULTIPLY;    if(s=="screen")      return BlendMode::SCREEN;
    if(s=="overlay")     return BlendMode::OVERLAY;     if(s=="darken")      return BlendMode::DARKEN;
    if(s=="lighten")     return BlendMode::LIGHTEN;     if(s=="color_dodge") return BlendMode::COLOR_DODGE;
    if(s=="color_burn")  return BlendMode::COLOR_BURN;  if(s=="hard_light")  return BlendMode::HARD_LIGHT;
    if(s=="soft_light")  return BlendMode::SOFT_LIGHT;  if(s=="difference")  return BlendMode::DIFFERENCE;
    if(s=="exclusion")   return BlendMode::EXCLUSION;   if(s=="hue")         return BlendMode::HUE;
    if(s=="saturation")  return BlendMode::SATURATION;  if(s=="color")       return BlendMode::COLOR;
    if(s=="luminosity")  return BlendMode::LUMINOSITY;
    return BlendMode::NORMAL;
}
static Color* parseColor(kiwi::MemoryPool &pool,const std::string &hex) {
    if(hex.empty()||hex[0]!='#') return nullptr;
    auto hv=[](char c)->uint8_t{
        if(c>='0'&&c<='9')return(uint8_t)(c-'0');
        if(c>='a'&&c<='f')return(uint8_t)(c-'a'+10);
        return(uint8_t)(c-'A'+10);
    };
    uint8_t r=0,g=0,b=0,a=255;
    if(hex.size()>=7){r=hv(hex[1])*16+hv(hex[2]);g=hv(hex[3])*16+hv(hex[4]);b=hv(hex[5])*16+hv(hex[6]);}
    if(hex.size()>=9) a=hv(hex[7])*16+hv(hex[8]);
    Color*c=pool.allocate<Color>();new(c)Color();
    c->set_r((float)r);c->set_g((float)g);c->set_b((float)b);c->set_a((float)a);return c;
}

// =============================================================================
// 节点数量统计
// =============================================================================

static uint32_t countLayerNodes(const DslLayer &layer) {
    if(layer.type=="instance") return 1;
    uint32_t n=1; for(auto&child:layer.children) n+=countLayerNodes(child); return n;
}
static uint32_t countTotal(const DslDoc &doc, uint32_t compNodeCount=0) {
    uint32_t n=(uint32_t)doc.pages.size()+1;
    for(auto&page:doc.pages) for(auto&layer:page.layers) n+=countLayerNodes(layer);
    return n+compNodeCount;
}

// =============================================================================
// SymbolMap + derivedSymbolData 计数
// =============================================================================

using SymbolMap   = std::map<std::string, std::pair<CompSetData*, const PixsoNode*>>;
using ChildrenMap = std::map<std::string, std::vector<const PixsoNode*>>;

static std::string gkStr(uint32_t s,uint32_t l){ return std::to_string(s)+":"+std::to_string(l); }

static ChildrenMap buildChildrenMap(const CompSetData &cs) {
    ChildrenMap m;
    auto*nodes=cs.msg.pixsoNodes(); if(!nodes) return m;
    for(uint32_t i=0;i<nodes->size();i++){
        const PixsoNode&n=(*nodes)[i]; auto*pi=n.parentIndex(); if(!pi||!pi->guid()) continue;
        uint32_t ps=pi->guid()->sessionID()?*pi->guid()->sessionID():0;
        uint32_t pl=pi->guid()->localID()  ?*pi->guid()->localID()  :0;
        m[gkStr(ps,pl)].push_back(&n);
    }
    return m;
}
static uint32_t computeDerivedCount(const PixsoNode &node, const ChildrenMap &cm) {
    if(!node.guid()) return 0;
    uint32_t s=node.guid()->sessionID()?*node.guid()->sessionID():0;
    uint32_t l=node.guid()->localID()  ?*node.guid()->localID()  :0;
    auto it=cm.find(gkStr(s,l)); if(it==cm.end()) return 0;
    uint32_t count=0;
    for(const PixsoNode*child:it->second){
        count++;
        uint32_t t=child->type()?(uint32_t)*child->type():0;
        if(t==17) count+=child->derivedSymbolData()?(uint32_t)child->derivedSymbolData()->size():0;
        else      count+=computeDerivedCount(*child,cm);
    }
    return count;
}

// 收集 DSL 中所有 instance 的 component_set_key
static void collectCompSetKeys(const DslLayer &layer, std::set<std::string> &keys) {
    if (layer.type=="instance" && !layer.componentSetKey.empty())
        keys.insert(layer.componentSetKey);
    for (auto &child : layer.children) collectCompSetKeys(child, keys);
}

// =============================================================================
// Blob 辅助：收集 / 重映射
// =============================================================================

static void collectBlobsFromNode(const PixsoNode &n, std::set<int32_t> &out) {
    auto addPaths=[&](const kiwi::Array<Path>*arr){
        if(!arr)return;
        for(uint32_t i=0;i<arr->size();i++) if((*arr)[i].blobIndex()) out.insert(*(*arr)[i].blobIndex());
    };
    addPaths(n.fillGeometry()); addPaths(n.strokeGeometry());
    if(n.vectorData()&&n.vectorData()->vectorNetworkBlob()) out.insert(*n.vectorData()->vectorNetworkBlob());
    if(n.textData()&&n.textData()->glyphs()){
        const auto*g=n.textData()->glyphs();
        for(uint32_t i=0;i<g->size();i++) if((*g)[i].blobIndex()) out.insert(*(*g)[i].blobIndex());
    }
    if(n.symbolData()&&n.symbolData()->symbolOverrides()){
        const auto*ov=n.symbolData()->symbolOverrides();
        for(uint32_t i=0;i<ov->size();i++) collectBlobsFromNode((*ov)[i],out);
    }
    if(n.derivedSymbolData()){
        const auto*ds=n.derivedSymbolData();
        for(uint32_t i=0;i<ds->size();i++) collectBlobsFromNode((*ds)[i],out);
    }
}
static void remapBlobsInNode(PixsoNode &n, const std::map<int32_t,int32_t>&remap) {
    if(remap.empty()) return;
    auto fixPaths=[&](kiwi::Array<Path>*arr){
        if(!arr)return;
        for(uint32_t i=0;i<arr->size();i++){
            Path&p=(*arr)[i];
            if(p.blobIndex()){auto it=remap.find(*p.blobIndex());if(it!=remap.end())p.set_blobIndex(it->second);}
        }
    };
    fixPaths(n.fillGeometry()); fixPaths(n.strokeGeometry());
    if(n.vectorData()&&n.vectorData()->vectorNetworkBlob()){
        auto it=remap.find(*n.vectorData()->vectorNetworkBlob());
        if(it!=remap.end()) n.vectorData()->set_vectorNetworkBlob(it->second);
    }
    if(n.textData()&&n.textData()->glyphs()){
        auto*g=n.textData()->glyphs();
        for(uint32_t i=0;i<g->size();i++){
            Glyph&gl=(*g)[i];
            if(gl.blobIndex()){auto it=remap.find(*gl.blobIndex());if(it!=remap.end())gl.set_blobIndex(it->second);}
        }
    }
    if(n.symbolData()&&n.symbolData()->symbolOverrides()){
        auto*ov=n.symbolData()->symbolOverrides();
        for(uint32_t i=0;i<ov->size();i++) remapBlobsInNode((*ov)[i],remap);
    }
    if(n.derivedSymbolData()){
        auto*ds=n.derivedSymbolData();
        for(uint32_t i=0;i<ds->size();i++) remapBlobsInNode((*ds)[i],remap);
    }
}

// =============================================================================
// fillLayerNode
// =============================================================================

static void fillLayerNode(kiwi::MemoryPool &pool,
                          kiwi::Array<PixsoNode> &arr, uint32_t &idx,
                          const DslLayer &layer,
                          uint32_t parentS, uint32_t parentL, int childPos,
                          const SymbolMap &symMap,
                          const std::map<CompSetData*, ChildrenMap> &childMaps) {
    if (layer.type == "instance") {
        if (layer.symbolId.empty()) return;
        auto gk=parseGK(layer.id), sgk=parseGK(layer.symbolId);
        PixsoNode &n=arr[idx++];
        n.set_type(NodeType::INSTANCE); n.set_phase(NodePhase::CREATED);
        n.set_guid(makeGUID(pool,gk.s,gk.l));
        n.set_name(pool.string(layer.name.c_str()));
        n.set_parentIndex(makeParent(pool,parentS,parentL,makePos(childPos)));

        Matrix *mat=pool.allocate<Matrix>();new(mat)Matrix();
        mat->set_m00(1.f);mat->set_m01(0.f);mat->set_m02(layer.box.x);
        mat->set_m10(0.f);mat->set_m11(1.f);mat->set_m12(layer.box.y);
        n.set_transform(mat);

        float sizeW=layer.box.w, sizeH=layer.box.h;
        {
            auto smSz=symMap.find(layer.symbolId);
            if(smSz!=symMap.end()){
                const PixsoNode*sym=smSz->second.second;
                if(sym->size()){
                    if(sym->size()->x()) sizeW=*sym->size()->x();
                    if(sym->size()->y()) sizeH=*sym->size()->y();
                }
            }
        }
        Vector *sz=pool.allocate<Vector>();new(sz)Vector();
        sz->set_x(sizeW);sz->set_y(sizeH);n.set_size(sz);

        SymbolData *sd=pool.allocate<SymbolData>();new(sd)SymbolData();
        sd->set_symbolID(makeGUID(pool,sgk.s,sgk.l));n.set_symbolData(sd);

        auto smIt=symMap.find(layer.symbolId);
        if(smIt!=symMap.end()){
            CompSetData*csData=smIt->second.first;
            const PixsoNode*symNode=smIt->second.second;
            auto cmIt=childMaps.find(csData);
            if(cmIt!=childMaps.end()){
                uint32_t cnt=computeDerivedCount(*symNode,cmIt->second);
                if(cnt>0) n.set_derivedSymbolData(pool,cnt);
            }
        }
        return;
    }

    auto gk=parseGK(layer.id);
    PixsoNode &n=arr[idx++];
    n.set_type(mapLayerType(layer.type)); n.set_phase(NodePhase::CREATED);
    n.set_guid(makeGUID(pool,gk.s,gk.l));
    n.set_name(pool.string(layer.name.c_str()));
    n.set_visible(layer.visible); n.set_opacity(layer.opacity);
    n.set_blendMode(mapBlendMode(layer.blendMode));
    n.set_parentIndex(makeParent(pool,parentS,parentL,makePos(childPos)));

    Matrix *mat=pool.allocate<Matrix>();new(mat)Matrix();
    mat->set_m00(1.f);mat->set_m01(0.f);mat->set_m02(layer.box.x);
    mat->set_m10(0.f);mat->set_m11(1.f);mat->set_m12(layer.box.y);
    n.set_transform(mat);

    Vector *sz=pool.allocate<Vector>();new(sz)Vector();
    sz->set_x(layer.box.w);sz->set_y(layer.box.h);n.set_size(sz);

    if(layer.cornerRadius!=0.f) n.set_cornerRadius(layer.cornerRadius);
    if(!layer.fills.empty()){
        auto &paints=n.set_fillPaints(pool,(uint32_t)layer.fills.size());
        for(size_t i=0;i<layer.fills.size();i++){
            const DslFill&f=layer.fills[i]; Paint&p=paints[i];
            PaintType pt=PaintType::SOLID;
            if(f.type=="gradient_linear") pt=PaintType::GRADIENT_LINEAR;
            else if(f.type=="gradient_radial") pt=PaintType::GRADIENT_RADIAL;
            else if(f.type=="image") pt=PaintType::IMAGE;
            p.set_type(pt);p.set_visible(f.visible);p.set_opacity(f.opacity);
            p.set_blendMode(BlendMode::NORMAL);
            if(!f.color.empty()){Color*c=parseColor(pool,f.color);if(c)p.set_color(c);}
        }
    }
    for(size_t i=0;i<layer.children.size();i++)
        fillLayerNode(pool,arr,idx,layer.children[i],gk.s,gk.l,(int)i,symMap,childMaps);
}

// =============================================================================
// buildMsg
// =============================================================================

static std::vector<uint8_t> buildMsg(
        kiwi::MemoryPool &pool, const DslDoc &doc,
        std::vector<std::unique_ptr<CompSetData>> &compSets) {

    uint32_t compNodeCount=0;
    for(auto&cs:compSets){auto*nodes=cs->msg.pixsoNodes();if(nodes)compNodeCount+=nodes->size();}

    uint32_t total=countTotal(doc,compNodeCount);

    SymbolMap symMap;
    std::map<CompSetData*,ChildrenMap> childMaps;
    for(auto&cs:compSets){
        childMaps[cs.get()]=buildChildrenMap(*cs);
        auto*nodes=cs->msg.pixsoNodes(); if(!nodes) continue;
        for(uint32_t i=0;i<nodes->size();i++){
            const PixsoNode&n=(*nodes)[i];
            if(!n.type()||*n.type()!=NodeType::SYMBOL||!n.guid()) continue;
            uint32_t s=n.guid()->sessionID()?*n.guid()->sessionID():0;
            uint32_t l=n.guid()->localID()  ?*n.guid()->localID()  :0;
            symMap[gkStr(s,l)]={cs.get(),&n};
        }
    }

    PixsoMsg out; out.set_type(PixsoMsgType::FIC_DOCUMENT);
    auto &arr=out.set_pixsoNodes(pool,total);
    uint32_t idx=0;

    // 合并 blobs（内容去重）
    std::vector<std::vector<uint8_t>>              mergedBlobs;
    std::map<std::string,int32_t>                  blobContentIdx;
    std::map<CompSetData*,std::map<int32_t,int32_t>> blobRemaps;
    for(auto&cs:compSets){
        auto*blobs=cs->msg.blobs(); if(!blobs||blobs->size()==0) continue;
        auto&remap=blobRemaps[cs.get()];
        for(uint32_t i=0;i<blobs->size();i++){
            const auto*bytes=(*blobs)[i].bytes();
            if(!bytes||bytes->size()==0){remap[(int32_t)i]=-1;continue;}
            std::string key(reinterpret_cast<const char*>(&(*bytes)[0]),bytes->size());
            auto it=blobContentIdx.find(key);
            if(it!=blobContentIdx.end()){remap[(int32_t)i]=it->second;}
            else{
                int32_t newIdx=(int32_t)mergedBlobs.size();
                mergedBlobs.push_back(std::vector<uint8_t>(&(*bytes)[0],&(*bytes)[0]+bytes->size()));
                blobContentIdx[key]=newIdx; remap[(int32_t)i]=newIdx;
            }
        }
    }
    if(!mergedBlobs.empty()){
        auto&outBlobs=out.set_blobs(pool,(uint32_t)mergedBlobs.size());
        for(size_t i=0;i<mergedBlobs.size();i++){
            auto&dstB=outBlobs[i].set_bytes(pool,(uint32_t)mergedBlobs[i].size());
            for(size_t j=0;j<mergedBlobs[i].size();j++) dstB[j]=mergedBlobs[i][j];
        }
    }

    for(size_t pi=0;pi<doc.pages.size();pi++){
        const DslPage&page=doc.pages[pi];
        uint32_t canvasL=(pi==0)?1u:(uint32_t)(pi+2);
        PixsoNode&cv=arr[idx++];
        cv.set_type(NodeType::CANVAS); cv.set_phase(NodePhase::CREATED);
        cv.set_guid(makeGUID(pool,0,canvasL));
        cv.set_name(pool.string(page.name.c_str()));
        cv.set_parentIndex(makeParent(pool,0,0,"!"));
        for(size_t li=0;li<page.layers.size();li++)
            fillLayerNode(pool,arr,idx,page.layers[li],0,canvasL,(int)li,symMap,childMaps);
    }

    {
        PixsoNode&hv=arr[idx++];
        hv.set_type(NodeType::CANVAS); hv.set_phase(NodePhase::CREATED);
        hv.set_guid(makeGUID(pool,0,2));
        hv.set_name(pool.string("Internal Only Canvas"));
        hv.set_internalOnly(true);
        hv.set_parentIndex(makeParent(pool,0,0,"~"));
    }

    for(auto&cs:compSets){
        auto*nodes=cs->msg.pixsoNodes(); if(!nodes) continue;
        uint32_t N=nodes->size();
        std::set<std::pair<uint32_t,uint32_t>> guidSet;
        for(uint32_t i=0;i<N;i++){
            const PixsoNode&n=(*nodes)[i];
            if(n.guid()&&n.guid()->sessionID()&&n.guid()->localID())
                guidSet.insert({*n.guid()->sessionID(),*n.guid()->localID()});
        }
        auto brmIt=blobRemaps.find(cs.get());
        const std::map<int32_t,int32_t>*csRemap=
            (brmIt!=blobRemaps.end()&&!brmIt->second.empty())?&brmIt->second:nullptr;
        for(uint32_t i=0;i<N;i++){
            const PixsoNode&orig=(*nodes)[i];
            bool parentInSet=false;
            if(orig.parentIndex()&&orig.parentIndex()->guid()){
                auto*pg=orig.parentIndex()->guid();
                uint32_t ps=pg->sessionID()?*pg->sessionID():0;
                uint32_t pl=pg->localID()  ?*pg->localID()  :0;
                parentInSet=guidSet.count({ps,pl})>0;
            }
            arr[idx]=orig;
            if(!parentInSet) arr[idx].set_parentIndex(makeParent(pool,0,2,"a0"));
            if(csRemap) remapBlobsInNode(arr[idx],*csRemap);
            idx++;
        }
    }

    if(idx!=total) fprintf(stderr,"[ERROR] 节点计数不一致: 预期 %u, 实际 %u\n",total,idx);
    kiwi::ByteBuffer bb;
    if(!out.encode(bb)) return {};
    return std::vector<uint8_t>(bb.data(),bb.data()+bb.size());
}

// =============================================================================
// WASM 导出函数
// =============================================================================

// dslToHex(dslJsonPath, componentDir) → hex string
// - dslJsonPath:  DSL JSON 文件的绝对/相对路径（NODERAWFS 直接读本地文件）
// - componentDir: 组件 hex 目录路径（按 component_set_key 自动查找 {key}.txt）
std::string dslToHex(const std::string &dslJsonPath,
                     const std::string &componentDir) {
    // 读取 DSL JSON
    auto raw = readFile(dslJsonPath.c_str());
    if (raw.empty()) return "{\"error\":\"cannot read DSL: " + dslJsonPath + "\"}";

    JsonParser jp((const char*)raw.data(), raw.size());
    JVal root = jp.parse();
    if (root.isNull()) return "{\"error\":\"JSON parse failed\"}";

    DslDoc doc = parseDoc(root);

    // 从目录按 component_set_key 加载组件 hex
    std::vector<std::unique_ptr<CompSetData>> compSets;
    std::string dir = componentDir;
    if (!dir.empty() && dir.back() != '/') dir += '/';

    std::set<std::string> keys;
    for (auto &page : doc.pages)
        for (auto &layer : page.layers)
            collectCompSetKeys(layer, keys);

    std::vector<std::string> missingKeys;
    for (auto &key : keys) {
        std::string path = dir + key + ".txt";
        auto cs = std::make_unique<CompSetData>();
        if (loadCompSet(path.c_str(), *cs)) {
            compSets.push_back(std::move(cs));
        } else {
            fprintf(stderr, "[ERROR] 组件集文件不存在: %s\n", path.c_str());
            missingKeys.push_back(key);
        }
    }

    // 构建 + 压缩
    kiwi::MemoryPool pool;
    auto kiwiBin = buildMsg(pool, doc, compSets);
    if (kiwiBin.empty()) return "{\"error\":\"buildMsg failed\"}";

    auto pixData = compressToPix(kiwiBin);
    if (pixData.empty()) return "{\"error\":\"compress failed\"}";

    std::string hexStr = "<!-- pixso binary data -->\n" + bytesToHex(pixData);

    // 有缺失组件时返回 JSON（含 hex + missing 列表），否则直接返回 hex 字符串
    if (!missingKeys.empty()) {
        // 转义 hex 中的换行（JSON string 不能含裸换行）
        std::string escapedHex;
        for (char c : hexStr) {
            if (c == '\n') escapedHex += "\\n";
            else if (c == '"') escapedHex += "\\\"";
            else escapedHex += c;
        }
        std::string json = "{\"hex\":\"" + escapedHex + "\",\"missing\":[";
        for (size_t i = 0; i < missingKeys.size(); i++) {
            if (i > 0) json += ",";
            json += "\"" + missingKeys[i] + "\"";
        }
        json += "]}";
        return json;
    }
    return hexStr;
}

EMSCRIPTEN_BINDINGS(dsl_to_hex_wasm) {
    emscripten::function("dslToHex", &dslToHex);
}
