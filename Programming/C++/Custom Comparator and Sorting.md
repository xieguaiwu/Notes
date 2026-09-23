---
title: Custom Comparator and Sorting
tags:
  - C++
  - Algorithm
  - STL
  - 方法性
created: 2026-09-23
modified: 2026-09-23
---

# Custom Comparator and Sorting

> [!abstract] 四种定制方式 + 严格弱序规则
> `std::sort` 默认按 `operator<` 升序排序，通过传入**自定义比较器**可实现任意排序逻辑。C++ 提供四种方式：Lambda、Functor、普通函数、重载 `operator<`。比较器必须满足**严格弱序（Strict Weak Ordering）**，否则触发未定义行为。

## 1. 四种定制方式

### 1.1 Lambda 表达式（首选）

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {5, 2, 8, 1, 9};

// 降序
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});

// 按绝对值升序
std::sort(v.begin(), v.end(), [](int a, int b) {
    return std::abs(a) < std::abs(b);
});
```

> [!tip] 捕获外部变量
> Lambda 可捕获外部状态，实现动态比较逻辑：
> ```cpp
> int threshold = 5;
> std::sort(v.begin(), v.end(), [threshold](int a, int b) {
>     // 阈值两侧的元素按不同规则排序
>     bool a_low = a < threshold;
>     bool b_low = b < threshold;
>     if (a_low != b_low) return a_low > b_low;  // 小值在前
>     return a < b;
> });
> ```

### 1.2 Functor（仿函数）

```cpp
struct CompareByLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

std::vector<std::string> words = {"apple", "hi", "banana"};
std::sort(words.begin(), words.end(), CompareByLength{});
```

> [!note] Functor 携带状态
> Functor 可存储成员变量，实现参数化比较：
> ```cpp
> struct CompareByField {
>     std::string field_name;
>     CompareByField(std::string name) : field_name(std::move(name)) {}
>     bool operator()(const Record& a, const Record& b) const {
>         return a.get(field_name) < b.get(field_name);
>     }
> };
> std::sort(records.begin(), records.end(), CompareByField("score"));
> ```

### 1.3 普通函数

```cpp
bool compareDescending(int a, int b) {
    return a > b;
}

std::sort(v.begin(), v.end(), compareDescending);
```

> [!warning] 函数指针陷阱
> 传递函数名时退化为函数指针，无法内联优化。性能敏感场景优先选 Lambda 或 Functor。

### 1.4 重载 `operator<`

```cpp
struct Student {
    std::string name;
    int score;
    
    bool operator<(const Student& o) const {
        return score > o.score;   // 按分数降序（反直觉但合法）
    }
};

std::vector<Student> students = {{"Alice", 95}, {"Bob", 87}};
std::sort(students.begin(), students.end());  // 无需传比较器
```

## 2. 多字段排序

```cpp
struct Student {
    std::string name;
    int score;
    int age;
};

