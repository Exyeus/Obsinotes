---
sr-due: 2025-09-24
sr-interval: 168
sr-ease: 294
---

#review 

C++11 对 `algorithm` 库进行了许多扩展和增强，尤其是在与 Lambda 表达式、并行算法等方面的结合上。`algorithm` 库包含了大量常见的算法操作，主要用于操作序列（如数组、容器等），例如排序、查找、比较、变换、聚合等。接下来我将详细介绍 C++11 `algorithm` 库中的一些常见功能，并结合代码示例进行说明。

### 1. **`std::sort`：排序**
`std::sort` 用于对容器或数组中的元素进行排序。C++11 引入了 **Lambda 表达式**，使得在排序中指定自定义比较函数变得更加简洁。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 3, 8, 1, 2};

    // 升序排序
    sort(v.begin(), v.end());
    cout << "升序排序: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // 使用 Lambda 表达式进行降序排序
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    
    ** extra lambda exp make the descending sort
    ** seeming that all lans share the tradition of setting ascending
    ** sort as their default option
    cout << "降序排序: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
```

>An analogy. In python, similar code: `iterable = sorted(iterable, key=f, reverse = BOOLEAN)`. But in C this sequence is fixed, so the sorting only relys on the *lambda function*.
>In C++: If true, then put you at the front !

**输出：**
```
升序排序: 1 2 3 5 8 
降序排序: 8 5 3 2 1
```
- **分析：**
  - `std::sort(v.begin(), v.end())` 默认按升序排列。
  - 使用 **Lambda 表达式** `[](int a, int b) { return a > b; }` 定义了自定义的降序排序。

### 2. **`std::find`：查找元素**
`std::find` 用于在序列中查找第一个匹配的元素。如果找到了元素，返回其迭代器，否则返回序列的<font color="#ffff00">末尾迭代器</font>。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    
    auto it = find(v.begin(), v.end(), 30);
    if (it != v.end()) {
        cout << "找到元素: " << *it << endl;
// what if *it - v.begin() - 1; to return the index of array language
    } else {
        cout << "元素未找到" << endl;
    }

    return 0;
}
```
**输出：**
```
找到元素: 30
```
- **分析：** 
  - `std::find(v.begin(), v.end(), 30)` 查找值为 `30` 的元素。
  - 如果找到了，`it` 将是指向该元素的迭代器，否则 `it` 将是 `v.end()`。

### 3. **`std::accumulate`：累加**
`std::accumulate` 用于对<font color="#ffff00">序列中的元素进行累加</font>。可以传入一个初始值，以及一个二元操作函数（如加法）。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // 使用默认加法操作进行累加
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "累加和: " << sum << endl;

    // 使用 Lambda 表达式计算累积积
    int product = accumulate(v.begin(), v.end(), 1, [](int a, int b) {
        return a * b;
    });
    cout << "累积积: " << product << endl;

    return 0;
}
```
**输出：**
```
累加和: 15
累积积: 120
```
- **分析：**
  - `std::accumulate(v.begin(), v.end(), 0)` 默认使用加法运算对容器中的元素进行累加。
  - 使用 **Lambda 表达式** `[](int a, int b) { return a * b; }` 替代默认的加法操作，从而计算积。

### 4. **`std::count`：计数**
`std::count` 用于计算序列中某个元素的出现次数。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 3, 2, 4};

    // 计算数字2出现的次数
    int count_2 = count(v.begin(), v.end(), 2);
    cout << "数字2出现的次数: " << count_2 << endl;

    return 0;
}
```
**输出：**
```
数字2出现的次数: 3
```
- **分析：**
  - `std::count(v.begin(), v.end(), 2)` 返回元素 `2` 在容器中的出现次数。

### 5. **`std::reverse`：反转序列**
`std::reverse` 用于反转序列中的元素。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // 反转容器
    reverse(v.begin(), v.end());
    cout << "反转后的容器: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
```
**输出：**
```
反转后的容器: 5 4 3 2 1
```
- **分析：**
  - `std::reverse(v.begin(), v.end())` 将容器中的元素顺序反转。

### 6. **`std::for_each`：对每个元素执行操作**
`std::for_each` 对容器中的每个元素执行指定的操作，可以*结合 Lambda 表达式来进行*。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // 使用 Lambda 表达式打印每个元素
    for_each(v.begin(), v.end(), [](int num) {
        cout << num << " ";
    });
    cout << endl;

    return 0;
}
```
**输出：**
```
1 2 3 4 5
```
- **分析：**
  - `std::for_each(v.begin(), v.end(), [](int num) { cout << num << " "; })` 对容器中的每个元素执行打印操作。

### 7. **`std::remove` 和 `std::remove_if`：移除元素**
`std::remove` 用于移除指定值的元素，而 `std::remove_if` 根据给定的条件移除元素。注意，`std::remove` 并<font color="#ffff00">不真正删除元素，而是将它们移到序列的末尾，返回一个新的逻辑末尾迭代器</font>。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 2, 6};

    // 移除值为2的元素
    v.erase(remove(v.begin(), v.end(), 2), v.end());
    cout << "移除2后的容器: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    return 0;
}
```
**输出：**
```
移除2后的容器: 1 3 4 5 6
```
- **分析：**
  - `std::remove(v.begin(), v.end(), 2)` 会将所有值为 `2` 的元素移到容器的末尾，并返回新的逻辑末尾迭代器，`erase` 会将这些元素从容器中删除。

### 8. **`std::min_element` 和 `std::max_element`：查找最小/最大元素**
`std::min_element` 和 `std::max_element` 用于查找序列中的最小和最大元素。

**示例：**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {10, 20, 5, 15, 30};

    auto min_it = min_element(v.begin(), v.end());
    auto max_it = max_element(v.begin(), v.end());

    cout << "最小元素: " << *min_it << endl;
    cout << "最大元素: " << *max_it << endl;

    return 0;
}
```
**输出：**
```
最小元素: 5
最大元素: 30
```
- **分析：**
  - `std::min_element(v.begin(), v.end())` 返回指向