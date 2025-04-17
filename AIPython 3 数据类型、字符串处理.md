---
sr-due: 2025-04-12
sr-interval: 3
sr-ease: 250
---

#review 
### 浮点数

常用表示：+- x.xx
科学记数法：$a E/e b$ $a \times 10^b$
同样的话题：数值范围、小数精度

### 复数

用 Object 角度看待问题
`z.real` `z.imag` 注意Python使用 `@property` 来做到将函数在访问属性的时候调用并且 `return` 出结果。
### 类型转化

```python

float(5)-> 5.0

int(5.6)-> 5

# The exceeded part should be truncated

```
可以用到的函数
- abs
- divmod
- round
- max
- min
- complex
### Math 库
以下是Python `math`库中的一些常用函数及其说明，整理成表格形式：

| 函数名                | 数学表示                                          | 描述                     |     |         |
| ------------------ | --------------------------------------------- | ---------------------- | --- | ------- |
| `math.fabs(x)`     | $                                            | x                      | $  | 返回x的绝对值 |
| `math.ceil(x)`     | $\lceil x \rceil$                           | 向上取整，返回不小于x的最小整数       |     |         |
| `math.floor(x)`    | $\lfloor x \rfloor$                         | 向下取整，返回不大于x的最大整数       |     |         |
| `math.trunc(x)`    |                                               | 截断x的小数部分，返回整数部分        |     |         |
| `math.modf(x)`     |                                               | 返回x的小数部分和整数部分          |     |         |
| `math.exp(x)`      | $e^x$                                       | 返回e的x次幂，e是自然对数         |     |         |
| `math.log(x)`      | $\ln(1+x)$                                  | 返回x的自然对数，只输入x时         |     |         |
| `math.log2(x)`     | $\log_2 x$                                  | 返回x的2对数值               |     |         |
| `math.log10(x)`    | $\log_{10} x$                               | 返回x的10对数值              |     |         |
| `math.sqrt(x)`     | $\sqrt{x}$                                  | 返回x的平方根                |     |         |
| `math.pow(x, y)`   | $x^y$                                       | 返回x的y次幂                |     |         |
| `math.sin(x)`      | $\sin x$                                    | 返回x的正弦函数值，x是弧度值        |     |         |
| `math.cos(x)`      | $\cos x$                                    | 返回x的余弦函数值，x是弧度值        |     |         |
| `math.tan(x)`      | $\tan x$                                    | 返回x的正切函数值，x是弧度值        |     |         |
| `math.asin(x)`     | $\arcsin x$                                 | 返回x的反正弦函数值，x是弧度值       |     |         |
| `math.acos(x)`     | $\arccos x$                                 | 返回x的反余弦函数值，x是弧度值       |     |         |
| `math.atan(x)`     | $\arctan x$                                 | 返回x的反正切函数值，x是弧度值       |     |         |
| `math.hypot(x, y)` | $\sqrt{x^2 + y^2}$                          | 返回(x,y)坐标到原点(0,0)的距离   |     |         |
| `math.sinh(x)`     | $\sinh x$                                   | 返回x的双曲正弦函数值            |     |         |
| `math.cosh(x)`     | $\cosh x$                                   | 返回x的双曲余弦函数值            |     |         |
| `math.tanh(x)`     | $\tanh x$                                   | 返回x的双曲正切函数值            |     |         |
| `math.asinh(x)`    | $\text{arsinh } x$                          | 返回x的反双曲正弦函数值           |     |         |
| `math.acosh(x)`    | $\text{arcosh } x$                          | 返回x的反双曲余弦函数值           |     |         |
| `math.atanh(x)`    | $\text{arctanh } x$                         | 返回x的反双曲正切函数值           |     |         |
| `math.erf(x)`      | $\frac{2}{\sqrt{\pi}} \int_0^x e^{-t^2} dt$ | 高斯误差函数，应用于概率论、统计学等领域   |     |         |
| `math.erfc(x)`     | $1 - \text{erf}(x)$                         | 余补高斯误差函数               |     |         |
| `math.gamma(x)`    | $\int_0^\infty x^{t-1}e^{-x} dx$            | 伽玛（Gamma）函数，也叫欧拉第二积分函数 |     |         |
| `math.lgamma(x)`   | $\ln(\gamma(x))$                            | 伽玛函数的自然对数              |     |         |

这些函数覆盖了基本的数学运算、三角函数、双曲函数、对数函数、指数函数以及一些特殊函数，适用于各种科学计算和工程应用。

- 包含对数据的操作函数
- 包含数学上的计数计算函数
### 字符串操作

*字符串运算*。
- + 与 \* 以进行连接
- len 以计算长度
- str 以 coerce up

*字符串操作*。
- 替换与大小写转换
- `for _ in` 以遍历之

*格式化处理*。
- 格式化输出：`f""` `"..".format()` `"%d %d", para1, para2`
- 格式控制
	填充 对齐 宽度 精度

### 字符串案例

```python
import time
scale = 10
for i in range(scale + 1):
	a = "**"*i
	b = ".." * (scale - i)
	c = (i / scale)*100
	print("%{0:^3.0f}[{1}->{2}]".format(c, a, b))
	time.sleep(0.2)
print("The process terminates")
```

输出结果：
```python
% 0 [->....................]
%10 [**->..................]
%20 [****->................]
%30 [******->..............]
%40 [********->............]
%50 [**********->..........]
%60 [************->........]
%70 [**************->......]
%80 [****************->....]
%90 [******************->..]
%100[********************->]
```

### 区分“回车`\r`”与“换行`\n`”

前者是把打印头定位到这一行的左边界，后者是将“纸张”下移一行。
- Unix 系统：换行
- Windows：回车加换行
- Mac：回车
```python
>>> import time 
>>> for i in range(101):
...     print("\r{:3}%".format(i),end="")
...     time.sleep(0.1)
...
100%
```