cmake_minimum_required(VERSION 3.5)
project(td3_test1)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Set CMAKE_BUILD_TYPE
set(CMAKE_BUILD_TYPE Release)
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
if(ALIAS_ROS2_TF2)
  add_definitions(-Dtf2=ros2_tf2)
  add_definitions(-Dtf2_ros=ros2_tf2_ros)
  add_definitions(-Dmessage_filters=ros2_message_filters)
endif()
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package( custom_interfaces REQUIRED)
find_package( nav_msgs REQUIRED)
find_package( rclcpp REQUIRED)
find_package( sbus_interface REQUIRED)
find_package( sensor_msgs REQUIRED)
include_directories("include/td3_test1")
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Node
add_executable(td3_test1 
src/slros2_generic_param.cpp
src/main.cpp
src/ros2nodeinterface.cpp
src/rtGetInf.cpp
src/rtGetNaN.cpp
src/rt_nonfinite.cpp
src/slros2_initialize.cpp
src/slros_busmsg_conversion.cpp
src/td3_test1.cpp
src/td3_test1_data.cpp
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
target_compile_options(td3_test1 PUBLIC 
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -Wall -Wextra -Wpedantic
  >)
endif()
target_compile_options(td3_test1 PRIVATE
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -DMW_DL_DATA_PATH=C:/Users/roma/Desktop/DRL_DE~1
  -DMODEL=td3_test1
  -DNUMST=1
  -DNCSTATES=0
  -DHAVESTDIO
  -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
  -DCLASSIC_INTERFACE=0
  -DALLOCATIONFCN=0
  -DTID01EQ=0
  -DTERMFCN=1
  -DONESTEPFCN=1
  -DMAT_FILE=0
  -DMULTI_INSTANCE_CODE=1
  -DINTEGER_CODE=0
  -DMT=0
  -DROS2_PROJECT
  -DSTACK_SIZE=64
  -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
  -DRT=RT
  -fpermissive  >
  )
ament_target_dependencies(
  td3_test1
  "custom_interfaces"
  "nav_msgs"
  "rclcpp"
  "sbus_interface"
  "sensor_msgs"
)
target_include_directories(td3_test1 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(td3_test1 
	${CMAKE_DL_LIBS}
    )
install(TARGETS td3_test1
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
ament_export_include_directories(
  include
)
foreach(file_i ${CUDA_BINS})
add_custom_command(
                   TARGET td3_test1
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CMAKE_INSTALL_PREFIX}/td3_test1_ert_rtw/${file_i}
				   )
add_custom_command(
                   TARGET td3_test1
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CMAKE_INSTALL_PREFIX}/codegen/exe/td3_test1/${file_i}
				   )				   
endforeach(file_i)
ament_package()
# Generated on Fri Jun 28 10:48:08 2024
