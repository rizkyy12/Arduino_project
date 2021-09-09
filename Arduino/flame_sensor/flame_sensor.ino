//#define sensorPin A0
//#define LED 12
// -- Node MCU
#define sensorPin_a A0
#define sensorPin_d 12
#define LED 4

int sensorValue_d, sensorValue_a = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue_a = analogRead(sensorPin_a);
  sensorValue_d = digitalRead(sensorPin_d);
  Serial.print("Sensor value analog : "); Serial.println(sensorValue_a);
  Serial.print("Sensor value digital : "); Serial.println(sensorValue_d);

  if (sensorValue_d == LOW) {
    Serial.println("Fire detected");
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else {
    digitalWrite(LED, LOW);
    delay(1000);
  }
}
