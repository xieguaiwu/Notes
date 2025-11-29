---
tags:
  - MachineLearning
  - Math
  - Algorithm
title: Basic Learning Model
created: 2025-11-21T09:35:00
modified:
---
# Basic Learning Model
## 1. The Learning Problem
一般的学习问题的模型如下所示：
![[learning_problem.png]]
对于未知的映射（其数学定义见[[function mapping]]），有输入集$\mathcal{X}\in\mathbb{R^d}$，其中$\mathbb{R}^d$是n-dimensional Euclidean space（见[[n-dimensional Euclidean space]]），另一方面也有输出集$\mathcal{Y}$

数据集$\mathcal{D}$即图中的training examples，它的一般形式是一对输入和输出$(x_N,y_N)$，其中$y_n=f(x_n)$

另一方面，一切可能的公式 (candidate formulas) 则位于集合$\mathcal{H}$中

图中的learning algorithm $\mathcal{A}$的目的就在于**从$\mathcal{A}$中选择一个$g$来逼近target function$f$**，令$g\approx f$

## 2. Perceptron
vocab: Perceptron$\Leftrightarrow$感知机
感知机是一个**二分类**的线性分类模型：
- 找到一个超平面（在二维空间中就是一条直线）来分隔两类数据（关于hyperplane，见[[Hyperplane]]）
- 对于线性可分的数据，感知机保证能够收敛到一个解

对于输入**向量$x$**，给予不同的权重$w$，计算加权和。超过阈值则给出一个布尔值。
由于模型意在判断正误，故**设定值域$\mathcal{Y}=\{-1,+1\}$**。首先定义函数$sign(x)$来衡量这个阈值：
$sign(x):\text{when }x>0\Leftrightarrow sign(x)=+1\text{; when }x<0\Leftrightarrow sign(x)=-1$

将函数$h(h\in\mathcal{H})$写作如下形式来将感知机的决策过程形式化：
$$h(x)=sign((\sum_{i=1}^d w_ix_i)+b)$$
其中，$x_1,\ldots, x_d$是向量$x$的组成部分，$b$则是一个bias term，它用来配合$f(x)$决定阈值，因为考虑到只有当$f(x)$中$x>0$时才能得到$+1$的返回值，所以：
$$h(x)=+1\Leftrightarrow\sum_{i=1}^d w_ix_i>-b$$

在训练此模型时，需要分类数据集$\mathcal{D}$，若设定$\circ$是$+1$而$\times$是$-1$，则可能会出现如下两种情况：
![[misclassified_and_classified_data_set.png]]

---

为了方便表述，将函数$h(x)$完全转换成向量形式，设定：
$$\mathbf{x}=[x_0,x_1,\ldots,x_d]^\mathbf{T}$$
$$\mathbf{w}=[w_0,w_1,\ldots,w_d]^\mathbf{T}$$
其中$\mathbf{T}$表示向量转置 (transpose) ，其效果见[[Vector and Matrix]]。在这样表示之后：
$$\mathbf{w^T x}=\sum_{i=1}^d w_ix_i$$
于是将原先的$h(x)$表达式重写为
$$h(x)=sign(\mathbf{w^T x})+b$$
这属于机器学习模型中的线性方法，即属于广义线性方法 (Generalized linear methods)：$f(x,\theta)=\mathbf{w^T}\phi(x)+b$

---

## 3. Perceptron Learning Algorithm
PLA算法：用来解决分类错误

在PLA算法中，会对权重向量$\mathbf{w}$进行迭代算法 (iterative method)：
在迭代次数$t(t\in\mathbb{Z^+})$时，会有权重向量$\mathbf{w}(t)$

假如在这个迭代上出现了前文所提的**misclassified data**，在数据集$\mathcal{D}$中写作$(x(t),y(t))$
由于这个数据是错误分类的，所以：
$$y(t)\neq sign(\mathbf{w^T}(t)x(t))$$
由于感知器函数的值域仅仅是$\mathcal{Y}=\{-1,+1\}$，当出现上述的不等关系时，说明$\mathbf{w^T}(t)x(t)$点积为负，于是通过下方的变换来修改
$$\mathbf{w}(t+1)=\mathbf{w}(t)+y(t)\mathbf{x}(t)$$

它的原理在于：
如果$y(t)$是$−1$，但被错误分类为$+1$，这意味着$w(t)$与$x(t)$的夹角太小（点积为正）。变为$w(t+1)=w(t)−x(t)$，即**从权重中减去向量$x(t)$，使权重向量远离$x(t)$**。

在图象上形如下图：
![[PLA_weight_updating.png]]
