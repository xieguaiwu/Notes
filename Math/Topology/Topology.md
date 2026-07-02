---
title: Topology
tags:
  - Math
  - Topology
  - 定义性
  - 基本原理
created: 2026-07-03
---

# Topology

> [!abstract] 概述
> **拓扑学 (Topology)** 是研究空间在连续变形下不变性质的数学分支。**点集拓扑 (Point-Set Topology)** 为其基础层，将"开集"作为原始概念，公理化地定义连续性、紧致性、连通性等核心结构，将分析学中的 $\varepsilon$-$\delta$ 语言推广为纯粹的集合论语言。

## 1 拓扑空间的定义

> [!note] 拓扑空间 (Topological Space)
> 设 $X$ 为一集合，$\mathcal{T} \subseteq \mathcal{P}(X)$ 是 $X$ 的子集族。称 $(X, \mathcal{T})$ 为一个**拓扑空间**，$\mathcal{T}$ 中的元素称为**开集 (Open Set)**，当满足以下三条公理：
>
> 1. **空集与全集**：$\emptyset \in \mathcal{T}$ 且 $X \in \mathcal{T}$
> 2. **有限交封闭**：若 $U_1, U_2, \dots, U_n \in \mathcal{T}$，则 $\bigcap_{i=1}^n U_i \in \mathcal{T}$
> 3. **任意并封闭**：若 $\{U_\alpha\}_{\alpha \in I} \subseteq \mathcal{T}$，则 $\bigcup_{\alpha \in I} U_\alpha \in \mathcal{T}$
>
> 直观：开集是"每个点都有呼吸空间"的集合——任一点都含在一个完全落在该集合内的"邻域"中。

```mermaid
flowchart TB
    TopSpace["拓扑空间 (X, T)"
    TopSpace --> Open["开集 (Open Sets)<br/>公理: $\emptyset$,X; 有限交; 任意并"]
    TopSpace --> Closed["闭集 (Closed Sets)<br/>开集的补集"]
    TopSpace --> Nbh["邻域 (Neighborhood)<br/>包含某开集的集合"]
    TopSpace --> Closure["闭包 (Closure)<br/>包含A的最小闭集"]
    TopSpace --> Interior["内部 (Interior)<br/>包含于A的最大开集"]
    TopSpace --> Boundary["边界 (Boundary)<br/>闭包 $\cap$ 补集的闭包"]
    Open --> Continuity["连续性<br/>开集原像是开集"]
    Open --> Compactness["紧致性<br/>开覆盖有有限子覆盖"]
    Open --> Connectedness["连通性<br/>无既开又闭的非平凡子集"]
```

> [!tip] 三种等价定义
> 拓扑空间的定义有三套等价语言：
> - **开集公理**（如上）——最常用
> - **闭集公理**：$\emptyset, X$ 闭；有限并封闭；任意交封闭
> - **邻域公理**：每个点 $x$ 指定一个邻域族 $\mathcal{N}(x)$，满足滤子性质
> - **闭包算子 (Kuratowski 公理)**：算子 $\operatorname{cl}: \mathcal{P}(X) \to \mathcal{P}(X)$ 满足四条公理

## 2 基本概念

### 2.1 闭集、闭包、内部、边界

> [!definition] 闭集与相关算子
> - **闭集 (Closed Set)**：$F \subseteq X$ 是闭集 $\iff$ $X \setminus F$ 是开集
> - **闭包 (Closure)**：$\operatorname{cl}(A) = \bigcap \{F \supseteq A \mid F \text{ 是闭集}\}$ ——包含 $A$ 的最小闭集
> - **内部 (Interior)**：$\operatorname{int}(A) = \bigcup \{U \subseteq A \mid U \text{ 是开集}\}$ ——包含于 $A$ 的最大开集
> - **边界 (Boundary)**：$\partial A = \operatorname{cl}(A) \setminus \operatorname{int}(A) = \operatorname{cl}(A) \cap \operatorname{cl}(X \setminus A)$

> [!example] 在 $\mathbb{R}$ 标准拓扑中
> 取 $A = (0, 1]$。则：
> - $\operatorname{int}(A) = (0, 1)$
> - $\operatorname{cl}(A) = [0, 1]$
> - $\partial A = \{0, 1\}$
> - $A$ 既不是开集也不是闭集

### 2.2 极限点与稠密性

