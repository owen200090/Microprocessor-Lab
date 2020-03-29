#define LED 13
#define SW 1
int count = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SW), handle, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, !digitalRead(LED));
  delay(1000*count);
}

void handle() {
  count = (count++)%3+1;
}
