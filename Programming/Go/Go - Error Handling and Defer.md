---
tags:
  - Go
  - ProgrammingLanguages
  - 方法性
  - 基本原理
title: "Go - Error Handling and Defer"
created: 2026-06-01
modified: 2026-06-01
---

# Go - Error Handling and Defer

> [!abstract] Go 通过 `error` 接口值而非异常进行错误处理，配合 `defer` 实现资源管理。这种设计使控制流显式化，避免隐式异常传播。

## 1. error 接口

```go
type error interface {
    Error() string
}
```

`error` 是 Go 内置接口，任何实现了 `Error() string` 方法的类型都可以作为错误值。

### 1.1 基本用法

```go
func divide(a, b int) (int, error) {
    if b == 0 {
        return 0, fmt.Errorf("division by zero")
    }
    return a / b, nil
}

result, err := divide(10, 0)
if err != nil {
    fmt.Println("Error:", err)
    return
}
```

> [!note] 习惯做法
> Go 中函数返回多个值时，`error` 通常是最后一个返回值。调用后立即检查 `err != nil` 是标准模式。

## 2. 自定义错误类型

```go
// 简单自定义
type NotFoundError struct {
    Query string
}

func (e *NotFoundError) Error() string {
    return "not found: " + e.Query
}

// 带额外信息的错误
type HttpError struct {
    StatusCode int
    Message    string
}

func (e *HttpError) Error() string {
    return fmt.Sprintf("HTTP %d: %s", e.StatusCode, e.Message)
}
```

### 2.1 错误类型检查

```go
result, err := search(query)
if err != nil {
    var notFound *NotFoundError
    if errors.As(err, &notFound) {
        // 处理未找到错误
        fmt.Printf("Query '%s' not found\n", notFound.Query)
    } else {
        // 其他类型错误
        fmt.Println("Error:", err)
    }
}

// 使用 errors.Is 检查特定错误值
var ErrNoResults = fmt.Errorf("no translation results")
if errors.Is(err, ErrNoResults) {
    // 处理无结果的情况
}
```

## 3. 错误包装

```go
// 使用 %w 包装错误
func fetchData() error {
    err := http.Get("https://api.example.com/data")
    if err != nil {
        return fmt.Errorf("fetch failed: %w", err)
    }
    return nil
}

// 解包
err := fetchData()
if err != nil {
    fmt.Println(err)                    // "fetch failed: ..."
    fmt.Println(errors.Unwrap(err))     // 原始错误
    fmt.Println(errors.Is(err, someSentinel)) // 链式检查
}
```

### 3.1 合并多个错误

```go
err1 := fmt.Errorf("first error")
err2 := fmt.Errorf("second error")
combined := errors.Join(err1, err2)
// combined.Error() → "first error\nsecond error"
```

## 4. defer

`defer` 用于延迟函数调用，在包含它的函数返回前执行。常用于资源释放。

### 4.1 基本用法

```go
func readFile(path string) ([]byte, error) {
    f, err := os.Open(path)
    if err != nil {
        return nil, err
    }
    defer f.Close()  // 函数返回时自动关闭

    return io.ReadAll(f)
}
```

### 4.2 LIFO 执行顺序

多个 `defer` 按后进先出（LIFO）顺序执行：

```go
func example() {
    defer fmt.Println("first deferred")
    defer fmt.Println("second deferred")
    defer fmt.Println("third deferred")
}
// 输出:
// third deferred
// second deferred
// first deferred
```

### 4.3 defer 与返回值

```go
func count() (n int) {
    defer func() { n++ }()  // 可以修改命名返回值
    return 1
}
// count() 返回 2
```

| 特性 | 说明 |
|------|------|
| 执行时机 | 函数 return 之后，返回值返回给调用者之前 |
| 参数求值 | 参数在 defer 声明时立即求值，而非执行时 |
| 命名返回值 | defer 可以读取和修改命名返回值 |

### 4.4 常见用途

```go
// 1. 关闭资源
f, _ := os.Open("file.txt")
defer f.Close()

// 2. 解锁
mu.Lock()
defer mu.Unlock()

// 3. 记录函数耗时
func slowFunc() {
    defer func(start time.Time) {
        log.Printf("slowFunc took %v", time.Since(start))
    }(time.Now())
    // ...
}

// 4. 恢复 panic
defer func() {
    if r := recover(); r != nil {
        log.Printf("recovered from panic: %v", r)
    }
}()
```

## 5. 最佳实践

| 原则 | 说明 |
|------|------|
| **始终检查错误** | `if err != nil` 不应该被省略 |
| **错误尽早返回** | 避免深层嵌套的 if-else |
| **defer 越早越好** | 获取资源后立即 defer 释放 |
| **错误包含上下文** | 用 `%w` 包装，提供额外的信息 |
| **区分错误值 vs 错误类型** | `errors.Is` 检查值，`errors.As` 检查类型 |

## 相关笔记

- [[Go - Interfaces]] — error 接口的定义
- [[Go - Structs and Methods]] — 方法接收者与自定义错误类型
