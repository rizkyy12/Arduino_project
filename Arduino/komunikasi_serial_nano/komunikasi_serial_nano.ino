#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  mySerial.begin(115200);
}

void loop(){
  mySerial.write(12);
  delay(1000);
}
