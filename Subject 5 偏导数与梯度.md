---
sr-due: 2025-09-23
sr-interval: 167
sr-ease: 290
---

#review 
### 偏导数思想

取 平行于 $xOz$ $yOz$ 这两个平面，然后对其截得方程的曲线求切线。

### 三种符号表示

1. **表示偏导数相对于 $x$ 的偏导数**：
    - 符号：$\frac{\partial w}{\partial x}(x_0, y_0)$
2. **表示偏导数相对于 $y$ 的偏导数**：
    - 符号：$\frac{\partial w}{\partial y}(x_0, y_0)$
3. **使用更简洁的记法（莱布尼茨记法）**：
    - 相对于 $x$ 的偏导数：$\frac{\partial}{\partial x} w(x_0, y_0)$
    - 相对于 $y$ 的偏导数：$\frac{\partial}{\partial y} w(x_0, y_0)$
4. **点上偏导数的表示（特别强调在点 $(x_0, y_0)$ 处的值）**：
    - 对于 $x$ 的偏导数：$w_x(x_0, y_0)$
    - 对于 $y$ 的偏导数：$w_y(x_0, y_0)$

更加原始的表述：
$$\frac{d}{dx}f(x,y_{0})|_{x_{0}}\implies \frac{\partial f}{\partial x}|_{(x_{0},y_{0})}$$

### 应用示范

最小二乘法，近似方程的求解

$$
D=\sum_{i=1}^{n}(y_{i}-(ax_{i}+b))^2\implies \begin{cases}
\frac{\partial D}{\partial a}=0 \\
 \\
\frac{\partial D}{\partial b}=0
\end{cases}\implies 
$$
$$
\begin{cases}
\left( \sum x_{i}^{2} \right)a+\left( \sum x_{i} \right)b=\sum x_{i}y_{i} \\ \\
\left( \sum x_{i} \right)a+nb=\sum y_{i}
\end{cases}
$$
在此之后，切记，是将整个视为关于a和b的二元函数，然后求解到关于 a，b的二次方程。

### 二阶偏导数检验

$$使 \begin{cases}
A=(f_{x x})_{0} \\
 \\
B=(f_{xy})_{0} \\ \\
C=(f_{yy})_{0}
\end{cases}\implies \begin{cases}
AC-B^2>0  \begin{cases}
A > 0 \bigvee C>0 \implies极小值点 \\
 \\
A<0 \bigvee C<0 \implies 极大值点
\end{cases}
\\
 \\ 
AC -B^2<0\implies(x_{0},y_{0}) 是一个鞍点
\end{cases}$$
注意，这里因为 $AC-B^2>0\implies AC>0\implies AC具有相同正负性$

这个公式的根本在于，对于$f=ax^2+bxy+cy^2$，可以将其表成：
$$
f=\frac{1}{4a}\left( 4a^2\left( x+\frac{b}{2a}y \right)^2 +(4ac-b^2)y^2 \right)
$$
与此同时，对于这个$f$，可以求得，按照上面的 ABC 表示法，
$$
\begin{cases}
A=2a \\
 \\
B=b \\
 \\
C=2c
\end{cases}
$$
在这里，由于 $4a^ 2\geq0$，因此，$4ac-b^2$的正负性是否与之相同，就能够极大决定整个函数在二阶偏导数为0之时的情况！

特别注意，如果 $4ac-b^2==0$，那么这里只有一个二次变量，这个时候就会发生十分严重的衰减：无论是二元函数还是三元函数，其
$$
x+\frac{b}{2a}y=0
$$会在十分广大的区域之内成立，而在这个区域内，另一方由于也是0（系数是0），会造成十分广大且连续的最小值，因此无法求解最小值。

直观上，就是有一整条线贴在了 $xOy$ 平面之上。错误的，是一整排线！（发自我的电脑，2025年4月9日 16:49:02）

### 计算之案例

给定 $w=f(x,y)$，但是又想将其视为 $u \text{ , } v$ 表示的二元函数，即此时存在关系：
$$
\begin{cases}
x=x(u,v) \\
 \\
y=y(u,v)
\end{cases}
$$
具体可以参考，给定 $x$ $y$ 表示的直角坐标系方程，但是又希望用 $r$ $\theta$ 表示的极坐标方程来将其进一步表示。
此时，就要利用偏导，因为这即使*是参数方程，也是二元的*，不能如此前一般*一阵微分恒等*将其表示并且计算！
$$
\begin{array}
\\w=f(x,y) \\
x=x(u,v) \\
y=y(u,v)
\end{array}\implies dw=f_{x}dx+f_{y}dy=f_{x}(x_{u}du+x_{v}dv)+f_{y}(y_{u}du+y_{v}dv)
$$

