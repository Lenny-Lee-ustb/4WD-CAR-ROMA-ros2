#!/bin/bash

# 检查参数数量是否正确
if [ "$#" -ne 2 ]; then
    echo "Usage: ./setPara <Paraname> <value>"
    exit 1
fi

PARAM_NAME=$1
PARAM_VALUE=$2

# ROS2节点名称和命名空间（根据实际情况修改）
NODE_NAME="motion_controller_withTD3"
NAMESPACE=""

# 构建完整的节点路径
if [ -z "$NAMESPACE" ]; then
    FULL_NODE_PATH="/$NODE_NAME"
else
    FULL_NODE_PATH="/$NAMESPACE/$NODE_NAME"
fi

# 使用ros2 param set命令修改参数
ros2 param set $FULL_NODE_PATH $PARAM_NAME $PARAM_VALUE

# 检查命令是否执行成功
if [ $? -eq 0 ]; then
    echo "Successfully set $PARAM_NAME to $PARAM_VALUE in $NODE_NAME"
else
    echo "Failed to set parameter. Please check:"
    echo "1. ROS2是否正在运行"
    echo "2. 节点名称是否正确"
    echo "3. 参数名称和类型是否正确"
fi

#可在终端中通过以下代码授予脚本执行权限
#chmod +x xxxx.sh
