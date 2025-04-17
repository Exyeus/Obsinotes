### **1. `strncmp` 函数原型**

`strncmp` 是 C 标准库中用于比较字符串的函数，它通过逐字符比较两个字符串的前 n 个字符，判断它们是否相等。

函数原型：

```c
int strncmp(const char *str1, const char *str2, size_t n);
```

---
### **2. 参数详解**

- **`const char *str1`**: 第一个字符串的指针（只读）。
- **`const char *str2`**: 第二个字符串的指针（只读）。
- **`size_t n`**: 比较的字符数。

---

### **3. 返回值**

- **`0`**：两字符串的前 n 个字符相等。
- **正值**：`str1` 中出现的第一个不同字符大于 `str2` 中对应字符。
- **负值**：`str1` 中出现的第一个不同字符小于 `str2` 中对应字符。

---

### **4. 参数传递方式**

- **字符串指针传递方式：**
    - `const char *` 表明字符串是只读的，`strncmp` 不会修改字符串的内容。
    - 调用时可直接传入字符串字面量、数组或指针变量。
- **`n` 的传递方式：**
    - 以值传递的形式，指定需要比较的字符数量。

---

### **5. `strncmp` 的实现原理**

`strncmp` 按照以下规则逐字符比较两个字符串：

1. 从起始地址开始逐字符比较。
2. 如果字符相等，继续比较下一字符，直到达到字符数限制 `n`，或遇到字符串的终止符 `\0`。
3. 如果在 `n` 个字符内找到第一个不同字符，则根据字符 ASCII 值返回差值。

等价实现代码：

```c
int strncmp(const char *str1, const char *str2, size_t n) {
    while (n--) {
        if (*str1 != *str2 || *str1 == '\0' || *str2 == '\0') {
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
    }
    return 0;
}
```

---

### **6. 使用 `strncmp` 比较字符串特定部分**

#### **6.1 比较前 n 个字符**

只需要将字符串的起始地址直接传入，并设置需要比较的字符数 `n`。

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abcdef";
    char str2[] = "abcxyz";

    if (strncmp(str1, str2, 3) == 0) {
        printf("The first 3 characters are the same.\n");
    } else {
        printf("The first 3 characters are different.\n");
    }

    return 0;
}
```

**结果：** 输出 `The first 3 characters are the same.`。

---

#### **6.2 比较后 n 个字符**

通过偏移字符串的起始地址（指针偏移），定位到需要比较的部分。

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abcdef";
    char str2[] = "xyzdef";

    // 偏移到字符串的最后 n 个字符
    if (strncmp(str1 + 3, str2 + 3, 3) == 0) {
        printf("The last 3 characters are the same.\n");
    } else {
        printf("The last 3 characters are different.\n");
    }

    return 0;
}
```

**结果：** 输出 `The last 3 characters are the same.`。

---

#### **6.3 比较中间的 n 个字符**

通过调整字符串的起始地址，定位到需要比较的中间部分。

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "123abcdef456";
    char str2[] = "789abcdef000";

    // 偏移到中间部分
    if (strncmp(str1 + 3, str2 + 3, 6) == 0) {
        printf("The middle 6 characters are the same.\n");
    } else {
        printf("The middle 6 characters are different.\n");
    }

    return 0;
}
```

**结果：** 输出 `The middle 6 characters are the same.`。

---

### **7. 使用注意事项**

1. **`n` 的值不超过较短字符串的长度：** 如果 `n` 大于某个字符串的长度，但另一个字符串的 `n` 范围内有字符，会导致比较结果受影响。
    
    ```c
    char str1[] = "abc";
    char str2[] = "abcdef";
    printf("%d\n", strncmp(str1, str2, 6)); // 返回负值，因为 str1 短于 str2。
    ```
    
2. **字符比较基于 ASCII 值：** `strncmp` 按字符的 ASCII 值进行比较，大小写敏感。
    
    ```c
    char str1[] = "abc";
    char str2[] = "ABC";
    printf("%d\n", strncmp(str1, str2, 3)); // 返回正值，因为 'a' > 'A'。
    ```
    
3. **空指针检查：** 在使用 `strncmp` 前确保传入的字符串指针不是 `NULL`，否则会导致运行时错误。
    

---

### **8. 总结**

- **`strncmp` 是一种安全、灵活的字符串比较工具，适用于部分字符串的比较场景。**
- 可通过字符串起始地址偏移实现对特定部分（前、中、后）的比较。
- 注意字符串终止符 `\0` 和比较字符数 `n` 的关系，以避免意外结果。