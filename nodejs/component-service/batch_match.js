#!/usr/bin/env node
'use strict';

const fs               = require('fs');
const path             = require('path');
const { matchVariant } = require('./match_variant');

const envFile = path.resolve(__dirname, '.env');
if (fs.existsSync(envFile)) {
  fs.readFileSync(envFile, 'utf8').split('\n').forEach(line => {
    const trimmed = line.trim();
    if (!trimmed || trimmed.startsWith('#')) return;
    const [k, v] = trimmed.split('=');
    if (k && v && !process.env[k.trim()]) process.env[k.trim()] = v.trim();
  });
}

// concurrency 控制：同时最多 N 个 LLM 请求在飞
async function matchVariants(descriptions, concurrency = 5) {
  const results = new Array(descriptions.length).fill(null);
  const queue   = descriptions.map((desc, i) => ({ desc, i }));

  async function worker() {
    while (queue.length > 0) {
      const { desc, i } = queue.shift();
      try {
        results[i] = await matchVariant(desc);
      } catch (err) {
        console.error(`[batch_match] 第 ${i} 条「${desc}」失败：${err.message}`);
        results[i] = { error: err.message, description: desc };
      }
    }
  }

  await Promise.all(Array.from({ length: Math.min(concurrency, descriptions.length) }, worker));
  return results;
}

// CLI：
//   单条：node batch_match.js "描述文字"
//   批量 JSON 数组：node batch_match.js '[{"description":"xxx"},{"description":"yyy"}]'
//   批量字符串数组：node batch_match.js '["xxx","yyy"]'
//   stdin：echo '[...]' | node batch_match.js
if (require.main === module) {
  let input;
  if (process.argv[2]) {
    try {
      input = JSON.parse(process.argv[2]);
    } catch {
      // 非 JSON，当作单条描述字符串
      input = process.argv[2];
    }
  } else {
    input = JSON.parse(fs.readFileSync('/dev/stdin', 'utf8'));
  }

  const descriptions = Array.isArray(input)
    ? input.map(x => (typeof x === 'string' ? x : x.description))
    : [typeof input === 'string' ? input : input.description];

  matchVariants(descriptions)
    .then(r => console.log(JSON.stringify(r, null, 2)))
    .catch(err => { console.error(err.message); process.exit(1); });
}

module.exports = { matchVariants };
