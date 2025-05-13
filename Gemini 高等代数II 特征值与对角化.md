#review 
### Key Ideas

- Unstd coordinates, bases and vectors: coordinates are the results of measuring vectors using different bases.
- Bases should be used to represent other *vectors* on its own right. It natural to express another base using current base.
- Similar Matrices: they have the same e'vals and eigen-polynomials.
- Hamilton-Caylay: for a matrix A, $f_{A}(\lambda)|_{\lambda=A} =0_{n\times n}$.
- A new viewpoint: *the subspace of eigenvectors for a eigenvalue*.
- This kind of subspace works in analysing the diagonalizablity. k in $(\lambda-\lambda_{i})^{k}$ stands for the alge-repeated-times, while the *dimension* of a *subspace* for an e'val stands for the geo-repeated times.
- Matrix is diagonalizable $\Leftrightarrow$ 1. $\lambda$'s are in proper *field*; 2. for every $\lambda$ , *alge* == *geo*.

### 线性变换与矩阵的桥梁

#### 引入与动机 (Hook & Motivation)

想象一下我们在二维平面上进行各种操作：旋转一个图形、拉伸一个图形、或者沿着某个方向投影一个图形。这些操作都可以看作是把一个点（向量）变成另一个点（向量）。有些操作非常“规矩”，比如旋转或拉伸，它们保持了向量加法和数量乘法的特性，我们称之为**线性变换**。

比如，把平面上的所有点绕原点逆时针旋转 90 度。向量 $(1, 0)$ 变成了 $(0, 1)$，向量 $(0, 1)$ 变成了 $(-1, 0)$。如果我们知道任何一个向量 $(x, y)$ 都可以写成 $x(1, 0) + y(0, 1)$，那么旋转后它会变成什么样呢？由于这个变换是“线性”的，它会把 $x(1, 0) + y(0, 1)$ 变成 $x$ 乘以 $(1, 0)$ 旋转后的向量，加上 $y$ 乘以 $(0, 1)$ 旋转后的向量。也就是变成 $x(0, 1) + y(-1, 0) = (-y, x)$。

看到了吗？只要知道线性变换对基向量（比如这里的 $(1, 0)$ 和 $(0, 1)$）的作用，我们就能知道它对任何向量的作用。

但是，用语言描述“逆时针旋转 90 度”或者写出公式 $(-y, x)$ 有点抽象，特别是对于更高维度的空间。有没有一种统一、简洁、并且适合计算（计算机处理）的方式来表示这些线性变换呢？

答案就是**矩阵**！矩阵就是用来“捕捉”线性变换对基向量的影响的工具。一旦我们有了矩阵，线性变换的应用就变成了简单的矩阵乘法。

#### 必要知识回顾 (Prerequisite Review)

在我们深入之前，快速回顾几个你需要牢记的概念：

1.  **向量空间 (Vector Space):** 一组向量以及定义在其上的加法和数量乘法，满足一些基本性质。可以想象成允许向量进行加减和伸缩的空间，比如二维平面、三维空间，或者多项式空间、函数空间等。
2.  **基 (Basis):** 向量空间中的一组特殊的向量，它们是**线性无关**的，并且可以**线性组合**出空间中的任何一个向量。基的数量称为空间的**维数**。基向量就像我们空间中的“坐标轴”。
3.  **坐标 (Coordinates):** 对于一个向量 $\alpha$ 和一组基 $\epsilon_1, \dots, \epsilon_n$，向量 $\alpha$ 可以唯一地表示为 $\alpha = x_1 \epsilon_1 + \dots + x_n \epsilon_n$。这里的数 $x_1, \dots, x_n$ 就是向量 $\alpha$ 在这组基下的坐标。通常我们把坐标写成列向量 $X = (x_1, \dots, x_n)^T$。
4.  **线性变换 (Linear Transformation):** 从一个<font color="#ffff00">向量空间</font> $V$ 到<font color="#ffff00">另一个向量空间</font> $W$ 的映射 $A$，满足对任意向量 $\alpha, \beta \in V$ 和数 $k, l$：$A(k\alpha + l\beta) = kA(\alpha) + lA(\beta)$。这说明线性变换保持线性组合。
5.  **矩阵乘法 (Matrix Multiplication):** 特别是矩阵乘以列向量。一个 $m \times n$ 矩阵 $A$ 乘以一个 $n \times 1$ 列向量 $X$，结果是一个 $m \times 1$ 列向量 $Y=AX$。记住矩阵乘法的列视角：$AX$ 是矩阵 $A$ 的列向量的线性组合，组合系数就是向量 $X$ 的分量。

#### 直观解释与感性认识 (Intuitive Explanation)

想象你的向量空间 $V$ 是一个房间，你选择了一组“测量尺子”作为基 $\epsilon_1, \dots, \epsilon_n$。任何一个向量 $\alpha$ 都<font color="#ffff00">可以用这组尺子量出它沿着每个方向的分量</font>（坐标, *coordinates*）。

现在有一个线性变换 $A$（比如一个神奇的“变形”操作）。你想知道这个变形操作是怎样的。<font color="#ffff00">最简单的办法就是看看它把你的那些“测量尺子”（基向量）变成了什么样子</font>。

$A$ 把 $\epsilon_1$ 变成了 $A\epsilon_1$，把 $\epsilon_2$ 变成了 $A\epsilon_2$，...，把 $\epsilon_n$ 变成了 $A\epsilon_n$。

由于 $A\epsilon_i$ 仍然是 $V$ 中的向量（如果 $A$ 是从 $V$ 到 $V$ 的线性变换），它们也可以用你原来的那组尺子 $\epsilon_1, \dots, \epsilon_n$ 来<font color="#ffff00">测量和表示</font>。

>Transformation may squash current vector into a reduced vector space.

$A\epsilon_1 = a_{11}\epsilon_1 + a_{21}\epsilon_2 + \dots + a_{n1}\epsilon_n$
$A\epsilon_2 = a_{12}\epsilon_1 + a_{22}\epsilon_2 + \dots + a_{n2}\epsilon_n$
...
$A\epsilon_n = a_{1n}\epsilon_1 + a_{2n}\epsilon_2 + \dots + a_{nn}\epsilon_n$

这些系数 $a_{ij}$ 就是线性变换 $A$ 在这组基下的“行为记录”。把这些记录整理一下，就得到了一个矩阵。

#### 逐步形式化与精确定义 (Gradual Formalization)

**定理 7.3.1** 说的是：如果你确定了线性变换对**一组基**的作用，那么这个线性变换就被**唯一地**确定了。
设 $\epsilon_1, \dots, \epsilon_n$ 是 $V$ 的一组基，对于任意给定的向量 $\alpha_1, \dots, \alpha_n$（它们可以是 $V$ 中的，也可以是另一个向量空间 $W$ 中的），都唯一存在一个线性变换 $A: V \to W$ 使得 $A\epsilon_i = \alpha_i$ 对所有 $i=1, \dots, n$ 成立。

**为什么是唯一的？**
因为任何向量 $\beta \in V$ 都可以唯一地写成基向量的线性组合 $\beta = c_1\epsilon_1 + \dots + c_n\epsilon_n$。
如果 $A$ 是一个线性变换，根据线性性，它作用在 $\beta$ 上必须是 $A(\beta) = A(c_1\epsilon_1 + \dots + c_n\epsilon_n) = c_1A(\epsilon_1) + \dots + c_n A(\epsilon_n)$.
如果 $A\epsilon_i$ 已经确定为 $\alpha_i$，那么 $A(\beta)$ 就必须等于 $c_1\alpha_1 + \dots + c_n\alpha_n$。对于任何向量 $\beta$，其像 $A(\beta)$ 的值是唯一确定的，所以线性变换 $A$ 是唯一的。

**定义 7.3.1** formalizes the matrix representation.
设 $\epsilon_1, \dots, \epsilon_n$ 是 $V$ 的一组基，$A: V \to V$ 是一个线性变换。将基向量的像用这组基表示：
$A\epsilon_1 = a_{11}\epsilon_1 + a_{21}\epsilon_2 + \dots + a_{n1}\epsilon_n$
$A\epsilon_2 = a_{12}\epsilon_1 + a_{22}\epsilon_2 + \dots + a_{n2}\epsilon_n$
...
$A\epsilon_n = a_{1n}\epsilon_1 + a_{2n}\epsilon_2 + \dots + a_{nn}\epsilon_n$

这些系数 $a_{ij}$ 排列成的矩阵：
$$
A = \begin{pmatrix}
a_{11} & a_{12} & \cdots & a_{1n} \\
a_{21} & a_{22} & \cdots & a_{2n} \\
\vdots & \vdots & \ddots & \vdots \\
a_{n1} & a_{n2} & \cdots & a_{nn}
\end{pmatrix}
$$

>It is a transpose from what we normally use, about indices.

称为线性变换 $A$ 在基 $\epsilon_1, \dots, \epsilon_n$ 下的矩阵。**注意**这里的系数排列方式：$A\epsilon_j$ 的坐标 $(a_{1j}, a_{2j}, \dots, a_{nj})^T$ 构成了矩阵的**第 $j$ 列**。

用讲义中的形式表达式：
$A (\epsilon_1, \dots, \epsilon_n) = (A\epsilon_1, \dots, A\epsilon_n)$
将等号右边写成基向量的线性组合形式：
$(A\epsilon_1, \dots, A\epsilon_n) = (\sum_{i=1}^n a_{i1}\epsilon_i, \dots, \sum_{i=1}^n a_{in}\epsilon_i)$
这可以用矩阵乘法简洁表示为：
$(\epsilon_1, \dots, \epsilon_n) A = (\sum_{i=1}^n \epsilon_i a_{i1}, \dots, \sum_{i=1}^n \epsilon_i a_{in}) = (\sum_{i=1}^n a_{i1}\epsilon_i, \dots, \sum_{i=1}^n a_{in}\epsilon_i)$
**所以，形式表达式 $A(\epsilon_1, \dots, \epsilon_n) = (\epsilon_1, \dots, \epsilon_n)A$ 成立。**（这里 $(\epsilon_1, \dots, \epsilon_n)$ 被看作一个“行向量”包含向量，与矩阵相乘得到一个新行向量，其分量是变换后的基向量）。

**命题 7.3.2** 总结了这个重要的对应关系：给定一个线性空间 $V$ 和一组基，每一个线性变换 $A$ 都唯一对应一个 $n$ 阶方阵 $A$（这个矩阵取决于基），反过来，每一个 $n$ 阶方阵 $A$ 也唯一对应一个线性变换 $A$（这个变换就是把基向量 $\epsilon_i$ 变换成以 $A$ 的第 $i$ 列为坐标的向量）。这是一个**一一对应**。

这个一一对应关系非常重要，因为它把对线性变换的研究转化为了对矩阵的研究，而矩阵是数值计算友好的。

**定理 7.3.3** 进一步说明了这个对应关系的好处：它保持了线性变换的运算。
设线性变换 $A, B$ 在同一组基下的矩阵分别是 $A, B$。
1.  和 $A+B$ 对应的矩阵是 $A+B$。
2.  数乘 $kA$ 对应的矩阵是 $kA$。
3.  乘积（复合）$AB$ 对应的矩阵是 $AB$。
4.  可逆变换 $A^{-1}$ 对应的矩阵是 $A^{-1}$。

**为什么是这样？**
我们以乘积为例：$A(B(\epsilon_j))$。
$$B(\epsilon_j) = \sum_k b_{kj}\epsilon_k$$
$$A(B(\epsilon_j)) = A(\sum_k b_{kj}\epsilon_k) = \sum_k b_{kj} A(\epsilon_k)$$ (利用 $A$ 的线性性)
$$A(\epsilon_k) = \sum_i a_{ik}\epsilon_i$$
$$A(B(\epsilon_j)) = \sum_k b_{kj} (\sum_i a_{ik}\epsilon_i) = \sum_k \sum_i a_{ik}b_{kj} \epsilon_i = \sum_i (\sum_k a_{ik}b_{kj}) \epsilon_i$$
注意 $\sum_k a_{ik}b_{kj}$ 正好是矩阵乘积 $AB$ 的 $(i, j)$ 位置的元素。
所以，$A(B(\epsilon_j))$ 在这组基下的坐标就是 $(AB)$ 的第 $j$ 列。根据矩阵表示的定义，这就是复合变换 $AB$ 在这组基下的矩阵。

#### 核心原理与推导过程 (Core Principles & Derivation Walkthrough)

**定理 7.3.4 (线性变换下像的坐标)**：这个定理非常实用。它告诉我们，知道了<font color="#ffff00">向量的坐标和线性变换的矩阵，怎么求变换后向量的坐标</font>。
设 $\alpha \in V$ 在基 $\epsilon_1, \dots, \epsilon_n$ 下的坐标是 $X = (x_1, \dots, x_n)^T$。
所以 $\alpha = x_1\epsilon_1 + \dots + x_n\epsilon_n = (\epsilon_1, \dots, \epsilon_n)X$.
设 $A$ 是线性变换 $A$ <font color="#ffff00">在这组基下的矩阵</font>。
我们要找 $A\alpha$ 在同一组基下的坐标 $Y = (y_1, \dots, y_n)^T$.
$A\alpha = A((\epsilon_1, \dots, \epsilon_n)X)$
由于线性变换作用在线性组合上等于对分量作用后线性组合（这是线性的定义），更正式地，对于矩阵表示 $(\epsilon_1, \dots, \epsilon_n)X$，线性变换 $A$ 的作用可以看作矩阵 $A$ 的作用（因为我们用矩阵表示了 $A$），即 $A((\epsilon_1, \dots, \epsilon_n)X) = (A\epsilon_1, \dots, A\epsilon_n)X$.
根据形式表达式 $A(\epsilon_1, \dots, \epsilon_n) = (\epsilon_1, \dots, \epsilon_n)A$，我们有：
$A\alpha = (A\epsilon_1, \dots, A\epsilon_n)X = (\epsilon_1, \dots, \epsilon_n)AX$.
同时，$A\alpha$ 在这组基下的坐标是 $Y$，所以 $A\alpha = (\epsilon_1, \dots, \epsilon_n)Y$.
由于坐标是唯一的，我们比较 $(\epsilon_1, \dots, \epsilon_n)Y = (\epsilon_1, \dots, \epsilon_n)AX$，得到 $Y = AX$.

这就是说，**在选定一组基后，向量的坐标变成列向量，线性变换变成矩阵，线性变换作用在向量上的结果（的坐标）就是矩阵乘以向量的坐标列向量。** $A\alpha \leftrightarrow AX$.

#### 换基与相似矩阵

生活中的坐标系不止一种（直角坐标，极坐标），向量空间中的基也是如此。同一个线性变换，在不同的基下会有不同的矩阵表示。这是“相似矩阵”概念的来源。

**定理 7.3.4 (换基)**：设 $\{\epsilon_1, \dots, \epsilon_n\}$ 和 $\{\eta_1, \dots, \eta_n\}$ 是 $V$ 的两组基。设从基 $\epsilon$ 到基 $\eta$ 的过渡矩阵是 $P$。这意味着 $\eta_j = \sum_i p_{ij} \epsilon_i$，或者写作 $(\eta_1, \dots, \eta_n) = (\epsilon_1, \dots, \epsilon_n)P$. 矩阵 $P$ 是可逆的。
设线性变换 $A$ 在基 $\epsilon$ 下的矩阵是 $A$，在基 $\eta$ 下的矩阵是 $B$. 则 $$B = P^{-1}AP$$

