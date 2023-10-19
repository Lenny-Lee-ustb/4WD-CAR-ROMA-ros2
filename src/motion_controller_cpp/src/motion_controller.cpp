#include "rclcpp/rclcpp.hpp"
#include "sbus_interface/msg/sbus.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "custom_interfaces/msg/actuator_command.hpp"

class Motion_controller_node : public rclcpp::Node
{
public:
    Motion_controller_node(std::string name) : Node(name)
    {
        speed_max_ = this->declare_parameter<double>("speedMax", 2.0);
        angle_max_ = this->declare_parameter<double>("angleMax", 0.7);
        min_speed_threshold_ = this->declare_parameter<double>("minSpeedThreshold", 0.15);

        motor_cmd_.actuator_command.resize(4);
        motor_cmd_.actuator_command[0].name = "Front Left";
        motor_cmd_.actuator_command[1].name = "Front Right";
        motor_cmd_.actuator_command[2].name = "Rear Right";
        motor_cmd_.actuator_command[3].name = "Rear Left";
        servo_cmd_.actuator_command.resize(2);
        servo_cmd_.actuator_command[0].name = "Front Left";
        servo_cmd_.actuator_command[1].name = "Front Right";
        moveable_in_ = 0;
        direct_in_ = 0;
        control_in_ = 0;

        sbus_subs_ = this->create_subscription<sbus_interface::msg::Sbus>("sbus", 10, std::bind(&Motion_controller_node::sbus_command_callback, this, std::placeholders::_1));
        upper_cmd_subs_ = this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", 10, std::bind(&Motion_controller_node::upper_command_callback, this, std::placeholders::_1));
        motor_cmd_pub_ = this->create_publisher<custom_interfaces::msg::ActuatorCommand>("motor_cmd", 10);
        servo_cmd_pub_ = this->create_publisher<custom_interfaces::msg::ActuatorCommand>("servo_cmd", 10);
        command_info_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("command_info",10);
        cmd_trans_timer_ = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&Motion_controller_node::CmdTrans, this));
        RCLCPP_INFO(this->get_logger(), "%s节点已经启动.", name.c_str());
    }

private:
    rclcpp::Subscription<sbus_interface::msg::Sbus>::SharedPtr sbus_subs_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr upper_cmd_subs_;
    rclcpp::Publisher<custom_interfaces::msg::ActuatorCommand>::SharedPtr motor_cmd_pub_, servo_cmd_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr command_info_pub_;
    rclcpp::TimerBase::SharedPtr cmd_trans_timer_;
    geometry_msgs::msg::Twist upper_cmd_, sbus_cmd_, cmd_;
    custom_interfaces::msg::ActuatorCommand motor_cmd_, servo_cmd_;

    int moveable_in_, direct_in_, control_in_, cmdMuxCount_;
    bool failsafe_, frame_lost_;
    double speed_max_, angle_max_, min_speed_threshold_;

    void sbus_command_callback(const sbus_interface::msg::Sbus::SharedPtr sbus_cmd);
    void upper_command_callback(const geometry_msgs::msg::Twist::SharedPtr upper_cmd);

    void CmdTrans();
    void fwdKinematicCal(const double vX, const double avZ);
};

void Motion_controller_node::sbus_command_callback(const sbus_interface::msg::Sbus::SharedPtr sbus_cmd)
{
    int longSbusIn, steerSbusIn = 0; // from upper controller

    longSbusIn = sbus_cmd->mapped_channels[1] - 500;
    steerSbusIn = sbus_cmd->mapped_channels[0] - 500;
    // remap steer angle to symatric[-500, 500]
    moveable_in_ = sbus_cmd->mapped_channels[3];
    direct_in_ = sbus_cmd->mapped_channels[7];
    control_in_ = sbus_cmd->mapped_channels[5];
    failsafe_ = sbus_cmd->failsafe;
    frame_lost_ = sbus_cmd->frame_lost;
    // signal inout and store
    sbus_cmd_.linear.x = double(longSbusIn) / 500.0 * speed_max_;
    sbus_cmd_.angular.z = - double(steerSbusIn) / 500.0 * angle_max_;
}

void Motion_controller_node::upper_command_callback(const geometry_msgs::msg::Twist::SharedPtr upper_cmd)
{
    upper_cmd_ = *upper_cmd;
}

void Motion_controller_node::CmdTrans()
{
    if ((!moveable_in_ == !control_in_) || failsafe_ == 1 || frame_lost_ == 1)
    {
        cmd_.linear.x =0;
        cmd_.angular.z =0;
        // cmd state == 0, cmd send zero to platform
        if ((failsafe_ == 1 || frame_lost_ == 1)  && cmdMuxCount_ % 100 == 0)
        {
            RCLCPP_WARN(this->get_logger(), "RC SIGNAL LOST!!! Check RC status!");
        }
        else if (cmdMuxCount_ % 100 == 0)
        {
            RCLCPP_WARN(this->get_logger(), "moveable_in=%d, control_in=%d", !!moveable_in_, !!control_in_);
        }
    }
    else
    {
        if (!moveable_in_ == false)
        {
            cmd_ = sbus_cmd_;
            cmd_.linear.z = 1;
            // cmd linear.z == 1, cmd comes from upper controller
        }
        if (!control_in_ == false)
        {
            cmd_ = upper_cmd_;
            cmd_.linear.z = -1;
            // cmd linear.z == 1, cmd comes from sbus
        }
    }
    cmd_.linear.x = fmin(fmax(cmd_.linear.x, -speed_max_), speed_max_);
    cmd_.angular.z = fmin(fmax(cmd_.angular.z, -angle_max_), angle_max_);

    fwdKinematicCal(cmd_.linear.x, cmd_.angular.z);
    command_info_pub_->publish(cmd_);
    cmdMuxCount_++;
}

void Motion_controller_node::fwdKinematicCal(const double vX, const double avZ)
{
    motor_cmd_.drive_mode = "velocity";
    motor_cmd_.actuator_command[0].velocity = vX;
    motor_cmd_.actuator_command[1].velocity = -vX;
    motor_cmd_.actuator_command[2].velocity = -vX;
    motor_cmd_.actuator_command[3].velocity = vX;
    // motor_cmd_.actuator_command[0].effort = vX;
    // motor_cmd_.actuator_command[1].effort = -vX;
    // motor_cmd_.actuator_command[2].effort = -vX;
    // motor_cmd_.actuator_command[3].effort = vX;
    motor_cmd_pub_->publish(motor_cmd_);

    servo_cmd_.actuator_command[0].position  = avZ;
    servo_cmd_.actuator_command[1].position  = avZ;
    servo_cmd_pub_->publish(servo_cmd_);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<Motion_controller_node>("Motion_controller_node");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
