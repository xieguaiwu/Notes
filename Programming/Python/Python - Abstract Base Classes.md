---
tags:
  - Python
  - OOP
  - DesignPatterns
  - TypeSystem
  - 概念性
title: Python - Abstract Base Classes
created: 2026-06-01
---

# Python - Abstract Base Classes — Interface Contracts and Strategy Patterns

> [!abstract] Overview
> Python 的抽象基类（ABC）提供了一种正式定义接口契约的机制。不同于 duck typing 的"看起来像鸭子就是鸭子"，ABC 要求子类显式实现特定方法，避免了运行时才发现的缺失方法错误。加上 `@abstractmethod`、`register()` 虚拟子类和 `isinstance` 检查，ABC 是 Python 中实现 Strategy、Template Method、Factory 等设计模式的基础设施。本文以 CTM 的 `BaseBroker(ABC)` 为案例，展示 ABC 在插件化架构中的应用。

Related: [[Python - Decorators]] | [[PyTorch - Custom Gradients]]

---

## 1. Abstract Base Classes — Core Principles

### What & Why

Python 的 ABC 解决一个根本矛盾：Python 是动态类型语言，但大型系统需要**接口契约**来保证组件间协作的可靠性。

没有 ABC 时，接口只是约定（convention）：

```python
# 文档写着"你需要实现 execute() 方法"——但 Python 不会帮你检查
class AlpacaBroker:
    def execute(self, order):   # 如果拼错为 execcute，只有运行时才知道
        ...

class BinanceBroker:
    def ejecutar(self, order):  # 不同语言工程师命名不同
        ...
```

有 ABC 时，接口是强制约束：

```python
from abc import ABC, abstractmethod

class BaseBroker(ABC):
    @abstractmethod
    def execute(self, order):
        """所有 Broker 必须实现 execute"""
        ...

# class AlpacaBroker(BaseBroker): pass  # 实例化时 TypeError！
```

ABC 的实例化保护在 `__init__` 调用时触发——任何未实现的 `@abstractmethod` 都会抛出 `TypeError`。越早失败（实例化时 vs 调用时），调试成本越低。

### Mathematical / Theoretical Foundation

**Python 的抽象机制层级**：

| 层级 | 机制 | 检查时机 | 强制力度 |
|------|------|---------|---------|
| 1 | Duck Typing | 调用时 | 无强制，运行时 AttributeError |
| 2 | `hasattr(obj, 'method')` | 调用前 | 手动检查，无标准约束 |
| 3 | `isinstance(obj, MyABC)` | 任意时刻 | 需要虚拟子类注册或显式继承 |
| 4 | `@abstractmethod` | 实例化时 | 强制实现，缺失即 TypeError |
| 5 | `Protocol` (PEP 544) | 静态类型检查 | 结构性子类型，无运行时强制 |

**ABC 的核心 API**：

```python
from abc import ABC, abstractmethod, abstractproperty

class BaseModel(ABC):
    @abstractmethod
    def forward(self, x):
        """所有模型必须实现前向传播"""
        ...

    @abstractmethod
    def loss(self, y_pred, y_true):
        """所有模型必须实现损失计算"""
        ...

    # Python 3.3+ 中 @abstractproperty 已废弃，用 @property + @abstractmethod
    @property
    @abstractmethod
    def model_type(self):
        ...
```

**虚拟子类 (Virtual Subclass)**：允许一个类**被识别为**某个 ABC 的子类而不需要实际继承它：

```python
from abc import ABC

class IterableMixin(ABC):
    @abstractmethod
    def __iter__(self):
        ...

# 任意实现了 __iter__ 的类都可以注册
list.__class__.register(IterableMixin)  # 错误：list 是内建类型

# 正确方式：
IterableMixin.register(list)           # list 现在是 IterableMixin 的虚拟子类
assert isinstance([], IterableMixin)   # True
```

| 方式 | 语法 | 继承关系 | isinstance 检查 | 适用场景 |
|------|------|---------|----------------|---------|
| 显式继承 | `class A(Base):` | 是 | True | 可控代码，明确归属 |
| 虚拟注册 | `Base.register(A)` | 否 | True | 第三方库、不修改源码 |
| `__subclasshook__` | 类方法 | 条件性 | True（条件满足）| 结构性子类型检查 |

### Key Design Dimensions & Tradeoffs

