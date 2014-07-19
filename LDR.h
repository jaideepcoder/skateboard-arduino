#ifndef LDR_h
#define LDR_h
#define MAX 900
#define MIN 750

#include<Arduino.h>

class LDR
{
  public:
    LDR(int pin);
    void begin();
    int getAmbientLight();
    int getSensorInput();
  
  private:
    int _pin;
};

#endif

