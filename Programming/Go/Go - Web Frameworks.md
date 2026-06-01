---
tags:
  - Go
  - ProgrammingLanguages
  - 方法性
  - 基本原理
title: "Go - Web Frameworks"
created: 2026-06-02
modified: 2026-06-02
---

# Go - Web Frameworks

> [!abstract] Go 生态拥有从极简到全功能的 Web 框架。标准库 `net/http` 足以构建生产级服务，而 Gin、Echo、Fiber、Chi 等第三方框架在路由性能、中间件生态和开发效率上提供增强。选择框架的核心权衡在于：依赖成本 vs 开发效率。

## 1. net/http（标准库）

Go 标准库自带的 HTTP 包，无需任何第三方依赖。

```go
package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/hello", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hello, %s!", r.URL.Query().Get("name"))
	})

	http.ListenAndServe(":8080", nil)
}
```

> [!note] Go 1.22+ 增强了 `ServeMux`，支持方法路由（`GET /users/{id}`）和路径参数，大幅缩小了与第三方路由器的差距。

| 特性 | 说明 |
|------|------|
| 零依赖 | 标准库内置，编译快 |
| 接口设计 | `http.Handler` 和 `http.HandlerFunc` 是通用抽象 |
| 中间件 | 通过 `func(http.Handler) http.Handler` 函数签名实现 |
| 适合场景 | 微服务、API、对依赖敏感的项目 |

## 2. Gin

Gin 是目前 Star 数最高的 Go Web 框架，以高性能和简洁 API 著称。底层使用定制的 httprouter。

```go
package main

import (
	"net/http"
	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.GET("/hello/:name", func(c *gin.Context) {
		name := c.Param("name")
		c.JSON(http.StatusOK, gin.H{"message": "Hello, " + name})
	})
	r.Run(":8080")
}
```

| 特性 | 说明 |
|------|------|
| 路由 | 基于 Radix Tree（httprouter），零内存分配 |
| 中间件 | 内置 Logger、Recovery；`Use()` 注册中间件 |
| 数据绑定 | 支持 JSON/XML/Form 的自动绑定与验证 |
| 错误管理 | 集中式 `c.Error()` 收集 handler 中的错误 |
| 适合场景 | RESTful API、高并发服务、需要快速原型的项目 |

## 3. Echo

Echo 是一个高性能、极简的框架，专注于 HTTP 语义的正确性和 API 的直观性。

```go
package main

import (
	"net/http"
	"github.com/labstack/echo/v4"
)

func main() {
	e := echo.New()
	e.GET("/hello/:name", func(c echo.Context) error {
		name := c.Param("name")
		return c.JSON(http.StatusOK, map[string]string{
			"message": "Hello, " + name,
		})
	})
	e.Start(":8080")
}
```

| 特性 | 说明 |
|------|------|
| 路由 | 高性能 Radix Tree，支持分组和路由命名 |
| 中间件 | 丰富的内置中间件（CORS、JWT、CSRF 等） |
| 数据绑定 | 基于 struct tag 的自动绑定和验证 |
| Context | 自定义 `echo.Context`，返回 `error` 而非裸写响应 |
| 适合场景 | REST API、需要充足内置中间件的项目 |

> [!tip] Echo vs Gin
> Echo 的 Context 和中间件接口使用 `error` 返回值传递错误，风格更接近标准库的 `HandlerFunc` 签名。Gin 使用链条式 `c.Next()` 和 `c.Abort()` 控制流。

## 4. Fiber

Fiber 受 Express.js 启发，构建在 fasthttp 之上，追求极致性能。API 设计与 Express 高度相似。

```go
package main

import "github.com/gofiber/fiber/v3"

func main() {
	app := fiber.New()
	app.Get("/hello/:name", func(c fiber.Ctx) error {
		name := c.Params("name")
		return c.JSON(fiber.Map{"message": "Hello, " + name})
	})
	app.Listen(":8080")
}
```

| 特性 | 说明 |
|------|------|
| 底层引擎 | fasthttp（非标准 `net/http`），零内存分配的 HTTP 解析 |
| 中间件 | Express 风格，丰富的官方中间件库 |
| 路由 | Radix Tree，支持分组、参数和通配符 |
| 兼容性 | **不兼容** `net/http` 标准的 Handler 接口 |
| 适合场景 | 对延迟极度敏感的高并发服务、快速原型 |

> [!warning] fasthttp 兼容性
> Fiber 基于 fasthttp，无法直接使用依赖 `http.Handler` 的第三方中间件或库。如果项目需要与标准库生态深度集成，慎用。

## 5. Chi

Chi 是一个轻量、组合式、与标准库 100% 兼容的路由器。设计哲学是 "只做路由，不多不少"。

```go
package main

import (
	"net/http"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

func main() {
	r := chi.NewRouter()
	r.Use(middleware.Logger)
	r.Get("/hello/{name}", func(w http.ResponseWriter, r *http.Request) {
		name := chi.URLParam(r, "name")
		w.Write([]byte("Hello, " + name))
	})
	http.ListenAndServe(":8080", r)
}
```

