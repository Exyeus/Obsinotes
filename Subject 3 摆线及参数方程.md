## 摆线参数方程的建立

使用向量来证明 !
不妨设轨迹之点为 $P$ , 球心 C 垂直 $x$ 于 H 点, 那么有:
$$
\begin{array}
\vec{OP}=\vec{OH}+\vec{HC}+\vec{CP}=(\theta+0+(-\sin \theta),0+1+(-\cos \theta)) \\ \\

\implies \begin{cases}
x(\theta)=\theta-\sin \theta \\ \\

y(\theta)=1-\cos \theta
\end{cases} \\
 \\
\implies dy / dx= \sin \theta / (1-\cos \theta)
\end{array}
$$
>注意：使用易于表达，易于发现的向量来分析图形！
>向量的自身特性，其恰好两个分量，表示为 $x(t)$ 和 $y(t)$ ，有利于参数方程同样结构的求取和建立！

其中, 参数方程之求导便是切线方程几何性质研究的典范:

$$
\lim_{ n \to 0 } \frac{\sin n}{1-\cos }=\lim_{ n \to 0 } \frac{n}{1-\left( 1-\frac{n^2}{2} \right)}=\lim_{ n \to 0 } \frac{2}{n} \implies \infty,i.eDNE
$$
>注意等价无穷小代换以及对极限存在与否的判定

所以结论是这个曲线在原点以及 $2\pi$ 等地方的切线斜率是无限大的。

# 对于参数方程的一个新的视角

把参数视为时间，那么方程里面各个分量关于这个参数的表达式，
就可以视为是一个物体,在做运动的时候，关于时间t在各个方向上位移的函数。

## 参数方程的向量化

构造: $\vec{r}(t)=x(t)\hat{i}+y(t)\hat{j}+z(t)\hat{k}$

求导, 可以得到 $$\frac{d \vec{r}}{dt}=(x'(t), y'(t))=\vec{v}(t)$$
这就是在每一点的 *速度* 的向量表达.
进一步, 定义 $$T=\frac{\vec{v}}{\lvert \vec{v} \rvert}:::是参数方程在各个点的单位切向向量$$
$$s=弧长\text{ , }spe ed = \frac{ds}{dt}=\lvert v \rvert =\sqrt{ (x'(t))^2+(y'(t))^2 }$$
>其中有一点值得注意, 便是 $\Delta s\geq \lvert \Delta r \rvert$, 因为 r 的本质是向量, 其进行减法也是在直线的尺度上进行 ! 而 $\Delta s$ 则是在曲面上进行
>注意这个结论：$\vec{v}= \hat{T} |s|$ ，以后自有妙用！

