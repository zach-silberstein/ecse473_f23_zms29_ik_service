# LAB6

### This project creates a service that returns the inverse kinematics solutions given an end effector pose of the robot arm used in the ARIAC competition

The project contains both a service and a client. The client calls the service with a given pose and then prints the joint angles returned by the service for each solution.

#### Initial setup
To run this project the cwru_ariac_2019 package must be installed and can be found [here](https://github.com/cwru-eecs-373/cwru_ariac_2019). Specifically, this project uses the ur_kinematics package which needed to generate the inverse kinematics solutions.

Additional information about the competition and useful documentation can be found [here](https://bitbucket.org/osrf/ariac/wiki/2019/Home).


#### Usage: 
To run the project, launch the launch file by running  
    `roslaunch roslaunch ik_service ik_service.launch`  
Doing the above will only launch the service. To launch the client, which shows off example ussage of the service, run  
    `rosrun ik_service ik_client_node`  
If the client is run succesfully the output should be:  
    Call to ik_service returned [4] solutions  
    Solution 1: [6.056550, 6.020876, 0.936839, 4.037859, 4.712389, 4.485754] radians  
    Solution 2: [6.056550, 0.607225, 5.346346, 5.042003, 4.712389, 4.485754] radians  
    Solution 3: [3.368228, 2.534368, 0.936839, 4.382775, 1.570796, 4.939024] radians  
    Solution 4: [3.368228, 3.403901, 5.346346, 5.386919, 1.570796, 4.939024] radians  
