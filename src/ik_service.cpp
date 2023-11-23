#include "ros/ros.h"
#include "ik_service/PoseIK.h"

bool pose_ik(ik_service::PoseIK::Request  &req,
         ik_service::PoseIK::Response &res)
{
  ROS_INFO("Pose Information...");
  res.num_sols = -1;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_ik_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("pose_ik", pose_ik);
  ros::spin();

  return 0;
}