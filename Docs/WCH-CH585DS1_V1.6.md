# 概述

CH585 是集成 BLE 无线通讯和高速 USB 及 NFC 的 RISC-V MCU/SoC。片上集成了 2Mbps 低功耗蓝牙BLE通讯模块、USB全速控制器及收发器、USB高速控制器及收发器（480Mbps）、NFC近场通信无线接口、段式LCD驱动模块、LED点阵屏接口、2个SPI、4个串口、14路ADC、触摸按键检测模块等丰富的外设资源。

# 功能

#  内核 Core：

- 青稞 32 位 RISC-V3C 内核
- 支持 RV32IMBC 指令集和自扩展指令
- 低功耗三级流水线
- 多档系统主频，最低 32KHz，最高 78MHz
- 特有高速的中断响应机制

#  512K 字节非易失存储 FlashROM：

- 448KB 用户应用程序存储区 CodeFlash
- 32KB 用户非易失数据存储区 DataFlash
- 24KB 系统引导程序存储区 BootLoader
- 8KB 系统非易失配置信息存储区 InfoFlash
- 支持 ICP、ISP 和 IAP，支持 OTA 无线升级

#  128K 字节易失数据存储 SRAM：

- 96KB双电源供电的睡眠保持存储区RAM96K
- 32KB双电源供电的睡眠保持存储区RAM32K

# $\bullet$ 电源管理和低功耗：

- 支持 $1 . 8 5 \mathsf { V } { \sim } 3 . 6 \mathsf { V }$ 电源
- 内置DC-DC转换，可降低功耗
- 空闲模式 Idle：1.44mA（PLL/HSE 不停止）
- 暂停模式 Halt：1.01mA（PLL/HSE 不停止）200uA（PLL/HSE 停止）
- 睡眠模式 Sleep：2.6uA～8.2uA 多档
- 下电模式 Shutdown：0.65uA～5.5uA 多档
- 3.3V 关闭 DC-DC 时，蓝牙接收电流：5.8mA
- 3.3V 启用 DC-DC 时，蓝牙接收电流：3.0mA
- 可选低功耗或高精度的电池电压低压监控

# $\bullet$ 安全特性：AES-128 加解密，芯片唯一 ID

# $\bullet$ 低功耗蓝牙 BLE：

- 集成2.4GHz RF收发器和基带及链路控制
- 接收灵敏度-95dBm，可编程 $+ 4 . 5 { \mathsf { d B m } }$ 发送功率
- BLE 符合 Bluetooth Low Energy 5.4 规范
- 支持 2Mbps 和 1Mbps
- 支持 2.4G 模式下最高 8KHz 上报率
- 提供优化的协议栈和应用层API，支持组网

# $\bullet$ 实时时钟RTC：支持定时和触发两种模式

$\bullet$ 段式LCD：支持112点（ $2 8 ^ { \* 4 }$ ）LCD 面板

LED点阵屏接口：支持1/2/4/8路数据线

 时钟：内置 PLL、16MHz 和 32KHz 时钟

#  1 组全速 USB 2.0 控制器及 PHY：

- 15个端点，支持64字节数据包，支持DMA
- 支持全/低速的 Host 主机和 Device 设备模式

#  1 组 480Mbps 高速 USB 2.0 控制器及 PHY：

- 支持1024字节数据包，支持DMA
- 支持高/全速的 Host 主机和 Device 设备模式

# 近场通信无线接口NFC：

- 支持读卡器模式和卡模式
- 支持ISO14443-A类卡片读取、写入等操作

# 模数转换ADC：

- 12位模数转换器，支持差分和单端输入
- 14路外部模拟信号通道和3路内部信号

# 触摸按键检测模块TouchKey：14路通道

#  定时器 Timer 和脉宽调制 PWM：

- 4 组 26 位定时器，16MHz 主频定时可达 4.2S
- 4 路捕捉/采样，支持上升沿/下降沿/双边沿
- 4 路 26 位 PWM 输出
- 8 路 8 位 PWM 输出或前 6 路 16 位 PWM 输出

#  异步串口 UART：

- 4 组独立 UART，兼容 16C550，内置 8 级 FIFO
- 23位计数器，通讯波特率可达9Mbps
- UART0支持部分Modem，支持硬件自动流控
- UART0支持多机通讯时从机地址自动匹配

# 串行外设接口SPI：

- 2 组独立 SPI，内置 FIFO
- 支持 Master 和 Slave 模式，支持 DMA

# 两线串行接口I2C：

- 支持 Master 和 Slave 模式，兼容 SMBus
- 支持7位或10位地址和总线广播

# 温度传感器TS

# $\bullet$ 单/双线仿真调试接口

# 通用输入输出端口GPIO：

- 40 个 GPIO，其中 2 个支持 5V 信号输入
- 可选上拉或下拉电阻，可选输出驱动能力
- 32个GPIO支持中断输入和唤醒输入

# 封装形式：QFN

CH584 基于 CH585 简化，去掉了一组 USBHS 和 SPI1 模块，RAM 容量为 96KB。

<table><tr><td>芯片型号</td><td>用户闪存+引导闪存+数据闪存</td><td>数据存储RAM</td><td>RTC时钟</td><td>定时器</td><td>捕捉</td><td>PWM</td><td>串口</td><td>SPI</td><td>I2C</td><td>BLE蓝牙</td><td>ADC及TS</td><td>电容触摸按键</td><td>USBFS</td><td>USBHS</td><td>DC-DC</td><td>通用I/O</td><td>NFC</td><td>LED点阵屏接口</td><td>段式LCD</td><td>封装形式</td></tr><tr><td>CH585M</td><td>448+24+32K</td><td>128K</td><td rowspan="7">✓</td><td>4</td><td>4</td><td>4+8</td><td>4</td><td>2</td><td>1</td><td rowspan="7">✓</td><td>14+1</td><td>14路</td><td>1</td><td>1</td><td rowspan="7">✓</td><td>40</td><td rowspan="3">✓</td><td>1/2/4/8路</td><td>28*4</td><td>QFN48</td></tr><tr><td>CH585F</td><td>448+24+32K</td><td>128K</td><td>4</td><td>4</td><td>4+7</td><td>4</td><td>1</td><td>1</td><td>7+1</td><td>7路</td><td>1</td><td>1</td><td>24</td><td>-</td><td>14*4</td><td>QFN32</td></tr><tr><td>CH585C</td><td>448+24+32K</td><td>128K</td><td>4</td><td>4</td><td>4+5</td><td>2</td><td>1</td><td>-</td><td>4+1</td><td>-</td><td>1</td><td>1</td><td>17</td><td>-</td><td>-</td><td>QFN26C3</td></tr><tr><td>CH585D</td><td>448+24+32K</td><td>128K</td><td>4</td><td>4</td><td>4+3</td><td>2</td><td>1</td><td>-</td><td>4+1</td><td>-</td><td>1</td><td>1</td><td>12</td><td>-</td><td>-</td><td>-</td><td>QFN20</td></tr><tr><td>CH584M</td><td>448+24+32K</td><td>96K</td><td>4</td><td>4</td><td>4+8</td><td>4</td><td>1</td><td>1</td><td>14+1</td><td>14路</td><td>1</td><td>-</td><td>40</td><td rowspan="3">✓</td><td>1/2/4/8路</td><td>28*4</td><td>QFN48</td></tr><tr><td>CH584X</td><td>480+24+512K</td><td>96K</td><td>4</td><td>4</td><td>4+8</td><td>4</td><td>1</td><td>1</td><td>14+1</td><td>14路</td><td>1</td><td>-</td><td>40</td><td>1/2/4/8路</td><td>28*4</td><td>QFN48</td></tr><tr><td>CH584F</td><td>448+24+32K</td><td>96K</td><td>4</td><td>4</td><td>4+7</td><td>4</td><td>1</td><td>1</td><td>7+1</td><td>7路</td><td>1</td><td>-</td><td>24</td><td>-</td><td>14*4</td><td>QFN32</td></tr></table>

# 第 1 章 引脚信息

# 1.1 引脚排列

# 1.1.1 CH585 引脚排列

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/253162239681a8283a1c6476fa72587a06c3d63f3b683455bfb75485b3062bce.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/bfeaddb58c85ac109bfe58ff49ec808d6d4aa549ea008ac787936989d3d903cc.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/19913a7dc1a34c3ea66196fa37d244c0fbaff1870457a1056280a11f3b341ca9.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/62b5948b7dd7f246d0ae4a246a281ab42a9fd5743522613fe2d3eba15feb3d32.jpg null)

# 1.1.2 CH584 引脚排列

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/6cb89302414e4c41010c82f84b8479c677f7f38668e31ca5e88ea24c99cf6330.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/c13fe9d9b3fc2e7fd9a9b153f92fc059f189018dfd7cabfe1393634c8e2b1300.jpg null)

# 1.2 引脚描述

注意，下表中的引脚功能描述针对的是所有功能，不涉及具体型号产品。不同型号之间外设资源有差异，查看前请先根据产品型号资源表确认是否有此功能。

注：1.引脚类型： $\boldsymbol { P } =$ 电源； $I \ = \ T T L / C M O S$ 电平斯密特输入； $0 \ : = \ : c m o s$ 电平三态输出；

表 1-1 CH585 引脚定义

$A \ =$ 模拟信号输入或输出； 5VT $=$ 支持5V信号电压输入。

<table><tr><td colspan="4">引脚编号</td><td rowspan="2">引脚名称</td><td rowspan="2">引脚类型(1)</td><td rowspan="2">复用功能在前优先</td><td rowspan="2">功能描述(2)</td></tr><tr><td>CH585C</td><td>CH585F</td><td>CH585M</td><td>CH585D</td></tr><tr><td>0</td><td>0</td><td>0</td><td>0</td><td>GND</td><td>P</td><td>-</td><td>芯片底板,公共接地端,电压0V参考点。</td></tr><tr><td>3</td><td>-</td><td>-</td><td>-</td><td>GND</td><td>P</td><td>-</td><td>公共接地端,电压0V参考点。</td></tr><tr><td>13</td><td>2</td><td>1</td><td>1</td><td>VDCID</td><td>P</td><td>-</td><td>内部数字电路LDO调整器的电源输入,需外接退耦电容。启用DC-DC时建议4.7uF(支持1uF~10uF,容值小DC-DC效率略有下降),不启用DC-DC时建议不小于1uF。</td></tr><tr><td>14</td><td>3</td><td>2</td><td>2</td><td>VSW</td><td>P</td><td>-</td><td>DC-DC开关输出,启用DC-DC时必须贴近引脚串接电感连接VDCID,建议用10uH电感(支持4.7uH~22uH,感值小DC-DC效率略有下降),不启用DC-DC时可以直连VDCID。</td></tr><tr><td rowspan="2">15</td><td rowspan="2">4</td><td rowspan="2">3</td><td rowspan="2">3</td><td>VDD33</td><td>P</td><td>VBAT</td><td>DC-DC或电池电源输入,需贴近引脚外接退耦电容。启用时建议2.2uF或1uF,不启用DCDC时建议不小于1uF。</td></tr><tr><td>VI033</td><td>P</td><td>-</td><td>I/0电源输入。</td></tr><tr><td>-</td><td>-</td><td>4</td><td>-</td><td>PA7</td><td>I/0/A</td><td>TXD2/PWM5_/LED6/A11</td><td>PA7:通用双向数字I/0引脚。TXD2:UART2串行数据输出。PWM5_:脉宽调制输出通道5引脚映射。LED6:LED屏接口串行数据输出6。A11:ADC模拟信号输入通道11。</td></tr><tr><td>-</td><td>-</td><td>5</td><td>-</td><td>PA8</td><td>I/0/A</td><td>RXD1/LED7/A12</td><td>PA8:通用双向数字I/0引脚。RXD1:UART1串行数据输入。LED7:LED屏接口串行数据输出7。A12:ADC模拟信号输入通道12。</td></tr><tr><td rowspan="2">16</td><td rowspan="2">5</td><td>6</td><td>4</td><td>PA9(4)</td><td>I/0/A</td><td>TMRO/TXD1/A13</td><td>PA9:通用双向数字I/0引脚。TMRO:定时器0的捕捉输入0和PWM输出通道0。TXD1:UART1串行数据输出。A13:ADC模拟信号输入通道13。</td></tr><tr><td>7</td><td>-</td><td>PB9(4)</td><td>I/0/A</td><td>NFCI</td><td>PB9:通用双向数字I/0引脚。NFCI:NFC模拟输入。</td></tr><tr><td>17</td><td>6</td><td>8</td><td>-</td><td>PB8</td><td>I/0/A</td><td>NFCM</td><td>PB8:通用双向数字I/0引脚。NFCM:NFC模拟输入。</td></tr><tr><td>18</td><td>7</td><td>9</td><td>-</td><td>PB17</td><td>I/0/A</td><td>NFC+</td><td>PB17:通用双向数字I/0引脚。NFC+:NFC模拟输出P端。</td></tr><tr><td>19</td><td>8</td><td>10</td><td>-</td><td>PB16</td><td>I/0/A</td><td>NFC-</td><td>PB16:通用双向数字I/0引脚。NFC-:NFC模拟输出N端。</td></tr><tr><td>20</td><td>9</td><td>11</td><td>5</td><td>PB15(3)</td><td>I/0/5VT</td><td>TCK/MISO_/DTR_</td><td>PB15:通用双向数字I/0引脚。TCK(3):仿真调试接口的串行时钟输入。MISO_:SPI0的MISO引脚映射。DTR_:UART0的DTR引脚映射。</td></tr><tr><td>21</td><td>10</td><td>12</td><td>6</td><td>PB14(3)</td><td>I/0/5VT</td><td>TIO</td><td>PB14:通用双向数字I/0引脚。</td></tr><tr><td>CH685C</td><td>CH685F</td><td>CH685M</td><td>CH685D</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td>/MOSI_/PWM10/DSR_</td><td>T10(3):仿真调试接口的串行数据输入输出,内置上拉。MOSI_:SPI0的MOSI引脚映射。PWM10:脉宽调制输出通道10。DSR_:UART0的DSR引脚映射。</td></tr><tr><td>22</td><td>11</td><td>13</td><td>7</td><td>PB13</td><td>I/0</td><td>U2D+/SCK0_/SCL/TXD1_</td><td>PB13:通用双向数字I/0引脚。U2D+:高速USB 2.0的D+数据线。SCK0_:SPI0的SCK引脚映射。SCL:I2C串行时钟引脚,主机输出和输入/从机输入。TXD1_:UART1的TXD1引脚映射。</td></tr><tr><td>23</td><td>12</td><td>14</td><td>8</td><td>PB12</td><td>I/0</td><td>U2D-/SCS_/SDA/RXD1_</td><td>PB12:通用双向数字I/0引脚。U2D-:高速USB 2.0的D-数据线。SCS_:SPI0的SCS引脚映射。SDA:I2C串行数据引脚,开漏输出和输入。RXD1_:UART1的RXD1引脚映射。</td></tr><tr><td>24</td><td>13</td><td>15</td><td>9</td><td>PB11</td><td>I/0/A</td><td>UD+/TMR2_</td><td>PB11:通用双向数字I/0引脚。UD+:全速USB 2.0的D+数据线。TMR2_:定时器2的TMR2引脚映射。</td></tr><tr><td>25</td><td>14</td><td>16</td><td>10</td><td>PB10</td><td>I/0/A</td><td>UD-/TMR1_</td><td>PB10:通用双向数字I/0引脚。UD-:全速USB 2.0的D-数据线。TMR1_:定时器1的TMR1引脚映射。</td></tr><tr><td>-</td><td>15</td><td>17</td><td>-</td><td>PB7</td><td>I/0</td><td>TXDO/PWM9</td><td>PB7:通用双向数字I/0引脚。TXDO:UART0串行数据输出。PWM9:脉宽调制输出通道9。</td></tr><tr><td>-</td><td>16</td><td>18</td><td>-</td><td>PB6</td><td>I/0</td><td>RTS/PWM8</td><td>PB6:通用双向数字I/0引脚。RTS:UART0的MODEM输出信号,请求发送。PWM8:脉宽调制输出通道8。</td></tr><tr><td>-</td><td>17</td><td>19</td><td>-</td><td>PB5</td><td>I/0</td><td>DTR</td><td>PB5:通用双向数字I/0引脚。DTR:UART0的MODEM输出信号,数据终端就绪。</td></tr><tr><td>26</td><td>18</td><td>20</td><td>-</td><td>PB4</td><td>I/0</td><td>RXDO/PWM7</td><td>PB4:通用双向数字I/0引脚。RXDO:UART0串行数据输入。PWM7:脉宽调制输出通道7。</td></tr><tr><td>-</td><td>-</td><td>21</td><td>-</td><td>PB3</td><td>I/0</td><td>DCD/PWM9_</td><td>PB3:通用双向数字I/0引脚。DCD:UART0的MODEM输入信号,载波检测。PWM9_:脉宽调制输出通道9引脚映射。</td></tr><tr><td>-</td><td>-</td><td>22</td><td>-</td><td>PB2</td><td>I/0</td><td>PWM8_</td><td>PB2:通用双向数字I/0引脚。PWM8_:脉宽调制输出通道8引脚映射。</td></tr><tr><td>-</td><td>-</td><td>23</td><td>-</td><td>PB1</td><td>I/0</td><td>DSR/PWM7_</td><td>PB1:通用双向数字I/0引脚。DSR:UART0的MODEM输入信号,数据装置就绪。PWM7_:脉宽调制输出通道7引脚映射。</td></tr><tr><td>-</td><td>-</td><td>24</td><td>-</td><td>PBO</td><td>I/0</td><td>CTS/PWM6</td><td>PBO:通用双向数字I/0引脚。CTS:UART0的MODEM输入信号,清除发送。PWM6:脉宽调制输出通道6。</td></tr><tr><td>1</td><td>19</td><td>25</td><td>-</td><td>PB23</td><td>I/0</td><td>/TMR0_</td><td>PB23:通用双向数字I/0引脚。</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td>/TXD2_/PWM11/RST</td><td>TMRO_:定时器0的TMRO引脚映射。TXD2_:UART2的TXD2引脚映射。PWM11:脉宽调制输出通道11。RST:外部复位输入,低电平有效,内置上拉电阻。</td></tr><tr><td>2</td><td>20</td><td>26</td><td>11</td><td>PB22</td><td>I/0</td><td>TMR3/RXD2_</td><td>PB22:通用双向数字I/0引脚。TMR3:定时器3的捕捉输入3和PWM输出通道3。RXD2_:UART2的RXD2引脚映射。</td></tr><tr><td>-</td><td>-</td><td>27</td><td>-</td><td>PB21</td><td>I/0</td><td>SCL_/TXD3_</td><td>PB21:通用双向数字I/0引脚。SCL_:I2C串行时钟引脚映射。TXD3_:UART3的TXD3引脚映射。</td></tr><tr><td>-</td><td>-</td><td>28</td><td>-</td><td>PB20</td><td>I/0</td><td>SDA_/RXD3_</td><td>PB20:通用双向数字I/0引脚。SDA_:I2C串行数据引脚映射。RXD3_:UART3的RXD3引脚映射。</td></tr><tr><td>-</td><td>-</td><td>29</td><td>-</td><td>PB19</td><td>I/0</td><td>-</td><td>PB19:通用双向数字I/0引脚。</td></tr><tr><td>-</td><td>-</td><td>30</td><td>-</td><td>PB18</td><td>I/0</td><td>-</td><td>PB18:通用双向数字I/0引脚。</td></tr><tr><td>4</td><td>21</td><td>31</td><td>12</td><td>X32MO</td><td>I/A</td><td>-</td><td>高频振荡器HSE的反相输出端,外接32MHz晶体的一端。</td></tr><tr><td>5</td><td>22</td><td>32</td><td>13</td><td>X32MI</td><td>A</td><td>-</td><td>高频振荡器HSE的输入端,外接32MHz晶体的另一端。</td></tr><tr><td>6</td><td>23</td><td>33</td><td>14</td><td>VINTA</td><td>P</td><td>-</td><td>内部模拟电路的电源节点,需贴近引脚外接退耦电容。不启用DC-DC时建议0.47uF;启用DC-DC时建议不小于0.47uF(支持0.47uF~2.2uF,容值大功耗略大)。</td></tr><tr><td>7</td><td>24</td><td>34</td><td>15</td><td>ANT</td><td>A</td><td>-</td><td>RF射频信号输入输出,建议直连天线。</td></tr><tr><td>8</td><td>25</td><td>35</td><td>16</td><td>VDCIA</td><td>P</td><td>-</td><td>内部模拟电路LDO调整器的电源输入,需外接退耦电容。建议0.1uF,直连VDCID。</td></tr><tr><td>-</td><td>26</td><td>36</td><td>-</td><td>PA4</td><td>I/0/A</td><td>RXD3/LEDC/A0</td><td>PA4:通用双向数字I/0引脚。RXD3:UART3串行数据输入。LEDC:LED屏接口串行时钟输出。A0:ADC模拟信号输入通道0。</td></tr><tr><td>-</td><td>27</td><td>37</td><td>-</td><td>PA5</td><td>I/0/A</td><td>TXD3/LED4/A1</td><td>PA5:通用双向数字I/0引脚。TXD3:UART3串行数据输出。LED4:LED屏接口串行数据输出4。A1:ADC模拟信号输入通道1。</td></tr><tr><td>-</td><td>-</td><td>38</td><td>-</td><td>PA6</td><td>I/0/A</td><td>RXD2/PWM4_/LED5/A10</td><td>PA6:通用双向数字I/0引脚。RXD2:UART2串行数据输入。PWM4_:脉宽调制输出通道4引脚映射。LED5:LED屏接口串行数据输出5。A10:ADC模拟信号输入通道10。</td></tr><tr><td>-</td><td>-</td><td>39</td><td>-</td><td>PAO</td><td>I/0/A</td><td>SCK1/LEDO/A9</td><td>PAO:通用双向数字I/0引脚。SCK1:SPI1串行时钟引脚,主机输出。LEDO:LED屏接口串行数据输出0。A9:ADC模拟信号输入通道9。</td></tr><tr><td>-</td><td>-</td><td>40</td><td>-</td><td>PA1</td><td>I/0/A</td><td>MOS11/LED1/A8</td><td>PA1:通用双向数字I/0引脚。MOS11:SPI1串行数据引脚,主机输出。LED1:LED屏接口串行数据输出1。</td></tr><tr><td>CH585C</td><td>CH585F</td><td>CH585M</td><td colspan="5">CH585D</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>A8: ADC模拟信号输入通道8。</td></tr><tr><td>-</td><td>-</td><td>41</td><td>-</td><td>PA2</td><td>I/0/A</td><td>TMR3_/_MISO1/RI/LED2/A7</td><td>PA2:通用双向数字I/0引脚。TMR3_:定时器3的TMR3引脚映射。MISO1:SPI1串行数据引脚,主机输入。RI:UART0的MODEM输入信号,振铃指示。LED2:LED屏接口串行数据输出2。A7:ADC模拟信号输入通道7。</td></tr><tr><td>-</td><td>-</td><td>42</td><td>-</td><td>PA3</td><td>I/0/A</td><td>LED3/A6</td><td>PA3:通用双向数字I/0引脚。LED3:LED屏接口串行数据输出3。A6:ADC模拟信号输入通道6。</td></tr><tr><td>9</td><td>28</td><td>43</td><td>17</td><td>PA15</td><td>I/0/A</td><td>MISO/RXDO_/A5</td><td>PA15:通用双向数字I/0引脚。MISO:SPI0串行数据引脚,主机输入/从机输出。RXDO_:UART0的RXDO引脚映射。A5:ADC模拟信号输入通道5。</td></tr><tr><td>10</td><td>29</td><td>44</td><td>18</td><td>PA14</td><td>I/0/A</td><td>MOSI/TXD0_/A4</td><td>PA14:通用双向数字I/0引脚。MOSI:SPI0串行数据引脚,主机输出/从机输入。TXDO_:UART0的TXDO引脚映射。A4:ADC模拟信号输入通道4。</td></tr><tr><td>11</td><td>30</td><td>45</td><td>19</td><td>PA13</td><td>I/0/A</td><td>SCKO/PWM5/A3</td><td>PA13:通用双向数字I/0引脚。SCKO:SPI0串行时钟引脚,主机输出/从机输入。PWM5:脉宽调制输出通道5。A3:ADC模拟信号输入通道3。</td></tr><tr><td>12</td><td>31</td><td>46</td><td>20</td><td>PA12</td><td>I/0/A</td><td>SCS/PWM4/A2</td><td>PA12:通用双向数字I/0引脚。SCS:SPI0从机模式下的片选输入,低电平有效。PWM4:脉宽调制输出通道4。A2:ADC模拟信号输入通道2。</td></tr><tr><td>-</td><td>32</td><td>47</td><td>-</td><td>PA11</td><td>I/0/A</td><td>X32K0/TMR2</td><td>PA11:通用双向数字I/0引脚。X32K0:低频振荡器的反相输出端,外接32KHz晶体的一端。TMR2:定时器2的捕捉输入2和PWM输出通道2。</td></tr><tr><td>-</td><td>1</td><td>48</td><td>-</td><td>PA10</td><td>I/0/A</td><td>X32KI/TMR1</td><td>PA10:通用双向数字I/0引脚。X32KI:低频振荡器的输入端,外接32KHz晶体的另一端。TMR1:定时器1的捕捉输入1和PWM输出通道1。</td></tr></table>

2.引脚的复用功能及映射根据其优先级在表中按从高到底排列，其中GPI0功能为最低优先级。

3.单/双线仿真调试接口通过ISP工具配置。仿真调试接口启用后，PB15和PB14仅用作TCK和TI0，不再用于GPI0或外设复用功能引脚。关闭仿真调试接口后，PB15和PB14才可用于GPI0和外设复用功能引脚。使用单线仿真调试接口时必须开启HSI时钟。

4.对于CH585F和CH585C芯片，PA9和PB9引脚在芯片内部短接合封，禁止将两个I0均配置为输出功能。

表 1-2 CH584 引脚定义

<table><tr><td colspan="2">引脚编号</td><td rowspan="2">引脚名称</td><td rowspan="2">引脚类型(1)</td><td rowspan="2">复用功能在前优先</td><td rowspan="2">功能描述(2)</td></tr><tr><td>CH584F</td><td>CH584M/X</td></tr><tr><td>0</td><td>0</td><td>GND</td><td>P</td><td>-</td><td>芯片底板,公共接地端,电压0V参考点。</td></tr><tr><td>-</td><td>-</td><td>GND</td><td>P</td><td>-</td><td>公共接地端,电压0V参考点。</td></tr><tr><td>2</td><td>1</td><td>VDCID</td><td>P</td><td>-</td><td>内部数字电路LDO调整器的电源输入,需外接退耦电容。启用DC-DC时建议4.7uF(支持1uF~10uF,容值小DC-DC效率略有下降),不启用DC-DC时建议不小于1uF。</td></tr><tr><td>3</td><td>2</td><td>VSW</td><td>P</td><td>-</td><td>DC-DC开关输出,启用DC-DC时必须贴近引脚串接电感连接VDCID,建议用10uH电感(支持4.7uH~22uH,感值小DC-DC效率略有下降),不启用DC-DC时可以直连VDCID。</td></tr><tr><td rowspan="2">4</td><td rowspan="2">3</td><td>VDD33</td><td>P</td><td>VBAT</td><td>DC-DC或电池电源输入,需贴近引脚外接退耦电容。启用时建议2.2uF或1uF,不启用DCDC时建议不小于1uF。</td></tr><tr><td>VI033</td><td>P</td><td>-</td><td>I/0电源输入。</td></tr><tr><td>-</td><td>4</td><td>PA7</td><td>I/0/A</td><td>TXD2/PWM5_/LED6/A11</td><td>PA7:通用双向数字I/0引脚。TXD2:UART2串行数据输出。PWM5_:脉宽调制输出通道5引脚映射。LED6:LED屏接口串行数据输出6。A11:ADC模拟信号输入通道11。</td></tr><tr><td>-</td><td>5</td><td>PA8</td><td>I/0/A</td><td>RXD1/LED7/A12</td><td>PA8:通用双向数字I/0引脚。RXD1:UART1串行数据输入。LED7:LED屏接口串行数据输出7。A12:ADC模拟信号输入通道12。</td></tr><tr><td rowspan="2">5</td><td>6</td><td>PA9(4)</td><td>I/0/A</td><td>TMRO/TXD1/A13</td><td>PA9:通用双向数字I/0引脚。TMRO:定时器0的捕捉输入0和PWM输出通道0。TXD1:UART1串行数据输出。A13:ADC模拟信号输入通道13。</td></tr><tr><td>7</td><td>PB9(4)</td><td>I/0/A</td><td>NFCI</td><td>PB9:通用双向数字I/0引脚。NFCI:NFC模拟输入。</td></tr><tr><td>6</td><td>8</td><td>PB8</td><td>I/0/A</td><td>NFCM</td><td>PB8:通用双向数字I/0引脚。NFCM:NFC模拟输入。</td></tr><tr><td>7</td><td>9</td><td>PB17</td><td>I/0/A</td><td>NFC+</td><td>PB17:通用双向数字I/0引脚。NFC+:NFC模拟输出P端。</td></tr><tr><td>8</td><td>10</td><td>PB16</td><td>I/0/A</td><td>NFC-</td><td>PB16:通用双向数字I/0引脚。NFC-:NFC模拟输出N端。</td></tr><tr><td>9</td><td>11</td><td>PB15(3)</td><td>I/0/5VT</td><td>TCK/MISO_/DTR_</td><td>PB15:通用双向数字I/0引脚。TCK(3):仿真调试接口的串行时钟输入。MISO_:SPI0的MISO引脚映射。DTR_:UART0的DTR引脚映射。</td></tr><tr><td>10</td><td>12</td><td>PB14(3)</td><td>I/0/5VT</td><td>TIO/MOSI_/PWM10/DSR_</td><td>PB14:通用双向数字I/0引脚。TIO(3):仿真调试接口的串行数据输入输出,内置上拉。MOSI_:SPI0的MOSI引脚映射。PWM10:脉宽调制输出通道10。DSR_:UART0的DSR引脚映射。</td></tr><tr><td>11</td><td>13</td><td>PB13</td><td>I/0</td><td>SCK0_/SCL/TXD1_</td><td>PB13:通用双向数字I/0引脚。SCK0_:SPI0的SCK引脚映射。SCL:12C串行时钟引脚,主机输出和输入/从机输入。TXD1_:UART1的TXD1引脚映射。</td></tr><tr><td>12</td><td>14</td><td>PB12</td><td>I/0</td><td>SCS_/SDA/RXD1_</td><td>PB12:通用双向数字I/0引脚。SCS_:SPI0的SCS引脚映射。SDA:12C串行数据引脚,开漏输出和输入。RXD1_:UART1的RXD1引脚映射。</td></tr><tr><td>13</td><td>15</td><td>PB11</td><td>I/0/A</td><td>UD+/TMR2_</td><td>PB11:通用双向数字I/0引脚。UD+:全速USB 2.0的D+数据线。TMR2_:定时器2的TMR2引脚映射。</td></tr><tr><td>14</td><td>16</td><td>PB10</td><td>I/0/A</td><td>UD-/TMR1_</td><td>PB10:通用双向数字I/0引脚。UD-:全速USB 2.0的D-数据线。TMR1_:定时器1的TMR1引脚映射。</td></tr><tr><td>15</td><td>17</td><td>PB7</td><td>I/0</td><td>TXDO/PWM9</td><td>PB7:通用双向数字I/0引脚。TXDO:UART0串行数据输出。PWM9:脉宽调制输出通道9。</td></tr><tr><td>16</td><td>18</td><td>PB6</td><td>I/0</td><td>RTS/PWM8</td><td>PB6:通用双向数字I/0引脚。RTS:UART0的MODEM输出信号,请求发送。PWM8:脉宽调制输出通道8。</td></tr><tr><td>17</td><td>19</td><td>PB5</td><td>I/0</td><td>DTR</td><td>PB5:通用双向数字I/0引脚。DTR:UART0的MODEM输出信号,数据终端就绪。</td></tr><tr><td>18</td><td>20</td><td>PB4</td><td>I/0</td><td>RXDO/PWM7</td><td>PB4:通用双向数字I/0引脚。RXDO:UART0串行数据输入。PWM7:脉宽调制输出通道7。</td></tr><tr><td>-</td><td>21</td><td>PB3</td><td>I/0</td><td>DCD/PWM9_</td><td>PB3:通用双向数字I/0引脚。DCD:UART0的MODEM输入信号,载波检测。PWM9_:脉宽调制输出通道9引脚映射。</td></tr><tr><td>-</td><td>22</td><td>PB2</td><td>I/0</td><td>PWM8_</td><td>PB2:通用双向数字I/0引脚。PWM8_:脉宽调制输出通道8引脚映射。</td></tr><tr><td>-</td><td>23</td><td>PB1</td><td>I/0</td><td>DSR/PWM7_</td><td>PB1:通用双向数字I/0引脚。DSR:UART0的MODEM输入信号,数据装置就绪。PWM7_:脉宽调制输出通道7引脚映射。</td></tr><tr><td>-</td><td>24</td><td>PBO</td><td>I/0</td><td>CTS/PWM6</td><td>PBO:通用双向数字I/0引脚。CTS:UART0的MODEM输入信号,清除发送。PWM6:脉宽调制输出通道6。</td></tr><tr><td>19</td><td>25</td><td>PB23</td><td>I/0</td><td>/TMR0_/TXD2_/PWM11/RST</td><td>PB23:通用双向数字I/0引脚。TMRO_:定时器0的TMRO引脚映射。TXD2_:UART2的TXD2引脚映射。PWM11:脉宽调制输出通道11。RST:外部复位输入,低电平有效,内置上拉电阻。</td></tr><tr><td>20</td><td>26</td><td>PB22</td><td>I/0</td><td>TMR3/RXD2_</td><td>PB22:通用双向数字I/0引脚。TMR3:定时器3的捕捉输入3和PWM输出通道3。</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td>RXD2_: UART2 的 RXD2 引脚映射。</td></tr><tr><td>-</td><td>27</td><td>PB21</td><td>I/0</td><td>SCL_/TXD3_</td><td>PB21: 通用双向数字 I/0 引脚。SCL_: I2C 串行时钟引脚映射。TXD3_: UART3 的 TXD3 引脚映射。</td></tr><tr><td>-</td><td>28</td><td>PB20</td><td>I/0</td><td>SDA_/RXD3_</td><td>PB20: 通用双向数字 I/0 引脚。SDA_: I2C 串行数据引脚映射。RXD3_: UART3 的 RXD3 引脚映射。</td></tr><tr><td>-</td><td>29</td><td>PB19</td><td>I/0</td><td>-</td><td>PB19: 通用双向数字 I/0 引脚。</td></tr><tr><td>-</td><td>30</td><td>PB18</td><td>I/0</td><td>-</td><td>PB18: 通用双向数字 I/0 引脚。</td></tr><tr><td>21</td><td>31</td><td>X32M0</td><td>I/A</td><td>-</td><td>高频振荡器 HSE 的反相输出端,外接 32MHz 晶体的一端。</td></tr><tr><td>22</td><td>32</td><td>X32MI</td><td>A</td><td>-</td><td>高频振荡器 HSE 的输入端,外接 32MHz 晶体的另一端。</td></tr><tr><td>23</td><td>33</td><td>VINTA</td><td>P</td><td>-</td><td>内部模拟电路的电源节点,需贴近引脚外接退耦电容。不启用 DC-DC 时建议 0.47uF; 启用 DC-DC 时建议不小于 0.47uF (支持 0.47uF~2.2uF,容值大功耗略大)。</td></tr><tr><td>24</td><td>34</td><td>ANT</td><td>A</td><td>-</td><td>RF 射频信号输入输出,建议直连天线。</td></tr><tr><td>25</td><td>35</td><td>VDCIA</td><td>P</td><td>-</td><td>内部模拟电路 LDO 调整器的电源输入,需外接退耦电容。建议 0.1uF,直连 VDCID。</td></tr><tr><td>26</td><td>36</td><td>PA4</td><td>I/0/A</td><td>RXD3/LEDC/A0</td><td>PA4: 通用双向数字 I/0 引脚。RXD3: UART3 串行数据输入。LEDC: LED 屏接口串行时钟输出。A0: ADC 模拟信号输入通道 0。</td></tr><tr><td>27</td><td>37</td><td>PA5</td><td>I/0/A</td><td>TXD3/LED4/A1</td><td>PA5: 通用双向数字 I/0 引脚。TXD3: UART3 串行数据输出。LED4: LED 屏接口串行数据输出 4。A1: ADC 模拟信号输入通道 1。</td></tr><tr><td>-</td><td>38</td><td>PA6</td><td>I/0/A</td><td>RXD2/PWM4_/LED5/A10</td><td>PA6: 通用双向数字 I/0 引脚。RXD2: UART2 串行数据输入。PWM4_: 脉宽调制输出通道 4 引脚映射。LED5: LED 屏接口串行数据输出 5。A10: ADC 模拟信号输入通道 10。</td></tr><tr><td>-</td><td>39</td><td>PAO</td><td>I/0/A</td><td>/LED0/A9</td><td>PAO: 通用双向数字 I/0 引脚。LEDO: LED 屏接口串行数据输出 0。A9: ADC 模拟信号输入通道 9。</td></tr><tr><td>-</td><td>40</td><td>PA1</td><td>I/0/A</td><td>/LED1/A8</td><td>PA1: 通用双向数字 I/0 引脚。LED1: LED 屏接口串行数据输出 1。A8: ADC 模拟信号输入通道 8。</td></tr><tr><td>-</td><td>41</td><td>PA2</td><td>I/0/A</td><td>TMR3_/RI/LED2/A7</td><td>PA2: 通用双向数字 I/0 引脚。TMR3_: 定时器 3 的 TMR3 引脚映射。RI: UART0 的 MODEM 输入信号,振铃指示。LED2: LED 屏接口串行数据输出 2。A7: ADC 模拟信号输入通道 7。</td></tr><tr><td>-</td><td>42</td><td>PA3</td><td>I/0/A</td><td>LED3/A6</td><td>PA3: 通用双向数字 I/0 引脚。LED3: LED 屏接口串行数据输出 3。</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td>A6: ADC模拟信号输入通道6。</td></tr><tr><td>28</td><td>43</td><td>PA15</td><td>I/0/A</td><td>MISO/RXDO_/A5</td><td>PA15: 通用双向数字I/0引脚。MISO: SPI0串行数据引脚,主机输入/从机输出。RXDO_: UART0的RXDO引脚映射。A5: ADC模拟信号输入通道5。</td></tr><tr><td>29</td><td>44</td><td>PA14</td><td>I/0/A</td><td>MOSI/TXDO_/A4</td><td>PA14: 通用双向数字I/0引脚。MOSI: SPI0串行数据引脚,主机输出/从机输入。TXDO_: UART0的TXDO引脚映射。A4: ADC模拟信号输入通道4。</td></tr><tr><td>30</td><td>45</td><td>PA13</td><td>I/0/A</td><td>SCKO/PWM5/A3</td><td>PA13: 通用双向数字I/0引脚。SCKO: SPI0串行时钟引脚,主机输出/从机输入。PWM5: 脉宽调制输出通道5。A3: ADC模拟信号输入通道3。</td></tr><tr><td>31</td><td>46</td><td>PA12</td><td>I/0/A</td><td>SCS/PWM4/A2</td><td>PA12: 通用双向数字I/0引脚。SCS: SPI0从机模式下的片选输入,低电平有效。PWM4: 脉宽调制输出通道4。A2: ADC模拟信号输入通道2。</td></tr><tr><td>32</td><td>47</td><td>PA11</td><td>I/0/A</td><td>X32K0/TMR2</td><td>PA11: 通用双向数字I/0引脚。X32K0: 低频振荡器的反相输出端,外接32KHz晶体的一端。TMR2: 定时器2的捕捉输入2和PWM输出通道2。</td></tr><tr><td>1</td><td>48</td><td>PA10</td><td>I/0/A</td><td>X32KI/TMR1</td><td>PA10: 通用双向数字I/0引脚。X32KI: 低频振荡器的输入端,外接32KHz晶体的另一端。TMR1: 定时器1的捕捉输入1和PWM输出通道1。</td></tr></table>

注：1.引脚类型： $\boldsymbol { P } =$ 电源； $I \ = \ T T L / C M O S$ 电平斯密特输入；0=CM0S电平三态输出；A=模拟信号输入或输出；5VT $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ 支持5V信号电压输入。

2.引脚的复用功能及映射根据其优先级在表中按从高到底排列，其中GPI0功能为最低优先级。

3.单/双线仿真调试接口通过ISP工具配置。仿真调试接口启用后，PB15和PB14仅用作TCK和TI0，不再用于GPI0或外设复用功能引脚。关闭仿真调试接口后，PB15和PB14才可用于GPI0和外设复用功能引脚。使用单线仿真调试接口时必须开启HSI时钟。

4.对于CH584F芯片，PA9和PB9引脚在芯片内部短接合封，禁止将两个I0均配置为输出功能。

表 1-3 复用于段式 LCD驱动的引脚说明

<table><tr><td>引脚名称</td><td>类型</td><td>复用功能</td><td>功能描述</td></tr><tr><td>PB4~PB7</td><td>A</td><td>COM0~COM3</td><td>驱动段式 LCD 的各个公共端,根据需要选用部分或全部。这些公共端引脚由寄存器 R32_PIN_IN_DIS 中对应的位控制着。当该位为 0 时,这些公共引脚用于数字输入或其它非 LCD 功能;为 1 时,这些引脚为 LCD 段驱动。</td></tr><tr><td>PBO~PB3</td><td rowspan="5">A</td><td>SEGO~SEG3</td><td>驱动段式 LCD 的各个段,根据需要选用部分或全部。</td></tr><tr><td>PA0~PA3</td><td>SEG4~SEG7</td><td rowspan="4">这些段式 LCD 驱动的引脚分别由寄存器 R32_PIN_IN_DIS 和寄存器 R16_PIN_CONFIG 中对应的位分别控制着。当对应的位为 0 时,这些引脚用于数字输入或其它非 LCD 功能;为 1 时,这些引脚为 LCD 段驱动。</td></tr><tr><td>PB8~PB23</td><td>SEG8~SEG23</td></tr><tr><td>PA7~PA9</td><td>SEG24~SEG26</td></tr><tr><td>PA13</td><td>SEG27</td></tr></table>

# 第 2章 系统结构及存储器

# 2.1 系统结构

下图为CH585系统结构框图。内核是青稞RISC-V微处理器，详细说明参考青稞内核手册。

图 2-1 CH585 内部结构框图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/2d396fc573f57a07938447a2700eff885395607f8a0f9035d4ddd5dc90a0d5e6.jpg null)

# 2.2 存储器映像

CH585 的寻址空间主要包括 CODE 区/FlashROM、DATA 区/SRAM、外设等几个不同区域，详见下图所示。

图2-2 存储器映射图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/a0e72c38fba82b4baf06c83a0711255302cdf0038c7a34cd2a9f081b931f555f.jpg null)

# 2.3 存储器映像表

各存储器映射区域地址范围如下表所示：

表2-1 存储器映射区域地址

<table><tr><td>地址范围</td><td>用途</td><td>描述</td></tr><tr><td>0x00000000-0x0007FFFF</td><td>片上 CODE 区域，非易失存储器</td><td>512KB, FlashROM</td></tr><tr><td>0x00080000-0x1FFFFFF</td><td>保留</td><td>-</td></tr><tr><td>0x20000000-0x2001FFFF</td><td>片上 DATA 区域，易失存储器</td><td>128KB, SRAM</td></tr><tr><td>0x20020000-0x3FFFFFF</td><td>保留</td><td>-</td></tr><tr><td>0x40000000-0x4000FFFF</td><td>各种外设</td><td>多个外设模块</td></tr><tr><td>0x40010000-0xE000BFFF</td><td>保留</td><td>-</td></tr><tr><td>0xE0000000-0xE000FFFF</td><td>系统内部各种外设</td><td>系统控制空间 SCS</td></tr><tr><td>0xE0010000-0xFFFFFF</td><td>保留</td><td>-</td></tr></table>

# 2.3.1 片上 CODE 区域映射表

表 2-2-1 CODE 区域地址（针对除 CH584X 以外的 CH584 和 CH585 芯片）

<table><tr><td>地址范围</td><td>用途</td><td>描述</td></tr><tr><td>0x00000000-0x0006FFFF</td><td>用户应用程序存储区 CodeFlash</td><td>448KB</td></tr><tr><td>0x00070000-0x00077FFF</td><td>用户非易失数据存储区 DataFlash</td><td>32KB</td></tr><tr><td>0x00078000-0x0007DFFF</td><td>系统引导程序存储区 BootLoader</td><td>24KB</td></tr><tr><td>0x0007E000-0x0007FFFF</td><td>系统非易失配置信息存储区 InfoFlash</td><td>8KB</td></tr></table>

地址 0x0007E000-0x0007EEFF 的配置信息可以由用户通过工具设置。

表 2-2-2 CODE 区域地址（仅针对 CH584X 芯片）

<table><tr><td>地址范围</td><td>用途</td><td>描述</td></tr><tr><td>0x00000000-0x00077FFF</td><td>用户应用程序存储区 CodeFlash</td><td>480KB</td></tr><tr><td>-</td><td>用户非易失数据存储区 DataFlash</td><td>512KB</td></tr><tr><td>0x00078000-0x0007DFFF</td><td>系统引导程序存储区 BootLoader</td><td>24KB</td></tr><tr><td>0x0007E000-0x0007FFFF</td><td>系统非易失配置信息存储区 InfoFlash</td><td>8KB</td></tr></table>

地址 0x0007E000-0x0007EEFF 的配置信息可以由用户通过工具设置。

注：读取DataFlash的具体操作请参考例子程序。

表2-3 用户级非易失配置信息说明

<table><tr><td>位地址</td><td>名称</td><td>用途</td><td>默认值</td></tr><tr><td>位2~位0</td><td>RESERVED</td><td>保留</td><td>101b</td></tr><tr><td>位3</td><td>CFG_RESET_EN</td><td>RST外部手工复位输入引脚使能</td><td>0</td></tr><tr><td>位4</td><td>CFG_DEBUG_EN</td><td>单/双线仿真调试接口 SWD/TWD 使能</td><td>1</td></tr><tr><td>位5</td><td>CFG_IWDG_EN</td><td>独立看门狗使能</td><td>0</td></tr><tr><td>位6</td><td>CFG_BOOT_EN</td><td>系统引导程序 BootLoader 使能</td><td>1</td></tr><tr><td>位7</td><td>CFG_ROM_READ</td><td>FlashROM中的代码和数据保护模式:0-禁止编程器读出,程序保密;1-允许读出</td><td>1</td></tr><tr><td>位27~位8</td><td>RESERVED</td><td>保留</td><td>FFF0Fh</td></tr><tr><td>位31~位28</td><td>VALID_sig</td><td>配置信息有效标志,固定值</td><td>0100b</td></tr></table>

注：当CFG\_DEBUG\_EN=1、CFG\_RESET\_EN=O、CFG\_ROM\_READ=1，单/双线仿真调试接口启用。

# 2.3.2 片上 DATA 区域映射表

表 2-4 DATA 区域地址

<table><tr><td>地址范围</td><td>用途</td><td>描述</td></tr><tr><td>0x20000000-0x20017FFF</td><td>主+辅双电源供电的可独立保持存储区 RAM96K</td><td>96KB</td></tr><tr><td>0x20018000-0x2001FFFF</td><td>主+辅双电源供电的可独立保持存储区 RAM32K</td><td>32KB</td></tr></table>

# 2.3.3 外设地址分配

CH585主要包含以下外设，每个外设占用一定的地址空间，外设寄存器的实际访问地址为：基地址 $^ +$ 偏移地址。在后续章节中，寄存器的地址有详细说明。下表为各个外设基地址的分配表。

表2-5 外设基地址分配表

<table><tr><td>外设编号</td><td>外设名称</td><td>外设基址</td></tr><tr><td rowspan="2">1</td><td>SYS (PMU/RTC/GPIO等)</td><td rowspan="2">0x4000 1000</td></tr><tr><td>AUX (ADC/TKEY/PLL等)</td></tr><tr><td>2</td><td>FlashROM-Control</td><td>0x4000 1800</td></tr><tr><td>3</td><td>TMRO</td><td>0x4000 2000</td></tr><tr><td>4</td><td>TMR1</td><td>0x4000 2400</td></tr><tr><td>5</td><td>TMR2</td><td>0x4000 2800</td></tr><tr><td>6</td><td>TMR3</td><td>0x4000 2C00</td></tr><tr><td>7</td><td>UART0</td><td>0x4000 3000</td></tr><tr><td>8</td><td>UART1</td><td>0x4000 3400</td></tr><tr><td>9</td><td>UART2</td><td>0x4000 3800</td></tr><tr><td>10</td><td>UART3</td><td>0x4000 3C00</td></tr><tr><td>11</td><td>SPI0</td><td>0x4000 4000</td></tr><tr><td>12</td><td>SPI1</td><td>0x4000 4400</td></tr><tr><td>13</td><td>I2C</td><td>0x4000 4800</td></tr><tr><td>14</td><td>PWMx (PWM4~PWM11)</td><td>0x4000 5000</td></tr><tr><td>15</td><td>LCD</td><td>0x4000 6000</td></tr><tr><td>16</td><td>USBFS</td><td>0x4000 8000</td></tr><tr><td>17</td><td>USBHS</td><td>0x4000 9000</td></tr><tr><td rowspan="2">18</td><td rowspan="2">Radio:BLE</td><td>0x4000 C000</td></tr><tr><td>0x4000 D000</td></tr><tr><td>19</td><td>NFC</td><td>0x4000 E000</td></tr><tr><td>20</td><td>LED</td><td>0x4000 F000</td></tr></table>

下表为后续章节寄存器描述中“访问”的解释说明：

表2-6 访问属性说明

<table><tr><td>缩写词</td><td>描述</td></tr><tr><td>RF</td><td>只读且读取值为固定值，不受复位影响。</td></tr><tr><td>RO</td><td>只读。</td></tr><tr><td>WO</td><td>只写，读取值为0或无效。</td></tr><tr><td>RZ</td><td>只读，读取完之后自动清0。</td></tr><tr><td>WZ</td><td>写则清0。</td></tr><tr><td>RW</td><td>可读可写。</td></tr><tr><td>RW1Z</td><td>可读，写1则清0。</td></tr><tr><td>WA</td><td>只写且仅安全模式下，读取值为0或无效。</td></tr><tr><td>RWA</td><td>可读，仅安全模式下可写。</td></tr></table>

下表为后续章节中使用的缩写解释说明：

表2-7 名词缩写说明

<table><tr><td>缩写词</td><td>描述</td></tr><tr><td>HSE</td><td>外部高频晶体振荡时钟源（建议32MHz）</td></tr><tr><td>HSI</td><td>内部高频RC时钟振荡源（应用软件运行时校准后为16MHz）</td></tr><tr><td>LSE</td><td>外部低频晶体振荡时钟源（建议32KHz）</td></tr><tr><td>LSI</td><td>内部低频RC时钟振荡源（应用软件运行时校准后为32KHz）</td></tr><tr><td>CK32M</td><td>高频时钟源（默认32MHz）</td></tr><tr><td>TCK32M</td><td>高频时钟周期（1/CK32M）</td></tr><tr><td>CK16M</td><td>高频时钟源（默认16MHz）</td></tr><tr><td>TCK16M</td><td>高频时钟周期(1/CK16M)</td></tr><tr><td>CK32K</td><td>低频时钟源(默认32KHz)</td></tr><tr><td>Fpll</td><td>PLL输出时钟(624MHz)</td></tr><tr><td>HCLK</td><td>系统主频时钟</td></tr><tr><td>Fsys</td><td>系统主频时钟频率</td></tr><tr><td>Tsys</td><td>系统主频时钟周期(1/Fsys)</td></tr><tr><td>RAM32K</td><td>高地址的32KB SRAM</td></tr><tr><td>RAM96K</td><td>低地址的96KB SRAM</td></tr><tr><td>USBFS</td><td>USB全速</td></tr><tr><td>USBHS</td><td>USB高速</td></tr><tr><td>0x</td><td>以其开头的数据表示16进制数</td></tr><tr><td>h</td><td>以其结束的数据表示16进制数</td></tr><tr><td>b</td><td>以其结束的数据表示2进制数</td></tr></table>

# 第 3 章 中断

系统内置快速可编程中断控制器（Programmable Fast Interrupt Controller，PFIC），最多支持 256 个中断向量。当前系统管理了 24 个外设中断通道和 16 个内核中断通道，其他中断源保留。

# 3.1 中断控制器

24个外设中断，每个中断请求都有独立的触发和屏蔽控制位，有专用的状态位。

1个不可屏蔽中断NMI。

特有快速中断进出机制，硬件自动压栈和恢复，无需指令开销。

特有快速中断响应机制，4路可编程直达中断向量地址。

# 3.2 系统 SysTick 定时器

内核自带了一个32位计数器（SysTick），支持HCLK或者HCLK/8作为时基，具有较高优先级。

# 3.3 中断和异常向量

下表列出了芯片系统的向量表。

表3-1 中断向量表

<table><tr><td>编号</td><td>优先级</td><td>优先级类型</td><td>名称</td><td>说明</td><td>地址</td></tr><tr><td>0</td><td>-3</td><td>固定</td><td>Reset</td><td>复位</td><td>0x0000_0000</td></tr><tr><td>1</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>0x0000_0004</td></tr><tr><td>2</td><td>-2</td><td>固定</td><td>NMI</td><td>不可屏蔽中断</td><td>0x0000_0008</td></tr><tr><td>3</td><td>-1</td><td>固定</td><td>EXC</td><td>所有类型的失效、异常中断</td><td>0x0000_000C</td></tr><tr><td>4</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>-</td></tr><tr><td>5</td><td>-1</td><td>固定</td><td>ECALL-M</td><td>机器模式回调中断</td><td>0x0000_0014</td></tr><tr><td>6-7</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>-</td></tr><tr><td>8</td><td>-1</td><td>固定</td><td>ECALL-U</td><td>用户模式回调中断</td><td>0x0000_0020</td></tr><tr><td>9</td><td>-1</td><td>固定</td><td>BREAKPOINT</td><td>断点回调中断</td><td>0x0000_0024</td></tr><tr><td>10-11</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>-</td></tr><tr><td>12</td><td>0</td><td>可设置</td><td>SysTick</td><td>系统嘀嗒定时器</td><td>0x0000_0030</td></tr><tr><td>13</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>-</td></tr><tr><td>14</td><td>1</td><td>可设置</td><td>SWI</td><td>软件中断</td><td>0x0000_0038</td></tr><tr><td>15</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>0x0000_003C</td></tr><tr><td>16</td><td>2</td><td>可设置</td><td>TMRO</td><td>TMRO定时器0中断</td><td>0x0000_0040</td></tr><tr><td>17</td><td>3</td><td>可设置</td><td>GPIO_A</td><td>GPIO端口PA通用I/O中断</td><td>0x0000_0044</td></tr><tr><td>18</td><td>4</td><td>可设置</td><td>GPIO_B</td><td>GPIO端口PB通用I/O中断</td><td>0x0000_0048</td></tr><tr><td>19</td><td>5</td><td>可设置</td><td>SPI0</td><td>SPI0中断</td><td>0x0000_004C</td></tr><tr><td>20</td><td>6</td><td>可设置</td><td>BLEB</td><td>无线模块的BB中断</td><td>0x0000_0050</td></tr><tr><td>21</td><td>7</td><td>可设置</td><td>BLEL</td><td>无线模块的LLE中断</td><td>0x0000_0054</td></tr><tr><td>22</td><td>8</td><td>可设置</td><td>USB</td><td>全速USB中断</td><td>0x0000_0058</td></tr><tr><td>23</td><td>-</td><td>-</td><td>-</td><td>保留</td><td>0x0000_005C</td></tr><tr><td>24</td><td>10</td><td>可设置</td><td>TMR1</td><td>TMR1定时器1中断</td><td>0x0000_0060</td></tr><tr><td>25</td><td>11</td><td>可设置</td><td>TMR2</td><td>TMR2定时器2中断</td><td>0x0000_0064</td></tr><tr><td>26</td><td>12</td><td>可设置</td><td>UARTO</td><td>UARTO异步串口0中断</td><td>0x0000_0068</td></tr><tr><td>27</td><td>13</td><td>可设置</td><td>UART1</td><td>UART1异步串口1中断</td><td>0x0000_006C</td></tr><tr><td>28</td><td>14</td><td>可设置</td><td>RTC</td><td>RTC 实时时钟中断</td><td>0x0000_0070</td></tr><tr><td>29</td><td>15</td><td>可设置</td><td>ADC</td><td>ADC 和 TouchKey 中断</td><td>0x0000_0074</td></tr><tr><td>30</td><td>16</td><td>可设置</td><td>I2C</td><td>I2C 中断</td><td>0x0000_0078</td></tr><tr><td>31</td><td>17</td><td>可设置</td><td>PWMX_SP11</td><td>PWMX (PWM4~11) 中断和 SPI1 中断</td><td>0x0000_007C</td></tr><tr><td>32</td><td>18</td><td>可设置</td><td>TMR3</td><td>TMR3 定时器 3 中断</td><td>0x0000_0080</td></tr><tr><td>33</td><td>19</td><td>可设置</td><td>UART2</td><td>UART2 异步串口 2 中断</td><td>0x0000_0084</td></tr><tr><td>34</td><td>20</td><td>可设置</td><td>UART3</td><td>UART3 异步串口 3 中断</td><td>0x0000_0088</td></tr><tr><td>35</td><td>21</td><td>可设置</td><td>WDOG_BAT</td><td>看门狗定时器中断/电池低电压中断</td><td>0x0000_008C</td></tr><tr><td>36</td><td>22</td><td>可设置</td><td>NFC</td><td>NFC 中断</td><td>0x0000_0090</td></tr><tr><td>37</td><td>23</td><td>可设置</td><td>USB2_DEVICE</td><td>高速 USB 设备中断</td><td>0x0000_0094</td></tr><tr><td>38</td><td>24</td><td>可设置</td><td>USB2_HOST</td><td>高速 USB 主机中断</td><td>0x0000_0098</td></tr><tr><td>39</td><td>25</td><td>可设置</td><td>LED</td><td>LED 中断</td><td>0x0000_009C</td></tr></table>

# 3.4 寄存器

# 3.4.1 PFIC 寄存器描述

PFIC 相关寄存器基地址：0xE000E000

表 3-2 PFIC 相关寄存器列表

<table><tr><td>名称</td><td>偏移地址</td><td>描述</td><td>复位值</td></tr><tr><td>R32_PF_ISR1</td><td>0x00</td><td>PFIC中断使能状态寄存器1</td><td>0x0000032C</td></tr><tr><td>R32_PF_ISR2</td><td>0x04</td><td>PFIC中断使能状态寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_IPR1</td><td>0x20</td><td>PFIC中断挂起状态寄存器1</td><td>0x00000000</td></tr><tr><td>R32_PF_IPR2</td><td>0x24</td><td>PFIC中断挂起状态寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_ITHRESDR</td><td>0x40</td><td>PFIC中断优先级阈值配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PF_GISR</td><td>0x4C</td><td>PFIC中断全局状态寄存器</td><td>0x00000000</td></tr><tr><td>R32_PF(IDCFGR</td><td>0x50</td><td>PFIC快速中断ID配置寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R32_PF_FIADDRRO</td><td>0x60</td><td>PFIC快速中断0地址寄存器</td><td>0xxxxxxxxxx0</td></tr><tr><td>R32_PF_FIADDRR1</td><td>0x64</td><td>PFIC快速中断1地址寄存器</td><td>0xxxxxxxxxx0</td></tr><tr><td>R32_PF_FIADDRR2</td><td>0x68</td><td>PFIC快速中断2地址寄存器</td><td>0xxxxxxxxxx0</td></tr><tr><td>R32_PF_FIADDRR3</td><td>0x6C</td><td>PFIC快速中断3地址寄存器</td><td>0xxxxxxxxxx0</td></tr><tr><td>R32_PF_IENR1</td><td>0x100</td><td>PFIC中断使能设置寄存器1</td><td>0x00000000</td></tr><tr><td>R32_PF_IENR2</td><td>0x104</td><td>PFIC中断使能设置寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_IRER1</td><td>0x180</td><td>PFIC中断使能清除寄存器1</td><td>0x00000000</td></tr><tr><td>R32_PF_IRER2</td><td>0x184</td><td>PFIC中断使能清除寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_IPSR1</td><td>0x200</td><td>PFIC中断挂起设置寄存器1</td><td>0x00000000</td></tr><tr><td>R32_PF_IPSR2</td><td>0x204</td><td>PFIC中断挂起设置寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_IPRR1</td><td>0x280</td><td>PFIC中断挂起清除寄存器1</td><td>0x00000000</td></tr><tr><td>R32_PF_IPRR2</td><td>0x284</td><td>PFIC中断挂起清除寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_IACTR1</td><td>0x300</td><td>PFIC中断激活状态寄存器1</td><td>0x00000000</td></tr><tr><td>R32_PF_IACTR2</td><td>0x304</td><td>PFIC中断激活状态寄存器2</td><td>0x00000000</td></tr><tr><td>R32_PF_IPRIORx</td><td>0x400</td><td>PFIC中断优先级配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PF_SCTLR</td><td>0xD10</td><td>PFIC系统控制寄存器</td><td>0x00000000</td></tr></table>

用户模式下，可以支持全局中断控制，请参考EVT评估板资料中提供的示例。

内核中断控制位说明：

1、Reset、NMI、EXC、ECALL-M、ECALL-U、BREAKPOINT 中断默认总是开启。

2、NMI、EXC支持中断挂起清除和置位控制（PFIC\_IPSR1和PFIC\_IPRR1寄存器控制），不支持中断使能设置和清除控制。

3、Reset、ECALL-M、ECALL-U、BREAKPOINT 不支持中断挂起清除和置位控制、中断使能设置和清除控制。

PFIC 中断使能状态寄存器 1（R32\_PFIC\_ISR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:12]</td><td>INTENSTA</td><td>R0</td><td>31#及以下中断当前使能状态。1: 当前编号中断已使能;0: 当前编号中断未启用。</td><td>0</td></tr><tr><td>[11:0]</td><td>Reserved</td><td>R0</td><td>保留。Reset、NMI、EXC、ECALL 等中断位,下同。</td><td>32Ch</td></tr></table>

PFIC 中断使能状态寄存器 2（R32\_PFIC\_ISR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>INTENSTA</td><td>R0</td><td>32#及以上中断当前使能状态。
1: 当前编号中断已使能;
0: 当前编号中断未启用。</td><td>0</td></tr></table>

PFIC 中断挂起状态寄存器 1（R32\_PFIC\_IPR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>PENDSTA</td><td>R0</td><td>31#及以下中断当前挂起状态。1: 当前编号中断已挂起;0: 当前编号中断未挂起。</td><td>0</td></tr></table>

PFIC 中断挂起状态寄存器 2（R32\_PFIC\_IPR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>PENDSTA</td><td>R0</td><td>32#及以上中断当前挂起状态。
1: 当前编号中断已挂起;
0: 当前编号中断未挂起。</td><td>0</td></tr></table>

PFIC 中断优先级阈值配置寄存器（R32\_PFIC\_ITHRESDR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>THRESHOLD</td><td>RW</td><td>中断优先级阈值设置值。低于当前设置值的中断优先级值，当挂起时不执行中断服务；此寄存器为0时表示阈值寄存器功能无效。[7:5]：优先级阈值；[4:0]：保留，固定为0，写无效。</td><td>0</td></tr></table>

PFIC 中断全局状态寄存器（R32\_PFIC\_GISR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:14]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>13</td><td>CPU_LOCKSTA</td><td>R0</td><td>当前内核处于锁定状态:1:锁定;0:非锁定。</td><td>0</td></tr><tr><td>12</td><td>CPUDBG_MODE</td><td>R0</td><td>当前内核处于调试状态:1:调试;0:非调试。</td><td>0</td></tr><tr><td>11</td><td>CPU_GLOB_I E</td><td>R0</td><td>全局中断使能:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:使能中断;0:禁止中断。</td><td></td></tr><tr><td>10</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>9</td><td>GPENDSTA</td><td>R0</td><td>当前是否有中断处于挂起:1:有;0:没有。</td><td>0</td></tr><tr><td>8</td><td>GACTSTA</td><td>R0</td><td>当前是否有中断被执行:1:有;0:没有。</td><td>0</td></tr><tr><td>[7:0]</td><td>NESTSTA</td><td>R0</td><td>当前中断嵌套状态,目前支持2级嵌套,[1:0]有效。3:第2级中断中;1:第1级中断中;0:没有中断发生;其他:不可能情况。</td><td>0</td></tr></table>

PFIC 快速中断 ID 配置寄存器（R32\_PFIC\_IDCFGR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>FIID3</td><td>RW</td><td>配置快速中断3的中断编号。</td><td>X</td></tr><tr><td>[23:16]</td><td>FIID2</td><td>RW</td><td>配置快速中断2的中断编号。</td><td>X</td></tr><tr><td>[15:8]</td><td>FIID1</td><td>RW</td><td>配置快速中断1的中断编号。</td><td>X</td></tr><tr><td>[7:0]</td><td>FIID0</td><td>RW</td><td>配置快速中断0的中断编号。</td><td>X</td></tr></table>

PFIC 快速中断 0 地址寄存器（R32\_PFIC\_FIADDRR0）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:1]</td><td>ADDR0</td><td>RW</td><td>快速中断0服务程序地址bit[31:1], bit0为0。</td><td>X</td></tr><tr><td>0</td><td>FIOEN</td><td>RW</td><td>快速中断0通道使能位:1:启用快速中断0通道;0:关闭。</td><td>0</td></tr></table>

PFIC 快速中断 1 地址寄存器（R32\_PFIC\_FIADDRR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:1]</td><td>ADDR1</td><td>RW</td><td>快速中断1服务程序地址bit[31:1], bit0为0。</td><td>X</td></tr><tr><td>0</td><td>FI1EN</td><td>RW</td><td>快速中断1通道使能位:1:启用快速中断1通道;0:关闭。</td><td>0</td></tr></table>

PFIC 快速中断 2 地址寄存器（R32\_PFIC\_FIADDRR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:1]</td><td>ADDR2</td><td>RW</td><td>快速中断2服务程序地址bit[31:1], bit0为0。</td><td>X</td></tr><tr><td>0</td><td>FI2EN</td><td>RW</td><td>快速中断2通道使能位:1:启用快速中断2通道;0:关闭。</td><td>0</td></tr></table>

PFIC 快速中断 3 地址寄存器（R32\_PFIC\_FIADDRR3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:1]</td><td>ADDR3</td><td>RW</td><td>快速中断3服务程序地址bit[31:1], bit0为0。</td><td>X</td></tr><tr><td>0</td><td>F13EN</td><td>RW</td><td>快速中断3通道使能位:
1:启用快速中断3通道;
0:关闭。</td><td>0</td></tr></table>

PFIC 中断使能设置寄存器 1（R32\_PFIC\_IENR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:12]</td><td>INTEN</td><td>W0</td><td>31#及以下中断使能控制。1:当前编号中断使能;0:无影响。</td><td>0</td></tr><tr><td>[11:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

PFIC 中断使能设置寄存器 2（R32\_PFIC\_IENR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>INTEN</td><td>W0</td><td>32#及以上中断使能控制。
1: 当前编号中断使能;
0: 无影响。</td><td>0</td></tr></table>

PFIC 中断使能清除寄存器 1（R32\_PFIC\_IRER1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:12]</td><td>INTRESET</td><td>W0</td><td>31#及以下中断关闭控制。1:当前编号中断关闭;0:无影响。</td><td>0</td></tr><tr><td>[11:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

PFIC 中断使能清除寄存器 2（R32\_PFIC\_IRER2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>INTRESET</td><td>W0</td><td>32#及以上中断关闭控制。
1: 当前编号中断关闭;
0: 无影响。</td><td>0</td></tr></table>

PFIC 中断挂起设置寄存器 1（R32\_PFIC\_IPSR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>PENDSET</td><td>WO</td><td>31#及以下中断挂起设置。1:当前编号中断挂起;0:无影响。</td><td>0</td></tr></table>

PFIC 中断挂起设置寄存器 2（R32\_PFIC\_IPSR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>PENDSET</td><td>W0</td><td>32#及以上中断挂起设置。
1: 当前编号中断挂起;
0: 无影响。</td><td>0</td></tr></table>

PFIC 中断挂起清除寄存器 1（R32\_PFIC\_IPRR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>PENDRESET</td><td>W0</td><td>31#及以下中断挂起清除。
1: 当前编号中断清除挂起状态;
0: 无影响。</td><td>0</td></tr></table>

PFIC 中断挂起清除寄存器 2（R32\_PFIC\_IPRR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>PENDRESET</td><td>W0</td><td>32#及以上中断挂起清除。
1: 当前编号中断清除挂起状态;
0: 无影响。</td><td>0</td></tr></table>

PFIC 中断激活状态寄存器 1（R32\_PFIC\_IACTR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>IACTS</td><td>RO</td><td>31#及以下中断执行状态。
1: 当前编号中断执行中;
0: 当前编号中断未执行。</td><td>0</td></tr></table>

PFIC 中断激活状态寄存器 2（R32\_PFIC\_IACTR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[7:0]</td><td>IACTS</td><td>R0</td><td>32#及以上中断执行状态。
1: 当前编号中断执行中;
0: 当前编号中断未执行。</td><td>0</td></tr></table>

PFIC 中断优先级配置寄存器（R32\_PFIC\_IPRIORx）（ $x = 0 - 6 3 )$

控制器支持 256 个中断（0-255），每个中断使用 8bit 来设置控制优先级。

<table><tr><td rowspan="2">IPRIOR63</td><td>31</td><td>24</td><td>23</td><td>16</td><td>15</td><td>8</td><td>7</td><td>0</td></tr><tr><td colspan="2">PRI0_255</td><td colspan="2">PRI0_254</td><td colspan="2">PRI0_253</td><td colspan="2">PRI0_252</td></tr><tr><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td></td></tr><tr><td>IPRIORx</td><td colspan="2">PRI0_(4x+3)</td><td colspan="2">PRI0_(4x+2)</td><td colspan="2">PRI0_(4x+1)</td><td colspan="2">PRI0_(4x)</td></tr><tr><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td><td></td></tr><tr><td>IPRIOR0</td><td colspan="2">PRI0_3</td><td colspan="2">PRI0_2</td><td colspan="2">PRI0_1</td><td colspan="2">PRI0_0</td></tr></table>

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[2047:2040]</td><td>IP_255</td><td>RW</td><td>同IP_0描述。</td><td>0</td></tr><tr><td>...</td><td>...</td><td>...</td><td>...</td><td>...</td></tr><tr><td>[31:24]</td><td>IP_3</td><td>RW</td><td>同IP_0描述。</td><td>0</td></tr><tr><td>[23:16]</td><td>IP_2</td><td>RW</td><td>同IP_0描述。</td><td>0</td></tr><tr><td>[15:8]</td><td>IP_1</td><td>RW</td><td>同IP_0描述。</td><td>0</td></tr><tr><td>[7:0]</td><td>IP_0</td><td>RW</td><td>编号0中断优先级配置:[7:5]:优先级控制位。优先级数值越小则优先级越高。只有2级中断嵌套,即只能抢占1次,[7:5]为抢占位; [4:0]:保留,固定为0,写无效。</td><td>0</td></tr></table>

PFIC 系统控制寄存器（R32\_PFIC\_SCTLR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>31</td><td>SYSRESET</td><td>WO</td><td>系统复位。自动清0。写1有效,写0无效。</td><td>0</td></tr><tr><td>[30:6]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>5</td><td>SETEVENT</td><td>WO</td><td>设置事件,可以唤醒WFE的情况。</td><td>0</td></tr><tr><td>4</td><td>SEVONPEND</td><td>RW</td><td>设置新的中断进入挂起态为唤醒事件,可以从WFE指令后唤醒系统,如果未执行WFE指令,将在下次执行该指令后立即唤醒系统。1:新的中断进入挂起态为唤醒事件;0:新的中断进入挂起态不作为唤醒事件。</td><td>0</td></tr><tr><td>3</td><td>WFITOWFE</td><td>RW</td><td>将WFI指令当成是WFE执行。1:将之后的WFI指令当做WFE指令;0:无作用。</td><td>0</td></tr><tr><td>2</td><td>SLEEPDEEP</td><td>RW</td><td>控制系统的低功耗模式:1:deepsleep;0:sleep。</td><td>0</td></tr><tr><td>1</td><td>SLEEPONEXIT</td><td>RW</td><td>控制离开中断服务程序后,系统状态:1:系统进入低功耗模式;0:系统进入主程序。</td><td>0</td></tr><tr><td>0</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr></table>

# 3.4.2 WCH 定义 CSR 寄存器

RISC-V 架构中定义了一些控制和状态寄存器（Control and Status Register,CSR），用于配置或标识或记录运行状态。CSR寄存器属于内核内部的寄存器，使用专用的12位地址空间。WCH芯片除了 RISC-V 特权架构文档中定义的标准寄存器外，还增加了一些厂商定义寄存器，需要使用 csr 指令进行访问。

注：部分CSR寄存器需要系统在机器模式下访问，非机器模式下访问这些CSR寄存器将导致芯片进入异常。标注为“MRW"：需要系统在机器模式下才能访问；标注为“MRO"：在机器模式下只读。

中断系统控制寄存器（INTSYSCR）

CSR 地址： $0 \times 8 0 4$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x380</td></tr><tr><td>5</td><td>HM_POP_OFF</td><td>RW</td><td>单次出栈屏蔽功能,退出中断自动清零:1:下次退出中断时屏蔽硬件压栈;0:硬件出栈功能正常。</td><td>0</td></tr><tr><td>[4:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>1</td><td>INESTEN</td><td>R0</td><td>中断嵌套功能使能,固定值为1:1:使能;0:关闭。</td><td>1</td></tr><tr><td>0</td><td>HWSTKEN</td><td>RW</td><td>硬件压栈功能使能。1:使能;0:关闭。</td><td>0</td></tr></table>

注：中断嵌套功能的开启和关闭，由寄存器INESTCR的位NEST\_LVL控制。

用户访问机器状态寄存器(USER\_ACCESS\_MSTATUS)

CSR 地址： $0 \times 8 0 0$

寄存器功能设置同MSTATUS寄存器。

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:13]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[12:11]</td><td>MPP</td><td>R0</td><td>退出异常时机器状态:00:退出异常时机器状态设置为U模式;11:退出异常时机器状态设置为M模式;01:保留;10:保留。</td><td>0</td></tr><tr><td>[10:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>7</td><td>MPIE</td><td>RW</td><td>当寄存器 CORECFGR的位IE_REMAP_EN使能时,该位在用户模式下可读可写。</td><td>0</td></tr><tr><td>[6:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>3</td><td>MIE</td><td>RW</td><td>当寄存器 CORECFGR的位IE_REMAP_EN使能时,该位在用户模式下可读可写。</td><td>0</td></tr><tr><td>[2:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

机器状态寄存器（MSTATUS）

CSR 地址： $\mathtt { 0 } \mathtt { x } \mathtt { 3 0 0 }$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:13]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>[12:11]</td><td>MPP</td><td>MRW</td><td>退出异常时机器状态:00:退出异常时机器状态设置为U模式;11:退出异常时机器状态设置为M模式;01:保留;10:保留。</td><td>0</td></tr><tr><td>[10:8]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>7</td><td>MPIE</td><td>MRW</td><td>退出中断后,全局中断使能(进入中断时更新为进入MIE值):1:退出中断后,使能全局中断;0:退出中断后,关闭全局中断。</td><td>0</td></tr><tr><td>[6:4]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>3</td><td>MIE</td><td>MRW</td><td>进入中断时,全局中断使能,(退出中断时更新为MPIE值):1:使能全局中断;0:关闭全局中断。</td><td>0</td></tr><tr><td>[2:0]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr></table>

异常入口基地址寄存器（MTVEC）

CSR 地址： $0 \times 3 0 5$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:2]</td><td>BASEADD</td><td>MRW</td><td>中断向量表基地址。其中位[9:2]固定为0。</td><td>0</td></tr><tr><td>1</td><td>MODE1</td><td>MRW</td><td>中断向量表识别模式。
1：按绝对地址识别，支持全范围，但必须跳转；
0：按跳转指令识别，有限范围，支持非跳指令。</td><td>0</td></tr><tr><td>0</td><td>MODE0</td><td>MRW</td><td>中断或异常入口地址模式选择：
1：根据其编号*4进行地址偏移；</td><td>0</td></tr></table>

<table><tr><td></td><td></td><td>0: 使用统一入口地址。</td><td></td></tr></table>

微处理器配置寄存器（CORECFGR）

CSR 地址： $0 \times 8 0 0$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>7</td><td>HF_NMI</td><td>MRW</td><td>硬件错误产生NMI:1:硬件错误时,产生NMI中断;0:硬件错误时,产生异常中断;注:当前硬件错误仅包括嵌套溢出。</td><td>0</td></tr><tr><td>6</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>5</td><td>IE_REMAP_EN</td><td>MRW</td><td>MIE寄存器映射使能:1:CSR地址0x800的位3和位7分别映射为MSTATUS寄存器的位MIE和MSTATUS寄存器的位MPIE;0:CSR地址0x800为只读寄存器,返回值为MSTATUS的值。</td><td>0</td></tr><tr><td>4</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>3</td><td>ROM_LOOP_ACC</td><td>MRW</td><td>ROM区指令循环体加速使能:1:循环体在128字节以内的连续指令将被全部加速,而256字节以内的连续指令将被部分加速;0:关闭ROM区循环加速功能。</td><td>0</td></tr><tr><td>2</td><td>ROM_JUMP_ACC</td><td>MRW</td><td>ROM区指令跳转加速使能:1:使能ROM区指令跳转加速;0:关闭ROM区指令跳转加速。</td><td>0</td></tr><tr><td>[1:0]</td><td>FETCH_MODE</td><td>MRW</td><td>取指模式:00:预取关闭。指令预取功能关闭,避免无效的取指操作,CPU流水线上至多存在1条有效指令。此模式功耗最低,性能下降约2~3倍;01:预取使能。指令预取功能打开,CPU将持续对指令存储器进行访问,直到内部指令缓冲器待执行指令数量超过一定数量,或者指令缓冲器已满时,暂停取指令,此模式功耗高,性能强;(CPU预测失败将引入冗余取指操作,在部分情况下,执行单元将额外引入0~2个周期的气泡,大部分程序性能下降不明显);其他:保留。</td><td>01b</td></tr></table>

中断嵌套控制寄存器（INESTCR）

CSR 地址：0xBC1

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>31</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>30</td><td>NEST_OVR</td><td>MRW</td><td>硬件错误中断嵌套溢出标志位，写1清零：
1: 中断溢出标志;
0: 中断未溢出。
注：中断溢出仅会在执行二级中断服务函数产生指令异常和NMI中断时发生。此时异常和NMI中断正常进入，但是CPU堆栈溢出，不可从此异常和NMI中断退出。</td><td>0</td></tr><tr><td>[29:12]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>[11:8]</td><td>NEST_sta</td><td>MRO</td><td>嵌套状态标志位:0000:无中断;0001:一级中断;0011:二级中断,(一级嵌套);0111:三级中断,(二级嵌套,发生溢出)。</td><td>0</td></tr><tr><td>[7:2]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>[1:0]</td><td>NEST_LVL</td><td>MRW</td><td>嵌套等级:00:禁止嵌套,(关闭嵌套功能);01:一级嵌套,(打开嵌套功能);10:无法写入;11:无法写入。注1:对该域写10或者11,寄存器被置为01;注2:写入11时,读该寄存器,可获得芯片的最高嵌套等级。</td><td>0</td></tr></table>

# 3.4.3 物理内存保护单元 PMP

为了提高系统安全，RISC-V 架构中定义了一套物理地址访问限制，可以为区域内物理内存设置其读、写、执行属性，区域长度最小4字节保护。PMP单元在用户模式下一直生效，在机器模式下可选生效，如果违背了当前内存限制，将会产生系统异常中断（EXC）。

PMP单元包含4组8bit的配置寄存器（合计32bit）和4组地址寄存器，需要使用csr指令进行访问，并且在机器模式下进行。

PMP 配置寄存器（PMPCFG0）

CSR 地址： $\mathtt { 0 } \mathtt { x } \mathtt { 3 } \mathtt { A 0 }$

<table><tr><td>位</td><td>名称</td><td>访问</td><td colspan="3">描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>pmp3cfg</td><td>MRW</td><td colspan="3">见pmp0cfg。</td><td>0</td></tr><tr><td>[23:16]</td><td>pmp2cfg</td><td>MRW</td><td colspan="3">见pmp0cfg。</td><td>0</td></tr><tr><td>[15:8]</td><td>pmp1cfg</td><td>MRW</td><td colspan="3">见pmp0cfg。</td><td>0</td></tr><tr><td rowspan="7">[7:0]</td><td rowspan="7">pmp0cfg</td><td rowspan="7">MRW</td><td>位</td><td>名称</td><td>描述</td><td rowspan="7">0</td></tr><tr><td>7</td><td>L</td><td>锁定使能,仅复位可解锁:1:锁定相关寄存器;0:不锁定。</td></tr><tr><td>[6:5]</td><td>-</td><td>保留。</td></tr><tr><td>[4:3]</td><td>A</td><td>地址对齐及保护区域范围选择。</td></tr><tr><td>2</td><td>X</td><td>可执行属性。</td></tr><tr><td>1</td><td>W</td><td>可写入属性。</td></tr><tr><td>0</td><td>R</td><td>可读出属性</td></tr></table>

地址对齐及保护区域范围选择，对于 A\_ADDR $\leqslant$ region $<$ B\_ADDR 区域进行内存保护（要求A\_ADDR 和 B\_ADDR 均 4 字节对齐）：

1、如果 B\_ADDR – A\_ADDR $= = 2 ^ { 2 }$ ，则采用NA4方式；

2、如果 B\_ADDR – A\_ADDR == 2(G+2)， ${ \textsf { G } } \geqslant { \textsf { 1 } }$ ，且 A\_ADDR 为 $2 ^ { ( 6 + 2 ) }$ )对齐则采用 NAPOT 方式；

3、否则使用TOR方式。

<table><tr><td>A值</td><td>方式</td><td>描述</td></tr><tr><td>0</td><td>OFF</td><td>没有区域要保护。</td></tr><tr><td>1</td><td>TOR</td><td>顶端对齐区域保护：
region = BUS_ADDR &gt;&gt; 2;</td></tr><tr><td></td><td></td><td>pmp0cfg下, 0≤region&lt;pmpaddr0;pmp1cfg下,pmpaddr0≤region&lt;pmpaddr1;pmp2cfg下,pmpaddr1≤region&lt;pmpaddr2;pmp3cfg下,pmpaddr2≤region&lt;pmpaddr3。pmpaddri-1=A_ADDR&gt;&gt;2;pmpaddri=B_ADDR&gt;&gt;2。</td></tr><tr><td>2</td><td>NA4</td><td>固定4字节区域保护。pmp0cfg~pmp3cfg对应pmpaddr0~pmpaddr3作为起始地址。pmpaddri=A_ADDR&gt;&gt;2。</td></tr><tr><td>3</td><td>NAPOT</td><td>保护2(G+2)区域,G≥1,其中A_ADDR为2(G+2)对齐。pmpaddri=(A_ADDR&gt;&gt;2) | (2(G-1)-1)。</td></tr></table>

PMP 地址 0 寄存器（PMPADDR0）

CSR 地址： $\mathtt { 0 } \mathtt { x } \mathtt { 3 } \mathtt { B 0 }$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>ADDR0</td><td>MRW</td><td>PMP设置地址0的bit[33:2]。实际高2位未用。</td><td>XXXXh</td></tr></table>

PMP 地址 1 寄存器（PMPADDR1）

CSR 地址： $0 \times 3 { \tt B } 1$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>ADDR1</td><td>MRW</td><td>PMP设置地址1的bit[33:2]。实际高2位未用。</td><td>XXXXh</td></tr></table>

PMP 地址 2 寄存器（PMPADDR2）

CSR 地址： $0 \times 3 8 2$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>ADDR2</td><td>MRW</td><td>PMP设置地址2的bit[33:2]。实际高2位未用。</td><td>XXXXh</td></tr></table>

PMP 地址 3 寄存器（PMPADDR3）

CSR 地址： $0 \times 3 8 3$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>ADDR3</td><td>MRW</td><td>PMP设置地址3的bit[33:2]。实际高2位未用。</td><td>XXXXh</td></tr></table>

# 3.4.4 SysTick 寄存器描述

STK 相关寄存器基地址：0xE000F000

表3-3 STK相关寄存器列表

<table><tr><td>名称</td><td>偏移地址</td><td>描述</td><td>复位值</td></tr><tr><td>R32_STK_CTRL</td><td>0x00</td><td>系统计数控制寄存器</td><td>0x00000000</td></tr><tr><td>R32_STK_SR</td><td>0x04</td><td>系统计数状态寄存器</td><td>0x00000000</td></tr><tr><td>R32_STK_CNTL</td><td>0x08</td><td>系统计数器低位寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R32_STK_CMPLR</td><td>0x10</td><td>计数重加载低位寄存器</td><td>0xxxxxxxxxx</td></tr></table>

系统计数控制寄存器（STK\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>MODE</td><td>RW</td><td>计数模式：
1：向下计数；
0：向上计数。</td><td>0</td></tr><tr><td>3</td><td>STRE</td><td>RW</td><td>自动重装载计数使能:1:向上计数到比较值之后从0开始计数,向下计数到0之后从比较值开始向下计数;0:继续向上/向下计数。</td><td>0</td></tr><tr><td>2</td><td>STCLK</td><td>RW</td><td>计数器时钟源选择:1:HCLK做时基;0:HCLK/8做计数时基。</td><td>0</td></tr><tr><td>1</td><td>STIE</td><td>RW</td><td>计数器中断使能控制位:1:使能计数器中断;0:无计数器中断。</td><td>0</td></tr><tr><td>0</td><td>STE</td><td>RW</td><td>系统计数器使能控制位:1:启动系统计数器STK;0:关闭系统计数器STK,计数器停止计数。</td><td>0</td></tr></table>

计数状态寄存器（STK\_SR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>31</td><td>SWIE</td><td>RW</td><td>软件中断触发使能(SWI):1:触发软件中断;0:关闭触发。注:进入软件中断后须将此位清0,否则将一直触发。</td><td>0</td></tr><tr><td>[30:1]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>CNTIF</td><td>RWO</td><td>计数值比较标志,写0清除,写1无效:1:向上计数达到比较值,向下计数达到0;0:未达到比较值。</td><td>0</td></tr></table>

系统计数器低位寄存器（STK\_CNTL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>CNTL</td><td>RW</td><td>STK计数器计数值低32位。</td><td>XXXXXXXXh</td></tr></table>

计数重加载低位寄存器（STK\_CMPLR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>CMPL</td><td>RW</td><td>设置重加载计数器值低32位。</td><td>XXXXXXXXh</td></tr></table>

# 3.4.5 硬件断点设置

处理器支持4路指令地址和数据地址断点，其中TDATA1寄存器的位TYPE固定值为2，而TDATA1寄存器中其它位符合调试标准中mcontrol定义，最多支持四通道断点。TSELECT触发器低2位有效，通过TSELECT寄存器的值来选择中断点通道，再配置断点地址和控制信息。

断点通道选择寄存器（TSELECT）

CSR 地址： $0 \times 7 \mathsf { A 0 }$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:2]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>[1:0]</td><td>TSELECT</td><td>MRW</td><td>断点通道选择寄存器,配置后即选中对应通道,可操作 TDATA1 和 TDATA2 寄存器配置断点信息。</td><td>X</td></tr></table>

断点通道控制寄存器（TDATA1）（上电复位）

CSR 地址：0x7A1

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:28]</td><td>TYPE</td><td>MRO</td><td>断点类型定义,mcontrol类型。</td><td>0010b</td></tr><tr><td>[27]</td><td>DMODE</td><td>MRO</td><td>仅调试模式可以修改触发器的相关寄存器。</td><td>1</td></tr><tr><td>[26:21]</td><td>MASKMAX</td><td>MRO</td><td>当MATCH=1时,允许匹配的最大指数幂范围,即最大允许匹配231字节范围。</td><td>011111b</td></tr><tr><td>[20:13]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>12</td><td>ACTION</td><td>MRW</td><td>设置触发断点时采取的处理模式:1:触发时进入到调试模式;0:触发时进入到断点回调中断。</td><td>0</td></tr><tr><td>[11:8]</td><td>Reserved</td><td>MRO</td><td>保留。</td><td>0</td></tr><tr><td>7</td><td>MATCH</td><td>MRW</td><td>匹配策略配置:1:触发值和TDATA2的高M位相等时匹配,其中M=31-N,N为TDATA2的第一个0的索引(从低位开始);0:触发值和TDATA2相等时匹配。</td><td>0</td></tr><tr><td>6</td><td>M</td><td>MRW</td><td>M模式下触发器使能:1:M模式下使能触发器;0:M模式下关闭触发器。</td><td>0</td></tr><tr><td>3</td><td>U</td><td>MRW</td><td>U模式下触发器使能:1:U模式下使能触发器;0:U模式下关闭触发器。</td><td>0</td></tr><tr><td>2</td><td>EXECUTE</td><td>MRW</td><td>指令读地址触发使能:1:使能;0:关闭。</td><td>0</td></tr><tr><td>1</td><td>STORE</td><td>MRW</td><td>数据写地址触发使能:1:使能;0:关闭。</td><td>0</td></tr><tr><td>0</td><td>LOAD</td><td>MRW</td><td>数据读地址触发使能:1:使能;0:关闭。</td><td>0</td></tr></table>

断点通道地址寄存器（TDATA2）

CSR 地址：0x7A2

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>TDATA2</td><td>MRW</td><td>用于保存匹配值。</td><td>X</td></tr></table>

# 第 4 章 系统控制

# 4.1 复位控制

系统支持 6 种复位形式，分别为电源上电复位 RPOR(real power on reset)、外部手工复位MR(manual reset)、内部软件复位 SR(software reset)、看门狗复位(watch-dog reset)、下电模式下唤醒导致的全局复位 GRWSM(global reset by waking under shutdown mode)、常规唤醒导致的局部寄存器复位 LRW(local reset by waking)。

寄存器 R8\_GLOB\_RESET\_KEEP 和 RB\_ROM\_CODE\_OFS，只在 RPOR 或者 GRWSM 复位时被复位，而不受其它复位形式影响。

下图中时序参数和复位特性参数请参考第20.5节的时序参数表。

# 4.1.1 电源上电复位 RPOR

当电源上电时，芯片内部POR模块会产生上电复位，并延时以等待电源稳定。另外，在运行过程中，当电源电压低于 Vlvr 时，芯片内部 LVR 模块会产生低压复位直到电压回升，并延时以等待电源稳定。下图为上电复位过程和低压复位过程。

图4-1 上电复位

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/8d4519c294eee6709596c0e75a96058d77fcc201740f1dfd77890cb238b8c48e.jpg null)

# 4.1.2 外部手工复位 MR

外部手工复位由外部加到RST引脚的低电平触发，当复位低电平持续时间大于最小复位脉冲宽度(Trst)时即触发系统进行复位。

图4-2 外部复位

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/e8dfa20a8000a44a58ccdbced5543cacfad40ba0cf9d52d9d56a220440cb7ffc.jpg null)

# 4.1.3 内部软件复位 SR

内部软件复位，用于不需要外部干预而自行复位。设置全局复位配置寄存器(R8\_RST\_WDOG\_CTRL)的位RB\_SOFTWARE\_RESET为1，即可实现软件复位。该位会自动清0。

# 4.1.4 看门狗复位（WTR）

看门狗功能是基于一个8位的递增计数器，计数时钟周期为131072/Fsys。当开启了看门狗超时复位功能后，一旦此计数器溢出会复位整个系统。

# 4.1.5 下电模式唤醒后的复位 GRWSM

一旦系统进入下电模式（详见电源管理章节）后，在唤醒信号的作用下，系统将有序执行唤醒操作，唤醒之后系统将执行全局复位，此复位效果类似于上电复位。

# 4.1.6 常规唤醒操作引起的复位 LRW

如果系统是从睡眠模式中被唤醒，则在相关电源准备就绪之后会产生复位，此复位为局部复位，根据需要对睡眠模式下掉电的寄存器进行有选择的复位。

在睡眠模式下，各功能模块的寄存器分为三类：

第一种是属于需数据保持的功能模块的关键寄存器（例如配置/模式等），睡眠时由辅助电源继续供电，数据不丢失，睡眠和唤醒对其数据无影响；

第二种是属于需数据保持的功能模块的可再生寄存器（例如计数器、FIFO等），睡眠时断电，唤醒后数据是随机数（例如FIFO存储单元）或者被复位（例如FIFO计数器）；

第三种是属于无需数据保持的功能模块的寄存器，睡眠时断电，唤醒后数据是随机数（例如FIFO存储单元）或者被复位（例如FIFO计数器、配置/模式寄存器）。

LRW就是用于上述后两种被复位的寄存器。

# 4.2 安全访问

系统某些寄存器的属性是“RWA”或者“WA”，表示当前寄存器为安全访问寄存器，可以直接读取但是写入需要进入安全访问模式。

先写入 R8\_SAFE\_ACCESS\_SIG 寄存器 $\_ { 0 \times 5 7 }$ ；

再写入 R8\_SAFE\_ACCESS\_SIG 寄存器 $0 \times \mathsf { A } 8$ ；

即可进入安全访问模式，此时可以操作具有“RWA/WA”属性的寄存器，此后约112个系统主频周期（Tsys）都处于安全模式下，该有效期内可以改写一个或多个安全类寄存器，超出上述有效期后将自动终止安全模式。或者可提前向R8\_SAFE\_ACCESS\_SIG寄存器写入 $0 \times 0 0$ 提前终止安全模式。

# 4.3 寄存器描述

表4-1 系统控制相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8SAFE_MODE_CTRL</td><td>0x40001010</td><td>安全访问模式控制寄存器</td><td>0x01</td></tr><tr><td>R8SAFE_CLK_CTRL</td><td>0x40001011</td><td>安全访问时钟控制寄存器</td><td>0x00</td></tr><tr><td>R8SAFE_DEBUG_CTRL</td><td>0x40001012</td><td>安全访问调试控制寄存器</td><td>0x00</td></tr><tr><td>R8SAFE_LRST_CTRL</td><td>0x40001013</td><td>安全访问长时复位控制寄存器</td><td>0x00</td></tr><tr><td>R8SAFE_ACCESSSIG</td><td>0x40001040</td><td>安全访问标记寄存器</td><td>0xX2</td></tr><tr><td>R8CHIP_ID</td><td>0x40001041</td><td>芯片ID寄存器</td><td>0x93/0x92/0x90</td></tr><tr><td>R8SAFE_ACCESS_ID</td><td>0x40001042</td><td>安全访问ID寄存器</td><td>0x0C</td></tr><tr><td>R8_WDOG_COUNT</td><td>0x40001043</td><td>看门狗计数器寄存器</td><td>0x00</td></tr><tr><td>R8_RESET_STATUS</td><td>0x40001044</td><td>复位状态寄存器</td><td>0x01</td></tr><tr><td>R8_GLOBRom_CFG</td><td>0x40001044</td><td>FlashROM应用配置寄存器</td><td>0x01</td></tr><tr><td>R8_GLOB_CFG_INFO</td><td>0x40001045</td><td>全局配置信息状态寄存器</td><td>0xX8</td></tr><tr><td>R8_RST_WDOG_CTRL</td><td>0x40001046</td><td>看门狗及复位配置寄存器</td><td>0x00</td></tr><tr><td>R8_GLOB_RESET_KEEP</td><td>0x40001047</td><td>复位保持寄存器</td><td>0x00</td></tr><tr><td>R32_FLASH_DATA</td><td>0x40001800</td><td>FlashROM字数据寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R32_FLASH_CONTROL</td><td>0x40001804</td><td>FlashROM控制寄存器</td><td>0x074000XX</td></tr><tr><td>R8_FLASH_DATA</td><td>0x40001804</td><td>FlashROM字节数据寄存器</td><td>0xXX</td></tr><tr><td>R8_FLASH_CTRL</td><td>0x40001806</td><td>FlashROM存取控制寄存器</td><td>0x40</td></tr><tr><td>R8_FLASH_CFG</td><td>0x40001807</td><td>FlashROM存取配置寄存器</td><td>0x07</td></tr></table>

安全访问模式控制寄存器(R8\_SAFE\_MODE\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_XROM_312M_SEL</td><td>RW</td><td>XROM时钟选择:1:312MHz;0:624MHz。</td><td>0</td></tr><tr><td>[3:1]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RBSAFE_AUTO_EN</td><td>RW</td><td>安全寄存器自动关闭使能:1:使能;0:关闭。</td><td>1</td></tr></table>

安全访问时钟控制寄存器(R8\_SAFE\_CLK\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:3]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_CLK_OFF_LED</td><td>RWA</td><td>LED主频时钟关闭使能:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>1</td><td>RB_CLK_OFF_ADC</td><td>RWA</td><td>ADC主频时钟关闭使能:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>0</td><td>RB_CLK_OFF_NFC</td><td>RWA</td><td>NFC主频时钟关闭使能:1:关闭; 0:开启。</td><td>0</td></tr></table>

安全访问调试控制寄存器(R8\_SAFE\_DEBUG\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_DEBUG_DIS</td><td>RWA</td><td>DEBUG 关闭使能:
1: 关闭; 0: 开启。</td><td>0</td></tr><tr><td>[3:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

安全访问长时复位控制寄存器(R8\_SAFE\_LRST\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_IWDG_RST_EN</td><td>RWA</td><td>独立看门狗复位使能:1:iwdg_rst执行上电复位;0:iwdg_rst执行全局复位。</td><td>0</td></tr><tr><td>[3:2]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>1</td><td>RB LONG_TIM_SEL</td><td>RWA</td><td>长复位时间选择:1:31ms; 0:18ms。</td><td>0</td></tr><tr><td>0</td><td>RB LONG_RST_EN</td><td>RWA</td><td>长复位使能:1:开启; 0:关闭。</td><td>0</td></tr></table>

安全访问标记寄存器(R8\_SAFE\_ACCESS\_SIG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td colspan="3">描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8SAFE_ACCESSSIG</td><td>WO</td><td colspan="3">安全访问标记寄存器。
部分寄存器(访问属性为RWA)为保护寄存</td><td>X2h</td></tr><tr><td></td><td></td><td></td><td colspan="3">器,必须进入安全访问模式才能进行写操作。对该寄存器先写入0x57,再写入0xA8,即可进入安全访问模式,并且限时约112(7*16)个主时钟周期(Tsys),超过则自动保护。可以写入其它任意值强制直接退出安全访问模式,回到保护状态。</td><td></td></tr><tr><td rowspan="4">7</td><td rowspan="4">RB CHIP_ID1</td><td rowspan="4">RO</td><td colspan="3">芯片识别码,其复位值和位RB CHIP_ID0的复位值用于芯片识别。</td><td rowspan="4">X</td></tr><tr><td>芯片类型</td><td>RB CHIP_ID1</td><td>RB CHIP_ID0</td></tr><tr><td>CH585</td><td>1</td><td rowspan="2">1</td></tr><tr><td>CH584</td><td>0</td></tr><tr><td>[6:4]</td><td>RBSAFE_ACC_TIMER</td><td>RO</td><td colspan="3">当前安全访问时间计数。</td><td>0</td></tr><tr><td>3</td><td>RBSAFE_ACC_ACT</td><td>RO</td><td colspan="3">当前安全访问模式状态:1:未锁定/安全访问模式下,可写;0:锁定,RWA属性寄存器不可改写。</td><td>0</td></tr><tr><td>2</td><td>RB CHIP_ID0</td><td>RO</td><td colspan="3">芯片识别码,其复位值和位RB CHIP_ID1的复位值用于芯片识别。</td><td>1</td></tr><tr><td>[1:0]</td><td>RBSAFE_ACC_MODE</td><td>RO</td><td colspan="3">当前安全访问模式状态:11:安全模式,可写入属性RWA寄存器;其他:非安全模式。</td><td>0</td></tr></table>

芯片 ID 寄存器(R8\_CHIP\_ID)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td rowspan="3">[7:0]</td><td rowspan="3">R8 CHIP_ID</td><td rowspan="3">RF</td><td>CH585: 固定值 93h, 用于识别芯片。</td><td>93h</td></tr><tr><td>CH584: 固定值 92h, 用于识别芯片。</td><td>92h</td></tr><tr><td>CH585C: 固定值 91h, 用于识别芯片。</td><td>91h</td></tr></table>

安全访问 ID 寄存器(R8\_SAFE\_ACCESS\_ID)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8SAFE_ACCESS_ID</td><td>RF</td><td>固定值0x0C。</td><td>0Ch</td></tr></table>

看门狗计数器寄存器(R8\_WDOG\_COUNT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_WDOG_COUNT</td><td>RW</td><td>可预置初值的看门狗计数器,一直自动递增,可从0xFF循环到0x00再继续。计数周期=131072/Fsys。</td><td>0</td></tr></table>

复位状态寄存器(R8\_RESET\_STATUS)、FlashROM 应用配置寄存器(R8\_GLOB\_ROM\_CFG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB-ROM_CODE_WE</td><td>RWA</td><td>FlashROM程序存储区CodeFlash的擦除/编程使能位:X0:全部擦写保护;01:129-240K允许擦写;11:0-240K允许擦写。</td><td>0</td></tr><tr><td>7</td><td>RB-ROM_CODE_WE</td><td>RWA</td><td>FlashROM程序存储区CodeFlash的擦除/编程使能位(0-128K):1:允许擦除/编程;</td><td>0</td></tr><tr><td></td><td></td><td></td><td>0:该区擦写保护。</td><td></td></tr><tr><td>6</td><td>RB-ROM_DATA_WE</td><td>RWA</td><td>FlashROM数据存储区DataFlash的擦除/编程使能位(0-240K):1:允许擦除/编程;0:全部擦写保护。</td><td>0</td></tr><tr><td>5</td><td>RB-ROM_CTRL_EN</td><td>RWA</td><td>FlashROM存取控制接口使能:1:允许控制;0:禁止存取。</td><td>0</td></tr><tr><td>4</td><td>RB-ROM_CODE_OFSS</td><td>RWA</td><td>选择用户程序代码在FlashROM的起始偏移地址,该值不受MR、SR、WTR或GRWSM影响,仅在RPOR有效时才能清零:1:0x040000(跳过ROM中前256KB);0:0x000000。</td><td>0</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>[2:0]</td><td>RB_RESET_FLAG</td><td>RO</td><td>最近一次复位状态:000:软件复位SR(RB_WDOG_RST_EN=0时软件复位可产生此状态,否则可复位但不产生此状态);001:上电复位RPOR;010:看门狗超时复位WTR;011:外部手动复位MR;101:从下电模式唤醒时的复位GRWSM;100/110/111:唤醒复位LRW,且此前的上一次复位分别是SR/WTR/MR。</td><td>001b</td></tr></table>

全局配置信息状态寄存器(R8\_GLOB\_CFG\_INFO)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>11b</td></tr><tr><td>5</td><td>RB_BOOTLoader</td><td>R0</td><td>Bootloader 状态:1: 当前处于 Bootloader 状态;0: 当前处于用户程序状态。</td><td>1/0</td></tr><tr><td>4</td><td>RB_CFG_DEBUG_EN</td><td>R0</td><td>仿真调试接口使能状态:1: 可仿真调试,可读取 FlashROM;0: 禁止仿真调试。</td><td>0</td></tr><tr><td>3</td><td>RB_CFG_BOOT_EN</td><td>R0</td><td>系统引导程序 BootLoader 使能状态:1: 已启用; 0: 未启用。</td><td>1</td></tr><tr><td>2</td><td>RB_CFG_RESET_EN</td><td>R0</td><td>RST#外部手动复位输入使能状态:1: 已启用; 0: 未启用。</td><td>0</td></tr><tr><td>1</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_CFG-ROM_READ</td><td>R0</td><td>FlashROM 代码和数据区保护状态:1: 外部编程器可读;0: 保护,外部不可访问,程序保密。</td><td>0</td></tr></table>

看门狗及复位配置寄存器(R8\_RST\_WDOG\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_WDOG_INT_FLAG</td><td>RW1Z</td><td>看门狗定时器中断标志:1:发生了看门狗计数溢出,即检测到R8_WDOG_COUNT递增0xFF到0x00;</td><td>0</td></tr><tr><td></td><td></td><td></td><td>0: 看门狗计数未溢出。标志写1清0,或者重新加载看门狗计数器值(R8_WDOG_COUNT)清0,或者执行SETEVENT清0。</td><td></td></tr><tr><td>3</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_WDOG_INT_EN</td><td>RWA</td><td>看门狗定时器中断使能位:1: 使能,看门狗计数溢出后产生中断;0: 关闭看门狗定时器中断。</td><td>0</td></tr><tr><td>1</td><td>RB_WDOG_RST_EN</td><td>RWA</td><td>看门狗超时复位使能位:1: 使能,看门狗计数溢出后系统复位;0: 仅作为看门狗定时器。注:此位置1后软件复位操作将不影响RB_RESET_FLAG状态。</td><td>0</td></tr><tr><td>0</td><td>RB_SOFTWARE_RESET</td><td>WA/WZ</td><td>系统软件复位控制,复位后将自动清零:1: 执行系统软件复位;0: 空闲,无动作。</td><td>0</td></tr></table>

复位保持寄存器(R8\_GLOB\_RESET\_KEEP)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8&quot;GLOB_RESET_KEEP</td><td>RW</td><td>复位保持寄存器，该寄存器值不受手动复位、软件复位、看门狗复位或者普通唤醒复位的影响。</td><td>0</td></tr></table>

有关FlashROM的操作或者设置可以参考相关子程序，本手册不提供有关FlashROM字数据寄存器和FlashROM控制寄存器的说明。

# 4.4 Flash-ROM 操作步骤

1.擦除Flash-ROM，请参考和调用相关子程序。

2.写Flash-ROM，请参考和调用相关子程序。

3.读 Flash-ROM，读取 CodeFlash 通过指向程序存储空间的指针；读取 DataFlash 具体操作请参考例子程序。

# 4.5 芯片唯一 ID 号

每个芯片出厂时都具有唯一的ID号，即芯片身份识别号。该ID数据及其校验和共8字节，存储于芯片内部只读区域中，具体操作请参考例子程序。

# 第 5 章 电源控制

# 5.1 电源管理

CH585 和 CH584 内置有电源管理单元 PMU。系统电源从 VDD33 输入，通过内置的多个 LDO 电压调整器为系统的 FlashROM、系统的数字电路（包括内核和 USB 等）和系统的模拟电路（包括高频振荡器、PLL、ADC 和 RF 收发器等）提供所需的电源。GPIO 和 FlashROM 的电源从 VIO33 输入。

正常工作时的电源供电分为两种方式：直接电源和DC-DC转换。在正常工作之外，CH585和CH584提供了4种低功耗模式：空闲模式、暂停模式、睡眠模式、下电模式。

上电后默认不启用DC-DC，而是提供直通电源，其电压纹波较小。为了降低正常运行时的系统功耗，可以选择启用DC-DC提升电源能耗利用率，工作电流通常将下降到直通方式的 $60 %$ 左右。

为了降低睡眠时的系统功耗，可以选择关闭系统主LDO，切换成由系统内置的超低功耗ULP-LDO提供辅助电源。当系统进入睡眠或下电模式时，除了电源管理和RTC寄存器等常供电单元外，系统的高32KB和低96KB的SRAM、内核及所有的外设皆可选择是否维持供电，LSE/LSI可选择是否开启。

图5-1 电源系统

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/0ecfc63e55c9d7a723f276758a89714df7447c8d1ef02314b72ef771ce7ac83b.jpg null)

# 5.2 寄存器描述

表5-1 功耗管理相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_SLP_CLK_OFF0</td><td>0x4000100C</td><td>睡眠时钟控制寄存器0</td><td>0x00</td></tr><tr><td>R8_SLP_CLK_OFF1</td><td>0x4000100D</td><td>睡眠时钟控制寄存器1</td><td>0x00</td></tr><tr><td>R8_SLP_WAKE_CTRL</td><td>0x4000100E</td><td>唤醒事件配置寄存器</td><td>0x20</td></tr><tr><td>R8_SLP_POWER_CTRL</td><td>0x4000100F</td><td>外设睡眠电源控制寄存器</td><td>0x00</td></tr><tr><td>R16_POWER_PLAN</td><td>0x40001020</td><td>睡眠电源管理寄存器</td><td>0x11DF</td></tr><tr><td>R16_AUX_POWER_ADJ</td><td>0x40001022</td><td>辅助电源调整控制寄存器</td><td>0x0XXX</td></tr><tr><td>R8_BAT_DET_CTRL</td><td>0x40001024</td><td>电池电压检测控制寄存器</td><td>0x00</td></tr><tr><td>R8_BAT_DET_CFG</td><td>0x40001025</td><td>电池电压检测配置寄存器</td><td>0x02</td></tr><tr><td>R8_BAT_STATUS</td><td>0x40001026</td><td>电池状态寄存器</td><td>0x00</td></tr></table>

睡眠时钟控制寄存器 0(R8\_SLP\_CLK\_OFF0)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_SLP_CLK_UART3</td><td>RWA</td><td>串口3时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>6</td><td>RB_SLP_CLK_UART2</td><td>RWA</td><td>串口2时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>5</td><td>RB_SLP_CLK_UART1</td><td>RWA</td><td>串口1时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>4</td><td>RB_SLP_CLK_UART0</td><td>RWA</td><td>串口0时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>3</td><td>RB_SLP_CLK_TMR3</td><td>RWA</td><td>定时器3时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>2</td><td>RB_SLP_CLK_TMR2</td><td>RWA</td><td>定时器2时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>1</td><td>RB_SLP_CLK_TMR1</td><td>RWA</td><td>定时器1时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>0</td><td>RB_SLP_CLK_TXR0</td><td>RWA</td><td>定时器0时钟源:1:关闭; 0:开启。</td><td>0</td></tr></table>

睡眠时钟控制寄存器 1(R8\_SLP\_CLK\_OFF1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_SLP_CLK_BLE</td><td>RWA</td><td>BLE控制器时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>6</td><td>RB_SLP_CLK_LCD_</td><td>RWA</td><td>LCD控制器时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>5</td><td>RB_SLP_CLK_USB2</td><td>RWA</td><td>高速USB控制器时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>4</td><td>RB_SLP_CLK_USB</td><td>RWA</td><td>全速USB控制器时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>3</td><td>RB_SLP_CLK_I2C</td><td>RWA</td><td>I2C时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>2</td><td>RB_SLP_CLK_PWMX</td><td>RWA</td><td>PWMx时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>1</td><td>RB_SLP_CLK_SPI1</td><td>RWA</td><td>SPI1时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>0</td><td>RB_SLP_CLK_SPI0</td><td>RWA</td><td>SPI0时钟源:1:关闭; 0:开启。</td><td>0</td></tr></table>

唤醒事件配置寄存器(R8\_SLP\_WAKE\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB(GPIO_WAKE_MODE</td><td>RWA</td><td>GPIO边沿唤醒模式使能:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:边沿唤醒(根据极性);0:电平唤醒。</td><td></td></tr><tr><td>6</td><td>RB_WAKEEV_MODE</td><td>RWA</td><td>唤醒事件内部记忆模式使能:1:使能记忆,支持短脉冲事件唤醒;0:不记忆,事件需保持有效直到唤醒。</td><td>0</td></tr><tr><td>5</td><td>RB_SLP_BAT_WAKE</td><td>RWA</td><td>使能电池低压事件唤醒系统:1:使能; 0:关闭。</td><td>1</td></tr><tr><td>4</td><td>RB_SLP_GPIO_WAKE</td><td>RWA</td><td>使能 GPIO事件唤醒系统:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>3</td><td>RB_SLP_RTC_WAKE</td><td>RWA</td><td>使能RTC事件唤醒系统:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>2</td><td>RB_GPIO_EDGE_WAKE</td><td>RWA</td><td>GPIO边沿唤醒模式选择:1:任意边沿;0:根据极性需要配置的边沿。注:任意边沿仅支持WFE。</td><td>0</td></tr><tr><td>1</td><td>RB_SLP_USB2_WAKE</td><td>RWA</td><td>使能高速USB事件唤醒系统:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>0</td><td>RB_SLP_USB_WAKE</td><td>RWA</td><td>使能全速USB事件唤醒系统:1:使能; 0:关闭。</td><td>0</td></tr></table>

注：当配置多个I/0为边沿唤醒，其中一个I/0产生符合条件的唤醒信号，其它配置的I/0必须符合以下条件：如果配置为上升沿唤醒，需保持为低电平；如果配置为下降沿唤醒，需保持为高电平。此时才能够正常唤醒。

外设睡眠电源控制寄存器(R8\_SLP\_POWER\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB_RAM_RETENT_LV</td><td>RWA</td><td>SRAM睡眠时辅助电源低压使能:00:禁止;01:低功耗模式一;10:低功耗模式二;11:低功耗模式三。</td><td>0</td></tr><tr><td>5</td><td>RB_CLK_OFF_RAMR</td><td>RWA</td><td>RAM32K的SRAM时钟关闭控制:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>4</td><td>RB_CLK_OFF_RAMX</td><td>RWA</td><td>主SRAM(RAM96K)的时钟关闭控制:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_CLK_OFF_UTMI</td><td>RWA</td><td>Utmi_clk时钟源:1:关闭; 0:开启。</td><td>0</td></tr><tr><td>[1:0]</td><td>RB_WAKE_DLY_MOD</td><td>RWA</td><td>选择唤醒后的延时周期数:11:无延时,8个周期+TSUCLK,禁用;10:超短延时,70个周期+TSUCLK;01:短延时,520个周期+TSUCLK,建议;00:长延时,3590个周期+TSUCLK。其中,TSUCLK取决于睡眠模式和时钟配置,可能包含TSUHSE或PLL或两者合计的启动时间,具体组合参考评估板中示例。</td><td>0</td></tr></table>

睡眠电源管理寄存器(R16\_POWER\_PLAN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_PWR_PLAN_EN</td><td>RWA/WZ</td><td>睡眠电源规划控制使能:1:开启规划;0:关闭或结束规划。开启电源规划,用于稍后进入睡眠或下电模式时执行,执行后该位自动清0。</td><td>0</td></tr><tr><td>[14:11]</td><td>RB_PWR_MUST_0010</td><td>RWA</td><td>保留,必须写0010b。</td><td>0010b</td></tr><tr><td>10</td><td>RB_PWR_DCDC_PRE</td><td>RWA</td><td>DC-DC偏置电路使能(即时生效):1:使能; 0:禁止。</td><td>0</td></tr><tr><td>9</td><td>RB_PWR_DCDC_EN</td><td>RWA</td><td>DC-DC使能位(即时生效):1:DC-DC使能,直通电源关闭;0:DC-DC禁止,直通电源开启。</td><td>0</td></tr><tr><td>8</td><td>RB_PWR_LDO_EN</td><td>RWA</td><td>内部LDO控制(睡眠规划):1:开启LDO;0:规划将关闭LDO,更省。</td><td>1</td></tr><tr><td>7</td><td>RB_PWR_SYS_EN</td><td>RWA</td><td>系统电源控制(睡眠规划):1:提供系统电源(在VSW引脚);0:关闭系统电源,规划将进入睡眠模式或者下电模式。</td><td>1</td></tr><tr><td>6</td><td>Reserved</td><td>RWA</td><td>保留,必须写0。</td><td>1</td></tr><tr><td>5</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_PWR_RAM96K</td><td>RWA</td><td>RAM96K的SRAM供电(睡眠规划):1:双供电;0:不用辅助电源。</td><td>1</td></tr><tr><td>3</td><td>RB_PWR_EXTENDED</td><td>RWA</td><td>USB和RF配置供电(睡眠规划):1:双供电;0:不用辅助电源。</td><td>1</td></tr><tr><td>2</td><td>RB_PWR_CORE</td><td>RWA</td><td>内核和基本外设供电(睡眠规划):1:双供电;0:不用辅助电源。</td><td>1</td></tr><tr><td>1</td><td>RB_PWR_RAM32K</td><td>RWA</td><td>RAM32K的SRAM供电(睡眠规划):1:双供电;0:不用辅助电源。</td><td>1</td></tr><tr><td>0</td><td>RB_PWR_XROM</td><td>RWA</td><td>FlashROM供电(睡眠规划):1:持续供电;0:睡眠时关闭电源。</td><td>1</td></tr></table>

此寄存器除 RB\_PWR\_DCDC\_PRE 和 RB\_PWR\_DCDC\_EN 之外均为睡眠规划预置，其电源配置在进入低功耗的睡眠模式和下电模式后生效。

辅助电源调整控制寄存器(R16\_AUX\_POWER\_ADJ)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:12]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[11:8]</td><td>Reserved</td><td>R0</td><td>保留,只读位,写操作不影响。</td><td>XXXXb</td></tr><tr><td>7</td><td>RB_DCDC_CHARGE</td><td>RWA</td><td>低功耗辅助 DC-DC 使能位:1:辅助 DC-DC 使能;0:辅助 DC-DC 禁止。</td><td>0</td></tr><tr><td>6</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[5:3]</td><td>Reserved</td><td>RWA</td><td>保留,写入时必须保持原值不变。</td><td>1XXb</td></tr><tr><td>[2:0]</td><td>RB_ULPLDO_ADJ</td><td>RWA</td><td>超低功耗 LDO 的辅助电源输出电压调节值(数值仅供参考,不建议修改):</td><td>XXXb(010b)</td></tr></table>

<table><tr><td></td><td></td><td>000: 0.77V; 001: 0.80V; 010: 0.84V; 011: 0.88V; 100: 0.91V; 101: 0.95V; 110: 0.99V; 111: 1.03V。</td><td></td></tr></table>

电池电压检测控制寄存器(R8\_BAT\_DET\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>3</td><td>RB_BAT_LOW_IE</td><td>RWA</td><td>电池低电压中断使能:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>2</td><td>RB_BAT_LOWER_IE</td><td>RWA</td><td>电池超低电压中断使能:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>1</td><td>RB_BAT_MON_EN</td><td>RWA</td><td>低功耗的电池电压监控功能使能:1:使能低压监控,增加电流约1uA;0:关闭低功耗的电池低压监控。</td><td>0</td></tr><tr><td>0</td><td>RB_BAT_LOW_VTHX</td><td>RWA</td><td>当RB_BAT_MON_EN=1时,设置低功耗的低压监控阈值。参考RB_BAT_LOW_VTH。</td><td>0</td></tr><tr><td>0</td><td>RB_BAT_DET_EN</td><td>RWA</td><td>当RB_BAT_MON_EN=0时,是高精度的电池电压检测功能使能:1:使能低压检测,同时开启基准电压等模块,睡眠模式下电流210uA;0:关闭高精度的电池低压检测。</td><td>0</td></tr></table>

注：如果电池电压达到超低电压检测阈值，且RBBATLOWERIE和RBBATLOWIE都使能（正常情况下只使能其中之一)，那么将产生NMI不可屏蔽中断，等效于提高中断优先级。

电池电压检测配置寄存器(R8\_BAT\_DET\_CFG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[1:0]</td><td>RB_BAT_LOW_VTH</td><td>RWA</td><td>当 RB_BAT_MON_EN=0时,设置高精度的超低电压及低电压的检测阈值:(超低电压参考阈值,低电压参考阈值)00:1.7V, 1.95V;01:1.9V, 2.15V;10:2.1V, 2.35V;11:2.3V, 2.55V。当 RB_BAT_MON_EN=1时,以RB_BAT_LOW_VTHX为最高位加上此2位合并3位设置低功耗的低压监控阈值:000:1.7V; 001:1.8V;010:1.9V; 011:2.0V;100:2.1V; 101:2.2V;110:2.3V; 111:2.4V。</td><td>10b</td></tr></table>

电池状态寄存器(R8\_BAT\_STATUS)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>1</td><td>RB_BAT_STAT_LOW</td><td>R0</td><td>电池低压检测或低压监控的结果,指示电池电压处于低电压状态:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:低于低电压阈值; 0:否。</td><td></td></tr><tr><td>0</td><td>RB_BAT_STAT_LOWER</td><td>R0</td><td>当RB_BAT_MON_EN=0时,指示电池电压处于超低电压状态:1:低于超低电压阈值;0:否。</td><td>0</td></tr></table>

# 5.3 低功耗模式

在系统复位后，微控制器处于正常运行状态。当MCU不需要运行时，可以选择适当的低功耗模式来节省功耗。用户需要根据最低电源消耗、最快启动时间和可用唤醒事件等条件，选定一个合适的低功耗模式。

芯片提供以下4种主要的低功耗模式：

 空闲模式(Idle）

所有外设保持正常供电，内核停止运行，时钟系统运转。检测到唤醒事件后，可以立即唤醒。

$\bullet$ 暂停模式(Halt)

在空闲模式的基础上，时钟系统停止。检测到唤醒事件后，首先时钟运转，然后唤醒内核运行。

 睡眠模式(Sleep)：

主 LDO 关闭，由超低功耗 ULP-LDO 维持 PMU、内核和基本外设供电，LSE 或 LSI 可以选择是否开启，RAM32K、RAM96K、USB 和 RF 配置可以选择是否维持供电。检测到唤醒事件后，首先主 LDO 开启，然后时钟运转，最后唤醒内核，程序继续运行，需要时可以重新设置到更高主频。

 下电模式(Shutdown）：

在睡眠模式的基础上，关闭了内核和基本外设以及 USB 和 RF 配置，LSE 或 LSI 可以选择是否开启，RAM32K、RAM96K可以选择是否维持供电。检测到唤醒事件后，PMU将执行GRWSM复位，软件可根据复位标志 RB\_RESET\_FLAG 和可选的 RAM 中的保持数据区分于 RPOR。

下表详细描述了几种低功耗模式的特征及唤醒途径：

表5-2 低功耗模式

<table><tr><td>模式</td><td>特征</td><td>进入条件</td><td>唤醒事件</td><td>测试条件</td><td>功耗(1)</td></tr><tr><td rowspan="2">空闲模式Idle</td><td rowspan="2">外设均正常供电,内核停止运行,时钟系统运转,但可以通过外设时钟控制位选择开启各外设的时钟。</td><td rowspan="2">设置 SLEEPDEEP=0,设置唤醒条件后执行_WFI()或_WFE()</td><td rowspan="2">I/0 或 RTC或BAT或USB或I2C或SysTick或SPI或TMR或UART或ADC</td><td>主频 HSE=16MHz,FLASH片选关闭,外设时钟关闭,未开DC-DC</td><td>1.44mA</td></tr><tr><td>主频 HSI=16MHz,FLASH片选关闭,外设时钟关闭,未开DC-DC</td><td>1.26mA</td></tr><tr><td rowspan="3">暂停模式Halt</td><td rowspan="3">外设均正常供电,内核停止运行,时钟(PLL/HSE)可配置开或关。注:当 RB_CLK_XT32M_KEEP=1时,可以通过外设时钟控制位选择开启各外设的时钟。</td><td rowspan="3">设置 SLEEPDEEP=1,设置唤醒条件后执行_WFI()或_WFE()</td><td rowspan="3">I/0 或 RTC或BAT或USB</td><td>HSE=16MHz,未开DC-DC,RB_CLK_XT32M_KEP = 1</td><td>1.01mA</td></tr><tr><td>HSI=16MHz,未开DC-DC,RB_CLK_XT32M_KEP = 1</td><td>0.8mA</td></tr><tr><td>未开DC-DC,RB_CLK_XT32M_KEP = 0</td><td>200uA</td></tr><tr><td>睡眠模式Sleep</td><td>主LDO关闭,超低功耗ULP-LDO维持PMU、内核和基本外设供电,LSE或LSI可以选择是否</td><td>设置 SLEEPDEEP=1,设置 POWER_PLAN,设置唤醒条件后执行</td><td>I/0 或 RTC或BAT。芯片唤醒后</td><td>详见表5-3</td><td>2.6uA~8.2uA</td></tr><tr><td></td><td>开启,RAM32K、RAM96K、USB和RF配置可以选择是否维持供电。</td><td>_WFI()或_WFE()。</td><td>会继续运行</td><td></td><td></td></tr><tr><td>下电模式Shut down</td><td>超低功耗LDO维持PMU供电,LSE或LSI可以选择是否开启,RAM32K、RAM96K可以选择是否维持供电,用于保持数据。</td><td>设置SLEEPDEEP=1,设置POWER_PLAN,设置唤醒条件后执行_WFI()或_WFE()。</td><td>I/0或RTC或BAT。芯片唤醒后会自动复位</td><td>详见表5-3</td><td>0.65uA~5.5uA</td></tr></table>

下表描述了几种低功耗模式的详细配置：

表5-3 低功耗模式详细配置示例

<table><tr><td>规划配置</td><td>SYS_EN</td><td>RAM32K</td><td>RAM96K</td><td>CK32K</td><td>CORE</td><td>EXTEND</td><td>LCD</td><td>功耗(1)(仅供参考)</td></tr><tr><td>维持供电的功能</td><td>系统电源VSW</td><td>数据区32KB</td><td>数据区96KB</td><td>LSE/LSI二选一RTC唤醒</td><td>CPU内核和基本外设</td><td>USB和RF配置</td><td>LCD段式显示</td><td>PMU和RTC寄存器常供电,约0.3uA</td></tr><tr><td rowspan="5">下电模式常用配置</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0.65uA</td></tr><tr><td>0</td><td>1</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>2.2uA</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>0</td><td>0</td><td>0</td><td>5.5uA</td></tr><tr><td>0</td><td>0</td><td>0</td><td>1</td><td>0</td><td>0</td><td>0</td><td>1.2uA(LSI)1.1uA(LSE)</td></tr><tr><td>0</td><td>1</td><td>0</td><td>1</td><td>0</td><td>0</td><td>0</td><td>2.8uA(LSI)2.7uA(LSE)</td></tr><tr><td rowspan="6">睡眠模式常用配置</td><td>0</td><td>1</td><td>0</td><td>0</td><td>1</td><td>0</td><td>0</td><td>2.6uA</td></tr><tr><td>0</td><td>1</td><td>0</td><td>1</td><td>1</td><td>0</td><td>0</td><td>3.1uA(LSI)3.0uA(LSE)</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>1</td><td>0</td><td>0</td><td>6uA</td></tr><tr><td>0</td><td>0</td><td>1</td><td>1</td><td>1</td><td>0</td><td>0</td><td>6.5uA(LSI)6.3uA(LSE)</td></tr><tr><td>0</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>0</td><td>8.2uA(LSI)8.1uA(LSE)</td></tr><tr><td>0</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>10uA(2)</td></tr></table>

注：1.电流参数均在室温下抽测得出，注意温度变化导致电流变化；

设置 SCAN CLK SEL=128 LCD DUTY=1/4 LCD BIAS=1/3 LCD RAM 全为 1 。 LCD 模块 $2 5 %$ 下抽测结果为5uA左右； $0 { \sim } 5 0 ^ { \circ } C$ 温度约7uA，最差12uA； $- 2 0 { \sim } 7 5 ^ { \circ } C$ 温度约 $1 7 u A$ ，最差40uA； ${ 2 8 \* 4 }$ 的LCD 屏功耗实测约为11uA。

# 5.4 DC-DC 操作步骤

启用DC-DC电源模式（启用前需确认外部硬件电路上存在DC-DC所需的电感和电容）

（1）、进入安全访问模式：寄存器 R8\_SAFE\_ACCESS\_SIG 先写入 $0 \times 5 7$ ，再写入 ${ 0 } \times { \mathsf { A } } { 8 }$ ；

（2）、打开 DC-DC 偏置电路：将寄存器 R16\_POWER\_PLAN 的 RB\_PWR\_DCDC\_PRE 置 1；

（3）、延时约 10uS；

（4）、进入安全访问模式：寄存器 R8\_SAFE\_ACCESS\_SIG 先写入 $0 \times 5 7$ ，再写入 ${ 0 } \times { \mathsf { A } } { 8 }$

（5）、打开 DC-DC 电源：将寄存器 R16\_POWER\_PLAN 的 RB\_PWR\_DCDC\_EN 置 1，启用 DC-DC。

关闭DC-DC，切换到直通电源模式

（1）、进入安全访问模式：寄存器 R8\_SAFE\_ACCESS\_SIG 先写入 0x57，再写入 ${ 0 } \times { \mathsf { A } } { 8 }$ ；

（2）、清零寄存器 R16\_POWER\_PLAN 的 RB\_PWR\_DCDC\_EN 和 RB\_PWR\_DCDC\_PRE 控制位。

# 第 6 章 系统时钟及 RTC

# 6.1 系统时钟简介

以下几种不同的时钟源可被选择来驱动系统时钟 HCLK（Fsys）：

 HSE 或 HSI 之分频

$\bullet$ 内部 PLL 时钟源的二分频（312MHz）进行分频

 HSE 原始时钟 CK32M 或 HSI 原始时钟 CK16M

 LSE 或 LSI 原始时钟 CK32K

任意一个时钟源都可以被独立地启动或关闭，由此可以优化系统功耗。

# 6.1.1 时钟结构

图6-1 时钟树框图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/7a20c56e709d6e23aded7f92c9a1ad05df5a36233d9ab391bef8915eec07c1fd.jpg null)

上图是系统内部的时钟树结构，其中的RTC功能使用的是32KHz时钟源CK32K，所以使用这些功能必须打开低频时钟；USB的数据传输依靠PLL分频后产生的时钟源；其他的外设驱动时钟以及数字控制逻辑由系统时钟或者再分频驱动。

# 6.2 RTC 简介

实时时钟（RTC）是一个独立的定时器，包含一组连续计数的计数器。在相应软件配置下，可提供简单日历功能。修改计数器的值可以重新设置当前的时间和日期。

RTC寄存器与PMU一样常供电，在系统复位或从低功耗模式唤醒后，RTC的设置和时间维持不变。

# 6.2.1 主要特性

# 可配置2种模式：

 定时模式：软件可选择固定周期时间（定时）产生中断通知。

$\bullet$ 触发模式：匹配一个软件预设的目标闹钟时间，产生中断通知。

3组16位计数器，提供了CK32K原始周期、2秒周期、1天周期的计数。

# 6.3 寄存器描述

表6-1 时钟及振荡器控制相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R16_CLK_SYS_CFG</td><td>0x40001008</td><td>系统时钟配置寄存器</td><td>0x0003</td></tr><tr><td>R8_HFCK_PWR_CTRL</td><td>0x4000100A</td><td>高频时钟模块电源控制寄存器</td><td>0x14</td></tr><tr><td>R16_INT32K_TUNE</td><td>0x4000102C</td><td>内部32KHz时钟校准寄存器</td><td>0x1011</td></tr><tr><td>R8_XT32K_TUNE</td><td>0x4000102E</td><td>外部32KHz时钟谐振控制寄存器</td><td>0xC7</td></tr><tr><td>R8_CK32K_CONFIG</td><td>0x4000102F</td><td>32KHz振荡器配置寄存器</td><td>0xX2</td></tr><tr><td>R8_XT32M_TUNE</td><td>0x4000104E</td><td>外部32MHz时钟谐振控制寄存器</td><td>0x02</td></tr><tr><td>R16_osc_CAL_CNT</td><td>0x40001050</td><td>振荡器频率校准计数值寄存器</td><td>0xXXXX</td></tr><tr><td>R8_osc_CAL_OV_CNT</td><td>0x40001052</td><td>振荡器频率校准溢出次数寄存器</td><td>0x00</td></tr><tr><td>R8_osc_CAL_CTRL</td><td>0x40001053</td><td>振荡器频率校准控制寄存器</td><td>0x09</td></tr><tr><td>R8_PLL_CONFIG</td><td>0x4000104B</td><td>PLL配置寄存器</td><td>0x0A</td></tr><tr><td>R8_RTC_FLAG_CTRL</td><td>0x40001030</td><td>RTC标志和控制寄存器</td><td>0x30</td></tr><tr><td>R8_RTC_MODE_CTRL</td><td>0x40001031</td><td>RTC模式配置寄存器</td><td>0x02</td></tr><tr><td>R32_RTC_TRIG</td><td>0x40001034</td><td>RTC触发数值寄存器</td><td>0x00000000</td></tr><tr><td>R16_RTC_CNT_32K</td><td>0x40001038</td><td>RTC基于32768Hz计数值寄存器</td><td>0xXXXXXX</td></tr><tr><td>R16_RTC_CNT_2S</td><td>0x4000103A</td><td>RTC以2S为单位的计数值寄存器</td><td>0xXXXXXX</td></tr><tr><td>R32_RTC_CNT_DAY</td><td>0x4000103C</td><td>RTC以天为单位的计数值寄存器</td><td>0x0000XXX</td></tr></table>

系统时钟配置寄存器(R16\_CLK\_SYS\_CFG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:14]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>13</td><td>RB_PLL_GATE_TIME</td><td>RWA</td><td>在切换PLL时钟来源时,关闭PLL时钟的时间选择:1:40us; 0:30us。</td><td>0</td></tr><tr><td>12</td><td>RB_PLL_GATE_DISS</td><td>RWA</td><td>在切换PLL时钟来源时,是否关闭PLL时钟:1:不关闭; 0:关闭。</td><td>0</td></tr><tr><td>[11:10]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>9</td><td>RB_OSC32M_SEL</td><td>RWA</td><td>PLL时钟源的选择:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:外部32MHz振荡器HSE;0:内部16MHz振荡器HSI。注:完成切换需要1us。</td><td></td></tr><tr><td>8</td><td>RB_XROM_SCLK_SEL</td><td>RWA</td><td>XROM时钟来源:1:PLL时钟源(624MHz)或PLL时钟源的二分频(312MHz);0:16MHz或32MHz的两倍频。</td><td>0</td></tr><tr><td>[7:6]</td><td>RB_CLK_SYS_MOD</td><td>RWA</td><td>HCLK系统时钟源模式选择:00:CK32M或CK16M进行分频;01:PLL时钟源的二分频(312MHz)进行分频;10:CK32M或CK16M作为HCLK(默认16MHz);11:CK32K(默认32KHz)作为HCLK。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[4:0]</td><td>RB_CLK_PLL_DIV</td><td>RWA</td><td>HCLK输出时钟分频系数,最小值为2,0代表最大值32,写1将关闭HCLK。</td><td>00011b</td></tr></table>

计算：

$\mathsf { F c k } 3 2 \mathsf { m } = \mathsf { X T } \_ 3 2 \mathsf { M H } z ;$

Fck16m $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ RC\_16MHz；

Fck32k $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ RB\_CLK\_OSC32K\_XT ? XT\_32KHz : RC\_32KHz；

Fpll $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ (RB\_OSC32M\_SEL ? Fck32m/2 : Fck16m) \* 39 = 624MHz；

$\mathsf { F p } | \mathsf { I } \_ \mathsf { d } \mathsf { i } \mathsf { v } 2 = \mathsf { F p } | \mathsf { I } / 2 = 3 1 2 \mathsf { M } \mathsf { H } z$ $\underline { { \underline { { \mathbf { \delta \pi } } } } }$

Fsys $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ RB\_CLK\_SYS\_MOD\[1] ? (RB\_CLK\_SYS\_MOD\[0] ? Fck32k : (RB\_OSC32M\_SEL ? Fck32m : Fck16m) )：

( ( RB\_CLK\_SYS\_MOD\[0] ? Fpll\_div2 : (RB\_OSC32M\_SEL ? Fck32m : Fck16m) ) / RB\_CLK\_PLL\_DIV )；

上电默认值 Fsys $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ Fck16m/ RB\_CLK\_PLL\_DIV $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ 16MHz / 3 = 5.33MHz；

Fsys 范围：

<table><tr><td>位 RB_CLK_SYS_MOD[1:0]</td><td>HCLK 系统时钟源模式</td><td>Fsys 范围</td></tr><tr><td>11</td><td>CK32K</td><td>32KHz(在 RAM 中运行)</td></tr><tr><td>00/10</td><td>CK32M 或 CK16M 进行分频/CK32M 或 CK16M</td><td>1MHz~32MHz</td></tr><tr><td>01</td><td>PLL 的二分频进行分频</td><td>9.75MHz~78MHz</td></tr></table>

高频时钟模块电源控制寄存器(R8\_HFCK\_PWR\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_CLK_PLL_PON</td><td>RWA</td><td>PLL电源控制位:1:上电; 0:掉电。</td><td>1</td></tr><tr><td>3</td><td>RB_CLK_XT32M_KEEP</td><td>RWA</td><td>用于暂停模式下控制时钟系统的停止:1:Halt模式下不自动停止HSE和PLL;0:Halt模式下自动停止HSE和PLL。</td><td>0</td></tr><tr><td>2</td><td>RB_CLK_XT32M_PON</td><td>RWA</td><td>外部32MHz振荡器HSE电源控制位:1:上电; 0:掉电。</td><td>1</td></tr><tr><td>1</td><td>RB_CLK_RC16M_PON</td><td>RWA</td><td>内部16MHz振荡器HSI的使能:1:开启; 0:关闭。</td><td>1</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

内部 32KHz 时钟校准寄存器(R16\_INT32K\_TUNE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:13]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[12:0]</td><td>RB_INT32K_TUNE</td><td>RWA</td><td>内部RC 32KHz时钟频率校准值。</td><td>1011h</td></tr></table>

外部 32KHz 时钟谐振控制寄存器(R8\_XT32K\_TUNE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>RB_XT32K_C_LOAD</td><td>RWA</td><td>选择与外部32KHz晶体匹配的内置负载电容(可能影响RTC时钟精度):电容量 = RB_XT32K_C_LOAD + 12pF,0000b~1111b分别对应约12pF~27pF。根据所用晶体参数选择。</td><td>1100b</td></tr><tr><td>[3:2]</td><td>RB_RC32K_I_TUNE</td><td>RWA</td><td>RC32K调节位,内部32KHz振荡器偏置电流选择:00:70%额定电流;01:额定电流;10:140%额定电流;11:200%额定电流。</td><td>01b</td></tr><tr><td>[1:0]</td><td>RB_XT32K_I_TUNE</td><td>RWA</td><td>外部32KHz振荡器偏置电流选择:00:70%额定电流;01:额定电流;10:140%额定电流;11:200%额定电流。注:在晶体振荡器稳定后可改为额定电流。</td><td>11b</td></tr></table>

32KHz 振荡器配置寄存器(R8\_CK32K\_CONFIG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_32K_CLK_PIN</td><td>RO</td><td>32KHz时钟引脚状态（异步信号）。</td><td>X</td></tr><tr><td>[6:4]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>3</td><td>RB_CLK_OSC32K_FILT</td><td>RWA</td><td>内部32KHz振荡器噪声过滤模式:1:启用; 0:禁止。</td><td>0</td></tr><tr><td>2</td><td>RB_CLK_OSC32K_XT</td><td>RWA</td><td>CK32K(32KHz)时钟源选择位:1:外部32KHz振荡器;0:内部32KHz振荡器。</td><td>0</td></tr><tr><td>1</td><td>RB_CLK_INT32K_PON</td><td>RWA</td><td>内部32KHz振荡器电源控制位:1:上电; 0:掉电。</td><td>1</td></tr><tr><td>0</td><td>RB_CLK_XT32K_PON</td><td>RWA</td><td>外部32KHz振荡器电源控制位:1:上电; 0:掉电。</td><td>0</td></tr></table>

外部 32MHz 时钟谐振控制寄存器(R8\_XT32M\_TUNE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>RB_XT32M_C_LOAD</td><td>RWA</td><td>选择与外部32MHz晶体匹配的内置负载电容（可能影响无线通讯）：[7] = 0：电容量 = RB_XT32M_C_LOAD*2 + 10pF；[7] = 1：电容量 = RB_XT32M_C_LOAD*2 + 2pF。</td><td>0</td></tr><tr><td></td><td></td><td></td><td>因此 0000b~0111b 分别对应约 10pF~24pF; 1000b~1111b 分别对应约 2pF~16pF 根据所用晶体参数选择, 常用为 0111b。</td><td></td></tr><tr><td>[3:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[1:0]</td><td>RB_XT32M_I_BIAS</td><td>RWA</td><td>外部 32MHz 振荡器偏置电流选择:00: 75%额定电流;01: 额定电流;10: 125%额定电流;11: 150%额定电流。</td><td>11b</td></tr></table>

振荡器频率校准计数值寄存器(R16\_OSC\_CAL\_CNT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_osc_CAL_IF</td><td>RW1Z</td><td>振荡器捕捉完成中断标志位，写1清零：1：有中断；0：无中断。</td><td>0</td></tr><tr><td>14</td><td>RB_osc_CAL_OV_CLR</td><td>RW1Z</td><td>R8_osc_CAL_OV_CNT 寄存器数值非零指示，写1将R8_osc_CAL_OV_CNT清零。</td><td>0</td></tr><tr><td>[13:0]</td><td>RB_osc_CAL_CNT</td><td>RO</td><td>对多个CK32K周期基于系统主频的计数值，用于校准内部32KHz振荡器频率。</td><td>XXXXh</td></tr></table>

振荡器频率校准溢出次数寄存器(R8\_OSC\_CAL\_OV\_CNT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>RB_osc_CAL_OV_CNT</td><td>RO</td><td>振荡器频率校准计数溢出次数，向RB_osc_CAL_OV_CLR写1清零此寄存器。</td><td>0</td></tr></table>

振荡器频率校准控制寄存器(R8\_OSC\_CAL\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>6</td><td>RB_osc_CNT_END</td><td>RWA</td><td>振荡器捕捉终点选择:1:追加2个周期;0:不追加。</td><td>0</td></tr><tr><td>5</td><td>RB_osc_CNT_EN</td><td>RWA</td><td>振荡器频率校准计数器使能位:1:使能计数;0:禁止计数。</td><td>0</td></tr><tr><td>4</td><td>RB_osc_CAL_IE</td><td>RWA</td><td>振荡器捕捉完成中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>3</td><td>RB_osc_CNT_HALT</td><td>R0</td><td>振荡器频率校准计数器计数状态位:1:正在暂停计数;0:正在计数中。</td><td>1</td></tr><tr><td>[2:0]</td><td>RB_osc_CNT_TOTAL</td><td>RWA</td><td>振荡器捕捉总周期数选择:000:1个;001:2个;010:4个;011:32个;100:64个;101:128个;110:1024个;111:2047个。</td><td>001b</td></tr></table>

PLL 配置寄存器(R8\_PLL\_CONFIG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[5:0]</td><td>RB_PLL_CFG_DAT</td><td>RWA</td><td>PLL配置参数。</td><td>001010b</td></tr></table>

RTC 标志和控制寄存器(R8\_RTC\_FLAG\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_RTC_TRIG_FLAG</td><td>RO</td><td>RTC触发模式激活标志。</td><td>0</td></tr><tr><td>6</td><td>RB_RTC_TMR_FLAG</td><td>RO</td><td>RTC定时模式激活标志。</td><td>0</td></tr><tr><td>5</td><td>RB_RTC_TRIG_CLR</td><td>RW</td><td>禁用触发模式时,此位固定为1。使能触发模式时,写1清零触发模式激活标志RB_RTC_TRIG_FLAG并自动清0。</td><td>1</td></tr><tr><td>4</td><td>RB_RTC_TMR_CLR</td><td>RW</td><td>禁用定时模式时,此位固定为1。使能定时模式时,写1清零定时模式激活标志RB_RTC_TMR_FLAG并自动清0。</td><td>1</td></tr><tr><td>[3:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr></table>

RTC 模式配置寄存器(R8\_RTC\_MODE\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_RTC_LOAD_HI</td><td>RWA</td><td>写1将加载RTC计数器高字,加载后自动清0。将R32_RTC_TRIG(实际仅低14位)加载到R32_RTC_CNT_DAY。</td><td>0</td></tr><tr><td>6</td><td>RB_RTC_LOAD_LO</td><td>RWA</td><td>写1将加载RTC计数器低字,加载后自动清0。将R32_RTC_TRIG高16位加载到R16_RTC_CNT_2S;将R32_RTC_TRIG低16位加载到R16_RTC_CNT_32K。</td><td>0</td></tr><tr><td>5</td><td>RB_RTC_TRIG_EN</td><td>RWA</td><td>RTC触发模式使能位:1:使能; 0:禁用。</td><td>0</td></tr><tr><td>4</td><td>RB_RTC_TMR_EN</td><td>RWA</td><td>RTC定时模式使能位:1:使能; 0:禁用。</td><td>0</td></tr><tr><td>3</td><td>RB_RTCignite_BO</td><td>RWA</td><td>触发模式下忽略比较匹配值的最低位:1:忽略最低位;0:比较最低位。</td><td>0</td></tr><tr><td>[2:0]</td><td>RB_RTC_TMR_MODE</td><td>RWA</td><td>RTC定时模式固定周期(定时)选择:000:0.125S; 001:0.25S;010:0.5S; 011:1S;100:2S; 101:4S;110:8S; 111:16S。</td><td>010b</td></tr></table>

RTC 触发数值寄存器(R32\_RTC\_TRIG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>R32_RTC_TRIG</td><td>RWA</td><td>RTC触发模式下的预设匹配数值,其高16位和低16位分别与R16_RTC_CNT_2S和R16_RTC_CNT_32K进行匹配。与RB_RTC_LOAD_LO及RB_RTC_LOAD_HI配合,用于更新RTC计数器当前值。</td><td>0</td></tr></table>

注：预设匹配数值不是直接写入目标时间，涉及简单计算，请参考后面的说明。

RTC 基于 32768Hz 计数值寄存器(R16\_RTC\_CNT\_32K)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_RTC_CNT_32K</td><td>R0</td><td>RTC基于32768Hz计数值寄存器。</td><td>XXXXh</td></tr></table>

RTC 以 2S 为单位的计数值寄存器(R16\_RTC\_CNT\_2S)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_RTC_CNT_2S</td><td>R0</td><td>RTC以2S为单位的当前计数值。</td><td>XXXXh</td></tr></table>

RTC 以天为单位的计数值寄存器(R32\_RTC\_CNT\_DAY)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:14]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[13:0]</td><td>R32_RTC_CNT_DAY</td><td>R0</td><td>RTC以天为单位的当前计数值。</td><td>XXXXXXXXXXb</td></tr></table>

# 6.4 功能描述及配置

# 6.4.1 RTC 计数器初始化

(1)、设置 R32\_RTC\_TRIG 寄存器数值，将 RB\_RTC\_LOAD\_HI 置位，即可将 R32\_RTC\_TRIG 寄存器的数值加载到 R32\_RTC\_CNT\_DAY 寄存器中；

(2)、设置 R32\_RTC\_TRIG 寄存器数值，将 RB\_RTC\_LOAD\_LO 置位，即可将 R32\_RTC\_TRIG 寄存器的高低各 16 位数值分别加载到 R16\_RTC\_CNT\_2S 寄存器和 R16\_RTC\_CNT\_32K 寄存器。

# 6.4.2 RTC 时钟源切换为 LSE 晶振

(1)、确认 X32KI 和 X32KO 所在的 GPIO 引脚没有设置为输出，没有设置上拉和下拉电阻，只有晶体；

(2)、配置 R8\_CK32K\_CONFIG 寄存器，置 RB\_CLK\_XT32K\_PON 为 1，开启外部 32KHz 晶体振荡器；

(3)、建议先置 RB\_XT32K\_I\_TUNE 为最大，等待晶体振荡器稳定（约数百 mS）后再改为额定电流；

(4)、配置 R8\_CK32K\_CONFIG 寄存器，置 RB\_CLK\_OSC32K\_XT 为 1，要求时钟源切换到晶体振荡器；

(5)、等待至少半个 32KHz 时钟周期，通常 16uS，真正完成时钟源的切换。

# 6.4.3 RTC 定时功能

(1)、配置 R8\_RTC\_MODE\_CTRL 寄存器，设置 RB\_RTC\_TMR\_MODE 选择合适的定时周期，置 RB\_RTC\_TMR\_EN为1，打开RTC定时功能；

(2)、达到定时周期后，会产生 RTC 定时激活标志 RB\_RTC\_TMR\_FLAG 及中断，查询 R8\_RTC\_FLAG\_CTRL寄存器，置位 RB\_RTC\_TMR\_CLR 可清零标志。

# 6.4.4 RTC 触发功能

(1)、在R32\_RTC\_TRIG寄存器中设置好目标匹配数值，计算和操作步骤：

以当前时间 R32\_RTC\_CNT\_32K（高 16 位 R16\_RTC\_CNT\_2S 和低 16 位 R16\_RTC\_CNT\_32K）加上间隔时间 DelayTime（单位 S），计算出目标时间数值，T32 = R32\_RTC\_CNT\_32K $^ +$ DelayTime $^ \*$ 32768，将T32写入R32\_RTC\_TRIG寄存器中，完成匹配数值设定；

(2)、配置 R8\_RTC\_MODE\_CTRL 寄存器，置 RB\_RTC\_TRIG\_EN 为 1，打开 RTC 触发功能；

(3)、当 RTC 当前计数值 R16\_RTC\_CNT\_2S 和 R16\_RTC\_CNT\_32K 分别与 R32\_RTC\_TRIG 预设的高和低 16位匹配时，产生 RTC 触发激活标志 RB\_RTC\_TRIG\_FLAG 及中断，置位 RB\_RTC\_TRIG\_CLR 可清零标志。

(4)、如果 RTC 已经过校时，那么可以支持目标绝对时间触发，由目标年/月/日/时/分/秒/毫秒计算出目标时间数值T32，其它步骤同上。具体可参考评估板例子程序。

# 6.4.5 用 HSE 校准内部 32K 时钟 LSI

参考评估板例子程序。

# 第 7 章 通用 I/O 和复用功能

# 7.1 GPIO 简介

芯片提供了 2 组 GPIO 端口 PA 和 PB，共 40 个通用输入输出引脚，其中 32 个引脚具有中断和唤醒功能，部分引脚具有复用及映射功能。

每个 GPIO 端口有一个 32 位方向配置寄存器 R32\_Px\_DIR，一个 32 位引脚输入寄存器 R32\_Px\_PIN，一个32位数据输出寄存器R32\_Px\_OUT，一个32位数据复位寄存器R32\_Px\_CLR，一个32位上拉电阻配置寄存器 R32\_Px\_PU，一个 32 位下拉电阻/驱动能力配置寄存器 R32\_Px\_PD\_DRV。

PA 端口中 PA\[0]～PA\[15]位有效，对应芯片上 16 个 GPIO 引脚。

PB 端口中 PB\[0]～PB\[23]位有效，对应芯片上 24 个 GPIO 引脚。

每个I/O端口位可以自由编程，但是I/O端口寄存器必须按8位、16位或者32位字访问。如果引脚的复用功能没有开启，则默认作为通用I/O口使用。

下图是GPIO内部结构框图：

图 7-1 I/O 内部结构框图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/0e3e0dbe73463d64c596d5e11297de784ae331eff7b3a2907f44c1b77910a266.jpg null)

# 7.2 外部中断/唤醒

芯片的部分I/O管脚具有中断功能，并可实现睡眠唤醒。

为了使用外部中断，端口位必须配置成输入模式。并提供4种触发模式：高电平、低电平、上升沿、下降沿。

唤醒功能需要打开端口位的中断使能 R16\_Px\_INT\_EN，并开启寄存器 R8\_SLP\_WAKE\_CTRL 中的 GPIO唤醒控制位 RB\_SLP\_GPIO\_WAKE。

当配置多个I/O为边沿唤醒，其中一个I/O产生符合条件的唤醒信号，其它配置的I/O必须符合以下条件：如果配置为上升沿唤醒，需保持为低电平；如果配置为下降沿唤醒，需保持为高电平。此时才能够正常唤醒。

# 7.3 GPIO 的复用与重映射

# 7.3.1 复用功能

部分 I/O 引脚具有复用功能，上电后默认所有 I/O 引脚均为通用 I/O 功能，启用各功能模块后，相应的原 GPIO 引脚被配置成各自功能模块对应的功能引脚。

如果一个管脚复用多个功能，并且多个功能都已开启，那么复用功能的优先级顺序请参考1.2节引脚描述的“复用功能”列表中功能顺序。

例如：PB23 脚复用为 RST#/TMR0\_/TXD2\_/PWM11，则 RST#复位输入功能优先，PWM11 输出功能的优先级最低。这样可以在多个复用功能中，将功能优先级最低的部分不需使用的引脚启用相对更高优先级的复用功能。

下表列出了部分用于外设模块的功能引脚的 GPIO 配置。

表 7-1 定时器 x

<table><tr><td>TMRO/1/2/3 引脚</td><td>功能配置</td><td>GPIO 配置</td></tr><tr><td rowspan="2">TMRx</td><td>输入捕捉通道 x</td><td>输入(浮空输入/上拉输入/下拉输入)</td></tr><tr><td>输出 PWM 通道 x</td><td>推挽输出</td></tr></table>

表 7-2 UARTx

<table><tr><td>UART0/1/2/3 引脚</td><td>功能配置</td><td>GPIO 配置</td></tr><tr><td>TXDx</td><td>串口发送 x</td><td>推挽输出</td></tr><tr><td>RXDx</td><td>串口接收 x</td><td>上拉输入（推荐）或浮空输入</td></tr><tr><td>RTS, DTR</td><td>MODEM 信号输出或 RS485 控制</td><td>推挽输出</td></tr><tr><td>CTS, DSR, RI, DCD</td><td>MODEM 信号输入</td><td>上拉输入（推荐）或浮空输入</td></tr></table>

表 7-3 SPI

<table><tr><td>SPI引脚</td><td>功能配置</td><td>GPIO配置</td></tr><tr><td rowspan="2">SCKx</td><td>主模式时钟输出</td><td>推挽输出</td></tr><tr><td>从模式时钟输入</td><td>输入(浮空输入/上拉输入/下拉输入)</td></tr><tr><td rowspan="4">MOSIX</td><td>全双工模式-主模式</td><td>推挽输出</td></tr><tr><td>全双工模式-从模式</td><td>输入(浮空输入/上拉输入/下拉输入)</td></tr><tr><td>半双工模式-主模式</td><td>未用到,可做通用I/O</td></tr><tr><td>半双工模式-从模式</td><td>未用到,可做通用I/O</td></tr><tr><td rowspan="4">MISOx</td><td>全双工模式-主模式</td><td>输入(浮空输入/上拉输入/下拉输入)</td></tr><tr><td>全双工模式-从模式</td><td>输入(推荐上拉,片选后自动切为推挽输出)或推挽输出(禁止用于总线连接方式)</td></tr><tr><td>半双工模式-主模式</td><td>输入或推挽输出,手工切换</td></tr><tr><td>半双工模式-从模式</td><td>输入(推荐上拉,片选后自动切为推挽输出)</td></tr><tr><td rowspan="2">SCS</td><td>主模式片选输出</td><td>推挽输出(可换用其它引脚)</td></tr><tr><td>从模式片选输入</td><td>上拉输入(推荐)或浮空输入</td></tr></table>

表 7-4 I2C

<table><tr><td>I2C引脚</td><td>功能配置</td><td>GPIO配置</td></tr><tr><td rowspan="3">SCL</td><td>串行时钟输出-主模式</td><td>推挽输出(此模式不支持多主机)</td></tr><tr><td>串行时钟输出/输入-多主模式</td><td>输入(推荐上拉,需要时自动开漏输出)</td></tr><tr><td>串行时钟输入-从模式</td><td>上拉输入(推荐)或浮空输入</td></tr><tr><td>SDA</td><td>串行数据输入输出</td><td>输入(推荐上拉,需要时自动开漏输出)</td></tr></table>

表 7-5 ADC

<table><tr><td>ADC采样通道引脚</td><td>功能配置</td><td>GPIO配置</td></tr><tr><td>Ax</td><td>模拟数字转换输入通道</td><td>仅模拟输入</td></tr></table>

表 7-6 USB

<table><tr><td>USB信号引脚</td><td>功能配置</td><td>GPIO配置</td></tr><tr><td>UD-</td><td>连接到内部全速USB收发器</td><td>浮空输入</td></tr><tr><td>UD+</td><td>连接到内部全速USB收发器</td><td>浮空输入</td></tr><tr><td>U2D-</td><td>连接到内部高速USB收发器</td><td>浮空输入</td></tr><tr><td>U2D+</td><td>连接到内部高速USB收发器</td><td>浮空输入</td></tr></table>

表 7-7 NFC

<table><tr><td>NFC信号引脚</td><td>功能配置</td><td>GPIO配置</td></tr><tr><td>NFC1, NFCM</td><td>NFC模拟输入</td><td>仅模拟输入</td></tr><tr><td>NFC+, NFC-</td><td>NFC模拟输出</td><td>仅模拟输入</td></tr></table>

# 7.3.2 功能引脚重映射

为了使外设功能的同时利用率达到最优，可以通过设置R16\_PIN\_ALTERNATE功能引脚重映射寄存器把一些功能引脚重新映射到其他引脚上。

表7-8 复用功能重映射引脚

<table><tr><td>外设功能引脚</td><td>默认所在的 GPIO 引脚</td><td>重映射到的 GPIO 引脚</td></tr><tr><td>SCS/SCK0/MOSI/MISO</td><td>PA[12]/PA[13]/PA[14]/PA[15]</td><td>PB[12]/PB[13]/PB[14]/PB[15]</td></tr><tr><td>RXD3/TXD3</td><td>PA[4]/PA[5]</td><td>PB[20]/PB[21]</td></tr><tr><td>RXD2/TXD2</td><td>PA[6]/PA[7]</td><td>PB[22]/PB[23]</td></tr><tr><td>RXD1/TXD1</td><td>PA[8]/PA[9]</td><td>PB[12]/PB[13]</td></tr><tr><td>RXD0/TXD0/DSR/DTR</td><td>PB[4]/PB[7]/PB[1]/PB[5]</td><td>PA[15]/PA[14]/PB[14]/PB[15]</td></tr><tr><td>TMR3/PWM3/CAP3</td><td>PB[22]</td><td>PA[2]</td></tr><tr><td>TMR2/PWM2/CAP2</td><td>PA[11]</td><td>PB[11]</td></tr><tr><td>TMR1/PWM1/CAP1</td><td>PA[10]</td><td>PB[10]</td></tr><tr><td>TMRO/PWM0/CAPO</td><td>PA[9]</td><td>PB[23]</td></tr><tr><td>PWM4/PWM5</td><td>PA[12]/PA[13]</td><td>PA[6]/PA[7]</td></tr><tr><td>PWM7/PWM8/PWM9</td><td>PB[4]/PB[6]/PB[7]</td><td>PB[1]/PB[2]/PB[3]</td></tr><tr><td>SCL/SDA</td><td>PB[13]/PB[12]</td><td>PB[21]/PB[20]</td></tr></table>

# 7.4 寄存器描述

表 7-9 GPIO 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R16_PIN_ALTERNATE</td><td>0x40001018</td><td>功能引脚重映射寄存器</td><td>0x0000</td></tr><tr><td>R16_PIN_CONFIG</td><td>0x4000101A</td><td>功能引脚配置寄存器</td><td>0x0000</td></tr><tr><td>R32_PIN_IN_DIS</td><td>0x4000101C</td><td>功能引脚数字输入禁用寄存器</td><td>0x0000</td></tr><tr><td>R16_PA_INT_EN</td><td>0x40001090</td><td>PA端口中断使能寄存器</td><td>0x0000</td></tr><tr><td>R16_PB_INT_EN</td><td>0x40001092</td><td>PB端口中断使能寄存器</td><td>0x0000</td></tr><tr><td>R16_PA_INT_MODE</td><td>0x40001094</td><td>PA端口中断模式配置寄存器</td><td>0x0000</td></tr><tr><td>R16_PB_INT_MODE</td><td>0x40001096</td><td>PB端口中断模式配置寄存器</td><td>0x0000</td></tr><tr><td>R16_PA_INT_IF</td><td>0x4000109C</td><td>PA端口中断标志寄存器</td><td>0x0000</td></tr><tr><td>R16_PB_INT_IF</td><td>0x4000109E</td><td>PB端口中断标志寄存器</td><td>0x0000</td></tr><tr><td>R32_PA_DIR</td><td>0x400010A0</td><td>PA端口方向配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PA_PIN</td><td>0x400010A4</td><td>PA端口引脚输入寄存器</td><td>0x0000XXXX</td></tr><tr><td>R32_PA_OUT</td><td>0x400010A8</td><td>PA端口数据输出寄存器</td><td>0x00000000</td></tr><tr><td>R32_PA_CLR</td><td>0x400010AC</td><td>PA端口数据复位寄存器</td><td>0x00000000</td></tr><tr><td>R32_PA_PU</td><td>0x400010B0</td><td>PA端口上拉电阻配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PA_PD_DRV</td><td>0x400010B4</td><td>PA端口下拉/驱动配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PA_SET</td><td>0x400010B8</td><td>PA端口输出置位寄存器</td><td>0x00000000</td></tr><tr><td>R32_PB_DIR</td><td>0x400010C0</td><td>PB端口方向配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PB_PIN</td><td>0x400010C4</td><td>PB端口引脚输入寄存器</td><td>0x00XXXXXX</td></tr><tr><td>R32_PB_OUT</td><td>0x400010C8</td><td>PB端口数据输出寄存器</td><td>0x00000000</td></tr><tr><td>R32_PB_CLR</td><td>0x400010CC</td><td>PB端口数据复位寄存器</td><td>0x00000000</td></tr><tr><td>R32_PB_PU</td><td>0x400010D0</td><td>PB端口上拉电阻配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PB_PD_DRV</td><td>0x400010D4</td><td>PB端口下拉/驱动配置寄存器</td><td>0x00000000</td></tr><tr><td>R32_PB_SET</td><td>0x400010D8</td><td>PB端口输出置位寄存器</td><td>0x00000000</td></tr></table>

功能引脚重映射寄存器(R16\_PIN\_ALTERNATE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_RFAnt_SW_EN</td><td>RW</td><td>RF天线开关控制输出使能:1:开关控制输出到PB[16]~PB[21];0:禁止输出。</td><td>0</td></tr><tr><td>14</td><td>RB_PIN_UO_INV</td><td>RW</td><td>UART0输入输出反相使能:1: RXD0/RXD0反相输入, TXD0/TXD0反相输出;0:正常同相输入、输出。</td><td>0</td></tr><tr><td>13</td><td>RB_PIN_INTX</td><td>RW</td><td>INT24/INT25功能引脚映射选择位:1: INT24/25映射到PB[22]/PB[23];0: INT24/25映射到PB[8]/PB[9]。注: INT24/INT25是R16_PB_INT_EN、R16_PB_INT_MODE、R16_PB_INT_IF中[9:8]对应的中断输入。</td><td>0</td></tr><tr><td>12</td><td>RB_PIN_MODEM</td><td>RW</td><td>UART0 MODEM功能引脚映射选择位:1: DSR/DTR映射到PB[14]/PB[15];0: DSR/DTR映射到PB[1]/PB[5]。</td><td>0</td></tr><tr><td>11</td><td>RB_PIN_I2C</td><td>RW</td><td>I2C功能引脚映射选择位:1: SCL/SDA映射到PB[21]/PB[20];0: SCL/SDA映射到PB[13]/PB[12]。</td><td>0</td></tr><tr><td>10</td><td>RB_PIN_PWMX</td><td>RW</td><td>PWMx功能引脚映射选择位:1: PWM4/5/7/8/9映射到PA[6]/PA[7]/PB[1]/PB[2]/PB[3];0: PWM4/5/7/8/9映射到PA[12]/PA[13]/PB[4]/PB[6]/PB[7]。</td><td>0</td></tr><tr><td>9</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>8</td><td>RB_PIN_SPI0</td><td>RW</td><td>SPI0功能引脚映射选择位:1: SCK0/SCS/MOSI/MISO映射到PB[12]/PB[13]/PB[14]/PB[15];0: SCK0/SCS/MOSI/MISO映射到PA[12]/PA[13]/PA[14]/PA[15]。</td><td>0</td></tr><tr><td>7</td><td>RB_PIN_UART3</td><td>RW</td><td>UART3功能引脚映射选择位:1: RXD3_/TXD3_映射到PB[20]/PB[21];0: RXD3/TXD3映射到PA[4]/PA[5]。</td><td>0</td></tr><tr><td>6</td><td>RB_PIN_UART2</td><td>RW</td><td>UART2 功能引脚映射选择位:1: RXD2_/TXD2_映射到PB[22]/PB[23];0: RXD2/TXD2 映射到 PA[6]/PA[7]。</td><td>0</td></tr><tr><td>5</td><td>RB_PIN_UART1</td><td>RW</td><td>UART1 功能引脚映射选择位:1: RXD1_/TXD1_映射到 PB[12]/PB[13];0: RXD1/TXD1 映射到 PA[8]/PA[9]。</td><td>0</td></tr><tr><td>4</td><td>RB_PIN_UART0</td><td>RW</td><td>UART0 功能引脚映射选择位:1: RXD0_/TXD0_映射到 PA[15]/PA[14];0: RXD0/TXD0 映射到 PB[4]/PB[7]。</td><td>0</td></tr><tr><td>3</td><td>RB_PIN_TMR3</td><td>RW</td><td>TMR3 功能引脚映射选择位:1: TMR3_/PWM3_/CAP3_映射到 PA[2];0: TMR3/PWM3/CAP3 映射到 PB[22]。</td><td>0</td></tr><tr><td>2</td><td>RB_PIN_UART2</td><td>RW</td><td>TMR2 功能引脚映射选择位:1: TMR2_/PWM2_/CAP2_映射到 PB[11];0: TMR2/PWM2/CAP2 映射到 PA[11]。</td><td>0</td></tr><tr><td>1</td><td>RB_PIN_TMR1</td><td>RW</td><td>TMR1 功能引脚映射选择位:1: TMR1_/PWM1_/CAP1_映射到 PB[10];0: TMR1/PWM1/CAP1 映射到 PA[10]。</td><td>0</td></tr><tr><td>0</td><td>RB_PIN_SMRO</td><td>RW</td><td>TMRO 功能引脚映射选择位:1: TMRO_/PWM0_/CAPO_映射到 PB[23];0: TMRO/PWM0/CAPO 映射到 PA[9]。</td><td>0</td></tr></table>

功能引脚配置寄存器(R16\_PIN\_CONFIG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>RB_PBHx_IN_DIS</td><td>RW</td><td>(x=[23:16])PB16~PB23通道引脚数字输入禁用。1:关闭数字输入,可减少I/0漏电,PB16~PB23为LCD段驱动;0:打开数字输入,关闭LCD段驱动。注:1.位8~15与PB16~PB23一一对应。2.PB0~PB15通道引脚数字输入禁用请参考寄存器R32_PIN_IN_DIS相对应的位。</td><td>0</td></tr><tr><td>7</td><td>RB_PIN_USB_EN</td><td>RW</td><td>全速USB引脚使能:1:PB10~11为全速USB通讯引脚;0:PB10~11不用于全速USB通讯。</td><td>0</td></tr><tr><td>6</td><td>RB_UDPPU_EN</td><td>RW</td><td>全速USB UD+引脚内部上拉电阻使能:1:强制使能上拉(RB_UC_DEVPU_EN在睡眠或下电模式下不起作用,由此代替);0:由RB_UC_DEVPU_EN控制是否上拉。</td><td>0</td></tr><tr><td>5</td><td>RB_PIN_USB2_EN</td><td>RW</td><td>高速USB引脚使能:1:PB12~13为高速USB通讯引脚;0:PB12~13不用于高速USB通讯。</td><td>0</td></tr><tr><td>4</td><td>RB_PB16_8_SEL</td><td>RW</td><td>PB8和PB16的中断引脚选择:1:PB16;0:PB8。</td><td>0</td></tr><tr><td>[3:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr></table>

注：如果引脚用于模拟功能，建议将该引脚的数字输入功能关闭，即设置数字输入禁用，从而可以降低功耗，并有利于减少干扰。

功能引脚数字输入禁用寄存器(R32\_PIN\_IN\_DIS)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>RB_PBLx_IN_DIS</td><td>RW</td><td>(x=[15:0])PBO~PB15通道引脚数字输入禁用。1:关闭数字输入,可减少I/0漏电,PBO~PB15为LCD段驱动;0:打开数字输入,关闭LCD段驱动。注:1.位16~31与PBO~PB15一一对应。2.PB16~PB23通道引脚数字输入禁用请参考寄存器R16_PIN_CONFIG的相对应的位。</td><td>0</td></tr><tr><td>[15:0]</td><td>RB_PAX_IN_DIS</td><td>RW</td><td>(x=[15:0])PAO~PA15通道引脚数字输入禁用。1:关闭数字输入,可减少I/0漏电,其中PAO~PA3、PA7~PA9以及PA13为LCD段驱动;0:打开数字输入,关闭LCD段驱动。注:位0~15与PAO~PA15一一对应。</td><td>0</td></tr></table>

注：如果引脚用于模拟功能，建议将该引脚的数字输入功能关闭，即设置数字输入禁用，从而可以降低功耗，并有利于减少干扰。

PA 端口中断使能寄存器(R16\_PA\_INT\_EN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_PA_INT_EN</td><td>RW</td><td>PA引脚中断使能位:
1:使能相应中断;
0:禁止相应中断。</td><td>0</td></tr></table>

PB 端口中断使能寄存器(R16\_PB\_INT\_EN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_PB_INT_EN</td><td>RW</td><td>PB引脚中断使能位:
1:使能相应中断;
0:禁止相应中断。</td><td>0</td></tr></table>

注：R16\_PB\_INT\_EN\[9:8]由RB\_PIN\_INTX选择对应PB\[23:22]或PB\[9:8]。

PA 端口中断模式配置寄存器(R16\_PA\_INT\_MODE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_PA_INT_MODE</td><td>RW</td><td>PA引脚中断模式选择位:
1:边沿触发; 0:电平触发。</td><td>0</td></tr></table>

PB 端口中断模式配置寄存器(R16\_PB\_INT\_MODE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_PB_INT_MODE</td><td>RW</td><td>PB引脚中断模式选择位:1:边沿触发; 0:电平触发。</td><td>0</td></tr></table>

注：R16\_PB\_INT\_MODE\[9:8]由RB\_PIN\_INTX选择对应PB\[23:22]或PB\[9:8]。

PA 端口中断标志寄存器(R16\_PA\_INT\_IF)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_PA_INT_IF</td><td>RW1Z</td><td>PA引脚中断标志位，写1清零：
1：有中断； 0：无中断。</td><td>0</td></tr></table>

PB 端口中断标志寄存器(R16\_PB\_INT\_IF)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_PB_INT_IF</td><td>RW1Z</td><td>PB引脚中断标志位，写1清零：
1：有中断； 0：无中断。</td><td>0</td></tr></table>

注：R16\_PB\_INT\_IF\[9:8]由RB\_PIN\_INTX选择对应PB\[23:22]或PB\[9:8]。

PA 端口方向配置寄存器(R32\_PA\_DIR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_DIR_1</td><td>RW</td><td>PA引脚当前输入输出方向配置:</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PA_DIR_0</td><td>RW</td><td>1:引脚为输出模式;0:引脚为输入模式。</td><td>0</td></tr></table>

PA 端口引脚输入寄存器(R32\_PA\_PIN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_PIN_1</td><td>R0</td><td>PA引脚当前电平状态（仅在R32_PA_DIR对应位为0时，该位值有效）：</td><td>XXh</td></tr><tr><td>[7:0]</td><td>R8_PA_PIN_0</td><td>R0</td><td>1：引脚输入高电平；0：引脚输入低电平。</td><td>XXh</td></tr></table>

PA 端口数据输出寄存器(R32\_PA\_OUT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_OUT_1</td><td>RW</td><td rowspan="2">方向寄存器R32_PA_DIR对应位为1时:控制PA引脚输出电平状态:1:输出高电平;0:输出低电平。方向寄存器R32_PA_DIR对应位为0时:控制PA引脚中断极性选择:1:高电平/上升沿;0:低电平/下降沿。</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PA_OUT_0</td><td>RW</td><td>0</td></tr></table>

PA 端口数据复位寄存器(R32\_PA\_CLR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_CLR_1</td><td>WZ</td><td>PA数据寄存器复位控制:</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PA_CLR_0</td><td>WZ</td><td>1: R32_PA_OUT对应位数据清0;0:无影响。</td><td>0</td></tr></table>

PA 端口上拉电阻配置寄存器(R32\_PA\_PU)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_PA_1</td><td>RW</td><td>PA引脚上拉电阻使能控制:</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PA_PA_0</td><td>RW</td><td>1:启用上拉电阻;0:关闭上拉电阻。</td><td>0</td></tr></table>

PA 端口下拉/驱动配置寄存器(R32\_PA\_PD\_DRV)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_PD_DRV_1</td><td>RW</td><td rowspan="2">方向寄存器R32_PA_DIR对应位为0时:PA引脚下拉电阻使能控制:1:启用下拉电阻;0:关闭下拉电阻。方向寄存器R32_PA_DIR对应位为1时:PA引脚电流驱动能力选择:1:20mA级别;0:5mA级别。</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PA_PD_DRV_0</td><td>RW</td><td>0</td></tr></table>

PA 端口输出置位寄存器 (R32\_PA\_SET)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PA_SET_1</td><td>WZ</td><td rowspan="2">置位寄存器 R32_PA_SET 对应位为 0 时,PA 引脚输出保持;为 1 时, PA 引脚输出高电平。</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PA_SET_0</td><td>WZ</td><td>0</td></tr></table>

PB 端口方向配置寄存器(R32\_PB\_DIR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB_DIR_2</td><td>RW</td><td>PB引脚当前输入输出方向配置:</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PB_DIR_1</td><td>RW</td><td>1:引脚为输出模式;</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PB_DIR_0</td><td>RW</td><td>0:引脚为输入模式。</td><td>0</td></tr></table>

PB 端口引脚输入寄存器(R32\_PB\_PIN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB_PIN_2</td><td>R0</td><td rowspan="2">PB引脚当前电平状态（仅在R32_PB_DIR对应位为0时，该位值有效）：</td><td>XXh</td></tr><tr><td>[15:8]</td><td>R8_PB_PIN_1</td><td>R0</td><td>XXh</td></tr><tr><td>[7:0]</td><td>R8_PB_PIN_0</td><td>R0</td><td>1：引脚输入高电平；0：引脚输入低电平。</td><td>XXh</td></tr></table>

PB 端口数据输出寄存器(R32\_PB\_OUT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB_OUT_2</td><td>RW</td><td>方向寄存器R32_PB_DIR对应位为1时:控制PB引脚输出电平状态:1:输出高电平;0:输出低电平。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PB_OUT_1</td><td>RW</td><td rowspan="2">方向寄存器R32_PB_DIR对应位为1时:控制PB引脚输出电平状态:1:输出高电平;0:输出低电平。方向寄存器R32_PB_DIR对应位为0时:控制PB引脚中断极性选择:1:高电平/上升沿;</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PB_OUT_0</td><td>RW</td><td>0</td></tr><tr><td></td><td></td><td></td><td>0:低电平/下降沿。</td><td></td></tr></table>

PB 端口数据复位寄存器(R32\_PB\_CLR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB_CLR_2</td><td>WZ</td><td>PB数据寄存器复位控制:</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PB_CLR_1</td><td>WZ</td><td>1: R32_PB_OUT对应位数据清0;</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PB_CLR_0</td><td>WZ</td><td>0: 无影响。</td><td>0</td></tr></table>

PB 端口上拉电阻配置寄存器(R32\_PB\_PU)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB Pru_2</td><td>RW</td><td>PB引脚上拉电阻使能控制:</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PB Pru_1</td><td>RW</td><td>1:启用上拉电阻;</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PB Pru_0</td><td>RW</td><td>0:关闭上拉电阻。</td><td>0</td></tr></table>

PB 端口下拉/驱动配置寄存器(R32\_PB\_PD\_DRV)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB_PD_DRV_2</td><td>RW</td><td rowspan="2">方向寄存器R32_PB_DIR对应位为0时:PB引脚下拉电阻使能控制:1:启用下拉电阻;0:关闭下拉电阻。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PB_PD_DRV_1</td><td>RW</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PB_PD_DRV_0</td><td>RW</td><td>方向寄存器R32_PB_DIR对应位为1时:PB引脚电流驱动能力选择:1:20mA级别;0:5mA级别。</td><td>0</td></tr></table>

PB 端口输出置位寄存器 (R32\_PB\_SET)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[23:16]</td><td>R8_PB_SET_2</td><td>WZ</td><td rowspan="3">置位寄存器 R32_PB_SET 对应位为 0 时, PB 引脚输出保持;为 1 时,PB 引脚输出高电平。</td><td>0</td></tr><tr><td>[15:8]</td><td>R8_PB_SET_1</td><td>WZ</td><td>0</td></tr><tr><td>[7:0]</td><td>R8_PB_SET_0</td><td>WZ</td><td>0</td></tr></table>

# 7.5 GPIO 引脚模式配置

每个 GPIO 都可以配置成 5 种模式，具体见下表：

表7-10 端口配置表

<table><tr><td>模式</td><td>R32_Px_DIR</td><td>R32_Px_PU</td><td>RB_PAx_IN_DIS/
RB_PBLx_IN_DIS/
RB_PBHx_IN_DIS</td><td>R32_Px_PD_DRV</td></tr><tr><td>浮空输入/高阻输入/模拟输入</td><td>0</td><td>0</td><td>0</td><td>0</td></tr><tr><td>仅模拟输入(减少I/0漏电)</td><td>0</td><td>0</td><td>1</td><td>0</td></tr><tr><td>带上拉电阻的输入</td><td>0</td><td>1</td><td>0</td><td>0</td></tr><tr><td>带下拉电阻的输入</td><td>0</td><td>0</td><td>0</td><td>1</td></tr><tr><td>推挽输出,驱动能力5mA级别</td><td>1</td><td>X</td><td>X</td><td>0</td></tr><tr><td>推挽输出,驱动能力20mA级别</td><td>1</td><td>X</td><td>X</td><td>1</td></tr></table>

# 第 8 章 通用定时器 TMRx

# 8.1 TMRx 简介

芯片提供了 4 个 26 位定时器，TMR0、TMR1、TMR2 和 TMR3，最长定时时间为 $2 \hat { { \mathbf { \nabla } } } 2 6$ 个时钟周期。它适用于多种场合，包括测量输入信号脉冲长度（输入捕捉）或者产生输出波形（PWM），支持DMA功能。每个定时器都是完全独立的，可以一起同步操作。

# 8.1.1 主要特性

 4 个 26 位定时器，每个定时器定时时间最大为 $2 ^ { \sim } 2 6$ 个时钟周期

$\bullet$ 支持定时器中断，支持DMA及中断

$\bullet$ 支持捕捉功能，测量输入脉冲长度或周期

$\bullet$ 捕捉功能可设置为电平变化捕捉和高或低电平保持时间捕捉功能

$\bullet$ 支持 26 位 PWM 功能，可动态调整 PWM 占空比设置

# 8.2 寄存器描述

表 8-1 TMR0 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8(TM0_CTRL_MOD</td><td>0x40002000</td><td>模式设置寄存器</td><td>0x02</td></tr><tr><td>R8(TM0_CTRL_DMA</td><td>0x40002001</td><td>DMA 控制寄存器</td><td>0x00</td></tr><tr><td>R8(TM0_INTER_EN</td><td>0x40002002</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8(TM0_INT_FLAG</td><td>0x40002006</td><td>中断标志寄存器</td><td>0x00</td></tr><tr><td>R8(TM0_FIFO_COUNT</td><td>0x40002007</td><td>FIFO 计数寄存器</td><td>0x0X</td></tr><tr><td>R32(TM0_COUNT</td><td>0x40002008</td><td>当前计数值寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32(TM0_CNT_END</td><td>0x4000200C</td><td>计数终值设置寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32(TM0_FIFO</td><td>0x40002010</td><td>FIFO 寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32(TM0_DMA&quot;Now</td><td>0x40002014</td><td>DMA 当前缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32(TM0_DMA_BEG</td><td>0x40002018</td><td>DMA 起始缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32(TM0_DMA_END</td><td>0x4000201C</td><td>DMA 结束缓冲区地址</td><td>0x000XXXXXXXXX</td></tr></table>

表 8-2 TMR1 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_TMR1_CTRL_MOD</td><td>0x40002400</td><td>模式设置寄存器</td><td>0x02</td></tr><tr><td>R8_TMR1_CTRL_DMA</td><td>0x40002401</td><td>DMA 控制寄存器</td><td>0x00</td></tr><tr><td>R8_TMR1_INTER_EN</td><td>0x40002402</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_TMR1_INT_FLAG</td><td>0x40002406</td><td>中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_TMR1_FIFO_COUNT</td><td>0x40002407</td><td>FIFO 计数寄存器</td><td>0x0X</td></tr><tr><td>R32_TMR1_COUNT</td><td>0x40002408</td><td>当前计数值寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR1_CNT_END</td><td>0x4000240C</td><td>计数终值寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR1_FIFO</td><td>0x40002410</td><td>FIFO 寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR1_DMA NOW</td><td>0x40002414</td><td>DMA 当前缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32_TMR1_DMA_BEG</td><td>0x40002418</td><td>DMA 起始缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32_TMR1_DMA_END</td><td>0x4000241C</td><td>DMA 结束缓冲区地址</td><td>0x000XXXXXXXXX</td></tr></table>

表 8-3 TMR2 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_TMR2_CTRL_MOD</td><td>0x40002800</td><td>模式设置寄存器</td><td>0x02</td></tr><tr><td>R8_TMR2_CTRL_DMA</td><td>0x40002801</td><td>DMA 控制寄存器</td><td>0x00</td></tr><tr><td>R8_TMR2_INTER_EN</td><td>0x40002802</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_TMR2_INT_FLAG</td><td>0x40002806</td><td>中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_TMR2_FIFO_COUNT</td><td>0x40002807</td><td>FIFO 计数寄存器</td><td>0x0X</td></tr><tr><td>R32_TMR2_COUNT</td><td>0x40002808</td><td>当前计数值寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR2_CNT_END</td><td>0x4000280C</td><td>计数终值寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR2_FIFO</td><td>0x40002810</td><td>FIFO 寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR2_DMA NOW</td><td>0x40002814</td><td>DMA 当前缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32_TMR2_DMA_BEG</td><td>0x40002818</td><td>DMA 起始缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32_TMR2_DMA_END</td><td>0x4000281C</td><td>DMA 结束缓冲区地址</td><td>0x000XXXXXXXXX</td></tr></table>

表 8-4 TMR3 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_TMR3_CTRL_MOD</td><td>0x40002C00</td><td>模式设置寄存器</td><td>0x02</td></tr><tr><td>R8_TMR3_CTRL_DMA</td><td>0x40002C01</td><td>DMA 控制寄存器</td><td>0x00</td></tr><tr><td>R8_TMR3_INTER_EN</td><td>0x40002C02</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_TMR3_INT_FLAG</td><td>0x40002C06</td><td>中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_TMR3_FIFO_COUNT</td><td>0x40002C07</td><td>FIFO 计数寄存器</td><td>0x0X</td></tr><tr><td>R32_TMR3_COUNT</td><td>0x40002C08</td><td>当前计数值寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR3_CNT_END</td><td>0x40002C0C</td><td>计数终值设置寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR3_FIFO</td><td>0x40002C10</td><td>FIFO 寄存器</td><td>0x0XXXXXXXXX</td></tr><tr><td>R32_TMR3_DMA NOW</td><td>0x40002C14</td><td>DMA 当前缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32_TMR3_DMA_BEG</td><td>0x40002C18</td><td>DMA 起始缓冲区地址</td><td>0x000XXXXXXXXX</td></tr><tr><td>R32_TMR3_DMA_END</td><td>0x40002C1C</td><td>DMA 结束缓冲区地址</td><td>0x000XXXXXXXXX</td></tr></table>

模式设置寄存器(R8\_TMRx\_CTRL\_MOD) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB_TMR_CAP_EDGE</td><td>RW</td><td>捕捉模式下,选择捕捉触发方式:00:不触发;01:捕捉任何边沿变化之间的时间;10:捕捉下降沿到下降沿之间时间;11:捕捉上升沿到上升沿之间时间。计数模式下,选择计数的边沿:00:不采样计数;01:采样到任意边沿计数;10:采样到下降沿计数;11:采样到上升沿计数。</td><td>0</td></tr><tr><td>[7:6]</td><td>RB_TMR_PWM_REPEAT</td><td>RW</td><td>PWM模式下,选择数据重复方式:00:重复1次;01:重复4次;10:重复8次;11:重复16次。</td><td>0</td></tr><tr><td>5</td><td>RB_TMR_FREQ_13_56</td><td>RW</td><td>TMRO和TMR3的计数频率设置位:1: TMR以内部13.56M为计数频率,要求系统时钟频率必须在42MHz及以上时才可启用;0: TMR以系统时钟为计数频率。</td><td>0</td></tr><tr><td>4</td><td>RB_TMR_CAP_COUNT</td><td>RW</td><td>RB_TMR_MODE_IN=1输入模式的子模式:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:计数模式;0:捕捉模式。</td><td></td></tr><tr><td>4</td><td>RB_TMR_OUT_POLAR</td><td>RW</td><td>PWM模式下,输出极性设置位:1:默认高电平,低电平有效;0:默认低电平,高电平有效。</td><td>0</td></tr><tr><td>3</td><td>RB_TMR_OUT_EN</td><td>RW</td><td>定时器输出使能位:1:输出使能;0:输出禁止。</td><td>0</td></tr><tr><td>2</td><td>RB_TMR_COUNT_EN</td><td>RW</td><td>定时器计数使能位:1:使能计数;0:停止计数。</td><td>0</td></tr><tr><td>1</td><td>RB_TMR_ALL_CLEAR</td><td>RW</td><td>定时器的FIFO/计数器/中断标志清零:1:强制清空和清零;0:不清。</td><td>1</td></tr><tr><td>0</td><td>RB_TMR_MODE_IN</td><td>RW</td><td>定时器模式设置位:1:输入模式(捕捉模式或计数模式);0:定时模式或PWM模式。</td><td>0</td></tr></table>

中断使能寄存器(R8\_TMRx\_INTER\_EN) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_TMR_IE_FIFO_0V</td><td>RW</td><td>FIFO溢出(捕捉模式FIFO满或PWM模式FIFO空)中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>3</td><td>RB_TMR_IE_DMA_END</td><td>RW</td><td>DMA结束中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>2</td><td>RB_TMR_IE_FIFO_HF</td><td>RW</td><td>FIFO使用过半(捕捉模式FIFO&gt;=4或PWM模式FIFO&lt;4)中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>1</td><td>RB_TMR_IE_DATA_ACT</td><td>RW</td><td>数据激活(捕捉模式指每次捕捉到新数据,PWM模式指数值触发导致有效电平结束)中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>0</td><td>RB_TMR_IE_CYC_END</td><td>RW</td><td>周期结束(捕捉模式指超时,PWM模式和定时模式指周期结束)中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr></table>

中断标志寄存器(R8\_TMRx\_INT\_FLAG) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_TMR_IF_FIFO_0V</td><td>RW1Z</td><td>FIFO 溢出（捕捉模式 FIFO 满或 PWM 模式 FIFO 空）标志位，写 1 清零：1：已溢出；0：未溢出。</td><td>0</td></tr><tr><td>3</td><td>RB_TMR_IF_DMA_END</td><td>RW1Z</td><td>DMA 完成标志位,写 1 清零:1: 已完成; 0: 未完成。</td><td>0</td></tr><tr><td>2</td><td>RB_TMR_IF_FIFO_HF</td><td>RW1Z</td><td>FIFO 使用过半(捕捉模式 FIFO&gt;=4 或 PWM模式 FIFO&lt;4)标志位,写 1 清零:1: FIFO 使用已过半;0: FIFO 使用未过半。</td><td>0</td></tr><tr><td>1</td><td>RB_TMR_IF_DATA_ACT</td><td>RW1Z</td><td>数据激活(捕捉模式指每次捕捉到新数据,PWM 模式指数值触发导致有效电平结束)标志位,写 1 清零:1: 产生/用了数据;0: 未产生/未用。</td><td>0</td></tr><tr><td>0</td><td>RB_TMR_IF_CYC_END</td><td>RW1Z</td><td>周期结束(捕捉模式指超时,PWM 模式和定时模式指周期结束,计数模式指计数溢出)标志位,写 1 清零:1: 超时/周期结束;0: 未超时/未结束。</td><td>0</td></tr></table>

FIFO 计数寄存器(R8\_TMRx\_FIFO\_COUNT) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[3:0]</td><td>RB_TMRx_FIFO_COUNT</td><td>R0</td><td>FIFO内数据计数，最大值8。</td><td>0Xh</td></tr></table>

当前计数值寄存器(R32\_TMRx\_COUNT) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:26]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0Xh</td></tr><tr><td>[25:0]</td><td>R32_TMRx_COUNT</td><td>R0</td><td>计数器当前计数值。</td><td>XXXXXXXXh</td></tr></table>

计数终值设置寄存器(R32\_TMRx\_CNT\_END) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>R32_TMRx_CNT_END</td><td>RW</td><td>定时器模式下，一个定时周期时钟数；PWM模式下，PWM单周期总时钟数；捕捉模式下，捕捉超时时钟数。仅低26位有效，最大值67108863。计数模式下，计数值终值-2（溢出）。注：对此寄存器的写操作，将自动清零R32_TMRx_COUNT 寄存器中的值。</td><td>0XXXXXXXXh</td></tr></table>

FIFO 寄存器(R32\_TMRx\_FIFO) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>R32_TMRx_FIFO</td><td>RO/WO</td><td>FIFO0数据寄存器，仅低26位有效。</td><td>0XXXXXXXXh</td></tr></table>

DMA 控制寄存器(R8\_TMRx\_CTRL\_DMA) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:3]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_TMR_DMA_LOOP</td><td>RW</td><td>DMA 地址循环功能使能位:1: 使能地址循环;0: 禁止地址循环。</td><td>0</td></tr><tr><td></td><td></td><td></td><td>如果使能 DMA 地址循环,当 DMA 地址增加到设置的末尾地址时,自动循环指向设置的首地址。</td><td></td></tr><tr><td>1</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_TMR_DMA_ENABLE</td><td>RW</td><td>DMA 功能使能位:1: 使能 DMA;0: 禁止 DMA。</td><td>0</td></tr></table>

DMA 当前缓冲区地址(R32\_TMRx\_DMA\_NOW) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:2]</td><td>RB_TMRx_DMA NOW</td><td>R0</td><td>DMA数据缓冲区当前地址。可用于计算已转换次数，计算方法：COUNT=(TMR_DMA NOW-TMR_DMA_BEG)/4。</td><td>XXXXh</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

DMA 起始缓冲区地址(R32\_TMRx\_DMA\_BEG) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:2]</td><td>RB_TMRx_DMA_BEG</td><td>RW</td><td>DMA数据缓冲区起始地址，地址必须4字节对齐。</td><td>XXXXh</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

DMA 结束缓冲区地址(R32\_TMRx\_DMA\_END) (x=0/1/2/3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:2]</td><td>RB_TMRx_DMA_END</td><td>RW</td><td>DMA数据缓冲区结束地址（不含），地址必须4字节对齐。</td><td>XXXXh</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

# 8.3 功能描述及配置

# 8.3.1 定时、计数功能

芯片的每个定时器都支持最长定时时间 $2 \hat { { \mathbf { \nabla } } } 2 6$ 个时钟周期，执行增量计数模式。如果系统时钟周期为32MHz，则最长定时时间为： $3 1 . 2 5 n { \mathbb { S } } ^ { \* } 2 { \hat { \quad } } 2 6 { \approx } 2 { \mathbb { S } }$ 。每个定时器都有独立的中断。

定时功能操作步骤如下：

(1)、将 RB\_TMR\_ALL\_CLEAR 置位，清零 R32\_TMRx\_COUNT 和中断标志等；

(2)、设置寄存器 R32\_TMRx\_CNT\_END 为需要定时的时间值；

具体计算方法为：Time $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ Tsys \*R32\_TMRx\_CNT\_END；

(3)、清零 RB\_TMR\_ALL\_CLEAR，清零 RB\_TMR\_MODE\_IN 对应定时模式；

(4)、可选步骤，设置 R8\_TMRx\_INTER\_EN 寄存器，置位 RB\_TMR\_IE\_CYC\_END 可打开定时周期中断；

(5)、将 R8\_TMRx\_CTRL\_MOD 寄存器的 RB\_TMR\_COUNT\_EN 置位，启动定时器计数；

(6)、当计数到 R32\_TMRx\_COUNT 等于 R32\_TMRx\_CNT\_END 时，定时完成。此时 R8\_TMRx\_INT\_FLAG 的RB\_TMR\_IF\_CYC\_END 将置 1，可写 1 清零。

计数功能操作步骤如下：

(1)、将计数对应的I/O引脚方向设置为输入；

(2)、在 R32\_TMRx\_CNT\_END 中设定计数溢出终值；

(3)、配置 R8\_TMRx\_CTRL\_MOD，置位 RB\_TMR\_MODE\_IN 和 RB\_TMR\_CAP\_COUNT 对应计数模式，清零

RB\_TMR\_ALL\_CLEAR 位 ， 通 过 RB\_TMR\_CAP\_EDGE 选 择 采 样 边 沿 方 式 ， 将 R8\_TMRx\_CTRL\_MOD 的RB\_TMR\_COUNT\_EN 置 1，使能计数功能；

(4)、可选步骤，如果需要启用中断则设置相应的中断使能寄存器位；

(5)、R32\_TMRx\_COUNT 存放当前计数值，每次计数达到计数终值，RB\_TMR\_IE\_CYC\_END 都会置 1 并且R32\_TMRx\_COUNT清0，如果开启中断则会触发硬件中断。

# 8.3.2 PWM 功能

芯片的每个定时器均具有PWM功能和DMA数据加载功能。PWM可设置默认输出极性为高电平或低电平，同一数据重复输出次数可选为 1，4，8 或 16 次，该重复功能结合 DMA 可以用于模仿 DAC 的效果。PWM输出有效电平的最短时间单位为1个系统时钟，可动态修改PWM的占空比，模仿出特殊波形。PWM 操作步骤如下：

(1)、将 RB\_TMR\_ALL\_CLEAR 置位，清空和清零 R32\_TMRx\_FIFO 和中断标志等；

(2)、设置 PWM 总周期寄存器 R32\_TMRx\_CNT\_END，该值应该不小于 R32\_TMRx\_FIFO 寄存器中的值；

(3)、配置 R8\_TMRx\_CTRL\_MOD，清零 RB\_TMR\_ALL\_CLEAR，清零 RB\_TMR\_MODE\_IN 对应 PWM 模式，通过RB\_TMR\_OUT\_POLAR 选择输出极性，根据需要通过 RB\_TMR\_PWM\_REPEAT 选择同一数据重复次数；

(4)、设置数据寄存器R32\_TMRx\_FIFO，最小值为0，对应占空比 $0 %$ ，最大值同 R32\_TMR\_CNT\_END，对应占空比 $100 %$ ，占空比计算：R32\_TMRx\_FIFO/R32\_TMRx\_CNT\_END。可通过 DMA 加载连续动态数据，结合同一数据重复输出次数，可以模仿出特殊波形；

(5)、配置 R8\_TMRx\_CTRL\_MOD，置位 RB\_TMR\_COUNT\_EN 启动计数和 RB\_TMR\_OUT\_EN 允许 PWM 输出；

(6)、将 PWM 对应的 I/O 引脚设置为输出；

(7)、可选步骤，如果需要启用中断则设置相应的中断使能寄存器位；

(8)、PWM 一个周期完成后，如果开启中断则当 RB\_TMR\_IF\_DATA\_ACT 或 RB\_TMR\_IF\_CYC\_END 置位后会触发硬件中断；

(9)、更新R32\_TMRx\_FIFO中数据可以动态改变PWM的占空比，建议通过DMA加载。

例如：设置 RB\_TMR\_OUT\_POLAR 位为 0，R32\_TMRx\_FIFO 为 6，R32\_TMRx\_CNT\_END 为 18，则产生 PWM的基本时序图如下所示，其占空比为：R32\_TMRx\_FIFO/R32\_TMRx\_CNT\_END $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ 1/3。

图 8-1 PWM 输出时序图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/51d03fb5ef9ff64bb62dd415e7004c252d991ddd98702460753d1b62e0fd5881.jpg null)

如果 RB\_TMR\_PWM\_REPEAT 设置为 00 则表示上述过程重复 1 次，01 表示重复 4 次，10 表示重复 8次，11表示重复16次。重复之后再加载FIFO中的下一个数据继续。

# 8.3.3 捕捉功能

芯片的每个定时器都具备捕捉功能和DMA数据存储功能。捕捉模式可以选择任何边沿触发开始至任何边沿触发结束、上升沿触发开始至上升沿触发结束、下降沿触发开始至下降沿触发结束三种模式。以下为捕捉触发模式说明表：

表8-5 捕捉触发模式说明表

<table><tr><td>捕捉模式选择位</td><td>触发方式</td><td>图示</td></tr><tr><td>RB_TMR Catch EDGE</td><td></td><td></td></tr><tr><td>00</td><td>不捕捉</td><td>无</td></tr><tr><td>01</td><td>边沿触发边沿至边沿</td><td></td></tr><tr><td>10</td><td>下降沿至下降沿</td><td></td></tr><tr><td>11</td><td>上升沿至上升沿</td><td></td></tr></table>

边沿触发模式下有2种触发状态，可以捕捉高电平宽度或低电平宽度。数据寄存器R32\_TMRx\_FIFO的有效数据的最高位（位 25）为 1 表示捕捉到的是高电平，为 0 表示捕捉到的是低电平。如果连续多组数据的位25都是1（或0），说明该高（或低）电平的宽度超过超时值，需多组合并累计。

下降沿至下降沿、上升沿至上升沿触发模式下，可以捕捉一个输入变化周期。数据寄存器R32\_TMRx\_FIFO的有效数据的最高位（位25）为0表示正常采样到一个周期，为1则表示输入变化周期超过超时值R32\_TMRx\_CNT\_END，需加上后一组数据累计为单个输入变化周期。

具体说明如下图所示：

图8-2 以系统时钟计数捕捉周期

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/2b6b8e31d57d1b3587f1c7106cd6a7954368a2383514bdff98c61e53f103be33.jpg null)

如上图所示，每个时钟周期内采样一次：

当 RB\_TMR\_CATCH\_EDGE=01b 时，设置为边沿触发采样，采样到的时间宽度为 3、3、10；

当 RB\_TMR\_CATCH\_EDGE $\mathtt { \_ 1 0 b }$ 时，设置为下降沿至下降沿采样，采样到的时间宽度为 13；

当RB\_TMR\_CATCH\_EDGE=11b时，设置为上升沿至上升沿采样，采样到的时间宽度为6。

捕捉模式操作步骤：

(1)、将 RB\_TMR\_ALL\_CLEAR 置位，清空和清零 R32\_TMRx\_FIFO 和中断标志等；

(2)、将捕捉对应的 I/O 引脚方向设置为输入；

(3)、在R32\_TMRx\_CNT\_END中设定合理的捕捉超时时间，可用于在输入信号长时间无变化时产生超时中断，也可以在输入信号无变化超时后，产生超时数据（数据的位25为1，低25位可向后累计）；

(4)、配置 R8\_TMRx\_CTRL\_MOD，置位 RB\_TMR\_MODE\_IN 对应捕捉模式，通过 RB\_TMR\_CAP\_EDGE 选择捕捉的边沿方式，将 R8\_TMRx\_CTRL\_MOD 的 RB\_TMR\_COUNT\_EN 置 1，使能计数；

(5)、可选步骤，如果需要启用中断则设置相应的中断使能寄存器位；

(6)、如果需要采用DMA方式保存捕捉的数据，需要设置寄存器R32\_TMRx\_DMA\_BEG为存储捕捉数据缓冲区的首地址，设置寄存器 R32\_TMRx\_DMA\_END 为存储捕捉数据缓冲区的结束地址（不含），并设置R8\_TMRx\_CTRL\_DMA 的 RB\_TMR\_DMA\_ENABLE 为 1，使能 DMA 功能；

(7)、将 R8\_TMRx\_CTRL\_MOD 的 RB\_TMR\_ALL\_CLEAR 清零，启动捕捉功能；

(8)、每次捕捉到数据，RB\_TMR\_IF\_DATA\_ACT 都会置 1，如果开启中断则会触发硬件中断，捕捉到的数据默认存放在R32\_TMRx\_FIFO中，如果开启DMA，则捕捉到的数据会自动存放在DMA设置的数据缓冲区中。

# 8.3.4 DMA 功能

芯片的每个定时器均具有DMA功能，在使用DMA完成中断时需要注意相关寄存器的配置顺序。

使能DMA完成中断的步骤如下：

(1)、读取 R32\_TMR1\_DMA\_NOW，将 R32\_TMR1\_DMA\_END 赋值为任一不和 R32\_TMR1\_DMA\_NOW 相等的值（例：可以取值为 R32\_TMR1\_DMA\_NOW + 0x100）；

(2)、将 R8\_TMR1\_INT\_FLAG 的位 RB\_TMR\_IF\_DMA\_END 写 1 清零；

(3)、将 R8\_TMR1\_INTER\_EN 中的位 RB\_TMR\_IE\_DMA\_END 置 1。

非循环模式清除DMA完成中断的步骤如下：

(1)、读取 R32\_TMR1\_DMA\_NOW，将 R32\_TMR1\_DMA\_END 赋值为任一不和 R32\_TMR1\_DMA\_NOW 相等的值（例：可以取值为 R32\_TMR1\_DMA\_NOW + 0x100）；

(2)、将 R8\_TMR1\_INT\_FLAG 的位 RB\_TMR\_IF\_DMA\_END 写 1 清零。

循环模式清除DMA完成中断的步骤如下：

(1)、将 R8\_TMR1\_INT\_FLAG 的位 RB\_TMR\_IF\_DMA\_END 写 1 清零。

# 第 9 章 通用异步收发器 UART

# 9.1 UART 简介

CH585和CH584芯片提供了4组全双工的异步串口UART0/1/2/3。支持全双工和半双工串口通讯，其中UART0提供发送状态引脚用于切换RS485，并且支持MODEM调制解调器信号CTS、DSR、RI、DCD、DTR、RTS。

# 9.1.1 主要特性

$\bullet$ 兼容16C550异步串口并且有所增强

$\bullet$ 支持5、6、7或者8个数据位以及1或者2个停止位

$\bullet$ 支持奇、偶、无校验、空白0、标志1等校验方式

$\bullet$ 可编程通讯波特率，最高达9Mbps波特率

$\bullet$ 内置 8 个字节的 FIFO 先进先出缓冲器，支持 4 个 FIFO 触发级

 UART0 支持 MODEM 调制解调器信号 CTS、DSR、RI、DCD、DTR、RTS

UART0支持硬件流控制信号CTS和RTS自动握手和自动传输速率控制，兼容TL16C550C

$\bullet$ 支持串口帧错误检测、支持 Break 线路间隔检测

 支持全双工和半双工串口通讯，UART0 提供发送状态引脚用于切换 RS485

# 9.2 寄存器描述

表 9-1 UART0 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_UART_MCR</td><td>0x40003000</td><td>调制解调器 MODEM 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART_IER</td><td>0x40003001</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_UART_FCR</td><td>0x40003002</td><td>FIFO 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART_LCR</td><td>0x40003003</td><td>线路控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART_IIR</td><td>0x40003004</td><td>中断识别寄存器</td><td>0x01</td></tr><tr><td>R8_UART_LSR</td><td>0x40003005</td><td>线路状态寄存器</td><td>0x60</td></tr><tr><td>R8_UART_MSBR</td><td>0x40003006</td><td>调制解调器 MODEM 状态寄存器</td><td>0xX0</td></tr><tr><td>R8_UART_RBR</td><td>0x40003008</td><td>接收缓冲寄存器</td><td>0xXX</td></tr><tr><td>R8_UART_THR</td><td>0x40003008</td><td>发送保持寄存器</td><td>0xXX</td></tr><tr><td>R8_UART_RFC</td><td>0x4000300A</td><td>接收 FIFO 计数寄存器</td><td>0x00</td></tr><tr><td>R8_UART_TFC</td><td>0x4000300B</td><td>发送 FIFO 计数寄存器</td><td>0x00</td></tr><tr><td>R16_UART_DL</td><td>0x4000300C</td><td>波特率除数锁存器</td><td>0xXX</td></tr><tr><td>R8_UART_DIV</td><td>0x4000300E</td><td>预分频除数寄存器</td><td>0xXX</td></tr><tr><td>R8_UART_ADR</td><td>0x4000300F</td><td>从机地址寄存器</td><td>0xFF</td></tr></table>

表 9-2 UART1 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_UART1_MCR</td><td>0x40003400</td><td>调制解调器 MODEM 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART1_IER</td><td>0x40003401</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_UART1_FCR</td><td>0x40003402</td><td>FIFO 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART1_LCR</td><td>0x40003403</td><td>线路控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART1_IIR</td><td>0x40003404</td><td>中断识别寄存器</td><td>0x01</td></tr><tr><td>R8_UART1_LSR</td><td>0x40003405</td><td>线路状态寄存器</td><td>0x60</td></tr><tr><td>R8_UART1_RBR</td><td>0x40003408</td><td>接收缓冲寄存器</td><td>0xXX</td></tr><tr><td>R8_UART1_THR</td><td>0x40003408</td><td>发送保持寄存器</td><td>0xXX</td></tr><tr><td>R8_UART1_RFC</td><td>0x4000340A</td><td>接收FIFO计数寄存器</td><td>0x00</td></tr><tr><td>R8_UART1_TFC</td><td>0x4000340B</td><td>发送FIFO计数寄存器</td><td>0x00</td></tr><tr><td>R16_UART1_DL</td><td>0x4000340C</td><td>波特率除数锁存器</td><td>0xXX</td></tr><tr><td>R8_UART1_DIV</td><td>0x4000340E</td><td>预分频除数寄存器</td><td>0xXX</td></tr></table>

表 9-3 UART2 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_UART2_MCR</td><td>0x40003800</td><td>调制解调器 MODEM 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART2_IER</td><td>0x40003801</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_UART2_FCR</td><td>0x40003802</td><td>FIFO 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART2_LCR</td><td>0x40003803</td><td>线路控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART2_IIR</td><td>0x40003804</td><td>中断识别寄存器</td><td>0x01</td></tr><tr><td>R8_UART2_LSR</td><td>0x40003805</td><td>线路状态寄存器</td><td>0x60</td></tr><tr><td>R8_UART2_RBR</td><td>0x40003808</td><td>接收缓冲寄存器</td><td>0xXX</td></tr><tr><td>R8_UART2_THR</td><td>0x40003808</td><td>发送保持寄存器</td><td>0xXX</td></tr><tr><td>R8_UART2RFC</td><td>0x4000380A</td><td>接收 FIFO 计数寄存器</td><td>0x00</td></tr><tr><td>R8_UART2_TFC</td><td>0x4000380B</td><td>发送 FIFO 计数寄存器</td><td>0x00</td></tr><tr><td>R16_UART2_DL</td><td>0x4000380C</td><td>波特率除数锁存器</td><td>0xXX</td></tr><tr><td>R8_UART2_DIV</td><td>0x4000380E</td><td>预分频除数寄存器</td><td>0xXX</td></tr></table>

表 9-4 UART3 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_UART3_MCR</td><td>0x40003C00</td><td>调制解调器 MODEM 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART3_IER</td><td>0x40003C01</td><td>中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_UART3_FCR</td><td>0x40003C02</td><td>FIFO 控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART3_LCR</td><td>0x40003C03</td><td>线路控制寄存器</td><td>0x00</td></tr><tr><td>R8_UART3_IIR</td><td>0x40003C04</td><td>中断识别寄存器</td><td>0x01</td></tr><tr><td>R8_UART3_LSR</td><td>0x40003C05</td><td>线路状态寄存器</td><td>0x60</td></tr><tr><td>R8_UART3_RBR</td><td>0x40003C08</td><td>接收缓冲寄存器</td><td>0xXX</td></tr><tr><td>R8_UART3_THR</td><td>0x40003C08</td><td>发送保持寄存器</td><td>0xXX</td></tr><tr><td>R8_UART3RFC</td><td>0x40003C0A</td><td>接收 FIFO 计数寄存器</td><td>0x00</td></tr><tr><td>R8_UART3_TFC</td><td>0x40003C0B</td><td>发送 FIFO 计数寄存器</td><td>0x00</td></tr><tr><td>R16_UART3_DL</td><td>0x40003C0C</td><td>波特率除数锁存器</td><td>0xXX</td></tr><tr><td>R8_UART3_DIV</td><td>0x40003C0E</td><td>预分频除数寄存器</td><td>0xXX</td></tr></table>

调制解调器 MODEM 控制寄存器(R8\_UARTx\_MCR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_MCR_HALF</td><td>RW</td><td>半双工收发模式控制(仅 UART0 支持):1:进入半双工收发模式,发送优先,不发送时为接收;0:禁止半双工模式。</td><td>0</td></tr><tr><td>6</td><td>RB_MCR_TNOW</td><td>RW</td><td>DTR 引脚输出正在发送状态使能(仅 UART0 支持):1:将正在发送指示状态输出到 DTR 引脚,可以用于控制 RS485 收发切换;0:DTR 引脚为正常功能。</td><td>0</td></tr><tr><td>5</td><td>RB_MCR_AU_FLOW_EN</td><td>RW</td><td>CTS 和 RTS 硬件自动流控使能(仅 UART0 支持):</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:启用CTS和RTS硬件自动流控;0:禁用CTS和RTS硬件自动流控。流控模式下,如果此位为1,那么仅在检测到CTS引脚输入有效(低电平有效)时串口才继续发送下一个数据,否则暂停串口发送,当此位为1时的CTS输入状态变化不会产生MODEM状态中断。如果此位为1并且RTS为1,那么当接收FIFO空时,串口会自动有效RTS引脚(低电平有效),直到接收的字节数达到FIFO的触发点时,串口才自动无效RTS引脚,并能够在接收FIFO空时再次有效RTS引脚。使用硬件自动流控,可将己方的CTS引脚接到对方的RTS引脚,并将己方的RTS引脚送到对方的CTS引脚。</td><td></td></tr><tr><td>4</td><td>RB_MCR_LOOP</td><td>RW</td><td>内部回路的测试模式使能(仅UARTO支持):1:使能内部回路的测试模式;0:禁止内部回路的测试模式。在内部回路的测试模式下,串口所有对外输出引脚均为无效状态,TXD内部返回到RXD,RTS内部返回到CTS,DTR内部返回到DSR,OUT1内部返回到RI,OUT2内部返回到DCD。</td><td>0</td></tr><tr><td>3</td><td>RB_MCR_OUT2RB_MCR_INT_OE</td><td>RW</td><td>串口的中断请求输出控制位:1:允许发出请求;0:禁止。</td><td>0</td></tr><tr><td>2</td><td>RB_MCR_OUT1</td><td>RW</td><td>用户自定义MODEM控制位(仅UARTO支持),没有连接实际输出引脚:1:置高;0:置低。</td><td>0</td></tr><tr><td>1</td><td>RB_MCR_RTS</td><td>RW</td><td>RTS信号输出电平控制(仅UARTO支持):1:RTS信号输出有效(低电平);0:RTS信号输出高电平(默认)。</td><td>0</td></tr><tr><td>0</td><td>RB_MCR_DTR</td><td>RW</td><td>DTR信号输出电平控制(仅UARTO支持):1:DTR信号输出有效(低电平);0:DTR信号输出高电平(默认)。</td><td>0</td></tr></table>

中断使能寄存器(R8\_UARTx\_IER)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_IER_RESET</td><td>WZ</td><td>串口软件复位控制位,自动清零:1:软件复位该串口;0:正常工作。</td><td>0</td></tr><tr><td>6</td><td>RB_IER_TXD_EN</td><td>RW</td><td>串口 TXD 引脚输出使能位:1:使能引脚输出;0:禁止引脚输出。</td><td>0</td></tr><tr><td>5</td><td>RB_IER_RTS_EN</td><td>RW</td><td>RTS 引脚输出使能位(仅 UART0 支持):1:使能引脚输出;0:禁止引脚输出。</td><td>0</td></tr><tr><td>4</td><td>RB_IER_DTR_EN</td><td>RW</td><td>DTR 引脚输出使能位(仅 UART0 支持):1:使能引脚输出;0:禁止引脚输出。</td><td>0</td></tr><tr><td>3</td><td>RB_IER_MODEM_CHG</td><td>RW</td><td>调制解调器输入状态变化中断使能位(仅UART0 支持):1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>2</td><td>RB_IER_LINE_STAT</td><td>RW</td><td>接收线路状态中断使能位:1:使能中断; 0:禁止中断。</td><td>0</td></tr><tr><td>1</td><td>RB_IER_THR_empty</td><td>RW</td><td>发送保持寄存器空中断使能位:1:使能中断; 0:禁止中断。</td><td>0</td></tr><tr><td>0</td><td>RB_IER_RECV_RDY</td><td>RW</td><td>接收数据中断使能位:1:使能中断; 0:禁止中断。</td><td>0</td></tr></table>

FIFO 控制寄存器(R8\_UARTx\_FCR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB_FCR_FIFO_TRIG</td><td>RW</td><td>接收FIFO的中断和硬件流控制的触发点选择:00:1字节;01:2字节;10:4字节;11:7字节。用来设置接收FIFO的中断和硬件流控制的触发点,例如:10对应4个字节,即接收满4个字节产生接收数据可用的中断,并在使能硬件流控制时自动无效RTS引脚。</td><td>00b</td></tr><tr><td>[5:3]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>000b</td></tr><tr><td>2</td><td>RB_FCR_TX_FIFO_CLR</td><td>WZ</td><td>发送FIFO数据清空使能位,自动清零:1:清空发送FIFO的数据(不含TSR);0:不清空发送FIFO的数据。</td><td>0</td></tr><tr><td>1</td><td>RB_FCR_RX_FIFO_CLR</td><td>WZ</td><td>接收FIFO数据清空使能位,自动清零:1:清空接收FIFO的数据(不含RSR);0:不清空接收FIFO的数据。</td><td>0</td></tr><tr><td>0</td><td>RB_FCR_FIFO_EN</td><td>RW</td><td>FIFO使能位:1:启用8字节FIFO;0:禁用FIFO。禁用FIFO后为16C450兼容模式,相当于FIFO只有一个字节(RECV_TG1=0、RECV_TGO=0、FIFO_EN=1),建议启用。</td><td>0</td></tr></table>

线路控制寄存器(R8\_UARTx\_LCR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_LCR_DLABRB_LCR_GP_BIT</td><td>RW</td><td>串口通用位,用户自定义。</td><td>0</td></tr><tr><td>6</td><td>RB_LCR_BREAK_EN</td><td>RW</td><td>强制产生 BREAK 线路间隔使能位:1: 强制产生; 0: 不产生。</td><td>0</td></tr><tr><td>[5:4]</td><td>RB_LCR_PAR_MOD</td><td>RW</td><td>奇偶校验位格式选择:00: 奇校验; 01: 偶校验;10: 标志位(MARK, 置 1);11: 空白位(SPACE, 清 0)。仅当 RB_LCR_PAR_EN 位为 1 时有效。</td><td>00b</td></tr><tr><td>3</td><td>RB_LCR_PAR_EN</td><td>RW</td><td>奇偶校验位使能位:1: 允许发送时产生和接收时校验奇偶校验位;0: 无奇偶校验位。</td><td>0</td></tr><tr><td>2</td><td>RB_LCR_STOP_BIT</td><td>RW</td><td>停止位格式设置位:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1: 两个停止位; 0: 一个停止位。</td><td></td></tr><tr><td>[1:0]</td><td>RB_LCR_WORD_SZ</td><td>RW</td><td>串口数据长度选择:00: 5个数据位; 01: 6个数据位;10: 7个数据位; 11: 8个数据位。</td><td>00b</td></tr></table>

中断识别寄存器(R8\_UARTx\_IIR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB_IIR_FIFO_ID</td><td>R0</td><td>串口FIFO启用状态位:11: FIFO已启用; 00: FIFO未启用。</td><td>00b</td></tr><tr><td>[5:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>00b</td></tr><tr><td>[3:1]</td><td>RB_IIR_INT_MASK</td><td>R0</td><td>中断标志: 如果RB_IIR_NO_INT位为0,则表示有中断产生,需要读取后判断中断源。具体请参看表9-5。</td><td>000b</td></tr><tr><td>0</td><td>RB_IIR_NO_INT</td><td>R0</td><td>串口无中断标志位:1: 无中断; 0: 有中断。</td><td>1</td></tr></table>

中断识别寄存器 R8\_UARTx\_IIR 的 RB\_IIR\_NO\_INT 位以及 RB\_IIR\_INT\_MASK 的每一个位所表示的含义如下表所示：

表 9-5 IIR 寄存器中 RB\_IIR\_INT\_MASK 含义

<table><tr><td colspan="4">IIR寄存器位</td><td rowspan="2">优先级</td><td rowspan="2">中断类型</td><td rowspan="2">中断源</td><td rowspan="2">清中断方法</td></tr><tr><td>IID3</td><td>IID2</td><td>IID1</td><td>NOINT</td></tr><tr><td>0</td><td>0</td><td>0</td><td>1</td><td>无</td><td>没有中断产生</td><td>没有中断。</td><td>-</td></tr><tr><td>1</td><td>1</td><td>1</td><td>0</td><td>0</td><td>总线地址匹配</td><td>接收到1个数据是串口总线地址,且该地址与预置从机值相匹配或是广播地址。(仅UART0支持)</td><td>读IIR或禁用多机模式</td></tr><tr><td>0</td><td>1</td><td>1</td><td>0</td><td>1</td><td>接收线路状态</td><td>OVER_ERR、PAR_ERR、FRAM_ERR、BREAK_ERR</td><td>读LSR</td></tr><tr><td>0</td><td>1</td><td>0</td><td>0</td><td>2</td><td>接收数据可用</td><td>接收到的字节数达到FIFO0的触发点。</td><td>读RBR</td></tr><tr><td>1</td><td>1</td><td>0</td><td>0</td><td>2</td><td>接收数据超时</td><td>超过4个数据时间未收到下一数据。</td><td>读RBR</td></tr><tr><td>0</td><td>0</td><td>1</td><td>0</td><td>3</td><td>THR寄存器空</td><td>发送保持寄存器空,或者,RB_IER_THR_empty位从0变1触发。</td><td>读IIR或写THR</td></tr><tr><td>0</td><td>0</td><td>0</td><td>0</td><td>4</td><td>MODEM输入变化</td><td>△CTS、△DSR、△RI、△DCD置1触发。</td><td>读MSR</td></tr></table>

线路状态寄存器(R8\_UARTx\_LSR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_LSR_ERR_RX_FIFO</td><td>R0</td><td>接收FIFO错误标志位:1:接收FIFO中存在至少一个PAR_ERR、FRAM_ERR或BREAK_ERR错误;0:接收FIFO中不存在错误。</td><td>0</td></tr><tr><td>6</td><td>RB_LSR_TX_ALL_IMP</td><td>R0</td><td>发送保持寄存器THR和发送移位寄存器TSR全空标志位:1:两者全空;0:两者非全空。</td><td>1</td></tr><tr><td>5</td><td>RB_LSR_TX_FIFO_IMP</td><td>R0</td><td>发送FIFO空标志位:1:发送FIFO空;0:发送FIFO非空。</td><td>1</td></tr><tr><td>4</td><td>RB_LSR_BREAK_IMP</td><td>RZ</td><td>BREAK线路间隔检测标志位:1:检测到BREAK;0:未检测到BREAK。</td><td>0</td></tr><tr><td>3</td><td>RB_LSR_FRAME_ERR</td><td>RZ</td><td>数据帧错误标志位:1:表示正在从接收FIFO中读取的数据存在帧错误,缺少有效的停止位;0:当前读取的数据帧没有错误。</td><td>0</td></tr><tr><td>2</td><td>RB_LSR_PAR_ERR</td><td>RZ</td><td>接收数据奇偶校验错误标志位:1:表示正在从接收FIFO中读取的数据存在奇偶校验错;0:当前读取的数据奇偶校验正确。</td><td>0</td></tr><tr><td>1</td><td>RB_LSR_OVER_ERR</td><td>RZ</td><td>接收FIFO缓冲区溢出标志位:1:已溢出;0:未溢出。</td><td>0</td></tr><tr><td>0</td><td>RB_LSR_DATA_RDY</td><td>RO</td><td>接收FIFO中有接收到的数据标志位:1:FIFO中有数据;0:无数据。读取FIFO中所有数据后,该位自动清0。</td><td>0</td></tr></table>

调制解调器 MODEM 状态寄存器(R8\_UART0\_MSR)（仅 UART0 支持）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_MSB_DCD</td><td>R0</td><td>DCD引脚状态位:1: DCD有效(低电平);0: DCD无效(高电平)。</td><td>0</td></tr><tr><td>6</td><td>RB_MSB_RI</td><td>R0</td><td>RI引脚状态位:1: RI有效(低电平);0: RI无效(高电平)。</td><td>0</td></tr><tr><td>5</td><td>RB_MSB_DSR</td><td>R0</td><td>DSR引脚状态位:1: DSR引脚有效(低电平);0: DSR引脚无效(高电平)。</td><td>X</td></tr><tr><td>4</td><td>RB_MSB_CTS</td><td>R0</td><td>CTS引脚状态位:1: CTS引脚有效(低电平);0: CTS引脚无效(高电平)。</td><td>X</td></tr><tr><td>3</td><td>RB_MSB_DCD_CHG</td><td>RZ</td><td>DCD引脚输入状态变化标志位:1: 发生过变化; 0: 无变化。</td><td>0</td></tr><tr><td>2</td><td>RB_MSB_RI_CHG</td><td>RZ</td><td>RI引脚输入状态变化标志位:1: 发生过变化; 0: 无变化。</td><td>0</td></tr><tr><td>1</td><td>RB_MSB_DSR_CHG</td><td>RZ</td><td>DSR引脚输入状态变化标志位:1: 发生过变化; 0: 无变化。</td><td>0</td></tr><tr><td>0</td><td>RB_MSB_CTS_CHG</td><td>RZ</td><td>CTS引脚输入状态变化标志位:1: 发生过变化; 0: 无变化。</td><td>0</td></tr></table>

接收缓冲寄存器(R8\_UARTx\_RBR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UARTx_RBR</td><td>RO</td><td>数据接收缓冲寄存器。如果LSR的DATA_RDY位为1,则可以从该寄存器读取接收到的数据;如果FIFO_EN为1,则从串口移位寄存器RSR接收到的数据首先被存放于接收FIFO0中,然后通过该寄存器读出。</td><td>XXh</td></tr></table>

发送保持寄存器(R8\_UARTx\_THR)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UARTx_THR</td><td>WO</td><td>发送保持寄存器。包括发送FIFO,用于写入准备发送的数据;如果FIFO_EN为1,则写入的数据首先被存放于发送FIFO中,然后通过发送</td><td>XXh</td></tr><tr><td></td><td></td><td></td><td>移位寄存器 TSR 逐个输出。</td><td></td></tr></table>

接收 FIFO 计数寄存器(R8\_UARTx\_RFC)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UARTxRFC</td><td>R0</td><td>当前接收FIFO中数据计数。</td><td>00h</td></tr></table>

发送 FIFO 计数寄存器(R8\_UARTx\_TFC)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UARTx_TFC</td><td>R0</td><td>当前发送 FIFO 中数据计数。</td><td>00h</td></tr></table>

波特率除数锁存器(R16\_UARTx\_DL)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>R16_UARTx_DL</td><td>RW</td><td>16位除数用于计算波特率。公式：除数=串口内部基准时钟Fuart/16/所需通讯波特率。例：如果串口内部基准时钟Fuart为1.8432MHz，所需波特率为9600bps，则除数=1843200/16/9600=12。</td><td>XXXXh</td></tr></table>

预分频除数寄存器(R8\_UARTx\_DIV)（x=0/1/2/3）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UARTx_DIV</td><td>RW</td><td>用于计算串口的内部基准时钟,低7位有效。公式:除数 = Fsys * 2 / 串口内部基准时钟,最大值127。</td><td>XXh</td></tr></table>

从机地址寄存器(R8\_UART0\_ADR)（仅 UART0 支持）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UART0_ADR</td><td>RW</td><td>串口0多机通讯时的从机地址:FFh:不使用;其他:从机地址。</td><td>OFFh</td></tr></table>

R8\_UART0\_ADR 预置本机作为从机时的地址，用于在多机通讯时自动比较接收到的地址，并在地址匹配或者在接收到广播地址 0FFH 时产生中断，同时允许接收后续数据包。在地址没有匹配之前不接收任何数据，开始发送数据后或者重写 R8\_UART0\_ADR 寄存器后停止接收任何数据，直到下次地址再次匹配或者接收到广播地址时再允许接收。

R8\_UART0\_ADR 为 0FFH 时或者 RB\_LCR\_PAR\_EN=0 时，禁用总线地址自动比较功能。

R8\_UART0\_ADR 不为 0FFH 并且 RB\_LCR\_PAR\_EN=1 时，启用总线地址自动比较功能，同时应该配置下述参数：RB\_LCR\_WORD\_SZ 为 11b 以选择 8 个数据位方式，对于地址字节为 MARK 的情况(即数据字节的位 9 为 0），应设置 RB\_LCR\_PAR\_MOD 为 10b，对于地址字节为 SPACE 的情况（即数据字节的位 9为 1），应设置 RB\_LCR\_PAR\_MOD 为 11b。

# 9.3 功能描述及配置

UART0/1/2/3输出引脚都是3.3V LVCMOS电平。异步串口方式下引脚包括：数据传输引脚和MODEM联络信号引脚（仅UART0支持）。数据传输引脚包括：TXD引脚和RXD引脚，默认都是高电平；MODEM联络信号引脚包括：CTS引脚、DSR引脚、RI引脚、DCD引脚、DTR引脚、RTS引脚，默认都是高电平。所有这些MODEM联络信号都可以作为通用I/O引脚，由应用程序控制并定义其用途。

4 组 UART 各自拥有独立的收发缓冲区及 8 字节 FIFO，支持单工、半双工或者全双工异步串行通

讯。串行数据包括1个低电平起始位，5、6、7或8个数据位，0个或者1个附加校验位或者标志位，1 个或者 2 个高电平停止位，支持奇校验/偶校验/标志校验/空白校验。串口发送信号的波特率误差小于 $0 . 5 %$ ，串口接收信号的允许波特率误差不大于 $2 %$ 。

# 9.3.1 波特率计算

1\)计算串口内部基准时钟 Fuart，设置 R8\_UARTx\_DIV 寄存器，最大值 127，通常写入 1。

2\)计算波特率，设置 R16\_UARTx\_DL 寄存器。

波特率公式 =Fsys \* 2 / R8\_UARTx\_DIV / 16 / R16\_UARTx\_DL。

# 9.3.2 串口发送

串口发送的“THR 寄存器空”中断 UART\_II\_THR\_EMPTY 是指当前发送 FIFO 空。当读取 IIR 寄存器后，该中断被清除，或者当向THR写入下一个数据后，该中断也能被清除。如果仅仅是向THR写入一个字节，那么由于该字节很快被转移到发送移位寄存器TSR中开始发送，所以很快会再次产生发送THR寄存器空中断的请求，此时可以写入下一个准备发送的数据。当TSR寄存器中的数据被全部移出后，串口发送才真正完成，此时LSR寄存器的RB\_LSR\_TX\_ALL\_EMP位变为1有效。

在中断触发方式下，当收到串口发送保持寄存器 THR 空的中断后，如果已使能 FIFO，那么可以向THR寄存器及FIFO一次写入最多8字节，然后控制器会按顺序自动发送；如果禁止FIFO，那么一次只能写入一个字节；如果没有数据需要发送，那么可以直接退出（之前读取IIR时已经自动清除中断）。

在查询方式下，可以根据LSR寄存器的RB\_LSR\_TX\_FIFO\_EMP位判断发送FIFO是否为空，当此位为1则可以向THR寄存器及FIFO写入数据，如果使能FIFO，那么一次可以写入最多8个字节。

也可读取R8\_UARTx\_TFC寄存器判断当前FIFO中待发送的剩余数据个数，如果不等于8，则可继续向FIFO中写入待发送数据，这种方式可以节约填充时间。

# 9.3.3 串口接收

串口接收数据可用中断 UART\_II\_RECV\_RDY 是指接收 FIFO 中的已有数据字节数已经到或超过由FCR 寄存器的 RB\_FCR\_FIFO\_TRIG 设置选择的 FIFO 触发点。当从 RBR 读取数据使 FIFO 字数低于 FIFO触发点时，该中断被清除。

串口接收数据超时中断 UART\_II\_RECV\_TOUT 是指接收 FIFO 中至少有一个字节的数据，并且从上一次串口接收到数据和从上一次被系统取走数据开始，已经等待了相当于接收 4 个数据的时间。当再次接收到一个新的数据后，该中断被清除，或者当单片读取一次RBR寄存器后，该中断也能被清除。当接收 FIFO 全空时，LSR 寄存器的 RB\_LSR\_DATA\_RDY 位为 0，当接收 FIFO 中有数据时，RB\_LSR\_DATA\_RDY位为1有效。

在中断触发方式下，当收到串口接收数据超时的中断后，可以读取 R8\_UARTx\_RFC 寄存器查询当前 FIFO 中剩余数据计数，直接读取全部数据，或者不断查询 LSR 寄存器的 RB\_LSR\_DATA\_RDY，如果此位有效则读数据，直到此位无效。当收到串口接收数据可用的中断后，可以先从RBR寄存器一次性读取 RB\_FCR\_FIFO\_TRIG 设定字节个数的数据，或者也可以根据 RB\_LSR\_DATA\_RDY 位和 R8\_UARTx\_RFC寄存器读取当前FIFO中所有数据。

在查询方式下，可以根据 LSR 寄存器的 RB\_LSR\_DATA\_RDY 位判断接收 FIFO 是否为空，或读取R8\_UARTx\_RFC寄存器获取当前FIFO中数据计数，来获取串口接收的所有数据。

# 9.3.4 硬件流控制

硬件流控制包括自动 CTS（RB\_MCR\_AU\_FLOW\_EN 置 1）和自动 RTS（RB\_MCR\_AU\_FLOW\_EN 和RB\_MCR\_RTS 都置 1）。

如果使能自动CTS，那么CTS引脚在串口发送数据之前必须有效。串口发送器在发送下一个数据之前会检测CTS引脚，当CTS引脚状态有效时，发送器发送下一个数据。为了使发送器停止发送后面的数，CTS引脚必须在当前发送的最后一个停止位的中间时刻之前被无效。自动CTS功能减少了向系统申请的中断。当使能硬件流控制后，由于控制器会根据CTS引脚状态自动控制发送器，所以CTS引脚电平的改变不会触发 MODEM 中断。如果使能自动 RTS，那么仅当 FIFO 中有足够空间接收数据时才使RTS引脚输出有效，而在接收FIFO满时使RTS引脚输出无效。如果接收FIFO中的数据被全部取走

或清空，那么RTS引脚输出有效。当到达接收FIFO的触发点时（接收FIFO中已有字节数不少于FCR寄存器的RB\_FCR\_FIFO\_TRIG设定的字节数），RTS引脚输出无效，并且允许对方发送器在RTS引脚无效后再发送一个另外的数据。一旦接收 FIFO 被取空数据，RTS 引脚就会自动重新有效，从而使对方的发送器恢复发送。如果自动 CTS 和自动 RTS 都被使能（MCR 寄存器的 RB\_MCR\_AU\_FLOW\_EN 和RB\_MCR\_RTS都为1），那么当己方的RTS引脚连接对方的CTS引脚时，除非己方的接收FIFO中有足够的空间，否则对方不会发送数据。因此，通过这种硬件流控制，可以避免串口接收时的 FIFO 溢出和超时错误。

# 第 10 章 串行外设接口 SPI

# 10.1 SPI 简介

SPI是一种全双工串行接口，总线上连接有一个主机和若干从机，同一时刻，仅有一对主从在通讯。通常 SPI 接口由 4 个引脚组成：SPI 片选引脚 SCS、SPI 时钟引脚 SCK、SPI 串行数据引脚 MISO（主机输入/从机输出引脚）和SPI串行数据引脚MOSI（主机输出/从机输入引脚）。

# 10.1.1 主要特性

CH585 芯片提供 2 个 SPI 接口（SPI0 和 SPI1），CH584 芯片仅提供了 SPI0，特性如下：

 SPI0 支持主机模式（Master）和从机模式（Slave），SPI1 只支持主机模式（Master）

$\bullet$ 兼容串行外设接口(SPI)规范

$\bullet$ 支持模式0和模式3数据传输方式

 8 位数据传输方式，数据位序可选：字节低位在前或者高位在前

$\bullet$ 时钟频率最高可达系统主频Fsys的一半

 8 字节 FIFO

SPI0从机模式支持首字节为命令模式或数据流模式

SPI0支持DMA，数据传输效率更高

# 10.2 寄存器描述

表 10-1 SPI0 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_SPI_CTRL_MOD</td><td>0x40004000</td><td>SPI0模式控制寄存器</td><td>0x02</td></tr><tr><td>R8_SPI_CTRL_CFG</td><td>0x40004001</td><td>SPI0配置寄存器</td><td>0x00</td></tr><tr><td>R8_SPI_INTER_EN</td><td>0x40004002</td><td>SPI0中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_SPI_CLOCK_DIV</td><td rowspan="2">0x40004003</td><td>SPI0主机模式时钟分频寄存器</td><td rowspan="2">0x10</td></tr><tr><td>R8_SPI_SLAVE_PRE</td><td>SPI0从机模式预置数据寄存器</td></tr><tr><td>R8_SPI buffers</td><td>0x40004004</td><td>SPI0数据缓冲区</td><td>0xXX</td></tr><tr><td>R8_SPIRUN_FLAG</td><td>0x40004005</td><td>SPI0工作状态寄存器</td><td>0x00</td></tr><tr><td>R8_SPI_INT_FLAG</td><td>0x40004006</td><td>SPI0中断标志寄存器</td><td>0x40</td></tr><tr><td>R8_SPI_FIFO_COUNT</td><td>0x40004007</td><td>SPI0收发FIFO计数寄存器</td><td>0x00</td></tr><tr><td>R16_SPITOTAL_CNT</td><td>0x4000400C</td><td>SPI0收发数据总长度寄存器</td><td>0x0000</td></tr><tr><td>R8_SPI_FIFO</td><td>0x40004010</td><td>SPI0数据FIFO寄存器</td><td>0xXX</td></tr><tr><td>R8_SPI_FIFO_COUNT1</td><td>0x40004013</td><td>SPI0收发FIFO计数寄存器1</td><td>0x00</td></tr><tr><td>R32_SPI_DMA NOW</td><td>0x40004014</td><td>SPI0DMA缓冲区当前地址</td><td>0x000XXXXX</td></tr><tr><td>R32_SPI_DMA_BEG</td><td>0x40004018</td><td>SPI0DMA缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_SPI_DMA_END</td><td>0x4000401C</td><td>SPI0DMA缓冲区结束地址</td><td>0x000XXXXX</td></tr></table>

表 10-2 SPI1 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_SPI_CTRL_MOD</td><td>0x40004400</td><td>SPI1模式控制寄存器</td><td>0x02</td></tr><tr><td>R8_SPI_CTRL_CFG</td><td>0x40004401</td><td>SPI1配置寄存器</td><td>0x00</td></tr><tr><td>R8_SPI_INTER_EN</td><td>0x40004402</td><td>SPI1中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_SPI_CLOCK_DIV</td><td>0x40004403</td><td>SPI1主机模式时钟分频寄存器</td><td>0x10</td></tr><tr><td>R8_SPI buffers</td><td>0x40004404</td><td>SPI1数据缓冲区</td><td>0xXX</td></tr><tr><td>R8_SPIRUN_FLAG</td><td>0x40004405</td><td>SPI1工作状态寄存器</td><td>0x00</td></tr><tr><td>R8_SPI_INT_FLAG</td><td>0x40004406</td><td>SPI1中断标志寄存器</td><td>0x40</td></tr><tr><td>R8_SPI1_FIFO_COUNT</td><td>0x40004407</td><td>SPI1收发FIFO计数寄存器</td><td>0x00</td></tr><tr><td>R16_SPI1_TOTAL_CNT</td><td>0x4000440C</td><td>SPI1收发数据总长度寄存器</td><td>0x00</td></tr><tr><td>R8_SPI1_FIFO</td><td>0x40004410</td><td>SPI1数据FIFO寄存器</td><td>0xXX</td></tr><tr><td>R8_SPI1_FIFO_COUNT1</td><td>0x40004413</td><td>SPI1收发FIFO计数寄存器</td><td>0x00</td></tr></table>

SPI 模式控制寄存器(R8\_SPIx\_CTRL\_MOD) $\scriptstyle ( x = 0 / 1$ )

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_SPI_MISO_OE</td><td>RW</td><td>MISO引脚输出使能位(可在2线模式数据线切换方向使用):1:MISO输出使能;0:MISO输出禁止。</td><td>0</td></tr><tr><td>6</td><td>RB_SPI_MOSI_OE</td><td>RW</td><td>MOSI引脚输出使能位:1:MOSI输出使能;0:MOSI输出禁止。</td><td>0</td></tr><tr><td>5</td><td>RB_SPI_SCK_OE</td><td>RW</td><td>SCK引脚输出使能位:1:SCK输出使能;0:SCK输出禁止。</td><td>0</td></tr><tr><td>4</td><td>RB_SPI_FIFO_DIR</td><td>RW</td><td>FIFO方向设置位:1:输入模式(指示接收数据);0:输出模式(指示发送数据)。</td><td>0</td></tr><tr><td>3</td><td>RB_SPI_SLV_CMD_MOD</td><td>RW</td><td>SPI0从机模式下首字节方式选择(仅SPI0支持):1:首字节命令模式;0:数据流模式。在首字节命令模式下,当接收到SPI片选有效后的首字节数据后,将视为命令码,且RB_SPI_IF_RST_BYTE将置1。</td><td>0</td></tr><tr><td>3</td><td>RB_SPI_MST_SCK_MOD</td><td>RW</td><td>主机模式时钟空闲方式选择:1:模式3(空闲时SCK为高电平);0:模式0(空闲时SCK为低电平)。</td><td>0</td></tr><tr><td>2</td><td>RB_SPI_2WIRE_MOD</td><td>RW</td><td>从机模式2线或3线SPI模式选择(仅SPI0支持,SPI1无此控制位):1:2线模式/半双工(SCK/MISO);0:3线模式/全双工(SCK/MOSI/MISO)。</td><td>0</td></tr><tr><td>1</td><td>RB_SPI_ALL_CLEAR</td><td>RW</td><td>SPI的FIFO/计数器/中断标志清零:1:强制清空和清零;0:不清。</td><td>1</td></tr><tr><td>0</td><td>RB_SPI_MODE_SLAVE</td><td>RW</td><td>SPI0主从模式选择(仅SPI0支持):1:从机模式;0:主机模式。</td><td>0</td></tr></table>

SPI 配置寄存器(R8\_SPIx\_CTRL\_CFG) $\scriptstyle ( x = 0 / 1$ )

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>6</td><td>RB_SPI_MST_DLY_EN</td><td>RW</td><td>主机模式下输入延迟使能:1:使能,用于SPI时钟接近Fsys一半等高速应用;0:禁止,常规应用。</td><td>0</td></tr><tr><td>5</td><td>RB_SPI_BIT_ORDER</td><td>RW</td><td>SPI数据位序选择:
1:低位在前;
0:高位在前。</td><td>0</td></tr><tr><td>4</td><td>RB_SPI_AUTO_IF</td><td>RW</td><td>使能访问BUFFER/FIFO时自动清除标志位RB_SPI_IF_BYTE_END的功能:
1:使能;
0:禁止。</td><td>0</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_SPI_DMAindsight</td><td>RW</td><td>DMA地址循环功能使能位(仅SPI0支持):
1:使能地址循环;
0:禁止地址循环。
如果使能DMA地址循环,当DMA地址增加到设置的末尾地址时,自动循环指向设置的首地址。</td><td>0</td></tr><tr><td>1</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_SPI_DMA_ENABLE</td><td>RW</td><td>DMA功能使能位(仅SPI0支持):
1:使能DMA;
0:禁止DMA。</td><td>0</td></tr></table>

SPI 中断使能寄存器(R8\_SPIx\_INTER\_EN) (x=0/1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_SPI_IE_FST_BYTE</td><td>RW</td><td>从机模式的首字节命令模式下,首字节接收中断使能位(仅SPI0支持):1:使能接收到第一个字节中断;0:禁止接收到第一个字节中断。</td><td>0</td></tr><tr><td>[6:5]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_SPI_IE_FIFO_0V</td><td>RW</td><td>从机模式下,FIFO0溢出(接收时FIFO0满或发送时FIFO0空)中断使能位(仅SPI0支持):1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>3</td><td>RB_SPI_IE_DMA_END</td><td>RW</td><td>DMA结束中断使能位(仅SPI0支持):1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>2</td><td>RB_SPI_IE_FIFO_HF</td><td>RW</td><td>FIFO0使用过半中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>1</td><td>RB_SPI_IE_BYTE_END</td><td>RW</td><td>SPI单字节传输完成中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>0</td><td>RB_SPI_IE_CNT_END</td><td>RW</td><td>SPI全部字节传输完成中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr></table>

SPI 主机模式时钟分频寄存器(R8\_SPIx\_CLOCK\_DIV) (x=0/1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_SPI_CLOCK_DIV</td><td>RW</td><td>主机模式分频系数，最小值为2，最大值为254。</td><td>10h</td></tr></table>

<table><tr><td></td><td></td><td>Fsck = 系统主频 Fsys/分频系数。</td><td></td></tr></table>

SPI 从机模式预置数据寄存器(R8\_SPI0\_SLAVE\_PRE)（仅 SPI0 支持）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_SPI0_SLAVE_PRE</td><td>RW</td><td>从机模式下，预置的首个返回数据。用于接收首字节数据后的返回数据。</td><td>10h</td></tr></table>

SPI 数据缓冲区(R8\_SPIx\_BUFFER) ( $\scriptstyle \mathbf { x } = 0 / 1$ )

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_SPI_x_buffer</td><td>RW</td><td>SPI数据发送和接收缓冲区。</td><td>XXh</td></tr></table>

SPI 工作状态寄存器(R8\_SPIx\_RUN\_FLAG) $\scriptstyle ( x = 0 / 1$ )

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_SPI_SLV_SELECT</td><td>R0</td><td>从机模式被片选状态位(仅SPI0支持):1:正被选中;0:没有被片选。</td><td>0</td></tr><tr><td>6</td><td>RB_SPI_SLV_CS_LOAD</td><td>R0</td><td>从机模式被片选后首次加载状态位(仅SPI0支持):1:正在加载R8_SPI0_SLAVE_PRE;0:尚未加载或者已完成。</td><td>0</td></tr><tr><td>5</td><td>RB_SPI_FIFO_READY</td><td>R0</td><td>FIFO0准备就绪状态位:1:FIFO0就绪(R16_SPIx_TOTAL_CNT非0,且接收时FIFO0未满或发送时FIFO0不空);0:FIFO0未准备好。</td><td>0</td></tr><tr><td>4</td><td>RB_SPI_SLV_CMD_ACT</td><td>R0</td><td>从机模式下命令接收完成状态位,即交换完首字节数据(仅SPI0支持):1:指示刚刚交换完成的是首字节;0:首字节尚未交换或不是首字节。</td><td>0</td></tr><tr><td>[3:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

SPI 中断标志寄存器(R8\_SPIx\_INT\_FLAG) (x=0/1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_SPI_IF_FST_BYTE</td><td>RW1Z</td><td>从机模式下,接收到首字节标志位(仅SPI0支持):1:已接收到首字节;0:未接收到。</td><td>0</td></tr><tr><td>6</td><td>RB_SPI-Free</td><td>R0</td><td>当前SPI空闲状态位:1:当前SPI空闲;0:当前SPI非空闲。</td><td>1</td></tr><tr><td>5</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_SPI_IF_FIFO_0V</td><td>RW1Z</td><td>从机模式下,FIFO0溢出(接收时FIFO0满或发送时FIFO0空)标志位,写1清零:1:FIFO0溢出;0:FIFO0未溢出。</td><td>0</td></tr><tr><td>3</td><td>RB_SPI_IF_DMA_END</td><td>RW1Z</td><td>DMA完成标志位(仅SPI0支持),写1清零:1:已完成;0:未完成。</td><td>0</td></tr><tr><td>2</td><td>RB_SPI_IF_FIFO_HF</td><td>RW1Z</td><td>FIFO0使用过半(接收时FIFO&gt;=4或发送时FIFO&lt;4)标志位,写1清零:1: FIFO使用已过半;0: FIFO使用未过半。</td><td>0</td></tr><tr><td>1</td><td>RB_SPI_IF_BYTE_END</td><td>RW1Z</td><td>SPI单字节传输完成标志位,写1清零:1: 单字节传输完成;0: 传输未完成。</td><td>0</td></tr><tr><td>0</td><td>RB_SPI_IF_CNT_END</td><td>RW1Z</td><td>SPI全部字节传输完成标志位,写1清零:1: 全部字节传输完成;0: 传输未完成。</td><td>1</td></tr></table>

SPI 收发 FIFO 计数寄存器(R8\_SPIx\_FIFO\_COUNT) $\scriptstyle ( \mathsf { x } = 0 / 1$

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[3:0]</td><td>RB_SPIx_FIFO_COUNT</td><td>RW</td><td>当前 FIFO 中字节计数。</td><td>0</td></tr></table>

SPI 收发数据总长度寄存器(R16\_SPIx\_TOTAL\_CNT) $\scriptstyle ( x = 0 / 1$ )

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:12]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[11:0]</td><td>RB_SPIX_TOTAL_CNT</td><td>RW</td><td>主机模式下SPI数据收发总字节数,低12位有效。在使用DMA时一次最多可以收发4095个字节。不支持从机模式。</td><td>0</td></tr></table>

SPI 数据 FIFO 寄存器(R8\_SPIx\_FIFO) $\scriptstyle ( x = 0 / 1$ )

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_SPIx_FIFO</td><td>RO/WO</td><td>数据 FIFO 寄存器。</td><td>XXh</td></tr></table>

寄存器 R8\_SPIx\_BUFFER 和 R8\_SPIx\_FIFO 均为 SPI 数据相关寄存器，主要区别在于：

读 R8\_SPIx\_BUFFER 是取自 SPI 最近一次交换到的数据，不影响 FIFO 和 R8\_SPIx\_FIFO\_COUNT，

主机模式下写 R8\_SPIx\_BUFFER 是直接发送该字节，从机模式下写操作未定义；

读 R8\_SPIx\_FIFO 是取自 FIFO 中最早交换到的数据，将减少 FIFO 和 R8\_SPIx\_FIFO\_COUNT，

写R8\_SPIx\_FIFO是将数据暂存到FIFO中，在从机模式下由外部SPI主机决定何时取走，在主机模式下当 R16\_SPIx\_TOTAL\_CNT 非 0 时自动启动发送。

SPI 收发 FIFO 计数寄存器 1(R8\_SPIx\_FIFO\_COUNT1) (x=0/1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[3:0]</td><td>RB_SPIx_FIFO_COUNT1</td><td>RW</td><td>当前 FIFO 中字节计数。
同 R8_SPIx_FIFO_COUNT。</td><td>0</td></tr></table>

SPI0 DMA 缓冲区当前地址(R32\_SPI0\_DMA\_NOW)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:0]</td><td>RB_SPI0_DMA NOW</td><td>RW</td><td>DMA数据缓冲区当前地址。可用于计算已转换次数，计算方法：COUNT=SPI0_DMA NOW-SPIO_DMA_BEG。</td><td>XXXXXh</td></tr></table>

SPI0 DMA 缓冲区起始地址(R32\_SPI0\_DMA\_BEG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:0]</td><td>RB_SPI0_DMA_BEG</td><td>RW</td><td>DMA数据缓冲区起始地址。</td><td>XXXXXh</td></tr></table>

SPI0 DMA 缓冲区结束地址(R32\_SPI0\_DMA\_END)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:0]</td><td>RB_SPI0_DMA_END</td><td>RW</td><td>DMA数据缓冲区结束地址（不含）。</td><td>XXXXXh</td></tr></table>

# 10.3 SPI 传输格式

SPI 支持模式 0 和模式 3 两种传输格式，通过设置 R8\_SPIx\_CTRL\_MOD 的 RB\_SPI\_MST\_SCK\_MOD 进行选择。总是在SCK上升沿采样串行数据输入，在下降沿输出串行数据。

数据传输格式如下图所示：

模式 0：RB\_SPI\_MST\_SCK\_MOD = 0

图 10-1 SPI 模式 0 传输格式

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/4df0a465e0c60cfd1c5dd0f9df934c81b36bc97f9a137e444b2f90a29c31fd48.jpg null)

模式 3：RB\_SPI\_MST\_SCK\_MOD = 1

图 10-2 SPI 模式 3 传输格式

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/d89ad3318bbbda510af95556ebf2105b6dc0ce2d172b31e9382473db307b92cc.jpg null)

# 10.4 SPI 配置

# 10.4.1 SPI 主机模式

SPI主机模式下，在SCK引脚产生串行时钟，片选引脚可以指定为任意I/O引脚。

配置步骤：

(1)、设置 R8\_SPI0\_CLOCK\_DIV，配置 SPI 时钟频率；

(2)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_MODE\_SLAVE 为 0，配置 SPI 为主机模式；

(3)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_MST\_SCK\_MOD，选择时钟空闲模式 0 或模式 3；

(4)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_FIFO\_DIR 配置 FIFO 方向，为 1 则 FIFO 用于接收，为 0 则FIFO用于发送。

(5)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_MOSI\_OE 和 RB\_SPI\_SCK\_OE 为 1，RB\_SPI\_MISO\_OE 为 0，并设置 GPIO 方向配置寄存器(R32\_PA/PB\_DIR)使 MOSI 引脚和 SCK 引脚为输出，MISO 引脚为输入；

(6)、2 线模式下 SCK 不变，RB\_SPI\_MOSI\_OE=0，不用 MOSI，由 MISO 半双工实现输入（同 3 线模式，RB\_SPI\_MISO\_OE=0 且引脚置为输入）和输出（RB\_SPI\_MISO\_OE=1 且引脚置为输出），手工切换方向；

(7)、可选步骤，如果启用DMA，那么需将收发缓冲区起始地址写入R32\_SPI\_DMA\_BEG，结束地址（不含）写入 R32\_SPI\_DMA\_END，建议在设置完 RB\_SPI\_FIFO\_DIR 后再置位 RB\_SPI\_DMA\_ENABLE，如果确认 R16\_SPI0\_TOTAL\_CNT 为 0，那么也可在此先设置 RB\_SPI\_DMA\_ENABLE 为 1，使能 DMA 功能。

# 数据发送过程：

(1)、设置 RB\_SPI\_FIFO\_DIR 为 0，当前 FIFO 方向为输出；

(2)、写 R16\_SPI0\_TOTAL\_CNT 寄存器，设置要发送的数据长度；

(3)、写 R8\_SPI0\_FIFO 寄存器，向 FIFO 中写入要发送的数据，如果 R8\_SPI0\_FIFO\_COUNT 小于 FIFO容量则可以继续写FIFO，如果是启用DMA，则由DMA自动加载FIFO完成此步骤；

(4)、只要 R16\_SPI0\_TOTAL\_CNT 非 0 并且 FIFO 中有数据，SPI 主机就会自动发送数据，否则暂停；

(5)、等待R16\_SPI0\_TOTAL\_CNT寄存器为0，说明数据发送完成，如果只发送一字节，也可以查询等待 RB\_SPI\_FREE 为空闲、或等待 R8\_SPI0\_FIFO\_COUNT 为 0。

# 数据接收过程：

(1)、设置 RB\_SPI\_FIFO\_DIR 为 1，当前 FIFO 方向为输入；

(2)、写 R16\_SPI0\_TOTAL\_CNT 寄存器，设置要接收的数据长度；

(3)、只要 R16\_SPI0\_TOTAL\_CNT 非 0 并且 FIFO 未满，SPI 主机就会自动接收数据，否则暂停；

(4)、等待 R8\_SPI0\_FIFO\_COUNT 寄存器不为 0，则说明接收到返回数据，读取 R8\_SPI0\_FIFO 中的值即为接收到的数据，如果是启用DMA，则由DMA自动读取FIFO完成此步骤。

# 10.4.2 SPI 从机模式

SPI0支持从机模式，在从机模式下，SCK引脚用于接收外部连接的SPI主机的串行时钟。

# 配置步骤：

(1)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_MODE\_SLAVE 为 1，配置 SPI0 为从机模式；

(2)、根据需要设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_SLV\_CMD\_MOD，选择从机首字节模式或数据流模式；

(3)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_FIFO\_DIR，配置 FIFO 方向，为 1 则 FIFO 用于接收，为 0 则FIFO 用于发送；

(4)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_MOSI\_OE 和 RB\_SPI\_SCK\_OE 为 0，RB\_SPI\_MISO\_OE 为 1，并设置 GPIO 方向配置寄存器(R32\_PA/PB\_DIR)使 MOSI 引脚、SCK 引脚和 SCS 引脚为输入，MISO 引脚为输入（支持总线下多个从机连接，被片选后 MISO 会自动切换为输出，也支持一主一从）或输出（仅用于一主一从对连）。在 SPI 从机模式下 MISO 的 I/O 引脚方向，除了能够由 GPIO 方向配置寄存器设为输出之外，还支持 SPI 片选有效期间自动切换为输出，但其输出数据由 RB\_SPI\_MISO\_OE 选择，为1时输出SPI数据，为0时输出GPIO数据输出寄存器的数据。建议，设置MISO引脚为输入，使MISO在片选无效时不输出，便于多机操作时共享SPI总线；

(5)、可选的，设置SPI0从机模式预置数据寄存器R8\_SPI0\_SLAVE\_PRE，用于被片选后首次自动加载到缓冲区中用于对外输出。当 8 个时钟过去之后（即首个数据字节在主从双方之间交换完毕），控制器得到外部 SPI 主机发来的首字节数据（命令码），外部 SPI 主机交换得到 R8\_SPI0\_SLAVE\_PRE 中的预置数据（状态值）。R8\_SPI0\_SLAVE\_PRE 的位 7 将在 SPI 片选有效后的 SCK 低电平期间自动加载到MISO 引脚上，对于 SPI 模式 0（CLK 默认为低电平），如果预置了 R8\_SPI0\_SLAVE\_PRE 的位 7，那么外部SPI主机将在SPI片选有效但尚未传输数据时，就能够通过查询MISO引脚得到R8\_SPI0\_SLAVE\_PRE的位7的预置值，从而通过仅仅有效一下SPI片选就能快速获得R8\_SPI0\_SLAVE\_PRE的位7的值（通

常是向主机提供一个忙状态，便于主机快速查询）；

(6)、可选步骤，如果启用DMA，那么需将收发缓冲区起始地址写入R16\_SPI\_DMA\_BEG，结束地址（不含）写入 R16\_SPI\_DMA\_END，必须在设置完 RB\_SPI\_FIFO\_DIR 后才能置位 RB\_SPI\_DMA\_ENABLE。

# 数据发送过程：

(1)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_FIFO\_DIR 为 0，当前 FIFO 方向为输出；

(2)、可选步骤，如果启用 DMA，那么需设置 RB\_SPI\_DMA\_ENABLE 为 1，使能 DMA 功能；

(3)、将多个发送数据写入到 FIFO 寄存器 R8\_SPI0\_FIFO 中，由外部 SPI 主机决定何时取走，如果是启用DMA，则由DMA自动加载FIFO完成此步骤；

(4)、查询 R8\_SPI0\_FIFO\_COUNT，如果未满则继续向 FIFO 写入待发送的数据。

# 数据接收过程：

(1)、设置 R8\_SPI0\_CTRL\_MOD 的 RB\_SPI\_FIFO\_DIR 为 1，当前 FIFO 方向为输入；

(2)、可选步骤，如果启用 DMA，那么需设置 RB\_SPI\_DMA\_ENABLE 为 1，使能 DMA 功能；

(3)、查询 R8\_SPI0\_FIFO\_COUNT，如果不空则说明已接收到数据，通过读取 R8\_SPI0\_FIFO 取走数据，如果是启用DMA，则由DMA自动读取FIFO完成此步骤；

(4)、单个字节的数据接收，也可以不使用 FIFO，可以直接读取 R8\_SPI0\_BUFFER。

# 10.5 SPI 时序

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/181fbb53a652523f971bd1f71e9393aeb96411642fe7254dda5f196b084920ad.jpg null)

<table><tr><td>名称</td><td>参数说明 (TA=25°C, V1033=3.3V)</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>TSS</td><td>SCK上升沿之前SCS有效的建立时间</td><td>Tsys*1.05</td><td></td><td></td><td>nS</td></tr><tr><td>TSH</td><td>SCK上升沿之后SCS有效的保持时间</td><td>Tsys*1.05</td><td></td><td></td><td>nS</td></tr><tr><td>TNS</td><td>SCK上升沿之前SCS无效的建立时间</td><td>15</td><td></td><td></td><td>nS</td></tr><tr><td>TNH</td><td>SCK上升沿之后SCS无效的保持时间</td><td>15</td><td></td><td></td><td>nS</td></tr><tr><td>TN</td><td>SCS无效时间(SPI操作间隔时间)</td><td>Tsys*2</td><td></td><td></td><td>nS</td></tr><tr><td>TCH</td><td>SCK时钟的高电平时间</td><td>Tsys*0.55</td><td></td><td></td><td>nS</td></tr><tr><td>TCL</td><td>SCK时钟的低电平时间</td><td>Tsys*0.55</td><td></td><td></td><td>nS</td></tr><tr><td>TDS</td><td>SCK上升沿之前MOSI/MISO输入的建立时间</td><td>8</td><td></td><td></td><td>nS</td></tr><tr><td>TDH</td><td>SCK上升沿之后MOSI/MISO输入的保持时间</td><td>5</td><td></td><td></td><td>nS</td></tr><tr><td>TOE</td><td>SCK下降沿到MISO/MOSI输出有效</td><td>0</td><td></td><td>18</td><td>nS</td></tr><tr><td>TOX</td><td>SCK下降沿到MISO/MOSI输出改变</td><td>0</td><td>5</td><td>16</td><td>nS</td></tr><tr><td>TOZ</td><td>SCS无效到MISO/MOSI输出无效</td><td>2</td><td></td><td>24</td><td>nS</td></tr></table>

注：Tsys是系统主频时钟周期（1/Fsys）。

# 第 11 章 PWM

# 11.1 PWM 控制器简介

除了定时器提供的4路26位PWM输出之外，系统还提供了8路8位PWM输出（PWM4～PWM11）或6路16位PWM输出（PWM4～PWM9），占空比可调，PWM周期固定可选8种周期，操作简单。

# 11.2 寄存器描述

表 11-1 PWMx 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_PWM_OUT_EN</td><td>0x40005000</td><td>PWMx输出使能寄存器</td><td>0x00</td></tr><tr><td>R8_PWM_POLAR</td><td>0x40005001</td><td>PWMx输出极性配置寄存器</td><td>0x00</td></tr><tr><td>R8_PWM_CONFIG</td><td>0x40005002</td><td>PWMx配置控制寄存器</td><td>0x0X</td></tr><tr><td>R8_PWM_CLOCK_DIV</td><td>0x40005003</td><td>PWMx时钟分频寄存器</td><td>0x00</td></tr><tr><td>R32_PWM4_7_DATA</td><td>0x40005004</td><td>PWM4/5/6/7数据保持寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R8_PWM4_DATA</td><td>0x40005004</td><td>PWM4数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM5_DATA</td><td>0x40005005</td><td>PWM5数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM6_DATA</td><td>0x40005006</td><td>PWM6数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM7_DATA</td><td>0x40005007</td><td>PWM7数据保持寄存器</td><td>0xXX</td></tr><tr><td>R32_PWM8_11_DATA</td><td>0x40005008</td><td>PWM8/9/10/11数据保持寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R8_PWM8_DATA</td><td>0x40005008</td><td>PWM8数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM9_DATA</td><td>0x40005009</td><td>PWM9数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM10_DATA</td><td>0x4000500A</td><td>PWM10数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM11_DATA</td><td>0x4000500B</td><td>PWM11数据保持寄存器</td><td>0xXX</td></tr><tr><td>R8_PWM_INT_CTRL</td><td>0x4000500C</td><td>PWMx中断控制和状态寄存器</td><td>0x00</td></tr><tr><td>R32_PWM_REG_DATA8</td><td>0x40005010</td><td>PWM8/9数据寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R32_PWM_REG_CYCLE</td><td>0x40005014</td><td>PWM周期数结束寄存器</td><td>0x0000XXX</td></tr></table>

PWMx 输出使能寄存器(R8\_PWM\_OUT\_EN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_PWM11_OUT_EN</td><td>RW</td><td>PWM11 输出使能位:1: 使能;0: 禁止。</td><td>0</td></tr><tr><td>6</td><td>RB_PWM10_OUT_EN</td><td>RW</td><td>PWM10 输出使能位:1: 使能;0: 禁止。</td><td>0</td></tr><tr><td>5</td><td>RB_PWM9_OUT_EN</td><td>RW</td><td>PWM9 输出使能位:1: 使能;0: 禁止。</td><td>0</td></tr><tr><td>4</td><td>RB_PWM8_OUT_EN</td><td>RW</td><td>PWM8 输出使能位:1: 使能;0: 禁止。</td><td>0</td></tr><tr><td>3</td><td>RB_PWM7_OUT_EN</td><td>RW</td><td>PWM7 输出使能位:1: 使能;0: 禁止。</td><td>0</td></tr><tr><td>2</td><td>RB_PWM6_OUT_EN</td><td>RW</td><td>PWM6 输出使能位:1: 使能;0: 禁止。</td><td>0</td></tr><tr><td>1</td><td>RB_PWM5_OUT_EN</td><td>RW</td><td>PWM5 输出使能位: 
1: 使能; 
0: 禁止。</td><td>0</td></tr><tr><td>0</td><td>RB_PWM4_OUT_EN</td><td>RW</td><td>PWM4 输出使能位: 
1: 使能; 
0: 禁止。</td><td>0</td></tr></table>

PWMx 输出极性配置寄存器(R8\_PWM\_POLAR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_PWM11_POLAR</td><td>RW</td><td>PWM11 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>6</td><td>RB_PWM10_POLAR</td><td>RW</td><td>PWM10 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>5</td><td>RB_PWM9_POLAR</td><td>RW</td><td>PWM9 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>4</td><td>RB_PWM8_POLAR</td><td>RW</td><td>PWM8 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>3</td><td>RB_PWM7_POLAR</td><td>RW</td><td>PWM7 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>2</td><td>RB_PWM6_POLAR</td><td>RW</td><td>PWM6 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>1</td><td>RB_PWM5_POLAR</td><td>RW</td><td>PWM5 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr><tr><td>0</td><td>RB_PWM4_POLAR</td><td>RW</td><td>PWM4 输出极性控制位:1: 默认高电平,低有效;0: 默认低电平,高有效。</td><td>0</td></tr></table>

PWMx 配置控制寄存器(R8\_PWM\_CONFIG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_PWM10_11_STAG_EN</td><td>RW</td><td>PWM10/11交错输出使能位:1:交错输出;0:独立输出。</td><td>0</td></tr><tr><td>6</td><td>RB_PWM8_9_STAG_EN</td><td>RW</td><td>PWM8/9交错输出使能位:1:交错输出;0:独立输出。</td><td>0</td></tr><tr><td>5</td><td>RB_PWM6_7_STAG_EN</td><td>RW</td><td>PWM6/7交错输出使能位:1:交错输出;0:独立输出。</td><td>0</td></tr><tr><td>4</td><td>RB_PWM4_5_STAG_EN</td><td>RW</td><td>PWM4/5交错输出使能位:1:交错输出;0:独立输出。</td><td>0</td></tr><tr><td>[3:2]</td><td>RB_PWM_CYC_MOD</td><td>RW</td><td>PWM数据宽度选择:
00:8位数据宽度;
01:7位数据宽度;
10:6位数据宽度;
11:16位数据宽度。</td><td>00b</td></tr><tr><td>1</td><td>RB_PWM_STAG_ST</td><td>RO</td><td>PWM交错标志位:
1:指示PWM5/7/9/11被允许输出;
0:指示PWM4/6/8/10被允许输出。</td><td>X</td></tr><tr><td>0</td><td>RB_PWM_CYCLE_SEL</td><td>RW</td><td>PWM周期选择:
1:8/7/6位数据宽度对应255/127/63个时钟周期;
16位数据宽度对应时钟周期受R32_PWM_REG_CYCLE控制。
0:8/7/6位数据宽度对应256/128/64个时钟周期;
16位数据宽度对应时钟周期受R32_PWM_REG_CYCLE控制。</td><td>0</td></tr></table>

PWM 时钟分频寄存器(R8\_PWM\_CLOCK\_DIV)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_PWM_CLOCK_DIV</td><td>RW</td><td>PWM基准时钟分频系数。Fpw=Fsys/R8_PWM_CLOCK_DIV。</td><td>00h</td></tr></table>

PWMx 数据保持寄存器组 1(R32\_PWM4\_7\_DATA)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>R8_PWM7_DATA</td><td>RW</td><td>PWM7数据保持寄存器。</td><td>XXh</td></tr><tr><td>[23:16]</td><td>R8_PWM6_DATA</td><td>RW</td><td>PWM6数据保持寄存器。</td><td>XXh</td></tr><tr><td>[15:8]</td><td>R8_PWM5_DATA</td><td>RW</td><td>PWM5数据保持寄存器。</td><td>XXh</td></tr><tr><td>[7:0]</td><td>R8_PWM4_DATA</td><td>RW</td><td>PWM4数据保持寄存器。</td><td>XXh</td></tr><tr><td>[31:16]</td><td>R16_PWM5_DATA</td><td>RW</td><td>PWM5数据保持寄存器（16位宽）。</td><td>XXh</td></tr><tr><td>[15:0]</td><td>R16_PWM4_DATA</td><td>RW</td><td>PWM4数据保持寄存器（16位宽）。</td><td>XXh</td></tr></table>

PWMx 数据保持寄存器组 2(R32\_PWM8\_11\_DATA)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>R8_PWM11_DATA</td><td>RW</td><td>PWM11数据保持寄存器。</td><td>XXh</td></tr><tr><td>[23:16]</td><td>R8_PWM10_DATA</td><td>RW</td><td>PWM10数据保持寄存器。</td><td>XXh</td></tr><tr><td>[15:8]</td><td>R8_PWM9_DATA</td><td>RW</td><td>PWM9数据保持寄存器。</td><td>XXh</td></tr><tr><td>[7:0]</td><td>R8_PWM8_DATA</td><td>RW</td><td>PWM8数据保持寄存器。</td><td>XXh</td></tr><tr><td>[31:16]</td><td>R16_PWM7_DATA</td><td>RW</td><td>PWM7数据保持寄存器（16位宽）。</td><td>XXh</td></tr><tr><td>[15:0]</td><td>R16_PWM6_DATA</td><td>RW</td><td>PWM6数据保持寄存器（16位宽）。</td><td>XXh</td></tr></table>

PWM 中断控制和状态寄存器(R8\_PWM\_INT\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_PWM_IF_CYC</td><td>RW1Z</td><td>PWM周期结束标志位，写1清零：1：周期结束；0：未结束。</td><td>0</td></tr><tr><td>[6:2]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>00000b</td></tr><tr><td>1</td><td>RB_PWM_CYC_PRE</td><td>RW</td><td>选择PWM周期结束中断时间点：</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1: 提前 16 个计数产生中断(以 8 位数据宽度为例, 计数到 240 时产生中断);0: 提前 2 个计数产生中断(以 8 位数据宽度为例, 计数到 254 时产生中断)。</td><td></td></tr><tr><td>0</td><td>RB_PWM_IE_CYC</td><td>RW</td><td>PWM 周期结束中断使能位:1: 使能中断;0: 禁止中断。</td><td>0</td></tr></table>

PWM8/9 数据寄存器(R32\_PWM\_REG\_DATA8)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>R16_PWM9_REG_DATA</td><td>RW</td><td>PWM9通道的16位bit数据。</td><td>XXXXh</td></tr><tr><td>[15:0]</td><td>R16_PWM8_REG_DATA</td><td>RW</td><td>PWM8通道的16位bit数据。</td><td>XXXXh</td></tr></table>

注：只有16数据宽度时有效。

PWM 周期数结束寄存器(R32\_PWM\_REG\_CYCLE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0000h</td></tr><tr><td>[15:0]</td><td>RB_PWM_CYC_VALUE</td><td>RW</td><td>16数据宽度时的PWM时钟周期:Nyc=RB_PWM_CYC_VALUE+1</td><td>XXXXh</td></tr></table>

# 11.3 PWM 配置

(1)、设置寄存器 R8\_PWM\_CLOCK\_DIV，配置 PWM 的基准时钟频率；

(2)、设置PWM输出极性配置寄存器R8\_PWM\_POLAR，配置对应PWMx的输出极性；

(3)、设置 PWM 配置控制寄存器 R8\_PWM\_CONFIG，设置 PWM 的模式、数据位宽、周期；

(4)、设置 PWM 输出使能寄存器 R8\_PWM\_OUT\_EN，开启对应的 PWMx 输出使能；

(5)、根据需要的占空比计算出数据，写入对应的数据保持寄存器 R8\_PWMx\_DATA；

(6)、设置PWM4-PWM11中所需的PWM引脚方向为输出，可选地，设置相应I/O的驱动能力；

(7)、根据需要更新 R8\_PWMx\_DATA 中的数据，更新输出占空比。

时钟周期数（Ncyc）计算公式：

数据宽度 $n { = } 8 / 7 / 6$ ：Ncyc=2^n-RB\_PWM\_CYCLE\_SEL；

16 位数据宽度 Ncyc=RB\_PWM\_CYC\_VALUE+1

PWMx 占空比计算公式：

占空比=R8\_PWMx\_DATA/Ncyc

PWMx 输出频率 Fpwmout 计算公式：

PWMx 输出频率 Fpwmout=Fpwm/Ncyc=Fsys/R8\_PWM\_CLOCK\_DIV/Ncyc

注：如果需要通过PWM产生直流信号，那么可以PWMx输出端使用R/C等电路滤波，建议用时间常数远大于4/Fpwmout的两级RC，或时间常数远大于100/Fpwmout的一级RC。

# 第 12 章 两线串行接口 I2C

# 12.1 I2C 简介

I2C是一种中低速串行总线，总线上可以连接有多个主机和若干从机。通常I2C接口由2个引脚组成：串行时钟引脚SCL、串行数据引脚SDA。

# 12.1.1 主要特性

CH585 和 CH584 芯片提供 I2C 接口，特性如下：

$\bullet$ 支持主机模式（Master）和从机模式（Slave），支持多主多从

$\bullet$ 支持两种速度模式：100KHz 和 400KHz，兼容 I2C 两线串行总线规范

支持7位或10位地址

$\bullet$ 从设备支持双7位地址

$\bullet$ 支持总线广播

$\bullet$ 支持总线仲裁、错误检测、PEC校验、延长时钟

 兼容 SMBus

# 12.2 I2C 概述

I2C是个半双工的总线，它同时只能运行在下列四种模式中之一：主设备发送模式、主设备接收模式、从设备发送模式和从设备接收模式。I2C模块默认工作在从模式，在产生起始条件后，会自动地切换到主模式，当仲裁丢失或者产生停止信号后，会切换到从模式。I2C模块支持多主机功能。工作在主模式时，I2C 模块会主动发出数据和地址。数据和地址都以 8 位为单位进行传输，高位在前，低位在后，在起始事件后的是一个字节（7位地址模式下）或两个字节（10位地址模式下）地址，主机每发送8位数据或地址，从机需要回复一个应答ACK，即把SDA总线拉低，如图12-1所示。

图 12-1 I2C 时序图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/6463b79c3d5b39ca28b36d3950e0f42b9e75dedaf7e820c5f36ababc5be5a94a.jpg null)

# 12.3 主模式

主模式时，I2C模块主导数据传输并输出时钟信号，数据传输以开始事件开始，以结束事件结束。使用主模式通讯的步骤为：

1）在控制寄存器 2（R16\_I2C\_CTRL2）和时钟控制寄存器（R16\_I2C\_CKCFGR）中设置正确的时钟；

2）在上升沿寄存器（R16\_I2C\_RTR）设置合适的上升沿；

3）在控制寄存器（R16\_I2C\_CTRL1）中置 PE 位启动外设；

4）在控制寄存器（R16\_I2C\_CTRL1）中置START位，产生起始事件。

在置 START 位后，I2C 模块会自动切换到主模式，MSL 位会置位，产生起始事件，在产生起始事件后，SB位会置位，如果ITEVTEN位（在R16\_I2C\_CTRL2）被置位，则会产生中断。此时应该读取状态寄存器1（R16\_I2C\_STAR1），写从地址到数据寄存器后，SB位会自动清除；

5）如果是使用 10 位地址模式，那么写数据寄存器发送头序列（头序列为 $1 1 1 1 0 \times \times 0 6$ ，其中的 xx 位

是 10 位地址的最高两位）。

在发送完头序列之后，状态寄存器的ADD10位会被置位，如果ITEVTEN位已经置位，则会产生中断，此时应读取R16\_I2C\_STAR1寄存器后，写第二个地址字节到数据寄存器后，清除ADD10位。

然后写数据寄存器发送第二个地址字节，在发送完第二个地址字节后，状态寄存器的 ADDR 位会被置位，如果 ITEVTEN 位已经置位，则会产生中断，此时应读取 R16\_I2C\_STAR1 寄存器后再读一次R16\_I2C\_STAR2 寄存器以清除 ADDR 位；

如果使用的是7位地址模式，那么写数据寄存器发送地址字节，在发送完地址字节后，状态寄存器的 ADDR 位会被置位，如果 ITEVTEN 位已经置位，则会产生中断，此时应读取 R16\_I2C\_STAR1 寄存器后再读一次 R16\_I2C\_STAR2 寄存器以清除 ADDR 位；

在7位地址模式下，发送的第一个字节为地址字节，头7位代表的是目标从设备地址，第8位决定了后续报文的方向，0代表是主设备写入数据到从设备，1代表是主设备向从设备读取信息。

在10位地址模式下，如图12-3所示，在发送地址阶段，第一个字节为 $1 1 1 1 0 \times \times 0$ ， $\tt { x x }$ 为10位地址的最高 2 位，第二个字节为 10 位地址的低 8 位。若后续进入主设备发送模式，则继续发送数据；若后续准备进入主设备接收模式，则需要重新发送一个起始条件，跟随发送一个字节为 $1 1 1 1 0 \times \times 1$ ，然后进入主设备接收模式。

图12-3 10位地址时主机收发数据示意图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/f7bea7d1c9a5daafd1f230d1b8ce9f4f134bd2579cb1bcdcf31a01e53625eaad.jpg null)

6）发送模式时，主设备内部的移位寄存器将数据从数据寄存器发送到SDA线上，当主设备接收到ACK时，状态寄存器 1（R16\_I2C\_STAR1）的 TxE 被置位，如果 ITEVTEN 和 ITBUFEN 被置位，还会产生中断。向数据寄存器写入数据将会清除TxE位。

如果 TxE 位被置位且上次发送数据之前没有新的数据被写入数据寄存器，那么 BTF 位会被置位,在其被清除之前，SCL将保持低电平，读R16\_I2C\_STAR1后，向数据寄存器写入数据将会清除BTF位。

而在接收模式时，I2C模块会从SDA线接收数据，通过移位寄存器写进数据寄存器。在每个字节之后，如果ACK位被置位，那么I2C模块将会发出一个应答低电平，同时RxNE位会被置位，如果ITEVTEN和 ITBUFEN 被置位，还会产生中断。如果 RxNE 被置位且在新的数据被接收前，原有的数据没有被读出，则BTF位将被置位，在清除BTF之前，SCL将保持低电平，读取R16\_I2C\_STAR1后，再读取数据寄存器将会清除BTF位。

7）主设备在结束发送数据时，会主动发一个结束事件，即置STOP位。在接收模式时，主设备需要在最后一个数据位的应答位置NAK。注意，产生NAK后，I2C模块将会切换至从模式。

# 12.4 从模式

从模式时，I2C模块能识别它自己的地址和广播呼叫地址。软件能控制开启或禁止广播呼叫地址的识别。一旦检测到起始事件，I2C 模块将 SDA 的数据通过移位寄存器与自己的地址（位数取决于ENDUAL 和 ADDMODE）或广播地址（ENGC 置位时）相比较，如果不匹配将会忽略，直到产生新的起始事件。如果与头序列相匹配，则会产生一个ACK信号并等待第二个字节的地址；如果第二字节的地址也匹配或者7位地址情况下全段地址匹配，那么：首先产生一个ACK应答；ADDR位被置位，如果ITEVTEN位已经置位，那么还会产生相应的中断；如果使用的是双地址模式（ENDUAL位被置位），还需要读取DUALF位来判断主机唤起的是哪一个地址。

从模式默认是接收模式，在接收的头序列的最后一位为1，或者7位地址最后一位为1时（取决于第一次接收到头序列还是普通的7位地址），I2C模块将进入到发送器模式，TRA位将指示当前是接收器还是发送器模式。

发送模式时，在清除ADDR位后，I2C模块将字节从数据寄存器通过移位寄存器发送到SDA线上。在收到一个应答 ACK 后，TxE 位将被置位，如果设置了 ITEVTEN 和 ITBUFEN，还会产生一个中断。如果TxE被置位但在下一个数据发送结束前没有新的数据被写入数据寄存器时，BTF位将被置位。在清除BTF前，SCL将保持低电平，读取状态寄存器1（R16\_I2C\_STAR1）后，再向数据寄存器写入数据将会清除BTF位。

接收模式时，在 ADDR 被清除后，I2C 模块将 SDA 上的数据通过移位寄存器存进数据寄存器，在每接收到一个字节后，I2C模块都会置一个ACK位，并置RxNE位，如果设置了ITEVTEN和ITBUFEN，还会产生一个中断。如果 RxNE 被置位，且在接收到新的数据前旧的数据没有被读出，那么 BTF 会被置位。在清除 BTF 位之前 SCL 会保持低电平。读取状态寄存器 1（R16\_I2C\_STAR1）并读取数据寄存器里的数据会清除BTF位。

当I2C模块检测到停止事件时，将置STOPF位，如果设置了ITEVFEN位，还会产生一个中断。用户需要读取状态寄存器（R16\_I2C\_STAR1）再写控制寄存器（比如复位控制字SWRST）来清除。

# 12.5 错误

# 12.5.1 总线错误 BERR

在传输地址或者数据期间，I2C模块检测到外部的起始或者停止事件时，将产生一个总线错误。产生总线错误时，BERR 位被置位，如果设置了 ITERREN 还会产生一个中断。在从模式下，数据被丢弃，硬件释放总线。如果是起始信号，硬件会认为是重启信号，开始等待地址或停止信号；如果是停止信号，则提前按正常的停止条件操作。在主模式下，硬件不会释放总线，同时不影响当前传输，由用户代码决定是否中止传输。

# 12.5.2 应答错误 AF

当 I2C 模块检测到一个字节后没有应答时，会产生应答错误。产生应答错误时：AF 会被置位，如果设置了 ITERREN 还会产生一个中断；遇到 AF 错误，如果 I2C 模块工作在从模式，硬件必须释放总线，如果处于主模式，软件必须生成一个停止事件。

# 12.5.3 仲裁丢失 ARLO

当 I2C 模块检测到仲裁丢失时，产生仲裁丢失错误。产生仲裁丢失错误时：ARLO 位被置位，如果设置了ITERREN还会产生一个中断；I2C模块切换到从模式，并不再响应针对它的从地址发起的传输，除非有主机发起新的起始事件；硬件会释放总线。

# 12.5.4 过载/欠载错误 OVR

# 1）过载错误：

在从机模式下，如果禁止时钟延长，I2C模块正在接收数据，如果已经接受到一个字节的数据，但是上一次接收到数据还没有被读出，则会产生过载错误。发生过载错误时，最后收到的字节将被丢弃，发送方应当重发最后一次发送的字节。

# 2）欠载错误：

在从模式下，如果禁止时钟延长，I2C模块正在发送数据，如果在下一个字节的时钟到来之前新的数据还没有被写入到数据寄存器，那么将产生欠载错误。在发生欠载错误时，前一次数据寄存器里的数据将被发送两次，如果发生欠载错误，那么接收方应该丢弃重复收到的数据。为了不产生欠载错误，I2C模块应当在下一个字节的第一个上升沿之前将数据写入数据寄存器。

# 12.6 时钟延长

如果禁止时钟延长，那么就存在发生过载/欠载错误的可能。但如果使能了时钟延长：

1）在发送模式下，如果 TxE 置位且 BTF 置位，SCL 将一直为低，一直等待用户读取状态寄存器，并向数据寄存器写入待发送的数据；

2）在接收模式下，如果RxNE置位且BTF置位，那么SCL在接收到数据后将保持低，直到用户读取状态寄存器，并读取数据寄存器；

由此可见，使能时钟延长可以避免出现过载/欠载错误。

# 12.7 SMBus

SMBus也是一种两线接口，一般应用于在系统和电源管理之间。SMBus和I2C有很多相似的地方，例如 SMBus 使用和 I2C 一样的 7 位地址模式，以下是他们的共同点：

1）主从通信模式，主机提供时钟，支持多主多从；

2）两线通讯结构；

3）支持7位地址格式。

区别：

1）I2C 支持的速度可达 400KHz，SMBus 速度仅达 100KHz，且 SMBus 有最小 10KHz 的速度限制；

2）SMBus的时钟为低超过35mS时，会报超时，但I2C无此限制；

3）SMBus 有固定的逻辑电平，而 I2C 没有，取决于芯片电源电压 VDD；

4）SMBus有总线协议，而I2C没有。

SMBus 还包括设备识别、地址解析协议、唯一的设备标识符、SMBus 提醒和各种总线协议，具体请参考SMBus规范2.0版本。当使用SMBus时，只需要置控制寄存器的SMBus位，按需配置SMBTYPE位和 ENAARP 位。

# 12.8 中断

I2C模块提供事件中断和错误中断，进入同一个中断服务程序，经查询后区分处理。

图 12-4 I2C 中断请求

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/ce1cb51db24fa77e5cb1802f78cb39b44720052dfcbe3adddf34a22f13cfed1f.jpg null)

# 12.9 包校验错误 PEC

包错误校验(PEC)是为了提供传输的可靠性而增加一项CRC8校验的步骤，使用以下多项式对每一位串行数据进行计算： $0 = x ^ { 8 } + x ^ { 2 } + x + 1$ 。

PEC计算是由控制寄存器的ENPEC位激活，对所有信息字节进行计算，包括地址和读写位在内。在发送时，启用 PEC 会在最后一字节数据之后加上一个字节的 CRC8 计算结果；而在接收模式，在最

后一字节被认为是 CRC8 校验结果，如果和内部的计算结果不符合，就会回复一个 NAK，如果是主接收器，无论校验结果正确与否，都会回复一个NAK。

# 12.10 寄存器描述

表 12-1 I2C 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R16_I2C_CTRL1</td><td>0x40004800</td><td>I2C控制寄存器1</td><td>0x0000</td></tr><tr><td>R16_I2C_CTRL2</td><td>0x40004804</td><td>I2C控制寄存器2</td><td>0x0000</td></tr><tr><td>R16_I2C_OADDR1</td><td>0x40004808</td><td>I2C地址寄存器1</td><td>0x0000</td></tr><tr><td>R16_I2C_OADDR2</td><td>0x4000480C</td><td>I2C地址寄存器2</td><td>0x0000</td></tr><tr><td>R16_I2C_DATAR</td><td>0x40004810</td><td>I2C数据寄存器</td><td>0x0000</td></tr><tr><td>R16_I2C_STAR1</td><td>0x40004814</td><td>I2C状态寄存器1</td><td>0x0000</td></tr><tr><td>R16_I2C_STAR2</td><td>0x40004818</td><td>I2C状态寄存器2</td><td>0x0000</td></tr><tr><td>R16_I2C_CKCFGR</td><td>0x4000481C</td><td>I2C时钟寄存器</td><td>0x0000</td></tr><tr><td>R16_I2C_RTR</td><td>0x40004820</td><td>I2C上升时间寄存器</td><td>0x0002</td></tr></table>

I2C 控制寄存器（R16\_I2C\_CTRL1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_I2C_SWRST</td><td>RW</td><td>软件重置,用户代码置此位会使I2C外设重置。在复位前确定I2C总线的引脚被释放,总线处于空闲状态。注:该位可以在总线上没有检测到停止条件但是busy位为1时,重置I2C模块。</td><td>0</td></tr><tr><td>14</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>13</td><td>RB_I2C_ALERT</td><td>RW</td><td>SMBus提醒位,用户代码可以设置此位或者清除此位;当PE置位后,此位可以被硬件清除。1:驱动SMBusALERT引脚使其变低,响应地址头应紧跟在ACK信号后面;0:释放SMBusALERT引脚使其变高,响应地址头应紧跟在NACK信号后面。</td><td>0</td></tr><tr><td>12</td><td>RB_I2C_PEC</td><td>RW</td><td>数据包出错检测使能位,置此位启用数据包出错检测。用户代码可以对此位置位或清零;当PEC被传输后,或产生开始或结束信号,或者PE位清0时,硬件清零该位;1:带PEC;0:不带PEC。注:仲裁丢失时,PEC失效。</td><td>0</td></tr><tr><td>11</td><td>RB_I2C_POS</td><td>RW</td><td>ACK和PEC位置设置位,该位可以被用户代码置位或者清零,在PE被清零后,可以被硬件清除;1:ACK位控制在移位寄存器里接收的下一个字节的ACK或者NAK。PEC移位寄存器里接收的下一字节是PEC;0:ACK位控制当前移位寄存器内正在接受的字节的ACK或者NAK。PEC位表明当位前移位寄存器的字节是PEC。注:POS位在2字节数据接收中的用法如下:必须在接收之前配置好。为了NACK第2个字节,必须在清除ADDR位后立刻清除ACK位;为了检</td><td>0</td></tr><tr><td></td><td></td><td></td><td>测第二个字节的 PEC,必须在 ADDR 事件发生后,配置 POS 位后设置 PEC 位。</td><td></td></tr><tr><td>10</td><td>RB_I2C_ACK</td><td>RW</td><td>应答使能位,该位可以被用户代码置位或者清零,当 PE 位被置位时,该位可以被硬件清除;1: 在接收到一个字节后返回一个应答;0: 不设应答。</td><td>0</td></tr><tr><td>9</td><td>RB_I2C_STOP</td><td>RW</td><td>停止事件产生位,该位可以被用户代码置位或清零,或当检测到停止事件时,由硬件清除,或检测到超时错误时,由硬件将其置位。主模式下:1: 在当前字节传输或者当前起始条件发出后产生停止事件;0: 无停止事件产生。从模式下:1: 在当前字节传输后释放 SCL 和 SDA 线;0: 无停止事件产生。</td><td>0</td></tr><tr><td>8</td><td>RB_I2C_START</td><td>RW</td><td>起始事件产生位,该位可以被用户代码置位或者清零,当起始条件发出后或者 PE 被清零时,由硬件清零。主模式下:1: 重复产生起始事件;0: 无起始事件产生。从模式下:1: 当总线空闲时,产生起始事件;0: 无起始事件产生。</td><td>0</td></tr><tr><td>7</td><td>RB_I2C_NOSTRETCH</td><td>RW</td><td>禁止时钟延长位,此位用于在 ADDB 或 BTF 标志被置位的情况下,禁止从模式下的时钟延长,直至被软件清零。1: 禁止时钟延长;0: 允许时钟延长。</td><td>0</td></tr><tr><td>6</td><td>RB_I2C_ENGC</td><td>RW</td><td>广播呼叫使能位,置此位使能广播呼叫,应答广播地址 00h。</td><td>0</td></tr><tr><td>5</td><td>RB_I2C_ENPEC</td><td>RW</td><td>PEC 使能位,置此位开启 PEC 计算。</td><td>0</td></tr><tr><td>4</td><td>RB_I2C_ENARP</td><td>RW</td><td>ARP 使能位,置此位使能 ARP。如果 SMBTYPE=0,则使用 SMBus 设备的默认地址;如果 SMBTYPE=1,则使用 SMBus 的主地址。</td><td>0</td></tr><tr><td>3</td><td>RB_I2C_SMBTYPE</td><td>RW</td><td>SMBus 设备类型,置 1 为 SMBus 主设备,置 0 为SMBus 从设备。</td><td>0</td></tr><tr><td>2</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>1</td><td>RB_I2C_SMBUS</td><td>RW</td><td>SMBus 模式选择位,置 1 为使用 SMBus 模式,置 0 为使用 I2C 模式。</td><td>0</td></tr><tr><td>0</td><td>RB_I2C_PE</td><td>RW</td><td>I2C 外设使能位。1: 启用 I2C 模块;0: 禁用 I2C 模块。</td><td>0</td></tr></table>

I2C 控制寄存器 2（R16\_I2C\_CTRL2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>00000b</td></tr><tr><td>10</td><td>RB_I2C_ITBUFEN</td><td>RW</td><td>缓冲器中断使能位。</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:当TxE或者RxEN被置位时,产生事件中断;0:当TxE或者RxEN被置位时,不产生中断。</td><td></td></tr><tr><td>9</td><td>RB_I2C ITEVTEN</td><td>RW</td><td>事件中断使能位,置此位使能事件中断。在下列条件下,将产生此中断:SB=1(主模式);ADDR=1(主从模式);ADDR10=1(主模式);STOPF=1(从模式);BTF=1,但是没有TxE或者RxEN事件;如果ITBUFEN=1,TxE事件为1;如果ITBUFEN=1,RxNE事件为1。</td><td>0</td></tr><tr><td>8</td><td>RB_I2C_ITERREN</td><td>RW</td><td>出错中断使能位,置位表示允许出错中断。在下列条件下,将产生该中断;BERR=1;ARLO=1;AF=1;OVR=1;PECERR=1;TIMEOUT=1;SMBAlert=1。</td><td>0</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>[5:0]</td><td>RB_I2C_FREQ</td><td>RW</td><td>I2C模块时钟频率域,必须输入正确的时钟频率以产生正确的时序,允许的范围在2~36MHz之间。必须设置在000010b到100100b之间,单位为MHz。建议:标准模式下,输入时钟最低为2MHz;快速模式下,输入时钟最低为4MHz。</td><td>000000b</td></tr></table>

I2C 地址寄存器 1（R16\_I2C\_OADDR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_I2C_ADDMODE</td><td>RW</td><td>地址模式。
1: 10位从机地址（不响应7位地址);
0: 7位从机地址（不响应10位地址）。</td><td>0</td></tr><tr><td>[14:10]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>00000b</td></tr><tr><td>[9:8]</td><td>RB_I2C_ADD9_8</td><td>RW</td><td>总线地址,在使用10位地址时为第9-8位,在使用7位地址时忽略。</td><td>00b</td></tr><tr><td>[7:1]</td><td>RB_I2C_ADD7_1</td><td>RW</td><td>总线地址,第7-1位。</td><td>0000000b</td></tr><tr><td>0</td><td>RB_I2C_ADDO</td><td>RW</td><td>总线地址,使用10位地址时为第0位,在使用7位地址时忽略。</td><td>0</td></tr></table>

I2C 地址寄存器 2（R16\_I2C\_OADDR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>00h</td></tr><tr><td>[7:1]</td><td>RB_I2C_ADD2</td><td>RW</td><td>总线地址，双地址模式下地址的7-1位。</td><td>00h</td></tr><tr><td>0</td><td>RB_I2C_ENDUAL</td><td>RW</td><td>双地址模式使能位，置此位可以让ADD2也能被识别。</td><td>0</td></tr></table>

I2C 数据寄存器（R16\_I2C\_DATAR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>00h</td></tr><tr><td>[7:0]</td><td>RB_I2C_DATAR</td><td>RW</td><td>数据寄存器,用来存放接收到的数据或者存放用于发送到总线的数据。</td><td>00h</td></tr></table>

I2C 状态寄存器 1（R16\_I2C\_STAR1）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_I2C_SMBALERT</td><td>RWO</td><td>SMBus警示位,该位可以由用户写0复位,或在PE变低时由硬件复位。在SMBus主机模式下:1:产生了SMBus警示;0:无SMBus警示。在SMBus从机模式下:1:收到SMBAlert响应地址头序列直到SMBAlert变低;0:没有收到SMBAlert响应地址头序列。</td><td>0</td></tr><tr><td>14</td><td>RB_I2C_TIMEOUT</td><td>RWO</td><td>超时或者Tlow错误标志位,该位可以由用户写0复位,或在PE变低时由硬件复位。1:SCL处于低已达到25mS,或者主机低电平累计时钟扩招时间超过10mS,或者从设备低电平累计时间超过25mS;0:无超时错误。注:在从模式下此位被置位,从设备会复位通讯,硬件会释放总线;在主模式下此位被置位,硬件会发出停止条件。</td><td>0</td></tr><tr><td>13</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>12</td><td>RB_I2C_PECERR</td><td>RWO</td><td>在接收时发生PEC错误标志位,该位可以由用户写0复位,或在PE变低时由硬件复位。1:有PEC错误,接收到PEC后,返回NAK;0:无PEC错误。</td><td>0</td></tr><tr><td>11</td><td>RB_I2C_OVR</td><td>RWO</td><td>过载、欠载标志位。1:有过载、欠载事件发生:当NOSTRETCH=1时,在接收模式中收到一个新的字节时,数据寄存器里的内容还未被读出,则新接收的字节将丢失;在发送模式时,没有新的数据写入数据寄存器,同样的字节将被发送两次;0:无过载、欠载事件。</td><td>0</td></tr><tr><td>10</td><td>RB_I2C_AF</td><td>RWO</td><td>应答失败标志位,该位可以由用户写0复位,或在PE变低时由硬件复位。1:应答错误;0:应答正常。</td><td>0</td></tr><tr><td>9</td><td>RB_I2C_ARLO</td><td>RWO</td><td>仲裁丢失标志位,该位可以由用户写0复位,或在PE变低时由硬件复位。1:检测到仲裁丢失,模块失去对总线的控制;0:仲裁正常。</td><td>0</td></tr><tr><td>8</td><td>RB_I2C_BERR</td><td>RWO</td><td>总线出错标志位,该位可以由用户写0复位,或在PE变低时由硬件复位。1:起始或者停止条件出错;0:正常。</td><td>0</td></tr><tr><td>7</td><td>RB_I2C_TxE</td><td>R0</td><td>数据寄存器为空标志位,向数据寄存器写数据可以清除,或者产生一个起始或者停止位后,或当PE为0后,由硬件自动清除。1:发送数据时,发送数据寄存器为空;0:数据寄存器非空。</td><td>0</td></tr><tr><td>6</td><td>RB_I2C_RxNE</td><td>RO</td><td>数据寄存器非空标志位,对数据寄存器的读写操作将清除此位,或者当PE为0后,由硬件清除此位。1:接收数据时,数据寄存器不为空;0:正常。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_I2C_STOPF</td><td>RO</td><td>停止事件标志位,用户读取状态寄存器1之后,对控制寄存器1的写操作将会清除该位,或者当PE为0后,由硬件清除此位。1:在应答之后,从设备在总线上检测到停止事件;0:没有检测到停止事件。</td><td>0</td></tr><tr><td>3</td><td>RB_I2C_ADD10</td><td>RO</td><td>10位地址头序列发送标志位,用户读取状态寄存器1之后,对控制寄存器1的写操作将会清除该位,或者当PE为0后,由硬件清除此位。1:在10位地址模式下,主设备已经将第一个地址字节发送出去;0:无。</td><td>0</td></tr><tr><td>2</td><td>RB_I2C_BTF</td><td>RO</td><td>字节发送结束标志位,用户读取状态寄存器1后,对数据寄存器的读写将清除此位;在传输中,发起一个起始或者停止事件后,或当PE为0后,由硬件清除此位。1:字节发送结束。当NOSTRETCH=0时:发送时,当一个新数据被发送且数据寄存器还未被写入新数据;接收时,当接收一个新的字节但是数据寄存器还未被读取;0:无。</td><td>0</td></tr><tr><td>1</td><td>RB_I2C_ADDR</td><td>RWO</td><td>地址被发送/地址匹配标志位,用户读取状态寄存器1后,对状态寄存器2的读操作将会清除此位,或当PE为0时,由硬件清除此位。主模式:1:地址发送结束:在10位地址模式下,当收到地址的第二个字节的ACK后改为被置位;在7位地址模式下,当收到地址的ACK后被置位;0:地址发送没有结束。从模式:1:收到的地址匹配;0:地址不匹配或者没有收到地址。</td><td>0</td></tr><tr><td>0</td><td>RB_I2C_SB</td><td>RO</td><td>起始位发送标志位,读取状态寄存器1后写数据寄存器的操作将清除该位,或当PE为0时,硬件将会清除此位。1:已发送起始位;0:未发送起始位。</td><td>0</td></tr></table>

I2C 状态寄存器 2（R16\_I2C\_STAR2）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>RB_I2C_PEC</td><td>RO</td><td>包错误检查域，当 PEC 使能时（ENPEC 置位），此域存放 PEC 的值。</td><td>00h</td></tr><tr><td>7</td><td>RB_I2C DualF</td><td>RO</td><td>匹配检测标志位，在产生停止位或起始位时，或</td><td>0</td></tr><tr><td></td><td></td><td></td><td>者在PE=0时,硬件会将该位清零。1:接收到的地址与OADDR2中的内容相符;0:接收到的地址与OADDR1中的内容相符。</td><td></td></tr><tr><td>6</td><td>RB_I2C_SMBHOST</td><td>RO</td><td>SMBus主机头标志位,在产生停止位或起始位时,或者在PE=0时,硬件会将该位清零。1:当SMBTYPE=1且ENARP=1时,收到了SMBus主机地址;0:未接收到SMBus主机地址。</td><td>0</td></tr><tr><td>5</td><td>RB_I2C_SMBDEFAULT</td><td>RO</td><td>SMBus设备默认地址标志位,在产生停止位或起始位时,或者在PE=0时,硬件会将该位清零。1:当ENARP=1,收到SMBus设备的默认地址;0:未收到地址。</td><td>0</td></tr><tr><td>4</td><td>RB_I2C_GENCALL</td><td>RO</td><td>广播呼叫地址标志位,在产生停止位或起始位时,或者在PE=0时,硬件会将该位清零。1:当ENG=1时,收到广播呼叫的地址;0:未收到广播呼叫地址。</td><td>0</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_I2C_TRA</td><td>RO</td><td>发送/接收标志位,在检测到停止事件(STOPF=1),重复的起始条件或者总线仲裁丢失(ARLO=1)或者PE=0时,硬件会将其清零。1:数据已发送;0:接收了数据。该位根据地址字节的R/W位来决定。</td><td>0</td></tr><tr><td>1</td><td>RB_I2C_BUSY</td><td>RO</td><td>总线忙标志位,该位在检测到一个停止位时会被清零。在接口被禁用时(PE=0),该信息仍被更新。1:总线忙:SDA或SCL存在低电平;0:总线空闲无通讯。</td><td>0</td></tr><tr><td>0</td><td>RB_I2C_MSL</td><td>RO</td><td>主从模式指示位,当接口处于主模式时(SB=1),硬件将该位置位;当总线检测到一个停止位,仲裁丢失时,或者PE=0时,硬件会清除该位。</td><td>0</td></tr></table>

I2C 时钟寄存器（R16\_I2C\_CKCFGR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_I2C_F_S</td><td>RW</td><td>主模式选择位。1: 快速模式;0: 标准模式。</td><td>0</td></tr><tr><td>14</td><td>RB_I2C_DUTY</td><td>RW</td><td>快速模式时的时钟高电平时间的占空比。1: 36%;0: 33.3%。</td><td>0</td></tr><tr><td>[13:12]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>00b</td></tr><tr><td>[11:0]</td><td>RB_I2C_CCR</td><td>RW</td><td>时钟分频系数域,决定SCL时钟的频率波形。在I2C标准模式下或SMBus模式下:Thigh = CCR * THCLKTlow = CCR * THCLK在I2C快速模式下:如果DUTY = 0:Thigh = CCR * THCLK</td><td>000h</td></tr><tr><td></td><td></td><td></td><td>Tlow=2*CCR*THCLK
如果DUTY=1:(速度达到400kHz)
THigh=9*CCR*THCLK
Tlow=16*CCR*THCLK
例:在标准模式下,产生100kHz的SCL频率:
CCR=FREQR/(2*100KHz), FREQR=52MHz时,
THCLK=1/52MHz, 则CCR=52MHz/(2*100KHz)=260, CCR写入0x104。</td><td></td></tr></table>

I2C 上升时间寄存器（R16\_I2C\_RTR）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>000h</td></tr><tr><td>[5:0]</td><td>RB_I2C_TRISE</td><td>RW</td><td>最大上升时间域。这个位设置主模式的SCL的上升时间。最大的上升沿时间等于TRISE-1个时钟周期。此位只能在PE清零下设置。</td><td>000010b</td></tr></table>

# 12.11 I2C 时序

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/2921b8ba47a75140d9027c8341dd8ae513efa9f8b7999b0ad122948676787f21.jpg null)

<table><tr><td>名称</td><td>参数说明 (TA=25°C, V1033=3.3V)</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>TSSTA</td><td>SDA 下降沿之前 SCL 高电平的建立时间</td><td>0.4</td><td></td><td></td><td>uS</td></tr><tr><td>THSTA</td><td>SDA 下降沿之后 SCL 高电平的保持时间</td><td>0.4</td><td></td><td></td><td>uS</td></tr><tr><td>TSDA</td><td>SCL 上升沿之前 SDA 数据的建立时间</td><td>0.05</td><td></td><td></td><td>uS</td></tr><tr><td>THDA</td><td>SCL 上升沿之后 SDA 数据的保持时间</td><td>&gt;TCHIG</td><td></td><td></td><td>uS</td></tr><tr><td>TSSTO</td><td>SDA 上升沿之前 SCL 高电平的建立时间</td><td>0.4</td><td></td><td></td><td>uS</td></tr><tr><td>THSTO</td><td>SDA 上升沿之后 SCL 高电平的保持时间</td><td>0.8</td><td></td><td></td><td>uS</td></tr><tr><td>TCLOW</td><td>SCL 时钟的低电平时间</td><td>0.6</td><td></td><td></td><td>uS</td></tr><tr><td>TCHIG</td><td>SCL 时钟的高电平时间</td><td>0.5</td><td></td><td></td><td>uS</td></tr><tr><td>TAA</td><td>SCL 下降沿到 SDA 输出有效</td><td>0.006</td><td></td><td>0.4</td><td>uS</td></tr><tr><td>TDH</td><td>SCL 下降沿之后 SDA 输出保持时间</td><td>0.006</td><td></td><td></td><td>uS</td></tr><tr><td>TR</td><td>SCL 或 SDA 输入上升沿时间</td><td></td><td></td><td>0.2</td><td>uS</td></tr></table>

# 第 13 章 段式 LCD

# 13.1 段式 LCD 简介

CH585 和 CH584 提供了段式 LCD 控制器接口，可支持 112 个点（ $^ { 2 8 ^ { \* 4 } }$ ）LCD 面板。支持 3.3V 和2.5V 驱动电压，扫描频率可调，支持 1/2duty、1/3duty、1/4duty 和 1/3bias、1/2bias 规格 LCD。

# 13.2 寄存器描述

表 13-1 LCD 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_LCD_CMD</td><td>0x40006000</td><td>LCD命令寄存器</td><td>0x00</td></tr><tr><td>R32_LCD_RAMO</td><td>0x40006004</td><td>LCD RAMO寄存器</td><td>0x00000000</td></tr><tr><td>R32_LCD_RAM1</td><td>0x40006008</td><td>LCD RAM1寄存器</td><td>0x00000000</td></tr><tr><td>R32_LCD_RAM2</td><td>0x4000600C</td><td>LCD RAM2寄存器</td><td>0x00000000</td></tr><tr><td>R32_LCD_RAM3</td><td>0x40006010</td><td>LCD RAM3寄存器</td><td>0x00000000</td></tr><tr><td>R32_LCD_SEG_EN</td><td>0x40006014</td><td>LCD段使能寄存器</td><td>0x00000000</td></tr></table>

LCD 命令寄存器(R8\_LCD\_CMD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_VLCD_SEL</td><td>RW</td><td>LCD驱动电压选择。1:2.5V;0:3.3V。</td><td>0</td></tr><tr><td>[6:5]</td><td>RB.scan_CLK_SEL</td><td>RW</td><td>扫描时钟选择:00:256Hz;01:512Hz;10:1KHz;11:128Hz。</td><td>0</td></tr><tr><td>[4:3]</td><td>RB_LCD_DUTY</td><td>RW</td><td>LCD占空比选择:00:1/2;01:1/3;10:1/4;11:无效。</td><td>0</td></tr><tr><td>2</td><td>RB_LCD_BIAS</td><td>RW</td><td>偏压比选择:1:1/3;0:1/2。</td><td>0</td></tr><tr><td>1</td><td>RB_LCD_ON</td><td>RW</td><td>LCD开关:1:开启;0:关闭。</td><td>0</td></tr><tr><td>0</td><td>RB_SYS_EN</td><td>RW</td><td>系统使能:1:开启;0:关闭。</td><td>0</td></tr></table>

LCD RAM0 寄存器(R32\_LCD\_RAM0)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>RB_LCD_SEGX(X=0-7)</td><td>RW</td><td>SEGO-SEG7段的数据,每段4位。</td><td>0</td></tr></table>

LCD RAM1 寄存器(R32\_LCD\_RAM1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>RB_LCD_SEGX(X=8-15)</td><td>RW</td><td>SEG8-SEG15段的数据，每段4位。</td><td>0</td></tr></table>

LCD RAM2 寄存器(R32\_LCD\_RAM2)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>RB_LCD_SEGX (X=16-23)</td><td>RW</td><td>SEG16-SEG23 段的数据，每段 4 位。</td><td>0</td></tr></table>

LCD RAM3 寄存器(R32\_LCD\_RAM3)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:0]</td><td>RB_LCD_SEGX (X=24-27)</td><td>RW</td><td>SEG24-SEG27段的数据，每段4位。</td><td>0</td></tr></table>

LCD 段使能寄存器(R32\_LCD\_SEG\_EN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:28]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[27:0]</td><td>RB_LCD_SEG_EN</td><td>RW</td><td>SEG27-SEGO段的使能，高电平有效。</td><td>0</td></tr></table>

# 13.3 段式 LCD 配置

(1)、选择并打开 32KHz 时钟源；

(2)、设置将要用到的 LCD 驱动管脚为仅模拟输入并配置为浮空态，必选，设置 R32\_PIN\_IN\_DIS 和R16\_PIN\_CONFIG 相对应的位。注意，外部复位 RST 复用了 LCD 驱动管脚 SEG2，如果要使用 SEG2，则要取消外部复位功能；

(3)、向 LCD 数据寄存器 R32\_LCD\_RAM0/1/2/3 加载要显示的段码数据；

(4)、配置 R8\_LCD\_CMD，设置驱动电压、扫描频率、bias、duty 等参数，并将 LCD\_ON 和寄存器R32\_LCD\_SEG\_EN 中的 RB\_LCD\_SEG\_EN 置位，开启段式 LCD 驱动；

(5)、可以随时更新 LCD 数据寄存器中的数据，改变显示内容。

# 第 14 章 独立看门狗（IWDG）

# 14.1 IWDG 简介

独立看门狗（IWDG）由专用的内部低速时钟（LSI）驱动。

# 14.2 寄存器描述

表14-1 独立看门狗相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R32_IWDG_KR</td><td>0x40001000</td><td>看门狗键寄存器</td><td>0xXXXXXXXXX</td></tr><tr><td>R32_IWDG_CFG</td><td>0x40001004</td><td>看门狗配置寄存器</td><td>0x4FFFXFFF</td></tr></table>

看门狗键寄存器(R32\_IWDG\_KR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:16]</td><td>Reserved</td><td>W0</td><td>保留。</td><td>XXXXh</td></tr><tr><td>[15:0]</td><td>IWDG_KR</td><td>W0</td><td>KEY[15:0]:键值(只写寄存器,读出值为0x0000);软件必须以一定的间隔写入0xFFFF,重装载计数值,否则,当计数器为0时,看门狗会产生复位,写入0x5555表示解除保护。写入0xFFFF,启动看门狗工作(若选择了硬件看门狗则不受此命令字限制)</td><td>XXXXh</td></tr></table>

看门狗配置寄存器(R32\_IWDG\_CFG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>31</td><td>IWDG_EN</td><td>R0</td><td>看门狗启动标志位:1:开启;0:关闭。</td><td>0</td></tr><tr><td>30</td><td>WR_PROTECT</td><td>R0</td><td>写保护标志位:1:开启保护,开启后操作受保护字段不生效;0:解除保护。</td><td>1</td></tr><tr><td>29</td><td>STOP_EN</td><td>RW</td><td>看门狗停止使能(受保护):1:开启停止开关;0:关闭停止开关。注:仅调试模式有效。</td><td>0</td></tr><tr><td>28</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[27:16]</td><td>COUNT</td><td>R0</td><td>看门狗递减计数器。</td><td>FFFh</td></tr><tr><td>15</td><td>PVU</td><td>R0</td><td>看门狗配置寄存器更新标志位(受保护):1:寄存器有更新;0:寄存器无更新。</td><td>X</td></tr><tr><td>[14:12]</td><td>PR</td><td>RW</td><td>预分频因子(受保护):000:4分频;001:8分频;010:16分频;011:32分频;100:64分频;101:128分频;110:256分频;111:512分频。</td><td>000b</td></tr><tr><td>[11:0]</td><td>RLR</td><td>RW</td><td>RL[11:0]:看门狗计数器重装载(受保护);用于定义看门狗计数器的重装载值,每当向</td><td>FFFh</td></tr><tr><td></td><td></td><td></td><td>IWDG_KR 寄存器写入 0xFFFF 时,重装载值会被传送到计数器中。随后计数器从这个值开始递减计数。看门狗超时周期可通过此重装载值和时钟预分频值来计算。</td><td></td></tr></table>

注：标注受保护的位，在R32\_IWDG\_CFG 寄存器中的WR\_PROTECT标志位为1时，读/写操作不生效。必须先向IWDG\_KR寄存器中写入Ox5555，此时R32\_IWDG\_CFG寄存器中的WR\_PROTECT位为0，才能对这些位进行读/写操作。

# 第 15 章 模数转换器 ADC

# 15.1 ADC 简介

CH585和CH584芯片提供一个12位逐次逼近型模拟数字转换器ADC，提供多达17个通道，支持通道扫描（SCAN）功能，支持14个外部信号源和3个内部信号源。

# 15.1.1 主要特性

# 12位分辨率

14个外部电压采样通道、内部的温度检测通道、内部的电池电压检测通道、内部的NFC能量检测通道

$\bullet$ 单端输入模式和差分输入模式检测

$\bullet$ 采样时钟频率可选

 ADC 输入电压范围 0V～VIO33

$\bullet$ 可选PGA，提供增益调节选择

$\bullet$ 可选输入缓冲器BUF，支持高阻信号源

$\bullet$ 支持 DMA 和定时间隔自动连续 ADC 采样，间隔可调

支持通道扫描功能，可配置扫描的顺序、扫描通道的数量，并提供扫描结束中断

# 15.1.2 功能描述

下图为一个ADC模块的框图。

图 15-1 ADC 结构图

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/9441541edc01c05504ddfe92774087e5002a6733d32f9d02d039baa7d1252cca.jpg null)

# 15.2 寄存器描述

表 15-1 ADC 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_ADC_CHANNEL</td><td>0x40001058</td><td>ADC输入通道选择寄存器</td><td>0x10</td></tr><tr><td>R8_ADC_CFG</td><td>0x40001059</td><td>ADC配置寄存器</td><td>0xA0</td></tr><tr><td>R8_ADC_CONVERT</td><td>0x4000105A</td><td>ADC转换控制寄存器</td><td>0x00</td></tr><tr><td>R8_TEM_SENSOR</td><td>0x4000105B</td><td>温度传感器控制寄存器</td><td>0x00</td></tr><tr><td>R16_ADC_DATA</td><td>0x4000105C</td><td>ADC数据寄存器</td><td>0x0XXX</td></tr><tr><td>R8_ADC_INT_FLAG</td><td>0x4000105E</td><td>ADC中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_ADC_CTRL_DMA</td><td>0x40001061</td><td>DMA和中断控制寄存器</td><td>0x00</td></tr><tr><td>R8_ADC_DMA_IF</td><td>0x40001062</td><td>ADC和DMA中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_ADC_AUTO_CYCLE</td><td>0x40001063</td><td>连续ADC定时周期寄存器</td><td>0xXX</td></tr><tr><td>R32_ADC_DMA NOW</td><td>0x40001064</td><td>DMA当前缓冲区地址</td><td>0x000XXXXX</td></tr><tr><td>R32_ADC_DMA_BEG</td><td>0x40001068</td><td>DMA起始缓冲区地址</td><td>0x000XXXXX</td></tr><tr><td>R32_ADC_DMA_END</td><td>0x4000106C</td><td>DMA结束缓冲区地址</td><td>0x000XXXXX</td></tr><tr><td>R32_ADC.scan_CFG1</td><td>0x40001070</td><td>扫描配置寄存器1</td><td>0xFFFFFFF</td></tr><tr><td>R32_ADC.scan_CFG2</td><td>0x40001074</td><td>扫描配置寄存器2</td><td>0x000FFFF</td></tr></table>

ADC 输入通道选择寄存器(R8\_ADC\_CHANNEL)

PGA 增益计算公式说明：ΔV \* A + Vref = 2 \* Vref \* ADC / 4096。

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[4:0]</td><td>RB_ADC_CH_INX</td><td>RW</td><td>ADC通道索引号,共17个通道:00h~0Dh:外部信号通道A0~A13;0Eh:电池电压VBAT;0Fh:内置温度传感器TS。10h:NFC能量检测通道。</td><td>10000b</td></tr></table>

ADC 配置寄存器(R8\_ADC\_CFG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB_ADC_CLK_DIV</td><td>RW</td><td>ADC时钟频率选择:当R16_CLK_SYS_CFG[9] = 1时:00:保留;01:基于CK32M的4分频,8MHz;10:基于CK32M的6分频,5.33MHz;11:基于CK32M的8分频,4MHz。当R16_CLK_SYS_CFG[9] = 0时:00:基于CK16M的2分频,8MHz;01:基于CK16M的4分频,4MHz;10:基于CK16M的6分频,2.67MHz;11:基于CK16M的8分频,2MHz。注:ADC时钟频率最高支持8MHz。</td><td>10</td></tr><tr><td>[5:4]</td><td>RB_ADC_PGA_GAIN[1:0]</td><td>RW</td><td>ADC的输入PGA增益选择:结合寄存器R8_ADC_CONVERT中的位RB_ADC_PGA_GAIN[2]使用。当RB_ADC_PGA_GAIN[2]=0时:00:-12dB,1/4倍;01:-6dB,1/2倍;10:0dB,1倍,无增益;11:6dB,2倍。当RB_ADC_PGA_GAIN[2]=1时:00:6dB,2倍;01:12dB,4倍;10:18dB,8倍;11:24dB,16倍。</td><td>10</td></tr><tr><td>3</td><td>RB_ADC_OFS_TEST</td><td>RW</td><td>ADC偏移误差测试模式:1:测试/校准模式,测试模式下数据寄存器R16_ADC_DATA低12位数据将按位取反(0x0573反为0x0A8C);0:正常模式。</td><td>0</td></tr><tr><td>2</td><td>RB_ADC_DIFF_EN</td><td>RW</td><td>ADC通道信号输入模式:1:差分输入;0:单端输入。</td><td>0</td></tr><tr><td>1</td><td>RB_ADCBUF_EN</td><td>RW</td><td>ADC输入缓冲器BUF使能:1:开启;0:关闭。</td><td>0</td></tr><tr><td>0</td><td>RB_ADC_POWER_ON</td><td>RW</td><td>ADC模块电源使能控制:1:使能;0:关闭。</td><td>0</td></tr></table>

ΔV：ADC模块输入的电压。

单端模式下 $\Delta \mathsf { V } = \mathsf { \Gamma } ( \mathsf { V } \mathsf { I } \mathsf { N } \mathrm { \~ \texttt \~ { \~ - \~ } \~ } \mathsf { V } \mathsf { r } \mathsf { e } \mathsf { f } )$ ，其中 VIN 就是被测电压。

差分模式下 $\Delta V = \mathrm { ( V I N p \mathrm { \~ - \~ } V I N n ) }$ ，其中 VINp 和 VINn 为差分输入的两个电压。

ADC模块输入电压参数为 $\forall \ \* \ \mathsf { A }$ ，需要满足：– Vref ≤ V \* A ≤ + Vref。

A：增益系数，参考表15-2和表15-3中“PGA增益选择”。

ADC：ADC 转换后的数字量，即 R16\_ADC\_DATA。

Vref：内部模拟电路的电源节点VINTA的实际电压值，通常为 $1 . 0 5 \mathsf { V } \pm 0 . 0 1 5 \mathsf { V } .$ 。

表15-2 PGA增益选择与输入电压范围表（单端输入模式）

<table><tr><td>PGA 增益选择</td><td>由 ADC 转换后的数据计算被采样的电压 Vi</td><td>理论可测电压上限</td><td>测量电压范围(假定 Vref=1.05V)</td><td>高精度测量电压范围</td></tr><tr><td>-12dB (1/4 倍)</td><td>(ADC/512-3)*Vref</td><td>5*Vref</td><td>-0.2V~VI033+0.2V</td><td>2.9V~VI033</td></tr><tr><td>-6dB (1/2 倍)</td><td>(ADC/1024-1)*Vref</td><td>3*Vref</td><td>-0.2V~3.15V</td><td>1.9V~3V</td></tr><tr><td>0dB (1 倍)</td><td>(ADC/2048)*Vref</td><td>2*Vref</td><td>0V~2.1V</td><td>0V~2V</td></tr><tr><td>6dB (2 倍)</td><td>(ADC/4096+0.5)*Vref</td><td>1.5*Vref</td><td>0.525V~1.575V</td><td>0.6V~1.5V</td></tr><tr><td>12dB (4 倍)</td><td>(ADC/8192+0.75)*Vref</td><td>1.25*Vref</td><td>0.788V~1.31V</td><td>0.8V~1.28V</td></tr><tr><td>18dB (8 倍)</td><td>(ADC/16384+0.875)*Vref</td><td>1.125*Vref</td><td>0.919V~1.18V</td><td>0.93V~1.15V</td></tr><tr><td>24dB (16 倍)</td><td>(ADC/32768+0.9375)*Vref</td><td>1.0625*Vref</td><td>0.984V~1.1156V</td><td>0.99V~1.11V</td></tr></table>

表15-3 PGA增益选择与输入电压范围表（差分输入模式（VINn=0V， $\vee 1 N p \geqslant 0 V$ 为例））

<table><tr><td>PGA 增益选择</td><td>VINn</td><td>由 ADC 转换后的数据计算被采样的电压VINp</td><td>理论可测电压上限</td><td>测量电压范围(假定 Vref=1.05V)</td><td>高精度测量电压范围</td></tr><tr><td>-12dB (1/4 倍)</td><td>0V</td><td>(ADC/512-4)*Vref</td><td>4*Vref</td><td>0V~VI033+0.2V</td><td>0V~VI033</td></tr><tr><td>-6dB (1/2 倍)</td><td>0V</td><td>(ADC/1024-2)*Vref</td><td>2*Vref</td><td>0V~2.1V</td><td>0V~2V</td></tr><tr><td>0dB (1 倍)</td><td>0V</td><td>(ADC/2048-1)*Vref</td><td>1*Vref</td><td>0V~1.05V</td><td>0V~1V</td></tr><tr><td>6dB (2 倍)</td><td>0V</td><td>(ADC/4096-0.5)*Vref</td><td>0.5*Vref</td><td>0V~0.525V</td><td>0V~0.5V</td></tr><tr><td>12dB (4 倍)</td><td>0V</td><td>(ADC/8192-0.25)*Vref</td><td>0.25*Vref</td><td>0V~0.26V</td><td>0V~0.23V</td></tr><tr><td>18dB (8 倍)</td><td>0V</td><td>(ADC/16384-0.125)*Vref</td><td>0.125*Vref</td><td>0V~0.13V</td><td>0V~0.1V</td></tr><tr><td>24dB (16 倍)</td><td>0V</td><td>(ADC/32768-0.0625)*Vref</td><td>0.0625*Vref</td><td>0V~0.0656V</td><td>0V~0.06V</td></tr></table>

高增益模式在应用上建议使用差分模式，方便调节偏置电压，如：上述表 15-3 所示，可以选择VINn 接 GND，VINp 接被测信号。

说明：较低的电压如果进行负增益（信号减小）后采样，可能将会导致一段电压范围内误差大；而较高的电压如果经过正增益（信号放大）后采样，可能将会导致ADC转换值溢出，因此建议根据被测信号电压范围选择合理的增益模式。

默认建议开启输入缓冲器，只有当外部信号源内阻小于1KΩ时，才可以关闭输入缓冲器进行ADC。

当采用差分输入时，建议关闭输入缓冲器。当用于 TouchKey 检测时，必须开启输入缓冲器，且建议选择0dB增益。

ADC 转换控制寄存器(R8\_ADC\_CONVERT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_ADC_EOC_X</td><td>R0</td><td>ADC转换结束标志(异步信号):1:完成;0:进行中。</td><td>0</td></tr><tr><td>6</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[5:4]</td><td>RB_ADC_SAMPLE_TIME</td><td>RW</td><td>ADC采样周期选择:00:4*Tadc;01:5*Tadc;10:6*Tadc;11:7*Tadc;</td><td>0</td></tr><tr><td>[3:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>1</td><td>RB_ADC_PGA_GAIN[2]</td><td>RW</td><td>ADC的输入PGA增益选择:结合寄存器R8_ADC_CFG中的位RB_ADC_PGA_GAIN[1:0]使用。注:使用TS时,该位必须为0,即使用TS时,RB_ADC_PGA_GAIN[2:0]=011b。</td><td>0</td></tr><tr><td>0</td><td>RB_ADC_START</td><td>RW</td><td>ADC转换启动控制及状态,在非连续ADC结束时或在DMA结束时自动清零:1:开始转换/正在转换;0:停止转换。</td><td>0</td></tr></table>

温度传感器控制寄存器(R8\_TEM\_SENSOR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_TEM_SEN_PWR_ON</td><td>RW</td><td>TS温度传感器电源使能:1:使能;0:关闭。</td><td>0</td></tr><tr><td>[6:0]</td><td>Reserved</td><td>RW</td><td>保留。</td><td>0</td></tr></table>

ADC 数据寄存器(R16\_ADC\_DATA)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:12]</td><td>Reserved</td><td>RW</td><td>保留。</td><td>0000</td></tr><tr><td>[11:0]</td><td>RB_ADC_DATA</td><td>RO</td><td>ADC转换后的数据。</td><td>XXXh</td></tr></table>

ADC 中断标志寄存器(R8\_ADC\_INT\_FLAG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_ADC_IF_EOC</td><td>R0</td><td>ADC转换完成标志。对寄存器R8_ADC_CONVERT或R8_TKEY_CONVERT进行写操作可清零此标志。</td><td>0</td></tr><tr><td>[6:0]</td><td>Reserved</td><td>RW</td><td>保留。</td><td>0000000</td></tr></table>

DMA 和中断控制寄存器(R8\_ADC\_CTRL\_DMA)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_ADC_AUTO_EN</td><td>RW</td><td>定时间隔自动连续ADC采样使能:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:使能自动ADC;0:禁止自动ADC。</td><td></td></tr><tr><td>6</td><td>RB_ADC_CONT_EN</td><td>RW</td><td>ADC连续转换模式使能:1:使能连续ADC;0:禁止连续ADC。</td><td>0</td></tr><tr><td>5</td><td>RB.scan_AUTO_TYPE</td><td>RW</td><td>ADC SCAN模式下:1:连续触发;0:周期性触发。</td><td>0</td></tr><tr><td>4</td><td>RB_ADC_IE_EOC</td><td>RW</td><td>ADC转换完成中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>3</td><td>RB_ADC_IE_DMA_END</td><td>RW</td><td>DMA结束中断使能位:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>2</td><td>RB_ADC_DMA(loop</td><td>RW</td><td>DMA地址循环功能使能位:1:使能地址循环;0:禁止地址循环。如果使能DMA地址循环,当DMA地址增加到设置的末尾地址时,自动循环指向设置的首地址。</td><td>0</td></tr><tr><td>1</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_ADC_DMA_ENABLE</td><td>RW</td><td>DMA功能使能位:1:使能DMA;0:禁止DMA。</td><td>0</td></tr></table>

ADC 和 DMA 中断标志寄存器(R8\_ADC\_DMA\_IF)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>000</td></tr><tr><td>4</td><td>RB_ADC_IF_END_ADC</td><td>RW1Z</td><td>ADC转换完成中断标志,写1清零或DMA取走数据或对寄存器R8_ADC_CONVERT进行写操作可清零此标志:1:已完成一次ADC;0:未完成。</td><td>0</td></tr><tr><td>3</td><td>RB_ADC_IF_DMA_END</td><td>RW1Z</td><td>DMA完成标志位,写1清零:1:已完成;0:未完成。</td><td>0</td></tr><tr><td>[2:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>000</td></tr></table>

连续 ADC 定时周期寄存器(R8\_ADC\_AUTO\_CYCLE)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_ADC_AUTO_CYCLE</td><td>RW</td><td>连续ADC定时周期起始值，以16个系统时钟为单位计数，满256后重新加载。计算方法：定时=(256-R8_ADC_AUTO_CYCLE)*16*Tsys。连续TKEY定时周期起始值时，以32MHz或16MHz时钟为单位计数。计算方法：定时=R8_ADC_AUTO_CYCLE*TCK32M(或TCK16M)。</td><td>XXh</td></tr></table>

DMA 当前缓冲区地址(R32\_ADC\_DMA\_NOW)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:1]</td><td>RB_ADC_DMA NOW</td><td>R0</td><td>DMA数据缓冲区当前地址。可用于计算已转换次数，计算方法：COUNT=(ADC_DMA NOW-ADC_DMA_BEG)/2。</td><td>XXXXh</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

DMA 起始缓冲区地址(R32\_ADC\_DMA\_BEG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:1]</td><td>RB_ADC_DMA_BEG</td><td>RW</td><td>DMA数据缓冲区起始地址，地址必须2字节对齐。</td><td>XXXXh</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

DMA 结束缓冲区地址(R32\_ADC\_DMA\_END)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:1]</td><td>RB_ADC_DMA_END</td><td>RW</td><td>DMA数据缓冲区结束地址（不含），地址必须2字节对齐。</td><td>XXXXh</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

扫描配置寄存器 1(R32\_ADC\_SCAN\_CFG1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:28]</td><td>RB_ADC_scan_CH8</td><td>RW</td><td>通道8模拟输入通道选择位:0000:A0;0001:A1;0010:A2;0011:A3;0100:A4;0101:A5;0110:A6;0111:A7;1000:A8;1001:A9;1010:A10;1011:A11;1100:A12;1101:A13;1110:电池电压VBAT;1111:内置温度传感器TS。</td><td>1111</td></tr><tr><td>[27:24]</td><td>RB_ADC_scan_CH7</td><td>RW</td><td>通道7模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[23:20]</td><td>RB_ADC_scan_CH6</td><td>RW</td><td>通道6模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[19:16]</td><td>RB_ADC_scan_CH5</td><td>RW</td><td>通道5模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[15:12]</td><td>RB_ADC_scan_CH4</td><td>RW</td><td>通道4模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[11:8]</td><td>RB_ADC_scan_CH3</td><td>RW</td><td>通道3模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[7:4]</td><td>RB_ADC_scan_CH2</td><td>RW</td><td>通道2模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[3:0]</td><td>RB_ADC_scan_CH1</td><td>RW</td><td>通道1模拟输入通道选择位:同上。</td><td>1111</td></tr></table>

扫描配置寄存器 2(R32\_ADC\_SCAN\_CFG2)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>31</td><td>RB_ADC_IF.scan_END</td><td>RW1Z</td><td>扫描结束标志位,为1表示扫描结束,该位写1清零,写0无效。</td><td>0</td></tr><tr><td>30</td><td>RB_ADC_scan_MASK_DIS</td><td>RW</td><td>ADC采样通道结束后,关闭通道使能:1:禁止关闭通道;0:使能关闭通道。</td><td>0</td></tr><tr><td>29</td><td>RB_ADC_IE.scan_END</td><td>RW</td><td>扫描结束中断使能:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>28</td><td>RB_ADC_scan_SEL</td><td>RW</td><td>扫描选择:1:ADC; 0:TKEY。</td><td>0</td></tr><tr><td>[27:24]</td><td>RB_ADC_scan_NUM</td><td>RW</td><td>扫描通道数量。</td><td>0</td></tr><tr><td>[23:20]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>[19:16]</td><td>RB_ADC_scan_CH13</td><td>RW</td><td>通道13模拟输入通道选择位:0000:A0;0001:A1;0010:A2;0011:A3;0100:A4;0101:A5;0110:A6;0111:A7;1000:A8;1001:A9;1010:A10;1011:A11;1100:A12;1101:A13;1110:电池电压VBAT;1111:内置温度传感器TS。</td><td>1111</td></tr><tr><td>[15:12]</td><td>RB_ADC_scan_CH12</td><td>RW</td><td>通道12模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[11:8]</td><td>RB_ADC_scan_CH11</td><td>RW</td><td>通道11模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[7:4]</td><td>RB_ADC_scan_CH10</td><td>RW</td><td>通道10模拟输入通道选择位:同上。</td><td>1111</td></tr><tr><td>[3:0]</td><td>RB_ADC_scan_CH9</td><td>RW</td><td>通道9模拟输入通道选择位:同上。</td><td>1111</td></tr></table>

# 15.3 ADC 配置

# 15.3.1 外部通道采样

(1)、设置 R8\_ADC\_CFG 的 RB\_ADC\_POWER\_ON 为 1 开启 ADC，通过 RB\_ADC\_CLK\_DIV 选择采样频率，通过 RB\_ADC\_BUF\_EN 和 RB\_ADC\_PGA\_GAIN 启用输入缓冲器及选择信号增益，通过 RB\_ADC\_SAMPLE\_TIME选择采样周期等；

(2)、设置 R8\_ADC\_CHANNEL 寄存器，选择外部或内部信号通道；

(3)、设置 R8\_ADC\_CONVERT 寄存器，置位 RB\_ADC\_START，启动 ADC 转换；

(4)、查询等待 RB\_ADC\_START 自动清零或者等待 RB\_ADC\_IF\_EOC 置 1，表示转换完成，可以读取R16\_ADC\_DATA获取12位ADC转换数据，时间足够时建议再次转换并丢弃首次ADC数据；

(5)、重复2、3、4步骤，可以继续采样另一通道或者下一组数据。

(6)、单次ADC转换周期：

ADC 采样（4/5/6/7 个时钟） $^ +$ 切换 1 个时钟 $^ +$ 转换时间（12 个时钟） $\approx$ 17/18/19/20 个 Tadc，连续 ADC 时还要加上 1 个时间间隔，其中，Tadc = TCK32M（或 ${ \mathsf { T } } \_ { \mathtt { C K 1 6 M } } .$ ） / RB\_ADC\_CLK\_DIV。

(7)、如果使用差分输入：

使能差分，选择0#通道：实际是对A0（正端）和A2（负端）的电压进行差分转换；

使能差分，选择 1#通道：实际是对 A1（正端）和 A3（负端）的电压进行差分转换；

ADC 转换后的结果，如果数据大于 $0 \times 8 0 0$ 表示差分正端的电压高于差分负端的电压；如果数据小于 $0 \times 8 0 0$ 表示差分正端的电压低于差分负端的电压。以PGA增益选择0dB为例，可测电压范围为- $\cdot 1 . 0 5 \mathsf { V } { \sim } 1 . 0 5 \mathsf { V }$ ， $0 \times 4 0 0$ 表示差分正端的电压低于差分负端的电压约0.5个Vref。

# 15.3.2 温度传感器采样

(1)、设置 R8\_TEM\_SENSOR 寄存器的 RB\_TEM\_SEN\_PWR\_ON 为 1 开启温度传感器，设置 R8\_ADC\_CHANNEL为15，选择温度传感器信号连接到ADC输入；

(2)、设置 RB\_ADC\_POWER\_ON 为 1 开启 ADC，设置 RB\_ADC\_DIFF\_EN 为 1，设置 RB\_ADC\_CLK\_DIV，设置RB\_ADC\_BUF\_EN 为 0，设置 RB\_ADC\_PGA\_GAIN 为 011b；

(3)、设置 R8\_ADC\_CONVERT 寄存器，置位 RB\_ADC\_START 为 1，启动 ADC 转换；

(4)、查询等待 RB\_ADC\_START 自动清零或者等待 RB\_ADC\_IF\_EOC 置 1，读取 R16\_ADC\_DATA 获取 12 位ADC转换数据，精度要求较高时，建议重复3和4步骤多次，计算ADC数据的平均值；

(5)、根据电压与温度换算关系得到温度值，具体请参考评估板例子程序。

# 15.3.3 启用 DMA 自动连续 ADC

(1)、参考非DMA方式设置ADC参数和选择通道等；

(2)、设置 R8\_ADC\_AUTO\_CYCLE 选择连续 ADC 的周期；

(3)、设置寄存器 R16\_ADC\_DMA\_BEG 为存储 ADC 数据缓冲区的首地址，设置寄存器 R16\_ADC\_DMA\_END为存储 ADC 数据缓冲区的结束地址（不含），并设置 R8\_ADC\_CTRL\_DMA 的 RB\_ADC\_DMA\_ENABLE 为 1，使能 DMA 功能；

(4)、可选步骤，如果需要启用中断则设置相应的中断使能寄存器位，当 RB\_ADC\_IE\_EOC = 1 时将由RB\_ADC\_IF\_END\_ADC 触发 ADC 完成中断，当 RB\_ADC\_IE\_EOC = 0 且 RB\_ADC\_IE\_DMA\_END = 0 时将由RB\_ADC\_IF\_EOC 触发 ADC 完成中断；

(5)、将 RB\_ADC\_AUTO\_EN 置 1 以开启自动连续 ADC；

(6)、每次 ADC 完成后，RB\_ADC\_IF\_EOC 和 RB\_ADC\_IF\_END\_ADC 都会置 1，但 RB\_ADC\_IF\_END\_ADC 会在DMA取走数据时自动清零，所以，如果需要查询ADC完成状态，那么可以查询RB\_ADC\_IF\_EOC。

# 15.4 通道扫描

# 15.4.1 扫描模式

扫描模式用来扫描一组模拟通道，扫描队列中的0通道所对应的模拟输入通道由R8\_ADC\_CHANNEL寄存器的\[4:0]来选择，扫描队列中的 $\mathsf { 1 } \sim \mathsf { 1 3 }$ 通道所对应的模拟输入通道则由 R32\_ADC\_SCAN\_CFG1 和R32\_ADC\_SCAN\_CFG2 寄存器来配置。

扫描通道模式可以通过设置 R32\_ADC\_SCAN\_CFG2 寄存器的 RB\_ADC\_SCAN\_NUM 位、RB\_ADC\_SCAN\_SEL位和 RB\_ADC\_SCAN\_MASK\_DIS 位来设置，如果 RB\_ADC\_SCAN\_NUM 不等于 0，则会对输入的模拟通道按照配置的顺序依次扫描；通过 RB\_ADC\_SCAN\_SEL 位来选择扫描的是 TKEY 还是 ADC；此外还可通过RB\_ADC\_SCAN\_MASK\_DIS 位控制：在每一次通道扫描中，ADC 采样结束后是否立刻关闭该通道。当RB\_SCAN\_MASK\_DIS位置1表示在每次通道扫描中，ADC采样结束后不关闭该通道，直到进行下一个通道扫描时，再关闭上一个通道开启下一个通道，而当RB\_SCAN\_MASK\_DIS置0表示在每次通道扫描中，ADC采样结束后立刻关闭该通道，到进行下一通道扫描时，开启下一个通道，以此防止关闭上一通道的延时导致两个通道同时导通的问题。

# 15.4.2 扫描中断

在扫描模式下，如果 R32\_ADC\_SCAN\_CFG2 寄存器的 RB\_ADC\_IE\_SCAN\_END 位被置位，将使能扫描结束中断，即在扫描队列的最后一个通道转换结束时将产生中断，此时R32\_ADC\_SCAN\_CFG2寄存器的RB\_ADC\_IF\_SCAN\_END位会被硬件置1（该位需要软件清0），表明扫描队列中的所有通道转换结束。

# 第 16 章 触摸按键 TouchKey

# 16.1 TouchKey 简介

芯片提供了电容检测模式，配合 ADC 模块使用，可以实现电容类触摸按键检测功能。共 14 个输入通道，支持触摸按键电容值范围 $1 0 \mathsf { p F } { \sim } 1 0 0 \mathsf { p F }$ ，提供驱动屏蔽输出以提高灵敏度。

# 16.2 寄存器描述

表 16-1 TouchKey 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_TKEY_COUNT</td><td>0x40001054</td><td>TouchKey 充放电时间寄存器</td><td>0xXX</td></tr><tr><td>R8_TKEY_CONVERT</td><td>0x40001056</td><td>TouchKey 检测控制寄存器</td><td>0x00</td></tr><tr><td>R8_TKEY_CFG</td><td>0x40001057</td><td>TouchKey 配置寄存器</td><td>0x00</td></tr><tr><td>R32_TKEY_SEL</td><td>0x4000107C</td><td>TouchKey 选择寄存器</td><td>0x00000000</td></tr></table>

TouchKey 充放电时间寄存器(R8\_TKEY\_COUNT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>RB_TKEY_DISCH_CNT</td><td>RW</td><td>TouchKey 放电周期数，以由 RB_ADC_CLK_DIV 选择的 ADC 时钟为计数单位。计算方法：放电时间=(RB_TKEY_DISCH_CNT+1)*Tadc。</td><td>XXXb</td></tr><tr><td>[4:0]</td><td>RB_TKEY_CHARG_CNT</td><td>RW</td><td>TouchKey 充电周期数，以由 RB_ADC_CLK_DIV 选择的 ADC 时钟为计数单位。计算方法：充电时间=(RB_TKEY_CHARG_CNT+ADC 采样周期)*Tadc。</td><td>XXXXb</td></tr></table>

TouchKey 检测控制寄存器(R8\_TKEY\_CONVERT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:1]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_TKEY_START</td><td>RW</td><td>TouchKey 检测控制及状态，自动清零：
1: 开始检测/正在转换;
0: 停止转换。</td><td>0</td></tr></table>

TouchKey 配置寄存器(R8\_TKEY\_CFG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td></td></tr><tr><td>6</td><td>RB_TKEY_DMA_EN</td><td>RW</td><td>TouchKey DMA使能:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>5</td><td>RB_TKEY_AUTO_EN</td><td>RW</td><td>TouchKey自动触发使能:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>4</td><td>RB_TKEY RAND_EN</td><td>RW</td><td>TouchKey随机触发使能:1:使能; 0:关闭。</td><td>0</td></tr><tr><td>3</td><td>RB_TKEY_PGA_ADJ</td><td>RW</td><td>选择ADC中PGA的运行速度:1:高速但功耗略大;0:正常速度。</td><td>0</td></tr><tr><td>2</td><td>RB_TKEY_DRV_EN</td><td>RW</td><td>TouchKey驱动屏蔽使能:</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:使能; 0:关闭。</td><td></td></tr><tr><td>1</td><td>RB_TKEY_CURRENT</td><td>RW</td><td>TouchKey 充电电流选择: 
1:60%电流; 0:额定电流。</td><td>0</td></tr><tr><td>0</td><td>RB_TKEY_PWR_ON</td><td>RW</td><td>TouchKey 模块电源使能控制: 
1:使能; 0:关闭。</td><td>0</td></tr></table>

TouchKey 选择寄存器(R32\_TKEY\_SEL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:18]</td><td>RB_TKEY_DRV_OUTEN</td><td>RW</td><td>TouchKey 多路驱动屏蔽各通道使能,高电平有效。</td><td>0</td></tr><tr><td>[17:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr></table>

# 16.3 TouchKey 配置

请参考和调用相关子程序。

# 第 17 章 USB 全速主机/设备控制器（USBFS）

# 17.1 USB 控制器简介

CH585和CH584提供1组全速USB主从控制器及收发器，主要特性如下：

 支持 USB Host 主机功能和 USB Device 设备功能

$\bullet$ 支持 USB 2.0 全速 12Mbps 或者低速 1.5Mbps

$\bullet$ 支持 USB 控制传输、批量传输、中断传输、同步/实时传输

支持最大64字节的数据包，内置FIFO，支持中断和DMA

# 17.2 寄存器描述

USB全速控制器的基地址是0x40008000。USB相关寄存器分为3个部分，部分寄存器是在主机和设备模式下进行复用的。

（1）、USB全局寄存器

（2）、USB设备控制寄存器

（3）、USB 主机控制寄存器

# 17.2.1 全局寄存器描述

表 17-1 USB 相关寄存器列表（标灰受 RB\_UC\_RESET\_SIE 复位控制）

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_USB_CTRL</td><td>0x40008000</td><td>USB 控制寄存器</td><td>0x06</td></tr><tr><td>R8_USB_INT_EN</td><td>0x40008002</td><td>USB 中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_USB_DEV_AD</td><td>0x40008003</td><td>USB 设备地址寄存器</td><td>0x00</td></tr><tr><td>R32_USB_STATUS</td><td>0x40008004</td><td>USB 状态寄存器</td><td>0xXX20XXXX</td></tr><tr><td>R8_USB_MIS_ST</td><td>0x40008005</td><td>USB 杂项状态寄存器</td><td>0xXX</td></tr><tr><td>R8_USB_INT_PG</td><td>0x40008006</td><td>USB 中断标志寄存器</td><td>0x20</td></tr><tr><td>R8_USB_INT_ST</td><td>0x40008007</td><td>USB 中断状态寄存器</td><td>0x3X</td></tr><tr><td>R8_USB_RX_LEN</td><td>0x40008008</td><td>USB 接收长度寄存器</td><td>0xXX</td></tr></table>

USB 控制寄存器(R8\_USB\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UC_HOST_MODE</td><td>RW</td><td>USB工作模式选择位:1:主机模式(HOST);0:设备模式(DEVICE)。</td><td>0</td></tr><tr><td>6</td><td>RB_UC_LOW_SPEED</td><td>RW</td><td>USB总线信号传输速率选择位:1:1.5Mbps;0:12Mbps。</td><td>0</td></tr><tr><td>5</td><td>RB_UC_DEV_DU_EN</td><td>RW</td><td>USB设备模式下,USB设备使能和内部上拉电阻控制位,为1则使能USB设备传输并且启用内部上拉电阻。RB_UDP_DU_EN可代替此位。</td><td>0</td></tr><tr><td>[5:4]</td><td>MASK_UC_SYS_CTRL</td><td>RW</td><td>见下表配置USB系统。</td><td>0</td></tr><tr><td>3</td><td>RB_UC_INT_BUSY</td><td>RW</td><td>USB传输完成中断标志未清零前自动暂停使能位:1:在中断标志UIF_TRANSFER未清零前自动暂停,设备模式下自动应答忙NAK,主机模式下自动暂停后续传输;0:不暂停。</td><td>0</td></tr><tr><td>2</td><td>RB_UC_RESET_SIE</td><td>RW</td><td>USB 协议处理器软件复位控制位:1: 强制复位 USB 协议处理器 (SIE), 需要软件清零;0: 不复位。</td><td>1</td></tr><tr><td>1</td><td>RB_UC_CLR_ALL</td><td>RW</td><td>USB 的 FIFO 和中断标志清零:1: 强制清空和清零;0: 不清。</td><td>1</td></tr><tr><td>0</td><td>RB_UC_DMA_EN</td><td>RW</td><td>USB 的 DMA 和 DMA 中断控制位:1: 使能 DMA 功能和 DMA 中断;0: 关闭 DMA。</td><td>0</td></tr></table>

由 RB\_UC\_HOST\_MODE 和 MASK\_UC\_SYS\_CTRL 组成 USB 系统控制组合：

<table><tr><td>RB_UC_HOST_MODE</td><td>MASK_UC_SYS_CTRL</td><td>USB系统控制描述</td></tr><tr><td>0</td><td>00</td><td>禁止USB设备功能,关闭内部上拉电阻。注:如果RB_UIDPU_EN=1则强制启用DP上拉电阻。</td></tr><tr><td>0</td><td>01</td><td>使能USB设备功能,关闭内部上拉电阻,需加外部上拉。注:如果RB_UIDPU_EN=1则强制启用DP上拉电阻。</td></tr><tr><td>0</td><td>1x</td><td>使能USB设备功能,启用内部1.5K上拉电阻。该上拉电阻优先于下拉电阻,也可用于GPIO模式。</td></tr><tr><td>1</td><td>00</td><td>USB主机模式,正常工作状态。</td></tr><tr><td>1</td><td>01</td><td>USB主机模式,强制DP/DM输出SEO状态。</td></tr><tr><td>1</td><td>10</td><td>USB主机模式,强制DP/DM输出J状态。</td></tr><tr><td>1</td><td>11</td><td>USB主机模式,强制DP/DM输出K状态/唤醒。</td></tr></table>

USB 中断使能寄存器(R8\_USB\_INT\_EN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>RW</td><td>保留。</td><td>0</td></tr><tr><td>6</td><td>RB_UID_DEV_NAK</td><td>RW</td><td>USB设备模式,接收到NAK中断:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>5</td><td>RB_MOD_1_WIRE</td><td>RW</td><td>USB单线模式使能:1:开启;0:关闭。</td><td>0</td></tr><tr><td>4</td><td>RB_UID_FIFO_0V</td><td>RW</td><td>FIFO溢出中断:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>3</td><td>RB_UID_HST_SOF</td><td>RW</td><td>USB主机模式,SOF定时中断:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>2</td><td>RB_UID_SUSPEND</td><td>RW</td><td>USB总线挂起或唤醒事件中断:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>1</td><td>RB_UID_TRANSFER</td><td>RW</td><td>USB传输完成中断:1:使能中断;0:禁止中断。</td><td>0</td></tr><tr><td>0</td><td>RB_UID_DETECT</td><td>RW</td><td>USB主机模式,USB设备连接或断开事件中断:1:使能中断;</td><td>0</td></tr><tr><td rowspan="2"></td><td></td><td></td><td>0:禁止中断。</td><td></td></tr><tr><td>RB_UID_BUS_RST</td><td>RW</td><td>USB设备模式,USB总线复位事件中断:1:使能中断;0:禁止中断。</td><td>0</td></tr></table>

USB 设备地址寄存器(R8\_USB\_DEV\_AD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UDA_GP_BIT</td><td>RW</td><td>USB通用标志位，用户自定义。</td><td>0</td></tr><tr><td>[6:0]</td><td>MASK_USB_ADDR</td><td>RW</td><td>主机模式：当前操作者的USB设备地址；设备模式：该USB自身地址。</td><td>0</td></tr></table>

USB 杂项状态寄存器(R8\_USB\_MIS\_ST)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UMS_SOF_PRES</td><td>RO</td><td>USB主机模式下SOF包预示状态位:1:将要发送SOF包,此时如有其它USB数据包将被自动延后;0:无SOF包发送。</td><td>X</td></tr><tr><td>6</td><td>RB_UMS_SOF_ACT</td><td>RO</td><td>USB主机模式下SOF包传输状态位:1:正在发出SOF包;0:发送完成或者空闲。</td><td>X</td></tr><tr><td>5</td><td>RB_UMS_SIE-Free</td><td>RO</td><td>USB协议处理器的空闲状态位:1:协议器空闲;0:忙,正在进行USB传输。</td><td>1</td></tr><tr><td>4</td><td>RB_UMS_R_FIFO_RDY</td><td>RO</td><td>USB接收FIFO数据就绪状态位:1:接收FIFO非空;0:接收FIFO为空。</td><td>0</td></tr><tr><td>3</td><td>RB_UMS_BUS_RESET</td><td>RO</td><td>USB总线复位状态位:1:当前USB总线处于复位态;0:当前USB总线处于非复位态。</td><td>X</td></tr><tr><td>2</td><td>RB_UMS_SUSPEND</td><td>RO</td><td>USB挂起状态位:1:USB总线处于挂起态,有一段时间没有USB活动;0:USB总线处于非挂起态。</td><td>0</td></tr><tr><td>1</td><td>RB_UMS_DM_LEVEL</td><td>RO</td><td>USB主机模式下,设备刚连入USB端口是DM引脚的电平状态,用于判断速度:1:高电平/低速;0:低电平/全速。</td><td>0</td></tr><tr><td>0</td><td>RB_UMS_DEV_ATTACH</td><td>RO</td><td>USB主机模式下端口的USB设备连接状态位:1:端口已经连接USB设备;0:端口没有USB设备连接。</td><td>0</td></tr></table>

USB 中断标志寄存器(R8\_USB\_INT\_FG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_U_IS_NAK</td><td>R0</td><td>USB设备模式下，NAK响应状态位：1：当前USB传输过程中回应NAK；0：无NAK响应。</td><td>0</td></tr><tr><td>6</td><td>RB_U_TOG_OK</td><td>R0</td><td>当前USB传输DATAL0/1同步标志匹配状态</td><td>0</td></tr><tr><td></td><td></td><td></td><td>位:1:同步;0:不同步。</td><td></td></tr><tr><td>5</td><td>RB_U_SIE-Free</td><td>RO</td><td>USB协议处理器空闲状态位:1:USB空闲;0:忙,正在进行USB传输。</td><td>1</td></tr><tr><td>4</td><td>RB_UID_FIFO_0V</td><td>RW</td><td>USB FIFO溢出中断标志位,写1清零:1: FIFO溢出触发;0:无事件。</td><td>0</td></tr><tr><td>3</td><td>RB_UID_HST_SOF</td><td>RW</td><td>USB主机模式下SOF定时中断标志位,写1清零:1: SOF包传输完成触发;0:无事件。</td><td>0</td></tr><tr><td>2</td><td>RB_UID_SUSPEND</td><td>RW</td><td>USB总线挂起或唤醒事件中断标志位,写1清零:1: USB挂起事件或唤醒事件触发;0:无事件。</td><td>0</td></tr><tr><td>1</td><td>RB_UID_TRANSFER</td><td>RW</td><td>USB传输完成中断标志位,写1清零:1:一个USB传输完成触发;0:无事件。</td><td>0</td></tr><tr><td rowspan="2">0</td><td>RB_UID_DETECT</td><td>RW</td><td>USB主机模式下USB设备连接或断开事件中断标志位,写1清零:1:检测到USB设备连接或断开触发;0:无事件。</td><td>0</td></tr><tr><td>RB_UID_BUS_RST</td><td>RW</td><td>USB设备模式下USB总线复位事件中断标志位,写1清零:1:USB总线复位事件触发;0:无事件。</td><td>0</td></tr></table>

USB 中断状态寄存器(R8\_USB\_INT\_ST)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UID_setup_ACT</td><td>RO</td><td>USB设备模式下,该位为1表示当前已成功接收到8字节的SETUP请求包,SETUP令牌不影响RB_UID_TOG_OK和MASK_UID_TOKEN、MASK_UID_ENDP及R8_USB_RX_LEN。</td><td>0</td></tr><tr><td>6</td><td>RB_UID_TOG_OK</td><td>RO</td><td>当前USB传输DATA0/1同步标志匹配状态位,同RB_U_TOG_OK:1:同步;0:不同步。</td><td>0</td></tr><tr><td>[5:4]</td><td>MASK_UID_TOKEN</td><td>RO</td><td>设备模式下,当前USB传输事务的令牌PID标识。</td><td>11b</td></tr><tr><td rowspan="2">[3:0]</td><td>MASK_UID_ENDP</td><td>RO</td><td>设备模式下,当前USB传输事务的端点号。</td><td>XXXXb</td></tr><tr><td>MASK_UID_H_RES</td><td>RO</td><td>主机模式下,当前USB传输事务的应答PID标识,0000表示设备无应答或超时;其它值表示应答PID。</td><td>XXXXb</td></tr></table>

MASK\_UIS\_TOKEN 用于 USB 设备模式下标识当前 USB 传输事务的令牌 PID：00 表示 OUT 包；10 表示IN包；11表示空闲；01未定义。

当 MASK\_UIS\_TOKEN 非空闲、并且 RB\_UIS\_SETUP\_ACT 也为 1 时，必须先处理前者，处理完前者后

清零一次 RB\_UIF\_TRANSFER 使前者进入空闲状态，再处理后者，最后再清零一次 RB\_UIF\_TRANSFER。

MASK\_UIS\_H\_RES 仅在主机模式下有效。在主机模式下，若主机发送 OUT/SETUP 令牌包时，则该PID 是握手包 ACK/NAK/STALL，或者是设备无应答/超时。若主机发送 IN 令牌包，则该 PID 是数据包的 PID（DATA0/DATA1）或者握手包 PID。

USB 接收长度寄存器(R8\_USB\_RX\_LEN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_USB_RX_LEN</td><td>R0</td><td>当前USB端点接收的数据字节数。</td><td>XXh</td></tr></table>

# 17.2.2 设备寄存器描述

在 USB 设备模式下，芯片提供了端点 0、1、2、3、4、5、6、7 共 8 组双向端点，所有端点的最大数据包长度都是64字节。

端点0是默认端点，支持控制传输，发送和接收共用一个64字节数据缓冲区。

端点1、端点2、端点3各自包括一个发送端点IN和一个接收端点OUT，发送和接收各有一个独立的64字节或者双64字节数据缓冲区，支持批量传输、中断传输和实时/同步传输。

端点 4、端点 5、端点 6、端点 7 包括一个发送端点 IN 和一个接收端点 OUT，发送和接收各有一个独立的64字节数据缓冲区，支持批量传输、中断传输和实时/同步传输。

每 组 端 点 都 具 有 一 个 控 制 寄 存 器 R8\_UEPn\_CTRL 和 发 送 长 度 寄 存 器 R8\_UEPn\_T\_LEN（ $\scriptstyle ( { \mathsf { n } } = 0 / 1 / 2 / 3 / 4 / 5 / 6 / 7 )$ ），用于设定该端点的同步触发位、对 OUT 事务和 IN 事务的响应以及发送数据的长度等。

作为 USB 设备所必要的 USB 总线上拉电阻可以由软件随时设置是否启用，当 USB 控制寄存器R8\_USB\_CTRL 中的 RB\_UC\_DEV\_PU\_EN 置 1 时，控制器根据 RB\_UD\_LOW\_SPEED 的速度设置，在内部为 USB总线的 DP/DM 引脚连接上拉电阻，并启用 USB 设备功能。上述控制不能用于睡眠或下电模式，但R16\_PIN\_CONFIG 中的 RB\_UDP\_PU\_EN 可以不受睡眠模式的影响而强制启用 DP 引脚的上拉电阻。

当检测到USB总线复位、USB总线挂起或唤醒事件，或者当USB成功处理完数据发送或者数据接收后，USB协议处理器都将设置相应的中断标志，如果中断使能打开，还会产生相应的中断请求。应用程序可以直接查询或在 USB 中断服务程序中查询并分析中断标志寄存器 R8\_USB\_INT\_FG，根据RB\_UIF\_BUS\_RST 和 RB\_UIF\_SUSPEND 进行相应的处理；并且，如果 RB\_UIF\_TRANSFER 有效，那么还需要继续分析 USB 中断状态寄存器 R8\_USB\_INT\_ST，根据当前端点号 MASK\_UIS\_ENDP 和当前事务令牌 PID标识 MASK\_UIS\_TOKEN 进行相应的处理。如果事先设定了各个端点的 OUT 事务的同步触发位RB\_UEP\_R\_TOG，那么可以通过 RB\_U\_TOG\_OK 或者 RB\_UIS\_TOG\_OK 判断当前所接收到的数据包的同步触发位是否与该端点的同步触发位匹配，如果数据同步，则数据有效；如果数据不同步，则数据应该被丢弃。每次处理完USB发送或者接收中断后，都应该正确修改相应端点的同步触发位，用于下次所发送的数据包或者下次所接收的数据包是否同步检测；另外，设置RB\_UEP\_AUTO\_TOG可以实现在发送成功或者接收成功后自动翻转相应的同步触发位。

各个端点准备发送的数据在各自的缓冲区中，准备发送的数据长度是独立设定在R8\_UEPn\_T\_LEN中；各个端点接收到的数据在各自的缓冲区中，但是接收到的数据长度都在 USB 接收长度寄存器R8\_USB\_RX\_LEN中，可以在USB接收中断时根据当前端点号区分。

表 17-2 USB 设备相关寄存器列表（标灰受 RB\_UC\_RESET\_SIE 复位控制）

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_UDEV_CTRL</td><td>0x40008001</td><td>USB 设备物理端口控制寄存器</td><td>0x0</td></tr><tr><td>R8_UEP4_1_MOD</td><td>0x4000800c</td><td>端点 1/4 模式控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP2_3_MOD</td><td>0x4000800d</td><td>端点 2/3 模式控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP567_MOD</td><td>0x4000800e</td><td>端点 5/6/7 模式控制寄存器</td><td>0x00</td></tr><tr><td>R32_UEPO_DMA</td><td>0x40008010</td><td>端点 0 缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_UEP1_DMA</td><td>0x40008014</td><td>端点 1 缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_UEP2_DMA</td><td>0x40008018</td><td>端点 2 缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_UEP3_DMA</td><td>0x4000801c</td><td>端点 3 缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R8_UEPO_T_LEN</td><td>0x40008020</td><td>端点0发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEPO_CTRL</td><td>0x40008022</td><td>端点0控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP1_T_LEN</td><td>0x40008024</td><td>端点1发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP1_CTRL</td><td>0x40008026</td><td>端点1控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP2_T_LEN</td><td>0x40008028</td><td>端点2发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP2_CTRL</td><td>0x4000802a</td><td>端点2控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP3_T_LEN</td><td>0x4000802c</td><td>端点3发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP3_CTRL</td><td>0x4000802e</td><td>端点3控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP4_T_LEN</td><td>0x40008030</td><td>端点4发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP4_CTRL</td><td>0x40008032</td><td>端点4控制寄存器</td><td>0x00</td></tr><tr><td>R32_UEP5_DMA</td><td>0x40008054</td><td>端点5缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_UEP6_DMA</td><td>0x40008058</td><td>端点6缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_UEP7_DMA</td><td>0x4000805c</td><td>端点7缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R8_UEP5_T_LEN</td><td>0x40008064</td><td>端点5发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP5_CTRL</td><td>0x40008066</td><td>端点5控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP6_T_LEN</td><td>0x40008068</td><td>端点6发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP6_CTRL</td><td>0x4000806a</td><td>端点6控制寄存器</td><td>0x00</td></tr><tr><td>R8_UEP7_T_LEN</td><td>0x4000806c</td><td>端点7发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UEP7_CTRL</td><td>0x4000806e</td><td>端点7控制寄存器</td><td>0x00</td></tr><tr><td>R32_EPn_MODE</td><td>0x40008070</td><td>端点8-15控制寄存器</td><td>0x0000000</td></tr></table>

USB 设备物理端口控制寄存器(R8\_UDEV\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UD_PD_DIS</td><td>RW</td><td>USB 设备端口 UD+/UD-引脚内部下拉电阻控制位:1:禁用内部下拉;0:使能内部下拉。可用于 GPIO 模式提供下拉电阻。</td><td>1</td></tr><tr><td>6</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>5</td><td>RB_UD_DP_PIN</td><td>RO</td><td>当前 UD+引脚状态:1:高电平;0:低电平。</td><td>X</td></tr><tr><td>4</td><td>RB_UD_DM_PIN</td><td>RO</td><td>当前 UD-引脚状态:1:高电平;0:低电平。</td><td>X</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_UD_LOW_SPEED</td><td>RW</td><td>USB 设备物理端口低速模式使能位:1:选择 1.5Mbps 低速模式;0:选择 12Mbps 全速模式。</td><td>0</td></tr><tr><td>1</td><td>RB_UD_HUBO_RESET</td><td>RW</td><td>USB HUBO 复位控制</td><td>0</td></tr><tr><td>0</td><td>RB_UD_PORT_EN</td><td>RW</td><td>USB 设备物理端口使能位:1:使能物理端口;0:禁用物理端口。</td><td>0</td></tr></table>

端点 1/4 模式控制寄存器(R8\_UEP4\_1\_MOD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP1_RX_EN</td><td>RW</td><td>1:使能端点1接收(OUT);0:禁止端点1接收。</td><td>0</td></tr><tr><td>6</td><td>RB_UEP1_TX_EN</td><td>RW</td><td>1:使能端点1发送(IN);0:禁止端点1发送。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_UEP1BUF_MOD</td><td>RW</td><td>端点1数据缓冲区模式控制位。</td><td>0</td></tr><tr><td>3</td><td>RB_UEP4_RX_EN</td><td>RW</td><td>1:使能端点4接收(OUT);0:禁止端点4接收。</td><td>0</td></tr><tr><td>2</td><td>RB_UEP4_TX_EN</td><td>RW</td><td>1:使能端点4发送(IN);0:禁止端点4发送。</td><td>0</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>00b</td></tr></table>

bUEP4\_RX\_EN 和 bUEP4\_TX\_EN 组合配置 USB 端点 0 和 4 的数据缓冲区模式，具体参考下表：

表17-3 端点0和4缓冲区模式

<table><tr><td>bUEP4_RX_EN</td><td>bUEP4_TX_EN</td><td>描述:以UEPO_DMA为起始地址由低向高排列</td></tr><tr><td>0</td><td>0</td><td>端点0单64字节收发共用缓冲区(IN和OUT)。</td></tr><tr><td>1</td><td>0</td><td>端点0单64字节收发共用缓冲区;端点4单64字节接收缓冲区(OUT)。</td></tr><tr><td>0</td><td>1</td><td>端点0单64字节收发共用缓冲区;端点4单64字节发送缓冲区(IN)。</td></tr><tr><td>1</td><td>1</td><td>端点0单64字节收发共用缓冲区;端点4单64字节接收缓冲区(OUT);端点4单64字节接收缓冲区(IN)。总共192字节排列如下:UEPO_DMA+0地址:端点0收发共用缓冲区64字节起始地址;UEPO_DMA+64地址:端点4接收缓冲区64字节起始地址;UEPO_DMA+128地址:端点4发送缓冲区64字节起始地址。</td></tr></table>

端点 2/3 模式控制寄存器(R8\_UEP2\_3\_MOD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP3_RX_EN</td><td>RW</td><td>1:使能端点3接收(OUT);0:禁止端点3接收。</td><td>0</td></tr><tr><td>6</td><td>RB_UEP3_TX_EN</td><td>RW</td><td>1:使能端点3发送(IN);0:禁止端点3发送。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_UEP3BUF_MOD</td><td>RW</td><td>端点3数据缓冲区模式控制位。</td><td>0</td></tr><tr><td>3</td><td>RB_UEP2_RX_EN</td><td>RW</td><td>1:使能端点2接收(OUT);0:禁止端点2接收。</td><td>0</td></tr><tr><td>2</td><td>RB_UEP2_TX_EN</td><td>RW</td><td>1:使能端点2发送(IN);0:禁止端点2发送。</td><td>0</td></tr><tr><td>1</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_UEP2BUF_MOD</td><td>RW</td><td>端点2数据缓冲区模式控制位。</td><td>0</td></tr></table>

由 RB\_UEPn\_RX\_EN 和 RB\_UEPn\_TX\_EN 以及 RB\_UEPn\_BUF\_MOD（n=1/2/3）组合分别配置 USB 端点 1、2、3 的数据缓冲区模式，具体参考下表。其中，在双 64 字节缓冲区模式下，USB 数据传输时将根据RB\_UEP\__TOG=0 选择前 64 字节缓冲区，根据 RB\_UEPTOG=1 选择后 64 字节缓冲区，设置RB\_UEP\_AUTO_ $\scriptstyle { \mathrm { T O G } } = 1$ 可实现自动切换。

表 17-4 端点 n 缓冲区模式（n=1/2/3）

<table><tr><td>RB_UEPn_RX_EN</td><td>RB_UEPn_TX_EN</td><td>RB_UEPnBUF_MOD</td><td>描述:以R16_UEPn_DMA为起始地址由低向高排列</td></tr><tr><td>0</td><td>0</td><td>X</td><td>端点被禁用,未用到R16_UEPn_DMA缓冲区。</td></tr><tr><td>1</td><td>0</td><td>0</td><td>单64字节接收缓冲区(OUT)。</td></tr><tr><td>1</td><td>0</td><td>1</td><td>双64字节接收缓冲区(OUT),由RB_UEP_R_TOG选择。</td></tr><tr><td>0</td><td>1</td><td>0</td><td>单64字节发送缓冲区(IN)。</td></tr><tr><td>0</td><td>1</td><td>1</td><td>双64字节发送缓冲区(IN),由RB_UEP_T_TOG选择。</td></tr><tr><td>1</td><td>1</td><td>0</td><td>单64字节接收缓冲区(OUT),单64字节发送缓冲区(IN)。</td></tr><tr><td>1</td><td>1</td><td>1</td><td>双64字节接收缓冲区(OUT),通过RB_UEP_R_TOG选择,双64字节发送缓冲区(IN),通过RB_UEP_T_TOG选择。全部256字节排列如下:UEPn_DMA+0地址:RB_UEP_R_TOG=0时端点接收地址;UEPn_DMA+64地址:RB_UEP_R_TOG=1时端点接收地址;UEPn_DMA+128地址:RB_UEP_T_TOG=0时端点发送地址;UEPn_DMA+192地址:RB_UEP_T_TOG=1时端点发送地址。</td></tr></table>

端点 5/6/7 模式控制寄存器(R8\_UEP567\_MOD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>00b</td></tr><tr><td>5</td><td>RB_UEP7_RX_EN</td><td>RW</td><td>1:使能端点7接收(OUT);0:禁止端点7接收。</td><td>0</td></tr><tr><td>4</td><td>RB_UEP7_TX_EN</td><td>RW</td><td>1:使能端点7发送(IN);0:禁止端点7发送。</td><td>0</td></tr><tr><td>3</td><td>RB_UEP6_RX_EN</td><td>RW</td><td>1:使能端点6接收(OUT);0:禁止端点6接收。</td><td>0</td></tr><tr><td>2</td><td>RB_UEP6_TX_EN</td><td>RW</td><td>1:使能端点6发送(IN);0:禁止端点6发送。</td><td>0</td></tr><tr><td>1</td><td>RB_UEP5_RX_EN</td><td>RW</td><td>1:使能端点5接收(OUT);0:禁止端点5接收。</td><td>0</td></tr><tr><td>0</td><td>RB_UEP5_TX_EN</td><td>RW</td><td>1:使能端点5发送(IN);0:禁止端点5发送。</td><td>0</td></tr></table>

由 RB\_UEPn\_RX\_EN 和 RB\_UEPn\_TX\_EN（ $\scriptstyle \mathtt { n = 5 / 6 / 7 }$ ）组合分别配置USB端点5、6、7的数据缓冲区模式，具体参考下表。

表17-5 端点n缓冲区模式（ $\scriptstyle \mathtt { n = 5 / 6 / 7 } ,$ ）

<table><tr><td>RB_UEPn_RX_EN</td><td>RB_UEPn_TX_EN</td><td>描述:以R16_UEPn_DMA为起始地址由低向高排列</td></tr><tr><td>0</td><td>0</td><td>端点被禁用,未用到R16_UEPn_DMA缓冲区。</td></tr><tr><td>1</td><td>0</td><td>单64字节接收缓冲区(OUT)。</td></tr><tr><td>0</td><td>1</td><td>单64字节发送缓冲区(IN)。</td></tr><tr><td>1</td><td>1</td><td>单64字节接收缓冲区(OUT),单64字节发送缓冲区(IN)。</td></tr></table>

端点 n 缓冲区起始地址(R32\_UEPn\_DMA) (n=0/1/2/3/5/6/7)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:0]</td><td>R32_UEPn_DMA</td><td>RW</td><td>端点n缓冲区起始地址。
地址必须4字节对齐。</td><td>XXXXXXXXh</td></tr></table>

注：接收数据的缓冲区的长度 >=min（可能收到的最大数据包长度+2字节，64字节）。

端点 n 发送长度寄存器(R8\_UEPn\_T\_LEN) (n=0/1/3/4/5/6/7)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[6:0]</td><td>R8_UEPn_T_LEN</td><td>RW</td><td>设置USB端点n准备发送的数据字节数。</td><td>XXh</td></tr></table>

端点 2 发送长度寄存器(R8\_UEP2\_T\_LEN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>R8_UEP2_HOST_PID3</td><td>RW</td><td>主机模式下的令牌标识 PID 的 bit3。</td><td>0</td></tr><tr><td>[6:0]</td><td>R8_UEP2_T_LEN</td><td>RW</td><td>设置USB端点n准备发送的数据字节数。</td><td>XXh</td></tr></table>

端点 n 控制寄存器(R8\_UEPn\_CTRL) (n=0/1/2/3/4/5/6/7)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP_R_TOG</td><td>RW</td><td>USB端点n的接收器(处理OUT事务)期望的同步触展位:1:期望DATA1;0:期望DATABO。</td><td>0</td></tr><tr><td>6</td><td>RB_UEP_T_TOG</td><td>RW</td><td>USB端点n的发送器(处理IN事务)准备的同步触展位:1:发送DATA1;0:发送DATABO。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_UEP_AUTO_TOG</td><td>RW</td><td>同步触展位自动翻转使能控制位:1:数据发送或接收成功后自动翻转相应的同步触展位;0:不自动翻转,可以手动切换。只支持端点1/2/3/5/6/7。</td><td>0</td></tr><tr><td>[3:2]</td><td>MASK_UEP_R_RES</td><td>RW</td><td>端点n的接收器对OUT事务的响应控制:00:应答ACK;01:超时/无响应,用于非端点0的实时/同步传输;10:应答NAK或忙;11:应答STALL或错误。</td><td>00b</td></tr><tr><td>[1:0]</td><td>MASK_UEP_T_RES</td><td>RW</td><td>端点n的发送器对IN事务的响应控制:00:DATA0/DATA1数据就绪并期望ACK;01:应答DATA0/DATA1并期望无响应,用于非端点0的实时/同步传输;10:应答NAK或忙;11:应答STALL或错误。</td><td>00b</td></tr></table>

端点 n 控制寄存器(R32\_EPn\_MODE) (n=8/9/10/11/12/13/14/15)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>00h</td></tr><tr><td>[23:17]</td><td>RB_EP_T_AF</td><td>RW</td><td>1:使能端点8-15发送复用;0:禁止端点8-15发送复用。</td><td>00h</td></tr><tr><td>16</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[15:8]</td><td>RB_EP_R_EN</td><td>RW</td><td>1:使能端点8-15接收(OUT);0:禁止端点8-15接收。</td><td>00h</td></tr><tr><td>[7:0]</td><td>RB_EP_T_EN</td><td>RW</td><td>1:使能端点8-15发送(IN);0:禁止端点8-15发送。</td><td>00h</td></tr></table>

# 17.2.3 主机寄存器描述

在USB主机模式下，芯片提供了一组双向主机端点，包括一个发送端点OUT和一个接收端点IN，数据包的最大长度是64字节，支持控制传输、中断传输、批量传输和实时/同步传输。

主机端点发起的每一个USB事务，在处理结束后总是自动设置RB\_UIF\_TRANSFER中断标志。应用程序可以直接查询或在USB中断服务程序中查询并分析中断标志寄存器R8\_USB\_INT\_FG，根据各中断标志分别进行相应的处理；并且，如果RB\_UIF\_TRANSFER有效，那么还需要继续分析USB中断状态寄存器 R8\_USB\_INT\_ST，根据当前 USB 传输事务的应答 PID 标识 MASK\_UIS\_H\_RES 进行相应的处理。

如果事先设定了主机接收端点的IN事务的同步触发位RB\_UH\_R\_TOG，那么可以通过RB\_U\_TOG\_OK或者 RB\_UIS\_TOG\_OK 判断当前所接收到的数据包的同步触发位是否与主机接收端点的同步触发位匹配，如果数据同步，则数据有效；如果数据不同步，则数据应该被丢弃。每次处理完USB发送或者接收中断后，都应该正确修改相应主机端点的同步触发位，用于同步下次所发送的数据包和检测下次所接收的数据包是否同步；另外，通过设置 RB\_UH\_T\_AUTO\_TOG 和 RB\_UH\_R\_AUTO\_TOG 可以实现在发送成功或接收成功后自动翻转相应的同步触发位。

USB 主机令牌设置寄存器 R8\_UH\_EP\_PID 用于设置被操作的目标设备的端点号和本次 USB 传输事务的令牌PID包标识。SETUP令牌和OUT令牌所对应的数据由主机发送端点提供，准备发送的数据在R32\_UH\_TX\_DMA缓冲区中，准备发送的数据长度设置在R16\_UH\_TX\_LEN中；IN令牌所对应数据由目标设备返回给主机接收端点，接收到数据存放 R32\_UH\_RX\_DMA 缓冲区中，接收到的数据长度存放在R8\_USB\_RX\_LEN 中。

表 17-6 USB 主机相关寄存器列表（标灰受 RB\_UC\_RESET\_SIE 复位控制）

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_UHOST_CTRL</td><td>0x40008001</td><td>USB 主机物理端口控制寄存器</td><td>0x0</td></tr><tr><td>R8_UH_EP_MOD</td><td>0x4000800d</td><td>USB 主机端点模式控制寄存器</td><td>0x00</td></tr><tr><td>R32_UH_RX_DMA</td><td>0x40008018</td><td>USB 主机接收缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_UH_TX_DMA</td><td>0x4000801c</td><td>USB 主机发送缓冲区起始地址</td><td>0x000XXXXX</td></tr><tr><td>R8_UH_setup</td><td>0x40008026</td><td>USB 主机辅助设置寄存器</td><td>0x00</td></tr><tr><td>R8_UH_EP_PID</td><td>0x40008028</td><td>USB 主机令牌设置寄存器</td><td>0x00</td></tr><tr><td>R8_UH_RX_CTRL</td><td>0x4000802a</td><td>USB 主机接收端点控制寄存器</td><td>0x00</td></tr><tr><td>R8_UH_TX_LEN</td><td>0x4000802c</td><td>USB 主机发送长度寄存器</td><td>0xXX</td></tr><tr><td>R8_UH_TX_CTRL</td><td>0x4000802e</td><td>USB 主机发送端点控制寄存器</td><td>0x00</td></tr></table>

USB 主机物理端口控制寄存器(R8\_UHOST\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UH_PD_DIS</td><td>RW</td><td>USB 主机端口 UD+/UD-引脚内部下拉电阻控制位:1:禁用内部下拉;0:使能内部下拉。可用于 GPIO 模式提供下拉电阻。</td><td>1</td></tr><tr><td>6</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>5</td><td>RB_UH_DP_PIN</td><td>RO</td><td>当前 UD+引脚状态:1:高电平;0:低电平。</td><td>X</td></tr><tr><td>4</td><td>RB_UH_DM_PIN</td><td>RO</td><td>当前 UD-引脚状态:1:高电平;0:低电平。</td><td>X</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_UH_LOW_SPEED</td><td>RW</td><td>USB 主机端口低速模式使能位:1:选择 1.5Mbps 低速模式;0:选择 12Mbps 全速模式。</td><td>0</td></tr><tr><td>1</td><td>RB_UH_BUS_RESET</td><td>RW</td><td>USB 主机模式总线复位控制位:1:强制输出 USB 总线复位;0:结束输出。</td><td>0</td></tr><tr><td>0</td><td>RB_UH_PORT_EN</td><td>RW</td><td>USB 主机端口使能位:1:使能主机端口;0:禁用主机端口。当 USB 设备断开连接时,该为自动清 0。</td><td>0</td></tr></table>

USB 主机端点模式控制寄存器(R8\_UH\_EP\_MOD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>6</td><td>RB_UH_EP_TX_EN</td><td>RW</td><td>主机发送端点发送（SETUP/OUT）使能位：1：使能端点发送；0：禁止端点发送。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_UH_EP_TBUF_MOD</td><td>RW</td><td>主机发送端点发送数据缓冲区模式控制位。</td><td>0</td></tr><tr><td>3</td><td>RB_UH_EP_RX_EN</td><td>RW</td><td>主机接收端点接收（IN）使能位：1：使能端点接收；0：禁止端点接收。</td><td>0</td></tr><tr><td>[2:1]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>0</td><td>RB_UH_EP_RBUF_MOD</td><td>RW</td><td>USB 主机接收端点接收数据缓冲区模式控制位。</td><td>0</td></tr></table>

由 RB\_UH\_EP\_TX\_EN 和 RB\_UH\_EP\_TBUF\_MOD 组合控制主机发送端点数据缓冲区模式，参考下表。

表17-7 主机发送缓冲区模式

<table><tr><td>RB_UH_EP_TX_EN</td><td>RB_UH_EP_TBUF_MOD</td><td>描述:以R32_UH_TX_DMA为起始地址</td></tr><tr><td>0</td><td>X</td><td>端点被禁用,未用到R32_UH_TX_DMA缓冲区。</td></tr><tr><td>1</td><td>0</td><td>单64字节发送缓冲区(SETUP/OUT)。</td></tr><tr><td>1</td><td>1</td><td>双64字节发送缓冲区,通过RB_UH_T_TOG选择:当RB_UH_T_TOG=0时选择前64字节缓冲区;当RB_UH_T_TOG=1时选择后64字节缓冲区。</td></tr></table>

由 RB\_UH\_EP\_RX\_EN 和 RB\_UH\_EP\_RBUF\_MOD 组合控制主机接收端点数据缓冲区模式，参考下表。

表17-8 主机接收缓冲区模式

<table><tr><td>RB_UH_EP_RX_EN</td><td>RB_UH_EP_RBUF_MOD</td><td>结构描述:以R32_UH_TX_DMA为起始地址</td></tr><tr><td>0</td><td>X</td><td>端点被禁用,未用到R32_UH_RX_DMA缓冲区。</td></tr><tr><td>1</td><td>0</td><td>单64字节接收缓冲区(IN)。</td></tr><tr><td>1</td><td>1</td><td>双64字节接收缓冲区,通过RB_UH_R_TOG选择:当RB_UH_R_TOG=0时选择前64字节缓冲区;当RB_UH_R_TOG=1时选择后64字节缓冲区。</td></tr></table>

USB 主机接收缓冲区起始地址(R32\_UH\_RX\_DMA)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:0]</td><td>R32_UH_RX_DMA</td><td>RW</td><td>主机端点数据接收缓冲区起始地址。低15位有效，地址必须4字节对齐。</td><td>XXXXXh</td></tr></table>

USB 主机发送缓冲区起始地址(R32\_UH\_TX\_DMA)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:0]</td><td>R32_UH_TX_DMA</td><td>RW</td><td>主机端点数据发送缓冲区起始地址。低15位有效，地址必须4字节对齐。</td><td>XXXXXXXXh</td></tr></table>

USB 主机辅助设置寄存器(R8\_UH\_SETUP)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UH_PRE_PID_EN</td><td>RW</td><td>低速前导包 PRE_PID 使能位:1:使能,用于通过外部 HUB 与低速 USB设备通讯;0:禁用低速前导包。</td><td>0</td></tr><tr><td>6</td><td>RB_UH_SOF_EN</td><td>RW</td><td>自动产生 SOF 包使能位:1:主机自动产生 SOF 包;0:不自动产生,但可手工产生。</td><td>0</td></tr><tr><td>[5:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>000000b</td></tr></table>

USB 主机令牌设置寄存器(R8\_UH\_EP\_PID)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:4]</td><td>MASK_UH_TOKEN</td><td>RW</td><td>设置本次USB传输事务的令牌PID包标识。</td><td>0000b</td></tr><tr><td>[3:0]</td><td>MASK_UH_ENDP</td><td>RW</td><td>设置本次被操作的目标设备的端点号。</td><td>0000b</td></tr></table>

USB 主机接收端点控制寄存器(R8\_UH\_RX\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UH_R_TOG</td><td>RW</td><td>USB主机接收器（处理IN事务）期望的同步触发位：
1：期望DATA1；
0：期望DATABO。</td><td>0</td></tr><tr><td>[6:5]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>00b</td></tr><tr><td>4</td><td>RB_UH_R_AUTO_TOG</td><td>RW</td><td>同步触发位自动翻转使能控制位：
1：数据接收成功后自动翻转相应的期待同步触发位(RB_UH_R_TOG)；
0：不自动翻转，可以手动切换。</td><td>0</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0</td></tr><tr><td>2</td><td>RB_UH_R_RES</td><td>RW</td><td>主机接收器对IN事务的响应控制位：
1：无响应，用于非0端点的实时/同步传输；
0：应答ACK。</td><td>0</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>00b</td></tr></table>

USB 主机发送长度寄存器(R8\_UH\_TX\_LEN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_UH_TX_LEN</td><td>RW</td><td>设置USB主机发送端点准备发送的数据字节数。</td><td>XXh</td></tr></table>

USB 主机发送端点控制寄存器(R8\_UH\_TX\_CTRL)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>6</td><td>RB_UH_T_TOG</td><td>RW</td><td>USB主机发送器（处理 SETUP/OUT 事务）准备的同步触发位：1：表示发送 DATA1；0：表示发送 DATA0。</td><td>0</td></tr><tr><td>5</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>4</td><td>RB_UH_T_AUTO_TOG</td><td>RW</td><td>同步触发位自动翻转使能控制位：</td><td>0</td></tr><tr><td></td><td></td><td></td><td>1:数据发送成功后自动翻转相应的同步触发位(RB_UH_T_TOG);0:不自动翻转,可以手动切换。</td><td></td></tr><tr><td>[3:1]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>000b</td></tr><tr><td>0</td><td>RB_UH_T_RES</td><td>RW</td><td>USB主机发送器对SETUP/OUT事务的响应控制位:1:期望无响应,用于非0端点的实时/同步传输;0:期望应答ACK。</td><td>0</td></tr></table>

# 第 18 章 USB 高速主机/设备控制器（USBHS）

# 18.1 USB 高速控制器简介

CH585 内置一组高速 USB 2.0 控制器以及 480Mbps 的 USB-PHY 物理层收发器。高速 USB 2.0 控制器具有主机控制器和设备控制器双重角色，当作为主机控制器时，它可支持低速、全速和高速的USB设备。当作为设备控制器时，可以灵活设置为低速、全速或高速模式以适应各种应用。

USB高速控制器特性如下：

 支持 USB 2.0、USB 1.1、USB 1.0 协议规范

$\bullet$ 支持最大1024字节数据包，内置FIFO，支持中断和DMA

$\bullet$ 支持控制传输、批量传输、中断传输、实时/同步传输

提供总线复位、挂起、唤醒和恢复功能

# 18.2 寄存器描述

USB 高速控制器的基地址分别是 0x40009000 和 0x40009100。USB 相关寄存器分为 2 个部分：

（1）、USB高速设备控制寄存器

（2）、USB高速主机控制寄存器

# 18.2.1 设备寄存器描述

表18-1 设备相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_USB2_CTRL</td><td>0x40009000</td><td>USBHS 控制寄存器</td><td>0x07</td></tr><tr><td>R8_USB2_BASE_MODE</td><td>0x40009001</td><td>USBHS 模式控制寄存器</td><td>0x00</td></tr><tr><td>R8_USB2_INT_EN</td><td>0x40009002</td><td>USBHS 中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_USB2_DEV_AD</td><td>0x40009003</td><td>USBHS 设备地址寄存器</td><td>0x00</td></tr><tr><td>R8_USB2_WAKE_CTRL</td><td>0x40009004</td><td>USBHS 远程唤醒寄存器</td><td>0x00</td></tr><tr><td>R8_USB2_TEST_MODE</td><td>0x40009005</td><td>USBHS 测试模式寄存器</td><td>0x00</td></tr><tr><td>R16_USB2_LPM_DATA</td><td>0x40009006</td><td>USBHS 电源管理寄存器</td><td>0x8000</td></tr><tr><td>R8_USB2_INT_PG</td><td>0x40009008</td><td>USBHS 中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_USB2_INT_ST</td><td>0x40009009</td><td>USBHS 中断状态寄存器</td><td>0x00</td></tr><tr><td>R8_USB2_MIS_ST</td><td>0x4000900A</td><td>USBHS 杂项状态寄存器</td><td>0x00</td></tr><tr><td>R16_USB2_FRAME_NO</td><td>0x4000900C</td><td>USBHS 帧号寄存器</td><td>0x0000</td></tr><tr><td>R16_USB2_BUS</td><td>0x4000900E</td><td>USBHS 总线状态寄存器</td><td>0x0000</td></tr><tr><td>R16_U2EP_TX_EN</td><td>0x40009010</td><td>USBHS 端点发送使能寄存器</td><td>0x0000</td></tr><tr><td>R16_U2EP_RX_EN</td><td>0x40009012</td><td>USBHS 端点接收使能寄存器</td><td>0x0000</td></tr><tr><td>R16_U2EP_T_TOG_AUTO</td><td>0x40009014</td><td>USBHS 端点发送自动翻转使能寄存器</td><td>0x0000</td></tr><tr><td>R16_U2EP_R_TOG_AUTO</td><td>0x40009016</td><td>USBHS 端点接收自动翻转使能寄存器</td><td>0x0000</td></tr><tr><td>R8_U2EP_T_BURST</td><td>0x40009018</td><td>USBHS 端点发送突发寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP_T_BURST_MODE</td><td>0x40009019</td><td>USBHS 端点发送突发模式寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP_R_BURST</td><td>0x4000901A</td><td>USBHS 端点接收突发寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP_R_RES_MODE</td><td>0x4000901B</td><td>USBHS 端点接收到复模式寄存器</td><td>0x00</td></tr><tr><td>R32_U2EP_AF_MODE</td><td>0x4000901C</td><td>USBHS 端点复用寄存器</td><td>0x00000000</td></tr><tr><td>R32_U2EP0_DMA</td><td>0x40009020</td><td>端点0缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP1_RX_DMA</td><td>0x40009024</td><td>端点1接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP2_RX_DMA</td><td>0x40009028</td><td>端点2接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP3_RX_DMA</td><td>0x4000902C</td><td>端点3接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP4_RX_DMA</td><td>0x40009030</td><td>端点4接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP5_RX_DMA</td><td>0x40009034</td><td>端点5接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP6_RX_DMA</td><td>0x40009038</td><td>端点6接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP7_RX_DMA</td><td>0x4000903C</td><td>端点7接收缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP1_TX_DMA</td><td>0x40009040</td><td>端点1发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP2_TX_DMA</td><td>0x40009044</td><td>端点2发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP3_TX_DMA</td><td>0x40009048</td><td>端点3发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP4_TX_DMA</td><td>0x4000904C</td><td>端点4发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP5_TX_DMA</td><td>0x40009050</td><td>端点5发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP6_TX_DMA</td><td>0x40009054</td><td>端点6发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP7_TX_DMA</td><td>0x40009058</td><td>端点7发送缓冲区的起始地址寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2EP0_MAX_LEN</td><td>0x4000905C</td><td>端点0最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP1_MAX_LEN</td><td>0x40009060</td><td>端点1最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP2_MAX_LEN</td><td>0x40009064</td><td>端点2最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP3_MAX_LEN</td><td>0x40009068</td><td>端点3最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP4_MAX_LEN</td><td>0x4000906C</td><td>端点4最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP5_MAX_LEN</td><td>0x40009070</td><td>端点5最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP6_MAX_LEN</td><td>0x40009074</td><td>端点6最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R32_U2EP7_MAX_LEN</td><td>0x40009078</td><td>端点7最大长度包寄存器</td><td>0x000000XX</td></tr><tr><td>R16_U2EP0_RX_LEN</td><td>0x4000907C</td><td>端点0接收长度寄存器</td><td>0x00XX</td></tr><tr><td>R16_U2EP1_RX_LEN</td><td>0x40009080</td><td>端点1单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP1_R_SIZE</td><td>0x40009082</td><td>端点1总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP2_RX_LEN</td><td>0x40009084</td><td>端点2单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP2_R_SIZE</td><td>0x40009086</td><td>端点2总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP3_RX_LEN</td><td>0x40009088</td><td>端点3单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP3_R_SIZE</td><td>0x4000908A</td><td>端点3总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP4_RX_LEN</td><td>0x4000908C</td><td>端点4单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP4_R_SIZE</td><td>0x4000908E</td><td>端点4总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP5_RX_LEN</td><td>0x40009090</td><td>端点5单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP5_R_SIZE</td><td>0x40009092</td><td>端点5总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP6_RX_LEN</td><td>0x40009094</td><td>端点6单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP6_R_SIZE</td><td>0x40009096</td><td>端点6总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP7_RX_LEN</td><td>0x40009098</td><td>端点7单次接收长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP7_R_SIZE</td><td>0x4000909A</td><td>端点7总接收数据长度寄存器</td><td>0xxxxxx</td></tr><tr><td>R16_U2EP0_T_LEN</td><td>0x4000909C</td><td>端点0发送长度寄存器</td><td>0x00XX</td></tr><tr><td>R8_U2EP0_TX_CTRL</td><td>0x4000909E</td><td>端点0发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP0_RX_CTRL</td><td>0x4000909F</td><td>端点0接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP1_T_LEN</td><td>0x400090AO</td><td>端点1发送长度寄存器</td><td>0x000</td></tr><tr><td>R8_U2EP1_TX_CTRL</td><td>0x400090A2</td><td>端点1发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP1_RX_CTRL</td><td>0x400090A3</td><td>端点1接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP2_T_LEN</td><td>0x400090A4</td><td>端点2发送长度寄存器</td><td>0x000</td></tr><tr><td>R8_U2EP2_TX_CTRL</td><td>0x400090A6</td><td>端点2发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP2_RX_CTRL</td><td>0x400090A7</td><td>端点2接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP3_T_LEN</td><td>0x400090A8</td><td>端点3发送长度寄存器</td><td>0x000</td></tr><tr><td>R8_U2EP3_TX_CTRL</td><td>0x400090AA</td><td>端点3发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP3_RX_CTRL</td><td>0x400090AB</td><td>端点3接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP4_T_LEN</td><td>0x400090AC</td><td>端点4发送长度寄存器</td><td>0x000</td></tr><tr><td>R8_U2EP4_TX_CTRL</td><td>0x400090AE</td><td>端点4发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP4_RX_CTRL</td><td>0x400090AF</td><td>端点4接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP5_T_LEN</td><td>0x400090B0</td><td>端点5发送长度寄存器</td><td>0x0000</td></tr><tr><td>R8_U2EP5_TX_CTRL</td><td>0x400090B2</td><td>端点5发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP5_RX_CTRL</td><td>0x400090B3</td><td>端点5接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP6_T_LEN</td><td>0x400090B4</td><td>端点6发送长度寄存器</td><td>0x0000</td></tr><tr><td>R8_U2EP6_TX_CTRL</td><td>0x400090B6</td><td>端点6发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP6_RX_CTRL</td><td>0x400090B7</td><td>端点6接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP7_T_LEN</td><td>0x400090B8</td><td>端点7发送长度寄存器</td><td>0x0000</td></tr><tr><td>R8_U2EP7_TX_CTRL</td><td>0x400090BA</td><td>端点7发送控制寄存器</td><td>0x00</td></tr><tr><td>R8_U2EP7_RX_CTRL</td><td>0x400090BB</td><td>端点7接收控制寄存器</td><td>0x00</td></tr><tr><td>R16_U2EP_T_ISO</td><td>0x400090BC</td><td>USBHS端点发送同步模式使能寄存器</td><td>0x0000</td></tr><tr><td>R16_U2EP_R_ISO</td><td>0x400090BE</td><td>USBHS端点接收同步模式使能寄存器</td><td>0x0000</td></tr></table>

USBHS 控制寄存器（R8\_USB2\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UD_LPM_EN</td><td>RW</td><td>LPM使能:1:使能;0:禁止。</td><td>0x0</td></tr><tr><td>6</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UD_DEV_EN</td><td>RW</td><td>USB设备使能:1:使能;0:禁止。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UD_DMA_EN</td><td>RW</td><td>DMA传输使能:1:使能;0:禁止。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UD_PHY_SUSPENDM</td><td>RW</td><td>USB PHY挂起:1:正常工作;0:挂起。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UD_CLR_ALL</td><td>RW</td><td>清除所有中断标志:1:清空USB中断标志和FIFO,需要软件清零;0:不清空。</td><td>0x1</td></tr><tr><td>1</td><td>RB_UD_RST_SIE</td><td>RW</td><td>USB协议处理器复位:1:强制复位USB协议处理器(SIE),包括端点相关寄存器,需要软件清零;0:不复位。</td><td>0x1</td></tr><tr><td>0</td><td>RB_UD_RSTLINK</td><td>RW</td><td>LINK层复位:1:USB Link层复位;0:不复位。</td><td>0x1</td></tr></table>

USBHS 模式控制寄存器（R8\_USB2\_BASE\_MODE）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>RB_UD_SPEED_TYPE[1:0]</td><td>RW</td><td>设备期望的速度模式:00:全速设备;01:高速设备;10:低速设备;11:保留。</td><td>0x0</td></tr></table>

USBHS 中断使能寄存器（R8\_USB2\_INT\_EN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UDIE_FIFO_OVER</td><td>RW</td><td>FIFO0 溢出中断。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UDIE_LINK_RDY</td><td>RW</td><td>USB 连接中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UDIE_SOF_ACT</td><td>RW</td><td>接收 SOF 包中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UDIE_TRANSFER</td><td>RW</td><td>USB 传输结束中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UDIE_LPM_ACT</td><td>RW</td><td>LPM 传输结束中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UDIE_BUS_SLEEP</td><td>RW</td><td>USB 总线睡眠中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UDIE_SUSPEND</td><td>RW</td><td>USB 总线暂停中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UDIE_BUS_RST</td><td>RW</td><td>USB 总线复位中断使能。1:使能中断;0:禁止中断。</td><td>0x0</td></tr></table>

USBHS 设备地址寄存器（R8\_USB2\_DEV\_AD）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[6:0]</td><td>RB_UD_DEV_ADDR[6:0]</td><td>RW</td><td>USB设备地址。</td><td>0x0</td></tr></table>

USBHS 远程唤醒寄存器（R8\_USB2\_WAKE\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:1]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UDREMOTE_WKUP</td><td>RW1Z</td><td>远程唤醒,硬件自动清零。</td><td>0x0</td></tr></table>

USBHS 测试模式寄存器（R8\_USB2\_TEST\_MODE）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UD_TEST_EN</td><td>RW</td><td>测试模式使能。</td><td>0x0</td></tr><tr><td>[6:4]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UD_TEST_SEONAK</td><td>RW</td><td>测试模式,输出SEO。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UD_TEST_PKT</td><td>RW</td><td>测试模式,输出一个包。包使用端点4的数据地址以及长度,TOG为DATA0。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UD_TEST_K</td><td>RW</td><td>测试模式,输出K。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UD_TEST_J</td><td>RW</td><td>测试模式,输出J。</td><td>0x0</td></tr></table>

USBHS 电源管理寄存器（R16\_USB2\_LPM\_DATA）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>15</td><td>RB_UD_LPM_BUSY</td><td>RW</td><td>电源管理忙。</td><td>0x1</td></tr><tr><td>[14:11]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UD_LPM_DATA[10:0]</td><td>RO</td><td>电源管理数据。</td><td>0x0</td></tr></table>

USBHS 中断标志寄存器（R8\_USB2\_INT\_FG）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UDIF_FIFO_0V</td><td>RW1Z</td><td>FIFO0 溢出中断标志位,写1清零。1: FIFO0 溢出触发;0:无事件。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UDIF_LINK_RDY</td><td>RW1Z</td><td>USB 连接中断标志位,写1清零。1: USB 连接事件触发;0:无事件。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UDIF_RX_SOF</td><td>RW1Z</td><td>接收SOF包中断标志位,写1清零。1: 接收SOF包事件触发;0:无事件。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UDIF_RTX_ACT</td><td>RO</td><td>USB 传输结束中断标志位:接收由 RB_UEP_R_DONE 清除;发送由 RB_UEP_T_DONE 清除。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UDIF_LPM_ACT</td><td>RW1Z</td><td>LPM 传输结束中断标志位,写1清零。1: LPM 传输结束事件触发;0:无事件。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UDIF_BUS_SLEEP</td><td>RW1Z</td><td>USB 总线睡眠中断标志位,当启用LPM时,进入L1(Sleep)状态会触发,写1清零。1: USB 总线睡眠事件触发;0:无事件。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UDIF_SUSPEND</td><td>RW1Z</td><td>USB 总线挂起中断标志位,写1清零。1: USB 挂起事件触发;0:无事件。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UDIF_BUS_RST</td><td>RW1Z</td><td>USB 总线复位中断标志位,写1清零。1: USB 总线复位事件触发;0:无事件。</td><td>0x0</td></tr></table>

USBHS 中断状态寄存器（R8\_USB2\_INT\_ST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UDIS_EP_DIR</td><td>R0</td><td>端点数据传输方向:1:端点IN数据;0:端点OUT/SETUP数据。</td><td>0x0</td></tr><tr><td>3</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[2:0]</td><td>RB_UDIS_EP_ID_MASK[2:0]</td><td>R0</td><td>发生数据传输的端点号。</td><td>0x0</td></tr></table>

USBHS 杂项状态寄存器（R8\_USB2\_MIS\_ST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UDMS_HS_MOD</td><td>RO</td><td>主机是否为高速。</td><td>0x0</td></tr><tr><td>[6:5]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UDMS_SUSPEND_REQ</td><td>RO</td><td>USB挂起请求。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UDMS_SIE-Free</td><td>RO</td><td>USB空闲状态。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UDMS_SLEEP</td><td>RO</td><td>USB睡眠状态。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UDMS_SUSPEND</td><td>RO</td><td>USB挂起状态。
1: USB总线处于挂起态,有一段时间没有USB活动;
0: USB总线处于非挂起态。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UDMS_READY</td><td>RO</td><td>USB连接状态。</td><td>0x0</td></tr></table>

USBHS 帧号寄存器（R16\_USB2\_FRAME\_NO）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:13]</td><td>RB_UD_MFRAME_NO[2:0]</td><td>R0</td><td>接收到的微帧号。</td><td>0x0</td></tr><tr><td>[12:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UD_FRAME_NO[10:0]</td><td>R0</td><td>接收到的帧号。</td><td>0x0</td></tr></table>

USBHS 总线状态寄存器（R16\_USB2\_BUS）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>3</td><td>RB_USB_DM_ST</td><td>R0</td><td>UDM状态。</td><td>0x0</td></tr><tr><td>2</td><td>RB_USB_DP_ST</td><td>R0</td><td>UDP状态。</td><td>0x0</td></tr><tr><td>1</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>0</td><td>RB_USB_WAKEUP</td><td>R0</td><td>USB唤醒(高有效)。</td><td>0x0</td></tr></table>

USBHS 端点发送使能寄存器（R16\_U2EP\_TX\_EN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>RB_UEP_TX_EN[15:0]</td><td>RW</td><td>0~15端点发送使能:1:使能;0:禁止。</td><td>0x0</td></tr></table>

USBHS 端点接收使能寄存器（R16\_U2EP\_RX\_EN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>RB_UEP_RX_EN[15:0]</td><td>RW</td><td>0~15端点接收使能:1:使能;0:禁止。</td><td>0x0</td></tr></table>

USBHS 端点发送自动翻转使能寄存器（R16\_U2EP\_T\_TOG\_AUTO）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[7:0]</td><td>RB_UEP_T_TOG_AUTO[7:0]</td><td>RW</td><td>0~7端点同步触发位自动翻转使能:1:数据发送成功后自动翻转;0:手动控制翻转。注:端点0仅支持手动控制翻转。</td><td>0x0</td></tr></table>

USBHS 端点接收自动翻转使能寄存器（R16\_U2EP\_R\_TOG\_AUTO）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[7:0]</td><td>RB_UEP_R_TOG_AUTO[7:0]</td><td>RW</td><td>0~7端点同步触发位自动翻转使能:
1: 数据接收成功后自动翻转;
0: 手动控制翻转。
注: 端点0仅支持手动控制翻转。</td><td>0x0</td></tr></table>

USBHS 端点发送突发寄存器（R8\_U2EP\_T\_BURST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>RB_UEP_T_BURST_EN[7:0]</td><td>RW</td><td>0~7端点burst发送使能:1:使能;0:禁止。</td><td>0x0</td></tr></table>

USBHS 端点发送突发模式寄存器（R8\_U2EP\_T\_BURST\_MODE）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>RB_UEP_T_BURST_MODE[7:0]</td><td>RW</td><td>0~7端点burst发送模式:1:突发模式下不发送0长度数据;0:突发模式下发送0长度数据。</td><td>0x0</td></tr></table>

USBHS 端点接收突发寄存器（R8\_U2EP\_R\_BURST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>RB_UEP_R_BURST_EN[7:0]</td><td>RW</td><td>0~7端点burst接收使能:1:使能;0:禁止。</td><td>0x0</td></tr></table>

USBHS 端点接收回复模式寄存器（R8\_U2EP\_R\_RES\_MODE）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>RB_UEP_R_RES_MODE[7:0]</td><td>RW</td><td>0~7端点接收返回模式:1: NYET;0: ACK。</td><td>0x0</td></tr></table>

USBHS 端点复用寄存器（R32\_U2EP\_AF\_MODE）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[7:1]</td><td>RB_UEP_T_AF[6:0]</td><td>RW</td><td>1~7端点复用使能:1:复用9-15;0:复用1-7。</td><td>0x0</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr></table>

端点 0 缓冲区的起始地址寄存器（R32\_U2EP0\_DMA）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[16:0]</td><td>UEPO_DMA[16:0]</td><td>RW</td><td>端点0的缓冲区起始地址。</td><td>0xX</td></tr></table>

端点 n 接收缓冲区的起始地址寄存器（R32\_U2EPn\_RX\_DMA）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[16:0]</td><td>UEPn_RX_DMA[16:0]</td><td>RW</td><td>端点n的接收缓冲区起始地址。地址必须4字节对齐。</td><td>0xX</td></tr></table>

端点 n 发送缓冲区的起始地址寄存器（R32\_U2EPn\_TX\_DMA）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[16:0]</td><td>UEPn_TX_DMA[16:0]</td><td>RW</td><td>端点n的发送缓冲区起始地址。地址必须4字节对齐。</td><td>0xX</td></tr></table>

端点 0 最大长度包寄存器（R32\_U2EP0\_MAX\_LEN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:7]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[6:0]</td><td>UEPO_MAX_LEN[6:0]</td><td>RW</td><td>端点0 DMA可偏移的最大限制长度。</td><td>0xX</td></tr></table>

端点 n 最大长度包寄存器（R32\_U2EPn\_MAX\_LEN）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:11]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>UEPn_MAX_LEN[10:0]</td><td>RW</td><td>端点 n DMA 可偏移的最大限制长度。</td><td>0xX</td></tr></table>

端点 0 接收长度寄存器（R16\_U2EP0\_RX\_LEN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:7]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[6:0]</td><td>UEPO_RX_LEN[6:0]</td><td>RW</td><td>端点0接收数据长度。</td><td>0xX</td></tr></table>

端点 $\mathsf { n }$ 单次接收长度寄存器（R16\_U2EPn\_RX\_LEN）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>UEPn_RX_LEN[15:0]</td><td>RW</td><td>端点n单次接收数据长度。</td><td>0xX</td></tr></table>

端点 n 总接收数据长度寄存器（R16\_U2EPn\_R\_SIZE）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>UEPn_R_SIZE[15:0]</td><td>RW</td><td>端点n总接收数据长度。</td><td>0xX</td></tr></table>

端点 0 发送长度寄存器（R16\_U2EP0\_T\_LEN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:7]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[6:0]</td><td>UEPO_T_LEN[6:0]</td><td>RW</td><td>端点0发送数据长度。</td><td>0xX</td></tr></table>

端点 0 发送控制寄存器（R8\_U2EP0\_TX\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP_T_DONE</td><td>RWO</td><td>端点0发送结束标志,写0清除。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UEP_T_NAK_ACT</td><td>RWO</td><td>端点0发送NAK结束标志,写0清除。</td><td>0x0</td></tr><tr><td>[5:3]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UEP_T_TOG_MASK</td><td>RW</td><td>端点0的发送期望的同步触发位:0: DATA0;1: DATA1。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>RB_UEP_T_RES_MASK[1:0]</td><td>RW</td><td>端点0对于发送的响应控制:00: 应答NAK或忙;01: 应答STALL或错误;10: 应答ACK;</td><td>0x0</td></tr><tr><td></td><td></td><td></td><td>11: 保留。</td><td></td></tr></table>

端点 0 接收控制寄存器（R8\_U2EP0\_RX\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP_R_DONE</td><td>RWO</td><td>端点0接收结束标志,写0清除。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UEP_R_NAK_ACT</td><td>RWO</td><td>端点0接收NAK结束标志,写0清除。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UEP_R_NAK_TOG</td><td>RO</td><td>端点0对于接收的返回NAK,数据包类型:1:DATA1;0:DATA0。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UEP_R_TOG_MATCH</td><td>RO</td><td>接收的同步触发位与期望的同步触发位匹配状态:1:同步;0:不同步。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UEP_R_setup_IS</td><td>RO</td><td>端点0接收的是否为SETUP事务。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UEP_R_TOG_MASK</td><td>RW</td><td>端点0的接收期望的同步触发位:1:DATA1;0:DATA0。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>RB_UEP_R_RES_MASK[1:0]</td><td>RW</td><td>端点0对于接收的响应控制:00:应答NAK或忙;01:应答STALL或错误;10:应答ACK;11:保留。</td><td>0x0</td></tr></table>

端点 n 发送长度寄存器（R16\_U2EPn\_T\_LEN）（ $( n { = } 1 \sim 7 )$ ）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:0]</td><td>UEPn_T_LEN[15:0]</td><td>RW</td><td>端点n发送数据长度。</td><td>0x0</td></tr></table>

端点 n 发送控制寄存器（R8\_U2EPn\_TX\_CTRL）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP_T_DONE</td><td>RWO</td><td>端点n发送结束标志,写0清除。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UEP_T_NAK_ACT</td><td>RWO</td><td>端点n发送NAK结束标志,写0清除。</td><td>0x0</td></tr><tr><td>[5:4]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[3:2]</td><td>RB_UEP_T_TOG_MASK[1:0]</td><td>RW</td><td>端点n的发送期望的同步触发位:00:DATA0;01:DATA1;10:DATA2;11:MDATA。注:此位手动模式下可配置,自动模式下不可配置。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>RB_UEP_T_RES_MASK[1:0]</td><td>RW</td><td>端点n对于发送的响应控制:00:应答NAK或忙;01:应答STALL或错误;10:应答ACK;11:保留。</td><td>0x0</td></tr></table>

端点 n 接收控制寄存器（R8\_U2EPn\_RX\_CTRL）（n=1～7）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UEP_R_DONE</td><td>RWO</td><td>端点n接收结束标志,写0清除。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UEP_R_NAK_ACT</td><td>RWO</td><td>端点n接收NAK结束标志,写0清除。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UEP_R_NAK_TOG</td><td>RO</td><td>端点n对于接收的返回NAK,数据包类型:1:DATA1;0:DATA0。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UEP_R_TOG_MATCH</td><td>RO</td><td>端点n接收的同步触发位与期望的同步触发位匹配状态:1:同步;0:不同步。</td><td>0x0</td></tr><tr><td>[3:2]</td><td>RB_UEP_R_TOG_MASK[1:0]</td><td>RW</td><td>端点n的接收期望的同步触发位:00:DATA0;01:DATA1;10:DATA2;11:MDATA。注:此位手动模式下可配置,自动模式下不可配置。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>RB_UEP_R_RES_MASK[1:0]</td><td>RW</td><td>端点n对于接收的响应控制:00:应答NAK或忙;01:应答STALL或错误;10:应答ACK;11:保留。</td><td>0x0</td></tr></table>

USBHS 端点发送同步模式使能寄存器（R16\_U2EP\_T\_ISO）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[7:1]</td><td>RB_UEPn_T_ISO_EN[6:0]</td><td>RW</td><td>上传端点（IN）同步模式使能。</td><td>0x0</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr></table>

USBHS 端点接收同步模式使能寄存器（R16\_U2EP\_R\_ISO）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:8]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[7:1]</td><td>RB_UEPn_R_ISO_EN[6:0]</td><td>RW</td><td>下传端点（OUT）同步模式使能。</td><td>0x0</td></tr><tr><td>0</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr></table>

# 18.2.2 主机寄存器描述

表18-2 主机相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_U2H_CFG</td><td>0x40009100</td><td>USBHS 主机配置寄存器</td><td>0x07</td></tr><tr><td>R8_U2H_INT_EN</td><td>0x40009102</td><td>USBHS 主机中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_U2H_DEV_AD</td><td>0x40009103</td><td>USBHS 主机设备地址寄存器</td><td>0x00</td></tr><tr><td>R32_U2H_CONTROL</td><td>0x40009104</td><td>USBHS 主机控制寄存器</td><td>0x00XXXXXX</td></tr><tr><td>R8_U2H_INT_FLAG</td><td>0x40009108</td><td>USBHS 主机中断标志寄存器</td><td>0x00</td></tr><tr><td>R8_U2H_INT_ST</td><td>0x40009109</td><td>USBHS 主机中断状态寄存器</td><td>0xXX</td></tr><tr><td>R8_U2H_MIS_ST</td><td>0x4000910A</td><td>USBHS 主机杂项状态寄存器</td><td>0xXX</td></tr><tr><td>R32_U2H_LPM_DATA</td><td>0x4000910C</td><td>USBHS 主机电源管理数据寄存器</td><td>0x0000XXX</td></tr><tr><td>R32_U2H_SPLIT_DATA</td><td>0x40009110</td><td>USBHS 主机 SPLIT 数据寄存器</td><td>0x000XXXXX</td></tr><tr><td>R32_U2H_FRAME</td><td>0x40009114</td><td>USBHS 主机帧寄存器</td><td>0x00000000</td></tr><tr><td>R32_U2H_TX_LEN</td><td>0x40009118</td><td>USBHS 主机发送长度寄存器</td><td>0x00000XXX</td></tr><tr><td>R32_U2H_RX_LEN</td><td>0x4000911C</td><td>USBHS 主机接收长度寄存器</td><td>0x00000XXX</td></tr><tr><td>R32_U2H_RX_MAX_LEN</td><td>0x40009120</td><td>USBHS 主机接收最大长度寄存器</td><td>0x00000XXX</td></tr><tr><td>R32_U2H_RX_DMA</td><td>0x40009124</td><td>DMA 接收地址寄存器</td><td>0x00000XXX</td></tr><tr><td>R32_U2H_TX_DMA</td><td>0x40009128</td><td>DMA 发送地址寄存器</td><td>0x00000XXX</td></tr><tr><td>R32_U2H_PORT_CTRL</td><td>0x4000912C</td><td>USBHS 主机端口控制寄存器</td><td>0x0000X000</td></tr><tr><td>R8_U2H_PORT_CFG</td><td>0x40009130</td><td>USBHS 主机端口配置寄存器</td><td>0x00</td></tr><tr><td>R8_U2H_PORT_INT_EN</td><td>0x40009132</td><td>USBHS 主机端口中断使能寄存器</td><td>0x00</td></tr><tr><td>R8_U2H_PORT_TEST_CT</td><td>0x40009133</td><td>USBHS 主机端口测试模式寄存器</td><td>0x00</td></tr><tr><td>R16_U2H_PORT_ST</td><td>0x40009134</td><td>USBHS 主机端口状态寄存器</td><td>0x0010</td></tr><tr><td>R8_U2H_PORT_CHG</td><td>0x40009136</td><td>USBHS 主机端口状态变化寄存器</td><td>0x00</td></tr><tr><td>R32_U2H_BC_CTRL</td><td>0x4000913C</td><td>USBHS 主机 BC 充电控制寄存器</td><td>0x00000000</td></tr><tr><td>R8_USBHS_PLL_CTRL</td><td>0x40009200</td><td>USBHS PLL 时钟控制寄存器</td><td>0x00</td></tr></table>

USBHS 主机配置寄存器（R8\_U2H\_CFG）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UH_LPM_EN</td><td>RW</td><td>LPM使能。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UH FORCE_FS</td><td>RW</td><td>强制使用USB_FS。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UH_SOF_EN</td><td>RW</td><td>使能SOF包发送。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UH_DMA_EN</td><td>RW</td><td>使能DMA发送。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UH_PHY_SUSPENDM</td><td>RW</td><td>PHY挂起。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UH_CLR_ALL</td><td>RW</td><td>清除中断标志以及FIFO,需要软件清零。</td><td>0x1</td></tr><tr><td>1</td><td>RB_UH_RST_SIE</td><td>RW</td><td>USB协议处理器复位,需要软件清零。</td><td>0x1</td></tr><tr><td>0</td><td>RB_UH_RST_LINK</td><td>RW</td><td>USB连接控制模块复位。</td><td>0x1</td></tr></table>

USBHS 主机中断使能寄存器（R8\_U2H\_INT\_EN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UHIE_FIFO_OVER</td><td>RW</td><td>FIFO 溢出中断使能。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UHIE_TXhalt</td><td>RW</td><td>发送暂停中断使能。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UHIE_SOF_ACT</td><td>RW</td><td>SOF 包发送中断使能。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UHIE_TRANSFER</td><td>RW</td><td>USB 结束或传输完成中断使能。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UHIE_RESUME_ACT</td><td>RW</td><td>总线恢复中断使能。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UHIE_WKUP_ACT</td><td>RW</td><td>唤醒中断使能。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr></table>

USBHS 主机设备地址寄存器（R8\_U2H\_DEV\_AD）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[6:0]</td><td>RB_UH_DEV_ADDR[6:0]</td><td>RW</td><td>当前操作的USB设备的地址。</td><td>0x0</td></tr></table>

USBHS 主机控制寄存器（R32\_U2H\_CONTROL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:24]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>23</td><td>RB_UH_RX_NO_RES</td><td>RW</td><td>IN-DATA 无应答，用于同步传输或高速 SPLIT 包。</td><td>0xX</td></tr><tr><td>22</td><td>RB_UH_TX_NO_RES</td><td>RW</td><td>OUT/SETUP - DATA 不期望应答，用于</td><td>0xX</td></tr><tr><td></td><td></td><td></td><td>同步传输或高速SPLIT包。</td><td></td></tr><tr><td>21</td><td>RB_UH_RX_NO_DATA</td><td>RW</td><td>IN令牌包后不期望数据包,用于高速SPLIT包。</td><td>0xX</td></tr><tr><td>20</td><td>RB_UH_TX_NO_DATA</td><td>RW</td><td>OUT/SETUP 令牌包后无数据包,用于高速SPLIT包。</td><td>0xX</td></tr><tr><td>19</td><td>RB_UH_PRE_PID_EN</td><td>RW</td><td>低速前导包PRE PID使能位,当端口工作于全速,需要发送低速包(PRE)需开启此位。1:使能,用于通过外部全速HUB与低速USB设备通讯;0:禁用低速前导包。</td><td>0xX</td></tr><tr><td>18</td><td>RB_UH_SPLIT_VALID</td><td>RW</td><td>发送SPLIT包有效。</td><td>0xX</td></tr><tr><td>17</td><td>RB_UH_LPM_VALID</td><td>RW</td><td>发送LPM包有效。</td><td>0xX</td></tr><tr><td>16</td><td>RB_UH_HOST_ACTION</td><td>RW</td><td>HOST 执行事务使能,事务完成后该位自动清零。</td><td>0x0</td></tr><tr><td>[15:11]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>10</td><td>RB_UHBUF_MODE</td><td>RW</td><td>数据缓存区控制位。1:发送时使用R32_U2H_RX_DMA,接收使用R32_U2H_TX_DMA;0:发送时使用R32_U2H_TX_DMA,接收使用R32_U2H_RX_DMA。</td><td>0x0</td></tr><tr><td>[9:8]</td><td>RB_UH_T_TOG_MASK[1:0]</td><td>RW</td><td>发送的数据PID:00:PID_DATA0;01:PID_DATA1;10:PID_DATA2;11:PID_MDATA。</td><td>0xX</td></tr><tr><td>[7:4]</td><td>RB_UH_T_ENDP_MASK[3:0]</td><td>RW</td><td>主机发送的事务令牌包端点号。</td><td>0xX</td></tr><tr><td>[3:0]</td><td>RB_UH_T_TOKEN_MASK[3:0]</td><td>RW</td><td>主机发送的事务令牌包PID。</td><td>0xX</td></tr></table>

USBHS 主机中断标志寄存器（R8\_U2H\_INT\_FLAG）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UHIF_FIFO_OVER</td><td>RW1Z</td><td>FIFO 溢出中断标志。</td><td>0x0</td></tr><tr><td>6</td><td>RB_UHIF_TXhalt</td><td>RW1Z</td><td>发送中止中断标志,主机模式下用于下传中读数据溢出,或在E0F2时间点发送未结束,中止发送,写1清零。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UHIF_SOF_ACT</td><td>RW1Z</td><td>SOF 包发送完成中断标志,写1清零。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UHIF_TRANSFER</td><td>RW1Z</td><td>USB 事务传输完成中断标志,写1清零。</td><td>0x0</td></tr><tr><td>3</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UHIF_WKUP_ACT</td><td>RW1Z</td><td>唤醒中断标志,写1清零。</td><td>0x0</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr></table>

USBHS 主机中断状态寄存器（R8\_U2H\_INT\_ST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:5]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0xX</td></tr><tr><td>4</td><td>RB_UHIS_PORT_RX_RESUME</td><td>RW</td><td>该位为1表示端口接收到唤醒信号。</td><td>0xX</td></tr><tr><td>[3:0]</td><td>RB_UH_R_TOKEN_MASK
[3:0]</td><td>RO</td><td>主机接收到的PID。</td><td>0xX</td></tr></table>

USBHS 主机杂项状态寄存器（R8\_U2H\_MIS\_ST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UHMS_BUS_SEO</td><td>RO</td><td>USB总线上为SEO。</td><td>0xX</td></tr><tr><td>6</td><td>RB_UHMS_BUS_J</td><td>RO</td><td>USB总线上为J。</td><td>0xX</td></tr><tr><td>[5:4]</td><td>RB_UHMS_LINESTATE[1:0]</td><td>RO</td><td>PHY的Linestate信号。</td><td>0xX</td></tr><tr><td>3</td><td>RB_UHMS_USB_WAKEUP</td><td>RO</td><td>USB总线唤醒状态:1:正在进行总线唤醒;0:未在进行总线唤醒。</td><td>0xX</td></tr><tr><td>2</td><td>RB_UHMS_SOF_ACT</td><td>RO</td><td>USB总线SOF包传输状态位:1:正在发出SOF包;0:发送完成或空闲。</td><td>0xX</td></tr><tr><td>1</td><td>RB_UHMS_SOF_PRE</td><td>RO</td><td>USB总线SOF包预示状态为:1:将要发送SOF包;0:无SOF包发送。</td><td>0xX</td></tr><tr><td>0</td><td>RB_UHMS_SOF-Free</td><td>RO</td><td>端口使能状态:1:端口使能;0:端口未使能。</td><td>0xX</td></tr></table>

USBHS 主机电源管理数据寄存器（R32\_U2H\_LPM\_DATA）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UH_LPM_DATA[10:0]</td><td>RW</td><td>链路电源管理包数据内容。</td><td>0xX</td></tr></table>

USBHS 主机 SPLIT 数据寄存器（R32\_U2H\_SPLIT\_DATA）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:19]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[18:0]</td><td>RB_UH_SPLIT_DATA[18:0]</td><td>RW</td><td>主机端点发送 SPLIT 包的数据内容,从高位到低位依次为 ET、E、S、Port、SC、Hub Addr。</td><td>0xX</td></tr></table>

USBHS 主机帧寄存器（R32\_U2H\_FRAME）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:26]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>25</td><td>RB_UH_SOF_CNT_CLR</td><td>RW</td><td>SOF计数清零。</td><td>0x0</td></tr><tr><td>24</td><td>RB_UH_SOF_CNT_EN</td><td>RW</td><td>SOF计数使能。</td><td>0x0</td></tr><tr><td>[23:19]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>[18:16]</td><td>RB_UH_MFRAME_NO[2:0]</td><td>RO</td><td>即将发送的SOF包的微帧号。</td><td>0x0</td></tr><tr><td>[15:11]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UH_FRAME_NO[10:0]</td><td>RW</td><td>即将发送的SOF包的帧号。</td><td>0x0</td></tr></table>

USBHS 主机发送长度寄存器（R32\_U2H\_TX\_LEN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UH_TX_LEN[10:0]</td><td>RW</td><td>发送数据长度。</td><td>0xX</td></tr></table>

USBHS 主机接收长度寄存器（R32\_U2H\_RX\_LEN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UH_RX_LEN[10:0]</td><td>RW</td><td>接收数据长度。</td><td>0xX</td></tr></table>

USBHS 主机接收最大长度寄存器（R32\_U2H\_RX\_MAX\_LEN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[10:0]</td><td>RB_UH_RX_MAX_LEN[10:0]</td><td>RW</td><td>接收最大长度。</td><td>0xX</td></tr></table>

DMA 接收地址寄存器（R32\_U2H\_RX\_DMA）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[16:0]</td><td>R32_UH_RX_DMA[16:0]</td><td>RW</td><td>接收地址，低两位无效，需要4字节对齐。</td><td>0xX</td></tr></table>

DMA 发送地址寄存器（R32\_U2H\_TX\_DMA）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>[16:0]</td><td>R32_UH_TX_DMA[16:0]</td><td>RW</td><td>发送地址，低两位无效，需要4字节对齐。</td><td>0xX</td></tr></table>

USBHS 主机端口控制寄存器（R32\_U2H\_PORT\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>16</td><td>RB_UH_BUS_RST LONG</td><td>RW</td><td>总线复位时间选择:1: 18ms;0: 16ms。</td><td>0x0</td></tr><tr><td>[15:12]</td><td>RB_UH_PORT_SLEEP_BESL[3:0]</td><td>RW</td><td>唤醒时间控制:0: 125us; 8: 3ms;1: 150us; 9: 4ms;2: 200us; A: 5ms;3: 300us; B: 6ms;4: 400us; C: 7ms;5: 500us; D: 8ms;6: 1ms; E: 9ms;7: 2ms; F: 10ms。</td><td>0xX</td></tr><tr><td>[11:9]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>8</td><td>RB_UH_CLR_PORT_SLEEP</td><td>WO</td><td>PORT 退出 SLEEP 状态 (LPM)。</td><td>0x0</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UH_CLR_PORTConnect</td><td>WO</td><td>使端口进入端口状态。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UH_CLR_PORT_EN</td><td>WO</td><td>PORT 退出使能状态,进入 DISABLED状态。</td><td>0x0</td></tr><tr><td>3</td><td>RB_UH_SET_PORT_SLEEP</td><td>WO</td><td>PORT 进入 SLEEP 状态 (LPM)。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UH_CLR_PORT_SUSP</td><td>WO</td><td>PORT 退出挂起状态。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UH_SET_PORT_SUSP</td><td>WO</td><td>PORT 进入挂起状态。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UH_SET_PORT_RESET</td><td>WO</td><td>端口发送复位。</td><td>0x0</td></tr></table>

USBHS 主机端口配置寄存器（R8\_U2H\_PORT\_CFG）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>7</td><td>RB_UH_PD_EN</td><td>RW</td><td>主机模式下15K电阻下拉使能。</td><td>0x0</td></tr><tr><td>[6:1]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UH_HOST_EN</td><td>RW</td><td>USB端口模式选择：
1：端口为主机模式；
0：端口为设备模式。</td><td>0x0</td></tr></table>

USBHS 主机端口中断使能寄存器（R8\_U2H\_PORT\_INT\_EN）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UHIE_PORT_SLP</td><td>RW</td><td>端口睡眠状态变化中断使能。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UHIE_PORT_RESET</td><td>RW</td><td>端口复位状态变化中断使能。</td><td>0x0</td></tr><tr><td>3</td><td>Reserved</td><td>RO</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UHIE_PORT_SUSP</td><td>RW</td><td>端口暂停状态变化中断使能。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UHIE_PORT_EN</td><td>RW</td><td>端口使能状态变化中断使能。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UHIE_PORT_connect</td><td>RW</td><td>端口连接状态变化中断使能。</td><td>0x0</td></tr></table>

USBHS 主机端口测试模式寄存器（R8\_U2H\_PORT\_TEST\_CT）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:3]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UH_TEST FORCE_EN</td><td>RW</td><td>测试模式使能。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UH_TEST_K</td><td>RW</td><td>测试输出K。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UH_TEST_J</td><td>RW</td><td>测试输出J。</td><td>0x0</td></tr></table>

USBHS 主机端口状态寄存器（R16\_U2H\_PORT\_ST）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:12]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>11</td><td>RB_UHIS_PORT_TEST</td><td>R0</td><td>端口是否在 test 模式。</td><td>0x0</td></tr><tr><td>10</td><td>RB_UHIS_PORT_HS</td><td>R0</td><td>端口连接速度是否为高速。</td><td>0x0</td></tr><tr><td>9</td><td>RB_UHIS_PORT_LS</td><td>R0</td><td>端口连接速度是否为低速。</td><td>0</td></tr><tr><td>[8:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UHIS_PORT_SLP</td><td>R0</td><td>端口睡眠。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UHIS_PORT_RST</td><td>R0</td><td>端口复位状态。</td><td>0x1</td></tr><tr><td>3</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UHIS_PORT_SUSP</td><td>R0</td><td>端口暂停状态。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UHIS_PORT_EN</td><td>R0</td><td>端口使能。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UHIS_PORT_connect</td><td>R0</td><td>端口连接状态。</td><td>0x0</td></tr></table>

USBHS 主机端口状态变化寄存器（R8\_U2H\_PORT\_CHG）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UHIF_PORT_SLP</td><td>RW1Z</td><td>端口睡眠状态变化，写1清零。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UHIF_PORT_RESET</td><td>RW1Z</td><td>端口复位状态变化，写1清零。</td><td>0x0</td></tr><tr><td>3</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_UHIF_PORT_SUSP</td><td>RW1Z</td><td>端口暂停状态变化，写1清零。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UHIF_PORT_EN</td><td>RW1Z</td><td>端口使能状态变化，写1清零。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UHIF_PORTConnect</td><td>RW1Z</td><td>端口连接状态变化，写1清零。</td><td>0x0</td></tr></table>

USBHS 主机 BC 充电控制寄存器（R32\_U2H\_BC\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:11]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>10</td><td>RB_UDM_VSRC_ACT</td><td>R0</td><td>自动模式下,该位表示UDM输出VBC_SRC,否则由UDM_BC_CMPE控制。注:UDP高于VBC_SRC但是UDP不是高电平时该位为1,否则为0。</td><td>0x0</td></tr><tr><td>9</td><td>RB_UDM_BC_VSRC</td><td>RW</td><td>UDM引脚BC协议源电压使能:1:UDM引脚输出BC协议源电压VBC_SRC;0:禁止输出。</td><td>0x0</td></tr><tr><td>8</td><td>RB_UDP_BC_VSRC</td><td>RW</td><td>UDP引脚BC协议源电压使能:1:UDP引脚输出BC协议源电压VBC_SRC;0:禁止输出。</td><td>0x0</td></tr><tr><td>7</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>6</td><td>RB_BC_AUTO_MODE</td><td>RW</td><td>自动模式使能:1:使能;0:关闭。</td><td>0x0</td></tr><tr><td>5</td><td>RB_UDM_BC_CMPE</td><td>RW</td><td>UDM引脚BC协议比较器使能:1:使能;0:关闭。</td><td>0x0</td></tr><tr><td>4</td><td>RB_UDP_BC_CMPE</td><td>RW</td><td>UDP引脚BC协议比较器使能:1:使能;0:关闭。</td><td>0x0</td></tr><tr><td>[3:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>1</td><td>RB_UDM_BC_CMPO</td><td>R0</td><td>UDM引脚BC协议比较器状态:1:UDM引脚电压高于BC协议参考值VBC_REF;0:UDM引脚电压低于BC协议参考值VBC_REF。</td><td>0x0</td></tr><tr><td>0</td><td>RB_UDP_BC_CMPO</td><td>R0</td><td>UDP引脚BC协议比较器状态:1:UDP引脚电压高于BC协议参考值VBC_REF;0:UDP引脚电压低于BC协议参考值VBC_REF。</td><td>0x0</td></tr></table>

USBHS PLL 时钟控制寄存器（R8\_USBHS\_PLL\_CTRL）

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:3]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0x0</td></tr><tr><td>2</td><td>RB_USBHPS_PLL_EN</td><td>RW</td><td>USBHS PLL 使能。</td><td>0x0</td></tr><tr><td>1</td><td>RB_USBHPS_PLL_LOWPWR</td><td>RW</td><td>USBHS PLL 低功耗模式（只在 USBHS 应用为固定低全速时可启用，非固定低全速时不可启用）：
1：开启低功耗，电流减少约0.3mA；
0：不开启低功耗。</td><td>0x0</td></tr><tr><td>0</td><td>RB_USBHPS_PLL_CKSEL</td><td>RW</td><td>USBHS 内部参考时钟源选择：</td><td>0x0</td></tr><tr><td></td><td></td><td></td><td>1: 不经过2分频保持32M;0: 经过2分频产生16M。</td><td></td></tr></table>

# 第 19 章 无线通讯

# 19.1 简介

芯片集成低功耗 2.4-GHz 无线通讯模块，包括 RF 收发器、基带和链路控制以及天线匹配网络，支持低功耗蓝牙BLE。内部提供数百个寄存器用于调节参数和控制过程及状态，本手册不对寄存器作详细介绍，无线通讯底层操作主要以子程序库提供应用支持。

# 主要特性：

$\bullet$ 集成 2.4GHz 射频收发器、BaseBand 基带和 LLE 链路控制

$\bullet$ 支持低功耗蓝牙 BLE，符合 Bluetooth Low Energy 5.4 规范

$\bullet$ 单端 RF 接口，简化板级设计

$\bullet$ 支持 2Mbps、1Mbps

$\bullet$ 支持2.4G模式下最高8KHz上报率

$\bullet$ 接收灵敏度-95dBm\@1Mbps，-93dBm\@2Mbps

$\bullet$ 可编程-20dBm 到 $+ 4 . 5 { \mathsf { d } } { \mathsf { B } } { \mathsf { m } }$ 发送功率，支持动态调整

$\bullet$ 支持 AES-128 硬件加解密

$\bullet$ 支持 DMA

 提供优化的协议栈和应用层 API，支持组网

# 19.2 LLE 模块

LLE 模块支持自动收发模式和手动收发模式，4 组独立的硬件定时器，可控制收发数据任意一过程的时间点。

# 19.3 DMA 模块

控制器有1组DMA，有两个通道。DMA的两个通道分别用于发送数据和接收数据,在自动发送模式中，可以同时配置发送DMA的地址和接收DMA的地址，这样在帧间隔期间不需要再进行配置。

# 19.4 BB 模块

# 19.5 AES 模块

具体的应用请基于BLE协议栈库使用，并参考提供的BLE应用示例。

# 第 20 章 近场通信无线接口（NFC）

# 20.1 NFC 简介

芯片提供一个近场通信无线接口，包含了收发器和兼容 ISO14443-A 的无线解码基带，支持读卡器(PCD)模式和卡(PICC)模式。本手册不对寄存器作详细介绍，无线通讯底层操作主要以子程序库提供应用支持。

# 主要特性：

 支持 ASK(Amplitude Shift Keying)调制和 NRZ(Non-Return-to-Zero)编码

 PCD 模式支持 ISO14443-A 协议中的 106kbit/s 数据波特率

PCD模式支持对ISO14443-A类卡片的读取、写入等操作

PCD模式支持防碰撞：若多个卡片同时进入射频场，读卡器会执行防碰撞算法来识别每个卡片

 PICC 模式支持模拟 ISO14443-A 类卡片，实现数据读取和写入操作

PICC模式支持NDEF数据交互功能，支持与手机等设备智能联动：电子名片、蓝牙OOB配对

$\bullet$ 提供优化的协议栈和应用层 API

$\bullet$ 提供硬件加速的加解密算法Crypto1，适用于M1类卡片

# 第 21 章 LED 屏控制器

# 21.1 LED 屏控制器简介

芯片提供了 LED 屏控制卡接口，内置 2 个 4 字节 FIFO，支持 DMA 和中断，节约 CPU 处理时间，支持1/2/4/8路数据线接口。

# 21.2 寄存器描述

表 21-1 LED 相关寄存器列表

<table><tr><td>名称</td><td>访问地址</td><td>描述</td><td>复位值</td></tr><tr><td>R8_LED_CTRL_MOD</td><td>0x4000F000</td><td>LED 模式配置寄存器</td><td>0x00</td></tr><tr><td>R8_LED CLOCK_DIV</td><td>0x4000F001</td><td>LED 串行时钟分频寄存器</td><td>0x10</td></tr><tr><td>R8_LED_CTRL_MOD1</td><td>0x4000F002</td><td>LED 模式配置寄存器 1</td><td>0x00</td></tr><tr><td>R16_LED_STATUS</td><td>0x4000F004</td><td>LED 状态寄存器</td><td>0x00A0</td></tr><tr><td>R32_LED_FIFO</td><td>0x4000F008</td><td>LED 数据 FIFO 寄存器</td><td>0xxxxxxxxxx</td></tr><tr><td>R16_LED_DMA_LEN</td><td>0x4000F010</td><td>LED DMA 发送长度</td><td>0x0XXX</td></tr><tr><td>R16_LED_DMA_CNT</td><td>0x4000F014</td><td>LED DMA 剩余计数寄存器</td><td>0x0000</td></tr><tr><td>R32_LED_DMA_BEG</td><td>0x4000F018</td><td>LED DMA 起始地址</td><td>0x000XXXXX</td></tr><tr><td>R32_LED_DMACUR</td><td>0x4000F01C</td><td>LED DMA 当前地址</td><td>0x000XXXXX</td></tr></table>

LED 模式配置寄存器(R8\_LED\_CTRL\_MOD)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:6]</td><td>RB_LEDChan_MOD</td><td>RW</td><td>LED通道模式选择:00:LEDO,单通道输出;01:LEDO/1,双通道输出;10:LEDO~3,4通道输出;11:LEDO~7,8通道输出。</td><td>0</td></tr><tr><td>5</td><td>RB_LED_IE_FIFO</td><td>RW</td><td>FIFO计数过半中断使能:1:FIFO计数&lt;=2中断触发;0:禁止中断。</td><td>0</td></tr><tr><td>4</td><td>RB_LED_DMA_EN</td><td>RW</td><td>LED DMA功能和DMA中断使能:1:开启; 0:关闭。</td><td>0</td></tr><tr><td>3</td><td>RB_LED_OUT_EN</td><td>RW</td><td>LED信号输出使能:1:开启; 0:关闭。</td><td>0</td></tr><tr><td>2</td><td>RB_LED_OUT_POLAR</td><td>RW</td><td>LED数据输出极性控制位:1:反相,数据0输出1,数据1输出0;0:直通,数据0输出0,数据1输出1。</td><td>0</td></tr><tr><td>1</td><td>RB_LED_ALL_CLEAR</td><td>RW</td><td>LED的FIFO/计数器/中断标志清零:1:强制清空和清零;0:不清。</td><td>0</td></tr><tr><td>0</td><td>RB_LED_BIT_ORDER</td><td>RW</td><td>LED串行数据位序选择:1:低位在前;0:高位在前。</td><td>0</td></tr></table>

LED 串行时钟分频寄存器(R8\_LED\_CLOCK\_DIV)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:0]</td><td>R8_LED_CLOCK_DIV</td><td>RW</td><td>LED 输出时钟分频系数。</td><td>10h</td></tr></table>

<table><tr><td></td><td></td><td>LED频率 = Fsys / R8_LED CLOCK_DIV。</td><td></td></tr></table>

LED 模式配置寄存器 1(R8\_LED\_CTRL\_MOD1)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[7:2]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>1</td><td>RB_IE_SEND_END</td><td>RW</td><td>DMA所有数据传输结束中断使能:1:开启;0:关闭。</td><td>0</td></tr><tr><td>0</td><td>RB_LED_DMA_LOOP</td><td>RW</td><td>LED DMA数据循环使用使能:1:开启;0:关闭。</td><td>0</td></tr></table>

LED 状态寄存器(R16\_LED\_STATUS)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:10]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>9</td><td>RB_LED_IF_DMA_INT</td><td>RW1Z</td><td>DMA传输结束中断标志位:1:传输结束;0:传输未结束。</td><td>0</td></tr><tr><td>8</td><td>RB_LED_IF_DMA_END</td><td>RW1Z</td><td>DMA完成标志位,写1清零或者写R16_LED_DMA_CNT清零:1:已完成;0:未完成。</td><td>0</td></tr><tr><td>7</td><td>RB_LED_LOAD_FAIL</td><td>R0</td><td>载入数据结果:1:FIFO空;0:FIFO中有数据。</td><td>1</td></tr><tr><td>6</td><td>RB_LED_IF_FIFO</td><td>RW1Z</td><td>FIFO计数过半中断标志位,写1清零或者写R16_LED_FIFO清零:1:FIFO计数≤2;0:FIFO计数&gt;2。</td><td>0</td></tr><tr><td>5</td><td>RB_LED_CLOCK</td><td>R0</td><td>当前LED时钟信号电平状态:1:高电平;0:低电平。</td><td>1</td></tr><tr><td>4</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[3:0]</td><td>RB_LED_FIFO_COUNT</td><td>R0</td><td>当前FIFO中字节计数值,一定为偶数。</td><td>0</td></tr></table>

LED 数据 FIFO 寄存器(R32\_LED\_FIFO)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:0]</td><td>R32_LED_FIFO</td><td>W0</td><td>LED数据FIFO入口，32位写入。</td><td>XXXXXXXXh</td></tr></table>

LED DMA 发送长度寄存器(R16\_LED\_DMA\_LEN)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:12]</td><td>RESERVED</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[11:0]</td><td>R16_LED_DMA_LENGTH</td><td>W0</td><td>DMA发送计数长度。</td><td>XXXh</td></tr></table>

LED DMA 剩余计数寄存器(R16\_LED\_DMA\_CNT)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[15:12]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[11:0]</td><td>RB_LED_DMA_CNT</td><td>R0</td><td>LED_DMA_MAIN主缓冲区当前DMA剩余字(16位)计数,DMA启动后自动递减,仅低12位有效。不包括辅助缓冲区。</td><td>0</td></tr></table>

LED DMA 起始地址(R32\_LED\_DMA\_BEG)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:2]</td><td>RB_LED_DMA_BEG</td><td>RW</td><td>DMA起始地址。</td><td>XXXXh</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

LED DMA 当前地址(R32\_LED\_DMA\_CUR)

<table><tr><td>位</td><td>名称</td><td>访问</td><td>描述</td><td>复位值</td></tr><tr><td>[31:17]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr><tr><td>[16:2]</td><td>RB_LED_DMACUR</td><td>R0</td><td>DMA当前地址。</td><td>XXXXh</td></tr><tr><td>[1:0]</td><td>Reserved</td><td>R0</td><td>保留。</td><td>0</td></tr></table>

# 21.3 LED 配置

(1)、设置 R8\_LED\_CLOCK\_DIV 选择 LED 输出时钟频率；

(2)、设置 R16\_LED\_DMA\_BEG 指向准备输出数据的起始地址；

(3)、设置 R8\_LED\_CTRL\_MOD，选择通道模式、输出极性、位顺序、启用中断和 DMA 功能等；

(4)、设置 LEDC 和必要的 LED0～LED7 引脚方向为输出，可选地，设置相应 I/O 的驱动能力；

(5)、设置 DMA 计数寄存器 R16\_LED\_DMA\_CNT，启动 DMA 发送，或者用写 FIFO 的方式发送数据。

# 第 22 章 参数

# 22.1 绝对最大值（临界或者超过绝对最大值将可能导致芯片工作不正常甚至损坏）

表22-1 绝对最大值参数表

<table><tr><td>名称</td><td>参数说明</td><td>最小值</td><td>最大值</td><td>单位</td></tr><tr><td>TA</td><td>工作时的环境温度</td><td>-40</td><td>85</td><td>°C</td></tr><tr><td>TS</td><td>储存时的环境温度</td><td>-40</td><td>125</td><td>°C</td></tr><tr><td>VDD33</td><td>系统电源电压（VDD33接电源，GND接地）</td><td>-0.4</td><td>4.0</td><td>V</td></tr><tr><td>VI033</td><td>I/0电源电压（VI033接电源，GND接地）</td><td>-0.4</td><td>4.0</td><td>V</td></tr><tr><td>VI0</td><td>输入或者输出引脚上的电压</td><td>-0.4</td><td>VI033+0.4</td><td>V</td></tr><tr><td>VI05</td><td>支持5V耐压的输入或者输出引脚上的电压</td><td>-0.4</td><td>5.5</td><td>V</td></tr><tr><td>VDCI</td><td>VDCID/VDCIA引脚上的电压（如果用外置DC-DC）</td><td>-0.4</td><td>VDD33+0.4</td><td>V</td></tr><tr><td>VXCK</td><td>X32MI/X32MO/启用LSE后的PA10/PA11的电压</td><td>-0.3</td><td>1.4</td><td>V</td></tr></table>

# 22.2 电气参数（测试条件： ${ \mathsf { T A } } = 2 5 { \mathsf { ^ { \circ } C } }$ ， $\mathsf { V D D 3 3 } = \mathsf { V } \mathsf { I 0 3 3 } = \mathsf { 3 . 3 V }$ ，Fsys $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ 16MHz）

表22-2 电气参数表

<table><tr><td>名称</td><td colspan="3">参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td rowspan="2">VDD33</td><td rowspan="2" colspan="2">系统电源电压@VDD33</td><td>未使用USB</td><td>1.85</td><td>3.3</td><td>3.6</td><td>V</td></tr><tr><td>使用USB</td><td>3.15</td><td>3.3</td><td>3.45</td><td>V</td></tr><tr><td rowspan="2">VI033</td><td rowspan="2" colspan="2">I/0电源电压@VI033</td><td>未使用USB</td><td>1.85</td><td>3.3</td><td>3.6</td><td>V</td></tr><tr><td>使用USB</td><td>3.15</td><td>3.3</td><td>3.45</td><td>V</td></tr><tr><td rowspan="2">\( ICC_8 \)</td><td rowspan="6">直通方式静态电源电流@条件:代码运行于RAM或FLASH 中</td><td rowspan="2">HSI 主频Fsys=8M</td><td>RAM</td><td></td><td>2.2</td><td></td><td>mA</td></tr><tr><td>FLASH</td><td></td><td>2.5</td><td></td><td>mA</td></tr><tr><td rowspan="2">\( ICC_{16} \)</td><td rowspan="2">HSE 主频Fsys=16M</td><td>RAM</td><td></td><td>3</td><td></td><td>mA</td></tr><tr><td>FLASH</td><td></td><td>3.5</td><td></td><td>mA</td></tr><tr><td rowspan="2">\( ICC_{48} \)</td><td rowspan="2">HSE-PLL 主频Fsys=78M</td><td>RAM</td><td></td><td>9</td><td></td><td>mA</td></tr><tr><td>FLASH</td><td></td><td>10.5</td><td></td><td>mA</td></tr><tr><td rowspan="2">\( IDDC_8 \)</td><td rowspan="6">启用 DC-DC后静态电源电流@条件:代码运行于RAM或FLASH 中</td><td rowspan="2">HSI 主频Fsys=8M</td><td>RAM</td><td></td><td>1.3</td><td></td><td>mA</td></tr><tr><td>FLASH</td><td></td><td>1.9</td><td></td><td>mA</td></tr><tr><td rowspan="2">\( IDDC_{16} \)</td><td rowspan="2">HSE 主频Fsys=16M</td><td>RAM</td><td></td><td>1.7</td><td></td><td>mA</td></tr><tr><td>FLASH</td><td></td><td>2.7</td><td></td><td>mA</td></tr><tr><td rowspan="2">\( IDDC_{48} \)</td><td rowspan="2">HSE-PLL 主频Fsys=78M</td><td>RAM</td><td></td><td>4</td><td></td><td>mA</td></tr><tr><td>FLASH</td><td></td><td>8.9</td><td></td><td>mA</td></tr><tr><td>VIL</td><td colspan="3">GPIO 低电平输入电压</td><td>0</td><td></td><td>0.9</td><td>V</td></tr><tr><td>VIH</td><td colspan="3">GPIO 高电平输入电压</td><td>2.0</td><td></td><td>VI033</td><td>V</td></tr><tr><td>VIL5</td><td colspan="3">支持 5V 耐压的 GPIO 低电平输入电压</td><td>0</td><td></td><td>0.9</td><td>V</td></tr><tr><td>VIH5</td><td colspan="3">支持 5V 耐压的 GPIO 高电平输入电压</td><td>2.0</td><td></td><td>5.0</td><td>V</td></tr><tr><td>VOL</td><td colspan="3">低电平输出电压(5mA/20mA 吸入电流)</td><td>0</td><td>0.3</td><td>0.4</td><td>V</td></tr><tr><td>VOH</td><td colspan="3">高电平输出电压(5mA/20mA 输出电流)</td><td>VI033-0.4</td><td>VI033-0.3</td><td>VI033</td><td>V</td></tr><tr><td>IIN</td><td colspan="3">GPIO 浮空输入端的输入电流</td><td>-3</td><td>0</td><td>3</td><td>uA</td></tr><tr><td>IUP</td><td colspan="3">GPIO 内置上拉电阻的输入端的输入电流</td><td>25</td><td>60</td><td>90</td><td>uA</td></tr><tr><td>IDN</td><td colspan="3">GPIO 内置下拉电阻的输入端的输入电流</td><td>-90</td><td>-60</td><td>-25</td><td>uA</td></tr><tr><td>Vref</td><td colspan="3">VINTA 引脚的电压(ADC 参考电压)</td><td>1.035</td><td>1.05</td><td>1.065</td><td>V</td></tr><tr><td>Vdc i</td><td colspan="3">VDCID 引脚在启用 DC-DC 后的电压</td><td>1.18</td><td>1.3</td><td>1.38</td><td>V</td></tr><tr><td>VIvr</td><td colspan="3">LVR 低压复位的门限电压</td><td>1.4</td><td>1.6</td><td>1.85</td><td>V</td></tr></table>

22.3 低功耗模式功耗（测试条件： ${ \mathsf { T A } } = 2 5 { \mathsf { ^ { \circ } C } }$ ， $\mathsf { V D D 3 3 } = \mathsf { V } \mathsf { I 0 3 3 } = \mathsf { 3 . 3 V }$ ，Fsys $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ 16MHz。）

表22-3 低功耗参数表（仅供参考，与温度相关）

<table><tr><td>低功耗模式</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>空闲模式,开启各模块时钟组合</td><td></td><td>1.26</td><td></td><td>mA</td></tr><tr><td>暂停模式,关闭所有时钟</td><td></td><td>200</td><td></td><td>uA</td></tr><tr><td>睡眠模式,多种组合,参考表5-3</td><td></td><td>2.6~8.2</td><td></td><td>uA</td></tr><tr><td>睡眠模式,PMU+内核+RAM32K,GPIO唤醒,无RTC</td><td></td><td>2.6</td><td></td><td>uA</td></tr><tr><td>下电模式,多种组合,参考表5-3</td><td></td><td>0.65~5.5</td><td></td><td>uA</td></tr><tr><td>下电模式,仅PMU,GPIO唤醒后复位,无RTC</td><td></td><td>0.65</td><td></td><td>uA</td></tr></table>

表22-4 各模块电流（仅供参考，与温度相关）

<table><tr><td>名称</td><td colspan="3">参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>IDD(RAM32K)</td><td colspan="3">RAM32K: 32KB SRAM</td><td></td><td>1.5</td><td></td><td>uA</td></tr><tr><td>IDD(RAM96K)</td><td colspan="3">RAM96K: 96KB SRAM</td><td></td><td>4.5</td><td></td><td>uA</td></tr><tr><td>IDD(LSI)</td><td colspan="3">内部LSI振荡器</td><td></td><td>0.5</td><td></td><td>uA</td></tr><tr><td>IDD(LSE)</td><td colspan="3">外部LSE振荡器</td><td></td><td>0.4</td><td></td><td>uA</td></tr><tr><td>IDD(HSI)</td><td colspan="3">内部HSI振荡器</td><td></td><td>120</td><td></td><td>uA</td></tr><tr><td>IDD(HSE)</td><td colspan="3">外部HSE振荡器</td><td></td><td>220</td><td></td><td>uA</td></tr><tr><td>IDD(BM)</td><td colspan="3">低功耗的电池低压监控BM模块</td><td></td><td>1</td><td></td><td>uA</td></tr><tr><td>IDD(BD)</td><td colspan="3">高精度的电池低压检测BD模块</td><td></td><td>85</td><td></td><td>uA</td></tr><tr><td>IDD(PLL)</td><td colspan="3">内部PLL振荡器</td><td></td><td>150</td><td></td><td>uA</td></tr><tr><td>IDD(ADC)</td><td colspan="3">ADC模块</td><td></td><td>400</td><td></td><td>uA</td></tr><tr><td rowspan="3">IDD(TKEY)</td><td colspan="3">TouchKey模块</td><td></td><td>100</td><td></td><td>uA</td></tr><tr><td colspan="3">电荷迁移模块</td><td></td><td>30</td><td></td><td>uA</td></tr><tr><td colspan="3">驱动屏蔽模块</td><td></td><td>350</td><td></td><td>uA</td></tr><tr><td>IDD(TS)</td><td colspan="3">温度传感器TS模块</td><td></td><td>100</td><td></td><td>uA</td></tr><tr><td>IDD(LCD)</td><td colspan="3">LCD模块(参考表5-3温度相关说明)</td><td></td><td>2</td><td></td><td>uA</td></tr><tr><td>IDD(USBFS)</td><td>USBFS模块</td><td colspan="2">发送状态</td><td></td><td>2</td><td></td><td>mA</td></tr><tr><td>IDD(USBHS)</td><td>USBHS模块</td><td colspan="2">发送状态</td><td></td><td>15</td><td></td><td>mA</td></tr><tr><td rowspan="3">IDD(NFC)</td><td rowspan="3">NFC模块</td><td colspan="2">读卡器接收模式</td><td></td><td>25.5(1)</td><td></td><td>mA</td></tr><tr><td colspan="2">读卡器发送模式</td><td></td><td>25(1)</td><td></td><td>mA</td></tr><tr><td colspan="2">卡模式</td><td></td><td>1.5</td><td></td><td>mA</td></tr><tr><td rowspan="8">IDD(BLE)</td><td rowspan="8">BLE蓝牙</td><td colspan="2">直通电源</td><td></td><td>5.8</td><td></td><td>mA</td></tr><tr><td>启用DC-DC</td><td>Fsys=78M</td><td></td><td>3.0</td><td></td><td>mA</td></tr><tr><td>-20dBm</td><td>直通电源</td><td></td><td>3.0</td><td></td><td>mA</td></tr><tr><td>发送功率</td><td>启用DC-DC</td><td>Fsys=78M</td><td></td><td>1.5</td><td>mA</td></tr><tr><td>0dBm</td><td>直通电源</td><td></td><td>7.8</td><td></td><td>mA</td></tr><tr><td>发送功率</td><td>启用DC-DC</td><td>Fsys=78M</td><td></td><td>3.8</td><td>mA</td></tr><tr><td>+4.5dBm</td><td>直通电源</td><td></td><td>15.0</td><td></td><td>mA</td></tr><tr><td>发送功率</td><td>启用DC-DC</td><td>Fsys=78M</td><td></td><td>7.2</td><td>mA</td></tr></table>

注：1、相关电流参数与天线和匹配网络有关。

# 22.4 时钟源

表 22-5 高速振荡器 HSI 和 HSE

<table><tr><td>名称</td><td>参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>FHSI</td><td>内部HSI振荡器频率</td><td></td><td>16</td><td></td><td>MHz</td></tr></table>

<table><tr><td>AHSI</td><td>HSI振荡器精度</td><td>TA=-40°C~85°C</td><td></td><td>±1</td><td></td><td>%</td></tr><tr><td>TSUHSI</td><td colspan="2">内部HSI振荡器启动到可用时间</td><td></td><td></td><td>1</td><td>us</td></tr><tr><td>FHSE</td><td colspan="2">外部HSE振荡器频率</td><td></td><td>32</td><td></td><td>MHz</td></tr><tr><td>TSUHSE</td><td colspan="2">外部HSE振荡器启动到可用时间</td><td>80</td><td>200</td><td>500</td><td>us</td></tr><tr><td>TSTHSE</td><td colspan="2">外部HSE振荡器启动到稳定时间</td><td>200</td><td>500</td><td>3000</td><td>us</td></tr></table>

表 22-6 低速振荡器 LSI 和 LSE

<table><tr><td>名称</td><td colspan="3">参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>FLSIR</td><td colspan="3">内部LSI振荡器频率（校准前）</td><td>20K</td><td>32K</td><td>48K</td><td>Hz</td></tr><tr><td>FLSI</td><td colspan="3">内部LSI频率（应用软件运行时校准后）</td><td>32726</td><td>32768</td><td>32810</td><td>Hz</td></tr><tr><td rowspan="3">ALSI</td><td rowspan="3">LSI振荡器精度（软件校准后）</td><td colspan="2">快速校准</td><td></td><td>1000</td><td></td><td>ppm</td></tr><tr><td rowspan="2">高精度校准(1)</td><td>TA=-40°C~85°C</td><td></td><td>600</td><td></td><td>ppm</td></tr><tr><td>TA=-20°C~60°C</td><td></td><td>300</td><td></td><td>ppm</td></tr><tr><td>TSULSI</td><td colspan="3">内部LSI振荡器启动到稳定时间</td><td></td><td>40</td><td>100</td><td>uS</td></tr><tr><td>TSULSE</td><td colspan="3">外部LSE振荡器启动到可用时间</td><td>100</td><td>300</td><td>1500</td><td>mS</td></tr><tr><td>TSTLSE</td><td colspan="3">外部LSE振荡器启动到稳定时间</td><td>500</td><td>1500</td><td>5000</td><td>mS</td></tr></table>

注：1、温度变化不超过±1℃。

表 22-7 PLL 特性

<table><tr><td>名称</td><td>参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>FPLL</td><td>PLL倍频输出时钟(CK16M*39倍)</td><td></td><td>624</td><td></td><td>MHz</td></tr><tr><td>TPLLLK</td><td>PLL锁相时间</td><td></td><td>20</td><td>40</td><td>us</td></tr></table>

22.5 时间参数（测试条件： ${ \mathsf { T A } } = 2 5 { \mathsf { ^ { \circ } C } }$ ， $\mathsf { V D D 3 3 } = \mathsf { V } \mathsf { I 0 3 3 } = \mathsf { 3 . 3 V }$ ，Fsys $\underline { { \underline { { \mathbf { \delta \pi } } } } }$ 5.33MHz）

表 22-8 时间参数

<table><tr><td>名称</td><td colspan="2">参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>\(T_{rpor}\)</td><td colspan="2">电源上电复位 RPOR 后的复位延时</td><td>11.5</td><td>15.5</td><td>19</td><td>ms</td></tr><tr><td>\(T_{rst}\)</td><td colspan="2">RST 有效信号宽度</td><td></td><td>0.1</td><td></td><td>us</td></tr><tr><td>\(T_{mr}\)</td><td colspan="2">外部复位 MR 后的复位延时</td><td>2</td><td>8</td><td>18</td><td>us</td></tr><tr><td>\(T_{sr}\)</td><td colspan="2">软件复位 SR 后的复位延时</td><td>2</td><td>8</td><td>18</td><td>us</td></tr><tr><td>\(T_{wtr}\)</td><td colspan="2">看门狗复位 WTR 后的复位延时</td><td>10</td><td>12</td><td>18</td><td>us</td></tr><tr><td rowspan="4">\(T_{WAK}\)</td><td rowspan="4">从低功耗状态退出的唤醒时间</td><td>空闲模式</td><td>0.6</td><td>1</td><td>3</td><td>us</td></tr><tr><td>暂停模式</td><td>\(T_{SUHSI}+1\)</td><td>\(T_{SUHSI}+80\)</td><td>\(T_{SUHSI}+150\)</td><td>us</td></tr><tr><td>睡眠模式</td><td>\(T_{SUHSI}+1\)</td><td>\(T_{SUHSI}+300\)</td><td>\(T_{SUHSI}+400\)</td><td>us</td></tr><tr><td>下电模式</td><td>\(T_{SUHSI}+0.4\)</td><td>\(T_{SUHSI}+1\)</td><td>\(T_{SUHSI}+5\)</td><td>ms</td></tr></table>

注：上表中延时参数均是基于Tsys的倍数，降低主频将增加延时。

上表中延时参数是基于使用内部HSI时钟源，如果睡眠期间使用外部HSE时钟源，那么表中暂停模式/睡眠模式/下电模式的延时参数 $T \_ { w A K }$ 均额外增加约 $0 . 2 { \sim } 1 m s$ （启动到可用TSUHSI）。

22.6 其它参数（测试条件： ${ \mathsf { T A } } = 2 5 { \mathsf { ^ { \circ } C } }$ ，VDD33 = VIO33 = 3.3V，Fsys = 16MHz）

表 22-9 其它参数

<table><tr><td>名称</td><td colspan="3">参数说明</td><td>最小值</td><td>典型值</td><td>最大值</td><td>单位</td></tr><tr><td>RTS</td><td colspan="3">TS温度传感器的测量范围</td><td>-40</td><td></td><td>85</td><td>°C</td></tr><tr><td>ATSC</td><td colspan="3">温度传感器经软件校准后的测量误差</td><td></td><td>±10</td><td></td><td>°C</td></tr><tr><td>TFRER</td><td colspan="3">Flash-ROM的单次扇区擦除操作时间</td><td>6</td><td>16</td><td>30</td><td>mS</td></tr><tr><td>TFRPG</td><td colspan="3">Flash-ROM的单次字编程操作时间</td><td>1</td><td>2</td><td>4</td><td>mS</td></tr><tr><td rowspan="2">NEPCE</td><td colspan="2" rowspan="2">Flash-ROM的擦写次数erase/program cycle endurance</td><td>5~45°C</td><td>100K</td><td>1000K(抽测)</td><td></td><td rowspan="2">times</td></tr><tr><td>-40~85°C</td><td>50K</td><td>200K(抽测)</td><td></td></tr><tr><td>TDR</td><td colspan="3">Flash-ROM的数据保持能力</td><td>20</td><td></td><td></td><td>years</td></tr><tr><td rowspan="2">VESD</td><td rowspan="2">I/0输入或者输出引脚上的ESD耐压</td><td colspan="2">天线ANT</td><td>2K</td><td>4K(抽测)</td><td></td><td>V</td></tr><tr><td colspan="2">I/0引脚:PA和PB</td><td>4K</td><td>6K(抽测)</td><td></td><td>V</td></tr></table>

# 第 23 章 封装

芯片封装

<table><tr><td>封装形式</td><td>塑体尺寸</td><td colspan="2">引脚节距</td><td>封装说明</td><td>订货型号</td></tr><tr><td>QFN48</td><td>5*5mm</td><td>0.35mm</td><td>13.8mil</td><td>四边无引线48脚</td><td>CH585M</td></tr><tr><td>QFN32</td><td>4*4mm</td><td>0.4mm</td><td>15.7mil</td><td>四边无引线32脚</td><td>CH585F</td></tr><tr><td>QFN26C3</td><td>3*3mm</td><td>0.4mm</td><td>15.7mil</td><td>WCH四边无引线26脚</td><td>CH585C</td></tr><tr><td>QFN20</td><td>3*3mm</td><td>0.4mm</td><td>15.7mil</td><td>四边无引线20脚</td><td>CH585D</td></tr><tr><td>QFN48</td><td>5*5mm</td><td>0.35mm</td><td>13.8mil</td><td>四边无引线48脚</td><td>CH584M</td></tr><tr><td>QFN48</td><td>5*5mm</td><td>0.35mm</td><td>13.8mil</td><td>四边无引线48脚</td><td>CH584X</td></tr><tr><td>QFN32</td><td>4*4mm</td><td>0.4mm</td><td>15.7mil</td><td>四边无引线32脚</td><td>CH584F</td></tr></table>

说明：尺寸标注的单位是 $\mathsf { m m }$ （毫米），引脚中心间距是标称值，除此之外的尺寸误差不大于±0.2mm。

QFN48

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/1800ca8b04197dcc6bc80a3d5f9d9e164c9068d6257ce052021e96e81ddc22f1.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/bdb3e40013334a4b6c9ecde00db12dfd48154d9b3c71b01fb68eb8a11054252b.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/6e19d213702ebbb0d748cf3badf0b23b0a5e64ee3dbe1b34042462153bc16327.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/3e5deac91fae751021ffe1568ec900e4e41762fb3fc7d21efbc86c3a43cd3181.jpg null)

QFN32

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/879318748a32bd457d0716c63cd9df250174fa27eaf0972c24be4ff3cbdb99d9.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/7292de24e61d461a7a49a40312138b5e6811bc3e6c44c98e810e0bf08120817a.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/c511e20337c8b9fdd39e08909a1e54ca373f859f4bae628059f4ee76f40d2485.jpg null)

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/78edbe017796fbf5b9d6d3c7587113f7abf958520407208a41c6b439686602d9.jpg null)

QFN20

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/d9a54efa15efd6c740555d6af197cd4ca5e0593210d9b9e9f6a08d37e193d0cd.jpg null)

QFN26C3

!\[image]\(https\://cdn-mineru.openxlab.org.cn/result/2026-03-30/8ea3da3b-1e3e-4c3d-81fa-c07639e597c5/33aaa095cc21d09884ea8550814d0746fbd0b71cc20a5c808aa8c8226040dfdc.jpg null)
