#ifndef Joystick_h
#define Joystick_h
#define DEBUG true
#include <Arduino.h>
#include <SoftwareSerial.h>

class Joystick
{
  public:
    Joystick(int Rx, int Tx);
    void begin();
    char readValue();
    SoftwareSerial HC05;
  private:
    int _Tx, _Rx;
    char _button;
}

#endif
