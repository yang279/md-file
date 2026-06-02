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

// =============================================================================
// 文件 I/O / pix 格式
// =============================================================================

static std::vector<uint8_t> readFile(const char *path) {
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "cannot open: %s\n", path); return {}; }
    fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> buf(sz); fread(buf.data(), 1, sz, f); fclose(f);
    return buf;
}
static bool writeFile(const char *path, const std::vector<uint8_t> &d) {
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write: %s\n", path); return false; }
    fwrite(d.data(), 1, d.size(), f); fclose(f); return true;
}

static const char PIX_MAGIC[] = "pixso-kw";
static const char PIX_META[]  = "compress:zstd";

static size_t parsePixHeader(const std::vector<uint8_t> &d) {
    if (d.size() < 12 || memcmp(d.data(), PIX_MAGIC, 8) != 0) return 0;
    size_t pos = 10; pos += d[pos] + 1; // skip metaLen + meta
    return (pos < d.size()) ? pos : 0;
}

static std::vector<uint8_t> decompressZstd(const uint8_t *src, size_t sz) {
    unsigned long long cs = ZSTD_getFrameContentSize(src, sz);
    if (cs == ZSTD_CONTENTSIZE_ERROR) { fprintf(stderr, "bad zstd frame\n"); return {}; }
    size_t dstSz = (cs == ZSTD_CONTENTSIZE_UNKNOWN) ? sz * 8 : (size_t)cs;
    std::vector<uint8_t> dst(dstSz);
    size_t r = ZSTD_decompress(dst.data(), dstSz, src, sz);
    if (ZSTD_isError(r)) { fprintf(stderr, "zstd: %s\n", ZSTD_getErrorName(r)); return {}; }
    dst.resize(r); return dst;
}

static std::vector<uint8_t> compressToPix(const std::vector<uint8_t> &kiwiBin) {
    size_t bound = ZSTD_compressBound(kiwiBin.size());
    std::vector<uint8_t> comp(bound);
    size_t r = ZSTD_compress(comp.data(), bound, kiwiBin.data(), kiwiBin.size(), 3);
    if (ZSTD_isError(r)) return {};
    comp.resize(r);
    std::vector<uint8_t> out;
    out.insert(out.end(), PIX_MAGIC, PIX_MAGIC + 8);
    out.push_back(0x00); out.push_back(0x02);
    uint8_t ml = (uint8_t)strlen(PIX_META);
    out.push_back(ml);
    out.insert(out.end(), PIX_META, PIX_META + ml);
    out.insert(out.end(), comp.begin(), comp.end());
    return out;
}

static std::string bytesToHex(const std::vector<uint8_t> &d) {
    static const char H[] = "0123456789abcdef";
    std::string r; r.reserve(d.size() * 2);
    for (uint8_t b : d) { r += H[b >> 4]; r += H[b & 0xF]; }
    return r;
}

// hex txt 文件读取（支持 <!-- --> 注释行）
static std::vector<uint8_t> loadHexFile(const char *path) {
    auto raw = readFile(path);
    if (raw.empty()) return {};
    std::string hex; hex.reserve(raw.size());
    bool skip = false;
    for (uint8_t c : raw) {
        if (c == '<' || c == '#') { skip = true; continue; }
        if (c == '\n') { skip = false; continue; }
        if (skip) continue;
        if ((c>='0'&&c<='9')||(c>='a'&&c<='f')||(c>='A'&&c<='F')) hex += (char)c;
    }
    std::vector<uint8_t> out;
    for (size_t i = 0; i + 1 < hex.size(); i += 2) {
        auto h = [](char c) -> uint8_t {
            if (c>='0'&&c<='9') return c-'0';
            if (c>='a'&&c<='f') return c-'a'+10;
            return c-'A'+10;
        };
        out.push_back((h(hex[i])<<4)|h(hex[i+1]));
    }
    return out;
}

// =============================================================================
// GUID / 节点索引
// =============================================================================

struct GK {
    uint32_t s=0, l=0;
    bool operator<(const GK &o)  const { return s!=o.s?s<o.s:l<o.l; }
    bool operator==(const GK &o) const { return s==o.s&&l==o.l; }
    bool isNull() const { return s==0&&l==0; }
    std::string str() const { char b[32]; snprintf(b,32,"{%u,%u}",s,l); return b; }
};

static GK gkOf(const GUID *g) {
    if (!g) return {};
    return {g->sessionID()?*g->sessionID():0, g->localID()?*g->localID():0};
}

struct NodeInfo {
    GK guid, parent, symbolID;
    std::string parentPos, name;
    uint32_t typeVal = 0;
    const PixsoNode *raw = nullptr;
};

