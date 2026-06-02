#include <emscripten/bind.h>
#include <string>
#include <vector>

// 处理逻辑：
// - config: JSON 字符串（预留，本 demo 只打印）
// - hexContents: 每个 hex 文件的内容字符串数组
// - 打印每个文件的前 10 个字符
// - 拼接所有前 10 字符，返回最终字符串
std::string processFiles(const std::string &config,
                         const std::vector<std::string> &hexContents) {
    std::string output;

    output += "=== config ===\n";
    output += config + "\n\n";

    output += "=== hex files ===\n";
    for (size_t i = 0; i < hexContents.size(); i++) {
        const std::string &content = hexContents[i];

        // 取前 10 个字符（跳过首行注释，只看 hex 数据行）
        std::string hexLine;
        size_t pos = content.find('\n');
        if (pos != std::string::npos && pos + 1 < content.size())
            hexLine = content.substr(pos + 1);   // 第二行（hex 数据）
        else
            hexLine = content;

        std::string first10 = hexLine.substr(0, 10);

        output += "file[" + std::to_string(i) + "] 前10字符: " + first10 + "\n";
    }

    output += "\n=== 拼接结果 ===\n";
    for (size_t i = 0; i < hexContents.size(); i++) {
        const std::string &content = hexContents[i];
        std::string hexLine;
        size_t pos = content.find('\n');
        if (pos != std::string::npos && pos + 1 < content.size())
            hexLine = content.substr(pos + 1);
        else
            hexLine = content;

        output += hexLine.substr(0, 10);
        if (i + 1 < hexContents.size()) output += "|";
    }
    output += "\n";

    return output;
}

EMSCRIPTEN_BINDINGS(demo) {
    emscripten::register_vector<std::string>("VectorString");
    emscripten::function("processFiles", &processFiles);
}
