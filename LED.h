#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED
{
  public:
    LED(int pin);
    void begin();
    int getIntensity();
    void setIntensity(int intensity);
  
  private:
    int _pin, _intensity;
};
#endif
