# MODUL_09 : MASTERING BLYNK

Pada modul 8 kita membahas BLYNK secara singkat, kali ini kita akan mempelajari bagaimana cara membuat kode atau projek menggunakan BLYNK dengan benar. Sebelumnya kita mempelajari apa itu VirtualPin secara singkat, dan bagaimana cara membaca nilai sensor yang kemudian ditampilkan di BLYNK melalui simulasi di wokwi. Sekarang kita akan membuat sebuah prototype untuk smart home sederhana menggunakan BLYNK sebagai perantara dari device / things ke dunia luar / internet.

### 1. Konsep Virtual Pins sebagai "Kabel Gaib"

Dalam *Smart Home*, kita butuh banyak kontrol: Lampu, Pintu, Suhu, Keamanan. Jika kita menggunakan pin fisik, kita akan cepat kehabisan lubang. **Virtual Pins (V0-V255)** adalah solusi "Puzzle" sesungguhnya.

- **Fungsi `BLYNK_WRITE(V1)`:** Ini adalah "pintu masuk" dari HP ke ESP32. Setiap kali kamu menekan tombol di HP yang terhubung ke V1, fungsi ini akan dipicu secara otomatis.

```arduino
// Gunakan Button di Aplikasi Blynk dengan Virtual Pin V1
BLYNK_WRITE(V1) {
  int statusLampu = param.asInt(); // Mengambil nilai 0 atau 1 dari BLYNK

  // Jika statusLampu = 1 atau jika tombol di BLYNK ditekan
  if (statusLampu == 1) {
    digitalWrite(PIN_LAMPU, HIGH); // Nyalakan lampu
    Serial.println("Smart Home: Lampu dinyalakan");
    // Jika statusLampu = 0 atau jika tombol di BLYNK tidak ditekan
  } else {
    digitalWrite(PIN_LAMPU, LOW);  // Matikan lampu
    Serial.println("Smart Home: Lampu dimatikan");
  }
}
```

- **Fungsi `Blynk.virtualWrite(V2, data)`:** Ini adalah "pintu keluar" dari ESP32 ke HP. Gunakan ini untuk mengirim suatu data (dalam kasus ini adalah data suhu) ke Dashboard.

```arduino
// Buat sebuah fungsi untuk membaca sensor dengan DHT 22
void bacaLingkungan() {
  float kelembapan = dht.readHumidity(); // Baca kelembapan sensor
  float suhu = dht.readTemperature();    // Baca temperatur sensor

  // Jika suhu atau kelembapan menampilkan sesuatu yang bukan angka
  // NaN (not a number), maka berikan pesan bahwa sensor gagal
  // membaca nilai
  if (isnan(kelembapan) || isnan(suhu)) {
    Serial.println("Gagal membaca sensor DHT!");
    return;
  }

  // Kirim data ke Blynk untuk ditampilkan di Gauge/Chart
  Blynk.virtualWrite(V4, suhu);       // Hubungkan ke Widget Gauge V4
  Blynk.virtualWrite(V5, kelembapan); // Hubungkan ke Widget Gauge V5

  Serial.print("Suhu: ");
  Serial.println(suhu);
}
```

> **Analogi:** Virtual Pin adalah nomor loket di bank. ESP32 adalah pegawainya, dan Blynk App adalah nasabahnya. Mereka tidak perlu saling melihat wajah, cukup tahu nomor loketnya saja.

### 2. Struktur Kode Dalam BLYNK

Tidak seperti menulis kode arduino pada umumnya, jika kita menggunakan BLYNK kita perlu memperhatikan beberapa hal, termasuk :

- Template id

- Template name

- Auth token

- SSID / Nama WIFI

- Password wifi

untuk menambahkan template id, template name, maupun auth token kita perlu melakukan beberapa hal berikut :

1. Membuat template baru di BLYNK dan menambahkan data stream sesuai dengan apa yang akan dibuat

2. Menambahkan device baru dengan template yang sudah kita buat lalu menambahkan beberapa widget yang diperlukan

informasi seperti auth token, template id dan template name akan diberikan dengan format seperti berikut :

```arduino
#define BLYNK_TEMPLATE_ID "TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "TOKEN"
```

> Ketiga hal tersebut **WAJIB** disimpan di baris utama program!. Jika tidak disimpan diawal program, maka saat kode dicompile akan menampilkan error untuk "mendefinisikan" template name maupun template ID

```arduino
// Contoh kode yang benar untuk BLYNK
#define BLYNK_TEMPLATE_ID "contoh id"
#define BLYNK_TEMPLATE_NAME "contoh template_name"
#define BLYNK_AUTH_TOKEN "contoh token"


#include <Wire.h>

char ssid[] = ""; //Nama WiFi yang digunakan
char pass[] = ""; //Password WiFi yang digunakan

void setup(){

}

void loop(){

}


// Contoh kode yang salah untuk BLYNK
#include <Wire.h>
#include "config.h"

char ssid[] = ""; //Nama WiFi yang digunakan
char pass[] = ""; //Password WiFi yang digunakan


#define BLYNK_TEMPLATE_ID "contoh id"
#define BLYNK_TEMPLATE_NAME "contoh template_name"
#define BLYNK_AUTH_TOKEN "contoh token"

void setup(){

}

void loop(){

}
```

### REFERENSI KODE

1. [Setup_Example - Wokwi ESP32, STM32, Arduino Simulator](https://wokwi.com/projects/455651878491500545)

2. [Virtualwrite_test - Wokwi ESP32, STM32, Arduino Simulator](https://wokwi.com/projects/455653317661673473)


