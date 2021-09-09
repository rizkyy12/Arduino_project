#include <MQ2.h>
#define mq2Pin A0

int led = 4;

float asap, lpg;

MQ2 mq2(mq2Pin);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  mq2.begin();
  delay(10);
}

void loop() {
  lpg = mq2.readLPG();
  asap = mq2.readSmoke();
  Serial.print("lpg : "); Serial.print(lpg); Serial.print("\t");
  Serial.print("asap : "); Serial.print(asap); Serial.print("\n"); //0.12
  delay(1000);
}
