---
sr-due: 2025-09-27
sr-interval: 166
sr-ease: 250
---

#review 

# 浮点数专用
在C++中，`cout` 用于输出数据，特别是浮点数时，默认的输出精度可能不是你想要的。幸运的是，C++ 提供了多种方法来控制浮点数输出的精度和格式。下面将介绍几种常见的设置精度和格式的方法，以及如何恢复为默认格式。

### 1. **`setprecision` 控制输出精度**

`setprecision` 是 `<iomanip>` <font color="#ffff00">头文件中</font>提供的一个流控制操作符，用于设置浮点数的输出精度（即小数点后面的位数）。它影响所有后续的浮点数输出。

- `setprecision(n)`：设置输出数字的精度为 `n` 位，`n` 是一个整数，表示输出浮点数的小数位数。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979;

    std::cout << "Default precision: " << num << std::endl;

    // 设置精度为 4 位小数
    std::cout << std::fixed << std::setprecision(4) << num << std::endl;  // 输出 3.1416

    // 设置精度为 6 位小数
    std::cout << std::setprecision(6) << num << std::endl;  // 输出 3.14159

    return 0;
}
```

**注意：**

- `std::setprecision(n)` 影响输出的总位数（包括整数部分和小数部分），而不仅仅是小数部分。
- 如果与 `std::fixed` 或 `std::scientific` 一起使用，`setprecision` 会分别设置小数位数和科学计数法的精度。

### 2. **`std::fixed` 设置<font color="#ffffff"><font color="#31d83b"><span style="background:#9254de">定点输出格式</span></font></font>**

`std::fixed` 是一个流控制符，用于控制浮点数的输出格式，使得浮点数以定点格式输出（即固定小数位数）。与 `setprecision` 一起使用时，可以控制小数点后的位数。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979;

    // 设置固定小数点格式，精度为 4 位
    std::cout << std::fixed << std::setprecision(4) << num << std::endl;  // 输出 3.1416
    std::cout << std::fixed << std::setprecision(6) << num << std::endl;  // 输出 3.141593

    return 0;
}
```

### 3. **`std::scientific` 设置科学计数法输出格式**

`std::scientific` 用于将浮点数以科学计数法的形式输出。如果需要以<font color="#ffff00">科学计数法显示浮动小数，可以使用此控制符</font>。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 12345.6789;

    // 设置科学计数法格式，精度为 3 位
    std::cout << std::scientific << std::setprecision(3) << num << std::endl;  // 输出 1.235e+04

    return 0;
}
```

### 4. **`std::defaultfloat` <font color="#ffff00"><font color="#b228e6">恢复为默认格式</font></font>**

如果你在程序中使用了 `std::fixed` 或 `std::scientific` 控制符，并希望恢复到默认的格式（即自动<font color="#ffff00">选择定点格式或科学计数法</font>），可以使用 `std::defaultfloat`。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 12345.6789;

    // 设置科学计数法格式
    std::cout << std::scientific << std::setprecision(3) << num << std::endl;  // 输出 1.235e+04

    // 恢复为默认格式
    std::cout << std::defaultfloat << num << std::endl;  // 输出 12345.7

    return 0;
}
```

### 5. **组合使用：设置精度、格式控制和宽度**

你可以将 `setprecision`、`std::fixed`、`std::scientific` 和 `std::setw`（设置输出字段宽度）等控制符结合起来使用，以获得更精细的输出控制。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979;

    // 设置为定点格式，精度为 4 位小数
    std::cout << std::fixed << std::setprecision(4) << num << std::endl;  // 输出 3.1416

    // 设置为科学计数法，精度为 6 位
    std::cout << std::scientific << std::setprecision(6) << num << std::endl;  // 输出 3.141593e+00

    // 恢复为默认格式
    std::cout << std::defaultfloat << num << std::endl;  // 输出 3.14159

    // 使用setw设置输出字段宽度为10
    std::cout << std::setw(10) << num << std::endl;  // 输出 " 3.14159"（宽度为10，右对齐）

    return 0;
}
```

### 总结

- **`setprecision(n)`**：设置浮点数输出精度，控制小数点后位数。
- **`std::fixed`**：定点格式输出，使输出固定为小数位。
- **`std::scientific`**：科学计数法格式输出。
- **`std::defaultfloat`**：恢复为默认格式，根据数字大小自动选择定点格式或科学计数法。
- **`std::setw(n)`**：设置输出字段宽度。

这些格式控制符和 `setprecision` 可以帮助你精确控制浮点数的输出方式，适应不同的需求。如果你希望恢复为默认格式，只需使用 `std::defaultfloat`。

# 更广泛的数字输出办法
### 1. 设置输出精度

你可以使用 `setprecision()` 来设置数字的精度（即输出的小数位数）。注意，它只影响浮点数的输出。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979;
    std::cout << std::fixed << std::setprecision(2) << num << std::endl;  // 输出 3.14
    std::cout << std::scientific << std::setprecision(3) << num << std::endl;  // 输出 3.142e+00
    return 0;
}
```

