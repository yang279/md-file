#!/usr/bin/env node
'use strict';

const fs     = require('fs');
const path   = require('path');
const OpenAI = require('openai');

// 自动加载同目录 .env
const envFile = path.resolve(__dirname, '.env');
if (fs.existsSync(envFile)) {
  fs.readFileSync(envFile, 'utf8').split('\n').forEach(line => {
    const [k, v] = line.split('=');
    if (k && v && !process.env[k.trim()]) process.env[k.trim()] = v.trim();
  });
}

const client = new OpenAI({
  apiKey:  process.env.DASHSCOPE_API_KEY,
  baseURL: 'https://api.deepseek.com/v1',
});
const SEARCH_INDEX = path.resolve(__dirname, 'search_index.json');
const MODEL        = process.env.MODEL || 'deepseek-v4-flash';

let _index = null;
function loadIndex() {
  if (!_index) _index = JSON.parse(fs.readFileSync(SEARCH_INDEX, 'utf8'));
  return _index;
}

// ── 第一步：LLM 语义提取 → 中文搜索关键词 ────────────────────────────────────

async function normalizeQuery(description) {
  const response = await client.chat.completions.create({
    model: MODEL,
    max_tokens: 512,
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

// ── 第三步：LLM 精选变体 ──────────────────────────────────────────────────────

async function llmRerank(description, candidates) {
  const sections = candidates.map(cs => {
    const variantLines = (cs.variants || [])
      .map(v => `  - ${v.variantKey || v.guid} | ${v.name}`)
      .join('\n');
    return `【${cs.name}】(${cs.sourceLabel})\nkey: ${cs.componentKey || cs.guid}\n变体:\n${variantLines || '  (无变体，standalone)'}`;
  }).join('\n\n');

  const response = await client.chat.completions.create({
    model: MODEL,
    max_tokens: 2048,
    tools: [{
      type: 'function',
      function: {
        name: 'select_variant',
        description: '选出与描述最匹配的具体变体',
        parameters: {
          type: 'object',
          properties: {
            componentKey: { type: 'string', description: '所属组件的 componentKey 或 guid' },
            variantKey:   { type: 'string', description: '变体的 variantKey 或 guid' },
            reason:       { type: 'string', description: '一句话说明匹配理由' },
          },
          required: ['componentKey', 'variantKey'],
        },
      },
    }],
    tool_choice: 'auto',
    messages: [{
      role: 'user',
      content: `从以下候选组件中，选出与描述最匹配的一个变体。\n\n描述：${description}\n\n候选：\n${sections}`,
    }],
  });

  const toolCall = response.choices[0]?.message?.tool_calls?.[0];
  if (!toolCall) return null;
  return JSON.parse(toolCall.function.arguments);
}

// ── 主入口 ────────────────────────────────────────────────────────────────────

async function matchVariant(description) {
  const { entries } = loadIndex();

  // Step 1: LLM 语义提取
  const keywords = await normalizeQuery(description);

  // Step 2: 本地过滤
  const candidates = localFilter(keywords, entries, 10);
  if (candidates.length === 0) return null;

  // Step 3: LLM 精选，传原始描述（语义更完整）
  const result = await llmRerank(description, candidates);
  if (!result) return null;

  const { componentKey, variantKey, reason } = result;
  const entry = entries.find(e => e.componentKey === componentKey || e.guid === componentKey);
  if (!entry) return null;

  const variant = (entry.variants || []).find(v => v.variantKey === variantKey || v.guid === variantKey);

  return {
    source:           entry.source,
    sourceLabel:      entry.sourceLabel,
    componentSetName: entry.name,
    componentKey:     entry.componentKey || entry.guid,
    hexFile:          entry.hexFile,
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

module.exports = { matchVariant };
