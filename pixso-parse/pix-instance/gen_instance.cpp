#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// ─────────── .pix 文件头 ───────────
// "pixso-kw" (8) + version[2] (2) + metaLen (1) + "compress:zstd" (13) = 24 bytes
static const char PIX_MAGIC[] = "pixso-kw";
static const uint8_t PIX_VERSION[2] = {0x00, 0x02};
static const char PIX_META[] = "compress:zstd";

// ─────────── hex 工具（前置，供 loadPixData 使用）───────────

static std::vector<uint8_t> hexToBytes(const std::string &hex) {
    std::vector<uint8_t> out;
    for (size_t i = 0; i + 1 < hex.size(); i += 2) {
        uint8_t hi = 0, lo = 0;
        char c = hex[i];
        if (c >= '0' && c <= '9') hi = c - '0';
        else if (c >= 'a' && c <= 'f') hi = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F') hi = c - 'A' + 10;
        c = hex[i+1];
        if (c >= '0' && c <= '9') lo = c - '0';
        else if (c >= 'a' && c <= 'f') lo = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F') lo = c - 'A' + 10;
        out.push_back((hi << 4) | lo);
    }
    return out;
}

// ─────────── 文件 I/O ───────────

static std::vector<uint8_t> readFile(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "cannot open: %s\n", path); return {}; }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f); fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> buf(sz);
    fread(buf.data(), 1, sz, f);
    fclose(f);
    return buf;
}

// 判断是否是 .txt hex 文件并读取：自动检测文件扩展名
// .txt 文件内容为纯 hex 字符串（可含注释行以 # 开头、空白字符）
static std::vector<uint8_t> loadPixData(const char *path) {
    std::string p(path);
    // 如果是 .txt，按 hex 文件处理
    if (p.size() >= 4 && p.substr(p.size() - 4) == ".txt") {
        auto raw = readFile(path);
        if (raw.empty()) return {};
        // 提取所有 hex 字符（跳过注释行、空白）
        std::string hex;
        hex.reserve(raw.size());
        bool inComment = false;
        for (uint8_t c : raw) {
            if (c == '#' || c == '<') { inComment = true; continue; }
            if (c == '\n') { inComment = false; continue; }
            if (inComment) continue;
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
                hex += (char)c;
        }
        return hexToBytes(hex);
    }
    // 否则直接读二进制
    return readFile(path);
}

static bool writeFile(const char *path, const std::vector<uint8_t> &data) {
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write: %s\n", path); return false; }
    fwrite(data.data(), 1, data.size(), f);
    fclose(f);
    return true;
}

// ─────────── hex 工具（继续）───────────

static std::string bytesToHex(const uint8_t *data, size_t size) {
    static const char hex[] = "0123456789abcdef";
    std::string out;
    out.reserve(size * 2);
    for (size_t i = 0; i < size; i++) {
        out += hex[(data[i] >> 4) & 0xF];
        out += hex[data[i] & 0xF];
    }
    return out;
}

// ─────────── zstd ───────────

static size_t parsePixHeader(const std::vector<uint8_t> &d) {
    if (d.size() < 8 + 2 + 1) return 0;
    if (memcmp(d.data(), PIX_MAGIC, 8) != 0) return 0;
    size_t pos = 8 + 2;
    uint8_t metaLen = d[pos++];
    pos += metaLen;
    return (pos < d.size()) ? pos : 0;
}

static std::vector<uint8_t> decompressZstd(const uint8_t *src, size_t srcSize) {
    unsigned long long cs = ZSTD_getFrameContentSize(src, srcSize);
    if (cs == ZSTD_CONTENTSIZE_ERROR) { fprintf(stderr, "bad zstd frame\n"); return {}; }
    size_t dstSize = (cs == ZSTD_CONTENTSIZE_UNKNOWN) ? srcSize * 8 : (size_t)cs;
    std::vector<uint8_t> dst(dstSize);
    size_t r = ZSTD_decompress(dst.data(), dstSize, src, srcSize);
    if (ZSTD_isError(r)) { fprintf(stderr, "zstd error: %s\n", ZSTD_getErrorName(r)); return {}; }
    dst.resize(r);
    return dst;
}

