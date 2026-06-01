---
tags:
  - ComputerScience
  - Go
  - 方法性
  - 基本原理
title: "Config File Management"
created: 2026-06-01
modified: 2026-06-01
---

# Config File Management

> [!abstract] 合理的配置文件管理涉及格式选择、存储位置规范、优先级策略和原子写入。结合 XDG 规范和 NO_COLOR 环境变量约定，提供统一且可预测的用户体验。

## 1. 配置文件格式

| 格式 | 优点 | Go 支持 |
|------|------|---------|
| **JSON** | 标准库支持，广泛使用 | `encoding/json` |
| **TOML** | 可读性好，支持注释 | 第三方库 |
| **YAML** | 最简洁 | 第三方库 |

> [!note] bl 选择 JSON
> JSON 是 Go 标准库原生支持的格式，无需额外依赖。配置结构简单时 JSON 足够。

## 2. XDG 规范

XDG Base Directory 规范定义了配置文件的存储位置：

```
~/.config/{app}/      → 配置文件
~/.cache/{app}/       → 缓存文件
~/.local/share/{app}/ → 数据文件
```

```go
import "os"

func configDir() string {
    if dir := os.Getenv("XDG_CONFIG_HOME"); dir != "" {
        return filepath.Join(dir, "bl")
    }
    return filepath.Join(os.Getenv("HOME"), ".config", "bl")
}
```

| 目录 | 用途 | 环境变量覆盖 |
|------|------|-------------|
| `~/.config/bl/` | 配置文件 | `XDG_CONFIG_HOME` |
| `~/.cache/bl/` | 缓存数据 | `XDG_CACHE_HOME` |
| `~/.local/share/bl/` | 数据文件 | `XDG_DATA_HOME` |

## 3. 配置优先级

```
CLI 标志 > 环境变量 > 配置文件 > 默认值
```

```go
// 从最高优先级到最低优先级读取配置
type Config struct {
    Source  string
    NoCache bool
    JSON    bool
}

func LoadConfig() Config {
    cfg := defaultConfig()           // 1. 默认值

    if v := os.Getenv("BL_SOURCE"); v != "" {
        cfg.Source = v               // 2. 环境变量覆盖
    }

    if v := os.Getenv("BL_NO_CACHE"); v != "" {
        cfg.NoCache = true
    }

    // 3. 配置文件覆盖
    if data, err := os.ReadFile(configPath()); err == nil {
        json.Unmarshal(data, &cfg)
    }

    // 4. CLI 标志最高优先级（在 main 中处理）
    return cfg
}
```

## 4. 原子写入

避免写入过程中程序崩溃导致配置文件损坏：

```go
func writeConfig(cfg *Config) error {
    data, err := json.MarshalIndent(cfg, "", "  ")
    if err != nil {
        return err
    }

    // 确保目录存在
    if err := os.MkdirAll(configDir(), 0755); err != nil {
        return err
    }

    // 原子写入
    path := filepath.Join(configDir(), "config.json")
    return os.WriteFile(path, data, 0644)
}
```

## 5. NO_COLOR 与终端检测

### 5.1 NO_COLOR 标准

遵循 [no-color.org](https://no-color.org) 社区标准：如果设置了 `NO_COLOR` 环境变量（无论值是什么），程序不应输出 ANSI 颜色码。

```go
func shouldUseColor() bool {
    if os.Getenv("NO_COLOR") != "" {
        return false          // NO_COLOR 设置后禁止颜色
    }
    if os.Getenv("TERM") == "dumb" {
        return false          // 无能力终端
    }
    if !isTerminal(os.Stdout) {
        return false          // 管道/重定向
    }
    return true
}

func isTerminal(f *os.File) bool {
    fi, _ := f.Stat()
    return (fi.Mode() & os.ModeCharDevice) != 0
}
```

### 5.2 终端检测方法

| 检测项 | 条件 | 说明 |
|--------|------|------|
| `NO_COLOR` | 环境变量不为空 | 用户显式禁用 |
| `TERM=dumb` | 环境变量 | 终端无能力 |
| `os.Stdout` 非字符设备 | `ModeCharDevice` 位 | 输出重定向到文件/管道 |

## 相关笔记

- [[Go Compilation and Deployment]] — 构建和部署配置
- [[Go - Error Handling and Defer]] — 文件操作中的错误处理
