---
tags:
  - Exercise
  - Math
  - Calculus
  - 定义性
title: limit_problem_1211
created: 2025-12-15T20:45:00
modified:
---
# limit_problem_12.11

## 1. 关于定义性的问题
这个题目与极限和连续性的定义高度相关
>如果已知$$\lim_{x\to a}f(x)=L(L\in\mathbb{R})$$求下方哪些命题是正确的
>1. $\exists f(a)$
>2. $f(x)$在$x=a$上连续
>3. $f(x)$在$x=a$点被定义
>4. $f(a)=L$

注意：**以上命题全部不正确**

正如[[limit]]中关于$\varepsilon-\delta$语言所说明的那样，$f(x)$在$x=a$上存在极限**不代表这一点是存在于原函数上的**
另一方面，回到[[continuity]]的定义：
$$\lim_{x\to c}f(x)=f(c)$$
因此，只有当$\lim_{x\to a}f(x)=f(a)=L$时，才可能会出现等式：
$$f(x)=L=f(a)$$

## 2. 定义&Intermediate Value Theorem
>已知$$g(0)=24,g(1)=35,g(3)=42,g(7)=68$$
下方哪些命题可以用来证明$\exists c\in [0,7]g(c)=50$？
1. $g(x)$在$[0,7]$上完全定义
2. $g(x)$在$[0,7]$上递增
3. $g(x)$在$[0,7]$上完全连续

重要：**只有3可以**

首先，**完全定义不代表连续性**（见连续性定义[[continuity]]）
其次，**递增的函数也可以是不连续的**
在两种情况中，函数都完全可以在区间内跳过$g(c)=50$，只有命题3能够借助intermediate value theorem证明$g(c)=50$的存在性

## 3. $\exists f(c)$与极限存在、可导性和连续性的关系
>下方哪个命题不能用来证明$$\exists f(0)$$
>1. $\exists\lim_{x\to 0}f(x)$
>2. $f$在$x=0$上连续
>3. $f$在$x=0$上可导
>4. $f$与$y$轴有交点

**只有1（存在极限）不能证明**
连续性：
$$\lim_{x\to 0}f(x)=f(0)\Rightarrow\exists f(0)$$
可导性：根据[[Differentiability and Continuity]]可以知道**可导性就意味着连续性**，所以仍然可以证明$\exists f(0)$
有交点：在几何上证明了$\exists f(0)$
