#review 

>Function: Similar to numpy
>Feature: Autograd. define a function, whose vars are `tensor` type, and are assigned specific real values, and the highlight below

- **使用 PyTorch：**
```python
import torch as t    
x = t.tensor(1.0, requires_grad=True)
y = t.tensor(1.0, requires_grad=True)    
# f = x**2 + 2*(y**2) + x*y
# 或者使用 PyTorch 的函数，这在内部构建了 grad_fn
f = x.pow(2) # pow is method of t.tensor
	+ t.tensor(2.0) #coe's should be tensors
 	    .mul(y.pow(2))  # mul is no longer binary operation.
			           # it need a starter now!
	    + x.mul(y)
    # f = x.pow(2) + 2 * y.pow(2) + x * y # 这样写也可以
    
f.backward() # 自动计算梯度
print(x.grad) # 输出: tensor(3.)
print(y.grad) # 输出: tensor(5.)
```

好的，我们今天来聊一聊 PyTorch。这份讲义涵盖了 PyTorch 的一些基本概念，特别是 `Tensor`（张量）和 `Autograd`（自动求导）。对于初学者来说，PyTorch 是一个非常友好且功能强大的人工智能/深度学习框架。我会尽量用直观的方式来讲解，帮助你理解这些概念，而不是死记硬背。

### 引入与动机 (Hook & Motivation)

想象一下，你想让电脑帮你识别图片中的猫和狗。这在今天听起来可能不算什么新鲜事，但背后其实蕴含着复杂的数学模型和计算过程。或者，你想预测明天的股票价格（当然，这非常非常难，但只是举个例子）。这些任务都需要计算机能够从数据中“学习”到某种模式或规律。

**PyTorch 是什么？** 简单来说，PyTorch 就是一个能帮助我们更轻松地构建和训练这些“学习”模型的工具箱。它就像一个功能强大的计算器，特别擅长处理一种叫做“张量”的数据结构（我们稍后会详细讲），并且能够<font color="#ffff00">自动帮我们完成机器学习中一个非常关键且繁琐的步骤——求导数（也叫梯度计算）</font>。

**为什么我们需要 PyTorch？**

1. **简化复杂计算：** 很多机器学习算法，尤其是深度学习，涉及到大量的矩阵运算和复杂的函数求导。手动计算这些几乎是不可能的。PyTorch 提供了现成的工具，让我们能用简洁的代码完成这些复杂操作。
2. **利用硬件加速：** 现代计算机的图形处理单元（GPU）非常擅长并行计算，这正是深度学习所需要的。PyTorch 可以方便地将计算任务分配给 GPU，从而大大加快训练速度。 [52]
3. **灵活性与易用性：** 相比于一些其他框架，PyTorch 被认为更加“Pythonic”，也就是说它的使用方式更贴近 Python 程序员的习惯。它允许我们用更灵活的方式构建模型，更容易调试和理解模型内部的运作机制，这对于学习和研究来说非常重要。 [12]

所以，学习 PyTorch，就像是获得了一把进入人工智能和深度学习世界的钥匙。它能让我们把精力更多地放在模型的设计和算法的理解上，而不是被繁杂的底层实现细节所困扰。 [11]

### 必要知识回顾 (Prerequisite Review)

在深入 PyTorch 之前，我们快速回顾几个基本概念，这些概念你可能在高等数学、线性代数或之前的编程课程中接触过：

1. **Python 基础：** PyTorch 是一个基于 Python 的库，所以你需要对 Python 的基本语法有所了解，比如变量、函数、类、列表等。
2. **Numpy：** Numpy 是 Python 中用于科学计算的核心库，它引入了 `ndarray`（N维数组）的概念。PyTorch 的 `Tensor` 和 Numpy 的 `ndarray` 非常相似，很多操作也很类似。如果你用过 Numpy，学习 PyTorch 的 `Tensor` 会感觉很亲切。 [24]
3. **导数/梯度（高等数学）：**
    - **导数：** 函数在某一点的导数描述了函数在该点附近的变化率，几何上表示函数曲线在该点的切线斜率。 [64]
    - **梯度：** 对于多元函数（有多个输入变量的函数），<font color="#ffff00">梯度是一个向量</font>，指向函数值增长最快的方向。在机器学习中，我们通常希望最小化一个“损失函数”（表示模型预测的好坏），梯度下降法就是沿着梯度的反方向调整模型参数，以期找到损失函数的最小值。
4. **线性代数基础：**
    - **标量 (Scalar)：** 一个单独的数，比如 18。 [20, 21]
    - **向量 (Vector)：** 一组有序的数，可以看作是一维数组，比如 `[3, 5, 7, 9, 2, 4]`。 [20, 21]
    - **矩阵 (Matrix)：** 二维的数字阵列，比如一个 3x2 的表格。 [20, 21]
    - **矩阵运算：** 比如矩阵加法、数乘、矩阵乘法（点积）等，这些是深度学习中非常核心的运算。 [38, 39]

