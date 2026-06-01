---
tags:
  - Database
  - ComputerScience
  - 方法性
  - 基本原理
title: "SQL Basics"
created: 2026-06-01
modified: 2026-06-01
---

# SQL Basics

> [!abstract] SQL（Structured Query Language）是关系数据库的标准查询语言。本文覆盖缓存场景中最常用的 SQL 操作。

## 1. 常用语句

### 1.1 创建表

```sql
CREATE TABLE IF NOT EXISTS entries (
    query TEXT PRIMARY KEY,
    data  BLOB NOT NULL
) WITHOUT ROWID;
```

| 子句 | 说明 |
|------|------|
| `IF NOT EXISTS` | 表已存在时不报错 |
| `TEXT PRIMARY KEY` | 字符串作为主键 |
| `BLOB` | 二进制数据（如压缩后的 JSON） |
| `WITHOUT ROWID` | 省略隐式 rowid，节省空间 |

### 1.2 插入或替换

```sql
INSERT OR REPLACE INTO entries (query, data) VALUES (?, ?);
```

- 主键冲突时覆盖已有行
- 等价于：先 DELETE 再 INSERT

### 1.3 查询

```sql
SELECT data FROM entries WHERE query = ?;
```

### 1.4 统计

```sql
SELECT COUNT(*) FROM entries;  -- 总条目数
```

### 1.5 删除

```sql
DELETE FROM cache_results WHERE text = ?;
```

## 2. 参数化查询

```go
// ✅ 正确：使用 ? 占位符防止 SQL 注入
stmt, _ := db.Prepare("SELECT data FROM entries WHERE query = ?")
rows, _ := stmt.Query(inputText)

// ❌ 危险：字符串拼接可能被注入
// rows, _ := db.Query("SELECT data FROM entries WHERE query = '" + inputText + "'")
```

| 特性 | 说明 |
|------|------|
| 占位符 | SQLite 使用 `?`，PostgreSQL 用 `$1`, `$2` |
| 安全性 | 驱动自动转义参数值 |
| 性能 | 预编译语句可复用执行计划 |

### 2.1 动态表名

```go
// 表名不能参数化，需拼接（确保表名不来自用户输入）
tableName := "cache_results"
sql := fmt.Sprintf("SELECT data FROM %s WHERE query = ?", tableName)
```

> [!warning] 表名拼接的安全性
> 表名本身不能参数化，必须拼接。但应确保表名来自硬编码常量，而非用户输入。

## 3. 事务

批量写入时使用事务，大幅度提升性能（SQLite 中尤为明显）：

```go
tx, _ := db.Begin()
stmt, _ := tx.Prepare("INSERT OR REPLACE INTO entries (query, data) VALUES (?, ?)")

for _, entry := range entries {
    _, err := stmt.Exec(entry.Query, entry.Data)
    if err != nil {
        tx.Rollback()  // 任一步失败则回滚
        return err
    }
}

return tx.Commit()
```

| 操作 | 无事务 | 有事务 |
|------|--------|--------|
| 单条插入 | 每次自动提交 | 一次提交 |
| 1000 条插入 | ~1000 次磁盘写入 | ~1 次磁盘写入 |
| 原子性 | 部分失败导致不一致 | 全部成功或全部回滚 |

## 4. SQLite 特有的优化

```sql
-- 启用 WAL 模式：写入时不阻塞读取
PRAGMA journal_mode = WAL;

-- 只读模式优化
PRAGMA query_only = 1;
```

## 符号速查

| 语句 | 用途 |
|------|------|
| `CREATE TABLE IF NOT EXISTS` | 创建表（不存在时） |
| `INSERT OR REPLACE` | 插入或覆盖 |
| `SELECT ... WHERE ?` | 参数化查询 |
| `DELETE FROM ... WHERE ?` | 删除指定行 |
| `COUNT(*)` | 统计行数 |
| `BEGIN` / `COMMIT` / `ROLLBACK` | 事务控制 |

## 相关笔记

- [[SQLite]] — SQLite 数据库详解
- [[Caching Principles]] — 缓存的数据持久化
