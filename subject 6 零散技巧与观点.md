---
sr-due: 2025-09-09
sr-interval: 148
sr-ease: 290
---

#review 
>就是由一般求导再变形罢了!
### 隐微分 Implicit Differentiation

案例
$$
\begin{array}
\\ y = \arcsin x \\
 \\
x=\sin y
\end{array}\implies dx=\cos y  dy\implies \frac{dy}{dx}=\frac{1}{\cos y}=\frac{1}{\sqrt{ 1-\sin^2y }}=\frac{1}{\sqrt{ 1-x^2 }}
$$
[[GPT on Implicit Differentiation]]

### $dy,\Delta y,y'$之间区别

记住 *线性主部* 这个概念。$x$ 变化量越小, $\Delta y$ 和另外两者就越接近 !

### 二元函数求偏导的又一种理解

其实就是复合函数求导罢了$$
f(u,v)\implies df=\frac{df}{du} \frac{du}{dt}+\frac{df}{dv} + \frac{dv}{dt}
= \frac{\partial f}{\partial u} \frac{du}{dt} + \frac{\partial f}{\partial v} \frac{dv}{dt}
$$>关键时刻，取得隔山打牛之效果——给了并非关心的$\frac{df}{dt}$ 但是给了别的，就可以间接计算。
### Lagrange Multipliers

临界点$(x_{0},y_{0},z_{0})$满足:
$$
\begin{array}
\\ w=f(x,y,z) \\
 \\
g(x, y,z) =c
\end{array}\implies \nabla f(x_{0},y_{0},z_{0})=\lambda \nabla g(x_{0},y_{0},z_{0})
$$
而*局部最小值与最大值*就出现在满足上述条件的 临界点 *critical points*
>在应用之时，要记得方程是辅助的，函数是用来分析其极值的
>不要瞪眼起手，而要求偏导数加列方程起手！

### 公式 $dz=-\frac{g_{x}}{g_{z}}dx$

对于函数$g(x,y,z)$，如果我们*要求$z$对于 $x$ 的偏导*
$$
\begin{array}
dg=g_{x}dx+g_{y}dy+g_{z}dz \\ \\

\implies dz=-\frac{g_{x}}{g_{z}}dx-\frac{g_{y}}{g_{z}}dy\texttt{ , 其中y是常数，dy=0} \\ \\

\implies dz=-\frac{g_{x}}{g_{z}}dx
\end{array}
$$
>用于解决，在偏导求解之中，固定谁不动而计算的问题！已经生疏！2025年2月22日 14:55:53
>符号表示：
>$$f(x,y,z)\implies\left(\frac{\partial z}{\partial x}\right)_{y}$$
>审其信否！
