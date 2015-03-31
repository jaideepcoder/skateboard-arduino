#ifndef LEDBridge_h
#define LEDBridge_h

#include <Arduino.h>
#include "LED.h"

class LEDBridge
{
  public:
    LEDBridge(int pin1, int pin2);
    void begin();
    int getIntensity();
    void setIntensity(int intensity, bool orientation);
    
  private:
    bool _orientation;
    int _intensity;
    int _pin1, _pin2;
    LED led1, led2;
    
};
#endif
