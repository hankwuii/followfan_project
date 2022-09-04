#include <ros/ros.h>
#include "server/mysrv.h"
#include <iostream>
using namespace std;

bool add(rospy_tutorials::AddTwoInts::Request  &req,
         rospy_tutorials::AddTwoInts::Response &res)
 {
   res.step = req.a / 1.8;
   ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
   ROS_INFO("sending back response: [%ld]", (long int)res.step);
   return true;
 }

int main(int argc, char** argv)
 {
   ros::init(argc, argv, "add_two_ints_server"); //初始化node
   ros::NodeHandle n; // node handler

   ros::ServiceServer service = n.advertiseService("add_two_ints", add); //定義service server以及callback function
   ROS_INFO("Ready to add two ints.");
   ros::spin(); //持續運行此node

   return 0;
}