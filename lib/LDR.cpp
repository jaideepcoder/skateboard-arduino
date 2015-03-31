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
  int light = map(constrain(getSensorInput(), MIN, MAX), MIN, MAX, 255, 0);
  return light;
}
