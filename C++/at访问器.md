---
tags:
  - C++
  - 定义性
  - 基本原理
  - STL
title: at访问器
created: 2026-04-27
modified: 2026-04-27
---

# at访问器

> [!abstract] C++ 容器的 `at()` 方法
> `at()` 是 C++ 标准容器提供的**带边界检查**的元素访问方法。与 `operator[]` 不同，`at()` 在索引/键越界时会抛出 `std::out_of_range` 异常，而非导致未定义行为。

## 1. 支持的容器

| 容器 | 签名 | 越界行为 |
|------|------|----------|
| `std::vector` | `reference at(size_type pos)` | 抛出 `out_of_range` |
| `std::array` | `reference at(size_type pos)` | 抛出 `out_of_range` |
| `std::string` | `reference at(size_type pos)` | 抛出 `out_of_range` |
| `std::deque` | `reference at(size_type pos)` | 抛出 `out_of_range` |
| `std::map` | `mapped_type& at(const Key& key)` | 抛出 `out_of_range` |
| `std::unordered_map` | `mapped_type& at(const Key& key)` | 抛出 `out_of_range` |

> [!note] 序列容器用**位置索引**，关联容器用**键**查找。

## 2. `at()` vs `operator[]`

### 2.1 序列容器（vector, array, string, deque）

| 特性 | `at(pos)` | `operator[]` |
|------|-----------|--------------|
| 边界检查 | ✅ 有 | ❌ 无 |
| 越界行为 | 抛出 `out_of_range` | **未定义行为** |
| 性能 | 略慢（检查开销） | 最快 |
| 安全性 | 高 | 低 |

```cpp
std::vector<int> v = {10, 20, 30};

// at() — 安全访问
try {
    int x = v.at(5);  // 抛出 std::out_of_range
} catch (const std::out_of_range& e) {
    std::cerr << e.what() << "\n";
}

// operator[] — 危险访问
int y = v[5];  // 未定义行为！可能崩溃、可能返回垃圾值
```

### 2.2 关联容器（map, unordered_map）

| 特性 | `at(key)` | `operator[]` |
|------|-----------|--------------|
| 键不存在时 | 抛出 `out_of_range` | **插入默认值**并返回引用 |
| 副作用 | 无 | 可能修改容器 |
| `const` 容器可用 | ✅ | ❌ |
| 适合查找 | ✅ | ❌ |

```cpp
std::map<std::string, int> scores = {{"Alice", 90}, {"Bob", 85}};

// at() — 安全查找，不修改容器
int a = scores.at("Alice");       // 90
int x = scores.at("Charlie");     // 抛出 std::out_of_range

// operator[] — 键不存在时自动插入
int y = scores["Charlie"];         // 插入 {"Charlie", 0}，返回 0
// scores 现在包含 {"Alice", 90}, {"Bob", 85}, {"Charlie", 0}
```

> [!warning] `operator[]` 的陷阱
> - 对 `map`/`unordered_map` 使用 `[]` 查找不存在的键时，会**静默插入**一个默认构造的元素，改变容器大小。
> - `[]` 不能用于 `const` 容器，因为它可能修改容器。
> - 如果只想查找而不想修改，**必须用 `at()` 或 `find()`**。

## 3. 用法示例

### 3.1 基本访问

```cpp
#include <vector>
#include <array>
#include <string>
#include <map>

std::vector<int> v = {1, 2, 3};
int x = v.at(0);            // 1

std::array<int, 3> arr = {10, 20, 30};
int y = arr.at(1);          // 20

std::string s = "hello";
char c = s.at(0);           // 'h'

std::map<int, std::string> m = {{1, "one"}, {2, "two"}};
std::string val = m.at(2);  // "two"
```

### 3.2 异常处理

```cpp
#include <stdexcept>
#include <iostream>

void safeAccess(const std::vector<int>& v, std::size_t idx) {
    try {
        std::cout << "v[" << idx << "] = " << v.at(idx) << "\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "越界访问: " << e.what() << "\n";
    }
}
```

### 3.3 `const` 上下文中安全访问 map

```cpp
void printValue(const std::map<std::string, int>& m, const std::string& key) {
    // 只能用 at()，不能用 []（因为 [] 可能修改容器）
    try {
        std::cout << key << ": " << m.at(key) << "\n";
    } catch (const std::out_of_range&) {
        std::cout << key << ": not found\n";
    }
}
```

## 4. 选择指南

| 场景 | 推荐方法 |
|------|----------|
| 索引/键可能越界，需要安全访问 | `at()` |
| 确定索引/键有效，追求极致性能 | `operator[]` |
| 在 `const` 函数中访问 map | `at()` 或 `find()` |
| 查找键是否存在 | `find()` 或 `contains()`（C++20） |
| 查找并插入（如计数器） | `operator[]` |

> [!important] 原则
> - **默认用 `at()`**：安全优先，除非性能分析表明边界检查是瓶颈。
> - **`operator[]` 只在索引已验证时使用**：如循环变量 `i < v.size()` 中的 `v[i]`。
> - **map 查找永远不要用 `[]`**：除非你确实想插入默认值。

## 5. C++23 `at()` 扩展

C++23 为 `std::string` 和 `std::string_view` 新增了带范围检查的 `at()` 重载，支持子串访问：

```cpp
// C++23 起
std::string s = "Hello, World!";
auto sub = s.at(7, 6);  // 从位置 7 开始，长度 6 → "World"
```

> [!tip] C++23 之前，需要手动组合 `substr()` 与边界检查。

---

## 相关笔记

- [[stdexcept]] - `at()` 抛出的 `out_of_range` 异常类
- [[Smart Pointer]] - 智能指针与内存管理