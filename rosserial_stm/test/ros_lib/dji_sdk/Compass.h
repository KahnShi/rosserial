#ifndef _ROS_dji_sdk_Compass_h
#define _ROS_dji_sdk_Compass_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dji_sdk
{

  class Compass : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t ts;
      int8_t x;
      int8_t y;
      int8_t z;

    Compass():
      header(),
      ts(0),
      x(0),
      y(0),
      z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_ts;
      u_ts.real = this->ts;
      *(outbuffer + offset + 0) = (u_ts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ts);
      union {
        int8_t real;
        uint8_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->x);
      union {
        int8_t real;
        uint8_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->y);
      union {
        int8_t real;
        uint8_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_ts;
      u_ts.base = 0;
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ts = u_ts.real;
      offset += sizeof(this->ts);
      union {
        int8_t real;
        uint8_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        int8_t real;
        uint8_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        int8_t real;
        uint8_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->z = u_z.real;
      offset += sizeof(this->z);
     return offset;
    }

    const char * getType(){ return "dji_sdk/Compass"; };
    const char * getMD5(){ return "b9095ec8234a90e0f1e272a9b3133790"; };

  };

}
#endif