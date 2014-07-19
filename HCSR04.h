#ifndef HCSR04_h
#define HCSR04_h

#include <Arduino.h>

class HCSR04
{
  public:
    HCSR04(int pin1, int pin2);
    void begin();
    int getDuration();
    int getDistance();
  
  private:
    int _pin1, _pin2;
    int _duration, _distance;
};

#endif
