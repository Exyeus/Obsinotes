### 基本符号表示
$$
S=qd+r\implies r=S \bmod d
$$
>We define x mod m to be the remainder r when we divide x by m

$$
x\bmod d=y\bmod d\implies x\equiv y(\bmod d)  \Leftrightarrow m |(x-y)
$$

### 计算法则

$$
\begin{cases}
a\equiv c(\bmod m) \\
 \\
b\equiv d (\bmod m)
\end{cases}\implies \begin{cases}
ab\equiv cd(\bmod m) \\
 \\
a+b\equiv c+d(\bmod m) \\
 \\
a-b\equiv c-d(\bmod m)
\end{cases}
$$
### 可用结论：

1. Remainder，range(0, m)，并且具有周期性，如果以 Remainder 的持续递增作为变量。
2. 一个应用示例。
$$
(13+11)\times 18 \begin{array}\
\equiv(6+4)\times 4(\bmod 7) \\
\equiv 10\times 4 (\bmod 7) \\
\equiv 3 \times 4 (\bmod 7) \\
\equiv 12 (\bmod 7)
\end{array}
$$
### 对幂求模
```python
def mod_exp(x, y, m):
	if y == 0:
		return 1
	else:
		z = mod_exp(x, y//2, m)
		if y%2 == 0:
			return (z * z % m)
		else:
			return x*z*z % m
print(mod_exp(2,4,3))
```
