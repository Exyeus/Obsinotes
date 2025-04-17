---
sr-due: 2025-04-13
sr-interval: 4
sr-ease: 272
---

#review 

[[CS61A 4.2 Implicit Sequence__]]

>`sorted` will return a new object, not destructively operating on the original data object
>`reversed` will return an iterator that accesses the sequence in a reversed order. Please `list` it to get a list.
>`key` parameter: giving an standard for the sort process. An efficient style is: 

好的同学！我们这次来聊聊 Python 中几个非常有用的、自带算法“魔力”的内建函数，特别是 `sorted()` 和 `reversed()`。它们就像瑞士军刀一样，能帮你轻松处理序列的排序和反转问题，而无需你亲自编写复杂的循环和比较逻辑。这与 C++ 的 `<algorithm>` 库的设计哲学有异曲同工之妙——提供强大、高效、易用的基础算法构建块。

**学科领域:** CS61A / Python 基础 / 数据结构与算法入门

---

### 1. 引入与动机 (Hook & Motivation)

想象一下，你刚统计完一次测验的成绩，得到一个列表 `scores = [88, 92, 75, 92, 85]`。现在你想：

*   看看最高分和最低分？（需要排序）
*   按照从高到低的顺序列出所有成绩？（需要排序）
*   或者，你有一个名字列表 `names = ["Alice", "Bob", "Charlie"]`，你想按字母倒序排列它们？
*   甚至，你有一列用户数据，比如 `users = [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 25}]`，你想按照年龄给用户排序？

手动写循环来做这些排序当然可以，但会很繁琐，而且容易出错。特别是对于复杂对象的排序，逻辑会更复杂。这时，Python 内建的 `sorted()` 和 `reversed()` 函数就能大显身手了！

**学习它们的重要性：**

*   **代码简洁高效:** 用一行代码完成排序或反转，清晰易读，且底层实现通常比我们自己手写的循环更优化（Python 的排序算法 Timsort 非常高效）。
*   **通用性强:** 它们可以处理各种可迭代的数据类型（列表、元组、字符串、字典视图等）。
*   **灵活定制:** 通过 `key` 参数，可以实现非常灵活的自定义排序逻辑，轻松应对复杂场景。
*   **面试常见:** 这些函数（尤其是 `sorted` 的 `key` 用法）是 Python 面试中经常考察的基础知识点。

掌握它们，能让你的 Python 数据处理能力提升一个档次！

---

### 2. 必要知识回顾 (Prerequisite Review)

在我们开始之前，确保你对以下概念有基本印象：

*   **可迭代对象 (Iterable):** 指那些可以被 `for` 循环遍历的对象，比如列表 (`list`)、元组 (`tuple`)、字符串 (`str`)、集合 (`set`)、字典 (`dict`，可以迭代键、值或项)、`range` 对象等。简单说，就是能“一个接一个”提供元素的东西。
*   **序列 (Sequence):** 一种特殊的可迭代对象，其元素是有序的，并且可以通过索引（下标）访问，比如列表、元组、字符串、`range`。
*   **函数调用与参数:** 如何调用一个函数，如何传递参数（位置参数、关键字参数如 `key=...`）。
*   **列表 (`list`) 的可变性:** 列表是**可变的 (mutable)**，意味着你可以直接修改列表的内容（添加、删除、修改元素）。
*   **元组 (`tuple`) 和字符串 (`str`) 的不可变性:** 元组和字符串是**不可变的 (immutable)**，一旦创建，它们的内容就不能被修改。任何看起来像修改的操作（如字符串拼接）实际上是创建了一个新的对象。

理解这些，特别是可迭代性和可变性，对于区分 `sorted()` 和列表自带的 `.sort()` 方法至关重要。

---

### 3. 直观解释与感性认识 (Intuitive Explanation)

让我们用一个简单的比喻来理解 `sorted()` 和 `reversed()`：

