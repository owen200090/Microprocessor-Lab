#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
int second;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire,OLED_RESET); //size 128x64

ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  Serial.begin(57600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,2,23,31,10);
  // year, month, dayOfMonth, hour, minute, second
  //printDateTime(setting_time);
  //Try to comment This line
  Rtc.SetDateTime(setting_time);
}
 void loop() {
  display.clearDisplay();
  RtcDateTime now = Rtc.GetDateTime();
  Serial.print(now.Year(), DEC);
  Serial.print('/');
  Serial.print(now.Month(), DEC);
  Serial.print('/');
  Serial.print(now.Day(), DEC);
  Serial.print(' ');
  Serial.print(now.Hour(), DEC);
  Serial.print(':');
  Serial.print(now.Minute(), DEC);
  Serial.print(':');
  Serial.print(now.Second(), DEC);
  Serial.println();
  Serial.print("Total Seconds since 1/1/2000 : ");
  Serial.print(now.TotalSeconds());
  Serial.println();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(now.Year());
  display.print("/");
  display.print(now.Month());
  display.print("/");
  display.println(now.Day());
  display.print(now.Hour());
  display.print(":");
  display.print(now.Minute());
  display.print(":");
  display.print(now.Second());
  display.display();
  delay(1000);
  
}
