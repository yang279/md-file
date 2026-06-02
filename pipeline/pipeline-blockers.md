# HTML → DSL → Hex 流程卡点整理

> 记录当前 `html_to_dsl.py` + `pix-dsl/dsl_to_hex` 流程中已确认的卡点，按阶段分类。

---

## 🎯 只考虑实例路径时的卡点（精简视图）

> 仅关注 HTML 元素 → 组件实例（TextInput / CheckBox / Button）这条路径时，其他图层属性（布局坐标、stroke、auto_layout 等）暂时不是优先问题。**真正阻塞实例可用的只有以下两个核心卡点 + 一个坐标定位问题。**

---

### 核心卡点：实例文本无法定制

HTML 的 `placeholder` / `value` → 实例组件内的文字，当前全链路**无一处实现**：

```
HTML <input placeholder="请输入邮箱">
  ↓ html_to_dsl.py
DSL instance.overrides = []          ← B1-3：DSL 层未写入 overrides
  ↓ dsl_to_hex
hex derivedSymbolData 全空槽位       ← B2-3：hex 层不读 overrides，槽位全空
  ↓ Pixso 渲染
显示："Input"（组件库原始占位符）    ← 结果：所有输入框显示同一文字
```

**两个方向可以解决：**

| 方向 | 路径 | 新增工作 |
|------|------|----------|
| **A：实现 overrides**（直接修） | DSL 写 overrides → dsl_to_hex 读取 → 写入 derivedSymbolData slot | 在 dsl_to_hex.cpp 里实现 slot 映射 + 写入（见 B2-3 详情）|
| **B：detach 绕过**（间接绕） | dsl_to_hex → pix-detach 展开实例 → text-patch 替换文字 | 新增 text-patch 步骤（见 B3-1 / B3-2）|

---

### 次要卡点：实例位置是估算值

实例节点的 `box.x / box.y` 靠规则估算，不是真实渲染坐标（见 B1-1）。  
对实例路径而言，**结构和文字内容是否正确比坐标更优先**，坐标问题可在后续引入 Headless Browser 后统一解决。

---

## 详细卡点说明（完整版）

---

## 第一阶段：HTML → DSL（`html_to_dsl.py`）

### B1-1 坐标全是估算值（严重）
**现象**：所有节点的 `box.x / box.y` 由固定规则计算（section 高度硬编码、padding-top 固定 80px），而非真实渲染坐标。  
**根因**：没有布局引擎，无法还原 CSS Flexbox / Grid 的实际摆放结果。  
**影响**：导入 Pixso 后图层位置与设计稿不符。  
**解决方向**：用 Headless Browser（Puppeteer / Playwright）执行 `getBoundingClientRect()`，取真实渲染坐标。

---

### B1-2 CSS Grid 多列布局 x 坐标不展开（严重）
**现象**：feature-grid / testimonial / pricing-table 中的卡片，在 DSL 里 x 坐标全为 0，没有按列展开。  
**根因**：`html_to_dsl.py` 遇到 `.grid` 容器时，子元素逐行叠加 y 偏移，但 x 偏移始终为 0。  
**影响**：三列卡片重叠在同一列。  
**解决方向**：同 B1-1，依赖真实渲染坐标；或解析 `grid-template-columns` 手动计算列宽。

---

### B1-3 `<input>` 实例的占位文字无法传递（中等）
**现象**：`<input placeholder="请输入邮箱">` 转为 instance 节点后，DSL 的 `instance.overrides` 为空数组，组件内的占位文字始终显示组件库原始值 `"Input"`。  
**根因**：`dsl_to_hex` 目前完全不处理 `instance.overrides`（见 B2-3），导致即使 DSL 里写了 overrides，hex 里也不生效。  
**影响**：所有 TextInput 实例显示相同的 "Input" 占位符。  
**解决方向（A）**：实现 B2-3（在 dsl_to_hex 里支持 override 写入 derivedSymbolData）。  
**解决方向（B）**：走 detach 路径（见 B3）。

---

### B1-4 文本内联混排样式丢失（中等）
**现象**：`<p>` 内的 `<strong>`、`<span style="color:...">` 等局部格式，被 `get_text(strip=True)` 拍平为单一样式文本节点。  
**根因**：当前 TEXT 节点只支持全文统一的 `text_style`，未使用 DSL 里 `TextData.styleOverrideTable` 的多段样式能力。  
**影响**：加粗/变色的局部文字在导入后失去差异样式。

---

### B1-5 图片 src 丢失（轻微）
**现象**：`<img src="...">` 生成的 rectangle 节点，`fills[].image_hash = "placeholder"`，不携带真实图片数据。  
**根因**：HTML 里的 `placehold.co` 图片是外链，转换时没有下载并计算 hash。  
**影响**：设计稿里图片区域为空。

---

### B1-6 元素级 opacity 丢失（轻微）
**现象**：CSS 内联样式 `opacity:.85` 等没有被提取到节点的 `opacity` 字段。  
**根因**：`parse_inline_style` 有读 `opacity`，但只在通用 frame 路径生效；text/button 等专用构建函数里没有提取。

---

### B1-7 边框（stroke）覆盖不完整（轻微）
**现象**：只有 `.card` 生成了 `strokes` 字段；`<header>` 的 `border-bottom` 等其他 border 样式未转换。  
**根因**：`make_card_layer` 硬编码了 stroke，其他函数没有解析 `border-*` CSS。

---

### B1-8 绝对定位元素位置错误（轻微）
**现象**：`position:absolute; top:-14px` 的"最受欢迎"徽章被按普通流处理，位置错误。  
**根因**：没有 CSS 层叠上下文解析能力。

