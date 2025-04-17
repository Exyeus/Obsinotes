C++ 中 `std::string` 类的 `find_last_not_of` 函数用于查找字符串中最后一个不属于指定字符集的位置。它从字符串的末尾开始查找，直到找到一个不属于指定字符集的字符为止。这个函数非常有用，特别是在去除字符串中的尾部空白字符或特定字符时。

### **函数原型**

```cpp
size_t find_last_not_of(const std::string& str, size_t pos = npos) const;
size_t find_last_not_of(const char* s, size_t pos = npos) const;
size_t find_last_not_of(char c, size_t pos = npos) const;
```

### **参数**

- **`str`**: 一个字符串，表示要查找的字符集。`find_last_not_of` 会查找字符串中最后一个不属于这个字符集的字符。
- **`s`**: 一个 C 风格的字符串，表示要查找的字符集。
- **`c`**: 一个单个字符，表示要查找的字符集。
- **`pos`**: 可选参数，指定开始查找的位置，默认为 `std::string::`[[npos]]，表示从字符串的末尾开始查找。

### **返回值**

- 返回字符串中最后一个不属于指定字符集的字符的索引（位置）。
- 如果没有找到符合条件的字符，返回 `std::string::npos`（即 `-1`）。

### **用法**

1. **查找最后一个不属于指定字符集的字符**
    
    - 当你希望找到从字符串末尾开始，最后一个不在某个字符集中的字符时，使用 `find_last_not_of`。
2. **常见应用**：
    
    - 去除字符串末尾的空白字符。
    - 查找特定字符集的最后一个非匹配字符。

### **例子**

#### 1. **查找最后一个不属于特定字符集的字符**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "hello world   ";
    
    // 查找最后一个不属于空格字符的字符的位置
    size_t pos = str.find_last_not_of(' '); // 查找最后一个不是空格的字符
    
    if (pos != std::string::npos) {
        std::cout << "Last non-space character is at index: " << pos << std::endl;
        std::cout << "Character: " << str[pos] << std::endl;
    } else {
        std::cout << "No non-space character found!" << std::endl;
    }
    
    return 0;
}
```

**输出：**

```
Last non-space character is at index: 10
Character: d
```

#### 2. **查找最后一个不属于多个字符集的字符**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "abc123xyz!";
    
    // 查找最后一个不属于 'abc123' 字符集的字符
    size_t pos = str.find_last_not_of("abc123"); // 查找最后一个不是 'a', 'b', 'c', '1', '2', '3' 的字符
    
    if (pos != std::string::npos) {
        std::cout << "Last non-'abc123' character is at index: " << pos << std::endl;
        std::cout << "Character: " << str[pos] << std::endl;
    } else {
        std::cout << "No matching character found!" << std::endl;
    }
    
    return 0;
}
```

**输出：**

```
Last non-'abc123' character is at index: 9
Character: !
```

#### 3. **使用 `npos` 查找从末尾开始的字符**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "****test****";
    
    // 查找最后一个不属于 '*' 字符的字符
    size_t pos = str.find_last_not_of('*');
    
    if (pos != std::string::npos) {
        std::cout << "Last non-'*' character is at index: " << pos << std::endl;
        std::cout << "Character: " << str[pos] << std::endl;
    } else {
        std::cout << "No non-'*' character found!" << std::endl;
    }
    
    return 0;
}
```

**输出：**

```
Last non-'*' character is at index: 4
Character: t
```

#### 4. **查找最后一个不属于字符集合的字符（使用 `find_last_not_of` 与 `std::string` 组合）**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str = "abcxyzabc";
    
    // 查找最后一个不属于 'abc' 字符集的字符
    size_t pos = str.find_last_not_of("abc");
    
    if (pos != std::string::npos) {
        std::cout << "Last non-'abc' character is at index: " << pos << std::endl;
        std::cout << "Character: " << str[pos] << std::endl;
    } else {
        std::cout << "No matching character found!" << std::endl;
    }
    
    return 0;
}
```

**输出：**

```
Last non-'abc' character is at index: 5
Character: x
```

### **总结**

- `find_last_not_of` 函数从字符串的末尾开始查找，并返回最后一个不属于给定字符集的位置。
- 可以使用单个字符、字符串或 C 风格的字符数组作为查找目标字符集。
- 如果没有找到符合条件的字符，函数返回 `std::string::npos`。

这种查找方式通常用于去除字符串末尾的空格或指定字符，或者需要在字符串末尾进行特定字符集的排除操作时。