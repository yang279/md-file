#!/usr/bin/env node
'use strict';

const fs                = require('fs');
const path              = require('path');
const express           = require('express');
const multer            = require('multer');
const { matchVariant, clearIndexCache } = require('./match_variant');
const { matchVariants }  = require('./batch_match');
const { matchDsl, matchDslSingle } = require('./match_dsl');
const { splitLibrary }   = require('./split_lib');
const { loadSources, saveSources, rebuildIndex } = require('./rebuild_index');

// 加载同目录 .env：让 PORT / LIB_OUT_DIR 等配置写在配置文件里而不必每次启动手动传环境变量，
// 显式传入的环境变量优先级更高（不会被 .env 覆盖）
const envFile = path.resolve(__dirname, '.env');
if (fs.existsSync(envFile)) {
  fs.readFileSync(envFile, 'utf8').split('\n').forEach(line => {
    const trimmed = line.trim();
    if (!trimmed || trimmed.startsWith('#')) return;
    const [k, v] = trimmed.split('=');
    if (k && v && !process.env[k.trim()]) process.env[k.trim()] = v.trim();
  });
}

const app    = express();
const PORT   = Number(process.env.PORT) || 3102;
const upload = multer({ storage: multer.memoryStorage() });

// 多组件库根目录：search_index.json 中每个 entry 的 hexFile 是相对 lib-out/{source}/ 的路径
// 优先读取环境变量 / .env 中的 LIB_OUT_DIR，未配置时退回默认相对路径
const LIB_OUT_DIR = process.env.LIB_OUT_DIR
  || path.resolve(__dirname, '../../pixso-parse/pix-split/lib-out');

app.use(express.json());

// 统一打印接口异常/非 2xx 响应：调用方只能看到响应体里的 { error }，看不到时间戳、
// 请求参数、是哪一步触发的——出问题时只能在调用方那一侧干瞪眼。这里在响应前统一落一条
// server 端日志（4xx 用 warn，5xx 用 error），带上时间戳、接口路径、简要请求信息和
// 失败原因，方便对照 match_variant 里逐步的 LLM 调用日志，串起"请求进来 → 卡在哪一步
// → 返回了什么"的完整链路
function logRouteResponse(label, status, message, extra) {
  const extraStr = extra ? ` (${extra})` : '';
  const line = `[${new Date().toISOString()}] ${label}${extraStr} 返回 ${status}：${message}`;
  if (status >= 500) console.error(line);
  else console.warn(line);
}

// 4xx/5xx 统一走这里发响应：日志和响应体一次性落地，不会出现"光记日志却忘了统一格式"
// 或者"响应了却没留痕迹"的不一致。payload 通常是 { error, ... }，日志里取 error 字段展示
function sendError(res, label, status, payload, extra) {
  const message = (payload && typeof payload === 'object' && 'error' in payload)
    ? payload.error
    : JSON.stringify(payload);
  logRouteResponse(label, status, message, extra);
  return res.status(status).json(payload);
}

// 进入每个接口时打一条"收到请求"日志，带上能帮助定位的关键参数——
// 这样从日志就能看出"请求到了没有 / 参数是什么 / 是卡住了还是根本没收到请求"
function logRouteEnter(label, extra) {
  const extraStr = extra ? ` (${extra})` : '';
  console.log(`[${new Date().toISOString()}] ${label}${extraStr} 收到请求`);
}

// ---------------------------------------------------------------------------
// 启动时根据 search_index.json 构建 hexKey → 绝对路径 的映射
// hexKey 取自 hexFile 的文件名（不含扩展名），如 "component/93_55829.txt" → "93_55829"
// ---------------------------------------------------------------------------
const SEARCH_INDEX_PATH = path.resolve(__dirname, 'search_index.json');
const hexPathMap = new Map();

