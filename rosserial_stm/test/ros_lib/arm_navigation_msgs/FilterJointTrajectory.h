#ifndef _ROS_SERVICE_FilterJointTrajectory_h
#define _ROS_SERVICE_FilterJointTrajectory_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/RobotState.h"
#include "ros/duration.h"
#include "arm_navigation_msgs/JointLimits.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"

namespace arm_navigation_msgs
{

static const char FILTERJOINTTRAJECTORY[] = "arm_navigation_msgs/FilterJointTrajectory";

  class FilterJointTrajectoryRequest : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      arm_navigation_msgs::RobotState start_state;
      uint8_t limits_length;
      arm_navigation_msgs::JointLimits st_limits;
      arm_navigation_msgs::JointLimits * limits;
      ros::Duration allowed_time;

    FilterJointTrajectoryRequest():
      trajectory(),
      start_state(),
      limits_length(0), limits(NULL),
      allowed_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->start_state.serialize(outbuffer + offset);
      *(outbuffer + offset++) = limits_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->allowed_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_time.sec);
      *(outbuffer + offset + 0) = (this->allowed_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->start_state.deserialize(inbuffer + offset);
      uint8_t limits_lengthT = *(inbuffer + offset++);
      if(limits_lengthT > limits_length)
        this->limits = (arm_navigation_msgs::JointLimits*)realloc(this->limits, limits_lengthT * sizeof(arm_navigation_msgs::JointLimits));
      offset += 3;
      limits_length = limits_lengthT;
      for( uint8_t i = 0; i < limits_length; i++){
      offset += this->st_limits.deserialize(inbuffer + offset);
        memcpy( &(this->limits[i]), &(this->st_limits), sizeof(arm_navigation_msgs::JointLimits));
      }
      this->allowed_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_time.sec);
      this->allowed_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_time.nsec);
     return offset;
    }

    const char * getType(){ return FILTERJOINTTRAJECTORY; };
    const char * getMD5(){ return "6611fde5aa78b0bd96efafadb00dff05"; };

  };

  class FilterJointTrajectoryResponse : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;

    FilterJointTrajectoryResponse():
      trajectory(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FILTERJOINTTRAJECTORY; };
    const char * getMD5(){ return "b07a38e3291ec1857951df2bfd71735e"; };

  };

  class FilterJointTrajectory {
    public:
    typedef FilterJointTrajectoryRequest Request;
    typedef FilterJointTrajectoryResponse Response;
  };

}
#endif
