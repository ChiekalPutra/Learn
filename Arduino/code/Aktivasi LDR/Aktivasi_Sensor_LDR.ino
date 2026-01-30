// Mendefinisikan pin yang digunakan untuk sensor LDR
#define ldr D0

void setup() {
  // Memulai komunikasi serial dengan baud rate 9600
  Serial.begin(9600);

  // Mengatur pin LDR sebagai input
  pinMode(ldr, INPUT);
}

void loop() {
  // Membaca nilai dari sensor LDR
  int value = digitalRead(ldr);

  // Memeriksa apakah sensor LDR mendeteksi cahaya atau tidak
  if (value == 1) {
    // Jika mendeteksi cahaya, cetak nilai HIGH ke Serial Monitor
    Serial.println(value);
  } else {
    // Jika tidak mendeteksi cahaya, cetak nilai LOW ke Serial Monitor
    Serial.println(value);
  }

  // Memberikan jeda 1 detik sebelum membaca ulang sensor LDR
  delay(1000);
}