| 概念 | 定义 |
|:---|:---|
| **极限点 (Limit Point)** | $x \in X$ 是 $A$ 的极限点 $\iff$ $x$ 的每个邻域与 $A$ 的交集中包含不同于 $x$ 的点 |
| **聚点 (Accumulation Point)** | 同极限点 |
| **孤立点 (Isolated Point)** | $x \in A$ 但不是 $A$ 的极限点 |
| **稠密 (Dense)** | $A \subseteq X$ 在 $X$ 中稠密 $\iff$ $\operatorname{cl}(A) = X$ |
| **可分 (Separable)** | $X$ 含有一个可数稠密子集 |

> [!example] $\mathbb{Q}$ 在 $\mathbb{R}$ 中稠密
> $\operatorname{cl}(\mathbb{Q}) = \mathbb{R}$，即任意实数都可以用有理数逼近。这等价于实数的完备性——参见 [[Mathematical_Analysis/Density and Completeness|实数的稠密性与完备性]]。

## 3 连续性与同胚

> [!definition] 连续映射
> 设 $(X, \mathcal{T}_X)$ 和 $(Y, \mathcal{T}_Y)$ 为拓扑空间。映射 $f: X \to Y$ 是**连续的**，当且仅当对任意 $V \in \mathcal{T}_Y$，有 $f^{-1}(V) \in \mathcal{T}_X$。
>
> 即：**开集的原像是开集**。

> [!tip] 与分析学连续性的一致性
> 在度量空间中，此定义等价于经典的 $\varepsilon$-$\delta$ 定义（见 [[Mathematical_Analysis/continuity|连续性的分析学定义]]）：
> $$
> \forall \varepsilon > 0,\ \exists \delta > 0,\ |x - a| < \delta \implies |f(x) - f(a)| < \varepsilon
> $$
> 也等价于：$x_n \to x \implies f(x_n) \to f(x)$（序列连续，在 [[Mathematical_Analysis/limit|极限]]定义基础上成立）。

> [!definition] 同胚 (Homeomorphism)
> 映射 $f: X \to Y$ 是一个**同胚**，当：
> 1. $f$ 是双射
> 2. $f$ 连续
> 3. $f^{-1}$ 连续
>
> 同胚是拓扑范畴 $\mathbf{Top}$ 中的同构。两个同胚的空间在拓扑学意义上"不可区分"。

> [!example] 经典同胚例子
> - 开区间 $(0, 1) \cong \mathbb{R}$（通过 $f(x) = \tan(\pi x - \pi/2)$）
> - 单位圆 $S^1$ 去掉一点 $\cong \mathbb{R}$
> - 咖啡杯与甜甜圈（环面）同胚——这是拓扑学的经典宣传图

> [!warning] 同胚不保距离
> 同胚保拓扑结构（开集、闭集、紧致、连通），但**不保距离、角度、面积**。保距离的同构是等距映射，属于度量几何的范畴。

## 4 紧致性

> [!definition] 紧致 (Compact)
> 拓扑空间 $X$ 是**紧致的**，当且仅当其任意开覆盖 $\{U_\alpha\}_{\alpha \in I}$（即 $\bigcup_\alpha U_\alpha = X$）都有**有限子覆盖**。
>
> 即：从任意多开集中，总能选出有限个覆盖整个空间。

> [!theorem] Heine–Borel 定理
> 在 $\mathbb{R}^n$ 的标准拓扑中：$A \subseteq \mathbb{R}^n$ 是紧致的 $\iff$ $A$ 是有界闭集。
>
> 这是分析学中 Bolzano–Weierstrass 定理的拓扑本质：有界闭区间上连续函数必一致连续、必有最大值。

**紧致性的核心性质**：

| 性质 | 说明 |
|:---|:---|
| **紧致集的闭子集紧致** | 紧致空间的每个闭子空间是紧致的 |
| **连续像紧致** | 若 $X$ 紧致且 $f$ 连续，则 $f(X)$ 紧致 |
| **紧致 Hausdorff 空间中紧致子集闭** | 在 Hausdorff 空间中，紧致子集必定是闭集 |
| **Tychonoff 定理** | 任意一族紧致空间的积空间是紧致的（等价于选择公理） |
| **紧致 Hausdorff 空间正规** | 紧致 + Hausdorff $\implies$ T4（见 §6 分离公理） |

