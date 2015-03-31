#include "Speaker.h"
#include<Arduino.h>
#include "Pitches.h"

Speaker::Speaker(int pin)
{
  _pin = pin;
}

void Speaker::begin()
{
  pinMode(_pin, OUTPUT);
}

void Speaker::play()
{
  tone(_pin, NOTE_G3);
}

void Speaker::stop()
{
  noTone(_pin);
}
