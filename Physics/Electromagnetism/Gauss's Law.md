---
tags:
  - Physics
  - 定理性
  - 证明
title: Gauss's Law
created: 2026-06-10
modified: 2026-06-10
---

# Gauss's Law

> [!abstract] 高斯定律
> 高斯定律是电磁学的基本定律之一，将闭合曲面上的电通量与曲面内包含的总电荷联系起来。它是麦克斯韦方程组的第一条方程。

## 高斯定律

> [!important] 高斯定律（积分形式）
> 通过任意闭合曲面 $S$ 的**电通量**等于该曲面内所包围的**总电荷**除以 $\varepsilon_0$：
> 
> $$\oint_S \vec{E} \cdot d\vec{A} = \frac{Q_{\text{enc}}}{\varepsilon_0}$$
> 
> 其中 $Q_{\text{enc}} = \int_V \rho \, dV$ 是闭合曲面 $S$ 内包围的总电荷。

### 微分形式

利用散度定理 $(\oint \vec{E} \cdot d\vec{A} = \int \nabla \cdot \vec{E} \, dV)$：

$$\nabla \cdot \vec{E} = \frac{\rho}{\varepsilon_0}$$

表明电场的散度等于局部电荷密度除以 $\varepsilon_0$——电荷是电场的"源"。

## 物理意义

> [!note] 实质
> - 高斯定律等价于**库仑定律**与**叠加原理**的结合
> - 揭示了电荷是电场的**源**：正电荷发出电场线，负电荷终止电场线
> - 静电场是**有源场**（散度不为零）

## 应用：对称性分析

高斯定律最强大的应用是计算具有高度对称性的电荷分布的电场。

### 1. 球对称分布

**均匀带电球壳**（半径 $R$，总电荷 $Q$）：

$$E(r) = \begin{cases}
0, & r < R \\[4pt]
\displaystyle\frac{1}{4\pi\varepsilon_0}\frac{Q}{r^2}, & r \ge R
\end{cases}$$

> [!warning] 注意
> 球壳内部的电场为**零**，这是静电屏蔽的原理。

**均匀带电球体**（半径 $R$，体密度 $\rho$）：

$$E(r) = \begin{cases}
\displaystyle\frac{\rho r}{3\varepsilon_0} = \frac{1}{4\pi\varepsilon_0}\frac{Qr}{R^3}, & r < R \\[8pt]
\displaystyle\frac{1}{4\pi\varepsilon_0}\frac{Q}{r^2}, & r \ge R
\end{cases}$$

> [!tip] 球体内部
> 球体内部的电场随 $r$ 线性增长，而非恒定！

### 2. 柱对称分布

**无限长均匀带电直线**（线密度 $\lambda$）：

$$E(r) = \frac{\lambda}{2\pi\varepsilon_0 r}$$

高斯面：半径为 $r$、长度为 $L$ 的圆柱面。

**无限长均匀带电圆柱体**（半径 $R$，体密度 $\rho$）：

$$E(r) = \begin{cases}
\displaystyle\frac{\rho r}{2\varepsilon_0}, & r < R \\[8pt]
\displaystyle\frac{\lambda}{2\pi\varepsilon_0 r}, & r \ge R
\end{cases}$$

### 3. 平面对称分布

**无限大均匀带电平面**（面密度 $\sigma$）：

$$E = \frac{\sigma}{2\varepsilon_0}$$

高斯面：贯穿平面的"药盒"（pillbox）形柱面。

**平行板电容器**（两板面密度 $\pm\sigma$）：

$$E = \frac{\sigma}{\varepsilon_0}$$

在两板之间的区域，两板的电场叠加增强；外部区域相互抵消为零。

## 高斯面选取技巧

| 对称性 | 高斯面形状 | 关键条件 |
|-------|-----------|---------|
| 球对称 | 同心球面 | $\vec{E} \parallel d\vec{A}$，$E$ 在球面上恒定 |
| 柱对称 | 同轴圆柱面 | $\vec{E} \perp$ 侧面，$E$ 在侧面上恒定 |
| 平面对称 | 药盒状柱面 | $\vec{E}$ 垂直于平面，上下底面 $E$ 恒定 |

## 与库仑定律的比较

| 性质 | 库仑定律 | 高斯定律 |
|-----|---------|---------|
| 适用范围 | 静电荷 | 任意电磁场（麦克斯韦方程组之一） |
| 对称性要求 | 无需对称性 | 需要对称性简化计算 |
| 揭示本质 | 力的平方反比律 | 电场的有源性 |

## 相关链接

- [[Electromagnetism/Electrostatics|Electrostatics]]
- [[Electromagnetism/Electric Fields|Electric Fields]]
- [[Electromagnetism/Electric Potential|Electric Potential]]
- [[Electromagnetism/Maxwell's Equations|Maxwell's Equations]]

## 注意事项

1. 高斯定律适用于**任何**闭合曲面和**任何**电荷分布，但仅对高对称性分布有简化计算作用
2. 曲面上的 $\vec{E}$ 是所有电荷（包括曲面外的）产生的总电场，但通量只由曲面内电荷贡献
3. 高斯定律的微分形式 $\nabla \cdot \vec{E} = \rho/\varepsilon_0$ 是**局部**关系
