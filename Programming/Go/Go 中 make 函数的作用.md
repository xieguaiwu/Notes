# Go 中 `make` 函数的作用

## 概述

`make` 是 Go 的**内置函数**，用于创建并初始化 **slice**（切片）、**map**（映射）和 **channel**（通道）这三种引用类型。

```go
selected := make(map[int]struct{})
```

## 为什么需要 `make`？

Go 中 map 是引用类型，声明后零值是 `nil`：

```go
var selected map[int]struct{}  // selected == nil，不能直接写入
```

往 `nil` map 里写数据会 **panic**（崩溃）：

```go
selected[0] = struct{}{}  // panic: assignment to entry in nil map
```

`make` 的作用就是把它变成一个**已初始化、可直接使用**的空 map：

```go
selected = make(map[int]struct{})  // 现在可以正常读写
selected[0] = struct{}{}           // ✅ 没问题
```

## 完整对比

| 写法 | 结果 | 能否读写？ |
|---|---|---|
| `var selected map[int]struct{}` | `nil` | 可读（返回零值），**不可写** |
| `selected := make(map[int]struct{})` | 空 map（已初始化） | 可读可写 |
| `selected := map[int]struct{}{}` | 空 map（字面量） | 可读可写（等效于 make） |

## 性能优化

`make` 可以额外指定**初始容量**来优化性能：

```go
m := make(map[int]struct{}, 10)  // 预分配 10 个键的空间
s := make([]int, 0, 10)          // 预分配 10 个元素的底层数组
```

## 适用范围

| 类型 | 说明 |
|---|---|
| `map` | 分配哈希表，返回已初始化的 map |
| `slice` | 分配底层数组，返回指定长度/容量的 slice |
| `channel` | 分配环形缓冲区，返回指定缓冲大小的 channel |

## 补充：`new` vs `make`

- `make`：只用于 map / slice / channel，返回**初始化后的值**（非指针）
- `new`：用于任意类型，返回**指向零值的指针**

```go
p := new(int)       // *int，指向 0
m := make(map[int]int)  // map[int]int，可用的空 map
```
