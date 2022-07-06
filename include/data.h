#include <fcntl.h>
#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <serial/serial.h>
#include <tf_mini.h>

namespace tf_mini_ros {
class Data {
public:
  Data(ros::NodeHandle &nh);
  ~Data(){};
  void run();

  void initSerial() {
    serial::Timeout timeout = serial::Timeout::simpleTimeout(50);
    serial_.setPort(port_name_);
    serial_.setBaudrate(baud_rate_);
    serial_.setTimeout(timeout);
    if (serial_.isOpen())
      return;
    try {
      serial_.open();
    } catch (serial::IOException &e) {
      ROS_ERROR("Cannot open port");
    }
  }

private:
  std::string port_name_;
  int baud_rate_;
  serial::Serial serial_;
  TfMini tf_mini_;
};
} // namespace tf_mini_ros
