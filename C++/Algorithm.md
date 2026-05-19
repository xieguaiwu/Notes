---
tags:
  - C++
  - 定义性
  - 基本原理
  - STL
  - Algorithm
title: Algorithm
created: 2026-04-27
modified: 2026-04-27
---

# Algorithm

> [!abstract] C++ `<algorithm>` 头文件
> `<algorithm>` 是 C++ 标准库中最大的头文件之一，提供大量**泛型算法**，通过迭代器操作序列，不依赖具体容器类型。大多数算法接受**谓词（Predicate）**自定义行为。

## 1. 非修改序列操作

### 1.1 `std::find` / `std::find_if` / `std::find_if_not`

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {1, 2, 3, 4, 5};

auto it1 = std::find(v.begin(), v.end(), 3);           // 查找值为3的元素
auto it2 = std::find_if(v.begin(), v.end(), [](int x) {
    return x > 3;
});                                                      // 查找第一个大于3的元素
auto it3 = std::find_if_not(v.begin(), v.end(), [](int x) {
    return x < 3;
});                                                      // 查找第一个不小于3的元素
```

> [!tip] 返回值
> 返回指向找到元素的迭代器；未找到则返回 `end()`。使用前务必检查。

### 1.2 `std::count` / `std::count_if`

```cpp
int n1 = std::count(v.begin(), v.end(), 3);       // 值为3的元素个数
int n2 = std::count_if(v.begin(), v.end(), [](int x) {
    return x > 3;
});                                                  // 大于3的元素个数
```

### 1.3 `std::all_of` / `std::any_of` / `std::none_of`

```cpp
bool all  = std::all_of(v.begin(), v.end(), [](int x) { return x > 0; });   // 全部>0?
bool any  = std::any_of(v.begin(), v.end(), [](int x) { return x > 3; });   // 任一>3?
bool none = std::none_of(v.begin(), v.end(), [](int x) { return x < 0; });  // 无<0?
```

> [!note] 空范围行为
> - `all_of` 对空范围返回 `true`（空真）
> - `any_of` 对空范围返回 `false`
> - `none_of` 对空范围返回 `true`

### 1.4 `std::for_each`

```cpp
std::for_each(v.begin(), v.end(), [](int& x) { x *= 2; });  // 将每个元素乘2
```

### 1.5 `std::equal` / `std::mismatch`

```cpp
std::vector<int> a = {1, 2, 3}, b = {1, 2, 4};

bool eq = std::equal(a.begin(), a.end(), b.begin());  // 逐元素比较

auto [it1, it2] = std::mismatch(a.begin(), a.end(), b.begin());
// it1 指向 a 中第一个不匹配元素 (3)，it2 指向 b 中对应元素 (4)
```

## 2. 修改序列操作

### 2.1 `std::copy` / `std::copy_if`

```cpp
std::vector<int> src = {1, 2, 3, 4, 5};
std::vector<int> dest(5);

std::copy(src.begin(), src.end(), dest.begin());  // 完整复制

std::vector<int> evens;
std::copy_if(src.begin(), src.end(), std::back_inserter(evens),
             [](int x) { return x % 2 == 0; });   // 只复制偶数
```

### 2.2 `std::transform`

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::vector<int> result(v.size());

// 一元变换
std::transform(v.begin(), v.end(), result.begin(), [](int x) { return x * x; });
// result = {1, 4, 9, 16, 25}

// 二元变换：两个序列合并
std::vector<int> a = {1, 2, 3}, b = {10, 20, 30}, c(3);
std::transform(a.begin(), a.end(), b.begin(), c.begin(), std::plus<int>());
// c = {11, 22, 33}
```

### 2.3 `std::fill` / `std::fill_n`

```cpp
std::vector<int> v(10);
std::fill(v.begin(), v.end(), 42);      // 全部填42
std::fill_n(v.begin(), 5, 0);            // 前5个填0
```

### 2.4 `std::replace` / `std::replace_if`

```cpp
std::vector<int> v = {1, 2, 3, 2, 5};

std::replace(v.begin(), v.end(), 2, 0);  // 所有2替换为0
std::replace_if(v.begin(), v.end(), [](int x) { return x > 3; }, -1);  // 大于3的替换为-1
```

### 2.5 `std::remove` / `std::remove_if`（删除-擦除惯用法）

```cpp
std::vector<int> v = {1, 2, 3, 2, 5, 2};

// remove 不真正删除，只是把非目标元素移到前面，返回新逻辑末尾
auto new_end = std::remove(v.begin(), v.end(), 2);  // 移除所有2
v.erase(new_end, v.end());  // 真正擦除尾部残余

// 一步到位：erase-remove 惯用法
v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x < 3; }), v.end());
```

