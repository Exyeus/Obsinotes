- 投影矩阵$Pb$，将b投影到距离其最近的列空间。
	- 已经在列空间中，投影得到b自己
	- 垂直于列空间，投影得到焦点
- 垂直于A的列空间的向量：处在$N(A^T)$之中的向量。
- ![[Class 15 Subspace Projection]]
- 列空间所有向量组合的表示$Ax$，b处在列空间之中，那么就有$b=Ax$
- $C(A) \perp N(A^T), ,b \to N(A^T)\implies e,,b\to C(A)\implies p,, \vec{e}+\vec{p}=b!$
- $Pb=p,,(I-P)b=e,,\vec{p}+\vec{e}=Ib=b$，$I-P$享有与$P$相同的投影矩阵的性质：乘之不变，P对称则I亦对称，因为本来就都是对称矩阵！
- 承接上面插入笔记之中的方程，引入最小二乘估计
	- 最小二乘，就是最小平方和；
	- $e=Ax-b$，量化起来就是要让 $\lvert e \rvert$ 最小！
	- 线性回归分析（Linear Regression）
		- 离群值 outlier，导致最小二乘估计的精确度降低！
	- 最重要之公式——统计学？
	- $$Find::\hat{x}=\begin{pmatrix}
\hat{C} \\
\hat{D}
\end{pmatrix},,P::using :: A^TA\hat{x}=A^Tb$$
- 误差和噪声（ERROR AND NOISE）最先使用之估计$$\begin{pmatrix}
1 & 1&1 \\
1&2 &3
\end{pmatrix}\cdot \begin{pmatrix}
1 & 1|1 \\
1 & 2|2 \\
1 & 3|2
\end{pmatrix}=\begin{pmatrix}
3 & 6|5 \\
6 & 14|11
\end{pmatrix}\implies \begin{matrix}
3C+6D=5 \\
6C+14D=11
\end{matrix}$$
使用增广矩阵，一步得到化简方程组，并且顺带解得 C D 之数值！
- 使用微积分办法：$f(C,D)=(C+D-1)^2+(C+2D-2)^2+(C+3D-2)^2$，然后对之求解偏导数拉格朗日乘数法、二元函数最值。
![[偏导数简单定义、应用示例及其理解]]
	- 可行性验证：二次函数求完偏导数之后，得到的东西也是一次的！直接就可以得到同样的两个方程！
- 分析最终结果：
	$$b=p+e=\begin{pmatrix}
\frac{7}{6} \\
\frac{10}{6} \\
\frac{13}{6}
\end{pmatrix}+\begin{pmatrix}
-\frac{1}{6} \\
\frac{2}{6} \\
-\frac{1}{6}
\end{pmatrix}\implies \begin{matrix}
\begin{pmatrix}
\frac{7}{6} \\
\frac{10}{6} \\
\frac{13}{6}
\end{pmatrix}+\begin{pmatrix}
-\frac{1}{6} \\
\frac{2}{6} \\
-\frac{1}{6}
\end{pmatrix}=\begin{pmatrix}
1 \\
2 \\
2
\end{pmatrix} \\
e\cdot \begin{pmatrix}
1 \\
2 \\
3
\end{pmatrix}=e\cdot \begin{pmatrix}
1 \\
1 \\
1
\end{pmatrix}=0
\end{matrix}$$
- SUMMARY 最小二乘法，主要用途就是做线性拟合，需要解这些方程$$\begin{matrix}
A^TA\hat{x}=A^Tb \\
P=A\hat{x}
\end{matrix}$$

