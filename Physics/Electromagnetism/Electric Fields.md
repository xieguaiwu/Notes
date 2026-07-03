---
tags:
  - Physics
  - 定义性
  - 证明
title: Electric Fields
created: 2026-06-10
modified: 2026-06-30
---

# Electric Fields

> [!abstract] 电场
> 电场是电荷周围存在的物理场，对置于其中的其他电荷施加力的作用。电场是电磁场的重要组成部分，是理解电磁学的核心概念。

> [!tip] 💡 一句话直觉
> 电场就像**一个电荷在周围空间撒下的「无形力网」**——你放一个试探电荷进去，它立刻感受到一个力。电场强度就是「单位电荷感受到的力的大小」。越靠近电荷，网越密（力越大）；越远，网越疏（力越小）。

## 电场强度 (Electric Field Intensity)

> [!note] 定义
> 电场强度定义为置于该点的**检验电荷** $q_0$ 所受电场力与其电荷量的比值：
> $$\vec{E} = \lim_{q_0 \to 0} \frac{\vec{F}}{q_0}$$
> 
> - 单位：$\text{N/C}$ 或 $\text{V/m}$
> - 方向：正电荷所受力的方向

> [!question] 🤔 为什么是"微小正检验电荷"（small positive test charge）？
>
> 电场定义中的检验电荷 $q_0$ 有**两个严格约束**：
>
> 1. **正（positive）** — 电场方向**约定**为**正**电荷所受力的方向（direction of force on a *positive* charge）。若用负电荷测，受力方向相反，电场方向将反号——所以这个约定保证 $⃗{E}$ 的方向唯一且直观。
> 2. **小（infinitesimally small, $q_0 \to 0$）** — 检验电荷必须足够小，以**不干扰原电场分布**（without disturbing the original field）。若 $q_0$ 太大，它会极化附近导体/电介质、或重分布自由电荷，使测得的场偏离真实的原电场。极限 $\lim_{q_0 \to 0}$ 就是数学上表达"无限小，但不为零"。
>
> 这个思想实验（thought experiment）贯穿整个电磁学：用一个**理想探针**（ideal probe）去测量物理量，探针本身不应改变被测系统。

### 库仑定律与点电荷电场 (Coulomb's Law → Point Charge Field)

点电荷的电场公式可从**库仑定律**（Coulomb's law）直接导出：

$$
\vec{F} = \frac{1}{4\pi\varepsilon_0} \frac{q \, q_0}{r^2} \hat{r} \quad \Longrightarrow \quad \vec{E} = \frac{\vec{F}}{q_0} = \frac{1}{4\pi\varepsilon_0} \frac{q}{r^2} \hat{r}
$$

即：库仑定律给出两个点电荷间的力 → 除以检验电荷 $q_0$ → 得到源电荷 $q$ 产生的电场。

> [!info] 🎯 单位矢量 $\hat{r}$（Unit Radial Vector）
> $\hat{r}$（读作"r-hat"）是**径向单位矢量**（unit radial vector），表示从源电荷（source charge）指向场点（field point）的方向，长度为 1。
> $$\hat{r} = \frac{\vec{r}}{|\vec{r}|}$$
> 它只标明**方向**，不携带大小信息。点电荷电场公式中用 $\hat{r}$ 而不用 $\vec{r}$，是因为场强大小已由 $\frac{1}{4\pi\varepsilon_0}\frac{q}{r^2}$ 表达，$\hat{r}$ 仅负责指明电场的方向（正电荷向外、负电荷向内）。

> [!info] 🧷 真空介电常数 $\varepsilon_0$（Vacuum Permittivity）
> $$\varepsilon_0 = 8.854 \times 10^{-12} \,\text{C}^2/(\text{N·m}^2)$$
> - **物理含义**：衡量真空"允许"电场线通过的能力——$\varepsilon_0$ 越大，同样电荷产生的电场越弱
> - **为什么有 $\varepsilon_0$**：库仑定律 $F = \frac{1}{4\pi\varepsilon_0}\frac{q_1 q_2}{r^2}$ 中的 $4\pi$ 是特意引入的，为的是让高斯定律 $\oint \vec{E} \cdot d\vec{A} = Q_{\text{enc}}/\varepsilon_0$ 形式简洁（无需 $4\pi$ 系数），而非巧合
> - **与光速的关系**：$\varepsilon_0$ 与真空磁导率 $\mu_0$ 共同决定了光速——$c = 1/\sqrt{\mu_0\varepsilon_0}$，这个关系直接**预言了光就是电磁波**

### 点电荷的电场 (Point Charge Field)

