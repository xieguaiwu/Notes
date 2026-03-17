---
tags:
  - Math
  - Exercise
  - 定义性
  - 基本原理
title: Basic Algebra
created: 2025-11-18T12:00:00
modified:
---
# Basic Algebra 基础代数技巧

## 十字相乘法（用于二次三项式 $ax^2 + bx + c$）

找两个数 $m, n$ 满足：
   - $m \times n = a \times c$
   - $m + n = b$

例如：$x^2 - 4x + 3$
   - 找两个数：乘积 = 3，和 = -4
   - 这两个数是 -1 和 -3
   - 分解为：$(x-1)(x-3)$

---

## 韦达定理（Vieta's Formulas）

对于一元二次方程 $ax^2 + bx + c = 0$（$a \neq 0$），设其两根为 $x_1, x_2$，则：

$$x_1 + x_2 = -\frac{b}{a}$$

$$x_1 \cdot x_2 = \frac{c}{a}$$

### 推广至一元三次方程

对于 $ax^3 + bx^2 + cx + d = 0$，设三根为 $x_1, x_2, x_3$：

$$x_1 + x_2 + x_3 = -\frac{b}{a}$$

$$x_1x_2 + x_2x_3 + x_3x_1 = \frac{c}{a}$$

$$x_1x_2x_3 = -\frac{d}{a}$$

---

## 配方法（Completing the Square）

将二次三项式 $ax^2 + bx + c$ 配方为 $a(x-h)^2 + k$ 的形式：

$$ax^2 + bx + c = a\left(x^2 + \frac{b}{a}x\right) + c = a\left(x + \frac{b}{2a}\right)^2 + c - \frac{b^2}{4a}$$

### 应用

1. **求二次函数顶点**：$y = a(x + \frac{b}{2a})^2 + \frac{4ac-b^2}{4a}$，顶点为 $(-\frac{b}{2a}, \frac{4ac-b^2}{4a})$

2. **解二次方程**：$ax^2 + bx + c = 0 \Rightarrow x = \frac{-b \pm \sqrt{b^2-4ac}}{2a}$

---

## 因式分解公式

### 基本公式

$$a^2 - b^2 = (a+b)(a-b)$$

$$a^2 \pm 2ab + b^2 = (a \pm b)^2$$

$$a^3 \pm b^3 = (a \pm b)(a^2 \mp ab + b^2)$$

$$a^3 + b^3 + c^3 - 3abc = (a+b+c)(a^2+b^2+c^2-ab-bc-ca)$$

### 二项式系数立方和

$$(a+b)^3 = a^3 + 3a^2b + 3ab^2 + b^3$$

$$(a-b)^3 = a^3 - 3a^2b + 3ab^2 - b^3$$

---

## 换元法（Substitution）

通过引入新变量简化复杂表达式。

### 例：解方程 $(x^2-2x)^2 - 3(x^2-2x) - 4 = 0$

设 $t = x^2 - 2x$，则：
$$t^2 - 3t - 4 = 0$$
$$(t-4)(t+1) = 0$$

解得 $t = 4$ 或 $t = -1$，再回代求解 $x$。

---

## 判别式的应用

对于 $ax^2 + bx + c = 0$，判别式 $\Delta = b^2 - 4ac$：

- $\Delta > 0$：两个不相等的实根
- $\Delta = 0$：两个相等的实根
- $\Delta < 0$：无实根（有两个共轭复根）
