---
tags:
  - Go
  - ProgrammingLanguages
  - 方法性
title: "Go - Database Access"
created: 2026-06-02
modified: 2026-06-02
---

# Go - Database Access

> [!abstract] Go 提供从标准库 `database/sql` 到全功能 ORM (GORM) 的多层数据库访问方案。ORM 减少样板代码但隐藏 SQL 语义，raw SQL 控制力最强但工作量大——选择取决于项目对抽象程度和性能的权衡。

## 1. database/sql

`database/sql` 是 Go 标准库提供的数据库抽象层，定义统一的接口，由各数据库驱动实现。

### 1.1 核心接口

```go
import (
    "database/sql"
    _ "github.com/lib/pq" // 仅注册驱动
)

db, err := sql.Open("postgres", "host=localhost dbname=test sslmode=disable")
if err != nil {
    log.Fatal(err)
}
defer db.Close()
```

`sql.Open` 并不建立连接，只验证参数。首次查询时才真正连接。

### 1.2 连接池

| 参数 | 方法 | 默认值 |
|------|------|--------|
| 最大打开连接数 | `db.SetMaxOpenConns(n)` | 0 (无限制) |
| 最大空闲连接数 | `db.SetMaxIdleConns(n)` | 2 |
| 连接最大存活时间 | `db.SetConnMaxLifetime(d)` | 永久 |

```go
db.SetMaxOpenConns(25)
db.SetMaxIdleConns(5)
db.SetConnMaxLifetime(5 * time.Minute)
```

### 1.3 基本操作

```go
var name string
err := db.QueryRow("SELECT name FROM users WHERE id = $1", 1).Scan(&name)

rows, err := db.Query("SELECT id, name FROM users")
defer rows.Close()
for rows.Next() {
    var id int; var name string
    rows.Scan(&id, &name)
}

result, err := db.Exec("UPDATE users SET name = $1 WHERE id = $2", "Alice", 1)
n, _ := result.RowsAffected()
```

### 1.4 预编译语句

```go
stmt, err := db.Prepare("SELECT name FROM users WHERE id = $1")
defer stmt.Close()
stmt.QueryRow(1).Scan(&name)
stmt.QueryRow(2).Scan(&name) // 复用执行计划
```

## 2. sqlx

`sqlx` 是 `database/sql` 的轻量扩展，保留底层 API 的同时提供结构体扫描和命名参数。

```go
import "github.com/jmoiron/sqlx"

db, err := sqlx.Connect("postgres", "host=localhost dbname=test sslmode=disable")
```

### 2.1 结构体扫描

```go
type User struct {
    ID    int    `db:"id"`
    Name  string `db:"name"`
    Email string `db:"email"`
}

var users []User
err = db.Select(&users, "SELECT id, name, email FROM users WHERE active = $1", true)

var user User
err = db.Get(&user, "SELECT id, name, email FROM users WHERE id = $1", 1)
```

`Get` 查询单行，`Select` 查询多行。字段通过 `db` tag 或字段名自动映射。

### 2.2 命名参数

```go
query := `INSERT INTO users (name, email) VALUES (:name, :email)`
result, err := db.NamedExec(query, map[string]interface{}{
    "name":  "Bob",
    "email": "bob@example.com",
})

// 直接从结构体获取参数
result, err = db.NamedExec(query, User{Name: "Bob", Email: "bob@example.com"})
```

### 2.3 事务

```go
tx, err := db.Beginx()
defer tx.Rollback()

tx.NamedExec("INSERT INTO users (name) VALUES (:name)", &User{Name: "Alice"})
tx.NamedExec("INSERT INTO users (name) VALUES (:name)", &User{Name: "Bob"})

tx.Commit()
```

## 3. pgx

`pgx` 是 PostgreSQL 专用驱动，提供比标准 `database/sql` 更丰富的 PG 特性。

```go
import "github.com/jackc/pgx/v5"

conn, err := pgx.Connect(context.Background(), "postgres://localhost:5432/test")
defer conn.Close(context.Background())
```

### 3.1 批量插入 (COPY)

```go
rows := [][]interface{}{
    {"Alice", "alice@example.com"},
    {"Bob", "bob@example.com"},
    {"Charlie", "charlie@example.com"},
}

_, err := conn.CopyFrom(
    context.Background(),
    pgx.Identifier{"users"},
    []string{"name", "email"},
    pgx.CopyFromRows(rows),
)
```

