#include "MotorController.h"
#include "HCSR04.h"
#include "Speaker.h"
#include "LDR.h"
#include "LEDController.h"
#include <SoftwareSerial.h>
#define DEBUG true

/*  Control Signal Definitions  */
#define UP     'f'
#define DOWN   'b'
#define RIGHT  'r'
#define LEFT   'l'
#define START  '1'
#define STOP   '0'
#define HORN   'h'


MotorController locomotor(6, 9, 10, 11);
SoftwareSerial HC05(2, 3); // RX, TX
HCSR04 distancer(4, 5);
Speaker horn(8);
LDR lightsensor(1);
LEDController light(3, 5);

int cycle;
int speed, angle;
char button;
void setup()
{
  cycle = 0;
  speed = angle = 0;
  if(DEBUG) Serial.begin(9600);
  HC05.begin(9600);
  if(DEBUG) HC05.println("Bluetooth On ");
  if(DEBUG) Serial.println("Bluetooth Connection Established Successfully");
  locomotor.begin();
  distancer.begin();
  horn.begin();
  lightsensor.begin();
  light.begin();
  locomotor.setSpeedAngle(speed, angle);
}

void loop()
{
  if(cycle%100==0) {
    if(HC05.available()) {
      button = HC05.read();
    }
    if(DEBUG) Serial.println("Current Button Pressed : " + button);
    if(button == UP)    locomotor.increaseSpeed(); light.IncreaseRedLEDIntensity();
    if(button == DOWN)  locomotor.decreaseSpeed(); light.DecreaseRedLEDIntensity();
    if(button == RIGHT) locomotor.increaseAngle();
    if(button == LEFT)  locomotor.decreaseAngle();
    
    if(button == START) locomotor.setSpeed(255);
    if(button == STOP)  locomotor.setSpeed(0);
    
    if(button == HORN)  horn.play(); if(DEBUG) Serial.println("Playing Horn");
    if(button != HORN)  horn.stop();
    
    if(DEBUG)  Serial.println(distancer.getDistance());
    if(distancer.getDistance() < 20) locomotor.setSpeed(0); locomotor.setAngle(0);

    if(DEBUG)  Serial.println("LED Level: " + lightsensor.getLEDLevel());
    light.setWhiteLevel(lightsensor.getLEDLevel());
    
    speed = locomotor.getSpeed();
    angle = locomotor.getAngle();
    
    if(DEBUG) Serial.println("Speed: " + speed);
    if(DEBUG) Serial.println("Angle: " + angle);
    
    locomotor.setSpeedAngle(speed, angle);
  }
  cycle++;
}


