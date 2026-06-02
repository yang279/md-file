#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include <emscripten/bind.h>

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// ─────────── hex 工具 ───────────

static std::vector<uint8_t> hexToBytes(const std::string &hex) {
    std::vector<uint8_t> out;
    bool inComment = false;
    std::string clean;
    for (char c : hex) {
        if (c == '#' || c == '<') { inComment = true; continue; }
        if (c == '\n') { inComment = false; continue; }
        if (inComment) continue;
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
            clean += c;
    }
    for (size_t i = 0; i + 1 < clean.size(); i += 2) {
        auto h = [](char c) -> uint8_t {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'a' && c <= 'f') return c - 'a' + 10;
            return c - 'A' + 10;
        };
        out.push_back((h(clean[i]) << 4) | h(clean[i+1]));
    }
    return out;
}

static std::string bytesToHex(const std::vector<uint8_t> &d) {
    static const char h[] = "0123456789abcdef";
    std::string r; r.reserve(d.size() * 2);
    for (uint8_t b : d) { r += h[b >> 4]; r += h[b & 0xF]; }
    return r;
}

// ─────────── .pix 解压/压缩 ───────────

static std::vector<uint8_t> decompressPix(const std::vector<uint8_t> &raw) {
    if (raw.size() < 12) return {};
    if (memcmp(raw.data(), "pixso-kw", 8) != 0) return {};
    size_t pos = 8 + 2;
    uint8_t ml = raw[pos++];
    pos += ml;
    auto cs = ZSTD_getFrameContentSize(raw.data() + pos, raw.size() - pos);
    if (cs == ZSTD_CONTENTSIZE_ERROR) return {};
    if (cs == ZSTD_CONTENTSIZE_UNKNOWN) cs = raw.size() * 8;
    std::vector<uint8_t> out(cs);
    size_t r = ZSTD_decompress(out.data(), cs, raw.data() + pos, raw.size() - pos);
    if (ZSTD_isError(r)) return {};
    out.resize(r);
    return out;
}

static std::vector<uint8_t> compressToPix(const std::vector<uint8_t> &kiwiBin) {
    size_t bound = ZSTD_compressBound(kiwiBin.size());
    std::vector<uint8_t> comp(bound);
    size_t r = ZSTD_compress(comp.data(), bound, kiwiBin.data(), kiwiBin.size(), 3);
    if (ZSTD_isError(r)) return {};
    comp.resize(r);

    std::vector<uint8_t> out;
    const char *magic = "pixso-kw";
    out.insert(out.end(), magic, magic + 8);
    out.push_back(0x00); out.push_back(0x02);
    const char *meta = "compress:zstd";
    out.push_back((uint8_t)strlen(meta));
    out.insert(out.end(), meta, meta + strlen(meta));
    out.insert(out.end(), comp.begin(), comp.end());
    return out;
}

// ─────────── GUID / ParentIndex 构造 ───────────

static GUID* makeGUID(kiwi::MemoryPool &pool, uint32_t s, uint32_t l) {
    GUID *g = pool.allocate<GUID>(); new (g) GUID();
    g->set_sessionID(s); g->set_localID(l);
    return g;
}

static ParentIndex* makeParent(kiwi::MemoryPool &pool,
                                uint32_t ps, uint32_t pl, const std::string &pos) {
    ParentIndex *pi = pool.allocate<ParentIndex>(); new (pi) ParentIndex();
    pi->set_guid(makeGUID(pool, ps, pl));
    pi->set_position(pool.string(pos.c_str()));
    return pi;
}

// ─────────── 组件集解析 ───────────

struct CompSetData {
    kiwi::MemoryPool pool;
    PixsoMsg msg;

    struct SymInfo {
        uint32_t nodeIndex;
        uint32_t guidSession, guidLocal;
        std::string name;
        float w = 0, h = 0;
    };
    std::vector<SymInfo> symbols;
    uint32_t rootIndex = 0;
    bool valid = false;
};

static bool parseCompSet(const std::vector<uint8_t> &raw, CompSetData &cs) {
    auto dec = decompressPix(raw);
    if (dec.empty()) return false;

    kiwi::ByteBuffer bb(dec.data(), dec.size());
    if (!cs.msg.decode(bb, cs.pool)) return false;

    auto *nodes = cs.msg.pixsoNodes();
    if (!nodes || nodes->size() == 0) return false;

    cs.rootIndex = 0;

    for (uint32_t i = 0; i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        if (!n.type() || *n.type() != NodeType::SYMBOL) continue;

        CompSetData::SymInfo si;
        si.nodeIndex = i;
        si.guidSession = n.guid() && n.guid()->sessionID() ? *n.guid()->sessionID() : 0;
        si.guidLocal   = n.guid() && n.guid()->localID()   ? *n.guid()->localID()   : 0;
        si.name = n.name() ? n.name()->c_str() : "";
        if (n.size()) {
            si.w = n.size()->x() ? *n.size()->x() : 0;
            si.h = n.size()->y() ? *n.size()->y() : 0;
        }
        cs.symbols.push_back(si);
    }
    cs.valid = true;
    return true;
}

// ─────────── 核心：生成 N+1 节点消息 ───────────

