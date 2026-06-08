# Node.js 服务接口文档

两个服务均使用纯 HTTP JSON 接口，无外部依赖。

---

## 向量索引（可选，提升语义搜索精度）

组件查询服务支持可选的向量语义搜索。未构建索引时自动降级为字符串匹配，功能不受影响。

**构建步骤（首次使用或组件库更新后执行一次）：**

```bash
cd nodejs/component-query

# 方案 A：Ollama（本地，免费）
# 前提：已安装 Ollama 并拉取模型
ollama pull nomic-embed-text
node build-embeddings.js

# 方案 B：OpenAI
OPENAI_API_KEY=sk-xxx node build-embeddings.js
```

输出文件：`{COMPONENT_DIR}/embeddings.json`（约 20~80MB，取决于变体数量）

**相关环境变量：**

| 变量 | 默认值 | 说明 |
|---|---|---|
| `OLLAMA_URL` | `http://localhost:11434` | Ollama 服务地址 |
| `OPENAI_API_KEY` | 未设置 | 设置后自动切换到 OpenAI API |
| `EMBEDDING_MODEL` | `nomic-embed-text` / `text-embedding-3-small` | 嵌入模型名称 |

> 脚本支持断点续传：中断后重新运行会跳过已完成的条目。

---

## 服务一：组件查询服务（component-query）

**默认端口：** `3100`

**启动：**
```bash
cd nodejs/component-query
# 标准目录布局下无需设置环境变量
PORT=3100 node server.js

# 自定义路径
PORT=3100 COMPONENT_DIR=/path/to/harmony_out/component node server.js
```

**环境变量：**

| 变量 | 默认值 | 说明 |
|---|---|---|
| `PORT` | `3100` | 监听端口 |
| `COMPONENT_DIR` | `../../pixso-parse/pix-split/lib-out/ict-ui/component` | 组件 hex 文件目录（含 `component_index.json`） |
| `INDEX_PATH` | `{COMPONENT_DIR}/component_index.json` | 索引文件路径（通常不需要单独设置） |
| `OLLAMA_URL` | `http://localhost:11434` | 查询时 embed 调用的 Ollama 地址（仅向量模式） |
| `OPENAI_API_KEY` | 未设置 | 设置后查询时 embed 改用 OpenAI |
| `EMBEDDING_MODEL` | 同构建脚本默认值 | 查询时使用的嵌入模型，需与构建时一致 |

---

### GET /health

健康检查。

**响应 200：**
```json
{
  "status": "ok",
  "component_sets": 319,
  "standalone_components": 172,
  "embeddings_loaded": true
}
```

`embeddings_loaded: true` 表示向量索引已加载，查询将使用语义搜索；`false` 时降级为字符串匹配。

---

### POST /query（当前已停用）

> **注意：** 该接口当前在 [server.js](component-query/server.js) 中已被注释掉，请求会返回 `404 { "error": "not found" }`。服务暂时只提供 `/health` 与 `/hex/:key`。以下为接口启用时的行为说明，供恢复时参考。

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
| `name` | string | 是 | 组件名称，支持中文/英文/混合，模糊匹配 |
| `props` | object | 否 | 变体属性过滤，键值对，大小写不敏感 |

**`name` 匹配规则：**

索引中组件名格式为 `.Button`、`.Title` 等（带前导点）。匹配时：
1. 去掉前导 `.`，小写化
2. 精确匹配 → 100 分
3. 包含匹配 → 60 分
4. 按空格/斜杠分词，每个 token 命中 → 10 分

返回评分最高的一个 componentSet。

**`props` 匹配规则：**

变体 name 格式为 `"类型=文本,状态=正常"` 或 `"status=default, size=normal"`，解析后与 props 逐字段比对（大小写不敏感），命中数即为 score。`matched_variants` 按 score 降序排列。

**响应 200（找到）：**

```json
{
  "found": true,
  "component_set": {
    "name": "文字链接",
    "component_set_key": "",
    "hex_key": "8229_277383",
    "canvas_name": "1.基础类"
  },
  "default_variant": {
    "name": "status=independent, Interaction=default, size=normal, disabled=false",
    "symbol_id": "8229:277395",
    "variant_key": "8229:277395",
    "component_set_key": "",
    "hex_key": "8229_277383",
    "score": 0
  },
  "matched_variants": [ ... ]
}
```

**响应 200（未找到）：**

```json
{ "found": false }
```

**响应字段说明：**

