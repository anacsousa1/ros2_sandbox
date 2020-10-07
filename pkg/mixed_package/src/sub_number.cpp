#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp" // Change 'example_interfaces'

class SubNode : public rclcpp::Node // Change 'SubNode'
{ 
public:
    SubNode() : Node("sub_node") // Change 'SubNode' and 'sub_node'
    { 
        numberSubscriber_ = this->create_subscription<example_interfaces::msg::Int64>( // Change type
            "/data/number", 10,     // Change topic
            std::bind(&SubNode::numberCallback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Sub node has been started."); // Change 'Sub node'
    }

private:
    void numberCallback(const example_interfaces::msg::Int64::SharedPtr msg) // Change 'numberCallback'
    {
        RCLCPP_INFO(this->get_logger(), "I heard %d", msg->data);
    }

    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr numberSubscriber_; // Change type
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubNode>(); // Change 'SubNode'
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}