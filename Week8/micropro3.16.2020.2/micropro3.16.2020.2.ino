//For arduino 1
void setup()
{
  Serial.begin(9600);
  while(!Serial){ ; }
}

void loop()
{
//  Serial.print("L100A");
//    Serial.print("L100B");
  //  Serial.print(analogRead(A1));
    int val = analogRead(A1);
    Serial.print("L");
    Serial.print(val*100/1024);
    Serial.print("A");
    Serial.print("L");
    Serial.print(val*100/1024);
    Serial.print("B");
}

//For arduino 2
#define LED_PIN 11
#define led_PIN 10
float brightness = 0;
String buff;
String puss;

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
}
  void loop() {
// put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
        if(inByte == 'L'){
      buff = " ";
    }
    if(('0'<= inByte) && (inByte <= '9')){
      buff += inByte;
    }
    if(inByte == 'A'){
      brightness = buff.toInt();
      Serial.println(brightness);
      analogWrite(LED_PIN,int(brightness*2.54));
    }
        if(inByte == 'B'){
          brightness = buff.toInt();
      Serial.println(brightness);
      analogWrite(led_PIN,int(brightness*2.54));
        }
  }
    }
