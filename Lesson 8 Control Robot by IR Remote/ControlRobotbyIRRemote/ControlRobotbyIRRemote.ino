/***********************************************************
File name: ControlRobotbyIRRemote.ino
Description: Every time a button on the remote control is pressed, 
             the robot turns once
E-mail: blonwiner@outlook.com
Author: blonwiner
Date: 2024/10/20 
***********************************************************/
#include <IRremote.h>
#include <Servo.h>
Servo servo1;//create servo object to control a servo
Servo servo2;//create servo object to control a servo
Servo servo3;//create servo object to control a servo
Servo servo4;//create servo object to control a servo
Servo servo5;//create servo object to control a servo
//The following can be modified according to your specific needs
int dataServo1 = 90; // Servo 1 rotation range(dataServo1=0~180)
int dataServo2 = 90; // Servo 2 rotation range(dataServo2=0~180) 
int dataServo3 = 90; // Servo 3 rotation range(dataServo3=0~180)
int dataServo4 = 90; // Servo 4 rotation range(dataServo4=0~180)
int dataServo5 = 90; // Servo 5 rotation range(dataServo5=0~180)

float dirServo1Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo2Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo3Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo4Offset = 0;    // define a variable for deviation(degree) of the servo
float dirServo5Offset = 0;    // define a variable for deviation(degree) of the servo
int val1=90;
int val2=90;
int val3=90;
int val4=90;
int val5=50;
int RECV_PIN = 7;//The definition of the infrared receiver pin 7
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  servo1.attach(9);//attachs the servo on pin 9 to servo object
  servo2.attach(6);//attachs the servo on pin 6 to servo object
  servo3.attach(5);//attachs the servo on pin 5 to servo object
  servo4.attach(3);//attachs the servo on pin 3 to servo object
  servo5.attach(11);//attachs the servo on pin 11 to servo object
  
  servo1.write(dataServo1+dirServo1Offset);//goes to dataServo1 degrees 
  servo2.write(dataServo2+dirServo2Offset);//goes to dataServo2 degrees 
  servo3.write(dataServo3+dirServo3Offset);//goes to dataServo3 degrees 
  servo4.write(dataServo4+dirServo4Offset);//goes to dataServo4 degrees 
  servo5.write(dataServo5+dirServo5Offset);//goes to dataServo5 degrees 
  Serial.begin(9600); //Open serial 
  irrecv.enableIRIn(); // Initialization infrared receiver
} 

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);//Wrap output in hex receive code
    Serial.println();//For ease of viewing the output to add a blank line
    irrecv.resume(); //Receiving the next value
/*Control the servo 1 to rotate*/
    if(results.value== 0xE318261B){val1=val1+10;if(val1>=180){val1=180;}}
    if(results.value== 0x511DBB){val1=val1-10;if(val1<=0){val1=0;}}
/*Control the servo 2 to rotate*/
    if(results.value== 0xEE886D7F){val2=val2+10;if(val2>=180){val2=180;}}
    if(results.value== 0x52A3D41F){val2=val2-10;if(val2<=0){val2=0;}}
/*Control the servo 3 to rotate*/
    if(results.value== 0xD7E84B1B){val3=val3+10;if(val3>=180){val3=180;}}
    if(results.value== 0x20FE4DBB){val3=val3-10;if(val3<=0){val3=0;}}
/*Control the servo 4 to rotate*/
    if(results.value== 0xF076C13B){val4=val4+10;if(val4>=180){val4=180;}}
    if(results.value== 0xA3C8EDDB){val4=val4-10;if(val4<=0){val4=0;}}
/*Control the servo 5 to rotate*/
    if(results.value== 0xE5CFBD7F){val5=val5+10;if(val5>=90){val5=90;}}
    if(results.value== 0x97483BFB){val5=val5-10;if(val5<=35){val5=35;}}
  }

  servo1.write(dataServo1+dirServo1Offset);//goes to dataServo1 degrees 
  servo2.write(dataServo2+dirServo2Offset);//goes to dataServo2 degrees 
  servo3.write(dataServo3+dirServo3Offset);//goes to dataServo3 degrees 
  servo4.write(dataServo4+dirServo4Offset);//goes to dataServo4 degrees 
  servo5.write(dataServo5+dirServo5Offset);//goes to dataServo5 degrees 

  if(dataServo1>val1){dataServo1--;  }
  if(dataServo1<val1){dataServo1++;  }
  if(dataServo1>180) {dataServo1=180;}
  if(dataServo1<0)   {dataServo1=0;  }

  if(dataServo2>val2){dataServo2--;  }
  if(dataServo2<val2){dataServo2++;  }
  if(dataServo2>180) {dataServo2=180;}
  if(dataServo2<0)   {dataServo2=0;  }

  if(dataServo3>val3){dataServo3--;  }
  if(dataServo3<val3){dataServo3++;  }
  if(dataServo3>180) {dataServo3=180;}
  if(dataServo3<0)   {dataServo3=0;  }

  if(dataServo4>val4){dataServo4--;  }
  if(dataServo4<val4){dataServo4++;  }
  if(dataServo4>180) {dataServo4=180;}
  if(dataServo4<0)   {dataServo4=0;  }

  if(dataServo5>val5){dataServo5--;  }
  if(dataServo5<val5){dataServo5++;  }
  if(dataServo5>90) {dataServo5=90;}
  if(dataServo5<35)  {dataServo5=35; }

  delay(50);//wait for 0.05second
}


