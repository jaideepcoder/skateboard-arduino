#include "MotorController.h"

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

void MotorController::setSpeed(int speed, int angle)
{
  _speed = speed;
  _angle = angle;
  _speed = map(_speed, 0, 255, 63, 255);//Maps voltage for minimum 6V for DC Motor
  angle = map(angle, 0, 90, 0, speed);
  _right.setSpeed(speed+angle);
  _left.setSpeed(speed-angle);
}

int MotorController::getAngle()
{
  return _angle;
}

void MotorController::setAngle(int angle)
{
  _angle = angle;
}

int MotorController::getDirection()
{

  if(_speed >= 0)
  {
    _direction = HIGH;
  }
  else
  {
    _direction = LOW;
  }
  return _direction;
}
