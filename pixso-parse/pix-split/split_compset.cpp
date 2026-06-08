#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H
#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include "split_compset_core.h"

// ─────────── 输出报告 ───────────

static void printReport(const std::vector<CompSet> &sets) {
    printf("=== 组件集拆解报告 ===\n\n");
    printf("%-6s %-12s %-40s %-20s %6s %6s %6s %8s\n",
        "index", "type", "组件集名称", "所在页面", "SYMBOL", "INST", "总节点", "hex大小");
    printf("%s\n", std::string(110, '-').c_str());

    for (size_t i = 0; i < sets.size(); i++) {
        const CompSet &cs = sets[i];
        std::string name = cs.rootName.size() > 38
                           ? cs.rootName.substr(0, 35) + "..." : cs.rootName;
        std::string canvas = cs.canvasName.size() > 18
                             ? cs.canvasName.substr(0, 15) + "..." : cs.canvasName;
        printf("%-6zu %-12s %-40s %-20s %6d %6d %6d %8zu\n",
            i, typeName(cs.rootType).c_str(),
            name.c_str(), canvas.c_str(),
            cs.symbolCount, cs.instanceCount,
            cs.totalNodes, cs.pixData.size());
    }
    printf("\n共 %zu 个组件集\n", sets.size());
}

// ─────────── main ───────────

static void printUsage(const char *prog) {
    fprintf(stderr,
        "Usage:\n"
        "  %s report      <complib.pix> [--publish-file <id>]           打印拆解报告\n"
        "  %s dump        <complib.pix> <outdir> [--publish-file <id>]  每个组件集存入 <outdir>/component/\n"
        "  %s build_index <complib.pix> <outdir> [--publish-file <id>]  dump + 生成 component_index.json\n"
        "  %s hex         <complib.pix> <index>  [--publish-file <id>]  打印指定组件集的 hex\n"
        "  %s hexall      <complib.pix> <out.txt>[--publish-file <id>]  所有组件集 hex 写入文件\n\n"
        "  --publish-file <id>  为缺少 componentKey 的组件补写发布信息\n"
        "                       componentKey = SHA1(publishFile + sessionID:localID)\n\n"
        "示例:\n"
        "  %s report      '../HarmonyOS Component Library（来自社区）.pix'\n"
        "  %s build_index '../HarmonyOS Component Library（来自社区）.pix' ./out --publish-file QcO-1WDViGmGQ4IFU_p4FQ\n",
        prog, prog, prog, prog, prog, prog, prog);
}

int main(int argc, char **argv) {
    if (argc < 3) { printUsage(argv[0]); return 1; }

    // 解析 --publish-file（可放在任意位置）
    std::string publishFile;
    std::vector<char *> args;
    for (int i = 0; i < argc; i++) {
        if (std::string(argv[i]) == "--publish-file" && i + 1 < argc) {
            publishFile = argv[++i];
        } else {
            args.push_back(argv[i]);
        }
    }
    // 用过滤后的 args 替代 argv/argc
    argc = (int)args.size();
    argv = args.data();

    std::string cmd = argv[1];
    auto raw = readFile(argv[2]);
    if (raw.empty()) { fprintf(stderr, "cannot open: %s\n", argv[2]); return 1; }

    fprintf(stderr, "解析组件库...\n");
    LibIndex li;
    if (!buildIndex(raw, li)) { fprintf(stderr, "解析失败\n"); return 1; }
    fprintf(stderr, "  节点总数: %zu\n", li.byGuid.size());

    if (!publishFile.empty()) {
        li.publishFile = publishFile;
        fprintf(stderr, "补写发布信息 (publishFile=%s)...\n", publishFile.c_str());
        patchPublishInfo(li);
    }

    fprintf(stderr, "拆解组件集...\n");
    auto sets = splitLibrary(li);
    fprintf(stderr, "  组件集数量: %zu\n\n", sets.size());

    if (cmd == "report") {
        printReport(sets);

    } else if (cmd == "dump" || cmd == "build_index") {
        if (argc < 4) { fprintf(stderr, "需要输出目录\n"); return 1; }
        std::string outdir = argv[3];
        dumpCompSets(sets, outdir, cmd == "build_index");

    } else if (cmd == "hex") {
        if (argc < 4) { fprintf(stderr, "需要 index\n"); return 1; }
        size_t idx = atoi(argv[3]);
        if (idx >= sets.size()) { fprintf(stderr, "index out of range\n"); return 1; }
        const CompSet &cs = sets[idx];
        printf("=== 组件集 [%zu] ===\n", idx);
        printf("名称    : %s\n", cs.rootName.c_str());
        printf("页面    : %s\n", cs.canvasName.c_str());
        printf("类型    : %s\n", typeName(cs.rootType).c_str());
        printf("SYMBOL  : %d\n", cs.symbolCount);
        printf("INSTANCE: %d\n", cs.instanceCount);
        printf("总节点  : %d\n", cs.totalNodes);
        printf("hex大小 : %zu bytes\n\n", cs.pixData.size());
        printf("HEX:\n%s\n", bytesToHex(cs.pixData).c_str());

    } else if (cmd == "hexall") {
        if (argc < 4) { fprintf(stderr, "需要输出文件\n"); return 1; }
        FILE *f = fopen(argv[3], "w");
        if (!f) { fprintf(stderr, "cannot write: %s\n", argv[3]); return 1; }
        fprintf(f, "# 组件集 hex 数据\n# 共 %zu 个\n\n", sets.size());
        for (size_t i = 0; i < sets.size(); i++) {
            const CompSet &cs = sets[i];
            fprintf(f, "[%zu] %s | %s | SYMBOL=%d INST=%d nodes=%d\n",
                i, cs.rootName.c_str(), cs.canvasName.c_str(),
                cs.symbolCount, cs.instanceCount, cs.totalNodes);
            fprintf(f, "%s\n\n", bytesToHex(cs.pixData).c_str());
        }
        fclose(f);
        printf("已写入: %s\n", argv[3]);

    } else {
        printUsage(argv[0]); return 1;
    }

    return 0;
}
