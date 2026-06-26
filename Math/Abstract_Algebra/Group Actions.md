---
title: Group Actions
tags:
  - Math
  - AbstractAlgebra
  - 概念性
  - 定理性
created: 2026-06-25
modified: 2026-06-25
---

# Group Actions

> [!abstract] 概述
> **群作用 (Group Action)** 是群"作用于"某个集合的方式——每个群元素充当该集合上的一个置换，且运算与群乘法相容。群作用是连接代数和组合/几何的桥梁：它把抽象群变成了具体的变换。

## 定义

设 $G$ 是群，$X$ 是非空集合。$G$ 在 $X$ 上的（左）**作用**是一个映射

$$\varphi: G \times X \to X, \quad (g, x) \mapsto g \!\cdot\! x$$

满足：

1. **单位元作用**：$\forall x \in X,\; e \!\cdot\! x = x$
2. **相容性**：$\forall g, h \in G,\; \forall x \in X,\; g \!\cdot\! (h \!\cdot\! x) = (gh) \!\cdot\! x$

> [!tip] 等价刻画
> 群作用 $G \curvearrowright X$ 等价于一个[[Group Homomorphisms|群同态]] $\rho: G \to S_X$，其中 $S_X$ 是 $X$ 上的[[Permutation Groups|置换群]]。$\rho(g)$ 就是"$g$ 所对应的置换"。


## 轨道与稳定子

### 轨道 (Orbit)

元素 $x \in X$ 的**轨道**是 $x$ 在群作用下所能到达的全部位置：

$$Gx = \{ g \!\cdot\! x \mid g \in G \}$$

轨道是 $X$ 上的等价类（$x \sim y \iff \exists g,\; y = g \!\cdot\! x$），$X$ 被划分为不相交的轨道之并。

### 稳定子 (Stabilizer)

元素 $x \in X$ 的**稳定子群**是固定 $x$ 不动的群元素集合：

$$G_x = \{ g \in G \mid g \!\cdot\! x = x \}$$

$G_x$ 是 $G$ 的[[Normal Subgroups and Quotient Groups|子群]]（但不一定是正规子群）。

### 轨道-稳定子定理

> [!theorem] 轨道-稳定子定理 (Orbit-Stabilizer Theorem)
> 若 $G$ 是有限群，则对任意 $x \in X$：
> $$|Gx| = \frac{|G|}{|G_x|}$$
> 即轨道的长度等于 $|G|$ 除以稳定子的阶。

**证明思路**：建立 $\{gG_x\}$（陪集）到 $\{g \!\cdot\! x\}$（轨道元素）的一一对应 $gG_x \mapsto g \!\cdot\! x$，然后应用 [[Cosets and Lagrange's Theorem|Lagrange 定理]]。$\square$

##### 数值示例：$D_4$ 作用在正方形顶点上

取 $D_4$（$|D_4|=8$），$X=\{\text{四个顶点}\}$。对顶点 1（左上角），稳定子含恒等+对角线反射，$|G_{v_1}|=2$；轨道为全部四个顶点，$|D_4v_1|=4$。验证：$4 = 8/2$。✓


## Burnside 引理

> [!theorem] Burnside 引理
> 设有限群 $G$ 作用在有限集 $X$ 上，$X/G$ 表示轨道集合。则轨道数：
> $$|X/G| = \frac{1}{|G|} \sum_{g \in G} |X^g|$$
> 其中 $X^g = \{ x \in X \mid g \!\cdot\! x = x \}$ 是 $g$ 的不动点集。

即：**轨道数等于各群元素不动点数的平均值**。

### 数值示例：项链着色

$G = D_4$（$|G|=8$），$X=2^4=16$ 种着色。

| 元素 | 个数 | 不动点条件 | $|X^g|$ |
|-----|:---:|-----------|:------:|
| 恒等 $e$ | 1 | 全部不动 | 16 |
| $90^\circ$ 旋转 | 2 | 四顶点同色 | 2 |
| $180^\circ$ 旋转 | 1 | 对顶点同色 | 4 |
| 对边反射 | 2 | 相邻两对同色 | 4 |
| 对角线反射 | 2 | 对角同色 | 4 |

$$|X/G| = \tfrac{1}{8}(16+2\times2+1\times4+2\times4+2\times4) = \tfrac{40}{8} = 5$$

**结果**：5 种不等价的二色正方形项链。


## 经典例子

### ① $S_n$ 在 $\{1,\dots,n\}$ 上的自然作用

$\sigma\!\cdot\! i = \sigma(i)$。轨道唯一（传递作用）；$|S_n|/|S_{n-1}| = n!/(n-1)! = n$ ✓。

### ② $\operatorname{GL}_n(\mathbb{R})$ 在 $\mathbb{R}^n$ 上的作用

$A \!\cdot\! v = Av$。轨道：$\mathbb{R}^n\setminus\{0\}$ 中任意两非零向量在同一轨道（基变换）。稳定子 $\cong \operatorname{GL}_{n-1}(\mathbb{R}) \rtimes \mathbb{R}^{n-1}$。

### ③ 左乘作用与 Cayley 定理

$g \!\cdot\! h = gh$，忠实（$g\!\cdot\! h = h \implies g = e$）。**Cayley 定理**：每个群同构于某个置换群的子群。

### ④ 共轭作用

$g \!\cdot\! x = gxg^{-1}$。轨道 = 共轭类 $\operatorname{Cl}(x)$，稳定子 = 中心化子 $C_G(x)$。$|\operatorname{Cl}(x)| = |G|/|C_G(x)|$。


## 共轭类与类方程

将轨道-稳定子定理应用于共轭作用，得**类方程 (Class Equation)**：

$$|G| = |Z(G)| + \sum_{[x]} \frac{|G|}{|C_G(x)|}$$

其中 $Z(G)$ 是中心，$[x]$ 取遍非中心共轭类代表元。类方程是 $p$-群非平凡中心、Sylow 定理等的关键工具。


## 应用

### 计数问题

Burnside 引理是组合计数的利器。除项链着色外，还可计算：
- 在对称群作用下图的不同构数目
- 多面体着色的不等价方案数
- 化学分子异构体计数

### 分类问题

- 群在集合上的作用决定了该集合的对称性结构
- 共轭作用给出了群的"分类骨架"——共轭类分解
- 传递作用等价于陪集空间 $G/H$，为分类所有群作用提供了范式


## 相关链接

- [[Group]] — 群定义
- [[Group Homomorphisms]] — 群作用 $\cong$ 同态 $G \to S_X$
- [[Permutation Groups]] — 置换表示
- [[Cosets and Lagrange's Theorem]] — 轨道-稳定子定理的陪集基础
- [[Normal Subgroups and Quotient Groups]] — 共轭与正规子群
