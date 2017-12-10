cmake_minimum_required(VERSION 3.5)
project(kfj_ros2_talker)

set(CMAKE_PREFIX_PATH
    $ENV{CMAKE_PREFIX_PATH}
    ${CMAKE_PREFIX_PATH}
    )

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker1 src/talker1.cpp)
ament_target_dependencies(talker1 rclcpp std_msgs)

add_executable(talker2 src/talker2.cpp)
ament_target_dependencies(talker2 rclcpp std_msgs)

install(TARGETS
    talker1
    talker2
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
