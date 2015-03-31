#ifndef MotorController_h
#define MotorController_h

#include "MotorBridge.h"

class MotorController
{
  public:
    MotorController(int pin1, int pin2, int pin3, int pin4);
    void begin();
    int getSpeed();
    void setSpeedAngle(int speed, int angle);
    void increaseSpeed();
    void decreaseSpeed();
    void increaseAngle();
    void decreaseAngle();
    void setSpeed(int speed);
    void setAngle(int angle);
    int getAngle();
    
  
  private:
    MotorBridge _right, _left;
    int _speed, _angle;
    int _pin1, _pin2, _pin3, _pin4;
};

#endif
