#review 

>Learn from example.
>data: ndarrays, generated inadvance or generated from np runtime.
>X should be added a new column to contain 1.
>W should be generated with $N+1$ columns to calculate the $b$.
>W should be updated with $W = W-lr*\nabla W$, where they are all numericals.
>`ndarrays` about W, contains numerical elements instead of expressions. For $\nabla W$, it is computed by some external formulas( roughly in this way ).
>Logistic is used to classify things.
>$p^{k}\times(1-p)^{n-k}$ should be maximized.$$\mathbf{Sigmoid}=\frac{1}{1+e^{-x} }$$This is used to squash the $(-\infty,\infty)$ by $\mathbf{x}\cdot \mathbf{w}$, into $(0, 1)$.
>More conduction.$$\begin{cases}
p=\frac{1}{1+e^{-z} } \in(0, 1) \\
 \\
\frac{p}{1-p}=\frac{1}{1+e^{-z} }\times \frac{1+e^{-z} }{e^{-z} }=e^{z}  \\
 \\
\ln\left( \frac{p}{1-p} \right)=\ln(e^{z} )=z \\
 \\
z=\mathbf{x}\cdot \mathbf{w}
\end{cases}$$

好的，同学！很高兴能和你一起探讨人工智能和 Python 程序设计中的回归分析。看到这些 PPT 笔记，内容相当丰富，涵盖了从基础工具（Numpy, Matplotlib）到核心模型（线性回归、逻辑回归）以及优化方法（梯度下降）的完整流程。你的目标是深入理解，尤其是逻辑回归部分，并且希望弄清楚公式背后的“为什么”，而不是死记硬背，这非常好！这正是一个优秀学习者应该具备的特质。

我们会借鉴 MIT 18.06 (Strang 教授的线性代数)、CS61A/B 的教学风格，注重直觉、推导和知识的联系。别担心数学基础或计算能力，我们会一步步来，确保每一步都清晰易懂。

我们先快速回顾一下你已经接触过的内容，并尝试从更深层次或者不同角度来理解它们，然后重点攻克**逻辑回归**。

---

## 快速回顾与深化：Numpy、Matplotlib 与线性回归

这部分内容你之前学过，我们主要目的是巩固理解，并为学习逻辑回归打好基础。

### Numpy：科学计算的基石

PPT 中提到了 Numpy 的重要性，尤其是在矩阵运算方面。

*   **核心优势：** Numpy 的核心是 `ndarray` (N-dimensional array) 对象。它之所以快，是因为：
    1.  **底层实现：** 许多操作是用 C 或 Fortran 实现的，避免了 Python 自身的解释器开销。
    2.  **内存连续：** `ndarray` 在内存中是连续存储的，利于 CPU 高速缓存优化。
    3.  **向量化 (Vectorization)：** 可以用简洁的数组表达式替代显式的循环，代码更易读，执行效率更高。例如，`a + b` 直接对两个 Numpy 数组 `a` 和 `b` 的对应元素求和，远快于写 Python 的 for 循环。

*   **矩阵乘法：** PPT 提到了一个练习题：如何用普通乘法、broadcasting 和 reduction 实现矩阵乘法 $C_{M \times N} = A_{M \times K} B_{K \times N}$。
    *   **标准方法：** 使用 `np.dot(A, B)` 或 `A @ B` (Python 3.5+)。这是最直接、最高效的方式。公式 $c_{ij} = \sum_{l=1}^{K} a_{il} \cdot b_{lj}$ 体现了点积的核心。
    *   **Broadcasting + Reduction 实现 (深化理解):** 这更能体现 Numpy 的机制。
        1.  **目标：** 计算 $c_{ij}$ 需要 $A$ 的第 $i$ 行和 $B$ 的第 $j$ 列的点积。
        2.  **挑战：** 如何让 $A$ 的第 $i$ 行（`A[i, :]`，维度 `1 x K`）和 $B$ 的第 $j$ 列（`B[:, j]`，维度 `K x 1`）的元素能"配对"相乘？
        3.  **思路 (利用 Broadcasting):**
            *   考虑计算 *所有* $c_{ij}$。我们需要让 $A$ 的每个元素 $a_{il}$ 和 $B$ 的每个元素 $b_{lj}$ 都能进行某种操作。
            *   我们可以扩展 $A$ 和 $B$ 的维度。将 $A$ 看作 `(M, 1, K)`，将 $B$ 转置后看作 `(1, N, K)`。
            *   `A_reshaped = A[:, np.newaxis, :]` # Shape (M, 1, K)
            *   `B_reshaped = B.T[np.newaxis, :, :]` # Shape (1, N, K)
            *   现在 `A_reshaped * B_reshaped` （逐元素乘法）会触发 broadcasting。Numpy 会将 `A_reshaped` 扩展成 `(M, N, K)`，将 `B_reshaped` 也扩展成 `(M, N, K)`。相乘的结果 `Temp` 的维度是 `(M, N, K)`，其中 `Temp[i, j, l]` 对应 $a_{il} \cdot b_{lj}$。
            *   **Reduction:** 最后，我们需要对 $K$ 这个维度求和（对应 $\sum_{l=1}^{K}$）。
            *   `C = np.sum(A_reshaped * B_reshaped, axis=2)` # Sum along the K dimension (axis=2)
        4.  **为什么这样做？** 这个过程虽然比 `A @ B` 繁琐，但它清晰地展示了：
            *   **Broadcasting 如何工作：** 通过 `np.newaxis` 增加维度，让形状能够匹配和扩展。
            *   **Element-wise 操作：** 基础运算是逐元素的。
            *   **Reduction (聚合)：** `np.sum` 如何沿着特定轴将信息聚合起来，得到最终结果。这对于理解更复杂的 Numpy 操作很有帮助。

### Matplotlib：数据可视化的利器

PPT 列出了常用的绘图函数：`scatter` (散点图), `plot` (折线图), `hist` (直方图), `contour` (等高线图)。

*   **为什么要可视化？**
    *   **直观理解数据：** 一图胜千言，快速把握数据分布、趋势、异常点。
    *   **模型诊断：** 比如绘制损失函数的等高线图，可以直观看到优化的路径和最小值点的位置。绘制预测值与真实值的散点图，可以判断模型拟合效果。

