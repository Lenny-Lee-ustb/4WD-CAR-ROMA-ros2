# Sbus_bridge_node 
## 1.简介
  
用于处理来自遥控器的信号，并发布出去。
  
---
## 2.启动方式
### 要启动Sbus_bridge_node，按照以下步骤操作：
```bash
cd 4WD-CAR-ROMA-ros2/  
colcon build --packages-select sbus_interface  
source ~/4WD-CAR-ROMA-ros2/install/setup.bash    
ros2 run sbus_bridge sbus_bridge_node  
```
---
## 3.订阅与发布
### 发布
```
/sbus(sbus_interface::msg::Sbus)  
```
包含了处理后的SBUS数据，可以检查是否丢帧，遥控状态是否正常，并包含了sbus各通道的数据。  
  
---
## 4.功能
  
接收来自遥控器的原始遥控信号，处理并发布
  
---

# Sbus_serial_dirver
  
用于操作和解析SBUS（Serial Bus）串行通信协议的数据
  
---
## 方法：
```bash
setCallback：设置一个回调函数，用于处理接收到的SBUS数据。  
setUpSBusSerialPort：初始化SBUS串口通信，包括连接串口和启动接收线程。  
connectSerialPort：打开串口设备并进行基本配置。  
disconnectSerialPort：关闭串口设备。  
startReceiverThread：启动接收线程。  
stopReceiverThread：停止接收线程。  
configureSerialPortForSBus：配置串口设备的参数，如波特率、数据位、停止位等。  
serialPortReceiveThread：接收线程的主要函数，负责从串口读取数据并解析SBUS消息。  
parseSbusMessage：解析SBUS消息的私有方法，将消息中的通道数据提取出来。  
```