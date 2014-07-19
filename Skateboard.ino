int x,y,z;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  x=random(-10,10);y=random(-10,10);z=random(-10,10);
  Serial.println(String(x)+' '+String(y)+' '+String(z));
  delay(10);
}



/*#include "IMU.h"

IMU imu(0);
VectorInt16 vel, pos;

void setup()
{
  imu.begin();
  vel.x=0; vel.y=0; vel.z=0;
  pos.x=0;pos.y=0;pos.z=0;

}

void loop()
{
  VectorInt16 accel = imu.getWorldFrameAccel();

  vel.x += accel.x;vel.y += accel.y;vel.z += accel.z;
  pos.x += vel.x;pos.y += vel.y;pos.z += vel.z;
  Serial.println(accel.x);//Serial.print(" ");Serial.println(accel.y);//Serial.print(", ");Serial.println(accel.z);
  random
}





/*#include "MotorController.h"
#include "LEDController.h"
#include "IMU.h"
//#include "I2CDev.h"
//#include "MPU6050.h"
//#include "MPU6050_6Axis_MotionApps20.h"
#include "HCSR04.h"
//#include "HC06.h" //Removed for Debugging Redefination error
#include "Math.h"
#include "Wire.h"
#include "Joystick.h"

MotorController locomotor(6, 9, 10, 11);
LEDController leds(4, 5, 6, 7, 0);
HCSR04 distancer(8, 7);
//HC06 bluetooth(115200);
Joystick bluetooth(0);
IMU imu(0);

void setup()
{
  bluetooth.begin();
  locomotor.begin();
  leds.begin();
  distancer.begin();
  imu.begin();
}

void loop()
{
  
  bluetooth.main();
  int speed = bluetooth.getSpeed();
  int angle = bluetooth.getAngle();
  locomotor.setSpeed(speed, angle);
  leds.setAcceleration(imu.getGravityFreeAccel().x);
  bool orientation = locomotor.getDirection();
  leds.setIntensity(orientation);
  
}*/
