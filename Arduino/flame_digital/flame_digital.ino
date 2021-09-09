#define flamePin 12
int LED = 4; // Use the onboard Uno LED
//int isFlamePin = 11;  // This is our input pin
int isFlame = HIGH;  // HIGH MEANS NO FLAME

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  isFlame = digitalRead(flamePin);
  if (isFlame == LOW)
  {
    Serial.println("FLAME, FLAME, FLAME");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("no flame");
    digitalWrite(LED, LOW);
  }
}
