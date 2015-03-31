#include "Joystick.h"
//#include <SoftwareSerial.h>// import the serial library
// This program shown how to control arduino from PC Via Bluetooth
// Connect ...
// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
// you will need arduino 1.0.1 or higher to run this sketch

Joystick::Joystick(int Rx, int Tx)
{
  _Rx = Rx;
  _Tx = Tx;
  SoftwareSerial HC05(_Rx, _Tx); // RX, TX
}

void Joystick::begin()
{
  if(DEBUG) Serial.begin(9600);
  HC05.begin(9600);
  if(DEBUG) HC05.println("Bluetooth On ");
  if(DEBUG) Serial.println("Bluetooth Connection Established Successfully");
}

char Joystick::readValue()
{
  if(HC05.available()) {
    _button = HC05.read();
  }
  if(DEBUG) Serial.println("Current Button Pressed : " + _button);
  return _button;
}