struct LibIdx {
    kiwi::MemoryPool pool;
    PixsoMsg msg;
    std::map<GK, NodeInfo> byGuid;
    std::map<GK, std::vector<GK>> children;
};

static bool buildIdx(const std::vector<uint8_t> &pixData, LibIdx &li) {
    size_t off = parsePixHeader(pixData);
    if (!off) { fprintf(stderr, "bad pix header\n"); return false; }
    auto dec = decompressZstd(pixData.data()+off, pixData.size()-off);
    if (dec.empty()) return false;
    kiwi::ByteBuffer bb(dec.data(), dec.size());
    if (!li.msg.decode(bb, li.pool)) { fprintf(stderr, "kiwi decode failed\n"); return false; }
    auto *nodes = li.msg.pixsoNodes();
    if (!nodes) return false;
    for (uint32_t i = 0; i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        NodeInfo ni;
        ni.guid    = gkOf(n.guid());
        ni.parent  = gkOf(n.parentIndex() ? n.parentIndex()->guid() : nullptr);
        ni.parentPos = (n.parentIndex()&&n.parentIndex()->position())
                       ? n.parentIndex()->position()->c_str() : "";
        ni.typeVal = n.type() ? (uint32_t)*n.type() : 0;
        ni.name    = n.name() ? n.name()->c_str() : "";
        ni.symbolID = (ni.typeVal==17 && n.symbolData())
                      ? gkOf(n.symbolData()->symbolID()) : GK{};
        ni.raw = &n;
        if (!ni.guid.isNull()) {
            li.byGuid[ni.guid] = ni;
            li.children[ni.parent].push_back(ni.guid);
        }
    }
    for (auto &[pg, cv] : li.children) {
        std::sort(cv.begin(), cv.end(), [&](const GK &a, const GK &b) {
            return li.byGuid[a].parentPos < li.byGuid[b].parentPos;
        });
    }
    return true;
}

// =============================================================================
// 新 GUID 分配（固定 session=0xD001，local 自增）
// =============================================================================

static uint32_t gSession = 0xD001;
static uint32_t gLocal   = 1;
static GK nextGuid() { return {gSession, gLocal++}; }

static GUID* mkGUID(kiwi::MemoryPool &pool, uint32_t s, uint32_t l) {
    GUID *g = pool.allocate<GUID>(); new(g) GUID();
    g->set_sessionID(s); g->set_localID(l);
    return g;
}
static ParentIndex* mkParent(kiwi::MemoryPool &pool,
                              uint32_t ps, uint32_t pl, const char *pos) {
    ParentIndex *pi = pool.allocate<ParentIndex>(); new(pi) ParentIndex();
    pi->set_guid(mkGUID(pool, ps, pl));
    pi->set_position(pool.string(pos));
    return pi;
}
static std::string makePos(int i) {
    char b[16]; snprintf(b, 16, "a%08x", (unsigned)i); return b;
}

// =============================================================================
// 核心：递归复制子树，深度解绑
//
// 设计重点：
//   1. *n = *ni.raw  浅拷贝原始节点（transform/size/fillPaints 等保留原始指针）
//   2. 覆盖 guid / parentIndex（指向 outPool 中的新对象）
//   3. 原始 pool（li.pool）在 encode 前不析构，所有原始指针仍有效
//   4. 遇到 INSTANCE 子节点时，递归展开其 SYMBOL 子树（深度解绑）
//   5. symVisited 记录已处理的 SYMBOL GUID，防止组件循环引用导致无限递归
// =============================================================================

