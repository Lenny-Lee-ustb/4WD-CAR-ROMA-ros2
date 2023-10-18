#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "tf2_ros/buffer.h"

class TFRepublisher : public rclcpp::Node
{
public:
    TFRepublisher()
        : Node("tf_republisher"), tf_buffer_(this->get_clock()), tf_listener_(tf_buffer_)
    {
        broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
        republishTransform();
    }

private:
    void republishTransform()
    {
        geometry_msgs::msg::TransformStamped transform;
        try {
            // Wait for the transform to be available
            rclcpp::sleep_for(std::chrono::seconds(2));

            transform = tf_buffer_.lookupTransform("T265", "base_footprint", rclcpp::Time(0));

            // Modify the frame ids for republishing
            transform.header.frame_id = "camera_pose_frame";
            transform.child_frame_id = "base_footprint";

            broadcaster_->sendTransform(transform);
            RCLCPP_INFO(this->get_logger(), "Transform republished.");
        }
        catch (tf2::TransformException &ex) {
            RCLCPP_ERROR(this->get_logger(), "%s", ex.what());
            rclcpp::shutdown();
        }
    }

    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> broadcaster_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TFRepublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