这些概念我们会在讲解过程中适时地进一步解释。现在，你只需要对它们有一个大概的印象就可以了。

### 直观解释与感性认识 (Intuitive Explanation)

#### Tensor（张量）：数据的容器

我们先来聊聊 PyTorch 中最基本的数据结构——`Tensor`。

- **什么是 Tensor？** 你可以把 `Tensor` 想象成一个多维的“数字盒子”或者“数字网格”。 [20, 24]
    - 如果这个盒子只有一个格子，里面放一个数字，那它就是一个 **标量 (Scalar)**，也叫 0 阶张量。比如，一张图片中猫的数量。
    - 如果这个盒子是一排格子，里面放一串数字，那它就是一个 **向量 (Vector)**，也叫 1 阶张量。比如，一个学生的各科成绩 `[语文90, 数学85, 英语92]`。
    - 如果这个盒子是一个二维的表格，像棋盘一样有很多行和列，那它就是一个 **矩阵 (Matrix)**，也叫 2 阶张量。比如，一张灰度图片，每个像素点的亮度值就可以存放在一个矩阵里。
    - 如果这个盒子有更多的维度呢？比如，一张彩色图片，它不仅有宽度和高度（两个维度），还有颜色通道（比如红、绿、蓝三个通道）。这样一个数据结构就需要一个 3 阶张量来表示。更复杂的数据，比如一段视频（可以看作是一系列图片），或者一个大型语言模型的参数，可能需要更高阶的张量。

所以，**`Tensor` 是对标量、向量、矩阵这些概念的一个推广，它可以是任意维度的。** [21, 22, 23] 在 PyTorch 中，几乎所有的数据，无论是输入数据、模型参数，还是计算结果，都是以 `Tensor` 的形式存在的。 [62]

- **Tensor 和 Numpy 的 `ndarray` 有什么关系？** 它们非常相似！ [24] 如果你熟悉 Numpy，你会发现 PyTorch `Tensor` 的很多操作（比如创建、索引、切片、数学运算）都和 Numpy `ndarray` 如出一辙。你可以把 PyTorch `Tensor` 看作是 Numpy `ndarray` 的“增强版”，<font color="#ffff00">一个关键的增强就是它可以被无缝地转移到 GPU 上进行计算，从而大大加速运算</font>。 [20, 52] 并且，PyTorch 的 `Tensor` 还可以<font color="#ffff00">记录自身的计算历史，这是实现自动求导的关键（我们稍后会讲到）</font>。

#### Autograd（自动求导）：让机器帮你算梯度

现在我们来看另一个核心概念：`Autograd`。

- 为什么需要求导？
    
    在机器学习中，我们通常会定义一个 损失函数 (Loss Function)。这个函数用来衡量我们模型的预测结果与真实答案之间的差距。我们的目标是调整模型的参数（比如神经网络中的权重和偏置），使得这个损失函数的值尽可能小。
    
    想象一下你在一个漆黑的山谷里，想走到谷底（损失函数的最小值点）。你怎么走呢？你可能会伸出脚，试探一下哪个方向是下坡路最陡的，然后朝那个方向迈一步。这个“下坡路最陡的方向”就是由**梯度**（导数在多维情况下的推广）的相反方向给出的。 [63]
    
    所以，为了优化模型，我们需要计算损失函数对于模型参数的梯度。
    
- 什么是 Autograd？
    
    Autograd 就是 PyTorch 提供的自动计算梯度的机制。 [20, 66] 你只需要用 PyTorch 的 Tensor 来构建你的计算过程（比如定义你的模型和损失函数），然后告诉 PyTorch 你想对哪些 Tensor（通常是模型的参数）求梯度。当你调用一个特殊的函数（比如 `loss.backward()`），PyTorch 就会自动地、神奇地帮你计算出损失函数对于这些参数的梯度值。 [67]
    
    这就像你只需要告诉汽车你的目的地，导航系统会自动规划出路线，而不需要你手动去查地图、记路标。`Autograd` 极大地解放了我们，让我们不用去手动推导和编写复杂的求导公式，从而可以更专注于模型结构本身。 [84]
    
    **直观感觉：** `Autograd` 像是在你进行每一步计算的时候，都在悄悄地记录“账本”。比如，你计算 $y=x^{2}$，它不仅算出 $y$ 的值，还记住了 $y$ 是怎么由 $x$ 得到的。当你要算梯度的时候，它就根据这个“账本”反向追溯，利用链式法则（微积分中的一个重要规则）一步步把梯度算出来。
    

### 逐步形式化与精确定义 (Gradual Formalization)

现在我们来更精确地看一下这两个概念。

#### Tensor

- **定义：** 在 PyTorch 中，`torch.Tensor` 是一个包含单一数据类型元素的多维矩阵。它可以有不同的数据类型（如 `torch.float32`, `torch.int64` 等）和不同的形状（shape，即各个维度的大小）。
    
