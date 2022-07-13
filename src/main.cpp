#include <data.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "tf_mini_ros");
  ros::NodeHandle nh("~");
  tf_mini_ros::Data *data;
  data = new tf_mini_ros::Data(nh);
  ROS_INFO("Reading TF mini data.");
  ros::Rate loop_rate(100);
  while (ros::ok()) {
    ros::spinOnce();
    data->run();
    loop_rate.sleep();
  }
}
