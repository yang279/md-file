#!/usr/bin/env node
'use strict';

/**
 * 离线向量索引构建脚本
 *
 * 用法：
 *   node build-embeddings.js
 *
 * 输出：
 *   {COMPONENT_DIR}/embeddings.json
 *
 * 环境变量（均有默认值，通常不需要设置）：
 *   COMPONENT_DIR     组件目录（含 component_index.json）
 *   INDEX_PATH        索引文件路径（默认 COMPONENT_DIR/component_index.json）
 *   EMBEDDING_MODEL   模型名称
 *   OLLAMA_URL        Ollama 服务地址（默认 http://localhost:11434）
 *   OPENAI_API_KEY    设置后自动切换到 OpenAI embedding API
 *
 * embedding API 选择：
 *   未设置 OPENAI_API_KEY → 使用 Ollama nomic-embed-text（本地，免费）
 *   设置   OPENAI_API_KEY → 使用 OpenAI text-embedding-3-small
 */

const fs   = require('fs');
const path = require('path');
const http  = require('http');
const https = require('https');

// ---------------------------------------------------------------------------
// 配置
// ---------------------------------------------------------------------------
const COMPONENT_DIR = process.env.COMPONENT_DIR
  || path.resolve(__dirname, '../../pixso-parse/pix-split/lib-out/ict-ui/component');
const INDEX_PATH = process.env.INDEX_PATH
  || path.join(COMPONENT_DIR, 'component_index.json');
const OUTPUT_PATH = path.join(COMPONENT_DIR, 'embeddings.json');

const USE_OPENAI     = !!process.env.OPENAI_API_KEY;
const OLLAMA_URL     = process.env.OLLAMA_URL || 'http://localhost:11434';
const DEFAULT_MODEL  = USE_OPENAI ? 'text-embedding-3-small' : 'nomic-embed-text';
const MODEL          = process.env.EMBEDDING_MODEL || DEFAULT_MODEL;
const BATCH_SIZE     = USE_OPENAI ? 20 : 5; // OpenAI 支持批量，Ollama 逐条更稳

// ---------------------------------------------------------------------------
// HTTP POST
// ---------------------------------------------------------------------------
function httpPost(url, body, extraHeaders = {}) {
  return new Promise((resolve, reject) => {
    const data   = JSON.stringify(body);
    const parsed = new URL(url);
    const mod    = parsed.protocol === 'https:' ? https : http;
    const opts   = {
      hostname: parsed.hostname,
      port:     parsed.port || (parsed.protocol === 'https:' ? 443 : 80),
      path:     parsed.pathname,
      method:   'POST',
      headers:  {
        'Content-Type':   'application/json',
        'Content-Length': Buffer.byteLength(data),
        ...extraHeaders,
      },
    };
    const req = mod.request(opts, res => {
      const chunks = [];
      res.on('data', c => chunks.push(c));
      res.on('end', () => {
        const text = Buffer.concat(chunks).toString();
        if (res.statusCode !== 200) {
          return reject(new Error(`HTTP ${res.statusCode}: ${text.slice(0, 200)}`));
        }
        try { resolve(JSON.parse(text)); }
        catch (e) { reject(new Error(`JSON parse error: ${text.slice(0, 200)}`)); }
      });
    });
    req.on('error', reject);
    req.end(data);
  });
}

// ---------------------------------------------------------------------------
// Embedding：Ollama（单条）或 OpenAI（批量）
// ---------------------------------------------------------------------------
async function embedOllama(text) {
  const res = await httpPost(
    `${OLLAMA_URL}/api/embeddings`,
    { model: MODEL, prompt: text }
  );
  if (!res.embedding) throw new Error('Ollama 未返回 embedding 字段');
  return res.embedding;
}

async function embedOpenAIBatch(texts) {
  const res = await httpPost(
    'https://api.openai.com/v1/embeddings',
    { model: MODEL, input: texts },
    { 'Authorization': `Bearer ${process.env.OPENAI_API_KEY}` }
  );
  // 按 index 排序返回
  return res.data.sort((a, b) => a.index - b.index).map(d => d.embedding);
}

