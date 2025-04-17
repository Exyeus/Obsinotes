### 二阶混合偏导数

两个二阶混合导数实际上可能不相等。
定理：$$ \mathbf{if} ::f_{yx}(x,y), f_{xy}(x,y) \text{ continuous},(x,y)\in D\implies f_{xy}(x,y)=f_{yx}(x,y),(x,y)\in D$$
### Partial Differentiation Equations PDE

We will consider this later when learning more advanced courses

### Laplace Operator
$$
\Delta=\frac{\partial^2}{\partial x^{2}}+\frac{\partial^{2}}{\partial y^{2}}+\frac{\partial^{2}}{\partial z^{2}}
$$
Essentially, this is just a denotation for computation.

### Total Differentiation
#### Total increment?
$$
\Delta z=f(x+\Delta x,y+\Delta y)-f(x,y)
$$
This, once expanded, will be quite complicate. We set $\rho=\sqrt{ (\Delta x)^{2}+(\Delta y)^{2} }$ , and we can reexpress this formula:
$$
\Delta z=y_{0}^{2}\Delta x+2x_{0}y_{0}\Delta y+o(\rho)
$$And we can further give an approximation, that$$\Delta z\approx y_{0}^{2}\Delta x+2x_{0}y_{0}\Delta y$$
#### The Defintion of Total Differentiation

1. $\Delta z=f(x_{0}+\Delta x,y_{0}+\Delta y)-f(x,y)$
2. This can be written as $\Delta z=A\Delta x+B\Delta y+o(\rho)$, with $\rho\to 0$
3. A and B above is independent with $\Delta x$ and $\Delta y$, instead dependent on $(x_{0},y_{0})$ *only*.
4. $\rho=\sqrt{ (\Delta x)^{2}+(\Delta y)^{2} }$, as the expression of a short distance to $(x_{0},y_{0})$, we can consider it to be within a small ball around the point $(x_{0},y_{0})$.
> In proofs that come later, we will and can demonstate $f(x)$ as a high-order ?infinitysmall sum, by proving$$\lim_{ (x,y) \to (0,0) } \frac{f(x,y)}{\rho}=0$$

$\mathbf{If}$ function satisfys all requirements above, then we say it is *differentiable* at the point $(x_{0},y_{0})$. $\mathbf{If}$ all points of D is *differentiable*, then we say the function $f(x,y)$ is differentiable in the are D.

Here come two significant Theorems:
1. *differentiable* $\implies$ *continuous*
2. *differentiable* $\implies$ both of the partial derivatives exist
>we prove the derivative to exist, by showing the limitation in the definition of the derivative exists, which means it does not evaluate to *infinity* or not has different value on each side, respectively.

3. partial derivatives exist in the neigbhouring area of $(x_{0},y_{0})$ and the 2 derivatives are *continuous* **AT** the point $(x_{0},y_{0})\implies f(x,y)$ is differentiable at the point
4. 