> [!NOTE]
> **推导：**
> $A$ 在基 $\epsilon$ 下的矩阵是 $A$，表示 $$A(\epsilon_1, \dots, \epsilon_n) = (\epsilon_1, \dots, \epsilon_n)A$$$A$ 在基 $\eta$ 下的矩阵是 $B$，表示 $$A(\eta_1, \dots, \eta_n) = (\eta_1, \dots, \eta_n)B$$我们知道 $$(\eta_1, \dots, \eta_n) = (\epsilon_1, \dots, \epsilon_n)P$$将此代入第二个等式：
> $A((\epsilon_1, \dots, \epsilon_n)P) = ((\epsilon_1, \dots, \epsilon_n)P)B$
> 利用线性变换对矩阵乘法的性质（可以视为 $A$ 作用在向量组上）：
> $(A\epsilon_1, \dots, A\epsilon_n)P = (\epsilon_1, \dots, \epsilon_n)PB$
> 再利用第一个等式 $A(\epsilon_1, \dots, \epsilon_n) = (\epsilon_1, \dots, \epsilon_n)A$:
> $(\epsilon_1, \dots, \epsilon_n)AP = (\epsilon_1, \dots, \epsilon_n)PB$
> 由于 $\epsilon_1, \dots, \epsilon_n$ 是一组基，它们是线性无关的，所以两边的矩阵必须相等（这可以理解为，如果 $(\epsilon_1, \dots, \epsilon_n)C = (\epsilon_1, \dots, \epsilon_n)D$，那么 $\sum c_{ij}\epsilon_i = \sum d_{ij}\epsilon_i$，由基的表示唯一性，$c_{ij}=d_{ij}$，所以 $C=D$）。
> $AP = PB$
> 因为 $P$ 是过渡矩阵，它一定是可逆的。将等式左乘 $P^{-1}$:
> $P^{-1}AP = P^{-1}PB = IB = B$.
> 所以 $B = P^{-1}AP$.
> 

**定义 7.5.2 (相似矩阵)**：如果存在可逆矩阵 $P$，使得 $B = P^{-1}AP$，则称矩阵 $A$ 与 $B$ **相似**，记作 $A \sim B$.

**定理 7.3.5** 和其后面的说明强调：同一个线性变换在不同基下的矩阵是相似的。反之，如果两个矩阵相似，它们可以看作是同一个线性变换在不同基下的矩阵。**相似是矩阵的一种等价关系，相似的矩阵代表的是同一种“内在”的线性变换。**

#### 相似矩阵的性质

相似矩阵因为<font color="#ffff00">代表同一个线性变换，所以它们有很多共同的、反映线性变换本质的性质</font>。
**性质 1-4** 列举了一些：秩、转置的相似性、加常数矩阵、数乘、幂次、多项式。
**性质 5** 是一个乘法性质，但需要公共的可逆矩阵 $P$，这限制了其应用范围。
**性质 (3) 可逆性**: $A$ 可逆当且仅当 $B$ 可逆，且 $A^{-1} \sim B^{-1}$。**原因：** 如果 $B = P^{-1}AP$，且 $A$ 可逆，则 $A^{-1}$ 存在。考虑 $$(P^{-1}A^{-1}P)B = P^{-1}A^{-1}P P^{-1}AP = P^{-1}A^{-1}IAP = P^{-1}A^{-1}AP = P^{-1}IP = P^{-1}P = E$$. 所以 $B$ 可逆且 $B^{-1} = P^{-1}A^{-1}P$. 这说明 $A^{-1}$ 和 $B^{-1}$ 也相似。反之亦然。

最重要的共同性质在讲义后面提到：**相似矩阵有相同的特征多项式，从而有相同的特征值。**

#### 示例与应用 (初步)

现在我们有了表示线性变换的工具（矩阵），以及如何在不同表示之间转换（相似）。下一步就是理解线性变换的“本质”是什么。哪些性质是矩阵表示无关的，而是线性变换本身固有的？这引出了特征值和特征向量的概念。

---

### 特征值和特征向量：寻找特殊的向量

#### 引入与动机 (Hook & Motivation)

回到线性变换的几何图像：旋转、拉伸、投影。大多数向量在经过线性变换后，不仅长度会改变，方向也会改变。比如平面上的逆时针 90 度旋转，除了零向量，所有非零向量的方向都变了。

但是，对于某些线性变换，是否存在一些**特殊的非零向量**，它们在变换后**方向不变**（或者仅仅是反向）？它们仅仅被“拉伸”或“压缩”了。

考虑一个沿着 x 轴方向拉伸 2 倍的变换：$(x, y) \to (2x, y)$。
向量 $(1, 0)$ 变成了 $(2, 0)$，它只是被拉长了 2 倍，方向没变。
向量 $(0, 1)$ 变成了 $(0, 1)$，它没变，相当于被拉长了 1 倍，方向也没变。
向量 $(1, 1)$ 变成了 $(2, 1)$，方向改变了。

这里的 $(1, 0)$ 和 $(0, 1)$ 就是这种特殊的向量，它们的方向在变换下保持不变。我们称这些向量为**特征向量** (Eigenvector)，而它们被拉伸（或压缩）的比例称为**特征值** (Eigenvalue)。

<font color="#ffff00">特征向量指明了线性变换作用下“稳定的方向”，而特征值说明了沿着这些方向的“缩放因子”。理解了一个线性变换在特征向量上的作用，就抓住了这个变换最核心、最本质的特性</font>。

#### 逐步形式化与精确定义 (Gradual Formalization)

**定义 7.4.1 (线性变换的特征值和特征向量)**：
设 $V$ 是向量空间，$A$ 是 $V$ 上的线性变换。如果存在一个常数 $\lambda_0 \in P$ (数域) 和一个**非零向量** $\alpha \in V$，使得：
$A\alpha = \lambda_0 \alpha$
则称 $\lambda_0$ 是线性变换 $A$ 的一个**特征值**，称向量 $\alpha$ 是 $A$ 的属于特征值 $\lambda_0$ 的一个**特征向量**。

**强调：** 特征向量必须是**非零向量**。因为 $A0 = 0 = \lambda 0$ 对于任何 $\lambda$ 都成立，零向量在这条等式上提供不了任何有用的信息。

> [!important] 
> **易见** 部分列举了特征向量的一些基本性质：
> 1.  属于同一个特征值 $\lambda_0$ 的**两个非零特征向量的和**（如果和不为零）仍然是属于 $\lambda_0$ 的特征向量。
>     证明：设 $A\xi_1 = \lambda_0 \xi_1$ 且 $A\xi_2 = \lambda_0 \xi_2$，且 $\xi_1 + \xi_2 \neq 0$.
>     $A(\xi_1 + \xi_2) = A\xi_1 + A\xi_2$ (由线性变换的性质)
>     $= \lambda_0 \xi_1 + \lambda_0 \xi_2 = \lambda_0 (\xi_1 + \xi_2)$
>     所以 $\xi_1 + \xi_2$ 也是属于 $\lambda_0$ 的特征向量。
> 2.  属于同一个特征值 $\lambda_0$ 的**特征向量的非零数乘**仍然是属于 $\lambda_0$ 的特征向量。
>     证明：设 $A\xi = \lambda_0 \xi$ 且 $k \neq 0$.
>     $A(k\xi) = kA\xi$ (由线性变换的性质)
>     $= k(\lambda_0 \xi) = (k\lambda_0)\xi$
>     哦等等，讲义里写的是 $k\lambda_0 \xi = \lambda_0 (k\xi)$. 这是对的。
>     所以 $k\xi$ 也是属于 $\lambda_0$ 的特征向量。
> 
> 这些性质说明，**属于同一个特征值 $\lambda_0$ 的所有特征向量，连同零向量，构成一个向量空间**。这个空间称为**特征子空间** $V_{\lambda_0} = \{ \alpha \in V \mid A\alpha = \lambda_0 \alpha \}$. 特征子空间的维数非常重要，我们后面会看到。

#### 如何求特征值和特征向量 (求法)

现在我们将线性变换 $A$ 转换为它在某个基下的矩阵 $A$.
设 $\epsilon_1, \dots, \epsilon_n$ 是 $V$ 的一组基。向量 $\alpha \in V$ 在这组基下的坐标是 $X = (x_1, \dots, x_n)^T$.
线性变换方程 $A\alpha = \lambda_0 \alpha$ 在坐标表示下是什么样子呢？
根据定理 7.3.4，$A\alpha$ 在这组基下的坐标是 $AX$.
$\lambda_0 \alpha$ 在这组基下的坐标是 $\lambda_0 X$.
所以，$A\alpha = \lambda_0 \alpha$ 等价于矩阵方程 $AX = \lambda_0 X$.

$AX = \lambda_0 X$
$AX - \lambda_0 X = 0$
$AX - \lambda_0 IX = 0$ (其中 $I$ 是单位矩阵，因为 $\lambda_0$ 是数，我们不能直接从矩阵中减去一个数，所以乘以单位矩阵 $I$)
$(A - \lambda_0 I)X = 0$ (讲义里写的是 $(\lambda_0 E - A)X = 0$，这仅仅是差一个负号，不影响解空间，但影响特征多项式的定义)

这是一个**齐次线性方程组**。我们正在寻找**非零向量** $\alpha$，对应于寻找**非零坐标向量** $X$.
齐次线性方程组 $(A - \lambda_0 I)X = 0$ 有非零解 $X$ 的充要条件是系数矩阵 $(A - \lambda_0 I)$ 不可逆。
矩阵不可逆的充要条件是它的行列式为零。
所以，存在非零特征向量的充要条件是 $|A - \lambda_0 I| = 0$. (或者讲义里的 $|\lambda_0 E - A| = 0$)

**定义 7.4.2 (矩阵的特征多项式、特征方程、特征值、特征向量)**：
设 $A$ 是 $P$ 上 $n$ 阶方阵，$\lambda$ 是一个**文字**（或者说变量）。

>矩阵 $\lambda E - A$ 的行列式 $|\lambda E - A|$ 称为 $A$ 的**特征多项式**，记为 $f_A(\lambda)$ (或者讲义里的 $f_A(x)$)。它是一个关于 $\lambda$ (或 $x$) 的**首一 $n$ 次多项式**。
>Coefficient of the first Highest-order term == 1

方程 $|\lambda E - A| = 0$ 称为 $A$ 的**特征方程**。
特征方程的根 $\lambda_0$ 就是矩阵 $A$ 的**特征值** (或特征根)。
对于每一个特征值 $\lambda_0$，满足 $A\xi = \lambda_0 \xi$ (等价于 $(\lambda_0 E - A)\xi = 0$) 的**非零向量** $\xi$ 称为 $A$ 的属于特征值 $\lambda_0$ 的**特征向量**。

> [!important] 
> **注意：** 线性变换的特征值和特征向量是“几何”概念，不依赖于基。矩阵的特征值和特征向量是“代数”概念，是矩阵本身的性质。但通过矩阵表示，它们建立了联系：线性变换的特征值就是其在任意基下矩阵的特征值，线性变换的特征向量可以通过矩阵的特征向量（坐标）还原得到。

#### 求特征值和特征向量的步骤 (总结)

求线性变换 $A$ 的特征值和特征向量：
1.  选定 $V$ 的一组基 $\epsilon_1, \dots, \epsilon_n$，求出 $A$ 在这组基下的矩阵 $A$.
2.  计算矩阵 $A$ 的特征多项式 $f_A(\lambda) = |\lambda E - A|$ (或者 $|\lambda E - A|$)，求解特征方程 $f_A(\lambda) = 0$ 的所有根 $\lambda_1, \dots, \lambda_s$. 这些根就是线性变换 $A$ 的全部特征值。
3.  对于每个特征值 $\lambda_i$，解齐次线性方程组 $(\lambda_i E - A)X = 0$. 找到它的基础解系 $\eta_{i1}, \dots, \eta_{in_i}$.
4.  将这些基础解系中的<font color="#ffff00">向量作为坐标，还原成向量空间的向量</font>：$\alpha_{ij} = (\epsilon_1, \dots, \epsilon_n)\eta_{ij}$. 这些 $\alpha_{ij}$ 就是属于特征值 $\lambda_i$ 的线性无关的特征向量，它们构成特征子空间 $V_{\lambda_i}$ 的一组基。<font color="#ffff00">所有的非零线性组合</font> $c_1\alpha_{i1} + \dots + c_{n_i}\alpha_{in_i}$ 就是属于 $\lambda_i$ 的全部特征向量。

求矩阵 $A$ 的特征值和特征向量的步骤类似，只是不需要第一步和第四步，直接对矩阵进行计算，得到的是坐标向量。

#### 示例与应用 (求特征值/向量)

**例 1 (微商变换)**
： $V = P[x]_{n-1}$ 是次数小于 $n$ 的多项式空间。$D(f(x)) = f'(x)$.
1.  取基 $1, x, x^2, \dots, x^{n-1}$.
    $D(1) = 0$ (坐标 $(0, \dots, 0)^T$)
    $D(x) = 1$ (坐标 $(1, 0, \dots, 0)^T$)
    $D(x^2) = 2x$ (坐标 $(0, 2, 0, \dots, 0)^T$)
    ...
    $D(x^{n-1}) = (n-1)x^{n-2}$ (坐标 $(0, \dots, 0, n-1, 0)^T$)
    D 在这组基下的矩阵 (注意列的构成):
    $$
    D = \begin{pmatrix}
    0 & 1 & 0 & \cdots & 0 \\
    0 & 0 & 2 & \cdots & 0 \\
    \vdots & \vdots & \vdots & \ddots & \vdots \\
    0 & 0 & 0 & \cdots & n-1 \\
    0 & 0 & 0 & \cdots & 0
    \end{pmatrix}
    $$
2.  特征多项式 $|\lambda E - D|$. 这是一个上三角矩阵的行列式，等于对角线元素的乘积。
$$|\lambda E - D| = \begin{vmatrix}
    \lambda & -1 & 0 & \cdots & 0 \\
    0 & \lambda & -2 & \cdots & 0 \\
    \vdots & \vdots & \vdots & \ddots & \vdots \\
    0 & 0 & 0 & \cdots & -(n-1) \\
    0 & 0 & 0 & \cdots & \lambda
    \end{vmatrix} = \lambda^n$$
    特征方程 $\lambda^n = 0$. 唯一的特征值是 $\lambda = 0$ (代数重数是 n)。
