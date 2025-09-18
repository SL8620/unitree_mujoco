/*
 * @Author: SL8620
 * @Date: 2025-09-18 09:46:29
 * @LastEditTime: 2025-09-18 10:00:52
 * @LastEditors: SL8620
 * @Description: 
 * @FilePath: \robot_driver_pkg\CMakeLists.txt
 * 
 */
cmake_minimum_required(VERSION 3.16)
project(robot_driver_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# generate messages
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/MotorCommand.msg"
  "msg/MotorCommandArray.msg"
  DEPENDENCIES sensor_msgs std_msgs
)

ament_export_dependencies(rosidl_default_runtime)

include_directories(include ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp)

# driver_mujoco component
add_library(driver_mujoco SHARED src/driver_mujoco.cpp)
ament_target_dependencies(driver_mujoco rclcpp rclcpp_components sensor_msgs std_msgs std_srvs)
target_include_directories(driver_mujoco PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_definitions(driver_mujoco PRIVATE "COMPOSITION_BUILDING_DLL")
rclcpp_components_register_node(driver_mujoco PLUGIN "RobotDriverMujoco" EXECUTABLE robot_driver_mujoco)
add_dependencies(driver_mujoco ${${PROJECT_NAME}_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_interfaces_cpp)

# driver_roshw component
add_library(driver_roshw SHARED src/driver_roshw.cpp)
ament_target_dependencies(driver_roshw rclcpp rclcpp_components sensor_msgs std_msgs std_srvs)
target_include_directories(driver_roshw PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_definitions(driver_roshw PRIVATE "COMPOSITION_BUILDING_DLL")
rclcpp_components_register_node(driver_roshw PLUGIN "RobotDriverROSHW" EXECUTABLE robot_driver_roshw)
add_dependencies(driver_roshw ${${PROJECT_NAME}_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_interfaces_cpp)

# mujoco_sim_node component
add_library(mujoco_sim_node_lib SHARED src/mujoco_sim_node.cpp)
ament_target_dependencies(mujoco_sim_node_lib rclcpp rclcpp_components sensor_msgs std_msgs std_srvs)
target_include_directories(mujoco_sim_node_lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_compile_definitions(mujoco_sim_node_lib PRIVATE "COMPOSITION_BUILDING_DLL")
rclcpp_components_register_node(mujoco_sim_node_lib PLUGIN "MujocoSimNode" EXECUTABLE mujoco_sim_node)
add_dependencies(mujoco_sim_node_lib ${${PROJECT_NAME}_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_interfaces_cpp)

# controller node (standalone)
add_executable(controller_node src/controller_node.cpp)
ament_target_dependencies(controller_node rclcpp)
target_include_directories(controller_node PRIVATE include)
add_dependencies(controller_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${PROJECT_NAME}_generate_interfaces_cpp)

install(TARGETS
  driver_mujoco
  driver_roshw
  mujoco_sim_node_lib
  controller_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
