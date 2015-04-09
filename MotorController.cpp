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
  _speed = constrain(_speed, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX);
  _angle = constrain(_angle, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX);
  
  //_speed = map(_speed, 0, 255, 63, 255);//Maps voltage for minimum 6V for DC Motor
  _angle = map(_angle, -255, 255, -_speed, _speed);
  if(abs(_speed)==_speed) {
    _left.setSpeed(constrain(_speed+_angle, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX));
    _right.setSpeed(constrain(_speed-_angle, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX));
  }
  else {
    _right.setSpeed(constrain(_speed+_angle, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX));
    _left.setSpeed(constrain(_speed-_angle, DIGITAL_PIN_MIN, DIGITAL_PIN_MAX));
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
