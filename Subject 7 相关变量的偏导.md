### 案例

在满足 $a=b\cos \theta$ 的直角三角形之中，求 $S=\frac{1}{2}ab\sin \theta$ 如何关于 $\theta$ 变化。

### 解决

使用全微分：
$$
dS=\frac{1}{2}a\sin \theta db+\frac{1}{2}b\sin \theta da+\frac{1}{2}ab\cos \theta d\theta
$$
1. $b$ 在 $a$ 固定的时候，如何依赖于 $\theta$ 变化？表述或许有误，应当是 $A$ 如何依赖于它们变化
	$da=0$，结合上面公式可以得到：$da=\cos \theta db-b\sin \theta d\theta=0$，于是：
	$db=b\tan \theta d\theta$
	此时再代入全微分之中，就可以得到：
	$$
	dS=\frac{1}{2}ab \frac{\sin^{2}\theta}{\cos \theta}d\theta+\frac{1}{2}ab\cos \theta d\theta=\frac{1}{2}ab\sec \theta d\theta
	$$
>注意：$a=b\cos \theta\to \frac{a}{b\cos \theta}=1$，本质上也可以看作是 $g(a,b,\theta)=c$。
>最终需要的形式，应当是 $dS=f_{1}(a,b,\theta)d\theta$，以表示关于 $\theta$ 变化
>还不够全面，应当是得到一个只有$\mathbf{d}\theta$ 的式子 ！


**另外的方法。** 表述不同但原理相同
	$$
	\frac{\partial A}{\partial \theta}_{a}=A_{\theta} \frac{\partial \theta}{\partial \theta}_{a}+A_{a} \frac{\partial a}{\partial \theta}_{a}+A_{b} \frac{\partial b}{\partial \theta}_{a}
	$$
	具体原理参见 [[subject 6 零散技巧与观点]]，注意关键结构的发掘与提炼