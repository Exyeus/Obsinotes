---
sr-due: 2025-05-19
sr-interval: 4
sr-ease: 270
---

#review 

> $\mathbf{k}$ is component in the same type to $\mathbf{i}$ and $\mathbf{j}$. We just use 1 to repr it.
> $\nabla \Phi=\nabla(z-f(x,y))=0$ gives the equation for the *norm vector*.
### 七、曲面上一点的法向量：如何找到垂直方向

#### 7.1 引入与动机

还记得在二维平面上，对于一条曲线 $y=f(x)$，在某一点的切线斜率是 $f'(x)$。那么垂直于切线的法线斜率就是 $-1/f'(x)$。如果我们想在三维空间中对一个曲面进行积分，或者计算穿过它的通量，我们需要知道曲面在每一点的**朝向**。这个朝向就由曲面在该点的**法向量**来表示，它是垂直于曲面在该点的切平面的向量。

对于一个由方程给出的曲面，比如 $z=f(x,y)$，我们怎么找到它的法向量呢？这就像问，如果你站在山坡上的某一点 (x, y, z)，哪个方向是正上方（垂直于山坡的方向）？

#### 7.2 必要知识回顾

*   **梯度：** 对于一个多变量函数 $\Phi(x, y, z)$，它的梯度 $\nabla \Phi$ 在某一点的方向是函数值增加最快的方向。更重要的是，梯度向量 $\nabla \Phi$ 垂直于该点通过的**等值面** $\Phi(x, y, z) = \text{constant}$。
*   **切向量：** 任何在曲面上通过该点的曲线，其在该点的切向量都躺在曲面的切平面上。
*   **向量叉乘：** 两个不平行的向量的叉乘结果，是一个同时垂直于这两个向量的向量。

#### 7.3 直观解释与方法推导

我们有两种主要方法来找曲面 $z=f(x,y)$ 在一点 $(x_0, y_0, z_0)$ (其中 $z_0 = f(x_0, y_0)$) 的法向量。

**方法一：利用梯度（Level Set Method）**

我们可以把曲面 $z=f(x,y)$ 看作是一个三变量函数 $\Phi(x,y,z) = z - f(x,y)$ 的**等值面** $\Phi(x,y,z) = 0$。
我们知道，梯度 $\nabla \Phi$ 垂直于函数 $\Phi$ 的等值面。所以， $\nabla \Phi$ 就是曲面 $z=f(x,y)$ 的一个法向量。

来计算 $\nabla \Phi$：
$$ \nabla \Phi = \frac{\partial \Phi}{\partial x} \mathbf{i} + \frac{\partial \Phi}{\partial y} \mathbf{j} + \frac{\partial \Phi}{\partial z} \mathbf{k} $$
这里 $\Phi(x,y,z) = z - f(x,y)$。
*   $\frac{\partial \Phi}{\partial x} = \frac{\partial}{\partial x}(z - f(x,y))$。注意，这里我们是把 $\Phi$ 看作 $x, y, z$ 三个独立变量的函数来求偏导。所以对 $x$ 求偏导时， $z$ 被视为常数。结果是 $-\frac{\partial f}{\partial x} = -f_x$.
*   $\frac{\partial \Phi}{\partial y} = \frac{\partial}{\partial y}(z - f(x,y))$. 对 $y$ 求偏导时，$z$ 被视为常数。结果是 $-\frac{\partial f}{\partial y} = -f_y$.
*   $\frac{\partial \Phi}{\partial z} = \frac{\partial}{\partial z}(z - f(x,y))$. 对 $z$ 求偏导时，$x, y$ 被视为常数，$f(x,y)$ 也被视为常数。结果是 $1$.

所以，梯度向量是 $\nabla \Phi = -f_x \mathbf{i} - f_y \mathbf{j} + 1 \mathbf{k} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$.
这是一个法向量！

**方法二：利用切向量的叉乘（Tangent Vector Cross Product Method）**

曲面上一点的切平面由该点处所有切向量构成。如果我们能找到两个在该点处不平行的切向量，它们的叉乘就会得到一个垂直于切平面的向量，也就是曲面的法向量。