*   **`sorted(东西)`:**
    *   想象你有一堆乱序的卡片（比如 `[3, 1, 4, 1, 5]`）。
    *   你调用 `sorted()`，就像是找了一个小助手。
    *   这个小助手会拿出**一套新的空白卡片**，看着你原来的那堆卡片，按照从小到大的顺序，把数字抄写到新卡片上，得到 `[1, 1, 3, 4, 5]`。
    *   然后，小助手把这**一叠排好序的新卡片**交给你。
    *   **关键：** 你原来那堆乱序的卡片**完全没有被动过**，还在原地。`sorted()` 给你的是一个**全新的、排好序的版本**。

*   **`reversed(东西)`:**
    *   想象你有一排按顺序排列的书 `['A', 'B', 'C']` 在书架上。
    *   你调用 `reversed()`，不是立刻给你一个新的、倒序的书架。
    *   而是给你一个**“反向导航指令”**。这个指令告诉你：“如果你想看这些书，请从最后一本 (`C`) 开始看，然后是倒数第二本 (`B`)，最后是第一本 (`A`)。”
    *   这个指令本身**不是书的集合**，只是一个**如何反向访问**的计划。
    *   你需要**按照这个指令去行动**（比如用 `for` 循环遍历，或者把它转换成一个列表 `list(reversed(...))`），才能真正得到反向的序列 `['C', 'B', 'A']`。
    *   **关键：** `reversed()` 本身不创建新的列表，而是返回一个**迭代器 (iterator)**，它描述了反向遍历的顺序，非常节省内存。

*   **列表的 `.sort()` 方法 (对比):**
    *   还用卡片的例子 `cards = [3, 1, 4, 1, 5]`。
    *   你调用 `cards.sort()`，就像是你**亲自**在那**一堆原始卡片上**进行整理。
    *   你直接把 `cards` 这堆卡片**原地排好序**，变成了 `[1, 1, 3, 4, 5]`。
    *   **关键：** `.sort()` 是列表对象自己的一个**动作（方法）**，它**直接修改了列表本身**，并且**不返回任何有意义的东西**（严格来说返回 `None`）。

这个直观的区别非常重要：`sorted()` 创建新列表，`reversed()` 创建反向迭代器，`.sort()` 修改原列表。

---

### 4. 逐步形式化与精确定义 (Gradual Formalization)

现在，我们用更精确的语言来定义它们。

#### 4.1 `sorted()` 内建函数

*   **签名:** `sorted(iterable, *, key=None, reverse=False)`
    *   `iterable`: **必需参数**。任何可迭代的对象（列表、元组、字符串、集合、字典视图等）。
    *   `key`: **可选关键字参数** (必须写成 `key=...`)。它应该是一个**函数**。这个函数会作用于 `iterable` 中的**每一个元素**，并且返回一个用于**比较的值（代理键）**。排序将根据这些代理键来进行，而不是直接比较元素本身。如果省略 (`None`)，则直接比较元素。
    *   `reverse`: **可选关键字参数** (必须写成 `reverse=...`)。一个布尔值。
        *   如果 `reverse=False` (默认值)，则按**升序** (ascending) 排列。
        *   如果 `reverse=True`，则按**降序** (descending) 排列。
*   **返回值:** 一个**新的列表 (list)**，包含了 `iterable` 中所有元素的排序结果。**原始的 `iterable` 保持不变。**
*   **稳定性:** Python 的 `sorted()` (以及 `.sort()`) 使用的 Timsort 算法是**稳定**的。这意味着如果多个元素具有相同的键（或值，如果没有指定 `key`），它们在排序后的输出列表中将保持其在原始 `iterable` 中的相对顺序。

#### 4.2 `reversed()` 内建函数

*   **签名:** `reversed(seq)`
    *   `seq`: **必需参数**。通常是一个**序列** (sequence)，即实现了 `__len__()` 和 `__getitem__()` 方法的对象，如 `list`, `tuple`, `str`, `range`。它也可以是任何定义了 `__reversed__()` 方法的对象（这是更通用的情况，字典视图在 Python 3.8+ 也支持）。
