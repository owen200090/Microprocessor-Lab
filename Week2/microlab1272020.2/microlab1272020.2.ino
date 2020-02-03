//Exercise 2
int clk_pin = 13;
//SHCP
int latch_pin = 10;
//STCP
int data_pin = 11;
//DS
int counter=0;
int btl =A0;
int btr =A1;
int bls=0;
int brs=0;

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
pinMode(btl,INPUT);
pinMode(btr,INPUT);
Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
  bls=digitalRead(btl);
  brs=digitalRead(btr);
  if(bls==LOW)
    {
      setLED(0x01 << counter);
      counter++;
      delay(1000);
      if(counter>=16)
      {
        counter=0;
      }
      setLED(0x01 << counter);
    }
    else if(brs==LOW)
    {
      setLED(0x01 << counter-2);
      counter--;
      delay(1000);
      if(counter<=1)
      {
        counter=17;
      }
      setLED(0x01 << counter);
    }
     else
    {
      setLED(0x00);
    }
    Serial.println(counter);
}