static std::vector<uint8_t> compressZstd(const uint8_t *src, size_t srcSize) {
    size_t bound = ZSTD_compressBound(srcSize);
    std::vector<uint8_t> dst(bound);
    size_t r = ZSTD_compress(dst.data(), bound, src, srcSize, 3 /* level */);
    if (ZSTD_isError(r)) { fprintf(stderr, "compress error: %s\n", ZSTD_getErrorName(r)); return {}; }
    dst.resize(r);
    return dst;
}

// ─────────── 构造 .pix 文件 ───────────

static std::vector<uint8_t> buildPixFile(const std::vector<uint8_t> &compressed) {
    std::vector<uint8_t> out;
    // magic
    out.insert(out.end(), PIX_MAGIC, PIX_MAGIC + 8);
    // version
    out.push_back(PIX_VERSION[0]);
    out.push_back(PIX_VERSION[1]);
    // meta length + meta string
    uint8_t metaLen = (uint8_t)strlen(PIX_META);
    out.push_back(metaLen);
    out.insert(out.end(), PIX_META, PIX_META + metaLen);
    // compressed payload
    out.insert(out.end(), compressed.begin(), compressed.end());
    return out;
}

// ─────────── GUID helper ───────────

struct GUIDKey {
    uint32_t session = 0, local = 0;
    bool operator<(const GUIDKey &o) const {
        return session != o.session ? session < o.session : local < o.local;
    }
    std::string str() const {
        char buf[32]; snprintf(buf, sizeof(buf), "{%u,%u}", session, local);
        return buf;
    }
};

static GUIDKey toKey(const GUID *g) {
    if (!g) return {};
    return { g->sessionID() ? *g->sessionID() : 0,
             g->localID()   ? *g->localID()   : 0 };
}

// ─────────── 组件集解析结果 ───────────

struct CompSetData {
    // 原始 PixsoMsg（pool 持有内存，msg 持有节点）
    kiwi::MemoryPool pool;
    PixsoMsg msg;

    // 顶层 SYMBOL 列表（供用户选择）
    struct SymInfo {
        uint32_t nodeIndex; // 在 pixsoNodes 数组中的下标
        GUIDKey  guid;
        std::string name;
        float w = 0, h = 0;
    };
    std::vector<SymInfo> symbols;
    uint32_t rootIndex = 0; // 根节点（SECTION/FRAME 容器）在数组中的下标
};

// ─────────── 解析组件集 hex ───────────

static bool parseCompSet(const std::vector<uint8_t> &raw, CompSetData &cs) {
    size_t off = parsePixHeader(raw);
    if (!off) { fprintf(stderr, "bad pix header\n"); return false; }

    auto dec = decompressZstd(raw.data() + off, raw.size() - off);
    if (dec.empty()) return false;

    kiwi::ByteBuffer bb(dec.data(), dec.size());
    if (!cs.msg.decode(bb, cs.pool)) { fprintf(stderr, "decode failed\n"); return false; }

    auto *nodes = cs.msg.pixsoNodes();
    if (!nodes || nodes->size() == 0) return false;

    // 节点[0] 是根容器（SECTION/FRAME）
    cs.rootIndex = 0;

    // 收集所有 SYMBOL
    for (uint32_t i = 0; i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        if (!n.type() || *n.type() != NodeType::SYMBOL) continue;

        CompSetData::SymInfo si;
        si.nodeIndex = i;
        si.guid = toKey(n.guid());
        si.name = n.name() ? n.name()->c_str() : "";
        if (n.size()) {
            si.w = n.size()->x() ? *n.size()->x() : 0;
            si.h = n.size()->y() ? *n.size()->y() : 0;
        }
        cs.symbols.push_back(si);
    }
    return true;
}

// ─────────── GUID / ParentIndex 构造辅助 ───────────

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