static std::vector<uint8_t> buildInstanceMsg(
    CompSetData &cs,
    const CompSetData::SymInfo &chosen,
    uint32_t instSession, uint32_t instLocal,
    uint32_t parentSession, uint32_t parentLocal,
    float x, float y
) {
    auto *nodes = cs.msg.pixsoNodes();
    uint32_t N = nodes->size();

    // 收集所有 GUID
    std::set<std::pair<uint32_t,uint32_t>> guidSet;
    for (uint32_t i = 0; i < N; i++) {
        const PixsoNode &n = (*nodes)[i];
        if (n.guid() && n.guid()->sessionID() && n.guid()->localID())
            guidSet.insert({*n.guid()->sessionID(), *n.guid()->localID()});
    }

    // 父节点不在消息内的节点，parent 改为 {0,2}（隐藏页）
    for (uint32_t i = 0; i < N; i++) {
        PixsoNode &n = (*nodes)[i];
        bool parentInSet = false;
        if (n.parentIndex() && n.parentIndex()->guid()) {
            auto *pg = n.parentIndex()->guid();
            uint32_t ps = pg->sessionID() ? *pg->sessionID() : 0;
            uint32_t pl = pg->localID()   ? *pg->localID()   : 0;
            parentInSet = guidSet.count({ps, pl}) > 0;
        }
        if (!parentInSet)
            n.set_parentIndex(makeParent(cs.pool, 0, 2, "a0"));
    }

    // 新建 INSTANCE 节点
    PixsoNode *inst = cs.pool.allocate<PixsoNode>(); new (inst) PixsoNode();
    inst->set_guid(makeGUID(cs.pool, instSession, instLocal));
    inst->set_type(NodeType::INSTANCE);
    inst->set_phase(NodePhase::CREATED);
    inst->set_name(cs.pool.string(chosen.name.c_str()));
    inst->set_visible(true);
    inst->set_parentIndex(makeParent(cs.pool, parentSession, parentLocal, "a0"));

    Matrix *mat = cs.pool.allocate<Matrix>(); new (mat) Matrix();
    mat->set_m00(1.f); mat->set_m01(0.f); mat->set_m02(x);
    mat->set_m10(0.f); mat->set_m11(1.f); mat->set_m12(y);
    inst->set_transform(mat);

    Vector *sz = cs.pool.allocate<Vector>(); new (sz) Vector();
    sz->set_x(chosen.w); sz->set_y(chosen.h);
    inst->set_size(sz);

    SymbolData *sd = cs.pool.allocate<SymbolData>(); new (sd) SymbolData();
    sd->set_symbolID(makeGUID(cs.pool, chosen.guidSession, chosen.guidLocal));
    inst->set_symbolData(sd);

    // 组装 N+1 节点消息
    PixsoMsg out;
    out.set_type(PixsoMsgType::NODE_CHANGES);
    auto &arr = out.set_pixsoNodes(cs.pool, N + 1);
    for (uint32_t i = 0; i < N; i++) arr[i] = (*nodes)[i];
    arr[N] = *inst;

    kiwi::ByteBuffer bb;
    if (!out.encode(bb)) return {};
    return std::vector<uint8_t>(bb.data(), bb.data() + bb.size());
}

// ─────────── WASM 暴露接口 ───────────

// 列出组件集中所有 SYMBOL，返回 JSON 字符串
// JSON 格式：[{"index":0,"guid":"1:11548","name":"类型=content","width":328,"height":90}, ...]
std::string listSymbols(const std::string &hexData) {
    auto raw = hexToBytes(hexData);
    if (raw.empty()) return "{\"error\":\"invalid hex\"}";

    CompSetData cs;
    if (!parseCompSet(raw, cs)) return "{\"error\":\"parse failed\"}";

    std::string json = "[";
    for (size_t i = 0; i < cs.symbols.size(); i++) {
        auto &s = cs.symbols[i];
        if (i > 0) json += ",";
        json += "{";
        json += "\"index\":" + std::to_string(i) + ",";
        json += "\"guid\":\"" + std::to_string(s.guidSession) + ":" + std::to_string(s.guidLocal) + "\",";
        // 转义 name 中的引号
        std::string escaped;
        for (char c : s.name) { if (c == '"') escaped += "\\\""; else escaped += c; }
        json += "\"name\":\"" + escaped + "\",";
        json += "\"width\":" + std::to_string((int)s.w) + ",";
        json += "\"height\":" + std::to_string((int)s.h);
        json += "}";
    }
    json += "]";
    return json;
}

// 创建实例，返回 hex 字符串（带 <!-- pixso binary data --> 首行）
// symbolIndex: SYMBOL 序号
// instSession/instLocal: 新实例的 GUID
// parentSession/parentLocal: 实例父节点 GUID（放在可见页，一般是 {0,1}）
// x, y: 实例位置
std::string createInstance(
    const std::string &hexData,
    int symbolIndex,
    int instSession, int instLocal,
    int parentSession, int parentLocal,
    float x, float y
) {
    auto raw = hexToBytes(hexData);
    if (raw.empty()) return "{\"error\":\"invalid hex\"}";

    CompSetData cs;
    if (!parseCompSet(raw, cs)) return "{\"error\":\"parse failed\"}";

    if (symbolIndex < 0 || symbolIndex >= (int)cs.symbols.size())
        return "{\"error\":\"symbol index out of range\"}";

    const auto &chosen = cs.symbols[symbolIndex];

    auto kiwiBin = buildInstanceMsg(cs, chosen,
        (uint32_t)instSession, (uint32_t)instLocal,
        (uint32_t)parentSession, (uint32_t)parentLocal,
        x, y);
    if (kiwiBin.empty()) return "{\"error\":\"encode failed\"}";

    auto compressed = compressToPix(kiwiBin);
    if (compressed.empty()) return "{\"error\":\"compress failed\"}";

    return "<!-- pixso binary data -->\n" + bytesToHex(compressed);
}

// 绑定到 JS
EMSCRIPTEN_BINDINGS(pix_instance) {
    emscripten::function("listSymbols",   &listSymbols);
    emscripten::function("createInstance", &createInstance);
}
