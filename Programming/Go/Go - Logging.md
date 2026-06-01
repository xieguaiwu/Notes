---
tags:
  - Go
  - ProgrammingLanguages
  - 方法性
  - 基本原理
title: "Go - Logging"
created: 2026-06-02
modified: 2026-06-02
---

# Go - Logging

> [!abstract] Go 生态中的结构化日志库围绕三个核心需求展开：性能（零分配/低分配）、结构化输出（JSON）、以及开发者体验。`log/slog` 在 1.21 成为标准库答案，而 Zap 和 Zerolog 在极致性能场景仍是首选。

## 1. slog (Go 1.21+ 标准库)

`slog` 是 Go 1.21 引入的结构化日志包，借鉴了 Zap 和 Zerolog 的设计经验，采用 key-value 对记录结构化字段。

### 1.1 基本用法

```go
logger := slog.New(slog.NewJSONHandler(os.Stderr, nil))
slog.SetDefault(logger)

slog.Info("request processed",
    "method", "GET",
    "path", "/api/users",
    "status", 200,
    "duration_ms", 12,
)
```

### 1.2 结构化分组

```go
logger.LogAttrs(context.Background(), slog.LevelInfo, "order created",
    slog.Int("order_id", 1234),
    slog.String("customer", "alice"),
    slog.Group("items",
        slog.String("sku", "AB-991"),
        slog.Int("qty", 2),
    ),
)
```

### 1.3 Handler 选项

```go
h := slog.NewJSONHandler(os.Stderr, &slog.HandlerOptions{
    Level:     slog.LevelDebug,
    AddSource: true,
})
// 也支持 slog.NewTextHandler 输出人类可读格式
```

> [!note] slog 的 `LogAttrs` 比 `Info(msg, key1, val1, ...)` 更高效，因为避免了 key-value 对中的类型推断开销。

## 2. Zap (Uber)

Zap 是 Uber 开源的高性能日志库，核心设计是避免 `reflect` 和内存分配。提供两种 API：`Logger`（高性能、强类型）和 `SugaredLogger`（易用、稍慢）。

### 2.1 Production Logger

```go
import "go.uber.org/zap"

logger, _ := zap.NewProduction()
defer logger.Sync()

logger.Info("server started",
    zap.String("addr", ":8080"),
    zap.Int("max_conn", 1000),
    zap.Duration("timeout", time.Second*30),
)
```

### 2.2 Sugared Logger（开发友好）

```go
sugar := logger.Sugar()
sugar.Infow("user login",
    "user_id", 42,
    "source", "web",
)
```

### 2.3 Development vs Production

| 配置 | JSON | 堆栈跟踪 | 日志级别 | 适用场景 |
|------|------|---------|---------|---------|
| `NewProduction()` | 是 | Error 及以上 | Info+ | 生产环境 |
| `NewDevelopment()` | 否 | Warn 及以上 | Debug+ | 开发调试 |
| `NewExample()` | 否 | 否 | 全部 | 测试/示例 |

## 3. Zerolog

Zerolog 以零分配为目标，提供流式（fluent）API，默认输出 JSON。

```go
import "github.com/rs/zerolog/log"

func main() {
    zerolog.TimeFieldFormat = zerolog.TimeFormatUnix

    log.Info().
        Str("service", "api-gw").
        Int("port", 443).
        Msg("gateway started")

    // 子 logger 带固定字段
    rlog := log.With().Str("component", "ratelimiter").Logger()
    rlog.Warn().Int("remaining", 5).Msg("quota low")
}
```

### 3.1 性能特点

Zerolog 的 `Msg()` 调用才会真正执行写入，中间链式调用只构建事件。这使得分支内可避免不必要的字段构建。

## 4. Logrus

Logrus 是 Go 生态最早的流行结构化日志库之一，但作者已声明进入维护模式，不推荐新项目使用。

```go
import log "github.com/sirupsen/logrus"

func init() {
    log.SetFormatter(&log.JSONFormatter{})
    log.SetLevel(log.InfoLevel)
}

log.WithFields(log.Fields{
    "user_id": 1001,
    "action":  "purchase",
}).Info("checkout completed")
```

> [!warning] Logrus 使用 `log.Fields`（即 `map[string]interface{}`）作为结构化字段，每次日志调用都涉及 map 分配和反射，性能显著低于 Zap、Zerolog 和 slog。

## 5. 性能对比

以下为各库在一次结构化日志调用中的近似相对比较（基于公开 benchmark，具体数值随版本变化）：

| 库 | 每次分配次数 | 每次分配量 | 相对吞吐量 |
|----|-----------|---------|----------|
| **Zap** (Logger) | ~0 | ~0 B | 高 |
| **Zerolog** | ~0 | ~0 B | 高 |
| **slog** (with LogAttrs) | ~0-1 | ~0 B | 中-高 |
| **Zap** (Sugared) | ~2-4 | ~96-128 B | 中 |
| **slog** (key-value pair) | ~3-5 | ~128-256 B | 中 |
| **Logrus** | ~8-15 | ~500-1500 B | 低 |

> [!note] 对于绝大多数应用，slog 的性能已经足够。仅在每秒数十万条日志的高吞吐场景（如网络代理、消息队列）才需要 Zap/Zerolog 的零分配特性。

## 6. 日志最佳实践

| 实践 | 说明 |
|------|------|
| **适当级别** | Debug（开发）、Info（关键操作）、Warn（可恢复异常）、Error（需关注） |
| **结构化字段** | 用 `"user_id"` 而非 `"user 1001 login"` 内嵌信息 |
| **避免敏感数据** | 密码、Token 不应出现在日志中 |
| **延迟字符串求值** | 使用 `fmt.Sprintf` 前先判断日志级别是否启用 |
| **context 传播** | 传递 `context.Context` 以携带 trace ID 等元数据 |
| **日志采样** | 高频日志路径使用 `slog.NewJSONHandler` 或 Zap 的 `Sampler` 限制频率 |
| **库不设全局 Logger** | 库代码应接受 `*slog.Logger` / `*zap.Logger` 参数，不调用全局日志函数 |

## 符号速查

| 概念 | 语法/入口 | 说明 |
|------|----------|------|
| slog 初始化 | `slog.New(slog.NewJSONHandler(w, opts))` | 标准库结构化日志 |
| slog 属性 | `slog.Int("key", val)`, `slog.String(...)` | 类型安全的字段 |
| Zap Production | `zap.NewProduction()` | JSON 输出，Info+ 级别 |
| Zap Sugared | `logger.Sugar()` | 开发友好的 Infow/Infof |
| Zerolog | `log.Info().Str(...).Msg(...)` | 流式 API，Msg() 触发写入 |
| Logrus | `log.WithFields(log.Fields{...}).Info(...)` | 维护模式，不推荐新项目 |
| 字段分组 | `slog.Group("name", fields...)` | 嵌套 JSON 对象 |
| context 传播 | `slog.InfoContext(ctx, ...)` | 携带 trace 信息 |

## 相关笔记

- [[Go - Error Handling and Defer]] — 错误记录与资源释放的日志配合
- [[Go - Web Frameworks]] — HTTP 中间件中的日志集成
- [[Go - CLI & Config]] — 命令行工具中的日志级别配置
