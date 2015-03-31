#ifndef LDR_h
#define LDR_h
#define LDR_MAX 900
#define LDR_MIN 750

#include<Arduino.h>

class LDR
{
  public:
    LDR(int pin);
    void begin();
    int getAmbientLight();
    int getSensorInput();
    int getLEDLevel();
  
  private:
    int _pin;
};

#endif

