### 1. 方法作为属性查找的动态特性

在 Python 中，当你访问一个实例属性时，如果该属性是一个函数，Python 会自动将其转换为一个"方法"（method）对象。这个过程是动态完成的。

```python
class MyClass:
    def my_method(self):
        return "Hello"

obj = MyClass()

# 直接访问类属性 - 这是一个函数
print(MyClass.my_method)  # <function MyClass.my_method at 0x...>

# 通过实例访问 - 这是一个方法
print(obj.my_method)  # <bound method MyClass.my_method of <__main__.MyClass object at 0x...>>
```

### 2. 父类方法调用子类属性和方法

Python 的方法解析顺序（MRO）允许父类方法调用子类中定义的属性和方法，这类似于 C++ 中的虚函数。

```python
class Parent:
    def parent_method(self):
        print("Parent method calling:", self.child_method())

class Child(Parent):
    def child_method(self):
        return "Child's method"

c = Child()
c.parent_method()  # 输出: Parent method calling: Child's method
```

### 3. 类似 C++ 虚继承的行为

在 Python 中，所有方法本质上都是"虚"的，因为方法查找总是在运行时动态解析。

```python
class Animal:
    def speak(self):
        print("Animal sound")

class Dog(Animal):
    def speak(self):
        print("Bark")

class Cat(Animal):
    def speak(self):
        print("Meow")

def make_sound(animal):
    animal.speak()  # 具体调用哪个speak方法在运行时决定

make_sound(Dog())  # 输出: Bark
make_sound(Cat())  # 输出: Meow
```

### 方法解析顺序（MRO）示例

Python 使用 C3 线性化算法来确定方法查找顺序：

```python
class A:
    def method(self):
        print("A")

class B(A):
    def method(self):
        print("B")
        super().method()

class C(A):
    def method(self):
        print("C")
        super().method()

class D(B, C):
    def method(self):
        print("D")
        super().method()

d = D()
d.method()
# 输出:
# D
# B
# C
# A
```

这个例子展示了 Python 的多重继承和方法解析顺序，`super()` 调用会根据 MRO 链找到下一个类的方法。

这些特性使得 Python 的面向对象编程非常灵活，方法调用总是动态解析的，支持多态和灵活的继承结构。