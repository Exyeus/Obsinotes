# 7.1
# 7.2
### 函数原型之用
- 函数原型的作用就是告诉编译器，这里有一个函数需要他去解析。在圆形中可以确定参数的数据类型，编译器在读取这个原函数的定义之后，就可以设置一些检查机制，让接下来注意运行。如果不是这个数据，就会报错。
- 一个操作：在计算$\frac{LARGE}{LARGE}$的时候，可以分子分母匹配相除然后再乘起来，避免OVERFLOW。

# 7.3 函数与数组
传入数组作为参数的本质是数组首位对应的那个指针。类比其他函数调用结构体等等类型时传递指针，来减少空间占用，保障数据安全。
#### 具体操作
- 填充数组 可以选择VOID或者回显一些报告信息
- 显示数组  `void show_array(const double ar[], int n)` 理解为什么不需要在方括号里面填写数字了吗？同时，传递二维数组就需要在第二个维度上标记数字，否则编译器将无法划分这个线性数据结构。
- 修改数组 可用`void` 或者 `OTHER TYPE`
#### 技巧
- 指定区间的数组传入 使用 `head pointer` `tail pointer` to use this _2 pointers_ to mark the range of the array _to be analysed_
> 此处注意传入数据的维护原则, 可以考虑创建`temp` `int * new_pter` 来做到, 处理数据的同时不会改变不应改变的数据
> `for (ptr = begin; ptr != end; ptr++) total = total + *ptr`

- 指针与`const`联动-几种情形
	- const 指针 -> 普通变量 `不能使用指针修改变量,但是可以直接修改`
	- const 指针 -> const变量 不改
	- 指针 -> const 变量 INVALID , 除非使用强制类型转换
	- const 二阶指针 -> 非const指针
# 7.4
#### 函数与二维数组
等价写法
```cpp
int sum(int ar[][4]) == int sum(int (*ar)[4])
ar2[r][c] == *(*(ar2 + r) + c)
```
>其中, `ar2 + r` is the ** dereference of the array that contains array, we * it to get the int array it points to.
>Then we add it up with c, to point to the inner index of this array, and we again use * to call the value it contains.

# 7.5 Functions and C-style string-array
### 一种非常有用的写法
```cpp
while (*str)
{
	statements; *str++;
} 只要字符不是空字符'\0' , *str 的数值就不是0, 这样循环就可以继续下去
```
>联系之前的办法, 可以使用`while (cin.get(char))` , 利用`cin`系列的一些返回值来做到在一定的读取条件下完成循环并且适时终止.
### 返回C-Style字符串的函数
原理就在于返回字符串首位的指针. 

# 7.6 Functions and Costomized Structure
[[按引用传递]]
Review
>结构体的用法: 直接用, 或者使用 `struct Student array[N]`, 创建一堆没有名字但是好用的数组. 这些数组直接名字加下标来访问即可.
>`struct Student *function()` 定义一个返回`student`结构的函数
>在排序中的应用--我的评价是仍然不如去排序二阶指针
>一个中心原则就是指针动一下比它指向的东西动一下, 动静要小得多的时候就应当考虑使用指针来传递\调用\排序

```cpp
struct travel
{
	int t1; int t2;
}
travel time_statics(travel figure1, travel figure2)
这里 travel 是一个结构定义, 这个函数接受两个结构作为参数, 同时返回一个经过其处理的结构!
```
#### 数学库中关于坐标的一些函数
- `atan2(y,x)` To  calculate the angle based on $\arctan \frac{y}{x}$.
#### 一种连续读取两个变量的办法 #输入输出
```cpp
while (cin>>rplace.x>>rplace.y)
解释?使用cin>>rplace.x的时候,调用一个函数,返回一个istream值.
```

# 7.7 函数与string对象
string对象与结构比较相似, 满足结构赋值给结构, 对象赋值给对象等操作.
可以创建string对象数组

# 7.8 函数与array对象
```cpp
std::array<double, 4> expenses;
show_detail_but_not_edit(expenses);
edit(&expenses);
void fill(std::array<double, VALUE>* var)
```

# 7.9 递归
几个要点:
- 每个递归都创建自己的一套变量 检测办法: 要求显示变量的地址 #实验验证
- 用于将一份工作不断分成规模更小的工作, 就可以用到递归

# 7.10 函数指针-用指针调用函数 #qsort 
```cpp
double pam(int) // Declare the prototype
double (*pf)(int)
// double *pf(int) is not ideal, due to the sequence in which symbols follows, this means define a function that returns [double *],a pointer to [double] Datatype
pf = pam // The level is the same, pf is a pointer to the same type that pam belongs to
 ``` 
 函数名字, 不带括号就是其地址, 类比数组没有 \[\] 就会被视为地址和指针看待
 >容忍逻辑上无法自圆其说的观点正是人类思维活动的特点

### 深入探讨函数指针
>REVIEW
>在函数原型之中, `const double array[] === const double *araay`
>由于可以省略 **标识符** , `const double array[] === const double[]` 
>`const double *array = const double *`