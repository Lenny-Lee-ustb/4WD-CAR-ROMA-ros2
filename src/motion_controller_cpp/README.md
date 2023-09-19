# Motion_controller
## 简介
 用于控制移动平台上的电机和舵机以实现运动控制。该节点接收来自Sbus接收器的输入，确定小车的线速度和角速度,然后设置电机、舵机控制参数并发布给其他节点使用。
 ---
## 启动方式
 要启动Motion_controller节点 ，按照以下步骤操作：
    'cd 4WD-CAR-ROMA-ros2/'
    'colcon build --packages-select custom_interfaces' 
    'colcon build --packages-select servo_rs485_py'
    'colcon build --packages-select sbus_interface'
    'source ~/4WD-CAR-ROMA-ros2/install/setup.bash'
    'colcon build --packages-select motion_controller_cpp'
    'source ~/4WD-CAR-ROMA-ros2/install/setup.bash'
    'ros2 run motion_controller_cpp motion_controller'
 ---
## 订阅与发布
### 订阅
    > /sbus(消息类型：sbus_interface/msg/Sbus）
     该主题接收来自Sbus接收器的输入，通过读取各通道数据，确定遥控状态，并确定线速度和角速度。
    > /cmd_vel(消息类型：geometry_msgs/msg/Twist）
     该主题接收来自上层控制器的输入，包括线速度和角速度命令（需要额外的发布方）。
### 发布
    > /motor_cmd(消息类型：custom_interfaces/msg/ActuatorCommand）
     该主题发布电机控制命令，包括速度和转矩命令。
    > /servo_cmd(消息类型：custom_interfaces/msg/ActuatorCommand）
     该主题发布伺服控制命令，用于控制伺服电机。
    > /command_info(消息类型：geometry_msgs/msg/Twist）
     该主题发布小车状态信息，便于用户检查小车状态。
 ---
## 功能
    主要作用是充当控制器，将来自遥控器的命令转化为电机和伺服的控制信号，从而实现移动平台的运动控制。