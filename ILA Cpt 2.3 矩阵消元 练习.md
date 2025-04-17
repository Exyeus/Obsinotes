### 区分: 同时与逐步

A: 将第三行加到第一行; B: 将第一行加到第三行 |$3 \times 3$ Matrix

$$
A与B同时:\begin{pmatrix}
1 &0&1 \\
0 & 1 & 0 \\
1 & 0 & 1
\end{pmatrix}| 先 A 后 B:\begin{pmatrix}
1 & 0 & 1 \\
0 & 1 & 0 \\
1 & 0 & 2
\end{pmatrix}
$$
先后操作会造成, 操作对象的改变, 进而使得原始的行或者列得到了多次操作.

### 思想 : 逆推方法

1. 构造出一个$3 \times 3$矩阵, 其主对角线上三个元素都是1, 但是不换行消元能够产生2和3位置上的负数主元
2. 使用$\begin{pmatrix}1 & 0 \\ 1 & 1\end{pmatrix}$和$\begin{pmatrix}1 & 1 \\ 0 & 1\end{pmatrix}$构造出$\begin{pmatrix}3 & 4\\5 & 7\end{pmatrix}$
	>这道题的补充背景 对于整数矩阵$\begin{pmatrix}a & b \\ c & d\end{pmatrix}$, $ad-bc=1$, 才可以进行这样的分解
	>联系知识: 矩阵相乘, 其 $\det$ 乘之后, 一如一定条件下的矩阵相乘: $|A||B|=|AB|$ 

### 双增广矩阵

$$
\begin{pmatrix}
1 & 4 \\
2 & 7
\end{pmatrix}\begin{pmatrix}
x \\ y
\end{pmatrix}=\begin{pmatrix}
1 \\0
\end{pmatrix} \text{ 以及 } \begin{pmatrix}
1 & 4 \\
2 & 7
\end{pmatrix}\begin{pmatrix}
u \\ v
\end{pmatrix}=\begin{pmatrix}
0 \\ 1
\end{pmatrix}
$$
要想同时解出, 构造$\begin{pmatrix}A &b_{1} & b_{2}\end{pmatrix}$ 即可

### Pascal 矩阵

将 帕斯卡三角形 / 杨辉三角 作为其元素的 下三角矩阵