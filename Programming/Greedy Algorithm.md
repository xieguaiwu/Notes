---
tags:
  - Algorithm
  - ComputerScience
  - 定义性
  - 基本原理
title: "Greedy Algorithm"
created: 2026-06-26
modified: 2026-06-26
---

# Greedy Algorithm

> [!abstract] 贪心算法
> 贪心算法（Greedy Algorithm）在每一步选择**当前最优**的决策，期望通过局部最优累积得到全局最优。它不回溯、不枚举，核心在于**贪心选择性质**和**最优子结构**。

## 1. 基本概念

### 1.1 贪心 vs 动态规划

| 维度 | 贪心算法 | 动态规划 |
|------|----------|----------|
| 决策方式 | 每一步做**不可撤销**的局部最优选择 | 枚举所有可能，保留子问题最优解 |
| 依赖关系 | 当前选择只依赖之前的选择 | 依赖子问题之间的重叠 |
| 正确性条件 | 贪心选择性质 + 最优子结构 | 最优子结构 |
| 实现复杂度 | 通常简单高效 | 需要状态定义与转移方程 |
| 适用场景 | 问题结构足够强，局部最优即全局最优 | 子问题重叠且有后效性时 |

### 1.2 贪心算法的两大关键性质

> [!note] 贪心选择性质（Greedy Choice Property）
> 全局最优解可以通过一系列**局部最优**（贪心）选择来构造，即每次选择当前看起来最优的选项，最终得到全局最优。

> [!note] 最优子结构（Optimal Substructure）
> 问题的最优解包含其**子问题**的最优解。如果一个选择将原问题分解为子问题，那么该选择后的子问题也必须能以贪心策略求解。

### 1.3 贪心算法的通用框架

```
1. 将原问题分解为一系列步骤
2. 每步根据某种贪心策略选择当前最优选项
3. 更新问题的状态
4. 重复直到得到完整解
5. （可选）证明该贪心策略的正确性
```

## 2. 经典问题

### 2.1 活动选择（Activity Selection）

> [!tip] 问题
> 给定 $n$ 个活动，每个活动有开始时间 $s_i$ 和结束时间 $f_i$。同一时间只能参加一个活动，求最多能参加多少个活动。

**贪心策略**：每次选择**结束时间最早**且与已选活动不冲突的活动。

```python
def activity_selection(activities):
    # activities: [(s1, f1), (s2, f2), ...]
    activities.sort(key=lambda x: x[1])  # 按结束时间排序
    selected = [activities[0]]
    last_end = activities[0][1]
    
    for s, f in activities[1:]:
        if s >= last_end:
            selected.append((s, f))
            last_end = f
    
    return selected
```

**正确性证明思路**：设 $OPT$ 为某个最优解中最早结束的活动为 $a_k$，若 $a_k$ 不是按贪心策略选出的最早结束的活动 $a_1$，则可替换 $a_k$ 为 $a_1$ 而不影响后续选择余地，因此贪心解不劣于最优解。

### 2.2 分数背包（Fractional Knapsack）

> [!tip] 问题
> 给定容量 $W$ 的背包和 $n$ 个物品，每个物品有重量 $w_i$ 和价值 $v_i$，物品可**分割**（取任意比例），求最大总价值。

**贪心策略**：每次选择**单位重量价值最高**的物品，尽可能多取。

```python
def fractional_knapsack(items, W):
    # items: [(weight, value), ...]
    items.sort(key=lambda x: x[1] / x[0], reverse=True)
    total_value = 0
    
    for w, v in items:
        if W >= w:
            total_value += v
            W -= w
        else:
            total_value += v * (W / w)
            break
    
    return total_value
```

> [!warning] 分数背包 vs 0-1 背包
> **分数背包**可用贪心（物品可分）；**0-1 背包**（物品不可分）只能用动态规划。这是初学贪心时最容易混淆的边界。

### 2.3 哈夫曼编码（Huffman Coding）

贪心策略：每次从字符频率中选出两个**频率最低**的节点合并，构建最优前缀码树。

```python
import heapq

def huffman_encode(freq):
    # freq: {char: frequency}
    heap = [[weight, [char, ""]] for char, weight in freq.items()]
    heapq.heapify(heap)
    
    while len(heap) > 1:
        lo = heapq.heappop(heap)
        hi = heapq.heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    
    return sorted(heap[0][1:], key=lambda p: p[0])
```

时间复杂度：$O(n \log n)$，其中 $n$ 为字符集大小。

### 2.4 最小生成树（MST）

| 算法 | 贪心策略 | 时间复杂度 |
|------|----------|-----------|
| **Kruskal** | 每次选权重最小且不形成环的边 | $O(E \log V)$ |
| **Prim** | 每次选与当前树相连的最小权重边 | $O(E \log V)$（二叉堆） |

> [!note] 两种算法的区别
> - **Kruskal**：基于**边**，全局排序后并查集维护连通性
> - **Prim**：基于**点**，类似 Dijkstra，从起点逐步扩张

### 2.5 Dijkstra 最短路径

**贪心策略**：维护未确定最短路径的节点集，每次选距离源点**最近**的节点加入已确定集，并松弛其邻接边。

```python
import heapq

def dijkstra(graph, start):
    dist = {v: float('inf') for v in graph}
    dist[start] = 0
    pq = [(0, start)]
    
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    
    return dist
```

> [!warning] Dijkstra 的限制
> - 只能处理**非负权边**（负权边需用 Bellman-Ford）
> - 本质是贪心算法，不是动态规划

### 2.6 区间调度变体

