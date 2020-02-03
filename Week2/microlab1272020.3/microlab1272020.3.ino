//Exercise 3
int clk_pin = 13;
//SHCP
int latch_pin = 10;
//STCP
int data_pin = 11;
//DS
int x=0;
int btl =A0;
int btr =A1;
int bls=0;
int brs=0;
int y=0;

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
}
void loop() {
// put your main code here, to run repeatedly:
  bls=digitalRead(btl);
  brs=digitalRead(btr);
  if(bls==0)
    {
      y=0;
    }
    if(y==0)
    {
    x++;  
    if(x>=16)
    {
      x=0;
    }}
    if(brs==0)
    {
      y=1;
    }
    if(y==1)
    {
      x--;
      if(x<0)
      {
        x=15;
      }
    }
    setLED(0x01<<x);
    delay(analogRead(A2));   
}