> [!example] 非紧致空间的例子
> - $\mathbb{R}$ 本身：开覆盖 $\{(-n, n)\}_{n \in \mathbb{N}}$ 无有限子覆盖
> - $(0, 1]$：开覆盖 $\{(1/n, 1]\}_{n \in \mathbb{N}}$ 无有限子覆盖（$0$ 不在空间中但"在边缘"）
> - 无限离散空间：每个单点集构成开覆盖，若无限则无有限子覆盖

### 4.1 紧致性的变体

| 概念 | 定义 |
|:---|:---|
| **列紧 (Sequentially Compact)** | 每个序列有收敛子序列 |
| **可数紧 (Countably Compact)** | 每个可数开覆盖有有限子覆盖 |
| **极限点紧 (Limit Point Compact)** | 每个无限子集有极限点 |
| **局部紧 (Locally Compact)** | 每点有一个紧致邻域 |
| **仿紧 (Paracompact)** | 每个开覆盖有局部有限的开加细（流形理论的关键概念） |

> [!note] 在度量空间中
> 紧致 $\iff$ 列紧 $\iff$ 完备且完全有界。这三种紧致性在此情景下等价，但在一般拓扑空间中彼此独立。

## 5 连通性

> [!definition] 连通 (Connected)
> 拓扑空间 $X$ 是**连通的**，当且仅当它不能表示为两个非空不相交开集的并。等价地：$X$ 的既开又闭的子集只有 $\emptyset$ 和 $X$。

> [!definition] 道路连通 (Path-Connected)
> $X$ 是**道路连通的**，当对任意 $x, y \in X$，存在连续映射 $\gamma: [0,1] \to X$ 使得 $\gamma(0) = x,\ \gamma(1) = y$。

