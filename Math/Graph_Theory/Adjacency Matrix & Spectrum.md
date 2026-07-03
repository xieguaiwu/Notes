---
tags:
  - Math
  - GraphTheory
  - LinearAlgebra
  - 定理性
  - 概念性
title: Adjacency Matrix & Spectrum
created: 2026-07-03
modified:
---

# 图——邻接矩阵与谱 (Adjacency Matrix & Spectrum)

> [!info] 来源
> Christopher Griffin, *Applied Graph Theory* (2023), 第 9 章：邻接矩阵与图谱 (Adjacency Matrix and Graph Spectrum)

> **前置知识**
> - [[Definitions]] — 图的基本词汇
> - [[Linear_Algebra/Eigenvalues and Eigenvectors]] — 特征值基础
> - [[Linear_Algebra/Matrix Operations]] — 矩阵乘法与转置
>
> **后续内容**
> - [[Laplacian & Spectral Clustering]] — Laplacian 矩阵与谱划分
> - [[Centrality Measures]] — 特征向量中心性、PageRank
> - [[Random Walks & PageRank]] — 图上的随机游走

---

## 1. 图的矩阵表示 (Matrix Representations of Graphs) (Griffin §9.1)

每个图 $G = (V, E)$（其中 $|V| = n$, $|E| = m$）都可以用多种矩阵表示。最基本的三种是**邻接矩阵**、**关联矩阵**和**度矩阵**。

### 1.1 邻接矩阵 $A$ (Adjacency Matrix)

**定义（邻接矩阵）**。设 $G = (V, E)$ 是简单图，顶点标记为 $V = \{v_1, v_2, \dots, v_n\}$。**邻接矩阵** $A = A(G)$ 是 $n \times n$ 矩阵，其元素为

$$
A_{ij} = \begin{cases}
1 & \text{若 } \{v_i, v_j\} \in E,\\[2pt]
0 & \text{否则}.
\end{cases}
$$

对于**无向**图，$A$ 是对称矩阵（$A^{\sf T} = A$）。对于**有向**图，若存在有向边 $v_i \to v_j$ 则 $A_{ij} = 1$；一般情况下 $A$ 不对称。

> [!example] 图及其邻接矩阵
> 考虑路径 $P_4$，顶点为 $1,2,3,4$，边为 $\{1,2\}, \{2,3\}, \{3,4\}$：
>
> ```mermaid
> graph LR
>     subgraph Graph["Graph G = P₄"]
>         direction LR
>         v1((1)) --- v2((2)) --- v3((3)) --- v4((4))
>     end
> ```
>
> $$
> A(P_4) = \begin{pmatrix}
> 0 & 1 & 0 & 0 \\
> 1 & 0 & 1 & 0 \\
> 0 & 1 & 0 & 1 \\
> 0 & 0 & 1 & 0
> \end{pmatrix}
> $$
>
> 对称矩阵，对角元为零（简单图），每行/列之和等于对应顶点的度数。

### 1.2 关联矩阵 $M$ (Incidence Matrix)

**定义（关联矩阵）**。设 $G = (V, E)$ 是图，有 $n$ 个顶点和 $m$ 条边。**关联矩阵** $M = M(G)$ 是 $n \times m$ 矩阵，其元素为

$$
M_{v,e} = \begin{cases}
1 & \text{若顶点 $v$ 与边 $e$ 关联},\\
0 & \text{否则}.
\end{cases}
$$

对于无向图，每一列（对应一条边）恰好有两个 1（即两个端点）。对于有向图，我们使用 $M_{v,e} = 1$ 表示出边，$-1$ 表示入边，否则为 0。

> [!note] 与 Laplacian 的关系
> 关联矩阵满足 $M M^{\sf T} = D + A$，其中 $D$ 是度矩阵（见下文）。对于使用带符号关联矩阵的有向图，$M M^{\sf T}$ 就是 **Laplacian 矩阵** $L = D - A$。

### 1.3 度矩阵 $D$ (Degree Matrix)

