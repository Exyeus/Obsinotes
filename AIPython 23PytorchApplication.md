![[Pasted image 20250512152548.png]]
![[Pasted image 20250512152633.png]]

![[Pasted image 20250512152648.png]]
好的，同学们！欢迎回到我们的课堂。在过去几周的学习中，我们一起探索了 Python 在科学计算，特别是在人工智能领域的基础应用。我们从 Python 语言本身的进阶特性（比如变量和对象引用）出发，深入了解了强大的 NumPy 库及其在处理数值数据和进行线性代数运算上的优势。我们还学习了如何利用这些工具去解决一个基本的机器学习问题：线性回归，并通过梯度下降法找到了模型的最佳参数。同时，我们也花了一些时间了解了人工智能的宏大图景、发展历史以及机器学习的基本流程和评估方法。

今天，我们将踏入人工智能深度学习领域的核心——PyTorch。PyTorch 是目前学术界和工业界非常流行的深度学习框架之一，它将极大地简化我们构建、训练和部署复杂模型的过程。本周我们将学习 PyTorch 的基础知识，特别是它的核心组成部分：Tensor 和 AutoGrad，以及如何利用这些工具和 `nn` 工具箱来实现一个简单的线性回归模型。

让我们先快速回顾一下之前课程的一些核心知识点，它们是理解 PyTorch 的基础：

---

### 三、 前期课程要点回顾

#### 3.1 Python 和 Numpy 进阶 - 变量、对象引用

我们学习了 Python 中变量和对象引用的概念。重要的是理解：

*   变量是对象的“标签”或“引用”，而不是存储对象值本身的容器。
*   赋值操作 = 是将一个变量名关联到一个对象。
*   `is` 运算符检查两个变量是否引用同一个对象（内存地址相同），而 == 检查对象的值是否相等。
*   对象分为**可变对象**（如 `list`, `dict`, `set`）和**不可变对象**（如 `int`, `float`, `str`, `tuple`）。修改可变对象会改变其内容，而不可变对象一旦创建就不能修改其值（看似修改实则是创建新对象并将变量指向新对象）。
*   函数参数传递是**共享传参 (call by sharing)**：传递的是对象引用的复本。函数内部的形参是外部实参的别名。修改函数内部的可变对象会影响外部，但对不可变对象重新赋值则不会。 mutable 默认值是陷阱的根源在于默认值是一个可变对象，它在函数定义时创建并绑定到函数对象上，后续所有不传递该参数的函数调用都会共享这个默认值对象。

#### 3.2 Numpy 与科学计算基础

NumPy 是 Python 中进行科学计算的基石，特别是处理大规模同质数据：

*   核心数据结构是 `ndarray`（N-dimensional array），它是一个多维数组，所有元素必须是**同一种数据类型**。
*   `ndarray` 数据存储在**连续的内存空间**中，相比 Python 列表效率更高。
*   NumPy 提供了丰富的数组创建方法（`zeros`, `ones`, `arange`, `randn` 等）。
*   重要的特性包括：
    *   **向量化 (Vectorization):** 对 `ndarray` 的运算通常会自动应用到每个元素，避免显式的 Python 循环，效率极高。
    *   **广播 (Broadcasting):** 允许 NumPy 在执行算术运算时，自动调整不同形状数组的大小，使其兼容，而无需复制数据。
    *   **归约 (Reduction):** 如 `sum()`, `mean()`, `max()` 等操作，将一个维度或所有维度的数据规约为一个或少数几个值。
*   NumPy 支持高效的**索引和切片**操作，需要注意的是切片通常返回原数组的**视图 (view)**，修改视图会影响原数组。 `.copy()` 方法可以显式创建副本。
*   NumPy 提供了丰富的**线性代数运算**（矩阵乘法 `@` 或 `.mm()`, 转置 `.T` 或 `.transpose()`, 逆 `.linalg.inv()` 等）。这些运算是机器学习和深度学习算法的基础。

#### 3.3 线性回归与梯度下降

我们将机器学习的第一个任务聚焦在**回归分析**，特别是线性回归：

*   **回归任务:** 预测一个连续的目标值 $y$ 基于一个或多个输入特征 $\mathbf{x}$。
*   **模型:** 我们假设目标值与特征之间存在线性关系，即 $\hat{y} = \mathbf{x} \cdot \mathbf{w} + b$。为了简化表示，我们将偏置项 $b$ 合并到权重向量 $\mathbf{w}$ 中，通过在特征向量 $\mathbf{x}$ <font color="#ffff00">末尾添加一个恒为 1 的维度来实现</font>（称为**偏置技巧**）。模型变为 $\hat{y} = \mathbf{x} \cdot \mathbf{w}$，其中 $\mathbf{x}$ 是扩充后的特征向量。
*   **损失函数:** 我们需要一个量化指标来衡量模型预测值 $\hat{y}$ 与真实值 $y$ 之间的差距。对于线性回归，我们使用了**均方误差 (Mean Squared Error, MSE)**:
    $$ L(\mathbf{w}) = \frac{1}{N} \sum_{i=1}^N (\hat{y}_i - y_i)^2 = \frac{1}{N} \sum_{i=1}^N (\mathbf{x}_i \cdot \mathbf{w} - y_i)^2 $$
    我们的目标是找到使 $L(\mathbf{w})$ 最小的参数 $\mathbf{w}^*$。
*   **优化:** 最小化损失函数通常使用**梯度下降法 (Gradient Descent)**。这是一种迭代优化算法：
    1.  随机初始化参数 $\mathbf{w}$。
    2.  在当前参数值处，计算损失函数对参数的梯度 $\nabla_\mathbf{w} L$（梯度指示了函数增长最快的方向）。
    3.  沿着梯度的反方向更新参数： $\mathbf{w} \leftarrow \mathbf{w} - \alpha \nabla_\mathbf{w} L$，其中 $\alpha$ 是**学习率 (learning rate)**，控制每次更新的步长。
    4.  重复步骤 2-3，直到参数收敛（变化很小）或达到最大迭代次数。
