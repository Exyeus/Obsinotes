---
sr-due: 2025-09-15
sr-interval: 154
sr-ease: 290
---

#review 

`std::pair` 是 C++ 标准库中的一个模板类，用于存储一对相关的数据元素，通常用来表示键值对。它位于 `<utility>` 头文件中。它是一个非常简单的容器类，其结构体中包含两个成员：`first` 和 `second`。

### 使用方法

1. **定义和初始化 `pair`**：
    
    - 创建一个 `pair` 对象，可以通过默认构造、拷贝构造或直接初始化两元素：
        
        ```cpp
        #include <iostream>
        #include <utility>
        
        int main() {
            // 默认构造
            std::pair<int, std::string> p1;
            p1.first = 10;
            p1.second = "hello";
            std::cout << p1.first << ", " << p1.second << std::endl;
        
            // 使用构造函数初始化
            std::pair<int, std::string> p2(20, "world");
            std::cout << p2.first << ", " << p2.second << std::endl;
        
            // 使用 make_pair 创建
            auto p3 = std::make_pair(30, "C++");
            std::cout << p3.first << ", " << p3.second << std::endl;
        
            return 0;
        }
        ```
        
2. **访问 `pair` 元素**： 通过 `.first` 和 `.second` 可以访问 `pair` 的两个元素。
    
    ```cpp
    std::pair<int, std::string> p = {1, "example"};
    std::cout << p.first << ", " << p.second << std::endl;
    ```
    
3. **`make_pair`**： `std::make_pair` 是一种创建 `pair` 的简便方法，它可以自动推导出类型，不需要显式指定类型：
    
    ```cpp
    auto p = std::make_pair(1, "example");
    ```
    

### 应用场景

1. **键值对（Map 和 Set）**： `pair` 最常用于表示键值对，尤其在关联容器如 `std::map` 和 `std::unordered_map` 中，它们存储的是 `pair` 类型的元素，其中 `first` 是键，`second` 是值。
    
    ```cpp
    std::map<int, std::string> m;
    m[1] = "one";
    m[2] = "two";
    for (const auto& [key, value] : m) {
        std::cout << key << ": " << value << std::endl;
    }
    ```
    
2. **多返回值**： `pair` 常用于函数返回多个值，尤其是返回两个相关的值。`std::tuple` 可以返回更多的值，但 `pair` 足够处理两者之间的情况。
    
    ```cpp
    std::pair<int, int> divide(int a, int b) {
        return {a / b, a % b};
    }
    auto result = divide(10, 3);
    std::cout << "quotient: " << result.first << ", remainder: " << result.second << std::endl;
    ```
    
3. **在算法中作为中间结果**： `pair` 可以用于许多算法中，作为存储中间状态或结果的简单容器。例如，`std::minmax` 可以返回一个 `pair`，表示最小值和最大值：
    
    ```cpp
    auto result = std::minmax(3, 7);
    std::cout << "min: " << result.first << ", max: " << result.second << std::endl;
    ```
    
4. **组合数据**： 通过 `pair` 可以将两个不相关的元素组合在一起，如在图算法中，`pair` 可以表示边的两个端点：
    
    ```cpp
    std::pair<int, int> edge = {1, 2};  // 图的边，1 和 2 是端点
    ```
    

### 可用操作

1. **比较操作**： `pair` 支持常见的比较操作，如 `==`、`!=`、`<`、`>`、`<=`、`>=`。比较是*按 `first` 和 `second` 元素的顺序进行*的：
    
    ```cpp
    std::pair<int, std::string> p1 = {1, "apple"};
    std::pair<int, std::string> p2 = {1, "banana"};
    if (p1 < p2) {
        std::cout << "p1 is less than p2" << std::endl;
    }
    ```
    
2. **交换内容**： `pair` 提供了一个 `swap` 成员函数来交换 `first` 和 `second` 元素的值：
    
    ```cpp
    std::pair<int, std::string> p1 = {1, "apple"};
    std::pair<int, std::string> p2 = {2, "banana"};
    p1.swap(p2);
    std::cout << p1.first << ", " << p1.second << std::endl;
    std::cout << p2.first << ", " << p2.second << std::endl;
    ```
    
3. **标准库支持**： `pair` 可以与标准库算法一起使用，例如排序和查找：
    
    ```cpp
    std::vector<std::pair<int, std::string>> v = {{3, "c"}, {1, "a"}, {2, "b"}};
    std::sort(v.begin(), v.end());
    for (const auto& p : v) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    ```
    

### 使用细节

1. **类型推导**： 使用 `std::make_pair` 时，编译器会自动推导出类型，但如果直接使用构造函数创建 `pair`，需要显式指定两个元素的类型。
    
2. **避免不必要的拷贝**： 对 `pair` 进行操作时，尽量通过引用来避免不必要的拷贝。例如，在传递 `pair` 给函数时，尽量传递 `const pair&`，而不是直接传值。
    
3. **保持一致的类型**： `pair` 的两个元素类型是固定的，所以确保其两者类型的使用是合理的。例如，不能在同一个 `pair` 中混用不同的类型，如果确实需要多类型数据，考虑使用 `std::tuple`。
    
4. **标准库 `pair` 与 C++11 之后的增强**： C++11 引入了*结构化绑定声明*，可以简化对 `pair` 的解包：
    
    ```cpp
    auto [key, value] = std::make_pair(10, "hello");
    std::cout << key << ": " << value << std::endl;
    ```
> Pair 为什么要用 `[key, value]` 来这样做？直接用两个变量是否可行？

5. **`pair` 的顺序比较**： `pair` 比较的顺序是首先比较 `first` 元素，如果 `first` 元素相等，则比较 `second` 元素。如果需要根据自定义规则进行比较，可能需要重载 `<` 运算符。
    

总之，`std::pair` 是一个功能简单但非常有用的容器，它可以在多种场景下帮助存储一对相关的值，简化代码结构。