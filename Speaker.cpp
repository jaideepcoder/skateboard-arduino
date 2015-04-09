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

void Speaker::buzzer_play()
{
  digitalWrite(_pin, HIGH);
}

void Speaker::buzzer_stop()
{
  digitalWrite(_pin, LOW);
}
