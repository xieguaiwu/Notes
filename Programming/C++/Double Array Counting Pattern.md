---
tags:
  - C++
  - 方法性
  - Algorithm
title: Double Array Counting Pattern
created: 2026-07-26
modified: 2026-07-26
---

# Double Array Counting Pattern

> [!abstract] `a[b[x]]` — 用数组值做下标
> 遍历序列时，用元素的值作为计数数组的下标（`cnt[arr[i]]++`），将分支判断转化为直接索引。常用于 CP 中替代 `if-else` 链，同时消除内层循环的重复构造开销。

## 1. 模式本质

```cpp
// 常规写法（分支判断）
if (arr[i] == 1) cnt1++;
if (arr[i] == 2) cnt2++;
if (arr[i] == 3) cnt3++;

// a[b[x]] 双数组索引
cnt[arr[i]]++;   // arr[i] 的值 (1/2/3) 直接作为 cnt 的下标
```

`a[b[x]]` 中：
- `x` = 遍历索引
- `b` = 原始数据数组（值域有限时适用）
- `a` = 计数数组（下标对应 `b` 的值域）

## 2. 实战案例 — Balanced Breed Block

### 题面
给定长度为 $N$ 的数组，元素取值 $\{1,2,3\}$（三种牛）。求**最长连续子数组**，满足：
1. 三种牛都出现至少一次
2. 三种牛的出现次数极差 $\leq 1$

### 原始代码（O(N³)，含 bug）

```cpp
bool judge(const vector<int> &v) {
    bool types[3];  // 未初始化！
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 1) types[0] = true;
        if (v[i] == 2) types[1] = true;
        if (v[i] == 3) types[2] = true;
    }
    // BUG: 应检查 types[], 却写了 v[0]/v[1]/v[2]
    if (v[0] == true && v[1] == true && v[2] == true) return true;
    return false;
}

int main() {
    // ... 输入 ...
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 1; j < N; ++j) {       // BUG: j 应从 i+1 开始
            vector<int> sublist(begin+L, begin+R);
            if (list[R] - list[L] <= 1       // BUG: 比较的是值而非计数
                && judge(sublist))
                current = max(R - L, current);
        }
    }
}
```



### `a[b[x]]` 优化版（O(N²)）

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; ++i) cin >> list[i];

    int ans = 0;
    for (int i = 0; i < N - 2; ++i) {
        int cnt[4] = {0};                  // cnt[1..3] 三 breed 计数
        for (int j = i; j < N; ++j) {
            cnt[list[j]]++;                // ★ a[b[x]]: 省掉 if-else
            if (cnt[1] && cnt[2] && cnt[3]) {
                int mx = max({cnt[1], cnt[2], cnt[3]});
                int mn = min({cnt[1], cnt[2], cnt[3]});
                if (mx - mn <= 1)
                    ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << "\n";
}
```

## 3. 优化幅度对比

| 维度 | 原版 | 优化版 |
|------|------|--------|
| 时间复杂度 | O(N³) | O(N²) |
| 空间复杂度 | O(N)（反复构造 sublist） | O(1)（固定 cnt[4]） |
| 分支判断 | 3 个 `if` + judge 内再遍历 | `cnt[list[j]]++` 一条 |
| 越界风险 | `v[0]` 在空 sublist 上 UB | 无（仅访问 cnt[1..3]） |
| judge 函数 | 独立函数，传参+遍历 | 内联，增量更新 |

核心节省来自：**不再为每对 `(i,j)` 构造 sublist 并重新遍历**，而是在 j 向右扩展时增量 `cnt[list[j]]++`，O(1) 维护计数状态。

## 4. 适用条件

`a[b[x]]` 模式要求：

- **值域小且已知**：可作为数组下标。本例值域 $\{1,2,3\}$，cnt[4] 足以容纳
- **离散整数**：C 数组下标必须为整数
- **频繁计数操作**：遍历中反复累加/查询，值得集中管理

> [!tip] 推广
> 值域较大时可改用 `unordered_map`（O(1) 均摊），或离散化后仍用数组。

## 5. 相关笔记

- [[Algorithm]] — C++ `<algorithm>` 与泛型编程
- [[Code Review — Balanced Breed Block Bugs]] — 原始代码的逐 bug 分析
- [[Template and XOR]] — 模板与位运算中的 CP 技巧
