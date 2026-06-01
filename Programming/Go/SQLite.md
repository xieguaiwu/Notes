---
tags:
  - ComputerScience
  - Database
  - Go
  - 基本原理
title: "SQLite"
created: 2026-06-01
modified: 2026-06-01
---

# SQLite

> [!abstract] SQLite 是嵌入式关系数据库，以文件形式存储整个数据库，零配置、零服务器进程。适合移动端/桌面应用的本地存储和缓存层。

## 1. 基本特征

| 特性 | 说明 |
|------|------|
| 架构 | 嵌入式（无独立服务器进程） |
| 存储 | 单个 `.db` 文件 |
| 配置 | 零配置 |
| 事务 | ACID 合规 |
| 体积 | 约 600KB |

## 2. PRAGMA 指令

SQLite 提供 `PRAGMA` 指令调整运行时行为：

```sql
-- WAL 模式：写入时不阻塞读取
PRAGMA journal_mode = WAL;

-- 禁用回滚日志（只读数据库时安全）
PRAGMA journal_mode = OFF;

-- 声明只读，SQLite 优化器跳过锁检查
PRAGMA query_only = 1;
```

| PRAGMA | 用途 | 适用场景 |
|--------|------|---------|
| `journal_mode = WAL` | 写不阻塞读 | 读多写少 |
| `journal_mode = OFF` | 无日志开销 | 只读数据库 |
| `query_only = 1` | 跳过锁检查 | 只读连接 |

## 3. 表结构优化

### 3.1 WITHOUT ROWID

```sql
-- 默认：隐式 rowid 列
CREATE TABLE entries (query TEXT PRIMARY KEY, data BLOB);

-- 优化：禁止隐式 rowid，节省每行约 8 字节
CREATE TABLE entries (query TEXT PRIMARY KEY, data BLOB) WITHOUT ROWID;
```

当主键本身就是自然键（如单词本身）时，`WITHOUT ROWID` 可以节省空间并提高查询效率。

### 3.2 TEXT vs INTEGER 主键

| 主键类型 | 适用场景 | 示例 |
|---------|---------|------|
| `INTEGER PRIMARY KEY` | 自增 ID | 用户表 |
| `TEXT PRIMARY KEY` | 自然键 | 单词查询缓存 |

## 4. CGO vs Pure-Go

| 维度 | `mattn/go-sqlite3` (CGO) | `modernc.org/sqlite` (Pure-Go) |
|------|-------------------------|-------------------------------|
| 实现 | C 语言 SQLite 的绑定 | C → Go transpile |
| 编译 | 需要 C 编译器 + SQLite 头文件 | 纯 Go 编译 |
| 交叉编译 | 困难（CGO 依赖） | 无障碍 |
| 性能 | 原生 C 性能 | 略低（~10-20%） |
| 二进制体积 | 较小 | 较大 |

> [!tip] Pure-Go 推荐
> 对于词典工具等需要交叉编译的场景，`modernc.org/sqlite` 是更好的选择。

## 5. 适用场景

| 适用 | 不适用 |
|------|--------|
| 读多写少的本地存储 | 高并发写入 |
| 移动端/桌面应用嵌入 | 分布式数据库 |
| 缓存层 | 大型数据集（>TB 级） |
| 配置存储 | 需要存储过程 |

### 5.1 在 bl 中的使用

```sql
-- 缓存表结构
CREATE TABLE IF NOT EXISTS cache_results (
    text TEXT PRIMARY KEY,
    data BLOB NOT NULL
) WITHOUT ROWID;

-- 写入缓存
INSERT OR REPLACE INTO cache_results (text, data)
VALUES (?, ?);

-- 查询缓存
SELECT data FROM cache_results WHERE text = ?;

-- 统计
SELECT COUNT(*) FROM cache_results;
```

## 6. 常用操作速查

| 操作 | SQL |
|------|-----|
| 创建表 | `CREATE TABLE IF NOT EXISTS ...` |
| 写入/更新 | `INSERT OR REPLACE INTO ... VALUES (?, ?)` |
| 查询 | `SELECT data FROM ... WHERE query = ?` |
| 删除 | `DELETE FROM ... WHERE query = ?` |
| 计数 | `SELECT COUNT(*) FROM ...` |
| 批量写入 | `BEGIN` → `INSERT` × N → `COMMIT` |

## 相关笔记

- [[Caching Principles]] — SQLite 作为缓存层的理论基础
- [[SQL Basics]] — SQL 语法基础
- [[Go Compilation and Deployment]] — Pure-Go 的意义