*   **绘制损失函数 $L(w, b)$ 等高线图 (深化理解):**
    1.  **动机：** 损失函数 $L(w, b)$ 是一个关于参数 $w$ 和 $b$ 的函数。我们想知道在 $(w, b)$ 平面上，哪些区域的损失值高，哪些区域低，最低点（最优参数）大概在哪里。等高线图像山脉地图一样，圈出的线代表相同“海拔”（损失值）。
    2.  **`meshgrid` 的作用：** 我们不能无限地计算每个 $(w, b)$ 点的损失。`meshgrid` 就像是在 $(w, b)$ 平面上撒下一张规则的渔网。它接收两个一维数组（比如，一系列 $w$ 的值和一系列 $b$ 的值），然后生成两个二维数组：一个 `W` 矩阵，每个位置 `(i, j)` 存的是第 $j$ 个 $w$ 值；一个 `B` 矩阵，每个位置 `(i, j)` 存的是第 $i$ 个 $b$ 值。这样，`W[i, j]` 和 `B[i, j]` 就构成了网格上第 `(i, j)` 个点的坐标 $(w_j, b_i)$。
    3.  **计算损失 (向量化):** 有了 `W` 和 `B` (维度都是 `grid_size_b x grid_size_w`)，以及训练数据 $x$ (N x 1) 和 $y$ (N x 1)，如何高效计算每个网格点的损失 $L(w, b) = \frac{1}{N} \sum_{i=1}^N (w x_i + b - y_i)^2$？
        *   **挑战：** 对于 `W` 和 `B` 中的每一个 $(w, b)$ 组合，都要遍历所有 $N$ 个数据点计算 MSE。直接用 Python 循环会非常慢。
        *   **向量化思路 (利用 Broadcasting):**
            *   将 $x$ 扩展为 `(N, 1)`， $y$ 扩展为 `(N, 1)`。
            *   `W` 和 `B` 是 `(grid_size_b, grid_size_w)`。
            *   我们需要计算 `w * x_i + b - y_i`。这里 `w` 和 `b` 来自网格，`x_i` 和 `y_i` 来自数据。
            *   考虑 `W` (shape `(G_b, G_w)`) 和 `x` (shape `(N, 1)` or `(N,)`)。我们需要让每个 `w` 和每个 `x_i` 相乘。可以使用 broadcasting：
                *   `x_reshaped = x.reshape(N, 1, 1)` # Shape (N, 1, 1)
                *   `W_reshaped = W[np.newaxis, :, :]` # Shape (1, G_b, G_w)
                *   `pred_term1 = W_reshaped * x_reshaped` # Broadcasting -> Shape (N, G_b, G_w)
            *   同样，`b` 和 `y`：
                *   `B_reshaped = B[np.newaxis, :, :]` # Shape (1, G_b, G_w)
                *   `y_reshaped = y.reshape(N, 1, 1)` # Shape (N, 1, 1)
                *   `errors = pred_term1 + B_reshaped - y_reshaped` # Shape (N, G_b, G_w)
            *   现在 `errors[i, j, k]` 代表用网格点 $(w_k, b_j)$ 对数据点 $x_i$ 预测产生的误差 $w_k x_i + b_j - y_i$。
            *   计算平方误差：`squared_errors = errors**2` # Shape (N, G_b, G_w)
            *   计算均方误差 (MSE)：对 N 个样本求平均。
                *   `Loss = np.mean(squared_errors, axis=0)` # Mean along the N dimension (axis=0) -> Shape (G_b, G_w)
            *   现在 `Loss[j, k]` 就是网格点 $(w_k, b_j)$ 对应的损失值。
        *   **绘制：** 有了 `W`, `B` 和 `Loss` (都是 `G_b x G_w` 的矩阵)，就可以调用 `plt.contour(W, B, Loss)` 来绘制等高线图了。

    4.  **关键思想：** 充分利用 Numpy 的 broadcasting 机制，避免显式 Python 循环，将对整个参数网格的损失计算向量化，从而极大提高效率。

### 一元与多元线性回归：模型、损失与优化

*   **模型 (Model):**
    *   **核心假设：** 因变量 $y$ 和自变量 $x$ (或 $x_1, x_2, ..., x_d$) 之间存在 **线性关系**。
    *   **一元：** $y \approx w x + b$. 几何上是一条直线。
    *   **多元：** $y \approx w_1 x_1 + w_2 x_2 + ... + w_d x_d + b$. 几何上是一个超平面。
    *   **符号简化 (Trick):** PPT 中提到，将 $x$ 扩展为 $(x_1, ..., x_d, 1)$，并将 $b$ 看作是对应于常数项 1 的权重 $w_{d+1}$，模型统一写成 $y \approx \mathbf{x} \cdot \mathbf{w}$。这里 $\mathbf{x}$ 是增广后的行向量 `(1 x (d+1))`，$\mathbf{w}$ 是列向量 `((d+1) x 1)`。
        *   **为什么这样做？** 数学表达更简洁，便于矩阵运算。编程实现时也更方便，不需要单独处理偏置项 $b$。

*   **损失函数 (Loss Function): 均方误差 (MSE)**
    *   $L(w, b) = \frac{1}{N} \sum_{i=1}^N (\hat{y}_i - y_i)^2$, 其中 $\hat{y}_i = w x_i + b$ (一元) 或 $\hat{y}_i = \mathbf{x}_i \cdot \mathbf{w}$ (多元)。
    *   **为什么用 MSE？**
        1.  **直观：** 它度量了预测值 $\hat{y}_i$ 和真实值 $y_i$ 之间的平均“距离”的平方。我们希望这个距离越小越好。
        2.  **数学性质：**
            *   **可微性：** MSE 对于参数 $w$ 和 $b$ (或 $\mathbf{w}$) 是连续可微的，这对于使用基于梯度的优化方法（如梯度下降）至关重要。
            *   **凸性：** 对于线性回归，MSE 损失函数是一个**凸函数**。这意味着它只有一个全局最小值，没有局部最小值。这保证了梯度下降法（如果步长合适）理论上一定能找到最优解。想象一个碗状的曲面，从任何地方往下走，最终都会到达碗底。
        3.  **概率解释 (更深层):** 如果我们假设真实值 $y_i$ 是由线性模型 $f(x_i; w, b)$ 加上一个均值为 0、方差为 $\sigma^2$ 的**高斯噪声** $\epsilon_i$ 生成的，即 $y_i = f(x_i; w, b) + \epsilon_i$，那么，最大化观测到所有 $y_i$ 的似然概率 (Maximum Likelihood Estimation, MLE)，最终推导出的结果恰好等价于最小化 MSE。所以，选择 MSE 隐含了对噪声呈高斯分布的假设。

