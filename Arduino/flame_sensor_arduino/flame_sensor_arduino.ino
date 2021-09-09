#define sensorPin_A A0
#define echoPin 4
#define trigPin 5

int long duration, distance;

void jarak() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  //  Serial.println(distance);
}
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sensorPin_A, INPUT);
}

void loop() {
  // baca permintaan nodeMCU
  String need = "";
  while (Serial.available() > 0) {
    need += char(Serial.read());
  }

  need.trim();
  if (need == "ya") {
    kirimdata();
  }
  need = "";
  delay(1000);
}

void kirim_data() {
  jarak();
  int asap = analogRead(sensorPin_A);
  // variable data yang akan di kirim ke nodeMCU
  String send_data = String(distance) + "!" + String(asap);
  Serial.println(send_data);
  delay(500);
}
