Seaborn 是一个基于 Matplotlib 的 Python 数据可视化库，它提供了更高级的接口，使得绘制美观、信息丰富的统计图形变得更加容易。

我们就从零开始，一步步教你如何使用 Seaborn 画出多个散点图。

---

## 零基础入门：使用 Seaborn 画多个散点图

**目标：** 学会使用 Seaborn 绘制基本的散点图，并掌握几种展示“多个”散点图关系的方法。

**核心思想：** 散点图（Scatter Plot）用于展示两个数值变量之间的关系。每个数据点在图上的位置由其对应的两个变量的值确定。Seaborn 可以让我们轻松地在此基础上增加更多信息维度（例如用颜色、大小区分不同类别）。

**你需要准备：**

1.  **Python 环境：** 确保你的电脑安装了 Python (通常 3.6 或更高版本)。
2.  **必要的库：** 需要安装 `seaborn`, `matplotlib` (seaborn 的基础), 和 `pandas` (用于数据处理)。
    *   打开你的终端或命令提示符，运行以下命令安装：
        ```bash
        pip install seaborn matplotlib pandas
        ```

---

### 步骤 1: 导入库并准备数据

任何数据分析和可视化的第一步都是导入所需的库，并准备好要使用的数据。Seaborn 通常与 Pandas DataFrame 配合使用效果最好。

```python
# 导入必要的库
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np # 用 numpy 生成一些示例数据

# --- 创建示例数据 ---
# 假设我们有一组关于学生的数据：身高(cm)、体重(kg)、年级(Grade)
# 我们随机生成一些数据来模拟
np.random.seed(0) # 设置随机种子保证每次结果一样
data = {
    'Height': np.random.normal(160, 10, 100), # 平均身高160cm，标准差10，生成100个样本
    'Weight': np.random.normal(55, 8, 100),  # 平均体重55kg，标准差8
    'Grade': np.random.choice(['Grade 1', 'Grade 2', 'Grade 3'], 100) # 从三个年级中随机选100个
}
df = pd.DataFrame(data)

# 打印看看数据长什么样
print(df.head())
```

现在，我们有了一个名为 `df` 的 Pandas DataFrame，包含了身高、体重和年级信息。

---

### 步骤 2: 绘制单个基础散点图

我们先画一个最简单的散点图，看看身高和体重之间的关系。

```python
# 使用 seaborn 的 scatterplot 函数
sns.scatterplot(data=df, x='Height', y='Weight')

# 使用 matplotlib 的函数来显示图形
plt.title('Height vs Weight') # 添加标题
plt.xlabel('Height (cm)')     # 添加 x 轴标签
plt.ylabel('Weight (kg)')     # 添加 y 轴标签
plt.show() # 显示图形
```

**讲解:**

*   `import seaborn as sns`: 导入 seaborn 库，并约定俗成地简写为 `sns`。
*   `import matplotlib.pyplot as plt`: 导入 matplotlib 的 pyplot 模块，用于显示和调整图形，简写为 `plt`。
*   `sns.scatterplot(...)`: 这是绘制散点图的核心函数。
    *   `data=df`: 指定要使用的数据来源是我们的 DataFrame `df`。
    *   `x='Height'`: 指定 x 轴对应 DataFrame 中的 'Height' 列。
    *   `y='Weight'`: 指定 y 轴对应 DataFrame 中的 'Weight' 列。
*   `plt.title(...)`, `plt.xlabel(...)`, `plt.ylabel(...)`: 这些是 Matplotlib 的函数，用于添加标题和轴标签，让图形更易懂。
*   `plt.show()`: 显示绘制好的图形。

你会看到一个基本的散点图，每个点代表一个学生的身高和体重。

---

### 步骤 3: 在单个图中展示“多个”散点关系 (使用 `hue`)

现在，我们想看看不同年级的学生在身高体重分布上有没有差异。我们可以在**同一个图**里，用**不同的颜色**来表示不同的年级。这就是 `hue` 参数的作用。

