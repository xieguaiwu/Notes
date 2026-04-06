---
tags:
  - Exercise
  - Math
  - Calculus
  - 定义性
title: integral_problem_04.06
created: 2026-04-06T16:00:00
modified:
---
# integral_problem_04.06
## 1 黎曼和与梯形近似比较

>定积分 $\displaystyle \int_0^4 \sqrt{x}\,dx$ 分别用左黎曼和、右黎曼和、梯形和近似，每个均使用4个等宽子区间。若 $L$ 为左黎曼和的值，$R$ 为右黎曼和的值，$T$ 为梯形和的值，下列哪个不等式正确？
>
>选项：
>- (A) $L < \displaystyle\int_0^4 \sqrt{x}\,dx < T < R$
>- (B) $L < T < \displaystyle\int_0^4 \sqrt{x}\,dx < R$
>- (C) $R < \displaystyle\int_0^4 \sqrt{x}\,dx < T < L$
>- (D) $R < T < \displaystyle\int_0^4 \sqrt{x}\,dx < L$

### 函数性质分析

函数 $f(x) = \sqrt{x} = x^{1/2}$ 在区间 $[0,4]$ 上：
- **单调递增**：$f'(x) = \frac{1}{2\sqrt{x}} > 0$（$x > 0$）
- **凹向下**：$f''(x) = -\frac{1}{4}x^{-3/2} < 0$（$x > 0$）

### 近似估计与积分真值的关系

对于**递增且凹向下**的函数：
- 左黎曼和 $L$：**低估**积分（矩形高度取左端点，低于曲线）
- 右黎曼和 $R$：**高估**积分（矩形高度取右端点，高于曲线）
- 梯形和 $T$：对凹向下函数，**低估**积分（弦在曲线下方）

因此预期顺序为：
$$L < T < \int_0^4 \sqrt{x}\,dx < R$$

### 数值验证

**积分真值**：
$$\int_0^4 \sqrt{x}\,dx = \left[\frac{2}{3}x^{3/2}\right]_0^4 = \frac{2}{3} \cdot 8 = \frac{16}{3} \approx 5.333$$

**子区间划分**：$\Delta x = \frac{4-0}{4} = 1$，分点为 $x_0=0, x_1=1, x_2=2, x_3=3, x_4=4$

**左黎曼和**：
$$L = f(0) + f(1) + f(2) + f(3) = 0 + 1 + \sqrt{2} + \sqrt{3} \approx 4.146$$

**右黎曼和**：
$$R = f(1) + f(2) + f(3) + f(4) = 1 + \sqrt{2} + \sqrt{3} + 2 \approx 6.146$$

**梯形和**：
$$T = \frac{1}{2}[f(0) + 2f(1) + 2f(2) + 2f(3) + f(4)] = 2 + \sqrt{2} + \sqrt{3} \approx 5.146$$

### 结论

验证：$L \approx 4.146 < T \approx 5.146 < \frac{16}{3} \approx 5.333 < R \approx 6.146$

**正确答案：B**
