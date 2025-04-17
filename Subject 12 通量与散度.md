### 通量 *Flux*

类比做功, 通量是*垂直于*轨迹的场的分量所做之功。
$$
W=\oint_{C}\left \langle M(x,y),N(x,y) \right \rangle\cdot\left \langle dx,dy \right \rangle=\oint \mathbf{F}\cdot \mathbf{\hat{T}}ds
$$
$$
\mathbf{Flux}=\oint \mathbf{F}\cdot  \hat{\mathbf{N}}ds
$$
这里注意，由于研究曲线是逆时针沿着曲线，而指向曲线外部的法向量变成了顺时针旋转 90°而得到 $\hat{n}$ ，进而得到线积分的变式，并且从其中提取出散度 *divergence*。
指向曲线外的是正，指向曲线内的，是负。无论正负，$dx$ $dy$ 的相对正负性不变。

### 散度 *Divergence*

$$
\mathbf{div}=\frac{\partial M}{\partial x}+\frac{\partial N}{\partial y}
$$
$$
\oint_{c}\mathbf{F}\cdot\mathbf{n}ds=\iint_{R}\mathbf{div}\mathbf{F}dA
$$
>$\mathbf{F\cdot n}=Md-Ndx$：经过C的F的通量
>$\mathbf{divF}=\left( \frac{\partial M}{\partial x}+\frac{\partial N}{\partial y} \right)$：R的源泉

[[Metaso_区域性质与公式的成立]]
