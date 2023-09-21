# Motion_controller_node

## 1.简介

用于控制移动平台上的电机和舵机以实现运动控制。  该节点接收来自遥控器的输入，确定期望的小车线速度和角速度，然后设置电机、舵机控制参数并发布给其他节点使用。  

---

## 2.启动方式

### 要启动Motion_controller_node节点 ，按照以下步骤操作：
```bash
cd 4WD-CAR-ROMA-ros2/  
colcon build --packages-select custom_interfaces  
colcon build --packages-select servo_rs485_py  
colcon build --packages-select sbus_interface  
source ~/4WD-CAR-ROMA-ros2/install/setup.bash  
colcon build --packages-select motion_controller_cpp  
source ~/4WD-CAR-ROMA-ros2/install/setup.bash  
ros2 run motion_controller_cpp motion_controller  
```
---

## 3.订阅与发布

### 订阅
```
/sbus(sbus_interface/msg/Sbus）  
```
通过读取消息中各通道数据，可以确定遥控状态、期望的线速度和角速度等。  
```
/cmd_vel(geometry_msgs/msg/Twist）  
```
包括线速度和角速度命令（需要额外的发布方）。  

### 发布
```
/motor_cmd(custom_interfaces/msg/ActuatorCommand）  
```
发布电机控制信息，包括速度和转矩信息。  
```
/servo_cmd(custom_interfaces/msg/ActuatorCommand）  
```
发布舵机控制信息，用于控制舵机。  
由servo_rs485_node节点接收此话题消息。  

```
/command_info(geometry_msgs/msg/Twist）  
```
发布小车状态信息，便于用户检查小车状态。  

---

## 4.功能
  
主要作用是充当控制器，将来自遥控器的信号转化为电机和舵机的控制信息，从而实现移动平台的运动控制。
  