考虑曲面上过点 $(x_0, y_0, z_0)$ 的两条特殊的曲线：
1.  保持 $y$ 不变 ($y=y_0$)，只让 $x$ 变化。这条曲线在曲面上，它的参数方程可以看作 $\mathbf{r}_1(x) = x \mathbf{i} + y_0 \mathbf{j} + f(x, y_0) \mathbf{k}$。这条曲线在点 $(x_0, y_0, z_0)$ 的切向量是其关于 $x$ 的导数：
    $$ \mathbf{v}_x = \frac{\partial \mathbf{r}_1}{\partial x} = \frac{\partial x}{\partial x} \mathbf{i} + \frac{\partial y_0}{\partial x} \mathbf{j} + \frac{\partial f(x, y_0)}{\partial x} \mathbf{k} = 1 \mathbf{i} + 0 \mathbf{j} + f_x \mathbf{k} = \mathbf{i} + f_x \mathbf{k} $$
    (我们在求偏导后，将 $x, y_0$ 视为 $(x_0, y_0)$ 点的值)
2.  保持 $x$ 不变 ($x=x_0$)，只让 $y$ 变化。这条曲线在曲面上，它的参数方程可以看作 $\mathbf{r}_2(y) = x_0 \mathbf{i} + y \mathbf{j} + f(x_0, y) \mathbf{k}$。这条曲线在点 $(x_0, y_0, z_0)$ 的切向量是其关于 $y$ 的导数：
    $$ \mathbf{v}_y = \frac{\partial \mathbf{r}_2}{\partial y} = \frac{\partial x_0}{\partial y} \mathbf{i} + \frac{\partial y}{\partial y} \mathbf{j} + \frac{\partial f(x_0, y)}{\partial y} \mathbf{k} = 0 \mathbf{i} + 1 \mathbf{j} + f_y \mathbf{k} = \mathbf{j} + f_y \mathbf{k} $$
    (我们在求偏导后，将 $x_0, y$ 视为 $(x_0, y_0)$ 点的值)

这两个切向量 $\mathbf{v}_x = \mathbf{i} + f_x \mathbf{k}$ 和 $\mathbf{v}_y = \mathbf{j} + f_y \mathbf{k}$ 位于该点的切平面上，且通常是不平行的（除非曲面在该点是水平的）。它们的叉乘会得到一个法向量：
$$ \mathbf{v}_x \times \mathbf{v}_y = (\mathbf{i} + f_x \mathbf{k}) \times (\mathbf{j} + f_y \mathbf{k}) $$
使用叉乘的分配律和基本单位向量的叉乘规则 ($\mathbf{i} \times \mathbf{j} = \mathbf{k}, \mathbf{i} \times \mathbf{k} = -\mathbf{j}, \mathbf{k} \times \mathbf{j} = -\mathbf{i}, \mathbf{k} \times \mathbf{k} = \mathbf{0}$):
$$ (\mathbf{i} \times \mathbf{j}) + (\mathbf{i} \times f_y \mathbf{k}) + (f_x \mathbf{k} \times \mathbf{j}) + (f_x \mathbf{k} \times f_y \mathbf{k}) $$
$$ = \mathbf{k} + f_y (\mathbf{i} \times \mathbf{k}) + f_x (\mathbf{k} \times \mathbf{j}) + f_x f_y (\mathbf{k} \times \mathbf{k}) $$
$$ = \mathbf{k} + f_y (-\mathbf{j}) + f_x (-\mathbf{i}) + 0 $$
$$ = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k} $$
这与方法一得到的结果完全一致！

所以，对于曲面 $z=f(x,y)$，向量 $\mathbf{N} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 是它在任意一点 $(x, y, f(x,y))$ 处的一个法向量。

#### 7.4 解释向量 $-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 中的 $\mathbf{k}$

这个向量 $\mathbf{N} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 是一个**具体的**法向量。它的分量分别是 $(-f_x, -f_y, 1)$。
请注意它的**k 分量总是 +1** (假设 $f_x, f_y$ 是有限的)。在三维空间中，$\mathbf{k}$ 方向是正 $z$ 方向（向上）。所以，这个特定的法向量 $-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 总是指向**向上**的方向（更准确地说，是 $z$ 分量为正的方向）。

曲面在一点有两个单位法向量，它们方向相反。如果我们选定向上为曲面的“正向”，那么这个向量的方向就是我们想要的法向量方向。如果选定向下为正向，那么我们就需要用它的反方向 $f_x \mathbf{i} + f_y \mathbf{j} - \mathbf{k}$。

**总结关于 k：** 在 $-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 中，$\mathbf{k}$ 的系数是 1。这意味着这个法向量的 $z$ 分量是正的，因此它是一个**指向上方**的法向量。这是由我们将曲面表示为 $z=f(x,y)$ 这种形式决定的，以及我们如何推导法向量（比如通过等值面 $z-f(x,y)=0$ 或特定的切向量叉乘）。

