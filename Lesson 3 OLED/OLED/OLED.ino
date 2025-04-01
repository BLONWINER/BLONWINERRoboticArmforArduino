 /*************************************
File name:OLED
Description:OLED Display images.
E-mail:blonwiner@outlook.com
Author:blonwiner
Date:2024/10/06 
*************************************/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET     4
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);


void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextColor(WHITE);//Sets the font display color
  display.clearDisplay();//cls
}

void loop() {
  //Set the font size
  display.setTextSize(2);
  //Set the display location
  display.setCursor(30,30);
  //String displayed
  display.print("Hello");
  //Began to show
  display.display();
}
