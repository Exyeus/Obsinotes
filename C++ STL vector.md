---
sr-due: 2025-07-03
sr-interval: 131
sr-ease: 290
---

#review #flashcards 

C++的`vector`是标准库中最常用的<font color="#ffff00">动态数组容器，它支持自动调整大小、灵活的元素访问、以及高效的内存管理</font>。下面是关于C++ `vector` STL的详尽性质、用法和支持的操作，包括相关的代码示例。

### 1. **Vector基本性质**

- **动态大小**：`vector`的大小会随着元素的加入自动增长，不需要预先指定大小。
- **连续内存**：`vector`存储的数据是连续的，可以通过索引访问。
- **内存管理**：`vector`会管理其内存，内存的增加是分配较大块内存，并且采用“几何增长”策略，通常每次增长大约1.5倍左右。
- **元素类型**：支持<font color="#ffff00">任意类型的元素（基本数据类型、类、指针等）</font>。

### 2. **常用操作**

以下是`vector`常用的操作：

#### 2.1 **声明与初始化**

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 声明一个空的vector
    vector<int> v1;
    
    // 初始化时指定大小和默认值
    vector<int> v2(5, 10); // 初始化为5个10

    // 使用初始化列表进行初始化
    vector<int> v3 = {1, 2, 3, 4, 5};

    // 显示v2和v3内容
    for (int i : v2) cout << i << " ";  // 输出: 10 10 10 10 10
    cout << endl;

    for (int i : v3) cout << i << " ";  // 输出: 1 2 3 4 5
    cout << endl;
}
```

#### 2.2 **添加元素**

- `push_back()`：在末尾添加元素。
- `emplace_back()`：直接在末尾构造元素（<font color="#31d83b">更加高效</font>）。
```emplace
v.安放
```

```cpp
vector<int> v;
v.push_back(10);    // 添加10
v.push_back(20);    // 添加20
v.emplace_back(30); // 更高效地添加30

for (int i : v) cout << i << " ";  // 输出: 10 20 30
```

>注意类似的python语法 [[CS61A 2.3 Sequences]]
```python
for x in list:
	......
[F(x) for x in list if <filter_statement>]
```
#### 2.3 **访问元素**

- `[]` 运算符：通过索引访问元素（无边界检查）。
- `at()`：通过==索引访问元素==（有边界检查）。
- `front()`：访问第一个元素。
- `back()`：访问最后一个元素。

```cpp
vector<int> v = {1, 2, 3, 4, 5};

cout << v[0] << endl;       // 输出: 1
cout << v.at(2) << endl;    // 输出: 3
cout << v.front() << endl;  // 输出: 1
cout << v.back() << endl;   // 输出: 5
```

#### 2.4 **修改元素**

- 直接通过索引或`at()`方法修改元素。

```cpp
vector<int> v = {1, 2, 3, 4, 5};
v[2] = 10;  // 修改第三个元素为10
v.at(4) = 20;  // 修改第五个元素为20

for (int i : v) cout << i << " ";  // 输出: 1 2 10 4 20
```

#### 2.5 **删除元素**

- `pop_back()`：删除末尾的元素。
- `erase()`：删除*指定位置*的元素。
- `clear()`：<font color="#ffff00">清空所有</font>元素。
[[C++ memset 功能用法]]

```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.pop_back();  // 删除末尾元素
v.erase(v.begin());  // 删除第一个元素
v.clear();  // 清空所有元素

cout << "Size after clear: " << v.size() << endl;  // 输出: Size after clear: 0
```

#### 2.6 **<font color="#ffff00">插入元素</font>**

- `insert()`：在指定位置插入元素。

```cpp
vector<int> v = {1, 2, 4, 5};
v.insert(v.begin() + 2, 3);  // 在第三个位置插入3

for (int i : v) cout << i << " ";  // 输出: 1 2 3 4 5
```

#### 2.7 **容量操作**

- `size()`：返回当前元素个数。
- `capacity()`：返回当前分配的内存大小（容量）。
- `empty()`：*检查* `vector`是否为空。
- `resize()`：改变`vector`的大小。
- `reserve()`：增加容量，<font color="#ffff00">以容纳更多元素而不重新分配内存</font>。注意, 是不重新分配, 不是不分配

```cpp
vector<int> v = {1, 2, 3};
cout << "Size: " << v.size() << endl;       // 输出: Size: 3
cout << "Capacity: " << v.capacity() << endl; // 输出: Capacity: 3

