# Pixso .pix 文件结构分析：实例与组件关系

## 一、文件概览

| 文件 | 节点总数 | SYMBOL（组件）| INSTANCE（实例）| CANVAS（页面）|
|------|---------|--------------|-----------------|---------------|
| 设计文件 `../设计文件.pix` | 52 | 4 | 4 | 2 |
| 组件集 `../HarmonyOS Component Library（来自社区）.pix` | 8284 | 1227 | 1960 | 11 |

## 二、核心概念

### NodeType 枚举（关键值）

| 值 | 名称 | 含义 |
|---|---|---|
| 16 | `SYMBOL` | **组件定义节点**，相当于类/模板。在组件集文件中大量存在 |
| 17 | `INSTANCE` | **实例节点**，是某个 SYMBOL 的具体使用。携带 `symbolData.symbolID` 指向对应 SYMBOL |
| 3  | `CANVAS` | 页面/画布节点，是顶层容器 |
| 2  | `DOCUMENT` | 文档根节点 |

### PixsoNode 关键字段

```
message PixsoNode {
  GUID          guid          // 节点唯一标识 {sessionID, localID}
  ParentIndex   parentIndex   // 父节点 {guid, position(排序字符串)}
  NodeType      type          // 节点类型
  string        name          // 节点名称
  NodePhase     phase         // MODIFY=0 / CREATED=1 / REMOVED=2
  Matrix        transform     // 2D 变换矩阵 [m00,m01,m02 / m10,m11,m12]
  Vector        size          // 宽高 {x=width, y=height}
  string        componentKey  // (仅 SYMBOL) 全局唯一 hash，跨文件引用依据
  SymbolData    symbolData    // (仅 INSTANCE) 指向 SYMBOL 的数据
}

message SymbolData {
  GUID          symbolID            // 所引用的 SYMBOL 节点 GUID
  PixsoNode[]   symbolOverrides     // 覆写的子节点列表（改变颜色/文字等）
  float         uniformScaleFactor  // 等比缩放系数
}

struct GUID {
  uint sessionID   // 来源会话 ID（组件集中固定，设计文件中为本地值）
  uint localID     // 节点在该会话内的唯一序号
}

message ParentIndex {
  GUID   guid       // 父节点 GUID
  string position   // 排序字符串，决定在父节点中的顺序
}
```

## 三、组件集文件分析（`../HarmonyOS Component Library（来自社区）.pix`）

### CANVAS（页面）列表

| GUID | 名称 |
|---|---|
| {3,38896} | 3. Views 展示类 |
| {594,10496} | 8.ColorStyle |
| {169,8794} | 0. Publis 公共 |
| {3,38894} | 4. Input 输入类 |
| {0,1} | Internal Only Canvas_conflict_conflict_conflict_conflict_conflict_conflict_conflict_conflict_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con_con |
| {594,13732} | 9.FontStyle |
| {42,34195} | 7. IconRes |
| {3,38892} | 5. Selection 选择类 |
| {3,38898} | 2. Controls 操作类 |
| {3,38900} | 1. Navigation 导航类 |
| {3,38886} | 6. Container 容器类 |

### SYMBOL（组件）统计

组件集共有 **1227** 个 SYMBOL 节点。以下列出前 30 个：