*   **返回值:** 一个**反向迭代器 (reverse iterator)**。它不是列表！它是一个一次性的、惰性的对象，用于按相反顺序逐个产生 `seq` 中的元素。
*   **行为:** 它不创建新的数据结构来存储反转后的元素，只是提供一种反向访问原始序列的方式。要获得反转后的列表，需要显式转换，例如 `list(reversed(seq))`。

#### 4.3 `list.sort()` 方法 (对比)

*   **签名:** `my_list.sort(*, key=None, reverse=False)`
    *   注意：这是**列表对象**的一个**方法**，不是全局函数。
    *   `key`: 和 `sorted()` 中的 `key` 含义相同。
    *   `reverse`: 和 `sorted()` 中的 `reverse` 含义相同。
*   **返回值:** `None`。它不返回排序后的列表。
*   **行为:** **直接在原地修改** `my_list` 本身，使其元素按排序顺序排列。

---

### 5. 核心原理与推导过程 (Core Principles & Derivation Walkthrough)

#### 5.1 `key` 参数的威力：自定义排序的“翻译官”

`key` 参数是 `sorted()` 和 `.sort()` 最强大的特性之一。它的核心思想是：**不要直接比较原始元素，而是比较通过 `key` 函数转换后的“代理值”。**

想象你要按学生年龄给一个字典列表排序：
`users = [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 25}, {'name': 'Charlie', 'age': 25}]`

直接比较字典 `{'name': 'Alice', 'age': 30}` 和 `{'name': 'Bob', 'age': 25}` 是没有意义的。我们需要告诉 `sorted`：“嘿，比较这些字典时，请只关注 `age` 字段的值。”

这就是 `key` 函数的作用。我们可以提供一个函数，它接收一个字典，返回该字典的 `age` 值：

```python
def get_age(user_dict):
  return user_dict['age']

sorted_users = sorted(users, key=get_age)
# sorted 会对每个 user 调用 get_age:
# get_age({'name': 'Alice', 'age': 30}) -> 30
# get_age({'name': 'Bob', 'age': 25}) -> 25
# get_age({'name': 'Charlie', 'age': 25}) -> 25
# 然后 sorted 根据这些返回的年龄 (30, 25, 25) 来排序原始的字典。
```

使用 `lambda` 表达式可以更简洁地定义这个 `key` 函数：

```python
sorted_users = sorted(users, key=lambda user: user['age'])
```
`lambda user: user['age']` 就是一个临时的、匿名的函数，它做的事情和 `get_age` 完全一样。

**`key` 函数的推导过程（内部想象）：**

1.  `sorted` 拿到 `iterable` 和 `key` 函数。
2.  它遍历 `iterable` 中的每个元素 `item`。
3.  对每个 `item`，调用 `key(item)` 得到一个 `proxy_key`。
4.  它在内部（概念上）创建一个临时的 (元素, 代理键) 对的列表，例如 `[(item1, key(item1)), (item2, key(item2)), ...]`。
5.  然后，它根据**代理键**对这个临时列表进行排序（如果代理键相同，利用排序稳定性保持原始相对顺序）。
6.  最后，它从排好序的对中提取出**原始元素**，组成一个新的列表返回。

#### 5.2 `reverse` 参数：简单直接的方向盘

`reverse` 参数很简单，它只是告诉排序算法最终结果是升序 (`False`) 还是降序 (`True`)。它作用在排序比较的最后阶段。

#### 5.3 `reversed()` 的迭代器本质：惰性求值

为什么 `reversed()` 不直接返回一个反转的列表？

*   **效率 (内存):** 如果你有一个非常非常长的序列，创建一个完整的反转副本会消耗大量内存。迭代器只在你需要下一个元素时才去获取它，是“惰性”的，内存占用极小。
*   **效率 (时间):** 有时你可能只需要反向序列的前几个元素，或者只需要遍历一次。迭代器避免了预先计算和存储整个反转序列的时间开销。
*   **通用性:** 迭代器是 Python 中处理序列数据的统一接口，可以与其他接受迭代器的工具（如 `for` 循环、`list()` 构造函数、`itertools` 模块）无缝协作。

