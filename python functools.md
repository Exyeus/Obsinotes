`functools` 是 Python 标准库中的一个模块，提供了许多高阶函数，用于函数式编程和函数的操作。它提供了多种工具，可以使函数的操作变得更简洁、优雅，尤其是对函数进行修饰、缓存、部分应用等操作。

下面是 `functools` 模块的常用函数和功能的详细介绍：

### 1. **`functools.partial`**

`partial` 函数可以通过固定一个或多个函数的参数，<font color="#31d83b">来生成一个新的函数。新生成的函数只需要传入剩余的参数即可。</font>
[[CS61A 1.6 Higher-Order Functions]]
#### 用法：

```python
import functools

def power(base, exponent):
    return base ** exponent

# 使用 partial 函数固定 base 参数为 2
square = functools.partial(power, base=2)

print(square(3))  # 输出 8，因为 2 ** 3 = 8
```

#### 解释：

`partial` 函数返回一个新的函数（例如 `square`），这个新函数已经绑定了一些参数（如 `base=2`），因此调用时只需要提供 `exponent` 参数。

### 2. **`functools.lru_cache`**

`lru_cache` 是一个装饰器，用于缓存函数的返回值，以提高函数的性能，尤其是在计算开销较大的情况下。LRU 是 “Least Recently Used”的缩写，表示缓存的大小一旦超过设定的最大值，就会移除最久未使用的缓存项。

#### 用法：

```python
import functools

@functools.lru_cache(maxsize=None)  # None 表示无限制
def expensive_function(n):
    print(f"Computing {n}...")
    return n * 2

print(expensive_function(5))  # 计算并缓存
print(expensive_function(5))  # 从缓存中获取
```
[[CS61A 1.6 Higher-Order Functions]] Function Decorators !
#### 解释：

- `maxsize` 参数控制缓存的大小。默认为 128，当缓存达到最大值时，会移除最久未使用的缓存项。
- 使用缓存可以显著提高性能，避免重复计算相同的参数。

### 3. **`functools.reduce`**

`reduce` 是一个高阶函数，用于对序列的元素进行累积操作，直到得到一个最终结果。`reduce` 会根据给定的二元操作函数将序列中的元素两两组合，最终返回单一结果。

#### 用法：

```python
import functools

# 对列表中的数字进行累加
numbers = [1, 2, 3, 4]
result = functools.reduce(lambda x, y: x + y, numbers)
print(result)  # 输出 10，因为 1 + 2 + 3 + 4 = 10
```

#### 解释：

- `reduce` 的第一个参数是一个二元函数，表示如何将两个元素合并成一个元素。
- 第二个参数是一个可迭代对象（如列表），`reduce` 将按照给定的函数进行累积操作。

### 4. **`functools.total_ordering`**

`total_ordering` 是一个类装饰器，它通过只定义少数几个比较方法（如 `__eq__` 和 `__lt__`），自动补全其余的比较方法（如 `__gt__`, `__ge__`, `__ne__` 等）。

#### 用法：

```python
import functools

@functools.total_ordering
class MyNumber:
    def __init__(self, value):
        self.value = value

    def __eq__(self, other):
        return self.value == other.value

    def __lt__(self, other):
        return self.value < other.value

num1 = MyNumber(5)
num2 = MyNumber(10)

print(num1 < num2)  # True
print(num1 <= num2)  # True
print(num1 > num2)  # False
print(num1 >= num2)  # False
print(num1 == num2)  # False
```

#### 解释：

- 只需要定义比较函数中的两个方法（通常是 `__eq__` 和 `__lt__`），其余的比较方法会由 `total_ordering` 自动补充，从而避免了重复编写所有比较方法。

### 5. **`functools.wraps`**

`wraps` 是一个装饰器，用于帮助开发者编写装饰器。它会将原函数的一些元数据（如 `__name__`, `__doc__` 等）复制到装饰器函数中，以保持原函数的特性。

#### 用法：

```python
import functools

def my_decorator(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        print("Before calling function")
        return func(*args, **kwargs)
    return wrapper

@my_decorator
def my_function():
    """This is my function"""
    print("Inside function")

print(my_function.__name__)  # 输出 my_function
print(my_function.__doc__)   # 输出 This is my function
```

#### 解释：

- `functools.wraps` 确保装饰器中的 `wrapper` 函数具有被装饰函数的名称、文档字符串和其他元数据。

### 6. **`functools.cache_property`**

`cache_property` 是一个装饰器，将方法的返回值缓存起来，当属性被访问时返回缓存的值，而不再重新计算。这个装饰器适用于计算开销大的只读属性。

#### 用法：

```python
import functools

class MyClass:
    def __init__(self, value):
        self._value = value

    @property
    @functools.cache_property
    def value(self):
        print("Computing value...")
        return self._value * 2

obj = MyClass(5)
print(obj.value)  # 计算并缓存
print(obj.value)  # 从缓存中获取
```

#### 解释：

- `cache_property` 类似于 `property`，但是它会缓存第一次计算的值，从而避免每次访问属性时都重新计算。

### 7. **`functools.cached_property` (Python 3.8+ 引入)**

与 `cache_property` 类似，但它是专门为类中的属性计算结果缓存设计的，它不会在每次访问时重新计算该属性的值。

#### 用法：

```python
import functools

class MyClass:
    def __init__(self, value):
        self._value = value

    @property
    @functools.cached_property
    def value(self):
        print("Computing value...")
        return self._value * 2

obj = MyClass(5)
print(obj.value)  # 计算并缓存
print(obj.value)  # 从缓存中获取
```

#### 解释：

`cached_property` 也会缓存方法的结果，避免重复计算，尤其适合计算开销较大的属性。

### 8. **`functools.cache_clear`**

`cache_clear` 用于清除通过 `functools.lru_cache` 或 `functools.cache_property` 缓存的数据。

#### 用法：

```python
import functools

@functools.lru_cache(maxsize=None)
def expensive_function(x):
    return x * 2

print(expensive_function(2))  # 输出 4
expensive_function.cache_clear()  # 清除缓存
```

### 9. **`functools.partialmethod`**

与 `partial` 类似，`partialmethod` 用于生成一个新的方法，但这个方法是类的实例方法。

#### 用法：

```python
import functools

class MyClass:
    def greet(self, name, greeting="Hello"):
        print(f"{greeting}, {name}!")

    greet_hello = functools.partialmethod(greet, greeting="Hello")
    greet_goodbye = functools.partialmethod(greet, greeting="Goodbye")

obj = MyClass()
obj.greet_hello("Alice")  # Output: Hello, Alice!
obj.greet_goodbye("Bob")  # Output: Goodbye, Bob!
```

### 总结：

`functools` 提供了许多实用的工具函数，特别适合用在函数式编程中。常见的有：

- `partial`：生成部分应用函数。
- `lru_cache`：缓存函数返回值，优化性能。
- `reduce`：对序列进行累积计算。
- `total_ordering`：简化自定义类的比较操作。
- `wraps`：用于编写装饰器时保持原函数信息。
- `cached_property` 和 `cache_property`：缓存计算属性的值。

这些函数有助于简化代码，提高代码的可读性和性能。