---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: integral_problem_05.08
created:
modified: 2026-05-08
---
# integral_problem_05.08

## Q1

> 计算定积分 $\displaystyle\int_0^4 \frac{x}{\sqrt{x^2+9}}\,dx$

见到 $\sqrt{x^2 + a^2}$ 就上三角代换？**先检查分子是否为根号内表达式的导数形式**！

分子 $x$ 恰好是 $x^2+9$ 导数的一半，直接 $u$-代换即可：

设 $u = x^2 + 9$，则 $du = 2x\,dx$，即 $x\,dx = \frac{1}{2}du$

**换限**：$x = 0 \implies u = 9$；$x = 4 \implies u = 25$

$$\int_0^4 \frac{x}{\sqrt{x^2+9}}\,dx = \frac{1}{2}\int_9^{25} u^{-1/2}\,du = \frac{1}{2}\left[2u^{1/2}\right]_9^{25} = \sqrt{25} - \sqrt{9} = 2$$

**易错点**：
1. **盲目使用三角代换** $x = 3\tan\theta$ → 过程冗长，换限复杂，容易在回代时出错
2. **忘记** $\frac{1}{2}$ **系数**：$du = 2x\,dx \implies x\,dx = \frac{1}{2}du$，系数必须提取
3. **换元后忘记同步更换积分上下限**，这是定积分换元法最常见的扣分点

---

## Q2

> 函数 $f(x) = \dfrac{\sin x}{x}\;(x > 0)$ 与 $x$ 轴、$y$ 轴及直线 $x = k$ 围成一个区域。已知 $dk = \dfrac{\pi}{4}$，求在 $k = \dfrac{\pi}{6}$ 时该区域面积的变化率。

**绝不能试图直接求 $\int \frac{\sin x}{x}dx$ 的初等形式！** 这是一个非初等积分（正弦积分 $\operatorname{Si}(x)$），只能通过微积分基本定理求导。

### 解答

设面积为 $A(k) = \displaystyle\int_0^k \frac{\sin x}{x}\,dx$

由**微积分基本定理（FTC）**：

$$\frac{dA}{dk} = f(k) = \frac{\sin k}{k}$$

在 $k = \dfrac{\pi}{6}$ 处：

$$\frac{dA}{dk}\bigg|_{k=\pi/6} = \frac{\sin(\pi/6)}{\pi/6} = \frac{1/2}{\pi/6} = \frac{3}{\pi}$$

面积的变化（微分）为：

$$dA = \frac{dA}{dk} \cdot dk = \frac{3}{\pi} \cdot \frac{\pi}{4} = \frac{3}{4}$$

**答案**：面积变化率（瞬时）为 $\dfrac{3}{\pi}$，面积的微分为 $\dfrac{3}{4}$。

### 易错点

1. **试图求 $\int \frac{\sin x}{x}dx$ 的原函数**：$\frac{\sin x}{x}$ 不存在初等原函数（不能用基本函数有限组合表达）。题目恰恰考察你是否认识到这一点并转而使用 FTC。花时间尝试分部积分或换元法只会走入死胡同。

2. **忘记 FTC**：$\frac{d}{dx}\int_a^x f(t)\,dt = f(x)$ 是微积分基本定理的核心，在积分无法初等计算时是唯一出路。

3. **混淆 $dA/dk$ 与 $dA$**：题目给出 $dk$ 是为了求面积的具体微分（近似变化量），而非仅停留于瞬时变化率。两者概念不同，不能将 $\frac{3}{\pi}$ 和 $\frac{3}{4}$ 混为一谈。

