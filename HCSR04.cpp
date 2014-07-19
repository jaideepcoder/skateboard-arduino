#include "HCSR04.h"

HCSR04::HCSR04(int pin1, int pin2)
{
  _pin1 = pin1, _pin2 = pin2;
}

void HCSR04::begin()
{
  pinMode(_pin1, OUTPUT);
  pinMode(_pin2, INPUT);
}

int HCSR04::getDuration()
{
  digitalWrite(_pin1, HIGH);
  delayMicroseconds(1000);
  digitalWrite(_pin1, LOW);
  _duration = pulseIn(_pin2, HIGH);
  return _duration;
}

int HCSR04::getDistance()
{
  _distance = (_duration/2)/29.1;
  return _distance;
}
