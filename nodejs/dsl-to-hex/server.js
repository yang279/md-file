'use strict';

const http      = require('http');
const { convert, getWasm, HEX_LIB_DIR } = require('./converter');

// ---------------------------------------------------------------------------
// 配置
// ---------------------------------------------------------------------------
const PORT = Number(process.env.PORT) || 3101;

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

// ---------------------------------------------------------------------------
// 路由处理
// ---------------------------------------------------------------------------
async function handle(req, res) {
  const url = new URL(req.url, `http://localhost:${PORT}`);

  // GET /health
  if (req.method === 'GET' && url.pathname === '/health') {
    return sendJSON(res, 200, { status: 'ok' });
  }

  // POST /convert
  if (req.method === 'POST' && url.pathname === '/convert') {
    let body;
    try {
      body = JSON.parse(await readBody(req));
    } catch {
      return sendJSON(res, 400, { error: 'invalid JSON body' });
    }

    const { dsl } = body;
    if (!dsl || typeof dsl !== 'object') {
      return sendJSON(res, 400, { error: 'dsl (object) is required' });
    }
    if (!Array.isArray(dsl.pages)) {
      return sendJSON(res, 400, { error: 'dsl.pages must be an array' });
    }

    const result = await convert(dsl);

    if (result.error) return sendJSON(res, 500, result);
    return sendJSON(res, 200, result);
  }

  sendJSON(res, 404, { error: 'not found' });
}

// ---------------------------------------------------------------------------
// 启动服务（预热 WASM）
// ---------------------------------------------------------------------------
async function main() {
  console.log('预热 WASM...');
  try {
    await getWasm();
    console.log('WASM 加载成功');
  } catch (e) {
    console.error('WASM 加载失败:', e.message);
    process.exit(1);
  }

  const server = http.createServer((req, res) => {
    handle(req, res).catch(err => {
      console.error('请求处理异常:', err);
      if (!res.headersSent) sendJSON(res, 500, { error: 'internal server error' });
    });
  });

  server.listen(PORT, () => {
    console.log(`\nDSL转hex服务已启动: http://localhost:${PORT}`);
    console.log(`HEX_LIB_DIR: ${HEX_LIB_DIR}\n`);
  });
}

main();