| # | GUID | 名称 | componentKey（前16位）| 父节点 GUID |
|---|------|------|----------------------|-------------|
| 1 | {1,11737} | left-2=Text | `` | {62,34222} |
| 2 | {320,8896} | TitleBar-secondary page-2in1 | `` | {6,34925} |
| 3 | {1,13201} | 类型=arrow up | `` | {36,35272} |
| 4 | {320,12455} | 列表=ON | `` | {320,12451} |
| 5 | {320,12162} | 尺寸=Medium,类型=Text,状态=Disable | `` | {320,12071} |
| 6 | {2782,9605} | 个数=2,land=ON | `` | {66,20967} |
| 7 | {2855,9985} | 属性=badge longest | `` | {331,13061} |
| 8 | {2674,9606} | cancel=Hover | `` | {2674,9609} |
| 9 | {15,35811} | 尺寸=Medium,类型=Unselected,状态=Loading | `` | {16,36613} |
| 10 | {320,12245} | 状态=Pressed,类型=Unselected | `` | {320,12216} |
| 11 | {1,8071} | Land=ON | `` | {66,22935} |
| 12 | {2674,9650} | 右侧区域=smallbutton+cancel | `` | {2674,9652} |
| 13 | {11,36298} | 组数=7 | `` | {66,22505} |
| 14 | {320,12416} | 属性 1=1 line | `` | {320,12410} |
| 15 | {320,12150} | 尺寸=Medium,类型=Text,状态=Loading | `` | {320,12071} |
| 16 | {1,13496} | .emoji | `` | {42,34195} |
| 17 | {331,12763} | 状态=typing,类型=horizontal left | `` | {331,12758} |
| 18 | {331,12705} | 属性 1=Text with close | `` | {331,12701} |
| 19 | {1802,9514} | 属性 1=title+2lines | `` | {1802,9484} |
| 20 | {331,13090} | 属性 6=24dp ic | `` | {331,13086} |
| 21 | {1,11600} | 2 Line=ON | `` | {58,36656} |
| 22 | {320,8904} | TitleBar-Title with icons-2in1 | `` | {6,34925} |
| 23 | {1,9396} | 尺寸=Small,类型=Selected,状态=Focus | `` | {16,36613} |
| 24 | {1,9347} | Multi selection=ON,组数=4 | `` | {16,37688} |
| 25 | {53,34235} | .color picker | `` | {56,37314} |
| 26 | {40,35055} | Space=ON,状态=Actived | `` | {73,9664} |
| 27 | {31,34477} | 类型=Pure Color,尺寸=Small,vertical=OFF | `` | {31,34419} |
| 28 | {331,13124} | 属性 6=radio btn | `` | {331,13112} |
| 29 | {15,35962} | 尺寸=Small,类型=Warning,状态=Disabled | `` | {16,36613} |
| 30 | {1,13192} | 类型=2line | `` | {36,35055} |
| … | … | （共 1227 个）| … | … |

## 四、设计文件分析（`../设计文件.pix`）

### 全部节点（按出现顺序）

