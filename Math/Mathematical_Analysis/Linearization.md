---
tags:
  - Calculus
  - Math
  - 定义性
title: Linearization
created: 2025-10-22T15:19:00
modified:
---
# Linearization

## 1. General Method
线性化用于估算函数在特定点上的数值大小，具体方法在于**使用与此点接近的另一点上的切线方程来估计其大小**：
$$\text{For function }f(x)\text{, known the value of }f(x_1)\text{ and the value of }f'(x_1)$$
根据[[导数与切线方程]]中的点斜式求出在$(x_1,y_1)$ 上的切线的表达式：
$$L(x_1)=f'(x_1)(x-x_1)+f(x_1)$$
如果想要求的值是$f(x_2)$，其中$x_1$和$x_2$十分接近，那么就可以干脆地估计$f(x_2)$：
$$f(x_2)\approx L(x_2)=f'(x_1)(x_2-x_1)+f(x_1)$$

## 2. Linearization and Differential
正如前文所言，在已知函数上的点$(a,f(a))$以及$f'(a)$时，可以这样求一个与$a$接近的值$x$的函数值$f(x)$的近似值：
$$f(x)\approx L(x)=f'(a)(x-a)+f(a)$$
直接定义$\Delta x=x-a$，那么：
$$f(a+\Delta x)\approx L(a+\Delta x)=f'(a)\Delta x+f(a)$$
在几何上则是：
![[linearization_and_differential.png]]

## 3. Error
误差写作$r(x)$：
$$r(x)=f(x)-L(x)$$
如果$(\forall x)(x\in [x,a])(\exists\frac{d^2}{dx} f(x))$：
$$r(x)=\frac{1}{2}f''(c)(x-a)^2$$
（这一点需要泰勒展开的知识才能证明）

## 4. Newton's Method

### 4.1 Basic
牛顿法直接使用了线性化的方法，用来估算函数零点，其大致思路如下：
![[first_estimate_for_zero.png]]
![[second_estimate_for_zero.png]]

### 4.2 In Algebra
首先对原函数在$x=a$时进行线性化，求切线与$x$轴交点：
$$L(x)=f'(a)(x-a)+f(a)=0$$
$$\Rightarrow x=a-\frac{f(a)}{f'(a)}$$
理想情况下，假如$f'(a)\ne 0$，而且可以不停通过更换估算点来接近，那么：
$$x_1=x_0-\frac{f(x_0)}{f'(x_0)}/x_2=x_1-\frac{f(x_1)}{f'(x_1)}/x_3=x_2-\frac{f(x_2)}{f'(x_2)}$$
所以通过多次迭代就大概可以得到零点