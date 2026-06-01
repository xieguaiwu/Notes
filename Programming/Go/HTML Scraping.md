---
tags:
  - ComputerScience
  - Go
  - 方法性
title: "HTML Scraping"
created: 2026-06-01
modified: 2026-06-01
---

# HTML Scraping

> [!abstract] HTML Scraping 从网页的 HTML 结构中提取结构化数据。当网站不提供公开 API 时，这是获取数据的常用手段。

## 1. 概念

```
HTTP GET 请求 → HTML 响应 → 解析 DOM → 提取数据
```

| 方式 | 适用场景 | 优点 | 缺点 |
|------|---------|------|------|
| **API 调用** | 网站提供公开 API | 稳定、结构化的数据 | 需要 API Key、限流 |
| **HTML Scraping** | 无公开 API | 通用性强 | 易被网站改版破坏 |

## 2. CSS 选择器

CSS 选择器通过样式路径定位 HTML 元素：

```go
// goquery 库的使用
doc, _ := goquery.NewDocumentFromReader(resp.Body)

// 类选择器
doc.Find(".phone_con .per-phone .phonetic")

// 属性选择器
doc.Find("[itemprop=\"mainEntity\"]")

// 标签 + 类
doc.Find("ul.rLstGt li")
```

| 选择器 | 示例 | 含义 |
|--------|------|------|
| `.class` | `.phonetic` | class="phonetic" 的元素 |
| `#id` | `#content` | id="content" 的元素 |
| `tag` | `div` | 所有 `<div>` |
| `parent child` | `ul li` | ul 下的所有 li |
| `[attr=val]` | `[type=text]` | 属性匹配 |

## 3. 多级降级解析

网站 HTML 结构可能变化或不一致，应采用从精确到宽松的解析策略：

```go
// 策略：从最高精度选择器开始，逐级放宽
func extractPhonetic(doc *goquery.Document) string {
    // 第一级：精确选择器
    if text := doc.Find(".phone_con .per-phone .phonetic").Text(); text != "" {
        return text
    }
    // 第二级：放宽结构限制
    if text := doc.Find(".per-phone .phonetic").Text(); text != "" {
        return text
    }
    // 第三级：只匹配类名
    if text := doc.Find(".phonetic").First().Text(); text != "" {
        return text
    }
    return ""
}
```

### 3.1 降级链

```
精确选择器 → 放宽结构限制 → 只匹配类名 → 正则提取 → 返回空
```

## 4. 风险与应对

| 风险 | 影响 | 应对 |
|------|------|------|
| **网站改版** | HTML 结构变化导致解析失败 | 多级降级解析 + 测试覆盖 |
| **User-Agent 拦截** | 服务器拒绝非浏览器请求 | 伪装 User-Agent |
| **限流（Rate Limit）** | 频繁请求被封 IP | 控制请求频率、缓存 |

```go
// 伪装 User-Agent
client := &http.Client{}
req, _ := http.NewRequest("GET", url, nil)
req.Header.Set("User-Agent",
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36")

// 请求间隔
time.Sleep(time.Second)  // 避免请求过快
```

## 5. Go 中的 HTML 解析库

| 库 | 选择器 | 特点 |
|----|--------|------|
| `golang.org/x/net/html` | 手动遍历 | 标准库扩展，底层 |
| `github.com/PuerkitoBio/goquery` | CSS 选择器 | 类似 jQuery，最流行 |
| `github.com/antchfx/htmlquery` | XPath | XPath 查询 |

### 5.1 goquery 基本操作

```go
doc.Find(".selector").Each(func(i int, s *goquery.Selection) {
    text := s.Text()      // 提取文本
    attr, _ := s.Attr("href")  // 提取属性
    html, _ := s.Html()   // 提取内部 HTML
})
```

## 相关笔记

- [[Strategy Pattern]] — 每种数据源作为独立的解析策略
- [[Query Chain Pattern]] — 数据源层在查询链中的位置