*   **优化 (Optimization): 梯度下降法 (Gradient Descent)**
    *   **目标：** 找到使损失函数 $L$ 最小的参数 $w, b$ (或 $\mathbf{w}$)。
    *   **核心思想：**
        1.  **方向：** 函数在某一点的**梯度** ($\nabla L$) 指向该点函数值**增长最快**的方向。那么，**负梯度** ($-\nabla L$) 就指向函数值**下降最快**的方向。
        2.  **步长：** 沿着负梯度方向走一小步，损失函数的值就会减小。这一小步的大小由**学习率 (Learning Rate, lr)** $\alpha$ 控制。
        3.  **迭代：** 重复这个过程，参数就会逐步逼近损失函数的最小值点。
    *   **更新规则：**
        *   一元：
            $w_{new} = w_{old} - \alpha \frac{\partial L}{\partial w}$
            $b_{new} = b_{old} - \alpha \frac{\partial L}{\partial b}$
        *   多元 (向量形式)：
            $\mathbf{w}_{new} = \mathbf{w}_{old} - \alpha \nabla_{\mathbf{w}} L$
    *   **梯度的计算 (PPT 公式解读):**
        *   **一元：**
            $\frac{\partial L}{\partial w} = \frac{2}{N} \sum_{i=1}^N (w x_i + b - y_i) x_i$
            $\frac{\partial L}{\partial b} = \frac{2}{N} \sum_{i=1}^N (w x_i + b - y_i) \cdot 1$
            *   **推导思路 (以 $\frac{\partial L}{\partial w}$ 为例):** 使用链式法则。$L = \frac{1}{N} \sum e_i^2$，其中 $e_i = (w x_i + b - y_i)$。
            $\frac{\partial L}{\partial w} = \frac{1}{N} \sum \frac{\partial (e_i^2)}{\partial w} = \frac{1}{N} \sum 2 e_i \frac{\partial e_i}{\partial w}$.
            由于 $\frac{\partial e_i}{\partial w} = \frac{\partial (w x_i + b - y_i)}{\partial w} = x_i$，代入即可得到结果。$\frac{\partial L}{\partial b}$ 同理，只是 $\frac{\partial e_i}{\partial b} = 1$。
            *   **向量形式 (PPT):** $\frac{\partial L}{\partial w} = \frac{2}{N} \mathbf{x}^T (\mathbf{\hat{y}} - \mathbf{y})$ (这里 $\mathbf{x}$ 是 N x 1 列向量, $\mathbf{\hat{y}} = w\mathbf{x} + b\mathbf{1}$ 也是 N x 1)。这需要仔细核对 PPT 的符号定义，它似乎把 x, 1, y 都定义为 N x 1 列向量。如果 $\mathbf{x}, \mathbf{1}, \mathbf{y}$ 都是 N x 1 列向量，那么 $\mathbf{\hat{y}} - \mathbf{y}$ 是 N x 1， $\mathbf{x}^T$ 是 1 x N，结果是 1x1 标量，正确。$\frac{\partial L}{\partial b} = \frac{2}{N} \mathbf{1}^T (\mathbf{\hat{y}} - \mathbf{y})$ 同理。
        *   **多元 (向量形式，使用增广 $\mathbf{x}_i$ 和 $\mathbf{w}$):**
            $L(\mathbf{w}) = \frac{1}{N} \sum_{i=1}^N (\mathbf{x}_i \cdot \mathbf{w} - y_i)^2$.
            PPT 给出的梯度 $\nabla_{\mathbf{w}} L = \frac{\partial L(\mathbf{w})}{\partial \mathbf{w}} = \frac{2}{N} \sum_{i=1}^N \mathbf{x}_i^T (\mathbf{x}_i \cdot \mathbf{w} - y_i)$.
            注意：这里 $\mathbf{x}_i$ 是 `1 x (d+1)` 行向量， $\mathbf{w}$ 是 `(d+1) x 1` 列向量，$\mathbf{x}_i \cdot \mathbf{w}$ 是标量。$\mathbf{x}_i^T$ 是 `(d+1) x 1` 列向量。所以梯度是一个 `(d+1) x 1` 的列向量，维度正确。
            **矩阵形式 (PPT):** $\nabla_{\mathbf{w}} L = \frac{2}{N} \mathbf{X}^T (\mathbf{X} \mathbf{w} - \mathbf{y})$.
            *   **解读：** $\mathbf{X}$ 是 $N \times (d+1)$ 的**设计矩阵** (design matrix)，每一行是一个样本 $\mathbf{x}_i$。$\mathbf{w}$ 是 $(d+1) \times 1$ 的参数向量。$\mathbf{y}$ 是 $N \times 1$ 的真实值向量。
            *   $\mathbf{Xw}$ (维度 $N \times 1$)：这是模型对所有 $N$ 个样本的预测值向量 $\mathbf{\hat{y}}$。
            *   $\mathbf{Xw} - \mathbf{y}$ (维度 $N \times 1$)：这是预测误差向量。
            *   $\mathbf{X}^T$ (维度 $(d+1) \times N$)：将误差向量“映射”回参数空间。第 $j$ 行 $(X^T)_{j,:}$ 乘以误差向量，相当于 $\sum_{i=1}^N x_{ij} ( \hat{y}_i - y_i)$，这正好是梯度向量的第 $j$ 个分量（除了常数因子 $2/N$）。
            *   **为什么是这个形式？** 这是多元函数求导和矩阵运算结合的结果。可以从标量形式的梯度 $\frac{\partial L}{\partial w_j} = \frac{2}{N} \sum_{i=1}^N (\mathbf{x}_i \cdot \mathbf{w} - y_i) x_{ij}$ 出发，将所有 $j=1, ..., d+1$ 的导数组合成一个列向量，最终可以写成这个简洁的矩阵形式。这个形式在编程实现时极其方便和高效！

    *   **收敛：** 迭代停止的条件通常是参数变化足够小，或者达到预设的最大迭代次数。

