#!/usr/bin/env node
'use strict';

const fs                = require('fs');
const path              = require('path');
const express           = require('express');
const multer            = require('multer');
const { matchVariant }  = require('./match_variant');
const { matchVariants } = require('./batch_match');
const { matchDsl }      = require('./match_dsl');

const app    = express();
const PORT   = Number(process.env.PORT) || 3100;
const upload = multer({ storage: multer.memoryStorage() });

// 多组件库根目录：search_index.json 中每个 entry 的 hexFile 是相对 lib-out/{source}/ 的路径
const LIB_OUT_DIR = process.env.LIB_OUT_DIR
  || path.resolve(__dirname, '../../pixso-parse/pix-split/lib-out');

app.use(express.json());

// ---------------------------------------------------------------------------
// 启动时根据 search_index.json 构建 hexKey → 绝对路径 的映射
// hexKey 取自 hexFile 的文件名（不含扩展名），如 "component/93_55829.txt" → "93_55829"
// ---------------------------------------------------------------------------
const SEARCH_INDEX_PATH = path.resolve(__dirname, 'search_index.json');
const hexPathMap = new Map();

function buildHexPathMap() {
  const { entries } = JSON.parse(fs.readFileSync(SEARCH_INDEX_PATH, 'utf8'));
  for (const entry of entries) {
    if (!entry.hexFile || !entry.source) continue;
    const key = path.basename(entry.hexFile, path.extname(entry.hexFile));
    hexPathMap.set(key, path.join(LIB_OUT_DIR, entry.source, entry.hexFile));
  }
  return hexPathMap.size;
}

const loadedCount = buildHexPathMap();
console.log(`hex 索引加载成功: ${loadedCount} 个 key（来源: ${SEARCH_INDEX_PATH}）`);

// 允许两种 key 格式，防止路径穿越：
//   旧格式：40 位小写 hex（SHA1 componentKey）
//   新格式：{sessionId}_{localId}（从 guid 派生）
const KEY_RE = /^([a-f0-9]{40}|\d+_\d+)$/;

// ── GET /health ───────────────────────────────────────────────────────────────

app.get('/health', (req, res) => {
  res.json({ status: 'ok', hex_keys: hexPathMap.size });
});

// ── POST /match ───────────────────────────────────────────────────────────────

app.post('/match', async (req, res) => {
  const { description } = req.body || {};
  if (!description || typeof description !== 'string') {
    return res.status(400).json({ error: 'description is required' });
  }
  try {
    const result = await matchVariant(description.trim());
    if (!result) return res.status(404).json({ error: 'no match found' });
    res.json(result);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// ── POST /batch ───────────────────────────────────────────────────────────────

app.post('/batch', async (req, res) => {
  const body = req.body;
  let descriptions;

  if (Array.isArray(body)) {
    descriptions = body.map(x => (typeof x === 'string' ? x : x.description));
  } else if (Array.isArray(body?.descriptions)) {
    descriptions = body.descriptions;
  } else {
    return res.status(400).json({ error: 'body must be an array or { descriptions: [] }' });
  }

  if (descriptions.length === 0) {
    return res.status(400).json({ error: 'descriptions array is empty' });
  }
  if (descriptions.length > 100) {
    return res.status(400).json({ error: 'max 100 descriptions per request' });
  }

  try {
    const results = await matchVariants(descriptions.map(d => d?.trim?.() ?? d));
    res.json(results);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// ── POST /match-dsl ───────────────────────────────────────────────────────────
// 支持两种方式：
//   1. multipart 文件上传：-F "file=@page.json"
//   2. JSON body：-H "Content-Type: application/json" -d '{...}'

app.post('/match-dsl', upload.single('file'), async (req, res) => {
  let nodeData;

  if (req.file) {
    try {
      nodeData = JSON.parse(req.file.buffer.toString('utf8'));
    } catch {
      return res.status(400).json({ error: 'uploaded file is not valid JSON' });
    }
  } else if (req.body && typeof req.body === 'object' && Object.keys(req.body).length > 0) {
    nodeData = req.body;
  } else {
    return res.status(400).json({ error: 'send a file via -F "file=@page.json" or a JSON body' });
  }

  try {
    const results = await matchDsl(nodeData);
    res.json(results);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// ── GET /hex/:key ─────────────────────────────────────────────────────────────
// 跨组件库查找 hex 文件：通过 search_index.json 构建的映射定位实际文件路径
// （不同库的 hex 文件分散在 lib-out/{source}/component/ 下）

app.get('/hex/:key', (req, res) => {
  const { key } = req.params;
  if (!KEY_RE.test(key)) {
    return res.status(400).json({ error: 'key must be a 40-char lowercase hex string or {sessionId}_{localId}' });
  }

  const filePath = hexPathMap.get(key);
  if (!filePath || !fs.existsSync(filePath)) {
    return res.status(404).json({ error: `component not found: ${key}` });
  }

  res.set('Content-Type', 'text/plain; charset=utf-8');
  fs.createReadStream(filePath).pipe(res);
});

app.listen(PORT, () => {
  console.log(`component-service 已启动: http://localhost:${PORT}`);
  console.log(`LIB_OUT_DIR: ${LIB_OUT_DIR}`);
});