3.  求属于 $\lambda = 0$ 的特征向量：解 $(0E - D)X = 0$, 即 $-DX=0$.
    $$
    \begin{pmatrix}
    0 & 1 & 0 & \cdots & 0 \\
    0 & 0 & 2 & \cdots & 0 \\
    \vdots & \vdots & \vdots & \ddots & \vdots \\
    0 & 0 & 0 & \cdots & n-1 \\
    0 & 0 & 0 & \cdots & 0
    \end{pmatrix}
    \begin{pmatrix}
    x_1 \\ x_2 \\ \vdots \\ x_{n-1} \\ x_n
    \end{pmatrix} = \begin{pmatrix}
    0 \\ 0 \\ \vdots \\ 0 \\ 0
    \end{pmatrix}
    $$
    方程组为：
    $x_2 = 0$
    $2x_3 = 0 \Rightarrow x_3 = 0$
    ...
    $(n-1)x_n = 0 \Rightarrow x_n = 0$
    只有 $x_1$ 是自由变量。解向量形式为 $(x_1, 0, \dots, 0)^T$. 取 $x_1=1$，基础解系是 $\eta = (1, 0, \dots, 0)^T$.
    属于 $\lambda=0$ 的特征子空间的维数是 1 (几何重数是 1)。
4.  还原成多项式：$\alpha = 1 \cdot 1 + 0 \cdot x + \dots + 0 \cdot x^{n-1} = 1$.
    特征向量是常数多项式 $c \cdot 1$, $c \neq 0$.
    $D(c) = c' = 0 = 0 \cdot c$. 这验证了常数多项式是属于特征值 0 的特征向量。

**例 3 (逆矩阵的特征向量)**：已知 $A = \begin{pmatrix} 2 & 1 & 1 \\ 1 & 2 & 1 \\ 1 & 1 & 2 \end{pmatrix}$，$\epsilon = \begin{pmatrix} 1 \\ k \\ 1 \end{pmatrix}$ 是 $A^{-1}$ 的一个特征向量，求 $k$.
设 $\lambda_0$ 是 $A^{-1}$ 对应于 $\epsilon$ 的特征值，则 $A^{-1}\epsilon = \lambda_0 \epsilon$.
如果 $A$ 可逆（其特征值都不为 0），且 $\epsilon$ 是 $A^{-1}$ 的特征向量，那么 $\epsilon$ 也是 $A$ 的特征向量，对应的特征值是 $\frac{1}{\lambda_0}$ (见性质 6)。
所以 $A\epsilon = \frac{1}{\lambda_0} \epsilon$.
先求 $A$ 的特征值：
$|\lambda E - A| = \begin{vmatrix} \lambda-2 & -1 & -1 \\ -1 & \lambda-2 & -1 \\ -1 & -1 & \lambda-2 \end{vmatrix}$
将第 2、3 行加到第 1 行：
$= \begin{vmatrix} \lambda-4 & \lambda-4 & \lambda-4 \\ -1 & \lambda-2 & -1 \\ -1 & -1 & \lambda-2 \end{vmatrix} = (\lambda-4) \begin{vmatrix} 1 & 1 & 1 \\ -1 & \lambda-2 & -1 \\ -1 & -1 & \lambda-2 \end{vmatrix}$
列变换 $C_2 - C_1, C_3 - C_1$:
$= (\lambda-4) \begin{vmatrix} 1 & 0 & 0 \\ -1 & \lambda-1 & 0 \\ -1 & 0 & \lambda-1 \end{vmatrix} = (\lambda-4)(\lambda-1)^2$.
特征方程 $(\lambda-4)(\lambda-1)^2 = 0$. A 的特征值是 $\lambda_1 = 4$ (1重), $\lambda_2 = 1$ (2重).
$A$ 可逆，其特征值 4 和 1 都不为 0.
如果 $\epsilon$ 是 $A^{-1}$ 的*特征向量，那么它必是 $A$ 的特征向量*，对应的特征值是 4 或 1.
Case 1: $\epsilon$ 是 $A$ 属于特征值 4 的特征向量。
$A\epsilon = 4\epsilon \Leftrightarrow (4E - A)\epsilon = 0$.
$$
(4E - A)\epsilon = \begin{pmatrix} 4-2 & -1 & -1 \\ -1 & 4-2 & -1 \\ -1 & -1 & 4-2 \end{pmatrix} \begin{pmatrix} 1 \\ k \\ 1 \end{pmatrix} = \begin{pmatrix} 2 & -1 & -1 \\ -1 & 2 & -1 \\ -1 & -1 & 2 \end{pmatrix} \begin{pmatrix} 1 \\ k \\ 1 \end{pmatrix} $$$$= \begin{pmatrix} 2 - k - 1 \\ -1 + 2k - 1 \\ -1 - k + 2 \end{pmatrix} = \begin{pmatrix} 1 - k \\ 2k - 2 \\ 1 - k \end{pmatrix}
$$
要使这是零向量，必须 $1-k=0$ 且 $2k-2=0$. 都得出 $k=1$.
Case 2: $\epsilon$ 是 $A$ 属于特征值 1 的特征向量。
$A\epsilon = 1\epsilon \Leftrightarrow (E - A)\epsilon = 0$.
$$
(E - A)\epsilon = \begin{pmatrix} 1-2 & -1 & -1 \\ -1 & 1-2 & -1 \\ -1 & -1 & 1-2 \end{pmatrix} \begin{pmatrix} 1 \\ k \\ 1 \end{pmatrix} = \begin{pmatrix} -1 & -1 & -1 \\ -1 & -1 & -1 \\ -1 & -1 & -1 \end{pmatrix} \begin{pmatrix} 1 \\ k \\ 1 \end{pmatrix} $$$$= \begin{pmatrix} -1 - k - 1 \\ -1 - k - 1 \\ -1 - k - 1 \end{pmatrix} = \begin{pmatrix} -2 - k \\ -2 - k \\ -2 - k \end{pmatrix}
$$
要使这是零向量，必须 $-2-k=0$, 解出 $k=-2$.
所以 $k$ 的可能取值是 $1$ 或 $-2$. (讲义里的计算结果 $k=1$ 或 $k=-2$ 是对的)。

**例 5 (AB+A 与 BA+A 特征值)**：证明 $AB+A$ 与 $BA+A$ 有相同的特征值。
核心在于证明 $| \lambda E - AB| = | \lambda E - BA|$.
证明方法是利用矩阵的行列式性质和分块矩阵。讲义里的证明是标准方法，我们来走一遍：
考虑分块矩阵 $M_1 = \begin{pmatrix} E & A \\ 0 & \lambda E \end{pmatrix} \begin{pmatrix} \lambda E - AB & 0 \\ B & E \end{pmatrix}$.
其行列式 $|M_1| = |E||A| |\lambda E - AB| |E| = \lambda^n |\lambda E - AB|$. (前面矩阵行列式是 $\lambda^n$)
同时直接计算乘积 $M_1 = \begin{pmatrix} E(\lambda E - AB) + A B & E \cdot 0 + AE \\ 0(\lambda E - AB) + \lambda E B & 0 \cdot 0 + \lambda E E \end{pmatrix} = \begin{pmatrix} \lambda E - AB + AB & A \\ \lambda B & \lambda E \end{pmatrix} = \begin{pmatrix} \lambda E & A \\ \lambda B & \lambda E \end{pmatrix}$.
所以 $\lambda^n |\lambda E - AB| = \begin{vmatrix} \lambda E & A \\ \lambda B & \lambda E \end{vmatrix}$.

考虑分块矩阵 $M_2 = \begin{pmatrix} \lambda E - BA & 0 \\ B & E \end{pmatrix} \begin{pmatrix} E & A \\ 0 & \lambda E \end{pmatrix}$.
其行列式 $|M_2| = |\lambda E - BA| |E| |E| |\lambda E| = |\lambda E - BA| \lambda^n$.
同时直接计算乘积 $M_2 = \begin{pmatrix} (\lambda E - BA)E + 0 \cdot 0 & (\lambda E - BA)A + 0 \cdot \lambda E \\ BE + E \cdot 0 & BA + E \lambda E \end{pmatrix} = \begin{pmatrix} \lambda E - BA & \lambda A - BAA + \lambda E \\ B & BA + \lambda E \end{pmatrix}$
这好像跟讲义里的不一样，讲义里是：
考虑分块矩阵 $\begin{pmatrix} \lambda E & A \\ B & E \end{pmatrix}$ 的行列式。
我们进行分块初等变换：
$\begin{vmatrix} \lambda E & A \\ B & E \end{vmatrix} \xrightarrow{R_1 - AE \cdot R_2} \begin{vmatrix} \lambda E - AEB & A - AE \\ B & E \end{vmatrix}$ (这个分块初等变换规则不常用，且看起来有问题)

我们使用讲义中的另一种思路：
考虑 $\begin{pmatrix} E & A \\ -B & \lambda E \end{pmatrix} \begin{pmatrix} \lambda E - AB & 0 \\ B & E \end{pmatrix} = \begin{pmatrix} \lambda E & A \\ -\lambda B + \lambda E B & -\lambda B A + \lambda E \end{pmatrix} = \begin{pmatrix} \lambda E & A \\ 0 & \lambda E - \lambda BA \end{pmatrix}$.
行列式：$|\begin{pmatrix} E & A \\ -B & \lambda E \end{pmatrix}| |\begin{pmatrix} \lambda E - AB & 0 \\ B & E \end{pmatrix}| = |\lambda E - AB| |\lambda E - AB|$. (左边第一个矩阵行列式是 $|\lambda E - (-B)A| = |\lambda E + BA|$? 不对)

换一种标准方法证明 $| \lambda E - AB | = | \lambda E - BA |$:
若 $A$ 可逆，则 $|\lambda E - AB| = |\lambda E - A(A^{-1}BA)| = |\lambda E - I BA| = |A^{-1}(\lambda E - BA)A| = |A^{-1}| |\lambda E - BA| |A| = \frac{1}{|A|} |\lambda E - BA| |A| = |\lambda E - BA|$.
所以当 $A$ 可逆时，结论成立。
当 $A$ 不可逆时，考虑多项式 $p(x) = |x E - AB|$ 和 $q(x) = |x E - BA|$. 我们已经证明当 $A$ 可逆时 $p(\lambda) = q(\lambda)$. 矩阵 $A-tE$ 只有有限个 $t$ 值使其不可逆（行列式为零）。所以对于除有限个点外所有的 $\lambda$，$|\lambda E - (A-tE)B| = |\lambda E - B(A-tE)|$. 这是一个关于 $t$ 的多项式等式，如果它在无限多个点上成立，则它恒等成立。令 $t=0$，得 $|\lambda E - AB| = |\lambda E - BA|$. (这是一个利用稠密性的证明技巧，可能对基础薄弱的同学稍难理解，但这是标准的严谨证明方法)。

现在回到例 5：
$AB+A = A(B+E)$
$BA+A = (B+E)A$
设 $C = B+E$. 那么我们要证 $AC$ 和 $CA$ 有相同的特征值。而我们刚刚证明了对于任意方阵 $A, C$， $| \lambda E - AC| = | \lambda E - CA|$.
所以 $| \lambda E - (A(B+E))| = | \lambda E - ((B+E)A)|$.
这意味着 $A(B+E)$ 和 $(B+E)A$ 有相同的特征多项式，从而有相同的特征值。
所以 $AB+A$ 与 $BA+A$ 有相同的特征值。

#### 特征值、特征向量的性质 (总结)

讲义中总结了线性变换和矩阵的特征值/向量的性质，这些性质都非常重要。特别是：
*   性质 5 ($g(\lambda)$ 是 $g(A)$ 的特征值): 如果 $\alpha$ 是 $A$ 属于 $\lambda$ 的特征向量 ($A\alpha = \lambda\alpha$)，则对于任意多项式 $g(x) = a_n x^n + \dots + a_1 x + a_0$，
    $g(A)\alpha = (a_n A^n + \dots + a_1 A + a_0 E)\alpha$
    $= a_n A^n \alpha + \dots + a_1 A \alpha + a_0 E \alpha$ (线性变换的线性性)
    $= a_n \lambda^n \alpha + \dots + a_1 \lambda \alpha + a_0 \lambda^0 \alpha$ (因为 $A^m \alpha = \lambda^m \alpha$)
    $= (a_n \lambda^n + \dots + a_1 \lambda + a_0)\alpha = g(\lambda)\alpha$.
    所以 $g(\lambda)$ 是 $g(A)$ 的特征值，$\alpha$ 仍是其特征向量。
*   性质 6 (可逆性与特征值): $A$ 可逆当且仅当 $A$ 的特征值都不为 0。
    证明：$A$ 可逆 $\Leftrightarrow |A| \neq 0$.
    根据特征多项式展开，$|\lambda E - A| = \lambda^n - tr(A)\lambda^{n-1} + \dots + (-1)^n |A|$.
    当 $\lambda=0$ 时，$|0E - A| = |-A| = (-1)^n |A|$.
    特征方程 $|\lambda E - A|=0$ 的根是特征值。所以 $\lambda=0$ 是特征值 当且仅当 $|0E - A| = 0$, 当且仅当 $(-1)^n |A| = 0$, 当且仅当 $|A| = 0$.
    所以，$A$ 可逆 ($|A| \neq 0$) 当且仅当 $0$ 不是 $A$ 的特征值 (即所有特征值都不为 0)。
    进一步，若 $A$ 可逆，$A\alpha = \lambda \alpha$ ($\alpha \neq 0, \lambda \neq 0$). 左乘 $A^{-1}$:
    $A^{-1}A\alpha = A^{-1}\lambda \alpha$
    $I\alpha = \lambda A^{-1}\alpha$
    $\alpha = \lambda A^{-1}\alpha$. 因为 $\lambda \neq 0$, 可以除以 $\lambda$:
    $A^{-1}\alpha = \frac{1}{\lambda}\alpha$.
    所以 $\lambda^{-1}$ 是 $A^{-1}$ 的特征值，$\alpha$ 是其特征向量。
    关于 $A^*$ (伴随矩阵) 的特征值：$A^* = |A| A^{-1}$. 如果 $|A| \neq 0$, $A^*$ 的特征值是 $|A| \lambda^{-1}$. 如果 $|A|=0$, 情况复杂一些，但对于可对角化的矩阵，结论 $|A|\lambda^{-1}$ 依然成立（将 A 对角化后直接看）。讲义中写的是 $\frac{1}{\lambda}|A|$，这是对的。

*   性质 7 ($A$ 和 $A^T$ 特征值相同): 因为 $|\lambda E - A^T| = |(\lambda E - A)^T| = |\lambda E - A|$. 它们有相同的特征多项式，因此有相同的特征值。**但是，它们的特征向量一般不同。**

#### 矩阵特征多项式的性质

*   **命题 1:** $f_A(x) = f_{A^T}(x)$. 证明如上，利用行列式转置不变。
*   **命题 2:** 相似矩阵有相同的行列式、相同的特征多项式、相同的特征值。
    证明 $|B| = |P^{-1}AP| = |P^{-1}||A||P| = |P|^{-1}|A||P| = |A|$. 行列式相同。
    $|\lambda E - B| = |\lambda E - P^{-1}AP| = |P^{-1}\lambda E P - P^{-1}AP| = |P^{-1}(\lambda E - A)P| = |P^{-1}||\lambda E - A||P| = |\lambda E - A|$. 特征多项式相同。
    特征多项式相同，根当然相同，所以特征值相同。
    **重要结论：** 线性变换的特征值是其“内在”性质，不随基的选择而改变。