`COPY` 比逐行 INSERT 快 10-100 倍，适合大批量数据导入。

### 3.2 LISTEN/NOTIFY

```go
_, err = conn.Exec(context.Background(), "LISTEN events")
for {
    notification, err := conn.WaitForNotification(context.Background())
    fmt.Printf("Channel: %s, Payload: %s\n", notification.Channel, notification.Payload)
}
// 另一连接: conn.Exec(ctx, "NOTIFY events, 'user_created'")
```

## 4. GORM

GORM 是 Go 最流行的全功能 ORM，提供模型定义、自动迁移、关联、钩子等特性。

### 4.1 模型定义与迁移

```go
type User struct {
    ID        uint   `gorm:"primaryKey"`
    Name      string `gorm:"size:100;not null"`
    Email     string `gorm:"uniqueIndex"`
    Orders    []Order
}

type Order struct {
    ID     uint
    UserID uint
    Amount float64
}

db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
db.AutoMigrate(&User{}, &Order{})
```

### 4.2 CRUD 操作

```go
// Create
user := User{Name: "Alice", Email: "alice@example.com"}
db.Create(&user)

// Read
var user User
db.First(&user, 1)                       // 主键查询
db.Where("name = ?", "Alice").First(&user) // 条件查询

// Update
db.Model(&user).Update("Name", "Bob")
db.Model(&user).Updates(User{Name: "Bob", Email: "bob@example.com"})

// Delete
db.Delete(&user, 1)
```

### 4.3 关联查询

```go
var user User
db.Preload("Orders").First(&user, 1) // user.Orders 已自动填充

var users []User
db.Preload("Orders").Find(&users)
```

### 4.4 钩子

GORM 提供 `BeforeCreate`、`AfterCreate`、`BeforeUpdate`、`AfterDelete` 等生命周期钩子。

```go
func (u *User) BeforeCreate(tx *gorm.DB) error {
    if u.Name == "" { return errors.New("name is required") }
    return nil
}
```

## 5. 方案对比

| 维度 | database/sql | sqlx | pgx | GORM |
|------|-------------|------|-----|------|
| 抽象层级 | 最低（raw SQL） | 低（struct 映射） | 低（PG 原生） | 高（ORM） |
| 学习成本 | SQL 知识 | SQL + 少量 API | PG 特性 + 库 API | GORM 约定 |
| 性能 | 最高 | 接近 raw | 最高（PG 专有优化） | 有 ORM 开销 |
| 数据库支持 | 所有（通过驱动） | 所有（通过驱动） | PostgreSQL only | MySQL/PG/SQLite/SQL Server |
| 迁移工具 | 无 | 无 | 无 | AutoMigrate |

### 5.1 选择建议

| 场景 | 推荐方案 |
|------|---------|
| 少量简单查询，追求零依赖 | `database/sql` |
| 中型项目，大量 struct 映射 | `sqlx` |
| PostgreSQL 深度功能（COPY、LISTEN/NOTIFY） | `pgx` |
| 快速原型、表单类 CRUD、团队不熟悉 SQL | GORM |
| 复杂查询、高性能要求 | `sqlx` 或 `database/sql` |

## 符号速查

| 概念 | 语法 / API | 说明 |
|------|-----------|------|
| 打开数据库 | `sql.Open(driver, dsn)` | 不建立连接，仅注册 |
| 查询单行 | `db.QueryRow().Scan(&v)` | 返回一行 |
| 查询多行 | `db.Query()` + `rows.Next()` | 遍历结果集 |
| 执行写操作 | `db.Exec()` | INSERT / UPDATE / DELETE |
| 预编译 | `db.Prepare()` | 复用执行计划 |
| sqlx 结构体扫描 | `db.Select(&slice, query, args...)` | 自动映射字段 |
| sqlx 命名参数 | `db.NamedExec(query, struct)` | struct tag 映射 |
| pgx COPY | `conn.CopyFrom(ctx, table, cols, rows)` | 批量导入 |
| pgx LISTEN | `conn.WaitForNotification(ctx)` | 异步通知 |
| GORM 迁移 | `db.AutoMigrate(&Model{})` | 自动建表 |
| GORM 预加载 | `db.Preload("Relation").Find(&slice)` | 关联查询 |

## 相关笔记

- [[Go - Web Frameworks]]
- [[Go - CLI & Config]]
- [[SQLite]]
- [[SQL Basics]]