- 创建 Tensor：
    
    PyTorch 提供了多种创建 Tensor 的方法，与 Numpy 非常类似：
    
    - 从 Python 列表或序列创建：`torch.tensor([[1., -1.], [1., -1.]])`
    - 创建特定形状和值的 Tensor：
        - `torch.zeros(rows, cols)`: 创建全零 Tensor。 [25]
        - `torch.ones(rows, cols)`: 创建全一 Tensor。 [25]
        - `torch.empty(rows, cols)`: 创建一个未初始化的 Tensor，其值是分配内存时的随机值。 [25]
        - `torch.rand(rows, cols)`: 创建元素在 `[0, 1)` 之间均匀分布的 Tensor。 [25]
        - `torch.randn(rows, cols)`: 创建元素从标准正态分布（均值为0，方差为1）中随机抽取的 Tensor。 [25]
    - 可以通过 `size()` 或 `.shape` 属性查看 Tensor 的形状：
        

```python
x = torch.rand(2, 3, 4) # 创建一个形状为 (2, 3, 4) 的 Tensorprint(x.size()) # 输出: torch.Size([2, 3, 4])
print(x.shape)  # 输出: torch.Size([2, 3, 4])
```

[26]
- **Tensor 的属性：**
    
    - `dtype`: Tensor 中元素的数据类型。
    - `shape` (或 `size()`): Tensor 的维度。
    - `device`: Tensor 存储的设备（CPU 或 GPU）。例如 `cpu` 或 `cuda:0`。 [59]
- Tensor 操作：
    
    PyTorch 提供了丰富的 Tensor 操作，包括：
    
    - **算术运算：** 加法 (`+` 或 `torch.add()`) [27, 28, 29, 30]、减法 (`-`) [37]、乘法（元素级 `*` 或 `torch.mul()` [38]；矩阵乘法 `torch.mm()` [38, 39]）、除法 (`torch.div()`) [45]。
        - **注意 `add_()` 和 `add()` 的区别：** 带有下划线后缀的操作（如 `x.add_(y)`）是 **in-place** 操作，即它们会直接修改 `x` 的值。而不带下划线的操作（如 `z = x.add(y)` 或 `z = x + y`）会返回一个新的 Tensor `z`，而 `x` 和 `y` 保持不变。 [30] 这个特性在很多 PyTorch 操作中都存在。
    - **线性代数运算：** 转置 (`.t()`) [38]、矩阵乘法 (`.mm()`) [39, 40, 41]。
        - 对于矩阵乘法 `A.mm(B)`，如果 A 是一个 m×n 的矩阵， B 是一个 n×k 的矩阵，那么结果是一个 m×k 的矩阵。中间的维度 n 必须匹配。 [39]
    - **索引和切片：** 与 Numpy `ndarray` 类似，可以使用方括号 `[]` 进行索引和切片。 [47]
        
        
        
        ```Python
        x = torch.randn(2, 3)
        first_row = x[0, :]    # 获取第一行
        first_col = x[:, 0]    # 获取第一列
        element = x[0, 0]      # 获取单个元素
        ```
        
    - **形状变换：**
        - `view()`: 改变 Tensor 的形状，但数据总数不变。新的 Tensor 与原始 Tensor 共享底层数据。这类似于 Numpy 的 `reshape()`。 [46]
            

```python
a = torch.tensor([[[1,2,3], [4,5,6]]]) # shape (1, 2, 3)
b = a.view(1, 6) # b 的 shape 是 (1, 6)，共享 a 的数据
# b 会是 tensor([[1., 2., 3., 4., 5., 6.]])
```
.
        - `reshape()`: 也可以改变形状，如果可能，它会返回一个*视图*（共享数据），否则会复制数据。
        - `squeeze()`: 移除所有大小为 1 的维度。 [47]
        - `unsqueeze(dim)`: 在指定维度 `dim` 插入一个大小为 1 的新维度。
    - **与其他库的转换：**
        - **Tensor to Numpy array:** 使用 `.numpy()` 方法。 [48, 49]
            
            
            
```Python
a = torch.ones(2, 3)
b = a.numpy() # b 是一个 Numpy array
```

.
        - **Numpy array to Tensor:** 使用 `torch.from_numpy()` 函数。 [48, 50]
            
```
import numpy as np
a = np.ones(5)
b = torch.from_numpy(a) # b 是一个 PyTorch Tensor
```
.
            **重要提示：** 通过这两种方式转换得到的 Tensor 和 Numpy array **共享底层内存**。这意味着如果你修改了其中一个，另一个也会跟着改变！ [48, 51] 如果不希望共享内存，可以在转换后使用 `.copy()` (Numpy) 或 `.clone().detach()` (PyTorch Tensor)。
    - **GPU 加速：**
        - `torch.cuda.is_available()`: 检查当前环境是否有可用的 CUDA 支持的 GPU。 [53, 54]
        - `.cuda()`: 将 Tensor 移动到 GPU 内存。
            
            
            
```Python
if torch.cuda.is_available():
    x_cpu = torch.randn(3, 3)
    x_gpu = x_cpu.cuda() # 将 x_cpu 的数据复制到 GPU
	# 或者 x_gpu = torch.randn(3, 3, device='cuda') 直接在GPU上创建
    print(x_gpu.device) # 输出类似 cuda:0
```

