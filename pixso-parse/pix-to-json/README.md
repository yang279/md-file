# pix-to-json — Pixso hex/pix 转 JSON 工具集

将 Pixso 的 `.pix` 二进制文件或 `.txt` hex 文件转换为可读 JSON，支持节点差异对比和 pix 转 hex。

---

## 目录结构

```
pix-to-json/
├── pix2json.js             # .pix/.txt → JSON
├── pix2hex.js              # .pix → .txt hex
├── diff_nodes.js           # 两个 pix/json 文件节点差异对比
├── package.json            # npm 依赖声明
├── package-lock.json
│
└── test_data/              # 测试数据
    ├── instance1_from_pix.txt  # 测试输入：instance1.pix 转出的 hex
    ├── instance1.json          # 测试输出：instance1.pix 转出的 JSON
    └── one_instance_out.json   # 测试输出：one_instance_out.txt 转出的 JSON
```

---

## 依赖安装

```bash
npm install
# 安装：fzstd（zstd 解压）、kiwi-schema（kiwi 解码，链接自 ../kiwi-master/js）
```

---

## pix2json — 转 JSON

### 用法

```bash
node pix2json.js <input.txt|input.pix> [output.json]
```

- 输入 `.txt`：hex 文本文件（首行 `<!-- pixso binary data -->` 可选）
- 输入 `.pix`：Pixso 二进制文件
- 不指定输出文件时，自动以输入文件名 + `.json` 命名

### 示例

```bash
# 转换 CLI 生成的 hex 结果
node pix2json.js ../pix-dsl/test_data/one_instance_out.txt

# 转换真实设计文件
node pix2json.js ../instance1.pix instance1.json

# 转换组件 hex
node pix2json.js ../pix-split/harmony_out/component/eb2f5b3b...txt
```

---

## pix2hex — pix 转 hex txt

### 用法

```bash
node pix2hex.js <input.pix> [output.txt]
```

输出格式与 `dsl_to_hex` 产物完全一致，可直接用于其他工具。

### 示例

```bash
node pix2hex.js ../instance1.pix instance1_from_pix.txt
```

---

## diff_nodes — 节点差异对比

对比两个 pix/txt/json 文件的 `pixsoNodes` 列表，按 GUID 匹配，输出：
- 仅在 A 中存在的节点
- 仅在 B 中存在的节点
- 共有节点中字段有差异的节点

### 用法

```bash
node diff_nodes.js <A.json|A.txt|A.pix> <B.json|B.txt|B.pix>
```

### 示例

```bash
# 对比 CLI 输出和真实设计文件
node diff_nodes.js test_data/one_instance_out.json test_data/instance1.json

# 直接传 pix 文件（自动转换）
node diff_nodes.js ../pix-dsl/test_data/one_instance_out.txt ../instance1.pix
```

---

## 输出 JSON 结构

```json
{
  "type": "FIC_DOCUMENT",
  "pixsoNodes": [
    {
      "guid": { "sessionID": 0, "localID": 1 },
      "type": "CANVAS",
      "name": "页面 1",
      "parentIndex": { "guid": { "sessionID": 0, "localID": 0 }, "position": "!" },
      ...
    },
    ...
  ],
  "blobs": [
    { "bytes": [102, 105, ...] },
    ...
  ]
}
```
