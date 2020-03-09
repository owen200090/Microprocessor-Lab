#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
bool sw1;
bool sw2;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,&Wire,OLED_RESET); //size 128x64

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); // clears the screen and buffer
//  display.drawPixel(127, 63, WHITE);
//  display.drawLine(0, 63, 127, 21, WHITE);
//  display.drawCircle( , , , WHITE);
  display.drawCircle(32, 32, 25, WHITE);
  display.drawCircle(96, 32, 25, WHITE);
//  display.fillCircle(45, 50, 8, WHITE);
//  display.drawTriangle(70, 60, 90, 60, 80, 46, WHITE);
//  display.setTextSize(1);
//  display.setTextColor(WHITE);
//  display.setCursor(0,0);
//  display.println("Welcome");
//  display.setTextSize(2);
//  display.println("KRAI");
//  display.setTextColor(BLACK, WHITE);
//  display.setTextSize(1);
//  display.println("www.krai.io");
//  display.setTextColor(WHITE, BLACK);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  display.display();
}

void loop() {
  
  display.clearDisplay();

  
  if(digitalRead(A0) == 0){
    sw1 = !sw1;
  }
  
  if(sw1)
  {
    display.fillCircle(32, 32, 25, WHITE);
  }
  else
  {
    display.drawCircle(32, 32, 25, WHITE);
  }
  if(digitalRead(A1)==0) {
    sw2 = !sw2;
  }
  if(sw2)
  {
    display.fillCircle(96, 32, 25, WHITE);
  }
  else
  {
    display.drawCircle(96, 32, 25, WHITE);
  }
  display.display();
}
