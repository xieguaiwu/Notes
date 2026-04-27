---
tags:
  - C++
  - 定义性
  - 基本原理
  - Memory
title: Smart Pointer
created: 2026-04-27
modified: 2026-04-27
---

# Smart Pointer

> [!abstract] `<memory>` 头文件中的智能指针
> 智能指针是 C++ 提供的自动内存管理工具，遵循 RAII 原则，在超出作用域时自动释放资源，有效防止内存泄漏和悬挂指针。

## 1. 智能指针类型

### 1.1 `std::unique_ptr`

> [!note] 独占所有权
> - 独占所有权的智能指针
> - 在超出作用域时自动删除对象
> - 不可复制，但可以移动

```cpp
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(42);
// 当ptr超出作用域时，其指向的内存会被自动释放
```

### 1.2 `std::shared_ptr`

> [!note] 共享所有权
> - 共享所有权的智能指针
> - 使用引用计数来管理对象生命周期
> - 当最后一个 `shared_ptr` 被销毁时，对象被删除

```cpp
#include <memory>
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
std::shared_ptr<int> ptr2 = ptr1;  // 引用计数增加到2
// 只有当ptr1和ptr2都被销毁时，对象才会被删除
```

### 1.3 `std::weak_ptr`

> [!note] 观察者指针
> - 不拥有对象的智能指针
> - 用于打破 `shared_ptr` 之间的循环引用
> - 必须转换为 `shared_ptr` 才能访问对象

```cpp
#include <memory>
std::shared_ptr<int> shared = std::make_shared<int>(42);
std::weak_ptr<int> weak = shared;
if (auto locked = weak.lock()) {  // 检查对象是否仍然存在
    // 使用locked访问对象
}
```

## 2. 内存分配相关函数

### 2.1 `std::make_unique<T>()`

> [!tip] 创建 `unique_ptr` 的推荐方法
> - 安全且高效
> - 避免显式 `new` 操作

```cpp
auto ptr = std::make_unique<int>(42);      // 创建int并初始化为42
auto arr = std::make_unique<int[]>(10);    // 创建整数数组
```

### 2.2 `std::make_shared<T>()`

> [!tip] 创建 `shared_ptr` 的推荐方法
> - 通常比直接使用构造函数更高效
> - 单次内存分配同时创建控制块和对象

```cpp
auto ptr = std::make_shared<int>(42);
auto obj = std::make_shared<MyClass>(arg1, arg2);  // 传递参数给构造函数
```

## 3. 自定义删除器

智能指针支持自定义删除器，用于特殊类型的资源清理：

```cpp
// 自定义删除器的unique_ptr
std::unique_ptr<int, void(*)(int*)> ptr(new int(42), [](int* p) {
    delete p;
    // 额外的清理操作
});
```

## 4. 内存分配器

| 工具 | 说明 |
|------|------|
| `std::allocator<T>` | 标准内存分配器类模板，用于容器的内存管理 |
| `std::allocate_shared` | 使用指定分配器创建 `shared_ptr` |
| `std::allocate_shared_noinit` | 使用指定分配器创建 `shared_ptr`（不初始化） |

## 5. `std::enable_shared_from_this`

> [!note] 从类内部安全获取 `shared_ptr`
> 使类能够生成指向自身的 `shared_ptr`，避免重复管理同一裸指针。

```cpp
class MyClass : public std::enable_shared_from_this<MyClass> {
public:
    std::shared_ptr<MyClass> getSharedPtr() {
        return shared_from_this();
    }
};
```

## 6. 智能指针对比

| 特性 | `unique_ptr` | `shared_ptr` | `weak_ptr` |
|------|-------------|-------------|------------|
| 所有权 | 独占 | 共享 | 无 |
| 可复制 | ❌ | ✅ | ✅ |
| 可移动 | ✅ | ✅ | ✅ |
| 引用计数 | 无 | 有 | 可观察 |
| 开销 | 最小 | 中等 | 最小 |
| 使用场景 | 独占资源 | 共享资源 | 打破循环引用 |

## 7. 优势

> [!tip] 智能指针的核心优势
> 1. **自动内存管理**：自动处理对象的生命周期，防止内存泄漏
> 2. **异常安全**：即使在异常情况下也能确保资源被正确释放
> 3. **RAII 原则**：通过构造函数和析构函数管理资源
> 4. **减少悬挂指针**：比原始指针更安全

## 8. 使用场景

| 场景 | 推荐智能指针 |
|------|-------------|
| 需要独占资源所有权 | `std::unique_ptr` |
| 需要共享资源所有权 | `std::shared_ptr` |
| 需要观察共享对象或打破循环引用 | `std::weak_ptr` |

---

## 相关笔记

- [[Constructor Init List]] - 构造函数与初始化
- [[stdexcept]] - C++ 标准异常类