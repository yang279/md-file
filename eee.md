组件集拆解流程：
1. 找到所有非隐藏页的CANVAS节点的一层子节点，子节点符合type为FRAME且isStateGroup为true或者type为SYMBOL节点。收集到数组中 symbolDatas。
2. 在 symbolDatas 中遍历找到每个节点的所有相关节点。
   2.1. 收集当前节点的所有子孙节点
   2.2. 子孙节点中存在 INSTANCE 节点，需要找到 symbolData.symbolID，收集组件节点、组件节点的父节点及组件节点的所有子孙节点。组件节点的父节点为 FRMAE且isStateGroup，就需要收集子孙节点，其他情况不需要。
       2.2.1. 组件节点的父节点非FRMAE，就需要将组件节点的 parentIndex的guid 改成0:2
       2.2.2. 组件节点的父节点为FRAME，就需要将组件节点的父节点的parentIndex的guid改成0:2
   2.3. 收集的所有子孙节点中的样式节点，且样式节点的父节点需要设置为0:2
   2.4. 所有节点的blob都需要收集，所有的 blobIndex 以及 vertor的index

