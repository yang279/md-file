#!/usr/bin/env node
'use strict';

// 对比两个 pix/txt 文件的 pixsoNodes，输出字段级差异
// Usage: node diff_nodes.js <fileA.json|A.txt|A.pix> <fileB.json|B.txt|B.pix>

const fs   = require('fs');
const path = require('path');

function loadJson(filePath) {
  const ext = path.extname(filePath).toLowerCase();
  if (ext === '.json') return JSON.parse(fs.readFileSync(filePath, 'utf8'));

  // 否则调用 pix2json 转换
  const { spawnSync } = require('child_process');
  const r = spawnSync('node', [path.join(__dirname, 'pix2json.js'), filePath, '/tmp/_diff_tmp.json'],
    { cwd: __dirname });
  if (r.status !== 0) { console.error(r.stderr.toString()); process.exit(1); }
  return JSON.parse(fs.readFileSync('/tmp/_diff_tmp.json', 'utf8'));
}

const TYPE_NAMES = {
  2:'DOCUMENT', 3:'CANVAS', 4:'GROUP', 5:'FRAME', 6:'BOOL_OP',
  7:'VECTOR', 8:'STAR', 9:'LINE', 10:'ELLIPSE', 11:'RECT',
  14:'TEXT', 16:'SYMBOL', 17:'INSTANCE'
};
const typeName = t => TYPE_NAMES[t] || `type(${t})`;
const gkStr    = g => g ? `{${g.sessionID},${g.localID}}` : 'null';

function nodeKey(n) {
  const g = n.guid;
  return g ? `${g.sessionID}:${g.localID}` : null;
}
function nodeSummary(n) {
  const t = n.type ? typeName(n.type) : '?';
  const g = gkStr(n.guid);
  const nm = n.name ? `"${n.name}"` : '';
  const sd = n.symbolData ? `→${gkStr(n.symbolData.symbolID)}` : '';
  const dc = n.derivedSymbolData ? `derived=${n.derivedSymbolData.length}` : '';
  return `${t} ${g} ${nm} ${sd} ${dc}`.trim();
}

function compareNodes(nodesA, nodesB, labelA, labelB) {
  const mapA = new Map(), mapB = new Map();
  for (const n of nodesA) { const k = nodeKey(n); if (k) mapA.set(k, n); }
  for (const n of nodesB) { const k = nodeKey(n); if (k) mapB.set(k, n); }

  console.log(`\n== ${labelA}: ${nodesA.length} nodes  vs  ${labelB}: ${nodesB.length} nodes ==\n`);

  // 仅在 A 里有
  const onlyA = [...mapA.keys()].filter(k => !mapB.has(k));
  if (onlyA.length) {
    console.log(`[仅 ${labelA}] ${onlyA.length} 个节点:`);
    for (const k of onlyA) console.log(`  + ${nodeSummary(mapA.get(k))}`);
  }

  // 仅在 B 里有
  const onlyB = [...mapB.keys()].filter(k => !mapA.has(k));
  if (onlyB.length) {
    console.log(`[仅 ${labelB}] ${onlyB.length} 个节点:`);
    for (const k of onlyB) console.log(`  - ${nodeSummary(mapB.get(k))}`);
  }

  // 共有节点，对比关键字段
  const FIELDS = ['type','name','visible','opacity','derivedSymbolData'];
  const diffs = [];
  for (const [k, a] of mapA) {
    const b = mapB.get(k);
    if (!b) continue;
    const diff = {};
    for (const f of FIELDS) {
      const va = f === 'derivedSymbolData'
        ? (a[f] ? a[f].length : 0)
        : a[f];
      const vb = f === 'derivedSymbolData'
        ? (b[f] ? b[f].length : 0)
        : b[f];
      if (JSON.stringify(va) !== JSON.stringify(vb))
        diff[f] = { [labelA]: va, [labelB]: vb };
    }
    if (Object.keys(diff).length)
      diffs.push({ guid: k, summary: nodeSummary(a), diff });
  }

  if (diffs.length) {
    console.log(`\n[字段差异] ${diffs.length} 个共有节点有差异:`);
    for (const d of diffs) {
      console.log(`  ${d.summary}`);
      for (const [f, v] of Object.entries(d.diff))
        console.log(`    ${f}: ${labelA}=${JSON.stringify(v[labelA])}  ${labelB}=${JSON.stringify(v[labelB])}`);
    }
  }

  if (!onlyA.length && !onlyB.length && !diffs.length)
    console.log('  ✓ 无差异');
}

const args = process.argv.slice(2);
if (args.length < 2) {
  console.error('Usage: node diff_nodes.js <A.json|A.txt|A.pix> <B.json|B.txt|B.pix>');
  process.exit(1);
}

const msgA = loadJson(path.resolve(args[0]));
const msgB = loadJson(path.resolve(args[1]));
const labelA = path.basename(args[0]);
const labelB = path.basename(args[1]);

console.log(`MsgType: ${labelA}=${msgA.type}  ${labelB}=${msgB.type}`);
compareNodes(msgA.pixsoNodes || [], msgB.pixsoNodes || [], labelA, labelB);
