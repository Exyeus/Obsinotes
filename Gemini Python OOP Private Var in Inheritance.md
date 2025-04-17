---
sr-due: 2025-04-12
sr-interval: 3
sr-ease: 250
---

#review 

>An deeper understanding to `super()`: Due to the inheritance, all implemented logic should be passed uneditedly to new classes.
>Therefore, it is the attribute `_Animal__name` created, instead of `__name`.
>So the terminal shows that ==no such an attribute== named `__name` !

好的同学，我们来分析一下这段面向对象编程的代码，并解答你的疑问。看到你已经在尝试通过编写和调试代码来学习，这是非常好的实践！出错了没关系，错误是最好的老师之一。

我们就从你的两个问题入手，然后扩展到一些常见的易错点。

---

### 解答你的疑问

**1. 为什么用 `pet._Animal__name` 而不是 `pet.__name`？**

*   **核心概念：名称改写 (Name Mangling)**

    在 Python 中，当你在类定义内部使用以**两个下划线 `__` 开头**（并且**不以**两个下划线结尾）的属性名（如 `self.__name`）时，Python 解释器会自动进行一种“名称改写”的操作。

    它的规则是：将 `__attributeName` 替换为 `_ClassName__attributeName`。

*   **在你的代码中：**
    *   在 `Animal` 类的 `__init__` 方法中，你写了 `self.__name = name`。因为这段代码在 `Animal` 类里，Python 自动将其改写为 `self._Animal__name = name`。
    *   `Dog` 和 `Cat` 类继承自 `Animal`。它们通过 `super().__init__(name)` 调用了父类的初始化方法，因此 `Dog` 和 `Cat` 的实例也拥有了这个被改写过的属性 `_Animal__name`。
    *   在 `Dog` 和 `Cat` 的 `play` 方法中，以及在 `PetShop` 的 `show_pets` 方法中，`pet` 是 `Dog` 或 `Cat` 的实例。我们想要访问的是那个在 `Animal` 类中定义的、逻辑上属于“动物名字”的属性。由于它在 `Animal` 类定义时被改写成了 `_Animal__name`，所以我们必须使用这个**完整的、被改写后的名字** `pet._Animal__name` 来访问它。

*   **为什么 `pet.__name` 不行？**

    如果你尝试在 `Dog` 的 `play` 方法（或 `PetShop` 的 `show_pets` 方法）中使用 `pet.__name`，Python 会尝试进行**相对于当前作用域**的名称改写。
    *   如果在 `Dog` 的方法里用 `pet.__name`，Python 会去找 `pet._Dog__name`。
    *   如果在 `PetShop` 的方法里用 `pet.__name`，Python 会去找 `pet._PetShop__name`。
    *   这些属性（`_Dog__name`, `_PetShop__name`）实际上并**不存在**，因为 `__name` 是在 `Animal` 类中定义的，只被改写成了 `_Animal__name`。因此会抛出 `AttributeError`。

*   **目的何在？**

    名称改写的主要目的是**避免子类意外地覆盖父类的“私有”属性**。它并不是真正的“私密”（因为你仍然可以用改写后的名字访问），而是一种约定，告诉其他开发者：“这个属性是内部实现细节，请谨慎直接访问或修改。”

**2. `super(Cat, self).__init__(name)` vs `super().__init__(name)`**

*   **核心概念：调用父类方法**

    在子类的 `__init__` 方法中，我们通常需要调用父类的 `__init__` 方法来确保父类定义的属性能够被正确初始化。`super()` 就是用来做这个的。

*   **两种形式：**
    *   `super(Cat, self).__init__(name)`: 这是 **Python 2** 中调用父类方法的标准语法，并且在 **Python 3** 中也**完全兼容、有效**。它明确指定了：
        1.  **当前类** (`Cat`)：`super()` 需要知道从哪个类的父类开始查找。
        2.  **当前实例** (`self`)：需要将实例传递给父类的方法。
    *   `super().__init__(name)`: 这是 **Python 3** 引入的**简化语法**。当你**在类的方法内部**使用 `super()` 时（不带任何参数），Python 3 会**自动**推断出当前的类和实例。因此，它等同于上面那种更显式的写法。

*   **它们有什么联系？**

    它们**功能上是等价的**（在 Python 3 的这个简单单继承场景下）。都是为了找到 `Cat` 的父类（即 `Animal`），并调用其 `__init__` 方法，同时把当前实例 `self` 和参数 `name` 传递过去。

*   **为什么你的代码用了第一种？**

    可能的原因：
    *   你参考的代码示例比较老，是基于 Python 2 风格编写的。
    *   编写者习惯于这种更明确的写法。
    *   在某些非常复杂的涉及多重继承的场景下，显式指定可能有助于（或被认为有助于）理解方法解析顺序（MRO），但对于你这个例子来说，完全没有必要。

