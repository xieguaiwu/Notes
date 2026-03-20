---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: integral_problem_03.18
created: 2026-03-18T08:17:00
modified:
---
# integral_problem_03.18
## Q1
>$\displaystyle \int \frac{1}{t\sqrt{t}} \, dt$

- $\frac{1}{t\sqrt{t}} = \frac{1}{t^{3/2}} = t^{-3/2}$
$$\int t^{-3/2} \, dt = \frac{t^{-3/2+1}}{-3/2+1} + C = \frac{t^{-1/2}}{-1/2} + C$$

$$= -2 \cdot t^{-1/2} + C = -\frac{2}{\sqrt{t}} + C$$
$$\boxed{-\frac{2}{\sqrt{t}} + C}$$
## Q2
>$\displaystyle \int_0^5 \sqrt{\frac{5-x}{5}} \, dx$
化简被积函数
$$\sqrt{\frac{5-x}{5}} = \sqrt{1 - \frac{x}{5}} = \frac{\sqrt{5-x}}{\sqrt{5}}$$

元积分
令 $u = 5 - x$，则 $du = -dx$，即 $dx = -du$

积分限变换：
   - 当 $x = 0$ 时，$u = 5$
   - 当 $x = 5$ 时，$u = 0$
$$\int_0^5 \frac{\sqrt{5-x}}{\sqrt{5}} \, dx = \frac{1}{\sqrt{5}} \int_5^0 \sqrt{u} \, (-du) = \frac{1}{\sqrt{5}} \int_0^5 u^{1/2} \,
  du$$

步骤 3：计算积分
$$= \frac{1}{\sqrt{5}} \cdot \left[\frac{u^{3/2}}{3/2}\right]_0^5 = \frac{1}{\sqrt{5}} \cdot \frac{2}{3} \cdot [u^{3/2}]_0^5$$
 $$= \frac{2}{3\sqrt{5}} \cdot (5^{3/2} - 0) = \frac{2}{3\sqrt{5}} \cdot 5\sqrt{5}$$
答案：
  $$\boxed{\frac{10}{3}}$$

## Q3
>$\displaystyle \int_{-2}^{4} \frac{f(x)}{8} \, dx$

函数 $f$ 在区间 $[a, b]$ 上的平均值公式：
$$\overline{f} = \frac{1}{b-a} \int_a^b f(x)\,dx$$

已知：
   - 区间 $[-2, 4]$，长度 $b - a = 4 - (-2) = 6$
   - 平均值 $\overline{f} = 12$

步骤 2：求 $\displaystyle \int_{-2}^{4} f(x)\,dx$
$$12 = \frac{1}{6} \int_{-2}^{4} f(x)\,dx$$
$$\int_{-2}^{4} f(x)\,dx = 12 \times 6 = 72$$

步骤 3：计算目标积分

  $$\int_{-2}^{4} \frac{f(x)}{8} \, dx = \frac{1}{8} \int_{-2}^{4} f(x)\,dx = \frac{1}{8} \times 72$$$$=\boxed{9}$$
## Q4
>$$\int \frac{x^3 + \sin x}{x^2 + 2}\,dx = \underbrace{\frac{x^2}{2} - \ln(x^2 + 2)}{\text{代数部分}} + \underbrace{\int \frac{\sin
  x}{x^2 + 2}\,dx}{\text{非初等积分}}$$

精确表达式：
  $$H(2) = \pi - \frac{21}{2} + \ln\frac{9}{2} - \int_2^5 \frac{\sin x}{x^2 + 2}\,dx$$

  数值近似：
  $$\boxed{H(2) \approx -5.867}$$

  ---

  详细推导：


  其中 $\displaystyle \int_2^5 \frac{\sin x}{x^2 + 2}\,dx \approx 0.0123$ 无法用初等函数表示。
