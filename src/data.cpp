#include <data.h>
#include <ros/ros.h>

namespace tf_mini_ros {
Data::Data(ros::NodeHandle &nh) {
  if (!nh.getParam("serial_port", port_name_) ||
      !nh.getParam("baud_rate", baud_rate_)) {
    ROS_ERROR("Could not find parameters");
  }
  initSerial();
}

void Data::run() {
  try {
    if (serial_.available()) {
      tf_mini_.rx_len_ = (int)serial_.available();
      serial_.read(tf_mini_.rx_buffer_, tf_mini_.rx_len_);
    }
  } catch (serial::IOException &e) {
  }
  tf_mini_.unpack();
  tf_mini_.clearBuffer();
}
} // namespace tf_mini_ros
