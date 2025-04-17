[[Class 22 Eigen Diagonalization Power of Matrices]]
嗯，好，我现在要用对角化的方法来将一个二次型化为标准型。老师让我自己想一个例题，然后详细讲解每一步骤。好，先想一个二次型吧。嗯，就拿这个二次型：

$Q(x) = 2x_1^2 + 3x_2^2 + 4x_3^2 + 2x_1x_2 + 2x_1x_3 + 2x_2x_3$

好，这个看起来有点复杂，应该需要用矩阵来表示一下。首先，我得把这个二次型写成矩阵的形式。二次型的一般形式是：

$Q(x) = x^T A x$

其中，$A$ 是对称矩阵。那我来写出矩阵 $A$ 吧：

$$A = \begin{pmatrix}
2 & 1 & 1 \\
1 & 3 & 1 \\
1 & 1 & 4 \\
\end{pmatrix}$$

嗯，这样写应该没错吧？接下来，我需要对这个矩阵进行对角化，也就是找到一个正交矩阵 $P$，使得：

$P^T A P = D$

其中，$D$ 是一个对角矩阵，里面的对角元素就是 $A$ 的特征值。好了，首先我要找到 $A$ 的特征值。特征值的计算需要解特征方程：

$\det(A - \lambda I) = 0$

所以，我先写出 $A - \lambda I$：

$$A - \lambda I = \begin{pmatrix}
2 - \lambda & 1 & 1 \\
1 & 3 - \lambda & 1 \\
1 & 1 & 4 - \lambda \\
\end{pmatrix}$$

然后计算行列式：

$\det(A - \lambda I) = (2 - \lambda)\left[(3 - \lambda)(4 - \lambda) - 1 \cdot 1\right] - 1\left[1 \cdot (4 - \lambda) - 1 \cdot 1\right] + 1\left[1 \cdot 1 - (3 - \lambda) \cdot 1\right]$

我开始计算每一部分：

首先计算第一个大括号里的：

$(3 - \lambda)(4 - \lambda) - 1 = (12 - 3\lambda - 4\lambda + \lambda^2) - 1 = \lambda^2 - 7\lambda + 11$

然后是第二个部分：

$1 \cdot (4 - \lambda) - 1 \cdot 1 = 4 - \lambda - 1 = 3 - \lambda$

最后是第三个部分：

$1 \cdot 1 - (3 - \lambda) \cdot 1 = 1 - 3 + \lambda = \lambda - 2$

把这些代回行列式的表达式：

$\det(A - \lambda I) = (2 - \lambda)(\lambda^2 - 7\lambda + 11) - 1(3 - \lambda) + 1(\lambda - 2)$

继续展开：

$= (2 - \lambda)(\lambda^2 - 7\lambda + 11) - (3 - \lambda) + (\lambda - 2)$

先计算第一个乘积：

$(2 - \lambda)(\lambda^2 - 7\lambda + 11) = 2\lambda^2 - 14\lambda + 22 - \lambda^3 + 7\lambda^2 - 11\lambda = -\lambda^3 + 9\lambda^2 - 25\lambda + 22$

然后剩下的部分：

$- (3 - \lambda) + (\lambda - 2) = -3 + \lambda + \lambda - 2 = 2\lambda - 5$

所以，整个行列式为：

$-\lambda^3 + 9\lambda^2 - 25\lambda + 22 + 2\lambda - 5 = -\lambda^3 + 9\lambda^2 - 23\lambda + 17$

于是，特征方程是：

$-\lambda^3 + 9\lambda^2 - 23\lambda + 17 = 0$

嗯，这个三次方程看起来有点麻烦。或许我可以试试有理根定理，看看有没有简单的根。可能的有理根是因数17的因数除以首项系数的因数，也就是±1, ±17。试试 $\lambda = 1$：

$-1 + 9 - 23 + 17 = 2 \neq 0$

不行，再试 $\lambda = 2$：

$-8 + 36 - 46 + 17 = -1 \neq 0$

再试 $\lambda = 3$：

$-27 + 81 - 69 + 17 = 2 \neq 0$

再试 $\lambda = 4$：

$-64 + 144 - 92 + 17 = 5 \neq 0$

Hmm，好像没有简单的整数根。或许我需要用其他方法，比如求导数或者使用数值方法。不过，这里可能出错了，我再检查一下我的计算。

回头看刚才的行列式计算，发现好像在展开的时候漏掉了一些项。让我重新计算一下行列式：

$\det(A - \lambda I) = (2 - \lambda)[(3 - \lambda)(4 - \lambda) - 1] - 1[1(4 - \lambda) - 1] + 1[1 - (3 - \lambda)]$

$= (2 - \lambda)(\lambda^2 - 7\lambda + 11) - (3 - \lambda) + (\lambda - 2)$

$= (2)(\lambda^2 - 7\lambda + 11) - \lambda(\lambda^2 - 7\lambda + 11) - 3 + \lambda + \lambda - 2$

$= 2\lambda^2 - 14\lambda + 22 - \lambda^3 + 7\lambda^2 - 11\lambda - 3 + 2\lambda - 2$

$= -\lambda^3 + 9\lambda^2 - 23\lambda + 17$

嗯，看来计算是对的。那么可能我的有理根假设有问题。也许这个多项式其实没有简单的有理根，需要用其他方法求解。或者，我是不是应该换一个二次型，这样计算起来更简单？

算了，这个例子可能有点复杂，我换个简单的。比如：

$Q(x) = x_1^2 + 2x_1x_2 + x_2^2$

好，这个看起来应该比较简单。让我再来试一次。