- `std::fixed`：使用固定小数点表示法。
- `std::scientific`：使用科学计数法表示。
- `std::setprecision()`：设置精度。

### 2. 设置输出宽度

你可以使用 `setw()` 来设置输出的宽度。如果<font color="#6425d0"><font color="#31d83b">输出的内容少于指定宽度，默认会用空格填充。如果想用其他字符填充，可以使用</font> </font>`setfill()`。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num = 42;
    std::cout << std::setw(6) << num << std::endl;  // 输出 "    42"，宽度为6，空格填充

    std::cout << std::setw(6) << std::setfill('0') << num << std::endl;  // 输出 "000042"，使用'0'填充
    return 0;
}
```

- `std::setw(n)`：设置输出宽度为 `n`。
- `std::setfill(c)`：设置填充字符为 `c`，默认为空格。

### 3. 设置对齐方式

默认情况下，`cout` 右对齐数字，左对齐字符串。你可以使用 `std::left` 和 `std::right` 来<font color="#31d83b">改变对齐方式</font>。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num = 42;
    std::cout << std::left << std::setw(6) << num << std::endl;   // 左对齐
    std::cout << std::right << std::setw(6) << num << std::endl;  // 右对齐
    return 0;
}
```

- `std::left`：左对齐。
- `std::right`：右对齐。

### 4. 输出带符号数字

你可以使用 `showpos` 来显示正数的符号（`+`）。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num1 = 42, num2 = -42;
    std::cout << std::showpos << num1 << std::endl;  // 输出 +42
    std::cout << num2 << std::endl;                  // 输出 -42
    return 0;
}
```

- `std::showpos`：输出正数时显示 `+` 符号。
- `std::noshowpos`：取消显示正数符号。

### 5. 输出十六进制、八进制、二进制

可以通过 `std::hex`, `std::oct`, `std::dec` 来分别控制输出为十六进制、八进制或十进制。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num = 255;
    std::cout << std::hex << num << std::endl;  // 输出 ff（十六进制）
    std::cout << std::oct << num << std::endl;  // 输出 377（八进制）
    std::cout << std::dec << num << std::endl;  // 输出 255（十进制）
    return 0;
}
```

- `std::hex`：十六进制输出。
- `std::oct`：八进制输出。
- `std::dec`：十进制输出。

### 6. 使用科学计数法或固定小数点表示法

- 使用 `std::fixed` 或 `std::scientific` 来控制浮点数的输出格式。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 123456.789;
    std::cout << std::fixed << std::setprecision(2) << num << std::endl;      // 固定小数点格式
    std::cout << std::scientific << std::setprecision(2) << num << std::endl;  // 科学计数法
    return 0;
}
```

### 7. 设置宽度和精度同时生效

你可以同时使用 `setw` 和 `setprecision` 来设置宽度和精度，确保输出按要求格式化。

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double num = 3.14159265358979;
    std::cout << std::setw(10) << std::setprecision(3) << num << std::endl;  // 输出 3.14，宽度为10
    return 0;
}
```

### #小结

- `std::setw(n)` 设置宽度。
- `std::setfill(c)` 设置填充字符。
- `std::setprecision(n)` 设置精度。
- `std::fixed` 和 `std::scientific` 控制浮点数输出格式。
- `std::showpos` 显示正数符号。
- `std::hex`, `std::oct`, `std::dec` 控制进制。
- `std::left`, `std::right`, `std::internal` 控制对齐。

这些格式化选项可以组合使用，根据你的需求来调整输出。