*   我们推导了 MSE 损失函数对于 $\mathbf{w}$ 的梯度，并写成了简洁的矩阵形式：
    $$ \nabla_\mathbf{w} L = \frac{2}{N} \mathbf{X}^T (\mathbf{X}\mathbf{w} - \mathbf{y}) $$
    其中 $\mathbf{X}$ 是训练样本特征组成的 $N \times (d+1)$ 矩阵（包含偏置列），$\mathbf{y}$ 是真实目标值组成的 $N \times 1$ 向量。
*   我们还介绍了 Matplotlib 库，用于可视化数据分布（散点图、直方图）、函数曲线（折线图）以及二维函数（如损失函数）的等高线图，这有助于我们直观理解梯度下降过程。

#### 3.4 逻辑回归

我们将线性模型的概念扩展到了**分类任务**，特别是**二分类**：

*   **分类任务:** 预测一个离散的类别标签，例如判断邮件是否为垃圾邮件（标签为 0 或 1）。
*   **为什么不用线性回归?** 线性回归的输出是一个连续值 $(-\infty, +\infty)$，不适合直接表示类别标签（通常为离散值）。此外，即使映射到 $[0, 1]$，线性模型的输出对输入过于敏感，一个小变化可能导致输出跨越分类边界。
*   **模型:** 逻辑回归首先计算一个线性分数 $z = \mathbf{x} \cdot \mathbf{w}$，然后将 $z$ 通过 **Sigmoid 函数** $g(z) = \frac{1}{1 + e^{-z}}$ 映射到 $[0, 1]$ 区间。这个输出值 $p = g(z)$ 可以解释为样本属于正类（类别 1）的**概率**。最终预测类别通常根据概率与阈值（如 0.5）进行比较：$\hat{y} = 1$ 如果 $p \ge 0.5$，否则 $\hat{y} = 0$。
*   **损失函数:** 对于分类问题，MSE 损失函数不太适合衡量概率预测的好坏。逻辑回归通常使用**交叉熵损失 (Cross-Entropy Loss)**，它源自<font color="#ffff00">最大化训练数据出现的概率（最大似然估计）</font>：
    $$ L(\mathbf{w}) = -\frac{1}{N} \sum_{i=1}^N [y_i \ln p_i + (1-y_i) \ln(1-p_i)] $$
    其中 $y_i$ 是真实标签（0或1），$p_i$ 是模型预测为正类的概率 $g(\mathbf{x}_i \cdot \mathbf{w})$。
*   **优化:** 同样使用梯度下降法最小化交叉熵损失。我们推导了交叉熵损失对于 $\mathbf{w}$ 的梯度，其矩阵形式与线性回归的梯度形式非常相似，只是 $(\mathbf{Xw} - \mathbf{y})$ 部分被替换为 $(\mathbf{p} - \mathbf{y})$：
    $$ \nabla_\mathbf{w} L = \frac{1}{N} \mathbf{X}^T (\mathbf{p} - \mathbf{y}) $$
    其中 $\mathbf{p}$ 是模型对所有样本预测的概率组成的 $N \times 1$ 向量。

#### 3.5 机器学习流程与评估

我们了解了构建一个机器学习系统的一般流程：

*   **数据准备:**
    *   **数据标注:** 为原始数据打上标签，构建监督学习所需的训练数据。
    *   **数据分割:** 将标注数据划分为训练集、验证集（用于超参数调优）和测试集（用于最终性能评估），确保测试集的数据对模型是“未知”的。
    *   **特征提取:** 将原始数据（文本、图像等）转换成机器学习算法可以处理的固定长度数值向量。
*   **模型训练:** 选择合适的模型架构和损失函数，使用训练集数据，通过优化算法（如梯度下降）最小化损失函数，学习模型的参数。
*   **模型测试与评估:** 使用测试集数据，计算模型的预测结果，并与真实标签对比，使用合适的**性能评价指标**来量化模型的表现。
*   **二分类评价指标:** 除了简单的**正确率 (Accuracy)** $\frac{TP+TN}{TP+FN+FP+TN}$ （在正负样本不平衡时可能失效），我们还学习了基于**混淆矩阵**（TP, FP, FN, TN）的更健壮指标：
    *   **精确率 (Precision):** $\frac{TP}{TP+FP}$ （预测为正例的样本中有多少是真正例）
    *   **召回率 (Recall):** $\frac{TP}{TP+FN}$ （所有真正例中有多少被模型找了出来）
    *   **F1 值 (F1-score):** $\frac{2 \times Precision \times Recall}{Precision + Recall}$ （Precision 和 Recall 的调和平均数，综合衡量两者的性能）

#### 3.6 人工智能导论

我们回顾了人工智能的起源（图灵测试，达特茅斯会议）、发展历史（早期AI、专家系统、两次AI冬天、统计机器学习、深度学习崛起）和重要里程碑（感知机、专家系统、ImageNet、AlphaGo、GPT系列）。了解了回归、分类、聚类、强化学习等不同的机器学习任务类型。

#### 3.7 PyTorch 入门 - Tensor 和 AutoGrad

我们正式引入了 PyTorch，一个强大的深度学习框架。

*   **为何需要框架?** 手动实现梯度下降等算法对于复杂模型（如神经网络）非常繁琐且容易出错。框架提供了高度优化的底层实现、GPU 加速能力以及自动微分功能，让我们能更专注于模型设计。
*   **PyTorch 的核心:**
    *   **Tensor:** PyTorch 的基本数据结构，类似于 NumPy 的 `ndarray`，但支持在 GPU 上进行计算，并且是构建计算图、实现自动微分的基础。我们看了 Tensor 的创建、基本运算、形状操作、索引切片以及与 NumPy 数组的转换。
    *   **AutoGrad:** PyTorch 的自动微分引擎。通过跟踪对 Tensor 的操作，它会隐式构建一个**计算图**。当我们对一个标量输出 Tensor（如损失函数）调用 `.backward()` 方法时，AutoGrad 会自动遍历计算图，使用链式法则计算图中所有需要梯度的 Tensor（通常是模型的参数）的梯度，并将结果存储在其 `.grad` 属性中。这是训练复杂模型（特别是深度学习模型）的关键。我们学习了如何通过设置 `requires_grad=True` 来标记需要计算梯度的 Tensor，以及如何在优化步骤前使用 `.zero_grad()` 清除累积的梯度。

