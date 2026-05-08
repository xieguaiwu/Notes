---
tags:
  - Exercise
  - Math
  - Calculus
  - 证明
title: differentiation_problem_05.08
created:
modified: 2026-05-08
---
# differentiation_problem_05.08

## Q1

> 若 $\cos(xy) = y - 1$，则 $\dfrac{dy}{dx}$ 在 $x = \dfrac{\pi}{2}$，$y = 1$ 处的取值是？

**隐函数求导必须记住：$y$ 是 $x$ 的函数，对 $xy$ 求导要用乘积法则！**

两边对 $x$ 求导：

$$-\sin(xy) \cdot \frac{d}{dx}(xy) = \frac{dy}{dx}$$

$$-\sin(xy) \cdot \left(y + x\frac{dy}{dx}\right) = \frac{dy}{dx}$$

展开并整理 $\dfrac{dy}{dx}$ 项：

$$-y\sin(xy) - x\sin(xy)\frac{dy}{dx} = \frac{dy}{dx}$$

$$-y\sin(xy) = \frac{dy}{dx}\big(1 + x\sin(xy)\big)$$

$$\frac{dy}{dx} = \frac{-y\sin(xy)}{1 + x\sin(xy)}$$

代入 $x = \dfrac{\pi}{2}$，$y = 1$（验证：$\cos\frac{\pi}{2} = 0 = 1-1$ ✓，$\sin\frac{\pi}{2} = 1$）：

$$\frac{dy}{dx}\bigg|_{(\frac{\pi}{2}, 1)} = \frac{-1 \cdot 1}{1 + \frac{\pi}{2} \cdot 1} = -\frac{1}{1 + \frac{\pi}{2}} = -\frac{2}{2+\pi}$$

**易错点**：
1. **链式法则缺项**：对 $\cos(xy)$ 求导，只写 $-\sin(xy)$ 而漏掉 $(xy)'$ → 这是对复合函数求导不完整
2. **乘积法则遗忘**：$\frac{d}{dx}(xy) = 1 \cdot y + x \cdot \frac{dy}{dx}$，**不是** $y$ 或 $x\frac{dy}{dx}$ 单独一项。$y$ 是 $x$ 的函数，不能当常数处理
3. **先代后求**：在求导之前就把 $y=1$ 代入 → 丢失了 $y$ 作为函数的信息，导致求导结果错误。必须先求出 $\frac{dy}{dx}$ 的表达式，再代入具体值
