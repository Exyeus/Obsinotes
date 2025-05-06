图表 1

![[Pasted image 20250505191113.png]]

图表 2

![[Pasted image 20250505191119.png]]

代码如下：

```python
import numpy as np
import matplotlib.pyplot as plt

class LogisticRegression(object):
    def __init__(self, dim, learning_rate=0.01, max_iter=1000, seed=None):
        np.random.seed(seed)
        self.lr = learning_rate
        self.max_iter = max_iter  # 定义学习率和训练轮数
        self.dim = dim
        # 初始化权重 W。维度是 (特征维度 + 1 (偏置项), 1)
        # 使用小的随机数初始化或全零初始化
        # self.W = np.zeros((self.dim + 1, 1))
        self.W = np.random.randn(self.dim + 1, 1) * 0.01 # 小随机数初始化

    def _sigmoid(self, z):
        """计算 Sigmoid 函数"""
        # 添加剪裁防止 exp 溢出 (对于非常大或非常小的 z)
        z = np.clip(z, -500, 500)
        return 1 / (1 + np.exp(-z))

    def fit(self, X, Y):
        # 请在此处补充类的方法:训练函数, 返回每轮loss的列表
        #输入:X为N * d维的训练数据, N为训练样本数, d为数据的维数, 即X是N
        #个d维数据点排成的矩阵；Y为N*1维的训练数据真实类别号, 即N个类别号排
        #成的向量；
        #输出:loss为列表, 长度为训练轮数, 每个元素为对应轮的损失函数值。
        loss = []
        N = X.shape[0] # 样本数 N

        # 确保 Y 是一个列向量 (N, 1)
        if Y.ndim == 1:
            Y = Y.reshape(-1, 1)

        X_augmented = np.hstack((X, np.ones((N, 1)))) # 形状变为 (N, d+1)

        # 梯度下降迭代
        for i in range(self.max_iter):
            # 1. 计算线性组合 z = XW
            z = X_augmented @ self.W # (N, d+1) @ (d+1, 1) -> (N, 1)

            # 2. 计算假设（预测概率） h = sigmoid(z)
            h = self._sigmoid(z) # (N, 1)

            # 3. 计算代价函数 (对数损失/二元交叉熵)
            # 为了数值稳定性，防止 log(0)，对 h 进行剪裁
            epsilon = 1e-8
            h_clipped = np.clip(h, epsilon, 1 - epsilon)
            cost = - (1 / N) * \
                        np.sum(\
                            Y * np.log(h_clipped) + (1 - Y) * np.log(1 - h_clipped)\
                            )
            loss.append(cost)

            # 4. 计算梯度 dJ/dW = (1/N) * X^T * (h - Y)
            error = h - Y # (N, 1)
            gradient = (1 / N) * (X_augmented.T @ error) # (d+1, N) @ (N, 1) -> (d+1, 1)

            # 5. 更新权重 W = W - learning_rate * gradient
            self.W = self.W - self.lr * gradient
        return loss

    def predict(self, X):
        # 请在此处补充类的方法:测试函数, 返回对应X的预测值和预测类别列表
        '''
        实现类的方法y_pred, y_pred_label= predict(X) 函数, 用于测试
        输入:X为N * d维的测试数据, N为测试样本数；
        输出:y_pred维数为N*1, 为模型的预测（回归）值, 即属于类别1的概率；
        y_pred_label维数为N*1, 为根据回归值得到的预测类别号, 只能取0或1
        y_pred_label的获得方法:若相应的y_pred小于0.5, 则y_pred_label为0,
        否则为1
        '''
        N = X.shape[0] # 测试样本数

        # 1. 给测试数据 X 添加偏置列
        X_augmented = np.hstack((X, np.ones((N, 1)))) # (N, d+1)

        # 2. 计算线性组合 z = XW
        z = X_augmented @ self.W # (N, d+1) @ (d+1, 1) -> (N, 1)

        # 3. 计算预测概率 Y_pred = sigmoid(z)
        Y_pred = self._sigmoid(z) # (N, 1)

        # 4. 根据概率生成预测类别标签 Y_pred_label
        # 如果概率 >= 0.5，则预测为 1，否则为 0
        Y_pred_label = (Y_pred >= 0.5).astype(int) # (N, 1), 元素为 0 或 1

        # 确保输出形状符合要求 (N, 1)
        # (上面的计算已经保证了是 (N, 1) 形状)

        return Y_pred, Y_pred_label

```