---

### 四、 本周重点：PyTorch 基础

欢迎来到本周的学习！基于我们对 Python、NumPy、线性回归、梯度下降以及 PyTorch 的初步认识，我们将更深入地探索 PyTorch，特别是它的 `nn` 工具箱，并学习如何用 PyTorch 实现一个完整的机器学习模型训练和测试流程，以线性回归为例。

#### 4.1 引入与动机：告别手动求导，迈向模块化构建

前面我们用 NumPy 从头实现了线性回归的训练过程。这是一个非常宝贵的经历，因为它让我们理解了机器学习模型训练的核心机制：<font color="#ffff00">前向计算、损失计算、梯度计算和参数更新</font>。我们手动推导了损失函数的梯度公式，并用 NumPy 向量化地实现了它。

然而，回想一下梯度下降的更新公式：$\mathbf{w} \leftarrow \mathbf{w} - \alpha \nabla_\mathbf{w} L$。这里的关键挑战是**计算梯度** $\nabla_\mathbf{w} L$。对于像线性回归或逻辑回归这样简单的模型，手动推导梯度是可行的。但想象一下深度神经网络：它可能有几十层甚至上百层，每一层都包含复杂的数学运算（矩阵乘法、非线性激活等），参数数量可能有几百万甚至上亿。要手动推导整个网络输出（比如最终的损失）对每一个参数的梯度，几乎是不可能的任务！而且，即使推导出来，手动实现如此复杂的梯度计算也是极易出错的。

这就是 PyTorch 等深度学习框架的强大之处。它们的核心能力之一就是**自动微分 (Automatic Differentiation)**，也就是我们上周初步接触的 AutoGrad。<font color="#ffff00">有了自动微分，我们只需要定义模型的前向计算过程（数据如何从输入流向输出，如何计算损失），框架就能自动帮我们计算出所有参数的梯度。这解放了我们，让我们能将精力放在设计更好的模型架构和训练策略上，而不是陷在繁琐的数学推导和易错的代码实现中</font>。

此外，复杂的模型往往是由一些**标准的组件**（比如一层线性变换、一层卷积、一个激活函数）组合而成。如果每次都要从零开始构建这些组件，效率会非常低下。PyTorch 提供了 `torch.nn` 这个工具箱，它就像一个包含了各种预制、高度优化的神经网络“乐高积木”，我们可以非常方便地构建复杂的模型结构。

所以，本周的目标就是学习如何利用 PyTorch 的 `Tensor`、`AutoGrad` 以及 `nn` 工具箱，以一种更高效、更模块化的方式实现机器学习模型的训练和测试。我们将从最简单的线性回归开始，但学到的方法将直接应用于更复杂的深度学习模型。

#### 4.2 必要知识回顾：Tensor 与 AutoGrad 的基石

在深入 `nn` 工具箱之前，我们必须牢固掌握 PyTorch 的两个核心概念：

1.  **Tensor:**
    *   它是 PyTorch 中所有数据表示的基础。
    *   它是一个多维数组，类似于 NumPy 的 `ndarray`，但能够在 GPU 上加速运算。
    *   可以通过 `torch.tensor()`, `torch.randn()`, `torch.zeros()` 等方式创建。
    *   具有 `.dtype` (数据类型), `.shape` (形状), `.device` (所在设备，CPU 或 CUDA) 等属性。
    *   **关键属性 `requires_grad`:** 如果设置为 `True`，PyTorch 会跟踪对这个 Tensor 的所有操作，以便后续计算梯度。这通常用于需要优化的模型参数。
    *   **关键属性 `is_leaf`:** 表示这个 Tensor 是否是计算图的叶子节点，通常是用户直接创建的或者不需要梯度的 Tensor。需要梯度的 Tensor 如果不是由用户直接创建（而是通过某个运算得到），则不是叶子节点。

2.  **[[Gemini AutoGrad]]:**
    *   它是 PyTorch 的自动微分引擎。
    *   在对 `requires_grad=True` 的 Tensor 进行运算时，AutoGrad 会记录这些运算并构建一个**动态计算图 (Dynamic Computation Graph)**。图中的节点是 Tensor，边是运算。
    *   对于一个通过一系列运算得到的**标量 (scalar)** Tensor（比如最终的损失值），调用 `.backward()` 方法会触发反向传播过程。AutoGrad 会沿着计算图从这个标量 Tensor 向前追溯到所有 `requires_grad=True` 的叶子节点 Tensor，并使用链式法则计算这个标量 Tensor 对这些叶子节点 Tensor 的梯度。
    *   计算出的梯度会累积到对应 Tensor 的 `.grad` 属性中。**注意：梯度是累积的！** 如果不手动清零，每次调用 `.backward()` 都会将新的梯度加到 `.grad` 中。因此，在每次训练迭代计算新梯度之前，必须用 `.zero_grad()` 方法（通常是优化器的或者模型自身的）将所有参数的梯度清零。
    *   对于非标量 Tensor，调用 `.backward()` 需要传入一个与 Tensor 形状相同的梯度张量（称为 `gradient` 参数），表示上游传来的梯度。这在某些高级场景有用，但对于常见的“计算损失对参数的梯度”任务，损失是标量，直接调用 `.backward()` 即可。

理解 `Tensor` 的属性（特别是 `requires_grad`）和 `AutoGrad` 的 `.backward()` 工作原理（计算标量对叶子节点的梯度，梯度累积需要清零）是使用 PyTorch 进行模型训练的基础。

#### 4.3 直观解释与感性认识：PyTorch 的“零件盒”与“自动化工厂”

