# 服务迁移说明：dsl-to-hex + component-service

本文档说明将 `nodejs/dsl-to-hex` 与 `nodejs/component-service` 迁移到其他服务器时，需要带走哪些文件、安装什么依赖、配置哪些环境变量。

两者是**调用关系**：`dsl-to-hex` 在转换时通过 HTTP 调用 `component-service` 的 `GET /hex/:key` 拉取组件 hex 数据，因此推荐**整体一起迁移**；如果只迁移其中一个，另一个必须仍可通过网络访问到。

---

## 一、component-service（端口 3100）

### 1.1 需要迁移的文件

整个目录 `nodejs/component-service/`：

| 文件/目录 | 说明 | 大小 |
|---|---|---|
| `server.js` | 服务入口（合并了 LLM 查询接口与 hex 获取接口） | — |
| `match_variant.js` / `batch_match.js` / `match_dsl.js` | LLM 匹配逻辑模块 | — |
| `search_index.json` | 组件检索索引（653 条 entry，含 `source`/`hexFile` 映射） | ~2.5MB |
| `package.json` | 依赖声明（`express`、`multer`、`openai`） | — |
| `.env` | 含 `DASHSCOPE_API_KEY`，**敏感信息，注意传输与存储安全** | — |
| `node_modules/` | 可随目录一起拷贝，或在目标机器上 `npm install` 重新安装 | ~24MB |

> 不需要带走 `API.md`（纯文档）。

### 1.2 ⚠️ 必须额外迁移的外部数据：lib-out 组件库

**这是最容易遗漏的一项。** `search_index.json` 里每条 entry 的 `hexFile` 是相对路径，实际 hex 文件存放在仓库里的：

```
pixso-parse/pix-split/lib-out/{source}/{hexFile}
```

`/hex/:key` 接口运行时依赖这些目录是否存在。当前 `search_index.json` 引用了 3 个库：

| source 目录 | 说明 | 大小 |
|---|---|---|
| `lib-out/ict-ui/` | ICT UI 组件库（491 个组件，hex 用 SHA1 命名） | ~79MB |
| `lib-out/h-design-chart/` | H Design 图表库（161 个组件，hex 用 `{sessionId}_{localId}` 命名） | ~70MB |
| `lib-out/h-design-light/` | H Design 浅色样式库（1 个组件） | 16KB |

合计约 **150MB**。迁移时把这三个目录（含其 `component/*.txt` 与 `component_index.json`）一并拷贝到目标机器，并通过 `LIB_OUT_DIR` 环境变量指向其父目录（即包含这三个子目录的 `lib-out` 路径）。

> `lib-out/h-design-dark/` 未被 `search_index.json` 引用，可以不迁移。

### 1.3 运行环境

- **Node.js**：本机验证版本 `v24.15.0`，理论上任意现代 LTS（≥ 18）均可
- **npm 依赖**：`express ^5.2.1`、`multer ^2.1.1`、`openai ^6.42.0`
  ```bash
  cd component-service && npm install
  ```
- **网络出站**：需要能访问 `https://api.deepseek.com`（`/match`、`/batch`、`/match-dsl` 依赖 LLM 调用）

### 1.4 环境变量

| 变量 | 默认值 | 必须修改？ | 说明 |
|---|---|---|---|
| `PORT` | `3100` | 按需 | 监听端口 |
| `LIB_OUT_DIR` | `../../pixso-parse/pix-split/lib-out`（相对 `__dirname` 解析） | **是** | 迁移后原相对路径大概率失效，需指向新机器上 lib-out 的实际绝对路径 |
| `DASHSCOPE_API_KEY` | 取自 `.env` | 否（已含在 `.env` 中） | LLM 调用密钥 |
| `MODEL` | `deepseek-v4-flash` | 否 | 可在 `.env` 中改为 `deepseek-v4-pro` |

**启动示例：**

```bash
cd component-service
PORT=3100 LIB_OUT_DIR=/srv/data/lib-out node server.js
```

### 1.5 验证

```bash
curl http://localhost:3100/health
# 期望: {"status":"ok","hex_keys":653}
# 若 hex_keys 不是 653，说明 search_index.json 与 lib-out 版本不匹配

curl http://localhost:3100/hex/93_55829           # h-design-chart 的 key，验证跨库查找
curl http://localhost:3100/hex/<ict-ui的某个SHA1key>  # ict-ui 的 key

curl -X POST http://localhost:3100/match \
  -H "Content-Type: application/json" \
  -d '{"description":"主按钮大号"}'               # 验证 LLM 查询链路（含外网访问）
```

---

## 二、dsl-to-hex（端口 3101）

### 2.1 需要迁移的文件

