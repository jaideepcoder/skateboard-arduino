#include "MotorBridge.h"

MotorBridge::MotorBridge(int pin1, int pin2) : _motor1(pin1, pin2)
{
  _pin1 = pin1, _pin2 = pin2;
}

void MotorBridge::begin()
{
  _motor1.begin();
}

int MotorBridge::getSpeed()
{
  return _speed;
}

void MotorBridge::setSpeed(int speed)
{
  _speed = speed;
  _motor1.setSpeed(_speed);
}

