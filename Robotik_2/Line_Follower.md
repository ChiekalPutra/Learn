# ROBOT LINE FOLLOWER

##### APA ITU LINE FOLLOWER?

*Line Follower robot* merupakan jenis [robot](http://e-belajarelektronika.com/category/robot/) yang termasuk dalam kategori [robot](http://e-belajarelektronika.com/tag/robot-2/) mobile yang di desain untuk bekerja secara *autonomous* atau tanpa dikendalikan dan memiliki kemampuan untuk mendeteksi dan bergerak mengikuti (*follows*) garis yang ada di permukaan. Sistem kendali yang digunakan dalam robot ini dirancang untuk bisa mendeteksi jalur (garis yang berwarna hitam) yang ada dan melakukan gerakan agar tetap berada dalam jalur.

##### BAGIAN DARI ROBOT LINE FOLLOWER

Untuk memahami bagaimana robot ini bekerja secara mendalam, pertama kita harus mengetahui terlebih dahulu bagian-bagian dari robot tersebut.

1. Sensor:
   
   * Bagian paling penting dari robot line follower adalah sensornya. Robot line follower biasanya menggunakan sensor *IR* (*infrared*) atau *LDR* (*Light Dependent Resistor*) untuk mengikuti garis. Dalam sensor *IR* terdapat dua buah komponen yaitu *IR LED* dan *Photodiode*. Sensor ini nantinya akan menentukan apakah objek tersebut mengikuti garis atau tidak melalui pantulannya / refleksinya.

2. Mikrokontroller:
   
   * Mikrokontroller digunakan sebagai otak utama dari robot yang akan menerima input dari seluruh sensor dan membuat keputusan berdasarkan logika yang mendasarinya (programnya). Contoh mikrokontroller yang sering dipakai untuk robot line follower adalah Arduino, Raspberry Pi dan mikrokontroller dari seri ESP

3. Motor:
   
   * Robot line follower biasanya menggunakan *dc motor* (dinamo) untuk mengontrol pergerakannya. Motor tersebut memiliki kecepatan dan arah yang dikontrol melalui mikrokontroller berdasarkan logika dari input pada sensor. Untuk mengoperasikan motor ini diperlukan sebuah modul dengan nama *motor driver* agar bisa mengontrol kecepatan motor tersebut dan agar bisa mendapatkan gerakan yang halus , *motor driver* yang umum digunakan adalah *motor driver* dengan IC L298N .

4. Chassis dan Roda:
   
   * Secara umum *chassis* adalah *body* / *casing* dari robot, dan *chassis* bisa digerakan dengan roda yang terhubung pada motor. *Design* dari *chassis* dapat berubah-rubah sesuai kebutuhan, tetapi secara umum semakin ringan dan tersusun maka akan lebih baik dan effisien.

5. Power Supply:
   
   * Untuk mengoperasikan robot diperlukan juga power yang stabil dan tahan lama, biasanya menggunakan baterai yang cukup efisien seperti baterai Li-ion atau Li-Po. Penggunaan daya akan bergantung dari pilihan motor dan mikrokontroller yang digunakan.

##### BAGAIMANA ROBOT LINE FOLLOWER BEKERJA?

Prinsip kerja robot line follower sangat sederhana, robot ini akan disediakan garis yang digambar di lantai dan kemudian robot akan memandu sensor yang terpasang untuk mengikuti garis tersebut. Jika dijabarkan, cara kerja robot line follower adalah sebagai berikut.

1. Deteksi Garis:
   
   * Sensor *IR* pada robot akan melakukan proses *scanning* / pemindaian secara terus menerus. Kemudian sensor akan mendeteksi perbedaan antara refleksi dari garis dan permukaan sekitarnya menjadi sebuah sinyal elektrik.

2. Memproses Sinyal:
   
   * Sinyal yang didapat dari sensor akan dikirim ke mikrokontroller untuk diproses. Jika robot memutuskan bahwa dia berada di garis, maka mikrokontroller akan terus mengirimkan sinyal untuk melanjutkan pergerakan robot ke depan.

3. Error Handling / Mengatasi Error:
   
   * Jika robot menyimpang dari jalur, maka sensor akan mendeteksi kesalahan tersebut, dan mikrokontroler akan menyesuaikan kecepatan motor sesuai dengan itu.

4. Siklus Robot:
   
   * Robot tersebut akan menelusuri garis yang sama berulang kali. Semakin akurat pembacaan oleh sensor dan pemrograman pada mikrokontroler, semakin halus dan cepat pergerakan robot di sepanjang garis tersebut.