[54, 61]
        - `.cpu()`: 将 Tensor 移回 CPU 内存。
        - 在进行运算时，参与运算的 Tensor 必须在同一个设备上（要么都在 CPU，要么都在同一个 GPU）。

#### Autograd（自动求导）

- **核心概念：`requires_grad` 和 `grad_fn`**
    
    - `torch.Tensor` 有一个属性 `requires_grad`，默认为 `False`。如果你希望 PyTorch <font color="#ffff00">跟踪对这个 Tensor 的所有操作以便后续计算梯度</font>，你需要将其设置为 `True`。 [67] 通常，模型的**可学习参数**（如神经网络的权重）会被设置为 `requires_grad=True`。
        
        
        ```python
        x = torch.tensor(3.0, requires_grad=True) # 我们希望计算关于 x 的梯度
        w = torch.tensor(2.0, requires_grad=True) # 另一个可学习参数
        b = torch.tensor(1.0, requires_grad=True) #
        ```
        
    - 当一个 Tensor 是由其他 `requires_grad=True` 的 Tensor 计算得到时，它会自动拥有一个 `grad_fn` 属性。`grad_fn` 指向一个函数，该函数记录了创建该 Tensor 的操作（比如 `AddBackward0` 表示加法操作，`MulBackward0` 表示乘法操作）。 [82] 这构成了反向传播计算图的基础。
        
        
        ```python
        y = x * w + b  # y 是通过 x, w, b 计算得到的
        print(y.requires_grad) # 会是 True
        print(y.grad_fn)       # 会显示类似 <AddBackward0 object at ...>
        ```
        
        如果所有输入的 `requires_grad` 都是 `False`，那么输出的 `requires_grad` 也会是 `False`，并且 `grad_fn` 为 `None`。
- `backward()` 方法：
    
    当你有一个标量（通常是损失函数 loss）并且它的 requires_grad=True 时，你可以调用它的 `.backward()` 方法。 [67] 这个方法会触发自动求导过程，PyTorch 会根据 grad_fn 链反向传播，计算出该标量相对于所有 `requires_grad=True` 的叶子节点 Tensor（即那些不是由其他 `requires_grad=True` 的 Tensor 计算得到的 Tensor，通常是模型的参数或最初的输入）的梯度。
    
- grad 属性：
    
    调用 .backward() 之后，梯度会累积到各个叶子 Tensor 的 .grad 属性中。 [67]
    
    ```python
    x = torch.tensor(3.0, requires_grad=True)
    y = x * x  # y = x^2
    y.backward() # 计算 dy/dx
    print(x.grad) # 输出 tensor(6.)，因为 dy/dx = 2x，当 x=3 时，梯度是 6
    ```
    
    **注意：**
    
    1. `.backward()` 默认只能对**标量**输出调用。如果你的输出是向量或矩阵，你需要提供一个与输出形状相同的 `gradient` 参数给 `.backward()`，这通常用于计算向量-雅可比积。但在大多数机器学习应用中，损失函数都是标量。
    2. **梯度是累加的！** 如果你多次调用 `.backward()` 而不清除之前的梯度，新的梯度会累加到 `.grad` 属性上。在训练神经网络时，通常在每次参数更新前，需要手动将参数的梯度清零，使用 `optimizer.zero_grad()` 或手动遍历参数并调用 `param.grad.zero_()`。
- 计算图 (Computational Graph)：
    
    Autograd 的工作原理是隐式地构建一个动态计算图。
    
    - **前向传播 (Forward Pass)：** 当你执行 Tensor 操作时，PyTorch 会记录下这些操作以及它们之间的依赖关系，形成一个有向无环图 (DAG)。图中的节点是 Tensor，边代表了产生输出 Tensor 的函数（`grad_fn`）。
    - **反向传播 (Backward Pass)：** 当你对某个标量输出（如 `loss`）调用 `.backward()` 时，PyTorch 从这个输出节点开始，沿着图反向追溯，利用链式法则计算梯度，并将梯度累积到叶子节点的 `.grad` 属性中。
    
    **动态图的优势：** PyTorch 的计算图是动态构建的。这意味着图的结构可以在每次前向传播时发生改变。这使得处理变长输入（如文本）、使用控制流（如 `if` 语句和循环）以及构建更复杂的模型变得非常自然和灵活。这与一些早期框架（如 TensorFlow 1.x 的静态图）有所不同。
    

### 核心原理与推导过程 (Core Principles & Derivation Walkthrough)

#### Autograd 的核心：链式法则

`Autograd` 之所以能够自动计算梯度，其数学基础是微积分中的**链式法则 (Chain Rule)**。

