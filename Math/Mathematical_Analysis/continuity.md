---
tags:
  - Calculus
  - Math
title: continuity
created: 2025-09-24T09:54:00
modified:
---
# continuity
[[limit]]
[[calculus]]
## 1. Continuity at a Point
A function $f(x)$ is continuous at point the $c$ within its domain only when:
$$(\forall c)(c\in\mathbf{D})\lim_{x\to c}f(x)=f(c)$$
## 2. Continuous of the Whole Function
A function is continuous in an interval only when the function is continuous at every point within that interval.
$$(\forall c)(c\in\mathbf{D})\lim_{x\to c}f(x)=f(c)$$
## 3. Continuity and Differentiability
[[differentiation]]
$$可导性\Rightarrow 连续性$$
但连续性不一定代表可导性：
### 3.1 可导性定义
见[[differentiation]]中关于可导性定义的叙述，可知只有当双侧导数都存在且彼此相等时，函数才在一个点上是可导的。
对于绝对值函数在特定点上的不可导性已经证明$连续性\nRightarrow 可导性$
### 3.2 证明$可导性\Rightarrow 连续性$
见[[Differentiability and Continuity]]


## 4. Two Kinds of Discontinuity
![[discontinue.png]]
由此可见，只要可以通过定义函数中的点$f(c)$就能够消除掉的discontinuity是**removable discontinuity**，反之则是**nonremovable discontinuity**