*   **特征多项式展开式与迹、行列式**：
    $$|\lambda E - A| = \begin{vmatrix}
    \lambda-a_{11} & -a_{12} & \cdots & -a_{1n} \\
    -a_{21} & \lambda-a_{22} & \cdots & -a_{2n} \\
    \vdots & \vdots & \ddots & \vdots \\
    -a_{n1} & -a_{n2} & \cdots & \lambda-a_{nn}
    \end{vmatrix}$$
    展开后，$\lambda^n$ 项的系数是 1 (首一多项式)。
    $\lambda^{n-1}$ 项的系数是 $(\lambda-a_{11})(\lambda-a_{22})\cdots(\lambda-a_{nn})$ 展开中提取 $\lambda^{n-1}$ 的部分，以及其他项的贡献。主要贡献来自对角线，其他项贡献的 $\lambda$ 的次数较低。精确计算可知，$\lambda^{n-1}$ 项的系数是 $-(a_{11} + a_{22} + \dots + a_{nn})$.
    常数项是令 $\lambda=0$，得到 $|-A| = (-1)^n |A|$.
    所以 $f_A(\lambda) = \lambda^n - (a_{11}+\dots+a_{nn})\lambda^{n-1} + \dots + (-1)^n|A|$.
    如果 $\lambda_1, \dots, \lambda_n$ 是特征多项式的 $n$ 个根（可能重复，在复数域上考虑），根据韦达定理（根与系数的关系）：
    根的和 $$\sum \lambda_i = - (\text{系数 of } \lambda^{n-1}) / (\text{系数 of } \lambda^n) $$$$= - (-(a_{11}+\dots+a_{nn})) / 1 = a_{11}+\dots+a_{nn}$$.
    根的积 $\prod \lambda_i = (-1)^n \cdot (\text{常数项}) / (\text{系数 of } \lambda^n) = (-1)^n \cdot (-1)^n |A| / 1 = |A|$.

    **定义：** 矩阵 $A$ 的对角线元素之和称为矩阵的**迹 (Trace)**，记为 $tr(A) = \sum a_{ii}$.
    **命题：** $\sum_{i=1}^n \lambda_i = tr(A)$ 且 $\prod_{i=1}^n \lambda_i = |A|$.

    **迹的性质**：
    1. $tr(A+B) = tr(A) + tr(B)$ (对角线元素相加)
    2. $tr(kA) = k tr(A)$ (对角线元素乘以 k)
    3. $tr(A^T) = tr(A)$ (转置不改变对角线元素)
    4. $tr(AB) = tr(BA)$. **证明：** $tr(AB) = \sum_i (AB)_{ii} = \sum_i \sum_k a_{ik}b_{ki}$. $tr(BA) = \sum_k (BA)_{kk} = \sum_k \sum_i b_{ki}a_{ik}$. 两个求和式仅仅是改变了求和次序，结果相同。
    5. $tr(ABC) = tr(BCA) = tr(CAB)$. (通过循环交换，利用 $tr(XY) = tr(YX)$ 两次即可得证)。
    6. 如果 $A \sim B$，则 $tr(A) = tr(B)$. **证明：** $B = P^{-1}AP$. $tr(B) = tr(P^{-1}(AP)) = tr((AP)P^{-1}) = tr(A(PP^{-1})) = tr(AI) = tr(A)$.

    **重要结论：** 迹和行列式都是相似不变量，它们只取决于线性变换本身（通过其特征值）。

#### 哈密尔顿-凯莱定理 (Hamilton-Cayley Theorem)

这是一个非常深刻的定理。
**定理 7.4.4:** 对于数域 $P$ 上的任意 $n$ 阶方阵 $A$，它满足自己的<font color="#ffff00">特征方程</font>。即，如果 $f_A(\lambda)$ 是 $A$ 的特征多项式，那么 $f_A(A) = 0$. (这里的 0 是零矩阵)。
形式上，如果 $f_A(\lambda) = \lambda^n + a_{n-1}\lambda^{n-1} + \dots + a_1\lambda + a_0$，那么 $A^n + a_{n-1}A^{n-1} + \dots + a_1A + a_0E = 0$.

**证明思路 (讲义中的方法):**
设 $B(\lambda)$ 是矩阵 $\lambda E - A$ 的伴随矩阵。根据伴随矩阵的性质，有 $B(\lambda)(\lambda E - A) = |\lambda E - A| E = f_A(\lambda) E$.
$B(\lambda)$ 的每个元素是 $\lambda E - A$ 的代数余子式，它们是 $\lambda$ 的多项式，次数不超过 $n-1$. 因此，$B(\lambda)$ 可以写成关于 $\lambda$ 的多项式，系数是数值矩阵：
$B(\lambda) = B_{n-1}\lambda^{n-1} + B_{n-2}\lambda^{n-2} + \dots + B_1\lambda + B_0$. (讲义里系数顺序反了，无所谓)
将 $f_A(\lambda) = \lambda^n + a_{n-1}\lambda^{n-1} + \dots + a_1\lambda + a_0$ 代入 $f_A(\lambda)E$:
$f_A(\lambda)E = \lambda^n E + a_{n-1}\lambda^{n-1}E + \dots + a_1\lambda E + a_0 E$.
将 $B(\lambda)$ 的多项式形式和 $\lambda E - A$ 的乘积展开：
$B(\lambda)(\lambda E - A) = (B_{n-1}\lambda^{n-1} + \dots + B_0)(\lambda E - A)$
$= B_{n-1}\lambda^n + B_{n-2}\lambda^{n-1} + \dots + B_0\lambda - B_{n-1}\lambda^{n-1}A - B_{n-2}\lambda^{n-2}A - \dots - B_0A$
$= B_{n-1}\lambda^n + (B_{n-2} - B_{n-1}A)\lambda^{n-1} + \dots + (B_0 - B_1A)\lambda - B_0A$.
比较等式 $B(\lambda)(\lambda E - A) = f_A(\lambda)E$ 两边关于 $\lambda$ 的同次幂系数 (矩阵相等):
$\lambda^n: B_{n-1} = E$
$\lambda^{n-1}: B_{n-2} - B_{n-1}A = a_{n-1}E \Rightarrow B_{n-2} = a_{n-1}E + B_{n-1}A = a_{n-1}E + A$
$\lambda^{n-2}: B_{n-3} - B_{n-2}A = a_{n-2}E \Rightarrow B_{n-3} = a_{n-2}E + B_{n-2}A = a_{n-2}E + (a_{n-1}E+A)A = a_{n-2}E + a_{n-1}A + A^2$
...
$\lambda^1: B_0 - B_1A = a_1 E \Rightarrow B_0 = a_1 E + B_1 A$
$\lambda^0: -B_0 A = a_0 E$.

现在将这些系数等式分别右乘 $A^n, A^{n-1}, \dots, A, E$ 并相加：
$B_{n-1} A^n = E A^n = A^n$
$(B_{n-2} - B_{n-1}A)A^{n-1} = a_{n-1}EA^{n-1} \Rightarrow B_{n-2}A^{n-1} - B_{n-1}A^n = a_{n-1}A^{n-1}$
$(B_{n-3} - B_{n-2}A)A^{n-2} = a_{n-2}EA^{n-2} \Rightarrow B_{n-3}A^{n-2} - B_{n-2}A^{n-1} = a_{n-2}A^{n-2}$
...
$(B_0 - B_1A)A^1 = a_1 EA^1 \Rightarrow B_0 A - B_1 A^2 = a_1 A$
$(-B_0 A)E = a_0 EE \Rightarrow -B_0 A = a_0 E$

将这些等式相加：左边的中间项会抵消 $(B_{n-2}A^{n-1} - B_{n-2}A^{n-1}) + (B_{n-3}A^{n-2} - B_{n-3}A^{n-2}) + \dots + (B_0 A - B_0 A)$.
左边剩下 $B_{n-1}A^n - B_{n-1}A^n$ (第一项和第二项的后一部分)，以及 $B_0 A - B_0 A$ (倒数第二项的前一部分和最后一项)。
啊，讲义中右乘的幂次似乎有问题，应该是：
$B_{n-1} = E \quad (\times A^n)$
$B_{n-2} - B_{n-1}A = a_{n-1}E \quad (\times A^{n-1})$
$B_{n-3} - B_{n-2}A = a_{n-2}E \quad (\times A^{n-2})$
...
$B_0 - B_1A = a_1 E \quad (\times A^1)$
$-B_0 A = a_0 E \quad (\times A^0 = E)$

右乘后相加：
$B_{n-1}A^n = A^n$
$B_{n-2}A^{n-1} - B_{n-1}A^n = a_{n-1}A^{n-1}$
$B_{n-3}A^{n-2} - B_{n-2}A^{n-1} = a_{n-2}A^{n-2}$
...
$B_0 A - B_1 A^2 = a_1 A$
$-B_0 A = a_0 E$

将这些等式的左边相加：$B_{n-1}A^n + (B_{n-2}A^{n-1} - B_{n-1}A^n) + \dots + (B_0 A - B_1 A^2) + (-B_0 A)$.
除了第一项 $B_{n-1}A^n$ 和中间的 $B_i A^{n-i}$ 和 $B_{i-1}A^{n-i+1}$ 会抵消外 (例如 $B_{n-2}A^{n-1}$ 和 $-(B_{n-2}A)A^{n-2}$?), 这似乎需要 $B_i A^{n-i}$ 与 $B_{i-1}A^{n-i+1}$ 抵消...
我们重写系数等式：
$B_{n-1} = E$
$B_{n-2} = a_{n-1}E + B_{n-1}A$
...
$B_0 = a_1 E + B_1 A$
$0 = a_0 E + B_0 A$

将这些等式从上到下分别乘以 $A^n, A^{n-1}, \dots, A, E$ 并相加：
$B_{n-1} A^n = E A^n = A^n$
$B_{n-2} A^{n-1} = (a_{n-1}E + B_{n-1}A)A^{n-1} = a_{n-1}A^{n-1} + B_{n-1}A^n$
...
$B_0 A = (a_1 E + B_1 A)A = a_1 A + B_1 A^2$
$0 \cdot E = (a_0 E + B_0 A)E = a_0 E + B_0 A$

这组等式相加后左边是 $\sum_{k=0}^{n-1} B_{n-1-k} A^k$. 右边是 $\sum_{k=0}^{n-1} a_{n-1-k} A^k + \sum_{k=0}^{n-1} B_{n-k} A^{k+1}$. 似乎也不直接。

**更简洁的理解**：伴随矩阵的定义 $B(\lambda)(\lambda E - A) = f_A(\lambda) E$ 是一个多项式矩阵等式。如果我们可以直接“代入”矩阵 $A$ 到这个等式中，问题就解决了。但严格来说，矩阵不能直接代入到 $\lambda E - A$ 中，因为 $\lambda$ 是一个变量。
一种严谨的证明是基于多项式矩阵理论，或者利用矩阵的相似标准型（如 Jordan 标准型），先证明对角矩阵或 Jordan 块满足定理，然后推广到一般矩阵（因为特征多项式相似不变）。讲义中试图展示一个纯代数推导，虽然步骤有点跳跃，但基本思想是利用伴随矩阵的多项式性质。对于初学者，理解定理的结论和应用更重要。

**推论 (线性变换的哈密尔顿-凯莱定理):** $f_A(A) = O$. 这是直接从矩阵形式推广来的，因为线性变换满足的多项式关系，其在任意基下的矩阵也满足。

#### 哈密尔顿-凯莱定理的应用

1.  **求逆矩阵:** 如果 $A$ 可逆，则 $a_0 = (-1)^n |A| \neq 0$.
    $A^n + a_{n-1}A^{n-1} + \dots + a_1A + a_0E = 0$.
    将 $a_0 E$ 移项：$A^n + a_{n-1}A^{n-1} + \dots + a_1A = -a_0 E$.
    因为 $a_0 \neq 0$，左乘 $A^{-1}$:
    $A^{-1}(A^n + a_{n-1}A^{n-1} + \dots + a_1A) = A^{-1}(-a_0 E)$
    $A^{n-1} + a_{n-1}A^{n-2} + \dots + a_1 E = -a_0 A^{-1}$.
    $A^{-1} = -\frac{1}{a_0}(A^{n-1} + a_{n-1}A^{n-2} + \dots + a_1 E)$.
    **优点：** 可以用矩阵的低次幂表示逆矩阵，避免了解方程组或计算伴随矩阵除以行列式的方法，特别适合符号计算。
    **例 6:** $A = \begin{pmatrix} 2 & 3 \\ -1 & 1 \end{pmatrix}$. $f_A(\lambda) = \lambda^2 - 3\lambda + 5$. $n=2, a_1=-3, a_0=5$.
    $A$ 可逆因为 $a_0=5 \neq 0$.
    由哈密尔顿-凯莱定理 $A^2 - 3A + 5E = 0$.
    $5E = 3A - A^2$.
    $E = \frac{3}{5}A - \frac{1}{5}A^2$.
    左乘 $A^{-1}$: $A^{-1} = \frac{3}{5}E - \frac{1}{5}A$.
    $A^{-1} = \frac{1}{5}(3E - A) = \frac{1}{5} \left( \begin{pmatrix} 3 & 0 \\ 0 & 3 \end{pmatrix} - \begin{pmatrix} 2 & 3 \\ -1 & 1 \end{pmatrix} \right) = \frac{1}{5} \begin{pmatrix} 1 & -3 \\ 1 & 2 \end{pmatrix} = \begin{pmatrix} 1/5 & -3/5 \\ 1/5 & 2/5 \end{pmatrix}$. 这和直接计算 $A^{-1} = \frac{1}{|A|}adj(A) = \frac{1}{2-(-3)}\begin{pmatrix} 1 & -3 \\ 1 & 2 \end{pmatrix} = \frac{1}{5}\begin{pmatrix} 1 & -3 \\ 1 & 2 \end{pmatrix}$ 结果一致。

