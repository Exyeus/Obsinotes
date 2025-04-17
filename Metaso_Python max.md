### 1. 基本语法
`max()` 有两种调用方式：
- 形式一（处理可迭代对象）：  
```python
  max(iterable, *[, key, default])
```
  - `iterable`：可迭代对象（如列表、元组、集合、字符串等）。
  - `key`（可选）：自定义比较规则的函数，作用于每个元素。
  - `default`（可选）：当可迭代对象为空时返回的默认值 。

- 形式二（直接比较多个参数）：  
```python
  max(arg1, arg2, *args[, key])
```
  - `arg1, arg2, ...`：多个参数（需为相同类型）。

---

### 2. 基本用法
#### (1) 处理可迭代对象
```python
numbers = [5, 2, 9, 1]
print(max(numbers))  # 输出 9 [[3, 5, 19]]

words = ["apple", "banana", "pear"]
print(max(words))    # 输出 "pear"（按字母顺序比较）[[8, 14]]
```

#### (2) 比较多个参数
```python
print(max(3, 8, 2))  # 输出 8 [[6, 8, 17]]
```

---

### 3. 高级用法
#### (1) 使用 `key` 参数自定义规则
- 按字符串长度比较：  
```python
  words = ["apple", "banana", "pear"]
  print(max(words, key=len))  # 输出 "banana" [[5, 12, 14]]
```

- 按字典的值比较：  
```python
  scores = {"Alice": 90, "Bob": 85, "Charlie": 95}
  print(max(scores, key=lambda k: scores[k]))  # 输出 "Charlie" [[14, 16]]
```

- 按自定义对象属性比较：  
```python
  class Person:
      def __init__(self, name, age):
          self.name = name
          self.age = age
  people = [Person("Tom", 30), Person("Alice", 25)]
  oldest = max(people, key=lambda p: p.age)
  print(oldest.name)  # 输出 "Tom" [[10, 16, 20]]
```

#### (2) 处理空可迭代对象
使用 `default` 避免 `ValueError`：  
```python
empty_list = []
print(max(empty_list, default=0))  # 输出 0 [[1, 6, 15]]
```

---

### 4. 适用数据类型
- 数值类型：直接比较大小 。
- 字符串：按 Unicode 码点或字母顺序比较（如 `max("abcXYZ")` 返回 `'Z'`）。
- 字典：默认比较键，需结合 `key` 参数比较值 。
- 混合类型：不同类型（如数字与字符串）会引发 `TypeError` 。

---

### 5. 注意事项
1. 空可迭代对象：未设置 `default` 时会抛出 `ValueError` 。
2. 数据类型一致性：参数或元素需为相同类型，否则报错 。
3. 多个最大值：返回第一个遇到的最大值 。
4. 版本兼容性：`default` 参数需 Python 3.4+ 支持 。

---

### 6. 示例汇总
```python
# 按绝对值比较
nums = [-5, 3, -8]
print(max(nums, key=abs))  # 输出 -8 [[2, 5]]

# 处理元组
points = (4, 7, 2, 9)
print(max(points))          # 输出 9 [[3, 8]]

# 多列表比较（需先解包）
list1 = [1, 2, 3]
list2 = [4, 5]
print(max(*list1, *list2))  # 输出 5 [[1, 6]]
```

---

通过合理使用 `key` 和 `default` 参数，`max()` 函数可以灵活应对数值、字符串、字典及自定义对象等多种场景，是 Python 中处理最大值问题的强大工具 。