---

## 深入讲解：逻辑回归 (Logistic Regression)

好了，现在进入我们今天的主角——逻辑回归。你可能会疑惑，名字里带“回归”，但它通常用来解决**分类**问题，这是为什么呢？

### 1. 引入与动机 (Hook & Motivation)

*   **问题场景：** 想象一下，我们不再是预测房价（连续值），而是想判断一封邮件是否是垃圾邮件（是/否），或者一个肿瘤是良性还是恶性（良性/恶性）。这些都是**二分类 (Binary Classification)** 问题，输出结果是离散的类别（通常编码为 0 和 1）。
*   **线性回归的局限性：** 我们能不能直接用线性回归来做分类呢？比如，让类别 1 对应输出 1，类别 0 对应输出 0。
    *   模型：$\hat{y} = \mathbf{x} \cdot \mathbf{w}$
    *   问题：线性回归的输出 $\hat{y}$ 是 $(-\infty, +\infty)$ 的任意实数，但我们期望的输出是 0 或 1，或者至少是一个介于 0 和 1 之间的**概率**。如果 $\hat{y} = 1.5$ 或 $\hat{y} = -0.3$，这该如何解释为类别？
    *   强行阈值？我们可以设定一个阈值，比如 0.5，如果 $\hat{y} > 0.5$ 就预测为 1，否则为 0。但这并不理想：
        *   线性模型对远离阈值的数据点“过于自信”，一个离群点可能极大影响拟合的直线/平面，导致分类边界偏移。
        *   MSE 损失函数在这种 0/1 场景下也不是最佳选择（后面会细说）。
*   **核心需求：** 我们需要一个模型，它的输出能在 `(0, 1)` 区间内，并且可以被自然地解释为“属于类别 1 的概率”。

### 2. 必要知识回顾 (Prerequisite Review)

*   **线性回归模型：** 理解 $\mathbf{z} = \mathbf{x} \cdot \mathbf{w}$ 的含义，即特征的线性组合。
*   **概率基础：** 理解 $P(Y=1 | \mathbf{x})$ 的含义，即给定特征 $\mathbf{x}$，事件 $Y$ 发生的（条件）概率。
*   **指数函数与对数函数：** $e^x$ 和 $\ln(x)$ 的基本性质，它们是互逆运算。

### 3. 直观解释与感性认识 (Intuitive Explanation)

*   **目标：** 将线性模型的输出 $\mathbf{z} = \mathbf{x} \cdot \mathbf{w}$ (范围 $(-\infty, +\infty)$) 映射到概率空间 $(0, 1)$。
*   **寻找合适的映射函数：** 我们需要一个函数 $g(z)$，满足：
    1.  输入 $z \in (-\infty, +\infty)$。
    2.  输出 $g(z) \in (0, 1)$。
    3.  单调递增：$z$ 越大（线性组合得分越高），属于类别 1 的概率 $p$ 也应该越大。
    4.  最好是 S 形曲线，中间变化快，两端变化慢（符合直觉：当证据非常强时，再增加一点证据对概率的影响不大）。
*   **Sigmoid (Logistic) 函数：** 恰好满足这些要求的函数之一是 Sigmoid 函数：
    $$ p = g(z) = \frac{1}{1 + e^{-z}} $$
    *   **形状：**
        *   当 $z \to +\infty$, $e^{-z} \to 0$, $p \to 1 / (1 + 0) = 1$.
        *   当 $z \to -\infty$, $e^{-z} \to +\infty$, $p \to 1 / (1 + \infty) = 0$.
        *   当 $z = 0$, $e^0 = 1$, $p = 1 / (1 + 1) = 0.5$.
        *   它是一个光滑的、单调递增的 S 形曲线，完美地将实数轴映射到 (0, 1) 区间。
    *   **类比：** 想象一个调光开关，线性回归的输出 $z$ 是你转动开关的角度（可以无限转），Sigmoid 函数则把这个角度转换成灯泡的亮度（只能在 0% 到 100% 之间变化）。

*   **逻辑回归模型的核心思想：**
    1.  先用线性模型计算一个“得分”或“证据强度”： $z = \mathbf{x} \cdot \mathbf{w}$。

>Recall
>What does this $z=\mathbf{x}\cdot \mathbf{w}$ come from?
>$z = a_{1}x_{1}+a_{2}x_{2}+\dots+b=a_{1}x_{1}+a_{2}x_{2}+\dots+b\cdot 1$
>$=(a_{1},a_{2},\dots ,b)\cdot(x_{1},x_{2},\dots,x_{n-1},1)$
>$=\mathbf{w}\cdot \mathbf{x}$.

.
    2.  再用 Sigmoid 函数将这个得分转换为概率： $p = P(Y=1 | \mathbf{x}; \mathbf{w}) = \sigma(z) = \frac{1}{1 + e^{-(\mathbf{x} \cdot \mathbf{w})}}$。
    *   这个 $p$ 就是模型预测的 $\mathbf{x}$ 属于类别 1 的概率。

*   **为什么叫“逻辑”回归 / “对数几率”回归？(PPT 提及)**
    *   **几率 (Odds):** 指事件发生的概率与不发生的概率之比： $Odds = \frac{p}{1-p}$。 $p$ 在 (0, 1) 之间，Odds 在 $(0, +\infty)$ 之间。
    *   **对数几率 (Log-odds / Logit):** 对几率取自然对数： $\text{Logit} = \ln(\frac{p}{1-p})$。
    *   **神奇的联系：** 让我们从逻辑回归模型 $p = \frac{1}{1 + e^{-z}}$ 反推 Logit：
        *   $1 - p = 1 - \frac{1}{1 + e^{-z}} = \frac{1 + e^{-z} - 1}{1 + e^{-z}} = \frac{e^{-z}}{1 + e^{-z}}$
        *   $\frac{p}{1-p} = \frac{1 / (1 + e^{-z})}{e^{-z} / (1 + e^{-z})} = \frac{1}{e^{-z}} = e^z$
        *   $\ln(\frac{p}{1-p}) = \ln(e^z) = z$
    *   **结论：** 逻辑回归模型实际上是在用线性模型 $\mathbf{z} = \mathbf{x} \cdot \mathbf{w}$ 来拟合**对数几率**！
        $$ \ln\left(\frac{P(Y=1|\mathbf{x})}{1 - P(Y=1|\mathbf{x})}\right) = \mathbf{x} \cdot \mathbf{w} $$
    *   这就是它名字的由来。虽然它最终预测的是概率 $p$，但其内部核心是对 Logit 进行线性回归。由于<font color="#ffff00">最终目标通常是分类，所以它被归为分类算法，但其数学形式和“回归”有关</font>。

