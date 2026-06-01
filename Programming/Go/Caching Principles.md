---
tags:
  - ComputerScience
  - Go
  - 基本原理
  - 方法性
title: "Caching Principles"
created: 2026-06-01
modified: 2026-06-01
---

# Caching Principles

> [!abstract] 缓存是计算机科学中解决速度差异的核心手段——将慢速操作的结杲暂存在快速存储中，避免重复开销。

## 1. 为何需要缓存

| 存储层级 | 延迟量级 | 与 L1 缓存的差距 |
|---------|---------|----------------|
| L1 缓存 | ~1ns | 1× |
| 内存 (RAM) | ~100ns | 100× |
| SSD | ~10μs | 10,000× |
| 网络请求 | ~100ms | 100,000,000× |

### 1.1 在词典应用中的体现

```
内存映射文件  →  SQLite 缓存  →  HTTP 在线查询
（微秒级）       （毫秒级）       （百毫秒级）
```

- **重复查询**：用户反复查同一个词时避免重复网络请求
- **降级支持**：无网络环境下仍能返回缓存结果

## 2. 缓存键设计

```go
// 键设计：{来源}:{查询文本}
cacheKey := fmt.Sprintf("%s:%s", sourceName, queryText)
```

| 设计原则 | 说明 |
|---------|------|
| **隔离性** | 不同来源的同一词不冲突（youdao:hello ≠ woerter-net:Haus） |
| **确定性** | 相同的输入始终生成相同的缓存键 |
| **可读性** | 键应能从内容推导，便于调试 |

## 3. 缓存策略

### 3.1 Cache-Aside（旁路缓存）

最常用的策略，流程如下：

```
请求数据
  → 查缓存（命中 → 返回）
  → 未命中 → 查数据源
  → 回填缓存
  → 返回
```

```go
func getResult(key string) (*Result, error) {
    // 1. 先查缓存
    if cached, ok := cache.Get(key); ok {
        return cached, nil
    }
    // 2. 未命中，查数据源
    result, err := fetchFromSource(key)
    if err != nil {
        return nil, err
    }
    // 3. 回填缓存
    cache.Set(key, result)
    return result, nil
}
```

### 3.2 Write-Through（写穿透）

写入数据源时同步写入缓存：`写操作 → 写缓存 → 写数据源`，保证缓存和数据源一致。

## 4. 缓存穿透

当查询的数据**不存在**时，每次查询都会穿透到数据源。

### 防御方式

```go
// 1. 缓存空值（短 TTL）
cache.Set(key, emptyResult, time.Minute)

// 2. 布隆过滤器（Bloom Filter）
// 快速判断 key 是否"可能存在"
if !bloomFilter.MightContain(key) {
    return nil // 肯定不存在，直接返回
}
```

| 方式 | 优点 | 缺点 |
|------|------|------|
| 缓存空值 | 实现简单 | 占用空间 |
| 布隆过滤器 | 空间效率高 | 有误判率（False Positive） |

## 5. 缓存一致性

| 数据特性 | 缓存策略 |
|---------|---------|
| **不可变数据**（如离线词典） | 无需失效，可永久缓存 |
| **业务数据** | 数据源更新后，缓存需失效或更新 |

> [!tip] bl 项目的特点
> 词典查询中查询结果不随时间变化（"apple"的翻译不会变），因此无缓存一致性问题。

## 6. 缓存在 bl 项目中的位置

```
离线词典（最快，微秒级）
  → SQLite 缓存（次快，毫秒级）
    → HTTP 在线（最慢，百毫秒级）
```

查询链中每层都在向上层提供"缓存"服务——离线词典是文件级缓存，SQLite 是磁盘级缓存。

## 相关笔记

- [[SQLite]] — bl 项目中缓存层的实现基础
- [[Query Chain Pattern]] — 缓存作为查询链中的一环
- [[Unified Data Flow Design]] — 缓存操作的统一数据模型