$$\vec{E}(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \frac{q}{r^2} \hat{r}$$

### 电场叠加 (Superposition of Electric Fields)

$$\vec{E}(\vec{r}) = \frac{1}{4\pi\varepsilon_0} \sum_{i=1}^n \frac{q_i}{|\vec{r} - \vec{r}_i|^2} \hat{\mathcal{R}}_i$$

## 电场线与电通量

### 电场线 (Electric Field Lines)

> [!tip] 电场线性质
> - 电场线从正电荷出发，终止于负电荷
> - 电场线的切线方向表示电场方向
> - 电场线的**密度**表示电场强度的大小
> - 电场线不会相交
> - 静电平衡时，电场线垂直于导体表面

> [!example] 🌍 类比：电场线 = 水流线
> 想象一张地形图：等高线密集的地方坡度陡，稀疏的地方坡度缓。电场线也是同理——**密集处场强大，稀疏处场强小**。电场线的方向就是正电荷受力的方向，好比水流的方向。

```mermaid
graph TD
    subgraph "电场线示例"
        direction LR
        A[正电荷 +] --> B[负电荷 -]
    end
```

### 电通量 (Electric Flux)

> [!note] 定义
> 电通量是电场通过某一曲面的"流量"度量：
> $$\Phi_E = \int_S \vec{E} \cdot d\vec{A} = \int_S E\cos\theta \, dA$$
> 
> 其中 $d\vec{A}$ 的方向为曲面的法线方向。

## 电荷密度 (Charge Density)

实际带电体常需描述电荷在空间中的**分布密集程度**，有三种电荷密度：

| 类型 | 符号 | 定义 | 电荷元 | 单位 | 适用场景 |
|------|------|------|-------|------|---------|
| **线电荷密度** (linear charge density) | $\lambda$ | $\lambda = \dfrac{dq}{dl}$ | $dq = \lambda\,dl'$ | $\text{C/m}$ | 细长带电体（杆、环、线） |
| **面电荷密度** (surface charge density) | $\sigma$ | $\sigma = \dfrac{dq}{dA}$ | $dq = \sigma\,dA'$ | $\text{C/m}^2$ | 带电薄板、导体表面 |
| **体电荷密度** (volume charge density) | $\rho$ | $\rho = \dfrac{dq}{dV}$ | $dq = \rho\,dV'$ | $\text{C/m}^3$ | 三维带电体（球、柱） |

> [!tip] 💡 从离散到连续
> 点电荷是理想化模型；真实物体中的电荷是连续分布的。将电荷离散求和 $\sum$ 替换为积分 $\int$，电荷元 $dq$ 按分布类型代入对应表达式即可。

## 特殊电场分布

### 1. 电偶极子的电场

在远离偶极子的区域（$r \gg d$），用球坐标表示：

$$E_r = \frac{1}{4\pi\varepsilon_0} \frac{2p\cos\theta}{r^3}$$
$$E_\theta = \frac{1}{4\pi\varepsilon_0} \frac{p\sin\theta}{r^3}$$

### 2. 均匀带电细杆

长度为 $L$、线密度为 $\lambda$ 的细杆，在垂直平分线上距杆 $x$ 处的电场：

$$E = \frac{1}{4\pi\varepsilon_0} \frac{\lambda L}{x\sqrt{x^2 + (L/2)^2}}$$

当 $L \to \infty$（无限长直导线）：
$$E = \frac{\lambda}{2\pi\varepsilon_0 x}$$

方向垂直于导线。

### 3. 均匀带电圆盘轴线

半径为 $R$、面密度 $\sigma$ 的圆盘轴线上的电场：

$$E = \frac{\sigma}{2\varepsilon_0}\left(1 - \frac{x}{\sqrt{x^2 + R^2}}\right)$$

> [!tip] 极限情况
> - $x \to 0$（靠近圆盘）：$E \to \sigma/(2\varepsilon_0)$，等价于无限大平面
> - $x \gg R$（远离圆盘）：$E \to \frac{1}{4\pi\varepsilon_0}\frac{Q}{x^2}$，等价于点电荷

## 相关链接

- [[Physics/Electromagnetism/Electrostatics|Electrostatics]]
- [[Physics/Electromagnetism/Gauss's Law|Gauss's Law]]
- [[Physics/Electromagnetism/Electric Potential|Electric Potential]]
- [[Physics/Electromagnetism/Electromagnetism - Home|Electromagnetism - Home]]

> [!summary] 🎯 核心要点
> 电场 = 电荷周围空间的**力线地图**。电场强度是矢量，叠加要按方向求和。高斯定律提供了另一种（有时更简单的）计算电场的方法。

## 注意事项

1. 电场是**矢量场**，叠加时必须遵循矢量加法
2. 检验电荷必须足够小，以避免影响原电场分布
3. 电场**线不能相交**，否则会在交点处有多个切线方向
4. 静电平衡下，导体内部电场处处为零
5. 偶极子电场 $E \propto 1/r^3$ 衰减比点电荷 $1/r^2$ 更快——因为正负电荷的贡献在远距离上几乎互相抵消
