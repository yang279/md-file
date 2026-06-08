# component-service 接口文档

整合自两个来源的服务：
- **查询接口**（`/match`、`/batch`、`/match-dsl`）—— 移植自 `pixso-parse/pix-split/enrich`，基于 LLM 的语义化组件变体匹配
- **hex 获取接口**（`/hex/:key`）—— 沿用 `nodejs/component-query` 的逻辑，改造为跨多组件库查找

合并后对外统一暴露在 **3100 端口**，供 [dsl-to-hex](../dsl-to-hex/) 等下游服务使用。

---

## 启动

```bash
cd nodejs/component-service

# 默认配置（需要 search_index.json 与 lib-out 目录已就绪）
node server.js

# 自定义端口 / 组件库根目录
PORT=3100 LIB_OUT_DIR=/path/to/lib-out node server.js
```

启动时会读取 `search_index.json` 构建 hex key → 文件路径的映射，并打印加载到的 key 数量。

**环境变量：**

| 变量 | 默认值 | 说明 |
|---|---|---|
| `PORT` | `3100` | 监听端口 |
| `LIB_OUT_DIR` | `../../pixso-parse/pix-split/lib-out` | 多组件库根目录，`search_index.json` 中每条 entry 的 `hexFile` 相对此目录下的 `{source}/` 解析 |
| `DASHSCOPE_API_KEY` | 见 `.env` | LLM（DeepSeek）调用密钥，`/match`、`/batch`、`/match-dsl` 依赖 |
| `MODEL` | `deepseek-v4-flash` | LLM 模型名，可在 `.env` 中改为 `deepseek-v4-pro` |

> `.env` 文件已随服务一并复制，包含 `DASHSCOPE_API_KEY`，本地启动无需额外配置。

---

## 数据来源说明

`search_index.json`（移植自 enrich，653 条 entry）汇聚了三个组件库的索引：

| source | sourceLabel | entry 数 | hex 文件命名格式 |
|---|---|---|---|
| `ict-ui` | ICT UI 组件库 | 491 | 40 位小写 SHA1（如 `be1d28168c521684a3d888b60f9e8a645653b4b7.txt`） |
| `h-design-chart` | H Design 图表库 | 161 | `{sessionId}_{localId}`（如 `93_55829.txt`） |
| `h-design-light` | H Design 浅色样式库 | 1 | `{sessionId}_{localId}`（如 `1_7379.txt`） |

每条 entry 的 `hexFile` 字段是相对 `lib-out/{source}/` 的路径，例如 `h-design-chart` 的 `93:55829` 对应文件实际位于：

```
{LIB_OUT_DIR}/h-design-chart/component/93_55829.txt
```

服务启动时遍历所有 entry，以 `hexFile` 文件名（去掉扩展名）为 key 建立 `key → 绝对路径` 映射（实测 653 条 entry 无 key 冲突），从而让 `/hex/:key` 无需调用方关心组件来自哪个库。

---

## 接口列表

### GET /health

健康检查。

**响应 200：**
```json
{ "status": "ok", "hex_keys": 653 }
```

`hex_keys` 为已加载的 hex key 映射条数。

---

### POST /match

单条组件变体语义匹配（LLM 驱动）。

**请求体：**

| 字段 | 类型 | 必填 | 说明 |
|---|---|---|---|
| `description` | string | 是 | 组件描述，支持自然语言或结构化描述 |

```json
{ "description": "主按钮大号" }
```

**响应 200：**

```json
{
  "source": "ict-ui",
  "sourceLabel": "ICT UI 组件库",
  "componentSetName": "1.按钮",
  "componentKey": "9a9da828027b6bdc773731bb333817c0799c208d",
  "hexFile": "component/9a9da828027b6bdc773731bb333817c0799c208d.txt",
  "variant": {
    "name": "status=primary, Interaction=default, size=large, disabled=false",
    "variantKey": "7f599a2db9d8ac901cf4c858825d1e04221d3021",
    "guid": "4280:102987"
  },
  "reason": "该变体为 status=primary（主按钮）、size=large（大号），且为默认交互状态，与“主按钮大号”完全匹配。"
}
```

