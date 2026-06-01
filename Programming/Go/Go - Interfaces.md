---
tags:
  - Go
  - ProgrammingLanguages
  - 定义性
  - 基本原理
title: "Go - Interfaces"
created: 2026-06-01
modified: 2026-06-01
---

# Go - Interfaces

> [!abstract] Go 中的接口是方法签名的集合，类型通过实现这些方法隐式满足接口（duck typing）。
> 接口是 Go 类型系统的核心抽象机制，也是实现多态和策略模式的基础。

## 1. 接口定义

### 1.1 基本语法

```go
type Stringer interface {
    String() string
}
```

一个类型只要实现了 `String() string` 方法，就隐式满足了 `Stringer` 接口——无需 `implements` 关键字。

### 1.2 隐式实现

```go
type Book struct {
    Title string
    Author string
}

func (b Book) String() string {
    return b.Title + " by " + b.Author
}

// Book 隐式满足 Stringer 接口
func print(s Stringer) {
    fmt.Println(s.String())
}
```

## 2. 接口值

接口值在运行时由两个 word 组成：

| 组件 | 说明 |
|------|------|
| **具体类型指针** | 指向实际存储的具体类型的类型信息 |
| **数据指针** | 指向实际存储的值 |

```go
var s Stringer = Book{"The Go Programming Language", "Donovan & Kernighan"}
// s 内部: (类型: Book, 值: Book{...})
```

### 2.1 nil 接口值 vs nil 值接口

```go
var s Stringer       // nil 接口: 类型和值都是 nil
var b *Book = nil
s = b                // 非 nil 接口: 类型是 *Book, 值是 nil
s == nil             // false! 因为类型信息不为 nil
```

> [!warning] 接口的 nil 检查陷阱
> 接口值为 nil 当且仅当**类型和值都为 nil**。将一个 nil 具体类型赋值给接口后，接口的类型信息不为空，因此 `== nil` 返回 `false`。

## 3. 空接口

```go
var any interface{}  // 或使用 Go 1.18+ 的 any 关键字
any = 42
any = "hello"
any = Book{}
```

空接口可以持有任何类型的值，但使用时需要类型断言来还原。

## 4. 类型断言

```go
var s interface{} = "hello"

str := s.(string)        // 直接断言，失败则 panic
str, ok := s.(string)    // 安全断言，ok 指示是否成功

switch v := s.(type) {   // type switch
case string:
    fmt.Println("string:", v)
case int:
    fmt.Println("int:", v)
default:
    fmt.Println("unknown type")
}
```

## 5. 接口与策略模式

接口最经典的应用是策略模式（Strategy Pattern）：

```go
// 策略抽象
type DictionarySource interface {
    FetchURL(query string) string
    Parse(html string) (*TranslationData, error)
}

// 具体策略
type YoudaoSource struct{}
func (y YoudaoSource) FetchURL(query string) string {
    return "https://dict.youdao.com/result?q=" + query
}

type WoerterNetSource struct{}
func (w WoerterNetSource) FetchURL(query string) string {
    return "https://www.verbformen.com/?w=" + query
}

// 上下文：用接口编排策略
type Rdict struct {
    source DictionarySource  // 运行时替换
}
```

## 符号速查

| 概念 | 语法 | 说明 |
|------|------|------|
| 接口定义 | `type Name interface { Method() }` | 定义一组方法签名 |
| 隐式实现 | 类型实现全部方法即可 | 无需 `implements` |
| 类型断言 | `x.(T)` | 提取接口的实际值 |
| 安全断言 | `x.(T), ok` | 失败不 panic |
| Type Switch | `switch x.(type)` | 按类型分支 |
| 空接口 | `interface{}` / `any` | 持有任意类型 |

## 相关笔记

- [[Go - Structs and Methods]] — 方法接收者类型
- [[Strategy Pattern]] — 接口在策略模式中的应用
- [[Tagged Union]] — 类型系统的另一种抽象方式