### 4. 逐步形式化与精确定义 (Gradual Formalization)

*   **模型假设：** 给定 $d$ 维特征向量 $\mathbf{x} = (x_1, x_2, ..., x_d)$（通常增广为 $(x_1, ..., x_d, 1)$），我们希望预测其属于类别 1 的概率 $p$。
*   **逻辑回归模型：**
    $$ p = P(Y=1 | \mathbf{x}; \mathbf{w}) = \sigma(\mathbf{x} \cdot \mathbf{w}) = \frac{1}{1 + e^{-\mathbf{x} \cdot \mathbf{w}}} $$
    其中：
    *   $\mathbf{x}$ 是 $(1 \times (d+1))$ 的（增广）行向量。
    *   $\mathbf{w}$ 是 $((d+1) \times 1)$ 的参数向量（包含偏置 $b$）。
    *   $\mathbf{x} \cdot \mathbf{w}$ 是线性组合（标量）。
    *   $\sigma(z) = \frac{1}{1 + e^{-z}}$ 是 Sigmoid 函数。
    *   $p$ 是模型预测的 $\mathbf{x}$ 属于类别 1 的概率，因此 $P(Y=0 | \mathbf{x}; \mathbf{w}) = 1 - p$。

### 5. 核心原理与推导过程 (Core Principles & Derivation Walkthrough)

现在到了最关键的部分：如何找到最优的参数 $\mathbf{w}$？我们需要定义一个损失函数，然后最小化它。

#### 5.1 损失函数：为什么不用 MSE？为什么用交叉熵？

*   **MSE 的问题：** 如果我们直接用 MSE 来衡量预测概率 $p = \sigma(\mathbf{x} \mathbf{w})$ 和真实标签 $y \in \{0, 1\}$ 之间的差距，即 $L_{MSE}(\mathbf{w}) = \frac{1}{N} \sum (\sigma(\mathbf{x}_i \mathbf{w}) - y_i)^2$。这个损失函数对于 $\mathbf{w}$ 来说是**非凸**的！它会有很多<font color="#ffff00">局部最小值</font>，梯度下降法很难保证找到全局最优解。这是因为 Sigmoid 函数的非线性性质引入了复杂性。

*   **新的思路：最大似然估计 (Maximum Likelihood Estimation, MLE)**
    *   **思想：** 我们应该选择什么样的参数 $\mathbf{w}$，使得在给定训练数据 $\mathbf{X} = \{\mathbf{x}_1, ..., \mathbf{x}_N\}$ 的情况下，观测到对应的真实标签 $\mathbf{Y} = \{y_1, ..., y_N\}$ 的**概率最大**？
    *   **单个样本的似然：** 对于一个样本 $(\mathbf{x}_i, y_i)$，模型预测其属于类别 1 的概率是 $p_i = \sigma(\mathbf{x}_i \mathbf{w})$。
        *   如果真实标签 $y_i = 1$，我们希望 $p_i$ 尽可能大。观测到 $y_i=1$ 的概率就是 $p_i$。
        *   如果真实标签 $y_i = 0$，我们希望 $p_i$ 尽可能小，也就是 $1-p_i$ 尽可能大。观测到 $y_i=0$ 的概率就是 $1-p_i$。
        *   **统一表达：** 我们可以用一个巧妙的式子统一这两种情况：
            $$ P(y_i | \mathbf{x}_i; \mathbf{w}) = p_i^{y_i} (1 - p_i)^{1 - y_i} $$
            验证一下：
            *   当 $y_i = 1$ 时，上式变为 $p_i^1 (1 - p_i)^0 = p_i$。
            *   当 $y_i = 0$ 时，上式变为 $p_i^0 (1 - p_i)^1 = 1 - p_i$。
            完美！这个式子正好表达了模型预测正确的概率。
    *   **整个数据集的似然：** 假设样本之间是独立同分布的 (i.i.d.)，那么观测到整个数据集 $\mathbf{Y}$ 的联合概率（似然函数 $L(\mathbf{w})$）就是所有单个样本概率的乘积：
        $$ L(\mathbf{w}) = P(\mathbf{Y} | \mathbf{X}; \mathbf{w}) = \prod_{i=1}^N P(y_i | \mathbf{x}_i; \mathbf{w}) = \prod_{i=1}^N p_i^{y_i} (1 - p_i)^{1 - y_i} $$
    *   **目标：** 找到 $\mathbf{w}^* = \arg \max_{\mathbf{w}} L(\mathbf{w})$。

*   **对数似然与交叉熵损失 (Log-Likelihood & Cross-Entropy Loss):**
    *   **连乘变连加：** 乘积形式 $L(\mathbf{w})$ 不方便求导优化。通常取其对数，将乘积变为求和，这不改变最大值点的位置（因为 $\ln$ 函数是单调递增的）。这称为对数似然函数 $\ell(\mathbf{w})$：
        $$ \ell(\mathbf{w}) = \ln L(\mathbf{w}) = \ln \left( \prod_{i=1}^N p_i^{y_i} (1 - p_i)^{1 - y_i} \right) $$
        $$ \ell(\mathbf{w}) = \sum_{i=1}^N \ln \left( p_i^{y_i} (1 - p_i)^{1 - y_i} \right) $$
        $$ \ell(\mathbf{w}) = \sum_{i=1}^N [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ] $$
    *   **最大化似然 vs 最小化损失：** 我们的目标是最大化对数似然 $\ell(\mathbf{w})$。在机器学习中，我们习惯于**最小化**损失函数。因此，我们定义损失函数 $J(\mathbf{w})$ 为**负的平均对数似然 (Negative Average Log-Likelihood)**：
        $$ J(\mathbf{w}) = -\frac{1}{N} \ell(\mathbf{w}) = -\frac{1}{N} \sum_{i=1}^N [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ] $$
        *   **这个就是逻辑回归的损失函数，也称为二元交叉熵损失 (Binary Cross-Entropy Loss)。**
    *   **为什么叫交叉熵？** 熵是信息论中的概念，衡量不确定性。交叉熵衡量的是，用一个概率分布 $p$（模型的预测）来表示另一个真实分布 $y$（0或1）时所需要的“额外信息量”或“距离”。最小化交叉熵，就是让模型的预测分布 $p$ 尽可能地接近真实的标签分布 $y$。
    *   **性质：** 这个 $J(\mathbf{w})$ 函数对于 $\mathbf{w}$ 是**凸函数**！这意味着梯度下降法可以保证找到全局最小值。这是选择 MLE 而非 MSE 的一个重要原因。

