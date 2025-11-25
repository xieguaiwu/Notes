---
tags:
  - Calculus
  - Math
  - 证明
  - 定义性
title: Continuity and Boundedness
created: 2025-11-24T23:04:00
modified:
---
# Boundedness
## 1. Def
假如对于$f:A\to\mathbb{R}$
$$\exists M>0(M\in\mathbb{R})\forall x(x\in A)|f(x)|\leq M$$
则函数$f$是有界的
假如对于$\forall x\in A$同时有
$$f(x)\leq M$$
$$f(x)\geq m$$
则$f$同时有上界 (upper bound) 和下界 (lower bound)

## 2. Continuity & Boundedness
对于下方两个函数：
![[continuity_and_boundedness.png]]
此函数为$f(x)$，其中$x\neq 1$，但$\lim_{x\to 1}f(x)=0$

同时有$g(x)$
![[continuity_and_boundedness2.png]]
其为分段函数，当$x\leq 2$时$g(x)=1$，反之则$g(x)=-1$，这意味着$\neg\exists\lim_{x\to 2}g(x)$

考虑以下极限：
>$$\lim_{x\to 1}(f(x)\cdot g(x+1))$$


可以意识到不确定性，因为已知
$$\neg\exists\lim_{x\to 2}g(x)$$
但是根据**1**可知函数$g$有界
$$(\forall x)|g(x)|\leq 1$$

回到一开始的极限中，考虑到极限法则：
$$\lim_{x\to a}(f(x)\cdot g(x))=L\cdot M$$
而
$$\lim_{x\to 1}f(x)=0$$
那么原极限等同于
$$\lim_{x\to 1}(f(x)\cdot g(x+1))=0\cdot 1=0$$