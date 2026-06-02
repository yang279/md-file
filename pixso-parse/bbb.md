遗留问题：
1. 传入的hex很多都是带有 blobs 数据的，节点中会有 blobIndex 对应着使用的是 blobs 的下标，因此此处需要提前进行下标的修改，然后再拼接node数据和 blobs 数据，先分析 给方案，等我确认方案后再实现。 blobs 不应该随便重复。
2. 构建实例的时候 不应该修改传入的 组件节点的 xy 宽高等数据，此处需要研究一下 是否有修改组件数据的情况

以上两个遗留问题只研究解决方案，不进行代码实现。 方案需要写入md文件

---

## 问题 1：Blob 数据处理

### 现状分析

通过实验确认：

- **组件 hex 文件**（pix-split 产出）：`PixsoMsg.blobs` 数组为空，但节点中大量存在 `fillGeometry[].blobIndex`、`strokeGeometry[].blobIndex`、`Glyph.blobIndex`、`VectorData.vectorNetworkBlob` 字段，其值指向原始库文件（`.pix`）的 blobs 下标
- **真实设计文件**（如 instance1.pix）：`PixsoMsg.blobs` 有 69 条，节点的 blobIndex 正确引用本地 blobs 数组
- **我们生成的 hex**：blobs 数组为空，节点里的 blobIndex 全是悬空引用（dangling reference），渲染引擎读取几何数据时将拿到空数据或崩溃

**根本原因**：pix-split 提取组件节点时，只拷贝了 PixsoNode 数组，没有同步提取这些节点引用的 blobs 条目。

---

### 涉及 blobIndex 的字段

| 结构 | 字段 | 说明 |
|---|---|---|
| `Path`（在 fillGeometry/strokeGeometry 中） | `blobIndex` | 几何路径数据（SVG path 的二进制编码） |
| `VectorData` | `vectorNetworkBlob` | 矢量网络 blob 下标 |
| `Glyph` | `blobIndex` | 字形轮廓数据 |

---

### 解决方案（两阶段）

#### 阶段 A：修复 pix-split（提取时同步带走 blob）

在 `split_compset.cpp` 的 `makeCompSet` 函数里，收集完节点列表后：

1. **扫描所有收集到的节点**，找出所有 `blobIndex` / `vectorNetworkBlob` 引用值，组成集合 `usedBlobIndices`
2. **从原始库的 `PixsoMsg.blobs` 数组中取出对应条目**，按原始下标升序排列
3. **建立重映射表**：`old_index → new_local_index`（new 从 0 开始连续编号）
4. **更新节点副本中的 blobIndex 字段**：遍历所有收集到的节点，把 blobIndex 替换成新本地下标
5. **将提取到的 blobs 写入该组件 hex 的 PixsoMsg**（`out.set_blobs(pool, count)`）

这样每个组件 hex 都是自包含的：blobs 只包含本组件实际用到的条目，下标从 0 开始连续。

---

#### 阶段 B：修复 dsl_to_hex（合并时去重并重映射）

在 `buildMsg` 里，合并多个 CompSetData 时：

1. **加载阶段**（`loadCompSet` 后）：读取每个 CompSetData 的 blobs 数组，为每条 blob 计算内容哈希（SHA-1 或 CRC32 即可）
2. **去重合并**：维护一个全局 `merged_blobs` 数组。对每个 CompSetData 的每条 blob：
   - 若内容哈希已存在于 merged_blobs → 复用已有下标
   - 否则 → 追加到 merged_blobs，分配新下标
3. **建立每个 CompSetData 的下标重映射表**：`map<int, int> remap`（old → merged）
4. **拷贝节点到输出数组时**（不修改原始节点，见问题 2）：对副本中所有含 blobIndex 的字段，用 remap 表替换为合并后的新下标
5. **在输出 PixsoMsg 上设置合并后的 blobs**：`out.set_blobs(pool, merged_blobs.size())`，并逐条填入

---

## 问题 2：不应修改传入的组件节点数据

### 现状分析

当前 `buildMsg` 里的孤根重挂逻辑（orphan-root rerouting）直接修改了 CompSetData 原始节点：

```cpp
// 当前代码：直接修改原始节点
PixsoNode &n = (*nodes)[i];
if (!parentInSet)
    n.set_parentIndex(makeParent(cs->pool, 0, 2, "a0"));

// 之后才拷贝
arr[idx++] = (*nodes)[i];
```

**问题**：
- 修改的是 CompSetData 持有的节点（`cs->pool` 内存区域里的原始数据）
- 若同一个 CompSetData 在多次 `buildMsg` 调用中复用，第二次的孤根检测会失效（parentIndex 已被上一次修改成 `{0,2}`，会被误判为已在集合内）
- 违背了"传入数据不应被修改"的契约

此外，经过分析，**x/y/宽高数据未被修改**：`fillLayerNode` 里为 INSTANCE 节点设置的 `transform` 和 `size` 都是新分配在主 pool 里的对象，不触碰 CompSetData 里的节点。因此问题仅限于 `parentIndex` 的修改。

---

### 解决方案

**先拷贝，再修改副本**：

```
// 修改后的逻辑（伪代码）
for i in 0..N:
    arr[idx] = (*nodes)[i]        // 1. 先拷贝原始节点到输出数组
    if orphan((*nodes)[i], guidSet):
        arr[idx].set_parentIndex( // 2. 只修改输出副本，不动原始节点
            makeParent(pool, 0, 2, "a0")
        )
    idx++
```

关键点：
- `arr[idx].set_parentIndex(...)` 中使用**主 pool**（不是 cs->pool），新 ParentIndex 对象分配在主 pool 里
- 原始 `(*nodes)[i]` 的 parentIndex 指针不被触碰，CompSetData 保持只读
- 同理，问题 1 中的 blobIndex 重映射也在副本上操作：`arr[idx].fillGeometry()[j].set_blobIndex(remap[old])`

---

## 实现顺序建议

```
A. pix-split 修复（阶段A）：提取时带走 blob
   ↓
B. dsl_to_hex 修复（问题2）：先拷贝再改副本
   ↓
C. dsl_to_hex 修复（阶段B）：合并 blob + 重映射 blobIndex
```

A 优先，因为 B/C 依赖 A 产出的自包含组件 hex。B 和 C 可同步实现，在同一次节点拷贝循环里完成"改 parentIndex + 改 blobIndex"。
