---
title: "Mathematical Foundations of Greedy Algorithms"
tags:
  - Math
  - Algorithm
  - Combinatorics
  - 定理性
  - 基本原理
created: 2026-07-23
---

# Mathematical Foundations of Greedy Algorithms

> [!abstract] 概述
> 贪心算法是计算机科学中一类重要的算法范式，但其有效性往往被归因于直觉而非严格的数学结构。本笔记从**纯数学**的角度剖析贪心算法背后的最优性条件，揭示许多贪心算法实质上是对某一数学优化问题的**精确解析解**的计算化表达。

---

## 1. 拉格朗日乘子法与分数背包

### 1.1 问题重构

分数背包问题（Fractional Knapsack）的标准叙述是：给定容量 $T$ 的背包，$n$ 个物品各有权重 $w_i$ 和价值 $v_i$，物品可分割，求最大总价值。将其写为线性规划：

\[
\begin{aligned}
\max \quad & \sum_{i=1}^n v_i x_i \\
\text{s.t.} \quad & \sum_{i=1}^n w_i x_i \le T \\
& 0 \le x_i \le 1
\end{aligned}
\]

其中 $x_i \in [0,1]$ 表示物品 $i$ 被装入的比例。

### 1.2 拉格朗日松弛

构造拉格朗日函数（引入对偶变量 $\lambda \ge 0$）：

\[
\mathcal{L}(x, \lambda) = \sum_{i=1}^n v_i x_i - \lambda \left(\sum_{i=1}^n w_i x_i - T\right)
= \sum_{i=1}^n (v_i - \lambda w_i) x_i + \lambda T
\]

对于给定的 $\lambda$，由于 $x_i$ 之间无耦合，每一项 $(v_i - \lambda w_i)x_i$ 可独立优化：

\[
x_i^*(\lambda) =
\begin{cases}
1, & v_i - \lambda w_i > 0 \iff v_i/w_i > \lambda \\[4pt]
0, & v_i - \lambda w_i < 0 \iff v_i/w_i < \lambda \\[4pt]
\in [0,1], & v_i/w_i = \lambda
\end{cases}
\]

### 1.3 互补松弛与临界比率

由互补松弛条件（Complementary Slackness），当约束紧时 $\lambda > 0$ 且：

\[
\lambda \left(\sum_{i=1}^n w_i x_i - T\right) = 0
\]

最优 $\lambda^*$ 使得 $\sum w_i x_i^*(\lambda^*) = T$。换言之，$\lambda^*$ 恰好是**最后一个部分装入的物品的单位价值比率**。

### 1.4 结论

> [!tip] 数学本质
> 贪心算法中按 $v_i/w_i$ 排序并依次装入的过程，**等价于**拉格朗日乘子法中寻找临界阈值 $\lambda^*$ 的离散实现。排序是在隐式地确定 KKT 条件中的活跃约束集，而最后部分装入的那个物品就是在解方程 $\sum w_i x_i = T$。

因此分数背包的贪心算法**不是**一个启发式方法——它是线性规划 KKT 条件的精确数值解法。

---

## 2. 排序不等式与调度问题

### 2.1 排队接水问题

$N$ 个人打水，第 $i$ 人用时 $t_i > 0$。求使平均等待时间最小的排列顺序。

设排列 $\pi$，第 $i$ 个人的等待时间为之前所有人的用时之和，总等待时间：

\[
S(\pi) = 0 \cdot t_{\pi(1)} + 1 \cdot t_{\pi(2)} + 2 \cdot t_{\pi(3)} + \cdots + (N-1) \cdot t_{\pi(N)}
= \sum_{i=1}^N (i-1) \cdot t_{\pi(i)}
\]

### 2.2 排序不等式

> [!note] 排序不等式（Rearrangement Inequality）
> 设 $a_1 \le a_2 \le \cdots \le a_n$，$b_1 \le b_2 \le \cdots \le b_n$，则对任意排列 $\sigma$：
> \[
> \sum_{i=1}^n a_i b_{n-i+1} \le \sum_{i=1}^n a_i b_{\sigma(i)} \le \sum_{i=1}^n a_i b_i
> \]
> 即**顺序和 $\ge$ 乱序和 $\ge$ 逆序和**。

在总等待时间中，系数向量 $c = (0, 1, 2, \dots, N-1)$ **递增**。要最小化 $\sum c_i t_{\pi(i)}$，由排序不等式，应将 $t$ 按**升序**排列以形成逆序对配置——即最大的时间配最小的系数。

### 2.3 相邻交换证明

若不用排序不等式，也可以直接通过相邻交换证明：

