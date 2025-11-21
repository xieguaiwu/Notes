---
tags:
  - MachineLearning
  - Math
title: Basic Learning Model
created: 2025-11-21T09:35:00
modified:
---
# Basic Learning Model
## 1. The Learning Problem
一般的学习问题的模型如下所示：
![[learning_problem.png]]
对于未知的映射（其数学定义见[[function mapping]]），有输入集$\mathcal{X}\in\mathbb{R}^d$，其中$\mathbb{R}^d$是n-dimensional Euclidean space（见[[n-dimensional Euclidean space]]），另一方面也有输出集$\mathcal{Y}$

数据集$\mathcal{D}$即图中的training examples，它的一般形式是一对输入和输出$(x_N,y_N)$，其中$y_n=f(x_n)$

另一方面，一切可能的公式 (candidate formulas) 则位于集合$\mathcal{H}$中

图中的learning algorithm $\mathcal{A}$的目的就在于**从$\mathcal{A}$中选择一个$g$来逼近target function$f$**，令$g\approx f$

## 2. Perceptron
vocab: Perceptron$\Leftrightarrow$感知机

对于输入**向量$x$**，给予不同的权重$w$，计算加权和。超过阈值则给出一个布尔值。
由于模型意在判断正误，故**设定值域$\mathcal{Y}=\{-1,+1\}$**。首先定义函数$f(x)$来衡量这个阈值：
$$f(x):\text{when }x>0\Leftrightarrow f(x)=+1\text{; when }x<0\Leftrightarrow f(x)=-1$$

将函数$h(h\in\mathcal{H})$写作如下形式来将感知机的决策过程形式化：
$$h(x)=f((\sum_{i=1}^d w_ix_i)+b)$$
其中，$x_1,\ldots, x_d$是向量$x$的组成部分，$b$则是一个bias term，它用来配合$f(x)$决定阈值，因为考虑到只有当$f(x)$中$x>0$时才能得到$+1$的返回值，所以：
$$h(x)=+1\Leftrightarrow\sum_{i=1}^d w_ix_i>-b$$

在训练此模型时，需要分类数据集$\mathcal{D}$，若设定$\circ$是$+1$而$\times$是$-1$，则可能会出现如下两种情况：
![[misclassified_and_classified_data_set.png]]
