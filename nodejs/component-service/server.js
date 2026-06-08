#!/usr/bin/env node
'use strict';

const fs                = require('fs');
const path              = require('path');
const express           = require('express');
const multer            = require('multer');
const { matchVariant }  = require('./match_variant');
const { matchVariants } = require('./batch_match');
const { matchDsl }      = require('./match_dsl');
const { splitLibrary }  = require('./split_lib');

const app    = express();
const PORT   = Number(process.env.PORT) || 3102;
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

// description 应为简短自然语言描述（如"主按钮大号"），不能是序列化的 JSON 对象/数组——
// 后者会被逐字嵌入多次 LLM 调用的 prompt（normalizeQuery + selectComponentSet + selectVariant），
// 既无法被正确语义匹配，又徒增数倍 token 消耗。match-dsl 走的是 collectNodes 提取 label 后再匹配，
// 不受影响；这里专门拦在 /match、/batch 的入口。
const MAX_DESCRIPTION_LENGTH = 200;

function checkDescription(desc) {
  if (desc === undefined || desc === null || desc === '') {
    return 'description is required';
  }
  if (typeof desc !== 'string') {
    return 'description must be a string';
  }
  const trimmed = desc.trim();
  if (!trimmed) {
    return 'description is required';
  }
  if (trimmed.length > MAX_DESCRIPTION_LENGTH) {
    return `description too long (max ${MAX_DESCRIPTION_LENGTH} chars) — pass a short natural-language description, not a serialized object`;
  }
  if (/^[{\[]/.test(trimmed)) {
    try {
      JSON.parse(trimmed);
      return 'description must be a short natural-language text, not a serialized JSON object/array — extract a field like label/name first';
    } catch {
      // 不是合法 JSON，可能只是描述恰好以 { [ 开头，按普通文本放行
    }
  }
  return null;
}

// ── POST /match ───────────────────────────────────────────────────────────────

app.post('/match', async (req, res) => {
  const { description } = req.body || {};
  const descErr = checkDescription(description);
  if (descErr) {
    return res.status(400).json({ error: descErr });
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

  const invalid = [];
  descriptions.forEach((d, i) => {
    const err = checkDescription(d);
    if (err) invalid.push({ index: i, error: err });
  });
  if (invalid.length > 0) {
    return res.status(400).json({ error: 'invalid descriptions', details: invalid });
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

// ── POST /split ───────────────────────────────────────────────────────────────
// 上传 .pix 组件库文件，调用 split_compset WASM 拆解为
// {componentKey 或 sessionId_localId}.txt + component_index.json。
//
// 不传 source：打包为 zip 返回（zip 根目录即 component/，需手动解压进 lib-out/{source}/）。
// 传了 source：跳过打包，直接把 component/ 写入 LIB_OUT_DIR/{source}/，免去手动解压挪动。
//
// 无论哪种方式，这一步都只完成"拆解落盘"，产物要真正接入查询/匹配能力，
// 仍需按 API.md「新增组件库」一节继续走：登记 SOURCES → 重新生成 search_index.json →
// 同步到本服务 → 重启验证。

const SPLIT_UPLOAD_LIMIT = 200 * 1024 * 1024; // 200MB，.pix 库文件可能较大
const splitUpload = multer({ storage: multer.memoryStorage(), limits: { fileSize: SPLIT_UPLOAD_LIMIT } });

// source 即 lib-out/ 下的目录名，限制为简单目录名，禁止路径分隔符与 .. 防止路径穿越
const SOURCE_DIR_RE = /^[a-zA-Z0-9][a-zA-Z0-9_-]*$/;

app.post('/split', splitUpload.single('file'), async (req, res) => {
  if (!req.file) {
    return res.status(400).json({ error: 'send a .pix file via -F "file=@library.pix"' });
  }

  const publishFile = typeof req.body?.publishFile === 'string' ? req.body.publishFile.trim() : '';
  const source      = typeof req.body?.source === 'string' ? req.body.source.trim() : '';
  if (source && !SOURCE_DIR_RE.test(source)) {
    return res.status(400).json({ error: 'source must be a simple directory name (letters/digits/-/_, no path separators)' });
  }

  try {
    const opts = { originalName: req.file.originalname, publishFile };
    if (source) {
      opts.source  = source;
      opts.saveDir = path.join(LIB_OUT_DIR, source);
    }

    const result = await splitLibrary(req.file.buffer, opts);
    if (result.error) return res.status(500).json({ error: result.error });
    res.json(result);
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