设存在相邻逆序对 $t_i > t_{i+1}$ 但访问顺序为 $\dots, t_i, t_{i+1}, \dots$。交换二者得 $\dots, t_{i+1}, t_i, \dots$，总等待时间的变化：

\[
\Delta = [(i-1)t_{i+1} + i\cdot t_i] - [(i-1)t_i + i\cdot t_{i+1}] = t_i - t_{i+1} < 0
\]

交换后总时间严格减少。因此任何非升序排列都可以通过有限次相邻交换改进，最优排列必为升序。

> [!tip] 数学本质
> 这个问题的贪心选择（"选当前等待时间最短的人先服务"）实质上是在**增量构造排序不等式的逆序对配置**。每一步的"局部最优"等价于数学上必然的全局最优——不需要任何"试错"或"回溯"。

### 2.4 一般形式：Smith 规则

更一般地，对于最小化加权完成时间和的调度问题：

\[
\min \sum_{i=1}^n w_i C_i
\]

其中 $C_i$ 为任务 $i$ 的完成时间，最优策略是按 $t_i / w_i$ 升序排列（Smith's Rule），这是排序不等式在高维的推广。

---

## 3. 信息论与最优前缀码

### 3.1 问题与目标

合并果子问题（Optimal Merge Pattern / Huffman Coding）：给定 $n$ 个符号的频率 $w_1, \dots, w_n$，构造一棵二叉树使得加权路径长度最小：

\[
C = \sum_{i=1}^n w_i d_i
\]

其中 $d_i$ 为符号 $i$ 在树中的深度。

### 3.2 熵界

设 $W = \sum w_i$ 为总权重，$p_i = w_i / W$ 为概率分布。Huffman 树的最小加权路径长度满足信息论下界：

\[
H(p) \le \frac{C}{W} < H(p) + 1
\]

其中 $H(p) = -\sum_{i=1}^n p_i \log_2 p_i$ 为信息熵。

> [!note] 解释
> - **下界** $\frac{C}{W} \ge H(p)$：每个符号至少需要 $-\log_2 p_i$ 比特来区分，由 Kraft 不等式与 Shannon 信源编码定理保证。
> - **上界** $\frac{C}{W} < H(p) + 1$：Huffman 编码总是可以在 1 比特之内达到熵界。
> - **推广**：当权重为 $2$ 的负幂次时，$\frac{C}{W} = H(p)$，Huffman 编码的冗余为零。

### 3.3 信源编码定理视角

Shannon 第一定理（信源编码定理）指出：对于独立同分布信源，任何唯一可译码的平均码长不小于信源的熵。Huffman 算法的贪心策略（将最小概率的两个符号合并）被证明是**唯一**能精确达到这个下界（至多 +1 比特）的构造方法。

### 3.4 数学本质

> [!tip] 数学本质
> 贪心合并两个最小权重元素的策略，等价于在概率单纯形上沿**最小信息损失**方向递归折叠。每一步不是"任意"选择，而是在保持最优子结构的同时，使当前折叠对总代价的增量最小——这一点由 **Sibling Property**（Gallager, 1978）形式化刻画。

---

## 4. 拟阵论：贪心有效的统一框架

### 4.1 拟阵的定义

> [!note] 拟阵（Matroid）
> 一个拟阵 $\mathcal{M} = (E, \mathcal{I})$ 由有限集 $E$ 和独立集族 $\mathcal{I} \subseteq 2^E$ 构成，满足：
> 1. **空集独立**：$\emptyset \in \mathcal{I}$
> 2. **遗传性**：若 $A \in \mathcal{I}$ 且 $B \subseteq A$，则 $B \in \mathcal{I}$
> 3. **交换性**：若 $A, B \in \mathcal{I}$ 且 $|A| < |B|$，则 $\exists x \in B \setminus A$ 使得 $A \cup \{x\} \in \mathcal{I}$

### 4.2 Rado-Edmonds 定理

> [!tip] Rado-Edmonds 贪心定理
> 在拟阵 $\mathcal{M} = (E, \mathcal{I})$ 上，给定非负权函数 $w: E \to \mathbb{R}^+$，贪心算法（每次选权值最大且保持独立性的元素）得到的独立集 $G$ 是**最大权独立集**。

这是**充要条件**：如果一个组合优化问题的可行域构成拟阵，则贪心算法必然得到全局最优；反之，如果一个问题的贪心算法对所有权函数都正确，则其可行域必构成拟阵。

### 4.3 拟阵贪心的经典实例

