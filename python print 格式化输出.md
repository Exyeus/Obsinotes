---
sr-due: 2025-09-16
sr-interval: 155
sr-ease: 290
---

#review 

在 Python 中，输出数据的方式有几种，常见的有以下几种：

### 1. **`print()` 函数**

`print()` 是最常见的输出方式，通常用于将信息输出到控制台。

**基本用法**：

```python
print("Hello, World!")
```

**输出多个变量**：可以将多个变量用逗号分隔，`print()` 会自动在它们之间插入空格。

```python
x = 5
y = 10
print("x:", x, "y:", y)
# Notice: Supported value type does not has specific limitations
```

**输出不换行**：`print()` 默认会在输出内容后加上一个换行符，可以通过 `end` *参数改变*。

```python
print("Hello", end=" ")
print("World!")
# Output: Hello World!
```

**自定义分隔符**：通过 `sep` 参数设置不同的分隔符。

```python
print("apple", "banana", "cherry", sep=", ")
# Output: apple, banana, cherry
# Consider the situation of scattered strings and variables, maybe this also works!
```

### 2. **格式化字符串输出**

**格式化字符串输出有多种方式**，以下是几种常见的格式化方法：

#### (1) **使用 `%` 操作符（旧的方式）**

`%` 是旧式的格式化方法，虽然它已经被新的格式化方法所替代，但仍然在一些旧代码中可见。

**基本用法**：

```python
name = "Alice"
age = 30
print("Name: %s, Age: %d" % (name, age))
# Output: Name: Alice, Age: 30
```

**格式说明符**：

- `%s`：字符串
- `%d`：整数
- `%f`：浮点数
- `%x`：十六进制整数

**指定宽度与精度**：

```python
pi = 3.14159265
print("Pi: %.2f" % pi)
# Output: Pi: 3.14
```

#### (2) **使用 `str.format()` 方法（推荐）**

`str.format()` 是一种更现代的格式化方法，能够提供更强大的功能。

**基本用法**：

```python
name = "Alice"
age = 30
print("Name: {}, Age: {}".format(name, age))
# Output: Name: Alice, Age: 30
```

**位置和关键字参数**：

- **位置参数**：通过位置指定输出的值

```python
print("Name: {}, Age: {}".format("Alice", 30))
# Output: Name: Alice, Age: 30
```

- **关键字参数**：通过关键字指定输出的值

```python
print("Name: {name}, Age: {age}".format(name="Alice", age=30))
# Output: Name: Alice, Age: 30
```

**指定输出顺序**：

```python
print("{1} is the age of {0}".format("Alice", 30))
# Output: 30 is the age of Alice
```

**格式化数字**：

```python
pi = 3.14159265
print("Pi: {:.2f}".format(pi))
# Output: Pi: 3.14
```

#### (3) **f-strings (Python 3.6+ 推荐方式)**

f-strings 是 Python 3.6 以后引入的非常直观且简洁的字符串格式化方式。通过*在字符串前*加 `f` 或 `F`，然后将变量用 `{}` 包裹即可。

**基本用法**：

```python
name = "Alice"
age = 30
print(f"Name: {name}, Age: {age}")
# Output: Name: Alice, Age: 30
```

**表达式嵌入**：可以直接在花括号内插入表达式。

```python
x = 5
y = 10
print(f"x + y = {x + y}")
# Output: x + y = 15
```

**格式化数字**：

```python
pi = 3.14159265
print(f"Pi: {pi:.2f}")
# Output: Pi: 3.14
```

### 3. **其他输出方式**

#### (1) **`repr()` 和 `str()`**

- `repr()`：用于生成对象的“官方”字符串表示，通常用于*调试或者日志记录*，返回的字符串可以用作*代码*。`eval`之？
- `str()`：用于生成对象的“人类可读”表示。

**示例**：

```python
obj = [1, 2, 3]
print(str(obj))  # [1, 2, 3]
print(repr(obj)) # [1, 2, 3]
```

#### (2) **`logging` 模块**

用于生成日志，支持输出到文件、控制台，支持不同的日志级别（如：DEBUG、INFO、WARNING、ERROR、CRITICAL）。

**示例**：

```python
import logging
logging.basicConfig(level=logging.INFO)
logging.info("This is an info message.")
logging.error("This is an error message.")
```

`logging` 允许你设置日志级别和输出位置，可以比 `print()` 更加灵活和有用。

#### (3) **输出到文件**

Python 中可以将输出重定向到文件而不是控制台。

**基本用法**：

```python
with open("output.txt", "w") as f:
    print("Hello, file!", file=f)
```

### 4. **数据格式化输出的途径**

数据格式化输出的方法非常多，主要可以根据需求*选择适当的工具*来进行输出：

#### (1) **格式化数值输出**：

- 控制数值的精度和宽度，适用于浮点数、整数等数据类型的格式化输出。
- 格式化表达式：`{:.2f}` 表示保留两位小数，`{:5d}` 表示宽度为5的整数。

#### (2) **日期和时间格式化**：

`datetime` 模块提供了方便的日期时间格式化方法。

```python
from datetime import datetime
now = datetime.now()
print(f"Current time: {now:%Y-%m-%d %H:%M:%S}")
# Output: Current time: 2025-01-24 10:30:15
```

#### (3) **JSON 格式化**：

使用 `json` 模块可以将字典或其他数据结构格式化为 JSON 格式输出。

```python
import json
data = {"name": "Alice", "age": 30}
print(json.dumps(data, indent=4))
# Output:
# {
#     "name": "Alice",
#     "age": 30
# }
```

#### (4) **对齐和填充**：

通过格式化字符串可以指定对齐方式和填充字符。

```python
print("{:<10} {:>10} {:^10}".format("Left", "Right", "Center"))
# Output:
# Left       Right    Center    
```

### **总结**：

Python 提供了多种方式来进行数据的输出，包括：

- `print()`：最常见的输出方式。
- 字符串格式化：`%`、`str.format()`、`f-strings`。
- 文件输出：将输出重定向到文件中。
- `logging` 模块：用于更复杂的日志输出。
- 其他格式化输出方式：如 JSON 输出、日期时间格式化等。

选择合适的方式取决于你需要输出的内容的复杂程度和输出的目标。