#!/usr/bin/env node
'use strict';

const fs     = require('fs');
const path   = require('path');
const OpenAI = require('openai');

// 自动加载同目录 .env
const envFile = path.resolve(__dirname, '.env');
if (fs.existsSync(envFile)) {
  fs.readFileSync(envFile, 'utf8').split('\n').forEach(line => {
    const trimmed = line.trim();
    if (!trimmed || trimmed.startsWith('#')) return;
    const [k, v] = trimmed.split('=');
    if (k && v && !process.env[k.trim()]) process.env[k.trim()] = v.trim();
  });
}

// LLM 相关配置全部可在 .env 中覆盖：
//   DASHSCOPE_API_KEY  调用密钥（必填）
//   LLM_BASE_URL       接口地址，默认指向 DeepSeek
//   MODEL              模型名，默认 deepseek-v4-flash
//   LLM_TIMEOUT_MS     单次请求超时（毫秒），默认 60000；命中超时时 err.message 形如
//                      "Request timed out." / "Connection error."，会被下面的 callLLM 打到日志里
const BASE_URL   = process.env.LLM_BASE_URL || 'https://api.deepseek.com/v1';
const MODEL      = process.env.MODEL || 'deepseek-v4-flash';
const TIMEOUT_MS = Number(process.env.LLM_TIMEOUT_MS) || 60_000;

const client = new OpenAI({
  apiKey:  process.env.DASHSCOPE_API_KEY,
  baseURL: BASE_URL,
  timeout: TIMEOUT_MS,
});

const SEARCH_INDEX = path.resolve(__dirname, 'search_index.json');

// 包一层日志：记录每次 LLM 调用的发起/耗时/失败原因——
// /match 等接口报错只会把 err.message 透传给调用方，本身不打印任何东西，
// 出现 "timeout" 时单看接口响应不知道是哪一步、卡了多久，必须靠这里的日志定位
async function callLLM(label, params) {
  const start = Date.now();
  console.log(`[match_variant] ${label} → 调用 ${BASE_URL} (model=${MODEL}, timeout=${TIMEOUT_MS}ms)`);
  try {
    const response = await client.chat.completions.create(params);
    console.log(`[match_variant] ${label} ✓ 完成，耗时 ${Date.now() - start}ms`);
    return response;
  } catch (err) {
    console.error(`[match_variant] ${label} ✗ 失败，耗时 ${Date.now() - start}ms：${err.message}`);
    throw err;
  }
}

let _index = null;
function loadIndex() {
  if (!_index) _index = JSON.parse(fs.readFileSync(SEARCH_INDEX, 'utf8'));
  return _index;
}

// rebuild_index 重新生成 search_index.json 后调用，使下次匹配重新读盘而非用旧缓存
function clearIndexCache() {
  _index = null;
}

// ── 第一步：LLM 语义提取 → 中文搜索关键词 ────────────────────────────────────

async function normalizeQuery(description) {
  const response = await callLLM('normalizeQuery（语义提取）', {
    model: MODEL,
    max_tokens: 512,
    thinking: { type: 'disabled' },
    messages: [
      {
        role: 'system',
        content: '你是 UI 组件库搜索助手。将用户描述转换为 2~5 个中文搜索关键词，用于在组件库中检索。只输出关键词，空格分隔，不要任何解释。',
      },
      {
        role: 'user',
        content: description,
      },
    ],
  });
  return response.choices[0]?.message?.content?.trim() || description;
}

// ── 第二步：本地关键词过滤（无 LLM，瞬间完成）────────────────────────────────

function tokenize(text) {
  const words = text.split(/[\s=,\/\-_.()（）【】]+/).filter(t => t.length >= 1);
  const bigrams = [];
  const chars = [...text.replace(/[\s=,\/\-_.()（）【】]+/g, '')];
  for (let i = 0; i < chars.length - 1; i++) {
    bigrams.push(chars[i] + chars[i + 1]);
  }
  return [...new Set([...words, ...bigrams])].filter(t => t.length >= 2);
}

function localFilter(query, entries, topK = 10) {
  const tokens = tokenize(query);
  return entries
    .map(entry => {
      let score = 0;
      for (const tok of tokens) {
        if (entry.searchText.includes(tok)) score += tok.length;
      }
      return { entry, score };
    })
    .filter(x => x.score > 0)
    .sort((a, b) => b.score - a.score)
    .slice(0, topK)
    .map(x => x.entry);
}

// ── 第三步 A：LLM 选组件集（轻量 prompt：仅名称 + 变体数量，不展开变体）────────
//
// 候选集的全部变体名 token 量很大（少数组件集变体数上百），一次性塞给模型会让
// prompt 膨胀到上万 token。先用极小的 prompt 让模型按"组件集语义"判断该选哪个集合，
// 这一步本身不需要看变体细节也能判断准确。

