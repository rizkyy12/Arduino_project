#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "CTBot.h"
#include <UniversalTelegramBot.h>

int my_id = 1208499416;

String ssid  = "KONZ";
String pass  = "CINGDOGAN2019";
String token  = "1927620122:AAG_Lq6LyXBU1-0nhFLVOqfEv-XgrlfsGMk";
WiFiClientSecure client;

// ------- variable nodeMCU Communication -------
int led = 2;
unsigned long prevMillis = 0;
const long interval = 1000;
String arrData[2];
int data1, data2;
// ------------------- END ----------------------

CTBot myBot;
UniversalTelegramBot uBot(token, client);

void setup() {
  Serial.begin(115200);
  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  pinMode(led, OUTPUT);

  if (myBot.testConnection()) {
    Serial.println("Koneksi OK");
  }
  else {
    Serial.println("Koneksi Not OK");
  }
}

void loop() {
  TBMessage msg;
  String pesan = msg.text;
  String welcome, info_bot;
  if (myBot.getNewMessage(msg)) {
    Serial.println("Pesan masuk : " + msg.text);
    if (pesan == "/start") {
      welcome = "Selamat datang di bot kami! \n";
      welcome += "Pendeteksi titik api dengan peringatan dini melalui Telegram.\n";
      welcome += "/info";
      welcome += " <-- info mengenai Bot\n";
      welcome += "/status";
      welcome += " <-- status kondisi saat ini";
      myBot.sendMessage(my_id, welcome);
    }
    else if (pesan = "/info") {
      info_bot = "fireBot merupakan bot Telegram yang digunakan untuk ";
      info_bot += "melaporkan titik api yang dapat memicu terjadinya kebakaran.\n";
      info_bot += "Project ini dibuat untuk menyelesaikan tugas pada mata kuliah Mikrokontroller 2.\n";
      info_bot += "Kelompok : Rizky Andhika A & M. Zaky Al-Farish";
      myBot.sendMessage(my_id, info_bot);
    }
  }
  if (data1 < 600 and data2 >= 1) {
    digitalWrite(led, HIGH);
    myBot.sendMessage(my_id, "Api kecil terdeteksi pada Ruangan 1");
  }
  else {
    digitalWrite(led, LOW);
  }
  delay(500);
}
