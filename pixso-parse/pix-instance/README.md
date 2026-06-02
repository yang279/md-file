# pix-instance — Pixso 实例节点生成工具

读取组件集 hex 文件，选择其中一个 SYMBOL 变体，生成包含该实例的完整 `.pix` hex 数据。

---

## 目录结构

```
pix-instance/
├── gen_instance.cpp    # 实例生成工具源码
├── gen_instance         # 编译产物
├── show_tree.cpp        # 节点树可视化工具源码
├── show_tree            # 编译产物
├── Makefile
├── README.md
└── examples/            # 示例输出
    ├── dialog_content_instance.txt      # Dialog "类型=content" 实例
    └── dialog_instance.txt              # Dialog "title+content+2 button" 实例
```

---

## 依赖（相对路径）

| 依赖 | 路径 |
|------|------|
| pixso kiwi schema | `../pixso.h` |
| kiwi 库头文件 | `../kiwi-master/kiwi.h` |
| zstd 压缩库 | `../zstd-1.5.6/` |
| 组件集 hex 文件 | 由 `pix-split` 项目生成 |

---

## 编译

```bash
make              # 编译全部
make gen_instance # 只编译实例生成工具
make show_tree    # 只编译节点树查看工具
```

---

## gen_instance — 实例生成

### 用法

```bash
# 列出组件集中所有 SYMBOL 变体（含序号、GUID、尺寸、名称）
./bin/gen_instance list <compset.txt>

# 创建实例（按序号选择变体）
./bin/gen_instance create <compset.txt> <序号> [x] [y] [输出文件]

# 创建实例（按名称模糊匹配变体）
./bin/gen_instance create <compset.txt> <名称关键词> [x] [y] [输出文件]
```

- 输入支持 `.txt`（hex 文件）或 `.pix`（二进制）
- 输出 `.txt` 存 hex 文本，输出 `.pix` 存二进制

### 示例

```bash
# 列出 Dialog 组件集的所有变体
./bin/gen_instance list "../pix-split/harmony_out/component/"

# 创建第 18 个变体（"类型=content"）的实例，位于坐标 (100, 200)
./bin/gen_instance create "../pix-split/harmony_out/component/" 18 100 200 output.txt

# 按名称创建
./bin/gen_instance create "../pix-split/harmony_out/component/" "类型=content" 0 0 output.txt
```

### 生成逻辑

1. 解析组件集 hex → 获取全量 N 个节点（原始 GUID 和子树完整保留）
2. 对所有**父节点不在消息内**的节点，将 `parentIndex` 统一改为 `{0,2}`（隐藏页）
   - 避免组件库的 `{0,1}`（库的隐藏页）和设计文件 `{0,1}`（可见页）GUID 冲突
3. 新增 1 个 INSTANCE 节点：
   - `guid = {1, 9999}`（需根据目标设计文件实际最大 localID 调整）
   - `type = INSTANCE`，`phase = CREATED`
   - `parentIndex = {0,1}`（可见页）
   - `symbolData.symbolID` = 选中 SYMBOL 的原始 GUID
4. 输出 **N+1 个节点**的 hex

### 输出节点结构

```
可见页 {0,1}
  └─ INSTANCE {1,9999}  "类型=content"  → symbolID={1,11548}

隐藏页 {0,2}
  ├─ SECTION  "1.Dialog - 对话框"（组件集根容器）
  ├─ SYMBOL {1,11548}  "类型=content"（完整子树）
  ├─ SYMBOL {1,9455}   "尺寸=Medium,类型=Text,..."（被引用的外部组件）
  └─ ...
```

---

## show_tree — 节点树可视化

解析 `.pix` 二进制文件，打印节点树及各页面子节点统计。

### 用法

```bash
# 直接分析二进制文件
./bin/show_tree <file.pix>

# 分析 hex 文本文件（先转换）
tail -1 <file.txt> | xxd -r -p > /tmp/tmp.pix && ./bin/show_tree /tmp/tmp.pix
```

### 输出示例

```
PixsoMsg.type = 2  (NODE_CHANGES)
pixsoNodes 数量: 150

=== 可见页 {0,1} 的直接子节点 ===
共 1 个直接子节点：
  [INSTANCE  ] {1,9999}  "类型=content"  → symbolID={1,11548}

=== 隐藏页 {0,2} 的直接子节点 ===
共 9 个直接子节点：
  [SYMBOL    ] {1,11548}  "类型=content"
  ...
```

---

## 注意事项

1. **GUID 冲突**：新 INSTANCE 的 GUID 当前写死为 `{1,9999}`，实际写入设计文件时应读取目标文件最大 `localID` 并 +1。

2. **"恢复主组件"按钮**：Pixso 对所有实例节点都显示此按钮，表示"可跳转到主组件"，属于正常行为，不代表数据有误。

3. **hex 格式**：输出 `.txt` 文件首行为 `<!-- pixso binary data -->`，第二行为 hex 字符串。读取时自动跳过注释行。
