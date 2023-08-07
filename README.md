# 4WD CAR ROMA ros2

## 项目描述 Description

This project is under constuction!

---

## Installation

### Install ROS2

`wget http://fishros.com/install -O fishros && . fishros`  

### Install Realsense

`sudo apt install ros-humble-librealsense2*`  
`sudo apt install ros-humble-realsense2-*`  

### Setup DynamixelSDK python

At ~/ directory

`git clone https://github.com/ROBOTIS-GIT/DynamixelSDK.git`  
`cd DynamixelSDK/python/`  
`sudo python setup.py install`

### Init Serial

You should read rules/rules.md

### Reduce serial latency

`sudo apt install expect`  
`sudo apt-get install -y setserial`

### Clone this workspace and build

```bash
git clone https://github.com/Lenny-Lee-ustb/4WD-CAR-ROMA-ros2
cd 4WD-CAR-ROMA-ros2
git submodule init
git submodule update
colcon build --symlink-install
```

---

## Submodule in this work

1. [sllidar_ros2](https://github.com/Slamtec/sllidar_ros2)
2. [sbus_ros2](https://github.com/Lenny-Lee-ustb/sbus_ros2)
