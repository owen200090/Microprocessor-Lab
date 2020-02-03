//Exercise 1
int clk_pin = 13;
//SHCP
int latch_pin = 10;
//STCP
int data_pin = 11;
//DS

byte number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};
void setLED(uint8_t _state){
  digitalWrite(latch_pin,LOW);
  for(int i=0;i<8;i++)
  {
    digitalWrite(data_pin,(_state>>(7-i)) & 0x01);
    digitalWrite(clk_pin,HIGH);
    digitalWrite(clk_pin,LOW);
  }
  digitalWrite(latch_pin,HIGH);
}

void setup() {
// put your setup code here, to run once:
pinMode(clk_pin,OUTPUT);
pinMode(latch_pin,OUTPUT);
pinMode(data_pin,OUTPUT);
setLED(0x3F);
}
void loop() {
// put your main code here, to run repeatedly:
  for (int x=0;x<=9;x++)
  {
  setLED(number[x]);
  delay(200);
  }
}
