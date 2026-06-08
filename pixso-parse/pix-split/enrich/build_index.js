#!/usr/bin/env node
'use strict';

const fs   = require('fs');
const path = require('path');

const MERGED = path.resolve(__dirname, 'merged.json');
const OUT    = path.resolve(__dirname, 'search_index.json');

const merged = JSON.parse(fs.readFileSync(MERGED, 'utf8'));

function buildSearchText(entry) {
  const parts = [entry.name, entry.sourceLabel || ''];
  for (const v of entry.variants || []) {
    parts.push(v.name);
    // "缩放轴=折线图,状态=默认" → 拆出 "缩放轴" "折线图" "状态" "默认"
    parts.push(...v.name.split(/[=,]/));
  }
  return parts.join(' ');
}

const entries = [
  ...merged.componentSets.map(e => ({ ...e, _type: 'set' })),
  ...merged.standaloneComponents.map(e => ({ ...e, _type: 'standalone' })),
].map(e => ({ ...e, searchText: buildSearchText(e) }));

fs.writeFileSync(OUT, JSON.stringify({ entries }, null, 2), 'utf8');
console.log(`search_index.json written: ${entries.length} entries`);
