---
title: Tensor Products
tags:
  - Math
  - LinearAlgebra
  - 定义性
  - 概念性
created: 2026-06-25
---

# Tensor Products

## 1. 动机

双线性映射 $B: V \times W \to U$ 对每个变元分别线性，但**不是**向量空间之间的线性映射，因此无法直接使用矩阵、核、特征值等线性代数工具。

张量积的核心思想：**构造一个新的向量空间 $V \otimes W$，使得每个双线性映射 $B: V \times W \to U$ 唯一"因子分解"为一个线性映射 $L: V \otimes W \to U$**。双线性→线性，问题简化为标准线性代数。

---

## 2. Universal Property（泛性质）

> **定义（张量积）。** 向量空间 $V \otimes W$ 及其双线性映射 $\otimes: V \times W \to V \otimes W$ 满足：对任意双线性映射 $B: V \times W \to U$，存在**唯一**线性映射 $L: V \otimes W \to U$，使得下图交换：
>
> $$
> \begin{CD}
> V \times W @>{\otimes}>> V \otimes W \\
> @| @VV{L}V \\
> V \times W @>{B}>> U
> \end{CD}
> $$
>
> 即 $B(v,w) = L(v \otimes w)$ 对任意 $v \in V,\; w \in W$ 成立。

**泛性质的威力：** 一旦验证某个空间满足此性质，所有双线性映射的处理自动归结为这个空间上的线性映射。具体构造只是证明存在性。

---

## 3. 构造（概要）

令 $V,W$ 是域 $F$ 上的向量空间。取集合 $\{v \otimes w \mid v \in V,\; w \in W\}$ 生成的自由向量空间 $F(V \times W)$，模去双线性关系生成的子空间：

- $(v_1+v_2) \otimes w = v_1 \otimes w + v_2 \otimes w$
- $v \otimes (w_1+w_2) = v \otimes w_1 + v \otimes w_2$
- $c(v \otimes w) = (cv) \otimes w = v \otimes (cw)$

商空间 $F(V \times W) / \sim$ 即为 $V \otimes W$。直观上，$v \otimes w$ 是一个**形式符号**，只服从双线性规则——没有其他关系。

---

## 4. 维数与基

若 $V,W$ 有限维，$\{e_1,\dots,e_m\}$ 为 $V$ 的基，$\{f_1,\dots,f_n\}$ 为 $W$ 的基，则：

$$
\dim(V \otimes W) = \dim V \times \dim W
$$

且 $\{e_i \otimes f_j\}$ 构成 $V \otimes W$ 的一组基。任意 $t \in V \otimes W$ 唯一写成：

$$
t = \sum_{i=1}^m \sum_{j=1}^n a^{ij}\, (e_i \otimes f_j), \qquad a^{ij} \in F
$$

---

## 5. 张量的分量表示

$V \otimes W$ 中的元素称为**张量**。纯张量 $v \otimes w$ 在基下展开：

$$
v = \sum_i v^i e_i,\quad w = \sum_j w^j f_j \;\Longrightarrow\; v \otimes w = \sum_{i,j} v^i w^j\, (e_i \otimes f_j)
$$

分量 $a^{ij} = v^i w^j$ 是两坐标的**外积**。一般张量是纯张量的线性组合，分量 $a^{ij}$ 构成 $m \times n$ 矩阵——张量作为"多维数组"的代数根源。

---

## 6. 线性映射的张量积

给定线性映射 $T: V \to V'$ 和 $S: W \to W'$，诱导双线性映射 $B(v,w) = T(v) \otimes S(w)$。由泛性质，存在唯一线性映射 $T \otimes S: V \otimes W \to V' \otimes W'$，满足：

$$
(T \otimes S)(v \otimes w) = T(v) \otimes S(w)
$$

基下 $T \otimes S$ 的矩阵正是 $T$ 和 $S$ 的 **Kronecker 积**。性质：$(T_1 \otimes S_1) \circ (T_2 \otimes S_2) = (T_1 T_2) \otimes (S_1 S_2)$，$\mathrm{id}_V \otimes \mathrm{id}_W = \mathrm{id}_{V \otimes W}$。

---

## 7. 例子

### 7.1 $\mathbb{R}^m \otimes \mathbb{R}^n \cong \mathbb{R}^{mn}$

标准基 $e_i \in \mathbb{R}^m,\; f_j \in \mathbb{R}^n$ 下，$e_i \otimes f_j \mapsto$ 第 $(i,j)$ 位为 1 的 $mn \times 1$ 向量给出同构。双线性映射 $B: \mathbb{R}^m \times \mathbb{R}^n \to \mathbb{R}$ 对应矩阵 $M$，$L(v \otimes w) = v^T M w$。

### 7.2 Kronecker 积

若 $T \in \mathbb{R}^{p \times m},\; S \in \mathbb{R}^{q \times n}$，则 $T \otimes S$ 的 $(pq) \times (mn)$ 矩阵为：

$$
T \otimes S =
\begin{pmatrix}
t_{11} S & t_{12} S & \cdots & t_{1m} S \\
t_{21} S & t_{22} S & \cdots & t_{2m} S \\
\vdots   & \vdots   & \ddots & \vdots   \\
t_{p1} S & t_{p2} S & \cdots & t_{pm} S
\end{pmatrix}
$$

出现在量子力学（纠缠态）、控制系统和图像处理中。

### 7.3 双线性型作为对偶张量

双线性型 $B: V \times V \to F$ 等价于 $V^* \otimes V^*$ 中的元素。系数矩阵 $A_{ij} = B(e_i, e_j)$ 正是该张量的分量——**一切双线性型都是二阶协变张量**。

---

## 8. 连接

- [[Bilinear Forms]] — 双线性型位于 $V^* \otimes V^*$，张量积视角统一了其表示与变换。
- [[Dual Space]] — $V^*$ 参与构造 $(p,q)$-型混合张量 $V^{\otimes p} \otimes (V^*)^{\otimes q}$，微分几何的基石。
- [[Vector Spaces and Subspaces]] — 张量积与子空间、直和相容：$(U_1 \oplus U_2) \otimes W \cong (U_1 \otimes W) \oplus (U_2 \otimes W)$。

---

## 9. 高级简览

- **对称张量** $S^k V \subseteq V^{\otimes k}$：在置换 $\sigma$ 下 $v_1 \otimes \cdots \otimes v_k \mapsto v_{\sigma(1)} \otimes \cdots \otimes v_{\sigma(k)}$ 不变的子空间。对称代数 $\bigoplus_{k \ge 0} S^k V$ 同构于多项式代数 $F[v_1,\dots,v_n]$。
- **交错张量** $\bigwedge^k V$：在奇置换下变号。外代数（Grassmann 代数）$\bigwedge V = \bigoplus_{k=0}^n \bigwedge^k V$ 是微分形式、行列式理论和 de Rham 上同调的基础。

张量积提供了从线性空间"生长"出多项式代数和外代数的统一钥匙。
