#ifndef _ROS_naoqi_bridge_msgs_StatusChangeStamped_h
#define _ROS_naoqi_bridge_msgs_StatusChangeStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"

namespace naoqi_bridge_msgs
{

  class StatusChangeStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int16_t recharge_type;
      std_msgs::String old_status;
      std_msgs::String new_status;

    StatusChangeStamped():
      header(),
      recharge_type(0),
      old_status(),
      new_status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_recharge_type;
      u_recharge_type.real = this->recharge_type;
      *(outbuffer + offset + 0) = (u_recharge_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_recharge_type.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->recharge_type);
      offset += this->old_status.serialize(outbuffer + offset);
      offset += this->new_status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_recharge_type;
      u_recharge_type.base = 0;
      u_recharge_type.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_recharge_type.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->recharge_type = u_recharge_type.real;
      offset += sizeof(this->recharge_type);
      offset += this->old_status.deserialize(inbuffer + offset);
      offset += this->new_status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/StatusChangeStamped"; };
    const char * getMD5(){ return "631ab2246eca82d839e3a99b76567775"; };

  };

}
#endif