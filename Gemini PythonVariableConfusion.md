---
sr-due: 2025-04-12
sr-interval: 4
sr-ease: 270
---

#review 

>`global` can be written at the beginning of each function, to tell the function to operating the var with this `very name` in global scope.
>`nonlocal` is usually used in nested function. Then, its parent scope is often not the `global`, therefore it is natural to use this to order the function to access the var in the direct parent frame with this very name.
好的，同学！很高兴和你一起探索 Python 中一个非常基础但也极其重要的概念——**变量的作用域 (Scope)**。很多初学者，甚至有些有经验的开发者，有时也会在这里遇到困惑。别担心，我们会像剥洋葱一样，一层一层地揭开它的面纱，从直观的感觉开始，逐步深入核心。

**学科领域:** CS61A (Composing Programs) / 编程语言基础

---

### 1. 引入与动机 (Hook & Motivation)

想象一下，你在写一个稍微复杂点的 Python 程序，里面有几个函数。你定义了一个变量 `x` 在程序的开头，然后在一个函数 `func` 里面，你又用到了 `x`。这时，你可能会问：

*   `func` 里面用的 `x` 是外面那个 `x` 吗？
*   如果我在 `func` 里面给 `x` 赋一个新的值，外面的 `x` 会变吗？
*   为什么有时候我明明在外面定义了 `x`，但在函数里用它却报错了？

比如看这段代码：

```python
message = "Hello from outside!"

def greet():
    # 试图打印外部的 message
    print(message)

greet() # 输出: Hello from outside!

def try_modify_message():
    # 看起来是想修改外面的 message
    message = "Hello from inside!"
    print(message)

try_modify_message() # 输出: Hello from inside!
print(message)       # 输出: Hello from outside!  <-- 咦？为什么外面的没变？

count = 10
def counter():
    # 想让计数器加 1
    # print(count) # 如果取消这行注释，下一行会怎样？
    count = count + 1 # <-- 这里可能会出问题！
    print(count)

# counter() # 如果调用会发生什么？(很可能会报错!)
```

这些疑问和潜在的错误，都直指一个核心概念：**作用域**。

**学习作用域的重要性：**

*   **避免 Bug:** 理解变量在哪里可见、在哪里可以被修改，是避免 `UnboundLocalError` 等常见错误的关键。
*   **编写清晰的代码:** 清晰的作用域规则让你的代码更容易被理解和预测。你知道函数内部的操作是否会影响到外部，反之亦然。
*   **有效管理状态:** 特别是在复杂的程序中，你需要知道信息（状态）存储在哪里，以及如何在不同部分之间安全地共享和修改它。`global` 和 `nonlocal` 就是管理这种共享的工具。

简单来说，搞懂作用域，就像是给你的代码世界建立清晰的“地址系统”，让你能准确地找到和使用每一个“居民”（变量）。

---

### 2. 必要知识回顾 (Prerequisite Review)

在我们深入作用域之前，我们只需要快速回顾两个基本概念：

*   **函数定义与调用 (Function Definition & Call):**
    *   我们使用 `def` 关键字来定义一个函数，例如 `def my_function(): ...`。
    *   使用函数名加上括号 `()` 来调用函数，例如 `my_function()`。
    *   关键点：每次调用函数时，Python 会为这次调用创建一个**新的、临时的执行环境**（可以想象成一个短暂的工作空间），函数内部的操作通常在这个环境中进行。
*   **变量赋值 (Variable Assignment):**
    *   使用 `=` 符号将一个名字（变量名）**绑定 (bind)** 到一个值（对象），例如 `x = 10`。这个名字 `x` 之后就可以用来引用那个值 `10`。

记住这两点，特别是函数调用会创建新的环境，对于理解作用域非常有帮助。

---

### 3. 直观解释与感性认识 (Intuitive Explanation)

**作用域，本质上就是变量的“有效范围”或者说“可见区域”。**

想象一下你的程序是一栋大楼：

