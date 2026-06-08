'use strict';

const http    = require('http');
const fs      = require('fs');
const path    = require('path');
const ComponentSearcher = require('./searcher');

// ---------------------------------------------------------------------------
// 配置
// ---------------------------------------------------------------------------
const PORT          = Number(process.env.PORT) || 3100;
const COMPONENT_DIR = process.env.COMPONENT_DIR
  || path.resolve(__dirname, '../../pixso-parse/pix-split/lib-out/ict-ui/component');
const INDEX_PATH    = process.env.INDEX_PATH
  || path.join(COMPONENT_DIR, 'component_index.json');

// ---------------------------------------------------------------------------
// 启动时加载索引（失败直接退出）
// ---------------------------------------------------------------------------
let searcher;
try {
  searcher = new ComponentSearcher(INDEX_PATH);
  console.log(`组件索引加载成功: ${INDEX_PATH}`);
  console.log(`  componentSets: ${searcher.stats.component_sets}`);
  console.log(`  standaloneComponents: ${searcher.stats.standalone_components}`);
} catch (e) {
  console.error('加载索引失败:', e.message);
  process.exit(1);
}

// ---------------------------------------------------------------------------
// 工具函数
// ---------------------------------------------------------------------------
function sendJSON(res, status, data) {
  const body = JSON.stringify(data);
  res.writeHead(status, {
    'Content-Type':   'application/json; charset=utf-8',
    'Content-Length': Buffer.byteLength(body),
  });
  res.end(body);
}

function readBody(req) {
  return new Promise((resolve, reject) => {
    const chunks = [];
    req.on('data', c => chunks.push(c));
    req.on('end',  () => resolve(Buffer.concat(chunks).toString('utf8')));
    req.on('error', reject);
  });
}

// 允许两种 key 格式，防止路径穿越：
//   旧格式：40 位小写 hex（SHA1 componentKey）
//   新格式：{sessionId}_{localId}（从 guid 派生）
const KEY_RE = /^([a-f0-9]{40}|\d+_\d+)$/;

// ---------------------------------------------------------------------------
// 路由处理
// ---------------------------------------------------------------------------
async function handle(req, res) {
  const url = new URL(req.url, `http://localhost:${PORT}`);

  // GET /health
  if (req.method === 'GET' && url.pathname === '/health') {
    return sendJSON(res, 200, { status: 'ok', ...searcher.stats });
  }

  // POST /query（暂时停用）
  // if (req.method === 'POST' && url.pathname === '/query') {
  //   let body;
  //   try {
  //     body = JSON.parse(await readBody(req));
  //   } catch {
  //     return sendJSON(res, 400, { error: 'invalid JSON body' });
  //   }
  //
  //   const { name, props } = body;
  //   if (!name || typeof name !== 'string' || !name.trim()) {
  //     return sendJSON(res, 400, { error: 'name (string) is required' });
  //   }
  //   if (props !== undefined && (typeof props !== 'object' || Array.isArray(props))) {
  //     return sendJSON(res, 400, { error: 'props must be an object' });
  //   }
  //
  //   const result = await searcher.query({ name, props });
  //   return sendJSON(res, 200, result);
  // }

  // GET /hex/:key
  if (req.method === 'GET' && url.pathname.startsWith('/hex/')) {
    const key = url.pathname.slice(5); // strip '/hex/'
    if (!KEY_RE.test(key)) {
      return sendJSON(res, 400, { error: 'key must be a 40-char lowercase hex string' });
    }

    const filePath = path.join(COMPONENT_DIR, `${key}.txt`);
    if (!fs.existsSync(filePath)) {
      return sendJSON(res, 404, { error: `component not found: ${key}` });
    }

    res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
    fs.createReadStream(filePath).pipe(res);
    return;
  }

  sendJSON(res, 404, { error: 'not found' });
}

// ---------------------------------------------------------------------------
// 启动服务
// ---------------------------------------------------------------------------
const server = http.createServer((req, res) => {
  handle(req, res).catch(err => {
    console.error('请求处理异常:', err);
    if (!res.headersSent) sendJSON(res, 500, { error: 'internal server error' });
  });
});

server.listen(PORT, () => {
  console.log(`\n组件查询服务已启动: http://localhost:${PORT}`);
  console.log(`COMPONENT_DIR: ${COMPONENT_DIR}\n`);
});