- 回顾链式法则：
    
    假设你有一个复合函数。例如，z 是 y 的函数 (z=f(y))，而 y 又是 x 的函数 (y=g(x))。那么 z 也是 x 的函数 (z=f(g(x)))。链式法则告诉我们如何计算 z 相对于 x 的导数：$$\frac{dx}{dz}​=\frac{dy}{dz}​⋅\frac{dx}{dy}$$​
    简单来说，就是“外层导数乘以内层导数”。
    
    对于更复杂的嵌套，比如 $y=f(u), u=g(v), v=h(x)$，那么：
    
    $dxdy​=dudy​⋅dvdu​⋅dxdv​$
    
- Autograd 如何应用链式法则：
    
    考虑一个简单的计算：
    
    1. $a = \text{inputTensor}$ (设置 `a.requires_grad=True`)
    2. $b=w_1​⋅a$
    3. $c=w_2​⋅a$
    4. $d=w_3​⋅b+w_4​⋅c$
    5. $L = \text{lossFunction}(d)$ (这里的 $w_1​,w_2​,w_3​,w_4​$ 也是 `requires_grad=True` 的参数)
    
    当我们调用 `L.backward()` 时，PyTorch 会从 L 开始反向计算：
    
    - 它知道如何计算 ∂L∂d​ (这是损失函数本身的导数)。
    - 然后，它需要计算 $∂L/​∂w_3​,∂L​/∂w_4​,∂L/∂b​,∂L/∂c$​。
        - 例如，对于 w3​：∂w3​∂L​=∂d∂L​⋅∂w3​∂d​。PyTorch 知道 d=w3​⋅b+w4​⋅c，所以 ∂w3​∂d​=b。==ALL the $\partial$ involved function have inversed order!==
        - 对于 b：∂b∂L​=∂d∂L​⋅∂b∂d​。PyTorch 知道 ∂b∂d​=w3​。
    - 接着，它会继续反向传播到 b 和 c 的输入：
        - 对于 w1​ (通过 b): ∂w1​∂L​=(∂d∂L​⋅∂b∂d​)⋅∂w1​∂b​=∂b∂L​⋅∂w1​∂b​。PyTorch 知道 b=w1​⋅a，所以 ∂w1​∂b​=a。
        - 对于 a (可能会从 b 和 c 两条路径接收梯度，这些梯度会相加)： ∂a∂L​=∂b∂L​⋅∂a∂b​+∂c∂L​⋅∂a∂c​。
    
    `grad_fn` 在这里扮演了关键角色。每个 `grad_fn` 都知道如何计算其输出相对于其输入的局部梯度（例如，对于乘法节点 y=u⋅v，它知道 ∂u∂y​=v 和 ∂v∂y​=u）。当 `.backward()` 被调用时，梯度值（最初是 ∂L∂L​=1）从最终的损失节点开始，通过这些 `grad_fn` 函数在计算图中反向流动，每个 `grad_fn` 接收来自其后续节点的梯度，乘以局部梯度，然后将结果传递给其前面的节点。
    
    **为什么是“自动”的？** 因为 PyTorch 帮你构建了这个计算图，并实现了所有基本操作（加、乘、激活函数等）的局部梯度计算方法。你只需要用这些基本操作组合成你的模型，它就能自动应用链式法则。
    

#### 一个手动推导的例子（对照 PyTorch）

假设我们有函数 $f(x,y)=x^2+2y^2+xy$。我们想计算在点 $(x=1,y=1)$ 处的偏导数。 [76]

- **手动推导：**
  $$\begin{array}
     ∂x∂f​=2x+y  \\
     ∂y∂f​=4y+x 在 (x=1,y=1) 处：\\
     ∂x∂f​=2(1)+1=3\\
     ∂y∂f​=4(1)+1=5\\
     \end{array}
 $$
- **使用 PyTorch：**
    ```python
    import torch as t
    
    x = t.tensor(1.0, requires_grad=True)
    y = t.tensor(1.0, requires_grad=True)
    
    # f = x**2 + 2*(y**2) + x*y
    # 或者使用 PyTorch 的函数，这在内部构建了 grad_fn
    f = x.pow(2) # pow is method of t.tensor
	    + t.tensor(2.0) #coe's should be tensors
 	    .mul(y.pow(2))  # mul is no longer binary operation.
			           # it need a starter now!
	    + x.mul(y)
    # f = x.pow(2) + 2 * y.pow(2) + x * y # 这样写也可以
    
    f.backward() # 自动计算梯度
    
    print(x.grad) # 输出: tensor(3.)
    print(y.grad) # 输出: tensor(5.)
    ```
你可以看到，PyTorch 自动计算的结果与我们手动推导的结果完全一致。我们不需要去想求导的规则，只需要正确地用 `Tensor` 和 PyTorch 操作来表达函数 f 即可。

**推导过程中的思想：**

1. **局部性：** 链式法则的美妙之处在于，计算一个复杂函数的梯度可以分解为计算一系列简单函数（图中的每个操作）的局部梯度。
2. **反向流动：** 梯度信息从最终的输出（损失）开始，一步步向前面的节点传递。
3. **累加：** 如果一个变量通过多条路径影响最终输出，那么从这些路径反向传播回来的梯度会累加起来。这对应于多变量微积分中的全微分和链式法则。

