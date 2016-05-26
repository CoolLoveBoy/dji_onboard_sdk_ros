#include <ros/ros.h>
#include <stdio.h>
#include <dji_sdk/dji_drone.h>
#include <cstdlib>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

using namespace DJI::onboardSDK;

int main(int argc, char **argv)
{
  int temp32;
  ros::init(argc, argv, "waypoint_navigator")
  ros::NodeHandle nh;
  DJIDrone* drone = new DJIDrone(nh);

	//virtual RC test data
	uint32_t virtual_rc_data[16];
	//set frequency test data
	uint8_t msg_frequency_data[16] = {1,2,3,4,3,2,1,2,3,4,3,2,1,2,3,4};
	//waypoint action test data
  dji_sdk::WaypointList newWaypointList;
  dji_sdk::Waypoint waypoint0;
  dji_sdk::Waypoint waypoint1;
  dji_sdk::Waypoint waypoint2;
  dji_sdk::Waypoint waypoint3;
  dji_sdk::Waypoint waypoint4;

  //groundstation test data
	dji_sdk::MissionWaypointTask waypoint_task;
	dji_sdk::MissionWaypoint 	 waypoint;
	dji_sdk::MissionHotpointTask hotpoint_task;
	dji_sdk::MissionFollowmeTask followme_task;
	dji_sdk::MissionFollowmeTarget followme_target;

  drone->request_sdk_permission_control();
  printf("Control requested.");

  while(1)
  {
	  ros::spinOnce();
    temp32 = getchar();

    if(temp32 == 'a')
    {
      //mission waypoint upload
      waypoint_task.velocity_range = 5;
      waypoint_task.idle_velocity = 3;
      waypoint_task.action_on_finish = 0;
      waypoint_task.mission_exec_times = 1;
      waypoint_task.yaw_mode = 4;
      waypoint_task.trace_mode = 0;
      waypoint_task.action_on_rc_lost = 0;
      waypoint_task.gimbal_pitch_mode = 0;

      waypoint.latitude = 47.453184;
      waypoint.longitude = 8.680281;
      waypoint.altitude = 1.2;
      waypoint.damping_distance = 0;
      waypoint.target_yaw = 0;
      waypoint.target_gimbal_pitch = 0;
      waypoint.turn_mode = 0;
      waypoint.has_action = 0;

      waypoint_task.mission_waypoint.push_back(waypoint);

      waypoint.latitude = 47.453562;
      waypoint.longitude = 8.681361;
      waypoint.altitude = 1.2;
      waypoint.damping_distance = 0;
      waypoint.target_yaw = 0;
      waypoint.target_gimbal_pitch = 0;
      waypoint.turn_mode = 0;
      waypoint.has_action = 0;

      waypoint_task.mission_waypoint.push_back(waypoint);

      waypoint.latitude = 47.453249;
      waypoint.longitude = 8.680707;
      waypoint.altitude = 1.2;
      waypoint.damping_distance = 0;
      waypoint.target_yaw = 0;
      waypoint.target_gimbal_pitch = 0;
      waypoint.turn_mode = 0;
      waypoint.has_action = 0;

      waypoint_task.mission_waypoint.push_back(waypoint);

      waypoint.latitude = 47.453331;
      waypoint.longitude = 8.681043;
      waypoint.altitude = 1.2;
      waypoint.damping_distance = 0;
      waypoint.target_yaw = 0;
      waypoint.target_gimbal_pitch = 0;
      waypoint.turn_mode = 0;
      waypoint.has_action = 0;

      waypoint_task.mission_waypoint.push_back(waypoint);

      waypoint.latitude = 47.452992;
      waypoint.longitude = 8.680374;
      waypoint.altitude = 1.2;
      waypoint.damping_distance = 0;
      waypoint.target_yaw = 0;
      waypoint.target_gimbal_pitch = 0;
      waypoint.turn_mode = 0;
      waypoint.has_action = 0;

      waypoint_task.mission_waypoint.push_back(waypoint);

      waypoint.latitude = 47.453382;
      waypoint.longitude = 8.681481;
      waypoint.altitude = 1.2;
      waypoint.damping_distance = 0;
      waypoint.target_yaw = 0;
      waypoint.target_gimbal_pitch = 0;
      waypoint.turn_mode = 0;
      waypoint.has_action = 0;

      waypoint_task.mission_waypoint.push_back(waypoint);

      drone->mission_waypoint_upload(waypoint_task);
    }

    return 0;
  }

}
