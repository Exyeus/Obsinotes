### SingleLay Conv


> [!NOTE] example
> 3 \* 32 \* 32 RGB
> $3 * 32 *32$ tensor can be used to repr this image
> ![[Pasted image 20250526141043.png]]

>pooling 池化
>输出tensor 维度与卷积核大小一致
>![[Pasted image 20250526141304.png]]

每一层卷积之后都要进行一次 [[非线性激活]]
在这里，$29=32-5+1$. [参考各种算法](AIPython 25NeuralNetwork)

#### 单个卷积层

像素过多，不能使用 nlp 网络。
$5\times 5\times 3$ 输入到一个 [[神经元]] 之中？给神经元加上 bias
用神经元覆盖整个图片：让卷积核 / [[感受野]] 在整个图像上平移

乘法：
$$卷积核大小 \times 通道数$$
考虑 bias: 数量与通道数相同。
$$z^{[1]} =W^{[1]} a^{[0]} +br^{[0]} $$
非线性函数
......
#### 实现一层神经元——通过 Python

```python
nn.Conv2d(self, in_channels,
			out_channels,
			kernel_size,
			stride=1,
			padding=0,
			dilation=1,
			groups=1,
			bias=True))
```

### 池化层

意图：进一步缩减高与宽的维度
在第一个卷积层之后，构建一个池化层

#### 最大池化
顾名思义，会提取最大的，体现特征的数值
过滤器 $2\times 2$. $\text{Padding} = 0$.
可以使得 $6 \times 28 \times 28 \to 6 \times 14 \times 14$

最大区别：池化是没有可训练参数的。池化一般不会设置太多的 Padding。池化都在一个通道内进行，每个通道独立进行，不会改变通道的个数。

```python
nn.MaxPool2d(kernel_size, stride=None, padding=0, dilation=1, return_indices=False, ceil_mode=False)
```
#### 平均池化
相较于 最大池化，较少使用。
```python
nn.AvgPool2d(kernel_size, stride=None, padding=0, ceil_mode=False, count_include_pad=True)
```

#### Pytroch 

三通道 5 行 10 层
5 行 1 列
每一列的最大值保存下来，得到一个 $1\times 10$ 的结果
`kernel_size = 2` `stride = 2` 使得：
1. 互不相交
2. 大约将图片缩减至一半


> [!warning] Complete the code here!
> Contents
> ![[Pasted image 20250526143520.png]]


#### 卷积神经网络

回顾之前那个。设置 `stride = 2`, `padding = 0`, 就可以得到 $6 \times 28 \times 28 \to 6 \times 14 \times 14$.

### 卷积神经网络

过了池化层，维度就会减半
高和宽快速缩减，通道数变多 ？？

#### 分类概率

##### 二分类
二分类概率分布–样本空间：
	一个事件所有发生的可能情况 
		• 𝑆={发生，不发生} 
		• 𝑆={第0类，第1类}
		–样本点概率：𝑃s，满足𝑃s ≥0且𝑃s ≤1
	–定义在一个样本空间𝑆的概率分布，满足 
		• 𝑃s ≥0，∀𝑠∈𝑆 
		• 𝑃第0类+𝑃第1类=1 
		•可以用2个概率值（一个概率分布）表示对于一个事件发生的概率的估计
			–{0.1, 0.9}
			–{1, 0} 必定为第0类的概率
			–{0, 1} 必定为第1类的概

##### Softmax 函数

得到一个输出。每一维都在 $[0,1]$, 且数值相加之和 ：1
$$q(y=i)=\frac{e^{z[i]} }{\sum_{j} e^{z[j]} }$$
z 越大，$e^{z}$ 越大。但是注意，由于 $e^{x}$ 性质，会使得结果再小，输出也不会是 0。

当只有二维输入，可以得到 sigmoid 函数

#### 继续分析

$16 \times 5 \times 5$ 包含 400 个元素， `flatten(1)` 得到一个大小为 400 的一维向量。
400 个单元作为输入，10 个单元作为输出，构建[[全连接层]]。
*全连接*。维度 400 * 10，10个输出，`softmax` 之，得到属于各个数字的概率。

- 卷积神经网络通过参数共享和稀疏连接这两种机制减少参数，以便用 更少的训练数据来训练，防止过拟合。 
- 平移不变性：向右移动两个像素，图片中的猫依然清晰可见；因为神经网络的卷积结构使得即使移动几个像素，这张图片依然具有非常相 似的特征。

#### 训练卷积神经网络

`nn.CrossEntrophy` 作为损失函数。
[[置信度]]

[[Gemini AIPython TrainingPytorchNeuralNetwork]]