#### 5.2 梯度推导：损失函数对参数 $\mathbf{w}$ 求导

我们的目标是计算梯度 $\nabla_{\mathbf{w}} J(\mathbf{w}) = \frac{\partial J(\mathbf{w})}{\partial \mathbf{w}}$，以便使用梯度下降法。梯度是一个向量，其第 $j$ 个分量是 $\frac{\partial J(\mathbf{w})}{\partial w_j}$。

*   **推导链条 (Chain Rule):** 我们需要从 $J$ 对 $w_j$ 求导。中间涉及到 $p_i = \sigma(z_i)$ 和 $z_i = \mathbf{x}_i \cdot \mathbf{w} = \sum_k x_{ik} w_k$。
    $$ \frac{\partial J}{\partial w_j} = \frac{\partial}{\partial w_j} \left( -\frac{1}{N} \sum_{i=1}^N [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ] \right) $$
    $$ \frac{\partial J}{\partial w_j} = -\frac{1}{N} \sum_{i=1}^N \frac{\partial}{\partial w_j} [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ] $$
    根据链式法则，$\frac{\partial [\cdot]}{\partial w_j} = \frac{\partial [\cdot]}{\partial p_i} \frac{\partial p_i}{\partial z_i} \frac{\partial z_i}{\partial w_j}$。我们分步计算这三项：

    1.  **$\frac{\partial z_i}{\partial w_j}$：**
        $z_i = \mathbf{x}_i \cdot \mathbf{w} = x_{i1}w_1 + x_{i2}w_2 + ... + x_{ij}w_j + ... + x_{i,d+1}w_{d+1}$
        所以，$z_i$ 对 $w_j$ 求偏导，只有 $x_{ij}w_j$ 这一项有关，结果就是：
        $$ \frac{\partial z_i}{\partial w_j} = x_{ij} $$
        (其中 $x_{ij}$ 是第 $i$ 个样本的第 $j$ 个特征值，如果 $j=d+1$，则 $x_{i,d+1}=1$)

    2.  **$\frac{\partial p_i}{\partial z_i}$：Sigmoid 函数的导数 (PPT 中有)**
        $p_i = \sigma(z_i) = (1 + e^{-z_i})^{-1}$
        使用导数公式 $(u^{-1})' = -u^{-2} u'$ 和 $(e^{-z_i})' = -e^{-z_i}$：
        $$ \frac{d p_i}{d z_i} = -(1 + e^{-z_i})^{-2} \cdot (-e^{-z_i}) $$
        $$ \frac{d p_i}{d z_i} = \frac{e^{-z_i}}{(1 + e^{-z_i})^2} $$
        这个形式不够简洁，我们把它变成 $p_i$ 的形式：
        $$ \frac{d p_i}{d z_i} = \frac{1}{1 + e^{-z_i}} \cdot \frac{e^{-z_i}}{1 + e^{-z_i}} $$
        $$ \frac{d p_i}{d z_i} = \frac{1}{1 + e^{-z_i}} \cdot \frac{(1 + e^{-z_i}) - 1}{1 + e^{-z_i}} $$
        $$ \frac{d p_i}{d z_i} = \frac{1}{1 + e^{-z_i}} \cdot \left( 1 - \frac{1}{1 + e^{-z_i}} \right) $$
        因为 $p_i = \frac{1}{1 + e^{-z_i}}$，所以得到一个非常优雅的结果：
        $$ \frac{d p_i}{d z_i} = p_i (1 - p_i) $$
        **直观理解：** Sigmoid 函数的导数在其自身等于 0.5 时最大（曲线最陡），在接近 0 或 1 时最小（曲线最平缓）。这个性质在反向传播中很有用。

    3.  **$\frac{\partial [\cdot]}{\partial p_i}$：**
        $$ \frac{\partial}{\partial p_i} [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ] = y_i \frac{1}{p_i} + (1 - y_i) \frac{1}{1 - p_i} \cdot (-1) $$
        $$ = \frac{y_i}{p_i} - \frac{1 - y_i}{1 - p_i} $$
        通分合并：
        $$ = \frac{y_i(1 - p_i) - p_i(1 - y_i)}{p_i(1 - p_i)} $$
        $$ = \frac{y_i - y_i p_i - p_i + y_i p_i}{p_i(1 - p_i)} $$
        $$ = \frac{y_i - p_i}{p_i(1 - p_i)} $$

    *   **组合起来：**
        $$ \frac{\partial [\cdot]}{\partial w_j} = \left( \frac{y_i - p_i}{p_i(1 - p_i)} \right) \cdot (p_i (1 - p_i)) \cdot (x_{ij}) $$
        $$ = (y_i - p_i) x_{ij} $$
        这个结果非常简洁！

    *   **代回 $\frac{\partial J}{\partial w_j}$：**
        $$ \frac{\partial J}{\partial w_j} = -\frac{1}{N} \sum_{i=1}^N (y_i - p_i) x_{ij} $$
        $$ \frac{\partial J}{\partial w_j} = \frac{1}{N} \sum_{i=1}^N (p_i - y_i) x_{ij} $$
        这和 PPT 中的 $\frac{\partial L(\mathbf{w})}{\partial w_j} = \frac{1}{N} \sum_{i=1}^N x_{ij} (p_i - y_i)$ (忽略了因子2，可能 PPT 的 L 定义不同或省略了) 完全一致！

