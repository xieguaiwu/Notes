---
tags:
  - ProgrammingLanguages
  - ComputerScience
  - Go
  - 定义性
  - 基本原理
title: "Tagged Union"
created: 2026-06-01
modified: 2026-06-01
---

# Tagged Union

> [!abstract] 标签联合（Tagged Union / Discriminated Union / Sum Type）是一种类型，其值可以是多种不同类型中的一种，用一个标签字段区分当前存储的是哪一种。

## 1. 概念

```go
// 一个值可能是：
//   - 英→中翻译
//   - 德语词条
// 用一个 type 字段区分
```

| 名称 | 含义 |
|------|------|
| **Tagged Union** | 带标签的联合类型 |
| **Discriminated Union** | 可区分的联合 |
| **Sum Type** | 和类型（代数数据类型） |

### 1.1 与 enum 的区别

```go
// 普通枚举：只表示状态
type Color int
const (
    Red Color = iota
    Green
    Blue
)

// 标签联合：每个分支可以是不同的数据结构
// {type: "to_chinese", data: ToChinese{...}}
// {type: "german",      data: GermanEntry{...}}
```

## 2. JSON 序列化

### 2.1 JSON 表示

```json
{"type": "to_chinese", "data": {"input_text": "hello", "meanings": [...]}}
{"type": "german",      "data": {"word": "Haus", "definitions": [...]}}
```

反序列化时先读 `type`，再根据它选择解析 `data` 的目标类型。

### 2.2 Go 实现

```go
type ResultType int

const (
    TypeToChinese ResultType = iota
    TypeToEnglish
    TypeGerman
)

// 包装结构
type TranslationData struct {
    Type  ResultType
    ToChinese *ToChinese
    ToEnglish *ToEnglish
    German    *GermanEntry
}

// 自定义 JSON 序列化
func (t *TranslationData) MarshalJSON() ([]byte, error) {
    switch t.Type {
    case TypeToChinese:
        return json.Marshal(map[string]any{
            "type": "to_chinese",
            "data": t.ToChinese,
        })
    case TypeGerman:
        return json.Marshal(map[string]any{
            "type": "german",
            "data": t.German,
        })
    // ...
    }
}

func (t *TranslationData) UnmarshalJSON(data []byte) error {
    var raw struct {
        Type string          `json:"type"`
        Data json.RawMessage `json:"data"`
    }
    if err := json.Unmarshal(data, &raw); err != nil {
        return err
    }
    switch raw.Type {
    case "to_chinese":
        t.Type = TypeToChinese
        t.ToChinese = new(ToChinese)
        return json.Unmarshal(raw.Data, t.ToChinese)
    case "german":
        t.Type = TypeGerman
        t.German = new(GermanEntry)
        return json.Unmarshal(raw.Data, t.German)
    }
    return fmt.Errorf("unknown type: %s", raw.Type)
}
```

## 3. 不同语言中的实现

| 语言 | 实现方式 | 模式匹配 |
|------|---------|---------|
| **Go** | 包装结构体 + 手动 marshal | `switch` 语句 |
| **Rust** | `enum` + `#[serde(tag, content)]` | `match` 穷尽检查 |
| **C++17** | `std::variant<Ts...>` | `std::visit` + `overloaded` |
| **TypeScript** | `type X = {type:"a"} \| {type:"b"}` | `switch` + 类型守卫 |

## 4. 适用场景

| 适用 | 不适用 |
|------|--------|
| API 返回多种数据格式 | 所有分支结构相同（用普通 struct 即可） |
| 协议消息有多种类型 | 分支极少且不变 |
| 需要向前兼容扩展新类型 | 性能极度敏感（分支判断有开销） |

## 相关笔记

- [[Go - Interfaces]] — 接口是另一种类型抽象方式
- [[Unified Data Flow Design]] — 统一类型 vs 标签联合的权衡
- [[Strategy Pattern]] — 策略模式与标签联合的配合
