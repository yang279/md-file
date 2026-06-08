'use strict';

const fs   = require('fs');
const os   = require('os');
const path = require('path');
const http  = require('http');
const https = require('https');
const { spawnSync } = require('child_process');

// ---------------------------------------------------------------------------
// WASM 单例（服务生命周期内只初始化一次）
// ---------------------------------------------------------------------------
let _wasmMod = null;

async function getWasm() {
  if (_wasmMod) return _wasmMod;

  const wasmJs = process.env.WASM_PATH
    || path.join(__dirname, 'bin/dsl_to_hex.js');

  if (!fs.existsSync(wasmJs)) {
    throw new Error(`WASM 文件不存在: ${wasmJs}\n请设置环境变量 WASM_PATH`);
  }

  const DslToHex = require(wasmJs);
  _wasmMod = await DslToHex();
  return _wasmMod;
}

// ---------------------------------------------------------------------------
// 遍历 DSL 图层树，收集所有不重复的 component_set_key
// ---------------------------------------------------------------------------
function collectKeys(layer, out) {
  if (layer.type === 'instance') {
    const key = layer.instance && layer.instance.component_set_key;
    if (key) out.add(key);
    return; // instance 不含 children
  }
  for (const child of layer.children || []) {
    collectKeys(child, out);
  }
}

function extractComponentKeys(dsl) {
  const keys = new Set();
  for (const page of dsl.pages || []) {
    for (const layer of page.layers || []) {
      collectKeys(layer, keys);
    }
  }
  return [...keys];
}

// ---------------------------------------------------------------------------
// 遍历 DSL 图层树，收集 svg/image 类型的 placeholder
// ---------------------------------------------------------------------------
function collectPlaceholders(layer, out) {
  const p = layer.placeholder;
  if (p && p.is_placeholder && p.note) {
    const type = p.replacement_type;
    if (type === 'svg' || type === 'image') {
      out.push({ id: layer.id, type, note: p.note });
    }
  }
  for (const child of layer.children || []) {
    collectPlaceholders(child, out);
  }
}

function extractPlaceholders(dsl) {
  const list = [];
  for (const page of dsl.pages || []) {
    for (const layer of page.layers || []) {
      collectPlaceholders(layer, list);
    }
  }
  return list;
}

// id "1:14" → "1_14"（用于文件名）
function idToGuid(id) {
  return String(id).replace(/:/g, '_');
}

// ---------------------------------------------------------------------------
// HTTP GET 工具（不依赖第三方库）
// ---------------------------------------------------------------------------
function httpGet(url) {
  return new Promise((resolve, reject) => {
    const mod = url.startsWith('https:') ? https : http;
    const req = mod.get(url, res => {
      if (res.statusCode !== 200) {
        res.resume();
        const err = new Error(`HTTP ${res.statusCode}: ${url}`);
        err.statusCode = res.statusCode;
        return reject(err);
      }
      const chunks = [];
      res.on('data', c => chunks.push(c));
      res.on('end',  () => resolve(Buffer.concat(chunks).toString('utf8')));
    });
    req.on('error', reject);
  });
}

// ---------------------------------------------------------------------------
// 并发拉取所有组件的 hex 内容
// ---------------------------------------------------------------------------
async function fetchAllHex(keys, queryBaseUrl) {
  const results = await Promise.allSettled(
    keys.map(async key => {
      const content = await httpGet(`${queryBaseUrl}/hex/${key}`);
      return { key, content };
    })
  );

  const hexMap     = {};
  const missingKeys = [];
  for (const r of results) {
    if (r.status === 'fulfilled') {
      hexMap[r.value.key] = r.value.content;
    } else {
      // 取 key 名（从 URL 末尾或错误信息里提取不到时兜底）
      const key = r.reason?.message?.match(/\/hex\/([a-f0-9]{40})/)?.[1] || 'unknown';
      missingKeys.push(key);
      console.warn(`[WARN] 组件 hex 拉取失败: ${r.reason?.message}`);
    }
  }
  return { hexMap, missingKeys };
}

