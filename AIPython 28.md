### 数据加载与 Dataloader

#### 数据加载过程

1. 硬盘加载
2. 存入内存
3. CPU 数据预处理，加入缓存
4. GPU 获取缓存的数据并计算之

利用GPU的并行计算特性！
GPU 利用率 往往因为 CPU 提供数据速率不足而受限，所以要使用 CPU 的多进程来保证 GPU 的速度

```python
trainset = torchvision.datasets.CIFAR10(root = './data', train = True, download = True)
trainloader = torch.utils.data.Dataloader(trainset, batch_size = 4, shuffle = True, num_workers = 2)
* Using 2 processes to speed up!*
```

### VGG Network Construction

![[Pasted image 20250529163140.png]]

一系列不同层数的神经网络
注意每次卷积后面跟一个 非线性激活
输入在横贯各列的长条里面！
Interesting part: 注意有 `conv1` 1 * 1 * 通道数 ...
把一个像素的所有通道作为输入，然后对其信息进行整合

![[Pasted image 20250529163322.png]]

前面部分为特征提取
由于使用了适当的 padding，这些图片的长宽不会改变
？确定不是比例不变？

#### VGG 搭建

使用字典存放数据
![[Pasted image 20250529163823.png]]

字母：模型的代号
四个网络里面，所有卷积核的大小一样

信息足够构建一个VGG