---

## 第二阶段：DSL → Hex（`pix-dsl/dsl_to_hex.cpp`）

### B2-1 TEXT 节点缺少排版属性（中等）
**现象**：`text_style` 中的以下字段已解析但未写入 kiwi：
- `align_h / align_v` → `TextAlignHorizontal / TextAlignVertical`
- `letter_spacing` → `TextStyleData::set_letterSpacing`
- `line_height` → `TextStyleData::set_lineHeight`

**影响**：文字对齐、行高在 Pixso 里默认显示，可能与设计稿不符。  
**代码位置**：`dsl_to_hex.cpp` TEXT 分支末尾的 `// TODO` 注释处。

---

### B2-2 strokes / auto_layout / effects 完全未实现（中等）
**现象**：DSL 里的 `strokes`、`auto_layout`、`effects` 三个字段在 `DslLayer` 结构体和 `parseLayer` 中均未定义/解析。  
**影响**：
- `strokes`：卡片边框丢失
- `auto_layout`：frame 的 flex 布局信息丢失，变为绝对位置空框
- `effects`：阴影/模糊全部丢失

---

### B2-3 instance.overrides 完全未实现（严重）
**现象**：DSL `instance.overrides[]`（node_id + field + value）在 `parseLayer` 里从未被读取，`DslLayer` 结构体也没有对应字段。`derivedSymbolData` 所有槽位写入后保持 kiwi 默认空值，等同于无覆写。  
**影响**：所有实例内的文字永远显示组件库原始占位值，无法通过 DSL 定制。  
**实现难点**：  
1. 需要对 SYMBOL 子树做与 `computeDerivedCount` 完全一致的 DFS，建立 `node_id → slot_index` 映射  
2. 找到对应 slot，向 `derivedSymbolData[i].textData` 写入 characters + characterStyleIDs + styleOverrideTable  
3. 需要在加载组件集之后、fillLayerNode 执行时完成，时序上有依赖

---

### B2-4 image_hash / gradient stops 未实现（轻微）
**现象**：`fills[].image_hash` 在 kiwi 里未写入实际内容；渐变的 `stops[]`（ColorStop）未解析。  
**影响**：图片填充为空，渐变退化为无颜色。

---

## 第三阶段：实例文本修改的替代路径（detach）

当 B2-3 尚未实现时，可以通过 `pix-detach` 绕开 override 机制：

```
dsl_to_hex  →  hex（含 INSTANCE）
     ↓
pix-detach  →  hex（INSTANCE 展开为 FRAME/TEXT，TEXT.characters = "Input"）
     ↓
text-patch  →  hex（按位置顺序替换 TEXT.characters 为实际文字）
```

### B3-1 text-patch 步骤目前不存在
**现象**：解绑后需要一个新工具（或在 detach 内扩展）来替换 TEXT 节点的文字。目前无此工具。

### B3-2 同类实例解绑后无法区分
**现象**：login 页两个 TextInput 解绑后都生成名为 `"Input"` 的 TEXT 节点，无法通过节点名区分哪个是 email、哪个是 password。  
**解决方向**：在 DSL instance 上附加一个 `patch_text` 扩展字段，detach 时读取该字段写入 `textData.characters`；或靠图层树中的顺序（第 1 个 = email，第 2 个 = password）约定匹配。

---

## 卡点优先级汇总

> `实例路径` 列标 ✅ 表示只走实例路径时该卡点仍然相关；标 `—` 表示实例路径下可暂时忽略。

| 编号 | 描述 | 严重程度 | 阶段 | 实例路径 | 最短解法 |
|------|------|----------|------|----------|----------|
| B2-3 | instance.overrides 未实现 | 🔴 严重 | DSL→Hex | ✅ **核心** | detach + text-patch 绕过 |
| B1-3 | input 占位文字无法传递 | 🔴 严重 | HTML→DSL | ✅ **核心** | 依赖 B2-3 或 detach 路径 |
| B1-1 | 坐标全是估算值 | 🟠 中等 | HTML→DSL | ✅ 次要 | Headless Browser 取真实坐标 |
| B3-1 | text-patch 工具不存在 | 🟠 中等 | Detach路径 | ✅ 若走detach | 新增或扩展 pix-detach |
| B3-2 | 解绑后同类实例无法区分 | 🟠 中等 | Detach路径 | ✅ 若走detach | DSL 扩展 patch_text 字段 |
| B1-2 | Grid 列 x 坐标不展开 | 🟠 中等 | HTML→DSL | — | 同 B1-1 |
| B2-1 | TEXT 排版属性缺失 | 🟡 轻微 | DSL→Hex | — | 补 TODO 三个字段 |
| B2-2 | strokes/auto_layout/effects 未实现 | 🟡 轻微 | DSL→Hex | — | 扩展 DslLayer + fillLayerNode |
| B1-4 | 内联混排样式丢失 | 🟡 轻微 | HTML→DSL | — | 使用 styleOverrideTable 多段样式 |
| B1-5 | 图片 src 丢失 | 🟡 轻微 | HTML→DSL | — | 下载图片计算 hash |
| B2-4 | image_hash/gradient 未实现 | 🟡 轻微 | DSL→Hex | — | 扩展 Paint 写入 |
| B1-6 | 元素 opacity 丢失 | 🟡 轻微 | HTML→DSL | — | 各构建函数补提取 |
| B1-7 | border → stroke 覆盖不完整 | 🟡 轻微 | HTML→DSL | — | 解析 border-* CSS |
| B1-8 | 绝对定位元素位置错误 | 🟡 轻微 | HTML→DSL | — | 依赖真实渲染坐标 |
