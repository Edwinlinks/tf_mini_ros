//
// Created by luotinkai on 2022/7/4.
//

#include <ros/ros.h>
#include <sensor_msgs/Range.h>
#include <serial/serial.h>

namespace tf_mini_ros {

struct tfMiniData {
  double distance;
  double strength;
};

class TfMini {
public:
  TfMini();
  void unpack();

  void clearBuffer() {
    rx_buffer_.clear();
    rx_len_ = 0;
  }

  ros::Publisher tf_mini_pub_;
  std::vector<uint8_t> rx_buffer_;
  int rx_len_;
  tfMiniData tf_mini_data_;
  sensor_msgs::Range tf_data_;

private:
  void publishData();
  int checkSum();

  ros::Time last_get_, last_send_;
  const int k_frame_length_ = 128, k_header_length_ = 5, k_cmd_id_length_ = 2,
            k_tail_length_ = 2;
  const int k_unpack_buffer_length_ = 256;
  uint8_t unpack_buffer_[256]{};
  int client_id_;
};
} // namespace tf_mini_ros