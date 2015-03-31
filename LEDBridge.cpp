#include "LEDBridge.h"

LEDBridge::LEDBridge(int pin1) : led1(pin1)
{
  _pin1 = pin1;
}

void LEDBridge::begin()
{
  led1.begin();
}

int LEDBridge::getIntensity()
{
  return _intensity;
}

void LEDBridge::setIntensity(int intensity)
{
  _intensity = intensity;
  led1.setIntensity(_intensity);
}
