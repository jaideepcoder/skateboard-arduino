#include "MotorBridge.h"

MotorBridge::MotorBridge(int pin1, int pin2) : _motor1(pin1, pin2), _motor2(pin1, pin2)
{
  _pin1 = pin1, _pin2 = pin2;
}

void MotorBridge::begin()
{
  _motor1.begin();
  _motor2.begin();
}

int MotorBridge::getSpeed()
{
  return _speed;
}

void MotorBridge::setSpeed(int speed)
{
  _speed = speed;
  _motor1.setSpeed(_speed);
  _motor2.setSpeed(_speed);
}

bool MotorBridge::getDirection()
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
