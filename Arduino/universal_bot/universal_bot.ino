#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

#define sensorPin_a A0
#define LED D2
#define chat_id "1208499416"
WiFiClientSecure client;

String ssid  = "TAHU BULAT";
String pass  = "cingdogan2019";
String token  = "1927620122:AAG_Lq6LyXBU1-0nhFLVOqfEv-XgrlfsGMk";
int sensorValue_a = 0;

UniversalTelegramBot myBot(token, client);

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  client.setInsecure();

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sensorValue_a = analogRead(sensorPin_a);
  Serial.print("Sensor value analog : "); Serial.println(sensorValue_a);
  if (sensorValue_a < 100) {
    digitalWrite(LED, HIGH);
    myBot.sendMessage(chat_id, "Api kecil terdeteksi pada Ruangan 1");
    delay(100);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
