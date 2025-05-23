---
sr-due: 2025-10-25
sr-interval: 184
sr-ease: 290
---

#review 
### 偏导数定义：`alias` 偏微商

设函数 $z=f(x,y)$ ，在点 $(x_{0},y_{0})$ 的某个邻域内有定义，将 $y$ 固定为 $y_{0}$，若极限
$$
\lim_{ \Delta x \to 0 } \frac{f(x_{0}+\Delta x,y_{0})-f(x_{0},y_{0})}{\Delta x}
$$
存在，那么称这个极限的数值，为函数在这个点关于 $x$ 的一阶偏导数。

>偏导数的几何意义，是在 $xOy$ 之中确立直线并且将其扩充为一个平行于 $z$ 轴的直线。这会导致在不同的顺序下，$f_{x y}$  与 $f_{yx}$ 不一定相等。

>此外，$f_{x}$ 是平行于 $x$ 轴的截面所得的曲线，而$f_{y}$ 则是平行于 $y$ 轴，这一个结论对于构建向量而言十分有用。
>偏导数的一个重要思想，是确定一个变量不变，使之为常数，然后变动另外一个变量。这使得对于一般的点，要求得其偏导数，如果另外一个变量已知，那么就可以先代入已知的常数，再进行求偏导。 
>对于那些函数有定义但是难以求得极限的点，要使用定义求解偏导数。例如$$z=f(x,y)=\sqrt{ |xy| }\implies?f_{x}(0,0)?f_{y}(0,0)$$
>$$ \lim_{ x \to 0 } \frac{\sqrt{ |x\cdot_{0}| }-\sqrt{ |0\cdot 0| }}{x}=0 $$
>由此也可以看出，
>1. 一元极限不存在不能主观臆断其类比所得二元极限也不存在
>2. 一个求解这样的极限的一般范式是，对于$(x_{0},y_{0})$，以及 $f(x,y)$，$$\frac{\partial f}{\partial x}=\lim_{ \Delta x \to 0 } \frac{f(x_{0}+\Delta x,y_{0})-f(x_{0},y_{0})}{\Delta x}$$
而其中这些数值直接代入，只要有定义，不必管他，代就是了
### 符号的理解：

$\partial f  / \partial x$ 是一个独立的符号，形如
$$
\frac{\partial p}{\partial V}   \frac{\partial V}{\partial T}  \frac{\partial T}{\partial R}
$$
这样的除法式子，一个都不能消掉！

### 联系上学期知识——如何使得极限存在

$\phi(x,y)$ 在 $(0,0)$ 邻域内连续，那么 $\phi(x)$ 应当具有什么样的性质，使得
$$
f(x,y)=|x \times y|\times \phi(x)
$$
$f_{x}(0,0)$ 和 $f_{y}(0,0)$ 存在？
*解答*。将其根据定义并且计算得到
$$
\lim_{ x \to 0 } \left[ \frac{|x|}{x}\cdot \phi(x,y) \right]
$$
那么，*规避左边这个在 0 处突然变向*的式子的唯一方式，就是使得 $\lim_{ (x,y) \to (0,0) }\phi(x,y)=0$。
### 成立的关系：

![[Pasted image 20250306100947.png]]

[[单变量函数的可微 可导 连续 导数连续 可积]]