```python
# 使用 hue 参数按 'Grade' 列给点着色
sns.scatterplot(data=df, x='Height', y='Weight', hue='Grade')

plt.title('Height vs Weight by Grade')
plt.xlabel('Height (cm)')
plt.ylabel('Weight (kg)')
plt.legend(title='Grade') # 显示图例并设置标题
plt.show()
```

**讲解:**

*   `hue='Grade'`: 这是关键！它告诉 Seaborn 根据 'Grade' 列的不同值（'Grade 1', 'Grade 2', 'Grade 3'）来给散点图上的点赋予不同的颜色。
*   `plt.legend(...)`: 由于我们用了 `hue`，Seaborn 会自动创建一个图例来解释颜色代表什么。`plt.legend()` 可以用来调整图例，这里我们给图例加了个标题。

现在，你在一个图里就看到了“多个”（按年级区分的）散点分布情况。你还可以尝试用 `size='Grade'` (用点的大小区分) 或 `style='Grade'` (用点的形状区分)，或者组合使用它们！

---

### 步骤 4: 绘制多个独立的散点图 (使用 Matplotlib Subplots)

如果你想在**不同的子图 (Subplot)** 中绘制不同的散点图（比如，比较不同数据集，或者同一数据集的不同变量关系），你需要结合 Matplotlib 的子图功能。

假设我们想分别看 'Grade 1' 和 'Grade 2' 的身高体重关系。

```python
# 创建一个包含 1 行 2 列子图的图形窗口
fig, axes = plt.subplots(1, 2, figsize=(12, 5)) # figsize 控制整个图形的大小

# --- 在第一个子图 (axes[0]) 中绘制 Grade 1 的数据 ---
sns.scatterplot(data=df[df['Grade'] == 'Grade 1'], # 筛选出 Grade 1 的数据
                x='Height', y='Weight',
                ax=axes[0]) # 指定在第一个子图上绘制
axes[0].set_title('Grade 1: Height vs Weight')
axes[0].set_xlabel('Height (cm)')
axes[0].set_ylabel('Weight (kg)')
axes[0].set_xlim(df['Height'].min()-5, df['Height'].max()+5) # 设置 x 轴范围，让两个图可比
axes[0].set_ylim(df['Weight'].min()-5, df['Weight'].max()+5) # 设置 y 轴范围

# --- 在第二个子图 (axes[1]) 中绘制 Grade 2 的数据 ---
sns.scatterplot(data=df[df['Grade'] == 'Grade 2'], # 筛选出 Grade 2 的数据
                x='Height', y='Weight',
                ax=axes[1]) # 指定在第二个子图上绘制
axes[1].set_title('Grade 2: Height vs Weight')
axes[1].set_xlabel('Height (cm)')
axes[1].set_ylabel('Weight (kg)')
axes[1].set_xlim(df['Height'].min()-5, df['Height'].max()+5) # 保持 x 轴范围一致
axes[1].set_ylim(df['Weight'].min()-5, df['Weight'].max()+5) # 保持 y 轴范围一致

# 调整子图布局，防止标题和标签重叠
plt.tight_layout()
plt.show()
```

**讲解:**

*   `fig, axes = plt.subplots(1, 2, figsize=(12, 5))`: 这行代码创建了一个新的图形 (`fig`) 和一个包含多个**轴对象 (Axes)** 的数组 (`axes`)。`plt.subplots(1, 2)` 表示创建 1 行 2 列的子图网格。`axes` 现在是一个包含两个元素的数组，`axes[0]` 代表左边的子图，`axes[1]` 代表右边的子图。
*   `data=df[df['Grade'] == 'Grade 1']`: 我们使用 Pandas 的索引功能筛选出特定年级的数据子集。
*   `ax=axes[0]` (或 `ax=axes[1]`): 这是关键！它告诉 Seaborn 函数 (`scatterplot`) 在哪个具体的 Matplotlib 轴对象上绘制图形。
*   `axes[0].set_title(...)`, `axes[0].set_xlabel(...)`, `axes[0].set_ylabel(...)`: 注意，当在特定子图上操作时，我们调用的是轴对象 (`axes[0]`) 的方法，而不是 `plt` 的方法。
*   `axes[0].set_xlim(...)`, `axes[0].set_ylim(...)`: 为了方便比较，我们手动设置了两个子图的 x 轴和 y 轴范围，使它们保持一致。
*   `plt.tight_layout()`: 自动调整子图参数，使之填充整个图像区域，避免重叠。