// 先按分数降序，分数相同按年龄升序，年龄相同按姓名字典序升序
std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    if (a.score != b.score) return a.score > b.score;
    if (a.age != b.age) return a.age < b.age;
    return a.name < b.name;
});
```

## 3. 严格弱序规则

比较器 $\text{comp}(a, b)$ 必须满足以下三条，否则**未定义行为**：

| 规则 | 公式 | 含义 |
|:-----|:-----|:-----|
| **反自反性** | $\text{comp}(a, a) = \text{false}$ | 元素不能"小于"自身 |
| **非对称性** | $\text{comp}(a, b) = \text{true} \Rightarrow \text{comp}(b, a) = \text{false}$ | 若 $a$ 在 $b$ 前，则 $b$ 不能在 $a$ 前 |
| **传递性** | $\text{comp}(a, b) \land \text{comp}(b, c) \Rightarrow \text{comp}(a, c)$ | 顺序可传递 |

> [!warning] 典型错误：`<=` 代替 `<`
> ```cpp
> // ❌ 错误：a==b 时 comp(a,b)==true 且 comp(b,a)==true，违反非对称性
> std::sort(v.begin(), v.end(), [](int a, int b) { return a <= b; });
> 
> // ✅ 正确
> std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
> ```

> [!warning] 典型错误：仅按第二字段排序丢失第一字段信息
> ```cpp
> // ❌ 意图按分数降序，但分数相同时顺序不确定
> std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
>     return a.score > b.score;   // 分数相等时 comp(a,b)==false 且 comp(b,a)==false
> });                              // 这是合法的，但不稳定 —— 相等元素的相对顺序不确定
> 
> // ✅ 用 stable_sort 保持相等元素原顺序，或用多字段排序显式规定
> ```

## 4. 排序算法对比

| 算法 | 复杂度 | 稳定性 | 适用场景 |
|:-----|:-------|:-------|:---------|
| `std::sort` | $O(N \log N)$ | 不稳定 | 通用，性能首选 |
| `std::stable_sort` | $O(N \log^2 N)$ 或 $O(N \log N)$ | 稳定 | 需保持相等元素原顺序 |
| `std::partial_sort` | $O(N \log K)$ | 不稳定 | 只需前 $K$ 个有序元素 |
| `std::nth_element` | 平均 $O(N)$ | 不稳定 | 求第 $K$ 小/中位数 |
| `std::make_heap` + `std::sort_heap` | $O(N \log N)$ | 不稳定 | 堆排序，无需额外空间 |

```cpp
// partial_sort：前 3 个最小且有序
std::partial_sort(v.begin(), v.begin() + 3, v.end());

// nth_element：第 4 小的元素到位（两侧无序）
std::nth_element(v.begin(), v.begin() + 3, v.end());

// 默认最大堆转最小序列
std::sort_heap(v.begin(), v.end(), std::greater<>());
```

## 5. 对容器排序

```cpp
// deque / array / vector 均支持
std::deque<int> dq = {3, 1, 4, 1, 5};
std::sort(dq.begin(), dq.end());

std::array<int, 5> arr = {3, 1, 4, 1, 5};
std::sort(arr.begin(), arr.end());

// list 不能用 std::sort（非随机访问迭代器）
// 用成员函数 list.sort()
std::list<int> lst = {3, 1, 4, 1, 5};
lst.sort();                          // 成员函数，O(N log N)，稳定
lst.sort([](int a, int b) { return a > b; });
```

## 6. 实战案例：区间合并前的排序

```cpp
struct Interval {
    int start, end;
};

std::vector<Interval> intervals = {{5, 8}, {1, 3}, {2, 6}};

// 按起点升序排列，起点相同按终点升序
std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    if (a.start != b.start) return a.start < b.start;
    return a.end < b.end;
});

// 现在 intervals 按起点有序，可直接扫描合并
for (size_t i = 1; i < intervals.size(); ++i) {
    if (intervals[i].start <= intervals[i-1].end) {
        intervals[i-1].end = std::max(intervals[i-1].end, intervals[i].end);
        // 标记 intervals[i] 为已合并...
    }
}
```

## 7. 相关笔记

- [[Algorithm]] — `<algorithm>` 头文件中 `sort`/`partial_sort`/`nth_element` 的函数签名
- [[Double Array Counting Pattern]] — 值域有限时用数组下标替代排序
- [[Hash Table - Separate Chaining]] — 排序确定链表顺序后可用二分查找优化
- [[Greedy Algorithm]] — 贪心策略第一步通常需要排序
- [[Linked List]] — `std::list::sort()` 的归并排序实现

## 8. 注意事项

1. **Lambda 是首选**：简洁、可内联、可捕获上下文，90% 场景适用。
2. **Functor 用于复用**：比较逻辑需在多处使用，或需携带状态时选用。
3. **严格弱序是铁律**：`<=` 代替 `<` 导致 UB，编译期不报错，运行时可能崩溃或产生错误结果。
4. **`std::sort` 不稳定**：相等元素可能交换位置，需保持原序时用 `stable_sort`。
5. **性能排序**：`sort` > `stable_sort` > `partial_sort`（只需 Top-K 时） > `nth_element`（只需中位数时）。
6. **自定义类型需提供比较器**：内置类型用默认 `<`，`struct`/`class` 需显式定义比较逻辑。