| # | 类型 | GUID | 名称 | 父节点 GUID | 宽 | 高 |
|---|------|------|------|------------|----|----||
| 0 | INSTANCE | {10,35} | .Default | {10,34} | 24 | 24 |
| 1 | TEXT | {10,43} |  | {10,39} | 24 | 24 |
| 2 | VECTOR | {10,42} | path | {10,41} | 20 | 20 |
| 3 | FRAME | {10,39} | square_dashed | {10,38} | 24 | 24 |
| 4 | GROUP | {9,70} | Regular 12sp | {9,67} | 62 | 17 |
| 5 | SYMBOL | {10,38} | .Default | {0,2} | 24 | 24 |
| 6 | INSTANCE | {10,33} | .Default | {10,32} | 24 | 24 |
| 7 | GROUP | {9,63} | Medium 16sp | {9,62} | 62 | 22 |
| 8 | RECTANGLE | {10,40} | rect | {10,39} | 24 | 24 |
| 9 | RECTANGLE | {9,72} | 矩形 | {9,49} | 0 | 22 |
| 10 | GROUP | {9,62} | Textview | {9,49} | 62 | 40 |
| 11 | SYMBOL | {10,30} | 尺寸=40 | {10,29} | 40 | 40 |
| 12 | GROUP | {9,55} | Regular 12sp | {9,52} | 62 | 17 |
| 13 | FRAME | {9,49} | Account card/items/text/normal/1x4 | {8,1} | 312 | 39 |
| 14 | INSTANCE | {10,28} |  | {8,1} | 40 | 40 |
| 15 | GROUP | {9,60} | Regular 12sp | {9,57} | 62 | 17 |
| 16 | SYMBOL | {10,34} | 尺寸=28 | {10,29} | 28 | 28 |
| 17 | TEXT | {9,66} | 12sp | {9,65} | 62 | 17 |
| 18 | GROUP | {9,53} | Medium 16sp | {9,52} | 62 | 22 |
| 19 | GROUP | {9,68} | Medium 16sp | {9,67} | 62 | 22 |
| 20 | RECTANGLE | {10,36} | Light/comp_background_tertiary | {0,2} | 0 | 0 |
| 21 | INSTANCE | {10,31} | .Default | {10,30} | 24 | 24 |
| 22 | TEXT | {9,69} | 16sp | {9,68} | 62 | 22 |
| 23 | FRAME | {10,29} | 3.Icon Button | {0,2} | 220 | 80 |
| 24 | TEXT | {9,59} | 16sp | {9,58} | 62 | 22 |
| 25 | RECTANGLE | {9,86} | 矩形 | {9,85} | 16 | 16 |
| 26 | RECTANGLE | {9,50} | 矩形 | {9,49} | 0 | 22 |
| 27 | FRAME | {8,1} | 容器 1 | {0,1} | 482 | 164 |
| 28 | RECTANGLE | {9,51} | 矩形 | {9,49} | 0 | 22 |
| 29 | CANVAS | {0,2} | Internal Only Canvas | {0,0} | 0 | 0 |
| 30 | GROUP | {9,57} | Textview | {9,49} | 62 | 40 |
| 31 | VECTOR | {9,87} | 路径 | {9,85} | 7 | 12 |
| 32 | TEXT | {9,56} | 12sp | {9,55} | 62 | 17 |
| 33 | TEXT | {9,61} | 12sp | {9,60} | 62 | 17 |
| 34 | TEXT | {9,64} | 16sp | {9,63} | 62 | 22 |
| 35 | SYMBOL | {10,32} | 尺寸=32 | {10,29} | 32 | 32 |
| 36 | GROUP | {9,65} | Regular 12sp | {9,62} | 62 | 17 |
| 37 | RECTANGLE | {9,84} | Rectangle 271 | {9,83} | 24 | 24 |
| 38 | GROUP | {10,41} | g | {10,39} | 20 | 20 |
| 39 | TEXT | {9,71} | 12sp | {9,70} | 62 | 17 |
| 40 | FRAME | {9,83} | 1.通用/2.Icon图标/Fill/Left-Disabled | {8,1} | 24 | 24 |
| 41 | TEXT | {2,2} | Title | {2,1} | 252 | 28 |
| 42 | TEXT | {9,54} | 16sp | {9,53} | 62 | 22 |
| 43 | RECTANGLE | {8,2} | 矩形 1 | {8,1} | 87 | 46 |
| 44 | GROUP | {9,85} | left | {9,83} | 16 | 16 |
| 45 | FRAME | {2,1} | Card | {0,1} | 300 | 108 |
| 46 | GROUP | {9,52} | Textview | {9,49} | 62 | 40 |
| 47 | RECTANGLE | {10,37} | Light/icon_primary | {0,2} | 0 | 0 |
| 48 | GROUP | {9,67} | Textview | {9,49} | 62 | 40 |
| 49 | TEXT | {2,3} | Desc | {2,1} | 252 | 20 |
| 50 | GROUP | {9,58} | Medium 16sp | {9,57} | 62 | 22 |
| 51 | CANVAS | {0,1} | 页面 1 | {0,0} | 0 | 0 |

### SYMBOL（本地组件定义）

设计文件中有 **4** 个本地 SYMBOL：

| GUID | 名称 | componentKey |
|---|---|---|
| {10,38} | .Default | `3cd86b21ac498941521bd94177f10b2d4d2a0c02` |
| {10,30} | 尺寸=40 | `549fdf93a10fec402c93432a2e228e407ccc2954` |
| {10,34} | 尺寸=28 | `4ad9c6195dc5f7859cf07583b39c4ebc18a7d0b9` |
| {10,32} | 尺寸=32 | `ecb8481025909ec9371c3b25104bb8b7c1079224` |

### INSTANCE（实例）→ SYMBOL 映射

| # | 实例 GUID | 实例名称 | 指向 symbolID | 在设计文件中找到? | 在组件集中找到? | 组件名称 |
|---|-----------|---------|--------------|-----------------|----------------|----------|
| 1 | {10,35} | .Default | {10,38} | ✓设计文件 | 否 | .Default |
| 2 | {10,33} | .Default | {10,38} | ✓设计文件 | 否 | .Default |
| 3 | {10,28} |  | {10,30} | ✓设计文件 | 否 | 尺寸=40 |
| 4 | {10,31} | .Default | {10,38} | ✓设计文件 | 否 | .Default |

