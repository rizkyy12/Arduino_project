#include <config.h>
// -- Motor 1
//#define RPWM1 7
//#define LPWM1 6
//
//// -- Motor 2
//#define RPWM2 10
//#define LPWM2 9
//
//// -- Motor 3
//#define RPWM3 12
//#define LPWM3 11

void setup() {
  Serial.begin(9600);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  pinMode(RPWM3, OUTPUT);
  pinMode(LPWM3, OUTPUT);
}

void loop() {
  analogWrite(RPWM3, 10);
  analogWrite(LPWM3, 0);
  delay(1000);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM3, 0);
  delay(1000);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM3, 10);
  delay(1000);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM3, 0);
  delay(1000);
}