当你写 `for item in reversed(my_list):` 时，Python 在每次循环迭代时，才通过 `reversed()` 返回的迭代器去获取 `my_list` 中对应的下一个（反向的）元素。

#### 5.4 排序稳定性 (Stability) 的意义

思考之前的 `users` 例子，Bob 和 Charlie 年龄都是 25。
`users = [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 25}, {'name': 'Charlie', 'age': 25}]`

如果按年龄升序排序 `sorted(users, key=lambda u: u['age'])`：

*   一个**稳定**的排序**保证**会得到： `[{'name': 'Bob', 'age': 25}, {'name': 'Charlie', 'age': 25}, {'name': 'Alice', 'age': 30}]` (Bob 在 Charlie 之前，因为他们在原始列表中就是这个顺序)。
*   一个**不稳定**的排序可能会得到上面结果，也可能得到： `[{'name': 'Charlie', 'age': 25}, {'name': 'Bob', 'age': 25}, {'name': 'Alice', 'age': 30}]` (Bob 和 Charlie 的顺序可能被打乱)。

稳定性在多级排序或需要保持同键元素原始顺序的场景下非常重要。Python 的排序是稳定的，这是一个很好的特性。

---

### 6. 示例与应用 (Examples & Application)

#### 示例 1: 基本用法

```python
nums = [3, 1, 4, 1, 5, 9, 2, 6]
chars = "python"
my_tuple = (5, 2, 8, 1)

# sorted() - 返回新列表，原数据不变
sorted_nums = sorted(nums)
print(f"Original nums: {nums}")       # Output: Original nums: [3, 1, 4, 1, 5, 9, 2, 6]
print(f"Sorted nums: {sorted_nums}") # Output: Sorted nums: [1, 1, 2, 3, 4, 5, 6, 9]

sorted_chars = sorted(chars)
print(f"Original chars: {chars}")       # Output: Original chars: python
print(f"Sorted chars: {sorted_chars}") # Output: Sorted chars: ['h', 'n', 'o', 'p', 't', 'y'] (注意变成了字符列表)

sorted_tuple = sorted(my_tuple)
print(f"Original tuple: {my_tuple}")     # Output: Original tuple: (5, 2, 8, 1)
print(f"Sorted tuple (as list): {sorted_tuple}") # Output: Sorted tuple (as list): [1, 2, 5, 8] (注意返回的是列表)

# reversed() - 返回迭代器
reversed_nums_iter = reversed(nums)
print(f"Reversed nums iterator: {reversed_nums_iter}") # Output: Reversed nums iterator: <list_reverseiterator object at 0x...>

# 使用迭代器
print("Reversed nums (from iterator):")
for num in reversed_nums_iter:
    print(num, end=" ") # Output: 6 2 9 5 1 4 1 3
print()

# 将迭代器转为列表
reversed_nums_list = list(reversed(nums))
print(f"Reversed nums (as list): {reversed_nums_list}") # Output: Reversed nums (as list): [6, 2, 9, 5, 1, 4, 1, 3]

reversed_chars_list = list(reversed(chars))
print(f"Reversed chars (as list): {reversed_chars_list}") # Output: Reversed chars (as list): ['n', 'o', 'h', 't', 'y', 'p']

# list.sort() - 原地修改，返回 None
nums_copy = nums[:] # 创建一个副本以防修改原始 nums
print(f"Nums copy before sort: {nums_copy}") # Output: Nums copy before sort: [3, 1, 4, 1, 5, 9, 2, 6]
return_value = nums_copy.sort()
print(f"Return value of sort(): {return_value}") # Output: Return value of sort(): None
print(f"Nums copy after sort: {nums_copy}")   # Output: Nums copy after sort: [1, 1, 2, 3, 4, 5, 6, 9]
```

