#include "Joystick.h"

Joystick::Joystick(int x)
{ 
  i=x;
  int cmd[6] = {0, 0, 0, 0, 0, 0};                       // bytes received
  buttonStatus = 0;                                  // first Byte sent to Android device
  previousMillis = 0;                                // will store last time Buttons status was updated
  setButtonFeedback = false;                      // momentary buttons feedback to Android device
  sendInterval = SLOW;                               // interval between Buttons status transmission (milliseconds)
  displayStatus = "xxxx";                          // message to Android device

}

void Joystick::begin()
{
  Serial.begin(115200);
  
}

int Joystick::getSpeed()
{
  return _speed;
}

int Joystick::getAngle()
{
  return _angle;
}

void Joystick::setSpeed(int y)
{
  _speed = map(y, -100, 100, -255, 255);
}

void Joystick::setAngle(int x)
{
  _angle = map(x, -100, 100, -90, 90);
}

void Joystick::main()
{
  if(Serial.available())  {                            // data received from smartphone
    delay(2);                                                              //  <<mod XXXXXXXX
    cmd[0] =  Serial.read();  
    if(cmd[0] == STX)  {
      i=1;      
      while(Serial.available())  {
        delay(1);                                                          //  <<mod XXXXXXXX
        cmd[i] = Serial.read();
        if(cmd[i]>127 || i>5)                               break;   // Communication error << XXX Mod
        if((cmd[i]==ETX) && ((i==2 && cmd[1]>2) || i==5))   break;   // Button or Joystick data
        i++;
      }
      if     (i==2 && cmd[1]>48 && cmd[1]<68)     getButtonState(cmd[1]);                         // 3 Bytes
      else if(i==5 && cmd[1]<3  && cmd[3]<3 )     getJoystickState(cmd);                          // 6 Bytes
    }
  }
  sendBlueToothData();                                                       //  <<mod XXXXXXXX
//    delay(5);                                                              //  <<mod XXXXXXXX
// your code here
}

void Joystick::sendBlueToothData()
{
  static long previousMillis = 0;                             
  long currentMillis = millis();
  if(setButtonFeedback == true)  {                      // allow momentary button visual effect
    previousMillis = currentMillis + 250;   
    setButtonFeedback = false;
  }
  if(currentMillis - previousMillis > sendInterval) {   // send data to smartphone
    previousMillis = currentMillis; 

// Data frame transmitted back from Arduino to Android device:
// < 0X02   Buttons state   0X01   DataField#1   0x04   DataField#2   0x05   DataField#3    0x03 >  
// < 0X02       01011       0X01      120.00     0x04      -4500      0x05   Motor enabled  0x03 >    // example

    Serial.print((char)0x2);                                                 // Start of Transmission
    Serial.print(getButtonStatusString());      Serial.print((char)0x1);   // buttons status feedback
    Serial.print(GetDataField_1_int());         Serial.print((char)0x4);   // datafield #1
    Serial.print(GetDataField_2_float());       Serial.print((char)0x5);   // datafield #2
    Serial.print(displayStatus);                                             // datafield #3
    Serial.print((char)0x3);                                                 // End of Transmission
  } 
}

String Joystick::getButtonStatusString()
{
  String bStatus = "";
  for(int i=0; i<6; i++)  {
    if(buttonStatus & (B100000 >>i))      bStatus += "1";
    else                                  bStatus += "0";
  }
  return bStatus;
}

void Joystick::getButtonState(int bStatus)
{
  switch (bStatus) {
// -----------------  BUTTON #1  -----------------------
    case '1':
      buttonStatus |= B000001;        // ON
      Serial.println("\n** Button_1: ON **");    // your code here...
      displayStatus = "LED <ON>";
      Serial.println(displayStatus);
      digitalWrite(ledPin, HIGH);
      break;
    case '2':
      buttonStatus &= B111110;        // OFF
      Serial.println("\n** Button_1: OFF **");    // your code here...
      displayStatus = "LED <OFF>";
      Serial.println(displayStatus);
      digitalWrite(ledPin, LOW);
      break;
// -----------------  BUTTON #2  -----------------------
    case '3':
      buttonStatus |= B000010;        // ON
      Serial.println("\n** Button_2: ON **");    // your code here...
      break;
    case '4':
      buttonStatus &= B111101;        // OFF
      Serial.println("\n** Button_2: OFF **");    // your code here...
      break;
// -----------------  BUTTON #3  -----------------------
    case '5':
      buttonStatus |= B000100;        // ON
     // setButtonFeedback = true;            moved to button #5 (for push buttons)
      Serial.println("\n** Button_3: ON **");    // your code here...
      displayStatus = "Motor #1 enabled"; // Demo text message
      Serial.println(displayStatus);
      break;
    case '6':
      buttonStatus &= B111011;      // OFF
      Serial.println("\n** Button_3: OFF **");    // your code here...
      displayStatus = "Motor #1 stopped";
      Serial.println(displayStatus);
      break;
// -----------------  BUTTON #4  -----------------------
    case '7':
      buttonStatus |= B001000;       // ON
      Serial.println("\n** Button_4: ON **");    // your code here...
      displayStatus = "Datafield update <FAST>";
      Serial.println(displayStatus);
      sendInterval = FAST;
      break;
    case '8':
      buttonStatus &= B110111;    // OFF
      Serial.println("\n** Button_4: OFF **");    // your code here...
      displayStatus = "Datafield update <SLOW>";
      Serial.println(displayStatus);
      sendInterval = SLOW;
     break;
// -----------------  BUTTON #5  -----------------------
    case '9':           // configured as momentary button
//      buttonStatus |= B010000;        // ON
      setButtonFeedback = true;                     // moved from button #3
      Serial.println("\n** Button_5: + pushed + **"); // your code here...
      displayStatus = "Button_5: ++ pushed ++";
      break;
//   case 'A':
//     buttonStatus &= B101111;        // OFF
//     break;
// -----------------  BUTTON #6  -----------------------
    case 'B':
      buttonStatus |= B100000;        // ON
      Serial.println("\n** Button_6: ON **");    // your code here...
       displayStatus = "Button #6 ON"; // Demo text message
     break;
    case 'C':
      buttonStatus &= B011111;        // OFF
      Serial.println("\n** Button_6: OFF **");    // your code here...
      displayStatus = "Button #6 OFF";
      break;
// -----------------------------------------------------
  }
}

void Joystick::getJoystickState(byte data[6])
{
  int joyX = (data[1]<<7) + data[2];
  int joyY = (data[3]<<7) + data[4];
  joyX = joyX - 200;                                            // Offset to avoid
  joyY = joyY - 200;                                            // transmitting negative numbers
  if(joyX<-100 || joyX>100 || joyY<-100 || joyY>100)    return; // commmunication error
  
  Serial.print("Joystick position:  ");
  Serial.print(joyX); Serial.print(", "); Serial.println(joyY);
    
  // Your code here ...
  setSpeed(joyY);
  setAngle(joyX);
}

int Joystick::GetDataField_1_int()  {            // Data dummy values sent to Android device for demo purpose
  static int i= -30;                   // Replace with your own code
  i ++;
  if(i >0)    i = -3000;
  return i;  
}

float Joystick::GetDataField_2_float()  {       // Data dummy values sent to Android device for demo purpose
  static float i=50;                  // Replace with your own code
  i-=.5;
  if(i <-50)    i = 50;
  return i;  
}