2.  **求矩阵的方幂:** 设要求 $A^m$.
    对多项式 $x^m$ 用特征多项式 $f_A(x)$ 做带余除法：
    $x^m = f_A(x) q(x) + r(x)$, 其中余式 $r(x)$ 的次数小于 $f_A(x)$ 的次数 $n$. $r(x) = r_{n-1}x^{n-1} + \dots + r_1 x + r_0$.
    将矩阵 $A$ 代入此多项式恒等式：
    $A^m = f_A(A) q(A) + r(A)$.
    由哈密尔顿-凯莱定理，$f_A(A) = 0$.
    所以 $A^m = r(A) = r_{n-1}A^{n-1} + \dots + r_1 A + r_0 E$.
    **优点：** 将任意高次幂 $A^m$ 表示为次数不超过 $n-1$ 的多项式，计算量大大降低。
    **关键：** 怎么求余式 $r(x)$ 的系数 $r_i$?
    由于 $x^m = f_A(x) q(x) + r(x)$ 是多项式恒等式，对于 $f_A(x)$ 的根 $\lambda_i$，代入恒等式得：
    $\lambda_i^m = f_A(\lambda_i) q(\lambda_i) + r(\lambda_i)$.
    因为 $\lambda_i$ 是 $f_A(x)$ 的根，$f_A(\lambda_i) = 0$.
    所以 $\lambda_i^m = r(\lambda_i)$.

    *   **情况 1 (特征值互异):** $f_A(x) = (x-\lambda_1)\dots(x-\lambda_n)$, $\lambda_i$ 互不相同。
        有 $n$ 个等式:
        $\lambda_1^m = r(\lambda_1) = r_{n-1}\lambda_1^{n-1} + \dots + r_1 \lambda_1 + r_0$
        $\lambda_2^m = r(\lambda_2) = r_{n-1}\lambda_2^{n-1} + \dots + r_1 \lambda_2 + r_0$
        ...
        $\lambda_n^m = r(\lambda_n) = r_{n-1}\lambda_n^{n-1} + \dots + r_1 \lambda_n + r_0$
        这是一个关于未知数 $r_0, r_1, \dots, r_{n-1}$ 的线性方程组。系数矩阵是范德蒙矩阵的转置，因为 $\lambda_i$ 互异，范德蒙行列式不为零，所以这个方程组有唯一解，可以解出 $r_i$.
    *   **情况 2 (特征值有重根):** 设 $\lambda_i$ 是 $f_A(x)$ 的 $k_i$ 重根。
        $\lambda_i$ 也是 $f_A(x)$ 的导数 $f_A'(x), f_A''(x), \dots, f_A^{(k_i-1)}(x)$ 的根。
        对恒等式 $x^m = f_A(x) q(x) + r(x)$ 关于 $x$ 求导，然后代入重根 $\lambda_i$:
        $m x^{m-1} = f_A'(x)q(x) + f_A(x)q'(x) + r'(x)$. 代入 $x=\lambda_i$:
        $m \lambda_i^{m-1} = f_A'(\lambda_i)q(\lambda_i) + f_A(\lambda_i)q'(\lambda_i) + r'(\lambda_i)$.
        如果 $f_A(\lambda_i)=0$ 且 $f_A'(\lambda_i)=0$，则 $m \lambda_i^{m-1} = r'(\lambda_i)$.
        重复求导 $k_i-1$ 次，代入 $\lambda_i$，可以得到 $k_i$ 个关于 $r_i$ 的方程：
        $\lambda_i^m = r(\lambda_i)$
        $m\lambda_i^{m-1} = r'(\lambda_i)$
        $m(m-1)\lambda_i^{m-2} = r''(\lambda_i)$
        ...
        $m(m-1)\dots(m-k_i+2)\lambda_i^{m-k_i+1} = r^{(k_i-1)}(\lambda_i)$
        对所有互异特征值 $\lambda_1, \dots, \lambda_s$ 及其重数 $k_1, \dots, k_s$，总共可以得到 $k_1 + \dots + k_s = n$ 个线性方程，解出 $r_0, \dots, r_{n-1}$.

    **例 7:** $A = \begin{pmatrix} 1 & 1 \\ 0 & 2 \end{pmatrix}$. 求 $A^n$.
    $f_A(\lambda) = \begin{vmatrix} \lambda-1 & -1 \\ 0 & \lambda-2 \end{vmatrix} = (\lambda-1)(\lambda-2)$. 特征值 $\lambda_1=1, \lambda_2=2$ (互异)。
    余式次数小于 2，设 $r(x) = ax+b$.
    根据 $\lambda^n = r(\lambda)$:
    $1^n = a(1) + b \Rightarrow 1 = a+b$
    $2^n = a(2) + b \Rightarrow 2^n = 2a+b$
    解方程组：$(2a+b) - (a+b) = 2^n - 1 \Rightarrow a = 2^n - 1$.
    $b = 1 - a = 1 - (2^n - 1) = 2 - 2^n$.
    所以 $r(x) = (2^n-1)x + (2-2^n)$.
    $A^n = r(A) = (2^n-1)A + (2-2^n)E$.
    $A^n = (2^n-1)\begin{pmatrix} 1 & 1 \\ 0 & 2 \end{pmatrix} + (2-2^n)\begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix} = \begin{pmatrix} 2^n-1 & 2^n-1 \\ 0 & 2(2^n-1) \end{pmatrix} + \begin{pmatrix} 2-2^n & 0 \\ 0 & 2-2^n \end{pmatrix}$
    $A^n = \begin{pmatrix} (2^n-1) + (2-2^n) & 2^n-1 \\ 0 & 2(2^n-1) + (2-2^n) \end{pmatrix} = \begin{pmatrix} 1 & 2^n-1 \\ 0 & 2^{n+1}-2+2-2^n \end{pmatrix} = \begin{pmatrix} 1 & 2^n-1 \\ 0 & 2^{n+1}-2^n \end{pmatrix} = \begin{pmatrix} 1 & 2^n-1 \\ 0 & 2^n \end{pmatrix}$.

    **例 8:** $A = \begin{pmatrix} 1 & 1 & 0 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{pmatrix}$. 求 $A^n$.
    $f_A(\lambda) = \begin{vmatrix} \lambda-1 & -1 & 0 \\ 0 & \lambda-1 & -1 \\ 0 & 0 & \lambda-1 \end{vmatrix} = (\lambda-1)^3$. 特征值 $\lambda=1$ (3重)。
    余式次数小于 3，设 $r(x) = ax^2 + bx + c$.
    根据重根情况，使用等式 $\lambda^n = r(\lambda)$, $n\lambda^{n-1} = r'(\lambda)$, $n(n-1)\lambda^{n-2} = r''(\lambda)$. 代入 $\lambda=1$:
    $1^n = a(1)^2 + b(1) + c \Rightarrow 1 = a+b+c$.
    $n(1)^{n-1} = 2a(1) + b \Rightarrow n = 2a+b$.
    $n(n-1)(1)^{n-2} = 2a \Rightarrow n(n-1) = 2a$.
    解方程组：
    $a = n(n-1)/2$.
    $b = n - 2a = n - n(n-1) = n - n^2 + n = 2n - n^2$.
    $c = 1 - a - b = 1 - n(n-1)/2 - (2n-n^2) = 1 - (n^2-n)/2 - 2n + n^2 = 1 + n^2/2 - n/2 - 2n = 1 + n^2/2 - 5n/2$.
    所以 $r(x) = \frac{n(n-1)}{2}x^2 + (2n-n^2)x + (1 + \frac{n^2-5n}{2})$.

    $A^n = r(A) = \frac{n(n-1)}{2}A^2 + (2n-n^2)A + (1 + \frac{n^2-5n}{2})E$.
    先计算 $A^2$:
    $A^2 = \begin{pmatrix} 1 & 1 & 0 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} 1 & 1 & 0 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{pmatrix} = \begin{pmatrix} 1 & 2 & 1 \\ 0 & 1 & 2 \\ 0 & 0 & 1 \end{pmatrix}$.
    $A^n = \frac{n(n-1)}{2}\begin{pmatrix} 1 & 2 & 1 \\ 0 & 1 & 2 \\ 0 & 0 & 1 \end{pmatrix} + (2n-n^2)\begin{pmatrix} 1 & 1 & 0 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{pmatrix} + (1 + \frac{n^2-5n}{2})\begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix}$
    计算各项系数相加：
    $(1,1)$ 位置: $\frac{n(n-1)}{2} + (2n-n^2) + (1 + \frac{n^2-5n}{2}) = \frac{n^2-n + 4n-2n^2 + 2+n^2-5n}{2} = \frac{2}{2} = 1$.
    $(1,2)$ 位置: $\frac{n(n-1)}{2} \cdot 2 + (2n-n^2) \cdot 1 + (1 + \frac{n^2-5n}{2}) \cdot 0 = n(n-1) + 2n - n^2 = n^2 - n + 2n - n^2 = n$.
    $(1,3)$ 位置: $\frac{n(n-1)}{2} \cdot 1 + (2n-n^2) \cdot 0 + (1 + \frac{n^2-5n}{2}) \cdot 0 = \frac{n(n-1)}{2}$.
    $(2,2)$ 位置: $\frac{n(n-1)}{2} + (2n-n^2) + (1 + \frac{n^2-5n}{2}) = 1$.
    $(2,3)$ 位置: $\frac{n(n-1)}{2} \cdot 2 + (2n-n^2) \cdot 1 = n(n-1) + 2n - n^2 = n^2 - n + 2n - n^2 = n$.
    $(3,3)$ 位置: $\frac{n(n-1)}{2} + (2n-n^2) + (1 + \frac{n^2-5n}{2}) = 1$.
    其他位置都是 0.
    所以 $A^n = \begin{pmatrix} 1 & n & n(n-1)/2 \\ 0 & 1 & n \\ 0 & 0 & 1 \end{pmatrix}$.
    这个结果可以通过观察 $A=I+N$ 其中 $N = \begin{pmatrix} 0 & 1 & 0 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{pmatrix}$ 是幂零矩阵 ($N^3=0$), $I$ 和 $N$ 可交换 ($IN=NI=N$)，所以 $(I+N)^n = \sum_{k=0}^n \binom{n}{k} I^{n-k} N^k = \binom{n}{0}I + \binom{n}{1}N + \binom{n}{2}N^2 + \binom{n}{3}N^3 + \dots$.
    $N^2 = \begin{pmatrix} 0 & 0 & 1 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{pmatrix}$. $N^k=0$ for $k \ge 3$.
    $A^n = 1 \cdot E + n N + \frac{n(n-1)}{2} N^2 + 0 + \dots$
    $A^n = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} + n \begin{pmatrix} 0 & 1 & 0 \\ 0 & 0 & 1 \\ 0 & 0 & 0 \end{pmatrix} + \frac{n(n-1)}{2} \begin{pmatrix} 0 & 0 & 1 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{pmatrix} = \begin{pmatrix} 1 & n & n(n-1)/2 \\ 0 & 1 & n \\ 0 & 0 & 1 \end{pmatrix}$.
    结果一致！这个例子也说明了哈密尔顿-凯莱定理求矩阵幂的强大。

    **例 9 (斐波那契数列):** 递归关系 $a_{n+1} = a_n + a_{n-1}$. 初始值 $a_0=0, a_1=1$.
    写成矩阵形式：
    $\begin{pmatrix} a_{n+1} \\ a_n \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} a_n \\ a_{n-1} \end{pmatrix}$.
    记 $\alpha_n = \begin{pmatrix} a_{n+1} \\ a_n \end{pmatrix}$ 和 $A = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$. 则 $\alpha_n = A \alpha_{n-1}$.
    递推下去：$\alpha_n = A \alpha_{n-1} = A (A \alpha_{n-2}) = A^2 \alpha_{n-2} = \dots = A^n \alpha_0$.
    其中 $\alpha_0 = \begin{pmatrix} a_1 \\ a_0 \end{pmatrix} = \begin{pmatrix} 1 \\ 0 \end{pmatrix}$.
    所以 $\begin{pmatrix} a_{n+1} \\ a_n \end{pmatrix} = A^n \begin{pmatrix} 1 \\ 0 \end{pmatrix}$.
    要找到 $a_n$，只需要计算 $A^n$ 的第一列的第二个元素（或者第二列的第一个元素？）。
    根据哈密尔顿-凯莱定理求 $A^n$.
    $f_A(\lambda) = \begin{vmatrix} \lambda-1 & -1 \\ -1 & \lambda \end{vmatrix} = \lambda(\lambda-1) - (-1)(-1) = \lambda^2 - \lambda - 1$.
    特征方程 $\lambda^2 - \lambda - 1 = 0$. 根是 $\lambda_{1,2} = \frac{1 \pm \sqrt{1 - 4(-1)}}{2} = \frac{1 \pm \sqrt{5}}{2}$. 设 $\phi = \frac{1+\sqrt{5}}{2}, \psi = \frac{1-\sqrt{5}}{2}$.
    $A$ 的特征值是 $\phi, \psi$ (互异)。
    设 $A^n = aA+bE$. (注意这里的 $a, b$ 是余式系数，与斐波那契数列符号重了，我们用 $c_1, c_0$ 表示).
    $A^n = c_1 A + c_0 E$.
    $\lambda^n = c_1 \lambda + c_0$.
    $\phi^n = c_1 \phi + c_0$
    $\psi^n = c_1 \psi + c_0$
    相减: $\phi^n - \psi^n = c_1 (\phi - \psi)$. $\phi - \psi = \frac{1+\sqrt{5}}{2} - \frac{1-\sqrt{5}}{2} = \frac{2\sqrt{5}}{2} = \sqrt{5}$.
    $c_1 = \frac{\phi^n - \psi^n}{\sqrt{5}}$.
    $c_0 = \phi^n - c_1 \phi = \phi^n - \frac{\phi^n - \psi^n}{\sqrt{5}}\phi = \frac{\sqrt{5}\phi^n - \phi^{n+1} + \psi^n \phi}{\sqrt{5}}$.
    $A^n = \frac{\phi^n - \psi^n}{\sqrt{5}} A + c_0 E$.
    $\begin{pmatrix} a_{n+1} \\ a_n \end{pmatrix} = A^n \begin{pmatrix} 1 \\ 0 \end{pmatrix} = (\frac{\phi^n - \psi^n}{\sqrt{5}} A + c_0 E) \begin{pmatrix} 1 \\ 0 \end{pmatrix}$
    $= \frac{\phi^n - \psi^n}{\sqrt{5}} A \begin{pmatrix} 1 \\ 0 \end{pmatrix} + c_0 E \begin{pmatrix} 1 \\ 0 \end{pmatrix}$
    $A \begin{pmatrix} 1 \\ 0 \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} 1 \\ 0 \end{pmatrix} = \begin{pmatrix} 1 \\ 1 \end{pmatrix} = \alpha_1$.
    $E \begin{pmatrix} 1 \\ 0 \end{pmatrix} = \begin{pmatrix} 1 \\ 0 \end{pmatrix} = \alpha_0$.
    所以 $\begin{pmatrix} a_{n+1} \\ a_n \end{pmatrix} = \frac{\phi^n - \psi^n}{\sqrt{5}} \begin{pmatrix} 1 \\ 1 \end{pmatrix} + c_0 \begin{pmatrix} 1 \\ 0 \end{pmatrix} = \begin{pmatrix} (\phi^n - \psi^n)/\sqrt{5} + c_0 \\ (\phi^n - \psi^n)/\sqrt{5} \end{pmatrix}$.
    我们关心的是 $a_n$, 也就是第二个分量。
    $a_n = \frac{\phi^n - \psi^n}{\sqrt{5}} = \frac{(\frac{1+\sqrt{5}}{2})^n - (\frac{1-\sqrt{5}}{2})^n}{\sqrt{5}}$. 这就是著名的 Binet 公式。
    讲义中写 $A^n = aA+bE = \begin{pmatrix} a+b & a \\ a & b \end{pmatrix}$. 这个形式不对，因为 $A = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$.
    $c_1 A + c_0 E = c_1 \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} + c_0 \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix} = \begin{pmatrix} c_1+c_0 & c_1 \\ c_1 & c_0 \end{pmatrix}$.
    那么 $\begin{pmatrix} a_{n+1} \\ a_n \end{pmatrix} = \begin{pmatrix} c_1+c_0 & c_1 \\ c_1 & c_0 \end{pmatrix} \begin{pmatrix} 1 \\ 0 \end{pmatrix} = \begin{pmatrix} c_1+c_0 \\ c_1 \end{pmatrix}$.
    所以 $a_n = c_1 = \frac{\phi^n - \psi^n}{\sqrt{5}}$.

