#include <ThreeWire.h>  
#include <RtcDS1302.h>

ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

int printDateTime(const RtcDateTime& dt){
//  Serial.print(dt.Year(), DEC);
//  Serial.print('/');
//  Serial.print(dt.Month(), DEC);
//  Serial.print('/');
//  Serial.print(dt.Day(), DEC);
//  Serial.print(' ');
  Serial.println();
  Serial.print(dt.Hour(), DEC);
  Serial.print(':');
  Serial.print(dt.Minute(), DEC);
  Serial.print(':');
  Serial.print(dt.Second(), DEC);
  Serial.println();
//  Serial.print("Total Seconds since 1/1/2000 : ");
//  Serial.print(dt.TotalSeconds());
  Serial.println();
}

void setup() {
  Serial.begin(57600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,2,0,0,0);
  // year, month, dayOfMonth, hour, minute, second
  printDateTime(setting_time);
  Serial.print("Start:");
  //Try to comment This line
  Rtc.SetDateTime(setting_time);
}
//Program1
 void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  delay(500);
  if(now.Minute()==1 && now.Second()==0)
  {
    Serial.print("\nStop"); 
  }
}
//Program2
//void setup(){
//  Serial.begin(9600);
//  pinMode(13,OUTPUT);
//  Serial.println("Start");
//}
//uint32_t totalSeconds = 0;
//void loop(){
//  totalSeconds++;
//  digitalWrite(13,totalSeconds%2);
//  if(totalSeconds >= 60*2) Serial.println("Stop");
//  delay(1000);
//}
