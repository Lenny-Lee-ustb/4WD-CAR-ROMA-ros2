# wt906_serial_node

## 1.简介

用于获取、处理IMU数据并将其发布的节点。  

---

## 2.启动方式

### 要启动wt906_serial_node节点 ，按照以下步骤操作：
```bash
cd 4WD-CAR-ROMA-ros2/  
colcon build --packages-select wt906_imu_py   
source ~/4WD-CAR-ROMA-ros2/install/setup.bash  
ros2 run wt906_imu_py wt906_serial  
```
---

## 3.订阅与发布

### 订阅

无  
 
### 发布
```
/imu_state_<serial_ID>(sensor_msgs/Imu)  
```

包括线性加速度、角速度和姿态四元数信息。  

```
imu_rpy_<serial_ID>(geometry_msgs/PointStamped)  
```

包括滚动、俯仰和偏航角度信息。  

## 4.功能
>wt906_serial_node节点功能包括：  
开启串口，通过串口读取原始IMU数据。  
解析原始数据以获得加速度、角速度和姿态角度信息，同时计算获取姿态四元数信息。  
将获得的信息通过话题发布，用户可接收并记录。  
  


