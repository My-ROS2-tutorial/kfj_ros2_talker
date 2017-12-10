/*
 * Talker in ROS2.
 *
 * Refer to
 *  - https://github.com/ros2/examples/blob/master/rclcpp/minimal_publisher/not_composable.cpp
 *  - http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
 *
 * This style is not recommended anymore.
 */

#include<stdio.h>
#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

const char* g_node_name = "talker1";
const char* g_topic_name = "chatter";

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(g_node_name);
    auto talker = node->create_publisher<std_msgs::msg::String>(g_topic_name);
    auto message = std::make_shared<std_msgs::msg::String>();
    auto count = 0;
    rclcpp::WallRate loop_rate(500ms);

    while (rclcpp::ok())
    {
        message->data = "Hello ROS2 " + std::to_string(count++);
        //RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", message->data.c_str());
        printf("Node %s: Publishing: '%s'\n", g_node_name, message->data.c_str());
        talker->publish(message);
        rclcpp::spin_some(node);
        loop_rate.sleep();
        if (count > 20) break;
    }
    rclcpp::shutdown();

    return 0;
}
