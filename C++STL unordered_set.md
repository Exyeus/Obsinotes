---
sr-due: 2025-09-06
sr-interval: 145
sr-ease: 270
---

#review 

`std::unordered_set` 是 C++ 标准库中的一个容器，提供了存储唯一元素的功能，其底层实现通常使用哈希表。与 `std::set` 不同，`std::unordered_set` 中的元素是无序的，但它提供了更高效的查找、插入和删除操作。

### 1. 基本概念

- **无序性**：`std::unordered_set` 中的元素不按任何特定顺序排列。与 `std::set` 相比，`unordered_set` 的最大特点是它不保持排序。
- **哈希表实现**：`unordered_set` 使用哈希表来管理元素，这使得元素的查找、插入和删除的时间复杂度平均为 O(1)，而在最坏情况下（哈希冲突严重时）为 O(n)。
- **唯一性**：`unordered_set` 中的元素是唯一的，无法插入重复的元素。

### 2. 头文件与命名空间

`unordered_set` 定义在 `<unordered_set>` 头文件中，并且需要使用 `std` 命名空间。

```cpp
#include <unordered_set>
using namespace std;
```

### 3. 创建和初始化

#### 基本创建

可以使用构造函数来创建一个 `unordered_set`。以下是几种常见的初始化方式：

```cpp
unordered_set<int> s;  // 创建一个空的 unordered_set
```

#### 使用初始化列表初始化

你可以通过初始化列表将元素加入 `unordered_set` 中：

```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
```

#### 从其他容器复制

如果你有一个数组或其他容器（如 `vector`），也可以通过复制构造函数初始化：

```cpp
vector<int> v = {1, 2, 3, 4, 5};
unordered_set<int> s(v.begin(), v.end());
```

### 4. 插入元素

使用 `insert` 方法可以向 `unordered_set` 中插入元素。如果插入的元素已存在，则不会插入重复元素。

```cpp
unordered_set<int> s;
s.insert(10);  // 插入 10
s.insert(20);  // 插入 20
s.insert(10);  // 不会插入，因为 10 已存在

// 插入多个元素
s.insert({30, 40, 50});
```

### 5. 查找元素

`unordered_set` 提供了 `find` 方法来查找元素。返回一个迭代器，如果找到元素，则迭代器指向该元素，否则指向 `end()`。

```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
auto it = s.find(3);  // 查找 3
if (it != s.end()) {
    cout << "Found: " << *it << endl;  // 输出 Found: 3
} else {
    cout << "Not found" << endl;
}
```

### 6. 删除元素

删除元素可以使用 `erase` 方法。如果需要删除一个特定的元素，传入该元素的值；如果需要删除某个迭代器位置的元素，可以直接传入该迭代器。

```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
s.erase(3);  // 删除元素 3

// 删除特定位置的元素
auto it = s.find(2);
if (it != s.end()) {
    s.erase(it);  // 删除找到的元素
}
```

#### 删除所有元素

使用 `clear` 方法可以清空 `unordered_set` 中的所有元素。

```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
s.clear();  // 清空所有元素
```

### 7. 大小和检查空

- `size()`：返回容器中元素的个数。
- `empty()`：检查容器是否为空。

```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
cout << "Size: " << s.size() << endl;  // 输出 Size: 5
cout << "Is empty: " << s.empty() << endl;  // 输出 Is empty: 0 (false)
```

### 8. 遍历

`unordered_set` 允许通过迭代器遍历元素。

```cpp
unordered_set<int> s = {1, 2, 3, 4, 5};
for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";  // 输出元素
}
cout << endl;
```

或者使用范围 `for` 循环（C++11 及以上）：

```cpp
for (int x : s) {
    cout << x << " ";  // 输出元素
}
cout << endl;
```

### 9. 哈希函数

`unordered_set` 默认使用 `std::hash` 来计算元素的哈希值。如果你想为自定义类型使用 `unordered_set`，你需要为该类型提供一个哈希函数。

例如，我们使用 `unordered_set` 存储自定义类型 `Point`，需要自定义哈希函数：

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    
    // 为 Point 定义自定义的哈希函数
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 自定义哈希函数
struct PointHash {
    size_t operator()(const Point& p) const {
        return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
    }
};

int main() {
    unordered_set<Point, PointHash> points;
    points.insert(Point(1, 2));
    points.insert(Point(3, 4));
    
    for (const auto& p : points) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
```

### 10. 常用操作总结

|操作|方法|复杂度|
|---|---|---|
|插入元素|`insert(val)`|平均 O(1)|
|查找元素|`find(val)`|平均 O(1)|
|删除元素|`erase(val)`|平均 O(1)|
|删除特定迭代器|`erase(iterator)`|平均 O(1)|
|获取大小|`size()`|O(1)|
|检查是否为空|`empty()`|O(1)|
|清空容器|`clear()`|O(n)|

### 11. 其他注意事项

- **哈希冲突**：如果不同的元素有相同的哈希值，`unordered_set` 需要进行链表或其他方式的处理。虽然大部分情况下哈希值分布均匀，但在极端情况下，哈希冲突可能导致性能下降。
- **无序性**：`unordered_set` 中的元素是无序的，因此如果你需要有序的元素，需要使用 `std::set`。
- **元素必须是可哈希的**：`unordered_set` 需要存储的元素类型能够提供哈希值。对于内置类型，如 `int`、`string`，标准库已经提供了哈希函数。如果是自定义类型，则需要提供自定义的哈希函数。

### 12. 总结

`std::unordered_set` 是一个高效的容器，适用于需要频繁查找、插入和删除元素的场景。其底层是哈希表，提供平均 O(1) 的复杂度，适合处理大量数据。在实际使用中，你可以根据需求灵活选择 `unordered_set` 和 `set`，但需要注意哈希函数的设计和冲突处理。