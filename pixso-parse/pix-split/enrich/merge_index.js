#!/usr/bin/env node
'use strict';

const fs   = require('fs');
const path = require('path');

const SOURCES = [
  { key: 'h-design-light', label: 'H Design 浅色样式库' },
  { key: 'h-design-chart', label: 'H Design 图表库'     },
  { key: 'ict-ui',         label: 'ICT UI 组件库'        },
];

const BASE = path.resolve(__dirname, '../lib-out');
const OUT  = path.resolve(__dirname, 'merged.json');

const merged = { componentSets: [], standaloneComponents: [] };

for (const { key, label } of SOURCES) {
  const indexPath = path.join(BASE, key, 'component', 'component_index.json');
  if (!fs.existsSync(indexPath)) {
    console.warn(`skip: ${indexPath} not found`);
    continue;
  }
  const data = JSON.parse(fs.readFileSync(indexPath, 'utf8'));

  for (const cs of data.componentSets || []) {
    merged.componentSets.push({ ...cs, source: key, sourceLabel: label });
  }
  for (const sc of data.standaloneComponents || []) {
    merged.standaloneComponents.push({ ...sc, source: key, sourceLabel: label });
  }
}

fs.writeFileSync(OUT, JSON.stringify(merged, null, 2), 'utf8');

console.log(`merged.json written`);
console.log(`  componentSets:        ${merged.componentSets.length}`);
console.log(`  standaloneComponents: ${merged.standaloneComponents.length}`);