// ─────────── 核心：组件集全量节点 + 1 个 INSTANCE ───────────
//
// 流程：
//   1. 原样保留组件集的 N 个节点
//   2. 把根节点（index=0）的 parentIndex.guid 改为 {0,2}（隐藏页）
//   3. 新增 1 个 INSTANCE 节点：
//        guid         = {instSession, instLocal}（新分配）
//        symbolID     = 用户选中的 SYMBOL 的原始 GUID
//        parentIndex  = {0,1}（可见页，或用户指定）
//        transform    = 平移到 (x, y)
//        size         = 与 SYMBOL 一致
//   输出节点数 = N + 1

static std::vector<uint8_t> buildInstanceMsg(
    CompSetData &cs,
    const CompSetData::SymInfo &chosen,
    uint32_t instSession, uint32_t instLocal,  // 新 INSTANCE 的 GUID
    GUIDKey instParent, const std::string &instPos,
    float x, float y
) {
    auto *nodes = cs.msg.pixsoNodes();
    uint32_t N = nodes->size();

    // ── 收集所有节点的 GUID 集合 ──
    std::set<std::pair<uint32_t,uint32_t>> guidSet;
    for (uint32_t i = 0; i < N; i++) {
        const PixsoNode &n = (*nodes)[i];
        if (n.guid() && n.guid()->sessionID() && n.guid()->localID())
            guidSet.insert({*n.guid()->sessionID(), *n.guid()->localID()});
    }

    // ── 凡是 parentIndex 不在消息内的节点，parent 统一改为 {0,2} 隐藏页 ──
    // 这样可以避免组件库内的 {0,1}（库的 Internal Only Canvas）和
    // 设计文件的 {0,1}（可见页）发生 GUID 冲突
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

    // ── 构造新 INSTANCE 节点 ──
    PixsoNode *inst = cs.pool.allocate<PixsoNode>(); new (inst) PixsoNode();

    inst->set_guid(makeGUID(cs.pool, instSession, instLocal));
    inst->set_type(NodeType::INSTANCE);
    inst->set_phase(NodePhase::CREATED);
    inst->set_name(cs.pool.string(chosen.name.c_str()));
    inst->set_visible(true);
    inst->set_parentIndex(makeParent(cs.pool, instParent.session, instParent.local, instPos));

    Matrix *mat = cs.pool.allocate<Matrix>(); new (mat) Matrix();
    mat->set_m00(1.f); mat->set_m01(0.f); mat->set_m02(x);
    mat->set_m10(0.f); mat->set_m11(1.f); mat->set_m12(y);
    inst->set_transform(mat);

    Vector *sz = cs.pool.allocate<Vector>(); new (sz) Vector();
    sz->set_x(chosen.w); sz->set_y(chosen.h);
    inst->set_size(sz);

    SymbolData *sd = cs.pool.allocate<SymbolData>(); new (sd) SymbolData();
    sd->set_symbolID(makeGUID(cs.pool, chosen.guid.session, chosen.guid.local));
    inst->set_symbolData(sd);

    // ── 组装 PixsoMsg（N + 1 个节点）──
    PixsoMsg out;
    out.set_type(PixsoMsgType::NODE_CHANGES);

    auto &arr = out.set_pixsoNodes(cs.pool, N + 1);
    for (uint32_t i = 0; i < N; i++) arr[i] = (*nodes)[i];
    arr[N] = *inst;

    kiwi::ByteBuffer bb;
    if (!out.encode(bb)) { fprintf(stderr, "encode failed\n"); return {}; }
    return std::vector<uint8_t>(bb.data(), bb.data() + bb.size());
}

// ─────────── main ───────────

static void printUsage(const char *prog) {
    fprintf(stderr,
        "Usage:\n"
        "  %s list  <complib.pix>              列出所有 SYMBOL\n"
        "  %s create <complib.pix> <symbol_name_or_index> [x y] [out.pix]\n"
        "  %s create-hex <hex_string> <symbol_name_or_index> [x y]\n\n"
        "示例:\n"
        "  %s list   '../HarmonyOS Component Library（来自社区）.pix'\n"
        "  %s create '../HarmonyOS Component Library（来自社区）.pix' 'TitleBar-Drawer-Phone' 100 200 out.pix\n",
        prog, prog, prog, prog, prog);
}