*   **内建作用域 (Built-in Scope):** 这是大楼的**外部公共空间**，像空气、阳光一样无处不在。这里住着 Python 内置的函数和常量，比如 `print()`, `len()`, `True`, `False`。你在任何地方都可以直接使用它们。
*   **全局作用域 (Global Scope):** 这是大楼的**大厅**。你在 `.py` 文件顶层（即不在任何函数内部）定义的变量，都住在这里。这个大厅里的变量，在整个程序运行期间通常都存在。
*   **局部作用域 (Local Scope):** 大楼里有很多**独立的房间**。每次你调用一个函数，Python 就会临时创建一个新的、独立的房间。函数内部定义的变量（包括函数的参数）就住在**这个房间**里。当函数执行结束，这个房间和里面的东西（局部变量）通常就消失了。
*   **嵌套函数作用域 (Enclosing Scope):** 有时候，一个房间里面可能还套着另一个**小隔间**（即一个函数定义在另一个函数内部）。对于小隔间来说，外面的那个房间就是它的“外层作用域”或“父房间”。

**变量查找的直观规则：**

当你（Python 解释器）在代码的某个地方需要用到一个变量 `x` 时，你会怎么找它？

1.  **先在当前房间 (Local Scope) 找：** 是不是我这个房间里就有个叫 `x` 的？
2.  **如果当前房间没有，去父房间 (Enclosing Scope) 找：** 如果我在一个小隔间里，就去外面的大房间找找看有没有 `x`。（如果有多层嵌套，就一层层往外找）
3.  **如果父房间还没有，去大厅 (Global Scope) 找：** 去程序顶层定义的变量里找找有没有 `x`。
4.  **如果大厅也没有，去公共空间 (Built-in Scope) 找：** 是不是 Python 内建的某个名字叫 `x`？
5.  **如果连公共空间都没有：** 那就没办法了，只能告诉你“名字 `x` 未定义”(NameError)。

这个由内向外的查找过程，就是 Python 寻找变量的基本直觉。

---

### 4. 逐步形式化与精确定义 (Gradual Formalization)

现在，我们把刚才的直观比喻，用更精确的术语来描述。Python 查找变量遵循的规则被称为 **LEGB 规则**：

*   **L (Local):** 本地作用域。指当前函数或代码块内部。当你在函数内部定义一个变量（包括函数参数），它默认就属于这个作用域。
*   **E (Enclosing function locals):** 嵌套函数的本地作用域。指包含当前函数的**外层函数**的作用域。Python 会从直接外层开始，一层层向外查找。只有在嵌套函数（一个函数定义在另一个里面）的情况下，这个作用域才存在。
*   **G (Global):** 全局作用域。指模块（通常就是你的 `.py` 文件）顶层的命名空间。在函数外部定义的变量通常属于这个作用域。
*   **B (Built-in):** 内建作用域。包含了 Python 预先定义的函数（如 `print`, `len`）和常量（如 `True`, `None`）。

**查找顺序：** Python 严格按照 **L -> E -> G -> B** 的顺序查找变量名。一旦找到，就停止查找。

**关键点：变量的创建与作用域的确定**

*   **读取变量：** 遵循 LEGB 规则查找。
*   **赋值变量 (`=`):** 这是最容易混淆的地方！
    *   默认情况下，如果在一个函数内部对一个变量进行**赋值**操作（例如 `x = 100`），**并且没有使用 `global` 或 `nonlocal` 声明**，Python 会**假定** `x` 是一个**局部变量 (Local Scope)**。
    *   如果此时局部作用域中还**没有** `x`，赋值操作会**创建**一个新的局部变量 `x`。
    *   如果局部作用域中**已经有** `x`，赋值操作会**更新**这个局部变量 `x` 的值。
    *   **重要：** 这个决定是在 Python **编译**（技术上是生成字节码）阶段做出的。只要函数体里有对 `x` 的赋值，`x` 就被认为是局部的（除非有 `global` 或 `nonlocal`）。