> [!warning] 连通与道路连通的关系
> 道路连通 $\implies$ 连通，但**逆命题不成立**。
> 标准反例：**拓扑学家的正弦曲线 (Topologist's Sine Curve)**
> $$
> T = \{(x, \sin(1/x)) \mid x \in (0, 1]\} \cup (\{0\} \times [-1, 1])
> $$
> $T$ 是连通的，但不是道路连通的——原点 $\{0\} \times [-1, 1]$ 上的点无法通过连续道路连接到右侧曲线。

**连通性的关键性质**：

- 连续像保连通：$f$ 连续且 $X$ 连通 $\implies$ $f(X)$ 连通
- 介值定理的拓扑本质：连通空间上的连续实值函数满足介值性质
- **连通分支 (Connected Component)**：极大连通子集，构成空间的一个划分
- **完全不连通 (Totally Disconnected)**：连通分支均为单点（如 $\mathbb{Q}$、Cantor 集）

## 6 分离公理

分离公理刻画了拓扑空间"有多 Hausdorff"——即点之间能用开集分离到什么程度。

| 公理 | 名称 | 条件 |
|:---|:---|:---|
| **T0** | Kolmogorov | 任意两点中至少有一点存在开邻域不含另一点 |
| **T1** | Fréchet | 每个单点集是闭集（等价：任意两点，每点都有不含另一点的邻域） |
| **T2** | Hausdorff | 任意两点存在互不相交的开邻域 |
| **T3** | 正则 (Regular) | T1 + 任意闭集与不在其中的点可被不相交开集分离 |
| **T3½** | Tychonoff | T1 + 闭集与点可被连续函数分离（完全正则） |
| **T4** | 正规 (Normal) | T1 + 任意两个不相交闭集可被不相交开集分离 |
| **T5** | 完全正规 | T1 + 任意两个分离的集合可被不相交开集分离 |

> [!tip] 记忆：分离强度谱系
> $$
> \text{T4} \implies \text{T3½} \implies \text{T3} \implies \text{T2} \implies \text{T1} \implies \text{T0}
> $$
> 在度量空间中：度量空间 $\implies$ T6（完全正规）；紧致 Hausdorff $\implies$ T4。

> [!example] 各种分离公理的典型例子
> - **Sierpinski 空间**：$X = \{0, 1\}$，$\mathcal{T} = \{\emptyset, \{1\}, X\}$ —— T0 但不 T1（$\{0\}$ 不是闭集）
> - **余有限拓扑**（见 §9 例 3）：T1 但不 T2
> - **$\mathbb{R}$ 标准拓扑**：T4（事实上 T6）
> - **Zariski 拓扑**（代数几何）：代数簇上的 Zariski 拓扑通常是 T1 但不 T2

## 7 积拓扑与商拓扑

### 7.1 积拓扑

> [!definition] 积拓扑 (Product Topology)
> 设 $\{X_\alpha\}_{\alpha \in I}$ 为一族拓扑空间。**积拓扑**是在 [[Set_Theory/Cartesian product|笛卡尔积]] $\prod_{\alpha} X_\alpha$ 上使所有投影映射 $\pi_\beta: \prod_\alpha X_\alpha \to X_\beta$ 连续的最粗拓扑。
>
> 其标准基为：$\prod_\alpha U_\alpha$，其中仅在有限个坐标上 $U_\alpha \neq X_\alpha$。

> [!warning] 箱拓扑 vs 积拓扑
> **箱拓扑 (Box Topology)** 允许任意坐标上 $U_\alpha \neq X_\alpha$（不限于有限），比积拓扑更细。在无限乘积中，积拓扑更"自然"——它使 Tychonoff 定理成立，且使连续映射 $f: Y \to \prod X_\alpha$ 等价于每个分量连续。

> [!theorem] Tychonoff 定理
> 任意一族紧致空间的积（赋积拓扑）是紧致的。此定理等价于**选择公理 (Axiom of Choice)**。

### 7.2 商拓扑

> [!definition] 商拓扑 (Quotient Topology)
> 设 $X$ 为拓扑空间，$\sim$ 为 $X$ 上的等价关系，$\pi: X \to X/{\sim}$ 为自然投影。商拓扑是使 $\pi$ 连续的最细拓扑：
> $$
> V \subseteq X/{\sim} \text{ 是开集} \iff \pi^{-1}(V) \subseteq X \text{ 是开集}
> $$

> [!example] 商拓扑构造的经典空间
> - **环面 $T^2$**：$[0,1]^2$ 将相对边粘合（$[0,1]^2 / (0,y) \sim (1,y),\ (x,0) \sim (x,1)$）
> - **射影平面 $\mathbb{RP}^2$**：$S^2$ 将对径点等同
> - **Klein 瓶**：$[0,1]^2$ 将一对边反向粘合
> - **Möbius 带**：$[0,1]^2$ 将一对边反向粘合，另一对边保持
> - 在 [[Category_Theory|范畴论]] 中，商拓扑是遗忘函子 $U: \mathbf{Top} \to \mathbf{Set}$ 的余等值子

## 8 度量化定理

> [!definition] 可度量化 (Metrizable)
> 拓扑空间 $(X, \mathcal{T})$ 是**可度量化的**，当存在 $X$ 上的度量 $d$，使得由度量诱导的拓扑恰好是 $\mathcal{T}$。

> [!theorem] Urysohn 度量化定理
> 每个**正则 (T3)** 且**第二可数**的拓扑空间是可度量化的。（第二可数：拓扑有可数基）
>
> 这是点集拓扑的巅峰成果之一：纯粹拓扑条件 $\implies$ 度量的存在性。

| 度量化定理 | 条件 | 结论 |
|:---|:---|:---|
| **Urysohn** | 正则 + 第二可数 | 可度量化为 $\mathbb{R}^\omega$ 的子空间 |
| **Nagata–Smirnov** | 正则 + 有 $\sigma$-局部有限基 | 可度量化（充要条件） |
| **Bing–Nagata–Smirnov** | 正则 + 有 $\sigma$-离散基 | 可度量化（充要条件） |

> [!note] Urysohn 引理
> 若 $X$ 是 T4 空间，$A, B$ 是不相交闭集，则存在连续函数 $f: X \to [0,1]$ 使得 $f(A) = \{0\}$ 且 $f(B) = \{1\}$。此引理是度量化定理的关键工具，也是分析学中连续函数延拓的拓扑基础。

## 9 例子汇总

> [!example] 例 1: 实数标准拓扑 (Standard Topology)
> $\mathbb{R}$ 上由开区间 $(a, b)$ 生成的拓扑。这是分析学中一切连续性的基础。$\mathbb{R}^n$ 上由开球生成。

> [!example] 例 2: 离散拓扑 (Discrete Topology)
> $\mathcal{T} = \mathcal{P}(X)$ ——所有子集都是开集。这是**最细**的拓扑。每个函数从离散空间出发都连续。离散空间上的紧致 $\iff$ 有限。

> [!example] 例 3: 余有限拓扑 (Cofinite Topology)
> 开集 = 补集为有限集的集合 + $\emptyset$。$X$ 无限时：T1 但不 T2；紧致但不 Hausdorff。是代数几何中 Zariski 拓扑的雏形。

> [!example] 例 4: Sierpinski 空间
> $X = \{0, 1\}$，$\mathcal{T} = \{\emptyset, \{1\}, \{0, 1\}\}$。最小的非平凡非离散拓扑。T0 但不 T1。在 Domain 理论和理论计算机科学中有核心地位。

> [!example] 例 5: 余可数拓扑 (Cocountable Topology)
> 开集 = 补集为可数集的集合 + $\emptyset$。比余有限拓扑更细。不可数集上此拓扑不是第一可数的。

> [!example] 例 6: 度量拓扑 (Metric Topology)
> 由度量 $d$ 的开球 $B(x, r) = \{y \mid d(x, y) < r\}$ 生成的拓扑。所有度量空间都是 T6（完全正规）且第一可数。

> [!example] 例 7: 序拓扑 (Order Topology)
> 在全序集 $(X, <)$ 上，由开区间 $(a, b) = \{x \mid a < x < b\}$ 生成的拓扑。$\mathbb{R}$ 的标准拓扑是其特例。序拓扑中：紧致 $\iff$ 完备格（每个子集有上确界和下确界）。

> [!example] 例 8: 子空间拓扑 (Subspace Topology)
> $Y \subseteq X$，$\mathcal{T}_Y = \{U \cap Y \mid U \in \mathcal{T}_X\}$。$[0, 1]$ 作为 $\mathbb{R}$ 的子空间——它是紧致的（Heine–Borel）且连通的。

> [!example] 例 9: 平庸拓扑 (Trivial / Indiscrete Topology)
> $\mathcal{T} = \{\emptyset, X\}$ ——**最粗**的拓扑。任意函数到平庸空间都连续。平庸空间总是紧致和连通，但若 $|X| > 1$ 则不是 T0。

> [!example] 例 10: 特殊点拓扑 (Particular Point Topology)
> 固定 $p \in X$。开集 = 包含 $p$ 的集合 + $\emptyset$。T0 但不 T1。$p$ 是所有非空开集的"万能点"。

> [!example] 例 11: 排除点拓扑 (Excluded Point Topology)
> 固定 $p \in X$。开集 = 不包含 $p$ 的集合 + $X$。与特殊点拓扑"对偶"。

> [!example] 例 12: 下限拓扑 / Sorgenfrey 直线
> $\mathbb{R}$ 上由 $[a, b)$ 生成的拓扑。比标准拓扑更细。第一可数、可分、T4，但**不是**第二可数，且其平方不是 T4（Sorgenfrey 平面的著名反例）。

## 10 与其他领域的关系

- **分析学**：[[Mathematical_Analysis/continuity|连续性]]、[[Mathematical_Analysis/limit|极限]]、紧致性在拓扑框架中得到统一
- **范畴论**：$\mathbf{Top}$ 范畴，拓扑空间与连续映射；同胚是 $\mathbf{Top}$ 中的同构 —— 见 [[Category_Theory|Category Theory]]
- **代数拓扑**：基本群 $\pi_1$（[[Functor|函子]] $\mathbf{Top}_* \to \mathbf{Grp}$）、同调群
- **集合论**：拓扑空间的基础载体是集合，开集族是 [[Math/Set_Theory/Cartesian product|笛卡尔积]] 的子族
- **泛函分析**：Banach 空间、Hilbert 空间的弱拓扑与弱*拓扑（无限维分析的核心）
- **代数几何**：Zariski 拓扑（概形论的基础拓扑）
- **数理逻辑**：Stone 空间（Bool 代数的对偶范畴，完全不连通紧致 Hausdorff 空间）

> [!quote] 推荐教材
> - **入门级**：*Topology*（James R. Munkres）——点集拓扑的标准教材，大部分数学系采用
> - **进阶**：*General Topology*（John L. Kelley）——经典但写作风格较老；*Counterexamples in Topology*（Steen & Seebach）——丰富的反例库
> - **范畴论视角**：*Topology: A Categorical Approach*（Tai-Danae Bradley, Tyler Bryson, John Terilla）
> - **分析学背景**：*Real Analysis*（Royden）中有紧致性与度量化在分析学中的应用
