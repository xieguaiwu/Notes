---
tags:
  - Math
  - 定义性
  - Modelling
title: Optimization
created: 2026-10-06
modified: 2026-10-06
---
# Optimization
## 一般optimization
- $f(x_1,x_2|p,w,r)$其中$x_i$是真的可以在决策时改变的变量
- Object function $f(X)$
- Decision variables $X=(x_1,x_2, \ldots ,x_n)$
- Constraints $g_i(X)$ (optional)

关键的工作在于maximize or minimize $f(X)$ subject to $g_i(X)$,并且确认特定约束成立,例如: $\forall i\in I (g_i(X)\geq b_i) \vee (g_i(X)=b_i)\vee (g_i(X)\leq b_i)$

## Classification
- Unconstrained
- Linear Program
    - 有独特的object function
    - Object function and constraints are $linear$ in terms of decision variables
    - Decision variables可以被取分数和整数值
- Integer Program
    - 满足了linear program的所有其他要求
    - 但是decision variables只能取整数