---

### 5. 核心原理与推导过程 (Core Principles & Derivation Walkthrough)

#### 5.1 为什么默认赋值只影响局部？

这是 Python 设计的一个核心原则，旨在**保护函数的封装性**。函数应该像一个独立的“黑箱”，它的内部操作不应该轻易地、意外地修改外部的状态（全局变量或外层函数的变量）。如果函数内的赋值默认会修改外部变量，代码会变得非常混乱且难以追踪。

想象一下，如果你调用一个库函数，它内部恰好用了一个和你全局变量同名的变量，并且修改了它，你的全局状态就被意外污染了！默认创建局部变量的行为避免了这种情况。

#### 5.2 `UnboundLocalError`: 令人困惑的错误

我们来看之前那个 `counter` 函数的例子：

```python
count = 10 # Global count

def counter():
    # 尝试读取 count，但 Python 已经决定 count 是局部的了
    print(f"Current count (before increment): {count}") # <-- 如果取消这行注释，会在这里报错
    # 因为下面这行赋值，Python 在编译时就认为 count 是 counter 函数的局部变量
    count = count + 1
    print(f"New count: {count}")

# counter() # 调用会触发 UnboundLocalError
```

**为什么会报错？**

1.  **编译阶段：** Python 查看 `counter` 函数的代码，发现了 `count = count + 1` 这行赋值语句。因为它没有 `global` 或 `nonlocal` 声明，Python 就**标记** `count` 为 `counter` 函数的一个**局部变量**。
2.  **运行阶段：** 当 `counter()` 被调用时：
    *   执行到 `print(f"Current count: {count}")`（如果取消注释）或者 `count = count + 1` 的右侧 `count + 1` 时，Python 需要**读取** `count` 的值。
    *   根据 LEGB 规则，它首先在**局部作用域 (L)** 查找 `count`。
    *   但问题是，虽然 Python 知道 `count` 应该是个局部变量，但在执行到需要读取它的那一步时，这个**局部的 `count` 还没有被赋值**（赋值操作 `count = ...` 还没执行完呢！它需要先计算右边的值）。
    *   因此，Python 无法找到一个已经绑定了值的**局部** `count`，于是抛出 `UnboundLocalError: local variable 'count' referenced before assignment`。

**关键理解：** 这个错误不是因为找不到全局的 `count`，而是因为它认为 `count` 是局部的，但这个局部的 `count` 在被读取时尚未初始化（赋值）。

#### 5.3 `global` 关键字：打破局部限制，操作“大厅”变量

如果我们确实**想要**在函数内部修改全局变量 `count` 怎么办？这时就需要明确告诉 Python 我们的意图。

**目的：** 声明“我接下来要操作的 `count`，不是局部的，而是那个全局作用域（大厅）里的 `count`。”

**用法：** 在函数顶部使用 `global 变量名`。

```python
count = 10 # Global count

def counter_global():
    global count # <-- 告诉 Python: 下面的 'count' 指的是全局变量
    print(f"Global count before: {count}")
    count = count + 1 # 现在这个赋值操作会修改全局的 count
    print(f"Global count after: {count}")

counter_global() # 输出: Global count before: 10, Global count after: 11
print(f"Count outside function: {count}") # 输出: Count outside function: 11 <-- 全局的确实变了！
```

**机制：**

*   `global count` 声明之后，函数内所有对 `count` 的**读取**和**赋值**操作，都会直接指向**全局作用域 (G)** 中的那个 `count`。
*   赋值 `count = ...` 不再创建局部变量，而是修改全局变量。
*   读取 `count` 时，如果全局 `count` 存在，就读取它的值。

**为什么要显式声明？** 为了代码清晰和安全。它提醒阅读代码的人（包括未来的你）：“注意，这个函数会修改全局状态！”

#### 5.4 `nonlocal` 关键字：操作“父房间”变量（嵌套函数专属）

现在考虑嵌套函数的情况：

