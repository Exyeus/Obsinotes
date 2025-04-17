> $\det I=1$
> Sign reverses with ROW EXCHANGE
> Deter is linear in rach row separately, Making it practical to separate the DETER by a certain LINE/COLUMN
## 行列式A的公式
$$\begin{vmatrix}
a & b \\
c & d
\end{vmatrix}=\begin{vmatrix}
a & 0 \\
c & d
\end{vmatrix}+\begin{vmatrix}
0 & b \\
c & d
\end{vmatrix}=\begin{vmatrix}
a & 0 \\
c & 0
\end{vmatrix}+\begin{vmatrix}
a & 0 \\
0 & d
\end{vmatrix}+\dots+$$
新的理解：每行每列都要有元素，否则就会是singular matrix，直接变成0！
>确定符号
>低阶，考察将其变成顺序排列所需的操作次数，注意，可以跨元素交换！6
>高阶，考虑大量有规律的排序的逆序数的计算，判定奇排列和偶排列
## 余子式公式
## 三对角线矩阵