| 问题 | 底集 $E$ | 独立集 $\mathcal{I}$ | 拟阵类型 |
|------|----------|----------------------|----------|
| **MST (Kruskal)** | 图的所有边 | 不形成环的边集 | 图拟阵（Graphic Matroid） |
| **任务调度（单机、最小化延迟）** | 所有任务 | 调度可行的任务子集 | 贪婪拟阵（Greedoid） |
| **最大线性无关组** | 向量集合 | 线性无关的向量子集 | 向量拟阵（Vector Matroid） |
| **拟阵交**（一般不可贪心） | — | 两个拟阵独立集的交 | 需拟阵交算法 |

### 4.4 与常见贪心的对应

| 经典贪心问题 | 是否拟阵 | 若否，原因 |
|---|---|---|
| 分数背包 | ✅ 是（均匀拟阵 + 连续松弛） | — |
| 活动选择 | ✅ 是（图拟阵的特殊结构） | — |
| Huffman 编码 | ⚠️ 广义拟阵（贪婪拟阵） | 树结构非拟阵但有类似交换性 |
| 0-1 背包 | ❌ | 约束违反拟阵交换性 |
| TSP 最近邻 | ❌ | 路径结构无遗传性 |

### 4.5 数学本质

> [!tip] 数学本质
> 拟阵论为贪心算法的有效性提供了**最深刻**的数学解释：贪心正确的充要条件是问题具有**拟阵结构**。不是在拟阵上贪心特别高效，而是在拟阵上贪心**必然正确**。这回答了"为什么有些问题贪心有效而另一些不行"的根本问题。

---

## 5. 线性规划对偶性

### 5.1 原始-对偶视角

将贪心问题视为线性规划，其对偶问题给出了**贪心选择的定价解释**。

以分数背包为例：

\[
\begin{aligned}
\text{原始 (P)} \quad & \max_{x \ge 0} v^\top x & \quad \text{对偶 (D)} \quad & \min_{\lambda \ge 0, \mu \ge 0} \lambda T + \mu^\top \mathbf{1} \\
& \text{s.t. } w^\top x \le T & & \text{s.t. } \lambda w_i + \mu_i \ge v_i, \ \forall i \\
& x_i \le 1 & &
\end{aligned}
\]

对偶变量 $\lambda$ 是**背包容量的影子价格**（每增加一单位容量带来的价值增量），$\mu_i$ 是**物品 $i$ 的整数性价格**。

贪心算法的排序比率 $v_i/w_i$ 恰好是影子价格的排序——贪心选择断在 $v_i/w_i < \lambda^*$ 处，即物品价值不足以支付其占用的容量成本时停止。

### 5.2 经济学解释

- $\lambda^*$ 是背包的**边际容量价值**
- $v_i - \lambda^* w_i > 0$ 的物品是"盈利"的（可装入）
- $v_i - \lambda^* w_i < 0$ 的物品是"亏损"的（应排除）

这种解释适用于一切具有线性结构的贪心问题。

---

## 6. 数学方法 vs 算法实现对照

| 贪心问题 | 传统算法描述 | 纯数学方法 | 核心数学工具 |
|----------|-------------|-----------|-------------|
| 分数背包 | 按 $v/w$ 排序 | 解 KKT 系统求 $\lambda^*$ | 拉格朗日乘子法 |
| 排队接水 | 排序+模拟 | 排序不等式取等条件 | 重排不等式 |
| Huffman 编码 | 最小堆合并 | 熵界 + Sibling Property | 信息熵 |
| MST (Kruskal) | 并查集+贪心选边 | 图拟阵上 Rado-Edmonds | 拟阵论 |
| 活动选择 | 按结束时间排序 | 区间图拟阵 | 拟阵论 |
| 最小化加权完成时间 | Smith 规则排序 | 交换论证/排序不等式推广 | 偏序与拟阵 |

---

## 相关笔记

- [[Programming/Greedy Algorithm]] — 贪心算法的算法实现与经典例题
- [[Math/Graph Theory]] — 图论基础（MST 的 Kruskal/Prim）
- [[Math/Linear Algebra]] — 线性无关性与向量拟阵
- [[Math/Combinatorial]] — 组合优化的数学基础
- [[Math/Set Theory]] — 集合系统与拟阵的集合论基础

## 参考文献

- Edmonds, J. "Matroids and the Greedy Algorithm." *Mathematical Programming*, 1971.
- Gallager, R. G. "Variations on a Theme by Huffman." *IEEE Trans. Information Theory*, 1978.
- Papadimitriou, C. H. & Steiglitz, K. *Combinatorial Optimization: Algorithms and Complexity*. Ch. 12-13.
- Oxley, J. *Matroid Theory*. Oxford University Press, 2011.
- Cormen et al. *Introduction to Algorithms* (CLRS), Ch. 16 — Greedy Algorithms.