// symPath：当前调用栈上正在展开的 SYMBOL 集合（路径跟踪）
// 只阻断 A→B→A 形式的直接循环引用，不阻断同 SYMBOL 在不同分支重复展开。
// 这样每个 INSTANCE 出现几次就能展开几次，得到完整的独立图层副本。
static void copySubtree(
    const GK          &src,
    const GK          &dstParent,
    const std::string &dstPos,
    const LibIdx      &li,
    kiwi::MemoryPool  &outPool,
    std::vector<PixsoNode*> &outNodes,
    bool               isRoot,
    std::set<GK>      &symPath  // 当前路径上的 SYMBOL（进入时插入，退出时删除）
) {
    auto it = li.byGuid.find(src);
    if (it == li.byGuid.end()) return;
    const NodeInfo &ni = it->second;

    GK newG = nextGuid();

    // ── 深解绑：遇到 INSTANCE 子节点，且其 SYMBOL 在本 hex 中可找到 ──
    if (!isRoot
        && ni.typeVal == 17 /*INSTANCE*/
        && !ni.symbolID.isNull()
        && li.byGuid.count(ni.symbolID)
        && !symPath.count(ni.symbolID))  // 仅阻断当前路径上的直接循环
    {
        symPath.insert(ni.symbolID);  // 进入

        // 以 INSTANCE 的属性创建 FRAME
        PixsoNode *n = outPool.allocate<PixsoNode>(); new(n) PixsoNode();
        if (ni.raw) *n = *ni.raw;
        n->set_type(NodeType::FRAME);
        n->set_guid(mkGUID(outPool, newG.s, newG.l));
        n->set_parentIndex(mkParent(outPool, dstParent.s, dstParent.l, dstPos.c_str()));
        outNodes.push_back(n);

        // 展开 SYMBOL 的子节点
        auto cit = li.children.find(ni.symbolID);
        if (cit != li.children.end()) {
            int idx = 0;
            for (const GK &child : cit->second)
                copySubtree(child, newG, makePos(idx++), li, outPool, outNodes, false, symPath);
        }

        symPath.erase(ni.symbolID);  // 退出（允许后续分支再次展开同一 SYMBOL）
        return;
    }

    // ── 普通节点（SYMBOL 根 → FRAME，其他类型保持不变）──
    PixsoNode *n = outPool.allocate<PixsoNode>(); new(n) PixsoNode();
    if (ni.raw) *n = *ni.raw;

    n->set_guid(mkGUID(outPool, newG.s, newG.l));
    n->set_parentIndex(mkParent(outPool, dstParent.s, dstParent.l, dstPos.c_str()));
    if (isRoot && ni.typeVal == 16 /*SYMBOL*/) {
        n->set_type(NodeType::FRAME);
        symPath.insert(src);  // 进入（顶层 SYMBOL 自身加入路径）
    }

    outNodes.push_back(n);

    auto cit = li.children.find(src);
    if (cit != li.children.end()) {
        int idx = 0;
        for (const GK &child : cit->second)
            copySubtree(child, newG, makePos(idx++), li, outPool, outNodes, false, symPath);
    }

    if (isRoot && ni.typeVal == 16) symPath.erase(src);  // 退出顶层 SYMBOL
}

// =============================================================================
// 统计子树节点数（用于日志）
// =============================================================================
static int countTree(const GK &root, const LibIdx &li) {
    if (!li.byGuid.count(root)) return 0;
    int n = 1;
    auto it = li.children.find(root);
    if (it != li.children.end())
        for (auto &c : it->second) n += countTree(c, li);
    return n;
}

