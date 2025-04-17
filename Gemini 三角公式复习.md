好的同学！三角函数恒等式和变形公式是整个微积分学习中不可或缺的工具箱。它们就像是代数中的乘法公式和因式分解，能够帮助我们化简复杂的表达式、求解方程、计算极限以及（尤其在积分中）将难以下手的函数变形为可以处理的形式。

很多同学觉得三角函数公式多而杂乱，容易记混。关键在于理解它们的来源和相互之间的联系，而不是死记硬背。我们来梳理一下高等数学中最常用的一些，并点拨一下它们的证明思路和应用场景。

**学科领域：** 高等数学 (微积分)

---

**核心思想：** 大部分的三角函数公式都可以从最基本的定义（单位圆）和几个核心公式（如勾股定理、两角和差公式）推导出来。理解推导过程有助于记忆和灵活运用。

---

### 1. 基本关系 (Reciprocal & Quotient Identities)

这些是最基础的定义性关系。

*   **倒数关系 (Reciprocal Identities):**
    $$ \csc x = \frac{1}{\sin x}, \quad \sec x = \frac{1}{\cos x}, \quad \cot x = \frac{1}{\tan x} $$
    *   **证明思路：** 直接源自 $csc, sec, cot$ 的定义。
    *   **用法点拨：** 用于将表达式中的 $csc, sec, cot$ 转化为更常用的 $sin, cos, tan$ 进行处理，或反之，有时将分数形式转化为乘积形式。

*   **商数关系 (Quotient Identities):**
    $$ \tan x = \frac{\sin x}{\cos x}, \quad \cot x = \frac{\cos x}{\sin x} $$
    *   **证明思路：** 在单位圆上，点的坐标为 $(\cos x, \sin x)$，根据正切定义 $\tan x = y/x$ 得到。$\cot x$ 是 $\tan x$ 的倒数。
    *   **用法点拨：** 同样用于不同三角函数间的转换，尤其在处理包含 $\tan, \cot$ 的积分和极限时非常有用。

---

### 2. 勾股定理恒等式 (Pythagorean Identities)

这些恒等式极其常用，必须熟练掌握。

*   **基本形式：**
    $$ \sin^2 x + \cos^2 x = 1 $$
    *   **证明思路：** 在单位圆 $X^2 + Y^2 = 1$ 上取一点 $P$，其坐标为 $(\cos x, \sin x)$，代入圆的方程即得。
    *   **用法点拨：**
        *   用于简化含有 $\sin^2 x$ 或 $\cos^2 x$ 的表达式。
        *   在积分中，可以用来替换 $\sin^2 x$ 为 $1-\cos^2 x$ (或反之)，以便使用换元法或凑微分。例如，计算 $\int \sin^3 x \, dx = \int \sin^2 x \sin x \, dx = \int (1-\cos^2 x) \sin x \, dx$。
        *   提供 $\sin x$ 和 $\cos x$ 之间的转换途径（知道一个可以求另一个的绝对值）。

*   **推论形式（通过两边同除 $\cos^2 x$ 或 $\sin^2 x$ 得到）：**
    $$ 1 + \tan^2 x = \sec^2 x $$
    $$ \cot^2 x + 1 = \csc^2 x $$
    *   **证明思路：** 将 $\sin^2 x + \cos^2 x = 1$ 两边分别除以 $\cos^2 x$（假设 $\cos x \neq 0$）和 $\sin^2 x$（假设 $\sin x \neq 0$）即可得到。
    *   **用法点拨：**
        *   在积分中非常有用，特别是处理 $\tan$ 和 $\sec$ 的幂次积分。例如 $\int \tan^2 x \, dx = \int (\sec^2 x - 1) \, dx = \tan x - x + C$。以及计算 $\int \sec^n x \tan^m x \, dx$ 这类积分。
        *   用于涉及 $\tan, \sec, \cot, \csc$ 的表达式化简和方程求解。

---

