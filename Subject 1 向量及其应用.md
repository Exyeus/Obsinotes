---
sr-due: 2025-09-20
sr-interval: 164
sr-ease: 290
---

#review 
# 基本公式

$$
\begin{array}
\\v_{1}\times v_{2}\implies v_{3}\text{ , } \lvert v_{3} \rvert = \lvert v_{1} \rvert\lvert v_{2} \rvert   \text{ , 并且 , }v_{3}是一个垂直于v_{1}v_{2}所在平面的向量 \\
 \\
混合积:v_{1}\cdot(v_{2}\times v_{3})=v_{2}\cdot(v_{1}\times v_{3})=v_{3}\cdot(v_{1}\times v_{2})\text{ , }并且最终得到平行六面体的体积:\begin{vmatrix}
v_{11} & v_{12} & v_{13} \\
v_{21} & v_{22} & v_{23} \\
v_{31} & v_{32} & v_{33}
\end{vmatrix}
\end{array}
$$
# 应用 - Kepler's Second Law

### 进阶公式

$$

\\ \frac{d}{dt}(r \cdot s)=\frac{dr}{dt}\cdot s+r\cdot \frac{ds}{dt} \\$$
$$
\frac{d}{dt}(r\times s)=\frac{dr}{dt}\times s+\frac{ds}{dt}\times t
$$

如何理解 ? 类似各种运算定律的验证方法, 直接用*合适的符号表达* + 展开化简, 即可得到这一简洁的表达.
```
具体的求解过程, 通过(Δr + r)x(Δs + s) - r x s 获得
```
这些运算和函数的乘法运算, 在运算定律上大体是类似的, 但是要注意前后顺序的调换限制.
好在, 这里似乎并不会影响最终结果,

在 [[Subject 3 摆线及参数方程]] 提到, 参数方程对应向量的加减, 得到的乃是直来直去, 甚至接近于垂直于 原点-参数点 构成的向量.
因此, 可以用 $\Delta r\times r$ 来描述面积的变化量.由此, 得到
$$
\Delta SWEEP=\frac{1}{2}\lvert R\times \Delta R \rvert \implies \frac{2(\Delta SWEEP)}{\Delta T}=\left\lvert  R\times \frac{\Delta R}{\Delta T}  \right\rvert 
$$
其中, 根据 $A = dV/dT$, 有
$$
\frac{\Delta R}{\Delta T}=V\implies R\times V 是常数\implies \frac{d(R\times V)}{dT}=0=V\times V+R\times A = R\times A
$$
所以加速度一直都只是平行于这个用来扫面积的向量, 因此

```
行星在理想的模型之下运行, 处于一个固定的平面之中.
```
