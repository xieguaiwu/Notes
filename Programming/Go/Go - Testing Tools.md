---
tags:
  - Go
  - ProgrammingLanguages
  - 方法性
title: "Go - Testing Tools"
created: 2026-06-02
modified: 2026-06-02
---

# Go - Testing Tools

> [!abstract] Go 将测试作为一等公民内置在语言工具链中（`go test`），倡导表驱动测试（table-driven tests）作为标准模式。本章涵盖 Go 内置测试能力及社区生态中最重要的测试库：Testify、httptest、uber-go/mock 和原生 fuzzing。

## 1. 表驱动测试

表驱动测试是 Go 中最惯用的测试模式——将测试用例定义为结构体切片，统一循环执行。

### 1.1 基本模式

```go
func TestAdd(t *testing.T) {
    tests := []struct {
        name     string
        a, b     int
        expected int
    }{
        {"positive numbers", 1, 2, 3},
        {"negative numbers", -1, -1, -2},
        {"mixed signs", -1, 2, 1},
        {"zeros", 0, 0, 0},
    }

    for _, tt := range tests {
        t.Run(tt.name, func(t *testing.T) {
            got := Add(tt.a, tt.b)
            if got != tt.expected {
                t.Errorf("Add(%d, %d) = %d, want %d",
                    tt.a, tt.b, got, tt.expected)
            }
        })
    }
}
```

> [!note] `t.Run()` 创建子测试，使每个用例独立运行、独立报告，支持 `go test -run TestAdd/positive` 选择性执行。

## 2. Testify

Testify 是 Go 最流行的测试断言库，提供 assert、require、suite 和 mock 四套工具。

### 2.1 assert 与 require

```go
import (
    "testing"
    "github.com/stretchr/testify/assert"
    "github.com/stretchr/testify/require"
)

func TestUser(t *testing.T) {
    user, err := FetchUser(1)

    // require: 失败立即终止（适用于前置条件）
    require.NoError(t, err)
    require.NotNil(t, user)

    // assert: 失败继续执行（适用于值校验）
    assert.Equal(t, "Alice", user.Name)
    assert.Greater(t, user.Age, 0)
    assert.Contains(t, user.Email, "@")
}
```

| 方法 | 失败行为 | 适用场景 |
|------|---------|---------|
| `assert.*` | 标记失败，继续执行 | 值验证、多字段检查 |
| `require.*` | 标记失败，立即终止 | 前置条件（nil 检查等） |

### 2.2 Suite

Suite 提供 xUnit 风格的测试组织，支持 setup/teardown 钩子：

```go
import "github.com/stretchr/testify/suite"

type UserRepoSuite struct {
    suite.Suite
    db *sql.DB
}

func (s *UserRepoSuite) SetupSuite() {
    s.db = openTestDB()   // 整个 suite 初始化一次
}

func (s *UserRepoSuite) TearDownTest() {
    s.db.Exec("DELETE FROM users")  // 每个测试后清理
}

func (s *UserRepoSuite) TestInsertUser() {
    err := InsertUser(s.db, "Alice")
    s.Require().NoError(err)
}

func (s *UserRepoSuite) TestQueryUser() {
    user, err := QueryUser(s.db, 1)
    s.Assert().Equal("Alice", user.Name)
}

func TestUserRepoSuite(t *testing.T) {
    suite.Run(t, new(UserRepoSuite))
}
```

> [!tip] Suite 的生命周期钩子包括 `SetupSuite`、`TearDownSuite`、`SetupTest`、`TearDownTest`，按粒度从粗到细覆盖。

### 2.3 testify/mock

Testify 内置轻量 mock 机制，适合中小型项目：

```go
type MockUserRepo struct {
    mock.Mock
}

func (m *MockUserRepo) Find(id int) (*User, error) {
    args := m.Called(id)
    return args.Get(0).(*User), args.Error(1)
}

// 使用
mockRepo := new(MockUserRepo)
mockRepo.On("Find", 1).Return(&User{Name: "Alice"}, nil)
```

## 3. httptest

`net/http/httptest` 是 Go 标准库内置的 HTTP 测试工具包，零外部依赖。

### 3.1 测试 Handler（ResponseRecorder）

```go
func TestGetUserHandler(t *testing.T) {
    handler := http.HandlerFunc(GetUserHandler)

    req := httptest.NewRequest("GET", "/users/1", nil)
    w := httptest.NewRecorder()

    handler.ServeHTTP(w, req)

    resp := w.Result()
    assert.Equal(t, http.StatusOK, resp.StatusCode)
    assert.Equal(t, "application/json", resp.Header.Get("Content-Type"))

    var user User
    json.NewDecoder(resp.Body).Decode(&user)
    assert.Equal(t, "Alice", user.Name)
}
```

### 3.2 测试 HTTP 客户端（httptest.Server）

