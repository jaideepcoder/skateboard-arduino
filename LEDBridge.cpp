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

void LEDBridge::setIntensity(boolean intensity)
{
  led1.setIntensity(intensity);
}
