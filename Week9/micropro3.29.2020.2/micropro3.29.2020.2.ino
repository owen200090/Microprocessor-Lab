#define LED 13
#define SW 1
int count = 1;
int x = 0;
bool led_state = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT = 1;
  TCCR1B |= (1<<CS12);
  TIMSK1 |= (1<<TOIE1);
  interrupts();
  attachInterrupt(digitalPinToInterrupt(SW), handle, RISING);
}

void loop() {
  ISR(TIMER1_OVF_vect)
  {
    TCNT=1;
    if(++x==count)
    {
      led_state = !led_state;
      digitalWrite(LED, led_state);
      x=0;
    }
  }
}

void handle() {
  count = (count++)%3+1;
}