int main(int argc, char **argv) {
    if (argc < 3) { printUsage(argv[0]); return 1; }

    std::string cmd = argv[1];

    // ─── 读取组件集原始数据 ───
    std::vector<uint8_t> raw;
    if (cmd == "create-hex") {
        raw = hexToBytes(argv[2]);
    } else {
        raw = loadPixData(argv[2]);
    }
    if (raw.empty()) return 1;

    // ─── 解析组件集（全量节点 + SYMBOL 列表）───
    CompSetData cs;
    if (!parseCompSet(raw, cs)) { fprintf(stderr, "parse failed\n"); return 1; }

    auto *allNodes = cs.msg.pixsoNodes();
    uint32_t N = allNodes ? allNodes->size() : 0;

    // ─── list 命令 ───
    if (cmd == "list") {
        printf("组件集节点总数: %u，其中 SYMBOL: %zu\n\n", N, cs.symbols.size());
        printf("%-6s %-20s %-8s %-8s %s\n", "index", "GUID", "width", "height", "name");
        printf("%-6s %-20s %-8s %-8s %s\n", "------", "--------------------", "------", "------", "----");
        for (size_t i = 0; i < cs.symbols.size(); i++) {
            auto &s = cs.symbols[i];
            printf("%-6zu %-20s %-8.0f %-8.0f %s\n",
                i, s.guid.str().c_str(), s.w, s.h, s.name.c_str());
        }
        return 0;
    }

    // ─── create 命令 ───
    if (cmd != "create" && cmd != "create-hex") { printUsage(argv[0]); return 1; }
    if (argc < 4) { printUsage(argv[0]); return 1; }

    // 查找目标 SYMBOL
    std::string target = argv[3];
    const CompSetData::SymInfo *chosen = nullptr;

    bool isIndex = !target.empty() &&
                   std::all_of(target.begin(), target.end(), ::isdigit);
    if (isIndex) {
        size_t idx = std::stoul(target);
        if (idx < cs.symbols.size()) chosen = &cs.symbols[idx];
        else { fprintf(stderr, "index %zu out of range (max %zu)\n", idx, cs.symbols.size()-1); return 1; }
    } else {
        for (auto &s : cs.symbols) if (s.name == target) { chosen = &s; break; }
        if (!chosen)
            for (auto &s : cs.symbols)
                if (s.name.find(target) != std::string::npos) { chosen = &s; break; }
    }

    if (!chosen) {
        fprintf(stderr, "找不到 SYMBOL: \"%s\"\n", target.c_str());
        return 1;
    }

    // 可选参数
    float x = 0, y = 0;
    std::string outPath = "instance_out.txt";
    if (argc > 4) x = atof(argv[4]);
    if (argc > 5) y = atof(argv[5]);
    if (argc > 6) outPath = argv[6];

    // INSTANCE 的 GUID（新分配）和父节点
    uint32_t instSession = 1, instLocal = 9999;
    GUIDKey instParent = {0, 1};
    std::string instPos = "a0";

    // 根节点信息
    const PixsoNode &rootNode = (*allNodes)[cs.rootIndex];
    std::string rootName = rootNode.name() ? rootNode.name()->c_str() : "";

    printf("=== 创建实例（全量节点 + INSTANCE）===\n");
    printf("  组件集根节点     : \"%s\"（节点数 N=%u）\n", rootName.c_str(), N);
    printf("  根节点 parent    : {0,2}（隐藏页，已修改）\n");
    printf("  选中 SYMBOL      : \"%s\"  guid=%s\n", chosen->name.c_str(), chosen->guid.str().c_str());
    printf("  INSTANCE guid    : {%u,%u}  parent=%s  pos=(%.0f,%.0f)\n",
           instSession, instLocal, instParent.str().c_str(), x, y);
    printf("  输出节点数       : N+1 = %u\n", N + 1);

    // ── 构造消息 ──
    auto kiwiBytes = buildInstanceMsg(cs, *chosen, instSession, instLocal,
                                      instParent, instPos, x, y);
    if (kiwiBytes.empty()) return 1;

    printf("\n  kiwi 编码大小 : %zu bytes\n", kiwiBytes.size());

    // ── zstd 压缩 ──
    auto compressed = compressZstd(kiwiBytes.data(), kiwiBytes.size());
    if (compressed.empty()) return 1;

    printf("  zstd 压缩大小 : %zu bytes\n", compressed.size());

    // ── 构造 .pix 文件 ──
    auto pixFile = buildPixFile(compressed);
    printf("  .pix 文件大小 : %zu bytes\n", pixFile.size());

    // ── 输出 hex ──
    std::string hexOut = bytesToHex(pixFile.data(), pixFile.size());
    printf("\n=== 输出 hex ===\n%s\n", hexOut.c_str());

    // ── 保存文件：.txt 存 hex 字符串，其他存二进制 ──
    bool isTxt = outPath.size() >= 4 &&
                 outPath.substr(outPath.size() - 4) == ".txt";
    if (isTxt) {
        std::string content = "<!-- pixso binary data -->\n" + hexOut;
        std::vector<uint8_t> hexBytes(content.begin(), content.end());
        if (writeFile(outPath.c_str(), hexBytes))
            printf("\n已保存 hex 到: %s  (%zu 字符)\n", outPath.c_str(), hexOut.size());
    } else {
        if (writeFile(outPath.c_str(), pixFile))
            printf("\n已保存二进制到: %s  (%zu bytes)\n", outPath.c_str(), pixFile.size());
    }

    // ── 验证：重新解析生成的文件 ──
    printf("\n=== 验证：重新解析生成的 .pix ===\n");
    size_t off = parsePixHeader(pixFile);
    if (off) {
        auto dec = decompressZstd(pixFile.data() + off, pixFile.size() - off);
        if (!dec.empty()) {
            kiwi::ByteBuffer bb2(dec.data(), dec.size());
            kiwi::MemoryPool pool2;
            PixsoMsg msg2;
            if (msg2.decode(bb2, pool2)) {
                auto *nodes = msg2.pixsoNodes();
                printf("  解析成功，节点数: %u\n", nodes ? nodes->size() : 0);
                for (uint32_t ni = 0; nodes && ni < nodes->size(); ni++) {
                    const PixsoNode &n = (*nodes)[ni];
                    uint32_t t = n.type() ? (uint32_t)*n.type() : 0;
                    const char *tn = t==16?"SYMBOL":t==17?"INSTANCE":"?";
                    uint32_t gs=0,gl=0,ps=0,pl=0;
                    if (n.guid()) {
                        gs = n.guid()->sessionID()?*n.guid()->sessionID():0;
                        gl = n.guid()->localID()?*n.guid()->localID():0;
                    }
                    if (n.parentIndex()&&n.parentIndex()->guid()) {
                        ps = n.parentIndex()->guid()->sessionID()?*n.parentIndex()->guid()->sessionID():0;
                        pl = n.parentIndex()->guid()->localID()?*n.parentIndex()->guid()->localID():0;
                    }
                    printf("  节点[%u]: %-8s guid={%u,%u}  parent={%u,%u}  name=%s\n",
                        ni,tn,gs,gl,ps,pl,n.name()?n.name()->c_str():"");
                    if (n.symbolData()&&n.symbolData()->symbolID()) {
                        const GUID *sg=n.symbolData()->symbolID();
                        printf("          symbolID={%u,%u}\n",
                            sg->sessionID()?*sg->sessionID():0,
                            sg->localID()?*sg->localID():0);
                    }
                }
            } else {
                printf("  decode 失败\n");
            }
        }
    }

    return 0;
}
