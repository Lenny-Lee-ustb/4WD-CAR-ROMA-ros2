#!/bin/bash

# 检查是否提供了足够的参数
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <output_filename>"
  exit 1
fi

output_filename="$1"

# 执行ros2 bag record命令，并将file-name和topic-name参数传递给它
source /home/car01/4WD-CAR-ROMA-ros2/install/setup.bash
ros2 bag record -o "data/""$output_filename" /Imu_data /motor_state /servo_state
#hz: Imu:400; motor_state:1009; servo_state:100

#可在终端中通过以下代码授予脚本执行权限
#chmod +x xxxx.sh
