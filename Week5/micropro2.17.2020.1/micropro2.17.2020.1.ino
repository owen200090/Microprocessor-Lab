#include <SPI.h>
int DATA_PIN = 11;
int CLOCK_PIN = 13;
int SS_PIN_1 = 10;
int SS_PIN_2 = 9;
int i=0;
int j=0;

byte number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void spi_write_2(unsigned char c2Data)
{
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, c2Data);
  digitalWrite (SS_PIN_2, HIGH);
  digitalWrite (SS_PIN_2, LOW);
}
void spi_write_1(unsigned char c1Data)
{
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, c1Data);
  digitalWrite (SS_PIN_1, HIGH);
  digitalWrite (SS_PIN_1, LOW);
}

void setup()
{
  pinMode(SS_PIN_1, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void loop()
{
  for(j=0;j<=9;j++)
  {
    for(i=0;i<=9;i++)
    {
      spi_write_1(number[j]);
      spi_write_2(number[i]);
      delay(1000);
    }
  }
}
