---
sr-due: 2025-05-18
sr-interval: 3
sr-ease: 250
---

#review 

>Core Ideas:
>usually elementwise operations, for either M & M or M & f
>has linear alg module

好的，这是一份为你准备的 Numpy 简明使用教程，希望能帮助你快速掌握其核心用法。

---

## Numpy 简明使用教程

### 1. 简介 (Introduction)

*   **是什么？** Numpy (Numerical Python) 是 Python 科学计算的基础包。它提供了一个强大的 N 维数组对象 (`ndarray`)、复杂的广播功能、用于集成 C/C++/Fortran 代码的工具以及有用的线性代数、傅里叶变换和随机数生成能力。
*   **为什么重要？**
    *   **性能：** Numpy 底层使用 C 语言实现，其数组操作（向量化操作）比纯 Python 的列表操作快得多。
    *   **内存效率：** Numpy 数组在内存中是连续存储的，比 Python 列表更节省内存。
    *   **便捷性：** 提供了大量用于数组计算的函数和方法。
    *   **生态基础：** 是 Pandas, Scikit-learn, SciPy, Matplotlib 等众多数据科学和机器学习库的基础。
*   **核心对象：** `ndarray` (N-dimensional array)，一个存储**同类型**元素的多维网格。

### 2. 安装 (Installation)

通常使用 pip 进行安装：
```bash
pip install numpy
```
在 Python 代码中导入：
```python
import numpy as np # np 是 Numpy 的标准别名
```

### 3. 创建 Numpy 数组 (Array Creation)

*   **从 Python 列表或元组创建:**
    ```python
    # 一维数组
    list_a = [1, 2, 3, 4, 5]
    arr_a = np.array(list_a)
    print("从列表创建:", arr_a)
    print("类型:", type(arr_a))

    # 二维数组 (列表的列表)
    list_b = [[1, 2, 3], [4, 5, 6]]
    arr_b = np.array(list_b)
    print("\n从嵌套列表创建:\n", arr_b)
    ```
    **输出预测:**
    ```
    从列表创建: [1 2 3 4 5]
    类型: <class 'numpy.ndarray'>

    从嵌套列表创建:
     [[1 2 3]
     [4 5 6]]
    ```

*   **使用内置函数创建:**
    ```python
    # 创建全零数组 (需要指定形状 shape)
    zeros_arr = np.zeros((2, 3)) # 2行3列
    print("\n全零数组:\n", zeros_arr)

    # 创建全一数组
    ones_arr = np.ones((3, 2), dtype=int) # 指定数据类型为整数
    print("\n全一数组 (整数):\n", ones_arr)

    # 创建等差序列 (类似 range)
    range_arr = np.arange(0, 10, 2) # 从0开始，到10结束(不含)，步长为2
    print("\n等差序列数组:", range_arr)

    # 创建指定数量元素的等间隔序列 (包含起始和结束)
    linspace_arr = np.linspace(0, 1, 5) # 从0到1，生成5个等间隔数字
    print("\n等间隔序列数组:", linspace_arr)

    # 创建随机数组
    rand_arr = np.random.rand(2, 2) # 0到1之间的均匀分布
    print("\n随机数组 (0-1均匀分布):\n", rand_arr)
    randn_arr = np.random.randn(2, 2) # 标准正态分布 (均值为0，方差为1)
    print("\n随机数组 (标准正态分布):\n", randn_arr)
    randint_arr = np.random.randint(0, 10, size=(3, 3)) # [0, 10) 范围内的随机整数
    print("\n随机整数数组:\n", randint_arr)
    ```
    **输出预测:** (随机数部分每次运行会不同)
    ```
    全零数组:
     [[0. 0. 0.]
     [0. 0. 0.]]

    全一数组 (整数):
     [[1 1]
     [1 1]
     [1 1]]

    等差序列数组: [0 2 4 6 8]

    等间隔序列数组: [0.   0.25 0.5  0.75 1.  ]

    随机数组 (0-1均匀分布):
     [[0.123 0.456]
     [0.789 0.012]]  # 示例值

    随机数组 (标准正态分布):
     [[-0.567  1.234]
     [ 0.345 -0.890]] # 示例值

    随机整数数组:
     [[5 2 8]
     [1 9 0]
     [7 3 6]] # 示例值
    ```