// =============================================================================
// 验证：打印输出 hex 的节点树
// =============================================================================
static void verifyOutput(const std::vector<uint8_t> &pixData) {
    size_t off = parsePixHeader(pixData);
    if (!off) { fprintf(stderr, "verify: bad header\n"); return; }
    auto dec = decompressZstd(pixData.data()+off, pixData.size()-off);
    if (dec.empty()) return;
    kiwi::ByteBuffer bb(dec.data(), dec.size());
    kiwi::MemoryPool pool; PixsoMsg msg;
    if (!msg.decode(bb, pool)) { fprintf(stderr, "verify: decode failed\n"); return; }
    auto *nodes = msg.pixsoNodes();
    printf("  [OK] 节点总数: %u\n\n", nodes ? nodes->size() : 0);

    static const char *TN[] = {"?","NONE","DOCUMENT","CANVAS","GROUP","FRAME",
                                "BOOL","VECTOR","STAR","LINE","ELLIPSE","RECT",
                                "RPOLY","ROUNR","TEXT","SLICE","SYMBOL","INSTANCE"};
    auto tn = [](uint32_t t) -> std::string {
        if (t < 18) return TN[t];
        char b[20]; snprintf(b,20,"type(%u)",t); return b;
    };

    for (uint32_t i = 0; nodes && i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        uint32_t t  = n.type() ? (uint32_t)*n.type() : 0;
        uint32_t gs = (n.guid()&&n.guid()->sessionID()) ? *n.guid()->sessionID() : 0;
        uint32_t gl = (n.guid()&&n.guid()->localID())   ? *n.guid()->localID()   : 0;
        uint32_t ps=0, pl=0;
        if (n.parentIndex()&&n.parentIndex()->guid()) {
            ps = n.parentIndex()->guid()->sessionID() ? *n.parentIndex()->guid()->sessionID() : 0;
            pl = n.parentIndex()->guid()->localID()   ? *n.parentIndex()->guid()->localID()   : 0;
        }
        uint32_t nFills = n.fillPaints() ? n.fillPaints()->size() : 0;
        printf("  [%2u] %-8s guid={%u,%u} parent={%u,%u} fills=%u  \"%s\"\n",
               i, tn(t).c_str(), gs, gl, ps, pl, nFills,
               n.name() ? n.name()->c_str() : "");
        // print fill colors
        for (uint32_t fi = 0; fi < nFills; fi++) {
            const Paint &p = (*n.fillPaints())[fi];
            if (p.color()) {
                auto *c = p.color();
                printf("       fill rgba=(%.0f,%.0f,%.0f,%.0f)\n",
                       c->r()?*c->r():0.f, c->g()?*c->g():0.f,
                       c->b()?*c->b():0.f, c->a()?*c->a():0.f);
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
            "Usage: %s <input.txt> <output.txt>\n\n"
            "将输入 hex 中的所有 INSTANCE 节点解绑为普通图层（FRAME）\n"
            "输入：gen_instance 生成的 hex txt（含 INSTANCE + 组件集节点）\n"
            "输出：解绑后的 hex txt（仅含 DOCUMENT + CANVAS + FRAME 子树）\n",
            argv[0]);
        return 1;
    }

    printf("=== 组件解绑（detach instance）===\n");

    // ── 读取输入 ──
    auto pixData = loadHexFile(argv[1]);
    if (pixData.empty()) { fprintf(stderr, "读取失败: %s\n", argv[1]); return 1; }
    printf("  pix 大小: %zu bytes\n", pixData.size());

    // ── 解析索引 ──
    LibIdx li;
    if (!buildIdx(pixData, li)) return 1;
    printf("  节点总数: %zu\n", li.byGuid.size());

    // ── 找出所有 INSTANCE 节点 ──
    std::vector<GK> instances;
    for (auto &[g, ni] : li.byGuid)
        if (ni.typeVal == 17) instances.push_back(g);

    // ── 尝试找组件集根 FRAME 及其直接 SYMBOL 变体 ──
    // pix-split 的 encodeNodes 把组件集根节点放在 pixsoNodes[0]，
    // 所以直接用第 0 个节点作为根，无需遍历排序。
    std::vector<GK> variantSymbols;
    {
        auto *rawNodes = li.msg.pixsoNodes();
        GK compSetRoot = {};
        if (rawNodes && rawNodes->size() > 0) {
            const PixsoNode &first = (*rawNodes)[0];
            uint32_t t = first.type() ? (uint32_t)*first.type() : 0;
            if (t == 5 /*FRAME*/) {  // 只有 isStateGroup FRAME 才有变体
                compSetRoot = gkOf(first.guid());
            }
        }
        if (!compSetRoot.isNull()) {
            const NodeInfo &root = li.byGuid.at(compSetRoot);
            printf("  组件集根节点: \"%s\" (FRAME)\n", root.name.c_str());
            auto cit = li.children.find(compSetRoot);
            if (cit != li.children.end()) {
                for (const GK &child : cit->second) {
                    if (li.byGuid.at(child).typeVal == 16 /*SYMBOL*/)
                        variantSymbols.push_back(child);
                }
            }
            if (!variantSymbols.empty())
                printf("  发现变体 SYMBOL: %zu 个\n", variantSymbols.size());
        }
    }

    // 优先级：变体模式 > INSTANCE 模式
    // 有变体 SYMBOL 时，INSTANCE 节点是变体内部的嵌套引用，由 copySubtree 深度展开
    bool useVariantMode = !variantSymbols.empty();
    printf("  INSTANCE 数: %zu  变体 SYMBOL 数: %zu  → %s模式\n\n",
           instances.size(), variantSymbols.size(),
           useVariantMode ? "变体" : "INSTANCE ");

    if (!useVariantMode && instances.empty()) {
        fprintf(stderr, "未找到 INSTANCE 或可解绑的变体\n"); return 1;
    }

    // ── 构建输出 pool 和节点列表 ──
    kiwi::MemoryPool outPool;
    std::vector<PixsoNode*> outNodes;

    // DOCUMENT {0,0}
    {
        PixsoNode *d = outPool.allocate<PixsoNode>(); new(d) PixsoNode();
        d->set_type(NodeType::DOCUMENT); d->set_phase(NodePhase::CREATED);
        d->set_guid(mkGUID(outPool, 0, 0));
        d->set_name(outPool.string("Document")); d->set_visible(true);
        outNodes.push_back(d);
    }

    // 可见 CANVAS {0,1}
    {
        PixsoNode *cv = outPool.allocate<PixsoNode>(); new(cv) PixsoNode();
        cv->set_type(NodeType::CANVAS); cv->set_phase(NodePhase::CREATED);
        cv->set_guid(mkGUID(outPool, 0, 1));
        cv->set_name(outPool.string("页面 1")); cv->set_visible(true);
        cv->set_parentIndex(mkParent(outPool, 0, 0, makePos(0).c_str()));
        outNodes.push_back(cv);
    }

    int detachCount = 0;

    // ── 模式 A：解绑 INSTANCE 节点（仅在无变体 SYMBOL 时使用）──
    for (const GK &instGuid : useVariantMode ? std::vector<GK>{} : instances) {
        const NodeInfo &inst = li.byGuid.at(instGuid);

        if (inst.symbolID.isNull()) {
            fprintf(stderr, "  [SKIP] INSTANCE %s 无 symbolID\n", instGuid.str().c_str());
            continue;
        }
        if (!li.byGuid.count(inst.symbolID)) {
            fprintf(stderr, "  [SKIP] SYMBOL %s 不在本 hex 中\n", inst.symbolID.str().c_str());
            continue;
        }
        const NodeInfo &sym = li.byGuid.at(inst.symbolID);
        printf("  解绑 INSTANCE: \"%s\" → SYMBOL \"%s\"（%d 节点）\n",
               inst.name.c_str(), sym.name.c_str(), countTree(inst.symbolID, li));

        size_t rootIdx = outNodes.size();
        std::set<GK> symVisited;
        copySubtree(inst.symbolID, {0,1}, makePos(detachCount++), li, outPool, outNodes, true, symVisited);

        // 覆盖 root 的 transform / size 为 INSTANCE 的实际值
        if (inst.raw && rootIdx < outNodes.size()) {
            PixsoNode *root = outNodes[rootIdx];
            if (inst.raw->transform()) {
                Matrix *mat = outPool.allocate<Matrix>(); new(mat) Matrix();
                *mat = *inst.raw->transform();
                root->set_transform(mat);
            }
            if (inst.raw->size()) {
                Vector *sz = outPool.allocate<Vector>(); new(sz) Vector();
                *sz = *inst.raw->size();
                root->set_size(sz);
            }
            if (inst.raw->name())
                root->set_name(outPool.string(inst.raw->name()->c_str()));
        }
    }

    // ── 模式 B：解绑组件集变体 SYMBOL ──
    // 每个变体保留其在组件集内的原始 transform（位置相对于组件集根节点）
    for (const GK &symGuid : variantSymbols) {
        const NodeInfo &sym = li.byGuid.at(symGuid);
        printf("  解绑变体: \"%s\"（%d 节点）\n", sym.name.c_str(), countTree(symGuid, li));
        std::set<GK> symVisited;
        copySubtree(symGuid, {0,1}, makePos(detachCount++), li, outPool, outNodes, true, symVisited);
    }

    // 隐藏 CANVAS {0,2}
    {
        PixsoNode *hv = outPool.allocate<PixsoNode>(); new(hv) PixsoNode();
        hv->set_type(NodeType::CANVAS); hv->set_phase(NodePhase::CREATED);
        hv->set_guid(mkGUID(outPool, 0, 2));
        hv->set_name(outPool.string("__internal__")); hv->set_visible(false);
        hv->set_internalOnly(true);
        hv->set_parentIndex(mkParent(outPool, 0, 0, makePos(1).c_str()));
        outNodes.push_back(hv);
    }

    printf("\n  输出节点总数: %zu\n", outNodes.size());

    // ── 编码 & 输出 ──
    PixsoMsg outMsg; outMsg.set_type(PixsoMsgType::NODE_CHANGES);
    auto &arr = outMsg.set_pixsoNodes(outPool, (uint32_t)outNodes.size());
    for (size_t i = 0; i < outNodes.size(); i++) arr[i] = *outNodes[i];

    kiwi::ByteBuffer bb;
    if (!outMsg.encode(bb)) { fprintf(stderr, "encode failed\n"); return 1; }

    auto kiwiBin = std::vector<uint8_t>(bb.data(), bb.data()+bb.size());
    auto outPix  = compressToPix(kiwiBin);
    if (outPix.empty()) { fprintf(stderr, "compress failed\n"); return 1; }

    auto hexStr = bytesToHex(outPix);
    auto outStr = "<!-- pixso binary data -->\n" + hexStr;
    std::vector<uint8_t> outBytes(outStr.begin(), outStr.end());
    if (!writeFile(argv[2], outBytes)) return 1;
    printf("  已写入: %s  (%zu hex chars)\n\n", argv[2], hexStr.size());

    // ── 验证 ──
    printf("=== 验证（重新解析）===\n");
    verifyOutput(outPix);

    return 0;
}