```python
def plotData(X,Y):
    """
    使用红色+号表示正例, 蓝色圆点表示负例, 绘制数据集中正负例的分布情况
    """
    # plt.figure() # 不在这里创建 figure，让调用者控制
    # 确保 Y 是一维的，方便布尔索引
    if Y.ndim > 1 and Y.shape[1] == 1:
         Y = Y.ravel() # 转换为 (N,) 形状

    pos_idx = (Y==1)
    neg_idx = (Y==0)

    plt.plot(X[pos_idx,0],X[pos_idx,1],'r+', label='Positive') # 添加 label
    plt.plot(X[neg_idx,0],X[neg_idx,1],'bo', label='Negative') # 添加 label
    plt.xlabel("Feature 1") # 添加坐标轴标签
    plt.ylabel("Feature 2") # 添加坐标轴标签
    plt.legend() # 显示图例

def plotDecisioinBoundary(X, Y, regr):
    """
    在正负例分布图上进一步绘制出模型regr的分类界面
    """
    # 先绘制正负例分布情况
    plotData(X,Y) # 调用修改后的 plotData

    # 绘制等高线图, 在水平和垂直方向均有50个点
    plot_num=50;
    # plot_num_2D=plot_num**2; # 这个变量没有用到

    # 准备网格
    x_plot = np.linspace(start=X[:,0].min(),stop=X[:,0].max(),num=plot_num)
    y_plot = np.linspace(start=X[:,1].min(),stop=X[:,1].max(),num=plot_num) 
    x_plot = np.linspace(x_min, x_max, plot_num) 
    # 使用扩大的边界
    y_plot = np.linspace(y_min, y_max, plot_num) 
    # 使用扩大的边界
    X_plot, Y_plot = np.meshgrid(x_plot, y_plot) 
    # X_plot, Y_plot 形状都是 (plot_num, plot_num)

    # 请在此补充代码, 计算regr模型在各个格点的预测概率, 并构成一个形状和格点相同的P_matrix数组, 绘制等高线图
    # ====== 开始补充代码 ======
    # 1. 将网格点组合成 N x d 的矩阵，用于输入 predict 函数
    #    X_plot.ravel() 将 X_plot 展平成一维数组
    #    Y_plot.ravel() 将 Y_plot 展平成一维数组
    #    np.c_ 按列合并，得到 (plot_num*plot_num, 2) 的矩阵
    
    grid_points = np.c_[X_plot.ravel(), Y_plot.ravel()]

    # 2. 使用训练好的模型 regr 预测这些网格点的概率
    #    regr.predict 返回 (概率, 标签)，我们只需要概率部分
    
    pred_probs, _ = regr.predict(grid_points) # pred_probs 形状是 (plot_num*plot_num, 1)

    # 3. 将预测的概率向量重新塑形成与网格相同的形状
    
    P_matrix = pred_probs.reshape(X_plot.shape) # 形状变为 (plot_num, plot_num)
    # ====== 补充代码结束 ======

    # 绘制决策边界，即概率 p=0.5 的等高线
    # plt.contour(X_plot,Y_plot, P_matrix, np.array([0.5])) # 原代码
    
    plt.contour(X_plot, Y_plot, P_matrix, levels=[0.5], colors='green', linewidths=2) # 指定颜色和线宽

def test(y_pred, y_true):
    true = 0.
    for j in range(y_pred.shape[0]):
        if y_true[j] == y_pred[j]:
            true += 1
    acc = true/y_pred.shape[0]
    return acc
```

```python
# 导入测试数据
seed = 210404
data_1 = np.load('data_for_logistic_regression_1.npz')
x_train = data_1['x_train']
y_train = data_1['y_train']
x_test = data_1['x_test']
y_test = data_1['y_test']
dim = x_train.shape[1] # 获取特征维度 d

# 训练逻辑回归模型
regr = LogisticRegression(dim, learning_rate=0.01, max_iter=1000, seed=seed)
loss = regr.fit(x_train, y_train)

print("训练后的权重 W (包含偏置项):")
print(regr.W)

# 打印损失曲线
plt.figure(figsize=(8, 6)) # 创建一个新的 figure 用于绘制损失曲线
plt.plot(np.arange(len(loss)), loss, linestyle='-', color='green') # 用线图更适合表示损失变化趋势
plt.title("Training Loss Curve")
plt.xlabel("Iteration")
plt.ylabel("Loss (Cost)")
plt.grid(True)

# 显示测试集中的分类界面
plt.figure(figsize=(8, 6)) # 创建一个新的 figure 用于绘制决策边界
plotDecisioinBoundary(x_test, y_test, regr)
plt.title("Decision Boundary on Test Set")
plt.show() # 显示所有绘制的图形

# 预测测试集并计算准确率
y_pred, y_pred_label = regr.predict(x_test)
acc = test(y_pred_label, y_test) # 使用 y_pred_label (预测标签)
print(f'测试集上正确率: {acc:.4f}')

```

