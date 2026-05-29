---
tags:
  - C++
  - 定义性
  - 基本原理
  - OOP
title: Constructor Init List
created: 2026-04-27
modified: 2026-04-27
---

# Constructor Init List

> [!abstract] 构造函数默认参数与成员初始化列表
> C++ 构造函数中，成员初始化列表在函数体执行**前**初始化每个成员，是 C++ 最佳实践。结合默认参数，可以灵活地创建对象。

## 1. 语法

```cpp
Front(int r = 0, int c = 0, double val = 0.0)
    : rows(r), cols(c), data(r, std::vector<double>(c, val)) {}
```

## 2. 默认参数

```cpp
Front(int r = 0, int c = 0, double val = 0.0)
```

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `r` | `int` | `0` | 行数 |
| `c` | `int` | `0` | 列数 |
| `val` | `double` | `0.0` | 初始值 |

因为有默认值，调用时可省略尾部参数：

```cpp
Front f;              // r=0, c=0, val=0.0
Front f(3, 4);        // r=3, c=4, val=0.0
Front f(3, 4, 1.5);   // r=3, c=4, val=1.5
```

## 3. 成员初始化列表

```cpp
: rows(r), cols(c), data(r, std::vector<double>(c, val))
```

冒号 `:` 后是成员初始化列表，在函数体执行**前**初始化每个成员：

| 语法 | 含义 |
|------|------|
| `rows(r)` | 用参数 `r` 初始化成员 `rows` |
| `cols(c)` | 用参数 `c` 初始化成员 `cols` |
| `data(r, std::vector<double>(c, val))` | 用参数初始化成员 `data` |

> [!important] 二维数组初始化
> 最后一行最关键，展开看：
> ```cpp
> data(r, std::vector<double>(c, val))
> ```
> - `data` 类型为 `std::vector<std::vector<double>>`
> - `std::vector<double>(c, val)` — 构造**内层 vector**：长度 `c`，每个元素值为 `val`
> - `data(r, ...)` — 构造**外层 vector**：长度 `r`，每个元素是上面那个内层 vector
> 
> **效果**：创建一个 $r \times c$ 的二维数组，所有元素初始化为 `val`。

## 4. 空函数体 `{}`

所有初始化工作在初始化列表中完成，函数体为空——这是 C++ 最佳实践。

## 5. 为什么用成员初始化列表而非函数体内赋值？

```cpp
// ✅ 成员初始化列表（高效）—— 直接构造
Front(int r, int c, double val)
    : rows(r), cols(c), data(r, std::vector<double>(c, val)) {}

// ❌ 函数体内赋值（低效）—— 先默认构造，再赋值
Front(int r, int c, double val) {
    rows = r;
    cols = c;
    data = std::vector<std::vector<double>>(r, std::vector<double>(c, val));
}
```

> [!tip] 初始化列表的优势
> - 初始化列表直接构造成员，避免了"先默认构造再赋值"的额外开销
> - 对于 `const` 成员和引用成员，**必须**使用初始化列表，因为它们不能被赋值

---

## 相关笔记

- [[Smart Pointer]] - 智能指针与内存管理
- [[stdexcept]] - C++ 标准异常类