function buildHexPathMap() {
  const { entries } = JSON.parse(fs.readFileSync(SEARCH_INDEX_PATH, 'utf8'));
  hexPathMap.clear();
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

// source / sources[].key 即 lib-out/ 下的目录名，限制为简单目录名，禁止路径分隔符与 .. 防止路径穿越
const SOURCE_DIR_RE = /^[a-zA-Z0-9][a-zA-Z0-9_-]*$/;

// ── GET /health ───────────────────────────────────────────────────────────────

app.get('/health', (req, res) => {
  res.json({ status: 'ok', hex_keys: hexPathMap.size });
});

// ── /sources ──────────────────────────────────────────────────────────────────
// 组件库注册表，存于本服务的 sources.json。
// key 必须与 LIB_OUT_DIR 下的子目录名完全一致，否则 rebuild-index 会跳过该库。

app.get('/sources', (req, res) => {
  res.json({ sources: loadSources() });
});

app.post('/sources', (req, res) => {
  const key   = typeof req.body?.key === 'string' ? req.body.key.trim() : '';
  const label = typeof req.body?.label === 'string' ? req.body.label.trim() : '';
  logRouteEnter('POST /sources', `key="${key}", label="${label}"`);

  if (!key || !SOURCE_DIR_RE.test(key)) {
    return sendError(res, 'POST /sources', 400, { error: 'key must be a simple directory name (letters/digits/-/_, no path separators), matching the lib-out/ subdirectory' }, `key="${key}"`);
  }
  if (!label) {
    return sendError(res, 'POST /sources', 400, { error: 'label is required' }, `key="${key}"`);
  }

  const sources = loadSources();
  if (sources.some(s => s.key === key)) {
    return sendError(res, 'POST /sources', 409, { error: `source already registered: ${key}` });
  }

  sources.push({ key, label });
  saveSources(sources);
  res.json({ sources });
});

// ── POST /rebuild-index ───────────────────────────────────────────────────────
// 基于 sources.json 登记的组件库，重新读取各自的 component_index.json 并合并生成
// search_index.json，然后热重载 hexPathMap 与 match_variant 的索引缓存——
// 全程在本服务内完成，重建后立即热生效，无需重启。

app.post('/rebuild-index', (req, res) => {
  logRouteEnter('POST /rebuild-index');
  try {
    console.log('[server] /rebuild-index → 开始读取 sources.json 并重新生成 search_index.json');
    const result = rebuildIndex(LIB_OUT_DIR);
    console.log(`[server] /rebuild-index → 索引已重写，开始重建 hexPathMap 并清空匹配缓存（entries=${result.entries}）`);
    const hexKeys = buildHexPathMap();
    clearIndexCache();
    console.log(`[server] /rebuild-index ✓ 完成：hex_keys=${hexKeys}`);
    res.json({ ...result, hex_keys: hexKeys });
  } catch (err) {
    sendError(res, 'POST /rebuild-index', 500, { error: err.message });
  }
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
  const descLog = `description=${JSON.stringify(description)}`;
  logRouteEnter('POST /match', descLog);

  const descErr = checkDescription(description);
  if (descErr) {
    return sendError(res, 'POST /match', 400, { error: descErr }, descLog);
  }
  const trimmed = description.trim();
  try {
    const result = await matchVariant(trimmed);
    if (!result) return sendError(res, 'POST /match', 404, { error: 'no match found' }, `description="${trimmed}"`);
    console.log(`[server] POST /match (description="${trimmed}") ✓ 命中：${result.componentSetName} / ${result.variant?.name || '(standalone)'}`);
    res.json(result);
  } catch (err) {
    sendError(res, 'POST /match', 500, { error: err.message }, `description="${trimmed}"`);
  }
});

// ── POST /batch ───────────────────────────────────────────────────────────────

app.post('/batch', async (req, res) => {
  const body = req.body;
  let descriptions;
  logRouteEnter('POST /batch', `body 类型=${Array.isArray(body) ? 'array' : typeof body}`);

  if (Array.isArray(body)) {
    descriptions = body.map(x => (typeof x === 'string' ? x : x.description));
  } else if (Array.isArray(body?.descriptions)) {
    descriptions = body.descriptions;
  } else {
    return sendError(res, 'POST /batch', 400, { error: 'body must be an array or { descriptions: [] }' });
  }

  if (descriptions.length === 0) {
    return sendError(res, 'POST /batch', 400, { error: 'descriptions array is empty' });
  }
  if (descriptions.length > 100) {
    return sendError(res, 'POST /batch', 400, { error: 'max 100 descriptions per request' }, `实际 ${descriptions.length} 条`);
  }

  const invalid = [];
  descriptions.forEach((d, i) => {
    const err = checkDescription(d);
    if (err) invalid.push({ index: i, error: err });
  });
  if (invalid.length > 0) {
    return sendError(res, 'POST /batch', 400, { error: 'invalid descriptions', details: invalid }, `${invalid.length}/${descriptions.length} 条不合法`);
  }

  console.log(`[server] POST /batch → 开始批量匹配 ${descriptions.length} 条描述（内部 5 并发）`);
  try {
    const results = await matchVariants(descriptions.map(d => d?.trim?.() ?? d));
    const hit = results.filter(r => r && !r.error).length;
    console.log(`[server] POST /batch ✓ 完成：${descriptions.length} 条中 ${hit} 条命中`);
    res.json(results);
  } catch (err) {
    sendError(res, 'POST /batch', 500, { error: err.message }, `${descriptions.length} 条描述`);
  }
});

// ── POST /match-dsl 与 /match-dsl-single 共用：解析 multipart / JSON 两种请求体 ──
// 支持两种方式：
//   1. multipart 文件上传：-F "file=@page.json"
//   2. JSON body：-H "Content-Type: application/json" -d '{...}'

function readDslRequestBody(req, res, label) {
  if (req.file) {
    console.log(`[server] ${label} → multipart 文件上传：${req.file.originalname}（${req.file.size} 字节）`);
    try {
      return JSON.parse(req.file.buffer.toString('utf8'));
    } catch {
      sendError(res, label, 400, { error: 'uploaded file is not valid JSON' }, req.file.originalname);
      return undefined;
    }
  }
  if (req.body && typeof req.body === 'object' && Object.keys(req.body).length > 0) {
    console.log(`[server] ${label} → JSON body，根节点 keys=[${Object.keys(req.body).join(', ')}]`);
    return req.body;
  }
  sendError(res, label, 400, { error: 'send a file via -F "file=@page.json" or a JSON body' });
  return undefined;
}

// ── POST /match-dsl ───────────────────────────────────────────────────────────
// 整页统一匹配：本页所有实例合并成一次 LLM 裁决，看到全局上下文后统一选择，
// 同语义的多个实例（如多个"确定按钮"）会得到一致的组件集/变体

app.post('/match-dsl', upload.single('file'), async (req, res) => {
  logRouteEnter('POST /match-dsl');
  const nodeData = readDslRequestBody(req, res, 'POST /match-dsl');
  if (nodeData === undefined) return;

  try {
    const results = await matchDsl(nodeData);
    const hit = results.filter(r => r.match).length;
    console.log(`[server] POST /match-dsl ✓ 完成：提取到 ${results.length} 个可匹配节点，命中 ${hit} 个`);
    res.json(results);
  } catch (err) {
    sendError(res, 'POST /match-dsl', 500, { error: err.message });
  }
});

// ── POST /match-dsl-single ────────────────────────────────────────────────────
// 逐节点独立匹配（旧版行为）：每个实例各自跑一遍完整匹配流程，互不知情，
// 可能导致同语义的多个实例被分别选到不一致的组件集/变体；
// 保留供对照旧行为或排查问题时使用，新接入建议直接用 /match-dsl

app.post('/match-dsl-single', upload.single('file'), async (req, res) => {
  logRouteEnter('POST /match-dsl-single');
  const nodeData = readDslRequestBody(req, res, 'POST /match-dsl-single');
  if (nodeData === undefined) return;

  try {
    const results = await matchDslSingle(nodeData);
    const hit = results.filter(r => r.match).length;
    console.log(`[server] POST /match-dsl-single ✓ 完成：提取到 ${results.length} 个可匹配节点，命中 ${hit} 个`);
    res.json(results);
  } catch (err) {
    sendError(res, 'POST /match-dsl-single', 500, { error: err.message });
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
// 仍需按 API.md「新增组件库」一节继续走：POST /sources 注册 → POST /rebuild-index
// 重建索引并热重载。

const SPLIT_UPLOAD_LIMIT = 200 * 1024 * 1024; // 200MB，.pix 库文件可能较大
const splitUpload = multer({ storage: multer.memoryStorage(), limits: { fileSize: SPLIT_UPLOAD_LIMIT } });

app.post('/split', splitUpload.single('file'), async (req, res) => {
  if (!req.file) {
    logRouteEnter('POST /split');
    return sendError(res, 'POST /split', 400, { error: 'send a .pix file via -F "file=@library.pix"' });
  }

  const publishFile = typeof req.body?.publishFile === 'string' ? req.body.publishFile.trim() : '';
  const source      = typeof req.body?.source === 'string' ? req.body.source.trim() : '';
  logRouteEnter('POST /split', `file=${req.file.originalname} (${req.file.size} 字节), source="${source || '(未指定，返回 zip)'}"`);

  if (source && !SOURCE_DIR_RE.test(source)) {
    return sendError(res, 'POST /split', 400, { error: 'source must be a simple directory name (letters/digits/-/_, no path separators)' }, `source="${source}"`);
  }

  try {
    const opts = { originalName: req.file.originalname, publishFile };
    if (source) {
      opts.source  = source;
      opts.saveDir = path.join(LIB_OUT_DIR, source);
    }

    console.log(`[server] POST /split → 调用 split_compset WASM 拆解 ${req.file.originalname}`);
    const result = await splitLibrary(req.file.buffer, opts);
    if (result.error) return sendError(res, 'POST /split', 500, { error: result.error }, req.file.originalname);
    console.log(`[server] POST /split ✓ 完成：${JSON.stringify(result.stats || result)}`);
    res.json(result);
  } catch (err) {
    sendError(res, 'POST /split', 500, { error: err.message }, req.file.originalname);
  }
});

// ── GET /hex/:key ─────────────────────────────────────────────────────────────
// 跨组件库查找 hex 文件：通过 search_index.json 构建的映射定位实际文件路径
// （不同库的 hex 文件分散在 lib-out/{source}/component/ 下）

app.get('/hex/:key', (req, res) => {
  const { key } = req.params;
  logRouteEnter('GET /hex/:key', `key="${key}"`);

  if (!KEY_RE.test(key)) {
    return sendError(res, 'GET /hex/:key', 400, { error: 'key must be a 40-char lowercase hex string or {sessionId}_{localId}' }, `key="${key}"`);
  }

  const filePath = hexPathMap.get(key);
  if (!filePath || !fs.existsSync(filePath)) {
    return sendError(res, 'GET /hex/:key', 404, { error: `component not found: ${key}` }, `key="${key}"`);
  }

  console.log(`[server] GET /hex/:key (key="${key}") ✓ 命中：${filePath}`);
  res.set('Content-Type', 'text/plain; charset=utf-8');
  fs.createReadStream(filePath).pipe(res);
});

app.listen(PORT, () => {
  console.log(`component-service 已启动: http://localhost:${PORT}`);
  console.log(`LIB_OUT_DIR: ${LIB_OUT_DIR}`);
});
