void botMsg() {
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
}
