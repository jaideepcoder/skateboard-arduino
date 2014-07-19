#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pin1, int pin2);
    void begin();
    int getSpeed();
    void setSpeed(int speed);
    bool getDirection();
    //bool status();
  
  private:
    int _pin1, _pin2;
    int _speed;
    bool _direction;
    //bool _status;
};
#endif