### 示例与应用 (Examples & Application)

#### 简单示例：Tensor 创建和基本运算

```python
import torch

# 1. 创建 Tensor
x = torch.tensor([[1, 2, 3], [4, 5, 6]], dtype=torch.float32)
y = torch.rand_like(x) # 创建一个和 x 形状、类型都相同的随机 Tensor

print("Tensor x:\n", x)
print("Tensor y:\n", y)

# 2. 加法
z_add = x + y
# 或者 z_add = torch.add(x, y)
print("x + y:\n", z_add)

# 3. 元素级乘法
z_mul_elementwise = x * y
# 或者 z_mul_elementwise = torch.mul(x, y)
print("x * y (element-wise):\n", z_mul_elementwise)

# 4. 矩阵乘法
# 为了进行矩阵乘法，我们需要调整 y 的形状或者创建一个新的 Tensor
# 假设我们想计算 x (2x3) 和 y_T (3x2，y的转置) 的乘积
if y.shape[0] == 3 : # 确保 y 可以转置成 3xN 的形式
    y_T = y.t()
else: # 否则创建一个新的符合要求的矩阵
    y_reshaped = torch.randn(3, 2)
    y_T = y_reshaped

# 进行矩阵乘法的前提是 x 的列数等于 y_T 的行数
# x: 2x3, y_T: 3x2 (假设) -> 结果是 2x2
if x.shape[1] == y_T.shape[0]:
    z_mm = torch.mm(x, y_T)
    print("Matrix multiplication x @ y_T:\n", z_mm)
else:
    print(f"Cannot perform matrix multiplication with x shape {x.shape} and y_T shape {y_T.shape}")

# 5. 改变形状 (view)
a = torch.arange(1, 7) # tensor([1, 2, 3, 4, 5, 6])
b = a.view(2, 3)
print("Original a:", a)
print("View b (2x3):\n", b)
# 修改 b 会影响 a，因为它们共享数据
b[0, 0] = 100
print("Modified a after changing b:", a) # a 的第一个元素也会变成 100
```

[25, 27, 38, 39, 46]

#### 稍复杂示例：使用 Autograd 进行线性回归的梯度计算

线性回归是最简单的机器学习模型之一。模型可以表示为 y=$Xw+b$，其中 X 是输入特征， w 是权重， b 是偏置，y 是预测值。我们的目标是找到最优的 w 和 b 来最小化预测值与真实值之间的平方差损失：$L=\sum(y_{pred}​−y_{true}​)^{2}$。

这里我们只关注如何使用 Autograd 计算损失函数关于 w 和 b 的梯度。

```Python
import torch

# 0. 生成一些样本数据 (真实关系： y = 2*x + 1 + noise)
X_numpy = torch.arange(-5, 5, 0.1).view(-1, 1) # 输入特征 (100x1)
true_w = torch.tensor([[2.0]])
true_b = torch.tensor([1.0])
Y_numpy = torch.mm(X_numpy, true_w) + true_b + torch.randn(X_numpy.size(0), 1) * 0.5 # 真实输出 (100x1)

# 转换到 PyTorch Tensor
X = X_numpy
Y = Y_numpy

# 1. 初始化模型参数 (权重 w 和偏置 b)
# 我们希望计算关于 w 和 b 的梯度，所以 requires_grad=True
w = torch.randn(1, 1, requires_grad=True) # 初始权重 (1x1)
b = torch.zeros(1, 1, requires_grad=True) # 初始偏置 (1x1)

# 2. 定义模型 (前向传播)
def linear_model(X_input, w_param, b_param):
    return torch.mm(X_input, w_param) + b_param

# 3. 定义损失函数 (均方误差 Mean Squared Error, MSE)
def mse_loss(y_predicted, y_true):
    return torch.mean((y_predicted - y_true)**2)

# 假设进行一次迭代
learning_rate = 0.01 # 学习率，用于后续参数更新 (这里不实际更新，只演示梯度计算)

# 前向传播：计算预测值
Y_pred = linear_model(X, w, b)

# 计算损失
loss = mse_loss(Y_pred, Y)
print(f"Initial Loss: {loss.item()}") # .item() 用于从单元素 Tensor 中获取 Python 数字

# 反向传播：计算梯度
# 在调用 backward() 之前，如果不是第一次迭代，通常需要清除旧的梯度
# if w.grad is not None:
#     w.grad.zero_()
# if b.grad is not None:
#     b.grad.zero_()
loss.backward()

# 梯度现在存储在 w.grad 和 b.grad 中
print(f"Gradient for w: {w.grad}")
print(f"Gradient for b: {b.grad}")

# 在一个完整的训练循环中，接下来会用这些梯度来更新 w 和 b：
# with torch.no_grad(): # 更新参数时，我们不希望这些操作被 Autograd 跟踪
#     w -= learning_rate * w.grad
#     b -= learning_rate * b.grad
# 然后重复 前向传播 -> 计算损失 -> 反向传播 -> 更新参数 的过程。
```

[84]

这个例子展示了：