---

### 对角化：寻找“最好的”基

#### 引入与动机 (Hook & Motivation)

我们已经知道，同一个线性变换在不同基下对应不同的矩阵，这些矩阵彼此相似。我们也知道相似矩阵有很多共同的性质，但它们的具体形式可能千差万别。

有没有一组“最好”的基，使得线性变换在这组基下的矩阵拥有最简单的形式？什么样的矩阵最简单？当然是对角矩阵！
$$
\Lambda = \begin{pmatrix}
\lambda_1 & 0 & \cdots & 0 \\
0 & \lambda_2 & \cdots & 0 \\
\vdots & \vdots & \ddots & \vdots \\
0 & 0 & \cdots & \lambda_n
\end{pmatrix}
$$
对角矩阵的优势：
*   运算简单：加减法直接对角线元素操作，乘法对角线元素相乘 $(\Lambda_1 \Lambda_2)_{ii} = (\Lambda_1)_{ii}(\Lambda_2)_{ii}$，幂次直接对角线元素取幂 $(\Lambda^m)_{ii} = (\Lambda_{ii})^m$.
*   性质清晰：行列式是对角线元素的乘积，迹是对角线元素的和。对角线元素就是特征值！

如果一个线性变换可以找到一组基，使得其在这组基下的矩阵是对角矩阵，我们就说这个线性变换**可对角化**。对于矩阵来说，如果一个矩阵相似于一个对角矩阵，我们就说这个矩阵**可对角化**。

#### 逐步形式化与精确定义 (Gradual Formalization)

**定义 7.5.1 (线性变换的对角化)**：设 $V$ 是 $n$ 维线性空间，$A$ 是 $V$ 上的线性变换。如果存在 $V$ 的一组基 $\epsilon_1, \dots, \epsilon_n$，使得 $A$ 在这组基下的矩阵是对角矩阵 $\Lambda$，则称 $A$ 可对角化。

**定义 7.5.2 (矩阵的对角化)**： $A$ 是 $n$ 阶方阵。如果存在可逆矩阵 $X$ (或 $P$) 使得 $X^{-1}AX = \Lambda$ 是对角矩阵，则称 $A$ 可对角化。

这两种定义是等价的。如果线性变换 $A$ 可对角化，它在某组基 $\epsilon$ 下的矩阵 $A_{std}$ (比如标准基) 通过换基可以变成对角矩阵 $\Lambda$. 换基公式 $B = P^{-1}AP$ 表明，如果 $A_{std}$ 是 $A$ 在标准基下的矩阵，那么在另一组基下的矩阵 $\Lambda$ 满足 $\Lambda = P^{-1}A_{std}P$. 这正是矩阵可对角化的定义。反之，如果矩阵 $A$ 可对角化，即存在 $P$ 使 $P^{-1}AP = \Lambda$，那么矩阵 $A$ 可以看作某个线性变换在标准基下的矩阵，矩阵 $\Lambda$ 就是同一个线性变换在以 $P$ 的列向量为基的坐标系下的矩阵。

#### 可对角化的条件 (核心原理与推导)

那么，什么样的线性变换（或矩阵）可以对角化呢？对角化后的对角线元素是什么？

设线性变换 $A$ 在基 $\epsilon_1, \dots, \epsilon_n$ 下的矩阵是对角矩阵 $\Lambda = \text{diag}(\lambda_1, \dots, \lambda_n)$.
根据线性变换矩阵的定义，$A$ 作用在这组基向量上：
$A\epsilon_1$ 的坐标是 $\Lambda$ 的第 1 列 $(\lambda_1, 0, \dots, 0)^T$. 所以 $A\epsilon_1 = \lambda_1 \epsilon_1$.
$A\epsilon_2$ 的坐标是 $\Lambda$ 的第 2 列 $(0, \lambda_2, \dots, 0)^T$. 所以 $A\epsilon_2 = \lambda_2 \epsilon_2$.
...
$A\epsilon_n$ 的坐标是 $\Lambda$ 的第 $n$ 列 $(0, 0, \dots, \lambda_n)^T$. 所以 $A\epsilon_n = \lambda_n \epsilon_n$.

这意味着，如果 $A$ 可对角化，那么构成那组“最好的”基 $\epsilon_1, \dots, \epsilon_n$ 的向量，恰恰就是线性变换 $A$ 的特征向量！而对角矩阵的对角线元素 $\lambda_1, \dots, \lambda_n$ 就是对应的特征值。

更进一步，这组特征向量 $\epsilon_1, \dots, \epsilon_n$ 必须构成向量空间 $V$ 的一组基，这就要求它们是**线性无关**的，并且数量恰好是 $n$ 个 (空间维数)。

**定理 7.5.1 (线性变换可对角化的充要条件):** 设 $V$ 是 $n$ 维线性空间，$A$ 是 $V$ 上的线性变换。则 $A$ 可对角化的充要条件是 $A$ 有 $n$ 个线性无关的特征向量。
**定理 7.5.4 (矩阵可对角化的充要条件):** 设 $A$ 是 $n$ 阶方阵。则 $A$ 可对角化的充要条件是 $A$ 有 $n$ 个线性无关的特征向量。
（这两个定理是等价的，因为线性变换的可对角化等价于其矩阵的可对角化）。

**证明 (定理 7.5.4):**
*   **必要性 ($\Rightarrow$):** 设 $A$ 可对角化，则存在可逆矩阵 $P$ 使得 $P^{-1}AP = \Lambda = \text{diag}(\lambda_1, \dots, \lambda_n)$.
    $AP = P\Lambda$.
    设 $P$ 的列向量是 $p_1, \dots, p_n$. $P = (p_1, \dots, p_n)$.
    $A(p_1, \dots, p_n) = (p_1, \dots, p_n)\begin{pmatrix} \lambda_1 & & \\ & \ddots & \\ & & \lambda_n \end{pmatrix}$.
    矩阵乘法的列视角：$A p_j$ 是 $A$ 乘以第 $j$ 个列向量，结果是 $P\Lambda$ 的第 $j$ 列。
    $P\Lambda$ 的第 $j$ 列是 $(\lambda_j p_{1j}, \dots, \lambda_j p_{nj})^T = \lambda_j (p_{1j}, \dots, p_{nj})^T = \lambda_j p_j$.
    所以 $Ap_j = \lambda_j p_j$ 对 $j=1, \dots, n$ 成立。
    由于 $P$ 是可逆矩阵，其列向量 $p_1, \dots, p_n$ 线性无关。
    如果 $\lambda_j$ 是 $A$ 的特征值，且 $p_j$ 是非零向量，则 $p_j$ 是属于 $\lambda_j$ 的特征向量。
    如果 $\lambda_j$ 不是特征值，则 $Ap_j = \lambda_j p_j$ 且 $p_j \neq 0$ 矛盾了特征值的定义。所以 $\lambda_j$ 必须是特征值。
    如果某个 $\lambda_j$ 对应的 $p_j$ 是零向量，由于 $P$ 是可逆的，它的列向量不能是零向量。所以 $p_j \neq 0$.
    因此，如果 $A$ 可对角化，则 $P$ 的列向量构成了 $A$ 的 $n$ 个线性无关的特征向量，对角线元素就是对应的特征值。

*   **充分性 ($\Leftarrow$):** 设 $A$ 有 $n$ 个线性无关的特征向量 $\alpha_1, \dots, \alpha_n$，对应的特征值分别是 $\lambda_1, \dots, \lambda_n$. ($A\alpha_i = \lambda_i \alpha_i$).
    令 $P = (\alpha_1, \dots, \alpha_n)$. 由于 $\alpha_i$ 线性无关，$P$ 是可逆矩阵。
    考虑 $AP$:
    $AP = A(\alpha_1, \dots, \alpha_n) = (A\alpha_1, \dots, A\alpha_n) = (\lambda_1 \alpha_1, \dots, \lambda_n \alpha_n)$.
    将右边写成矩阵乘法：
    $(\lambda_1 \alpha_1, \dots, \lambda_n \alpha_n) = (\alpha_1, \dots, \alpha_n) \begin{pmatrix} \lambda_1 & & \\ & \ddots & \\ & & \lambda_n \end{pmatrix} = P\Lambda$.
    所以 $AP = P\Lambda$.
    左乘 $P^{-1}$: $P^{-1}AP = \Lambda$.
    $\Lambda$ 是对角矩阵，所以 $A$ 可对角化。

**结论：** 矩阵（或线性变换）可对角化的关键在于能否找到足够多 ( $n$ 个) 线性无关的特征向量。

#### 不同特征值对应的特征向量的线性无关性

**定理 7.5.2/7.5.5:** 线性变换（或矩阵）A 属于不同特征值的特征向量线性无关。

**证明 (情况 1：每个不同特征值取一个向量):**
设 $\lambda_1, \dots, \lambda_s$ 是 $A$ 的互异特征值，$\alpha_1, \dots, \alpha_s$ 分别是对应的特征向量 ($A\alpha_i = \lambda_i \alpha_i, \alpha_i \neq 0$).
用归纳法证明 $\alpha_1, \dots, \alpha_s$ 线性无关。
基步 $s=1$: $\alpha_1 \neq 0$，所以 $\{\alpha_1\}$ 线性无关。
归纳假设 $s=k$: 属于 $k$ 个互异特征值的特征向量 $\alpha_1, \dots, \alpha_k$ 线性无关。
归纳步 $s=k+1$: 考虑线性组合 $l_1\alpha_1 + \dots + l_{k+1}\alpha_{k+1} = 0$ (*).
对 (*) 式应用线性变换 $A$:
$A(l_1\alpha_1 + \dots + l_{k+1}\alpha_{k+1}) = A(0) = 0$
$l_1 A\alpha_1 + \dots + l_{k+1}A\alpha_{k+1} = 0$
$l_1 \lambda_1 \alpha_1 + \dots + l_{k+1}\lambda_{k+1}\alpha_{k+1} = 0$ (**).
将 (*) 式乘以 $\lambda_{k+1}$:
$l_1 \lambda_{k+1}\alpha_1 + \dots + l_k \lambda_{k+1}\alpha_k + l_{k+1}\lambda_{k+1}\alpha_{k+1} = 0 (***)$.
将 (**) - (***):
$l_1(\lambda_1 - \lambda_{k+1})\alpha_1 + \dots + l_k(\lambda_k - \lambda_{k+1})\alpha_k + l_{k+1}(\lambda_{k+1} - \lambda_{k+1})\alpha_{k+1} = 0$
$l_1(\lambda_1 - \lambda_{k+1})\alpha_1 + \dots + l_k(\lambda_k - \lambda_{k+1})\alpha_k = 0$.
根据归纳假设，$\alpha_1, \dots, \alpha_k$ 线性无关。所以它们前面的系数都必须是零：
$l_1(\lambda_1 - \lambda_{k+1}) = 0$
$l_2(\lambda_2 - \lambda_{k+1}) = 0$
...
$l_k(\lambda_k - \lambda_{k+1}) = 0$.
因为 $\lambda_1, \dots, \lambda_{k+1}$ 是互异的，所以 $\lambda_i - \lambda_{k+1} \neq 0$ 对 $i=1, \dots, k$.
这就迫使 $l_1 = 0, l_2 = 0, \dots, l_k = 0$.
将这些结果代回 (*) 式：$0\alpha_1 + \dots + 0\alpha_k + l_{k+1}\alpha_{k+1} = 0 \Rightarrow l_{k+1}\alpha_{k+1} = 0$.
因为 $\alpha_{k+1}$ 是特征向量，所以 $\alpha_{k+1} \neq 0$. 这迫使 $l_{k+1} = 0$.
所以 $l_1 = l_2 = \dots = l_{k+1} = 0$. $\alpha_1, \dots, \alpha_{k+1}$ 线性无关。
由归纳原理，定理成立。

**证明 (情况 2：每个特征值取一组线性无关向量):**
设 $\lambda_1, \dots, \lambda_s$ 是互异特征值，$S_i = \{\alpha_{i1}, \dots, \alpha_{in_i}\}$ 是属于 $\lambda_i$ 的一组线性无关特征向量 (即 $S_i$ 是特征子空间 $V_{\lambda_i}$ 的基).
我们要证明集合 $S = S_1 \cup S_2 \cup \dots \cup S_s$ 中的所有向量线性无关。
考虑一个线性组合，其系数来自 $S$ 中的所有向量，等于零：
$(\sum_{j=1}^{n_1} l_{1j}\alpha_{1j}) + (\sum_{j=1}^{n_2} l_{2j}\alpha_{2j}) + \dots + (\sum_{j=1}^{n_s} l_{sj}\alpha_{sj}) = 0$.
设 $\beta_i = \sum_{j=1}^{n_i} l_{ij}\alpha_{ij}$. 注意 $\beta_i$ 要么是属于 $\lambda_i$ 的特征向量，要么是零向量。
原式变成 $\beta_1 + \beta_2 + \dots + \beta_s = 0$.
如果这些 $\beta_i$ 中有非零向量，那么我们就有了属于不同特征值的非零向量的线性组合等于零。根据情况 1 的证明，这只有在所有向量都为零时才可能发生。
所以 $\beta_1 = 0, \beta_2 = 0, \dots, \beta_s = 0$.
$\sum_{j=1}^{n_i} l_{ij}\alpha_{ij} = 0$ 对每个 $i=1, \dots, s$ 成立。
因为 $\{\alpha_{i1}, \dots, \alpha_{in_i}\}$ 本身是线性无关的（它是 $V_{\lambda_i}$ 的基），所以对于每个 $i$，所有系数 $l_{ij}$ 都必须是零。
$l_{ij} = 0$ 对所有 $i=1,\dots,s$ 和 $j=1,\dots,n_i$ 成立。
因此，集合 $S$ 中的所有向量线性无关。

**推论 1/4:** 如果 $n$ 维空间上的线性变换 $A$ (或 $n$ 阶矩阵 $A$) 在数域 $P$ 中有 $n$ 个互异的特征值，那么 $A$ (或 $A$) 可以对角化。
**原因：** 互异的特征值意味着存在 $n$ 个不同的特征值。根据定理 7.5.2/7.5.5，属于这 $n$ 个互异特征值的特征向量必然线性无关。我们找到了 $n$ 个线性无关的特征向量，根据定理 7.5.1/7.5.4， $A$ (或 $A$) 可对角化。

**推论 2/5:** 如果复数域 $C$ 上 $n$ 维空间上的线性变换 $A$ (或 $n$ 阶矩阵 $A$) 的特征多项式没有重根，那么 $A$ (或 $A$) 可以对角化。
**原因：** 在复数域上，一个 $n$ 次多项式总有 $n$ 个根（计重数）。如果特征多项式没有重根，意味着有 $n$ 个互不相同的特征值。根据推论 1/4，即可对角化。

这些推论提供了判断可对角化的一个充分条件（互异特征值），但不是必要条件。有重根的矩阵**也可能**对角化。我们需要更精细的条件。

#### 几何重数和代数重数

