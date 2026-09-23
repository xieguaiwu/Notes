---
title: std::map - Ordered Associative Container
tags:
  - C++
  - DataStructure
  - STL
  - 定义性
  - 基本原理
created: 2026-09-23
modified: 2026-09-23
---

# std::map - Ordered Associative Container

> [!abstract] 有序关联容器 — 红黑树实现
> `std::map` 是 C++ 标准库中的**有序键值对容器**，底层用红黑树（自平衡二叉搜索树）实现。所有操作 $O(\log n)$，按键升序遍历。需要有序性、范围查询、或前缀匹配时首选 `map`；仅需快速查找时选 `unordered_map`。

## 1. 声明与初始化

```cpp
#include <map>
#include <string>

// 空 map
std::map<std::string, int> scores;

// 列表初始化
std::map<std::string, int> ages = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 22}
};

// 自定义比较器（降序）
std::map<int, std::string, std::greater<int>> reverse_map;

// multimap：允许重复键
std::multimap<std::string, int> multi_scores;
```

## 2. 插入元素

### 2.1 `operator[]`

```cpp
scores["Alice"] = 95;      // 插入新键
scores["Alice"] = 100;     // 覆盖已有值

// ⚠️ 注意：operator[] 若键不存在会默认构造值（int → 0）
// 因此不能用于 const map
```

### 2.2 `insert`

```cpp
// 插入单元素，返回 pair<iterator, bool>
auto [it, inserted] = scores.insert({"Dave", 88});
if (!inserted) {
    std::cout << "Key already exists: " << it->second << "\n";
}

// insert 不覆盖已有值
scores.insert({"Alice", 50});   // Alice 仍是 100，不会变成 50

// 批量插入
scores.insert({{"Eve", 91}, {"Frank", 76}});

// 带提示的插入（hint）— 若位置正确可均摊 O(1)
auto hint = scores.lower_bound("Grace");
scores.insert(hint, {"Grace", 82});
```

### 2.3 `emplace`（原位构造）

```cpp
// 避免临时对象的构造和拷贝
scores.emplace("Heidi", 97);
scores.emplace(std::piecewise_construct,
               std::forward_as_tuple("Ivan"),
               std::forward_as_tuple(85));
```

### 2.4 四种方式对比

| 方式 | 覆盖已有键 | 返回值 | 适用场景 |
|:-----|:----------|:-------|:---------|
| `m[key] = val` | ✅ 覆盖 | 引用 | 插入或更新 |
| `m.insert({key, val})` | ❌ 不覆盖 | `pair<it, bool>` | 仅插入新键 |
| `m.emplace(key, val)` | ❌ 不覆盖 | `pair<it, bool>` | 避免拷贝，性能最优 |
| `m.insert_or_assign(key, val)` | ✅ 覆盖 | `pair<it, bool>` | C++17，明确语义 |

## 3. 查找元素

### 3.1 `operator[]` 与 `at()`

```cpp
// operator[]：键不存在时默认插入
int val = scores["Alice"];    // 存在则返回值，不存在则插入默认值

// at()：键不存在时抛出 std::out_of_range
try {
    int val2 = scores.at("Unknown");
} catch (const std::out_of_range& e) {
    std::cout << "Key not found\n";
}
```

### 3.2 `find`

```cpp
auto it = scores.find("Bob");
if (it != scores.end()) {
    std::cout << "Bob's score: " << it->second << "\n";
}

// find 不插入新元素（const 安全）
```

### 3.3 `count` / `contains`

```cpp
// count：返回 0 或 1（map 键唯一）
if (scores.count("Alice")) { /* 存在 */ }

// contains：C++20，语义更清晰
if (scores.contains("Alice")) { /* 存在 */ }

// multimap 的 count 可返回多个
size_t n = multi_scores.insert({"Alice", 1});
// 再次 insert 相同 key...
size_t cnt = multi_scores.count("Alice");  // 返回该 key 的元素数量
```

## 4. 删除元素

```cpp
// 按 key 删除，返回删除的元素个数
size_t n = scores.erase("Alice");

// 按迭代器删除
auto it = scores.find("Bob");
if (it != scores.end()) scores.erase(it);

// 按范围删除
auto first = scores.lower_bound("C");
auto last = scores.upper_bound("F");
scores.erase(first, last);   // 删除 [C, F] 范围内的所有键

// 清空
scores.clear();
```

## 5. 遍历

```cpp
// 范围 for（按键升序）
for (const auto& [key, value] : scores) {       // C++17 结构化绑定
    std::cout << key << ": " << value << "\n";
}

// 迭代器
for (auto it = scores.begin(); it != scores.end(); ++it) {
    std::cout << it->first << " -> " << it->second << "\n";
}

// 逆序遍历
for (auto it = scores.rbegin(); it != scores.rend(); ++it) {
    std::cout << it->first << "\n";
}

// const 遍历
for (const auto& pair : scores) { ... }
```

## 6. 有序性相关操作

> [!tip] map 的核心优势
> 以下操作是 `unordered_map` **无法提供**的，也是选择 `map` 的关键理由。

### 6.1 `lower_bound` / `upper_bound`

```cpp
std::map<int, std::string> m = {{10, "a"}, {20, "b"}, {30, "c"}, {40, "d"}};

// lower_bound(key)：第一个 >= key 的元素
auto it1 = m.lower_bound(25);   // 指向 (30, "c")

// upper_bound(key)：第一个 > key 的元素
auto it2 = m.upper_bound(30);   // 指向 (40, "d")

// 查找第一个 >= 25 的键
auto it3 = m.lower_bound(25);
if (it3 != m.end()) {
    std::cout << "First >= 25: " << it3->first << "\n";  // 30
}
```

### 6.2 `equal_range`

