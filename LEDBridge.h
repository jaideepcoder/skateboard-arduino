#ifndef LEDBridge_h
#define LEDBridge_h

#include <Arduino.h>
#include "LED.h"

class LEDBridge
{
  public:
    LEDBridge(int pin1);
    void begin();
    int getIntensity();
    void setIntensity(int intensity);
    
  private:
    bool _orientation;
    int _intensity;
    int _pin1;
    LED led1;
    
};
#endif
