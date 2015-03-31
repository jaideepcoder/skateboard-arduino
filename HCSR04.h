#ifndef HCSR04_h
#define HCSR04_h

#include <Arduino.h>

class HCSR04
{
  public:
    HCSR04(int pin1, int pin2);
    void begin();
    float getDistance();
  
  private:
    int _pin1, _pin2;
    float _duration, _distance;
};

#endif
