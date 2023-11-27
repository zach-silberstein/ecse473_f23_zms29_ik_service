#include "ros/ros.h"
#include "ik_service/PoseIK.h"
#include "ur_kinematics/ur_kin.h"

bool pose_ik(ik_service::PoseIK::Request  &req,
         ik_service::PoseIK::Response &res)
{

  double T[4][4] = {{0.0, -1.0, 0.0, req.part_pose.position.x}, \
  {0.0, 0.0, 1.0, req.part_pose.position.y}, \
  {-1.0, 0.0, 0.0 , req.part_pose.position.z}, \
  {0.0, 0.0, 0.0, 1.0}};

  // Variable to receive the number of solutions returned
  int num_sol;
  // Allocate space for up to eight solutions of six joint angles
  double q_sols[8][6];
  // Inverse kinematic solution(s)
  num_sol = ur_kinematics::inverse(&T[0][0], &q_sols[0][0], 0.0);

  res.num_sols = num_sol;

  for (int sol = 0; sol < num_sol; sol++) {
    for (int angle = 0; angle < 6; angle++) {
      res.joint_solutions[sol].joint_angles[angle] = q_sols[sol][angle];
    }
  }

  
  /*
  // Initial joint angles for the arm
  double q[] = {3.14, -1.13, 1.51, 3.77, -1.51, 0};
  // Variable to receive forward kinematic solution
  double T[4][4];
  // Forward kinematic solution
  ur_kinematics::forward((double *)&q[0], (double *)&T[0][0]);
  // The inputs into the function are technically the memory locations of the memory where
  // the six joint angles are held (q) and the 16 entries for the T matrix can be placed.
  ROS_INFO("[%f,%f,%f,%f],[%f,%f,%f,%f],[%f,%f,%f,%f],[%f,%f,%f,%f]",\
      T[0][0], T[0][1], T[0][2], T[0][3], T[1][0], T[1][1], T[1][2] ,T[1][3],\
      T[2][0], T[2][1], T[2][2], T[2][3], T[3][0], T[3][1], T[3][2] ,T[3][3]);
  */
  
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