矩阵 $A$ 就是：

$$A = \begin{pmatrix}
1 & 1 \\
1 & 1 \\
\end{pmatrix}$$

嗯，这个应该容易求特征值。特征方程是：

$$\det(A - \lambda I) = \det\begin{pmatrix}
1 - \lambda & 1 \\
1 & 1 - \lambda \\
\end{pmatrix} = (1 - \lambda)^2 - 1 = \lambda^2 - 2\lambda$$

所以，

$\lambda(\lambda - 2) = 0$

特征值是 $\lambda = 0$ 和 $\lambda = 2$。

好，现在找到特征值了，接下来要找对应的特征向量。

对于 $\lambda = 0$：

$(A - 0I)x = A x = 0$

也就是：

$$\begin{pmatrix}
1 & 1 \\
1 & 1 \\
\end{pmatrix} \begin{pmatrix}
x_1 \\
x_2 \\
\end{pmatrix} = \begin{pmatrix}
0 \\
0 \\
\end{pmatrix}$$

这给出了方程：

$x_1 + x_2 = 0$

所以，特征向量可以取 $x = \begin{pmatrix} 1 \\ -1 \end{pmatrix}$

对于 $\lambda = 2$：

$$(A - 2I)x = \begin{pmatrix}
-1 & 1 \\
1 & -1 \\
\end{pmatrix} \begin{pmatrix}
x_1 \\
x_2 \\
\end{pmatrix} = \begin{pmatrix}
0 \\
0 \\
\end{pmatrix}$$

这给出了方程：

$-x_1 + x_2 = 0$

所以，特征向量可以取 $x = \begin{pmatrix} 1 \\ 1 \end{pmatrix}$

好，现在我有了特征值和特征向量，可以构造正交矩阵 $P$。不过，这两个特征向量 $\begin{pmatrix} 1 \\ -1 \end{pmatrix}$ 和 $\begin{pmatrix} 1 \\ 1 \end{pmatrix}$ 需要标准化。

标准化第一个向量：

$\|v_1\| = \sqrt{1^2 + (-1)^2} = \sqrt{2}$

所以，标准化后的 $v_1 = \frac{1}{\sqrt{2}} \begin{pmatrix} 1 \\ -1 \end{pmatrix}$

标准化第二个向量：

$\|v_2\| = \sqrt{1^2 + 1^2} = \sqrt{2}$

所以，标准化后的 $v_2 = \frac{1}{\sqrt{2}} \begin{pmatrix} 1 \\ 1 \end{pmatrix}$

于是，正交矩阵 $P$ 是：

$$P = \begin{pmatrix}
\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\
-\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\
\end{pmatrix}$$

现在，我来验证一下 $P^T A P = D$ 是否成立。

首先计算 $P^T A$：

$$P^T A = \begin{pmatrix}
\frac{1}{\sqrt{2}} & -\frac{1}{\sqrt{2}} \\
\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\
\end{pmatrix} \begin{pmatrix}
1 & 1 \\
1 & 1 \\
\end{pmatrix} = \begin{pmatrix}
\frac{1}{\sqrt{2}} \cdot 1 + (-\frac{1}{\sqrt{2}}) \cdot 1 & \frac{1}{\sqrt{2}} \cdot 1 + (-\frac{1}{\sqrt{2}}) \cdot 1 \\
\frac{1}{\sqrt{2}} \cdot 1 + \frac{1}{\sqrt{2}} \cdot 1 & \frac{1}{\sqrt{2}} \cdot 1 + \frac{1}{\sqrt{2}} \cdot 1 \\
\end{pmatrix} = \begin{pmatrix}
0 & 0 \\
\sqrt{2} & \sqrt{2} \\
\end{pmatrix}$$

然后计算 $P^T A P$：

$$P^T A P = \begin{pmatrix}
0 & 0 \\
\sqrt{2} & \sqrt{2} \\
\end{pmatrix} \begin{pmatrix}
\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\
-\frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}} \\
\end{pmatrix} = \begin{pmatrix}
0 \cdot \frac{1}{\sqrt{2}} + 0 \cdot (-\frac{1}{\sqrt{2}}) & 0 \cdot \frac{1}{\sqrt{2}} + 0 \cdot \frac{1}{\sqrt{2}} \\
\sqrt{2} \cdot \frac{1}{\sqrt{2}} + \sqrt{2} \cdot (-\frac{1}{\sqrt{2}}) & \sqrt{2} \cdot \frac{1}{\sqrt{2}} + \sqrt{2} \cdot \frac{1}{\sqrt{2}} \\
\end{pmatrix} = \begin{pmatrix}
0 & 0 \\
0 & 2 \\
\end{pmatrix}$$

嗯，得到了对角矩阵 $D = \begin{pmatrix} 0 & 0 \\ 0 & 2 \end{pmatrix}$，这和我之前的特征值 $0$ 和 $2$ 一致。看来是对的。

所以，最终，我把二次型 $Q(x) = x_1^2 + 2x_1x_2 + x_2^2$ 化为标准型：

$Q(x) = 0 \cdot y_1^2 + 2 \cdot y_2^2 = 2y_2^2$

其中，$y = P^T x$，也就是：

$y_1 = \frac{1}{\sqrt{2}}x_1 - \frac{1}{\sqrt{2}}x_2$
$y_2 = \frac{1}{\sqrt{2}}x_1 + \frac{1}{\sqrt{2}}x_2$

所以，标准型是：

$Q(x) = \boxed{2y_2^2}$

这个过程虽然有点复杂，但最终成功把二次型化为了标准型。
