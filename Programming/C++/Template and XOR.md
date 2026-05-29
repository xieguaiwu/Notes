---
tags:
  - C++
  - 定义性
  - 基本原理
  - Math
  - Type
title: Template and XOR
created: 2026-04-27
modified: 2026-04-27
---

# Template and XOR

> [!abstract] C++ 模板与 XOR 位运算
> 函数模板的基本用法，以及引用传递与 XOR 位运算的结合。

## 1. XOR 位运算

```cpp
void try_to_xor() {
    int a = 1, b = 21;
    int result = a ^ (1 >> b);  // ⚠️ 注意：1 >> b 是位移，不是 1 XOR b
    std::cout << result << "\n";
}
```

> [!warning] 常见陷阱
> `1 >> b` 是**右移运算**，不是 XOR。`a ^ (1 >> b)` 的含义是：
> 1. 先将 `1` 右移 `b` 位 → 结果为 `0`（因为 `1 >> 21 = 0`）
> 2. 再将 `a` 与 `0` 做 XOR → 结果为 `a` 本身
> 
> 如果想做 `a XOR b`，应写为 `a ^ b`。

## 2. 函数模板

### 2.1 普通引用参数

```cpp
template<class T>
T cal(T& p1, T& p2, T& p3) {
    return p1 ^ p2 ^ p3;
}
```

> [!note] 说明
> 调用时直接将实际参数传入函数，而不需要先把形式参数赋值到实际参数的地址上。
> 但使用非常量引用时，必须传入变量，不能传入字面量。

```cpp
int x = 1, y = 4;
std::cout << cal<int>(x, y, x) << "\n";  // ✅ 传入变量
// std::cout << cal<int>(1, 4, 1);         // ❌ 字面量不能绑定到 T&
```

### 2.2 常量引用参数

```cpp
template<class T>
T cal_safer(const T& p1, const T& p2, const T& p3) {
    return p1 ^ p2 ^ p3;
}
```

> [!tip] `const T&` 的优势
> - 增加const后，函数将无法修改实际参数 `p1`, `p2`, `p3`
> - 可以接受字面量和临时值

```cpp
std::cout << cal_safer<int>(1, 4, 1);  // ✅ 字面量可以绑定到 const T&
```

## 3. 引用传递对比

| 形式 | 能否修改实参 | 能否接受字面量 | 适用场景 |
|------|-------------|---------------|---------|
| `T&` | ✅ | ❌ | 需要修改实参时 |
| `const T&` | ❌ | ✅ | 只读访问，通用性更强 |

> [!important] 最佳实践
> 函数参数默认使用 `const T&`，除非确实需要修改实参才使用 `T&`。

---

## 相关笔记

- [[Graph Theory and Search]] - 图论与搜索算法
- [[Constructor Init List]] - 构造函数与初始化