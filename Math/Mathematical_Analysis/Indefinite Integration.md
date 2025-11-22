---
tags:
  - Math
  - Calculus
  - 定义性
title: Indefinite Integration
created: 2025-11-20T12:51:00
modified:
---
# Indefinite Integration

## 1. Antiderivatives
反导数即导数的逆运算，它正是不定积分：
$$\frac{d}{dx}F(x)=f(x)\Leftrightarrow\int f(x)=F(x)+C$$
其中$C$是常数，因为常数在被求导后会直接消除。正因如此，不定积分形如下图：
![[antiderivatives_intuition.png]]
同时，考虑到不定积分的定义和[[Higher Order Derivative]]的高阶导数知识点，可以意识到：
$$f'(x)=\int f''(x)$$

## 2. Rules of Antiderivatives
根据[[differentiation]]的**3.2**中的诸多导数规则，可以给出如下不定积分规则：
$$\int 0dx=C$$
$$\int kf(x) dx = k\cdot\int f(x) dx$$
$$\int[f(x)\pm g(x)]dx=\int f(x)dx\pm\int g(x)dx$$
下方的这条规则或许是最常用的：
$$\int x^ndx=\frac{x^{n+1}}{n+1}+C(n\neq 1)$$
下面则是三角函数的积分运算规则
$$\int\cos x\text{ }dx=\sin x +C$$
$$\int\sin x\text{ }dx=-\cos x +C$$
$$\int\sec^2 x\text{ }dx=\tan x +C$$
$$\int\sec x\tan x\text{ }dx=\sec x+C$$
$$\int\csc x\cot x=-\csc x +C$$

## 3. Sum
$$\sum_{i=1}^n=a_i=a_1+a_2+\ldots+a_n$$
求和运算有以下性质：
$$\sum_{i=1}^nka_i=k\cdot\sum_{i=1}^na_i$$
$$\sum_{i=1}^n(a_i\pm b_i)=\sum_{i=1}^na_i\pm\sum_{i=1}^nb_i$$

## 4. Sum techniques
