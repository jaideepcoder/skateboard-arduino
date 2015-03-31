#include "LEDController.h"

LEDController::LEDController(int pin1, int pin2) : _red(pin1), _white(pin2)
{
  _pin1 = pin1, _pin2 = pin2;
}

void LEDController::begin()
{
  _red.begin();
  _white.begin();
  _redlevel = 0, _whitelevel = 0;
}

void LEDController::IncreaseRedLEDIntensity()
{
  _redlevel++;
  _redlevel = constrain(_redlevel, 0, 255);
  _red.setIntensity(_redlevel);
}

void LEDController::DecreaseRedLEDIntensity()
{
  _redlevel--;
  _redlevel = constrain(_redlevel, 0, 255);
  _red.setIntensity(_redlevel);
}

void LEDController::setWhiteLevel(int intensity)
{
  _whitelevel = intensity;
  _whitelevel = constrain(_whitelevel, 0, 255);
  _white.setIntensity(_whitelevel);
}
