'use strict';

const path         = require('path');
const SplitCompset = require('./bin/split_compset.js');

// ─── 参数 ────────────────────────────────────────────────────────────────────
// node index.js <complib.pix> <outdir> [publishFile]
//
// 示例：
//   node index.js "../HarmonyOS Component Library（来自社区）.pix" harmony_out
//   node index.js "../xxx.pix" harmony_out QcO-1WDViGmGQ4IFU_p4FQ

const args = process.argv.slice(2);
if (args.length < 2) {
    console.error(
        'Usage: node index.js <complib.pix> <outdir> [publishFile]\n\n' +
        'Example:\n' +
        '  node index.js "../HarmonyOS Component Library（来自社区）.pix" harmony_out\n' +
        '  node index.js "../xxx.pix" harmony_out QcO-1WDViGmGQ4IFU_p4FQ\n'
    );
    process.exit(1);
}

const pixPath     = path.resolve(args[0]);
const outDir      = path.resolve(args[1]);
const publishFile = args[2] || '';

// ─── 执行 ────────────────────────────────────────────────────────────────────
SplitCompset().then(mod => {
    console.log('组件库:', pixPath);
    console.log('输出  :', outDir);

    const t0     = Date.now();
    const result = mod.splitCompset(pixPath, outDir, publishFile);
    const ms     = Date.now() - t0;

    const parsed = JSON.parse(result);
    if (parsed.error) {
        console.error('错误:', result);
        process.exit(1);
    }

    console.log(`耗时: ${ms} ms`);
    console.log('结果:', result);
}).catch(err => {
    console.error('WASM 初始化失败:', err);
    process.exit(1);
});