### 4. 数组属性 (Array Attributes)

```python
arr = np.array([[1, 2, 3], [4, 5, 6]])

print("数组形状 (shape):", arr.shape) # 返回一个元组，表示各维度大小
print("数组维度 (ndim):", arr.ndim)   # 数组的轴（维度）数
print("数组元素总数 (size):", arr.size) # 数组中元素的总数
print("数组元素类型 (dtype):", arr.dtype) # 数组元素的数据类型
```
**输出预测:**
```
数组形状 (shape): (2, 3)
数组维度 (ndim): 2
数组元素总数 (size): 6
数组元素类型 (dtype): int64 # (或 int32, 取决于系统)
```

### 5. 索引与切片 (Indexing and Slicing)

与 Python 列表类似，但可以扩展到多维。

```python
arr = np.arange(10) # [0 1 2 3 4 5 6 7 8 9]
print("原数组:", arr)

# 单个元素索引
print("第一个元素:", arr[0])
print("最后一个元素:", arr[-1])

# 切片 [start:stop:step] (不包含 stop)
print("索引1到4 (不含4):", arr[1:4])
print("前5个元素:", arr[:5])
print("步长为2:", arr[::2])
print("反转数组:", arr[::-1])

# 多维数组索引与切片
arr_2d = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print("\n二维数组:\n", arr_2d)
print("第0行, 第1列元素:", arr_2d[0, 1]) # 用逗号分隔维度
print("第1行所有元素:", arr_2d[1, :]) # : 表示该维度的所有元素
print("第2列所有元素:", arr_2d[:, 2])
print("子数组 (前2行, 1到2列):\n", arr_2d[:2, 1:3])

# 布尔索引 (非常有用!)
arr_bool = np.array([10, 20, 30, 40, 50])
mask = arr_bool > 25 # 创建一个布尔数组 [False False  True  True  True]
print("\n布尔掩码:", mask)
print("大于25的元素:", arr_bool[mask]) # 使用布尔数组作为索引
print("直接使用条件:", arr_bool[arr_bool % 20 == 0]) # 值为20的倍数的元素

# 花式索引 (Fancy Indexing - 使用整数数组作为索引)
arr_fancy = np.arange(10, 20) # [10 11 12 13 14 15 16 17 18 19]
indices = [1, 5, 8]
print("\n花式索引:", arr_fancy[indices]) # 获取索引为1, 5, 8的元素
```
**输出预测:**
```
原数组: [0 1 2 3 4 5 6 7 8 9]
第一个元素: 0
最后一个元素: 9
索引1到4 (不含4): [1 2 3]
前5个元素: [0 1 2 3 4]
步长为2: [0 2 4 6 8]
反转数组: [9 8 7 6 5 4 3 2 1 0]

二维数组:
 [[1 2 3]
 [4 5 6]
 [7 8 9]]
第0行, 第1列元素: 2
第1行所有元素: [4 5 6]
第2列所有元素: [3 6 9]
子数组 (前2行, 1到2列):
 [[2 3]
 [5 6]]

布尔掩码: [False False  True  True  True]
大于25的元素: [30 40 50]
直接使用条件: [20 40]

花式索引: [11 15 18]
```

### 6. 基本运算与通用函数 (Basic Operations & Universal Functions - ufuncs)

*   **元素级运算 (Element-wise):** 数组间的算术运算默认是元素级的。
    ```python
    a = np.array([1, 2, 3])
    b = np.array([4, 5, 6])

    print("\na + b =", a + b)
    print("a * b =", a * b)
    print("a ** 2 =", a ** 2)
    print("a > 1 =", a > 1) # 元素级比较

    # 也适用于多维数组 (需要形状兼容或可广播)
    c = np.array([[1, 1], [1, 1]])
    d = np.array([[2, 3], [4, 5]])
    print("\nc * d =\n", c * d)
    ```
    **输出预测:**
    ```
    a + b = [5 7 9]
    a * b = [ 4 10 18]
    a ** 2 = [1 4 9]
    a > 1 = [False  True  True]

    c * d =
     [[2 3]
     [4 5]]
    ```

