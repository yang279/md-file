#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include "dsl_core.h"

#include <sys/stat.h>

// =============================================================================
// CLI 专用工具
// =============================================================================

static bool writeFile(const char *path, const std::vector<uint8_t> &d) {
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write: %s\n", path); return false; }
    fwrite(d.data(), 1, d.size(), f); fclose(f);
    return true;
}

static bool isDirectory(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISDIR(st.st_mode);
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
        const char *nm = n.name()        ? n.name()->c_str()  : "";
        bool iInternal = n.internalOnly() && *n.internalOnly();
        uint32_t nFills = n.fillPaints() ? n.fillPaints()->size() : 0;

        printf("  [%2u] %-8s guid={%u,%u} parent={%u,%u}%s  fills=%u  \"%s\"\n",
               i, typeName(t).c_str(), gs, gl, ps, pl,
               iInternal ? " [internal]" : "", nFills, nm);

        if (n.symbolData() && n.symbolData()->symbolID()) {
            const GUID *sg = n.symbolData()->symbolID();
            printf("       symbolID={%u,%u}\n",
                   sg->sessionID() ? *sg->sessionID() : 0,
                   sg->localID()   ? *sg->localID()   : 0);
        }

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
                if (n.type() && *n.type() == NodeType::CANVAS) continue;
                uint32_t s = (n.guid() && n.guid()->sessionID()) ? *n.guid()->sessionID() : 0;
                uint32_t l = (n.guid() && n.guid()->localID())   ? *n.guid()->localID()   : 0;
                if (seenGuids.insert(gkStr(s, l)).second) compNodeCount++;
            }
        }
    }
    printf("  预期总节点数（GUID去重，跳过CANVAS）: %u\n\n", countTotal(doc, compNodeCount));

    kiwi::MemoryPool pool;
    auto kiwiBin = buildMsg(pool, doc, compSets);
    if (kiwiBin.empty()) return 1;
    printf("  kiwi 编码大小: %zu bytes\n", kiwiBin.size());

    auto pixData = compressToPix(kiwiBin);
    if (pixData.empty()) return 1;
    printf("  pix 大小: %zu bytes\n", pixData.size());

    std::string hexStr = bytesToHex(pixData);
    std::string outStr = "<!-- pixso binary data -->\n" + hexStr;
    std::vector<uint8_t> outBytes(outStr.begin(), outStr.end());
    if (!writeFile(argv[2], outBytes)) return 1;
    printf("  已写入: %s  (%zu hex chars)\n\n", argv[2], hexStr.size());

    printf("=== 验证（重新解析）===\n");
    verifyPix(pixData);

    return 0;
}
