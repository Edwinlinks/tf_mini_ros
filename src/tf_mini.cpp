//
// Created by luotinkai on 2022/7/4.
//
#include <tf_mini.h>

namespace tf_mini_ros {

TfMini::TfMini() : client_id_(0) {
  ros::NodeHandle root_nh;
  tf_mini_pub_ = root_nh.advertise<sensor_msgs::Range>("/tf_mini", 100);
}

int TfMini::checkSum() {
  int sumCheck = (0x59 + 0x59) % 256;
  for (int i = 2; i < rx_len_ - 1; i++) {
    sumCheck = (sumCheck + rx_buffer_[i]) % 256;
  }
  return sumCheck;
}

void TfMini::unpack() {
  if (checkSum() == rx_buffer_[8]) {
    tf_mini_data_.distance =
        (float)((rx_buffer_[3] << 8 | rx_buffer_[2]) / 100.0);
    tf_mini_data_.strength = (float)(rx_buffer_[5] << 8 | rx_buffer_[4]);
  }
  publishData();
}

void TfMini::publishData() {
  tf_data_.range = tf_mini_data_.distance;
  tf_data_.field_of_view = tf_mini_data_.strength;
  tf_mini_pub_.publish(tf_data_);
}
} // namespace tf_mini_ros