*   **通用函数 (ufuncs):** 对 `ndarray` 中的数据执行元素级操作的函数。
    ```python
    arr = np.array([0, np.pi/2, np.pi]) # [0.      1.57079633 3.14159265]

    print("\nsin(arr) =", np.sin(arr))
    print("exp(arr) =", np.exp(arr)) # e的次方
    print("sqrt(arr+1) =", np.sqrt(arr + 1)) # 先加1再开方
    print("log(arr+1) =", np.log(arr + 1)) # 自然对数 (ln)
    ```
    **输出预测:**
    ```
    sin(arr) = [0.0000000e+00 1.0000000e+00 1.2246468e-16] # sin(pi) 约等于 0
    exp(arr) = [ 1.          4.81047738 23.14069263]
    sqrt(arr+1) = [1.         1.603369   2.03509033]
    log(arr+1) = [0.         0.94439699 1.4210196 ]
    ```

### 7. 聚合运算 (Aggregation)

计算数组的统计量，如求和、平均值、最大/小值等。

```python
arr = np.array([[1, 2, 3], [4, 5, 6]])
print("\n数组:\n", arr)

print("所有元素求和:", np.sum(arr)) # 或 arr.sum()
print("所有元素均值:", np.mean(arr)) # 或 arr.mean()
print("所有元素最大值:", np.max(arr)) # 或 arr.max()
print("所有元素最小值:", np.min(arr)) # 或 arr.min()
print("所有元素标准差:", np.std(arr)) # 或 arr.std()

# 按轴 (axis) 聚合
# axis=0: 沿着行的方向操作 (压缩行，对每列进行计算)
# axis=1: 沿着列的方向操作 (压缩列，对每行进行计算)
print("\n按列求和 (axis=0):", np.sum(arr, axis=0)) # [1+4, 2+5, 3+6]
print("按行求均值 (axis=1):", np.mean(arr, axis=1)) # [(1+2+3)/3, (4+5+6)/3]
```
**输出预测:**
```
数组:
 [[1 2 3]
 [4 5 6]]
所有元素求和: 21
所有元素均值: 3.5
所有元素最大值: 6
所有元素最小值: 1
所有元素标准差: 1.707825127659933 # (数值可能因计算精度略有差异)

按列求和 (axis=0): [5 7 9]
按行求均值 (axis=1): [2. 5.]
```
**细节：** `axis` 参数非常重要，理解它操作的方向是关键。可以想象成沿着指定的轴“压扁”数组进行计算。

### 8. 广播 (Broadcasting)

当对不同形状的数组进行运算时，Numpy 会尝试**自动扩展**（或“广播”）较小数组的维度，使其形状与较大数组兼容。这是 Numpy 强大之处，避免了显式循环。

*   **规则（简化版）：**
    1.  从末尾开始比较两个数组的维度（形状）。
    2.  如果两个维度**相等**，或者其中一个维度是 **1**，则它们在那个维度上是兼容的。
    3.  如果维度不兼容且都不是 1，则会报错。
    4.  如果一个数组的维度少于另一个，<font color="#ffff00">会在其形状的前面补 1</font>，直到维度数相同。
    5.  运算时，大小为 1 的维度会被拉伸以匹配另一个数组对应维度的大小。

