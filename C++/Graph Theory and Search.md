---
tags:
  - C++
  - GraphTheory
  - Math
  - OOP
title: Graph Theory and Search
created: 2026-04-27
modified: 2026-04-27
---

# Graph Theory and Search

> [!abstract] 图的存储与遍历
> 图论中常见的存储结构（邻接矩阵、邻接表、链式前向星）和搜索算法（DFS、BFS）的 C++ 实现。[[Graph - Definations]]

## 1. 基本概念

> [!note] 头结点 vs 头指针 vs 首元结点
> - **头结点**：为了脱离整个数据链表，能轻易找到首元结点、操作首元结点而设置的结点
> - **头指针**：指向头结点的指针，储存头结点的地址
> - **首元结点**：包含有数据的第一个结点

## 2. 邻接矩阵 (Adjacency Matrix)

```cpp
bool unweighted_graph[mw][ml];  // 只需要表示[x][y]上是否有边
int weighted_graph[mw][ml];     // weighted_graph[x][y]=c -> 权重为c
```

| 操作 | 复杂度 |
|------|--------|
| 空间 | $O(n^2)$ |
| 查询边是否存在 | $O(1)$ |
| 遍历邻居 | $O(n)$ |

> [!tip] 适用场景
> 邻接矩阵适合稠密图（边数接近 $n^2$），查询边是否存在的操作频繁时使用。

## 3. 邻接表 (Adjacency List)

> [!note] 更常用的存储方式

```cpp
struct Edge2 {
    int to, weight;
};

vector<vector<Edge2>> adj(10);
```

| 操作 | 复杂度 |
|------|--------|
| 空间 | $O(n + m)$ |
| 查询边是否存在 | $O(\deg(u))$ |
| 遍历邻居 | $O(\deg(u))$ |

> [!tip] 邻接表内存访问局部性好，适合稀疏图。

## 4. 链式前向星 (Linked Forward Star)

> [!important] 最优的图存储方式
> 静态数组实现，空间连续，缓存友好，竞赛中最常用。

```cpp
const int MAXN = 100010;  // 最大节点数
const int MAXM = 200010;  // 最大边数

struct Edge3 {
    int to, weight3, next;
};

Edge3 edges[MAXM];       // 双向连接
int head[MAXN];          // head[u]：节点u的第一条边在edges中的索引
int total;

void init() {
    memset(head, -1, sizeof(head));  // 使用memset加速
    total = 0;
}

// 添加一条有向边 u->v，权重为w
void addEdge3(int u, int v, int w) {
    edges[total] = {v, w, head[u]};
    head[u] = total;  // 更新头指针
    ++total;
}

// 添加无向边（相当于添加两条有向边）
void addUndirectedEdge(int u, int v, int w) {
    addEdge3(u, v, w);
    addEdge3(v, u, w);
}
```

### 遍历

```cpp
// 遍历节点u的所有出边
for (int i = head[0]; i != -1; i = edges[i].next) {
    int v = edges[i].to;
    int w = edges[i].weight3;
    // 处理边(u, v, w)
}
```

## 5. 存储方式对比

| 特性 | 邻接矩阵 | 邻接表 | 链式前向星 |
|------|----------|--------|-----------|
| 空间 | $O(n^2)$ | $O(n+m)$ | $O(n+m)$ |
| 查边 | $O(1)$ | $O(\deg(u))$ | $O(\deg(u))$ |
| 遍历邻居 | $O(n)$ | $O(\deg(u))$ | $O(\deg(u))$ |
| 缓存友好 | ✅ | ❌ | ✅ |
| 适用图 | 稠密图 | 稀疏图 | 稀疏图 |

## 6. 搜索算法

### 6.1 DFS（深度优先搜索）

```cpp
void dfs(int u, vector<bool>& vis) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, vis);
    }
}
```

### 6.2 BFS（广度优先搜索）

```cpp
void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int l = q.front();
        q.pop();
        for (int v : adj[l]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
```

| 特性 | DFS | BFS |
|------|-----|-----|
| 数据结构 | 栈（递归） | 队列 |
| 最短路径 | ❌ 无权图不保证 | ✅ 无权图保证 |
| 空间 | $O(h)$ 递归深度 | $O(n)$ 队列 |
| 适用场景 | 连通性、拓扑排序 | 最短路径、层序遍历 |

---

## 相关笔记

- [[Template and XOR]] - 模板与位运算
- [[stdexcept]] - C++ 标准异常类