```go
func TestAPIClient(t *testing.T) {
    server := httptest.NewServer(http.HandlerFunc(
        func(w http.ResponseWriter, r *http.Request) {
            assert.Equal(t, "/users/1", r.URL.Path)
            fmt.Fprint(w, `{"name":"Alice","age":30}`)
        }))
    defer server.Close()

    client := NewAPIClient(server.URL)
    user, err := client.GetUser(1)

    require.NoError(t, err)
    assert.Equal(t, "Alice", user.Name)
}
```

> [!tip] `httptest.Server` 在随机端口启动真实 HTTP 服务器，适合测试依赖外部 API 的客户端代码。`httptest.NewTLSServer` 提供 HTTPS 支持。

## 4. uber-go/mock

uber-go/mock（原 gomock）通过代码生成创建接口 mock，适合大型项目中接口数量多的场景。

```bash
go install go.uber.org/mock/mockgen@latest
mockgen -source=user.go -destination=mock_user.go -package=service
```

```go
// 在测试中使用生成的 mock
ctrl := gomock.NewController(t)
defer ctrl.Finish()

mockRepo := NewMockUserRepository(ctrl)
mockRepo.EXPECT().FindByID(gomock.Eq(1)).Return(&User{Name: "Alice"}, nil)

service := NewUserService(mockRepo)
user, err := service.GetUser(1)
```

| 特性 | testify/mock | uber-go/mock |
|------|-------------|-------------|
| 生成方式 | 手写实现 | 代码生成 |
| 类型安全 | 运行时 | 编译时 |
| 接口变更 | mock 会编译失败 | 重新生成即可 |
| 适用规模 | 小型项目 | 中大型项目 |

## 5. Fuzzing

Go 1.18 引入原生 fuzz testing（`testing.F`），通过随机输入发现边界情况。

```go
func FuzzParseNumber(f *testing.F) {
    // 种子语料
    f.Add("42")
    f.Add("-1")
    f.Add("0")

    f.Fuzz(func(t *testing.T, input string) {
        result, err := ParseNumber(input)
        if err != nil {
            t.Skip() // 无效输入是预期行为
        }
        // 检查不变量：解析结果必须可数值化
        if result == "" {
            t.Error("unexpected empty result for valid input")
        }
    })
}
```

```bash
go test -fuzz=FuzzParseNumber -fuzztime=30s
```

> [!note] Fuzzing 引擎自动变异输入，持续运行直到发现崩溃或超时。失败的输入会保存到 `testdata/fuzz/` 目录，后续 `go test` 会自动回归。

## 6. 测试覆盖率

```bash
go test -cover                          # 输出覆盖率百分比
go test -coverprofile=coverage.out      # 生成覆盖率数据
go tool cover -html=coverage.out        # 浏览器查看行级覆盖
go tool cover -func=coverage.out        # 终端查看函数级覆盖
```

## 对比表

### 测试框架对比

| 特性 | 内置 testing | Testify Suite |
|------|------------|--------------|
| 断言风格 | `if` + `t.Error/Fatal` | `assert.Equal` / `require.NoError` |
| setup/teardown | `TestMain` 或手动 | `SetupSuite` / `TearDownTest` 等 |
| 子测试 | `t.Run()` | Suite 方法自动识别 |
| 依赖 | 无 | `github.com/stretchr/testify` |
| 学习曲线 | 低（仅标准库） | 中 |

### Mock 方案对比

| 方案 | 手写 | testify/mock | uber-go/mock |
|------|------|-------------|-------------|
| 类型安全 | 编译时 | 运行时 | 编译时 |
| 代码量 | 少（简单接口） | 中 | 自动生成 |
| 约束检查 | 手动 `t.Error` | `m.On().Return()` | `EXPECT().Times()` |
| 适用场景 | 1-2 方法的接口 | 中型项目 | 大型项目 / 接口频繁变更 |

## 符号速查

| 命令/语法 | 说明 |
|-----------|------|
| `go test` | 运行当前包测试 |
| `go test ./...` | 运行所有包测试 |
| `go test -v` | 详细输出 |
| `go test -run TestName` | 运行指定测试 |
| `go test -fuzz=FuzzName` | 运行 fuzz 测试 |
| `go test -cover` | 输出覆盖率 |
| `go test -coverprofile=out` | 生成覆盖率文件 |
| `go test -race` | 竞态检测 |
| `t.Run(name, fn)` | 创建子测试 |
| `t.Parallel()` | 标记测试可并行 |
| `t.Helper()` | 标记辅助函数 |
| `testing.T` | 测试上下文 |
| `testing.F` | Fuzz 测试上下文 |
| `mockgen -source=` | uber-go/mock 代码生成 |

## 相关笔记

- [[Go - Error Handling and Defer]] — 错误处理与 `require.NoError` 的配合
- [[Go - Interfaces]] — 接口是 mock 技术的基础
- [[Go - Web Frameworks]] — HTTP handler 测试实战
