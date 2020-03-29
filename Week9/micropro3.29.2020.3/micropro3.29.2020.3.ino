#define DATA 8
#define CLK 10
#define LATCH 9
int counter = 0;

byte number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void setLed(byte data){
  for(int i=0;i<8;i++){
    digitalWrite(DATA,!(data & (0x80>>i)));
    digitalWrite(CLK,1);
    delay(10);
    digitalWrite(DATA,0);
    digitalWrite(CLK,0);
    delay(10);
  }
  digitalWrite(LATCH,1);
  delay(10);
  digitalWrite(LATCH,0);
  delay(10);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  setLed(0x00);
  delay(100);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT = 1;
  TCCR1B |= (1<<CS12);
  TIMSK1 |= (1<<TOIE1);
  interrupts();
}

void loop() {
  ISR(TIMER1_OVF_vect)
  {
    TCNT = 1;
    counter = (++counter)%10;
    setLed(number[counter]); 
  }
}
