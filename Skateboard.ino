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

#include "MotorController.h"
#include "HCSR04.h"
#include "Speaker.h"
#include "LDR.h"
#include "LEDController.h"
#include <SoftwareSerial.h>
#include <Servo.h>
#define DEBUG true

/*  Control Signal Definitions  */
#define UP     'f'
#define DOWN   'b'
#define RIGHT  'r'
#define LEFT   'l'
#define START  '1'
#define STOP   '0'
#define HORN   'h'
#define LIGHT  'i'
#define NLIGHT 'n'
#define EMPTY  'e'

//Digital IC Pins
//Analog Pins
//1
Servo direction;
MotorController locomotor(6, 9, 10, 11);
SoftwareSerial HC05(7, 8); // RX, TX
HCSR04 distancer(4, 2);
Speaker horn(12);
LDR lightsensor(1);
LEDController light(3, 13);

int cycle;
int speed, angle, servoAngle;
boolean ledState;
char button;
void setup()
{
  ledState = false;
  cycle = 0;
  speed = angle = servoAngle = 0;
  if(DEBUG) Serial.begin(9600);
  HC05.begin(9600);
  direction.attach(5);
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
  // Executes every 100 cycle //
  if(cycle%100==0) {
    // Read data from HC05 Bluetooth Module //
    if(HC05.available()) {
      button = HC05.read();
    }
    
    if(DEBUG) Serial.print("Current Button Pressed : ");
    if(DEBUG) Serial.println(button);
    
    // Control Logic for Direction Control //
    if(button == UP)    locomotor.increaseSpeed();
    if(button == DOWN)  locomotor.decreaseSpeed();
    if(button == RIGHT) locomotor.increaseAngle();
    if(button == LEFT)  locomotor.decreaseAngle();
    
    // Control Logic for On-Off Signalling //
    if(button == START) locomotor.setSpeed(255);
    if(button == STOP)  locomotor.setSpeed(0);
    
    // Control Logic for Buzzer Horn //
    if(button == HORN)  horn.buzzer_play(); if(DEBUG) Serial.println("Playing Horn");
    if(button != HORN)  horn.buzzer_stop();
    
    // Control Logic for HCSR04 Proximity Sensor //
    if(DEBUG)  Serial.println(distancer.getDistance());
    if(distancer.getDistance() < 20) locomotor.setSpeed(0); locomotor.setAngle(0);

    // Control Logic for White LED Strip //
    if(button == LIGHT) ledState = true; light.setWhiteLevel(255);
    if(button == NLIGHT) ledState = false; light.setWhiteLevel(0);
    if(!ledState) light.setWhiteLevel(lightsensor.getLEDLevel());
    
   
    speed = locomotor.getSpeed();
    angle = locomotor.getAngle();
   
    // Control Logic for Red LED Strip //
    light.setRedLevel(map(constrain(speed, -255, 0), -255, 0, 255, 0));
   
    // Control Logic for Servo Motor // 
    if(speed != 0) servoAngle = map(angle, -255, +255, -30, +30);
    direction.write(servoAngle);
    
    locomotor.setSpeedAngle(speed, angle);
  }
  cycle++;
  delay(5);
}

// End of Program //
