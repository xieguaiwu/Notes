# Go 方法接收器（Receiver）

## 是什么

将函数绑定到特定类型上，使其成为该类型的方法。

```go
func (m model) Init() tea.Cmd { return nil }
//       ^^^^^^^ 接收器
```

## 普通函数 vs 方法

| | 写法 | 调用 |
|---|---|---|
| 普通函数 | `func Init() tea.Cmd` | `Init()` |
| 方法 | `func (m model) Init() tea.Cmd` | `myModel.Init()` |

## 从面向对象角度理解

- Java：方法隐式属于类，`this` 隐式存在
- Python：`def init(self)` — `self` 显式传入
- Go：`func (m model) Init()` — 接收器写在**函数名前**，相当于 `self`

本质就是把函数绑到类型上，`(m model)` 就是当前实例的引用名。

## 两种接收器

### 值接收器 `(m model)`

操作的是**副本**，不影响原始值：

```go
func (m model) SetCursor(n int) {
    m.cursor = n  // 只改了副本，外面的 model 不变
}
```

### 指针接收器 `(m *model)`

操作的是**原对象**，修改会保留：

```go
func (m *model) SetCursor(n int) {
    m.cursor = n  // 真实修改了原 model
}
```

### 选用原则

| 场景 | 推荐 |
|---|---|
| 只读方法、不修改数据 | 值接收器 |
| 需要修改接收者的字段 | 指针接收器 |
| 接收者是大型结构体 | 指针接收器（避免拷贝开销） |
| 接收者是 map / slice / channel | 值接收器（引用类型本身已是指针） |

## 关键特性

- 方法的接收器**只能定义在同一个包内的类型上**
- Go **没有类**，方法只是带接收器参数的函数——语法糖
- 值接收器的方法**自动同时拥有指针调用方式**（Go 自动解引用），反之亦然

```go
var m model
m.Init()       // 值调用 ✅
(&m).Init()    // 指针调用也 ✅（Go 自动处理）
```

## 在你的 Bubble Tea 程序中

```go
func (m model) Init() tea.Cmd   { return nil }   // 值接收器，不需要改数据
func (m model) Update(msg) ...  { ... return m, nil }  // 值接收器，返回新值
func (m model) View() string    { ... }           // 值接收器，只读
```

`Init()` 返回 `nil` 不需要修改数据，所以值接收器足够。`Update()` 虽然逻辑上在改数据，但它通过返回一个新的 `tea.Model` 来传递变更，而非原地修改接收器。
