---
sr-due: 2025-04-10
sr-interval: 37
sr-ease: 290
---

#review
C++中常见的字符串到数值的类型转换函数可分为传统C风格函数和C++11引入的新标准函数，它们在功能、安全性和使用场景上存在显著差异：

### 一、C风格函数（需包含头文件`<cstdlib>`）
1. **atoi**  
   - 功能：C字符串(`char*`) → `int`  
   - 特性：遇到非数字字符停止转换，转换失败返回0，不检查溢出

2. **atol**  
   - 功能：C字符串 → `long`  
   - 特性：与`atoi`类似，返回长整型

3. **atoll** (C++11新增)  
   - 功能：C字符串 → `long long`  
   - 特性：支持更大整数范围

4. **atof**  
   - 功能：C字符串 → `double`  
   - 特性：解析正负号/小数点/指数，失败返回0.0，不抛异常

5. **strtod/strtof/strtold**  
   - 功能：C字符串 → `double/float/long double`  
   - 特性：提供错误指针参数，可检测无效输入，比`atof`更安全

### 二、C++11标准函数（需包含头文件`<string>`）

1. **stoi**  
   - 功能：`std::string` → `int`  
   - 特性：支持进制参数（如二进制、十六进制），转换失败抛出`invalid_argument`或`out_of_range`异常

2. **stol/stoll**  
   - 功能：字符串 → `long/long long`  
   - 特性：与`stoi`类似，支持更大整数范围

3. **stof/stod/stold**  
   - 功能：字符串 → `float/double/long double`  
   - 特性：支持宽字符(`wstring`)，异常机制完善

### 三、注意事项
1. **输入有效性**  
   - C风格函数（如`atoi`）对无效输入（如`"123abc"`）会部分转换，返回截断值；而`stoi`会直接抛出异常

2. **错误处理**  
   - `atof`在溢出时返回未定义值，`stof`会抛`std::out_of_range`；`atof`无法区分"0"和无效输入，`stof`可通过异常明确错误类型

3. **类型兼容性**  
   - C风格函数仅支持`char*`，需确保字符串以`\0`结尾；C++函数直接处理`std::string`，避免缓冲区溢出风险

4. **性能与安全性权衡**  
   - 简单场景（如已知输入合法）可用`atoi`；需严格校验的场景（如用户输入）应优先使用`stoi`系列

5. **宽字符支持**  
   - `stof`可处理`wstring`（如`L"3.14"`），而`atof`仅支持窄字符

### 四、示例对比
```cpp
// C风格函数
const char* cstr = "123.45";
double d1 = atof(cstr);  // 无异常，失败返回0.0

// C++11函数
std::string s = "456px";
try {
    int i = stoi(s, nullptr, 10);  // 抛出invalid_argument
} catch (const std::exception& e) {
    // 处理异常
}
```

建议优先使用C++11的`stoi`/`stof`系列函数，尤其在需要可靠错误处理的场景。对于遗留代码或性能敏感模块，可谨慎使用C风格函数，但需自行添加输入验证逻辑。