```cpp
// 返回 [lower_bound, upper_bound) 的范围
auto [first, last] = m.equal_range(30);
for (auto it = first; it != last; ++it) {
    std::cout << it->first << "\n";   // 输出 30
}

// multimap 的 equal_range 可返回多个相同 key
```

### 6.3 前驱与后继

```cpp
auto it = m.find(30);

// 前驱
if (it != m.begin()) {
    auto prev = std::prev(it);
    std::cout << "Previous: " << prev->first << "\n";  // 20
}

// 后继
auto next = std::next(it);
if (next != m.end()) {
    std::cout << "Next: " << next->first << "\n";       // 40
}
```

### 6.4 最值

```cpp
auto min_it = m.begin();                    // 最小键
auto max_it = std::prev(m.end());           // 最大键

// 找小于 key 的最大元素（前驱）
auto it = m.lower_bound(key);
if (it != m.begin()) {
    --it;  // 现在 it->first < key
}

// 找大于 key 的最小元素（后继）
auto it2 = m.upper_bound(key);
if (it2 != m.end()) {
    // it2->first > key
}
```

## 7. 自定义比较器

```cpp
// 按字符串长度排序
struct CompareByLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};
std::map<std::string, int, CompareBy_length> length_ordered_map;

// Lambda 比较器（需用 decltype 推导类型）
auto cmp = [](int a, int b) { return a > b; };
std::map<int, std::string, decltype(cmp)> reverse_map(cmp);

// ⚠️ 警告：map 的比较器必须满足严格弱序
// 自定义比较器出错会导致红黑树结构损坏
```

## 8. `std::map` vs `std::unordered_map`

| 特性 | `std::map` | `std::unordered_map` |
|:-----|:-----------|:---------------------|
| 底层结构 | 红黑树 | 桶数组 + 链表 |
| 查找 / 插入 / 删除 | $O(\log n)$ | 期望 $O(1)$，最坏 $O(n)$ |
| 有序遍历 | ✅ 按键升序 | ❌ 不确定顺序 |
| `lower_bound` / `upper_bound` | ✅ 支持 | ❌ 不支持 |
| 内存开销 | 每个节点额外指针（父/左/右） | 桶数组 + 链表指针 |
| 迭代稳定性 | 插入/删除不使其他迭代器失效（仅被删迭代器失效） | rehash 后所有迭代器失效 |
| 自定义要求 | 比较器（`operator<`） | 哈希函数 + `operator==` |
| 性能特征 | 稳定 $O(\log n)$ | 通常更快，但可能被碰撞攻击 |

## 9. 实战案例

### 9.1 频次统计 + 有序输出

```cpp
std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
std::map<std::string, int> freq;
for (auto& w : words) freq[w]++;

// 按字母序输出频次
for (auto& [word, count] : freq) {
    std::cout << word << ": " << count << "\n";
}
// apple: 3
// banana: 2
// cherry: 1
```

### 9.2 时间线事件（按时间排序）

```cpp
std::map<int, std::string> timeline;
timeline[1945] = "WWII ends";
timeline[1969] = "Moon landing";
timeline[1989] = "Berlin Wall falls";

// 查找最近的事件（前驱）
int query_year = 1970;
auto it = timeline.upper_bound(query_year);
if (it != timeline.begin()) {
    --it;
    std::cout << "Most recent event before " << query_year << ": "
              << it->second << " (" << it->first << ")\n";
    // Moon landing (1969)
}
```

### 9.3 区间覆盖（用 map 维护不重叠区间）

```cpp
std::map<int, int> intervals;  // start -> end

void add_interval(int start, int end) {
    auto it = intervals.lower_bound(start);
    // 检查前一个区间是否重叠
    if (it != intervals.begin()) {
        auto prev = std::prev(it);
        if (prev->second >= start) {
            start = std::min(start, prev->first);
            end = std::max(end, prev->second);
            intervals.erase(prev);
        }
    }
    // 检查当前及后续重叠区间
    while (it != intervals.end() && it->first <= end) {
        end = std::max(end, it->second);
        it = intervals.erase(it);  // erase 返回下一个迭代器
    }
    intervals[start] = end;
}
```

## 10. `std::set` 简介

`std::map` 的键-only 版本，同样基于红黑树：

```cpp
std::set<int> s = {3, 1, 4, 1, 5};  // 自动去重: {1, 3, 4, 5}

s.insert(2);
s.erase(3);

// 有序操作与 map 相同
auto it = s.lower_bound(3);   // 指向 4

// 集合运算（<algorithm> 头文件）
std::vector<int> result;
std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
```

## 11. 相关笔记

- [[Hash Table - Separate Chaining]] — `unordered_map` 的详细用法及与 `map` 的对比
- [[Custom Comparator and Sorting]] — 排序时自定义比较器的方法
- [[Algorithm]] — `std::set_union` / `std::set_intersection` 等集合算法
- [[Linked List]] — 当需要频繁在中间插入时可考虑 `std::list`
- [[Double Array Counting Pattern]] — 值域有限时用数组替代 map

## 12. 注意事项

1. **`operator[]` 的副作用**：访问不存在的键会插入默认值，只读场景用 `at()` 或 `find()`。
2. **迭代器稳定性**：插入不使其他迭代器失效；删除仅使被删迭代器失效。
3. **性能常数**：红黑树的 $O(\log n)$ 常数较大，n < 100 时线性搜索可能更快。
4. **不能修改键**：`map` 的键是 `const`，修改键会破坏树结构。需改键时先删除再插入。
5. **`lower_bound` 语义**：返回第一个 $\geq$ key 的元素，不是"最接近的"。找前驱需额外判断。
6. **multimap 的 `operator[]`**：multimap 没有 `operator[]`（键不唯一），只能用 `insert` / `find` / `equal_range`。
