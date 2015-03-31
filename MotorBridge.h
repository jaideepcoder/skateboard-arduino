#ifndef MotorBridge_h
#define MotorBridge_h

#include "Motor.h"

class MotorBridge
{
  public:
    MotorBridge(int pin1, int pin2);
    void begin();
    int getSpeed();
    void setSpeed(int speed);
  
  private:
    Motor _motor1;
    int _pin1, _pin2;
    int _speed;
};

#endif
