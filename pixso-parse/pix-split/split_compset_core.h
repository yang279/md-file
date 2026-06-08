#pragma once

// =============================================================================
// split_compset 共享核心逻辑（CLI 与 WASM 入口共用）
//
// 调用方需先 #define IMPLEMENT_KIWI_H / IMPLEMENT_SCHEMA_H 并包含
// kiwi.h / pixso.h / zstd.h，再包含本文件。
// =============================================================================

#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sys/stat.h>

// ─────────── 基础工具 ───────────

static std::vector<uint8_t> readFile(const char *p) {
    FILE *f = fopen(p, "rb"); if (!f) return {};
    fseek(f, 0, SEEK_END); long s = ftell(f); fseek(f, 0, SEEK_SET);
    std::vector<uint8_t> b(s); fread(b.data(), 1, s, f); fclose(f);
    return b;
}

static bool writeFile(const char *p, const std::vector<uint8_t> &d) {
    FILE *f = fopen(p, "wb"); if (!f) return false;
    fwrite(d.data(), 1, d.size(), f); fclose(f); return true;
}

struct GK {
    uint32_t s = 0, l = 0;
    bool operator<(const GK &o) const { return s != o.s ? s < o.s : l < o.l; }
    bool operator==(const GK &o) const { return s == o.s && l == o.l; }
    bool isNull() const { return s == 0 && l == 0; }
    std::string str() const { char b[32]; snprintf(b, 32, "{%u,%u}", s, l); return b; }
};

static GK gk(const GUID *g) {
    if (!g) return {};
    return { g->sessionID() ? *g->sessionID() : 0,
             g->localID()   ? *g->localID()   : 0 };
}

static std::string safeStr(const kiwi::String *s) { return s ? s->c_str() : ""; }

static std::string typeName(uint32_t t) {
    switch (t) {
        case 2:  return "DOCUMENT";
        case 3:  return "CANVAS";
        case 4:  return "GROUP";
        case 5:  return "FRAME";
        case 14: return "TEXT";
        case 11: return "RECTANGLE";
        case 7:  return "VECTOR";
        case 16: return "SYMBOL";
        case 17: return "INSTANCE";
        case 104:return "SECTION";
        default: return "type(" + std::to_string(t) + ")";
    }
}

// ─────────── .pix 解压/压缩 ───────────