v.reserve(10);  // 将容量增加到至少10
cout << "Capacity after reserve: " << v.capacity() << endl; // 输出: Capacity after reserve: 10

v.resize(5, 0);  // 调整大小为5，新增元素用0填充
for (int i : v) cout << i << " ";  // 输出: 1 2 3 0 0
```

#### 2.8 **迭代器操作**

`vector`支持标准的迭代器，可以使用迭代器遍历元素。

```cpp
vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";  // 输出: 1 2 3 4 5
}
cout << endl;
```
[[C++ STL iterator auto]]
### 3. **高级用法**

#### 3.1 **拷贝与赋值**

- 使用`=`运算符进行拷贝。
- 使用`assign()`方法重新赋值。

```cpp
vector<int> v = {1, 2, 3};
vector<int> v_copy = v;  // 拷贝
vector<int> v_assign;
v_assign.assign({4, 5, 6});  // 使用assign重新赋值

for (int i : v_copy) cout << i << " ";   // 输出: 1 2 3
cout << endl;
for (int i : v_assign) cout << i << " ";  // 输出: 4 5 6
```

#### 3.2 **排序与查找**

- `sort()`：对`vector`进行排序。
- `find()`：查找元素。
- `binary_search()`：二分查找。

```cpp
#include <algorithm>  // For sort, find, binary_search
vector<int> v = {4, 2, 3, 1, 5};

sort(v.begin(), v.end());  // 排序
for (int i : v) cout << i << " ";  // 输出: 1 2 3 4 5

auto it = find(v.begin(), v.end(), 3);  // 查找3
if (it != v.end()) cout << "Found 3!" << endl;

bool found = binary_search(v.begin(), v.end(), 4);  // 二分查找4
if (found) cout << "Found 4!" << endl;
```
> 关于 `end()`, 参见 [[C++ Lib Algorithm]]
### 4. **性能**

- **时间复杂度**：
    - `push_back()`, `emplace_back()`: 平均时间复杂度O(1)，但在重新分配内存时是O(n)。
    - `insert()`, `erase()`: 时间复杂度O(n)，因为需要移动元素。
    - `at()`, `[]`: 时间复杂度O(1)。
    - `sort()`: 时间复杂度O(n log n)。
- **空间复杂度**：`vector`的空间复杂度与其当前的容量（而非元素数量）相关。

### 5. **常见注意点**

- **性能优化**：使用`reserve()`避免频繁的内存重新分配，尤其是当你大致知道`vector`的大小时。
- **动态增长**：`vector`会根据需要自动调整大小，但在有大量元素时，可能会造成不必要的内存分配。使用`reserve()`方法可以减少这类性能开销。

### 总结

C++的`vector`是一种非常灵活和高效的数据结构，适用于大多数动态数组的场景。它提供了许多功能，如动态扩展、快速随机访问、以及丰富的成员函数，能有效处理常见的数据存储和操作需求。

---

在 C++ 中，`vector` 是一个动态数组容器，它可以通过嵌套的方式来模拟多维数组。声明和使用多维 `vector` 有一些灵活性和注意事项。以下是关于如何声明和操作 C++ 中多维 `vector` 的详细说明。

### 1. **声明多维 `vector`**

多维 `vector` 可以通过嵌套 `vector` 来实现，常见的方式有两种：

#### 1.1. **二维 `vector`**

假设你需要声明一个二维 `vector`，即一个具有 `m` 行和 `n` 列的矩阵：

```cpp
#include <vector>
using namespace std;

