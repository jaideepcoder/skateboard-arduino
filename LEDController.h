#ifndef LEDController_h
#define LEDController_h

#include <Arduino.h>
#include "LEDBridge.h"

class LEDController
{
  public:
    LEDController(int pin1, int pin2);
    void begin();
    void IncreaseRedLEDIntensity();
    void DecreaseRedLEDIntensity();
    void setWhiteLevel(int intensity);
    
  private:
    int _redlevel, _whitelevel;
    int _pin1, _pin2, _ldrpin;
    LEDBridge _red, _white;
};
#endif