| 设计维度 | 选项 | 取舍 |
|---------|------|------|
| **抽象粒度** | 类级别 ABC / 方法级别 @abstractmethod | 类级别定义完整契约；方法级别可按需实现 |
| **子类型检查** | isinstance / issubclass / 无检查 | isinstance 灵活但有性能和脆弱性问题；无检查则回归 duck typing |
| **虚拟子类** | register / __subclasshook__ | register 显式但需人工维护；__subclasshook__ 自动但可能匹配过度 |
| **静态与动态** | ABC（运行时）/ Protocol（静态检查） | ABC 运行时强约束；Protocol 编译时检查但需 mypy 等工具 |
| **多重继承** | Python 原生 MRO | 强大但钻石继承风险；Protocol 无继承链负担 |

---

## 2. Case Study: CTM Patterns

### How CTM Applies These Principles

CTM 的 **Strategy Pattern** 架构中，`BaseBroker(ABC)` 定义了所有交易接口的统一契约。不同的 Broker 实现（Alpaca, IBKR, Simulated）继承这个 ABC 并实现各自的具体逻辑：

| ABC 技术 | CTM 的具体使用 | 动机 |
|---------|---------------|------|
| `BaseBroker(ABC)` | 定义 Broker 接口契约 | 所有 Broker 实现必须支持相同操作集 |
| `@abstractmethod` | `place_order()`, `get_positions()`, `get_account()` | 确保子类实现关键交易操作 |
| `@property + @abstractmethod` | `name`, `is_live` 等属性 | 强制返回 Broker 元信息 |
| `register()` | 虚拟子类注册测试 Mock | 测试框架的 FakeBroker 可注册为 BaseBroker 子类 |
| `__subclasshook__` | 自定义 isinstance 逻辑 | 简化第三方 Broker 的集成检查 |

**BaseBroker 的 ABC 定义**：

```python
from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import List, Optional

@dataclass
class Order:
    symbol: str
    quantity: int
    side: str        # "buy" / "sell"
    order_type: str  # "market" / "limit"

@dataclass
class Position:
    symbol: str
    quantity: int
    market_value: float

class BaseBroker(ABC):
    """
    所有 Broker 的公共接口。
    子类必须实现所有 @abstractmethod。
    """

    @property
    @abstractmethod
    def name(self) -> str:
        """Broker 名称（用于日志和监控）"""
        ...

    @property
    @abstractmethod
    def is_live(self) -> bool:
        """是否为实盘 Broker"""
        ...

    @abstractmethod
    def place_order(self, order: Order) -> str:
        """
        下单。返回订单 ID。
        """
        ...

    @abstractmethod
    def get_positions(self) -> List[Position]:
        """获取当前持仓"""
        ...

    @abstractmethod
    def get_account(self) -> dict:
        """获取账户信息（余额、购买力等）"""
        ...

    # 非抽象方法——所有子类共享
    def check_market_hours(self) -> bool:
        """检查是否在交易时间内（默认实现，子类可覆盖）"""
        import datetime
        now = datetime.datetime.now()
        return 9 <= now.hour < 16
```

**三种 Broker 实现**：

```python
class AlpacaBroker(BaseBroker):
    @property
    def name(self) -> str:
        return "Alpaca"

    @property
    def is_live(self) -> bool:
        return True

    def place_order(self, order: Order) -> str:
        # 实际的 Alpaca API 调用
        response = self.api.submit_order(...)
        return response.order_id

    def get_positions(self) -> List[Position]:
        return [Position(...) for p in self.api.list_positions()]

    def get_account(self) -> dict:
        return self.api.get_account()._asdict()


class SimulatedBroker(BaseBroker):
    """回测使用的模拟 Broker - 不涉及真实 API"""
    @property
    def name(self) -> str:
        return "Simulated"

    @property
    def is_live(self) -> bool:
        return False

    def place_order(self, order: Order) -> str:
        self.orders.append(order)
        return f"sim_{len(self.orders)}"

    def get_positions(self) -> List[Position]:
        return self._compute_simulated_positions()

    def get_account(self) -> dict:
        return {"cash": self.cash, "buying_power": self.cash}
```

### Design Decisions & Rationale

**1. 为什么用 ABC 而非 Protocol？**

CTM 需要在**运行时**确保 Broker 实现了全部接口。`isinstance(broker, BaseBroker)` 是路由选择（实盘 vs 回测）和安全检查（确保不会传入不完整的实现）的关键判断。ABC 提供运行时类型保证，而 Protocol 只在静态类型检查时生效（myprc 等工具）。

**2. 为什么 @property 和 @abstractmethod 组合？**

```python
# 正确做法——强制返回名称
@property
@abstractmethod
def name(self) -> str:
    ...

# 劣化方案——不是强制属性
name = "Alpaca"  # 子类可能忘记定义
```

