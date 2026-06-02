'use strict';

const path    = require('path');
const fs      = require('fs');
const DslToHex = require('./bin/dsl_to_hex.js');

// ─── 参数 ────────────────────────────────────────────────────────────────────
// node index.js <dsl.json> <component_dir> [out.txt]
//
// 示例：
//   node index.js ../dsl-one-instance.json ../pix-split/harmony_out/component
//   node index.js ../dsl-instance-demo.json ../pix-split/harmony_out/component out.txt

const args = process.argv.slice(2);
if (args.length < 2) {
    console.error(
        'Usage: node index.js <dsl.json> <component_dir> [out.txt]\n\n' +
        'Example:\n' +
        '  node index.js ../dsl-one-instance.json ../pix-split/harmony_out/component\n' +
        '  node index.js ../dsl-instance-demo.json ../pix-split/harmony_out/component out.txt\n'
    );
    process.exit(1);
}

const dslPath    = path.resolve(args[0]);
const compDir    = path.resolve(args[1]);
const outPath    = args[2] ? path.resolve(args[2]) : null;

// ─── 执行 ────────────────────────────────────────────────────────────────────
DslToHex().then(mod => {
    console.log('DSL :', dslPath);
    console.log('组件:', compDir);

    const t0     = Date.now();
    const result = mod.dslToHex(dslPath, compDir);
    const ms     = Date.now() - t0;

    if (result.startsWith('{"error"')) {
        console.error('错误:', result);
        process.exit(1);
    }

    const hexLine = result.split('\n')[1] || '';
    console.log(`耗时: ${ms} ms  |  hex: ${hexLine.length} chars`);

    if (outPath) {
        fs.writeFileSync(outPath, result, 'utf8');
        console.log('输出:', outPath);
    } else {
        // 没有指定输出文件时打印前 80 个字符预览
        console.log('预览:', hexLine.slice(0, 80) + '...');
    }
}).catch(err => {
    console.error('WASM 初始化失败:', err);
    process.exit(1);
});
