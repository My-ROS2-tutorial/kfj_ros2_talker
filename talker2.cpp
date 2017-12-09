/*
 * ROS2 talker using class member functions.
 *
 * Refer to https://github.com/ros2/examples/blob/master/rclcpp/minimal_publisher/member_function.cpp
 *
 */

#include<stdio.h>
#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

using namespace std::chrono_literals;


class KfjTalker2 : public rclcpp::Node
{
public:
    KfjTalker2()
        :Node(m_node_name),
          m_count(0)
    {
        m_publisher = create_publisher<std_msgs::msg::String>(m_topic_name);
        m_timer = create_wall_timer(500ms, std::bind(&KfjTalker2::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = std::make_shared<std_msgs::msg::String>();
        message->data = "Hello ROS2 " + std::to_string(m_count++);
        //RCLCPP_INFO(node->get_logger(), "Publishing: '%s'", message->data.c_str());
        printf("Node %s: Publishing: '%s'\n", m_node_name.c_str(), message->data.c_str());
        m_publisher->publish(message);
        if (m_count > 20)
        {
            m_timer->cancel();
        }
    }

private:
    size_t m_count;
    rclcpp::TimerBase::SharedPtr m_timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_publisher;

    const std::string m_node_name { "talker2" };
    const std::string m_topic_name { "chatter" };
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<KfjTalker2>());
    rclcpp::shutdown();

    return 0;
}
