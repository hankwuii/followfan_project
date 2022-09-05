#include <ros/ros.h>
#include "server/mysrv.h"
#include <iostream>
using namespace std;

bool division(server::mysrv::Request  &req,
              server::mysrv::Response &res)
 {
   res.step = req.b / 1.8;
   ROS_INFO("Request: x=%ld, y=%ld", (string)req.a, (long int)req.b);
   ROS_INFO("sending back response: [%ld]", (float)res.step);
   return true;
 }

int main(int argc, char** argv)
 {
   ros::init(argc, argv, "motor_rotate_server"); //初始化node
   ros::NodeHandle n; // node handler

   ros::ServiceServer service = n.advertiseService("motor_rotate", division); //定義service server以及callback function
   ROS_INFO("Ready to act.");
   ros::spin(); //持續運行此node

   return 0;
}