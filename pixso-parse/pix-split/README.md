# pix-split — Pixso 组件库拆解工具

将 Pixso 组件库 `.pix` 文件按组件集拆解，每个组件集输出一个独立的 hex 文本文件，携带完整 blob 几何数据，自洽可用。

---

## 目录结构

```
pix-split/
├── split_compset.cpp       # 拆解工具主源码
├── diagnose.cpp            # 诊断工具源码（查看节点统计）
├── dump_instances.cpp      # 实例列举工具源码
├── dump_keys.cpp           # componentKey 列举工具源码
├── split_compset           # 编译产物
├── Makefile
├── README.md
└── harmony_out/            # 拆解输出目录
    └── component/
        ├── component_index.json        # 组件索引文件
        ├── eb2f5b3bde54280c4c2a...txt  # .Title PC 组件集
        ├── 35e66a1862dab56af99b...txt  # .close btn 独立组件
        └── ...（共 326 个组件集/独立组件）
```

---

## 依赖

| 依赖 | 路径 |
|---|---|
| pixso kiwi schema | `../pixso.h` |
| kiwi 库头文件 | `../kiwi-master/kiwi.h` |
| zstd 压缩库 | `../zstd-1.5.6/` |

---

## 编译

```bash
make
```

---

## 用法

```bash
# 查看拆解报告（组件集列表及统计）
./bin/split_compset report <complib.pix> [--publish-file <id>]

# 拆解 + 生成索引（推荐）
./bin/split_compset build_index <complib.pix> <outdir> [--publish-file <id>]

# 仅拆解，不生成索引
./bin/split_compset dump <complib.pix> <outdir> [--publish-file <id>]

# 打印指定序号组件集的 hex
./bin/split_compset hex <complib.pix> <index> [--publish-file <id>]

# 所有组件集 hex 写入单个文本文件
./bin/split_compset hexall <complib.pix> <out.txt> [--publish-file <id>]
```

### `--publish-file <id>`

为没有 componentKey 的组件补写发布信息：

```
componentKey = SHA1(publishFile + sessionID:localID)
```

---

## 示例

```bash
# 拆解 HarmonyOS 组件库并生成索引
./bin/split_compset build_index \
  "../HarmonyOS Component Library（来自社区）.pix" \
  harmony_out \
  --publish-file QcO-1WDViGmGQ4IFU_p4FQ

# 查看报告
./bin/split_compset report "../HarmonyOS Component Library（来自社区）.pix"

# 查看第 0 个组件集的 hex
./bin/split_compset hex "../HarmonyOS Component Library（来自社区）.pix" 0
```

---

## 输出格式

### hex 文件

```
<!-- pixso binary data -->
706978736f2d6b7700020d636f6d70726573733a7a7374...（hex 字符串）
```

**文件命名**：
- 有 componentKey：`{componentKey}.txt`（40 位 SHA1 hex）
- 无 componentKey（未发布）：`{sessionID}_{localID}.txt`

### component_index.json

```json
{
  "componentSets": [
    {
      "name": ".Button Group",
      "guid": "58:36444",
      "componentKey": "7c366910bf8bc5d84d5ca1a3425f2a2e00ccc3af",
      "canvasName": "6. Container 容器类",
      "hexFile": "component/7c366910bf8bc5d84d5ca1a3425f2a2e00ccc3af.txt",
      "variants": [
        {
          "name": "类型=normal,个数=1",
          "guid": "1:11558",
          "variantKey": "6eb1d8c841e4289f559d238d1d6a0b22e48acb18",
          "parentKey": "7c366910bf8bc5d84d5ca1a3425f2a2e00ccc3af"
        }
      ]
    }
  ],
  "standaloneComponents": [
    {
      "name": ".close btn",
      "guid": "1:11823",
      "componentKey": "35e66a1862dab56af99b09de8bc5ddaf9a3966c5",
      "canvasName": "6. Container 容器类",
      "hexFile": "component/35e66a1862dab56af99b09de8bc5ddaf9a3966c5.txt"
    }
  ]
}
```

---

## 拆解逻辑

1. 解析 `.pix` 文件（zstd 解压 → kiwi 解码 → PixsoMsg）
2. 遍历所有可见 CANVAS 页面
3. 以每个页面的直接子节点（SECTION / SYMBOL / FRAME+isStateGroup）为一个组件集
4. 递归收集该组件集下所有节点：
   - 遇到 INSTANCE 节点：追踪 `symbolData.symbolID`，将引用的 SYMBOL 的整个**组件集**一并收入（保留 FRAME 包装）
5. 提取组件节点引用的所有 blob 条目，本地重新从 0 编号，写入输出 hex
6. 编码（kiwi encode → zstd 压缩 → pixso-kw 文件头）→ 转 hex

**自洽性保证**：每个 hex 文件包含所需的全部节点和 blob 数据，加载时不依赖外部文件。