整个目录 `nodejs/dsl-to-hex/`：

| 文件/目录 | 说明 |
|---|---|
| `server.js` | HTTP 服务入口 |
| `converter.js` | 核心转换逻辑（提取组件 key、拉取 hex、调用 WASM、打包 zip） |
| `package.json` | 无外部 npm 依赖 |
| `bin/dsl_to_hex.js` + `bin/dsl_to_hex.wasm` | **WASM 转换核心，必须两个文件成对存在、放在同一目录** |

> `dsl2hex-api.md`、`test-data/` 为文档与测试数据，非运行必需，可选择性带走。

### 2.2 运行环境

- **Node.js**：理论上 ≥ 14（用到了 WASM、`fs`、`child_process` 等内置模块），本机用 `v24.15.0` 验证
- **无 npm 依赖**（`package.json` 中 `dependencies` 为空）
- **系统命令 `zip`**：⚠️ **新增依赖**——打包 hex 与 placeholder 资源时通过 `child_process.spawnSync('zip', ...)` 调用系统 zip 命令。
  - macOS / 大多数 Linux 发行版自带；Debian/Ubuntu 精简镜像可能需要 `apt-get install zip`
  - 验证：`which zip`，找不到则需先安装，否则 `/convert` 会在打包阶段抛错 `zip 打包失败: ...`

### 2.3 环境变量

| 变量 | 默认值 | 必须修改？ | 说明 |
|---|---|---|---|
| `PORT` | `3101` | 按需 | 监听端口 |
| `COMPONENT_QUERY_URL` | `http://localhost:3100` | **是（如果 component-service 不在同机或同端口）** | 指向 component-service 的可访问地址 |
| `WASM_PATH` | `./bin/dsl_to_hex.js` | 否 | 通常无需改动，保持 `.js`/`.wasm` 同目录即可 |

**启动示例：**

```bash
cd dsl-to-hex
PORT=3101 COMPONENT_QUERY_URL=http://<component-service-host>:3100 node server.js
```

### 2.4 验证

```bash
curl http://localhost:3101/health
# 期望: {"status":"ok"}，且启动日志里 "WASM 加载成功"

curl -X POST http://localhost:3101/convert \
  -H "Content-Type: application/json" \
  -d '{ "dsl": { "meta": {...}, "pages": [...] } }'
# 期望返回 { "zip": "<base64>" }，且无 missing_keys（若有则说明
# component-service 侧 lib-out 数据不全或网络不通）
```

---

## 三、迁移检查清单

```
□ component-service/ 整个目录（含 .env，注意密钥安全传输）
□ component-service/node_modules/（或目标机器执行 npm install）
□ pixso-parse/pix-split/lib-out/ict-ui/           （~79MB）
□ pixso-parse/pix-split/lib-out/h-design-chart/   （~70MB）
□ pixso-parse/pix-split/lib-out/h-design-light/   （16KB）
□ dsl-to-hex/ 整个目录（含 bin/ 下的 .js + .wasm 必须成对）
□ 目标机器已安装 Node.js（≥ 18 推荐）
□ 目标机器已安装系统 zip 命令（dsl-to-hex 打包依赖）
□ 目标机器可访问 https://api.deepseek.com（component-service LLM 调用）
□ 设置 LIB_OUT_DIR 指向新机器上 lib-out 的绝对路径
□ 设置 COMPONENT_QUERY_URL 让 dsl-to-hex 能访问到 component-service
□ 启动后依次跑通 /health → /hex/:key → /match → /convert 全链路验证
```

---

## 四、常见问题排查

| 现象 | 可能原因 |
|---|---|
| `component-service` 启动后 `/health` 返回 `hex_keys` 不等于 653 | `search_index.json` 与拷贝过去的 `lib-out` 版本不一致 |
| `/hex/:key` 返回 404 `component not found` | `LIB_OUT_DIR` 路径配置错误，或对应 source 子目录未拷贝完整 |
| `/match` 等接口超时或报错 | 目标机器无法访问 `api.deepseek.com`，或 `DASHSCOPE_API_KEY` 失效 |
| `/convert` 返回 500 `zip 打包失败` | 目标机器缺少系统 `zip` 命令 |
| `/convert` 返回结果带 `missing_keys` | dsl-to-hex 无法从 `COMPONENT_QUERY_URL` 拉到对应 hex，检查网络连通性与 component-service 的 `lib-out` 数据完整性 |
| `WASM 加载失败` 导致 dsl-to-hex 启动即退出 | `bin/dsl_to_hex.js` 与 `bin/dsl_to_hex.wasm` 未放在同一目录，或 `WASM_PATH` 配置错误 |