**定义 7.5.3:** 设 $\lambda_i$ 是矩阵 $A$ (或线性变换 $A$) 的一个特征值。
*   $\lambda_i$ 的**代数重数 ($r_i$)**：在特征多项式 $f_A(\lambda)$ 中，$(\lambda - \lambda_i)$ 的次数。
*   $\lambda_i$ 的**几何重数 ($d_i$)**：属于特征值 $\lambda_i$ 的特征子空间 $V_{\lambda_i}$ 的维数，$d_i = \dim V_{\lambda_i}$. $V_{\lambda_i}$ 是齐次线性方程组 $(\lambda_i E - A)X = 0$ 的解空间。其维数等于 $n - rank(\lambda_i E - A)$.

**定理 7.5.7:** 对于任何一个特征值 $\lambda_i$，其几何重数**不超过**代数重数，即 $d_i \le r_i$. (这个定理证明需要 Jordan 标准型或其他高级工具，可以先记住结论)

回想可对角化的条件是存在 $n$ 个线性无关的特征向量。根据定理 7.5.2/7.5.5 (情况 2)，如果我们将所有互异特征值 $\lambda_1, \dots, \lambda_s$ 对应的特征子空间 $V_{\lambda_i}$ 的基合起来，它们是线性无关的。这些向量的总数是 $d_1 + d_2 + \dots + d_s$. 要有 $n$ 个线性无关的特征向量，总数必须等于 $n$.

**定理 7.5.3/7.5.6 (可对角化的充要条件)**：设 $V$ 是 $n$ 维线性空间，$A$ 是 $V$ 上的线性变换（或 $A$ 是 $n$ 阶方阵）。其全部互异特征值为 $\lambda_1, \dots, \lambda_s$.
则 $A$ (或 $A$) 可对角化的充要条件是：
1.  所有特征值 $\lambda_1, \dots, \lambda_s$ 都属于数域 $P$ (在线性变换或矩阵定义在 $P$ 上时)。这意味着特征多项式在 $P$ 上可以完全分解成一次因式的乘积。
2.  对于每一个特征值 $\lambda_i$，其几何重数等于代数重数 ($d_i = r_i$).

**证明 (定理 7.5.8 for matrices):**
*   **充分性 ($\Leftarrow$):** 假设所有 $\lambda_i \in P$ 且 $d_i = r_i$ 对所有 $i$ 成立。
    属于 $\lambda_i$ 的特征子空间 $V_{\lambda_i}$ 有基，其向量个数是 $d_i = r_i$.
    将所有特征子空间的基合起来，总向量个数是 $d_1 + \dots + d_s = r_1 + \dots + r_s$.
    由于特征多项式是 $n$ 次的，$f_A(\lambda) = (\lambda-\lambda_1)^{r_1}\dots(\lambda-\lambda_s)^{r_s}$, 代数重数之和等于次数 $n$.
    所以，总向量个数 $d_1 + \dots + d_s = n$.
    根据定理 7.5.2/7.5.5 (情况 2)，这些向量是线性无关的。我们找到了 $n$ 个线性无关的特征向量。
    根据定理 7.5.4，$A$ 可对角化。

*   **必要性 ($\Rightarrow$):** 假设 $A$ 可对角化。则存在 $n$ 个线性无关的特征向量 $\alpha_1, \dots, \alpha_n$.
    这些向量构成了 $P^n$ 的一组基。
    首先，对角化要求相似于一个对角矩阵 $\Lambda$ 且对角线元素在 $P$ 中。这些对角线元素就是特征值，所以所有特征值必须在 $P$ 中。($\lambda_i \in P$).
    其次，将这 $n$ 个特征向量按照所属的特征值进行分组。属于同一个特征值 $\lambda_i$ 的向量构成 $V_{\lambda_i}$ 的一部分生成集。由于它们总共是 $n$ 个线性无关向量，所以它们恰好是所有特征子空间的基的并集。
    总的线性无关特征向量个数是 $n = d_1 + \dots + d_s$.
    我们知道 $d_i \le r_i$ 对所有 $i$ 成立。
    所以 $n = \sum d_i \le \sum r_i$.
    而 $\sum r_i = n$ (代数重数之和等于多项式次数)。
    因此，不等式链 $\sum d_i \le \sum r_i$ 必须取等号。这只有当 $d_i = r_i$ 对所有 $i=1, \dots, s$ 成立时才可能。

**结论：** 矩阵可对角化的充要条件是“不缺”特征向量。具体来说，特征值要老实地待在定义域 $P$ 里，并且每个特征值的“有效”特征向量个数（几何重数）要达到它在特征多项式里出现的次数（代数重数）。

**推论 (线性变换可对角化):** 线性变换 A 可对角化当且仅当它在**任意**一组基下的矩阵 $A$ 可对角化。这再次体现了对角化是线性变换本身的性质。

#### 求矩阵对角化的步骤

1.  计算矩阵 $A$ 的特征多项式 $f_A(\lambda) = |\lambda E - A|$.
2.  求解特征方程 $f_A(\lambda) = 0$ 的所有根 $\lambda_1, \dots, \lambda_s$. (如果希望在数域 $P$ 上对角化，则要求所有根都在 $P$ 中。如果在复数域上对角化，这一步总能完成).
3.  对于每个特征值 $\lambda_i$，求出属于它的特征子空间 $V_{\lambda_i}$ 的一组基。这通过解齐次线性方程组 $(\lambda_i E - A)X = 0$ 来实现。基础解系的向量个数 $n_i$ 就是几何重数 $d_i = \dim V_{\lambda_i}$.
4.  检查对角化条件：
    *   所有特征值是否都在目标数域 $P$ 中？
    *   对于每个特征值 $\lambda_i$，其几何重数 $d_i$ 是否等于代数重数 $r_i$？ (代数重数是从特征多项式分解中看出的 $\lambda_i$ 的重数).
    如果两个条件都满足，则 $A$ 可对角化。否则，不可对角化。
5.  如果 $A$ 可对角化，将所有特征子空间的基向量组合在一起。由于 $\sum d_i = \sum r_i = n$，总共有 $n$ 个向量。根据定理 7.5.2/7.5.5 (情况 2)，它们是线性无关的，构成了 $P^n$ 的一组基。将这些特征向量作为列构成矩阵 $P$.
    $P = (\alpha_{11}, \dots, \alpha_{1n_1}, \dots, \alpha_{s1}, \dots, \alpha_{sn_s})$, 其中 $\alpha_{ij}$ 是 $V_{\lambda_i}$ 的基向量。
    则 $P$ 是可逆矩阵，并且 $P^{-1}AP = \Lambda$, 其中 $\Lambda$ 是对角矩阵，对角线元素就是对应的特征值，按照特征向量在 $P$ 中排列的顺序。例如，如果 $P$ 的前 $d_1$ 列是属于 $\lambda_1$ 的特征向量，接下来 $d_2$ 列属于 $\lambda_2$，等等，那么 $\Lambda$ 的前 $d_1$ 个对角线元素是 $\lambda_1$，接下来 $d_2$ 个是 $\lambda_2$，等等。

#### 示例 (判断和实现对角化)

**例 1 (微商变换 revisited):** 矩阵 $D = \begin{pmatrix} 0 & 1 & \cdots \\ & \ddots & \\ & & 0 \end{pmatrix}$ (上三角)。
特征多项式 $\lambda^n = 0$. 特征值 $\lambda=0$ (代数重数 $r_1=n$).
解 $(0E - D)X = 0$ 得到基础解系只有一个向量 $(1, 0, \dots, 0)^T$. 几何重数 $d_1 = 1$.
因为 $d_1 = 1 < n = r_1$ (对于 $n > 1$ 的情况)，所以 D 不能对角化。这与前面分析的微商变换的特征向量只有一个方向（常数多项式）一致。

**例 2 (4x4 Matrix revisited):** $A = \begin{pmatrix} 1 & 1 & 1 & 1 \\ 1 & 1 & -1 & -1 \\ 1 & -1 & 1 & -1 \\ 1 & -1 & -1 & 1 \end{pmatrix}$.
特征多项式 $(\lambda-2)^3(\lambda+2) = 0$.
特征值 $\lambda_1=2$ (代数重数 $r_1=3$), $\lambda_2=-2$ (代数重数 $r_2=1$).
所有特征值都在实数域中。
求 $\lambda_1=2$ 的几何重数：解 $(2E-A)X=0$.
$2E-A = \begin{pmatrix} 1 & -1 & -1 & -1 \\ -1 & 1 & 1 & 1 \\ -1 & 1 & 1 & 1 \\ -1 & 1 & 1 & 1 \end{pmatrix} \xrightarrow{RowOps} \begin{pmatrix} 1 & -1 & -1 & -1 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 \end{pmatrix}$.
秩 $r = 1$. 解空间维数 $d_1 = n - r = 4 - 1 = 3$.
几何重数 $d_1=3$ 等于代数重数 $r_1=3$.
求 $\lambda_2=-2$ 的几何重数：解 $(-2E-A)X=0$.
$-2E-A = \begin{pmatrix} -3 & -1 & -1 & -1 \\ -1 & -3 & 1 & 1 \\ -1 & 1 & -3 & 1 \\ -1 & 1 & 1 & -3 \end{pmatrix} \xrightarrow{RowOps} \dots$ (解方程组得到基础解系由 1 个向量组成).
几何重数 $d_2 = 1$. 等于代数重数 $r_2=1$.
因为 $d_1=r_1=3$ 且 $d_2=r_2=1$，所有特征值都在实数域，所以 A 可以对角化。
属于 $\lambda_1=2$ 的基础解系是 $\eta_1=(1,1,0,0)^T, \eta_2=(1,0,1,0)^T, \eta_3=(1,0,0,1)^T$.
属于 $\lambda_2=-2$ 的基础解系是 $\eta_4=(-1,1,1,1)^T$.
将这些向量作为列构成矩阵 $P$:
$P = \begin{pmatrix} 1 & 1 & 1 & -1 \\ 1 & 0 & 0 & 1 \\ 0 & 1 & 0 & 1 \\ 0 & 0 & 1 & 1 \end{pmatrix}$.
则 $P^{-1}AP = \Lambda = \begin{pmatrix} 2 & 0 & 0 & 0 \\ 0 & 2 & 0 & 0 \\ 0 & 0 & 2 & 0 \\ 0 & 0 & 0 & -2 \end{pmatrix}$. (对角线元素顺序对应 P 中特征向量的顺序).

**例 3 (Nilpotent Matrix):** $A \neq 0$ 且 $A^m=0$. 证明 A 不能与对角阵相似。
反证法：假设 $A$ 可对角化，则存在可逆 $P$ 使 $P^{-1}AP = \Lambda = \text{diag}(\lambda_1, \dots, \lambda_n)$.
那么 $(P^{-1}AP)^m = \Lambda^m$.
$P^{-1}A^m P = \Lambda^m$.
已知 $A^m=0$，所以 $P^{-1}0P = 0 = \Lambda^m$.
$\Lambda^m = \text{diag}(\lambda_1^m, \dots, \lambda_n^m) = 0$.
这意味着 $\lambda_i^m = 0$ 对所有 $i=1, \dots, n$ 成立。由于 $\lambda_i$ 是数，这只有当 $\lambda_i = 0$ 对所有 $i$ 成立时发生。
所以 $\Lambda = \text{diag}(0, \dots, 0) = 0$.
$P^{-1}AP = 0 \Rightarrow AP = P0 = 0$. 左乘 $P$: $A = P0 = 0$.
这与已知条件 $A \neq 0$ 矛盾。所以假设不成立，A 不能与对角阵相似 (不可对角化)。
这样的矩阵称为**幂零矩阵**。幂零矩阵（非零）的唯一特征值是 0，但其几何重数（零空间的维数 $n - rank(A)$）小于代数重数 $n$.

**例 4 ($A^2=A$):** 证明如果 $A^2=A$，则 A 的特征值只能是 0 或 1，且 A 可对角化。
(1) 设 $\lambda$ 是 $A$ 的特征值，$\alpha \neq 0$ 是对应的特征向量。$A\alpha = \lambda\alpha$.
$A^2\alpha = A(A\alpha) = A(\lambda\alpha) = \lambda A\alpha = \lambda (\lambda\alpha) = \lambda^2 \alpha$.
同时由 $A^2=A$， $A^2\alpha = A\alpha = \lambda\alpha$.
所以 $\lambda^2 \alpha = \lambda \alpha$.
$(\lambda^2 - \lambda)\alpha = 0$.
因为 $\alpha \neq 0$，所以 $\lambda^2 - \lambda = 0$. $\lambda(\lambda-1) = 0$.
特征值只能是 $\lambda=0$ 或 $\lambda=1$.

(2) 证明 A 可对角化。
我们需要证明属于特征值 0 和 1 的特征子空间的维数之和等于 $n$.
$V_{\lambda=0} = \{ \alpha \mid A\alpha = 0\alpha = 0 \}$. 这是矩阵 $A$ 的**零空间 (Null space)** $N(A)$.
$V_{\lambda=1} = \{ \alpha \mid A\alpha = 1\alpha = \alpha \}$. 这是方程 $(A-E)\alpha = 0$ 的解空间。

对于满足 $A^2=A$ 的矩阵，有 $P^n = N(A) \oplus R(A)$. ($R(A)$ 是 $A$ 的列空间，即值域)。
证明 $R(A) = V_{\lambda=1}$:
*   若 $\beta \in R(A)$, 则 $\beta = A\gamma$ 对某个 $\gamma \in P^n$.
    $A\beta = A(A\gamma) = A^2\gamma$. 因为 $A^2=A$, $A^2\gamma = A\gamma = \beta$.
    所以 $A\beta = \beta$, 即 $\beta \in V_{\lambda=1}$. 故 $R(A) \subseteq V_{\lambda=1}$.
*   若 $\beta \in V_{\lambda=1}$, 则 $A\beta = \beta$.
    这意味着 $\beta = A\beta$. 根据值域的定义，$A\beta$ 是 $A$ 的某个向量的像，所以 $A\beta \in R(A)$.
    故 $\beta \in R(A)$. 故 $V_{\lambda=1} \subseteq R(A)$.
    综上，$R(A) = V_{\lambda=1}$.

所以 $P^n = V_{\lambda=0} \oplus V_{\lambda=1}$.
由直和的定义，这意味着 $P^n$ 中的任何向量 $\alpha$ 都可以唯一写成 $\alpha = \alpha_0 + \alpha_1$, 其中 $\alpha_0 \in V_{\lambda=0}$ 且 $\alpha_1 \in V_{\lambda=1}$.
这也意味着 $\dim P^n = \dim V_{\lambda=0} + \dim V_{\lambda=1}$.
即 $n = d_0 + d_1$.
因为特征值只有 0 和 1，代数重数之和 $r_0 + r_1 = n$.
我们有 $d_0 \le r_0$ 且 $d_1 \le r_1$.
又因为 $d_0 + d_1 = n = r_0 + r_1$, 这只能意味着 $d_0 = r_0$ 且 $d_1 = r_1$.
所有特征值（0 和 1）都在实数域内（假设 $P$ 是实数域），且几何重数等于代数重数。根据定理 7.5.8，A 可对角化。
满足 $A^2=A$ 的矩阵称为**幂等矩阵**或**投影矩阵**。它们总是可对角化的，相似于一个对角矩阵，对角线上只有 0 和 1，1 的个数等于矩阵的秩。

