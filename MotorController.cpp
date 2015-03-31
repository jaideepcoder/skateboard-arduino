#include "MotorController.h"
#include<Arduino.h>

#define DIGITAL_PIN_MIN  -255
#define DIGITAL_PIN_MAX  +255

MotorController::MotorController(int pin1, int pin2, int pin3, int pin4) : _right(pin1, pin2), _left(pin3, pin4)
{
  _pin1 = pin1, _pin2 = pin2, _pin3 = pin3, _pin4 = pin4;
}

void MotorController::begin()
{
  _right.begin();
  _left.begin();
}

int MotorController::getSpeed()
{
  return _speed;
}

void MotorController::setSpeedAngle(int speed, int angle)
{
  _speed = speed;
  _angle = angle;
  constrain(_speed, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX);
  constrain(_angle, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX);
  
  //_speed = map(_speed, 0, 255, 63, 255);//Maps voltage for minimum 6V for DC Motor
  _angle = map(_angle, -255, 255, -_speed, _speed);
  if(abs(_speed)==_speed) {
    _left.setSpeed(_speed+_angle);
    _right.setSpeed(_speed-_angle);
  }
  else {
    _right.setSpeed(_speed+_angle);
    _left.setSpeed(_speed-_angle);
  }
}

int MotorController::getAngle()
{
  return _angle;
}

void MotorController::increaseSpeed()
{
  _speed++;
}
void MotorController::decreaseSpeed()
{
  _speed--;
}
void MotorController::increaseAngle()
{
  _angle++;
}
void MotorController::decreaseAngle()
{
  _angle--;
}
void MotorController::setSpeed(int speed)
{
  _speed = speed;
}
void MotorController::setAngle(int angle)
{
  _angle = angle;
}
