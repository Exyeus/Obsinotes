### Graph
#### Incidence Matrix 关联矩阵
$$
\begin{pmatrix}
-1 & 1&0&0 \\
0 & -1&1&0 \\
-1&0&1&0 \\
-1&0&0&1 \\
0&0&-1&1
\end{pmatrix}
$$
其中，负一代表从这个节点流出去，然后一代表流入这一列对应的序号的节点。
回路（LOOP）从图形直观上来看，就是一种从当前顶点到另外一个顶点的途径，可以通过另外几次操作达到同样的效果，最终形成一个环。而这一点，在矩阵上就体现为这几行存在线性，相关关系也就是一行可以有另外的两行或者更多行直接加起来或者相减得到。这一点还可以和向量的运算合起来，考虑向量的运算，就是一个向量可以表示为另外两个向量之和的话，那么这两个向量首尾相连，最终也会指向他们合起来的向量。

更进一步：点作为Nodes，连线作为Edges，这里实际上得到一个图。
- 如果图形成一个闭环（Loop），那么就存在线性相关，也就是有的Edge可以经由其他Edge组合得到。
- 如果图不存在闭环，也就是刻画出来的矩阵的行或者列都线性无关，那么这就是树。
- 消去所有的依赖基本的$Node\to Edge\to Node$，得到`?最小生成树`
- 更加牛逼的：$R+(M-R)=M$，也就是列空间维数+零空间维数=总的维数，进一步，得到拓扑结构，我们可以得到刻画顶点、面、边之间关系的欧拉公式。









