### 基本参数

- $\rho$：到原点的距离
- $\phi$：与 $z$ 轴正半轴所成角度
- $\theta$：投影至 $xOy$，与 $x$ 轴正半轴所成角度

理解：考虑 $r$ 为与原点连线在 $xOy$ 平面上的投影，那么有 $\rho^2=z^2+r^{2}$
于是，$z=\rho \cos \phi$，$r=\rho \sin \phi$，进一步分拆 $r$，最终得到：
$$
\begin{cases}
z=\rho \cos \phi \\
 \\
x=\rho \sin \phi \cos \theta \\
 \\
y=\rho \sin \phi \sin \theta
\end{cases} \text{ , } \begin{cases}
\rho=\sqrt{ x^{2}+y^{2}+z^2} \\
 \\
\phi=\arccos \left( \frac{z}{p} \right) \\
 \\
\theta=\arctan\left( \frac{y}{x} \right)
\end{cases}
$$
考虑进行微元体积：微元只可以得到一个曲边梯形，但是可以对这个曲边梯形进行近似。首先考虑其高度，是为 $\Delta \rho$，再考虑其底面，虽然是一个很小的曲面但是仍然可以取其长宽来作为面积：一方面，有$S_{1}=\rho \Delta \phi$，另一方面，有 $S_{2}=r\Delta \theta=\rho \sin \phi \Delta \theta$，最后得到：
$$
\Delta V \approx \Delta \rho \times \rho \Delta \phi \times \rho \sin \phi \Delta \theta
$$
$$
\Delta S=\rho \Delta \phi \times \rho \sin \phi \Delta \theta
$$
$$
\Delta V_{cone}=\frac{1}{3}\rho \Delta S=\frac{1}{3}\rho \times \rho \Delta \phi \times \rho \sin \phi \Delta \theta
$$
由第三个式子，可以进一步求出球的体积公式。