*   **推荐用法：**

    如果你确定你的代码运行在 **Python 3** 环境下（现在绝大多数情况都是），**推荐使用更简洁的 `super().__init__(name)`**。它代码更少，不易出错（比如把 `Cat` 写成了别的类名）。

---

### Python 面向对象编程易错点提醒 (Exam Prep)

结合你的代码和常见问题，为你总结一些 Python OOP 的易错点，希望能帮助你下午的考试：

1.  **`__init__` 方法：**
    *   **忘记写 `__init__`：** 如果你的类需要实例特定的属性（如 `name`），通常需要定义 `__init__` 来初始化它们。
    *   **忘记 `self` 参数：** 类中的**所有**实例方法（包括 `__init__`）的第一个参数**必须**是 `self`（或者其他约定俗成的名字，但强烈推荐 `self`）。调用方法时 Python 会自动传入实例，但定义时必须写上。
        *   *易错：* `def __init__(name): ...` -> 应该写 `def __init__(self, name): ...`
    *   **在 `__init__` 中混淆局部变量和实例变量：**
        *   *错误：* `def __init__(self, name): my_name = name` （`my_name` 只是个局部变量，方法结束就没了）
        *   *正确：* `def __init__(self, name): self.name = name` （`self.name` 才是实例的属性）

2.  **继承与 `super()`：**
    *   **忘记在子类 `__init__` 中调用 `super().__init__()`：** 如果父类 `__init__` 做了重要的初始化工作（比如设置了 `self.__name`），子类不调用 `super()` 就会导致这些初始化丢失，子类实例可能状态不完整。
    *   **`super()` 使用形式：** 在 Python 3 中，优先使用 `super().__init__(...)` 而不是 `super(ClassName, self).__init__(...)`，除非有特殊理由。确保理解两者等价（在简单场景下）。
    *   **传递正确的参数给 `super().__init__()`：** 父类的 `__init__` 需要什么参数，`super().__init__()` 就应该传递什么参数。
        *   *易错：* 父类是 `__init__(self, name, age)`，子类调用 `super().__init__(name)` （漏了 `age`）。

3.  **属性访问与封装：**
    *   **直接访问实例属性要用 `self.`：** 在类的方法内部，访问当前实例的属性必须通过 `self.` 前缀。
        *   *易错：* `def speak(self): print(name)` -> 应该 `print(self.__name)` 或 `print(self._Animal__name)` (根据情况)
    *   **理解名称改写 (`__private`)：**
        *   知道 `__name` 会变成 `_ClassName__name`。
        *   知道在类**外部**或**子类**中访问这个属性时，必须使用**改写后**的名字 (`instance._ClassName__name`)。
        *   避免在不需要名称改写的地方滥用 `__` （比如只想表示“受保护”，通常用单个下划线 `_name` 作为约定即可）。
    *   **区分实例属性和类属性：**
        *   `self.x = 1` 定义在 `__init__` 中，是**实例属性**，每个对象独有。
        *   `x = 1` 直接定义在 `class MyClass:` 下面，是**类属性**，所有实例共享。

4.  **方法调用与多态：**
    *   **实例方法调用需要实例：** `my_dog = Dog("Buddy")`，然后调用 `my_dog.speak()`。不能直接用类名调用实例方法 `Dog.speak()` (除非手动传入 `self`，一般不这么做)。
    *   **理解多态：** 像 `testing_PetShop` 中那样，`pet.speak()` 会根据 `pet` 的实际类型（`Dog` 或 `Cat`）自动调用对应类的 `speak` 方法。这是多态的核心。
    *   **方法覆盖 (Overriding)：** 子类可以定义和父类同名的方法（如 `speak`），这会覆盖父类的版本。确保覆盖的方法签名（参数列表）是你想要的。

5.  **对象创建与类型检查：**
    *   **创建实例要加括号 `()`：** `my_dog = Dog("Buddy")`。忘记括号 `my_dog = Dog` 只是把类本身赋给了变量。
    *   **使用 `isinstance(object, ClassName)` 进行类型检查：** 如你的 `show_pets` 中所示，这是判断一个对象是否是某个类（或其子类）的实例的标准方式。

**针对你的报错（虽然你没贴具体报错信息，但根据代码猜测）：**

*   很可能遇到过 `AttributeError: 'Dog' object has no attribute '__name'` 或类似错误，原因就是上面解释的名称改写问题。
*   也可能遇到过 `AttributeError: 'Dog' object has no attribute '_Animal__name'`，如果是在调用 `super().__init__(name)` 之前就尝试访问它。
*   还可能遇到 `TypeError`，比如忘记在 `super().__init__` 中传递 `name` 参数。

**最后的小建议：**

*   考试时如果遇到不确定的地方，先写出你认为最直接、最符合逻辑的代码。
*   注意 `self` 的使用！
*   如果涉及继承，想想父类的 `__init__` 是否需要调用，以及如何正确调用 `super()`。
*   访问带 `__` 的属性时，想想名称改写。

祝你下午考试顺利！放松心态，把你理解的知识清晰地表达出来就好。