int LED1 = 5;
String data = "";

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) {
    data += char(Serial.read());
    digitalWrite(LED1, HIGH);
  }
  Serial.println(data);
  delay(1000);
}