| 问题 | 贪心策略 | 说明 |
|------|----------|------|
| 最大不重叠区间数 | 按结束时间最早选 | 活动选择问题 |
| 最少覆盖点 | 按区间结束位置选点 | 区间选点问题 |
| 最少会议室 | 按开始时间排序，模拟 | 等同于同时重叠区间的最大数量 |
| 区间分组（最小分组） | 按开始时间排序，用小根堆维护结束时间 | 每个组内区间不重叠 |

### 2.7 硬币找零（特定币制）

> [!tip] 问题
> 给定面额 $c_1 > c_2 > \dots > c_k$ 的无限供应的硬币，用最少的硬币数凑出金额 $N$。

**贪心策略**：每次尽可能使用最大面额硬币。

```python
def coin_change_greedy(coins, amount):
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if amount == 0:
            break
        cnt = amount // coin
        count += cnt
        amount -= cnt * coin
    return count if amount == 0 else -1
```

> [!warning] 贪心仅对**规范币制**有效
> 对于人民币/美元等标准币制（$1, 5, 10, 25$ 等），贪心正确；但对于 $1, 3, 4$ 找零 $6$，贪心给出 $4+1+1=3$ 枚，而最优为 $3+3=2$ 枚。非规范币制需用**动态规划**。

## 3. 正确性证明方法

### 3.1 交换论证（Exchange Argument）

证明贪心解可以通过一系列**交换操作**变为最优解而不劣化结果。适用于活动选择、MST 等。

```
1. 设 G 为贪心解，OPT 为某个最优解
2. 找到 G 与 OPT 的第一个差异位置
3. 将 OPT 中该位置的决策替换为 G 的贪心决策
4. 证明替换后 OPT 不会变差
5. 归纳得 G 与 OPT 等价
```

### 3.2 数学归纳法（Induction）

证明贪心策略在第 $k$ 步后产生的部分解必然**包含在某个全局最优解**中。

```
1. 基础：第 1 步的贪心选择包含在某个最优解中
2. 归纳：设前 k 步的贪心选择包含在某个最优解中
3. 递推：证明第 k+1 步的贪心选择也可被纳入该最优解
4. 结论：整个贪心解就是最优解
```

### 3.3 拟阵理论（Matroid Theory）

对于满足**拟阵结构**的问题，贪心算法天然正确。

> [!note] 拟阵的三个公理
> 1. **空集**是独立集
> 2. **遗传性**：独立集的子集也是独立集
> 3. **交换性**：若 $|A| < |B|$ 且 $A,B$ 均为独立集，则存在 $x \in B \setminus A$ 使 $A \cup \{x\}$ 仍独立

如果问题可以建模为拟阵上的**最大权独立集**问题，则贪心算法（每次选权值最大且保持独立性的元素）必然得到全局最优解。

> [!tip] 拟阵贪心的典型例子
> - **Kruskal 算法**（图拟阵/循环拟阵）：边集独立当且仅当不形成环
> - **任务调度问题**（拟阵的推广——贪婪拟阵）

## 4. 常见误区

| 误区 | 说明 | 反例 |
|------|------|------|
| **贪心=排序** | 排序只是实现手段，决定排序规则（比较器）才是贪心策略设计的关键 | 不合适的排序规则导致错误 |
| **贪心正确无需证明** | 贪心的直观感常骗人，必须形式化证明 | 活动选择按开始时间排序选就错 |
| **"当前最优"模糊定义** | 不同"最优"标准导致完全不同结果 | 区间调度按长度 vs 按结束时间 |
| **忽略了后效性** | 贪心假设选择不影响后续决策空间 | 0-1 背包不可分割导致贪心失败 |
| **只需一个贪心策略** | 同一问题可能有多种贪心策略，仅部分正确 | 加权区间调度（需 DP） |

## 5. 应用速查

| 问题 | 贪心策略 | 正确性 |
|------|----------|--------|
| 活动选择 | 最早结束时间 | ✅ 交换论证 |
| 分数背包 | 单位重量最大价值 | ✅ |
| 哈夫曼编码 | 最小频率合并 | ✅ 贪心选择性质 |
| 最小生成树 | Kruskal/Prim | ✅ 拟阵/切割性质 |
| 单源最短路径（非负） | Dijkstra | ✅ 松弛性质 |
| 任务调度（最小化延迟） | 按截止时间最早（EDD） | ✅ |
| 任务调度（最小化完成时间和） | 按处理时间最短（SPT） | ✅ |
| 区间着色 | 按开始时间排序 | ✅ |
| 硬币找零（规范币制） | 最大面额优先 | ⚠️ 仅对规范币制 |
| 0-1 背包 | 单位价值最大 | ❌ 需 DP |
| TSP（旅行商） | 最近邻 | ❌ 无近似保证 |
| 加权区间调度 | 按结束时间 | ❌ 需 DP |

## 6. 复杂度总结

| 操作 | 典型实现 | 时间复杂度 |
|------|----------|-----------|
| 活动选择（排序+扫描） | 快速排序 | $O(n \log n)$ |
| 分数背包（排序+扫描） | 快速排序 | $O(n \log n)$ |
| 哈夫曼编码 | 最小堆 | $O(n \log n)$ |
| Kruskal MST | 排序+并查集 | $O(E \log E)$ |
| Prim MST | 二叉堆 | $O(E \log V)$ |
| Dijkstra | 二叉堆 | $O((V+E) \log V)$ |

---

## 相关笔记

- [[Algorithm]] - C++ STL 算法
- [[Graph Theory and Search]] - 图论基础与搜索算法
- [[Math]] - 数学基础与离散结构

## 参考文献

- Cormen et al. *Introduction to Algorithms* (CLRS), Ch. 16 — Greedy Algorithms
- Kleinberg & Tardos. *Algorithm Design*, Ch. 4 — Greedy Algorithms
- 拟阵理论: Oxley. *Matroid Theory*