*   **`nn` 工具箱 (零件盒):** 想象你在组装一台复杂的机器。你可以从零开始制作每一个螺丝、每一个齿轮，但这非常耗时。或者，你可以去一个零件商店，里面有各种标准化的、高质量的零件（齿轮组、轴承、电机等）。`torch.nn` 就是这个零件商店。它提供了构建神经网络所需的各种标准“层”(`Linear`, `Conv2d`, `ReLU` 等)，以及一些方便的容器（如 `Sequential`）可以将这些层像乐高一样堆叠起来。这些层都预先设计好，知道如何处理输入数据，并且最重要的是，它们知道如何与 AutoGrad 协同工作，自动处理前向计算和反向传播所需的信息。
*   **`nn.Module` (组装好的子组件/整机):** `nn.Module` 是 `nn` 工具箱的核心概念，它是所有零件（层）和组装好的子组件（甚至是整个模型）的基类。你可以把它想象成一个蓝图或者一个已经组装好的、带有输入接口和输出接口的盒子。每个 `nn.Module` 都知道它有哪些可调节的内部旋钮（**参数**，比如线性层中的权重和偏置），并且知道数据从输入接口进来后，如何在内部流动、经过哪些计算步骤最终从输出接口出去（这个计算步骤由 `forward()` 方法定义）。当你在 PyTorch 中定义一个模型时，你通常会创建一个继承自 `nn.Module` 的类，并在其中定义模型的结构和前向计算逻辑。
>一个基类。在神经网络之中的所有类，都是 `nn.Module` 的子类。

*   **`Parameter` (内部旋钮):** 在 `nn.Module` 内部，那些需要通过训练来学习、需要被优化的数值（比如权重矩阵 $\mathbf{W}$ 和偏置向量 $\mathbf{b}$）被特别标记为 `Parameter`。`Parameter` 实际上是 `Tensor` 的一个特殊子类，但它会被 `nn.Module` 自动识别并加入到 `model.parameters()` 的列表中，而且默认 `requires_grad=True`。这就是 AutoGrad 如何知道哪些 Tensor 是需要计算梯度的模型参数。
>一个子类

*   **`Optimizer` (自动化调旋钮工人):** 有了零件、组装好的机器和内部旋钮，我们还需要一个工人来根据机器的运行情况（损失大小）自动化地调节这些旋钮，以提升机器的性能（降低损失）。`torch.optim` 工具箱提供了各种优化算法（如 SGD, Adam 等）。你创建一个 `Optimizer` 实例，告诉它要优化哪些参数（就是 `model.parameters()` 返回的那些），以及使用的学习率等超参数。在训练过程中，`Optimizer` 会接收 AutoGrad 计算好的梯度，并按照选定的优化算法（如 $\mathbf{w} \leftarrow \mathbf{w} - \alpha \nabla_\mathbf{w} L$）来更新模型的参数。

总结来说，你可以用 `nn.Module` 来定义你的模型结构，模型内部的可训练数值用 `Parameter` 表示。`nn` 工具箱提供了很多现成的 `nn.Module` 子类作为基础构建块。当你给模型输入数据并计算出损失后，`AutoGrad` 会自动计算损失对所有 `Parameter` 的梯度。最后，`Optimizer` 会利用这些梯度来更新 `Parameter` 的值。整个过程就像一个高效的自动化工厂。


> [!NOTE] 
> Data
> 	sets of dots in spaces. every one repr $(x,y)$.
> Task
> Module
> Loss Function
> Optimization


#### 4.4 逐步形式化与精确定义：PyTorch 的核心 API

现在我们将直观理解转化为具体的 PyTorch 代码概念。