**引用来源统计：**

- 引用设计文件内部 SYMBOL：4 个
- 引用组件集 SYMBOL：0 个
- 未找到（可能来自其他外部文件）：0 个

## 五、节点树结构（设计文件）

以父节点 GUID 为键，列出其直接子节点：

- **[CANVAS]** `Internal Only Canvas` {0,2}
  - **[SYMBOL]** `.Default` {10,38}
    - **[FRAME]** `square_dashed` {10,39}
      - **[TEXT]** `` {10,43}
      - **[RECTANGLE]** `rect` {10,40}
      - **[GROUP]** `g` {10,41}
        - **[VECTOR]** `path` {10,42}
  - **[RECTANGLE]** `Light/comp_background_tertiary` {10,36}
  - **[FRAME]** `3.Icon Button` {10,29}
    - **[SYMBOL]** `尺寸=40` {10,30}
      - **[INSTANCE]** `.Default` {10,31}
          ↳ symbolID={10,38}
    - **[SYMBOL]** `尺寸=28` {10,34}
      - **[INSTANCE]** `.Default` {10,35}
          ↳ symbolID={10,38}
    - **[SYMBOL]** `尺寸=32` {10,32}
      - **[INSTANCE]** `.Default` {10,33}
          ↳ symbolID={10,38}
  - **[RECTANGLE]** `Light/icon_primary` {10,37}
- **[CANVAS]** `页面 1` {0,1}
  - **[FRAME]** `容器 1` {8,1}
    - **[FRAME]** `Account card/items/text/normal/1x4` {9,49}
      - **[RECTANGLE]** `矩形` {9,72}
      - **[GROUP]** `Textview` {9,62}
        - **[GROUP]** `Medium 16sp` {9,63}
          - **[TEXT]** `16sp` {9,64}
        - **[GROUP]** `Regular 12sp` {9,65}
          - **[TEXT]** `12sp` {9,66}
      - **[RECTANGLE]** `矩形` {9,50}
      - **[RECTANGLE]** `矩形` {9,51}
      - **[GROUP]** `Textview` {9,57}
        - **[GROUP]** `Regular 12sp` {9,60}
          - **[TEXT]** `12sp` {9,61}
        - **[GROUP]** `Medium 16sp` {9,58}
          - **[TEXT]** `16sp` {9,59}
      - **[GROUP]** `Textview` {9,52}
        - **[GROUP]** `Regular 12sp` {9,55}
          - **[TEXT]** `12sp` {9,56}
        - **[GROUP]** `Medium 16sp` {9,53}
          - **[TEXT]** `16sp` {9,54}
      - **[GROUP]** `Textview` {9,67}
        - **[GROUP]** `Regular 12sp` {9,70}
          - **[TEXT]** `12sp` {9,71}
        - **[GROUP]** `Medium 16sp` {9,68}
          - **[TEXT]** `16sp` {9,69}
    - **[INSTANCE]** `` {10,28}
        ↳ symbolID={10,30}
    - **[FRAME]** `1.通用/2.Icon图标/Fill/Left-Disabled` {9,83}
      - **[RECTANGLE]** `Rectangle 271` {9,84}
      - **[GROUP]** `left` {9,85}
        - **[RECTANGLE]** `矩形` {9,86}
        - **[VECTOR]** `路径` {9,87}
    - **[RECTANGLE]** `矩形 1` {8,2}
  - **[FRAME]** `Card` {2,1}
    - **[TEXT]** `Title` {2,2}
    - **[TEXT]** `Desc` {2,3}

## 六、如何构造一个实例节点

### 数据结构要求

要在设计文件中添加一个引用组件集内 SYMBOL 的实例节点，需要填充以下字段：