`@property @abstractmethod` 要求子类必须实现该属性。如果子类 `AlpacaBroker` 没有 `name` 属性，实例化时立即收到 `TypeError`。对比之下，如果基类只定义普通属性或类变量，子类忘记覆盖时不会报错，运行时产生难以追踪的逻辑错误。

**3. 为什么 check_market_hours 不是抽象方法？**

ABC 的精髓在于区分**必须实现**和**共享实现**：

- `place_order`：必须由每个 Broker 实现，无法共享（API 不同）
- `check_market_hours`：所有 Broker 共享的逻辑（市场时间判断），提供默认实现即可，子类可根据需要覆盖（如 Crypto 市场 24/7）

太多抽象方法增加实现负担；太少抽象方法模糊契约边界。设计 ABC 时需要问：**这个方法是有且仅有一种实现方式吗？** 如果是 → 基类直接实现。如果不同子类的实现一定不同 → 设为抽象方法。

> [!note] 与 Python - Decorators 的关系
> `AlpacaBroker` 继承了 `BaseBroker(ABC)` 的接口契约，同时使用 `@_retry_on_failure` 装饰器（见 [[Python - Decorators]]）注入重试行为。ABC 定义 **"做什么"**（place_order 签名和语义），装饰器定义 **"怎么做"**（容错和重试策略）。这种接口与行为增强的分离是 Strategy Pattern 的核心优势——替换 Broker 实现时，装饰器策略可以保持不变或独立调整。

### 虚拟子类的实际应用

```python
# 测试用 Mock Broker——不继承 BaseBroker
class FakeBroker:
    def place_order(self, order: Order) -> str:
        return "mock_order_001"
    def get_positions(self) -> List[Position]:
        return []
    def get_account(self) -> dict:
        return {"cash": 100000}

# 注册为 BaseBroker 的虚拟子类
BaseBroker.register(FakeBroker)

# 现在 FakeBroker 可以通过 isinstance 检查
broker = FakeBroker()
assert isinstance(broker, BaseBroker)  # True
```

> [!tip] 何时使用 register vs 显式继承
> `register()` 适用于你**无法修改源类**的场景（第三方库、内建类型）。对于自己的代码，显式继承是更好的选择——它提供了完整的多态性支持、IDE 自动补全和静态类型检查。`register()` 只影响 `isinstance` 检查，不影响方法实现——`FakeBroker` 如果漏了 `get_account`，`isinstance` 依然返回 True。

---

## 3. Key Takeaways

### When to Use These Techniques

| 模式 | 适用场景 |
|------|---------|
| **ABC + @abstractmethod** | 定义可替换组件的接口契约（Plugin、Strategy、Driver）|
| **@property + @abstractmethod** | 强制子类提供元数据、配置、状态标志 |
| **register()** | 将第三方库/测试 mock 注册为虚拟子类 |
| **__subclasshook__** | 基于方法存在性自动判断子类型（类 duck typing 的 ABC）|
| **ABC 组合 Decotrator** | ABC 定义接口，装饰器注入横切关注点（重试、日志、缓存）|

### Common Pitfalls to Avoid

- **抽象方法太多**：ABC 的每个 `@abstractmethod` 都是子类的负担。如果一个方法 90% 的子类实现相同，在基类提供默认实现而非设为抽象
- **register() 不会检查方法实现**：`BaseBroker.register(FakeBroker)` 通过 isinstance 检查，但 `FakeBroker` 缺少任何方法都不会报错。register 不是契约检查
- **ABC 与 __init_subclass__ 的冲突**：如果基类使用 `__init_subclass__` 钩子，子类继承时可能意外触发副作用。用 ABC 时注意 `__init_subclass__` 的执行顺序
- **Python 2 的 @abstractproperty 已废弃**：在 Python 3.3+ 中，用 `@property` 和 `@abstractmethod` 组合代替。两者顺序不能错：`@property` 在 `@abstractmethod` 上方
- **ABC 的性能成本**：实例化时的抽象方法检查有微小开销（毫秒级），对高频创建的对象（如每 batch 的临时对象）有累积影响。缓存或对象池可缓解

### Related Concepts & Further Reading

- [[Python - Decorators]] — ABC + Decotrator 的组合是 CTM Strategy Pattern 的核心
- [[PyTorch - Custom Gradients]] — PyTorch `nn.Module` 实质上是 ABC 思想的体现（`forward()` 是隐含的 @abstractmethod）
- Python `abc` 模块官方文档 — `ABCMeta`, `abstractmethod`, `register`, `__subclasshook__`
- PEP 3119 — Introducing Abstract Base Classes（Python 2.6/3.0）
- PEP 544 — Protocols: Structural subtyping (static duck typing)
- *Design Patterns* (GoF) — Strategy Pattern, Template Method Pattern 的经典实现
