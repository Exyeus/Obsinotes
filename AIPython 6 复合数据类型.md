### 追踪调用情况
```python
from inspect import dis
def f(a, b):
	c = a + b
	return c
dis.dis(f)
```

```
dis.dis(f)
  1           RESUME                   0

  2           LOAD_FAST_LOAD_FAST      1 (a, b)
              BINARY_OP                0 (+)
              STORE_FAST               2 (c)

  3           LOAD_FAST                2 (c)
              RETURN_VALUE
```

>由此观之：
>函数对象赋值给函数名指定的变量
>但是不会立即将其执行
>函数体中的语句可以包含当时没有被定义的变量名

```python
def g(a, b):
     dd
     a = 1
     b = 6
     c = a * b
     print(a,b,c)
```

```
dis.dis(g)
  1           RESUME                   0

  2           LOAD_GLOBAL              0 (dd)
              POP_TOP

  3           LOAD_CONST               1 (1)
              STORE_FAST               0 (a)

  4           LOAD_CONST               2 (6)
              STORE_FAST               1 (b)

  5           LOAD_FAST_LOAD_FAST      1 (a, b)
              BINARY_OP                5 (*)
              STORE_FAST               2 (c)

  6           LOAD_GLOBAL              3 (print + NULL)
              LOAD_FAST_LOAD_FAST      1 (a, b)
              LOAD_FAST                2 (c)
              CALL                     3
              POP_TOP
              RETURN_CONST             0 (None)
```
[[Metaso_Python dis lib]]
大部分的知识不是新知，可以参见：[[CS61A 2.4 Mutable Data]]

### 序列通用操作符和函数

```python
x in s
x not in s
s + t # catenation
s * n , equiv to n*s
s[start_index: end_index_no_self]
```
```
>>> a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
>>> b = a[3:9]
>>> b
[4, 5, 6, 7, 8, 9]
>>> c = a[2:2:10]
>>> c
[]
>>> c = a[2:10:2]
>>> c
[3, 5, 7, 9]
>>> c = a[2:11:2]
>>> c
[3, 5, 7, 9, 11]
```
```python
s.index(x, [i, j])
```
[[Metaso_Python seq.index()]]

### 部分数据类型及其新知

*集合*。
- 无序组合
- 元素可以动态增加或者删除
- 使用大括号 `{}` 表示
- 可以 *过滤* 掉重复元素
- 可以使用 `set` 生成

```python
>>> a = set(1, 2, 3, 4, 5, 6, 7, 8)
Traceback (most recent call last):
  File "<python-input-0>", line 1, in <module>
    a = set(1, 2, 3, 4, 5, 6, 7, 8)
TypeError: set expected at most 1 argument, got 8
>>> a = set((1, 2, 3, 4, 5, 6, 7, 8))
>>> b = {5, 6, 7, 8, 9, 10, 11, 12}
>>> a-b
{1, 2, 3, 4}
>>> b-a
{9, 10, 11, 12}
>>> a+b
Traceback (most recent call last):
  File "<python-input-5>", line 1, in <module>
    a+b
    ~^~
TypeError: unsupported operand type(s) for +: 'set' and 'set'
>>> a & b
{8, 5, 6, 7}
>>> a ^ b
{1, 2, 3, 4, 9, 10, 11, 12}
>>> a | b
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
>>> a <= b
False
>>> c = set([1,2,3])
>>> c
{1, 2, 3}
```
>只能传入一个元素，例如元组、列表

其他方法：
`add` `clear` `pop` `remove` `discard`
`copy` `isdisjoint` `len()` `in` `not in`

*列表*。注意是 bound value to name，所以将列表赋值给另一个 *列表* 不生成新的列表对象。C的变量是一个内存空间，Python的变量是一个 *name* ，赋值语句进行 *value* 的绑定。
[[Metaso_Python list operations]]