*   **示例：**
    ```python
    a = np.array([[1, 2, 3], [4, 5, 6]]) # Shape (2, 3)
    b = np.array([10, 20, 30])          # Shape (3,) -> 视为 (1, 3)
    c = np.array([[10], [20]])          # Shape (2, 1)

    print("\na (2, 3):\n", a)
    print("b (3,):", b)
    print("c (2, 1):\n", c)

    # a + b: (2, 3) + (1, 3) -> b 广播为 [[10, 20, 30], [10, 20, 30]]
    print("\na + b:\n", a + b)

    # a + c: (2, 3) + (2, 1) -> c 广播为 [[10, 10, 10], [20, 20, 20]]
    print("\na + c:\n", a + c)
    ```
    **输出预测:**
    ```
    a (2, 3):
     [[1 2 3]
     [4 5 6]]
    b (3,): [10 20 30]
    c (2, 1):
     [[10]
     [20]]

    a + b:
     [[11 22 33]
     [14 25 36]]

    a + c:
     [[11 12 13]
     [24 25 26]]
    ```

### 9. 线性代数 (Linear Algebra)

Numpy 的 `linalg` 模块提供了常用的线性代数运算。

```python
A = np.array([[1, 1], [0, 1]])
B = np.array([[2, 0], [3, 4]])

print("\nA:\n", A)
print("B:\n", B)

# 矩阵乘法 (不是元素级乘法!)
print("\n矩阵乘法 A @ B:\n", A @ B) # Python 3.5+ 推荐
print("矩阵乘法 np.dot(A, B):\n", np.dot(A, B)) # 另一种方式

# 矩阵转置
print("\nA的转置 A.T:\n", A.T)

# 计算行列式
print("\nA的行列式:", np.linalg.det(A))

# 计算逆矩阵
try:
    A_inv = np.linalg.inv(A)
    print("\nA的逆矩阵:\n", A_inv)
    print("验证 A @ A_inv (应接近单位矩阵):\n", A @ A_inv)
except np.linalg.LinAlgError:
    print("\nA 不可逆")

# 求解线性方程组 Ax = b
# 例如: x + y = 3, y = 2  => A = [[1,1],[0,1]], b = [3,2]
b_vec = np.array([3, 2])
try:
    x_sol = np.linalg.solve(A, b_vec)
    print("\n解线性方程组 Ax=b, x =", x_sol) # 预期解 [1, 2]
except np.linalg.LinAlgError:
    print("\n无法求解线性方程组 (A 可能奇异)")
```
**输出预测:**
```
A:
 [[1 1]
 [0 1]]
B:
 [[2 0]
 [3 4]]

矩阵乘法 A @ B:
 [[5 4]
 [3 4]]
矩阵乘法 np.dot(A, B):
 [[5 4]
 [3 4]]

A的转置 A.T:
 [[1 0]
 [1 1]]

A的行列式: 1.0

A的逆矩阵:
 [[ 1. -1.]
 [ 0.  1.]]
验证 A @ A_inv (应接近单位矩阵):
 [[1. 0.]
 [0. 1.]]

解线性方程组 Ax=b, x = [1. 2.]
```

### 10. 形状操作 (Reshaping & Stacking)

*   **改变形状 (`reshape`):** 返回一个具有新形状但不改变其数据的数组。元素总数必须保持不变。
    ```python
    arr = np.arange(6) # [0 1 2 3 4 5]
    reshaped_arr = arr.reshape((2, 3)) # 改为 2行3列
    print("\n原数组:", arr)
    print("Reshaped (2, 3):\n", reshaped_arr)

    # 展平数组 (`ravel` 或 `flatten`)
    print("展平数组:", reshaped_arr.ravel()) # 返回视图 (可能)
    print("展平数组 (copy):", reshaped_arr.flatten()) # 总是返回副本
    ```
    **输出预测:**
    ```
    原数组: [0 1 2 3 4 5]
    Reshaped (2, 3):
     [[0 1 2]
     [3 4 5]]
    展平数组: [0 1 2 3 4 5]
    展平数组 (copy): [0 1 2 3 4 5]
    ```

