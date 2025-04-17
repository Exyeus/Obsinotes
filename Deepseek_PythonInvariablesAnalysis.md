当然！不可变对象（如数字、字符串、元组）在创建后不能被修改。以下是具体的例子：

### 1. 数字（整数、浮点数等）
```python
a = 10
print(id(a))  # 输出a的内存地址
a = 20        # 实际上是创建了一个新对象，而不是修改原来的10
print(id(a))  # 内存地址变了
```
说明：`a = 20` 并没有修改 `10` 这个对象，而是让变量 `a` 指向了一个新的整数对象 `20`。

---

### 2. 字符串（str）
```python
s = "hello"
print(id(s))  # 输出s的内存地址
s += " world"  # 实际上是创建了一个新字符串
print(id(s))  # 内存地址变了
```
说明：字符串的拼接、替换等操作都会生成新对象，原字符串不变：
```python
s = "Python"
s[0] = "J"  # 报错！TypeError，不可修改
```

---

### 3. 元组（tuple）
```python
t = (1, 2, 3)
print(id(t))  
t += (4,)     # 实际上是创建了一个新元组
print(id(t))  # 内存地址变了
```
说明：元组内部的元素不可修改：
```python
t = (1, [2, 3])
t[1].append(4)  # 不报错！因为元组的元素是列表（可变对象）
t[0] = 10       # 报错！TypeError，元组的一级元素不可变
```

---

### 关键点总结：
1. 不可变对象的“修改”实际上是创建新对象，原对象不变。
2. 尝试直接修改不可变对象（如 `s[0] = "x"` 或 `t[0] = 10`）会触发 `TypeError`。
3. 元组的不可变性仅针对一级元素，如果元素是可变对象（如列表），其内容仍可修改。
在 Python 中，不可变对象（Immutable Objects）是指创建后不能被修改的对象。除了数字（`int`、`float`、`complex`）、字符串（`str`）和元组（`tuple`）之外，还有以下不可变类型：

---

## 1. 布尔值（`bool`）
布尔值 `True` 和 `False` 是不可变的，它们实际上是 `int` 的子类（`True == 1`，`False == 0`）。

### 示例
```python
b = True
print(id(b))  # 输出内存地址
b = False     # 实际上是创建了一个新的 bool 对象
print(id(b))  # 内存地址变了
```
说明：
- 不能直接修改 `True` 或 `False` 的值。
- 重新赋值会创建新对象。

---

## 2. 冻结集合（`frozenset`）
`frozenset` 是 `set` 的不可变版本，不能添加、删除或修改元素。

### 示例
```python
fs = frozenset([1, 2, 3])
print(fs)  # frozenset({1, 2, 3})

# 尝试修改会报错
fs.add(4)  # AttributeError: 'frozenset' object has no attribute 'add'
fs.remove(1)  # AttributeError
```
说明：
- `frozenset` 适用于需要不可变集合的场景（如作为字典的键）。
- 普通 `set` 是可变的，但 `frozenset` 不可变。

---

## 3. 字节串（`bytes`）
`bytes` 是不可变的字节序列，类似于 `str` 但存储的是二进制数据。

### 示例
```python
b = b"hello"
print(b)  # b'hello'

# 尝试修改会报错
b[0] = 72  # TypeError: 'bytes' object does not support item assignment

# 只能通过拼接创建新的 bytes
new_b = b + b" world"
print(new_b)  # b'hello world'
```
说明：
- `bytes` 适用于二进制数据，如文件 I/O、网络传输。
- 可变版本是 `bytearray`。

---

## 4. 命名元组（`namedtuple`）
`namedtuple` 是 `collections` 模块提供的不可变数据结构，具有命名字段。

### 示例
```python
from collections import namedtuple

Point = namedtuple("Point", ["x", "y"])
p = Point(1, 2)
print(p.x, p.y)  # 1 2

# 尝试修改会报错
p.x = 10  # AttributeError: can't set attribute

# 只能创建新对象
new_p = p._replace(x=10)  # 返回新对象
print(new_p)  # Point(x=10, y=2)
```
说明：
- `namedtuple` 是轻量级的不可变数据结构，适用于替代简单类。
- `_replace()` 方法返回新对象，而不是修改原对象。

---

## 5. 枚举（`enum.Enum`）
Python 的 `enum.Enum` 是不可变的，枚举值在定义后不能修改。

### 示例
```python
from enum import Enum

class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3

print(Color.RED)  # Color.RED

# 尝试修改会报错
Color.RED = 100  # AttributeError: Cannot reassign members
```
说明：
- 枚举值在定义后不可变，适用于常量定义。
- 枚举成员是单例模式，全局唯一。

---

## 6. 空类型（`NoneType`）
`None` 是 Python 的空值，属于 `NoneType`，也是不可变的。

### 示例
```python
n = None
print(id(n))  # 输出内存地址
n = "new value"  # 只是变量重新赋值，None 本身不可变
print(id(n))  # 内存地址变了
```
说明：
- `None` 是单例对象，所有 `None` 变量指向同一个内存地址。
- 不能修改 `None` 的值。

---

## 总结：Python 不可变对象类型

| 类型 | 可变性 | 可变版本（如果存在） |
|------|--------|------------------|
| `int` | ❌ 不可变 | - |
| `float` | ❌ 不可变 | - |
| `complex` | ❌ 不可变 | - |
| `str` | ❌ 不可变 | `bytearray`（部分可变） |
| `tuple` | ❌ 不可变 | `list` |
| `bool` | ❌ 不可变 | - |
| `frozenset` | ❌ 不可变 | `set` |
| `bytes` | ❌ 不可变 | `bytearray` |
| `namedtuple` | ❌ 不可变 | `dict` 或 `dataclass` |
| `enum.Enum` | ❌ 不可变 | - |
| `None` | ❌ 不可变 | - |

### 关键特性
1. 不可变对象在赋值或修改时实际上是创建新对象（如 `a = 10; a = 20` 不会修改 `10`，而是让 `a` 指向新对象）。
2. 尝试直接修改不可变对象会抛出 `TypeError` 或 `AttributeError`（如 `s[0] = 'x'` 或 `t[0] = 100`）。
3. 不可变对象适合作为字典的键或集合的元素（因为它们的哈希值不变）。

如果需要可变版本，可以使用 `list`、`set`、`bytearray` 或 `dict`。