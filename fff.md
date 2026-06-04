读一下 AGENT.md README.md 现在需要将整个流程串起来。

用户输入 -> 【DSL生成 SKILL】 -> DSL -> 【DSL转设计DSL node服务】 -> 设计DSL -> 【DSL转hex node服务】 -> hex

DSL与设计DSL最大的不同就是：
    DSL有本地SVG、图片数据，只有组件描述信息。
    设计DSL只能存云端SVG、图片数据，如果没有，则需要用占位符先进行占位，后续再处理。组件需要存组件key信息。

DSL转设计DSL中 需要根据组件描述信息 去找到对应的组件key，然后拼出对应的设计DSL的格式。此处需要提供【查询组件信息 node服务】。
例子：传入“按钮/Button” 输出 “组件库中Button的默认变体信息”。
   传入“按钮 属性=文本” 输出 ”组件库中Button的文本按钮变体信息“

先分析一下这个流程有什么问题吗？ 

1. DSL生成的 SKILL 暂不处理
2. DSL转设计DSL 暂不处理
3. DSL转hex 的 nodejs服务：
输入 设计dsl.md 格式的 dsl json 文件
输出 hex 文件
调用 c++ 编译好的 wasm 文件
4. 查询组件信息 的 nodejs 服务：
输入 组件名字/组件属性/组件一些描述 
输出变体数据