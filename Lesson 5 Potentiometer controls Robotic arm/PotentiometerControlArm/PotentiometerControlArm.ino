/***********************************************************
File name: PotentiometerControlArm.ino
Description: Potentiometer controls the rotation angle of the servo.
E-mail: blonwiner@outlook.com
Author: blonwiner
Date: 2024/10/06
***********************************************************/
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
int val1;
int val2;
int val3;
int val4;
int val5;
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
}
void loop()
{
  servo1.write(dataServo1+dirServo1Offset);//goes to dataServo1 degrees 
  servo2.write(dataServo2+dirServo2Offset);//goes to dataServo2 degrees 
  servo3.write(dataServo3+dirServo3Offset);//goes to dataServo3 degrees 
  servo4.write(dataServo4+dirServo4Offset);//goes to dataServo4 degrees 
  servo5.write(dataServo5+dirServo5Offset);//goes to dataServo5 degrees  

  val1 = map(analogRead(0), 0, 1023, 0, 180);  
  val2 = map(analogRead(1), 0, 1023, 0, 180);  
  val3 = map(analogRead(2), 0, 1023, 0, 180); 
  val4 = map(analogRead(3), 0, 1023, 0, 180); 
  val5 = map(analogRead(6), 0, 1023, 35, 90);
 
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
