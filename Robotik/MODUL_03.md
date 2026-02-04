# MODUL_03 : GETTING STARTED

### DARI TEORI KE AKSI

Selamat! Kamu sudah memahami bagaimana Arduino berpikir (Materi 1) dan bagaimana ia merasakan dunia melalui sensor (Materi 2). Sekarang pertanyaannya: **Bagaimana cara kita memasukkan perintah ke dalam otak tersebut?**

Untuk melakukannya, kita membutuhkan sebuah jembatan. Jembatan ini berupa perangkat lunak yang disebut **Arduino IDE** (Integrated Development Environment). Di sinilah tempat kita menuliskan "resep masakan" atau kode, lalu mengirimkannya melalui kabel USB ke papan Arduino Uno kita.

### 1. MENGENAL ARDUINO IDE

Saat kamu membuka Arduino IDE, jangan merasa terintimidasi oleh tampilannya. Fokuslah pada tiga tombol utama yang akan paling sering kamu tekan:

- **Verify (Centang):** Tombol ini berfungsi untuk mengecek apakah "resep" (kode) yang kamu tulis sudah benar bahasanya. Jika ada titik koma yang kurang atau salah ketik, Arduino IDE akan memberitahumu di bagian bawah.

- **Upload (Panah ke Kanan):** Inilah tombol ajaibnya. Tombol ini akan mengirimkan kode dari laptop ke papan Arduino. Saat proses ini terjadi, kamu akan melihat lampu kecil bertanda **TX/RX** di papan Arduinomu berkedip cepat—itu tandanya data sedang mengalir masuk.

- **Serial Monitor (Kaca Pembesar):** Seperti yang kita bahas sebelumnya, ini adalah cara Arduino "curhat". Melalui layar ini, Arduino bisa memberitahumu jarak yang ia baca dari sensor atau sekadar menyapa "Halo Dunia".

### 2. HELLO WORLD OF ELECTRONIC WORLD

Dalam dunia pemrogramman, bahasa apapun yang akan digunakan biasanya "ritual" pertama untuk memverifikasi apakah program tersebut berjalan sukses atau tidak adalah dengan membuat program "HELLO, WORLD!". Walaupun di arduino atau mikrokontroller lainnya kita bisa membuat program yang sama, tetapi biasanya "ritual" dalam dunia hardware sedikit berbeda. Mereka akan membuat sebuah program yang akan menyala-matikan lampu LED untuk memastikan bahwa perangkat mereka bekerja secara semestinya.

**Langkah-langkahnya:**

1. Sambungkan Arduino ke laptop menggunakan kabel USB.

2. Pilih papan yang benar di menu **Tools > Board > Arduino Uno**.

3. Pilih jalur kabel yang benar di menu **Tools > Port** (Pilih yang ada tulisan Arduino Uno).

4. Buka contoh kode: **File > Examples > 01.Basics > Blink**.

5. Tekan tombol **Upload**.

Jika lampu kecil bertanda **L** di papanmu mulai berkedip, selamat! Kamu baru saja berhasil memberikan nyawa pertama pada "robotmu".

### 3. CARA MENGHINDARI "SHORT CIRCUIT" (Hardware Safety)

Sebelum kita mulai merakit rangkaian yang lebih kompleks di level berikutnya, ada aturan keselamatan yang harus kamu ingat. Di dunia elektronika, ada istilah **"Magic Smoke"** ketika sebuah komponen mengeluarkan asap karena salah pasang kabel, biasanya komponen itu tidak akan bisa digunakan lagi selamanya.

- **Kabel Merah (VCC/5V/3.3V) & Hitam (GND):** Jangan biarkan kedua ujung kabel ini bersentuhan langsung satu sama lain saat Arduino menyala. Ini disebut *Short Circuit* (Korsleting).

- **Cabut Sebelum Rakit:** Selalu biasakan mencabut kabel USB dari laptop sebelum kamu mengubah posisi kabel di *Breadboard*. Ini demi keamanan Arduino dan laptopmu.

### 4. LEVEL UP

Sampai titik ini, kamu sudah bukan lagi seorang pemula yang buta tentang robotika. Kamu sudah tahu:

1. Siapa yang memimpin (Arduino).

2. Bagaimana cara ia berkomunikasi (Sensor & Aktuator).

3. Bagaimana cara memberi perintah (Arduino IDE).

Mulai modul berikutnya, kita tidak akan lagi hanya menyalakan lampu. Kita akan mulai membangun sistem yang bisa mengambil keputusan sendiri. Secara perlahan, tantangan akan bertambah, kode akan sedikit lebih panjang, dan rangkaian akan sedikit lebih ramai.

Siapkan dirimu, karena dari sini, kamu bukan lagi hanya pengguna teknologi kamu adalah **penciptanya**.



### Challenge!

Buka kembali kode **Blink** tadi. Cari angka `1000` di dalam kode tersebut, ubah menjadi `100`, lalu Upload lagi. Lihat perbedaannya pada lampu Arduino-mu. Apa yang sebenarnya terjadi?




















