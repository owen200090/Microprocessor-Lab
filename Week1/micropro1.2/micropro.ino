int Buttonleft = A0;
int Buttonright =A1;
int bls=0;
int brs=0;
int x=0;

void setLED(uint8_t _state){
  PORTD = _state << 2; //0b1111 1100 
  PORTB = _state >> 6; //0b1100 0000 -> 0000 0011
}
void setup() 
{
  pinMode (Buttonleft,INPUT);
  pinMode (Buttonright,INPUT);
  DDRD=0b11111100;
  DDRB=0b00000011;
  Serial.begin(9600);  
}

void loop(){
  bls=digitalRead(Buttonleft);
  brs=digitalRead(Buttonright);
    if(bls==LOW)
    {
      setLED(0x01 << x);
      x++;
      delay(1000);
      if(x>=8)
      {
        x=0;
      }
      setLED(0x01 << x);
    }
    else if(brs==LOW)
    {
      setLED(0x01 << x-2);
      x--;
      delay(1000);
      if(x<=1)
      {
        x=9;
      }
      setLED(0x01 << x);
    }
     else
    {
      setLED(0x00);
    }
    Serial.println(x);
}
