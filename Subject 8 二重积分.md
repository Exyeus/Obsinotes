### 定义
$$
\lim_{ \Delta A_{i} \to 0 } \sum f(x_{i},y_{i}) \Delta A_{i}\implies \iint_{R}f(x,y)dA
$$
定义罢了，真正计算的时候，大多数情况下并不会用这样的 *难以刻画* 的基底面积来计算。

### 计算

这样的求解，可以通过使用合适的切分方法，转化成为求解两次单变量积分的问题。
1. **直角坐标系下的求解。** 设想，沿着 $x$ 轴作一系列的切分平面，对于每个平面中这一体积的积分，再对 $x$ 积分就能得到最终体积
而对于所有的切面，则是 *以x为常量，y为变量*，对 $y$ 进行积分。而 $y$ 的上下限，不一定固定，例如基底是一个圆的时候。
这个时候，可以考虑将 $y$ 表示为关于 $x$ 的函数，这样可以将其表出并且限制变量的个数利于问题的求解。
综上：
$$
\int_{x_{min}}^{x_{max}} \left[  \int_{y_{min}(x)}^{y_{max}(x)}f(x,y)dy \right]dx
$$
**案例。** 求解 $z=1-x^2-y^2$在第一象限内，位于 $xOy$ 平面上方的体积。
列式：
$$
\int_{0}^{1}\left[ \int_{0}^{\sqrt{ 1-x^2 }}1-x^2-y^2dy \right]dx
$$
$$
\int_{0}^1 \left[ (1-x^2)y-\frac{1}{3}y^3 \right]_{0}^{\sqrt{ 1-x^2 }}dx
$$
$$
\frac{2}{3}\int_{0}^1 (1-x^2)\sqrt{ 1-x^2 } dx=\frac{\pi}{8}
$$

2. **极坐标下的求解。** 完成替换：$z=1-x^2-y^2\to z=1-r^2$，然后，在极坐标网格之中进行切分。
对于每一个小曲边梯形，可将其化为 $(r\times d\theta) \times dr$，对应的就是近似所得长方形的两条边。于是，我们得到：
$$
\int_{0}^{\pi/2} \left[ \int_{0}^1 (1-r^2) rdr \right]d\theta=\int_{0}^{\pi/2} \left( \frac{1}{2}r^2-\frac{1}{4}r^4 \right)_{0}^{1}d\theta=\int_{0}^{\pi/2} \frac{1}{8}d\theta=\frac{1}{8} \pi
$$

>回顾一下极坐标之中的替换： $x=r\cos \theta$， $y=r\sin \theta$ ， $x^2+y^{2}=r^{2}$。
>这里下标和上标分别为0和1，是因为这个图像十分简单。 
>如果是一个二元函数，积分区间之内，有的图像在 $xOy$ 之上，有的在 $xOy$ 之下，那么类比有向面积，整体将会抵消。

1. **平面面积的计算。** 计算 $x+y=1$ 和 $x^{2}+y^{2}=1$ 在第一象限内夹的弓形的面积。
分别对 $x$ 和 $y$ 积分，就当是高度为1的前面提及的案例：
$$
\int_{0}^1\int_{1-x}^{\sqrt{ 1-x^2 }}\left[f(x,y) == 1 \right]dydx=\int_{0}^{1}(\sqrt{ 1-x^2 }-(1-x))dx
$$
不算了，结合几何意义可以验算。

### 其他案例

#### 转动惯量

#### 质量计算

### 变量的替换

为什么要进行替换？为了使得函数更加好积分。上面直角坐标系化为极坐标系就是一个案例。
#### 线性替换
案例：
$$
\begin{pmatrix}
u \\
v
\end{pmatrix}=\begin{pmatrix}
3 & -2 \\
1 & 1
\end{pmatrix}\begin{pmatrix}
x \\
y
\end{pmatrix}\implies \begin{cases}
u=3x-2y \\
 \\
v=x+y
\end{cases}
$$
由此，用一个概念： *Jacobian Determinant* 来描绘这样的变换的效果：
$$
Jacobian Det=\begin{vmatrix}
u_{x} & u_{y} \\
v_{x} & v_{y}
\end{vmatrix}=\frac{\partial(u,v)}{\partial (x,y)}\implies dudv=\begin{vmatrix}
J
\end{vmatrix}dxdy
$$
反之，根据行列式性质，可以得到这个 Jacobian Matrix 的逆矩阵。

#### 非线性替换
$$
\int_{0}^{1}\int_{0}^{1}x^2ydxdy\implies \begin{cases}
u=x \\
 \\
v=xy
\end{cases}\implies |J|=\begin{vmatrix}
1 & 0 \\
y & x
\end{vmatrix}
$$
$$
\implies dudv=xdxdy\implies\iint_{?}x^2y \cdot \frac{1}{x} dudv
$$
$$
\implies \iint_{?}xydudv\implies \iint_{?} vdudv
$$
现在需要确定这个二重积分怎么拆分成两个一元积分然后计算。最终结果是：
$$\int_{0}^{1}\int_{v}^{1}vdudv$$
联系上面，分析二重积分的基本式子是：
$$
\int_{x_{min}}^{x_{max}} \left[  \int_{y_{min}(x)}^{y_{max}(x)}f(x,y)dy \right]dx
$$
务必把握住上下限是*一个变量关于另一个变量的函数的事实*，这里就涉及到最值的求解。
首先外层对于 $v$ 而言，它的范围是没有争议的 $[0,1]$ ，对于内层，在已知 $v$ 的前提下，如何求得 $u$ 的最小值，以得到下限？
$$
\begin{cases}
u =x \\
 \\
v=xy \\
 \\
y\to [0,1]
\end{cases}\implies u=\frac{v}{y}
$$
由此可知， $y=1$的时候，对应的 $u$ 有最小值，它的数值是 $v$ 。







