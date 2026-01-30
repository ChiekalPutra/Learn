// Mendefinisikan pin yang digunakan untuk trigger ultrasonik
#define triggerPin  D1
// Mendefinisikan pin yang digunakan untuk echo ultrasonik
#define echoPin     D2

void setup() {
  // Memulai komunikasi serial dengan baud rate 9600
  Serial.begin(9600);

  // Mengatur pin trigger sebagai output
  pinMode(triggerPin, OUTPUT);
  // Mengatur pin echo sebagai input
  pinMode(echoPin, INPUT);
}

void loop() {
  // Variabel untuk menyimpan durasi dan jarak
  long duration, jarak;

  // Mengirimkan sinyal ultrasonik
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Menerima waktu pantulan ultrasonik
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak berdasarkan waktu pantulan
  jarak = (duration / 2) / 29.1;

  // Menampilkan hasil jarak dalam centimeter ke Serial Monitor
  Serial.println("jarak :");
  Serial.print(jarak);
  Serial.println(" cm");

  // Memberikan jeda 1 detik sebelum melakukan pengukuran kembali
  delay(1000);
}