#### 7.5 法向量、单位法向量 $\mathbf{n}$、面积微元 $dS$ 和向量面积微元 $d\mathbf{S}$ 之间的联系

1.  **法向量 $\mathbf{N}$：** 我们刚刚找到了一个法向量 $\mathbf{N} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ (或 $f_x \mathbf{i} + f_y \mathbf{j} - \mathbf{k}$，取决于朝向)。它表示曲面在该点的法线方向，但它的长度不一定是 1。

2.  **单位法向量 $\mathbf{n}$：** 通量积分需要的是**单位**法向量 $\mathbf{n}$。这是用来表示曲面在某点的纯粹方向，长度为 1。要得到单位法向量，我们将法向量 $\mathbf{N}$ 除以它的长度：
    $$ \mathbf{n} = \frac{\mathbf{N}}{\|\mathbf{N}\|} $$
    计算 $\mathbf{N} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 的长度：
    $$ \|\mathbf{N}\| = \|-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}\| = \sqrt{(-f_x)^2 + (-f_y)^2 + 1^2} = \sqrt{f_x^2 + f_y^2 + 1} $$
    所以，**指向上方的单位法向量**是：
    $$ \mathbf{n}_{\text{up}} = \frac{-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}}{\sqrt{1 + f_x^2 + f_y^2}} $$
    **指向下方的单位法向量**是：
    $$ \mathbf{n}_{\text{down}} = \frac{f_x \mathbf{i} + f_y \mathbf{j} - \mathbf{k}}{\sqrt{1 + f_x^2 + f_y^2}} $$
    在通量积分 $\iint_S \mathbf{F} \cdot \mathbf{n} \, dS$ 中使用的 $\mathbf{n}$ 就是这个单位法向量，具体取哪个方向取决于曲面 $S$ 的**定向**。

3.  **面积微元 $dS$：** 曲面积分 $\iint_S f \, dS$ 需要的是**标量**面积微元 $dS$。它表示曲面上一个无穷小面积小片的面积。我们是如何将曲面上的面积积分转化为 $xy$ 平面上的二重积分的呢？
    想象 $xy$ 平面上有一个很小的矩形区域，面积是 $dx \times dy = dx dy$。这个小矩形是曲面上一个对应小片（面积为 $dS$）在 $xy$ 平面上的投影。这两块面积之间有一个比例因子，这个比例因子就反映了曲面相对于 $xy$ 平面的倾斜程度。
    这个比例因子正好等于法向量 $\mathbf{N} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 的长度。为什么？
    回想切向量的叉乘 $\mathbf{v}_x \times \mathbf{v}_y = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$. 考虑曲面上由沿着 $x$ 和 $y$ 方向的微小变化 $dx$ 和 $dy$ 张成的无穷小平行四边形区域。这个区域的面积**大小**正是向量 $\mathbf{v}_x dx$ 和 $\mathbf{v}_y dy$ 叉乘的**模长**：
    $$ dS = \| (\mathbf{i} + f_x \mathbf{k}) dx \times (\mathbf{j} + f_y \mathbf{k}) dy \| = \| (\mathbf{i} + f_x \mathbf{k}) \times (\mathbf{j} + f_y \mathbf{k}) \| \, dx dy $$
    $$ = \|-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}\| \, dx dy = \sqrt{1 + f_x^2 + f_y^2} \, dx dy $$
    所以，**标量面积微元** $dS$ 就等于 $\sqrt{1 + f_x^2 + f_y^2} \, dx dy$。这里的 $\sqrt{1 + f_x^2 + f_y^2}$ 是将 $xy$ 平面上的面积 $dx dy$ 放大到曲面上的面积 $dS$ 所需要的比例因子，它恰好是法向量 $\mathbf{N} = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$ 的长度。

