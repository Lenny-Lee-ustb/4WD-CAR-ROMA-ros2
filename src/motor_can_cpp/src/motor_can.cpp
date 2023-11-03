#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#endif

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/polygon_stamped.hpp"
#include "motor_can_cpp/Dji_M3508.hpp"
#include "motor_can_cpp/can_tools.h"
#include "custom_interfaces/msg/actuator_command.hpp"
#include "custom_interfaces/msg/actuator_state.hpp"

// socket taojiezi
int s;
bool stopFlag=0;
std::string canSeries, passwd;

class MotorCanNode : public rclcpp::Node
{
public:
    // 构造函数,有一个参数为节点名称
    MotorCanNode(std::string name) : Node(name)
    {
        // get params
        CanSeries = this->declare_parameter<std::string>("CanSeries", "can3");
        password = this->declare_parameter<std::string>("password", "1234");
        wheel_radius = this->declare_parameter<double>("wheel_radius", 0.07);
        motor_ratio = this->declare_parameter<double>("motor_ratio", 5.18);
        Kp = this->declare_parameter<double>("Kp", 1.2);
        Ki = this->declare_parameter<double>("Ki", 0.4);
        Kd = this->declare_parameter<double>("Kd", 0.0);
        IBound = this->declare_parameter<double>("IBound", 0.3);
        dt = this->declare_parameter<double>("dt", 0.001);
        preTorque = this->declare_parameter<double>("preTorque", 0.1);
        filter_a1 = this->declare_parameter<double>("filter_a1", 0.828);
        filter_b0 = this->declare_parameter<double>("filter_b0", 0.086);
        filter_b1 = this->declare_parameter<double>("filter_b1", 0.086);
        K_motor = this->declare_parameter<double>("K_motor", 0.0813);
        maxTorque = this->declare_parameter<double>("maxTorque", 1.6);
        minTorque = this->declare_parameter<double>("minTorque", -1.6);

        canSetup(CanSeries, password);
        s = socketCANInit(CanSeries);
        canSeries = CanSeries;
        passwd = password;
        txFrame.can_id = 0x200;
        txFrame.can_dlc = 8;
        rxFrame.can_dlc = 8;

        for (auto i = 0; i < 4; i++)
        {
            if (motor[i].MotorSetup(Kp, Ki, Kd, IBound, dt, preTorque, filter_a1, filter_b0, filter_b1, K_motor, maxTorque, minTorque))
            {
                RCLCPP_INFO(this->get_logger(), "motor[%d] setup", i);
            }
            // motor[i].speedDes = .8;
            // motor[i].torqueDes = 0.1;
        }

        motorRxCount = 0;
        motor_state.actuator_state.resize(4);
        motor_state.actuator_state[0].name = "Front Left";
        motor_state.actuator_state[1].name = "Front Right";
        motor_state.actuator_state[2].name = "Rear Right";
        motor_state.actuator_state[3].name = "Rear Left";

        // init sub and pub
        cmd_subscriber_ = this->create_subscription<custom_interfaces::msg::ActuatorCommand>("motor_cmd", 10, std::bind(&MotorCanNode::command_callback, this, std::placeholders::_1));
        state_publisher_ = this->create_publisher<custom_interfaces::msg::ActuatorState>("motor_state", 10);
        conrtol_loop_ = this->create_wall_timer(std::chrono::nanoseconds(1000000), std::bind(&MotorCanNode::control_loop_callback, this));
        can_rx_timer_ = this->create_wall_timer(std::chrono::nanoseconds(100000), std::bind(&MotorCanNode::can_rx_timer_callback, this));
        RCLCPP_INFO(this->get_logger(), "%s节点已经启动.", name.c_str());
    }

private:
    // variables
    rclcpp::Subscription<custom_interfaces::msg::ActuatorCommand>::SharedPtr cmd_subscriber_;
    rclcpp::Publisher<custom_interfaces::msg::ActuatorState>::SharedPtr state_publisher_;
    rclcpp::TimerBase::SharedPtr conrtol_loop_, can_rx_timer_;
    custom_interfaces::msg::ActuatorState motor_state;
    Motor_M3508 motor[4];
    std::string CanSeries, password;
    double Kp, Ki, Kd, IBound, dt, preTorque, filter_a1, filter_b0, filter_b1, K_motor, minTorque, maxTorque;
    double wheel_radius, motor_ratio;
    int motorRxCount, is_cmd_active;
    struct can_frame txFrame, rxFrame;

    // subscribe and CAN send
    void command_callback(const custom_interfaces::msg::ActuatorCommand::SharedPtr motor_cmd)
    {
        int motorNum = motor_cmd->actuator_command.size();
        is_cmd_active = 20;
        for (auto i = 0; i < motorNum; i++)
        {
            motor[i].drive_mode = motor_cmd->drive_mode;
            motor[i].speedDes = motor_cmd->actuator_command[i].velocity;
            motor[i].torqueDes = motor_cmd->actuator_command[i].effort;
        }
    }

