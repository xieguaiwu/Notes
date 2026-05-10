---
tags:
  - Math
  - Calculus
  - Exercise
  - 证明
title: differentiation_problem_03.20
created: 2026-03-20T09:37:00
modified:
---
# differentiation_problem_03.20
利用两边求对数来简化式子，从而求导
>$$y=\frac{x^2\sqrt{5x+1}}{(3x-2)^3}$$

两边取$\ln$：
$$\ln y=\ln x^2+\ln(5x+1)^{\frac{1}{2}}-\ln (3x-2)^3$$

展开：
$$\ln y=2\ln x+\frac{1}{2}\ln(5x+1)-3\ln(3x-2)$$

两边对$x$求导：
$$\frac{1}{y}\cdot \frac{dy}{dx}=\frac{2}{x}+\frac{1}{2}\cdot\frac{5}{5x+1}-3\cdot\frac{3}{3x-2}$$

整理得：
$$\frac{y'}{y}=\frac{2}{x}+\frac{5}{2(5x+1)}-\frac{9}{3x-2}$$

通分（最小公倍数 $2x(5x+1)(3x-2)$）：
$$\frac{y'}{y}=\frac{2 \cdot 2(5x+1)(3x-2) + 5x(3x-2) - 9 \cdot 2x(5x+1)}{2x(5x+1)(3x-2)}$$

计算分子：
- 第一项：$4(5x+1)(3x-2) = 4(15x^2-10x+3x-2) = 60x^2-28x-8$
- 第二项：$5x(3x-2) = 15x^2-10x$
- 第三项：$-18x(5x+1) = -90x^2-18x$

分子合并：
$$60x^2-28x-8 + 15x^2-10x - 90x^2-18x = -15x^2-56x-8$$

所以：
$$\frac{y'}{y}=\frac{-15x^2-56x-8}{2x(5x+1)(3x-2)}$$

最终结果：
$$y' = y \cdot \frac{-15x^2-56x-8}{2x(5x+1)(3x-2)} = \frac{x^2\sqrt{5x+1}}{(3x-2)^3} \cdot \frac{-15x^2-56x-8}{2x(5x+1)(3x-2)}$$

化简：
$$y' = \frac{x\sqrt{5x+1}}{(3x-2)^3} \cdot \frac{-15x^2-56x-8}{2(5x+1)(3x-2)}$$
