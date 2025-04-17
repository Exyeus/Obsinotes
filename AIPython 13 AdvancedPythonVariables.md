---
sr-due: 2025-04-12
sr-interval: 3
sr-ease: 250
---

#review 
### Summary for OOP

继承：
–在OOP 中定义一个class 时，可以从某个现有的class继承，新的class 称 为子类(subclass)，而被继承的class 称为基类、父类或超类(base class， super class)。
–继承：一个派生类(derived class)继承基类的字段和方法，即子类获得了 父类的全部功能。
–举例：Dog类继承Animal类

•多态：
–为不同数据类型的实体提供统一的接口。
–相同的消息给予不同的对象会引发不同的动作

类属性vs.实例属性
–类属性：绑定在类上的属性 
	•将函数绑定在类上，即可定义方法
–实例属性：绑定在实例上的属性 
	•用来保存和实例有关的数据和信息 
•属性（和方法）查找过程:
	–首先，在实例属性中查找（所以同名实例属性会覆盖类属性）
	–然后，在类属性中查找
	–然后，在父类属性中查找（继承的实现机制）
	–若在类或父类属性中找到一个类型为函数的属性，则自动返回一个类型为方 法的属性
	–注意：该查找过程是在程序运行时动态完成的 
		•动态绑定 
		•动态查找

对象创建：
–如果父类的构造函数已经包含了参数，子类调用父类的构造函数时需要 给与正确的参数

### Dive deeper into variables

相等性 
	• \==：比较对象所存储的数据的值是否相等 
	• is: 比较两个变量是否都<font color="#ffff00">引用了同一个对象</font>
[[Grok3_GRoEForPythonAndJava]]

### Recycling Variables

Objects contain a calculator for reference, counting currently how many *variables* have been bounded to this object.
*Therefore*, except for some small and frequently-used objects cached in Python, most of the variables will be recycled if the referenced-time of them is *0*.
```python
a = list()
a = "hello"
	** then the list is recycled.
```

### Variables and Invariables

*Variables*. `list` `dict` `set` `deque` `defaultdict`
*Invariables*. `number` `str` `tuple` 

[[Deepseek_PythonInvariablesAnalysis]]
[[Deepseek_PythonVariablesAnalysis]]

```
>>> name='Python'
>>> id(name)
1991974571920
>>> name+='Python'
>>> id(name)
1991981082480
>>> a = 1212121
>>> id(a)
1991980834256
>>> a = a + 1
>>> id(a)
1991980834384
```

>Even a simple adding and assigning will change the variable address!

```python
>>> id(t[0])
1991981084160
>>> id(t)
1991980887936
>>> id(t[0][0])
140727274832808
>>> id(t[0][1])
140727274832840
>>> id(t[0][1])
140727274832840
>>> id(t[0][2])
140727274832904
>>> id(t[0])
1991981084160
>>> id(t)
1991980887936
```

>Though tuple is not mutable, the elements inside it can mutate.
>Question: why `t[0] += [4]` leads to error, while `t[0].append(4)` leads to no warning?

[[Deepseek_顶层对象概念]]
[[Deepseek_DiveDeeperIntoImmutablity]]

可变与不可变指的是顶层对象不可变
–不可变是指所包含<span style="background:#d3f8b6">对象的标识符</span>不能发生改变 
•也就是每个元素对应的id值不动
–但是如果元素本身可以被修改，则不限制

### Copy Module

```python
from copy import copy, deepcopy
```

The method `copy` will create a new object.
Using `=` to assign creates no new object, and it is the same object that b and a refer. Copy 
```python
>>> from copy import copy, deepcopy
>>> tt = (1, 2, 3)
>>> tt1 = copy(tt)
>>> id(tt)
1991980703488
>>> id(tt1)
1991980703488
>>> tt2 = deepcopy(tt)
>>> id(tt2)
1991980703488
>>> id(tt3)
1991980703488
```

>For immutable tuple, all the four operation return the same result: bounding a new name to the existing `tt`

```python
>>> ll = [1, 2, 3]
>>> ll1 = ll
>>> ll2 = copy(ll)
>>> ll3 = deepcopy(ll)
>>> id(ll)
1991981110656
>>> id(ll1)
1991981110656
>>> id(ll2)
1991980697600
>>> id(ll3)
1991981110464
```

>Default copy pattern for lists: shallow copy
>Using `=` to copy lists, results in bounding a new name to the existing list object.

