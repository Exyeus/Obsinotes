---
sr-due: 2025-05-26
sr-interval: 47
sr-ease: 252
---

#review 

### 复合函数微分

$$
\begin{array}
\\z=f(u,v) \\
 \\
u= \phi(x,y) \\
 \\
v=\theta(x,y)
\end{array}\implies z=f[\phi(x,y),\theta(x,y)]
$$
这个就是由三个函数复合而成的复合函数，其中 $u$ 和 $v$ 是 *中间变量*。

*Theorem*。
若函数 $u=\phi(t)$ , $v=\theta(t)$ 在点 $t$ 可导，$z=f(u,v)$ 在 点 $(u.v)$ 处 *偏导连续*，那么复合函数在 $t$ 点可导，且有链式法则（全导数公式）：$$ \frac{dz}{dt}=\frac{\partial z}{\partial u} \times \frac{du}{dt}+\frac{\partial z}{\partial v} \times \frac{dv}{dt}$$十分关键，这里对于 $t$ 不再分叉，因此是 $dt$ ，而无需进一步的衍生＋偏导。
如果*偏导数连续*改为 *偏导数存在*， 那么结论将 *不一定* 成立。

如果两个 *中间变量* 都分叉到 $x$ 和 $y$ ，那么就会是两处偏导。
$$
\begin{cases}
z=e^{u}\sin v \\
 \\
u=xy \\
 \\
v=x+y
\end{cases}\implies \begin{cases}
\frac{\partial z}{\partial x}=\frac{\partial z}{\partial u} \times \frac{\partial u}{\partial x}+\frac{\partial z}{\partial v} \times \frac{\partial v}{\partial x} \\
 \\
\frac{\partial z}{\partial y} = \dots
\end{cases}
$$
```KEY
分段用乘，分叉用加；单路全导，叉路偏导
```

#### 类型

多元函数与多元函数复合
多元函数与一元函数复合
一元函数与多元函数复合

最终，对谁求导，就是表达式必须全部以 $dx$ 或者 $\partial x$ 结尾！

### 一阶全微分的形式不变性

$z=f(u(x,y),v(x,y))$ 在 $(x_{0},y_{0})$ 之处的全微分可以表示为 $dz=f_{u}du+f_{v}dv$。无论 $z$ 是自变量 $uv$ 的函数或者是中间变量 $uv$ 的函数，其全微分的 *形式* 是一样的，所以称之为 *全微分的形式不变性*

> 类比一元函数一阶微分的形式不变性

### 隐函数求微分

$$
\begin{cases}
F(x,y) \\
 \\
U_{r}(x_{0},y_{0})
\end{cases}\implies \begin{cases}
\text{conti partial deri} \\
F(x_{0},y_{0})=0 \\
 \\
F_{y}(x_{0},y_{0}) \neq 0
\end{cases}\implies \frac{dy}{dx}=-\frac{F_{x}}{F_{y}}
$$

