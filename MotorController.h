#ifndef MotorController_h
#define MotorController_h

#include <Arduino.h>
#include "MotorBridge.h"

class MotorController
{
  public:
    MotorController(int pin1, int pin2, int pin3, int pin4);
    void begin();
    int getSpeed();
    void setSpeed(int speed, int angle);
    void setAngle(int angle);
    int getAngle();
    int getDirection();
    
  
  private:
    MotorBridge _right, _left;
    int _speed, _angle;
    int _pin1, _pin2, _pin3, _pin4;
    bool _direction;
};

#endif
