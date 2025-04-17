- 为什么投影？
	- 用于求解无解的$Ax=b$。列空间中最合适的向量p，十分接近b且处于A的列空间之中。
- $A=\begin{pmatrix}a_{1} & a_{2}\end{pmatrix},p(projection)=A\hat{x}$，我们需要找到这个$\hat{x}$来使得误差向量 $|\vec{b}-\vec{p}|$ 最小，也就是垂直之时！
	- 更进一步，$\vec{e}=A\hat{x}-b$，其必然垂直于列空间中的两个基向量$\vec{a_{1}},\vec{a_{2}}$！
	- 更进一步，写出两个方程：$a_{1}^T(b-A\hat{x})=0, a_{2}^T(b-A\hat{x})=0$，并且思考如何将这两个方程（以及在处理更高阶矩阵的更多方程的情况下，将它们归并为一个矩阵！）
	- 在这一步之中，将包含$a_{1}^Ta_{2}^T$的矩阵还原成为$A^T$ $$\begin{pmatrix}
a_{1}^T \\
a_{2}^T
\end{pmatrix}\cdot(b-A\hat{x})=\begin{pmatrix}
0 \\
0
\end{pmatrix},A^T(b-A\hat{x})=0$$
	- $e/b-A\hat{x}$处于$N(A^T)$之中！$e \perp C(A)$！
	- $A^Te=A^T(b-A\hat{x})=0\implies A^TA\hat{x}=A^Tb$
- Summary
	- $\hat{x}=(A^TA)^{-1}A^Tb$
	- $projection::p=A\hat{x}=A(A^TA)^{-1}A^Tb$
		Not a bad and complex formula, instead its the LEAST 这就是好的矩阵，不一定能化简，因为$A$不一定可逆
	- What is the matrix that leads to the projection?
		$P=A(A^TA)^{-1}A^T?=AA^{-1}(A^T)^{-1}A^T$ Operation Not <font color="#b228e6">AWALYS</font> Allowed Due to the possibility that A is not invertible.
		(Holding not full RANK, or not a SQUARE)<font color="#b228e6"> 不满秩或者不是一个方阵，这里就不能这样操作！</font>$\exists(AA^T)^{-1}NOT\implies \exists A^{-1}$
		But if in the case of the holistic space, that would be the UNIT Matrix $I\implies P=I$.
		If it is in the case of just ONE DIMENSION, that would be just reduced to a number, making $\frac{aa^T}{a^Ta}$ 这个是在维度为1的时候的特例
		REMEMBER: The projection matrices must have the following 2 properties: $P^T=P;;P^N=P$ 投影矩阵直观上来看，必须具备的性质！
		
- LEAST SQUARE
	$$\begin{pmatrix}
1&1 \\
1&2 \\
1&3
\end{pmatrix}\begin{pmatrix}
C \\
D
\end{pmatrix}=\begin{pmatrix}
1 \\
2 \\
2
\end{pmatrix}, \implies Ax=b$$
	A most intutive example! Showing the basic principles behind LEAST SQUARE APPROXIMATION!