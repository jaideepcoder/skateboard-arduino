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

#include "Motor.h"
#include <Arduino.h>
Motor::Motor(int pin1, int pin2)
{
  _pin1 = pin1, _pin2 = pin2;
}

void Motor::begin()
{
  pinMode(_pin1, 'OUTPUT');
  pinMode(_pin2, 'OUTPUT');
}

int Motor::getSpeed()
{
  return _speed;
}

void Motor::setSpeed(int speed)
{
  _speed = speed;
  if(_speed > 0)
  {
    analogWrite(_pin1, abs(_speed));
  }
  else if(_speed < 0)
  {
    analogWrite(_pin2, abs(_speed));
  }
  else
  {
    analogWrite(_pin1, 0);
    analogWrite(_pin2, 0);
  }
}