1. 如何定义可学习参数 (`requires_grad=True`)。
2. 如何用 PyTorch 操作构建模型（前向传播）。
3. 如何定义损失函数。
4. 如何通过 `loss.backward()` 自动计算梯度。
5. 梯度会存储在参数的 `.grad` 属性中。

**为什么这个很重要？**

在更复杂的深度学习模型（比如卷积神经网络CNN、循环神经网络RNN）中，手动计算梯度几乎是不可能的。`Autograd` 使得我们可以定义任意复杂的模型，只要这些模型是由 PyTorch 的可微操作组成的，PyTorch 就能自动帮我们处理梯度计算，让我们能使用基于梯度的优化算法（如梯度下降、Adam等）来训练这些模型。

#### 应用场景：

- **训练各种神经网络：** 这是 PyTorch 最核心的应用。从简单的全连接网络到复杂的 CNNs, RNNs, Transformers 等，`Autograd` 都是训练过程的基石。
- **可微分编程：** 由于 PyTorch 的计算图是动态的，并且能够自动求导，它甚至可以用于更广泛的“可微分编程”场景，即任何可以通过一系列可微操作构建的计算过程，都可以用梯度下降等方法进行优化。例如，在某些物理模拟、控制系统或生成艺术中，如果目标函数可以表示为 PyTorch 计算图，就可以利用 `Autograd` 进行优化。

### 知识点总结与要点提炼 (Summary & Key Takeaways)

以下是关于 PyTorch `Tensor` 和 `Autograd` 的核心要点总结：

- **PyTorch 核心概念：**
    
    - **Tensor：** PyTorch 的基本数据结构，是一个多维数组，类似于 Numpy 的 `ndarray`，但具有 GPU 加速和自动求导能力。 [20, 62]
    - **Autograd：** PyTorch 的自动微分引擎，能够自动计算 `Tensor` 操作的梯度，是神经网络训练的核心。 [20, 66]
- **Tensor (张量)：**
    
    - **定义：** 可以是标量（0D）、向量（1D）、矩阵（2D）或更高维度的数组。 [21]
    - **创建：** `torch.tensor()`, `torch.zeros()`, `torch.ones()`, `torch.rand()`, `torch.randn()` 等。 [25]
    - **属性：** `.shape` (或 `.size()`), `.dtype`, `.device` (CPU/GPU)。
    - **操作：**
        - 丰富的算术运算、线性代数运算、索引、切片。 [27, 37, 38, 45, 47]
        - `_` 后缀的操作（如 `add_`）是 in-place 修改。 [30]
        - `view()` 或 `reshape()` 用于改变形状，`view()` 共享数据。 [46]
    - **Numpy 转换：** `.numpy()` (Tensor to Numpy), `torch.from_numpy()` (Numpy to Tensor)。两者共享内存。 [48, 49, 50]
    - **GPU 支持：** 使用 `.cuda()` 将 Tensor 移至 GPU，使用 `torch.cuda.is_available()` 检查 GPU 可用性。运算的 Tensor 需在同一设备。 [53, 54]
- **Autograd (自动求导)：**
    
    - **目的：** 自动计算损失函数相对于模型参数的梯度，用于基于梯度的优化。
    - **`requires_grad`：** Tensor 属性，设置为 `True` 以便 PyTorch 跟踪其操作并计算梯度。模型的可学习参数通常设为 `True`。 [67]
    - **`grad_fn`：** 当 Tensor 由 `requires_grad=True` 的 Tensor 计算得到时，会有关联的 `grad_fn`，记录了创建该 Tensor 的操作，用于构建反向计算图。 [82]
    - **`backward()`：** 在标量损失 Tensor 上调用 `loss.backward()` 来启动梯度计算。 [67]
    - **`.grad`：** 调用 `backward()` 后，梯度会累积到 `requires_grad=True` 的叶子 Tensor 的 `.grad` 属性中。 [67]
    - **梯度累加：** 梯度是累加的，在优化循环中通常需要在每次更新前清零梯度 (`optimizer.zero_grad()` 或 `param.grad.zero_()`)。
    - **计算图：** Autograd 通过构建动态计算图（前向传播时构建，反向传播时使用）来实现自动求导，核心是链式法则。
    - **`torch.no_grad()`：** 上下文管理器，在其作用域内的操作不会被 `Autograd` 跟踪，常用于模型评估或参数更新阶段，以节省内存和计算。
- **与其他知识的联系：**
    
    - **高等数学：** 导数、偏导数、梯度、链式法则是 `Autograd` 的数学基础。
    - **线性代数：** `Tensor` 操作大量依赖于向量和矩阵运算（加法、乘法、转置等）。
    - **Numpy：** PyTorch `Tensor` 的设计和 API 在很大程度上借鉴了 Numpy，便于有 Numpy 基础的学习者上手。
    - **机器学习/深度学习：** `Tensor` 是数据的表示，`Autograd` 是模型训练（参数优化）的核心机制。

### 学科思想与延伸思考 (Underlying Philosophy & Further Thinking)

