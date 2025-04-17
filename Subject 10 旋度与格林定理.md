### 二维旋度

定义：
$$
\mathbf{F}=\left \langle M,N \right \rangle\implies curl(\mathbf{F})=N_{x}-M_{y}
$$
注意，$\mathbf{F}$是一个向量，而$curl(\mathbf{F})$是一个数值。
这个数值 __刻画、量化__ 了场中流体、粒子的旋转效应。 $N_{x}-M_{y}$ 显示了旋转之感。?

### 格林定理

$$
\begin{array}
\\ 1.C是一个简单闭合曲线 \\
2.R是C的内部面积 \\ 
3.C必须满足右手角速度向上 \\
*简单：不会自交 \\
\end{array}\implies \oint_{C}Mdx+Ndy=\iint_{R}N_{x}-M_{y}dA
$$

#### 证明——*Green's Theorem*
构造 *简单垂直* ，以简化复杂的图形。事实上，总可以通过划分，将图形划分为垂直方向上不多重交叠的图形。 *但是仍然要重点考虑嵌入的情况*！
考虑由 $x=a$，$x=b$，$f_{1}(x)$，$f_{2}(x)$ 围成的图形，以及 $\overrightarrow{F}=\left \langle M(x,y),N(x,y) \right \rangle$。
*LHS*：
$$
\oint_{C}M(x,f_{1}(x))dx+N(x,f_{2}(x))df
$$
*RHS*：
$$
\iint_{R}N(x,f_{2}(x))_{x}-M(x,f_{1}(x))dydx\implies \int_{a}^{b}\int_{f_{1}(x)}^{f_{2}(x)}
$$
*上面的操作似乎行不通*。事实上，类比之前高中的一道吓人的解析几何试题，考虑分拆。
$$
\oint Mdx=\iint-M_{y}dA \text{ , } \oint Ndy=\iint N_{x}dA
$$
如此一来，事实上可以证明，这里先证明一边，另一半由对称性易得。沿用刚才证明之中的构造。
首先对于 $\oint Mdx$，可以将其分为 4 个部分：$x=a,x=b,c_{1}=f_{1}(x),c_{2}=f_{2}(x)$，其中，两条垂直线段意味着 $dx=0$，于是只需要考虑另外两条。
$$
\oint_{C}Mdx=\int_{a}^{b}M(x,f_{1}(x))dx+\int_{b}^{a}M(x,f_{2}(x))dx
$$
进一步化为：
$$
\oint_{C}Mdx=\int_{a}^{b}M(x,f_{1}(x))dx-\int_{a}^{b}M(x,f_{2}(x))dx
$$
而对于右侧：
$$
\iint_{R}-M_{y}dA=-\int_{a}^{b}\int_{f_{1}(x)}^{f_{2}(x)} \frac{\partial M}{\partial y}dydx=-\int_{a}^{b} [M(x_{2},f_{2}(x))-M(x,f_{1}(x))]
$$
>有一个问题：$\partial M / \partial y \cdot dydx$ 的化简规则是怎样的？
