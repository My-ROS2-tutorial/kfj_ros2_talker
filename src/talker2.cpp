/*
 * ROS2 talker using class member functions.
 *
 * Refer to https://github.com/ros2/examples/blob/master/rclcpp/minimal_publisher/member_function.cpp
 *
 */

#include "kfj_ros2_talker/kfj_talker2.hpp"

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<KfjTalker2>());
    rclcpp::shutdown();

    return 0;
}