**响应 400：** `{ "error": "description is required" }`

**响应 404：** `{ "error": "no match found" }`

> 实测单条匹配耗时约 5~6 秒（内部 2 次 LLM 调用：语义提取 + 精选）。

---

### POST /batch

批量组件变体匹配，最多 100 条，内部 5 并发执行。

**请求体（两种格式均可）：**

```json
{ "descriptions": ["主按钮大号", "折线图缩放轴默认状态"] }
```
```json
["主按钮大号", "折线图缩放轴默认状态"]
```

**响应 200：** 按输入顺序返回结果数组，单条失败时该项为 `{ error, description }`。

**响应 400：**
```json
{ "error": "body must be an array or { descriptions: [] }" }
{ "error": "descriptions array is empty" }
{ "error": "max 100 descriptions per request" }
```

---

### POST /match-dsl

输入一棵 node-dsl 节点树，自动提取所有可匹配节点（`button` / `input` / `navbar` / `tabbar` / `switch` / `badge` / `avatar`），用各节点 `label` 批量匹配组件变体。

**请求方式（二选一）：**

```bash
# multipart 文件上传
curl -X POST http://localhost:3100/match-dsl -F "file=@page.json"

# JSON body
curl -X POST http://localhost:3100/match-dsl -H "Content-Type: application/json" -d '{ ... }'
```

**响应 200：** 按深度优先顺序返回匹配结果数组（仅含参与匹配的节点）：

```json
[
  {
    "nid": 20,
    "semantic": "button",
    "label": "主登录按钮",
    "match": {
      "sourceLabel": "ICT UI 组件库",
      "componentSetName": "1.按钮",
      "componentKey": "...",
      "hexFile": "component/xxx.txt",
      "variant": { "name": "...", "variantKey": "..." },
      "reason": "..."
    }
  }
]
```

**响应 400：**
```json
{ "error": "uploaded file is not valid JSON" }
{ "error": "send a file via -F \"file=@page.json\" or a JSON body" }
```

> 实测对最小节点树（仅 `container` 根节点，无可匹配子节点）返回 `[]`。

---

### GET /hex/:key

跨组件库查找并返回指定 key 对应的 hex 文件内容（供 dsl-to-hex 等服务调用）。

**路径参数：** `key` —
- 40 位小写 hex 字符串（旧版 SHA1 componentKey，如 `ict-ui` 库）
- 或 `{sessionId}_{localId}` 格式（新版 guid 派生，如 `h-design-chart`、`h-design-light` 库）

**响应 200：** `Content-Type: text/plain`，hex 文件原始内容（已实测三个来源库的 key 均可正确解析定位）

**响应 404 — key 格式合法但未收录或文件缺失：**
```json
{ "error": "component not found: 0000000000000000000000000000000000000000" }
```

**响应 400 — key 格式不合法：**
```json
{ "error": "key must be a 40-char lowercase hex string or {sessionId}_{localId}" }
```

---

## 与原服务的差异说明

| | 原 component-query | 本服务 |
|---|---|---|
| 组件查询 | 字符串模糊匹配（`POST /query`，已停用） | LLM 语义匹配（`/match`、`/batch`、`/match-dsl`） |
| hex 获取范围 | 单一 `COMPONENT_DIR`（仅 ict-ui） | 跨 `ict-ui` / `h-design-chart` / `h-design-light` 三库统一查找 |
| hex 定位方式 | `path.join(COMPONENT_DIR, key + '.txt')` 直接拼路径 | 启动时基于 `search_index.json` 构建 `key → 绝对路径` 映射 |

---

## 调用示例

```bash
# 1. 语义匹配，拿到 variant.guid / componentKey
curl -s -X POST http://localhost:3100/match \
  -H "Content-Type: application/json" \
  -d '{ "description": "主按钮大号" }'

# 2. 用匹配结果中的 componentKey（或 hexFile 文件名）取 hex 内容
curl -s http://localhost:3100/hex/9a9da828027b6bdc773731bb333817c0799c208d
```
