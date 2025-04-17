`std::deque` 是 C++ 标准库中的一个容器类，全称是 "double-ended queue"（双端队列）。它是一种可以在两端高效插入和删除元素的序列容器，具有以下特点：

### 特点：

1. **双端访问：**  
    `std::deque` 允许从两端（前端和后端）进行高效的插入和删除操作。这意味着，除了能够像 `std::vector` 一样在末尾插入和删除元素外，还能在队列的前端进行类似的操作。
    
2. **动态数组：**  
    它在内部使用一系列固定大小的数组来存储元素，不像 `std::vector` 那样使用一个单一的连续数组。这使得它能够在两端进行高效的插入和删除，而不需要像 `std::vector` 那样移动大量的元素。
    
3. **随机访问：**  
    `std::deque` 支持通过下标进行随机访问，就像 `std::vector` 一样，允许以常数时间复杂度访问任何元素。
    
4. **内存使用：**  
    `std::deque` 在内存分配上通常比 `std::vector` 更为复杂，因为它在内部维护多个内存块，这使得它在插入或删除操作时可能比 `std::vector` 更高效，但它的内存管理开销相对较大。
    

### 用法示例：

```cpp
#include <iostream>
#include <deque>
#include <vector>

template <typename T, typename CONT = std::vector<T>>
class Stack {
public:
    void push(T value) {
        elements.push_back(value);
    }

    T pop() {
        if (size > 0) {
            T topValue = elements.back();
            elements.pop_back();
            --size;
            return topValue;
        }
        throw std::out_of_range("Stack is empty!");
    }

private:
    CONT elements;
    int size = 0;
};

int main() {
    Stack<int> intStack; // 默认使用 std::vector<int>
    intStack.push(10);
    intStack.push(20);
    std::cout << "Popped value: " << intStack.pop() << std::endl;  // 输出 20

    // 使用 std::deque<double>
    Stack<double, std::deque<double>> dblStack;
    dblStack.push(10.5);
    dblStack.push(20.5);
    std::cout << "Popped value: " << dblStack.pop() << std::endl;  // 输出 20.5

    return 0;
}
```

### 关键点：

1. **`std::deque` 的定义：** `std::deque<T>` 是 C++ STL 提供的一个容器，它支持在容器的两端进行插入和删除操作。相对 `std::vector`，`std::deque` 的插入和删除操作更加高效，尤其是在队列的头部。
    
2. **为什么在模板中使用 `std::deque`：** 在模板类 `Stack` 中，`CONT` 是一个容器类型的模板参数，它的默认值是 `std::vector<T>`，这意味着如果你没有显式指定容器类型，它将默认使用 `std::vector`。但是，你可以显式地选择其他容器类型，例如 `std::deque`，通过指定第二个模板参数来实现。
    
3. **`deque` 适用场景：** `std::deque` 适用于需要频繁在容器的两端进行插入或删除操作的场景。例如，如果你需要从栈的两端都能进行推送和弹出操作，`std::deque` 是一个不错的选择。
    

### 总结：

`std::deque` 是一个支持从两端高效插入和删除的容器，可以作为类模板的容器参数，在类模板实例化时根据需要指定容器类型。如果没有指定，`std::deque` 的默认值会是 `std::vector`，使得 `Stack` 类可以灵活使用不同的容器。