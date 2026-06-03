# md-skill 工作区说明

## 整体目标

把 Pixso 组件库 `.pix` 文件拆解成可复用的 hex 片段，再通过设计稿 DSL（JSON）将这些组件拼装成完整的 Pixso 文件（hex），最终可导入 Pixso 渲染。

---

## 数据流

```
HarmonyOS 组件库.pix
        │
        ▼
   pix-split          ← 拆解组件库，每个组件集输出一个 hex 文件
        │
        ▼
harmony_out/component/
  ├── *.txt           ← 每个组件集的 hex 数据
  └── component_index.json  ← 组件名/变体key/hex路径的查询索引
        │
        ▼
设计稿 DSL (.dsl.json)
        │
        ▼
   pix-dsl            ← 读取 DSL + 组件 hex，输出完整设计稿 hex
        │
        ▼
  output.txt          ← 最终可导入 Pixso 的 hex 文件
```

---

## 根目录文件

| 文件 | 说明 |
|---|---|
| `README.md` | 本说明文档 |
| `设计dsl.md` | DSL JSON 格式规范，定义 frame/text/instance 等图层结构 |
| `home_feed_2in1.dsl.json` | 2in1 首页信息流设计稿的 DSL，包含 10 个 instance 节点 |
| `home_feed_2in1.txt` | 上面 DSL 对应的 hex 输出（由 pix-dsl 生成） |
| `home_feed_2in1_components.md` | 列出 DSL 涉及的组件集 componentKey，便于查找 hex 文件 |
| `component_index.json` | 同 `pixso-parse/pix-split/harmony_out/component/component_index.json` 的副本 |
| `eee.md` | 组件集拆解流程的逻辑说明（parentIndex/0:2/样式节点等规则） |
| `html_to_dsl.py` | HTML 设计稿 → DSL JSON 转换脚本 |
| `html-to-design-flow.md` | HTML 转 DSL 的流程说明 |
| `instance_component_analysis.md` | instance 组件分析文档 |
| `SKILL.md` | Claude skill 配置（html-page-builder） |
| `pipeline/` | 管道阻塞问题记录 |

---

## pixso-parse/ 子目录

### 核心库文件

| 文件 | 说明 |
|---|---|
| `pixso.h` | Pixso kiwi schema 的 C++ 头文件，定义所有节点类型（PixsoNode、GUID、ParentIndex 等） |
| `pixso.js` / `pixso.kiwi` | JS 版 schema，供 pix-to-json 使用 |
| `kiwi-master/` | kiwi 二进制序列化库 |
| `zstd-1.5.6/` | zstd 压缩库（.pix 文件内部使用） |
| `node_modules/` | pix-to-json 的 Node.js 依赖 |

### 测试/参考 .pix 文件

| 文件 | 说明 |
|---|---|
| `HarmonyOS Component Library（来自社区）.pix` | **主组件库**，所有组件的来源 |
| `StatusBar.pix` | 1.StatusBar 组件导出的完整 pix，用于对比验证拆解结果 |
| `instance1.pix` | 包含 instance 节点的小测试设计文件 |
| `设计文件.pix` | 另一个参考设计文件 |

### 说明文档

| 文件 | 说明 |
|---|---|
| `aaa.md` | dsl→hex 整体流程说明；pix-split 要求；pix-dsl 注意事项 |
| `bbb.md` | blob 数据处理方案 + 不应修改原始组件节点的分析 |
| `ddd.md` | 用已有组件 hex 生成 DSL 文件的说明 |

---

## pixso-parse/ 各工具项目

### pix-split — 组件库拆解工具

**用途**：将 `HarmonyOS Component Library.pix` 拆解成按组件集粒度的 hex 文件。

**何时用**：组件库更新、或需要重新生成 hex 时。

```bash
cd pixso-parse/pix-split
make
./bin/split_compset build_index \
  '../HarmonyOS Component Library（来自社区）.pix' \
  harmony_out \
  --publish-file QcO-1WDViGmGQ4IFU_p4FQ
```

**输出**：
- `harmony_out/component/*.txt` — 每个组件集的 hex（文件名为 componentKey）
- `harmony_out/component/component_index.json` — 组件索引，结构：
  ```json
  {
    "componentSets": [{ "name", "componentKey", "hexFile", "variants": [...] }],
    "standaloneComponents": [{ "name", "componentKey", "hexFile" }]
  }
  ```

**关键逻辑**（见 `split_compset.cpp`）：
- 每个 hex 包含两个合成 CANVAS 节点：`{0,1}` 主页 + `{0,2}` 隐藏页
- 主根组件集 FRAME → 挂 `{0,1}`
- 被 INSTANCE 引用拉入的外部组件/symbol → 挂 `{0,2}`
- blob 全部收集并重映射为从 0 开始的连续下标

---

### pix-dsl — DSL 转 hex 工具

**用途**：将设计稿 DSL（JSON）+ 组件 hex 目录，输出完整的 Pixso hex 文件。

**何时用**：有 DSL 文件需要转成 Pixso 可导入格式时。

```bash
cd pixso-parse/pix-dsl
make

# 目录模式（推荐，自动按 component_set_key 找 hex）
./bin/dsl_to_hex \
  ../../home_feed_2in1.dsl.json \
  ../../home_feed_2in1.txt \
  ../pix-split/harmony_out/component
```

**DSL instance 节点关键字段**：
- `instance.component_set_key` → 找到对应的 `{key}.txt` hex 文件
- `instance.symbol_id` → 在 hex 中定位具体变体 SYMBOL

---

### pix-to-json — hex/pix 解码工具

**用途**：将 `.pix` 文件或 hex txt 解码成可读的 JSON，用于调试和验证。

**何时用**：需要查看 hex 文件内部节点结构时。

```bash
cd pixso-parse/pix-to-json
node pix2json.js ../StatusBar.pix         # 解码 .pix 文件
node pix2json.js ../pix-split/harmony_out/component/9330cc5....txt  # 解码 hex txt
# 输出同目录下的 .json 文件
```

---

### pix-instance — 组件实例构建

**用途**：构建 INSTANCE 节点相关逻辑（在 pix-dsl 内部使用）。

---

### pix-detach — 组件解绑

**用途**：将 INSTANCE 节点解绑为普通图层。

---

## 典型操作流程

### 场景 1：组件库有更新，重新拆解

```bash
cd pixso-parse/pix-split
./bin/split_compset build_index '../HarmonyOS Component Library（来自社区）.pix' harmony_out --publish-file QcO-1WDViGmGQ4IFU_p4FQ
```

### 场景 2：有新的 DSL 文件，转成 hex

```bash
cd pixso-parse/pix-dsl
./bin/dsl_to_hex /path/to/design.dsl.json /path/to/output.txt ../pix-split/harmony_out/component
```

### 场景 3：验证某个组件 hex 的节点结构

```bash
cd pixso-parse/pix-to-json
node pix2json.js ../pix-split/harmony_out/component/{componentKey}.txt
# 查看生成的 .json 文件
```

### 场景 4：对比拆解结果与真实 pix 文件的差异

```bash
cd pixso-parse/pix-to-json
node pix2json.js ../StatusBar.pix
node pix2json.js ../pix-split/harmony_out/component/9330cc56931bc08f2dba6ae32099f733e7949604.txt
# 用 Python 脚本对比两个 json
```