| 字段 | 说明 |
|---|---|
| `found` | 是否找到匹配的组件集 |
| `component_set.hex_key` | hex 文件键名，用于 `GET /hex/:key` 获取组件内容 |
| `component_set.component_set_key` | 旧版库为 40 位 SHA1；新版库为空字符串，改用 `hex_key` |
| `default_variant.symbol_id` | 变体 GUID（`sessionId:localId`），写入设计DSL 的 `instance.symbol_id` |
| `default_variant.variant_key` | 旧版为 SHA1，新版等于 `symbol_id` |
| `default_variant.hex_key` | 继承自组件集，指向同一个 hex 文件 |
| `variant.score` | props 命中数；无 props 时均为 0 |

**standalone 组件（无变体）：** `variant_key == symbol_id`，`name` 为组件名称本身。

**响应 400：**
```json
{ "error": "name (string) is required" }
```

---

### GET /hex/:key

返回指定 componentKey 对应的 hex 文件内容（供 dsl-to-hex 服务调用）。

**路径参数：** `key` — 40 位小写 hex 字符串（旧版 SHA1 componentKey），或 `{sessionId}_{localId}` 格式（新版，如 `8229_277383`）

**响应 200：** `Content-Type: text/plain`，hex 文件原始内容

**响应 404：**
```json
{ "error": "component not found: abc123..." }
```

**响应 400（key 格式错误）：**
```json
{ "error": "key must be a 40-char lowercase hex string" }
```

---

## 服务二：DSL转hex服务（dsl-to-hex）

**默认端口：** `3101`

**启动：**
```bash
cd nodejs/dsl-to-hex
# component-query 必须已启动
PORT=3101 COMPONENT_QUERY_URL=http://localhost:3100 node server.js
```

**环境变量：**

| 变量 | 默认值 | 说明 |
|---|---|---|
| `PORT` | `3101` | 监听端口 |
| `COMPONENT_QUERY_URL` | `http://localhost:3100` | 组件查询服务地址 |
| `WASM_PATH` | `./bin/dsl_to_hex.js` | WASM 加载器路径（`.js` 文件，`.wasm` 必须在同目录） |

**启动顺序：** 先启动 `component-query`，再启动 `dsl-to-hex`（后者启动时会预热 WASM，不依赖 component-query，但 `/convert` 请求需要 component-query 在线）。

---

### GET /health

**响应 200：**
```json
{ "status": "ok" }
```

---

### POST /convert

接收设计DSL JSON，输出包含 hex 文件及 placeholder 资源文件的 zip 压缩包（base64 编码）。详见 [dsl-to-hex/API.md](dsl-to-hex/API.md)。

**请求头：** `Content-Type: application/json`

**请求体：**

```json
{
  "dsl": {
    "meta": { ... },
    "pages": [ ... ]
  }
}
```

| 字段 | 类型 | 必填 | 说明 |
|---|---|---|---|
| `dsl` | object | 是 | 符合 `设计dsl.md` 规范的设计DSL JSON 对象 |

**响应 200（转换成功）：**

```json
{
  "zip": "<base64 编码的 zip 包，解压后含 output.hex 及 svg/png 资源文件>"
}
```

**响应 200（转换成功，但有组件缺失）：**

```json
{
  "zip": "<base64 编码的 zip 包>",
  "missing_keys": [
    "ecb8481025909ec9371c3b25104bb8b7c1079224"
  ]
}
```

`missing_keys` 存在时，zip 仍有效（WASM 跳过缺失组件继续生成），但对应 instance 节点将缺失。

**响应 500（转换失败）：**

```json
{ "error": "buildMsg failed" }
```

**响应 400：**

```json
{ "error": "dsl (object) is required" }
{ "error": "dsl.pages must be an array" }
{ "error": "invalid JSON body" }
```

---

## 完整调用流程示例

> `/query` 当前已停用（见上文说明），下面流程 1 仅作为接口恢复后的参考；当前实际可用流程为 2、3。

### 1. 查询 Button 文本变体（接口当前停用）

```bash
curl -X POST http://localhost:3100/query \
  -H "Content-Type: application/json" \
  -d '{
    "name": "Button",
    "props": { "类型": "文本" }
  }'
```

取响应中 `default_variant` 的 `symbol_id`、`variant_key`、`component_set_key`，填入设计DSL 的 `instance` 字段。

### 2. 转换设计DSL为zip

```bash
curl -X POST http://localhost:3101/convert \
  -H "Content-Type: application/json" \
  -d '{
    "dsl": { "meta": { ... }, "pages": [ ... ] }
  }' \
  | jq -r '.zip' | base64 -d > output.zip

unzip output.zip   # 得到 output.hex 及各 placeholder 资源文件（svg/png）
```

`output.hex` 即为可导入 Pixso 的文件内容，写入 `.txt` 扩展名即可导入。详见 [dsl-to-hex/API.md](dsl-to-hex/API.md)。

### 3. 获取组件hex（通常由 dsl-to-hex 内部调用）

```bash
curl http://localhost:3100/hex/ecb8481025909ec9371c3b25104bb8b7c1079224
```
