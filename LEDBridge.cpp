#include "LEDBridge.h"

LEDBridge::LEDBridge(int pin1, int pin2) : led1(pin1), led2(pin2)
{
  _pin1 = pin1, _pin2 = pin2;
}

void LEDBridge::begin()
{
  led1.begin();
  led2.begin();
}

int LEDBridge::getIntensity()
{
  return _intensity;
}

void LEDBridge::setIntensity(int intensity, bool orientation)
{
  _intensity = intensity;
  _orientation = orientation;
  if (_orientation)
  {
    led1.setIntensity(_intensity);
  }
  else
  {
    led2.setIntensity(_intensity);
  }
}
