$P[x]$ 中的 $f(x)$ $g(x)$ 如果被同样在这个多项式环的 $h(x)$ 整除，那么 $h(x)$ 是 $f(x)$ 和 $g(x)$ 的一个公因式。

### 最大公因式：

定义分两步走，证明亦是如此。
设 $f(x)$ $g(x)$ 在一元多项式环上，如果存在同样位于这个环的 $d(x)$，满足
1. $d(x) \mid f(x)$，$d(x) \mid g(x)$；
2. $$\forall \phi(x) \in P[x]，\mathbf{if}[\phi(x )\mid g(x),\phi (x) \mid f(x)\implies \phi(x) \mid d(x)]$$那么 $d(x)$ 称为 $f(x)$ 和 $g(x)$ 的一个最大公因式。

>在证明之中，首先务必证明这个多项式能够整除，然后再证明其他的所有多项式都能够整除这个多项式，才能判定它是 gcd
>两个多项式的首项系数为1的最大公因式是唯一确定的。

#### Theorem of Judging the GCD

for all 多项式 in $P[x]$ , say randomly $f(x)$ and $g(x)$ , there must be a *gcd* for them.
Also, the $d(x)$ can be written in the form of a combination of $f(x)$ and $g(x)$。
$$
d(x)=f(x)u(x)+g(x)v(x) \Leftrightarrow(f(x),g(x))=f(x)u(x)+g(x)v(x)
$$
**Proof**
*Lemma*
If the equation $f(x)=g(x)\times q(x)+r(x)$ is TRUE, then $f(x),g(x)$ and $g(x),r(x)$ share the same set of CDs, therefore they share the GCD as well.

*The existance of GCDs*. We should first prove the *gcds* do exist. Here in analog to the Euclid Method in Modular Arithmetic, we have the following method to prove this part of THEOREM by compute out the actual *GCD*.
We begin with
$f(x)=g(x)q_{1}(x)+r_{1}(x)$, we know what $g(x)$ and $f(x)$ are, therefore we can compute out the $r_{1}(x)$. *After this*, we use $r_{1}(x)$ to divide $g(x)$, so as to get $r_{2}(x)$. 
With this process, finally we will get, as the end of the process, an equation in the form of $$r_{s-1}(x)=r_{s}(x)\times q_{s+1}$$Then $r_{s}(x)$ is the gcd we want.
*The existance of $u(x)$ $v(x)$*. As in the equation above, $d(x)$ can be written in the form, within which are $u(x)$ and $v(x)$.
We start from  $r_{s}(x)$ , and substitute all previous formula, from the bottom to the top, and we will finally acquire a equation containing $r_{s}(x)$ on the LHS, and a mess containing $f(x)$ and $g(x)$ on the other side.
After sorting all the mess, we will *get 2 complex expressions*, representing $u(x)$ and $v(x)$ respectively, and the theorem *has been completed !*

#### Theorem for judging the Coprimality

The equivalent expression for the *coprimality* for $f(x)$ and $g(x)$ , is$$\exists u(x), v(x) \subset P[x]\implies f(x)u(x)+g(x)v(x)=1$$
>Ways to practically prove these:
>1. Find 2 polynomial satisfying the above *theorem*
>2. Assume $(f(x),g(x))=d(x)$, then try to conduct that $d(x)=1$

Also, here are a few significant facts:
1. if there are coprimaliy between $f(x),h(x)$ and $g(x),h(x)$, then also between $f(x)\times g(x), h(x)$.
2. 以邻为壑
3. 和平分裂

### GCD and Coprimality in Multi-polynomials
$$
\{ f_{i}(x) \}\subset P[x]\implies(f_{i}(x), \dots) =((f_{1}(x),\dots,f_{s-1}(x)),f_{s}(x))
$$
*The Way to prove this, along with other problems resembling to it:* Fix one side and prove the other side is equivalent.