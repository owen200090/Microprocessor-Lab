#define LED_PIN 11
#define led_PIN 10
float brightness = 0;
String buff;

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
