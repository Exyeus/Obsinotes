### 导体棒在匀强磁场中的运动分析

#### 1. 基本方程建立  
**a. 电磁感应与电路方程**  
导体棒切割磁感线产生电动势：  
$$
\mathcal{E} = BLv \quad \text{(法拉第电磁感应定律)}  
$$
  
电容器电压与电动势相等：  
$$
U_C = \mathcal{E} = BLv  
$$
  
电容器电荷量 $q$ 与速度 $v$ 的关系为：  
$$
q = C \cdot U_C = CBLv  
$$
  
电流 $i$ 由电荷变化率决定：  
$$
i = -\frac{dq}{dt} = -CBL\frac{dv}{dt} \quad \text{(放电电流方向与速度变化方向相反)}  
$$
  

**b. 动力学方程**  
安培力 $F$ 为：  
$$
F = B i L = -B^2L^2C\frac{dv}{dt}  
$$
  
根据牛顿第二定律：  
$$
m\frac{dv}{dt} = F \quad \Rightarrow \quad m\frac{dv}{dt} = -B^2L^2C\frac{dv}{dt}  
$$
  
整理得到二阶微分方程：  
$$
\frac{d^2v}{dt^2} + \frac{B^2L^2C}{m}\frac{dv}{dt} = 0 \quad \text{}  
$$
  

#### 2. 运动过程分析  
当电阻 $R = 0$ 时，方程简化为：  
$$
\frac{dv}{dt} = -\frac{B^2L^2C}{m}v  
$$
  
其解为速度随时间指数衰减：  
$$
v(t) = v_0 e^{-\frac{B^2L^2C}{m}t} \quad \text{}  
$$
  
但根据实际物理过程（如所述），导体棒因电容器放电而受到恒定安培力，导致匀减速运动，加速度为：  
$$
a = -\frac{B^2L^2C}{m} \quad \text{（恒定值）}  
$$
  
速度随时间线性变化：  
$$
v(t) = v_0 + at = v_0 - \frac{B^2L^2C}{m}t  
$$
  
当电容器放电完毕（$q=0$），导体棒速度降为零，随后反向加速充电，直到电容器电压达到极限 。  

---

### 理想点电荷的电势分析  

#### 1. 拉普拉斯方程  
在无其他电荷的空间中（点电荷外），电势 $\phi$ 满足拉普拉斯方程：  
$$
\nabla^2\phi = 0 \quad \text{（球坐标系下）}  
$$
  
对于点电荷 $q$，其电势解为：  
$$
\phi(r) = \frac{1}{4\pi\epsilon_0}\frac{q}{r}  
$$
  
该解满足拉普拉斯方程（$r \neq 0$），且电势随距离 $r$ 反比例衰减 。![](https://metaso-static.oss-cn-beijing.aliyuncs.com/metaso/pdf2texts/figures/57463348-905d-42af-a8cb-ec5f5c2f320b/8_8.jpg)
  

#### 2. 验证方程  
在球坐标系中，拉普拉斯方程展开为：  
$$
\frac{1}{r^2}\frac{d}{dr}\left(r^2\frac{d\phi}{dr}\right) = 0  
$$
  
代入 $\phi(r) = \frac{k}{r}$：  
$$
\frac{d}{dr}\left(r^2 \cdot \left(-\frac{k}{r^2}\right)\right) = \frac{d}{dr}(-k) = 0  
$$

验证成立，表明解正确。  

---

### 综合结论  
1. **导体棒运动**：  
   - 初始阶段受恒定安培力匀减速，速度线性减小至零。  
   - 后续反向加速，电容器充电，直至系统能量耗尽或结构极限 。  
2. **点电荷电势**：  
   - 满足拉普拉斯方程 $\nabla^2\phi = 0$，解为 $\phi(r) = \frac{1}{4\pi\epsilon_0}\frac{q}{r}$，随距离增大而衰减 。