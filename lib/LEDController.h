#ifndef LEDController_h
#define LEDController_h

#include <Arduino.h>
#include "LEDBridge.h"

class LEDController
{
  public:
    LEDController(int pin1, int pin2, int pin3, int pin4, int ldrpin);
    void begin();
    int getAmbientLight();
    void setAcceleration(int accel);
    int getSpeedDifferential();
    void setIntensity(int orientation);
    
  private:
    bool _orientation;
    int _intensity;
    int _pin1, _pin2, _pin3, _pin4, _ldrpin, _axcelpin;
    LEDBridge _red, _white;
    int _accel;
  
};
#endif
