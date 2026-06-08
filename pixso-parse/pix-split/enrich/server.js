#!/usr/bin/env node
'use strict';

const express           = require('express');
const multer            = require('multer');
const { matchVariant }  = require('./match_variant');
const { matchVariants } = require('./batch_match');
const { matchDsl }      = require('./match_dsl');

const app    = express();
const PORT   = process.env.PORT || 3102;
const upload = multer({ storage: multer.memoryStorage() });

app.use(express.json());

// ── GET /health ───────────────────────────────────────────────────────────────

app.get('/health', (req, res) => {
  res.json({ status: 'ok' });
});

// ── POST /match ───────────────────────────────────────────────────────────────

app.post('/match', async (req, res) => {
  const { description } = req.body || {};
  if (!description || typeof description !== 'string') {
    return res.status(400).json({ error: 'description is required' });
  }
  try {
    const result = await matchVariant(description.trim());
    if (!result) return res.status(404).json({ error: 'no match found' });
    res.json(result);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// ── POST /batch ───────────────────────────────────────────────────────────────

app.post('/batch', async (req, res) => {
  const body = req.body;
  let descriptions;

  if (Array.isArray(body)) {
    descriptions = body.map(x => (typeof x === 'string' ? x : x.description));
  } else if (Array.isArray(body?.descriptions)) {
    descriptions = body.descriptions;
  } else {
    return res.status(400).json({ error: 'body must be an array or { descriptions: [] }' });
  }

  if (descriptions.length === 0) {
    return res.status(400).json({ error: 'descriptions array is empty' });
  }
  if (descriptions.length > 100) {
    return res.status(400).json({ error: 'max 100 descriptions per request' });
  }

  try {
    const results = await matchVariants(descriptions.map(d => d?.trim?.() ?? d));
    res.json(results);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// ── POST /match-dsl ───────────────────────────────────────────────────────────
// 支持两种方式：
//   1. multipart 文件上传：-F "file=@page.json"
//   2. JSON body：-H "Content-Type: application/json" -d '{...}'

app.post('/match-dsl', upload.single('file'), async (req, res) => {
  let nodeData;

  if (req.file) {
    // 文件上传方式
    try {
      nodeData = JSON.parse(req.file.buffer.toString('utf8'));
    } catch {
      return res.status(400).json({ error: 'uploaded file is not valid JSON' });
    }
  } else if (req.body && typeof req.body === 'object' && Object.keys(req.body).length > 0) {
    // JSON body 方式（保持兼容）
    nodeData = req.body;
  } else {
    return res.status(400).json({ error: 'send a file via -F "file=@page.json" or a JSON body' });
  }

  try {
    const results = await matchDsl(nodeData);
    res.json(results);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

app.listen(PORT, () => {
  console.log(`component-match server running on http://localhost:${PORT}`);
});
