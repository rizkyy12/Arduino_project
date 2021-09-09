#define echoPin 4
#define trigPin 5

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  Serial.print("distance : ");Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
