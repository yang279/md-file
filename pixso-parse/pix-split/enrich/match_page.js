#!/usr/bin/env node
'use strict';

const fs       = require('fs');
const path     = require('path');
const Anthropic = require('@anthropic-ai/sdk');

const client = new Anthropic.default();
const INDEX  = path.resolve(__dirname, 'merged.json');
const MODEL  = 'claude-opus-4-8';

// ── 压缩索引（仅 key + 来源 + 名称，供 Stage 1 用）────────────────────────────

function buildCondensedIndex(index) {
  const lines = [];
  for (const cs of index.componentSets) {
    lines.push(`${cs.componentKey || cs.guid} | ${cs.sourceLabel} | ${cs.name}`);
  }
  for (const sc of index.standaloneComponents) {
    lines.push(`${sc.componentKey || sc.guid} | ${sc.sourceLabel} | ${sc.name} [standalone]`);
  }
  return lines.join('\n');
}

// ── Stage 1：一次调用，为所有 instance 批量粗筛候选组件集 ──────────────────────

async function stage1BatchCandidates(instances, index, pageDescription) {
  const condensed    = buildCondensedIndex(index);
  const instanceList = instances
    .map(inst => `- ${inst.id}: ${inst.hint}`)
    .join('\n');

  const response = await client.messages.create({
    model: MODEL,
    max_tokens: 1024,
    tools: [{
      name: 'select_candidates',
      description: '为页面中每个 instance 从组件库索引中选出 1-3 个候选组件集的 key',
      input_schema: {
        type: 'object',
        properties: {
          matches: {
            type: 'array',
            items: {
              type: 'object',
              properties: {
                id:   { type: 'string', description: 'instance 的 id' },
                keys: {
                  type: 'array',
                  items: { type: 'string' },
                  maxItems: 3,
                  description: '候选组件集的 componentKey 或 guid',
                },
              },
              required: ['id', 'keys'],
            },
          },
        },
        required: ['matches'],
      },
    }],
    tool_choice: { type: 'tool', name: 'select_candidates' },
    messages: [{
      role: 'user',
      content: [
        `你是一个 UI 组件匹配助手。请根据页面描述和各组件的意图，从组件库索引中为每个 instance 选出 1-3 个最相关的候选组件集。`,
        ``,
        `页面描述：${pageDescription || '（未提供）'}`,
        ``,
        `需要匹配的组件（id: 意图描述）：`,
        instanceList,
        ``,
        `组件库索引（格式：componentKey | 来源 | 组件名）：`,
        condensed,
      ].join('\n'),
    }],
  });

  const toolUse = response.content.find(b => b.type === 'tool_use');
  return toolUse ? toolUse.input.matches : [];
}

// ── Stage 2：一次调用，为所有候选精选最匹配的变体 ────────────────────────────

async function stage2BatchVariants(instances, candidateMatches, index) {
  const allEntries = [...index.componentSets, ...index.standaloneComponents];

  const sections = candidateMatches.map(({ id, keys }) => {
    const inst = instances.find(i => i.id === id);
    const details = keys.map(k => {
      const entry = allEntries.find(e => e.componentKey === k || e.guid === k);
      if (!entry) return `  [${k}: 未找到]`;
      const variantLines = (entry.variants || [])
        .map(v => `    - ${v.variantKey || v.guid} | ${v.name}`)
        .join('\n');
      return [
        `  【${entry.name}】(${entry.sourceLabel})`,
        `  componentKey: ${entry.componentKey || entry.guid}`,
        variantLines ? `  变体:\n${variantLines}` : `  (无变体，standalone)`,
      ].join('\n');
    }).join('\n');

    return `=== ${id}: ${inst?.hint || ''} ===\n${details}`;
  }).join('\n\n');

  const response = await client.messages.create({
    model: MODEL,
    max_tokens: 2048,
    tools: [{
      name: 'select_variants',
      description: '为每个 instance 选出最匹配的具体变体',
      input_schema: {
        type: 'object',
        properties: {
          results: {
            type: 'array',
            items: {
              type: 'object',
              properties: {
                id:           { type: 'string', description: 'instance 的 id' },
                componentKey: { type: 'string', description: '组件集的 componentKey 或 guid' },
                variantKey:   { type: 'string', description: '变体的 variantKey 或 guid；standalone 组件填与 componentKey 相同的值' },
                reason:       { type: 'string', description: '一句话匹配理由' },
              },
              required: ['id', 'componentKey', 'variantKey'],
            },
          },
        },
        required: ['results'],
      },
    }],
    tool_choice: { type: 'tool', name: 'select_variants' },
    messages: [{
      role: 'user',
      content: [
        `为以下每个 instance 从候选组件的变体列表中选出最匹配的一个变体。`,
        ``,
        sections,
      ].join('\n'),
    }],
  });

  const toolUse = response.content.find(b => b.type === 'tool_use');
  if (!toolUse) return [];

  return toolUse.input.results.map(r => {
    const entry   = allEntries.find(e => e.componentKey === r.componentKey || e.guid === r.componentKey);
    const variant = entry?.variants?.find(v => v.variantKey === r.variantKey || v.guid === r.variantKey);

    return {
      id:               r.id,
      componentSetName: entry?.name        || '',
      source:           entry?.source      || '',
      sourceLabel:      entry?.sourceLabel || '',
      componentKey:     r.componentKey,
      hexFile:          entry?.hexFile     || '',
      variant: variant ? {
        name:       variant.name,
        variantKey: variant.variantKey || variant.guid,
        guid:       variant.guid,
      } : null,
      reason: r.reason || '',
    };
  });
}

// ── 主入口 ────────────────────────────────────────────────────────────────────

/**
 * @param {{ pageDescription?: string, instances: {id: string, hint: string}[] }} input
 * @param {string} [indexPath]
 * @returns {Promise<{ pageDescription: string, results: object[] }>}
 */
async function matchPage(input, indexPath = INDEX) {
  const index = JSON.parse(fs.readFileSync(indexPath, 'utf8'));
  const { pageDescription = '', instances } = input;

  console.error(`[stage1] 粗筛 ${instances.length} 个 instance...`);
  const candidateMatches = await stage1BatchCandidates(instances, index, pageDescription);

  console.error(`[stage2] 精选变体...`);
  const results = await stage2BatchVariants(instances, candidateMatches, index);

  return { pageDescription, results };
}

// ── CLI ───────────────────────────────────────────────────────────────────────

if (require.main === module) {
  let input;
  if (process.argv[2]) {
    input = JSON.parse(fs.readFileSync(path.resolve(process.argv[2]), 'utf8'));
  } else {
    input = JSON.parse(fs.readFileSync('/dev/stdin', 'utf8'));
  }

  matchPage(input)
    .then(result => console.log(JSON.stringify(result, null, 2)))
    .catch(err => { console.error(err.message); process.exit(1); });
}

module.exports = { matchPage };