| 特性 | 说明 |
|------|------|
| 标准库兼容 | 直接实现 `http.Handler`，可搭配任何标准库中间件 |
| 中间件 | 官方 `middleware` 包提供 Logger、Recover、Timeout 等常用组件 |
| 路由 | Radix Tree，支持分组嵌套、路径参数、正则匹配 |
| 设计哲学 | 组合优于继承；每个功能是独立的中间件 |
| 适合场景 | 需要标准库兼容性、轻路由、中间件灵活组合的项目 |

> [!note] Chi 与标准库的差异
> Chi 本质上是一个增强版的路由器 + 中间件管理器。除路由外，其他功能（模板渲染、数据绑定、验证等）由标准库或独立库提供。

## 6. 框架对比

| 维度 | net/http | Gin | Echo | Fiber | Chi |
|------|----------|-----|------|-------|-----|
| 依赖数量 | 0 | ~10 | ~5 | ~5 | ~5 |
| 路由性能 | 中等 | 高 | 高 | 极高 | 高 |
| 中间件模型 | Handler 包装 | `Use()` + `c.Next()` | `Use()` + `return error` | Express 风格 `Use()` | Handler 包装 |
| 标准库兼容 | 原生 | `http.HandlerFunc` 适配 | `http.HandlerFunc` 适配 | 不兼容 | 100% 兼容 |
| 社区规模 | Go 内置 | 最大（75k+ Stars） | 大（30k+ Stars） | 大（35k+ Stars） | 中等（20k Stars） |
| 文档质量 | Go 官方文档 | 优秀 | 优秀 | 良好 | 良好 |
| 学习曲线 | 平坦 | 中等 | 中等 | 低（类 Express） | 平坦 |
| 何时选择 | 微服务、少依赖 | RESTful API、快速原型 | REST API、复杂中间件 | 高性能需求、类 Express 风格 | 标准库生态、轻路由 |

## 7. 中间件模式

Go Web 框架的中间件本质都是函数包装。核心模式分两种：

### 7.1 标准库 / Chi 模式

```go
// 中间件签名
func(next http.Handler) http.Handler

// 示例：请求计时
func Timer(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		start := time.Now()
		next.ServeHTTP(w, r)
		log.Printf("request took %v", time.Since(start))
	})
}

// 使用
r := chi.NewRouter()
r.Use(Timer)
```

### 7.2 Gin / Echo 模式

Gin 和 Echo 使用自定义的 Context，在中间件内部通过调用 `c.Next()` 或 `return` 来控制执行流：

```go
// Gin 中间件
func Timer() gin.HandlerFunc {
	return func(c *gin.Context) {
		start := time.Now()
		c.Next() // 执行下一个 handler
		log.Printf("request took %v", time.Since(start))
	}
}

// Echo 中间件
func Timer(next echo.HandlerFunc) echo.HandlerFunc {
	return func(c echo.Context) error {
		start := time.Now()
		err := next(c)
		log.Printf("request took %v", time.Since(start))
		return err
	}
}
```

| 模式 | 代表 | 流程控制 | 兼容性 |
|------|------|---------|--------|
| `func(http.Handler) http.Handler` | net/http, Chi | 隐式链式调用 | 标准库生态通用 |
| 自定义 Context + Next() | Gin | `c.Next()` 显式控制 | 框架专属 |
| 自定义 Context + error | Echo | `return next(c)` 传控制 | 框架专属 |
| Express 风格 | Fiber | `c.Next()` + `return error` | 框架专属 |

每种模式最终都在执行 `next()` 或类似调用，区别在于框架是否暴露这个调用点让开发者自行决定执行的时机（如度量前/后）。

## 符号速查

| 概念 | Gin | Echo | Fiber | Chi | net/http |
|------|-----|------|-------|-----|----------|
| 创建实例 | `gin.Default()` | `echo.New()` | `fiber.New()` | `chi.NewRouter()` | `http.NewServeMux()` |
| 注册路由 | `r.GET("/p", h)` | `e.GET("/p", h)` | `app.Get("/p", h)` | `r.Get("/p", h)` | `mux.HandleFunc("/p", h)` |
| 路径参数 | `c.Param("id")` | `c.Param("id")` | `c.Params("id")` | `chi.URLParam(r, "id")` | `r.PathValue("id")` \* |
| JSON 响应 | `c.JSON(200, v)` | `c.JSON(200, v)` | `c.JSON(v)` | 手动 `json.Marshal` | 手动 `json.Marshal` |
| 中间件注册 | `r.Use(m)` | `e.Use(m)` | `app.Use(m)` | `r.Use(m)` | 包装 Handler |
| 启动服务 | `r.Run(":8080")` | `e.Start(":8080")` | `app.Listen(":8080")` | 标准 `http.ListenAndServe` | 标准 `http.ListenAndServe` |

> \* Go 1.22+ `ServeMux` 才支持 `PathValue`

## 相关笔记

- [[Go - CLI & Config]] — 命令行工具与配置文件管理
- [[Go - Database Access]] — 数据库连接与查询
- [[Go - Logging]] — 日志记录与中间件集成
- [[Go - Interfaces]] — `http.Handler` 接口的设计原理
- [[Go - Error Handling and Defer]] — handler 中的错误处理模式
