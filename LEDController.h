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

#ifndef LEDController_h
#define LEDController_h

#include <Arduino.h>
#include "LEDBridge.h"

class LEDController
{
  public:
    LEDController(int pin1, int pin2);
    void begin();
    void IncreaseRedLEDIntensity();
    void DecreaseRedLEDIntensity();
    void setWhiteLevel(int intensity);
    void setRedLevel(int intensity);
    
  private:
    int _redlevel; boolean _whitelevel;
    int _pin1, _pin2, _ldrpin;
    LEDBridge _red, _white;
};
#endif