async function selectComponentSet(description, candidates) {
  const list = candidates.map(cs =>
    `【${cs.name}】(${cs.sourceLabel}) key: ${cs.componentKey || cs.guid} | ${(cs.variants || []).length} 个变体`
  ).join('\n');

  const response = await callLLM('selectComponentSet（选组件集）', {
    model: MODEL,
    max_tokens: 256,
    thinking: { type: 'disabled' },
    tools: [{
      type: 'function',
      function: {
        name: 'select_component_set',
        description: '选出与描述最匹配的组件集',
        parameters: {
          type: 'object',
          properties: {
            componentKey: { type: 'string', description: '所选组件集的 componentKey 或 guid' },
          },
          required: ['componentKey'],
        },
      },
    }],
    tool_choice: 'auto',
    messages: [{
      role: 'user',
      content: `从以下候选组件集中，选出与描述最匹配的一个。\n\n描述：${description}\n\n候选：\n${list}`,
    }],
  });

  const toolCall = response.choices[0]?.message?.tool_calls?.[0];
  if (!toolCall) return null;
  const { componentKey } = JSON.parse(toolCall.function.arguments);
  return candidates.find(c => c.componentKey === componentKey || c.guid === componentKey) || null;
}

// ── 第三步 B：LLM 在选定组件集内精选变体（仅展开这一个集合的变体）────────────
//
// 缩小到单一组件集后，prompt 只包含它自己的变体列表，既比"10 个集合的全部变体"
// 小得多，又因为去掉了其他候选集的干扰信息，模型更容易聚焦比对变体差异。

async function selectVariant(description, entry) {
  const variants = entry.variants || [];
  if (variants.length === 0) {
    return { variantKey: null, reason: '该组件为 standalone，无变体' };
  }

  const variantLines = variants
    .map(v => `  - ${v.variantKey || v.guid} | ${v.name}`)
    .join('\n');

  const response = await callLLM('selectVariant（精选变体）', {
    model: MODEL,
    max_tokens: 512,
    thinking: { type: 'disabled' },
    tools: [{
      type: 'function',
      function: {
        name: 'select_variant',
        description: '从指定组件集的变体中选出与描述最匹配的一个',
        parameters: {
          type: 'object',
          properties: {
            variantKey: { type: 'string', description: '变体的 variantKey 或 guid' },
            reason:     { type: 'string', description: '一句话说明匹配理由' },
          },
          required: ['variantKey'],
        },
      },
    }],
    tool_choice: 'auto',
    messages: [{
      role: 'user',
      content: `组件集【${entry.name}】(${entry.sourceLabel}) 有以下变体，选出与描述最匹配的一个。\n\n描述：${description}\n\n变体：\n${variantLines}`,
    }],
  });

  const toolCall = response.choices[0]?.message?.tool_calls?.[0];
  if (!toolCall) return null;
  return JSON.parse(toolCall.function.arguments);
}

// ── 主入口 ────────────────────────────────────────────────────────────────────

async function matchVariant(description) {
  const { entries } = loadIndex();
  console.log(`[match_variant] matchVariant 开始：「${description}」`);

  // Step 1: LLM 语义提取
  const keywords = await normalizeQuery(description);

  // Step 2: 本地过滤
  const candidates = localFilter(keywords, entries, 10);
  if (candidates.length === 0) return null;

  // Step 3a: LLM 选组件集（轻量 prompt，不含变体明细）
  const entry = await selectComponentSet(description, candidates);
  if (!entry) return null;

  // Step 3b: LLM 在选定组件集内精选变体（仅传该集合自己的变体）
  const picked = await selectVariant(description, entry);
  if (!picked) return null;

  const { variantKey, reason } = picked;
  const variant = (entry.variants || []).find(v => v.variantKey === variantKey || v.guid === variantKey);

  return {
    source:           entry.source,
    sourceLabel:      entry.sourceLabel,
    componentSetName: entry.name,
    componentKey:     entry.componentKey || entry.guid,
    hexFile:          entry.hexFile,
    // 相对 LIB_OUT_DIR 的完整路径（= source + '/' + hexFile），可直接写入设计 DSL 的
    // instance.path 字段，供 dsl-to-hex 拼 HEX_LIB_DIR 后本地读取，无需再调用本服务
    path:             entry.source && entry.hexFile ? `${entry.source}/${entry.hexFile}` : null,
    variant:          variant
      ? { name: variant.name, variantKey: variant.variantKey || variant.guid, guid: variant.guid }
      : null,
    reason:           reason || '',
  };
}

// ── CLI ───────────────────────────────────────────────────────────────────────

if (require.main === module) {
  let description;
  if (process.argv[2]) {
    description = process.argv[2];
  } else {
    const stdin = fs.readFileSync('/dev/stdin', 'utf8');
    description = JSON.parse(stdin).description;
  }

  matchVariant(description)
    .then(r => console.log(JSON.stringify(r, null, 2)))
    .catch(err => { console.error(err.message); process.exit(1); });
}

module.exports = { matchVariant, clearIndexCache };
