在 Python 中，可变对象（Mutable Objects）是指创建后可以被修改的对象。除了常见的 `list`、`dict` 和 `set` 之外，还有一些其他可变类型。以下是详细的分类和示例分析：

---

## 1. 列表（`list`）
列表是 Python 中最常用的可变序列，支持动态增删改操作。

### 示例
```python
lst = [1, 2, 3]
print(id(lst))  # 输出内存地址

# 修改列表
lst.append(4)    # 添加元素
lst[0] = 10      # 修改元素
del lst[1]       # 删除元素
print(lst)       # [10, 3, 4]
print(id(lst))   # 内存地址不变
```
说明：
- 列表支持 `append()`、`extend()`、`insert()`、`remove()`、`pop()` 等修改操作。
- 修改后内存地址不变，说明是原地修改。

---

## 2. 字典（`dict`）
字典是键值对的可变集合，键必须是不可变对象（如 `str`、`int`、`tuple`），但值可以是任意对象。

### 示例
```python
d = {"a": 1, "b": 2}
print(id(d))  # 输出内存地址

# 修改字典
d["c"] = 3    # 添加键值对
d["a"] = 100  # 修改值
del d["b"]    # 删除键值对
print(d)      # {'a': 100, 'c': 3}
print(id(d))  # 内存地址不变
```
说明：
- 字典支持 `update()`、`pop()`、`clear()` 等修改操作。
- 键必须是不可变的（如不能使用 `list` 或 `set` 作为键）。

---

## 3. 集合（`set`）
集合是无序且元素唯一的可变容器，支持数学集合操作（并集、交集等）。

### 示例
```python
s = {1, 2, 3}
print(id(s))  # 输出内存地址

# 修改集合
s.add(4)      # 添加元素
s.remove(2)   # 删除元素
s.discard(5)  # 安全删除（如果元素不存在，不报错）
print(s)      # {1, 3, 4}
print(id(s))  # 内存地址不变
```
说明：
- 集合支持 `add()`、`remove()`、`update()`、`intersection()` 等操作。
- 集合的元素必须是不可变的（如不能存储 `list` 或 `dict`）。

---

## 4. 字节数组（`bytearray`）
`bytearray` 是 `bytes` 的可变版本，适用于需要修改二进制数据的场景。

### 示例
```python
ba = bytearray(b"hello")
print(id(ba))  # 输出内存地址

# 修改字节数组
ba[0] = 72     # 修改第一个字节（ASCII 'H'）
ba.append(33)  # 添加 '!' (ASCII 33)
print(ba)      # bytearray(b'Hello!')
print(id(ba))  # 内存地址不变
```
说明：
- `bytearray` 适用于需要频繁修改二进制数据的场景（如网络协议解析）。
- 普通 `bytes` 是不可变的，而 `bytearray` 是可变的。

---

## 5. 队列（`collections.deque`）
`deque` 是双端队列，支持高效的头尾插入和删除，比 `list` 更适合频繁的头部操作。

### 示例
```python
from collections import deque

dq = deque([1, 2, 3])
print(id(dq))  # 输出内存地址

# 修改队列
dq.appendleft(0)  # 头部插入
dq.pop()          # 尾部删除
dq.extend([4, 5]) # 批量添加
print(dq)        # deque([0, 1, 2, 4, 5])
print(id(dq))    # 内存地址不变
```
说明：
- `deque` 的 `appendleft()` 和 `popleft()` 操作比 `list` 的 `insert(0, x)` 和 `pop(0)` 更高效。
- 线程安全，适合实现队列和栈。

---

## 6. 默认字典（`collections.defaultdict`）
`defaultdict` 是 `dict` 的子类，提供默认值以避免 `KeyError`。

### 示例
```python
from collections import defaultdict

dd = defaultdict(int)  # 默认值为 0
print(id(dd))  # 输出内存地址

# 修改默认字典
dd["a"] += 1   # 自动初始化 "a" 为 0，然后 +1
dd["b"] = 100  # 直接赋值
print(dd)      # defaultdict(<class 'int'>, {'a': 1, 'b': 100})
print(id(dd))  # 内存地址不变
```
说明：
- 适用于统计计数、分组等场景。
- 默认值工厂可以是 `int`、`list`、`set` 等。

---

## 7. 用户自定义类（`class`）
用户定义的类实例默认是可变的，除非显式禁止属性修改。

### 示例
```python
class Person:
    def __init__(self, name):
        self.name = name

p = Person("Alice")
print(id(p))  # 输出内存地址

# 修改对象属性
p.name = "Bob"  # 修改属性
p.age = 25      # 动态添加新属性
print(p.__dict__)  # {'name': 'Bob', 'age': 25}
print(id(p))       # 内存地址不变
```
说明：
- 可以通过 `__slots__` 限制动态属性添加，但实例仍是可变的。
- 如果需要不可变对象，可以重写 `__setattr__` 或使用 `@dataclass(frozen=True)`。

---

## 8. NumPy 数组（`numpy.ndarray`）
NumPy 数组是科学计算中常用的可变多维数组。

### 示例
```python
import numpy as np

arr = np.array([1, 2, 3])
print(id(arr))  # 输出内存地址

# 修改数组
arr[0] = 10     # 修改元素
arr = np.append(arr, 4)  # 返回新数组（原数组不可变大小）
print(arr)      # [10 2 3 4]
print(id(arr))  # 内存地址变了（因为 np.append 返回新对象）
```
说明：
- NumPy 数组的大小不可变，但元素值可修改。
- 部分操作（如 `np.append`）会返回新对象，而非原地修改。

---

## 总结：Python 可变对象类型

| 类型 | 可变性 | 不可变版本（如果存在） |
|------|--------|---------------------|
| `list` | ✅ 可变 | `tuple` |
| `dict` | ✅ 可变 | `frozenset`（仅键） |
| `set` | ✅ 可变 | `frozenset` |
| `bytearray` | ✅ 可变 | `bytes` |
| `collections.deque` | ✅ 可变 | - |
| `collections.defaultdict` | ✅ 可变 | - |
| 用户自定义类 | ✅ 可变 | `namedtuple` 或 `@dataclass(frozen=True)` |
| `numpy.ndarray` | ✅ 部分可变（元素可改，大小不可变） | - |

### 关键特性
1. 可变对象支持原地修改（如 `lst.append(1)` 或 `d["key"] = value`），内存地址不变。
2. 可变对象不能作为字典的键或集合的元素（因为哈希值可能变化）。
3. 线程安全性：部分可变对象（如 `list`、`dict`）在多线程环境下需加锁。

如果需要不可变版本，可以使用 `tuple`、`frozenset`、`bytes` 或 `namedtuple`。