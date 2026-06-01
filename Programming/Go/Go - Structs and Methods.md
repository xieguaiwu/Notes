---
tags:
  - Go
  - ProgrammingLanguages
  - 定义性
  - 基本原理
title: "Go - Structs and Methods"
created: 2026-06-01
modified: 2026-06-01
---

# Go - Structs and Methods

> [!abstract] Go 使用结构体（struct）组织数据，通过方法（method）定义行为。Go 没有类继承，而是通过结构体嵌入实现组合复用。

## 1. 结构体定义

```go
type Person struct {
    Name string
    Age  int
    Email string
}
```

### 1.1 初始化方式

```go
// 按字段顺序（不推荐）
p1 := Person{"Alice", 30, "alice@example.com"}

// 按字段名（推荐）
p2 := Person{
    Name: "Bob",
    Age:  25,
}

// 零值初始化
var p3 Person   // Name="", Age=0, Email=""
```

## 2. 方法定义

方法是为特定类型定义的函数，接收者（receiver）位于 `func` 关键字和方法名之间。

### 2.1 值接收者

```go
func (p Person) Greet() string {
    return "Hello, I'm " + p.Name
}
// 调用: p.Greet()
// 不修改原对象
```

### 2.2 指针接收者

```go
func (p *Person) SetAge(age int) {
    p.Age = age  // 直接修改原对象
}
// 调用: p.SetAge(31)
```

| 接收者类型 | 能否修改原对象 | 适用场景 |
|-----------|--------------|---------|
| **值接收者** `(p T)` | ❌ 不能 | 只读方法、小型不可变类型 |
| **指针接收者** `(p *T)` | ✅ 能 | 需要修改、大型结构体（避免拷贝） |

> [!tip] 一致性原则
> 同一个类型的方法应统一使用值接收者或指针接收者——不要混用。

### 2.3 方法与函数的区别

```go
// 函数
func Greet(p Person) string {
    return "Hello, " + p.Name
}

// 方法
func (p Person) Greet() string {
    return "Hello, " + p.Name
}
```

方法只是语法糖——本质上等同于第一个参数为接收者的函数。但方法允许接口匹配，而函数不能。

## 3. 结构体嵌入

Go 没有继承，但可以通过嵌入实现组合复用。

```go
type Address struct {
    City    string
    Country string
}

type Person struct {
    Name    string
    Address          // 嵌入（匿名字段）
}
```

### 3.1 字段提升

嵌入结构体的字段和方法会被"提升"到外层：

```go
p := Person{
    Name: "Alice",
    Address: Address{City: "Shanghai", Country: "China"},
}

p.City       // 提升字段，等价于 p.Address.City
p.Country    // 提升字段
```

### 3.2 方法提升

嵌入结构体的方法也会被提升：

```go
func (a Address) Full() string {
    return a.City + ", " + a.Country
}

p.Full()     // 提升方法，等价于 p.Address.Full()
```

### 3.3 嵌入 vs 接口实现

嵌入可以"组合"出满足接口的类型：

```go
type Greeter interface {
    Greet() string
}

// 假设 Address 有 Greet() 方法
// Person 嵌入了 Address，所以 Person 也满足 Greeter
```

## 4. 方法集

方法集（Method Set）决定类型是否满足接口：

| 类型 | 方法集 |
|------|--------|
| `T` | 所有 `T` 的值接收者方法 |
| `*T` | 所有 `T` 的值接收者 + 指针接收者方法 |

> [!warning] 方法集陷阱
> 值类型 `T` 的变量只能调用值接收者方法，无法调用指针接收者方法。但可寻址的值（如变量）可以自动取地址调用指针接收者方法。

```go
var p Person
p.SetAge(31)    // OK: 编译器自动转为 (&p).SetAge(31)

Person{}.SetAge(31) // 编译错误: 不可寻址
```

## 5. 常见模式

### 5.1 构造函数

```go
func NewPerson(name string, age int) *Person {
    return &Person{
        Name: name,
        Age:  age,
    }
}
```

> [!note] Go 没有构造函数语法，习惯上用 `NewXxx` 函数替代。

### 5.2 builder 模式

```go
type Config struct {
    Host string
    Port int
}

type ConfigBuilder struct {
    config Config
}

func (b *ConfigBuilder) Host(host string) *ConfigBuilder {
    b.config.Host = host
    return b  // 返回自身以支持链式调用
}

func (b *ConfigBuilder) Port(port int) *ConfigBuilder {
    b.config.Port = port
    return b
}

func (b *ConfigBuilder) Build() Config {
    return b.config
}
```

## 符号速查

| 概念 | 语法 | 说明 |
|------|------|------|
| 结构体 | `type T struct { F type }` | 数据聚合 |
| 值接收者 | `func (t T) M()` | 只读 |
| 指针接收者 | `func (t *T) M()` | 可修改 |
| 嵌入 | `type T struct { Other }` | 组合复用 |
| 方法集 | `T` 或 `*T` 的方法集合 | 决定接口满足 |

## 相关笔记

- [[Go - Interfaces]] — 接口与多态
- [[Go - Error Handling and Defer]] — 错误处理与资源管理