### 3. 两角和与差公式 (Angle Addition & Subtraction Formulas)

**这是后面很多公式的基础！理解它们的推导对掌握全局非常有益。**

*   **公式列表：**
    $$ \sin(A + B) = \sin A \cos B + \cos A \sin B $$
    $$ \sin(A - B) = \sin A \cos B - \cos A \sin B $$
    $$ \cos(A + B) = \cos A \cos B - \sin A \sin B $$
    $$ \cos(A - B) = \cos A \cos B + \sin A \sin B $$
    $$ \tan(A + B) = \frac{\tan A + \tan B}{1 - \tan A \tan B} $$
    $$ \tan(A - B) = \frac{\tan A - \tan B}{1 + \tan A \tan B} $$
*   **证明思路（以 $\cos(A-B)$ 为例）：**
    1.  在单位圆上取两点 $P(\cos A, \sin A)$ 和 $Q(\cos B, \sin B)$。
    2.  利用两点间距离公式计算线段 $PQ$ 长度的平方：$|PQ|^2 = (\cos A - \cos B)^2 + (\sin A - \sin B)^2 = 2 - 2(\cos A \cos B + \sin A \sin B)$。
    3.  考虑 $\triangle OPQ$（O是原点），利用余弦定理计算 $|PQ|^2$：$|PQ|^2 = |OP|^2 + |OQ|^2 - 2|OP||OQ|\cos(A-B) = 1^2 + 1^2 - 2(1)(1)\cos(A-B) = 2 - 2\cos(A-B)$。
    4.  比较两种方法得到的 $|PQ|^2$，即可得到 $\cos(A-B) = \cos A \cos B + \sin A \sin B$。
    5.  其他公式可以通过这个基础公式，利用 $\cos(-x)=\cos x, \sin(-x)=-\sin x$ 以及 $\sin x = \cos(\pi/2 - x), \cos x = \sin(\pi/2 - x)$ 等关系推导出来。例如，$\cos(A+B) = \cos(A - (-B)) = \dots$。
    6.  $\tan(A \pm B)$ 公式可以通过将 $\sin(A \pm B)$ 和 $\cos(A \pm B)$ 的结果相除，再分子分母同除以 $\cos A \cos B$ 得到。
*   **用法点拨：**
    *   **推导其他公式的基石**（如倍角、半角、和差化积、积化和差）。
    *   计算特殊角的三角函数值，例如 $\cos(15^\circ) = \cos(45^\circ - 30^\circ)$。
    *   简化包含 $f(x \pm c)$ 形式的三角表达式。
    *   在物理中（如波的叠加）和工程中有广泛应用。

---

### 4. 倍角公式 (Double Angle Formulas)

由和角公式令 $A=B$ 直接得到。

*   **公式列表：**
    $$ \sin(2A) = 2 \sin A \cos A $$
    $$ \cos(2A) = \cos^2 A - \sin^2 A $$
    $$ \cos(2A) = 2 \cos^2 A - 1 $$
    $$ \cos(2A) = 1 - 2 \sin^2 A $$
    $$ \tan(2A) = \frac{2 \tan A}{1 - \tan^2 A} $$
*   **证明思路：** 在和角公式中令 $A=B$ 即可。$\cos(2A)$ 的后两种形式是通过 $\sin^2 A + \cos^2 A = 1$ 代换得到的。
*   **用法点拨：**
    *   极其常用！特别是在积分中。看到 $\sin x \cos x$ 的组合通常可以考虑用 $\frac{1}{2}\sin(2x)$ 替换。
    *   $\cos(2A)$ 的三种形式在不同场合各有优势，需要灵活选用。例如，想把表达式全部转化为 $\cos A$ 时用 $2\cos^2 A - 1$。
    *   求解三角方程。
    *   推导降幂公式和半角公式。

---

### 5. 降幂公式 (Power Reduction Formulas) / 半角公式 (Half Angle Formulas)

它们本质上是倍角公式的变形，用于降低三角函数幂次或处理半角。

