#define MOTOR_D1_PIN 7
#define MOTOR_D2_PIN 8
#define MOTOR_PWM_PIN 9
#define chA 2
#define chB 3

bool previous_readA=false;
bool previous_readB=false;
bool current_readA=false;
bool current_readB=false;
int count = 0;

void setup()
{
  pinMode(MOTOR_D1_PIN, OUTPUT);
  pinMode(MOTOR_D2_PIN, OUTPUT);
  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(chA,INPUT_PULLUP);
  pinMode(chB,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Test Encoder");
  attachInterrupt(digitalPinToInterrupt(chA), Check, FALLING);
  attachInterrupt(digitalPinToInterrupt(chB), Check, FALLING);
}

void runcounter(bool dir)
{
  if(dir)
    count++;
  else
    count--;
  
  Serial.println("Counter="+String(count)+"Direction:"+(dir?"CW":"CCW"));
}

void Check()
{
    current_readA = !digitalRead(chA);
    current_readB = !digitalRead(chB);
    if(current_readA&&current_readB)
    {  
      if(previous_readA&&!previous_readB)
          runcounter(1);
      else if(!previous_readA&&previous_readB) 
          runcounter(0);
    }
    previous_readA = current_readA;
    previous_readB = current_readB;
}
void loop()
{
  setSpeed(1);
    delay(1000);
    setSpeed(-2);
    delay(1000);
}

void setSpeed(int x)
{
  if (x>0&&x<=255)
  {
    digitalWrite(MOTOR_D1_PIN,LOW);
  digitalWrite(MOTOR_D2_PIN,HIGH);
  analogWrite(MOTOR_PWM_PIN,x);
  }
  if(x<0&&x>=-255)
  {
    digitalWrite(MOTOR_D1_PIN,HIGH);
  digitalWrite(MOTOR_D2_PIN,LOW);
  analogWrite(MOTOR_PWM_PIN,-x);
  }
}
