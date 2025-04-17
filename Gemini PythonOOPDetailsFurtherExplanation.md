---
sr-due: 2025-04-12
sr-interval: 4
sr-ease: 270
---

#review 

*Highlights*
>The process of searching attributions in classes and instances: Keeping going down to its class or *parent class*, until an attr of this name is finally found.
>A wonderful metaphor. Combining the fact mentioned above, the logic of incrementing attr in a base class will definitely has influence on the following classes and instances, as long as the `__init__` function doesnot remove relevant implementation.

这是一个非常好的问题，它触及了类（Class）和实例（Instance）之间关系的核心，以及 Python 中对象模型的一些“活性”（liveness）特征。让我们来一步步拆解。

**核心观点：类本身就是一个对象**

关键在于理解：在 Python 中，当你定义一个类 (`class Student: ...`)，你不仅仅是在写一段文本蓝图。Python 解释器执行这段代码时，会在内存中**创建一个实际的“类对象”**。这个类对象本身就包含了你在类定义中写的所有东西：

1.  **类属性 (Class Attributes):**像 `university_name = "..."` 或 `num_students = 0` 这样的变量，它们被存储在**类对象本身**上。所有这个类的实例都将**共享**这些类属性（除非实例自己有同名的实例属性）。
2.  **方法 (Methods):** 像 `__init__`, `enroll`, `display_info`, `@classmethod get_university_info` 等。这些方法的定义也存储在类对象中。

**回答你的问题：**

1.  **“也就是说，一个类被定义之后，它里面的变量和函数都是在动态发生变化的吗？”**
    *   **类属性 (Variables like `num_students`)：是动态变化的。** 因为类对象本身是活在内存中的，它的属性值可以被修改。在我们的例子中，`Student.num_students += 1` 这行代码**直接修改了** `Student` 这个类对象上存储的 `num_students` 属性的值。它不是在修改某个实例的属性，而是修改属于类本身的那个共享属性。
    *   **方法 (Functions like `__init__`)：方法本身的代码通常不会动态改变。** `__init__` 函数的代码逻辑是在类定义时就固定了的。但是，当这个方法被**调用**时（即创建一个新实例时），它内部执行的代码（比如 `Student.num_students += 1`）会作用于当前的程序状态，从而**导致类属性的值发生变化**。

    可以想象成：类对象就像一个**中央控制板**。控制板上的**标签**（方法名）和**按钮的功能**（方法代码）通常不变，但是控制板上的**显示屏读数**（类属性的值，如 `num_students`）是可以被按钮操作（方法调用）动态更新的。

2.  **“在发生某一变化之后（比如 `num_students` 增加了），再创建实例，是否该实例也能得到发生了该变化的属性？”**
    *   **对于类属性 (like `num_students`)：是的，但不完全是“得到”。** 新创建的实例**并不会复制**一份当时的 `num_students` 值作为自己的属性。相反，实例通过一种查找机制**访问共享的类属性**。
    *   **查找机制：** 当你尝试访问 `instance.attribute` 时，Python 首先查找该实例自身是否有 `attribute` 这个**实例属性**。如果没有，它会去查找实例所属的**类对象**上是否有 `attribute` 这个**类属性**。如果还没有，它会沿着继承链向上查找父类。
    *   **所以：** 当你创建一个新的 `Student` 实例 `s3` 时，如果之前的操作已经让 `Student.num_students` 变成了 2，那么当 `s3.__init__` 执行 `Student.num_students += 1` 时，它会把类对象上的值从 2 修改为 3。之后，如果你通过 `s3.num_students` 或 `Student.num_students` 去访问，你都会得到**当前最新的值** 3。新实例看到的是类属性的**实时状态**。

3.  **“如果类得到了继承（比如 `GradStudent`），那么继承得到的新类，其实例化所得是否也能够具有原来的类之中发生的改变、其实例化时可以使得原来的类之中的学生数量+1（伴随 `__init__` 方法）？”**
    *   **是的，完全正确！** 这正是 `super().__init__(...)` 发挥作用的地方。
    *   **过程：**
        1.  你创建 `GradStudent` 实例：`gs1 = GradStudent("Bob", "G001", "Dr. Turing")`。
        2.  `GradStudent` 的 `__init__` 方法被调用。
        3.  `GradStudent.__init__` 中的 `super().__init__(name, student_id)` 被执行。
        4.  `super()` 找到了父类 `Student`，并调用了 `Student` 的 `__init__` 方法，并将 `gs1` 这个**实例**（作为 `self`）以及 `name` 和 `student_id` 传了进去。
        5.  现在，**`Student.__init__` 的代码开始执行**，作用在 `gs1` 这个实例上。
        6.  在 `Student.__init__` 内部，`Student.num_students += 1` 这一行代码被执行。**注意，这里修改的仍然是 `Student` 类对象上的那个共享的 `num_students`！**
        7.  `Student.__init__` 执行完毕，控制权返回到 `GradStudent.__init__`。
        8.  `GradStudent.__init__` 继续执行，设置 `self.thesis_advisor` 和 `GradStudent.num_grad_students += 1`（修改 `GradStudent` 类自己的类属性）。
    *   **结果：** 创建一个 `GradStudent` 实例，不仅会执行 `GradStudent` 特有的初始化逻辑（如增加 `num_grad_students`），还会**通过 `super()` 调用触发执行父类 `Student` 的初始化逻辑**，包括增加那个**共享的 `Student.num_students` 计数**。这非常符合逻辑，因为一个 `GradStudent` *同时也是一个* `Student`。

**总结与类比**

*   **类对象是“活”的：** <span style="background:#b1ffff">它存在于内存中，其类属性的值可以在程序运行时被修改。</span>
*   **实例共享类属性：** 实例通常不拥有类属性的副本，而是通过查找链访问定义在类对象上的那个共享版本。这意味着它们能看到类属性的最新值。
*   **继承与`super()`：** 继承使得子类可以访问父类的属性和方法。`super().__init__` 是一种机制，让子类的初始化过程可以**调用并执行父类的初始化逻辑**，确保父类定义的共享状态（如 `Student.num_students`）也能被子类的创建过程正确更新。

把 `Student` 类想象成一个**俱乐部总部**：
*   `num_students` 是总部墙上的**总会员计数器**。
*   `__init__` 是办理**入会手续**的过程。
*   每次有人办理入会手续（创建一个 `Student` 实例），办事员（`__init__` 方法）就会去把墙上的总计数器加 1。
*   `GradStudent` 是俱乐部里的一个**特殊分部**（比如研究生分部）。
*   研究生分部有自己的计数器 (`num_grad_students`)。
*   但办理研究生分部的入会手续 (`GradStudent.__init__`) 时，流程规定必须**先**去总部按标准流程也办理一遍基础入会手续 (`super().__init__`)，所以总部的那个总计数器**也会被加 1**。
*   任何时候去看总部的计数器，看到的都是最新的总会员数。新会员加入时看到的是当前的数字，然后自己的加入会让数字再加 1。

希望这个解释能让你更清晰地理解类属性的动态性和继承中 `super()` 的作用！这确实是理解 Python OOP 中一个比较微妙但关键的点。