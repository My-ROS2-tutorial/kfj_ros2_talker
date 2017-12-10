#include<stdio.h>

#include "kfj_ros2_talker/kfj_talker2.hpp"

using namespace std::chrono_literals;

KfjTalker2::KfjTalker2()
    : Node("talker2"),
      m_count(0)
{
    m_publisher = create_publisher<std_msgs::msg::String>("chatter");
    m_timer = create_wall_timer(500ms, std::bind(&KfjTalker2::timer_callback, this));
}

void KfjTalker2::timer_callback()
{
    auto message = std::make_shared<std_msgs::msg::String>();
    message->data = "Hello ROS2 " + std::to_string(m_count++);
    //RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", message->data.c_str());
    printf("Node %s: Publishing: '%s'\n", "talker2", message->data.c_str());
    m_publisher->publish(message);
    if (m_count > 20)
    {
        m_timer->cancel();
    }
}

