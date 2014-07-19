#include "Motor.h"

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

bool Motor::getDirection()
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

