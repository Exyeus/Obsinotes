---
sr-due: 2025-05-19
sr-interval: 25
sr-ease: 250
---

#review 
### 不可约多项式

定义：在数域 $P[x]$ 上，注意能不能分解跟数域有很大的关系。
1. $\partial p(x)\geq 1$
2. $p(x)$  不能进一步分解为两个次数更低的多项式.

*可约多项式*。如果可以写成两个次数更低的多项式的乘积。$f(x)=f_{1}(x)\times f_{2}(x)$。其中两个次数都要更低。次数不能相等，又大于零，称之为 *真因式*。

>是否可约要注意数域。
>任何数域，一次的多项式都不可约。
>不可约还硬要写成两个多项式的乘积，那么其中之一必定为 *零次多项式*。

*类似质数的一个定理*。
$p(x)$ 是一个不可约多项式，那么对于一切这个数域上面的多项式 $f(x)$ ，它和 $p(x)$ 之间的关系只有两种可能：
1. $p(x) \mid f(x)$
2. $(p(x),f(x))=1$

*“All in” 定理*。
还是这个 $p(x)$ $\forall f(x) \text{ , }g(x),\mathbf{if }(p(x) \mid f(x)g(x))\implies p(x) \mid f(x) \text{ , }\mathbf{or} p(x) \mid p(x)|g(x)$
因为 $p(x)$ 不可以进一步分割，所以其作除法只可以 All in。
但是它可以除掉这里面不止一个多项式。
我的意思是，如果 $p(x)$ 可以分拆，那么不同的部分归于不同的被除多项式的不同部分，那么就不能单个除掉。
可以理解为，只有一个 boss，只要能够 WIN，那么随便拿一个队员来，都可以 WIN。
推广，对于 $\prod f_{i}(x)$，同样成立！

### 因式分解以及唯一性定理

$P[x]$ 上面的，次数大于1的多项式都可以分解为这个数域上面的若干个 *不可约* 多项式的乘积。证明使用 *第一归纳法* 与 *第二归纳法*。

#### 推论
1. $P[x]$ 上面任意一个多项式 $f(x),\partial(f(x))\geq 1$，那么存在 $p(x)$，使得 $p(x) \mid f(x)$。

### 标准分解式
$$
f(x)=Cp_{1}^{r_{1}}(x)\times p_{2}^{r_{2}}(x)\times \dots \times p_{s}^{r_{s}}(x), 1\leq r_{i},i=1,2,\dots,s
$$
*推论*。
1. $(f(x),g(x))$
2. $[f(x),g(x)]$

>经常使用这个标准分解式来说明结构，从结构上进行构造来证明问题

### 重因式

*形式微商*。性质如同导数，但是本质并非*连续的实变量*，而是一如多项式定义中的，仅仅是字符和文字。

*与求导规则相印证的定理*。
数域 $P[x]$ 上，多项式$p(x)$ 是 $f(x)$ 的 $k(k\geq 1)$ 重因式，那么它必然是一阶微商的 $k-1$ 重因式。
*推广*：
1. 先决条件相同，那么，$p(x)$ 是 $f^{i}(x)(i\leq k-1)$ 的公因式。
2. $p(x)$ 是 $f(x)$ 的重因式 $\Leftrightarrow$ $p(x)$ 是$f(x)$ 和 $f'(x)$ 的公因式
3. $f(x)$ 没有重因式的充分必要条件是，$(f(x),f'(x))=1$。

#### 去除重因式
$$\frac{f(x)}{(f(x),f'(x))}=p_{1}(x)\times p_{2}(x) \times \dots \times p_{s}(x)$$
这个式子变形之后可以用于构造一个没有重因式的多项式

>$f(x)=(x-a)^n$ $\Leftrightarrow f'(x) \mid f(x)$

