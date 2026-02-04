# MODUL_04 : LIQUID CRYSTAL DISPLAY

### Mengapa Robot Butuh Layar?

Selama ini, kita berkomunikasi dengan Arduino melalui *Serial Monitor* di laptop. Namun, sebuah robot yang hebat harus bisa mandiri. Robot yang dibuat harus bisa memberitahu kondisinya tanpa perlu dihubungkan ke komputer. Di sinilah **LCD (Liquid Crystal Display)** berperan sebagai layar informasi bagi robotmu.

Di materi ini, kita akan mempelajari dua metode cara menghubungkan layar ini: cara yang melelahkan (Tanpa I2C) dan cara yang lebih mudah (Dengan I2C).

### 1. Mengenal LCD 16x2

Layar yang kita gunakan biasanya adalah tipe **16x2**. Artinya, layar ini memiliki **16 kolom** dan **2 baris**. Total ada 32 karakter yang bisa ditampilkan.

![](img/lcd162.jpg)

Setiap kotak karakter sebenarnya adalah kumpulan bintik-bintik kecil (pixel) yang diatur oleh chip kecil di belakang layar tersebut yang disebut Chip On Board (COB). Namun, tantangan utamanya adalah: bagaimana cara Arduino mengirimkan huruf "A" ke layar tersebut?

[Datasheet LCD 16x2 bisa dilihat disini](https://www.vishay.com/docs/37484/lcd016n002bcfhet.pdf)

### 2. Cara Lama: Mode Paralel (Tanpa I2C)

Pada awalnya, LCD didesain untuk menerima data secara paralel. Bayangkan kamu memiliki 16 pin di atas LCD. Untuk menyalakannya, kamu harus menghubungkan setidaknya **6 hingga 10 pin** ke Arduino.

- **Masalahnya:** Kamu akan kehabisan kabel jumper. Papan rangkaianmu (*breadboard*) akan terlihat seperti tumpukan mie instan yang sangat ruwet.

- **Risiko:** Jika satu kabel saja longgar atau salah masuk ke lubang, layar tidak akan memunculkan teks, melainkan kotak-kotak hitam atau karakter aneh (glitch).

- **Potensiometer:** Kamu harus memasang komponen tambahan bernama Potensiometer secara manual hanya untuk mengatur kontras (tingkat kecerahan teks).

### 3. Cara Modern: Menggunakan Modul I2C

Sekarang, bayangkan jika 16 pin yang rumit tadi diringkas menjadi hanya **4 kabel saja**. Inilah fungsi dari modul **I2C Adapter** (papan kecil yang biasanya sudah tersolder di belakang LCD).

Seperti yang sudah kita bahas di materi Komunikasi, I2C memungkinkan Arduino mengirimkan data teks yang sangat banyak hanya melalui dua jalur "tol" informasi: **SDA** (Data) dan **SCL** (Clock).

**Kenapa I2C jauh lebih baik untukmu?**

1. **Hemat Pin:** Kamu masih punya banyak pin sisa di Arduino untuk memasang sensor lain.

2. **Kontras Instan:** Di belakang modul I2C sudah ada baut kecil (Trimmer) yang bisa kamu putar dengan obeng untuk mengatur kontras, tanpa perlu merakit rangkaian potensiometer tambahan.

3. **Hanya 4 Kabel:** VCC (Listrik), GND (Ground), SDA (Jalur Data), dan SCL (Jalur Waktu).

### 4. Teori Praktik: Alamat di Dalam Grup

Karena I2C bekerja seperti "Grup WhatsApp", Arduino harus tahu "nomor telepon" atau alamat dari LCD tersebut agar pesannya tidak salah kirim.

Biasanya, LCD I2C memiliki alamat standar seperti **`0x27`** atau **`0x3F`**.

- Jika kamu menulis alamat yang salah di kodemu, LCD akan menyala tapi tetap kosong (Tidak menampilkan karakter apapun).

- Jika LCD menyala tapi teks tidak terlihat, cobalah putar baut biru di belakang modul I2C; mungkin teksnya ada, hanya saja terlalu pudar atau terlalu tebal. Atau pastikan kabel **SDA** dan **SCL** tidak longgar.

### 5. Logika Penempatan Teks (Koordinat)

Menulis di LCD tidak seperti menulis di buku. Kamu harus menentukan **koordinat** sebelum menulis.

- Ingat: Komputer selalu menghitung dari angka **0**, bukan 1.

- Kolom pertama, Baris pertama adalah koordinat **(0, 0)**.

- Kolom pertama, Baris kedua adalah koordinat **(0, 1)**.

Jika kamu lupa mengatur posisi kursor, tulisanmu mungkin akan menumpuk atau terpotong di luar layar.

### Challenge!

Buatkan simulasi di wokwi dengan 2 buah lcd atau lebih (dengan modul I2C) yang akan menampilkan pesan berikut :

LCD 1 : PRAKTIK, ROBOTIK

LCD 2 : LCD I2C, <NAMA>

**Catatan**, untuk mengubah alamat i2c lcd di wokwi buka file diagram.json dan cari perintah berikut :

```json
"attrs": { "pins": "i2c", "i2cAddress": "" }
```

kemudian ubah alamat i2c kedua lcd menjadi "0x27" dan "0x3E"