**定义（度矩阵）**。设 $G = (V, E)$ 是图。**度矩阵** $D = D(G)$ 是 $n \times n$ 对角矩阵

$$
D_{ij} = \begin{cases}
\deg(v_i) & \text{若 } i = j,\\
0 & \text{否则}.
\end{cases}
$$

对于上文的路径 $P_4$，有 $\deg(1)=1,\; \deg(2)=2,\; \deg(3)=2,\; \deg(4)=1$，因此

$$
D(P_4) = \operatorname{diag}(1, 2, 2, 1) = \begin{pmatrix}
1 & 0 & 0 & 0 \\
0 & 2 & 0 & 0 \\
0 & 0 & 2 & 0 \\
0 & 0 & 0 & 1
\end{pmatrix}.
$$

---

## 2. 邻接矩阵的性质 (Properties of the Adjacency Matrix)

### 2.1 途径与 $A$ 的幂 (Walks and Powers of $A$)（定理 9.1）

将代数与图结构联系起来的核心性质是：$A$ 的幂可以计数途径。

> [!abstract] 定理 9.1（途径计数）
> 设 $G = (V, E)$ 是简单图，邻接矩阵为 $A$。对任意 $k \ge 1$，元素 $(A^k)_{ij}$ 等于从顶点 $v_i$ 到顶点 $v_j$ 的**长度为 $k$ 的途径数**。

*对 $k$ 归纳证明。*

- **基础情况 $k = 1$：** $A_{ij} = 1$ 当且仅当 $\{v_i, v_j\} \in E$，即从 $i$ 到 $j$ 恰好有一条长度为 1 的途径（即边本身），否则为 0。✓
- **归纳步骤：** 假设命题对 $k$ 成立。那么
  $$
  (A^{k+1})_{ij} = \sum_{t=1}^{n} (A^k)_{it} \cdot A_{tj}.
  $$
  由归纳假设，$(A^k)_{it}$ 计数从 $i$ 到 $t$ 的长度为 $k$ 的途径数。乘以 $A_{tj}$ 则筛选出最后一步为 $t \to j$ 的途径。对所有中间顶点 $t$ 求和，即得到从 $i$ 到 $j$ 的长度为 $k+1$ 的途径总数。∎

> [!example] 3-正则图上的途径计数
> 考虑完全图 $K_4$，它是 **3-正则**的（每个顶点度数为 3）：
>
> ```mermaid
> graph LR
>     subgraph K4["K₄ (3-regular)"]
>         direction LR
>         1((1)) --- 2((2))
>         1 --- 3((3))
>         1 --- 4((4))
>         2 --- 3
>         2 --- 4
>         3 --- 4
>     end
> ```
>
> $$
> A(K_4) = \begin{pmatrix}
> 0 & 1 & 1 & 1\\
> 1 & 0 & 1 & 1\\
> 1 & 1 & 0 & 1\\
> 1 & 1 & 1 & 0
> \end{pmatrix}
> $$
>
> 计算 $A^2$：
>
> $$
> A^2 = \begin{pmatrix}
> 3 & 2 & 2 & 2\\
> 2 & 3 & 2 & 2\\
> 2 & 2 & 3 & 2\\
> 2 & 2 & 2 & 3
> \end{pmatrix}
> $$
>
> - **对角线** $(A^2)_{ii} = 3$：从 $i$ 到 $i$ 恰好有 3 条长度为 2 的途径（任选一个邻居 $j\neq i$ 并返回：$i \to j \to i$）。
> - **非对角线** $(A^2)_{ij} = 2$（$i \neq j$）：不同顶点之间恰好有 2 条长度为 2 的途径（两个共同邻居；在 $K_4$ 中，每对顶点共享另外两个顶点作为共同邻居）。例如，$1 \to 3 \to 2$ 和 $1 \to 4 \to 2$ 是从 1 到 2 的两条途径。

### 2.2 迹恒等式 (Trace Identities)

$A$ 及其幂的迹编码了图的基本不变量。

