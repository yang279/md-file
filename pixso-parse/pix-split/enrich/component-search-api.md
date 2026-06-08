# Component Match API

组件变体匹配服务，支持单条查找和批量查找。

## 目录

- [启动](#启动)
- [接口列表](#接口列表)
  - [GET /health](#get-health)
  - [POST /match](#post-match)
  - [POST /batch](#post-batch)
  - [POST /match-dsl](#post-match-dsl)
- [工作流程](#工作流程)

---

## 启动

```bash
# 首次使用需先构建搜索索引
node build_index.js

# 启动服务（默认端口 3000）
npm start

# 指定端口
PORT=3100 npm start
```

---

## 接口列表

### GET /health

健康检查。

**响应**

```json
{ "status": "ok" }
```

---

### POST /match

单条组件变体匹配。

**请求体**

| 字段 | 类型 | 必填 | 说明 |
|------|------|------|------|
| description | string | 是 | 组件描述，支持自然语言或结构化描述 |

```json
{ "description": "主按钮大号" }
```

**响应 200**

| 字段 | 类型 | 说明 |
|------|------|------|
| source | string | 组件库标识（如 `ict-ui`、`h-design-chart`） |
| sourceLabel | string | 组件库名称（如 `ICT UI 组件库`） |
| componentSetName | string | 组件集名称 |
| componentKey | string | 组件集 key |
| hexFile | string | 对应的 hex 文件路径 |
| variant | object | 匹配到的变体 |
| variant.name | string | 变体名称（如 `status=primary, size=large`） |
| variant.variantKey | string | 变体 key |
| variant.guid | string | 变体 GUID |
| reason | string | 匹配理由 |

```json
{
  "source": "ict-ui",
  "sourceLabel": "ICT UI 组件库",
  "componentSetName": "1.按钮",
  "componentKey": "4280:103404",
  "hexFile": "component/4280_103404.txt",
  "variant": {
    "name": "status=primary, Interaction=default, size=large, disabled=false",
    "variantKey": "4280:102987",
    "guid": "4280:102987"
  },
  "reason": "status=primary 对应主按钮，size=large 对应大号"
}
```

**响应 400** — description 缺失或非字符串

```json
{ "error": "description is required" }
```

**响应 404** — 未找到匹配结果

```json
{ "error": "no match found" }
```

---

### POST /batch

批量组件变体匹配，最多 100 条，内部 5 并发执行。

**请求体（两种格式均支持）**

格式 1 — 对象形式：
```json
{
  "descriptions": ["主按钮大号", "折线图缩放轴默认状态", "输入框禁用状态"]
}
```

格式 2 — 数组形式：
```json
["主按钮大号", "折线图缩放轴默认状态", "输入框禁用状态"]
```

**响应 200**

按输入顺序返回结果数组，单条匹配失败时该项为 `null` 或包含 `error` 字段。

```json
[
  {
    "source": "ict-ui",
    "sourceLabel": "ICT UI 组件库",
    "componentSetName": "1.按钮",
    "componentKey": "4280:103404",
    "hexFile": "component/4280_103404.txt",
    "variant": {
      "name": "status=primary, Interaction=default, size=large, disabled=false",
      "variantKey": "4280:102987",
      "guid": "4280:102987"
    },
    "reason": "status=primary 对应主按钮，size=large 对应大号"
  },
  {
    "source": "h-design-chart",
    "sourceLabel": "H Design 图表库",
    "componentSetName": "_缩放轴",
    "componentKey": "93:55829",
    "hexFile": "component/93_55829.txt",
    "variant": {
      "name": "缩放轴=折线图,状态=默认",
      "variantKey": "720:69249",
      "guid": "720:69249"
    },
    "reason": "完全匹配折线图缩放轴的默认状态"
  }
]
```

**响应 400** — 格式错误或超过 100 条

```json
{ "error": "max 100 descriptions per request" }
```

---

### POST /match-dsl

输入一棵 node-dsl 节点树（JSON 文件上传），自动提取所有可匹配节点（`button` / `input` / `navbar` / `tabbar` / `switch` / `badge` / `avatar`），用各节点的 `label` 批量查找对应组件变体。

**不参与匹配的 semantic 类型**：`icon` / `text` / `heading` / `divider` / `container` / `card` / `list` / `list-item` / `image` / `modal`

**请求方式**

multipart 文件上传，字段名为 `file`：

```bash
curl -X POST http://localhost:3102/match-dsl \
  -F "file=@your-page.json"
```

也兼容 JSON body（`Content-Type: application/json`）。

**文件内容**

node-dsl JSON，支持单个 Node 对象或 Node 数组：

```json
{
  "nid": 3,
  "tag": "div",
  "semantic": "container",
  "label": "登录页根容器",
  "confidence": "high",
  "rect": { "x": 0, "y": 0, "w": 375, "h": 812 },
  "style": {},
  "children": [
    {
      "nid": 4,
      "tag": "header",
      "semantic": "navbar",
      "label": "顶部导航栏",
      "confidence": "high",
      "rect": { "x": 0, "y": 0, "w": 375, "h": 56 },
      "style": {}
    },
    {
      "nid": 20,
      "tag": "button",
      "semantic": "button",
      "label": "主登录按钮",
      "confidence": "high",
      "rect": { "x": 20, "y": 260, "w": 335, "h": 48 },
      "style": {}
    }
  ]
}
```

**响应 200**

按节点在树中的出现顺序（深度优先）返回匹配结果数组，仅包含参与匹配的节点：

| 字段 | 类型 | 说明 |
|------|------|------|
| nid | number | 节点 ID |
| semantic | string | 节点语义类型 |
| label | string | 节点描述 |
| match | object \| null | 匹配到的组件变体，匹配失败时为 `null` |
| match.sourceLabel | string | 组件库名称 |
| match.componentSetName | string | 组件集名称 |
| match.componentKey | string | 组件集 key |
| match.hexFile | string | hex 文件路径 |
| match.variant | object | 匹配变体 |
| match.variant.name | string | 变体名称 |
| match.variant.variantKey | string | 变体 key |
| match.reason | string | 匹配理由 |

```json
[
  {
    "nid": 4,
    "semantic": "navbar",
    "label": "顶部导航栏",
    "match": {
      "sourceLabel": "ICT UI 组件库",
      "componentSetName": "导航栏",
      "componentKey": "...",
      "hexFile": "component/xxx.txt",
      "variant": {
        "name": "type=default",
        "variantKey": "..."
      },
      "reason": "顶部导航栏与导航栏组件完全对应"
    }
  },
  {
    "nid": 20,
    "semantic": "button",
    "label": "主登录按钮",
    "match": {
      "sourceLabel": "ICT UI 组件库",
      "componentSetName": "1.按钮",
      "componentKey": "4280:103404",
      "hexFile": "component/4280_103404.txt",
      "variant": {
        "name": "status=primary, Interaction=default, size=large, disabled=false",
        "variantKey": "4280:102987"
      },
      "reason": "主登录按钮对应 primary 状态的大号按钮"
    }
  }
]
```

**响应 400** — 请求体格式错误

```json
{ "error": "body must be a node-dsl Node or Node[]" }
```

---

## 工作流程

```
用户输入（支持中文、英文、自然语言、结构化描述）
  ↓
【第一步】LLM 语义提取（~2s）
  将输入转换为中文搜索关键词
  "button"        → "按钮"
  "primary large" → "主要 大号"
  "禁用的文本框"   → "输入框 禁用"
  ↓
【第二步】本地关键词过滤（瞬间，无费用）
  用关键词在 653 个组件里打分 → Top 10 候选
  ↓
【第三步】LLM 精选（~3s）
  从 Top 10 候选的变体列表中选出最匹配的一个
  ↓
返回结果
```

**耗时说明**

| 场景 | 耗时 |
|------|------|
| 单条查询 | 约 5~8 秒（2 次 LLM 调用） |
| 批量 N 条 | 约 5~8 秒（最多 5 并发，N ≤ 5 时与单条相同） |

**模型**：`deepseek-v4-flash`（默认），可通过 `.env` 中 `MODEL=deepseek-v4-pro` 切换
