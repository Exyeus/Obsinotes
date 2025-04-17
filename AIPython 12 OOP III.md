### The process of finding attributes and methods

1. lookup them in *instance* attributes
>This has the top priority, therefore covering the *class attributes*

2. If 1 failed, lookup in class attributes
3. If 2 failed, lookup in *parent class attributes*.

>If an attribute, of function type, then an attribute whose type is *method* will be automatically returned.
>[[Deepseek_FunctionAttrAndMethodReturn]]
>
>This process is dynamically completed while the program is running.
>
>Difference between method and function. methods have the *instance* as its first argument `self`. Therefore under certain circumstance, an instance must be passed into, as a parameter.

Methods serve as controlling and utilizing the data within objects. 

### MRO

Method Resulution Order.
```python
# 多重继承
class A:
    def greet(self):
        return "Hello from class A"
  
class B(A):
    def greet(self):
        return "Bonjour from class B"
  
class C(A):
    def greet(self):
        return "Hola from class C"
  
class D(B, C):
    pass
  
obj_D = D()
print(D.mro())
print(obj_D.greet())
```

```
[<class '__main__.D'>, <class '__main__.B'>, <class '__main__.C'>, <class '__main__.A'>, <class 'object'>] Bonjour from class B
```

Subclasses go first.
MRO gains its support from certain algorithm
`D B C A` is the sequence while calling to these. 

Another example.
```python
class A:
    def method(self):
        print("A method")
  
class B(A):
    def method(self):
        print("B method")
        super().method()
  
class C(A):
    def method(self):
        print("C method")
        super().method()
  
class D(B, C):
    def method(self):
        print("D method")
        super().method()
  
obj = D()
print(D.mro())
obj.method()
```

```
[<class '__main__.D'>, <class '__main__.B'>, <class '__main__.C'>, <class '__main__.A'>, <class 'object'>] 
D method 
B method 
C method 
A method
```

This is more intuitively compelling.

### Duck Typing.

*When a bird walks, swims, squeals all similar to a duck, then it can be called as a duck*.

Therefore, we implement a 2D array class to understand this.
[[Metaso_DuckTyping]]


















