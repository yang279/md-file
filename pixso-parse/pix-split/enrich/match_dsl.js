#!/usr/bin/env node
'use strict';

const { matchVariants } = require('./batch_match');

// 参与匹配的 semantic 类型
const MATCHABLE = new Set(['button', 'input', 'navbar', 'tabbar', 'switch', 'badge', 'avatar']);

// semantic → 中文提示，拼入 query 帮助本地过滤和 LLM 理解
const SEMANTIC_HINT = {
  button: '按钮',
  input:  '输入框',
  navbar: '导航栏',
  tabbar: '标签栏',
  switch: '开关',
  badge:  '角标',
  avatar: '头像',
};

// 递归收集所有需要匹配的节点
function collectNodes(nodeOrArray, result = []) {
  if (Array.isArray(nodeOrArray)) {
    nodeOrArray.forEach(n => collectNodes(n, result));
    return result;
  }
  const node = nodeOrArray;
  if (!node || typeof node !== 'object') return result;

  if (MATCHABLE.has(node.semantic)) {
    result.push({ nid: node.nid, semantic: node.semantic, label: node.label });
  }
  if (Array.isArray(node.children)) {
    node.children.forEach(child => collectNodes(child, result));
  }
  return result;
}

// 把 label + semantic hint 拼成更精准的查询词
function buildQuery(label, semantic) {
  const hint = SEMANTIC_HINT[semantic] || '';
  // 如果 label 里已经包含 hint，就不重复添加
  if (hint && !label.includes(hint)) {
    return `${label} ${hint}`;
  }
  return label;
}

async function matchDsl(nodeOrArray) {
  const nodes = collectNodes(nodeOrArray);
  if (nodes.length === 0) return [];

  const queries = nodes.map(n => buildQuery(n.label, n.semantic));
  const matches = await matchVariants(queries);

  return nodes.map((n, i) => ({
    nid:      n.nid,
    semantic: n.semantic,
    label:    n.label,
    match:    matches[i] || null,
  }));
}

// CLI：node match_dsl.js < node.json
if (require.main === module) {
  const input = JSON.parse(require('fs').readFileSync('/dev/stdin', 'utf8'));
  matchDsl(input)
    .then(r => console.log(JSON.stringify(r, null, 2)))
    .catch(err => { console.error(err.message); process.exit(1); });
}

module.exports = { matchDsl };
