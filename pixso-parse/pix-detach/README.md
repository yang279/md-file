# pix-detach — Pixso 实例解绑工具

将 hex 数据中的 INSTANCE 节点"解绑"为普通图层（FRAME），展开组件引用，使每个实例变成独立的图层树，不再依赖组件集定义。

---

## 目录结构

```
pix-detach/
├── detach.cpp          # 源码
├── Makefile
├── README.md
├── bin/                # 编译产物
│   └── detach
└── test_data/          # 测试数据
    ├── detach_out.txt          # 测试输出：单实例解绑结果
    └── picker_detach_out.txt   # 测试输出：选色器实例解绑结果
```

> **测试输入**：来自 `pix-instance/examples/` 或 `pix-dsl/` 目录生成的 hex 文件。

---

## 依赖

| 依赖 | 路径 |
|---|---|
| pixso kiwi schema | `../pixso.h` |
| kiwi 库 | `../kiwi-master/kiwi.h` |
| zstd 压缩库 | `../zstd-1.5.6/` |

---

## 编译

```bash
make
```

---

## 用法

```bash
./bin/detach <input.txt> <output.txt>
```

- 输入：`gen_instance` 或 `dsl_to_hex` 生成的 hex txt
- 输出：解绑后的 hex txt

### 示例

```bash
# 解绑单实例 hex
./bin/detach ../pix-dsl/test_data/one_instance_out.txt test_data/detach_out.txt

# 解绑多实例 hex
./bin/detach ../pix-dsl/test_data/instance_out.txt test_data/multi_detach_out.txt
```

---

## 解绑逻辑

```
输入 hex
  ↓
解析所有节点，找出所有 INSTANCE 节点
  ↓
对每个 INSTANCE：
  1. 找到其引用的 SYMBOL（在隐藏页 {0,2}）
  2. 将 SYMBOL 根节点替换为同等尺寸/位置的 FRAME
  3. 递归展开 SYMBOL 子树（遇到嵌套 INSTANCE 继续展开）
  4. 循环引用保护：路径跟踪防止 A→B→A 死循环
  ↓
输出 hex：不含任何 INSTANCE 节点，所有内容为普通图层
```

**关键特性**：
- **深度解绑**：嵌套 INSTANCE 也会被递归展开，输出为纯图层树
- **多实例展开**：同一 SYMBOL 被多个 INSTANCE 引用时，每次独立展开一份副本
- **GUID 重分配**：展开时为每个副本节点分配新 GUID，避免冲突

---

## 应用场景

- 将组件实例"固化"为普通图层，用于后续的图层编辑或渲染
- 去除对组件库的依赖，使输出 hex 自洽（不需要组件集数据）