static std::vector<uint8_t> decompressPix(const std::vector<uint8_t> &raw) {
    if (raw.size() < 12) return {};
    if (memcmp(raw.data(), "pixso-kw", 8) != 0) return {};
    size_t pos = 8 + 2;
    uint8_t ml = raw[pos++];
    pos += ml;  // skip "compress:zstd"
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

static std::string bytesToHex(const std::vector<uint8_t> &d) {
    static const char h[] = "0123456789abcdef";
    std::string r; r.reserve(d.size() * 2);
    for (uint8_t b : d) { r += h[b >> 4]; r += h[b & 0xF]; }
    return r;
}

// ─────────── SHA-1 ───────────

static std::string sha1hex(const std::string &data) {
    auto rol = [](uint32_t v, int n){ return (v << n) | (v >> (32 - n)); };
    uint32_t h0=0x67452301, h1=0xEFCDAB89, h2=0x98BADCFE, h3=0x10325476, h4=0xC3D2E1F0;

    std::vector<uint8_t> m(data.begin(), data.end());
    uint64_t bits = m.size() * 8;
    m.push_back(0x80);
    while (m.size() % 64 != 56) m.push_back(0);
    for (int i = 7; i >= 0; i--) m.push_back((bits >> (i*8)) & 0xFF);

    for (size_t i = 0; i < m.size(); i += 64) {
        uint32_t w[80];
        for (int j = 0; j < 16; j++)
            w[j] = ((uint32_t)m[i+j*4]<<24)|((uint32_t)m[i+j*4+1]<<16)|
                   ((uint32_t)m[i+j*4+2]<<8)|m[i+j*4+3];
        for (int j = 16; j < 80; j++)
            w[j] = rol(w[j-3]^w[j-8]^w[j-14]^w[j-16], 1);
        uint32_t a=h0, b=h1, c=h2, d=h3, e=h4;
        for (int j = 0; j < 80; j++) {
            uint32_t f, k;
            if      (j < 20) { f=(b&c)|(~b&d); k=0x5A827999; }
            else if (j < 40) { f=b^c^d;        k=0x6ED9EBA1; }
            else if (j < 60) { f=(b&c)|(b&d)|(c&d); k=0x8F1BBCDC; }
            else             { f=b^c^d;        k=0xCA62C1D6; }
            uint32_t t=rol(a,5)+f+e+k+w[j]; e=d; d=c; c=rol(b,30); b=a; a=t;
        }
        h0+=a; h1+=b; h2+=c; h3+=d; h4+=e;
    }
    char buf[41];
    snprintf(buf, 41, "%08x%08x%08x%08x%08x", h0, h1, h2, h3, h4);
    return buf;
}

// ─────────── 节点信息 ───────────

struct NodeRec {
    GK      guid;
    GK      parent;
    std::string parentPos;
    uint32_t typeVal  = 0;
    std::string name;
    GK      symbolID;       // 仅 INSTANCE 有效
    float   w = 0, h = 0;
    std::string componentKey;   // 组件 key（SYMBOL / isStateGroup FRAME 有效）
    bool    isStateGroup = false; // type==FRAME && isStateGroup==true → 组件集
    bool    isStyleMaster = false; // 有 sharedStyleMasterData 的样式主节点
    std::string styleKey;          // 样式主节点的 styleKey
    std::string styleRefKey;       // 该节点引用的 styleKey（sharedStyleReference）
    bool    internalOnly = false;  // CANVAS 节点且为隐藏页

    // 原始 PixsoNode 指针（用于 encode）
    const PixsoNode *raw = nullptr;
};

// ─────────── 解析库，建立全量索引 ───────────

struct LibIndex {
    // guid → NodeRec
    std::map<GK, NodeRec> byGuid;
    // parent → [children guids]（按 parentPos 排序）
    std::map<GK, std::vector<GK>> children;

    // 所有 PixsoNode 存活在 pool 里
    kiwi::MemoryPool pool;
    PixsoMsg msg;

    // 若外部传入 publishFile，则在 patchPublishInfo 中用于生成 componentKey
    std::string publishFile;

    // styleKey → guid（样式主节点索引）
    std::map<std::string, GK> styleByKey;
};

static bool buildIndex(const std::vector<uint8_t> &pixRaw, LibIndex &li) {
    auto dec = decompressPix(pixRaw);
    if (dec.empty()) { fprintf(stderr, "decompress failed\n"); return false; }

    kiwi::ByteBuffer bb(dec.data(), dec.size());
    if (!li.msg.decode(bb, li.pool)) { fprintf(stderr, "decode failed\n"); return false; }

    auto *nodes = li.msg.pixsoNodes();
    if (!nodes) return false;

    for (uint32_t i = 0; i < nodes->size(); i++) {
        const PixsoNode &n = (*nodes)[i];
        NodeRec r;
        r.guid   = gk(n.guid());
        r.parent = gk(n.parentIndex() ? n.parentIndex()->guid() : nullptr);
        r.parentPos = safeStr(n.parentIndex() ? n.parentIndex()->position() : nullptr);
        r.typeVal= n.type() ? (uint32_t)*n.type() : 0;
        r.name   = safeStr(n.name());
        r.symbolID = (r.typeVal == 17 && n.symbolData())
                     ? gk(n.symbolData()->symbolID()) : GK{};
        r.componentKey = safeStr(n.componentKey());
        r.isStateGroup = (n.isStateGroup() && *n.isStateGroup());
        r.isStyleMaster = (n.sharedStyleMasterData() != nullptr);
        if (r.isStyleMaster && n.sharedStyleMasterData()->styleKey())
            r.styleKey = safeStr(n.sharedStyleMasterData()->styleKey());
        if (n.sharedStyleReference() && n.sharedStyleReference()->styleKey())
            r.styleRefKey = safeStr(n.sharedStyleReference()->styleKey());
        r.internalOnly = (n.internalOnly() && *n.internalOnly());
        if (n.size()) {
            r.w = n.size()->x() ? *n.size()->x() : 0;
            r.h = n.size()->y() ? *n.size()->y() : 0;
        }
        r.raw = &n;
        if (!r.guid.isNull()) {
            li.byGuid[r.guid] = r;
            li.children[r.parent].push_back(r.guid);
            if (r.isStyleMaster && !r.styleKey.empty())
                li.styleByKey[r.styleKey] = r.guid;
        }
    }

    // 按 parentPos 排序子节点
    for (auto &[pg, cv] : li.children) {
        std::sort(cv.begin(), cv.end(), [&](const GK &a, const GK &b) {
            return li.byGuid[a].parentPos < li.byGuid[b].parentPos;
        });
    }
    return true;
}

// ─────────── 辅助：扫节点（含 symbolOverrides/derivedSymbolData）里的 inheritFillStyleID 引用 ───────────
// 前向声明
static void collectSubtree(const GK &root, const LibIndex &li,
                            std::set<GK> &visited, std::vector<GK> &ordered);

static void collectStyleRefsFromNode(const PixsoNode *n, const LibIndex &li,
                                     std::set<GK> &visited, std::vector<GK> &ordered) {
    if (!n) return;
    auto follow = [&](const GUID *g) {
        if (!g) return;
        GK k = gk(g);
        if (!k.isNull()) collectSubtree(k, li, visited, ordered);
    };
    follow(n->inheritFillStyleID());
    follow(n->inheritFillStyleIDForBackground());
    follow(n->inheritFillStyleIDForStroke());

    if (n->symbolData() && n->symbolData()->symbolOverrides()) {
        const auto *ov = n->symbolData()->symbolOverrides();
        for (uint32_t i = 0; i < ov->size(); i++)
            collectStyleRefsFromNode(&(*ov)[i], li, visited, ordered);
    }
    if (n->derivedSymbolData()) {
        const auto *ds = n->derivedSymbolData();
        for (uint32_t i = 0; i < ds->size(); i++)
            collectStyleRefsFromNode(&(*ds)[i], li, visited, ordered);
    }
}

// ─────────── 核心：收集组件集的完整节点集合 ───────────
//
// 策略：
//   1. 从容器根节点出发，BFS 收集整棵子树
//   2. 遇到 INSTANCE 节点，通过 symbolData.symbolID 找到被引用的 SYMBOL
//      将该 SYMBOL 的完整子树也加入收集集（递归处理 SYMBOL 内的 INSTANCE）
//   3. 所有收集到的 GUID 组成最终节点列表

static void collectSubtree(const GK &root, const LibIndex &li,
                            std::set<GK> &visited,
                            std::vector<GK> &ordered) {
    if (visited.count(root)) return;
    if (!li.byGuid.count(root)) return;

    visited.insert(root);
    ordered.push_back(root);

    const NodeRec &nr = li.byGuid.at(root);

    // 如果是 INSTANCE：追踪 symbolID，把被引用的 SYMBOL 子树也收进来
    if (nr.typeVal == 17 && !nr.symbolID.isNull()) {
        GK symGuid = nr.symbolID;
        // 检查该 SYMBOL 是否属于某个组件集（父节点是 FRAME+isStateGroup）
        // 若是，则从父 FRAME 根节点收集，确保整个组件集（所有变体）都被包含
        auto symIt = li.byGuid.find(symGuid);
        if (symIt != li.byGuid.end()) {
            GK parentOfSym = symIt->second.parent;
            auto parentIt = li.byGuid.find(parentOfSym);
            if (parentIt != li.byGuid.end() &&
                parentIt->second.typeVal == 5 &&
                parentIt->second.isStateGroup) {
                collectSubtree(parentOfSym, li, visited, ordered);
            } else {
                collectSubtree(symGuid, li, visited, ordered);
            }
        } else {
            collectSubtree(symGuid, li, visited, ordered);
        }
    }

    // 收集 inheritFillStyleID 引用的样式节点（字体/图标颜色定义节点）
    if (nr.raw) collectStyleRefsFromNode(nr.raw, li, visited, ordered);

    // 递归处理子节点
    auto it = li.children.find(root);
    if (it != li.children.end()) {
        for (const GK &child : it->second) {
            collectSubtree(child, li, visited, ordered);
        }
    }
}

// ─────────── 变体信息（组件集下的 SYMBOL 子节点）───────────

struct VariantInfo {
    std::string name;
    std::string guid;         // "sessionID:localID" 格式
    std::string componentKey; // 变体 key
    std::string parentKey;    // 所属组件集的 componentKey
};

// ─────────── 组件集信息 ───────────

struct CompSet {
    GK          rootGuid;
    std::string rootName;
    std::string canvasName;   // 所在页面
    uint32_t    rootType;
    std::string componentKey; // 根节点的 componentKey（用于文件命名）
    bool        isStateGroup = false; // 是否为组件集（FRAME + isStateGroup）
    int         symbolCount  = 0;
    int         instanceCount = 0;
    int         totalNodes   = 0;
    std::vector<GK>          allGuids; // 完整节点列表（有序）
    std::vector<uint8_t>     pixData;  // 编码后的 .pix 数据
    std::vector<VariantInfo> variants; // isStateGroup 时：直接 SYMBOL 子节点列表
};

// ─────────── Blob 辅助：收集 / 重映射 ───────────

// 递归收集一个 PixsoNode 里所有 blobIndex 引用
static void collectBlobsFromNode(const PixsoNode &n, std::set<int32_t> &out) {
    auto addPath = [&](const kiwi::Array<Path> *arr) {
        if (!arr) return;
        for (uint32_t i = 0; i < arr->size(); i++)
            if ((*arr)[i].blobIndex()) out.insert(*(*arr)[i].blobIndex());
    };
    addPath(n.fillGeometry());
    addPath(n.strokeGeometry());
    addPath(n.strokePaddingPath());
    if (n.vectorData() && n.vectorData()->vectorNetworkBlob())
        out.insert(*n.vectorData()->vectorNetworkBlob());
    if (n.textData() && n.textData()->glyphs()) {
        const auto *g = n.textData()->glyphs();
        for (uint32_t i = 0; i < g->size(); i++)
            if ((*g)[i].blobIndex()) out.insert(*(*g)[i].blobIndex());
    }
    // 递归子结构
    if (n.symbolData() && n.symbolData()->symbolOverrides()) {
        const auto *ov = n.symbolData()->symbolOverrides();
        for (uint32_t i = 0; i < ov->size(); i++) collectBlobsFromNode((*ov)[i], out);
    }
    if (n.derivedSymbolData()) {
        const auto *ds = n.derivedSymbolData();
        for (uint32_t i = 0; i < ds->size(); i++) collectBlobsFromNode((*ds)[i], out);
    }
}

// 收集一个 PixsoNode 中所有 blobIndex 字段的指针（包含递归子结构）
// 用于 remap 前保存原值、remap 后恢复，避免污染 li.pool
static void collectBlobPtrs(PixsoNode &n, std::vector<int32_t *> &ptrs) {
    auto addPaths = [&](kiwi::Array<Path> *arr) {
        if (!arr) return;
        for (uint32_t i = 0; i < arr->size(); i++)
            if ((*arr)[i].blobIndex()) ptrs.push_back((*arr)[i].blobIndex());
    };
    addPaths(n.fillGeometry());
    addPaths(n.strokeGeometry());
    addPaths(n.strokePaddingPath());
    if (n.vectorData() && n.vectorData()->vectorNetworkBlob())
        ptrs.push_back(n.vectorData()->vectorNetworkBlob());
    if (n.textData() && n.textData()->glyphs()) {
        auto *g = n.textData()->glyphs();
        for (uint32_t i = 0; i < g->size(); i++)
            if ((*g)[i].blobIndex()) ptrs.push_back((*g)[i].blobIndex());
    }
    if (n.symbolData() && n.symbolData()->symbolOverrides()) {
        auto *ov = n.symbolData()->symbolOverrides();
        for (uint32_t i = 0; i < ov->size(); i++) collectBlobPtrs((*ov)[i], ptrs);
    }
    if (n.derivedSymbolData()) {
        auto *ds = n.derivedSymbolData();
        for (uint32_t i = 0; i < ds->size(); i++) collectBlobPtrs((*ds)[i], ptrs);
    }
}

// 用重映射表修改一个 PixsoNode 里所有 blobIndex
// 注意：修改的是 li.pool 中的数据（浅拷贝节点的指针指向原始 pool）
// 调用方须在 encode 完成后通过 savedBlobs 恢复原值，避免跨组件污染
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
    fixPaths(n.strokePaddingPath());
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

// ─────────── 将收集到的节点 encode 成 PixsoMsg ───────────

// primaryRoot: 本次拆解的组件集根节点 GUID，挂到 {0,1}；其余孤根挂到 {0,2}
static std::vector<uint8_t> encodeNodes(const std::vector<GK> &guids,
                                         const GK &primaryRoot,
                                         const LibIndex &li) {
    kiwi::MemoryPool pool;
    PixsoMsg out;
    out.set_type(PixsoMsgType::NODE_CHANGES);

    // 辅助：分配 ParentIndex
    auto makePI = [&](uint32_t s, uint32_t l, const char *pos) -> ParentIndex* {
        GUID *pg = pool.allocate<GUID>();
        pg->set_sessionID(s); pg->set_localID(l);
        ParentIndex *pi = pool.allocate<ParentIndex>();
        pi->set_guid(pg); pi->set_position(kiwi::String(pos));
        return pi;
    };
    auto makeGUID = [&](uint32_t s, uint32_t l) -> GUID* {
        GUID *g = pool.allocate<GUID>();
        g->set_sessionID(s); g->set_localID(l);
        return g;
    };

    // 前两个槽放 CANVAS 节点，其余放组件节点
    const size_t OFFSET = 2;
    auto &arr = out.set_pixsoNodes(pool, (uint32_t)(OFFSET + guids.size()));

    // CANVAS {0,1}：主页面，组件集根节点挂这里
    arr[0].set_guid(makeGUID(0, 1));
    arr[0].set_parentIndex(makePI(0, 0, "!"));
    arr[0].set_type(NodeType::CANVAS);
    arr[0].set_phase(NodePhase::CREATED);
    arr[0].set_name(kiwi::String("Components"));

    // CANVAS {0,2}：隐藏页，引用组件/样式节点挂这里
    arr[1].set_guid(makeGUID(0, 2));
    arr[1].set_parentIndex(makePI(0, 0, "\""));
    arr[1].set_type(NodeType::CANVAS);
    arr[1].set_phase(NodePhase::CREATED);
    arr[1].set_name(kiwi::String(""));
    arr[1].set_internalOnly(true);

    // 1. 拷贝组件节点
    for (size_t i = 0; i < guids.size(); i++) {
        auto it = li.byGuid.find(guids[i]);
        if (it != li.byGuid.end() && it->second.raw)
            arr[OFFSET + i] = *it->second.raw;
    }

    // 1b. 孤根节点重挂：
    //   主根（正在拆解的组件集本身）→ {0,1}
    //   其余孤根（被 INSTANCE 引用拉入的外部组件/symbol）→ {0,2}
    {
        std::set<GK> guidSet(guids.begin(), guids.end());
        for (size_t i = 0; i < guids.size(); i++) {
            auto nodeIt = li.byGuid.find(guids[i]);
            if (nodeIt == li.byGuid.end()) continue;
            if (guidSet.count(nodeIt->second.parent)) continue; // 父在集合内，不是孤根
            bool isPrimary = (guids[i] == primaryRoot);
            arr[OFFSET + i].set_parentIndex(makePI(0, isPrimary ? 1 : 2, "a0"));
        }
    }

    // 2. 收集所有被引用的 blobIndex（只扫组件节点，跳过两个 CANVAS）
    std::set<int32_t> usedIdx;
    for (size_t i = 0; i < guids.size(); i++)
        collectBlobsFromNode(arr[OFFSET + i], usedIdx);

    // 3. 从库的 blobs 数组中提取实际数据，建本地重映射表（old → 0-based local）
    auto *libBlobs = li.msg.blobs();
    uint32_t libBlobCnt = libBlobs ? (uint32_t)libBlobs->size() : 0;

    if (!usedIdx.empty() && libBlobCnt > 0) {
        std::map<int32_t, int32_t> remap;
        std::vector<int32_t> validOld;
        for (int32_t old : usedIdx) {
            if (old >= 0 && (uint32_t)old < libBlobCnt) {
                remap[old] = (int32_t)validOld.size();
                validOld.push_back(old);
            }
        }

        if (!validOld.empty()) {
            // 4. 写入本地 blobs
            auto &outBlobs = out.set_blobs(pool, (uint32_t)validOld.size());
            for (size_t i = 0; i < validOld.size(); i++) {
                const Blob &src = (*libBlobs)[validOld[i]];
                const auto *srcB = src.bytes();
                if (srcB && srcB->size() > 0) {
                    auto &dstB = outBlobs[i].set_bytes(pool, (uint32_t)srcB->size());
                    for (uint32_t j = 0; j < srcB->size(); j++) dstB[j] = (*srcB)[j];
                }
            }

            // 5. 重映射节点中的 blobIndex
            // remapBlobsInNode 会就地修改 li.pool 里的数据（因为 arr 是浅拷贝）。
            // 在 remap 前收集所有 blobIndex 指针+原值，encode 完毕后恢复，
            // 避免污染 li.pool 造成后续组件 blob 收集错误。
            std::vector<std::pair<int32_t *, int32_t>> savedBlobs;
            for (size_t i = 0; i < guids.size(); i++) {
                std::vector<int32_t *> ptrs;
                collectBlobPtrs(arr[OFFSET + i], ptrs);
                for (int32_t *p : ptrs) savedBlobs.emplace_back(p, *p);
            }

            for (size_t i = 0; i < guids.size(); i++)
                remapBlobsInNode(arr[OFFSET + i], remap);

            kiwi::ByteBuffer bb;
            bool ok = out.encode(bb);

            // 恢复 li.pool 中的原始 blobIndex，防止跨组件污染
            for (auto &[ptr, val] : savedBlobs) *ptr = val;

            if (!ok) return {};
            return std::vector<uint8_t>(bb.data(), bb.data() + bb.size());
        }
    }

    kiwi::ByteBuffer bb;
    if (!out.encode(bb)) return {};
    return std::vector<uint8_t>(bb.data(), bb.data() + bb.size());
}

// ─────────── 主拆解函数 ───────────

static std::vector<CompSet> splitLibrary(const LibIndex &li) {
    std::vector<CompSet> result;

    // 将一个候选节点（SYMBOL 或 FRAME+isStateGroup）打包成 CompSet
    auto makeCompSet = [&](const NodeRec &child, const std::string &canvasName) {
        bool isCompSet = (child.typeVal == 5 && child.isStateGroup);

        CompSet cs;
        cs.rootGuid     = child.guid;
        cs.rootName     = child.name;
        cs.canvasName   = canvasName;
        cs.rootType     = child.typeVal;
        cs.componentKey = child.componentKey;
        cs.isStateGroup = isCompSet;

        std::set<GK>    visited;
        std::vector<GK> ordered;
        collectSubtree(child.guid, li, visited, ordered);
        cs.allGuids = ordered;

        for (const GK &g : ordered) {
            const NodeRec &nr = li.byGuid.at(g);
            if (nr.typeVal == 16) cs.symbolCount++;
            if (nr.typeVal == 17) cs.instanceCount++;
        }
        cs.totalNodes = (int)ordered.size();

        if (isCompSet) {
            auto cit = li.children.find(child.guid);
            if (cit != li.children.end()) {
                for (const GK &vGuid : cit->second) {
                    const NodeRec &vr = li.byGuid.at(vGuid);
                    if (vr.typeVal != 16) continue;
                    VariantInfo vi;
                    vi.name         = vr.name;
                    vi.guid         = std::to_string(vr.guid.s) + ":" + std::to_string(vr.guid.l);
                    vi.componentKey = vr.componentKey;
                    vi.parentKey    = child.componentKey;
                    cs.variants.push_back(std::move(vi));
                }
            }
        } else {
            VariantInfo vi;
            vi.name         = child.name;
            vi.guid         = std::to_string(child.guid.s) + ":" + std::to_string(child.guid.l);
            vi.componentKey = child.componentKey;
            vi.parentKey    = child.componentKey;
            cs.variants.push_back(std::move(vi));
        }

        auto kiwiBin = encodeNodes(ordered, child.guid, li);
        if (!kiwiBin.empty())
            cs.pixData = compressToPix(kiwiBin);

        return cs;
    };

    // 递归处理容器（CANVAS 或 SECTION）下的子节点，收集所有 SYMBOL/组件集
    std::function<void(const GK &, const std::string &)> processContainer =
        [&](const GK &containerGuid, const std::string &canvasName) {
            auto it = li.children.find(containerGuid);
            if (it == li.children.end()) return;

            for (const GK &childGuid : it->second) {
                const NodeRec &child = li.byGuid.at(childGuid);

                if (child.typeVal == 104 /* SECTION */) {
                    // 递归进入 SECTION
                    processContainer(child.guid, canvasName);
                } else if (child.typeVal == 16 /* SYMBOL */ ||
                           (child.typeVal == 5 /* FRAME */ && child.isStateGroup)) {
                    result.push_back(makeCompSet(child, canvasName));
                }
            }
        };

    // 找所有 CANVAS
    std::vector<GK> canvases;
    for (auto &[g, nr] : li.byGuid) {
        if (nr.typeVal == 3 /* CANVAS */) canvases.push_back(g);
    }

    for (const GK &cvGuid : canvases) {
        const NodeRec &cv = li.byGuid.at(cvGuid);
        if (cv.raw && cv.raw->internalOnly() && *cv.raw->internalOnly()) continue;
        processContainer(cvGuid, cv.name);
    }

    return result;
}

// ─────────── 补写 componentKey / publishFile / publishID ───────────
//
// 对所有 SYMBOL 和 FRAME+isStateGroup 节点：
//   若 componentKey 为空，则生成：
//     componentKey = SHA1(publishFile + sessionID + ":" + localID)
//     publishFile  = li.publishFile
//     publishID    = 节点自身 GUID
//
// 注意：kiwi::String 内部只存 const char* 指针，须确保字符串数据
// 在 PixsoNode 编码前始终有效。这里将生成的 key 存入 NodeRec::componentKey
// （std::string，map 元素指针不失效），publishFile 存入 li.publishFile。

static void patchPublishInfo(LibIndex &li) {
    if (li.publishFile.empty()) return;

    int patched = 0;
    for (auto &[g, nr] : li.byGuid) {
        bool isTarget = (nr.typeVal == 16) ||
                        (nr.typeVal == 5 && nr.isStateGroup);
        if (!isTarget || !nr.raw || !nr.componentKey.empty()) continue;

        // 生成 componentKey 并存入 NodeRec（指针稳定）
        nr.componentKey = sha1hex(li.publishFile +
                                  std::to_string(g.s) + ":" +
                                  std::to_string(g.l));

        auto *node = const_cast<PixsoNode *>(nr.raw);

        // componentKey
        node->set_componentKey(kiwi::String(nr.componentKey.c_str()));

        // publishFile（指向 li.publishFile，li 生命期覆盖编码阶段）
        node->set_publishFile(kiwi::String(li.publishFile.c_str()));

        // publishID = 节点自身 GUID
        GUID *pid = li.pool.allocate<GUID>();
        pid->set_sessionID(g.s);
        pid->set_localID(g.l);
        node->set_publishID(pid);

        patched++;
    }
    fprintf(stderr, "  补写 componentKey: %d 个节点\n", patched);
}

// ─────────── 落盘：写出 hex 文件 + component_index.json ───────────
//
// 在 <outdir>/component/ 下为每个拆解出的组件集写一个 {componentKey|guid}.txt，
// writeIndex=true 时额外生成 component_index.json（与 CLI build_index 一致）。

struct DumpStats {
    int written = 0;
    int componentSets = 0;
    int standaloneComponents = 0;
    std::string compDir;
    std::string indexPath;   // 为空表示未生成索引
};

static std::string compSetFileName(const CompSet &cs) {
    return cs.componentKey.empty()
         ? std::to_string(cs.rootGuid.s) + "_" + std::to_string(cs.rootGuid.l)
         : cs.componentKey;
}

static DumpStats dumpCompSets(const std::vector<CompSet> &sets,
                              const std::string &outdir,
                              bool writeIndex) {
    DumpStats stats;
    stats.compDir = outdir + "/component";
    mkdir(outdir.c_str(),        0755);
    mkdir(stats.compDir.c_str(), 0755);

    for (size_t i = 0; i < sets.size(); i++) {
        const CompSet &cs = sets[i];
        if (cs.pixData.empty()) continue;

        std::string fname = compSetFileName(cs);
        std::string hex   = "<!-- pixso binary data -->\n" + bytesToHex(cs.pixData);
        std::string path  = stats.compDir + "/" + fname + ".txt";
        std::vector<uint8_t> hexBytes(hex.begin(), hex.end());
        if (writeFile(path.c_str(), hexBytes)) {
            stats.written++;
            printf("[%zu] %s  (%d nodes, %zu hex chars)  -> %s\n",
                   i, cs.rootName.c_str(), cs.totalNodes, hex.size(), path.c_str());
        }
        if (cs.isStateGroup) stats.componentSets++;
        else                 stats.standaloneComponents++;
    }

    if (writeIndex) {
        std::string idxPath = stats.compDir + "/component_index.json";
        FILE *jf = fopen(idxPath.c_str(), "w");
        if (!jf) { fprintf(stderr, "cannot write: %s\n", idxPath.c_str()); return stats; }

        fprintf(jf, "{\n");

        // 组件集列表（isStateGroup==true）
        fprintf(jf, "  \"componentSets\": [\n");
        bool firstCs = true;
        for (auto &cs : sets) {
            if (!cs.isStateGroup) continue;
            if (!firstCs) fprintf(jf, ",\n");
            firstCs = false;
            std::string hexFile = "component/" + compSetFileName(cs) + ".txt";
            fprintf(jf, "    {\n");
            fprintf(jf, "      \"name\": \"%s\",\n", cs.rootName.c_str());
            fprintf(jf, "      \"guid\": \"%u:%u\",\n", cs.rootGuid.s, cs.rootGuid.l);
            fprintf(jf, "      \"componentKey\": \"%s\",\n", cs.componentKey.c_str());
            fprintf(jf, "      \"canvasName\": \"%s\",\n", cs.canvasName.c_str());
            fprintf(jf, "      \"hexFile\": \"%s\",\n", hexFile.c_str());
            fprintf(jf, "      \"variants\": [\n");
            for (size_t vi = 0; vi < cs.variants.size(); vi++) {
                const VariantInfo &v = cs.variants[vi];
                if (vi > 0) fprintf(jf, ",\n");
                fprintf(jf, "        {\n");
                fprintf(jf, "          \"name\": \"%s\",\n", v.name.c_str());
                fprintf(jf, "          \"guid\": \"%s\",\n", v.guid.c_str());
                fprintf(jf, "          \"variantKey\": \"%s\",\n", v.componentKey.c_str());
                fprintf(jf, "          \"parentKey\": \"%s\"\n", v.parentKey.c_str());
                fprintf(jf, "        }");
            }
            if (!cs.variants.empty()) fprintf(jf, "\n");
            fprintf(jf, "      ]\n");
            fprintf(jf, "    }");
        }
        if (!firstCs) fprintf(jf, "\n");
        fprintf(jf, "  ],\n");

        // 独立组件列表（isStateGroup==false，SYMBOL）
        fprintf(jf, "  \"standaloneComponents\": [\n");
        bool firstSc = true;
        for (auto &cs : sets) {
            if (cs.isStateGroup) continue;
            if (!firstSc) fprintf(jf, ",\n");
            firstSc = false;
            std::string hexFile = "component/" + compSetFileName(cs) + ".txt";
            fprintf(jf, "    {\n");
            fprintf(jf, "      \"name\": \"%s\",\n", cs.rootName.c_str());
            fprintf(jf, "      \"guid\": \"%u:%u\",\n", cs.rootGuid.s, cs.rootGuid.l);
            fprintf(jf, "      \"componentKey\": \"%s\",\n", cs.componentKey.c_str());
            fprintf(jf, "      \"canvasName\": \"%s\",\n", cs.canvasName.c_str());
            fprintf(jf, "      \"hexFile\": \"%s\"\n", hexFile.c_str());
            fprintf(jf, "    }");
        }
        if (!firstSc) fprintf(jf, "\n");
        fprintf(jf, "  ]\n");

        fprintf(jf, "}\n");
        fclose(jf);

        stats.indexPath = idxPath;
        printf("\n已生成索引: %s\n", idxPath.c_str());
    }

    return stats;
}