```python
def outer():
    x = "outer variable"

    def inner():
        # 我们想在 inner 函数里修改 outer 函数的 x
        # 如果直接写 x = "inner modification" 会怎样？
        # x = "inner modification" # 这会创建一个 inner 函数的局部变量 x
        
        # 使用 nonlocal 来声明
        nonlocal x # <-- 告诉 Python: 下面的 'x' 指的是最近的外层函数(outer)的 x
        print(f"Inner sees x as: {x}")
        x = "modified by inner"
        print(f"Inner changed x to: {x}")

    inner()
    print(f"Outer sees x as: {x}") # <-- x 在 outer 里也被改变了

outer()
# 输出:
# Inner sees x as: outer variable
# Inner changed x to: modified by inner
# Outer sees x as: modified by inner
```

**目的：** 在**嵌套函数**内部，声明“我接下来要操作的 `x`，不是局部的，也不是全局的，而是那个**最近的、非全局的外层函数作用域 (Enclosing Scope)** 里的 `x`。”

**用法：** 在内层函数中使用 `nonlocal 变量名`。

**机制：**

*   `nonlocal x` 声明之后，内层函数对 `x` 的**读取**和**赋值**会指向**最近的外层函数作用域**（也就是 `outer` 函数的局部作用域）中的 `x`。
*   赋值 `x = ...` 不会创建 `inner` 的局部变量，而是修改 `outer` 的变量 `x`。
*   Python 会从当前函数（`inner`）的直接外层（`outer`）开始查找 `x`。如果 `outer` 没有 `x`，它会继续向更外层查找（如果还有嵌套），但**不会**查找到全局作用域 (G) 或内建作用域 (B)。如果在任何外层非全局作用域都找不到 `x`，使用 `nonlocal x` 会报错。

**与 `global` 的对比：**

*   `global` 是“一步登天”，直接跳到最顶层的**全局作用域**。
*   `nonlocal` 是“向外走一步（或几步）”，只查找**外层函数的作用域**，停在第一个找到的地方，且**不会**越过全局作用域的边界。

**为什么需要 `nonlocal`？**

它主要用于**闭包 (Closure)** 的场景。闭包允许一个内层函数“记住”并访问其外层函数作用域中的变量，即使外层函数已经执行完毕。`nonlocal` 使得这个内层函数不仅能读取，还能**修改**它所记住的那个外层变量的状态。我们稍后看的 `counter_maker` 例子就是典型的闭包应用。

---

### 6. 示例与应用 (Examples & Application)

让我们通过更多例子来巩固理解。

**示例 1: LEGB 规则演示**

```python
x = "I am global"

def outer_func():
    x = "I am outer" # 在 outer 的 Local Scope 定义 x

    def inner_func():
        # x = "I am inner" # 试着取消注释这行，看看输出会怎么变

        # 查找 x:
        # 1. inner 的 Local (L)? -> 没有（如果上面一行注释掉了）
        # 2. outer 的 Enclosing (E)? -> 有！是 "I am outer"
        # 停止查找，使用 outer 的 x
        print(f"Inner sees: {x}")

    inner_func()
    # 在 outer 函数内查找 x:
    # 1. outer 的 Local (L)? -> 有！是 "I am outer"
    print(f"Outer sees: {x}")

outer_func()
# 在全局作用域查找 x:
# 1. Global (G)? -> 有！是 "I am global"
print(f"Global sees: {x}")

# 输出 (当 inner_func 内部的 x 被注释时):
# Inner sees: I am outer
# Outer sees: I am outer
# Global sees: I am global
```

**示例 2: `UnboundLocalError` 重现与修复**

