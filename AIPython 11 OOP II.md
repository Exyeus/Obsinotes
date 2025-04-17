### Access

What are the advantages of *class method* over direct external access and edition?
>In the method built inside of a class, you can check the argus to avoid exceptions.

>vars starts with __ means unaccessible
>vars start with __ and end with __ are *special variables*

### Attributes

Because of python's property as a dynamic lan, *Instances* derived from *Classes* can be bounded with attributes freely.


```python
>>> class A():
...     name = 'A'
...     age = 19
...
>>> P1 = A()
>>> P1.name
'A'
>>> P1.age
19
>>> A.belongto = "TULIN"
>>> P1.belongto
'TULIN'
>>>
```
>Once a class is edited, the instances from it, either before or after, are able to access this newly-added property.

```python
>>>> A.name = 'Tim'
>>> P1.name
'Tim'
```

Seemingly that any changes work.

*Urgent Clarification*. The attributes defined *directly* under the definition clause of the class, are *class attributes*, in contrast to which are the *instance attributes*, those defined within the `__init__` function.
Be careful when choosing names for the two, *DO NOT* apply the same name for a *class attribute* and an *instance attribute*.

### Inheritance and Polymorphism

```key concepts
subclass
base class / super class
```

*Judge the type of a variable*
```python
isinstance(var, certain_type)
```
[[Metaso_DifferenceBtnTypeIsinstance]]
>In above link, when judging simple structure, like `int` or `float` , maybe `type` is a better choice. Notice that expression can be written as below: 
>`type(a, (int, float))

*An example of polymorphism*.
```python
def run_animal(animal):
	animal.run()

run_animal(Animal)
run_animal(Dog())
run_animal(Cat())
```

>Does using `Dog()` and `Cat()` means that, pass an instance into the function, rather than a class?

During the inheritance, the subclass will inhert the `__init__` method from its parent. If more attributes are desired, just edit the `__init__` method.
Similarly, editing special methods of existing classes, also receives a highly costomized outcome.

*Aquiring the info of an object*
- use `type` to judge
- use `dir` to acquire all attributes and methods of an object, and the return value is of `str` type.

Also, there are methods for operating the attributes.
`hasattr`
[[Metaso_ClassOperationMethods]]

``









