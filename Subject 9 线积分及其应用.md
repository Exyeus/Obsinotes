---
sr-due: 2025-09-08
sr-interval: 147
sr-ease: 290
---

#review 
### 基本理论：向量场

在空间分布的向量，根据 $(x,y)$ 坐标而确定参数的向量。
$$
\vec{F}=M(x,y)\hat{i}+N(x,y)\hat{j}
$$
### 线积分 变力做功的数学模型

$$
W=\int_{C}\vec{F}\cdot d \vec{r}=\lim_{ \Delta r_{i} \to 0 } \sum_{i}F_{i}\cdot \Delta r_{i}=\int_{t_{1}}^{t_{2}}\vec{F}\left( \frac{d \vec{r}}{dt} \right)dt
$$
本质上，是对于运行曲线之上每一段微小位移上，遍历做功的累计。

>注意技巧：将 $dt$ 用于积分变量。如此可以将积分上下限确立为 t 的相关
>对关键结构提炼并且将其转化为<font color="#31d83b">定义相关的、有意义的量</font>。

一种计算方法：化为
$$
\int_{t_{1}}^{t_{2}} \left \langle M(x,y),N(x,y) \right \rangle \cdot \left \langle d \vec{r_{x}},d \vec{r_{y}} \right \rangle=M(x,y)d \vec{r_{x}}+N(x,y)d \vec{r_{y}}
$$

此时参数方程的作用一如既往地凸显：**用一元来表示全部**！
##### 案例：假设在 $(x,y)$ 的点会受到 $\vec{F}=-y \hat{i}+ x \hat{j}$ 的作用力。这个点绕 $x^{2}+y^{2}=1$ 运行一周，做功几何？
考虑利用参数方程表示：位置方程 $(\cos \theta, \sin \theta)$，那么作用力的参数 $(-\sin \theta,\cos \theta)$
$$
\int_{0}^{2\pi} \left \langle -\sin \theta ,\cos \theta\right \rangle \cdot\left \langle -\sin \theta,\cos \theta \right \rangle d\theta=2\pi
$$
其中，$\left \langle -\sin \theta,\cos \theta \right \rangle$是力，$\left \langle -\sin \theta,\cos \theta \right \rangle$ 是坐标参数方程求导所得。

##### 案例：同样在这个力之下，从 $y=x^{2}$之上，$(0,0)$ 运行到 $(1,1)$，力所做之功？
同上，
$$
\begin{cases}
x=t \\
 \\
y=t^{2}
\end{cases}\implies
\int_{0}^{1} \left \langle -t^{2} ,t\right \rangle \cdot \left \langle 1,2t \right \rangle dt
$$
继续计算，可以得到
$$
\int_{0}^{1} -t^{2}+2t^{2}dt=\int_{0}^{1}t^{2} dt=\frac{1}{3}
$$
### 几何视角

回顾[[Subject 3 摆线及参数方程]]
$$
\frac{d \vec{r}}{dt}=\hat{T} \frac{d \vec{s}}{dt}
$$
其中，$d \vec{s}$ 是 *arclength* ，而 $\hat{T }$ 是单位长度的*方向向量*。
由此可以得到：
$$
\int \vec{F} \left[ \frac{\vec{d}r}{dt} dt \right]=\int \vec{F} \left[ \hat{T} \frac{d \vec{s}}{dt} \right]dt
$$
>通过这样的构造，成功地将
>$$ \int \vec{F}d \vec{r}$$从基于 $\vec{r}$ 变化转化成为了关于 $dt$ 变化！而即使对于 $d \vec{r}$ 将其除以 $dt$ ，其任然具有现实意义！
### 线积分的基本理论

如果 $\vec{F}=f_{x}\hat{i}+f_{y}\hat{j}$ ，也就是 $\nabla f$，那么满足：
$$
\int_{C} \mathbf{F}\cdot d\mathbf{r}=f(x,y)|_{P_{0}}^{P_{1}}=f(x_{1},y_{1})-f(x_{0},y_{0})
$$
>参考重力场，电场等。
>注意式子右边 $f(x_{1},y_{1})-f(x_{2},y_{2})$，不要忘了！

一些等价的表述：
- 向量场是 函数的梯度向量 $\nabla \mathbf{f}$
- 在任意闭合曲线上运行，累积做功为0
- 做功大小与路径无关，只会与初末位置有关

对于闭合曲线的线积分，已知有三种快捷的计算方法：
- 结合几何意义进行计算
- 使用上述 *线积分的基本理论* 进行计算，必须有 $\vec{\mathbf{F}}=\nabla \mathbf{f}$
- 使用 *Green's Theorem*——将线积分在一定的条件下，化为二重积分求解闭合曲面！

