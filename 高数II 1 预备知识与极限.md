---
sr-due: 2025-08-21
sr-interval: 133
sr-ease: 310
---

#review 
### 多元函数

都是多个变量到实数集的映射。其中一元函数有从 X 轴 到 Y 轴的直观展示，二元函数有从 $xOy$ 到 $z$ 的直观展示。

*$R^n$ 到 $R^{m}$ 的映射。* 
- 从 $R^{2}$ 到 $R^{2}$ ：参数方程 $$\begin{cases}
x=\phi(t) \\
 \\
y=\theta(t)
\end{cases} $$
普遍来说，只要*构造 $m$ 个有序的 $n$ 元函数* 就可以实现 $R^{n}\to R^{m}$ 的转变。[[高数II 5 复合函数与隐函数微分]]，考虑分叉等计算方式。

*距离*。考虑 1D 情况下的 $|x_{1}-x_{0}|$ 到二维的 $\sqrt{ (x_{1}-x_{0})^2+(x_{2}-x_{0})^{2} }$，自然可以得到 $R^{n}$ 下的距离：$\sqrt{ \sum(x_{i}-x_{0})^2 }$。它满足三条性质：
- 大于零；
- $P\to Q=Q\to P$
- $d(P,Q)\leq d(P,R)+d(R,Q)$
*邻域*。定义如下：记住这个符号！$U_{r}(P oi nt)$
$$
U_{r}(P_{0})=\{ P \in R^{n}|d(P_{0},P)<r \}
$$
*一系列定义*。
- 内点：邻域所有点都在集合之中。
- 外点：邻域所有点都不在集合中。

- 边界点：有的在有的不在。
- 边界：$\partial E$，是为 E 的边界。如同一个属性。

- 开集：所有点都是内点。
- 闭集：包括它的所有边界点。

- 连通：顾名思义。
- 区域：$R^n$ 之中，连通的非空开集。
- 闭区域：对于一个区域，考虑它是开集，那么进一步加入边界：$E \cup \partial E$，得到闭区域
- 有界集合：集合可以被一个 *以原点为中心*，半径为 $\rho$ 的球完全包裹起来。
脑补模型：$-a<x<a$ 和 $-b<y<b$ 限定的长方形与 $-a\leq x\leq a$与$-b\leq y\leq b$限定的长方形。
*内点*，无需多言。*外点*，$x$ 和 $y$ 大于 a b 的边界。*边界点*：长方形的框架，于两者而言都是边界点。

### 多元函数极限

定义：
$$
对于任意 \epsilon>0，都存在\delta >0，使得\sqrt{ (x-x_{0})^{2}+(y-y_{0})^{2} }<\delta之时，有|f(x,y)-A|<\epsilon
$$
$$
那么有\lim_{ \begin{array}
\\x\to x_{0} \\
y\to y_{0}
\end{array} } f(x,y)=A
$$
其中，$\sqrt{ (x-x_{0})^{2}+(y-y_{0})^{2} }<\delta$还可以写成 $|x-x_{0}|<\delta\text{ , }|y-y_{0}|<\delta$，二者的等价性，通过互相内部构造更小的形状来证明。

*证明极限不存在*。可以使用 $y=kx$ 来进行替换。其背后的思想一如偏导数的来源——在一个平行于 $z$ 轴的平面内进行操作。