# Motor_can
---
## 1.简介
### 启动MotorCan节点，用于控制和监控4个电机。
---
## 2.获取参数
```bash
motor_can_node : # node name  
  ros__parameters:  
    CanSeries: "can3"  
    wheel_radius: 0.07  
    motor_ratio: 5.18  
    Kp: 1.1  
    Ki: 0.4  
    Kd: 0.0  
    IBound: 0.3  
    dt: 0.001  
    preTorque: 0.15  
    filter_a1: 0.828  
    filter_b0: 0.086  
    filter_b1: 0.086  
    K_motor: 0.0813  
    maxTorque: 1.6  
    minTorque: -1.6  
```
---
## 3.启动方式
### 要启动MotorCan节点，按照以下步骤操作：
```bash
cd 4WD-CAR-ROMA-ros2/  
colcon build --packages-select custom_interfaces //首先编译custom_interfaces 功能包.  
colcon build --packages-select motor_can_cpp //继续编译motor_can_cpp 功能包。  
source ~/4WD-CAR-ROMA-ros2/install/setup.bash //配置环境变量。  
ros2 run motor_can_cpp motor_can //运行节点。  
```
---
## 4.订阅与发布
### 订阅
```
/motor_cmd(custom_interfaces/msg/ActuatorCommand)  
```
用于接收电机的控制命令,包含速度与扭矩。  
由motion_controller节点发布，包含4个电机的控制信息。  
### 发布
```
/motor_state(custom_interfaces/msg/ActuatorState)  
```
用于发布电机的状态信息。  
  
---
## 功能
>MotorCan节点的功能包括：  
初始化can通信，电机。  
定时控制以及刷新电机状态。  
接收并解析来自/motor_cmd主题的控制命令，以控制电机的速度和扭矩。  
将电机的状态信息发布到/motor_state主题，以便用户可以检查电机状态。  
节点关闭时同时关闭can通信。  