$$
更进一步，\begin{array}
\\f_{x}x_{u}+f_{u}y_{u}=\frac{\partial f}{\partial u} \\
 \\
f_{x}x_{v}+f_{y}y_{v}=\frac{\partial f}{\partial v}
\end{array}\implies dw=\frac{\partial f}{\partial u}du+\frac{\partial f}{\partial v}dv
$$
对比已有：
$$
dw=\frac{\partial f}{\partial x}dx+\frac{\partial f}{\partial y}dy
$$
可见 $x\equiv u$，$y \equiv v$，只需做出替换。
[[二元函数微分的偏导公式解释证明]]
### 公式的基础：多元函数的泰勒展开

对于二元函数：==有问题吧==
$$
\Delta f \approx f_{x}(x-x_{0})+f_{y}(y-y_{0})+\frac{f_{x x}}{2}(x-x_{0})^2+f_{yy}(y-y_{0})^2+\frac{f_{xy}}{2}(x-x_{0})(y-y_{0})
$$
$$
\Delta f \approx f_{x}(x-x_{0})+f_{y}(y-y_{0})+\frac{f_{x x}}{2}(x-x_{0})^2+\frac{1}{2}f_{yy}(y-y_{0})^2+f_{xy}(x-x_{0})(y-y_{0})
$$
在 $\Delta$ 之所得十分之小的时候，就会变成 $d$ 之
## 梯度向量

对于三元函数：
$$
\nabla f=
\left\langle  \frac{\partial f}{\partial x},
\frac{\partial f}{\partial y},
\frac{\partial f}{\partial z}
\right\rangle
$$
称为其梯度。

### 性质：

**梯度向量，垂直于水平曲线以及表面**
注意, 垂直的是曲线还是曲面, 要看其原函数的自变量个数. 二元函数会得到曲线, 而三元函数会得到曲面.

**对于 Surface 的情形, 所有这个曲面上的曲线的, 在这一点的切线, 都与梯度向量垂直.**

$$
\begin{array} \\
\mathbf{r}(t)=\left \langle x(t),y(t),z(t)\right \rangle \\
 \\
g(t)=f(x(t),y(t),z(t))=0
\end{array}\implies \frac{dg}{dt}=\frac{\partial f}{\partial x}|_{P} \cdot\frac{dx}{dt}|_{t_{0}}+\frac{\partial f}{\partial y}|_{P} \cdot\frac{dy}{dt}|_{t_{0}}+\frac{\partial f}{\partial z}|_{P} \cdot \frac{dz}{dt}|_{t_{0}}=0
$$
$$
\implies \left \langle  
\frac{\partial f}{\partial x}|_{P},
\frac{\partial f}{\partial y}|_{P},
\frac{\partial f}{\partial z}|_{P}
\right \rangle \cdot
\left \langle 
\frac{dx}{dt} |_{t_{0}}
\frac{dy}{dt} |_{t_{0}}
\frac{dz}{dt} |_{t_{0}}
\right \rangle =0
$$
$$
\implies \nabla f|_{P} \text{ } \cdot \text{ } \mathbf{r}'(t_{0})=0\implies \nabla f|_{P}\perp \mathbf{r}'(t_{0})
$$
### 任意切向量:

$$
\frac{dw}{ds}=\frac{(x'(t),y'(t),z'(t))}{\sqrt{ x'(t)^2+y'(t)^2 +z'(t)^2}}=\hat{u}
$$
其中, s 是一个在二元函数之下, 在 $xOy$ 平面之内的一个方向的向量.
进一步, 我们使用
$$
\frac{dw}{ds}/_{\hat{u}}=\nabla w \cdot \hat{u}
$$
来表示在各个方向上的切向量.
事实上, 这里
- 还应当有一个单位向量来描述方向, 但是这里需要的只是导数的数值.
- 核心的思想, 仍然是一个垂直于 $xOy$ 平面的平面, 去截取这个函数.
	- 这个平面与 $xOy$ 相交所得, 便是我们用作相乘的向量
	- 在 $\hat{i}$ 方向相乘, 就能得到在 x 方向的偏导数*数值*.
	- 最后能够得到的也只是数值了！正常的思路，应当是取一个 $(\cos \theta,\sin \theta)$ 的在 $xOy$ 平面之内的方向向量，然后考虑过这个方向向量，平行于 z 轴的平面，这个平面上对 函数 求取偏导数。