#### 示例 2: `reverse` 参数

```python
nums = [3, 1, 4, 1, 5, 9, 2, 6]

sorted_desc = sorted(nums, reverse=True)
print(f"Sorted descending: {sorted_desc}") # Output: Sorted descending: [9, 6, 5, 4, 3, 2, 1, 1]

nums.sort(reverse=True) # 原地降序排序
print(f"Nums sorted in-place descending: {nums}") # Output: Nums sorted in-place descending: [9, 6, 5, 4, 3, 2, 1, 1]
```

#### 示例 3: `key` 参数应用

```python
words = ["apple", "Banana", "Cherry", "date"]

# 按长度排序
sorted_by_len = sorted(words, key=len)
print(f"Sorted by length: {sorted_by_len}")
# Output: Sorted by length: ['date', 'apple', 'Banana', 'Cherry'] (date最短, apple/Banana/Cherry一样长，保持原相对顺序)

# 按字母顺序忽略大小写排序
sorted_case_insensitive = sorted(words, key=str.lower)
print(f"Sorted case-insensitive: {sorted_case_insensitive}")
# Output: Sorted case-insensitive: ['apple', 'Banana', 'Cherry', 'date']

# 按最后一个字母排序
sorted_by_last_char = sorted(words, key=lambda word: word[-1])
print(f"Sorted by last char: {sorted_by_last_char}")
# Output: Sorted by last char: ['Banana', 'apple', 'date', 'Cherry'] (a, e, e, y) -> ('Banana', 'apple', 'date' 保持相对顺序)

# 排序字典列表
users = [
    {'name': 'Alice', 'age': 30, 'score': 85},
    {'name': 'Bob', 'age': 25, 'score': 90},
    {'name': 'Charlie', 'age': 25, 'score': 85}
]

# 按年龄升序 (主要)，年龄相同按分数降序 (次要)
# 使用元组作为 key，排序时会依次比较元组的元素
sorted_users = sorted(users, key=lambda u: (u['age'], -u['score'])) # 分数取负实现降序
print(f"Sorted users (age asc, score desc): {sorted_users}")
# Output: Sorted users (age asc, score desc): [{'name': 'Bob', 'age': 25, 'score': 90}, {'name': 'Charlie', 'age': 25, 'score': 85}, {'name': 'Alice', 'age': 30, 'score': 85}]
# Bob(25, 90) -> Charlie(25, 85) -> Alice(30, 85)
```

#### 示例 4: `reversed()` 的常见用法

```python
message = "Hello"

# 逐个打印反向字符
for char in reversed(message):
    print(char)
# Output:
# o
# l
# l
# e
# H

# 判断回文串
word = "madam"
is_palindrome = list(word) == list(reversed(word))
print(f"Is '{word}' a palindrome? {is_palindrome}") # Output: Is 'madam' a palindrome? True

word = "hello"
is_palindrome = list(word) == list(reversed(word))
print(f"Is '{word}' a palindrome? {is_palindrome}") # Output: Is 'hello' a palindrome? False
```

#### 示例 5: 注意事项 - 混合类型排序

```python
mixed_list = [3, "apple", 1, "Banana"]

try:
    # 直接排序不同类型（如 int 和 str）通常会失败
    sorted(mixed_list)
except TypeError as e:
    print(f"TypeError: {e}") # Output: TypeError: '<' not supported between instances of 'str' and 'int'

# 使用 key 将所有元素转为字符串再排序，可以避免 TypeError
sorted_mixed_as_str = sorted(mixed_list, key=str)
print(f"Mixed list sorted as strings: {sorted_mixed_as_str}")
# Output: Mixed list sorted as strings: [1, 3, 'Banana', 'apple'] (按字符串 "1", "3", "Banana", "apple" 排序)
```

---

### 7. 知识点总结与要点提炼 (Summary & Key Takeaways)