> [!warning] `std::remove` 不改变容器大小
> `remove` 只是重排元素，返回新的逻辑末尾迭代器。必须配合 `erase()` 才能真正缩小容器。这是经典的 **erase-remove 惯用法**。

### 2.6 `std::unique`

```cpp
std::vector<int> v = {1, 1, 2, 2, 3, 3, 3};
auto last = std::unique(v.begin(), v.end());  // 去除相邻重复
v.erase(last, v.end());  // v = {1, 2, 3}
```

> [!important] `unique` 只去除**相邻**重复元素
> 对无序序列，必须先 `sort` 再 `unique`：
> ```cpp
> std::sort(v.begin(), v.end());
> v.erase(std::unique(v.begin(), v.end()), v.end());
> ```

### 2.7 `std::reverse` / `std::rotate`

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::reverse(v.begin(), v.end());  // v = {5, 4, 3, 2, 1}

std::vector<int> w = {1, 2, 3, 4, 5};
std::rotate(w.begin(), w.begin() + 2, w.end());  // 左旋2位: w = {3, 4, 5, 1, 2}
```

### 2.8 `std::shuffle`

```cpp
#include <random>
std::vector<int> v = {1, 2, 3, 4, 5};
std::random_device rd;
std::mt19937 g(rd());
std::shuffle(v.begin(), v.end(), g);  // 随机打乱
```

## 3. 排序与相关操作

### 3.1 `std::sort` / `std::stable_sort`

```cpp
std::vector<int> v = {5, 2, 4, 1, 3};

std::sort(v.begin(), v.end());                    // 升序
std::sort(v.begin(), v.end(), std::greater<>());  // 降序
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a % 10 < b % 10;                       // 按个位数排序
});

// stable_sort 保持相等元素的原始相对顺序
std::stable_sort(v.begin(), v.end());
```

| 特性 | `sort` | `stable_sort` |
|------|--------|---------------|
| 时间复杂度 | $O(N \log N)$ | $O(N \log^2 N)$ |
| 稳定性 | ❌ 不稳定 | ✅ 稳定 |
| 空间 | $O(\log N)$ | $O(N)$ |

### 3.2 `std::partial_sort`

```cpp
std::vector<int> v = {5, 2, 8, 1, 9, 3, 7};
std::partial_sort(v.begin(), v.begin() + 3, v.end());
// v 的前3个元素是最小的3个且有序，其余元素无序
```

### 3.3 `std::nth_element`

```cpp
std::vector<int> v = {5, 2, 8, 1, 9, 3, 7};
std::nth_element(v.begin(), v.begin() + 3, v.end());
// v[3] 是排序后应在的位置（即第4小的元素）
// v[0..2] ≤ v[3] ≤ v[4..6]，但两侧不一定有序
```

> [!tip] `nth_element` 的时间复杂度
> 平均 $O(N)$，比完整排序更快。常用于求中位数、第 K 小等。

## 4. 二分搜索

> [!important] 前提
> 二分搜索要求序列**已排序**（默认升序）。

### 4.1 `std::lower_bound` / `std::upper_bound`

```cpp
std::vector<int> v = {1, 2, 4, 4, 4, 6, 8};

auto lb = std::lower_bound(v.begin(), v.end(), 4);  // 第一个 ≥ 4 的位置 → v[2]
auto ub = std::upper_bound(v.begin(), v.end(), 4);  // 第一个 > 4 的位置 → v[5]
```

| 函数 | 含义 | 对 `4` 在上述序列中 |
|------|------|---------------------|
| `lower_bound` | 第一个 **≥** `val` 的迭代器 | 指向第1个 `4` |
| `upper_bound` | 第一个 **>** `val` 的迭代器 | 指向 `6` |

### 4.2 `std::binary_search`

```cpp
bool found = std::binary_search(v.begin(), v.end(), 4);  // true
bool found2 = std::binary_search(v.begin(), v.end(), 5);  // false
```

> [!note] `binary_search` 只返回 `bool`
> 如果需要位置信息，使用 `lower_bound`。

### 4.3 `std::equal_range`

```cpp
auto [first, last] = std::equal_range(v.begin(), v.end(), 4);
// [first, last) 是所有等于4的元素范围
int count = last - first;  // 4 出现的次数 = 3
```

> [!tip] 统计有序序列中某值出现次数
> `equal_range` 一次调用即可获得范围，比 `upper_bound - lower_bound` 更语义化。

## 5. 堆操作

```cpp
std::vector<int> v = {3, 1, 4, 1, 5, 9};

std::make_heap(v.begin(), v.end());   // 将序列变为最大堆
// v = {9, 5, 4, 1, 1, 3}

std::pop_heap(v.begin(), v.end());    // 将最大元素移到末尾，重新堆化
int max_val = v.back();                // 9
v.pop_back();                          // 移除最大元素