**例 6 (上三角矩阵):** $A = \begin{pmatrix} 1 & 1 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 2 \end{pmatrix}$. 能不能对角化？
$f_A(\lambda) = (\lambda-1)^2(\lambda-2)$.
特征值 $\lambda_1=1$ (代数重数 $r_1=2$), $\lambda_2=2$ (代数重数 $r_2=1$).
所有特征值都在实数域。
求 $\lambda_1=1$ 的几何重数：解 $(E-A)X=0$.
$E-A = \begin{pmatrix} 0 & -1 & 0 \\ 0 & 0 & 0 \\ 0 & 0 & -1 \end{pmatrix}$. 秩 $r = 2$.
解空间维数 $d_1 = n - r = 3 - 2 = 1$.
几何重数 $d_1=1$ 小于代数重数 $r_1=2$.
根据定理 7.5.8，因为存在特征值的几何重数不等于代数重数 ($d_1 < r_1$), 所以 A 不能对角化。

#### 总结对角化步骤的细化

结合所有定理和例子，判断一个矩阵 A (或线性变换 A) 是否可对角化，以及如何对角化：
1.  求出特征多项式 $f_A(\lambda) = |\lambda E - A|$ (或线性变换 A 在任意一组基下的矩阵 A 的特征多项式).
2.  求出特征方程 $f_A(\lambda) = 0$ 在数域 $P$ 中的所有根 $\lambda_1, \dots, \lambda_s$.
3.  **检查条件 1:** 如果存在特征值不在数域 $P$ 中 (例如在实数域上讨论，但出现了复特征值)，则 A 不能在数域 $P$ 上对角化。（但在复数域 C 上可能可以对角化）。
4.  如果所有特征值都在 $P$ 中，对于每个特征值 $\lambda_i$，确定其代数重数 $r_i$ (在 $f_A(\lambda)$ 中的因式 $(\lambda-\lambda_i)^{r_i}$ 的次数).
5.  对于每个特征值 $\lambda_i$，求解齐次线性方程组 $(\lambda_i E - A)X = 0$，求出其基础解系。基础解系的向量个数 $d_i$ 就是几何重数 $\dim V_{\lambda_i}$.
6.  **检查条件 2:** 比较每个特征值 $\lambda_i$ 的几何重数 $d_i$ 和代数重数 $r_i$. 如果 $d_i = r_i$ 对所有 $i=1, \dots, s$ 都成立，则 A 可对角化。否则，不可对角化。
7.  如果 A 可对角化，将所有特征子空间 $V_{\lambda_i}$ 的基础解系向量组合在一起，形成一个由 $n$ 个向量组成的集合。这些向量构成了 $P^n$ 的一组基（或 V 的一组基）。将这些向量按列排列组成矩阵 $P$.
8.  则 $P$ 是可逆矩阵，且 $P^{-1}AP = \Lambda$, 其中 $\Lambda$ 是对角矩阵，对角线上的元素是与 $P$ 中列向量对应的特征值，重复次数等于该特征值的几何重数 (和代数重数)。

#### 示例 (全为 a 的矩阵)

**例 5 (全为 a 的矩阵):** $A_{n \times n} = \begin{pmatrix} a & a & \dots & a \\ a & a & \dots & a \\ \vdots & \vdots & \ddots & \vdots \\ a & a & \dots & a \end{pmatrix}$ ($n > 1$). 将 A 对角化。
先求特征值：
$|A|$：所有行都相同，秩 $r(A)=1$ (如果 $a \neq 0$) 或 0 (如果 $a=0$). 如果 $a \neq 0$, $r(A)=1 < n$, 所以 $|A|=0$. 如果 $a=0$, $|A|=0$. 总之 $|A|=0$.
因为 $|A|=0$, $\lambda=0$ 是特征值。
$AX = 0 \iff \begin{pmatrix} a & a & \dots & a \\ \vdots & \vdots & \ddots & \vdots \\ a & a & \dots & a \end{pmatrix} \begin{pmatrix} x_1 \\ \vdots \\ x_n \end{pmatrix} = \begin{pmatrix} 0 \\ \vdots \\ 0 \end{pmatrix}$.
这等价于一个方程 $ax_1 + ax_2 + \dots + ax_n = 0$.
如果 $a=0$, 则 $A=0$, 特征值全是 0, $0E-A=0$, 秩为 0, 几何重数 $n$. A 就是零矩阵，已经是对方阵。
如果 $a \neq 0$, 方程是 $x_1 + x_2 + \dots + x_n = 0$.
这个方程的解空间维数是 $n-1$. (例如，令 $x_2, \dots, x_n$ 为自由变量，$x_1 = -(x_2 + \dots + x_n)$).
所以属于特征值 $\lambda=0$ 的几何重数 $d_0 = n-1$.
因为几何重数 $d_0=n-1$，根据 $d_0 \le r_0$，代数重数 $r_0 \ge n-1$.
所有特征值的代数重数之和等于 $n$. 如果只有一个特征值 0，那么 $r_0=n$.
但是 $A$ 不是零矩阵 ($a \neq 0$), 它有非零特征值吗？
迹 $tr(A) = a + a + \dots + a = na$.
特征值之和等于迹：$\sum \lambda_i = tr(A) = na$.
$n$ 个特征值中，有一个是 0 至少 $n-1$ 次 (代数重数 $\ge n-1$).
设特征值是 $\lambda_1, \dots, \lambda_n$. 其中至少 $n-1$ 个是 0. 比如 $\lambda_1=\dots=\lambda_{n-1}=0$.
那么 $\lambda_1 + \dots + \lambda_{n-1} + \lambda_n = 0 + \dots + 0 + \lambda_n = \lambda_n$.
同时迹是 $na$. 所以 $\lambda_n = na$.
如果 $na \neq 0$ (即 $a \neq 0$), 那么 $na$ 是一个非零特征值。
此时，特征值是 $\lambda=0$ (代数重数 $r_0=n-1$) 和 $\lambda=na$ (代数重数 $r_{na}=1$).
我们已经算得 $d_0 = n-1$.
对于 $\lambda=na$: 解 $(na E - A)X = 0$.
$\begin{pmatrix} na-a & -a & \dots & -a \\ -a & na-a & \dots & -a \\ \vdots & \vdots & \ddots & \vdots \\ -a & -a & \dots & na-a \end{pmatrix} \begin{pmatrix} x_1 \\ \vdots \\ x_n \end{pmatrix} = \begin{pmatrix} 0 \\ \vdots \\ 0 \end{pmatrix}$.
如果 $a=0$, 这是零矩阵 $0=0$, 解空间维数 $n$, $d_0=n$.
如果 $a \neq 0$: $\begin{pmatrix} (n-1)a & -a & \dots & -a \\ -a & (n-1)a & \dots & -a \\ \vdots & \vdots & \ddots & \vdots \\ -a & -a & \dots & (n-1)a \end{pmatrix} X = 0$.
对系数矩阵进行行变换。将所有行加到第一行：第一行变成 $((n-1)a - (n-1)a, \dots) = (0, \dots)$.
呃，加到第一行不对。 将所有列加到第一列，再把第一列乘以 $a$ 加到其他列... 比较麻烦。
换个思路找属于 $na$ 的特征向量。 $A\alpha = na \alpha$.
$\begin{pmatrix} a\sum x_i \\ a\sum x_i \\ \vdots \\ a\sum x_i \end{pmatrix} = na \begin{pmatrix} x_1 \\ x_2 \\ \vdots \\ x_n \end{pmatrix}$.
$a \sum x_i = na x_j$ 对所有 $j=1, \dots, n$ 成立。
如果 $a \neq 0$, $\sum x_i = n x_j$.
所以 $x_1 = x_2 = \dots = x_n$.
且 $nx_1 = nx_1$, 这是恒等式。
特征向量的形式是 $(c, c, \dots, c)^T$, $c \neq 0$. 例如 $(1, 1, \dots, 1)^T$.
属于 $\lambda=na$ 的特征子空间维数 $d_{na}=1$.
几何重数 $d_0=n-1$, 代数重数 $r_0=n-1$. ($d_0 = r_0$).
几何重数 $d_{na}=1$, 代数重数 $r_{na}=1$. ($d_{na} = r_{na}$).
所有特征值都在实数域 (假设 $a$ 是实数)，几何重数都等于代数重数。所以 A 可以对角化。
属于 $\lambda=0$ 的特征向量构成解空间 $x_1+\dots+x_n=0$ 的基。例如 $(-1, 1, 0, \dots, 0)^T, (-1, 0, 1, \dots, 0)^T, \dots, (-1, 0, 0, \dots, 1)^T$ 共 $n-1$ 个。
属于 $\lambda=na$ 的特征向量是 $(1, 1, \dots, 1)^T$.
将这些向量作为列构成 $P$：
$$P = \begin{pmatrix}
-1 & -1 & \dots & -1 & 1 \\
1 & 0 & \dots & 0 & 1 \\
0 & 1 & \dots & 0 & 1 \\
\vdots & \vdots & \ddots & \vdots & \vdots \\
0 & 0 & \dots & 1 & 1
\end{pmatrix}$$
则 $$P^{-1}AP = \Lambda = \begin{pmatrix}
0 & & & & \\
& 0 & & & \\
& & \ddots & & \\
& & & 0 & \\
& & & & na
\end{pmatrix}$$ (对角线上前 $n-1$ 个是 0，最后一个是 $na$).

---

### 总结与要点提炼 (Summary & Key Takeaways)

*   **线性变换与矩阵:** 线性变换可以通过它对一组基向量的作用来完全确定。将这些作用的结果（在同一组基下的坐标）按列排成矩阵，就得到了线性变换在这组基下的矩阵表示。这是一个非常重要的一一对应。
*   **坐标变换:** 向量的坐标在变换下的结果，可以通过矩阵乘以原坐标向量得到 ($Y = AX$)。
*   **相似矩阵:** 同一个线性变换在不同基下的矩阵是相似的 ($B = P^{-1}AP$)。相似矩阵拥有相同的行列式、迹、特征多项式和特征值，它们反映了线性变换的本质属性，与基无关。
*   **特征值与特征向量:** $A\alpha = \lambda\alpha$ ($\alpha \neq 0$). 特征向量 $\alpha$ 指示了在变换下方向不变的方向，特征值 $\lambda$ 表示了沿着该方向的缩放因子。
*   **求特征值/向量:** 通过特征方程 $|\lambda E - A| = 0$ 求特征值 $\lambda$，然后解齐次方程组 $(\lambda E - A)X = 0$ 求特征向量（坐标）。属于同一特征值的非零特征向量及零向量构成特征子空间。
*   **性质:** 特征值和特征向量有很多重要性质，特别是关于多项式、逆矩阵、伴随矩阵的性质。属于不同特征值的特征向量是线性无关的。
*   **哈密尔顿-凯莱定理:** 矩阵满足自己的特征多项式 $f_A(A) = 0$. 这个定理在计算逆矩阵和矩阵的高次幂时非常有用，可以将高次幂转化为低于 $n$ 次的矩阵多项式。
*   **对角化:** 寻找一组基，使得线性变换在该基下的矩阵是对角矩阵。或者说，矩阵相似于一个对角矩阵。这是最简单的矩阵形式，便于计算和分析。
*   **对角化条件:** $n$ 阶矩阵 A (或 $n$ 维线性变换 A) 可对角化的充要条件是它有 $n$ 个线性无关的特征向量。
*   **几何重数 vs 代数重数:** 可对角化的更精确条件是：所有特征值都在数域 $P$ 中，并且每个特征值的几何重数（特征子空间维数）等于其代数重数（特征多项式中的重数）。几何重数总是不超过代数重数。
*   **对角化过程:** 求出所有特征值，对每个特征值求出其特征子空间的一组基。如果基向量总数等于 $n$ (即几何重数等于代数重数)，则将这些基向量作为列构成可逆矩阵 $P$，则 $P^{-1}AP$ 是对角矩阵，对角线元素是对应的特征值。

### 学科思想与延伸思考 (Underlying Philosophy & Further Thinking)

*   **抽象与具象的转化:** 线性代数的一个核心思想就是将抽象的向量空间和线性变换，通过选择一组基，转化为具体的坐标和矩阵运算。对角化则是在这种转化中追求“最简单”的表示。
*   **不变性:** 特征值和特征多空间是线性变换的“内在”属性，它们不随基的选择而改变。它们抓住了变换的核心行为。
*   **空间的分解:** 如果一个空间可以被对角化，这意味着它可以分解成一些彼此独立的“特征方向”（特征子空间），线性变换在每个方向上仅仅是伸缩。整个复杂的变换行为被分解成了这些简单的伸缩。定理 $V = V_{\lambda_1} \oplus \dots \oplus V_{\lambda_s}$ 正是这种分解的体现。
*   **不是所有矩阵都能对角化:** 当几何重数小于代数重数时，“缺失”了足够的特征向量，空间无法完全分解到独立伸缩的方向上。这时，最好的简化形式是 Jordan 标准型，它在对角块之外还有一些 1，表示了除了伸缩之外的“剪切”行为。
*   **应用:** 特征值和特征向量的应用遍布科学和工程领域：
    *   **动力系统:** 预测系统的长期行为（哪些分量会增长/衰减最快，哪些方向是稳定的）。斐波那契数列就是一例。
    *   **微分方程:** 解线性常微分方程组。
    *   **数据分析:** 主成分分析 (PCA) 寻找数据中最重要的方向（方差最大的方向），这些方向就是协方差矩阵的特征向量。
    *   **量子力学:** 能量是哈密顿算符的特征值，量子态是特征向量。
    *   **图论:** 图的邻接矩阵的特征值和特征向量反映了图的结构性质。
    *   **搜索引擎:** PageRank 算法的核心就是计算一个巨大转移矩阵的特征向量。

对角化是理解线性变换结构、简化计算和揭示系统本质的重要工具。虽然不是所有矩阵都能对角化，但可对角化矩阵的性质非常良好。即使不可对角化，Jordan 标准型也提供了一种“尽量接近对角形”的标准形式。

#### 思考题

你提供的思考题非常好，覆盖了这些概念的应用：
1.  需要找出微分变换在基下的矩阵，然后判断其对角化条件。
2.  利用哈密尔顿-凯莱定理的思想和秩的性质来推断特征值。
3.  分析 $\alpha \beta^T$ 这种特殊矩阵的特征值和特征向量，判断对角化。这是一个秩为 1 的矩阵。
4.  对合矩阵 $A^2=E$ 和幂等矩阵 $A^2=A$ 类似，特征值只能是 1 或 -1。可以利用类似幂等矩阵的方法证明其可对角化。
5.  利用给定的条件 $AB=2B, AC=C$ 以及秩的性质来分析 $A$ 的特征值和可对角化性。
6.  重复了 $A$ 和 $A^T$ 特征值相同，已在讲义中证明。

希望这次深入的讲解能够帮助你更好地理解这些概念！在线性代数的学习中，多问“为什么”，多尝试自己推导，将抽象概念与具体的矩阵运算和几何图像联系起来，你会越来越有感觉的！加油！