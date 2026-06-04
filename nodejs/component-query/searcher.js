'use strict';

const fs   = require('fs');
const path = require('path');

// ---------------------------------------------------------------------------
// 名称归一化：去掉前导 '.'，小写，trim
// ---------------------------------------------------------------------------
function normalizeName(name) {
  return name.replace(/^\.+/, '').toLowerCase().trim();
}

// ---------------------------------------------------------------------------
// 对 query 字符串评分 normalized componentSet name
//   100 → 精确匹配
//    60 → 包含匹配
//    N  → token 匹配（每个 token 10 分，至少 1 分）
// ---------------------------------------------------------------------------
function scoreSetName(normalized, query) {
  const q = normalizeName(query);
  if (!q) return 0;
  if (normalized === q) return 100;
  if (normalized.includes(q)) return 60;
  // 按空格 / 斜杠分词后逐 token 匹配
  const tokens = q.split(/[\s\/]+/).filter(Boolean);
  if (tokens.length === 0) return 0;
  let hits = 0;
  for (const t of tokens) {
    if (normalized.includes(t)) hits++;
  }
  return hits > 0 ? hits * 10 : 0;
}

// ---------------------------------------------------------------------------
// 解析变体 name 字符串 "类型=文本,状态=正常,尺寸=大" → Map
// ---------------------------------------------------------------------------
function parseVariantName(name) {
  const map = {};
  for (const part of name.split(',')) {
    const eq = part.indexOf('=');
    if (eq > 0) {
      const k = part.slice(0, eq).trim();
      const v = part.slice(eq + 1).trim();
      map[k] = v;
    }
  }
  return map;
}

// ---------------------------------------------------------------------------
// 计算变体与 props query 的命中分（命中 key-value 对的数量）
// ---------------------------------------------------------------------------
function scoreVariant(variantName, props) {
  if (!props || Object.keys(props).length === 0) return 0;
  const map = parseVariantName(variantName);
  let score = 0;
  for (const [k, v] of Object.entries(props)) {
    if (map[k] !== undefined && map[k].toLowerCase() === String(v).toLowerCase()) {
      score++;
    }
  }
  return score;
}

// ---------------------------------------------------------------------------
// 格式化变体，统一输出结构
// ---------------------------------------------------------------------------
function formatVariant(v, componentSetKey, score) {
  return {
    name:              v.name,
    symbol_id:         v.guid,
    variant_key:       v.variantKey,
    component_set_key: componentSetKey,
    score,
  };
}

// ---------------------------------------------------------------------------
// ComponentSearcher
// ---------------------------------------------------------------------------
class ComponentSearcher {
  constructor(indexPath) {
    if (!fs.existsSync(indexPath)) {
      throw new Error(`component_index.json not found: ${indexPath}`);
    }
    const raw = JSON.parse(fs.readFileSync(indexPath, 'utf8'));

    // 预处理：带上归一化名称方便搜索
    this._sets = (raw.componentSets || []).map(cs => ({
      ...cs,
      _norm: normalizeName(cs.name),
    }));
    this._standalones = (raw.standaloneComponents || []).map(sc => ({
      ...sc,
      _norm: normalizeName(sc.name),
    }));

    this._totalSets      = this._sets.length;
    this._totalStandalone = this._standalones.length;
  }

  get stats() {
    return {
      component_sets:        this._totalSets,
      standalone_components: this._totalStandalone,
    };
  }

  // -------------------------------------------------------------------------
  // 主查询入口
  // -------------------------------------------------------------------------
  query({ name, props }) {
    if (!name || !name.trim()) {
      return { found: false, error: 'name is required' };
    }

    // 1. 在 componentSets 和 standaloneComponents 里找最佳匹配
    const match = this._findBestSet(name.trim());
    if (!match) return { found: false };

    // 2. 整理变体列表
    const variants = this._buildVariants(match, props || {});

    return {
      found: true,
      component_set: {
        name:              match.name,
        component_set_key: match.componentKey,
        canvas_name:       match.canvasName || '',
      },
      default_variant:    variants[0] || null,
      matched_variants:   variants,
    };
  }

  // -------------------------------------------------------------------------
  // 找评分最高的一个 componentSet / standalone
  // -------------------------------------------------------------------------
  _findBestSet(nameQuery) {
    let best = null;
    let bestScore = 0;

    for (const cs of this._sets) {
      const s = scoreSetName(cs._norm, nameQuery);
      if (s > bestScore) { bestScore = s; best = cs; }
    }
    for (const sc of this._standalones) {
      const s = scoreSetName(sc._norm, nameQuery);
      if (s > bestScore) { bestScore = s; best = sc; }
    }

    return bestScore > 0 ? best : null;
  }

  // -------------------------------------------------------------------------
  // 构建变体列表（含 props 评分排序）
  // -------------------------------------------------------------------------
  _buildVariants(match, props) {
    // standalone：无 variants 数组，自身即唯一"变体"
    if (!match.variants || match.variants.length === 0) {
      return [{
        name:              match.name,
        symbol_id:         match.guid,
        variant_key:       match.componentKey,
        component_set_key: match.componentKey,
        score:             0,
      }];
    }

    const hasProps = Object.keys(props).length > 0;

    const scored = match.variants.map(v => ({
      ...formatVariant(v, match.componentKey, scoreVariant(v.name, props)),
    }));

    if (hasProps) {
      // props 模式：按 score 降序，score=0 的排后面但仍返回
      scored.sort((a, b) => b.score - a.score);
    }
    // 无 props 模式：保持 index 原始顺序（第一个为默认变体）

    return scored;
  }
}

module.exports = ComponentSearcher;
