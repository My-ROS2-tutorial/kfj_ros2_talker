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

include_directories(include)
ament_export_include_directories(include)

add_executable(talker1 src/talker1.cpp)
ament_target_dependencies(talker1 rclcpp std_msgs)

add_library(${PROJECT_NAME} SHARED
    src/kfj_talker2.cpp
    )
ament_target_dependencies(${PROJECT_NAME}
    "rclcpp"
    "std_msgs"
    )
ament_export_libraries(${PROJECT_NAME})

add_executable(talker2 src/talker2.cpp)
target_link_libraries(talker2 ${PROJECT_NAME})
ament_target_dependencies(talker2 rclcpp std_msgs)

install(TARGETS
    talker1
    talker2
    ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(
    DIRECTORY include/
    DESTINATION include
    )

ament_package()
