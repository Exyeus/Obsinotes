### Lambda 表达式

定义匿名函数，通常将表达式赋值给一个名称。

### Python 的查找机制

```python
def f1():
	f2()
def f2():
	print("f2 has been called")
f1()
```

Python是动态的解释语言，不会像C那样进行预编译，而是会在调用到那个函数，有需要的时候才会开始查找，因此不需要 被 call 的函数在 call 之的函数前面！查找名字的背后是一个复杂的过程。
- 首先在局部变量里面
- 找不到，就去上一级代码块，直到没有 `indent` 的全局变量
- 在函数内部进行复制操作，那么默认这个变量是一个局部变量
- 使用 `global` 语句，改变赋值操作的默认，不生成局部变量
- 一个变量不可以既是 `global` 又是 `local`。

### 可变数量参数

```python
def vfunc(a, *b):
	print(type(b))
	for n in b:
		a += n
	return a
vfunc(1,2,3,4,5)
```

>这样的参数，必须放在参数列表最后
>所有超出 a 对应的变量的变量，包括第二个变量，都会被打包成为一个元组，然后传入函数之中。

### 函数的返回值

```python
def func(a, b):
	return a*b
s = func("ruc!", 2)
print(s)
>>> ruc!ruc!
def func(a, b):
	return b, a
s = func("ruc!", 2)
print(s, type(s))

>>>(2, 'ruc!')<class 'tuple'>
```

### 函数里面的局部变量

```python
n = 1
def func(a, b):
	global n # The existence of this expression greatly determines the final output
	n = b
	return a*b
s = func("ruc!", 2)

>ruc!ruc! 1 without global n
>ruc!ruc! 2 with global n
```

>这个情形，本质上是所处理的变量是一个 `primitive`，
>而当全局变量是一个 `compound type` 的时候，只要你不在函数里面进行赋值，就不会创建新的，而是应用全局变量
>一个关键的判断依据：是否在赋值表达式的左边！

### datetime 库

![[Pasted image 20250303214414.png]]

![[Pasted image 20250303214439.png]]