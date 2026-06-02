现在验证 html->dsl->hex 不包含实例组件的可行性。
文件都放到 pipeline 目录下
1. 用 SKILL.md 生成测试用的html文件
2. 将 html 文件转成符合 设计dsl.md 的 dsl json 文件。此处可以进行收敛去创建 SKILL 文件。
3. 使用 pix-dsl 将 dsl 生成 hex 文件，此处不允许修改 pix-dsl 目录中的文件。
4. 生成文件是否成功 是否存在错误，对 html 和 hex 文件图层进行比对，查看是否有数据丢失。
