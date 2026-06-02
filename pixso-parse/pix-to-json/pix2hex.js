#!/usr/bin/env node
'use strict';

// 将 .pix 二进制文件转成 hex txt 格式（与 dsl_to_hex 输出格式相同）
// Usage: node pix2hex.js <input.pix> [output.txt]

const fs   = require('fs');
const path = require('path');

const args = process.argv.slice(2);
if (args.length === 0) {
  console.error(
    'Usage:\n' +
    '  node pix2hex.js <input.pix> [output.txt]\n\n' +
    'Example:\n' +
    '  node pix2hex.js ../instance1.pix instance1.txt\n'
  );
  process.exit(1);
}

const inputPath  = path.resolve(args[0]);
const defaultOut = inputPath.replace(/\.pix$/, '.txt');
const outputPath = args[1] ? path.resolve(args[1]) : defaultOut;

const data = fs.readFileSync(inputPath);
const hex  = Buffer.from(data).toString('hex');
const out  = `<!-- pixso binary data -->\n${hex}\n`;

fs.writeFileSync(outputPath, out, 'utf8');
console.log(`Input : ${inputPath}  (${data.length} bytes)`);
console.log(`Output: ${outputPath}  (${hex.length} hex chars)`);
