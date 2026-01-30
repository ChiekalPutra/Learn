// Mendefinisikan pin yang digunakan untuk sensor getar
#define Getar D5

void setup()
{
  // Memulai komunikasi serial dengan baud rate 9600
  Serial.begin(9600);

  // Mengatur pin getar sebagai input
  pinMode(Getar, INPUT);
}

void loop()
{
  // Membaca status sensor getar
  unsigned char Getaran = digitalRead(Getar);

  // Memeriksa apakah terdeteksi getaran atau tidak
  if (Getaran == HIGH)
  {
    // Jika terdeteksi getaran, cetak nilai HIGH
    Serial.println(Getaran);
  }
  else {
    // Jika tidak terdeteksi getaran, cetak pesan bahwa getaran tidak terdeteksi
    Serial.println("Getaran tidak terdeteksi");
  }

  // Memberikan jeda 1 detik sebelum membaca ulang sensor
  delay(1000);
}