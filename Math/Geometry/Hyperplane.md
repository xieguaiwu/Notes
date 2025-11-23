---
tags:
  - Math
  - Geometry
  - 定义性
title: Hyperplane
created: 2025-11-23T10:02:00
modified:
---
# Hyperplane
## 1. 直观理解：什么是超平面？

**超平面**可以理解为**高维空间中的"平面"**。就像：

- 在**1维**空间（一条直线）中，超平面是一个**点**
- 在**2维**空间（一个平面）中，超平面是一条**直线**
- 在**3维**空间中，超平面是一个**平面**
- 在**n维**空间中，超平面是一个**$(n-1)$维**的子空间

**核心特征**：超平面总是比所在空间**低一个维度**。

## 2. 数学定义

### 基本方程
在n维空间中（见[[n-dimensional Euclidean space]]），超平面由以下线性方程定义（此处是感知器的函数，见[[Basic Learning Model]]）：
$$\mathbf{w} \cdot \mathbf{x} + b = 0$$
其中：
- $\mathbf{w} = (w_1, w_2, ..., w_n)$是**法向量**（权重向量），垂直于超平面
- $\mathbf{x} = (x_1, x_2, ..., x_n)$是空间中的点
- $b$是偏置项，控制超平面的位置

### 各维度的具体形式

| 维度  | 超平面类型 | 方程形式                                  | 可视化     |
| --- | ----- | ------------------------------------- | ------- |
| 1D  | 点     | $w_1x_1 + b = 0$                      | 数轴上的一个点 |
| 2D  | 直线    | $w_1x_1 + w_2x_2 + b = 0$             | 平面中的直线  |
| 3D  | 平面    | $w_1x_1 + w_2x_2 + w_3x_3 + b = 0$    | 空间中的平面  |
| nD  | 超平面   | $\mathbf{w} \cdot \mathbf{x} + b = 0$ | 无法直接可视化 |

## 3. 几何解释

### 法向量的重要性
- **法向量 $\mathbf{w}$** 垂直于超平面
- 它指示了超平面的"方向"
- 法向量的长度不影响超平面的位置，只影响方向

### 偏置项的作用
- $b$ 决定了超平面距离原点的远近
- 如果 $b = 0$，超平面通过原点
- $b$ 的符号决定超平面在法向量方向的哪一侧

### 点到超平面的距离
点 $\mathbf{x}_0$ 到超平面的距离公式：
$$\text{距离} = \frac{|\mathbf{w} \cdot \mathbf{x}_0 + b|}{\|\mathbf{w}\|}$$
其中 $\|\mathbf{w}\| = \sqrt{w_1^2 + w_2^2 + \cdots + w_n^2}$是法向量的长度。

## 4. 可视化示例

### 2D例子：直线作为超平面
```python
import numpy as np
import matplotlib.pyplot as plt

# 定义超平面：2x + y - 3 = 0
w = np.array([2, 1])  # 法向量
b = -3

# 生成直线
x = np.linspace(-2, 4, 100)
y = (-w[0]*x - b) / w[1]  # 解出 y

plt.figure(figsize=(8, 6))
plt.plot(x, y, 'r-', linewidth=2, label='超平面: 2x + y - 3 = 0')

# 绘制法向量（在点(1,1)处）
point = np.array([1, 1])
plt.quiver(point[0], point[1], w[0], w[1], color='blue', 
           scale=10, label='法向量 w = [2, 1]')

plt.grid(True)
plt.axis('equal')
plt.xlabel('x1')
plt.ylabel('x2')
plt.legend()
plt.title('2D空间中的超平面（一条直线）')
plt.show()
```

### 3D例子：平面作为超平面
```python
from mpl_toolkits.mplot3d import Axes3D

# 定义超平面：x + 2y + z - 4 = 0
w = np.array([1, 2, 1])  # 法向量
b = -4

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# 生成平面
x = np.linspace(-1, 5, 20)
y = np.linspace(-1, 5, 20)
X, Y = np.meshgrid(x, y)
Z = (-w[0]*X - w[1]*Y - b) / w[2]

# 绘制平面
ax.plot_surface(X, Y, Z, alpha=0.5, rstride=100, cstride=100)

# 绘制法向量
ax.quiver(2, 2, 2, w[0], w[1], w[2], length=2, color='red', 
          arrow_length_ratio=0.1, label='法向量')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D空间中的超平面（一个平面）')
plt.legend()
plt.show()
```

## 5. 超平面在机器学习中的应用

### 作为决策边界
在分类问题中，超平面用作**决策边界**：
$$f(\mathbf{x}) = \mathbf{w} \cdot \mathbf{x} + b$$
分类规则：
- 如果 $f(\mathbf{x}) \geq 0$，预测为**正类** $(+1)$
- 如果 $f(\mathbf{x}) < 0$，预测为**负类** $(-1)$

### 在具体算法中的应用

#### 1. 感知机
- 寻找一个超平面来线性分隔数据
- 更新规则调整 $\mathbf{w}$ 和 $b$ 来移动超平面

#### 2. 支持向量机 (SVM)
- 寻找**最大间隔超平面**
- 目标是让离超平面最近的数据点（支持向量）到超平面的距离最大化

#### 3. 逻辑回归
- 使用超平面作为决策边界
- 输出通过$sign(x)$函数转换为概率

## 6. 超平面的性质

### 分隔性
超平面将空间分成两个**半空间**：
- **正半空间**：$\mathbf{w} \cdot \mathbf{x} + b > 0$
- **负半空间**：$\mathbf{w} \cdot \mathbf{x} + b < 0$

### 线性性
超平面是**线性**的，这意味着：
- 它不能弯曲
- 只能处理线性可分的数据

### 齐次坐标表示
通过引入齐次坐标，可以简化表示：
$$\tilde{\mathbf{w}} \cdot \tilde{\mathbf{x}} = 0$$
其中 $\tilde{\mathbf{w}} = (w_1, w_2, ..., w_n, b)$，$\tilde{\mathbf{x}} = (x_1, x_2, ..., x_n, 1)$

## 7. 从低维到高维的推广

理解超平面的一个好方法是从低维例子开始：

| 维度  | 超平面 | 方程示例                                  | 分隔能力         |
| --- | --- | ------------------------------------- | ------------ |
| 1D  | 点   | $2x - 3 = 0$                          | 将直线分成两段      |
| 2D  | 直线  | $x + 2y - 4 = 0$                      | 将平面分成两个半平面   |
| 3D  | 平面  | $x + y + z - 1 = 0$                   | 将空间分成两个半空间   |
| nD  | 超平面 | $\mathbf{w} \cdot \mathbf{x} + b = 0$ | 将n维空间分成两个半空间 |

## 8. 总结

**超平面**的核心要点：
1. **定义**：n维空间中的$(n-1)$维线性子空间
2. **方程**：$\mathbf{w} \cdot \mathbf{x} + b = 0$
3. **几何意义**：法向量 $\mathbf{w}$ 指示方向，偏置 $b$ 控制位置
4. **应用**：机器学习中的决策边界
5. **局限性**：只能表示线性关系

理解超平面是理解许多机器学习算法（特别是线性模型）的基础，它为我们提供了一种在高维空间中思考和可视化的强大工具。
