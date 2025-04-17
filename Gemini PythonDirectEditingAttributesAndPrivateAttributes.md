---
sr-due: 2025-04-12
sr-interval: 3
sr-ease: 250
---

#review 

*Highlights*
>All \_\_var will be automatically transformed into format : \_ClassName__Attr.
>This attribute is accessible.
>Directly adding `__var` to a class or an instance, will eliminate the layer of specific process onto the attributes: ==this \_\_var has no more special meaning.==
>\_ClassName__attr is created automatically! 
好的，我们来深入探讨一下 Python 中属性访问的这些“内部”机制，特别是带有下划线的属性，以及直接在类或实例上设置属性的行为。

---

### 1. "私有"属性 (`__attr`) 与名字改编 (Name Mangling)

**动机 (Motivation):**

在很多面向对象语言（如 Java, C++）中，有明确的 `private`, `protected`, `public` 关键字来控制属性和方法的可见性。Python 则采取了一种不同的、更“约定俗成”的方式。它没有强制的“私有”，但提供了一种机制来**避免子类意外覆盖父类的“内部”属性或方法**，这主要是为了防止命名冲突。这就是双下划线 `__` 前缀的作用。

**核心机制：名字改编 (Name Mangling)**

当你（在类的定义内部）使用双下划线 `__` 开头（但**不以**双下划线结尾）来命名一个属性或方法时（例如 `self.__value = 10` 或 `def __calculate(self): ...`），Python 解释器会在**加载类定义时**自动进行“名字改编”。

它会将这个名字 `__attr` 变换成 `_ClassName__attr` 的形式。

*   `_`：一个下划线前缀。
*   `ClassName`：当前定义这个属性/方法的类的名字。
*   `__attr`：你原来使用的名字。

**示例:**

```python
class MySecret:
    def __init__(self):
        self.public_var = "I'm public"
        self.__private_var = "Secret Revealed?" # Name mangling will happen here

    def __private_method(self): # Name mangling will happen here too
        print("Executing private method")

    def access_private(self):
        print(f"Accessing from inside: {self.__private_var}") # Inside the class, use __private_var
        self.__private_method() # Inside the class, use __private_method

# --- Let's see what happens ---
secret_obj = MySecret()
print(secret_obj.public_var) # Works fine -> I'm public

# Trying to access directly using __private_var FAILS
# print(secret_obj.__private_var) # Raises AttributeError: 'MySecret' object has no attribute '__private_var'
# secret_obj.__private_method()   # Raises AttributeError: 'MySecret' object has no attribute '__private_method'

# How to access (if you MUST, but generally DON'T): Use the mangled name
print("Accessing mangled attribute:", secret_obj._MySecret__private_var) # -> Secret Revealed?
secret_obj._MySecret__private_method() # -> Executing private method

# Calling the public method that accesses them internally works fine
secret_obj.access_private()
# Output:
# Accessing from inside: Secret Revealed?
# Executing private method

# Check the object's dictionary (internal attributes)
print(dir(secret_obj))
# You will see '_MySecret__private_var' and '_MySecret__private_method' in the list,
# but NOT '__private_var' or '__private_method' directly.
```

**关键点:**

*   **目的：** 主要目的是**避免继承中的命名冲突**。如果子类也定义了一个 `__value`，名字改编会确保父类的 `_Parent__value` 和子类的 `_Child__value` 是不同的属性，不会互相覆盖。
*   **不是真私有：** 它不是一个安全特性，只是一个**名字变换机制**。知道改编规则的人仍然可以从外部访问（如 `instance._ClassName__attr`）。Python 的哲学是“我们都是成年人”，不强制隐藏，而是提供一种避免错误的约定。
*   **何时发生：** 名字改编发生在**类定义被解释器读取时**，并且只对在 `class` 块内部定义的、以 `__` 开头（且不以 `__` 结尾）的名字有效。

---

### 2. `_ClassName__PrivateAttr` 的由来

正如上面解释的，`_ClassName__PrivateAttr` **就是** Python 对类 `ClassName` 中定义的 `__PrivateAttr` 进行**名字改编后的结果**。

你不会（也不应该）在代码中直接写 `self._ClassName__PrivateAttr = value`。你应该写 `self.__PrivateAttr = value`，然后让 Python 自动为你处理名字改编。

看到 `_ClassName__PrivateAttr` 这种形式通常是在以下情况：

*   **调试时：** 使用 `dir(instance)` 或调试器查看对象的属性时，你会看到改编后的名字。
*   **有意绕过封装时（不推荐）：** 当你需要（通常是出于特殊目的，如测试或修复）从类外部访问这个被“隐藏”的属性时，你必须使用改编后的名字。

---

### 3. 直接对类或实例进行属性更改

现在我们来分析 `CertainInstance.attr = x`, `CertainClass.attr = x` 等操作。

**基础原理：Python 的动态性与属性查找**

Python 是动态类型的语言，这意味着对象的属性可以在运行时添加、修改或删除。当你执行 `obj.attr = value` 时，Python 会：

1.  **查找：** 检查 `obj` 是否已经有一个名为 `attr` 的属性。
2.  **操作：**
    *   如果**有**，就更新该属性的值为 `value`。
    *   如果**没有**，就在 `obj` 上**创建**一个新的属性 `attr`，并将其值设为 `value`。

这个 `obj` 可以是一个**实例对象**，也可以是一个**类对象**（因为类本身也是对象）。

**分析各种情况：**

