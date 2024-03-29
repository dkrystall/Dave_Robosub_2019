#ifndef _ROS_robosub_RControl_h
#define _ROS_robosub_RControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robosub
{

  class RControl : public ros::Msg
  {
    public:
      typedef int8_t _state_type;
      _state_type state;
      typedef float _rotation_type;
      _rotation_type rotation;
      typedef uint16_t _power_type;
      _power_type power;

    RControl():
      state(0),
      rotation(0),
      power(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        float real;
        uint32_t base;
      } u_rotation;
      u_rotation.real = this->rotation;
      *(outbuffer + offset + 0) = (u_rotation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotation);
      *(outbuffer + offset + 0) = (this->power >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->power >> (8 * 1)) & 0xFF;
      offset += sizeof(this->power);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        float real;
        uint32_t base;
      } u_rotation;
      u_rotation.base = 0;
      u_rotation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rotation = u_rotation.real;
      offset += sizeof(this->rotation);
      this->power =  ((uint16_t) (*(inbuffer + offset)));
      this->power |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->power);
     return offset;
    }

    const char * getType(){ return "robosub/RControl"; };
    const char * getMD5(){ return "a289d941a233da275e35f7841bc2373c"; };

  };

}
#endif
