// M1 
#define ENCA 2
#define ENCB 3

// M2
//#define ENCA 19
//#define ENCB 18

// M3
//#define ENCA 21
//#define ENCB 20

int encoderPos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
}

void loop() {
  Serial.println(encoderPos);
}

void readEncoder() {
  int b = digitalRead(ENCB);
  if (b > 0) {
    encoderPos++;
  }
  else {
    encoderPos--;
  }
}
