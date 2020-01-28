int Buttonleft = A0;
int Buttonright =A1;
int bls=0;
int brs=0;
int x=0;

void setup() {
  DDRD=0b11111100;
  DDRB=0b00000011;

}

void loop() {
  int x=2;
  int y=0;
  for(x=2;x<=7;x++)
  {
    PORTD=0b00000001<<x;
    delay(500);
  }
  PORTD=0b00000000;
  for(x=7;x<=9;x++)
  {
    PORTB=0b00000001<<y;
    y++;
    delay(500);
  }

}
