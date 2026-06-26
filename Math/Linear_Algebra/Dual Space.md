---
title: Dual Space
tags:
  - Math
  - LinearAlgebra
  - 概念性
  - 定义性
created: 2026-06-25
---

# Dual Space

## 定义

设 $V$ 是域 $F$ 上的向量空间。$V$ 上所有**线性泛函**的集合称作**对偶空间**：

$$
V^* := \mathcal{L}(V, F) = \{ f : V \to F \mid f \text{ 线性} \}
$$

加法和数乘逐点定义。如果向量是"箭头"，线性泛函就是"尺子"——将向量转化为标量的测量工具。

**维度：** $\dim V^* = \dim V$。线性泛函由其在基上的 $n$ 个取值唯一确定。

---

## 对偶基

设 $\{e_1, \dots, e_n\}$ 是 $V$ 的一组基。定义 $e^1, \dots, e^n \in V^*$ 为：

$$
e^i(e_j) = \delta_{ij}
$$

则 $\{e^1, \dots, e^n\}$ 构成 $V^*$ 的一组基，称为**对偶基**。

**坐标函数：** 对 $v = \sum v_j e_j$，有 $e^i(v) = v_i$——提取第 $i$ 个坐标分量。任一 $f \in V^*$ 可写为 $f = \sum f(e_i) \, e^i$。

> 度量视角：对偶基是"探头"，每个 $e^i$ 测量向量在 $e_i$ 方向的分量。

---

## 例子

**1. $\mathbb{R}^n$ 的点积：** 对固定 $a \in \mathbb{R}^n$，$f_a(x) = a \cdot x$ 是线性泛函。所有线性泛函都形如此（[[Inner Product and Norm|Riesz 表示定理]]雏形）。标准基的对偶基正是坐标函数 $e^i(x) = x_i$。

**2. 积分：** 设 $C[a,b]$ 为连续函数空间，$I(f) = \int_a^b f(x)\,dx$ 是线性泛函——用积分测量函数。

**3. 求值映射：** 固定 $x_0$，$\operatorname{ev}_{x_0}(f) = f(x_0)$ 是在某点"读取"函数值的线性泛函。

这些例子揭示对偶空间的本质：**线性泛函是对向量进行标量测量的工具**。

---

## 二次对偶 $V^{**}$

$V^*$ 本身是向量空间，可再次取对偶：$V^{**} := (V^*)^*$。定义自然映射 $\Phi: V \to V^{**}$：

$$
\Phi(v)(f) = f(v), \quad \forall f \in V^*
$$

- $\Phi$ 线性且单射
- $\dim V < \infty$ 时 $\Phi$ 是**同构**，且**不依赖基的选择**（自然同构）

**意义：** $V$ 与 $V^*$ 没有自然同构（需要选基或内积），但 $V$ 与 $V^{**}$ 有。向量本身可理解为"作用于泛函的泛函"——这就是有限维线性代数如此优雅的深层原因。无限维中 $V \subsetneq V^{**}$，$\Phi$ 仅为嵌入。

---

## 对偶映射（Transpose）

设 $T: V \to W$ 线性，定义 $T^{\mathsf{T}}: W^* \to V^*$：

$$
T^{\mathsf{T}}(f) = f \circ T
$$

**性质：** $(S \circ T)^{\mathsf{T}} = T^{\mathsf{T}} \circ S^{\mathsf{T}}$；$\ker(T^{\mathsf{T}}) = (\operatorname{im} T)^0$；$\operatorname{rank}(T^{\mathsf{T}}) = \operatorname{rank}(T)$。在矩阵表示下，$T^{\mathsf{T}}$ 对应 $A^{\mathsf{T}}$（转置矩阵）。

---

## 与其他概念的连接

- **[[Linear Transformations]]** — 线性泛函是 $T: V \to F$ 的特例
- **[[Bilinear Forms]]** — 双线性型诱导映射 $V \to V^*$；非退化时给出同构
- **[[Inner Product and Norm]]** — Riesz 表示定理：$\forall f \in V^*$，$\exists! u \in V$ 使 $f(v) = \langle v, u \rangle$，给出内积空间中的自然同构 $V \cong V^*$
- **[[Quotient Space]]** — $(V/W)^* \cong W^0$（零化子：在 $W$ 上为零的泛函）

---

## 总结

| 概念 | 测量什么 |
|------|----------|
| 线性泛函 | 向量 → 标量（"读数"） |
| 对偶基 $e^i$ | 第 $i$ 个坐标分量 |
| 积分泛函 | 函数的"面积" |
| 求值泛函 | 函数在某点值 |
| Riesz 表示 | 内积方向投影 |
| 对偶映射 | 变换前后的测量关系 |

**核心格言：** 向量是被测量的对象，对偶空间是测量工具的集合。二次对偶揭示：向量本身也是一种"测量测量的工具"。
