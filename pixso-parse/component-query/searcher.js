'use strict';

const fs   = require('fs');
const path = require('path');
const http  = require('http');
const https = require('https');

// ---------------------------------------------------------------------------
// 从 hexFile 字段提取 hex_key
//   "component/8229_277383.txt"  → "8229_277383"
//   "component/ecb8481025...txt" → "ecb8481025..."
// ---------------------------------------------------------------------------
function hexKeyFromFile(hexFile) {
  return path.basename(hexFile, '.txt');
}

// ---------------------------------------------------------------------------
// 名称归一化：去掉前导数字+点（"2.拖拽把手"→"拖拽把手"）、前导 '.'，小写，trim
// ---------------------------------------------------------------------------
function normalizeName(name) {
  return name.replace(/^\d+\./, '').replace(/^\.+/, '').toLowerCase().trim();
}

// ---------------------------------------------------------------------------
// componentSet name 评分
// ---------------------------------------------------------------------------
function scoreSetName(normalized, query) {
  const q = normalizeName(query);
  if (!q) return 0;
  if (normalized === q) return 100;
  if (normalized.includes(q)) return 60;
  const tokens = q.split(/[\s\/]+/).filter(Boolean);
  let hits = 0;
  for (const t of tokens) if (normalized.includes(t)) hits++;
  if (hits > 0) return hits * 10;

  // 中文无空格分词：找最长公共子串（≥2字符）作为模糊兜底
  let maxLen = 0;
  for (let len = q.length - 1; len >= 2; len--) {
    for (let i = 0; i <= q.length - len; i++) {
      if (normalized.includes(q.slice(i, i + len))) {
        if (len > maxLen) maxLen = len;
        break;
      }
    }
    if (maxLen >= len) break;
  }
  return maxLen >= 2 ? maxLen * 5 : 0;
}

// ---------------------------------------------------------------------------
// 解析变体 name 字符串为 map
//   "status=independent, size=normal" → { status: "independent", size: "normal" }
//   "类型=文本,状态=正常"              → { 类型: "文本", 状态: "正常" }
// ---------------------------------------------------------------------------
function parseVariantName(name) {
  const map = {};
  for (const part of name.split(/,\s*/)) {
    const eq = part.indexOf('=');
    if (eq > 0) {
      map[part.slice(0, eq).trim()] = part.slice(eq + 1).trim();
    }
  }
  return map;
}

// ---------------------------------------------------------------------------
// 变体与 props query 的命中分
// ---------------------------------------------------------------------------
function scoreVariant(variantName, props) {
  if (!props || Object.keys(props).length === 0) return 0;
  const map = parseVariantName(variantName);
  let score = 0;
  for (const [k, v] of Object.entries(props)) {
    if (map[k] !== undefined && map[k].toLowerCase() === String(v).toLowerCase()) score++;
  }
  return score;
}

// ---------------------------------------------------------------------------
// Cosine 相似度（Float32Array / 普通数组均可）
// ---------------------------------------------------------------------------
function cosineSim(a, b) {
  let dot = 0, na = 0, nb = 0;
  for (let i = 0; i < a.length; i++) {
    dot += a[i] * b[i];
    na  += a[i] * a[i];
    nb  += b[i] * b[i];
  }
  const denom = Math.sqrt(na) * Math.sqrt(nb);
  return denom === 0 ? 0 : dot / denom;
}

