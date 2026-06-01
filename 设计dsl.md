字段信息
# 设计 DSL

基于设计稿解析出来的通用表达结构，包含设计稿图层树、图层样式、组件数据、布局识别等信息，用标准 JSON 格式承载，包含以下主要内容：

| 字段 | 类型 | 必选 | 说明 | 详情 |
| :--- | :--- | :--- | :--- | :--- |
| mate | string | 是 | 文件来源信息 | [点击查看](#meta)
| content | array | 是 | 主要数据来源 | [点击查看](#content)
| name | string | 否 | 引用外部资源 | [点击查看](#assets) 

---


<a id="meta"></a>

## 文件来源信息（Meta）

| 字段 | 类型 | 必选 | 说明 | 详情 |
| :--- | :--- | :--- | :--- | :--- |
| version | string | 是 | DSL数据格式版本 ｜ 格式：Major.Minor.Patch, 例：`2.0.0`
| id | string | 是 | 文件为一标识 ｜ -
| name | string | 是 | 文件名称 ｜ -
| descirption | string | 是 | 文件描述 ｜ -
| created_at | string | 是 | 创建时间 ｜ 格式：ISO 8601(YYYY-MM-DD HH:mm:ss)
| updated_at | string | 是 | 更新时间 ｜ 格式：ISO 8601(YYYY-MM-DD HH:mm:ss)


---

## 主要数据内容

以数据嵌套形式表达图层上下文机构

- 同一数组内元素，为兄弟图层
- 数组下标从升序，为兄弟图层自上而下排序（注意：非图层视觉堆叠的上下关系）

| 字段 | 类型 | 必选 | 说明 | 详情 |
| :--- | :--- | :--- | :--- | :--- |
| key | string | 是 | 节点唯一标识 ｜ -
| name | string | 是 | 节点名称 ｜ -
| type | string | 是 | 节点类型 ｜ [点击查看](#type)
| box | object | 是 | 节点最小包围框 ｜ [点击查看](#bbox)
| style | object | 是 | 节点样式集合 ｜ [点击查看](#style)
| interaction | object | 是 | 交互跳转 ｜ [点击查看](#interaction)
| motion | object | 是 | 交互动效 ｜ [点击查看](#motion)
| content | string | 是 | 文本内容 ｜ -
| children | array | 是 | 容器节点的子节点集合 ｜ -
| layout_parent | object | 是 | 作为容器节点时的布局描述 ｜ [点击查看](#layout-parent)
| layout_child | object | 是 | 作为内容节点时的布局描述 ｜ [点击查看](#layout-child)
| component_instance | object | 是 | 组件实例节点的相关内容 ｜ [点击查看](#component-instance)
| library_style | array | 是 | 使用了规范库样式节点的相关数据 ｜ [点击查看](#library-style)
| library_style | array | 是 | 使用了规范库样式节点的相关数据 ｜ [点击查看](#)


---

## 示例 JSON

```json
{
  "id": "node-001",
  "type": "view",
  "name": "卡片容器",
  "style": {
    "width": 375,
    "height": 120,
    "x": 0,
    "y": 0,
    "backgroundColor": "#FFFFFF",
    "borderRadius": 8,
    "padding": [16, 16, 16, 16]
  },
  "layout": {
    "direction": "row",
    "alignItems": "center",
    "justifyContent": "space-between",
    "gap": 12,
    "wrap": false
  },
  "children": [
    {
      "id": "node-002",
      "type": "image",
      "name": "头像",
      "style": { "width": 48, "height": 48, "borderRadius": 24 },
      "props": { "src": "https://example.com/avatar.png" },
      "children": []
    },
    {
      "id": "node-003",
      "type": "text",
      "name": "标题",
      "style": { "fontSize": 16, "fontWeight": "700", "color": "#1A1A1A" },
      "props": { "content": "用户名" },
      "children": []
    }
  ],
  "meta": {
    "sourceFile": "design.fig",
    "layerId": "1:23",
    "parserVersion": "1.0.0"
  }
}
```