*   **降幂公式 (用于积分)：**
    $$ \sin^2 A = \frac{1 - \cos(2A)}{2} $$
    $$ \cos^2 A = \frac{1 + \cos(2A)}{2} $$
    $$ \tan^2 A = \frac{1 - \cos(2A)}{1 + \cos(2A)} $$
    *   **证明思路：** 直接从 $\cos(2A) = 1 - 2\sin^2 A$ 和 $\cos(2A) = 2\cos^2 A - 1$ 变形求解 $\sin^2 A$ 和 $\cos^2 A$。$\tan^2 A$ 由前两者相除得到。
    *   **用法点拨：** **积分神器！** 尤其是计算 $\int \sin^2 x \, dx$ 和 $\int \cos^2 x \, dx$，以及更高次幂（结合二项式展开）的积分，必须用降幂公式处理。

*   **半角公式 (用于求值或变形)：**
    $$ \sin\left(\frac{A}{2}\right) = \pm \sqrt{\frac{1 - \cos A}{2}} $$
    $$ \cos\left(\frac{A}{2}\right) = \pm \sqrt{\frac{1 + \cos A}{2}} $$
    $$ \tan\left(\frac{A}{2}\right) = \pm \sqrt{\frac{1 - \cos A}{1 + \cos A}} = \frac{1 - \cos A}{\sin A} = \frac{\sin A}{1 + \cos A} $$
    *   **证明思路：** 在降幂公式中，令 $A$ 替换为 $A/2$，则 $2A$ 变为 $A$，然后开方。正负号取决于 $A/2$ 所在的象限。$\tan(A/2)$ 的后两个无根号形式可以通过分子分母同乘以 $\sqrt{1-\cos A}$ 或 $\sqrt{1+\cos A}$ 并化简得到。
    *   **用法点拨：**
        *   计算特殊半角的三角函数值，例如 $\sin(22.5^\circ) = \sin(45^\circ/2)$。
        *   在某些积分换元（如万能代换 $t = \tan(x/2)$）中是基础。
        *   求解某些三角方程。

---

### 6. 和差化积公式 (Sum-to-Product Formulas)

将三角函数的和或差转化为积的形式。

*   **公式列表：**
    $$ \sin A + \sin B = 2 \sin\left(\frac{A+B}{2}\right) \cos\left(\frac{A-B}{2}\right) $$
    $$ \sin A - \sin B = 2 \cos\left(\frac{A+B}{2}\right) \sin\left(\frac{A-B}{2}\right) $$
    $$ \cos A + \cos B = 2 \cos\left(\frac{A+B}{2}\right) \cos\left(\frac{A-B}{2}\right) $$
    $$ \cos A - \cos B = -2 \sin\left(\frac{A+B}{2}\right) \sin\left(\frac{A-B}{2}\right) $$
*   **证明思路：**
    1.  从两角和差公式出发，例如 $\sin(u+v) = \sin u \cos v + \cos u \sin v$ 和 $\sin(u-v) = \sin u \cos v - \cos u \sin v$。
    2.  将这两式相加得到 $\sin(u+v) + \sin(u-v) = 2 \sin u \cos v$。
    3.  令 $A = u+v, B = u-v$。解出 $u = \frac{A+B}{2}, v = \frac{A-B}{2}$。
    4.  代入第2步的式子即得到第一个和差化积公式。其他公式类似推导。
*   **用法点拨：**
    *   **求解三角方程**是其主要用途，可以将和差形式因式分解为乘积形式，令每个因子为零来求解。
    *   在物理中分析波的干涉现象（例如声音的拍频）。
    *   简化某些三角函数表达式。

---

### 7. 积化和差公式 (Product-to-Sum Formulas)

将三角函数的积转化为和或差的形式。

