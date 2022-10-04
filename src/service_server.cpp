#include <ros/ros.h>
#include "motor_server/mysrv.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
你好嗎
float motor_step;

bool division_Callback(motor_server::mysrv::Request  &req, motor_server::mysrv::Response &res){
   motor_step = req.angle / 1.8;
   cout<<"step = "<< motor_step <<endl;
}

int main(int argc, char** argv){
   ros::init(argc, argv, "service_server"); 
   ros::NodeHandle n; 
   ros::ServiceServer service = n.advertiseService("mysrv", division_Callback); 

   ros::spin();

   return 0;
}
