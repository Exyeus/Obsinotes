在C语言和C++中，动态分配数组的方式略有不同，但原理上是相似的。

### 1. **C语言中动态分配数组**

C语言使用`malloc`、`calloc`、`realloc`等函数来进行内存分配。

#### **一维数组的动态分配**

```c
int *arr = (int*)malloc(n * sizeof(int)); // n是数组的元素个数
if (arr == NULL) {
    // 处理内存分配失败
}
```

#### **二维数组的动态分配**

动态分配二维数组时，可以使用一行代码来实现。我们通常使用**指针数组**或**一维数组模拟二维数组**来达到目的。这样做的好处是内存连续，访问起来比较方便。

```c
int (*arr)[m] = (int(*)[m])malloc(n * m * sizeof(int));
```

这里：

- `arr` 是一个指向 `n` 行、`m` 列二维数组的指针。
- `malloc(n * m * sizeof(int))` 分配了 `n * m` 个 `int` 类型的空间。
- 通过强制类型转换 `(int(*)[m])`，让 `arr` 成为一个指向每行 `m` 个整数的数组的指针。

#### **释放内存**

```c
free(arr);
```

### 2. **C++中动态分配数组**

C++支持`new`和`delete`操作符来进行内存分配和释放。其语法更简洁且类型安全。

#### **一维数组的动态分配**

```cpp
int* arr = new int[n]; // n是数组的元素个数
// 使用数组 arr...
delete[] arr; // 释放内存
```

#### **二维数组的动态分配**

在C++中，我们也可以使用 `new` 来分配二维数组。在C++中，类似的实现通常使用指向指针的指针，或者使用 `new` 来分配二维数组的内存。

```cpp
int** arr = new int*[n];  // 分配指针数组
for (int i = 0; i < n; ++i) {
    arr[i] = new int[m];  // 每个指针指向一行
}
// 使用二维数组 arr...
for (int i = 0; i < n; ++i) {
    delete[] arr[i];  // 释放每行内存
}
delete[] arr;  // 释放指针数组
```

#### **使用一行代码定义二维数组**

可以使用 `new` 来模拟一维数组为二维数组的内存结构，代码如下：

```cpp
int (*arr)[m] = new int[n][m]; // n行m列的二维数组
// 使用二维数组 arr...
delete[] arr; // 释放内存
```

这里 `arr` 是指向 `n` 行 `m` 列二维数组的指针，通过 `new` 来动态分配内存。

### 总结

- **C语言**通过 `malloc` 来分配内存，二维数组通常使用一维数组模拟。
- **C++**通过 `new` 来进行动态内存分配，语法上比C语言更简洁，且更安全。