*Special Property that `deepcopy` holds*
```python
>>> a = [1, 2]
>>> id(a)
1991981106368
>>> b = [a, 3]
>>> id(b)
1991981113664
>>> ab1 = b
>>> id(ab1)
1991981113664
>>> id(b[0])
1991981106368
>>> id(ab1[0])
1991981106368
>>> ab2 = copy(b)
>>> id(ab2)
1991981111488
>>> id(ab2[0])
1991981106368
>>> ab3=deepcopy(b)
>>> id(ab3)
1991981114880
>>> id(ab3[0])
1991981107776
```

>When using `deepcopy`, the id of the inner list `a` also changes, while using `copy` can not reach this effect!

### The pattern of passing args in Python func

The *only* supported way in Python for passing arguments, is *call by sharing*, passing the '<font color="#ffff00">copy</font>' of the *object* you want to pass in.
All the formal paras, actually receive the copies of references. The formal paras are another name of the actual paras.

*Avoid using mutables as functions' default parameters*. 

PPT 介绍的是 Python 中默认参数的陷阱，特别是可变对象（如列表）作为默认参数时会导致的“幽灵车”问题。结合代码来看：

#### 代码分析：

```python
class HauntedBus:
    def __init__(self, passengers=[]):
        self.passengers = passengers
	** the [] becomes a shared default parameter!
	** because of the shallow copy, 
	** the [] will be bounded to bus2 and bus3
	** at the same time!
```

- 这里 `passengers=[]` 作为默认参数，在函数定义时就已经计算并存储，而不是每次实例化 `HauntedBus` 时重新创建新的列表。
    

```python
bus1 = HauntedBus(['Alice', 'Bill'])
bus1.pick('Charlie')
bus1.drop('Alice')
print('bus1上的乘客:', bus1.passengers)
```

- `bus1` 传入了一个乘客列表 `['Alice', 'Bill']`，不会受默认参数影响，操作一切正常。
    

```python
bus2 = HauntedBus()
bus2.pick('Carrie')
print('bus2上的乘客:', bus2.passengers)
```

- `bus2` 没有传入 `passengers` 参数，因此 `self.passengers` 绑定了默认的空列表 `[]`，`bus2.pick('Carrie')` 修改的就是这个默认列表。
    

```python
bus3 = HauntedBus()
print('bus3上的乘客:', bus3.passengers)
bus3.pick('Dave')
print('bus2上的乘客:', bus2.passengers)
```

- `bus3` 也没有传入 `passengers`，所以它的 `self.passengers` 也是绑定到同一个默认列表 `[]`。当 `bus3.pick('Dave')` 执行后，这个默认列表被修改，因此 `bus2.passengers` 也变成了 `['Carrie', 'Dave']`。
    

```python
print('bus2是否为bus3的对象:', bus2.passengers is bus3.passengers)
```

- 由于 `bus2.passengers` 和 `bus3.passengers` 共享同一个默认列表，输出 `True`，说明它们是同一个对象。
    

```python
print('bus1上的乘客:', bus1.passengers)
```

- `bus1.passengers` 是 `['Bill', 'Charlie']`，不受影响，因为 `bus1` 传入了自己的乘客列表。
    

#### PPT 文字解析：

1. **实例化 `HauntedBus` 时，如果传入乘客，会按预期运行。**
    
    - 例如 `bus1 = HauntedBus(['Alice', 'Bill'])`，它有自己的列表，操作不会受影响。
        
2. **如果不为 `HauntedBus` 指定乘客的话，奇怪的事情就发生了，这是因为 `self.passengers` 变成了 `passengers` 参数默认值的别名。**
    
    - 例如 `bus2 = HauntedBus()` 和 `bus3 = HauntedBus()` 共享了同一个默认列表，`bus2.pick('Carrie')` 和 `bus3.pick('Dave')` 影响的是同一个列表。
        
3. **出现这个问题的根源是，默认值在定义函数时计算（通常在加载模块时），因此默认值变成了函数对象的属性。**
    
    - Python 仅在定义 `HauntedBus` 类时计算 `passengers=[]`，所以 `[]` 作为类属性共享给所有未指定 `passengers` 参数的实例。
        
4. **如果默认值是可变对象，而且修改它的值，那么后续的函数调用都会受到影响。**
    
    - `bus2` 和 `bus3` 的 `self.passengers` 都指向了同一个 `[]`，修改其中的元素会影响所有使用默认参数的实例。
        

#### 解决方案：

应该避免使用可变对象作为默认参数，改成：

```python
class HauntedBus:
    def __init__(self, passengers=None):
        if passengers is None:
            passengers = []
        self.passengers = passengers
```

这样，每次 `HauntedBus()` 实例化时，都会创建一个新的 `passengers` 列表，避免幽灵车的问题。