v.push_back(6);
std::push_heap(v.begin(), v.end());    // 将末尾新元素插入堆中正确位置

std::sort_heap(v.begin(), v.end());    // 堆排序（排序后不再是堆）
```

| 操作 | 说明 | 复杂度 |
|------|------|--------|
| `make_heap` | 构造堆 | $O(n)$ |
| `push_heap` | 插入元素 | $O(\log n)$ |
| `pop_heap` | 弹出最大元素 | $O(\log n)$ |
| `sort_heap` | 堆排序 | $O(n \log n)$ |

## 6. 集合操作

> [!important] 前提
> 集合操作要求两个序列**都已排序**。

```cpp
std::vector<int> a = {1, 2, 3, 4, 5};
std::vector<int> b = {3, 4, 5, 6, 7};
std::vector<int> result;

// 并集
std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
// result = {1, 2, 3, 4, 5, 6, 7}

result.clear();
// 交集
std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
// result = {3, 4, 5}

result.clear();
// 差集 a - b
std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
// result = {1, 2}

result.clear();
// 对称差集 (a ∪ b) - (a ∩ b)
std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
// result = {1, 2, 6, 7}
```

### `std::includes`（子集判断）

```cpp
std::vector<int> a = {1, 2, 3, 4, 5};
std::vector<int> sub = {2, 3};

bool is_subset = std::includes(a.begin(), a.end(), sub.begin(), sub.end());  // true
```

## 7. 最小值与最大值

```cpp
int m = std::min(3, 7);                          // 3
int M = std::max(3, 7);                          // 7
auto [lo, hi] = std::minmax({3, 1, 4, 1, 5});   // lo=1, hi=5

// 自定义比较
std::min(3, 7, [](int a, int b) { return a > b; });  // 返回较大的（因为比较逻辑反转）

// C++17: clamp
int clamped = std::clamp(15, 0, 10);  // 10（将值限制在[min, max]范围内）
```

> [!tip] `min`/`max` 的初始化列表版本
> ```cpp
> int m = std::min({3, 1, 4, 1, 5});  // 1
> int M = std::max({3, 1, 4, 1, 5});  // 5
> ```
> 接受 `initializer_list`，可比较任意多个值。

## 8. 排列

```cpp
std::vector<int> v = {1, 2, 3};

std::next_permutation(v.begin(), v.end());  // v = {1, 3, 2}
std::next_permutation(v.begin(), v.end());  // v = {2, 1, 3}
std::prev_permutation(v.begin(), v.end());  // v = {1, 3, 2}

// 生成全排列
std::sort(v.begin(), v.end());  // 必须先排序，确保从最小排列开始
do {
    // 处理当前排列
} while (std::next_permutation(v.begin(), v.end()));
```

> [!note] `next_permutation` 返回值
> 如果已经到达最后一个排列，返回 `false` 并重置为第一个排列。

## 9. 其他常用算法

| 算法 | 说明 | 复杂度 |
|------|------|--------|
| `std::swap` | 交换两个值 | $O(1)$ |
| `std::iter_swap` | 交换两个迭代器指向的值 | $O(1)$ |
| `std::distance` | 计算迭代器间距离 | $O(n)$/ $O(1)$ |
| `std::advance` | 移动迭代器 n 步 | $O(n)$/ $O(1)$ |
| `std::generate` | 用生成器填充序列 | $O(n)$ |
| `std::iota` | 递增填充（需 `<numeric>`） | $O(n)$ |

> [!warning] `<numeric>` 不在 `<algorithm>` 中
> `std::accumulate`、`std::iota`、`std::inner_product` 等数值算法在 `<numeric>` 头文件中，不要混淆。

## 10. 算法选择速查

| 需求 | 推荐算法 |
|------|----------|
| 查找元素 | `find` / `find_if` |
| 统计个数 | `count` / `count_if` |
| 条件判断 | `all_of` / `any_of` / `none_of` |
| 复制/过滤 | `copy` / `copy_if` |
| 变换 | `transform` |
| 删除元素 | `remove` + `erase` |
| 去重 | `sort` + `unique` + `erase` |
| 排序 | `sort`（不稳定）/ `stable_sort`（稳定） |
| 第 K 小 | `nth_element` |
| 二分查找 | `lower_bound` / `upper_bound` / `binary_search` |
| 范围查找 | `equal_range` |
| 最大堆 | `make_heap` + `push_heap` / `pop_heap` |
| 集合运算 | `set_union` / `set_intersection` / `set_difference` |
| 全排列 | `next_permutation` |
| 限值 | `clamp` |

---

## 相关笔记

- [[Smart Pointer]] - 智能指针与内存管理
- [[stdexcept]] - C++ 标准异常类
- [[Template and XOR]] - 模板与位运算