# Servo_node
---
## 1.简介
  
该节点通过串口连接控制和监控车前两个舵机。其他节点能够通过话题来输入期望的舵机位置，同时能够通过话题实时获取舵机的状态信息。
  
---

## 2.启动方式
### 要启动Servo_node节点，按照以下步骤操作：
首先确保成功安装[DynamixelSDK](https://emanual.robotis.com/docs/en/software/dynamixel/dynamixel_sdk/download/#file-structure)的python库(用于控制及管理电机)  

```bash
cd 4WD-CAR-ROMA-ros2/  
colcon build --packages-select custom_interfaces //首先编译custom_interfaces 功能包.  
colcon build --packages-select servo_rs485_py  
source ~/4WD-CAR-ROMA-ros2/install/setup.bash //配置环境变量。  
ros2 run servo_rs485_py servo_rs485_node  //运行节点。  
```
---
## 3.订阅与发布
### 订阅
```
/servo_cmd (custom_interfaces/msg/ActuatorCommand)

```
用于接收舵机的控制指令，该消息包含舵机的期望位置。  
由motion_controller节点发布该话题    

### 发布
```
/servo_state (custom_interfaces/msg/ActuatorState)    
```
用于发布舵机的状态信息。用户可接收并记录。    
  
---
## 4.功能
>servo_node节点的功能包括：  
设置参数，包括舵机位置范围，串口设置等。    
初始化串口，开启舵机并复位。  
接收来自/servo_cmd话题的位置控制信息，调整舵机位置。  
启用定时器，实时更新舵机位置，并循环将电机的状态信息发布到/motor_state话题，用户可以记录电机状态。  
 
