# component-service 接口文档

整合自两个来源的服务：
- **查询接口**（`/match`、`/batch`、`/match-dsl`）—— 移植自 `pixso-parse/pix-split/enrich`，基于 LLM 的语义化组件变体匹配
- **hex 获取接口**（`/hex/:key`）—— 沿用 `nodejs/component-query` 的逻辑，改造为跨多组件库查找

合并后对外统一暴露在 **3102 端口**，供 [dsl-to-hex](../dsl-to-hex/) 等下游服务使用。

---

## 启动

```bash
cd nodejs/component-service

# 默认配置（需要 search_index.json 与 lib-out 目录已就绪）
node server.js

# 自定义端口 / 组件库根目录
PORT=3102 LIB_OUT_DIR=/path/to/lib-out node server.js
```

启动时会读取 `search_index.json` 构建 hex key → 文件路径的映射，并打印加载到的 key 数量。

**环境变量：**

| 变量 | 默认值 | 说明 |
|---|---|---|
| `PORT` | `3102` | 监听端口 |
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

`/match`、`/batch`、`/match-dsl` 的匹配结果中额外带有拼好的 `path` 字段（`= source + '/' + hexFile`，如上例对应 `"h-design-chart/component/93_55829.txt"`），是相对 `LIB_OUT_DIR` 的完整路径。生成设计 DSL 时把它原样写进 instance 的 `path` 字段即可——`dsl-to-hex` 服务会用自己配置的 `HEX_LIB_DIR`（应指向同一份 `lib-out` 数据）拼接这个 `path` 直接读本地文件，不再调用本服务的 `/hex/:key` 接口。

---

## 新增组件库：从「拆解」到「接入服务」全流程

当有一个新的 `.pix` 组件库被拆解出来后，它**不会自动**出现在 `component-service` 里——还需要手动走完"合并索引 → 同步到本服务"这几步。完整链路如下：

```
①拆解 .pix              ②登记到 SOURCES         ③重新生成索引            ④同步到 component-service
pix-split/split_compset  pix-split/enrich/        merge_index.js           复制 search_index.json
   → lib-out/{source}/   merge_index.js              ↓                      （及 lib-out 数据，若路径不同）
                              SOURCES.push(...)    build_index.js              ↓
                                                      ↓                     重启服务，验证 hex_keys 增量
                                                  search_index.json
```

### 第 ① 步：拆解组件库，产出 `component/` 目录

有两种等价方式，二选一：

**方式 A — CLI（直接产出到 `lib-out/`，推荐用于本机批量处理）**

使用 `pixso-parse/pix-split/` 下的 `split_compset` 工具（详见 [pix-split/README.md](../../pixso-parse/pix-split/README.md)）：

```bash
cd pixso-parse/pix-split
./bin/split_compset build_index \
  "<新组件库>.pix" \
  lib-out/<新库目录名> \
  --publish-file <publish-id>
```

**方式 B — `POST /split` 接口（适合远程/无 shell 访问场景，本服务自带）**

