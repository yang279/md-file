#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "kiwi.h"
#include "pixso.h"
#include "zstd.h"

#include <emscripten/bind.h>

#include "split_compset_core.h"

// NODERAWFS=1 使 fopen/fread/mkdir 等系统调用直接路由到 Node.js fs，
// 无需挂载虚拟文件系统，也不需要把文件内容传进 WASM。

// =============================================================================
// WASM 导出函数
// =============================================================================

// splitCompset(pixPath, outDir, publishFile) → JSON 字符串
// - pixPath:     组件库 .pix 文件路径
// - outDir:      输出目录（生成 <outDir>/component/*.txt + component_index.json）
// - publishFile: 可选，缺少 componentKey 时用于补写发布信息（同 CLI --publish-file）
//
// 等价于 CLI: split_compset build_index <pixPath> <outDir> [--publish-file <publishFile>]
// 返回: {"total":N,"componentSets":A,"standaloneComponents":B,"compDir":"...","indexFile":"..."}
//   或: {"error":"..."}
std::string splitCompset(const std::string &pixPath,
                          const std::string &outDir,
                          const std::string &publishFile) {
    auto raw = readFile(pixPath.c_str());
    if (raw.empty())
        return "{\"error\":\"cannot open: " + pixPath + "\"}";

    LibIndex li;
    if (!buildIndex(raw, li))
        return "{\"error\":\"parse failed: " + pixPath + "\"}";

    if (!publishFile.empty()) {
        li.publishFile = publishFile;
        patchPublishInfo(li);
    }

    auto sets = splitLibrary(li);
    if (sets.empty())
        return "{\"error\":\"no component sets found\"}";

    auto stats = dumpCompSets(sets, outDir, /*writeIndex=*/true);

    std::string json = "{";
    json += "\"total\":" + std::to_string(stats.written) + ",";
    json += "\"componentSets\":" + std::to_string(stats.componentSets) + ",";
    json += "\"standaloneComponents\":" + std::to_string(stats.standaloneComponents) + ",";
    json += "\"compDir\":\"" + stats.compDir + "\",";
    json += "\"indexFile\":\"" + stats.indexPath + "\"";
    json += "}";
    return json;
}

EMSCRIPTEN_BINDINGS(split_compset_wasm) {
    emscripten::function("splitCompset", &splitCompset);
}
