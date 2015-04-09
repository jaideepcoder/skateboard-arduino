//  An arduino program to operate a mobile controlled skateboard implemented in Arduino language and Object Oriented C++.
//  v1.0
//  See complete license at:
//  github.com/jaideepcoder/skateboard-arduino/blob/master/LICENCE
//  
//  Copyright (C) 2015 Jaideep Bhoosreddy
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//  You should have received a copy of the GNU General Public License
//  along with this program. If not, see <http://www.gnu.org/licenses/>.

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
  intensity = constrain(intensity, 0, 255);
  if(intensity == 0) _whitelevel = LOW;
  else _whitelevel = HIGH;
  _white.setIntensity(_whitelevel);
}

void LEDController::setRedLevel(int intensity)
{
  intensity = constrain(intensity, 0, 255);
  if(intensity == 0) _redlevel = LOW;
  else _redlevel = HIGH;
  _red.setIntensity(_redlevel);
}