// ---------------------------------------------------------------------------
// 将 hex 输出与 svg/png 资源打包成 zip，返回 Buffer
// ---------------------------------------------------------------------------
function buildZip(tmpDir, hexContent, placeholders) {
  fs.writeFileSync(path.join(tmpDir, 'output.hex'), hexContent, 'utf8');

  const files = ['output.hex'];
  for (const { id, type } of placeholders) {
    const guid = idToGuid(id);
    const fname = type === 'svg' ? `${guid}.svg` : `${guid}.png`;
    if (fs.existsSync(path.join(tmpDir, fname))) files.push(fname);
  }

  const zipPath = path.join(tmpDir, 'output.zip');
  const r = spawnSync('zip', [zipPath, ...files], { cwd: tmpDir });
  if (r.status !== 0) {
    throw new Error(`zip 打包失败: ${r.stderr?.toString().trim()}`);
  }
  return fs.readFileSync(zipPath);
}

// ---------------------------------------------------------------------------
// 解析 WASM dslToHex 的返回值
// WASM 返回三种格式：
//   1. '{"error":"..."}' — 转换失败
//   2. '{"hex":"...","missing":["key",...]}' — 成功但有缺失组件
//   3. '<!-- pixso binary data -->\n{hex}' — 完全成功
// ---------------------------------------------------------------------------
function parseWasmResult(raw) {
  if (raw.startsWith('{"error"')) {
    return JSON.parse(raw); // { error: "..." }
  }
  if (raw.startsWith('{"hex"')) {
    const r = JSON.parse(raw);
    // WASM 在 JSON 中对换行和引号做了转义，这里还原
    const hex = r.hex.replace(/\\n/g, '\n').replace(/\\"/g, '"');
    return { hex, missing_keys: r.missing || [] };
  }
  return { hex: raw };
}

// ---------------------------------------------------------------------------
// 主转换函数
// ---------------------------------------------------------------------------
async function convert(dsl) {
  const queryBaseUrl = (process.env.COMPONENT_QUERY_URL || 'http://localhost:3100').replace(/\/$/, '');

  // 1. 提取所有 component_set_key
  const keys = extractComponentKeys(dsl);

  // 2. 并发拉取 hex 内容
  const { hexMap, missingKeys: fetchMissing } = await fetchAllHex(keys, queryBaseUrl);

  // 3. 写临时目录
  const tmpDir = fs.mkdtempSync(path.join(os.tmpdir(), 'pix-'));
  try {
    // hex 文件：{tmpDir}/{key}.txt（WASM 按此格式查找）
    for (const [key, content] of Object.entries(hexMap)) {
      fs.writeFileSync(path.join(tmpDir, `${key}.txt`), content, 'utf8');
    }

    // placeholder svg/image 文件：{tmpDir}/{guid}.svg 或 {guid}.png
    const placeholders = extractPlaceholders(dsl);
    for (const { id, type, note } of placeholders) {
      const guid = idToGuid(id);
      if (type === 'svg') {
        fs.writeFileSync(path.join(tmpDir, `${guid}.svg`), note, 'utf8');
      } else {
        // base64 → binary
        const b64 = note.replace(/^data:image\/[^;]+;base64,/, '');
        fs.writeFileSync(path.join(tmpDir, `${guid}.png`), Buffer.from(b64, 'base64'));
      }
    }

    // DSL JSON 临时文件
    const dslPath = path.join(tmpDir, 'dsl.json');
    fs.writeFileSync(dslPath, JSON.stringify(dsl), 'utf8');

    // 4. 调用 WASM（同步，阻塞事件循环，单线程自然串行）
    const mod = await getWasm();
    const raw = mod.dslToHex(dslPath, tmpDir);

    // 5. 解析结果
    const result = parseWasmResult(raw);
    if (result.error) return result;

    // 6. 打包 zip
    const zipBuf = buildZip(tmpDir, result.hex, placeholders);

    // 合并 fetch 阶段的 missing 与 WASM 报告的 missing
    const allMissing = [...fetchMissing, ...(result.missing_keys || [])];
    const out = { zip: zipBuf.toString('base64') };
    if (allMissing.length > 0) out.missing_keys = [...new Set(allMissing)];
    return out;
  } finally {
    // 7. 无论成功失败都清理临时目录
    try { fs.rmSync(tmpDir, { recursive: true, force: true }); } catch {}
  }
}

module.exports = { convert, getWasm };
