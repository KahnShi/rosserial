#ifndef _ROS_arm_navigation_msgs_Constraints_h
#define _ROS_arm_navigation_msgs_Constraints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/JointConstraint.h"
#include "arm_navigation_msgs/PositionConstraint.h"
#include "arm_navigation_msgs/OrientationConstraint.h"
#include "arm_navigation_msgs/VisibilityConstraint.h"

namespace arm_navigation_msgs
{

  class Constraints : public ros::Msg
  {
    public:
      uint8_t joint_constraints_length;
      arm_navigation_msgs::JointConstraint st_joint_constraints;
      arm_navigation_msgs::JointConstraint * joint_constraints;
      uint8_t position_constraints_length;
      arm_navigation_msgs::PositionConstraint st_position_constraints;
      arm_navigation_msgs::PositionConstraint * position_constraints;
      uint8_t orientation_constraints_length;
      arm_navigation_msgs::OrientationConstraint st_orientation_constraints;
      arm_navigation_msgs::OrientationConstraint * orientation_constraints;
      uint8_t visibility_constraints_length;
      arm_navigation_msgs::VisibilityConstraint st_visibility_constraints;
      arm_navigation_msgs::VisibilityConstraint * visibility_constraints;

    Constraints():
      joint_constraints_length(0), joint_constraints(NULL),
      position_constraints_length(0), position_constraints(NULL),
      orientation_constraints_length(0), orientation_constraints(NULL),
      visibility_constraints_length(0), visibility_constraints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = joint_constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_constraints_length; i++){
      offset += this->joint_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = position_constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position_constraints_length; i++){
      offset += this->position_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = orientation_constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < orientation_constraints_length; i++){
      offset += this->orientation_constraints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = visibility_constraints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < visibility_constraints_length; i++){
      offset += this->visibility_constraints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t joint_constraints_lengthT = *(inbuffer + offset++);
      if(joint_constraints_lengthT > joint_constraints_length)
        this->joint_constraints = (arm_navigation_msgs::JointConstraint*)realloc(this->joint_constraints, joint_constraints_lengthT * sizeof(arm_navigation_msgs::JointConstraint));
      offset += 3;
      joint_constraints_length = joint_constraints_lengthT;
      for( uint8_t i = 0; i < joint_constraints_length; i++){
      offset += this->st_joint_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->joint_constraints[i]), &(this->st_joint_constraints), sizeof(arm_navigation_msgs::JointConstraint));
      }
      uint8_t position_constraints_lengthT = *(inbuffer + offset++);
      if(position_constraints_lengthT > position_constraints_length)
        this->position_constraints = (arm_navigation_msgs::PositionConstraint*)realloc(this->position_constraints, position_constraints_lengthT * sizeof(arm_navigation_msgs::PositionConstraint));
      offset += 3;
      position_constraints_length = position_constraints_lengthT;
      for( uint8_t i = 0; i < position_constraints_length; i++){
      offset += this->st_position_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->position_constraints[i]), &(this->st_position_constraints), sizeof(arm_navigation_msgs::PositionConstraint));
      }
      uint8_t orientation_constraints_lengthT = *(inbuffer + offset++);
      if(orientation_constraints_lengthT > orientation_constraints_length)
        this->orientation_constraints = (arm_navigation_msgs::OrientationConstraint*)realloc(this->orientation_constraints, orientation_constraints_lengthT * sizeof(arm_navigation_msgs::OrientationConstraint));
      offset += 3;
      orientation_constraints_length = orientation_constraints_lengthT;
      for( uint8_t i = 0; i < orientation_constraints_length; i++){
      offset += this->st_orientation_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->orientation_constraints[i]), &(this->st_orientation_constraints), sizeof(arm_navigation_msgs::OrientationConstraint));
      }
      uint8_t visibility_constraints_lengthT = *(inbuffer + offset++);
      if(visibility_constraints_lengthT > visibility_constraints_length)
        this->visibility_constraints = (arm_navigation_msgs::VisibilityConstraint*)realloc(this->visibility_constraints, visibility_constraints_lengthT * sizeof(arm_navigation_msgs::VisibilityConstraint));
      offset += 3;
      visibility_constraints_length = visibility_constraints_lengthT;
      for( uint8_t i = 0; i < visibility_constraints_length; i++){
      offset += this->st_visibility_constraints.deserialize(inbuffer + offset);
        memcpy( &(this->visibility_constraints[i]), &(this->st_visibility_constraints), sizeof(arm_navigation_msgs::VisibilityConstraint));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/Constraints"; };
    const char * getMD5(){ return "fe6b6f09c687fd46c05a2de4ca18378a"; };

  };

}
#endif