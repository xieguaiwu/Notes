---
tags:
  - C++
  - 定义性
  - 基本原理
  - STL
  - DataStructure
title: Linked List
created: 2026-06-11
modified: 2026-06-11
---

# Linked List

> [!abstract] 链表
> 链表是一种**线性数据结构**，由一系列结点（Node）通过指针链接而成，每个结点包含数据域和指向下一个结点的指针。与数组不同，链表的元素在内存中**不连续存储**，支持 $O(1)$ 的插入/删除（已知位置）和 $O(n)$ 的随机访问。

## 1. 链表类型

| 类型 | 结构 | 特点 |
|:----|:----|:-----|
| **单向链表** | `Node -> Node -> Node -> NULL` | 每个结点仅指向后继 |
| **双向链表** | `NULL <- Node <-> Node <-> Node -> NULL` | 每个结点指向前驱和后继 |
| **循环链表** | `Node -> Node -> Node -> (back to head)` | 尾结点指向头结点 |

### 1.1 单向链表结点定义

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

### 1.2 双向链表结点定义

```cpp
struct DoublyListNode {
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};
```

## 2. 常见操作

> [!note] 头结点（dummy node）
> 为简化边界条件（空链表、删除首元结点等），常引入**哑结点**（dummy head）作为哨兵，其 `next` 指向真正的首元结点。操作结束后返回 `dummy->next` 即可。

### 2.1 遍历

```cpp
void traverse(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        // 处理 cur->val
        cur = cur->next;
    }
}
```

### 2.2 插入

```cpp
// 在结点 prev 之后插入新结点
ListNode* newNode = new ListNode(42);
newNode->next = prev->next;
prev->next = newNode;
```

### 2.3 删除

```cpp
// 删除结点 prev 的后继结点
ListNode* toDelete = prev->next;
prev->next = toDelete->next;
delete toDelete;  // 释放内存
```

### 2.4 反转

> [!tip] 迭代反转（三指针法）
> 用 `prev`、`cur`、`next` 三个指针逐步反转相邻结点的指向。

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->next;  // 暂存后继
        cur->next = prev;            // 反转指向
        prev = cur;                  // 前移
        cur = next;
    }
    return prev;  // prev 是反转后的头结点
}
```

递归版：

```cpp
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

## 3. 复杂度

| 操作 | 单向链表 | 双向链表 | 数组 |
|:----|:-------:|:-------:|:---:|
| 随机访问 | $O(n)$ | $O(n)$ | $O(1)$ |
| 头部插入 | $O(1)$ | $O(1)$ | $O(n)$ |
| 尾部插入（有尾指针） | $O(1)$ | $O(1)$ | $O(1)$* |
| 已知位置插入 | $O(1)$ | $O(1)$ | $O(n)$ |
| 已知位置删除 | $O(1)$ | $O(1)$ | $O(n)$ |
| 搜索 | $O(n)$ | $O(n)$ | $O(n)$ |

> \* 数组尾部插入摊销 $O(1)$，但可能触发 reallocation。

## 4. STL 容器

### 4.1 `std::forward_list`

> [!note] 单向链表 (C++11)
> - 头文件 `<forward_list>`
> - 单向链表，仅支持前向迭代
> - 无 `size()` 方法（$O(1)$ 无开销）
> - 提供 `before_begin()` 返回首元结点之前的迭代器（对应哑结点概念）

```cpp
#include <forward_list>

std::forward_list<int> fl = {1, 2, 3, 4, 5};
fl.push_front(0);             // 头部插入 O(1)
fl.pop_front();                // 头部删除 O(1)
fl.insert_after(fl.before_begin(), 99);  // 头部之后插入
fl.erase_after(fl.begin());   // 删除第二个元素
```

**常用方法**：

| 方法 | 说明 |
|:----|:-----|
| `push_front(val)` | 头部插入 |
| `pop_front()` | 头部删除 |
| `insert_after(pos, val)` | 在 pos 后插入 |
| `erase_after(pos)` | 删除 pos 后的元素 |
| `splice_after(pos, other)` | 将 other 链表拼接到 pos 后 |
| `before_begin()` | 指向首元结点之前的迭代器 |
| `sort()` | 排序 |
| `unique()` | 去重（连续相等） |
| `merge(other)` | 合并两个有序链表 |
| `reverse()` | 反转 |

### 4.2 `std::list`

> [!note] 双向链表
> - 头文件 `<list>`
> - 双向链表，支持双向迭代
> - 提供 `push_back` / `pop_back` 等完整接口

```cpp
#include <list>

std::list<int> lst = {1, 2, 3, 4, 5};
lst.push_back(6);             // 尾部插入
lst.push_front(0);            // 头部插入
lst.pop_back();               // 尾部删除
lst.pop_front();              // 头部删除
```

**常用方法**：

| 方法 | 说明 |
|:----|:-----|
| `push_front(val)` | 头部插入 |
| `pop_front()` | 头部删除 |
| `push_back(val)` | 尾部插入 |
| `pop_back()` | 尾部删除 |
| `insert(pos, val)` | 在 pos 处插入 |
| `erase(pos)` | 删除 pos 处的元素 |
| `splice(pos, other)` | 将 other 链表拼接到 pos 处 |
| `sort()` | 排序 |
| `unique()` | 去重 |
| `merge(other)` | 合并有序链表 |
| `reverse()` | 反转 |
| `remove(val)` | 删除所有等于 val 的元素 |
| `remove_if(pred)` | 删除满足谓词的元素 |

### 4.3 `std::forward_list` vs `std::list` 选择

| 条件 | 推荐 |
|:----|:----|
| 仅需单向遍历 | `forward_list`（更省内存） |
| 需要双向遍历 / 双向插入 | `list` |
| 需要 `size()` | `list` |
| 内存极度受限 | `forward_list`（每个结点省一个指针） |

## 5. 常见算法技巧

### 5.1 快慢指针（Floyd 判环）

```cpp
// 检测链表是否有环
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 寻找环入口
ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
```

### 5.2 获取中间结点

```cpp
ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### 5.3 合并两个有序链表

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);       // 哑结点简化操作
    ListNode* cur = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}
```

### 5.4 删除倒数第 N 个结点

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *fast = &dummy, *slow = &dummy;
    for (int i = 0; i < n; ++i) fast = fast->next;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return dummy.next;
}
```

### 5.5 原地重排（奇偶分离）

```cpp
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *odd = head, *even = head->next, *evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
```

## 6. 注意事项

> [!warning] 内存泄漏
> - 手动 `new` 的结点必须手动 `delete`
> - 使用 STL 容器（`forward_list`/`list`）自动管理内存
> - 频繁 `new`/`delete` 会导致性能问题，考虑使用内存池

> [!warning] 悬挂指针
> - 删除结点后及时将指针置为 `nullptr`
> - 小心多指针指向同一结点时的生命周期

> [!warning] 迭代器失效
> - `forward_list` 的 `insert_after`/`erase_after` 不影响其他迭代器
> - `list` 的插入/删除不使已有迭代器失效（唯一例外：被删除元素的迭代器）

## 相关链接

- [[Algorithm]] — C++ `<algorithm>` 中的 find/sort/merge 等操作链表迭代器版本
- [[Smart Pointer]] — 使用 `unique_ptr` 管理链表结点实现 RAII 语义
