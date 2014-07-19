#include "LEDController.h"
#include "LDR.h"

LEDController::LEDController(int pin1, int pin2, int pin3, int pin4, int ldrpin) : _red(pin1, pin2), _white(pin3, pin4)
{
  _pin1 = pin1, _pin2 = pin2, _pin3 = pin3, _pin4 = pin4;
  _ldrpin = ldrpin;
}

void LEDController::begin()
{
  _red.begin();
  _white.begin();
}

int LEDController::getAmbientLight()
{
  LDR ldr(_ldrpin);
  return(ldr.getAmbientLight());
}

int LEDController::getSpeedDifferential()
{
  
  return(map(abs(_accel), 0, 1023, 0, 255));
}

void LEDController::setAcceleration(int accel)
{
  _accel = accel;
}

void LEDController::setIntensity(int orientation)
{
  _orientation = orientation;
  int _whiteIntensity = getAmbientLight();
  int _redIntensity = getSpeedDifferential();
  _white.setIntensity(_whiteIntensity, _orientation);
  _red.setIntensity(_redIntensity, _orientation);
}