// ---------------------------------------------------------------------------
// 从 component_index.json 提取所有待嵌入条目
// ---------------------------------------------------------------------------
function buildEntries(index) {
  const entries = [];

  for (const cs of index.componentSets || []) {
    const hexKey = path.basename(cs.hexFile, '.txt');
    for (const v of cs.variants || []) {
      entries.push({
        id:      v.guid,                                       // 唯一 key
        hex_key: hexKey,                                       // 对应 hex 文件
        // 描述文本：组件名 / 变体属性 / 分类
        text:    `${cs.name} / ${v.name} / ${cs.canvasName}`,
      });
    }
    // componentSet 自身也加一条（方便按名称搜索整个组件集）
    entries.push({
      id:      cs.guid + '__set',
      hex_key: hexKey,
      text:    `${cs.name} / ${cs.canvasName}`,
    });
  }

  for (const sc of index.standaloneComponents || []) {
    const hexKey = path.basename(sc.hexFile, '.txt');
    entries.push({
      id:      sc.guid,
      hex_key: hexKey,
      text:    `${sc.name} / ${sc.canvasName}`,
    });
  }

  return entries;
}

// ---------------------------------------------------------------------------
// 主流程
// ---------------------------------------------------------------------------
async function main() {
  if (!fs.existsSync(INDEX_PATH)) {
    console.error(`索引文件不存在: ${INDEX_PATH}`);
    process.exit(1);
  }

  const index   = JSON.parse(fs.readFileSync(INDEX_PATH, 'utf8'));
  const entries = buildEntries(index);

  console.log(`组件目录:  ${COMPONENT_DIR}`);
  console.log(`Embedding: ${USE_OPENAI ? 'OpenAI' : 'Ollama'} / ${MODEL}`);
  console.log(`待嵌入条目: ${entries.length}`);
  console.log(`输出文件:  ${OUTPUT_PATH}`);
  console.log('');

  // 如果已有 embeddings.json，跳过已处理的条目（支持断点续传）
  let existing = {};
  if (fs.existsSync(OUTPUT_PATH)) {
    try {
      const prev = JSON.parse(fs.readFileSync(OUTPUT_PATH, 'utf8'));
      existing = prev.entries || prev;
      console.log(`已有 ${Object.keys(existing).length} 条，跳过重复`);
    } catch {}
  }

  const result = { ...existing };
  const todo   = entries.filter(e => !result[e.id]);
  console.log(`本次需处理: ${todo.length} 条\n`);

  if (todo.length === 0) {
    console.log('全部已完成，无需重新计算。');
    return;
  }

  let done = 0;
  const startTime = Date.now();

  if (USE_OPENAI) {
    // OpenAI：批量处理
    for (let i = 0; i < todo.length; i += BATCH_SIZE) {
      const batch = todo.slice(i, i + BATCH_SIZE);
      const texts = batch.map(e => e.text);
      const vecs  = await embedOpenAIBatch(texts);
      for (let j = 0; j < batch.length; j++) {
        result[batch[j].id] = { hex_key: batch[j].hex_key, text: batch[j].text, vec: vecs[j] };
      }
      done += batch.length;
      const elapsed = ((Date.now() - startTime) / 1000).toFixed(1);
      process.stdout.write(`\r进度: ${done}/${todo.length}  耗时: ${elapsed}s`);
      // 每批保存一次（防止中断丢失）
      saveResult(result, MODEL);
    }
  } else {
    // Ollama：逐条处理（Ollama 单条更稳定）
    for (let i = 0; i < todo.length; i += BATCH_SIZE) {
      const batch = todo.slice(i, i + BATCH_SIZE);
      await Promise.all(batch.map(async entry => {
        try {
          const vec = await embedOllama(entry.text);
          result[entry.id] = { hex_key: entry.hex_key, text: entry.text, vec };
        } catch (e) {
          console.warn(`\n  [跳过] ${entry.id}: ${e.message}`);
        }
      }));
      done += batch.length;
      const elapsed = ((Date.now() - startTime) / 1000).toFixed(1);
      process.stdout.write(`\r进度: ${done}/${todo.length}  耗时: ${elapsed}s`);
      // 每批保存
      saveResult(result, MODEL);
    }
  }

  console.log(`\n\n完成！共 ${Object.keys(result).length} 条向量已写入 ${OUTPUT_PATH}`);
}

function saveResult(entries, model) {
  fs.writeFileSync(OUTPUT_PATH, JSON.stringify({
    meta: {
      model,
      count:    Object.keys(entries).length,
      built_at: new Date().toISOString(),
    },
    entries,
  }));
}

main().catch(err => {
  console.error('\n错误:', err.message);
  process.exit(1);
});