*   **堆叠数组 (`vstack`, `hstack`):**
    ```python
    a = np.array([1, 1, 1])
    b = np.array([2, 2, 2])

    # 垂直堆叠 (按行)
    v_stack = np.vstack((a, b))
    print("\n垂直堆叠 (vstack):\n", v_stack)
    print("v_stack shape:", v_stack.shape)

    # 水平堆叠 (按列)
    h_stack = np.hstack((a.reshape(-1,1), b.reshape(-1,1))) # 需要先变列向量
    print("\n水平堆叠 (hstack):\n", h_stack)
    print("h_stack shape:", h_stack.shape)

    # np.column_stack 是 hstack 的一种便捷方式处理一维数组
    col_stack = np.column_stack((a,b))
    print("\n列堆叠 (column_stack):\n", col_stack)
    ```
    **输出预测:**
    ```
    垂直堆叠 (vstack):
     [[1 1 1]
     [2 2 2]]
    v_stack shape: (2, 3)

    水平堆叠 (hstack):
     [[1 2]
     [1 2]
     [1 2]]
    h_stack shape: (3, 2)

    列堆叠 (column_stack):
     [[1 2]
     [1 2]
     [1 2]]
    ```
    **细节：** `hstack` 对于一维数组是直接拼接，对于二维数组是按列拼接。如果想将两个一维数组按列拼成二维数组，常用 `np.column_stack` 或先 `reshape` 成列向量再 `hstack`。
[[Gemini NumpyVstackAndHstack]]
### 11. 使用场景样例：模拟线性回归预测

假设我们有一个简单的一元线性回归模型 $y = w x + b$，我们用 Numpy 来生成数据并进行预测。

```python
# 1. 定义模型参数 (假设已学习得到)
w_true = 2.5
b_true = 1.0

# 2. 生成自变量 X 数据
X = np.linspace(0, 10, 50) # 生成 50 个从 0 到 10 的等间隔数据点
print("X (前5个):", X[:5])

# 3. 计算理论上的 Y 值 (不含噪声)
y_true = w_true * X + b_true
print("Y_true (前5个):", y_true[:5])

# 4. 添加高斯噪声，模拟真实数据
noise = np.random.randn(50) * 2.0 # 标准正态分布噪声，乘以 2.0 调整噪声幅度
Y_noisy = y_true + noise
print("Y_noisy (前5个):", Y_noisy[:5])

# 5. 使用学习到的参数进行预测 (这里用真实参数模拟)
w_learned = 2.4 # 假设学习到的 w
b_learned = 1.1 # 假设学习到的 b
Y_pred = w_learned * X + b_learned
print("Y_pred (前5个):", Y_pred[:5])

# (可选) 计算预测误差 (例如 MSE - Mean Squared Error)
mse = np.mean((Y_noisy - Y_pred)**2)
print("\n均方误差 (MSE):", mse)
```
**输出预测:** (噪声和 MSE 会变化)
```
X (前5个): [0.         0.20408163 0.40816327 0.6122449  0.81632653]
Y_true (前5个): [1.         1.51020408 2.02040816 2.53061224 3.04081633]
Y_noisy (前5个): [ 0.85       1.81033691  1.61725863  4.33098127  2.03105986] # 含噪声
Y_pred (前5个): [1.1        1.58979592 2.07959184 2.56938776 3.05918367] # 预测值

均方误差 (MSE): 4.5321 # 示例值
```
这个例子展示了如何用 Numpy 生成数据、进行向量化的数学运算（乘法、加法）以及聚合（`np.mean`）来完成一个简单的机器学习任务流程（数据生成和预测部分）。

### 12. 总结

*   Numpy 是 Python 数据科学和 AI 的基石。
*   核心是 `ndarray`，提供高效的同构数据存储。
*   **向量化**是关键，避免 Python 循环，利用 Numpy 的底层 C 实现获得高性能。
*   掌握数组创建、索引切片（尤其是布尔索引）、元素级运算、聚合运算（注意`axis`）、广播和基本线性代数是高效使用 Numpy 的基础。
*   它是后续学习 Pandas、Scikit-learn 等库的必备前置知识。

希望这个简明教程对你有帮助！多动手练习是掌握 Numpy 最好的方法。