```python
items = [1, 2, 3]

def process_items_buggy():
    # 意图：如果 items 为空，就赋一个默认值
    if not items:
        items = [-1] # <-- 这行赋值使得 items 被认为是局部的
    print(f"Processing: {items}") # <-- 如果一开始 items 不为空，这里会尝试读取局部的 items，但它未被赋值

# process_items_buggy() # 如果 items=[1,2,3] 调用，会 UnboundLocalError

def process_items_fixed():
    global items # 明确指出我们要操作全局的 items
    if not items:
        items = [-1]
    print(f"Processing: {items}")

items = [] # 让全局 items 为空
process_items_fixed() # 输出: Processing: [-1]
print(f"Global items now: {items}") # 输出: Global items now: [-1]

items = [1, 2, 3] # 恢复全局 items
process_items_fixed() # 输出: Processing: [1, 2, 3]
print(f"Global items now: {items}") # 输出: Global items now: [1, 2, 3]
```

**示例 3: `nonlocal` 与闭包 - 计数器工厂**

这个例子展示了 `nonlocal` 的典型用途：在闭包中维护状态。

```python
def counter_maker():
    """创建一个新的、独立的计数器函数。"""
    count = 0 # 这个 count 属于 counter_maker 的局部作用域 (Enclosing for increment)

    def increment():
        """增加计数并返回当前值。"""
        nonlocal count # 声明：我要修改的是 counter_maker 的 count
        count += 1
        return count

    # 返回内部函数 increment。
    # 这个返回的函数“记住”了它被创建时的环境，包括那个 count 变量。
    # 这就是闭包！
    return increment

# 创建第一个计数器
counter1 = counter_maker()
print(f"Counter 1: {counter1()}") # 输出: Counter 1: 1
print(f"Counter 1: {counter1()}") # 输出: Counter 1: 2

# 创建第二个计数器，它是独立的
counter2 = counter_maker()
print(f"Counter 2: {counter2()}") # 输出: Counter 2: 1
print(f"Counter 1: {counter1()}") # 输出: Counter 1: 3 (第一个计数器不受影响)
```
在这个例子中，`counter_maker` 每调用一次，就创建一个新的 `count` 变量和 `increment` 函数。返回的 `increment` 函数（闭包）持有对其“出生环境”中 `count` 的引用。`nonlocal` 使得这个 `increment` 函数能够修改它所持有的那个特定的 `count`。

**示例 4: 常见陷阱 - 循环变量与延迟绑定 (Subtle Point related to Scope & Timing)**

这严格来说不完全是作用域问题，但与变量何时被查找（求值）密切相关，经常让初学者困惑。

```python
functions = []
for i in range(3):
    # 创建一个 lambda 函数，它打印变量 i
    # 问题：lambda 函数体里的 'i' 并非在创建时就被固定下来
    functions.append(lambda: print(f"Value is {i}"))

# 循环结束后，i 的值是 2
print(f"Loop finished, i is {i}") # 输出: Loop finished, i is 2

# 现在调用这些函数
print("Calling the functions:")
for f in functions:
    # 当 f() 执行时，它才去查找 'i' 的当前值
    # 此时循环早已结束，i 的最终值是 2
    f()

# 输出:
# Loop finished, i is 2
# Calling the functions:
# Value is 2
# Value is 2
# Value is 2  <-- 都输出了 2！

# --- 正确的做法：利用默认参数值捕获当前 i 的值 ---
functions_fixed = []
for i in range(3):
    # 使用默认参数 current_i = i
    # 默认参数的值在函数定义（lambda 创建）时就被计算和绑定了！
    # 这相当于为每次循环创建的 lambda 绑定了当时的 i 值
    functions_fixed.append(lambda current_i=i: print(f"Correct value is {current_i}"))

print("\nCalling the fixed functions:")
for f in functions_fixed:
    f()

# 输出:
# Calling the fixed functions:
# Correct value is 0
# Correct value is 1
# Correct value is 2
```
这个陷阱告诉我们，函数（包括 lambda）捕获的是变量本身（引用），而不是变量在定义那个时刻的值。除非使用像默认参数这样的技巧来强制在定义时就获取并存储值。

---

### 7. 知识点总结与要点提炼 (Summary & Key Takeaways)

让我们把关于 Python 作用域的核心内容梳理一下：