1. 抽象的力量 (Abstraction)：
    
    PyTorch 将复杂的数值计算和微分过程抽象为 Tensor 对象和 Autograd 引擎。用户不需要关心底层 CUDA 核函数如何编写，也不需要手动推导梯度公式。这种抽象使得研究人员和开发者可以将精力集中在模型架构和实验设计上。这与 CS61A 中强调的抽象思想一脉相承，通过构建强大的抽象层来管理复杂性。
    
2. 计算图作为核心表示 (Computational Graphs as a Core Representation)：
    
    无论是 TensorFlow、PyTorch 还是其他深度学习框架，计算图都是一个核心概念。它不仅是组织运算的方式，也是实现自动微分的基础。<font color="#ffff00">PyTorch 的动态计算图尤其强大，它允许图的结构在运行时根据输入数据或控制流（如循环和条件判断）发生变化。这为处理复杂和动态的模型（如自然语言处理中的递归网络或图神经网络）提供了极大的灵活性</font>。思考一下，这种“在运行时定义计算”的范式与传统的静态编译语言有什么异同？
    
3. 声明式 vs. 命令式编程的融合：
    
    早期的 TensorFlow (1.x) 更偏向于“声明式”编程：你先定义整个计算图，然后执行它。而 PyTorch 从一开始就更偏向于“命令式”编程：计算图是随着你的 Python 代码执行而动态构建的，这使得调试更加直观（你可以像调试普通 Python 代码一样设置断点、检查中间变量）。这种“所见即所得”的执行方式（Define-by-Run）是 PyTorch 受欢迎的重要原因之一。
    
4. 模块化与可组合性 (Modularity and Composability)：
    
    PyTorch 通过 torch.nn.Module 类鼓励用户将复杂的模型分解为更小的、可重用的模块。这些模块本身也可以包含其他模块，从而可以像搭积木一样构建非常复杂的网络结构。每个模块都有自己的参数和前向传播逻辑。这种设计思想类似于软件工程中的面向对象和组件化编程。
    
5. 从“轮子”到“造轮子”的平滑过渡：
    
    PyTorch 提供了大量预定义的层 (layers)、激活函数 (activation functions)、损失函数 (loss functions) 和优化器 (optimizers)。但同时，由于其灵活性和与 Python 的紧密集成，<font color="#ffff00">如果你想实现自定义的层或损失函数，甚至自定义 autograd.Function 来定义新的可微操作（并提供其前向和反向传播的精确实现），PyTorch 也提供了清晰的接口。这使得从使用现成组件到深入底层定制的过渡非常自然</font>。
    

**启发性问题：**

- 为什么在参数更新时，我们需要使用 `with torch.no_grad():` 或者先将梯度清零再调用 `backward()`？如果不这样做，会发生什么？
- `Tensor` 的 `view()` 操作和 `reshape()` 操作有什么主要的区别和相似之处？它们在什么情况下表现不同？
- 如果一个操作本身是不可微的（比如取整操作 `torch.round()` [45]），或者我们想在计算图的某个点“阻断”梯度的反向传播，可以怎么做？（提示：`.detach()` 方法）
- GPU 加速对于深度学习为什么如此重要？仅仅是因为 GPU 计算快吗？还有其他原因吗？（提示：并行性） [52]

**高观点导航：**

- **`torch.nn` 模块：** 我们今天主要关注了底层的 `Tensor` 和 `Autograd`。在实际构建神经网络时，你会更多地使用 `torch.nn` 模块。这个模块提供了构建神经网络所需的核心组件，如各种类型的层（线性层、卷积层、循环层）、损失函数、容器（如 `nn.Sequential`）等。它们都是基于 `Tensor` 和 `Autograd` 构建的，并封装了很多细节，使得模型构建更加便捷和模块化。
- **优化器 (`torch.optim`)：** 我们提到了梯度计算，但如何使用这些梯度来更新模型参数呢？`torch.optim` 模块提供了各种优化算法的实现，如 SGD (随机梯度下降)、Adam、RMSprop 等。你只需要将模型的参数和学习率等超参数传递给优化器，然后在计算完梯度后调用 `optimizer.step()`，它就会自动更新参数。
- **数据加载 (`torch.utils.data`)：** 高效地加载和预处理数据对于训练深度学习模型至关重要。`torch.utils.data` 提供了 `Dataset` 和 `DataLoader` 等工具，帮助你构建高效的数据加载流水线，支持批量处理、数据打乱、并行加载等。

通过理解今天学习的 `Tensor` 和 `Autograd`，你就掌握了 PyTorch 的“发动机”和“燃料”。接下来学习 `torch.nn`、`torch.optim` 和数据加载等内容，就像是为这台强大的发动机装上车身、方向盘和轮子，让你能够真正开动这辆“深度学习之车”去解决实际问题。

希望这次讲解对你有所帮助！PyTorch 是一个非常值得投入时间学习的工具。多动手实践，从简单的例子开始，逐步尝试更复杂的模型，你会越来越体会到它的强大和优雅。