*   **`torch.nn.Module`:**
    *   基类，所有神经网络模块的父类。
    *   你自定义模型时，通常会继承它： `class MyModel(nn.Module): ...`
    *   在 `__init__(self, ...)` 方法中：
        *   必须调用父类的构造函数： `super().__init__()` 或 `nn.Module.__init__()`。
        *   定义模型的各种子模块（其他 `nn.Module` 实例）或需要学习的参数 (`nn.Parameter` 实例），并将它们赋值为类的属性（这样它们会被 `nn.Module` 自动注册）。例如： `self.linear = nn.Linear(in_features, out_features)` 或 `self.weight = nn.Parameter(torch.randn(...))`。
    *   必须重写 `forward(self, x, ...)` 方法：
        *   定义输入 `x` 如何经过一系列计算得到输出。
        *   这个方法定义了模型的前向传播逻辑。
        *   `forward` 方法中进行的 Tensor 运算会被 AutoGrad 记录。
    *   `nn.Module` 实例是**可调用的 (callable)**。调用一个 Module 实例 `model(input)` 等价于调用 `model.__call__(input)`，后者内部会执行一些注册和钩子操作，最终调用 `model.forward(input)`。
    *   `model.parameters()`: 返回一个迭代器，遍历模型中所有被注册为 `nn.Parameter` 的属性（包括子 Module 中的 Parameter）。这些是需要训练的参数。
    *   `model.train()` 和 `model.eval()`: 设置 Module 的模式。影响到 `Dropout` 和 `BatchNorm` 等层的行为（训练时启用随机性/统计累积，评估时关闭随机性/使用固定统计）。对于线性回归这样简单的模型影响不大，但养成习惯很重要。

*   **`torch.nn.parameter.Parameter`:**
    *   `Parameter` 是 `Tensor` 的子类。
    *   创建方式：`nn.Parameter(data, requires_grad=True)`。`data` 是一个 `Tensor`。默认 `requires_grad` 为 `True`。
    *   当你将一个 `Parameter` 实例赋值给一个 `nn.Module` 实例的属性时（例如 `self.weight = nn.Parameter(...)`），它会自动被添加到 Module 的参数列表中。

*   **`torch.optim.Optimizer`:**
    *   基类，所有优化算法的父类。
    *   创建实例时，需要传入需要优化的参数（通常是 `model.parameters()` 的结果）和优化器的超参数（如学习率 `lr`）。例如：`optimizer = torch.optim.SGD(model.parameters(), lr=0.01)`。
    *   关键方法：
        *   `optimizer.zero_grad()`: 清除所有被优化器管理参数的 `.grad` 属性中的梯度。
        *   `optimizer.step()`: 根据当前存储在参数 `.grad` 属性中的梯度和优化器规则，更新参数的值。

*   **`torch.nn.modules.loss`:**
    *   包含各种标准的损失函数，它们也是 `nn.Module` 的子类。
    *   例如，**均方误差损失 (MSELoss)**: `loss_fn = nn.MSELoss()`。
    *   实例化后，损失函数实例也是可调用的。调用 `loss = loss_fn(prediction, target)` 会计算预测值和真实目标之间的损失，返回一个标量 Tensor。

#### 4.5 核心原理与推导过程（PyTorch 视角）：构建计算流

在 PyTorch 中训练模型的核心思想是构建一个**计算流**，然后让 AutoGrad 自动处理反向传播。我们不再手动推导和实现梯度公式，而是依赖于 AutoGrad 自动完成。

以线性回归为例，模型的数学形式是 $\hat{y} = \mathbf{x}\mathbf{w}^T + b$ (如果 $\mathbf{x}$ 是行向量，$\mathbf{w}$ 是列向量，无偏置技巧；如果使用偏置技巧，$\mathbf{x}$ 扩充并在 $\mathbf{w}$ 中包含偏置项，形式为 $\hat{y} = \mathbf{x}\mathbf{w}$ 矩阵乘法）。

在 PyTorch 中，我们通常这样组织数据和参数：

*   输入特征 $\mathbf{X}$: 一个 $N \times d$ 的 Tensor，其中 $N$ 是样本数，$d$ 是特征维度。
*   真实目标 $\mathbf{y}$: 一个 $N \times 1$ 或 $N$ 的 Tensor。
*   权重 $\mathbf{w}$: 一个 $d \times 1$ 的 Tensor (如果无偏置技巧) 或 $(d+1) \times 1$ 的 Tensor (如果使用偏置技巧)。
*   偏置 $b$: 一个标量 Tensor (如果无偏置技巧)。

**使用 `nn.Linear` 层（无偏置技巧的常见实现）**

`torch.nn.Linear(in_features, out_features)` 实现的是一个线性变换 $y = xW^T + b$ （如果输入 $x$ 是行向量，输出 $y$ 是行向量）或 $y = xW + b$ （如果输入 $x$ 是列向量，输出 $y$ 是列向量）。其中 $W$ 是一个 `out_features` $\times$ `in_features` 的权重矩阵，$b$ 是一个 `out_features` 维的偏置向量。

对于一元线性回归 ($d=1$，输出维度 $1$)，`nn.Linear(1, 1)` 会创建一个 $1 \times 1$ 的权重矩阵（也就是一个标量 $w$）和一个 $1$ 维的偏置向量（也就是一个标量 $b$）。输入是 $N \times 1$ 的 Tensor，输出也是 $N \times 1$ 的 Tensor。计算过程是：输入 $x_{N \times 1} \times W_{1 \times 1} + b_{1 \times 1}$ (广播)。

**使用自定义 Module 实现（含偏置技巧）**

如果我们想用偏置技巧，将偏置 $b$ 融入权重 $\mathbf{w}$，模型形式为 $\hat{y} = \mathbf{X}\mathbf{w}$，其中 $\mathbf{X}$ 是 $N \times (d+1)$ 矩阵，$\mathbf{w}$ 是 $(d+1) \times 1$ 向量。

1.  **数据预处理:** 在将输入特征 $\mathbf{X}_{N \times d}$ 送入模型前，需要在其最后一列添加一列全 1 的向量，使其变为 $\mathbf{X}_{N \times (d+1)}$。在 PyTorch 中，可以使用 `torch.cat` 拼接一个 `torch.ones(N, 1)` Tensor 来实现。

    ```python
    # 假设 X 是 N x d 的输入 Tensor
    # 增加一列全1特征
    ones = torch.ones(X.shape[0], 1, dtype=X.dtype, device=X.device)
    X_with_bias = torch.cat([X, ones], dim=1) # 在第1维度（列）上拼接
    # 现在的 X_with_bias 是 N x (d+1) 的 Tensor
    ```

2.  **定义模型 Module:** 创建一个继承自 `nn.Module` 的类。

    ```python
    import torch
    import torch.nn as nn

    class LinearRegression(nn.Module):
        def __init__(self, in_features):
            super().__init__()
            # 参数 w 的形状是 (in_features + 1) x 1
            # 使用 nn.Parameter 来让 PyTorch 知道这是需要学习的参数
            # 初始化为满足标准正态分布的值
            self.weight = nn.Parameter(torch.randn(in_features + 1, 1))

        def forward(self, X):
            # X 是 N x in_features 的 Tensor
            # 增加一列全1特征
            ones = torch.ones(X.shape[0], 1, \
            dtype=X.dtype, device=X.device)
            X_with_bias = torch.cat([X, ones], dim=1) # N x (in_features + 1)

            # 计算线性预测： (N x (in_features + 1)) @ ((in_features + 1) x 1) -> N x 1
            # 使用 @ 运算符进行矩阵乘法
            y_pred = X_with_bias @ self.weight
            return y_pred # 返回预测值 Tensor
    ```

    这里的 `self.weight` 是一个 `nn.Parameter` 实例，默认 `requires_grad=True`。`forward` 方法定义了如何从输入 `X` 计算出预测值 `y_pred`。矩阵乘法 `@` 是一个 PyTorch Tensor 运算，AutoGrad 会记录它。

> [!warning] 
> the `super().__init__` here is dispensable, for there are other underlying significant tasks should be done by the `init` from `Module.__init__`.

3.  **定义损失函数:** 使用 PyTorch 提供的 `nn.MSELoss`。

    ```python
    loss_fn = nn.MSELoss()
    ```

4.  **定义优化器:** 使用 `torch.optim.SGD`。

    ```python
    # 实例化模型，比如输入特征维度是 d=1
    model = LinearRegression(in_features=1)
    # 创建优化器，将 model.parameters() 传进去
    optimizer = torch.optim.SGD(model.parameters(), lr=0.01) # 学习率设置为 0.01
    ```

    `model.parameters()` 会找到我们定义的 `self.weight` 这个 `nn.Parameter`。

5.  **训练循环:** 这是核心迭代过程。

    ```python
    num_epochs = 1000 # 训练轮数
    losses = [] # 记录每轮的损失

    for epoch in range(num_epochs):
        # 1. 前向传播：计算预测值
        y_pred = model(X_train) # X_train 是 N x d 的训练数据特征

        # 2. 计算损失
        loss = loss_fn(y_pred, y_train) # y_train 是 N x 1 的训练数据真实目标

        # 3. 清零梯度
        # 在计算新梯度之前，必须清零之前累积的梯度
        optimizer.zero_grad()
        # model.zero_grad() 也可以达到同样效果，因为它会清零 model 中所有参数的梯度

        # 4. 反向传播：计算梯度
        # loss 是一个标量 Tensor，调用 .backward() 会计算损失对所有 requires_grad=True Tensor 的梯度
        # 梯度会自动存储在 model.weight.grad 中
        loss.backward()

        # 5. 参数更新
        # 优化器根据 model.weight.grad 和学习率更新 model.weight 的值
        optimizer.step()

        # 记录和打印损失
        losses.append(loss.item()) # .item() 获取 Tensor 中的标量数值
        if (epoch + 1) % 100 == 0:
            print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}')

    print("训练完成！")
    ```

    这个训练循环是 PyTorch 中进行模型训练的标准模式：前向计算 -> 计算损失 -> 梯度清零 -> 反向传播计算梯度 -> 优化器更新参数。无论模型多复杂，这个基本框架不变。

**为什么 AutoGrad 能够工作？**

核心在于**链式法则**。 AutoGrad 在前向计算时记录了每一步操作。比如 $L = MSE(\hat{y}, y)$，$\hat{y} = \mathbf{X}_{ext} \mathbf{w}$。当我们调用 `loss.backward()` 时，AutoGrad 知道 Loss 是由 $\hat{y}$ 和 $y$ 计算出来的，$\hat{y}$ 是由 $\mathbf{X}_{ext}$ 和 $\mathbf{w}$ 计算出来的。

它首先计算 $\frac{\partial L}{\partial \hat{y}}$（这是 MSELoss 知道如何计算的）。然后，为了计算 $\frac{\partial L}{\partial \mathbf{w}}$，它使用链式法则：
$$ \frac{\partial L}{\partial \mathbf{w}} = \frac{\partial L}{\partial \hat{y}} \times \frac{\partial \hat{y}}{\partial \mathbf{w}} $$
这里的 $\frac{\partial \hat{y}}{\partial \mathbf{w}}$ 是线性变换 $\mathbf{X}_{ext} \mathbf{w}$ 对 $\mathbf{w}$ 的导数（实际上是雅可比矩阵）。PyTorch 的每个 Tensor 运算（如矩阵乘法 `@`）都知道如何计算输出对输入的偏导数（或雅可比矩阵）。AutoGrad 沿着计算图一步步应用链式法则，将各层偏导数乘起来，最终得到损失对参数的梯度。这个过程完全自动化，我们只需要定义前向计算中的 Tensor 运算。

#### 4.6 示例与应用：PyTorch 实现一元线性回归

我们将使用您提供的示例代码框架，填充核心部分，展示如何用 PyTorch 实现一元线性回归。

首先是定义模型类：

```python
import torch
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt

# 设置随机种子，保证结果可复现
torch.manual_seed(42)
np.random.seed(42)

# 1. 数据准备
# 生成一元线性回归的模拟数据
# y = 2*x + 1 + noise
N = 100 # 样本数
X_np = np.random.rand(N, 1) * 10 # 生成 0 到 10 之间的随机 x 值
noise = np.random.randn(N, 1) # 添加标准正态分布噪声
y_np = 2 * X_np + 1 + noise # 真实目标值

# 将 numpy 数据转换为 PyTorch Tensor
# X 和 y 是模型的输入输出，不需要直接计算梯度，所以 requires_grad=False (默认值)
X_train = torch.tensor(X_np, dtype=torch.float32)
y_train = torch.tensor(y_np, dtype=torch.float32)

# 如果有测试集，同样处理
# X_test = ...
# y_test = ...

# 2. 定义模型
# 使用自定义 Module 实现含偏置技巧的线性回归
class LinearRegression(nn.Module):
    def __init__(self, in_features):
        super().__init__()
        # 参数 w 的形状是 (in_features + 1) x 1
        # 使用 nn.Parameter 来让 PyTorch 知道这是需要学习的参数
        # 初始化为满足标准正态分布的值
        self.weight = nn.Parameter(torch.randn(in_features + 1, 1))
        # self.bias = nn.Parameter(torch.randn(1)) # 如果不用偏置技巧，则定义 w 和 b

    def forward(self, X):
        # X 是 N x in_features 的 Tensor
        # 增加一列全1特征用于偏置
        ones = torch.ones(X.shape[0], 1, dtype=X.dtype, device=X.device)
        X_with_bias = torch.cat([X, ones], dim=1) # N x (in_features + 1)

        # 计算线性预测： (N x (in_features + 1)) @ ((in_features + 1) x 1) -> N x 1
        y_pred = X_with_bias @ self.weight
        # 如果不用偏置技巧： y_pred = X @ self.weight + self.bias
        return y_pred # 返回预测值 Tensor

# 3. 定义损失函数和优化器
input_dim = 1 # 输入特征维度
model = LinearRegression(in_features=input_dim) # 实例化模型
loss_fn = nn.MSELoss() # 均方误差损失
optimizer = torch.optim.SGD(model.parameters(), lr=0.01) # SGD优化器，优化model的所有参数

# 4. 训练模型
num_epochs = 1000 # 训练轮数
losses = [] # 记录每轮的损失

print("开始训练...")
for epoch in range(num_epochs):
    # 前向传播：计算预测值
    y_pred = model(X_train)

    # 计算损失
    loss = loss_fn(y_pred, y_train)

    # 清零梯度
    optimizer.zero_grad() # 清零模型参数的梯度

    # 反向传播：计算梯度
    loss.backward() # 计算损失对模型参数的梯度，存储在参数的 .grad 属性中

    # 参数更新
    optimizer.step() # 根据梯度和学习率更新参数值

    # 记录和打印损失
    losses.append(loss.item())
    if (epoch + 1) % 100 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}')

print("训练完成！")

# 打印学习到的参数
# model.weight 是一个 (input_dim + 1) x 1 的 Parameter
# 第一个元素对应原特征的权重 w，第二个元素对应偏置 b
learned_w_b = model.weight.data.numpy().flatten() # .data 或 .detach() 获取 Tensor 数值，转换为 numpy
print(f"学习到的参数 [w, b]: {learned_w_b}")
# 真实参数是 w=2, b=1

# 5. 模型测试/预测
# 用训练好的模型进行预测
with torch.no_grad(): # 在评估或预测阶段，不需要计算梯度，禁用 AutoGrad 可节省内存和计算
    y_pred_train = model(X_train).numpy() # 预测训练集结果并转回 numpy

# 可视化结果
plt.figure(figsize=(10, 6))
plt.scatter(X_np, y_np, label='真实数据', alpha=0.6) # 绘制原始数据散点图
plt.plot(X_np, y_pred_train, color='red', label=f'预测直线: y = {learned_w_b[0]:.2f}*x + {learned_w_b[1]:.2f}') # 绘制预测直线
plt.xlabel('X')
plt.ylabel('y')
plt.title('一元线性回归结果')
plt.legend()
plt.grid(True)
plt.show()

# 绘制损失随训练轮数的变化
plt.figure(figsize=(10, 6))
plt.plot(range(num_epochs), losses)
plt.xlabel('Epoch')
plt.ylabel('MSE Loss')
plt.title('训练损失随轮数变化')
plt.grid(True)
plt.show()

```

**代码讲解:**

1.  **数据准备:** 使用 NumPy 生成带噪声的线性数据，然后转换为 PyTorch Tensor。注意数据类型使用 `torch.float32`，这是神经网络中常用的浮点类型。
2.  **定义模型:** 我们定义了一个 `LinearRegression` 类，继承自 `nn.Module`。在 `__init__` 中，我们创建了一个 `nn.Parameter` 来表示扩充后的权重向量（包含偏置）。在 `forward` 方法中，我们实现了偏置技巧（拼接全 1 列）和矩阵乘法 `@` 来计算预测值。
3.  **定义损失函数和优化器:** 实例化 `nn.MSELoss` 和 `torch.optim.SGD`。将 `model.parameters()` 传递给优化器是关键，它告诉优化器需要更新哪些 Tensor。
4.  **训练模型:** 外层循环控制训练的轮数（epochs）。内层循环是标准的 PyTorch 训练步骤：
    *   `model(X_train)`: 调用模型的 `__call__` 方法，进而执行 `forward` 方法，得到预测值 `y_pred`。这个过程构建了计算图。
    *   `loss_fn(y_pred, y_train)`: 计算预测值和真实值之间的 MSE 损失。
    *   `optimizer.zero_grad()`: 清除上一步（如果存在）计算的梯度。
    *   `loss.backward()`: 执行反向传播，自动计算损失对 `model.weight` 的梯度，并将结果存到 `model.weight.grad`。
    *   `optimizer.step()`: 根据 `model.weight.grad` 更新 `model.weight` 的值。
    *   `.item()`: 从一个只包含一个元素的 Tensor 中取出其标量值，用于打印或记录。
5.  **模型测试/预测:** 训练完成后，我们可以使用训练好的模型进行预测。在预测阶段，我们通常不关心梯度，可以使用 `with torch.no_grad():` 上下文管理器来暂时禁用 AutoGrad，节省计算资源。
6.  **可视化:** 使用 Matplotlib 绘制原始数据点、学习到的回归直线以及训练过程中损失函数随轮数的变化，直观展示训练效果。

通过这个例子，我们看到，一旦模型的前向计算在 `forward` 方法中定义好，并且可训练参数被注册为 `nn.Parameter`，AutoGrad 和 Optimizer 就会接管梯度计算和参数更新的繁重工作。这正是 PyTorch 使得模型训练变得高效便捷的原因。

#### 4.7 知识点总结与要点提炼

*   **`torch.nn` 工具箱:** PyTorch 提供的高级 API，用于构建和训练神经网络。
*   **`nn.Module`:** 所有神经网络层和模型的基类，负责管理参数、定义前向传播 (`forward` 方法) 并与 AutoGrad 集成。
*   **`nn.Parameter`:** `Tensor` 的特殊子类，用于表示模型的训练参数，默认 `requires_grad=True` 并由 `nn.Module` 自动管理。
*   **`torch.optim` 工具箱:** 提供各种优化算法（如 SGD, Adam），用于根据梯度更新模型参数。
*   **标准训练流程:** `Optimizer.zero_grad()` -> `Loss.backward()` -> `Optimizer.step()`。这是 PyTorch 训练循环的核心骨架。
*   PyTorch 通过 `nn.Module` 和 `AutoGrad` 自动化了模型参数的梯度计算和更新过程，极大地简化了复杂模型的训练。
*   模型训练和测试阶段通常需要切换模式（`model.train()`, `model.eval()`)，并在测试/预测时禁用 AutoGrad (`with torch.no_grad():`)。

#### 4.8 学科思想与延伸思考

*   **模块化设计:** `nn.Module` 鼓励我们将复杂的模型分解为更小的、可管理的模块（层、子网络）。这种模块化思想是软件工程中的核心原则，也适用于构建大型神经网络。我们可以轻松地重用、组合和修改这些模块。
*   **计算图的强大:** AutoGrad 隐藏了底层复杂的数学推导，通过动态构建和遍历计算图来完成梯度计算。理解计算图的概念（虽然 PyTorch 是动态构建，不像 TensorFlow 早期是静态构建）对于理解 AutoGrad 的工作原理（特别是为什么 `.backward()` 需要一个标量以及梯度累积问题）至关重要。
*   **从函数到可训练 Module:** NumPy 里的函数操作是纯粹的数学计算。PyTorch 的 `nn.Module` 将数学计算（`forward` 方法）与可学习状态（`Parameter`）结合起来，形成了一个“智能”模块，它可以根据数据调整自身行为。
*   **向量化与 GPU 加速:** PyTorch 底层依然依赖于高效的 Tensor 运算，这些运算被高度优化，并能利用 GPU 的并行计算能力。这也是深度学习能够处理大规模数据和模型的基础。我们写的矩阵乘法 `@` 符号背后，是调用了高度优化的库（如 cuBLAS 在 NVIDIA GPU 上）来执行计算。

**思考题：**

1.  在我们自己实现的 `LinearRegression` Module 中，如果输入 `X` 的形状是 $N \times 1$（一元特征），`self.weight` 的形状是 $2 \times 1$（包含偏置）。那么 `X_with_bias` 是 $N \times 2$。`y_pred = X_with_bias @ self.weight` 的矩阵乘法维度是 $(N \times 2) @ (2 \times 1)$，结果是 $N \times 1$，这与真实目标 $y$ 的形状 $N \times 1$ 匹配，可以直接计算损失。如果输入 `X` 是 $N$ 维向量（而不是 $N \times 1$），会发生什么？PyTorch 的 Tensor 运算会如何处理？（提示：unsqueeze/reshape 来管理维度）
2.  为什么在训练循环中，我们必须在 `optimizer.step()` 之前调用 `loss.backward()`，又必须在 `loss.backward()` 之前调用 `optimizer.zero_grad()`？它们各自的作用是什么？
3.  除了 SGD，PyTorch 还提供了哪些优化器？它们有什么区别？（可以查阅 PyTorch 文档）
4.  我们用 `nn.MSELoss` 实现了损失函数。请回忆一下逻辑回归的损失函数是交叉熵。PyTorch 提供了对应的交叉熵损失函数吗？如何使用它？

---

### 五、 作业：用 PyTorch 实现逻辑回归

现在是检验学习成果的时候了！我们将把本周学习的 PyTorch 基础应用到我们之前用 NumPy 实现过的另一个模型：逻辑回归。

**任务:**

使用 PyTorch，实现一个 `LogisticRegression` 类来定义模型，并实现一个 `Logistic_Model` 类来管理训练和测试流程。

*   **模型定义 (`LogisticRegression` 类):**
    *   继承自 `nn.Module`。
    *   在 `__init__` 中，定义模型参数 `w` (使用 `nn.Parameter`)。同样使用偏置技巧，所以参数维度是 `in_features + 1`。
    *   在 `forward` 方法中，实现从输入 `X` (形状 $N \times d$) 计算到最终输出概率 (形状 $N \times 1$) 的逻辑：
        1.  在 `X` 后拼接一列全 1，得到 `X_with_bias` (形状 $N \times (d+1)$)。
        2.  计算线性得分 $z = X_{with\_bias} \cdot w$ (形状 $(N \times (d+1)) @ ((d+1) \times 1) \rightarrow N \times 1$)。
        3.  将 $z$ 通过 Sigmoid 函数 (`torch.sigmoid`) 转换为概率 $p$ (形状 $N \times 1$)。
        4.  返回概率 $p$。

*   **训练和测试管理 (`Logistic_Model` 类):**
    *   在 `__init__` 中，实例化你的 `LogisticRegression` 模型，定义损失函数（请查找 PyTorch 中适合二分类的交叉熵损失函数，提示：`nn.BCELoss` 或 `nn.BCEWithLogitsLoss`），定义优化器（如 `torch.optim.SGD`）。
    *   实现 `train(self, X_train, y_train, num_epochs, lr)` 方法：
        *   设置模型为训练模式 (`model.train()`)。
        *   外层循环迭代 `num_epochs`。
        *   内层实现标准的 PyTorch 训练步骤：前向计算 (`model(X_train)`) -> 计算损失 (`loss_fn(...)`) -> 梯度清零 (`optimizer.zero_grad()`) -> 反向传播 (`loss.backward()`) -> 参数更新 (`optimizer.step()`)。
        *   记录并返回训练过程中每轮的损失列表。
    *   实现 `predict(self, X_test)` 方法：
        *   设置模型为评估模式 (`model.eval()`)。
        *   使用 `with torch.no_grad():` 禁用 AutoGrad。
        *   进行前向计算 (`model(X_test)`) 得到预测概率 `y_pred` (形状 $N \times 1$)。
        *   根据概率阈值（如 0.5）将概率转换为预测类别标签 `y_pred_label` (形状 $N \times 1$，值为 0 或 1)。
        *   返回 `y_pred` 和 `y_pred_label`。

**提示:**

*   损失函数：`nn.BCELoss()` 用于计算二元交叉熵损失，但它要求输入的预测值是**概率** (0到1之间)。如果你的模型输出的是未经过 Sigmoid 的线性得分 $z$，可以使用 `nn.BCEWithLogitsLoss()`，它在内部会先对输入应用 Sigmoid，数值上更稳定。请根据你 `forward` 方法的返回值选择合适的损失函数。
*   你的真实标签 $y$ 需要是浮点类型 (`torch.float32`)，并且形状与预测值匹配 (都是 $N \times 1$)。
*   测试集的 `y_pred_label` 可以通过对 `y_pred` 应用条件判断实现，例如 `(y_pred >= 0.5).float()` 会得到 0 或 1 的 Tensor。

祝同学们实践愉快！通过这次作业，你们将更深入地理解 PyTorch 的工作方式，并为后续学习更复杂的深度学习模型打下坚实的基础。

**提交要求:**

*   填写并运行提供的 Jupyter Notebook 或 Python 脚本模板。
*   确保代码能够成功训练逻辑回归模型并进行预测。
*   提交完成后的文件。

**提交期限:** 2 周。
**提交平台:** 未来课堂。

---

同学们，今天我们迈出了使用 PyTorch 构建模型的第一步，这扇门背后是一个广阔而激动人心的深度学习世界。Tensor、AutoGrad 和 nn.Module 是 PyTorch 的灵魂，理解它们的工作方式，你们就已经掌握了进入这个世界的核心工具。下节课，我们将继续探索 PyTorch 提供的更多功能，并开始构建更复杂的模型。

谢谢大家！下周见！