4.  **向量面积微元 $d\mathbf{S}$：** 最后，向量面积微元 $d\mathbf{S}$ 定义为 $\mathbf{n} \, dS$. 它是一个向量，方向是单位法向量 $\mathbf{n}$ 的方向（曲面的朝向），大小是标量面积微元 $dS$。
    我们将上面得到的 $\mathbf{n}$ 和 $dS$ 的表达式代入：
    *   如果我们选择**指向上方**作为曲面的正向：$\mathbf{n} = \mathbf{n}_{\text{up}}$
        $$ d\mathbf{S} = \mathbf{n}_{\text{up}} \, dS = \left(\frac{-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}}{\sqrt{1 + f_x^2 + f_y^2}}\right) \cdot (\sqrt{1 + f_x^2 + f_y^2} \, dx dy) $$
        $$ d\mathbf{S} = (-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}) \, dx dy $$
    *   如果我们选择**指向下方**作为曲面的正向：$\mathbf{n} = \mathbf{n}_{\text{down}}$
        $$ d\mathbf{S} = \mathbf{n}_{\text{down}} \, dS = \left(\frac{f_x \mathbf{i} + f_y \mathbf{j} - \mathbf{k}}{\sqrt{1 + f_x^2 + f_y^2}}\right) \cdot (\sqrt{1 + f_x^2 + f_y^2} \, dx dy) $$
        $$ d\mathbf{S} = (f_x \mathbf{i} + f_y \mathbf{j} - \mathbf{k}) \, dx dy $$
    笔记中 V9, (13) 提到的 $d S = \pm ( − z_x \mathbf{i} − z_y \mathbf{j} + \mathbf{k}) dx dy$ (这里的 $z_x, z_y$ 就是 $f_x, f_y$) 就是这个结果。这个表达式直接包含了法向量的方向信息和面积的尺度因子。

#### 7.6 总结：如何从 $z=f(x,y)$ 得到 $d\mathbf{S}$

1.  从曲面方程 $z=f(x,y)$ (或 $\Phi(x,y,z) = z - f(x,y) = 0$) 找到一个法向量 $\mathbf{N} = \nabla(z-f(x,y)) = -f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}$。这个向量自然包含了向上方向（因为 $\mathbf{k}$ 分量是 +1）。
2.  计算这个法向量的长度 $\|\mathbf{N}\| = \sqrt{1 + f_x^2 + f_y^2}$。
3.  理解标量面积微元 $dS$ 与投影面积微元 $dx dy$ 的关系是 $dS = \|\mathbf{N}\| dx dy = \sqrt{1 + f_x^2 + f_y^2} dx dy$. 这里的 $\|\mathbf{N}\|$ 是面积的尺度因子。
4.  根据曲面的指定朝向，确定单位法向量 $\mathbf{n}$ 是 $\frac{\mathbf{N}}{\|\mathbf{N}\|}$ 还是 $\frac{-\mathbf{N}}{\|\mathbf{N}\|}$。通常，如果指定“向上”为正向， $\mathbf{n} = \frac{-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}}{\sqrt{1 + f_x^2 + f_y^2}}$. 如果指定“向下”， $\mathbf{n} = \frac{f_x \mathbf{i} + f_y \mathbf{j} - \mathbf{k}}{\sqrt{1 + f_x^2 + f_y^2}}$. 如果是封闭曲面，通常指定“向外”。
5.  向量面积微元 $d\mathbf{S} = \mathbf{n} \, dS$. 将 $\mathbf{n}$ 和 $dS$ 的表达式相乘，你会发现 $\|\mathbf{N}\|$ 这个长度因子正好抵消了：
    $$ d\mathbf{S} = \left(\frac{\pm \mathbf{N}}{\|\mathbf{N}\|}\right) (\|\mathbf{N}\| \, dx dy) = \pm \mathbf{N} \, dx dy = \pm (-f_x \mathbf{i} - f_y \mathbf{j} + \mathbf{k}) \, dx dy $$
    这里的 $\pm$ 号取决于你选择了向上还是向下作为正向。笔记中 V10.2 证明散度定理时提到“上表面用 + 号...下表面用 - 号”指的就是这个，上表面的法向量通常向上（+号），下表面的法向量通常向下（-号，对应向量 $\mathbf{N}$ 取负）。

所以，笔记中的表达式 $d S = \pm ( − z_x \mathbf{i} − z_y \mathbf{j} + \mathbf{k}) dx dy$ 实际上是向量面积微元 $d\mathbf{S}$ 的表达式，而不是标量面积微元 $dS$ 的。这个向量 $(-z_x \mathbf{i} - z_y \mathbf{j} + \mathbf{k})$ 是从 $z=f(x,y)$ 导出的一个法向量，其模长 $\sqrt{1+z_x^2+z_y^2}$ 恰好是标量面积微元 $dS$ 除以 $dx dy$ 的比例因子。

希望这样的详细解释能帮助你理清这些概念之间的关系！这是一个将几何（曲面、法向量、面积）和微积分（偏导数、积分）巧妙结合的关键步骤。