*   **梯度的向量/矩阵形式 (Vector/Matrix Form):**
    梯度 $\nabla_{\mathbf{w}} J(\mathbf{w})$ 是一个列向量，第 $j$ 个元素是 $\frac{\partial J}{\partial w_j}$。我们可以把所有这些分量组合起来：
    $$ \nabla_{\mathbf{w}} J(\mathbf{w}) = \begin{bmatrix} \frac{\partial J}{\partial w_1} \\ \vdots \\ \frac{\partial J}{\partial w_{d+1}} \end{bmatrix} = \begin{bmatrix} \frac{1}{N} \sum_{i=1}^N (p_i - y_i) x_{i1} \\ \vdots \\ \frac{1}{N} \sum_{i=1}^N (p_i - y_i) x_{i,d+1} \end{bmatrix} $$
    这个形式正好可以写成矩阵乘积：
    $$ \nabla_{\mathbf{w}} J(\mathbf{w}) = \frac{1}{N} \begin{bmatrix} x_{11} & x_{21} & \cdots & x_{N1} \\ \vdots & \vdots & \ddots & \vdots \\ x_{1,d+1} & x_{2,d+1} & \cdots & x_{N,d+1} \end{bmatrix} \begin{bmatrix} p_1 - y_1 \\ p_2 - y_2 \\ \vdots \\ p_N - y_N \end{bmatrix} $$
    其中第一个矩阵是设计矩阵 $\mathbf{X}$ 的转置 $\mathbf{X}^T$（维度 $(d+1) \times N$），第二个矩阵是预测概率向量 $\mathbf{p}$ 与真实标签向量 $\mathbf{y}$ 的差（维度 $N \times 1$）。
    $$ \nabla_{\mathbf{w}} J(\mathbf{w}) = \frac{1}{N} \mathbf{X}^T (\mathbf{p} - \mathbf{y}) $$
    *   **这个形式与 PPT 完全一致！** ($\mathbf{p}$ 是所有样本预测概率组成的 $N \times 1$ 列向量)。
    *   **直观解释：** 梯度是**误差向量** $(\mathbf{p} - \mathbf{y})$ 被**特征矩阵转置** $\mathbf{X}^T$ 加权求和的结果，再除以样本数 $N$。误差大的样本、或者特征值 $x_{ij}$ 绝对值大的地方，对梯度的贡献更大。这与线性回归的梯度形式 $\frac{2}{N} \mathbf{X}^T (\mathbf{\hat{y}} - \mathbf{y})$ 非常相似！只是预测值从 $\mathbf{\hat{y}} = \mathbf{Xw}$ 换成了概率 $\mathbf{p} = \sigma(\mathbf{Xw})$，并且损失函数的定义使得常数因子从 2 变成了 1（或省略）。这种相似性不是偶然，它们都源于广义线性模型 (Generalized Linear Models, GLM) 的框架。

#### 5.3 优化：梯度下降法

有了梯度，我们就可以使用梯度下降来更新参数 $\mathbf{w}$ 了：

1.  **初始化：** 随机选择一个初始参数向量 $\mathbf{w}^{(0)}$。
2.  **迭代更新 (第 $t$ 步)：**
    *   计算当前参数 $\mathbf{w}^{(t)}$ 下所有样本的预测概率： $\mathbf{p}^{(t)} = \sigma(\mathbf{X} \mathbf{w}^{(t)})$ （向量化计算）。
    *   计算梯度： $\nabla J(\mathbf{w}^{(t)}) = \frac{1}{N} \mathbf{X}^T (\mathbf{p}^{(t)} - \mathbf{y})$ （向量化计算）。
    *   更新参数： $\mathbf{w}^{(t+1)} = \mathbf{w}^{(t)} - \alpha \nabla J(\mathbf{w}^{(t)})$，其中 $\alpha$ 是学习率。
3.  **停止条件：** 重复步骤 2，直到 $\mathbf{w}$ 的变化足够小（收敛），或者达到最大迭代次数。

### 6. 示例与应用 (Examples & Application)

*   **简单示例：** 假设我们根据学习时长 $x$ 预测学生能否通过考试 $y \in \{0, 1\}$。逻辑回归会拟合一条 S 形曲线，给出不同学习时长对应的通过概率 $p = \sigma(wx+b)$。
*   **应用场景：**
    *   **医疗诊断：** 根据病人的各种生理指标预测是否患有某种疾病。
    *   **金融风控：** 根据用户的信用记录、收入等预测是否会违约。
    *   **自然语言处理：** 垃圾邮件检测、情感分析（判断评论是正面还是负面）。
    *   **图像识别：** 简单的图像分类（虽然现在深度学习更常用）。
*   **预测：** 模型训练好得到最优 $\mathbf{w}^*$ 后，对于一个新的样本 $\mathbf{x}_{new}$：
    1.  计算概率： $p_{pred} = \sigma(\mathbf{x}_{new} \cdot \mathbf{w}^*)$。
    2.  做出决策：设定一个阈值（通常是 0.5），如果 $p_{pred} > 0.5$，则预测类别为 1；否则预测类别为 0。这个阈值也可以根据具体应用的需求调整（比如，宁可错杀不可放过垃圾邮件，可能会调低阈值）。

### 7. 知识点总结与要点提炼 (Summary & Key Takeaways)

*   **核心任务：** 解决二分类问题，预测样本属于某个类别的概率。
*   **模型：** $p = P(Y=1 | \mathbf{x}; \mathbf{w}) = \sigma(\mathbf{x} \cdot \mathbf{w}) = \frac{1}{1 + e^{-\mathbf{x} \cdot \mathbf{w}}}$。本质是用线性模型拟合对数几率 $\ln(p/(1-p))$。
*   **Sigmoid 函数：** $\sigma(z) = 1 / (1 + e^{-z})$，将线性输出 $z$ 映射到 $(0, 1)$ 概率空间，具有 S 形曲线。其导数为 $\sigma'(z) = \sigma(z)(1 - \sigma(z))$。
*   **损失函数：** 基于最大似然估计推导出的**二元交叉熵损失** (Negative Average Log-Likelihood)：
    $J(\mathbf{w}) = -\frac{1}{N} \sum_{i=1}^N [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ]$。该损失函数是凸函数。
*   **梯度：** 损失函数对参数 $\mathbf{w}$ 的梯度为：
    $\nabla_{\mathbf{w}} J(\mathbf{w}) = \frac{1}{N} \mathbf{X}^T (\mathbf{p} - \mathbf{y})$。形式与线性回归梯度相似。
