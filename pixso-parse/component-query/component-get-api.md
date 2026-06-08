# component-query 接口文档

**默认端口：** `3100`

## 启动

```bash
cd nodejs/component-query
node server.js
```

## 环境变量

| 变量 | 默认值 | 说明 |
|---|---|---|
| `PORT` | `3100` | 监听端口 |
| `COMPONENT_DIR` | `../../pixso-parse/pix-split/lib-out/ict-ui/component` | 组件 hex 文件目录（含 `component_index.json`） |
| `INDEX_PATH` | `{COMPONENT_DIR}/component_index.json` | 索引文件路径 |
| `OLLAMA_URL` | `http://localhost:11434` | 向量模式下 embed 调用地址 |
| `OPENAI_API_KEY` | 未设置 | 设置后 embed 改用 OpenAI API |
| `EMBEDDING_MODEL` | `nomic-embed-text` / `text-embedding-3-small` | 嵌入模型，需与构建时一致 |

---

## GET /health

健康检查。

**响应 200：**
```json
{
  "status": "ok",
  "component_sets": 319,
  "standalone_components": 172,
  "embeddings_loaded": false
}
```

`embeddings_loaded: true` 表示向量索引已加载，`/query` 将使用语义搜索；`false` 时降级为字符串匹配。

---

## GET /hex/:key

返回指定组件的 hex 文件原始内容，供 dsl-to-hex 服务调用。

**路径参数：**

| 参数 | 格式 | 示例 |
|---|---|---|
| `key` | 40 位小写 hex（旧版 SHA1 componentKey） | `ecb8481025909ec9371c3b25104bb8b7c1079224` |
| `key` | `{sessionId}_{localId}`（新版，来自 guid） | `8229_277383` |

`key` 值来源于 `/query` 响应中的 `component_set.hex_key` 或 `default_variant.hex_key`。

**响应 200：** `Content-Type: text/plain`，hex 文件原始内容（流式返回）

**响应 404：**
```json
{ "error": "component not found: 8229_277383" }
```

**响应 400（key 格式不合法）：**
```json
{ "error": "key must be a 40-char lowercase hex string" }
```

```bash
curl http://localhost:3100/hex/8229_277383
curl http://localhost:3100/hex/ecb8481025909ec9371c3b25104bb8b7c1079224
```

---

## POST /query

> **当前状态：暂时停用**（server.js 中已注释，逻辑保留在 searcher.js）

根据组件名称和变体属性查询变体数据。

**请求头：** `Content-Type: application/json`

**请求体：**

```json
{
  "name": "Button",
  "props": {
    "类型": "文本",
    "状态": "正常"
  }
}
```

| 字段 | 类型 | 必填 | 说明 |
|---|---|---|---|
| `name` | string | 是 | 组件名称，支持中文/英文，模糊匹配 |
| `props` | object | 否 | 变体属性过滤，键值对，大小写不敏感 |

### name 匹配规则

索引中组件名格式为 `文字链接`、`.Button` 等。匹配时去掉前导数字+点与前导点，小写化后：

1. 精确匹配 → 100 分
2. 包含匹配 → 60 分
3. 按空格/斜杠分词，每个 token 命中 → 10 分
4. 中文最长公共子串（≥2字符） → `len × 5` 分

返回评分最高的一个 componentSet 或 standaloneComponent。

向量索引可用时（`embeddings_loaded: true`），且 `props` 为空时优先使用语义向量召回，再按字符串 props 精排。

### props 匹配规则

变体 name 格式为 `"类型=文本,状态=正常"` 或 `"status=default, size=normal"`，解析后与 props 逐字段比对（大小写不敏感），命中数即为 score。`matched_variants` 按 score 降序排列。

### 响应 200（找到）

```json
{
  "found": true,
  "component_set": {
    "name": "文字链接",
    "component_set_key": "be1d28168c521684a3d888b60f9e8a645653b4b7",
    "hex_key": "8229_277383",
    "canvas_name": "1.基础类"
  },
  "default_variant": {
    "name": "status=independent, Interaction=default, size=normal, disabled=false",
    "symbol_id": "8229:277395",
    "variant_key": "8229:277395",
    "component_set_key": "be1d28168c521684a3d888b60f9e8a645653b4b7",
    "hex_key": "8229_277383",
    "score": 0
  },
  "matched_variants": [
    {
      "name": "status=independent, Interaction=default, size=normal, disabled=false",
      "symbol_id": "8229:277395",
      "variant_key": "8229:277395",
      "component_set_key": "be1d28168c521684a3d888b60f9e8a645653b4b7",
      "hex_key": "8229_277383",
      "score": 0
    }
  ]
}
```

### 响应字段说明

| 字段 | 说明 |
|---|---|
| `component_set.hex_key` | 传给 `GET /hex/:key` 获取组件内容 |
| `component_set.component_set_key` | 旧版库为 40 位 SHA1；新版库为空字符串，改用 `hex_key` |
| `default_variant.symbol_id` | 变体 GUID（`sessionId:localId`），写入设计 DSL 的 `instance.symbol_id` |
| `default_variant.variant_key` | 旧版为 SHA1，新版等于 `symbol_id` |
| `variant.score` | props 命中数；无 props 时均为 0 |

**standalone 组件（无变体）：** `variant_key == symbol_id`，`name` 为组件名称本身。

### 响应 200（未找到）

```json
{ "found": false }
```

### 响应 400

```json
{ "error": "name (string) is required" }
```

---

## 向量索引（可选）

未构建时自动降级为字符串匹配，功能不受影响。

```bash
cd nodejs/component-query

# Ollama（本地，免费）
ollama pull nomic-embed-text
node build-embeddings.js

# OpenAI
OPENAI_API_KEY=sk-xxx node build-embeddings.js
```

输出文件：`{COMPONENT_DIR}/embeddings.json`（约 20~80MB）。脚本支持断点续传。
