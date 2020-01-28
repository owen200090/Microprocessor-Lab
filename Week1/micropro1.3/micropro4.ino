int Buttonleft = A0;
int Buttonright =A1;
int bls=0;
int brs=0;
int x=0;
int potPin = A2;
int y=1;

void setLED(uint8_t _state){
  PORTD = _state << 2; //0b1111 1100 
  PORTB = _state >> 6; //0b1100 0000 -> 0000 0011
}
void setup() {
    DDRD=0b11111100;
  DDRB=0b00000011;
}

void loop() {
  bls=digitalRead(A0);
  brs=digitalRead(A1);
    if(bls==0)
    {
      y=0;
    }
    if(y==0)
    {
    x++;  
    if(x>7)
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
        x=7;
      }
    }
    setLED(0x01<<x);
    delay(analogRead(A2));   
}