*   **作用域 (Scope):** 一个变量能够被访问的代码区域。决定了变量的可见性和生命周期。
*   **LEGB 规则:** Python 查找变量的顺序：
    1.  **L**ocal (函数内部)
    2.  **E**nclosing function locals (嵌套函数的外层)
    3.  **G**lobal (模块顶层)
    4.  **B**uilt-in (Python 内建)
*   **赋值行为:** 在函数内对变量赋值 (`x = value`) **默认创建或修改局部变量**。这是为了保护函数封装性。
*   **`UnboundLocalError`:** 当你尝试读取一个 Python 认为是局部变量、但该局部变量在读取时尚未被赋值时发生。通常是因为函数内稍后有对该变量的赋值语句。
*   **`global` 关键字:**
    *   用途：在函数内部声明，意图是**访问和修改全局作用域**中的变量。
    *   效果：使后续对该变量的读写操作直接作用于全局变量。
*   **`nonlocal` 关键字:**
    *   用途：在**嵌套函数**内部声明，意图是**访问和修改最近的外层（非全局）函数作用域**中的变量。
    *   效果：使后续对该变量的读写操作作用于那个外层函数的变量。
    *   常用于闭包中修改被捕获的外层变量。
*   **`global` vs `nonlocal`:** `global` 直达顶层全局；`nonlocal` 向外层查找（但不包括全局）。
*   **重要性:** 清晰理解作用域对于编写正确、可维护、无意外副作用的 Python 代码至关重要。

---

### 8. 学科思想与延伸思考 (Underlying Philosophy & Further Thinking)

*   **封装 (Encapsulation):** 作用域是编程中实现封装思想的基础工具之一。函数默认拥有自己的局部作用域，将内部实现细节和变量隐藏起来，只通过参数和返回值与外部交互。这降低了代码的复杂度，减少了命名冲突，使得代码模块化和重用成为可能。`global` 关键字某种程度上打破了这种封装，因此应谨慎使用，仅在确实需要修改全局状态时才用。
*   **状态管理 (State Management):** 程序的核心就是管理状态（数据）以及状态的变化。作用域规则定义了状态存储在哪里（哪个作用域）、谁可以访问它、谁可以修改它。`global` 提供了一种简单（但有时危险）的全局状态管理方式。`nonlocal` 结合闭包，提供了一种更精巧、更受控的方式来管理那些不适合放在全局、但又需要在某个函数及其内部函数间共享的状态。
*   **闭包 (Closures) 的本质:** 思考一下 `counter_maker` 的例子。为什么 `increment` 函数在 `counter_maker` 执行完毕后，仍然能访问并修改那个 `count` 变量？因为 Python 函数不仅仅是一段代码，它还携带了一个对其**定义时所在环境**（包括外层作用域中的变量）的引用。这个“函数代码 + 环境引用”的组合，就是闭包。`nonlocal` 正是操作这个被“记住”的环境中变量的钥匙。
*   **延伸思考:**
    *   如果有多层嵌套函数，`nonlocal` 会修改哪一层外层函数的变量？（答案：最近的那一层含有该变量的）
    *   在类 (Class) 的方法 (Method) 内部，变量查找规则是怎样的？（提示：实例变量 `self.x` 和局部变量 `x` 是不同的，方法内的局部变量查找仍然遵循 LEGB，但访问实例或类变量有特定方式）。
    *   除了函数，Python 中还有哪些结构会创建新的作用域？（例如：类定义、列表推导式在 Python 3.x 中有自己的作用域）。

---

希望这次讲解能帮助你透彻理解 Python 的变量作用域！记住，理解规则背后的“为什么”——比如封装性、状态管理的需要——比死记硬背 LEGB 这几个字母更重要。多写些小程序，动手试试 `global` 和 `nonlocal`，亲自触发并解决 `UnboundLocalError`，你会掌握得更快、更牢固。

如果在学习过程中还有任何疑问，随时都可以再提出来！