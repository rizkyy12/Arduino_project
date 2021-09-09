unsigned long myTime, myTimeS;

void setup() {
  Serial.begin(9600);
}

void loop() {
  myTime = millis();
  myTimeS = myTime/1000;
  Serial.print("Time (S) : "); Serial.println(myTimeS);
  delay(1000);
}
