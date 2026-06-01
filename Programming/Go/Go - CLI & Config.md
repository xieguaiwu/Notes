---
tags:
  - Go
  - ProgrammingLanguages
  - 方法性
title: "Go - CLI & Config"
created: 2026-06-02
modified: 2026-06-02
---

# Go - CLI & Config

> [!abstract] Go 生态通过 Cobra + Viper 组合提供从 CLI 命令构建到配置管理的完整方案。小项目可用标准库 `flag` 和 `os.Getenv`，复杂项目则引入 godotenv 加载 `.env` 文件、envconfig 做结构化绑定。

## 1. Cobra — 命令行框架

Cobra 是 Go 中最广泛使用的 CLI 框架（Kubernetes、Hugo、etcd 均基于它），提供命令、子命令和参数解析。

### 1.1 基本命令结构

```go
package cmd

import "github.com/spf13/cobra"

var rootCmd = &cobra.Command{
    Use:   "myapp",
    Short: "A brief description",
    Long:  "A longer description of your application.",
    Run: func(cmd *cobra.Command, args []string) {
        // 默认行为
    },
}

func Execute() {
    if err := rootCmd.Execute(); err != nil {
        os.Exit(1)
    }
}
```

### 1.2 子命令与持久化标志

```go
var (
    verbose bool
    config  string
)

func init() {
    // 持久化标志 — 对当前命令及所有子命令可见
    rootCmd.PersistentFlags().BoolVarP(&verbose, "verbose", "v", false, "verbose output")
    rootCmd.PersistentFlags().StringVar(&config, "config", "", "config file path")
}

var serveCmd = &cobra.Command{
    Use:   "serve",
    Short: "Start the server",
    Run: func(cmd *cobra.Command, args []string) {
        if verbose {
            log.Println("starting server...")
        }
        // ...
    },
}

func init() {
    rootCmd.AddCommand(serveCmd)
}
```

| 标志类型 | 方法 | 可见范围 |
|---------|------|---------|
| 持久化标志 | `PersistentFlags()` | 当前命令 + 所有子命令 |
| 本地标志 | `Flags()` | 仅当前命令 |

## 2. 标准库 flag — 简单 CLI

对于单文件工具或简单脚本，标准库 `flag` 足够且无外部依赖：

```go
package main

import (
    "flag"
    "fmt"
)

func main() {
    port := flag.Int("port", 8080, "server port")
    debug := flag.Bool("debug", false, "enable debug mode")
    flag.Parse()

    fmt.Printf("Starting on port %d, debug=%v\n", *port, *debug)
}
```

## 3. Viper — 配置管理

Viper 支持 JSON、TOML、YAML、HCL 等格式，从文件、环境变量、远程配置中心等多个来源读取，统一合并。

### 3.1 多来源加载与优先级

```go
import "github.com/spf13/viper"

func initConfig() {
    viper.SetConfigName("config")   // 文件名（不含扩展名）
    viper.SetConfigType("yaml")     // 如果文件名不含扩展名则指定
    viper.AddConfigPath(".")        // 搜索路径（可多次调用）
    viper.AddConfigPath("$HOME/.myapp")

    // 绑定环境变量
    viper.SetEnvPrefix("MYAPP")
    viper.AutomaticEnv()            // MYAPP_PORT → port

    // 读取配置
    if err := viper.ReadInConfig(); err != nil {
        if _, ok := err.(viper.ConfigFileNotFoundError); !ok {
            panic(fmt.Errorf("fatal error config file: %w", err))
        }
    }
}

func main() {
    initConfig()
    port := viper.GetInt("server.port")  // 嵌套键用 . 分隔
}
```

### 3.2 优先级顺序

```
命令行标志 > 环境变量 > 配置文件 > 默认值
```

```go
// 绑定 Cobra 标志到 Viper
viper.BindPFlag("verbose", rootCmd.PersistentFlags().Lookup("verbose"))

// 设置默认值
viper.SetDefault("server.port", 8080)
```

### 3.3 远程配置

```go
// 从 etcd 或 Consul 读取
viper.AddRemoteProvider("etcd", "http://127.0.0.1:4001", "/config/myapp.json")
viper.SetConfigType("json")
viper.ReadRemoteConfig()
```

## 4. godotenv — .env 文件加载

用于开发环境从 `.env` 文件加载环境变量，模拟生产环境的 12-Factor App 模式：

```go
import "github.com/joho/godotenv"

func main() {
    // 开发环境加载 .env
    if err := godotenv.Load(); err != nil {
        log.Println("No .env file found, using system env")
    }

    port := os.Getenv("PORT")
    dbURL := os.Getenv("DATABASE_URL")
}
```

```env
# .env
PORT=8080
DATABASE_URL=postgres://user:pass@localhost/db
```

## 5. envconfig — 环境变量结构化绑定

将环境变量直接映射到结构体字段，减少样板代码：

```go
import "github.com/kelseyhightower/envconfig"

type Config struct {
    Port     int    `envconfig:"PORT" default:"8080"`
    Debug    bool   `envconfig:"DEBUG" default:"false"`
    DBHost   string `envconfig:"DB_HOST" required:"true"`
}

func main() {
    var cfg Config
    if err := envconfig.Process("myapp", &cfg); err != nil {
        log.Fatal(err)
    }
    // cfg.Port = 8080, cfg.Debug = false, cfg.DBHost = ...
}
```

## 6. 配置方案对比

| 方案 | 文件类型 | 环境变量覆盖 | 远程配置 | 适用场景 |
|------|---------|-------------|---------|---------|
| `flag` 标准库 | 无 | 无 | 无 | 简单 CLI 工具 |
| `os.Getenv` + 手工解析 | 无 | ✅ | 无 | 少量配置项 |
| `godotenv` | `.env` | ✅ | 无 | 本地开发 |
| `envconfig` | 无 | ✅ | 无 | 12-Factor App |
| `viper` | JSON/YAML/TOML/HCL | ✅ | ✅ (etcd/Consul) | 复杂应用 |
| `viper` + `cobra` | JSON/YAML/TOML/HCL | ✅ | ✅ | 生产级 CLI 工具 |

## 符号速查

| 概念 | 语法/方法 | 说明 |
|------|----------|------|
| Cobra 命令 | `cobra.Command{Use, Run}` | 定义命令入口 |
| 持久化标志 | `PersistentFlags().StringVar()` | 对子命令也可见 |
| Cobra 绑定 Viper | `viper.BindPFlag("key", flag)` | 标志值同步到配置 |
| Viper 读配置 | `viper.ReadInConfig()` | 从搜索路径加载 |
| Viper 取值 | `viper.GetString("a.b.c")` | 嵌套键用 `.` 分隔 |
| Viper 环境变量 | `AutomaticEnv()` + `SetEnvPrefix()` | `MYAPP_PORT` → `port` |
| godotenv 加载 | `godotenv.Load()` | 读取 `.env` 到 `os.Getenv` |
| envconfig 绑定 | `envconfig.Process("prefix", &cfg)` | 结构体标签映射 |
| flag 解析 | `flag.Parse()` | 标准库 CLI 参数 |

## 相关笔记

- [[Go - Web Frameworks]] — HTTP 服务与 CLI 的集成模式
- [[Go - Logging]] — 日志库与配置注入
- [[Go - Error Handling and Defer]] — CLI 中的错误处理与资源管理