    // control_loop_callback 1000Hz
    void control_loop_callback()
    {   
        if (stopFlag)
        {
            printf("stop");
            for (auto i = 0; i < 4; i++)
            {
                motor[i].speedDes = 0.0;
            }
        }

        if (motor[0].drive_mode==0)
        {
            for (auto i = 0; i < 4; i++){
                motor[i].speedDes = 0.0;
                motor[i].curTx = motor[i].MotorVelocityTune();
            }
        } else if (motor[0].drive_mode==1)
        {
            for (auto i = 0; i < 4; i++){
                motor[i].curTx = motor[i].MotorVelocityTune();
            }
        } else if (motor[0].drive_mode==2){
            for (auto i = 0; i < 4; i++){
                motor[i].curTx = motor[i].MotorTorqueTune();
            }
        } else{
            printf("error");
            for (auto i = 0; i < 4; i++)
            {
                motor[i].speedDes = 0.0;
                motor[i].curTx = motor[i].MotorVelocityTune();
            }
        }

        for (int j = 0; j < 4; j++)
        {
            txFrame.data[2 * j] = motor[j].curTx >> 8;     // 控制电流值高 8 位
            txFrame.data[2 * j + 1] = motor[j].curTx >> 0; // 控制电流值低 8 位
        }
        if (is_cmd_active>=0){
            if (write(s, &txFrame, sizeof(struct can_frame)) == -1)
            {
                printf("send error in txMotorThread\n");
            }
            is_cmd_active--;
        }
        
    }

    // receive CAN Frame callback
    void can_rx_timer_callback()
    {
        int ID;
        if (read(s, &rxFrame, sizeof(struct can_frame)) < 0)
        {
            perror("Read Error at motor can\n");
            motorRxCount = -1;
        }

        if (int(rxFrame.can_id) > 0x200 && int(rxFrame.can_id) < 0x205)
        {
            ID = int(rxFrame.can_id - 0x200) - 1;
            motor[ID].angleRx = (rxFrame.data[0] << 8) + rxFrame.data[1];
            motor[ID].velRx = (rxFrame.data[2] << 8) + rxFrame.data[3];
            motor[ID].curRx = (rxFrame.data[4] << 8) + rxFrame.data[5];
            motor[ID].thermalRx = rxFrame.data[6]; // 'C

            motor[ID].speed = wheel_radius * (motor[ID].velRx / motor_ratio) * (2.0 * M_PI / 60.0);
            motor[ID].tor = motor[ID].K * motor[ID].curRx / 16384.0 * 20.0;
            motor[ID].temperature = double(motor[ID].thermalRx);

            motor[ID].speedFiltered = motor[ID].LowPassFilter(motor[ID].speedFiltered_Last, motor[ID].speed, motor[ID].speedLast);
            motor[ID].torFiltered = motor[ID].LowPassFilter(motor[ID].torFiltered_Last, motor[ID].tor, motor[ID].torLast);

            motor[ID].speedLast = motor[ID].speed;
            motor[ID].speedFiltered_Last = motor[ID].speedFiltered;
            motor[ID].torLast = motor[ID].tor;
            motor[ID].torFiltered_Last = motor[ID].torFiltered;

            // due to the configuration, it needs change the direction
            if ((ID == 0) || (ID == 3))
            {
                motor_state.actuator_state[ID].velocity = motor[ID].speedFiltered;
                motor_state.actuator_state[ID].effort = motor[ID].torFiltered;
            }
            else if ((ID == 1) || (ID == 2))
            {
                motor_state.actuator_state[ID].velocity = -motor[ID].speedFiltered; // m/s
                motor_state.actuator_state[ID].effort = -motor[ID].torFiltered;   // -16384~0~16384 -> -20-0-20A -> -1.626 - 1.626Nm
            }
        }

        if (motorRxCount % 4 == 0)
        {
            motor_state.header.stamp = rclcpp::Clock().now();
            state_publisher_->publish(motor_state);
        }
        motorRxCount++;
    }
};

void signalCallback(int signum)
{
    std::cout << "\nGet Ctrl+c " << signum << " signal to shutdwon the node." << std::endl;
    can_frame frame;
    frame.can_id = 0x200;
    frame.can_dlc = 8;
    for (int i = 0; i < 5; i++)
    {
        for (int i = 0; i < 8; i++)
        {
            frame.data[i] = 0;
        }
        write(s, &frame, sizeof(struct can_frame));
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    stopFlag = 1;
    canShutdown(canSeries, passwd);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "shutdown." << std::endl;
    rclcpp::shutdown();
}

int main(int argc, char **argv)
{
    /* 初始化rclcpp*/
    rclcpp::init(argc, argv);
    /*产生一个motor_can的节点*/
    auto node = std::make_shared<MotorCanNode>("motor_can");
    /*运行节点，并检测退出信号 Ctrl+C*/
    signal(SIGINT, signalCallback);
    rclcpp::spin(node);
    // /*停止运行*/
    // rclcpp::shutdown();
    return 0;
}
