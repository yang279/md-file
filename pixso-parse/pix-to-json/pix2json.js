#!/usr/bin/env node
'use strict';

const fs   = require('fs');
const path = require('path');

const { decompress } = require('fzstd');
const { ByteBuffer } = require('kiwi-schema');
const pixso = require('../pixso.js');
pixso.ByteBuffer = ByteBuffer;

// ─── hex 解析 ───────────────────────────────────────────────────────────────

function hexToBytes(text) {
  let hex = '';
  for (const line of text.split('\n')) {
    const t = line.trim();
    if (t.startsWith('<') || t.startsWith('#') || t === '') continue;
    hex += t;
  }
  const bytes = new Uint8Array(hex.length / 2);
  for (let i = 0; i < bytes.length; i++)
    bytes[i] = parseInt(hex.substr(i * 2, 2), 16);
  return bytes;
}

// ─── .pix 文件头解析 ─────────────────────────────────────────────────────────
// 格式: "pixso-kw"(8) + version[2](2) + metaLen(1) + meta(metaLen) + zstd data

function parsePixHeader(data) {
  const magic = 'pixso-kw';
  for (let i = 0; i < 8; i++)
    if (data[i] !== magic.charCodeAt(i))
      throw new Error(`Invalid pixso magic at byte ${i}`);
  let pos = 8 + 2;          // skip magic + version
  const metaLen = data[pos++];
  pos += metaLen;            // skip meta string
  return pos;
}

// ─── 主转换函数 ──────────────────────────────────────────────────────────────

function pixFileToJson(inputPath) {
  let data;

  if (inputPath.endsWith('.txt')) {
    const text = fs.readFileSync(inputPath, 'utf8');
    data = hexToBytes(text);
  } else {
    data = new Uint8Array(fs.readFileSync(inputPath));
  }

  const offset = parsePixHeader(data);
  const compressed = data.slice(offset);
  const decompressed = decompress(compressed);

  const bb = new ByteBuffer(decompressed);
  return pixso.decodePixsoMsg(bb);
}

// ─── CLI ─────────────────────────────────────────────────────────────────────

const args = process.argv.slice(2);
if (args.length === 0) {
  console.error(
    'Usage:\n' +
    '  node pix2json.js <input.txt|input.pix> [output.json]\n\n' +
    'Examples:\n' +
    '  node pix2json.js ../pix-dsl/one_instance_out.txt\n' +
    '  node pix2json.js ../instance1.pix instance1.json\n'
  );
  process.exit(1);
}

const inputPath  = path.resolve(args[0]);
const defaultOut = inputPath.replace(/\.(txt|pix)$/, '.json');
const outputPath = args[1] ? path.resolve(args[1]) : defaultOut;

console.log(`Input : ${inputPath}`);
try {
  const msg = pixFileToJson(inputPath);
  const json = JSON.stringify(msg, null, 2);
  fs.writeFileSync(outputPath, json, 'utf8');
  console.log(`Output: ${outputPath}  (${(json.length / 1024).toFixed(1)} KB)`);
  const nodes = msg.pixsoNodes || [];
  console.log(`Nodes : ${nodes.length}  MsgType: ${msg.type}`);
} catch (e) {
  console.error('Error:', e.message);
  process.exit(1);
}
