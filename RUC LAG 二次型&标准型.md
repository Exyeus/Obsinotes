二次型变换：
$$f(x_{i})=ax_{1}^2+bx_{2}^2+cx_{3}^2+dx_{1}x_{2}+ex_{2}x_{3}+fx_{1}x_{3}\implies(x_{1} x_{2}x_{3})\begin{pmatrix}
a & \frac{d}{2} & \frac{f}{2} \\
\frac{d}{2} & b & \frac{e}{2}  \\
\frac{f}{2} & \frac{e}{2} & c
\end{pmatrix}\begin{pmatrix}
x_{1} \\
x_{2} \\
x_{3}
\end{pmatrix}$$
$$
\begin{matrix}
x_{1}=c_{11}y_{1}+c_{12}y_{2}+\dots+c_{1n}y_{n} \\
\dots \\
\dots
\end{matrix}
$$称为由变量$x_{1},x_{2},x_{3},\dots,x_{n}$与$y_{1},y_{2},y_{3},\dots,y_{n}$得到的一个线性替换
其中，就有一个替换矩阵C，满足$$C=\begin{pmatrix}
c_{11}&c_{12}&\dots &c_{1n} \\
\dots \\
c_{n 1} & c_{n 2}&\dots&c_{nn}
\end{pmatrix},,X=CY$$
C满足以下等价的要求
- 非退化
- 满秩
- $\lvert C \rvert \neq 0$
- 非奇异
### 合同
$$
A;;B是两个N阶方阵，如有C，r(C)==N，B=C^TAC\implies AB合同
$$
### 变换合一
$$X^TAX\implies X_{1}^TC_{1}^TAC_{1}X_{1}\implies X_{2}^TC_{2}^TC_{1}^TAC_{1}C_{2}X_{2}\implies\dots\implies C^TAC$$
其中, $C=C_{1}C_{2}C_{3}\dots C_{s}$, 多次矩阵操作合而为一, 得到一个矩阵, 每次矩阵对应一次替换!
## 标准型
$$
\begin{matrix}
f(X)=X^TAX \\
X=CY \\
\end{matrix}\implies f(X)=d_{1}y_{1}^2+d_{2}y_{2}^2+\dots+d_{n}y_{n}^2
$$
这个只含有二次项的二次型为$f(X)=X^TAX$的标准型

### 转变方法
- 配方法
$$f(x_{1},x_{2},x_{3})=(x_{1}-x_{2}+x_{3})^2-(2x_{2}+x_{3})^2\implies \begin{matrix}
y_{1}=x_{1}-x_{2}+x_{3} \\
y_{2}=2x_{2}+x_{3} \\
y_{3}=x_{3}
\end{matrix}\implies \begin{matrix}
x_{1}=y_{1}+\frac{1}{2}y_{2}-\frac{3}{2}y_{3} \\
x_{2}=\frac{1}{2}(y_{2}-y_{3}) \\
x_{3}=y_{3}
\end{matrix}$$
$$
f=y_{1}^2-y_{2}^2
$$
注意，应当保有这些量，即使它们的系数是0.这里的矩阵：
$$
C=\begin{pmatrix}
1 & -1 & 1 \\
0 & 2&1 \\
0&0&1
\end{pmatrix}，显然\lvert C \rvert\neq 0 
$$把非零的项放在第一个位置
有平方，配方，减少一个
如果一开始就没有平方项，只出现了交叉项，不妨假设$a_{12}\neq 0$
进行代换:$$\begin{matrix}a_{1}x_{1}x_{2} \\
x_{1}=y_{1}+y_{2} \\
x_{2}=y_{1}-y_{2}\end{matrix}\implies a_{1}(y_{1}^2-y_{2}^2)$$
有很多的构造平方项的办法. 出现了平方项, 就可以归结为配方求解的问题.
任何线性的代换式子, 只要满足:
- 代入之后, 出现平方项,
- 并且是非退化矩阵
一个很牛逼的二次型的展开
$$
f(X)=A^TXA=A^T\sum_{j=1}^n \dots                                                                                                                                                                                                                                                                                                                    
$$
另一种情形: 没有平方项, $a_{ii}=0;;a_{ij}=0$,这是一个N-1元的二次型. 但是要注意, $x_{1}$的系数应当视为0, 而不是不存在$x_{1}$项, 此外, 替换的时候, 还需要有$x_{1}=y_{1}$, 来确保非退化, 上面也提到了这一点!

<font color="#b228e6">任意对称矩阵合同于对角型矩阵</font>

### 初等变换法
进行列变换
$$
f(x_{1},x_{2},x_{3})=4x_{1}x_{2}+2x_{1}x_{3}+2x_{2}x_{3},,A=\begin{pmatrix}
0 & 2 & 1 \\
2 & 0 & 1 \\
1 & 1 & 0
\end{pmatrix}
$$
$$
P=\begin{pmatrix}
A \\
E
\end{pmatrix}\to \begin{pmatrix}
D \\
C
\end{pmatrix},,D=\begin{pmatrix}
2 & 0 & 0 \\
0 & -\frac{9}{2} &0 \\
0 & 0 & -\frac{9}{4}
\end{pmatrix},,C=\begin{pmatrix}
1 & -1 & -\frac{7}{18} \\
0 & 1 & -\frac{19}{9} \\
0 & -\frac{3}{2} & -\frac{1}{3}
\end{pmatrix}\implies f(x_{1},x_{2},x_{3})=2y_{1}^2-\frac{9}{2}y_{2}^2-\frac{4}{9}y_{3}^2
$$

---

课程总结:
- 利用化归思想和递推方法
	- 对于平方项的配方处理, 已经可以达成
	- 于是, 对于没有平方项的, 通过一定的线性替换, 产生平方项, 然后按照上面的办法处理
	- 对于同样没有平方项, 并且$x_{1j}=0$, 也就是阶数少1, 那么就应当将其视作是系数为0, 且具有$x_{1}$之项, 根据之前已经通过递推解决了问题, 那么这里直接求解, 但是必须有$x_{1}=y_{1}$的替换, 来满足矩阵非退化的要求.
