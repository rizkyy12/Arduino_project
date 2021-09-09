#include <MQ2.h>
#define flame A0
#define mq2Pin A1

// D4 = 7, D5 = 8

int rx = 7; int tx = 8;

float asap;
int api;

MQ2 mq2(mq2Pin);
String send_data;

void setup() {
  Serial.begin(115200);
  mq2.begin();
  pinMode(mq2Pin, INPUT);
  pinMode(flame, INPUT);
}

void loop() {
  kirim_data();
  delay(1000);
}

void kirim_data() {
  api = analogRead(flame);
  asap = mq2.readSmoke();
  // variable data yang akan di kirim ke nodeMCU
  send_data = String(api) + "!" + String(asap);
  Serial.println(send_data);
}
