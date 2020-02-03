//Exercise 3
int clk_pin = 13;
//SHCP
int latch_pin = 10;
//STCP
int data_pin = 11;
//DS
int num=0;
char incoming;
int btl = A0;
int btr = A1;
int bls = 0;
int brs = 0;

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
pinMode(btl,INPUT);
pinMode(btr,INPUT);
setLED(0x3F);
Serial.begin(9600);
}
void loop() {
// put your main code here, to run repeatedly:
  bls=digitalRead(btl);
  brs=digitalRead(btr);
  if(bls==LOW)
  {
    setLED(number[num]);
    num++;
    delay(1000);
    if(num>9)
    {
      num=0;
    }
    setLED(number[num]);
  }
  else if(brs==LOW)
  {
    setLED(number[num-2]);
    num--;
    delay(1000);
    if(num<=1)
    {
      num=11;
    }
    setLED(number[num]);
  }
  else
  {
    setLED(0x00);
  }
  Serial.println(num);
}
