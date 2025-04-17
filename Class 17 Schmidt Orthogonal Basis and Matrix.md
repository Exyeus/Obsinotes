### Orthogonal Ones
各种垂直与正交，撑起来得到0
### 标准正交基如何对情况进行优化？
#### Gram & Schmidt
标准正交列的作用：$$Q=\begin{pmatrix}
q_{1}&\dots&q_{N}
\end{pmatrix}\implies Q^TQ=\begin{pmatrix}
q_{1}^T \\
\dots \\
q_{N}^T
\end{pmatrix}\begin{pmatrix}
q_{1}&\dots&q_{N}
\end{pmatrix}=I_{N}$$
>REVIEW
>三角矩阵 对角矩阵 置换矩阵 行阶梯矩阵 投影矩阵 标准正交矩阵 $Q$

如果有着标准正交列的矩阵还是方阵，那么可以有
$$\begin{matrix}
Q^TQ=I \\
\exists Q^{-1}
\end{matrix}\implies Q^T=Q^{-1}$$
联系$$\text{Permutation Matrix} \to P=\begin{pmatrix}
0 & 0 & 1 \\
1 & 0 & 0 \\
0 & 1 & 0
\end{pmatrix}\implies P\cdot P^T=I$$
$$Q=\begin{pmatrix}
\cos x & -\sin x \\
\sin x & \cos x
\end{pmatrix}\implies Q'=\frac{1}{\sqrt{ 2 }}\begin{pmatrix}
1 & 1 \\
1 & -1
\end{pmatrix}||Q''=\frac{1}{2}\begin{pmatrix}
1&1&1&1 \\
1&-1&1&-1 \\
1&1&-1&-1 \\
1&-1&-1&1
\end{pmatrix}(阿德玛)$$
正交阵由三角函数、正负1构成

>更高维数的阿德玛矩阵是否存在？如何求解？用处就是证明，有`-1` `1`形成的矩阵能够形成正交矩阵，具体参考阿德玛矩阵。
>总结：所有的列都相互垂直，它们的点积是0，同时，它们线性无关，构成一组正交基！同时，这些向量都必须是单位向量，所以还要除以它们的长度，并且每个列向量的模应当相同！
>Q has orthonormal columns.

所有的方程经过标准正交化都会变得更为简单。$Q^TQ$就是张成整个空间的投影矩阵！
$$A^TA\hat{x}=A^Tb\implies with::A\to Q\implies \hat{x}=Q^Tb\implies \hat{x}_{i}=q_{i}^Tb$$
>最后一式子：在第i列上的投影由此求得！

### Gram-Schmidt
$$基于几何直观的向量分解并且假设A的方向就是一个正交基向量的方向::B=b-\frac{A^Tb}{A^TA}A\implies A^TB=A^T\left( b-\frac{A^Tb}{A^TA} A\right)$$
再来一个向量$$c=C-\frac{A^TC}{A^TA}-\frac{B^TC}{B^TB}B\implies \begin{matrix}
c \perp B \\
c \perp A
\end{matrix}$$
>大小写标志着是原来的向量还是一个分量，并不是矩阵，不然无法进行除法！

一个实例：
$$a=\begin{pmatrix}
1 \\
1 \\
1
\end{pmatrix},b=\begin{pmatrix}
1 \\
0 \\
2
\end{pmatrix},B=a-\frac{A^Tb}{A^TA}A\implies B=\begin{pmatrix}
0 \\
-1 \\
1
\end{pmatrix}\implies Q=\begin{pmatrix}
a' &b'
\end{pmatrix}\to单位矩阵化\to \begin{pmatrix}
\frac{1}{\sqrt{ 3 }}&0 \\
\frac{1}{\sqrt{ 3 }} & -\frac{1}{\sqrt{ 2 }} \\
\frac{1}{\sqrt{3 }} & -\frac{1}{\sqrt{ 2 }}
\end{pmatrix}$$
注意，这里每一列都通过除以常数得到了单位矩阵
