/**************************************************************************************************************************************
/* Benewake TFplus infrared range sensor TFplus ROS package
/* Version 1.0
/**************************************************************************************************************************************

/**************************************************************************************************************************************
/* Package Information
/**************************************************************************************************************************************
  Package:			tfplus_ros
  Node:				tfplus_ros_node
  Published Topics:
    /tfplus_ros_node/TFplus (sensor_msgs/Range)
      The distance of object detected. 
      Note: This node won't publish topic if no object exists within TFplus's measurement range, and the behavior can be changed in file 
      /src/TFplus_ros_node.cpp
      
/**************************************************************************************************************************************
/* Quick Start
/**************************************************************************************************************************************
  $ cd tfplus_ros/src
  $ catkin_make
  $ roslaunch tfplus_ros tfplus.launch