*   **`CertainInstance.attr = x` (对实例操作)**
    *   **行为：** 在名为 `CertainInstance` 的**实例**上创建或修改一个名为 `attr` 的**实例属性**。
    *   **原理：** 这是最常见的设置实例状态的方式。如果 `CertainInstance` 之前没有 `attr` 属性，这个操作会**给这个特定的实例**添加一个新的属性。如果它已经有 `attr`（可能是在 `__init__` 中创建的），则会更新该实例属性的值。
    *   **范围：** 这个更改**只影响 `CertainInstance` 这个实例**。它不影响 `CertainClass` 或其他实例。
    *   **遮蔽 (Shadowing)：** 如果 `CertainClass` 已经有一个**类属性**也叫 `attr`，那么执行此操作后，`CertainInstance` 就拥有了自己的**实例属性** `attr`。当访问 `CertainInstance.attr` 时，Python 会优先找到这个实例属性，从而“遮蔽”了同名的类属性（对于这个实例而言）。其他实例仍然会访问到类属性（除非它们也被单独设置了实例属性）。

*   **`CertainClass.attr = x` (对类操作)**
    *   **行为：** 在名为 `CertainClass` 的**类对象**上创建或修改一个名为 `attr` 的**类属性**。
    *   **原理：** 修改了类本身的属性。
    *   **范围：** 这个更改会影响 `CertainClass` **本身**，以及**所有**当前和未来创建的、且**没有**自己同名实例属性 `attr` 的实例。这些实例在查找 `attr` 时，找不到实例属性，就会沿着继承链找到类属性，因此会看到这个新设置的值 `x`。
    *   **用途：** 常用于设置所有实例共享的常量、默认值，或者像我们之前例子中那样修改共享的计数器。

*   **`CertainClass.__attr = x` (对类操作，使用 `__`)**
    *   **行为：** 在名为 `CertainClass` 的**类对象**上创建或修改一个**字面名称**为 `__attr` 的**类属性**。
    *   **原理：** **关键区别来了！** 这个赋值操作发生在**类的外部**（不是在 `class CertainClass:` 定义块内部）。因此，Python 的**名字改编机制不会被触发**。你只是简单地在 `CertainClass` 这个对象上创建了一个名为 `__attr`（两个下划线开头）的普通类属性。
    *   **与名字改编的区别：** 这个 `CertainClass.__attr` **不是** 由类内部 `self.__attr` 改编而来的那个 `_CertainClass__attr`。它们是两个完全不同的属性！
    *   **结果：** 你现在有了一个名为 `__attr` 的**类属性**，可以通过 `CertainClass.__attr` 或 `instance.__attr` (如果实例没有自己的 `__attr` 属性) 来访问。这通常不是你想要修改那个“私有”成员的方式，这样做很可能会引起混淆。

*   **`CertainInstance.__attr = x` (对实例操作，使用 `__`)**
    *   **行为：** 在名为 `CertainInstance` 的**实例对象**上创建或修改一个**字面名称**为 `__attr` 的**实例属性**。
    *   **原理：** 同样，这个赋值发生在类的外部定义，**名字改编不适用**。你只是在 `CertainInstance` 这个特定的实例上创建了一个名为 `__attr` 的普通实例属性。
    *   **范围：** 只影响 `CertainInstance`。
    *   **与名字改编的区别：** 这个 `CertainInstance.__attr` 与类定义内部通过 `self.__attr` 创建的、经过改编的 `_CertainClass__attr` 没有任何关系。它甚至会遮蔽掉通过 `CertainClass.__attr = x` 创建的那个同名的类属性（对于这个实例而言）。

**总结与对比**

| 操作                      | 目标对象 | 属性类型       | 属性名 (实际存储)   | 名字改编? | 影响范围                                     |
| :------------------------ | :------- | :------------- | :---------------- | :-------- | :------------------------------------------- |
| `self.__attr = x` (内部) | 实例     | 实例属性       | `_ClassName__attr` | **是**    | 当前实例 (通过改编后的名字存储)              |
| `CertainInstance.attr = x` | 实例     | 实例属性       | `attr`            | 否        | 仅 `CertainInstance`                         |
| `CertainClass.attr = x`    | 类       | 类属性         | `attr`            | 否        | 类及所有无同名实例属性的实例               |
| `CertainClass.__attr = x`  | 类       | 类属性         | `__attr` (字面量) | **否**    | 类及所有无同名实例属性 `__attr` 的实例     |
| `CertainInstance.__attr = x`| 实例     | 实例属性       | `__attr` (字面量) | **否**    | 仅 `CertainInstance`                         |

**核心要点回顾：**

1.  `__attr` (在类定义内部) 是为了**触发名字改编** (`_ClassName__attr`)，主要目的是**防止子类意外覆盖**，不是强制私有。
2.  访问被改编的属性需要使用**改编后的名字** (`instance._ClassName__attr`)，但这通常是**不推荐**的。
3.  **直接**在**实例**上赋值 (`instance.attr = x` 或 `instance.__attr = x`) 会创建或修改**实例属性**，只影响该实例，且**不触发**名字改编。
4.  **直接**在**类**上赋值 (`Class.attr = x` 或 `Class.__attr = x`) 会创建或修改**类属性**，影响类和所有未遮蔽该属性的实例，也**不触发**名字改编。
5.  混淆 `__attr` (在类外部赋值) 和 `self.__attr` (在类内部，会触发改编) 是常见的错误来源。它们操作的是**不同名字**的属性。

理解 Python 这种基于约定和名字改编的“私有”机制，以及类和实例属性的动态性，对于编写健壮和清晰的面向对象代码至关重要。希望这个详细解释能解答你的疑惑！