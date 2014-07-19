#include "LED.h"

LED::LED(int pin)
{
  int _pin = pin;
}

void LED::begin()
{
  pinMode(_pin, 'OUTPUT');
}

int LED::getIntensity()
{
  return _intensity;
}

void LED::setIntensity(int intensity)
{
  _intensity = intensity;
  analogWrite(_pin, _intensity);
}
