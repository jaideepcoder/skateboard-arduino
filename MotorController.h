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

#ifndef MotorController_h
#define MotorController_h

#include "MotorBridge.h"

class MotorController
{
  public:
    MotorController(int pin1, int pin2, int pin3, int pin4);
    void begin();
    int getSpeed();
    void setSpeedAngle(int speed, int angle);
    void increaseSpeed();
    void decreaseSpeed();
    void increaseAngle();
    void decreaseAngle();
    void setSpeed(int speed);
    void setAngle(int angle);
    int getAngle();
    
  
  private:
    MotorBridge _right, _left;
    int _speed, _angle;
    int _pin1, _pin2, _pin3, _pin4;
};

#endif
