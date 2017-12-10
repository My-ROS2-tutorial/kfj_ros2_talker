#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

class KfjTalker2 : public rclcpp::Node
{
public:
    KfjTalker2();

private:
    void timer_callback();

private:
    size_t m_count; //!< number of messages sent until now
    rclcpp::TimerBase::SharedPtr m_timer;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_publisher;
};
