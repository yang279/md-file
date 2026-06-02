dsl->hex 的流程是：
1. 有一个完整的dsl数据，里面有普通图层 FRAME、RECTANGE 类型，以及INSTANCE类型，可以描述一个简单设计稿的图层结构。
2. 在dsl的INSTANCE节点中，会存在组件集key和实际变体key，需要获取到相应的组件集hex文件路径。
3. 将 dsl 的json文件，和所有涉及到的组件集hex路径 都作为参数传递给 c++模块（会编译成wasm），然后经过一系列转换生成对应的 hex 数据。
4. 将 hex 输出通过wasm输出，并写入txt文件中。

其中 
1. dsl数据结构见： 设计dsl.md
2. 需要更新 pix-split 逻辑，此项目仅用来对组件库文件进行拆解，拆解力度是按照组件集进行拆解。
   2.1 组件集的定义是type为FRAME，且 isStateGroup为true。
   2.2 需要将组件集的数据、变体的数据存入一个json文件中，当成一个查询文件，支持通过组件名找到对应的变体key、变体父节点key等数据。此处只需要考虑怎么定义这个json文件以及构建，不需要实现怎么查找。
   2.3 拆解生成的组件集hex命名都以componentkey作为文件名，如果不存在则用 guid即可。目录为 component
3. dsl转hex的逻辑为：普通类型的图层 直接转换成相应的pixso节点数据，实例类型的图层根据 pix-instance 的逻辑进行处理。使用c++进行编程
4. 对于 c++ 构建 pixso节点需要注意的是，需要注意pool的生命周期，无论是解码的pool 还是构建节点的pool 都是需要注意生命周期没有实效的。 pool 是pixso节点数据的内存所在真实区域，而pixsoMsg pixsoNode 都只是指针的形式使用对应的内存数据。

例子：
dsl-demo.json, 不存在instance，因此只需要传 dsl-demo.json 文件就行，输出是hex文件

instance的测试用例：`test_data/dsl-instance-demo.json`

**页面结构**（1 页，2 个顶层 FRAME）：

```
页面 9:1  "测试页面"
├── FRAME 100:1  "导航栏"  (375×44, fill:#FFFFFF)
│   ├── RECTANGLE  100:2  "背景色块"        (375×44, fill:#F5F5F5)  —— 普通图层
│   ├── INSTANCE   100:3  ".search 图标"    (24×24 @ 16,10)
│   └── INSTANCE   100:4  ".Arrow-right 图标" (24×24 @ 335,10)
└── FRAME 100:5  "内容区"  (375×768, fill:#F0F0F0)
    ├── INSTANCE   100:6  ".control button Normal size" (120×36 @ 16,16)
    ├── INSTANCE   100:7  ".more 图标"      (24×24 @ 335,16)
    └── RECTANGLE  100:8  "分割线"          (375×1 @ 0,60)         —— 普通图层
```

**涉及的组件 hex 文件**（均位于 `pix-split/harmony_out/component/`）：

| instance | symbol_id | 组件类型 | hex 文件 |
|---|---|---|---|
| .search 图标 | `39:35729` | standaloneComponent | `39_35729.txt` |
| .Arrow-right 图标 | `1:8969` | standaloneComponent | `1_8969.txt` |
| .control button Normal size | `2804:9994`（变体），组件集 `2804:9970` | componentSet 变体 | `2804_9970.txt` |
| .more 图标 | `67:33993` | standaloneComponent | `67_33993.txt` |

**说明**：
- `variant_key` / `component_set_key` 在 `component_index.json` 中均为空字符串（原始 pix-split 数据未包含 componentKey），因此运行时通过 `symbol_id`（GUID）在对应 hex 文件中定位 SYMBOL 节点。
- 对于 componentSet（`2804_9970.txt`）：该 hex 包含所有变体 SYMBOL，需根据 `symbol_id = "2804:9994"` 找到 `状态=Normal size` 变体。
- 对于 standaloneComponent：hex 文件本身即为该 SYMBOL 的全量节点数据。
- 预期命令（instance 逻辑实现后）：
  ```
  ./bin/dsl_to_hex test_data/dsl-instance-demo.json test_data/instance_out.txt \
    ../../pix-split/harmony_out/component/39_35729.txt \
    ../../pix-split/harmony_out/component/1_8969.txt \
    ../../pix-split/harmony_out/component/2804_9970.txt \
    ../../pix-split/harmony_out/component/67_33993.txt
  ```