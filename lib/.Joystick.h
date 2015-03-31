#ifndef Joystick_h
#define Joystick_h

#include<Arduino.h>

#define VERSION     "\n\nAndroTest V1.41 - @kas2014\ndemo for V4.X  (6 button version)"

// V1.41 minor modifications
// V1.4  improved communication errors handling
// V1.3  renamed for publishing, posted on 09/05/2014
// V1.2  Text display   ** not backward compatible **
// V1.1  Integer display
// V1.0  6 buttons + 4 data char implemented

// Demo setup:
// Button #1 controls pin13 LED
// Button #2 starts DEBUG
// Button #3 displays demo message
// Button #4 toggle datafield display rate
// Button #5 configured as "push" button (momentary)

// Arduino pin#2 to TX BlueTooth module
// Arduino pin#3 to RX BlueTooth module
// make sure your BT board is set @57600 bps
// better remove SoftSerial for PWM based projects

// For Mega 2560:
// remove   #include "SoftwareSerial.h", SoftwareSerial mySerial(2,3);
// search/replace  mySerial  >> Serial1
// pin#18 to RX bluetooth module, pin#19 to TX bluetooth module

//#include "SoftwareSerial.h"

#define    STX          0x01
#define    ETX          0x00
#define    ledPin       13
#define    SLOW         1000                           // Datafields refresh rate (ms)
#define    FAST         250                            // Datafields refresh rate (ms)

//SoftwareSerial mySerial(2,3);                           // BlueTooth module: pin#2=TX pin#3=RX


class Joystick
{
  public:
    Joystick(int x);
    void begin();
    int getSpeed();
    int getAngle();
    void setSpeed(int y);
    void setAngle(int x);
    void main();
    void sendBlueToothData();
    String getButtonStatusString();
    void getButtonState(int bStatus);
    void getJoystickState(byte data[6]);
    float GetDataField_2_float();
    int GetDataField_1_int();
  
  private:
    int _speed, _angle;

    int i;
    byte cmd [6];                       // bytes received
    byte buttonStatus;                                  // first Byte sent to Android device
    long previousMillis;                                // will store last time Buttons status was updated
    boolean setButtonFeedback;                      // momentary buttons feedback to Android device
    long sendInterval;                               // interval between Buttons status transmission (milliseconds)
    String displayStatus;                          // message to Android device
  
  
};

#endif