int main() {
    int m = 3, n = 4;
    vector<vector<int>> matrix(m, vector<int>(n));
    // 或者
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
}
```

- 第一种声明方式 `vector<vector<int>> matrix(m, vector<int>(n))` 初始化一个 3x4 的矩阵，所有元素默认为 `0`。
- 第二种方式通过初始化列表创建一个 3x3 的矩阵，`{1, 2, 3}, {4, 5, 6}, {7, 8, 9}` 是具体的元素。

#### 1.2. **三维 `vector`**

如果你需要声明一个三维数组，可以继续嵌套 `vector`：

```cpp
int x = 2, y = 3, z = 4;
vector<vector<vector<int>>> tensor(x, vector<vector<int>>(y, vector<int>(z)));
```

这种方式声明了一个 2x3x4 的三维 `vector`，所有元素默认初始化为 `0`。

### 2. **操作方法**

#### 2.1. **访问元素**

访问二维 `vector` 中的元素可以使用两个索引：

```cpp
matrix[i][j] = 10; // 设置第 i 行，第 j 列的元素为 10
int value = matrix[i][j]; // 获取第 i 行，第 j 列的元素
```

对于三维 `vector`，同理：

```cpp
tensor[i][j][k] = 5; // 设置 tensor[i][j][k] 的值为 5
```

#### 2.2. **添加新行或新列**

`vector` 的动态特性使得我们可以在运行时调整其大小。

- **添加新行：**

```cpp
matrix.push_back(vector<int>(n, 0)); // 在二维 `vector` 的末尾添加一个全为 0 的新行
```

- **添加新列：**

如果想要给已有的每一行添加新列，可以遍历每一行并使用 `push_back`：

```cpp
for (int i = 0; i < m; i++) {
    matrix[i].push_back(0); // 给第 i 行添加一个新的元素
}
```

#### 2.3. **调整大小**

使用 `resize` 方法可以调整 `vector` 的大小。

```cpp
matrix.resize(m_new); // 调整行数
for (int i = 0; i < m_new; i++) {
    matrix[i].resize(n_new); // 调整每一行的列数
}
```

### 3. **注意事项**

- **内存分配**：`vector` 会根据需要自动扩展，但在你预计会有大量元素时，使用 `reserve()` 可以提前为 `vector` 分配足够的内存，避免重复扩展时的性能损耗。

```cpp
matrix.reserve(m);  // 预留内存，避免后续多次分配
```

- **访问速度**：`vector` 提供了 O(1) 的随机访问，但由于是动态内存分配，连续访问可能比静态数组略慢一些。
    
- **初始化**：二维及多维 `vector` 初始化时，如果某一维没有显式初始化，C++ 会自动初始化为默认值。例如，`int` 默认初始化为 `0`，`string` 默认初始化为空字符串。
    
- **边界检查**：C++ `vector` 提供了 `at()` 方法，这比直接使用 `[]` 访问更加安全，因为 `at()` 会检查边界并抛出异常。
    
    ```cpp
    try {
        int value = matrix.at(i).at(j); // 安全访问
    } catch (const out_of_range& e) {
        cout << "Index out of range!" << endl;
    }
    ```
    

### 4. **总结**

- **声明**：使用嵌套 `vector` 来实现多维数组。
- **访问**：可以通过索引访问元素，支持动态调整大小。
- **性能**：`vector` 是动态的，能根据需要扩展，适合在运行时处理大小不确定的数据结构。

希望这些信息能帮助你更好地理解 C++ 中的多维 `vector`！如果有其他问题，随时问我！

# 一个三维案例

```cpp
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    int cut_times = 0;
    cin >> cut_times;
    // using vector to create a 3D array, with length, width
    // and height, corresponding to w, x and h.
    vector<vector<vector<int>>> cube(w, vector<vector<int>>\
    (x, vector<int>(h, 1)));
    // Let's offer a explanation for this expression
    // vector<vector<vector<int>>> cube(w, vector<vector<int>>\
    // (x, vector<int>(h, 1)));
    // The first vector<> means that we are creating a vector
    // with w elements, each element is a vector<vector<int>>.
    // The second vector<> means that we are creating a vector
    // with x elements, each element is a vector<int>.
    // The third vector<> means that we are creating a vector
    // with h elements, each element is an int.
    // The last 1 means that we are initializing all the elements
    // in the 3D array to 1.
    for (int i = 0; i < cut_times; i++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                for (int k = z1; k <= z2; k++)
                {
                    cube[i][j][k] = 0;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < h; k++)
            {
                if (cube[i][j][k] == 1)
                {
                    count += 1;
                }
            }
        }
    }
    cout << count;
    return 0;
}
```