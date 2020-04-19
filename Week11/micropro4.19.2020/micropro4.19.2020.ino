#define MOTOR_D1_PIN 7
#define MOTOR_D2_PIN 8
#define MOTOR_PWM_PIN 9
#define chA 2
#define chB 3
#define DATA 11
#define CLK 13
#define LATCH 10

#define LED1 5
#define LED2 6
#define LED3 4

byte NUMBER[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
};

void spi_write(unsigned char data){
  shiftOut(DATA, CLK, MSBFIRST, data);
  digitalWrite(LATCH,1);
  digitalWrite(LATCH,0);
}

int LED_current = 0;
bool LED_isNegative = false;

void setNumber(int number){
  if(number < 0){
    LED_isNegative = true;
    LED_current = -number;
  }else{
    LED_isNegative = false;
    LED_current = number;
  }
  digitalWrite(LED3,LED_isNegative);
}

void setup()
{
  pinMode(MOTOR_D1_PIN, OUTPUT);
  pinMode(MOTOR_D2_PIN, OUTPUT);
  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(chA, INPUT_PULLUP);
  pinMode(chB, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(chA), Check, FALLING);
  attachInterrupt(digitalPinToInterrupt(chB), Check, FALLING);
  Serial.println("Test Encoder");
  setPosition(1);
  setSpeed(1);
}

void LED_display_handle(){
  spi_write(NUMBER[LED_current/10]);
  digitalWrite(LED1,1);
  digitalWrite(LED2,0);
  delay(10);
  spi_write(NUMBER[LED_current%10]);
  digitalWrite(LED1,0);
  digitalWrite(LED2,1);
  delay(10);
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

bool previous_readA=false;
bool previous_readB=false;
bool current_readA=false;
bool current_readB=false;
int target = 0;
int count = 0;

void setPosition(int position){
  target = position;
}

void runcounter(bool dir)
{
  if(dir)
    count++;
  else
    count--;
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

float PID_millis_current = 0;
float PID_millis_previous = 0;
float PID_millis_delta = 0;
float PID_error = 0;
float PID_integral = 0;
float PID_derivative = 0;
float PID_previous_error = 0;
float PID_control_value;
float Kp = 5;
float Ki = 0.017;
float Kd = 0.1;

void speedControl_handle(){
  PID_millis_current = millis();
  PID_millis_delta = (PID_millis_current-PID_millis_previous)/1000.0;
  PID_error = target-count;
  PID_integral = PID_integral+PID_error*PID_millis_delta;
  PID_derivative = (PID_error-PID_previous_error)/PID_millis_delta;
  PID_control_value = Kp*PID_error + Ki*PID_integral + Kd*PID_derivative;
  setSpeed(PID_control_value);
  PID_previous_error = PID_error;
  PID_millis_previous = PID_millis_current;
}

String Buffer = "";

void loop(){  
  setPosition(analogRead(A0));
  speedControl_handle();
  setNumber(count/100);
  LED_display_handle();
  Serial.print(count);
  Serial.print(",");
  Serial.print(target);
  Serial.println();
}
