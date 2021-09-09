// Controll speed of the Motor with PID

float PID1, PID2;
float et, et_1;
float eint, eint_1, eint_update;
float edif;
float Kp, Ki, Kd, Ti, Td;
float SV, PV;
int MV;

unsigned long t;
double t_1, t_s;

float interval_elapsed;
float interval_limit;

#define RPWM2 10
#define LPWM2 9
#define ENC2A 19
#define ENC2B 18

float setPoint;
float incomingSetP = 0;
float maxRpm = 800;

int enc, enc_last, rrpm;
volatile int pulse_encoder;
int enc_dir_now, enc_dir_prev;
int speedo = 0;
String dir;

double error = 0, last_error = 0, sum_error = 0;
float rpm, ppr = 7;
long pm = 0, pm2 = 0;

int mulai;

void setup() {
  Kp = 0;
  Ti = 0;
  Td = 0;

  if (Ti == 0) {
    Ki = 0;
  }

  else {
    Ki = Kp / Ti;
  }
  Kd = Kp * Td;

  et_1 = 0;
  eint_1 = 0;
  interval_limit = 0.05;
  interval_elapsed = 0;

  t = millis();
  delay(10);

  Serial.begin(9600);
  pinMode(14, HIGH);
  pinMode(ENC2A, INPUT_PULLUP);
  pinMode(ENC2B, INPUT_PULLUP);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENC2A), readEncoder, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  mulai = digitalRead(14);

  if (mulai == 1) {
    read_rpm();
    SV = setPoint;
    PV = rpm;
    t = millis();
    t_s = (t * t_1) / 10; // waktu dalam s

    et = SV - PV;

    eint_update = ((et + et_1) * t_s) / 2;
    eint = eint_1 + eint_update;

    edif = (et - et_1) / t_s;

    PID1 = Kp * et + Ki * eint + Kd * edif;

    if (PID1 > maxRpm) {
      PID1 = maxRpm;
    }
    else if (PID1 < 0) {
      PID1 = 0;
    }
    else {
      PID1 = PID1;
    }

    PID1 = PID1;
    MV = PID1 * 255;

    PID2 = PID1;
    analogWrite(RPWM2, MV);

    interval_elapsed = interval_elapsed + t_s;
    if (interval_elapsed >= interval_limit) {
      Serial.print("SV : "); Serial.print(SV);
      Serial.print(" | ");
      Serial.print("PV : "); Serial.println(PV);
    }

    et_1 = et;
    eint_1 = eint;
    t_1;
  }
  else {
    mulai = 0;
  }
}

void read_rpm() {
  pm = millis();
  if (pm - pm2 >= 100) {
    rpm = abs((pulse_encoder / ppr) * 600);
    pulse_encoder = 0;
    pm2 = pm;
  }
}

void readEncoder() {
  int b = digitalRead(ENC2A);
  if (b > 0) {
    pulse_encoder++;
  }
  else {
    pulse_encoder--;
  }
}