*   **`sorted(iterable, key=None, reverse=False)`:**
    *   **功能:** 对任何可迭代对象进行排序。
    *   **返回:** 一个**新的、排好序的列表**。
    *   **副作用:** **不修改**原始的可迭代对象。
    *   **参数:** `key` 指定用于比较的函数，`reverse=True` 指定降序。
    *   **特性:** 排序是**稳定**的。
*   **`reversed(sequence)`:**
    *   **功能:** 获取序列的反向访问方式。
    *   **返回:** 一个**反向迭代器** (惰性求值)。
    *   **副作用:** **不修改**原始序列。
    *   **使用:** 常用于 `for` 循环或用 `list()` 转换为反转列表。
*   **`list.sort(key=None, reverse=False)`:**
    *   **功能:** 对列表进行**原地**排序。
    *   **返回:** `None`。
    *   **副作用:** **直接修改**调用该方法的列表。
    *   **参数:** 与 `sorted()` 的 `key` 和 `reverse` 相同。
    *   **特性:** 排序是**稳定**的。
*   **`key` 函数:**
    *   极其强大的自定义排序工具。
    *   接收一个元素，返回用于比较的代理值。
    *   常用 `lambda` 表达式创建。
    *   可返回元组实现多级排序。
*   **选择哪个？**
    *   需要保留原始数据，并得到一个新的排序版本 -> 使用 `sorted()`。
    *   只需要反向遍历或得到反转列表 -> 使用 `reversed()` (可能需要配合 `list()`)。
    *   想直接修改现有列表，且不需要保留原始顺序 -> 使用 `list.sort()` (通常略快于 `sorted()`，因为它不创建新列表)。

---

### 8. 学科思想与延伸思考 (Underlying Philosophy & Further Thinking)

*   **抽象 (Abstraction):** `sorted` 和 `reversed` 完美体现了抽象的思想。你只需要告诉 Python **“做什么”**（排序、反转）以及**“基于什么标准”**（通过 `key`），而完全不需要关心**“怎么做”**（具体的排序算法 Timsort 的内部细节，或反向迭代器的实现）。这大大简化了编程。
*   **声明式 vs. 命令式:** 使用 `sorted(data, key=lambda...)` 更接近**声明式编程**——你声明了你想要的结果（一个根据特定键排序的列表）。而手动编写排序循环则属于**命令式编程**——你详细指令计算机执行每一步操作。通常声明式代码更简洁、更易读。
*   **效率与优化:** Python 的内建函数通常是用 C 语言实现的，并且经过了高度优化。Timsort 是一种混合、自适应的排序算法，对真实世界中常见的半排序数据表现尤其出色。信任并使用这些内建函数，通常比自己“重新发明轮子”更高效、更可靠。
*   **接口一致性:** `sorted` 接受任何可迭代对象，返回列表。`reversed` 接受序列（或有 `__reversed__` 的对象），返回迭代器。这种一致性使得它们可以很好地融入 Python 的数据处理生态。
*   **延伸思考:**
    *   Python 的 Timsort 算法具体是如何工作的？它为什么是稳定的并且高效的？
    *   如何根据多个标准进行排序，且每个标准的排序方向（升序/降序）不同？ (提示：`key=lambda x: (x.attr1, -x.attr2)` 可以实现 attr1 升序，attr2 降序)
    *   除了 `sorted` 和 `reversed`，Python 的 `heapq` 模块提供了哪些与排序和优先级相关的算法？（堆排序、查找最小/最大的 N 个元素等）
    *   `itertools` 模块中有哪些函数可以与 `sorted`/`reversed` 结合，实现更复杂的数据处理流程？

---

希望这次关于 `sorted` 和 `reversed` 的讲解对你有所帮助！它们确实是 Python 工具箱中非常实用和强大的工具。多练习使用 `key` 参数来解决各种排序问题，你会发现它能让你的代码变得非常优雅。如果有任何不清楚的地方，随时可以继续提问！