*   **公式列表：**
    $$ \sin A \cos B = \frac{1}{2} [\sin(A+B) + \sin(A-B)] $$
    $$ \cos A \sin B = \frac{1}{2} [\sin(A+B) - \sin(A-B)] $$
    $$ \cos A \cos B = \frac{1}{2} [\cos(A+B) + \cos(A-B)] $$
    $$ \sin A \sin B = -\frac{1}{2} [\cos(A+B) - \cos(A-B)] = \frac{1}{2} [\cos(A-B) - \cos(A+B)] $$
*   **证明思路：** 这些公式其实就是和差化积公式推导的中间步骤！直接由两角和差公式相加或相减得到。例如，$\sin(A+B) = \sin A \cos B + \cos A \sin B$ 与 $\sin(A-B) = \sin A \cos B - \cos A \sin B$ 相加，得到 $\sin(A+B) + \sin(A-B) = 2 \sin A \cos B$，整理即得第一个公式。
*   **用法点拨：**
    *   **积分！** 计算形如 $\int \sin(mx) \cos(nx) \, dx$, $\int \cos(mx) \cos(nx) \, dx$, $\int \sin(mx) \sin(nx) \, dx$ 的积分时，必须使用积化和差将其转化为容易积分的和差形式。
    *   在信号处理中分析调制信号等。

---

### 8. 诱导公式 (Reduction Formulas) 与 周期性/奇偶性

这些公式帮助我们将任意角的三角函数值转化到 $(0, \pi/2)$ 区间内处理。

*   **周期性 (Periodicity):**
    $$ \sin(x + 2k\pi) = \sin x, \quad \cos(x + 2k\pi) = \cos x \quad (k \in \mathbb{Z}) $$
    $$ \tan(x + k\pi) = \tan x, \quad \cot(x + k\pi) = \cot x \quad (k \in \mathbb{Z}) $$
    *   **证明思路：** 源自角度的周期性定义。
    *   **用法点拨：** 将大角度或负角度转化到标准区间（如 $[0, 2\pi)$ 或 $(-\pi, \pi]$）内。

*   **奇偶性 (Even/Odd Properties):**
    $$ \sin(-x) = -\sin x \quad (\text{Odd}) $$
    $$ \cos(-x) = \cos x \quad (\text{Even}) $$
    $$ \tan(-x) = -\tan x \quad (\text{Odd}) $$
    *   **证明思路：** 单位圆定义或图像对称性。
    *   **用法点拨：** 处理负角度，简化表达式。

*   **诱导公式 (Cofunction & Other Reduction Formulas):** （口诀：奇变偶不变，符号看象限）
    例如：
    $$ \sin(\pi/2 - x) = \cos x, \quad \cos(\pi/2 - x) = \sin x $$
    $$ \sin(\pi/2 + x) = \cos x, \quad \cos(\pi/2 + x) = -\sin x $$
    $$ \sin(\pi - x) = \sin x, \quad \cos(\pi - x) = -\cos x $$
    $$ \sin(\pi + x) = -\sin x, \quad \cos(\pi + x) = -\cos x $$
    *   **证明思路：** 可以用两角和差公式严格推导，或者利用单位圆上的几何对称性。口诀中的“奇偶”指的是 $\pi/2$ 的奇数倍还是偶数倍，“变不变”指函数名是否改变（sin变cos，tan变cot等），“符号看象限”指假设原角 $x$ 是锐角时，原函数值的符号。
    *   **用法点拨：** 将任意角的三角函数最终归化为锐角三角函数，便于求值或比较。

---

**学习建议：**

1.  **抓住核心：** 深刻理解单位圆定义、勾股定理、两角和差公式。
2.  **推导联系：** 明白倍角、半角/降幂、和差化积、积化和差等是如何从和差公式推导出来的。自己动手推一遍效果最好。
3.  **理解应用场景：** 知道哪些公式在什么情况下特别有用（尤其是在积分和解方程中）。
4.  **练习！** 通过做题来熟练掌握和灵活运用这些公式。

掌握这些三角函数公式，你的微积分学习之路会顺畅很多！祝你成功！