// ---------------------------------------------------------------------------
// HTTP GET（用于 embedding API 调用）
// ---------------------------------------------------------------------------
function httpPost(url, body) {
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
        ...(process.env.OPENAI_API_KEY
          ? { 'Authorization': `Bearer ${process.env.OPENAI_API_KEY}` }
          : {}),
      },
    };
    const req = mod.request(opts, res => {
      const chunks = [];
      res.on('data', c => chunks.push(c));
      res.on('end', () => {
        if (res.statusCode !== 200) {
          return reject(new Error(`embedding API ${res.statusCode}: ${Buffer.concat(chunks).toString()}`));
        }
        resolve(JSON.parse(Buffer.concat(chunks).toString()));
      });
    });
    req.on('error', reject);
    req.end(data);
  });
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

    this._sets = (raw.componentSets || []).map(cs => ({
      ...cs,
      _norm:    normalizeName(cs.name),
      _hexKey:  hexKeyFromFile(cs.hexFile),
    }));
    this._standalones = (raw.standaloneComponents || []).map(sc => ({
      ...sc,
      _norm:   normalizeName(sc.name),
      _hexKey: hexKeyFromFile(sc.hexFile),
    }));

    // 加载向量索引（可选）
    const embPath = path.join(path.dirname(indexPath), 'embeddings.json');
    this._embeddings = null;
    if (fs.existsSync(embPath)) {
      try {
        const emb = JSON.parse(fs.readFileSync(embPath, 'utf8'));
        // 把 vec 转成 Float32Array 加速计算
        this._embeddings = {};
        for (const [id, entry] of Object.entries(emb.entries || emb)) {
          this._embeddings[id] = {
            ...entry,
            vec: new Float32Array(entry.vec),
          };
        }
        this._embModel = emb.meta?.model || 'unknown';
        console.log(`向量索引加载成功: ${Object.keys(this._embeddings).length} 条 (${this._embModel})`);
      } catch (e) {
        console.warn(`向量索引加载失败，降级为字符串匹配: ${e.message}`);
      }
    }
  }

  get stats() {
    return {
      component_sets:        this._sets.length,
      standalone_components: this._standalones.length,
      embeddings_loaded:     this._embeddings !== null,
    };
  }

  // -------------------------------------------------------------------------
  // 主查询入口（async，向量可用时优先使用）
  // -------------------------------------------------------------------------
  async query({ name, props }) {
    if (!name || !name.trim()) return { found: false, error: 'name is required' };

    // 有向量索引 且 无精确 props 过滤时：向量召回 + 字符串 props 精排
    if (this._embeddings && (!props || Object.keys(props).length === 0)) {
      const candidates = await this._vectorRecall(name.trim(), 10);
      if (candidates.length > 0) return this._buildResult(candidates[0].match, props || {});
    }

    // 降级：字符串匹配
    const match = this._findBestSet(name.trim());
    if (!match) return { found: false };
    return this._buildResult(match, props || {});
  }

  // -------------------------------------------------------------------------
  // 向量召回：embed query → cosine 排名 → 返回 top-K 对应的 componentSet
  // -------------------------------------------------------------------------
  async _vectorRecall(query, topK) {
    let queryVec;
    try {
      queryVec = await this._embed(query);
    } catch (e) {
      console.warn(`embed 调用失败，降级字符串匹配: ${e.message}`);
      return [];
    }

    // 计算所有条目的相似度
    const scored = Object.entries(this._embeddings).map(([id, entry]) => ({
      id,
      hexKey: entry.hex_key,
      score:  cosineSim(queryVec, entry.vec),
    })).sort((a, b) => b.score - a.score).slice(0, topK);

    // 通过 hex_key 反查 componentSet
    return scored.map(s => {
      const match = this._sets.find(cs => cs._hexKey === s.hexKey)
                 || this._standalones.find(sc => sc._hexKey === s.hexKey);
      return match ? { match, score: s.score } : null;
    }).filter(Boolean);
  }

  // -------------------------------------------------------------------------
  // 调用 Embedding API
  //   默认：Ollama  http://localhost:11434/api/embeddings
  //   可选：OpenAI  https://api.openai.com/v1/embeddings（设 OPENAI_API_KEY）
  // -------------------------------------------------------------------------
  async _embed(text) {
    if (process.env.OPENAI_API_KEY) {
      const url   = 'https://api.openai.com/v1/embeddings';
      const model = process.env.EMBEDDING_MODEL || 'text-embedding-3-small';
      const res   = await httpPost(url, { model, input: text });
      return res.data[0].embedding;
    }

    // Ollama
    const url   = (process.env.OLLAMA_URL || 'http://localhost:11434') + '/api/embeddings';
    const model = process.env.EMBEDDING_MODEL || 'nomic-embed-text';
    const res   = await httpPost(url, { model, prompt: text });
    return res.embedding;
  }

  // -------------------------------------------------------------------------
  // 字符串评分：找最佳 componentSet
  // -------------------------------------------------------------------------
  _findBestSet(nameQuery) {
    let best = null, bestScore = 0;
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
  // 构建统一响应
  // -------------------------------------------------------------------------
  _buildResult(match, props) {
    const variants = this._buildVariants(match, props);
    return {
      found: true,
      component_set: {
        name:              match.name,
        component_set_key: match.componentKey || '',
        hex_key:           match._hexKey,
        canvas_name:       match.canvasName || '',
      },
      default_variant:  variants[0] || null,
      matched_variants: variants,
    };
  }

  // -------------------------------------------------------------------------
  // 构建变体列表
  // -------------------------------------------------------------------------
  _buildVariants(match, props) {
    const hasProps = Object.keys(props).length > 0;

    if (!match.variants || match.variants.length === 0) {
      return [{
        name:              match.name,
        symbol_id:         match.guid,
        variant_key:       match.componentKey || match.guid,
        component_set_key: match.componentKey || '',
        hex_key:           match._hexKey,
        score:             0,
      }];
    }

    const scored = match.variants.map(v => ({
      name:              v.name,
      symbol_id:         v.guid,
      variant_key:       v.variantKey || v.guid,
      component_set_key: match.componentKey || '',
      hex_key:           match._hexKey,
      score:             scoreVariant(v.name, props),
    }));

    if (hasProps) scored.sort((a, b) => b.score - a.score);
    return scored;
  }
}

module.exports = ComponentSearcher;
