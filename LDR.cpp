#include "LDR.h"

LDR::LDR(int pin)
{
  _pin = pin;
}

void LDR::begin()
{
  analogReference(DEFAULT);
}

int LDR::getSensorInput()
{
  return analogRead(_pin);
}

int LDR::getAmbientLight()
{
  int light = constrain(getSensorInput(), LDR_MIN, LDR_MAX);
  return light;
}

int LDR::getLEDLevel()
{
  int light = map(getAmbientLight(), LDR_MIN, LDR_MAX, 255, 0);
  return light;
}