```
PixsoNode instance;
// 1. 分配新 GUID（sessionID 取当前文件的 session，localID 自增）
instance.guid = { sessionID, newLocalID };

// 2. 设置节点类型
instance.type = NodeType::INSTANCE;  // = 17

// 3. 设置阶段：新增
instance.phase = NodePhase::CREATED; // = 1

// 4. 指定父节点和排序位置
instance.parentIndex = { parentGuid, positionString };

// 5. 命名
instance.name = "MyInstance";

// 6. 位置与大小
instance.transform = { m00=1,m01=0,m02=x, m10=0,m11=1,m12=y };  // 平移到 (x,y)
instance.size = { width, height };

// 7. 核心：指向目标 SYMBOL 的 GUID
instance.symbolData.symbolID = targetSymbolGUID;  // 取自组件集文件
```

### 编码流程

```
1. 从组件集 .pix 解码，找到目标 SYMBOL 的 GUID
2. 构造 PixsoNode（INSTANCE），symbolData.symbolID = 目标 GUID
3. 将实例节点放入 PixsoMsg.pixsoNodes[]
4. 设置 PixsoMsg.type = PIX_DOCUMENT (= 16)
5. 调用 PixsoMsg::encode(ByteBuffer) 序列化为 kiwi 二进制
6. 用 ZSTD_compress() 压缩
7. 写入 .pix 文件："pixso-kw" + version[2] + len + "compress:zstd" + 压缩数据
```

## 七、真实示例：设计文件中某实例的完整字段

以实例 `.Default`（GUID={10,35}）为例：

```
guid        = {10,35}
type        = INSTANCE (17)
name        = ".Default"
parentGuid  = {10,34}  pos="!"
size        = {w=24.0, h=24.0}
transform   = [1.00, 0.00, 2.00 / 0.00, 1.00, 2.00]
symbolData.symbolID = {10,38}  → 组件名: "—"
symbolOverrides (1 个):
  {0,0}
```

## 八、总结：实例-组件-组件集三者关系

```
┌──────────────────────────────────────────────────────────────────────┐
│  组件集文件 (.pix)                                                     │
│  ┌─────────────────────────────────────────────────────────────────┐ │
│  │  CANVAS (页面)                                                   │ │
│  │   └─ SYMBOL (组件定义)  guid={A,B}  componentKey="xxxxx"        │ │
│  │       ├─ FRAME / GROUP / TEXT / VECTOR ...（子节点，定义外观）     │ │
│  │       └─ SYMBOL 可以嵌套引用其他 SYMBOL（实现组件复用）             │ │
│  └─────────────────────────────────────────────────────────────────┘ │
└──────────────────────────────────────────────────────────────────────┘
                              ↑
             symbolData.symbolID = {A,B}  （跨文件引用 GUID）
                              |
┌──────────────────────────────────────────────────────────────────────┐
│  设计文件 (.pix)                                                       │
│  ┌─────────────────────────────────────────────────────────────────┐ │
│  │  CANVAS (页面)                                                   │ │
│  │   └─ FRAME                                                       │ │
│  │       └─ INSTANCE (实例节点)  guid={C,D}                         │ │
│  │             symbolData.symbolID = {A,B}  ← 指向组件集的 SYMBOL    │ │
│  │             symbolOverrides[] = [...]  ← 局部覆写（改文字/颜色等）  │ │
│  │             transform / size          ← 实例自身的位置和大小       │ │
│  └─────────────────────────────────────────────────────────────────┘ │
└──────────────────────────────────────────────────────────────────────┘
```

**关键规律：**

1. **GUID 是跨文件引用的桥梁**：实例的 `symbolData.symbolID` 直接使用组件集中 SYMBOL 的原始 GUID，无需映射。
2. **SYMBOL 是不可变模板**：组件集中的 SYMBOL 定义了结构和默认外观，实例通过 `symbolOverrides` 覆写局部属性。
3. **组件集的 sessionID 与设计文件不同**：组件集中节点的 sessionID 来自原始创作会话，设计文件引用时原样使用。
4. **componentKey 用于跨版本匹配**：即使文件更新、GUID 改变，componentKey 不变，可用于找回对应组件。
5. **parentIndex 决定树形层级**：父节点 GUID + position 字符串共同确定节点在树中的位置和渲染顺序。
