#ifndef _ROS_aerial_robot_msgs_RollPitchYawTerm_h
#define _ROS_aerial_robot_msgs_RollPitchYawTerm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_msgs
{

  class RollPitchYawTerm : public ros::Msg
  {
    public:
      int16_t roll_p;
      int16_t roll_i;
      int16_t roll_d;
      int16_t pitch_p;
      int16_t pitch_i;
      int16_t pitch_d;
      int16_t yaw_d;

    RollPitchYawTerm():
      roll_p(0),
      roll_i(0),
      roll_d(0),
      pitch_p(0),
      pitch_i(0),
      pitch_d(0),
      yaw_d(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_roll_p;
      u_roll_p.real = this->roll_p;
      *(outbuffer + offset + 0) = (u_roll_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_p.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_p);
      union {
        int16_t real;
        uint16_t base;
      } u_roll_i;
      u_roll_i.real = this->roll_i;
      *(outbuffer + offset + 0) = (u_roll_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_i.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_i);
      union {
        int16_t real;
        uint16_t base;
      } u_roll_d;
      u_roll_d.real = this->roll_d;
      *(outbuffer + offset + 0) = (u_roll_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_d.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_d);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_p;
      u_pitch_p.real = this->pitch_p;
      *(outbuffer + offset + 0) = (u_pitch_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_p.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_p);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_i;
      u_pitch_i.real = this->pitch_i;
      *(outbuffer + offset + 0) = (u_pitch_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_i.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_i);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_d;
      u_pitch_d.real = this->pitch_d;
      *(outbuffer + offset + 0) = (u_pitch_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_d.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_d);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_d;
      u_yaw_d.real = this->yaw_d;
      *(outbuffer + offset + 0) = (u_yaw_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_d.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_d);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_roll_p;
      u_roll_p.base = 0;
      u_roll_p.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_p.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_p = u_roll_p.real;
      offset += sizeof(this->roll_p);
      union {
        int16_t real;
        uint16_t base;
      } u_roll_i;
      u_roll_i.base = 0;
      u_roll_i.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_i.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_i = u_roll_i.real;
      offset += sizeof(this->roll_i);
      union {
        int16_t real;
        uint16_t base;
      } u_roll_d;
      u_roll_d.base = 0;
      u_roll_d.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_d.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_d = u_roll_d.real;
      offset += sizeof(this->roll_d);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_p;
      u_pitch_p.base = 0;
      u_pitch_p.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_p.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_p = u_pitch_p.real;
      offset += sizeof(this->pitch_p);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_i;
      u_pitch_i.base = 0;
      u_pitch_i.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_i.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_i = u_pitch_i.real;
      offset += sizeof(this->pitch_i);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_d;
      u_pitch_d.base = 0;
      u_pitch_d.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_d.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_d = u_pitch_d.real;
      offset += sizeof(this->pitch_d);
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_d;
      u_yaw_d.base = 0;
      u_yaw_d.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_d.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_d = u_yaw_d.real;
      offset += sizeof(this->yaw_d);
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/RollPitchYawTerm"; };
    const char * getMD5(){ return "14a179f5309ca5bc435eceedda0bcca3"; };

  };

}
#endif