| 恒等式 | 推导 |
|:---------|:-----------|
| $\operatorname{tr}(A) = 0$ | 简单图无自环 ⇒ 所有 $A_{ii}=0$。 |
| $\operatorname{tr}(A^2) = 2|E|$ | $(A^2)_{ii} = \sum_j A_{ij}A_{ji} = \sum_j A_{ij}^2 = \deg(v_i)$，故 $\operatorname{tr}(A^2) = \sum_i \deg(v_i) = 2|E|$。 |
| $\operatorname{tr}(A^3) = 6 \times (\# \text{ of triangles})$ | $(A^3)_{ii}$ 计数长度为 3 的闭途径，每个三角形贡献 6 条途径（3 个起点 × 2 个方向）。 |

### 2.3 正则图 (Regular Graphs)

**定理（正则图特征值）**。若 $G$ 是 **$k$-正则图**（每个顶点度数为 $k$），则：

1. $k$ 是 $A$ 的一个特征值，对应特征向量 $\mathbf{1} = (1, 1, \dots, 1)^{\sf T}$。
2. 对 $A$ 的每个特征值 $\lambda$，有 $|\lambda| \le k$。
3. $G$ 连通当且仅当 $k$ 是**单重**特征值（重数为 1）。

*证明概要。* 对 $k$-正则图，$A$ 的每行之和为 $k$，故 $A \mathbf{1} = k \mathbf{1}$。其余结论由 Perron–Frobenius 定理得出（见 §3.3）。∎

---

## 3. 邻接矩阵的特征值 (Eigenvalues of the Adjacency Matrix) (Griffin §9.2)

### 3.1 谱 (The Spectrum)

**定义（谱）**。设 $A$ 是 $G$ 的邻接矩阵。$A$ 的特征值多重集 $\{\lambda_1, \lambda_2, \dots, \lambda_n\}$（包含重数）称为 $G$ 的**谱**，记为 $\operatorname{Sp}(G)$。

对于无向图，$A$ 是**实对称**矩阵，因此：
- 所有特征值都是实数。
- $A$ 可被正交矩阵对角化（[[Linear_Algebra/Spectral Theorem]]）。
- 存在一组标准正交的特征向量基。

### 3.2 谱半径与界 (Spectral Radius and Bounds)

**定义（谱半径）**。$G$ 的**谱半径**是最大绝对特征值：

$$
\rho(G) = \max_{i} |\lambda_i|.
$$

**定理（谱半径的界）**。对任意图 $G$，设最小度为 $\delta(G)$，最大度为 $\Delta(G)$，则：

$$
\delta(G) \le \rho(G) \le \Delta(G).
$$

此外，若 $G$ 连通，则 $\rho(G) < \Delta(G)$，**除非** $G$ 是正则图（此时 $\rho(G) = \Delta(G) = k$）。

> [!example] $C_4$ 的特征值分布
> 4-圈 $C_4$ 的邻接矩阵为：
>
> $$
> A(C_4) = \begin{pmatrix}
> 0 & 1 & 0 & 1\\
> 1 & 0 & 1 & 0\\
> 0 & 1 & 0 & 1\\
> 1 & 0 & 1 & 0
> \end{pmatrix}
> $$
>
> 其特征值为 $\{2, 0, 0, -2\}$。此处 $\delta(G)=\Delta(G)=2$，故 $\rho(G)=2 = \Delta(G)$（正则图）。
>
> ```mermaid
> xychart-beta
>     title "Spectrum of C₄: {2, 0, 0, -2}"
>     x-axis ["-2", "0", "2"]
>     y-axis "Multiplicity" 0 --> 2
>     bar [1, 2, 1]
> ```
>
> 谱关于 0 对称——$C_4$ 是二分图（见 §4.2）。

### 3.3 Perron–Frobenius 定理 (Perron–Frobenius Theorem)

**Perron–Frobenius 定理**是谱图理论的基石。它支配着非负矩阵的谱性质，进而支配着连通图邻接矩阵的谱性质。

> [!abstract] Perron–Frobenius 定理
> 设 $A$ 是 $n \times n$ **非负**（$A_{ij} \ge 0$）且**不可约**的矩阵。则：
>
> 1. **谱半径是特征值：** $\rho(A) > 0$ 是 $A$ 的一个特征值。
> 2. **单重性：** $\rho(A)$ 是**单重特征值**（代数重数为 1）。
> 3. **正特征向量：** 存在一个全正特征向量 $x > 0$（所有分量严格为正），满足 $A x = \rho(A) x$。
> 4. **支配性：** 对 $A$ 的任意特征值 $\lambda$，有 $|\lambda| \le \rho(A)$。
> 5. **循环性：** 若 $A$ 有 $h$ 个模等于 $\rho(A)$ 的特征值，则它们为 $\rho(A) \cdot e^{2\pi i k / h}$，其中 $k = 0, 1, \dots, h-1$。整数 $h$ 称为**本原指数**。

> [!note] 对图论的意义
> 对于**连通**图 $G$，邻接矩阵 $A$ 是非负且不可约的（不可约性等价于图的连通性）。应用 Perron–Frobenius 定理：
> - $\rho(G)$ 是单重特征值（称为 **Perron 根**或 **Perron–Frobenius 特征值**）。
> - Perron 特征向量 $x > 0$ 称为 **Perron 向量**；其每个分量对应一个顶点，均为正值。
> - 若 $G$ 是正则图，则 Perron 向量为 $\mathbf{1}$，且 $\rho(G)=k$。
> - 若 $G$ 是连通的二分图，则谱关于 0 对称，且 $h=2$（恰好有两个特征值的模等于 $\rho(G)$：$+\rho(G)$ 和 $-\rho(G)$）。

证明参见 [[Abstract_Algebra/Group]] 中相关的矩阵论概念（不可约性、本原性）。

---

## 4. 谱图性质 (Spectral Graph Properties)

### 4.1 基本谱不变量 (Basic Spectral Invariants)

设 $\operatorname{Sp}(G) = \{\lambda_1, \dots, \lambda_n\}$。以下结论可直接从迹恒等式和特征值的定义得出：

| 不变量 | 公式 | 说明 |
|:----------|:--------|:------------|
| 特征值个数 | $n = \|V\|$ | $A$ 是 $n \times n$ 矩阵。 |
| 特征值之和 | $\sum_{i=1}^n \lambda_i = 0$ | $\operatorname{tr}(A) = 0$（无自环）。 |
| 平方和 | $\sum_{i=1}^n \lambda_i^2 = 2\|E\|$ | $\operatorname{tr}(A^2) = 2\|E\|$。 |
| 立方和 | $\sum_{i=1}^n \lambda_i^3 = 6 \times (\# \text{ triangles})$ | $\operatorname{tr}(A^3)$ 计数有向 3-圈。 |
| 非零特征值个数 | $\le \operatorname{rank}(A)$ | 基础线性代数。 |

### 4.2 二分图与谱对称性 (Bipartite Graphs and Spectral Symmetry)

**定理（二分图的谱）**。图 $G$ 是**二分图**当且仅当其谱关于 **0 对称**：即 $\lambda$ 是重数为 $m$ 的特征值当且仅当 $-\lambda$ 也是相同重数的特征值。

> [!example]
> 圈 $C_4$ 是二分图，谱为 $\{2, 0, 0, -2\}$。圈 $C_3$（三角形）不是二分图，其特征值 $\{2, -1, -1\}$ 不关于 0 对称。

*证明概要。* ($\Rightarrow$) 若 $G$ 是二分图，二分划分为 $V_1, V_2$，将顶点重新排序使 $V_1$ 在前。则 $A$ 具有分块形式 $\begin{pmatrix}0 & B \\ B^{\sf T} & 0\end{pmatrix}$。若 $(\lambda, u)$ 是一个特征对，则 $(-\lambda, u')$ 也是特征对，其中 $u'$ 将一个分部的分量取反。($\Leftarrow$) 若谱对称，则对所有 $k$ 有 $\operatorname{tr}(A^{2k+1}) = 0$，说明不存在奇圈 ⇒ $G$ 是二分图。∎

### 4.3 同谱图 (Cospectral Graphs)

两个图称为**同谱的**，若它们谱相同但**非同构**。同谱性表明谱本身不能唯一确定一个图。

> [!example] 一个最小同谱对
> 图 $C_4 \cup K_1$（一个 4-圈加一个孤立顶点）和 $K_{1,4}$（具有 4 个叶子的星图）是**同谱**但**非同构**的：
>
> ```mermaid
> graph LR
>     subgraph G1["G₁ = C₄ ∪ K₁"]
>         direction TB
>         c1((1)) --- c2((2))
>         c2 --- c3((3))
>         c3 --- c4((4))
>         c4 --- c1
>         iso((5))
>     end
>     subgraph G2["G₂ = K₁,₄ (Star)"]
>         direction TB
>         center((c)) --- l1((1))
>         center --- l2((2))
>         center --- l3((3))
>         center --- l4((4))
>     end
> ```
>
> 两者共享相同的谱 $\{2, 0, 0, 0, -2\}$ 和特征多项式 $\lambda^5 - 4\lambda^3$。
>
> | 图 | 连通分支数 | 结构 | 区分不变量 |
> |:------|:----------:|:----------|:-------------------------|
> | $C_4 \cup K_1$ | 2 个分支 | 一个圈（4 个顶点）+ 孤立顶点 | 包含圈 |
> | $K_{1,4}$ | 1 个分支 | 树（无圈） | 二分图，无圈 |
>
> 虽然它们谱相同，但连通分支数、围长和直径均不同——这表明**谱 ≠ 同构**。

### 4.4 特征多项式 (Characteristic Polynomial)

**定义**。$G$ 的**特征多项式**为

$$
\phi_G(\lambda) = \det(\lambda I - A) = \lambda^n + c_1 \lambda^{n-1} + c_2 \lambda^{n-2} + \cdots + c_n.
$$

由于 $\operatorname{tr}(A)=0$，系数 $c_1 = -\operatorname{tr}(A) = 0$。系数具有图论意义，可通过 **Sachs 定理**（Harary–Sachs 定理）解释：$c_k$ 由基本子图（边和圈的互不相交并）决定。

常见图的特征多项式：

| 图 | 特征多项式 |
|:------|:--------------------------|
| $P_n$（路径） | $\prod_{j=1}^n \bigl(\lambda - 2\cos\frac{j\pi}{n+1}\bigr)$ |
| $C_n$（圈） | $\prod_{j=0}^{n-1} \bigl(\lambda - 2\cos\frac{2\pi j}{n}\bigr)$ |
| $K_n$（完全图） | $(\lambda - n+1)(\lambda + 1)^{n-1}$ |
| $K_{a,b}$（完全二分图） | $\lambda^{n-2}(\lambda^2 - ab)$，其中 $n = a+b$ |

---

## 5. 强正则图 (Strongly Regular Graphs)

强正则图（SRG）是受约束最严格的一类图，其谱完全由四个整数参数决定。

### 5.1 定义与参数 (Definition and Parameters)

**定义（强正则图）**。具有 $n$ 个顶点的 $k$-正则图 $G$ 称为参数为 $(n, k, \lambda, \mu)$ 的**强正则图**——记为 $\operatorname{SRG}(n, k, \lambda, \mu)$——若满足：

1. 每对**相邻**顶点恰好有 $\lambda$ 个共同邻居。
2. 每对**不相邻**（不同）顶点恰好有 $\mu$ 个共同邻居。

> [!note] 参数约束
> 对于非平凡的 SRG（不是完全图或空图），参数必须满足：
> - $k(k - \lambda - 1) = (n - k - 1)\mu$（计数长度为 2 的路径）。
> - $0 \le \lambda \le k-1$，$1 \le \mu \le k$。

### 5.2 SRG 的特征值 (Eigenvalues of SRGs)

$\operatorname{SRG}(n, k, \lambda, \mu)$ 的邻接矩阵满足二次关系：

$$
A^2 = kI + \lambda A + \mu(J - I - A)
$$

由此可得三个互异的特征值：

| 特征值 | 值 | 重数 |
|:-----------|:------|:-------------|
| $\lambda_1 = k$（**正则**特征值） | $k$ | 1 |
| $\lambda_2 = r$ | $\frac{1}{2}\bigl[(\lambda - \mu) + \sqrt{(\lambda - \mu)^2 + 4(k - \mu)}\bigr]$ | $m_r$ |
| $\lambda_3 = s$ | $\frac{1}{2}\bigl[(\lambda - \mu) - \sqrt{(\lambda - \mu)^2 + 4(k - \mu)}\bigr]$ | $m_s$ |

其中 $r + s = \lambda - \mu$，$rs = \mu - k$。重数满足：

$$
m_r + m_s = n - 1,\qquad k + m_r r + m_s s = 0.
$$

### 5.3 示例：Petersen 图 (Example: The Petersen Graph)

**Petersen 图**是强正则图的标准示例：

$$
\operatorname{Petersen} = \operatorname{SRG}(10, 3, 0, 1).
$$

- $n = 10$ 个顶点
- $k = 3$（3-正则）
- $\lambda = 0$（相邻顶点**没有**共同邻居）
- $\mu = 1$（不相邻顶点恰好有 **1** 个共同邻居）

使用特征值公式计算：

$$
r = \frac{1}{2}\bigl[(0-1) + \sqrt{1 + 4(3-1)}\bigr] = \frac{1}{2}[-1 + \sqrt{9}] = 1,
$$
$$
s = \frac{1}{2}\bigl[-1 - 3\bigr] = -2.
$$

重数为 $m_r = 5$，$m_s = 4$。因此 Petersen 图的谱为：

$$
\operatorname{Sp}(\text{Petersen}) = \{3^1,\; 1^5,\; -2^4\},
$$

其中上标表示重数。

> [!note] 唯一性
> Petersen 图是**唯一**的 $\operatorname{SRG}(10,3,0,1)$（在同构意义下）。强正则参数并不总是唯一确定一个图——存在具有相同参数但非同构的 SRG，称为**切换等价**图。

---

## 6. 符号速查 (Symbol Reference)

| 符号 | 含义 | 首次出现 |
|:-------|:--------|:-----------|
| $A$ | 邻接矩阵（$n \times n$） | §1.1 |
| $M$ | 关联矩阵（$n \times m$） | §1.2 |
| $D$ | 度矩阵（对角矩阵） | §1.3 |
| $\operatorname{Sp}(G)$ | $A(G)$ 的特征值多重集 | §3.1 |
| $\rho(G)$ | 谱半径，$\max_i \|\lambda_i\|$ | §3.2 |
| $\delta(G), \Delta(G)$ | 最小度，最大度 | §3.2 |
| $\phi_G(\lambda)$ | 特征多项式 $\det(\lambda I - A)$ | §4.4 |
| $\operatorname{SRG}(n, k, \lambda, \mu)$ | 强正则图参数 | §5.1 |
| $\mathbf{1}$ | 全 1 向量 $(1,1,\dots,1)^{\sf T}$ | §2.3 |
| $J$ | 全 1 矩阵（每个元素 $=1$） | §5.2 |

---

## 7. 相关链接 (Related Notes)

- [[Linear_Algebra/Eigenvalues and Eigenvectors]] — 特征值基本理论
- [[Linear_Algebra/Spectral Theorem]] — 实对称矩阵对角化
- [[Linear_Algebra/Diagonalization]] — 矩阵对角化一般理论
- [[Abstract_Algebra/Group]] — Perron–Frobenius 概念：不可约矩阵与本原性
- [[Laplacian & Spectral Clustering]] — Laplacian 矩阵与谱聚类
- [[Centrality Measures]] — 特征向量中心性使用 Perron 向量
- [[Isomorphism & Automorphism]] — 谱作为图不变量
- [[Walks, Cycles & Connectivity]] — 途径、迹与连通性
