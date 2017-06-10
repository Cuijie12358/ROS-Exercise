#include "ros/ros.h"
#include "testpack/DirAndDis.h"
bool reflash(testpack::DirAndDis::Request  &req,
             testpack::DirAndDis::Response &res)
{

  res.x = req.right - req.left + res.x;
  res.y = req.up - req.down + res.y;


  ROS_INFO("request: up=%long d, down=%long d ,left=%long d, right=%long d" ,(long int)req.up, (long int)req.down, (long int)req.left, (long int)req.right);
  ROS_INFO("sending back response: (%long d,%long d)", (long int)res.x, (long int)res.y);
  return true;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "dir_and_dis_server");
  ros::NodeHandle pose;

  ros::ServiceServer service = pose.advertiseService("dir_and_dis", reflash);
  ROS_INFO("Ready to set position.");
  ros::spin();

  return 0;
}

