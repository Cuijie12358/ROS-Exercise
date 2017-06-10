#include "ros/ros.h"
#include "testpack/DirAndDis.h"
#include <cstdlib>

int main(int argc,char **argv)
{
  ros::init(argc,argv,"dir_and_dis_client");
  if(argc != 5)
  {
    ROS_INFO("usage: set a new position (x,y)");
    return 1;
  }

  ros::NodeHandle pose;
 ros::ServiceClient client = pose.serviceClient<testpack::DirAndDis>("dir_and_dis");
  testpack::DirAndDis srv;
  srv.request.up = atoll(argv[1]);
  srv.request.down = atoll(argv[2]);
  srv.request.left = atoll(argv[3]);
  srv.request.right = atoll(argv[4]);
  if(client.call(srv))
  {
    ROS_INFO("new position: (%long d,%long d)",(long int)srv.response.x,(long int)srv.response.y);
  }
  else
  {
    ROS_ERROR("Failed to call service dir_and_dis");
    return 1;
  }

  return 0;
}