*   **优化：** 通常使用梯度下降法或其变种（如 Adam, SGD）来最小化损失函数，找到最优参数 $\mathbf{w}$。
*   **预测：** 计算 $p_{pred} = \sigma(\mathbf{x}_{new} \cdot \mathbf{w}^*)$，然后根据阈值（如 0.5）判断类别。

### 8. 学科思想与延伸思考 (Underlying Philosophy & Further Thinking)

*   **连接与转换：** 逻辑回归巧妙地通过 Sigmoid 函数将线性回归的输出（无界实数）与概率（有界(0,1)）联系起来。这种**转换思想**在机器学习中非常常见（例如激活函数在神经网络中的作用）。
*   **概率视角：** 逻辑回归是**从概率的角度**来建模分类问题。它不仅仅给出一个分类结果，还给出了这个结果的**置信度**（概率）。这对于需要风险评估的场景非常有用。
*   **损失函数的意义：** 交叉熵损失源于信息论和最大似然估计，其背后有深刻的概率统计基础。选择合适的损失函数对于模型训练至关重要，它直接体现了我们希望模型学习到的目标。
*   **广义线性模型 (GLM)：** 线性回归和逻辑回归都可以看作是广义线性模型的特例。GLM 提供了一个统一的框架来处理不同类型的因变量（连续、二元、计数等），其核心思想都是通过一个**连接函数 (link function)** 将因变量的期望与线性预测器 $\mathbf{x} \cdot \mathbf{w}$ 联系起来。
    *   线性回归：连接函数是恒等函数 (Identity link)，$E[Y|\mathbf{x}] = \mathbf{x} \cdot \mathbf{w}$。
    *   逻辑回归：连接函数是对数几率函数 (Logit link)，$\text{logit}(E[Y|\mathbf{x}]) = \ln(\frac{p}{1-p}) = \mathbf{x} \cdot \mathbf{w}$。
*   **思考：**
    *   如果分类问题不止两个类别（例如手写数字识别 0-9），逻辑回归还能用吗？（提示：可以扩展为 Softmax 回归/多项逻辑回归）
    *   梯度下降中的学习率 $\alpha$ 如何选择？太大或太小会有什么影响？
    *   除了梯度下降，还有没有其他方法可以求解逻辑回归的参数？（提示：牛顿法等）

---

## 作业：用 numpy 实现逻辑回归

PPT 最后布置了一个用 Numpy 实现逻辑回归的作业，这非常好，可以让你把理论知识转化为实践能力。

*   **目标：** 实现一个 `LogisticRegression` 类，包含 `fit(X, Y)` 和 `predict(X)` 方法。
*   **关键步骤 (`fit` 函数):**
    1.  **数据预处理：**
        *   获取数据维度 N (样本数) 和 d (特征数)。
        *   **扩充 X：** 在 X 矩阵的最后一列添加全为 1 的列，得到 $N \times (d+1)$ 的矩阵 $\mathbf{X}$ (用于包含偏置项 $b$)。`np.hstack((X, np.ones((N, 1))))`
        *   **初始化 w：** 随机初始化一个 $(d+1) \times 1$ 的参数向量 $\mathbf{w}$。`np.random.randn(d + 1, 1)`
    2.  **迭代优化 (循环指定轮数 `epochs`):**
        *   **计算线性组合 z：** $\mathbf{z} = \mathbf{X} \mathbf{w}$ (`X @ w`)。维度 $N \times 1$。
        *   **计算概率 p (Sigmoid)：** $\mathbf{p} = \sigma(\mathbf{z}) = 1 / (1 + \text{np.exp}(-\mathbf{z}))$。维度 $N \times 1$。
        *   **计算损失函数 J (交叉熵)：**
            $J = -\frac{1}{N} \sum [ y_i \ln p_i + (1 - y_i) \ln(1 - p_i) ]$
            用 Numpy 实现： `loss = -1/N * np.sum(Y * np.log(p) + (1 - Y) * np.log(1 - p))`。需要注意 `p` 可能非常接近 0 或 1 导致 `log` 计算溢出，可以加一个很小的 `epsilon`：`np.log(p + epsilon)` 和 `np.log(1 - p + epsilon)`。
            将 `loss` 存入列表。
        *   **计算梯度 grad：**
            $\nabla J = \frac{1}{N} \mathbf{X}^T (\mathbf{p} - \mathbf{Y})$ (`(1/N) * X.T @ (p - Y)`)。维度 $(d+1) \times 1$。
        *   **更新参数 w：** $\mathbf{w} = \mathbf{w} - \alpha \cdot \nabla J$ (`w = w - learning_rate * grad`)。
    3.  **返回：** 包含每轮损失值的列表 `loss`。
*   **关键步骤 (`predict` 函数):**
    1.  **输入：** 测试数据 `X_test` ($N_{test} \times d$)。
    2.  **扩充 X_test：** 同样在最后一列加 1，得到 $\mathbf{X}_{test}$ ($N_{test} \times (d+1)$)。
    3.  **计算概率：** 使用训练好的 $\mathbf{w}$，计算 $\mathbf{p}_{pred} = \sigma(\mathbf{X}_{test} \mathbf{w})$。维度 $N_{test} \times 1$。
    4.  **生成预测标签：**
        *   设定阈值 `threshold = 0.5`。
        *   `\mathbf{y}_{pred\_label} = (\mathbf{p}_{pred} > \text{threshold}).astype(int)`。这将生成一个 $N_{test} \times 1$ 的向量，元素为 0 或 1。
    5.  **返回：** 预测概率向量 $\mathbf{p}_{pred}$ 和 预测标签向量 $\mathbf{y}_{pred\_label}$。

*   **向量化的优势：** 注意在 `fit` 和 `predict` 中，所有的计算（矩阵乘法、Sigmoid、损失、梯度）都应该是向量化的，避免使用 Python 的 `for` 循环遍历样本，这样才能充分利用 Numpy 的效率。

希望这次讲解能帮助你更深入地理解回归分析，特别是逻辑回归背后的原理和推导过程。动手实现作业是巩固理解的最佳方式，如果在实现过程中遇到任何问题，随时可以再讨论！