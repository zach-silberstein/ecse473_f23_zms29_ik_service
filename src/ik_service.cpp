#include "ros/ros.h"
#include "ik_service/PoseIK.h"

bool pose_ik(ik_service::PoseIK::Request  &req,
         ik_service::PoseIK::Response &res)
{
  ROS_INFO("Pose Information...");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("pose_ik", pose_ik);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}