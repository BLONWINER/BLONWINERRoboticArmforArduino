/***********************************************************
File name: servo.ino
Description:   The servo motor circulates to 180 degrees, 90 degrees
               Degrees, 0 degrees,
E-mail: blonwiner@outlook.com
Author: blonwiner
Date: 2024/10/06 
***********************************************************/
#include <Servo.h>
Servo myservo;//create servo object to control a servo
void setup()
{
  myservo.attach(9);//attachs the servo on pin 9 to servo object
  myservo.write(0);//back to 0 degrees 
  delay(1000);//wait for a second
}
void loop()
{  
  myservo.write(180);//goes to 15 degrees 
  delay(2000);//wait for a second

  myservo.write(90);//goes to 30 degrees 
  delay(2000);//wait for a second.33
  
  myservo.write(0);//goes to 45 degrees 
  delay(2000);//wait for a second.33
}