`component-service` 内置了基于同一套 WASM（`split_compset_wasm.cpp` 编译产物）的拆解接口，详见下方[「POST /split」](#post-split)。它接收上传的 `.pix` 文件，拆解后把 `component/` 目录打包成 zip 返回——拿到 zip 后解压到 `lib-out/<新库目录名>/` 即可，效果与方式 A 完全一致：

```bash
curl -s -X POST http://localhost:3102/split -F "file=@<新组件库>.pix" -F "publishFile=<publish-id>" \
  | jq -r '.zip' | base64 -d > output.zip

unzip output.zip -d pixso-parse/pix-split/lib-out/<新库目录名>
```

两种方式产出的目录结构应为：

```
lib-out/<新库目录名>/
└── component/
    ├── component_index.json   # 必须：记录该库所有组件集/独立组件及其 hexFile 路径
    ├── {componentKey 或 sessionId_localId}.txt
    └── ...
```

> **目录名（即 `source` key）建议直接用新库名的 kebab-case**，因为这个名字会贯穿后续所有步骤——它既是 `lib-out/` 下的子目录名，也是 `merge_index.js` 里 `SOURCES` 的 `key`，还是 `search_index.json` 里每条 entry 的 `source` 字段。三者必须保持完全一致，否则 `component-service` 启动时拼出来的路径会找不到文件。

> ⚠️ **当前已存在但尚未接入的真实例子**：`lib-out/h-design-dark/` 目录已经拆解完成（含 `component_index.json`），但**尚未**出现在 `merge_index.js` 的 `SOURCES` 列表里，因此目前查不到、也匹配不到这个库里的组件——这正是本节要解决的"半成品"状态。

### 第 ② 步：登记到 `merge_index.js` 的 `SOURCES`

编辑 `pixso-parse/pix-split/enrich/merge_index.js`：

```js
const SOURCES = [
  { key: 'h-design-light', label: 'H Design 浅色样式库' },
  { key: 'h-design-chart', label: 'H Design 图表库'     },
  { key: 'ict-ui',         label: 'ICT UI 组件库'        },
  { key: 'h-design-dark',  label: 'H Design 深色样式库'  },   // ← 新增一行
];
```

- `key`：必须与 `lib-out/` 下的子目录名**完全一致**（决定运行时路径拼接是否正确）
- `label`：展示用的中文名，会出现在 `/match` 等接口返回结果的 `sourceLabel` 字段里

### 第 ③ 步：重新生成 `search_index.json`

```bash
cd pixso-parse/pix-split/enrich
node merge_index.js   # 重新读取 lib-out/{每个 source}/component/component_index.json → 写 merged.json
node build_index.js   # 基于 merged.json 生成最终的 search_index.json（含 searchText 检索字段）
```

执行完后留意终端输出的 entry 数量是否符合预期增量（新库贡献了多少个 componentSets / standaloneComponents）。

### 第 ④ 步：同步到 `component-service`

`component-service` 里的 `search_index.json` 是**独立复制**的一份（不是软链接，也不会自动跟 `enrich/` 同步），需要手动覆盖：

```bash
cp pixso-parse/pix-split/enrich/search_index.json nodejs/component-service/search_index.json
```

另外要确认 `component-service` 的 `LIB_OUT_DIR` 能访问到新库的 hex 文件：
- **本地/同机部署**：默认 `LIB_OUT_DIR` 指向 `pixso-parse/pix-split/lib-out`（与 `enrich` 共用同一份数据），新库目录已经在第①步落到这里了，无需额外操作
- **跨机器部署**（参见 [MIGRATION.md](../MIGRATION.md)）：需要把新增的 `lib-out/{新库目录名}/` 一并同步到目标机器上 `LIB_OUT_DIR` 指向的路径下

### 第 ⑤ 步：重启并验证

```bash
cd nodejs/component-service
node server.js
```

```bash
# 1. 确认 hex_keys 总数比接入前增加了（增量应等于新库贡献的 entry 数）
curl -s http://localhost:3102/health

# 2. 抽取新库 component_index.json 里的某个 hexFile，验证能查到
curl -s http://localhost:3102/hex/<新库里的某个key>

# 3. 用新库特有的组件描述跑一次语义匹配，确认能命中且 source/sourceLabel 正确
curl -s -X POST http://localhost:3102/match -H "Content-Type: application/json" \
  -d '{ "description": "<新库中某组件的典型描述>" }'
```

### 排错提示

| 现象 | 原因 |
|---|---|
| `/health` 的 `hex_keys` 没有增加 | `search_index.json` 没有重新生成或没有同步覆盖到 `component-service/` |
| `/hex/:key` 对新库的 key 返回 404 | `merge_index.js` 里 `SOURCES` 的 `key` 与 `lib-out/` 下实际目录名不一致，导致拼出的路径错误；或新库数据未落到 `LIB_OUT_DIR` 指向的目录下 |
| `/match` 匹配结果里出现新库但 `sourceLabel` 显示异常/缺失 | `SOURCES` 里 `label` 字段写错或漏写 |
| `key 冲突` / 同一个 key 映射到了错误的文件 | 极小概率事件（新库与已有库的 hex 文件名恰好相同），需要检查 `hexPathMap` 构建逻辑（[server.js:29-37](server.js#L29-L37)）按何种顺序覆盖，必要时改用 `source:key` 复合 key |

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
  "path": "ict-ui/component/9a9da828027b6bdc773731bb333817c0799c208d.txt",
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
curl -X POST http://localhost:3102/match-dsl -F "file=@page.json"

# JSON body
curl -X POST http://localhost:3102/match-dsl -H "Content-Type: application/json" -d '{ ... }'
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
      "path": "ict-ui/component/xxx.txt",
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

### POST /split

上传 `.pix` 组件库文件，调用 `split_compset` WASM（编译自 [pix-split/split_compset_wasm.cpp](../../pixso-parse/pix-split/split_compset_wasm.cpp)，与 CLI `split_compset build_index` 同源同逻辑）拆解为 `{componentKey 或 sessionId_localId}.txt` + `component_index.json`，打包为 zip 返回。

这是「[新增组件库全流程](#新增组件库从拆解到接入服务全流程)」的第①步——**拆解只是第一步，产物要真正可被 `/match`、`/hex` 用到，还需要继续走完登记 SOURCES → 重新生成索引 → 同步 → 重启验证**。

**请求方式：** `multipart/form-data`

| 字段 | 类型 | 必填 | 说明 |
|---|---|---|---|
| `file` | file | 是 | `.pix` 组件库文件 |
| `publishFile` | string | 否 | 缺少 `componentKey` 时用于补写发布信息（同 CLI `--publish-file`），生成规则：`componentKey = SHA1(publishFile + sessionID:localID)` |

```bash
curl -X POST http://localhost:3102/split \
  -F "file=@library.pix" \
  -F "publishFile=QcO-1WDViGmGQ4IFU_p4FQ"
```

**响应 200：**

```json
{
  "stats": {
    "total": 1,
    "componentSets": 1,
    "standaloneComponents": 0,
    "compDir": "component",
    "indexFile": "component/component_index.json"
  },
  "zip": "UEsDBAoAAAAAAMh..."
}
```

`stats` 字段含义同 CLI `build_index` 的输出：`total` 为写出的文件总数，`componentSets`/`standaloneComponents` 分别是组件集与独立组件数量；`compDir`/`indexFile` 是相对 zip 根目录的路径（始终是 `component` / `component/component_index.json`）。

**zip 包结构**（解压后即可整体放进 `lib-out/{新库目录名}/`）：

```
component/
├── component_index.json
├── {componentKey 或 sessionId_localId}.txt
└── ...
```

**响应 400 — 未上传文件：**
```json
{ "error": "send a .pix file via -F \"file=@library.pix\"" }
```

**响应 500 — 拆解失败**（文件不是合法 `.pix`、解析失败、或没有可拆出的组件集）：
```json
{ "error": "parse failed: library.pix" }
{ "error": "no component sets found" }
```

> 实测验证：上传一个含 1 个组件集（2 个变体）的真实 `.pix` 文件，返回 `{"total":1,"componentSets":1,"standaloneComponents":0,...}`，解压 zip 得到 `component/component_index.json` + `component/2_105.txt`，内容与 CLI 拆解结果一致；上传非 `.pix` 文件返回 `{"error":"parse failed: <原始文件名>"}`（已对临时路径做了脱敏，不会泄露服务器目录结构）。

> ⚠️ 上传体积限制 200MB（`.pix` 库文件可能较大）；接口本身只做"拆解 + 打包返回"，**不会**自动写入 `lib-out/`、不会更新 `search_index.json`，避免未经检查就覆盖现有数据。

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
| 组件库拆解 | 无 | `POST /split` —— 上传 `.pix` 直接拆解打包返回，免去手动跑 CLI |

---

## 调用示例

```bash
# 1. 语义匹配，拿到 variant.guid / componentKey
curl -s -X POST http://localhost:3102/match \
  -H "Content-Type: application/json" \
  -d '{ "description": "主按钮大号" }'

# 2. 用匹配结果中的 componentKey（或 hexFile 文件名）取 hex 内容
curl -s http://localhost:3102/hex/9a9da828027b6bdc773731bb333817c0799c208d
```
