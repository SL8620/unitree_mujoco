cmake_minimum_required(VERSION 3.8)
project(robot_driver_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(robot_msgs REQUIRED)

# ====== 驱动库 (包含 DriverMujoco / DriverROSHW 的实现) ======
add_library(robot_driver
  src/robot_driver_mujoco.cpp
  src/robot_driver_roshw.cpp
)

target_include_directories(robot_driver PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(robot_driver
  rclcpp
  sensor_msgs
  std_msgs
  robot_msgs
)

# ====== 可执行程序 ======
add_executable(controller_node src/controller_node.cpp)
target_link_libraries(controller_node robot_driver)
ament_target_dependencies(controller_node rclcpp sensor_msgs robot_msgs)

add_executable(driver_mujoco src/driver_mujoco.cpp)
target_link_libraries(driver_mujoco robot_driver)
ament_target_dependencies(driver_mujoco rclcpp sensor_msgs robot_msgs)

add_executable(driver_roshw src/driver_roshw.cpp)
target_link_libraries(driver_roshw robot_driver)
ament_target_dependencies(driver_roshw rclcpp sensor_msgs robot_msgs)

add_executable(mujoco_sim_node src/mujoco_sim_node.cpp)
target_link_libraries(mujoco_sim_node robot_driver)
ament_target_dependencies(mujoco_sim_node rclcpp sensor_msgs robot_msgs)

# ====== 安装 ======
install(TARGETS
  robot_driver
  controller_node
  driver_mujoco
  driver_roshw
  mujoco_sim_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()