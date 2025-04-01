/***********************************************************
File name: EEprom.ino
Description:   EEprom holds information
E-mail: blonwiner@outlook.com
Author: blonwiner
Date: 2024/10/06 
***********************************************************/
#include <EEPROM.h>
int a = 0;
void setup()
{
  Serial.begin(115200);
  
  a = EEPROM.read(5);
  if(a == 2)
  {
    Serial.println("Read Succes");  
  }
  else
  {
    Serial.println("Read Failed");  
    EEPROM.write(5,2);
    
  }
  
} 
void loop() 
{
  
}