现在你得到了两个并排的散点图，分别展示了不同年级学生的身高体重关系。

---

### 步骤 5: 使用 Seaborn 的 FacetGrid 或 PairGrid (更高级的多图方法)

Seaborn 提供了更强大的工具来自动创建基于数据子集的多个图形网格。

**方法一：`relplot` (基于 FacetGrid)**

`relplot` 是一个图形级别的函数，它可以轻松创建基于不同子集的散点图或线图网格。

```python
# 使用 relplot 创建按 'Grade' 分列的散点图
# kind='scatter' 是默认值，这里明确写出
sns.relplot(data=df, x='Height', y='Weight', col='Grade', kind='scatter')

plt.suptitle('Height vs Weight by Grade (Separate Plots)', y=1.02) # 添加总标题，并调整位置
plt.show()
```

**讲解:**

*   `sns.relplot(...)`: 这个函数会自动处理子图的创建和布局。
*   `col='Grade'`: 这个参数告诉 `relplot` 根据 'Grade' 列的不同值，为每个值创建一个新的**列**子图。你也可以用 `row='Grade'` 让它们按行排列，或者同时使用 `row` 和 `col` 创建二维网格。
*   `kind='scatter'`: 指定基础绘图类型是散点图。
*   `plt.suptitle(...)`: 给整个图形网格添加一个总标题。`y=1.02` 是为了防止标题与子图标题重叠。

这种方法代码更简洁，能快速生成按类别划分的多个散点图。

**方法二：`pairplot`**

如果你想看数据集中**所有数值变量两两之间**的关系，`pairplot` 是绝佳选择。它会创建一个散点图矩阵。

```python
# 绘制数据框中所有数值变量两两之间的散点图
# 对角线默认是直方图 (hist) 或 核密度估计 (kde)
sns.pairplot(df)
plt.suptitle('Pairwise Relationships in the Dataset', y=1.02)
plt.show()

# 也可以加入 hue 参数
sns.pairplot(df, hue='Grade')
plt.suptitle('Pairwise Relationships by Grade', y=1.02)
plt.show()
```

**讲解:**

*   `sns.pairplot(df)`: 对 `df` 中所有数值列（这里是 'Height', 'Weight'）进行两两组合，绘制散点图。对角线上默认绘制该变量自身的分布图（直方图或KDE）。
*   `hue='Grade'`: 同样可以应用 `hue` 参数，使得所有散点图和对角线分布图都按年级用颜色区分。

`pairplot` 非常适合快速探索性数据分析，一览变量间的整体关系。

---

## 总结

恭喜你！现在你应该掌握了使用 Seaborn 绘制多个散点图的几种核心方法：

1.  **单一散点图，用 `hue`/`size`/`style` 区分组别:** 最简单，在同一坐标系下比较不同组。使用 `sns.scatterplot()`。
2.  **多个独立子图，手动布局:** 需要结合 Matplotlib 的 `plt.subplots()`，并在 `sns.scatterplot()` 中指定 `ax` 参数。更灵活，但代码稍多。
3.  **使用 `relplot` (FacetGrid):** Seaborn 提供的便捷方法，通过 `row` 和 `col` 参数自动创建基于数据子集的图形网格。代码简洁。
4.  **使用 `pairplot`:** 用于快速查看数据集中所有数值变量两两之间的关系，生成散点图矩阵。非常适合探索性分析。

从零开始，关键是多动手实践！尝试用你自己的数据，或者修改示例数据，调整参数看看效果。祝你可视化学习愉快！