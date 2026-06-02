const fs   = require('fs');
const path = require('path');
const Demo = require('./demo.js');

async function main() {
    // 1. 读取 JSON 配置
    const configPath = path.join(__dirname, 'input.json');
    const configStr  = fs.readFileSync(configPath, 'utf8');
    const config     = JSON.parse(configStr);

    console.log('读取配置:', configPath);
    console.log('文件列表:', config.files);

    // 2. 读取每个 hex 文件内容
    const hexContents = [];
    for (const filePath of config.files) {
        const abs = path.resolve(__dirname, filePath);
        const content = fs.readFileSync(abs, 'utf8');
        console.log(`已读取: ${path.basename(filePath)} (${content.length} 字符)`);
        hexContents.push(content);
    }

    // 3. 加载 WASM 模块
    const mod = await Demo();
    console.log('\nWASM 模块已加载');

    // 4. 调用 WASM processFiles
    // Embind vector<string> 需要用 mod.VectorString 构造
    const vec = new mod.VectorString();
    for (const c of hexContents) vec.push_back(c);

    const result = mod.processFiles(configStr, vec);
    vec.delete();  // 释放 WASM 侧内存

    // 5. 打印结果
    console.log('\n===== WASM 输出 =====');
    console.log(result);

    // 6. 写入输出文件
    const outPath = path.join(__dirname, config.output || 'output.txt');
    fs.writeFileSync(outPath, result, 'utf8');
    console.log('已保存到:', outPath);
}

main().catch(console.error);
