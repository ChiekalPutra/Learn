# MODUL_05 : SENSOR ULTRASONIK

### Sang Kelelawar Elektronik

Pernahkah kamu bertanya-tanya bagaimana seekor kelelawar bisa terbang dengan kecepatan tinggi di dalam gua yang gelap gulita tanpa menabrak dinding? Kelelawar tidak menggunakan mata, melainkan telinga. Mereka menggunakan sistem bernama **Ekolokasi**. Sensor Ultrasonik **HC-SR04** adalah alat yang meniru keajaiban alam tersebut. Sensor ini memberikan kemampuan pada Arduino untuk "melihat" jarak benda di depannya, bahkan dalam kegelapan total atau jika benda tersebut transparan seperti kaca (yang sering kali menipu sensor berbasis cahaya).

![](img/Sensor-HC-SR04-1.jpg)

### 1. Mengenal Dua "Mata" HC-SR04

Jika kamu perhatikan fisik sensor ini, ia memiliki dua silinder besar yang tampak seperti mata. Namun, fungsinya sangat berbeda:

1. **Trigger (Pemicu):** Ini adalah "Mulut" sensor. Tugasnya adalah meneriakkan gelombang suara ultrasonik dengan frekuensi 40.000 Hz. Suara ini sangat tinggi sehingga telinga manusia (dan bahkan anjing) tidak bisa mendengarnya.

2. **Echo (Pantulan):** Ini adalah "Telinga" sensor. Tugasnya adalah diam dan mendengarkan dengan seksama. Ia menunggu pantulan suara yang tadi diteriakkan oleh Trigger kembali kepadanya.

![](img/how-ultrasonic-sensor-works-01.png)

### 2. Cara Kerja: Rahasia Di Balik Kecepatan Suara

Bagaimana sebuah teriakan bisa berubah menjadi angka sentimeter di layar LCD? Rahasianya ada pada **Waktu**.

Bayangkan kamu berteriak di depan sebuah tebing. Jika gema suaramu kembali dengan sangat cepat, artinya tebing itu dekat. Jika butuh waktu lama sampai kamu mendengar suaramu sendiri, artinya tebing itu jauh.

**Proses di dalam Arduino:**

1. Arduino menyuruh **Trigger** melepaskan pulsa suara selama 10 mikrodetik.

2. Suara melesat di udara dengan kecepatan **343 meter per detik**.

3. Begitu suara menabrak benda, ia memantul balik.

4. **Echo** menangkap suara itu dan memberi tahu Arduino berapa lama waktu yang dibutuhkan sejak suara keluar hingga kembali lagi.

### 3. Logika Matematika

Arduino tidak langsung tahu jaraknya, arduino hanya tahu **Waktu**. Kita harus membantu Arduino menghitung jaraknya menggunakan rumus kecepatan dasar. Namun, ada satu jebakan: waktu yang dicatat adalah waktu **pergi dan pulang**.

Karena kita hanya ingin tahu jarak dari sensor ke benda (satu arah), maka hasilnya harus **dibagi dua**.

**Jarak= (waktu×kecepatan) / 2**​

### 4. Batasan Sensor (Troubleshooting)

Meskipun canggih, sensor ini bukanlah indera yang sempurna. Ada beberapa kondisi yang bisa membuat sensor ini "bingung":

- **Sudut Miring:** Jika benda yang dideteksi terlalu miring, suara akan memantul ke arah lain dan tidak pernah kembali ke telinga Echo. Robotmu akan menganggap tidak ada apa-apa di depannya.

- **Benda Lunak:** Karpet, spons, atau bulu binatang menyerap suara ultrasonik alih-alih memantulkannya. Ini adalah "jubah gaib" bagi sensor ini.

- **Noise (Gangguan):** Jika ada banyak sensor ultrasonik di satu ruangan, mereka bisa saling "mendengar" teriakan sensor lain, yang menyebabkan pembacaan data menjadi kacau.

### Challenge!

Buatkan satu simulasi di wokwi menggunakan sensor ultrasonik ini, input hanya berupa sensor ultrasonik **HCSR-04** dan output bisa menggunakan komponen output lainnya seperti LCD, LED, BUZZER, dll.
