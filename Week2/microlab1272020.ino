//Exercise 1
int clk_pin = 13;
//SHCP
int latch_pin = 10;
//STCP
int data_pin = 11;
//DS
int counter=0;

void setLED(uint16_t _led_state){
  digitalWrite(latch_pin,LOW);
  for(int i=0;i<16;i++)
  {
    digitalWrite(data_pin,(_led_state>>(15-i)) & 0x01);
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
}
void loop() {
// put your main code here, to run repeatedly:
  setLED(0x01<<counter);
  counter++;
  if(counter>15) {counter=0;}
  delay(100);
}
