# CHEAT_SHEET ARDUINO

### 1. STRUKTUR PROGRAM

- Struktur Dasar

```arduino
// Struktur dasar program
void setup() {
  // Inisialisasi, hanya dijalankan satu kali setiap kode berjalan
}

void loop() {
  // Kode utama, dijalankan berulang kali
}
```

- Komentar

```arduino
// Komentar per baris

/*
  Komentar per blok
*/
```

- Fungsi

```arduino
void fungsiKu() {
  // kode dari fungsiKu
}

// panggil fungsi yang baru dibuat
fungsiKu();
```

#### 2. INPUT DAN OUTPUT

- Mengganti mode

```arduino
pinMode(pinLED, OUTPUT); // Ubah pinLED menjadi output

// Konstanta yang bisa dipakai
HIGH, LOW, INPUT, OUTPUT, INPUT_PULLUP
```

- Input & Output Digital

```arduino
// Membaca
int value = digitalRead(pin);
// Menulis 
digitalWrite(pin, value);
```

- Input & Output Analog

```arduino
// Membaca
int value = analogRead(pin);
// Menulis 
analogWrite(pin, value);
```

#### 3. KONTROL WAKTU

- Fungsi Yang Sudah Ada

```arduino
millis(), delay(), delayMicroseconds()
```

- Blink Tanpa Delay

```arduino
unsigned long currentMillis = millis(); // Ambil waktu sekarang dengan format milisecond

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update waktu sebelumnya

    // .. Lakukan apapun disini

  }
```

#### 4. KOMUNIKASI

- Serial (UART) | Universal Asynchronous Receiver-Transmitter

```arduino
Serial.begin(9600); // Mulai komunikasi pada baudrate 9600
Serial.print("Hello"); // Kirim Data
Serial.println(" World"); // Kirim data baru di baris baru
while (Serial.available()) { // baca data
  char data = Serial.read();
}
```

- I2C (I Squared C)

```arduino
#include <Wire.h>

void setup() {
  Wire.begin(); // Mulai komunikasi I2C
}

void loop() {
  Wire.beginTransmission(8); // Alamat Perangkat I2C
  Wire.write("Hello"); // Kirim Data
  Wire.endTransmission(); // Akhir dari transmisi data
}
```

- SPI (Serial Peripherals Interface)

```arduino
#include <SPI.h>

void setup() {
  SPI.begin(); // Mulai Komunikasi SPI
}

void loop() {
  digitalWrite(SS, LOW); // Aktifkan device
  SPI.transfer(0x0A); // Kirim Data
  digitalWrite(SS, HIGH); // Matikan device
}
```

#### 5. OPERATOR & KOMPARATOR

- Komparator

```arduino
//x sama dengan y
x == y

//x tidak sama dengan y
x != y

//x kurang dari y  
x < y 

//x lebih besar dari y
x > y

//x kurang dari atau sama dengan y
x <= y

//x lebih besar atau sama dengan y
x >= y
```

- Operator Aritmatika

```arduino
// Operator penugasan
a = b

// Penambahan
a + b

// Pengurangan
a - b

// Perkalian
a * b

// Pembagian
a / b

// Modulus atau sisa bagi
a % b
```

- Operator Bitwise

```arduino
//binary and
a & b  

//binary or
a | b  

//binary xor
a ^ b  

//binary not
a ~ b  

//left shift
a << b 

//right shift
a >> b
```

- Operator Gabungan

```arduino
//increment
a++

//decrement
a--

//compound addition
a += b

//compound subtraction
a -= b

//compound multiplication
a *= b

//compound division
a /= b

//compound and
a &= b

//compound or
a |= b
```

- Operator Boolean

```arduino
//not
!a

//and
a && b

//or
a || b
```

- Operator Akses

```arduino
//Operator tidak langsung
*variable

//Operator alamat
&variable
```

#### 6. DEKLARASI VARIABLE DAN KONVERSI TIPE

- Void

```arduino
//empty type (only for functions)
void
```

- Booleans

```arduino
//boolean, false or true
boolean = false;
```

- Integers

```arduino
//integer, 16 bits, from -32,768 to 32,767
int var = 100;

//Unsigned integer, 16 bits, from 0 to 65535
unsigned int var = 100;

//Short integer, 16 bits, from 0 to 65535
short var = 100;

//integer, 32 bits, from -2,147,483,648 to 2,147,483,647
long var = 100000L;

//Unsigned integer, 32 bits, from 0 to 4,294,967,295
unsigned long var = 100000L;
```

- Floating Point

```arduino
//floating point, 32 bits, from -3.4028235E+38 to 3.4028235E+38. Precision 6 digits
float var = 1.117;

//identical to float, except on Arduino Due where it is 64-bit floating point
double var = 1.117;
```

- Bytes

```arduino
//8 bits, from 0 to 255
byte var = B10010;

//16 bits, unsigned, from 0 to 65535
word var = 10000;
```

- Characters

```arduino
//8 bits, from -128 to 127
char var = 'A';

//8 bits, from 0 to 255
unsigned char var = 240;
```

- Variable Conversion

```arduino
//converts to char
char(variable);

//converts to byte
byte(variable);

//converts to int
int(variable);

//converts to word
word(variable);

//converts to long
long(variable);

//converts to float
float(variable);
```

- Variable Qualifiers

```arduino
//STATIC
//Variabel yang hanya terlihat di dalam suatu fungsi,
//dan nilainya dipertahankan di antara pemanggilan fungsi tersebut.
static int variable;

//CONST
//Variabel yang nilainya tidak dapat didefinisikan ulang setelah inisialisasi
const float pi = 3.14;

//VOLATILE
//Variabel yang diperintahkan oleh kompiler untuk tidak disimpan dalam register
//mikroprosesor, melainkan dipaksa untuk diperbarui di memori. Hal ini
//dilakukan ketika ada kemungkinan nilai variabel tersebut dimodifikasi oleh proses lain yang berjalan secara bersamaan dengan proses saat ini
//(misalnya saat menggunakan thread atau interupsi)
volatile int variable = LOW;
```

#### 7. ARRAY

- Membuat Array

```arduino
//declare vector
int myArray[5];

//initialize vector
int myArray[] = {2, 4, 8, 3, 6};

//declare and initialize vector
int myArray[5] = {2, 4, -8, 3, 2};
```

- Manipulasi Array

```arduino
//assign value to array element
myArray[0] = 10;

//get value of array element
x = myArray[4];
```

#### 8. STRING TEKS

- Teks Sebagai Karakter Array

```arduino
char string1[15];
char string2[8]  = {'a', 'r', 'd', 'u', 'i', 'n', 'o'};
char string3[8]  = {'a', 'r', 'd', 'u', 'i', 'n', 'o', '\0'};
char string4[ ]  = "text";
char string5[8]  = "text";
char string6[15] = "text";

//array of strings
char* stringArray[]={"String 1", "String 2", "String 3",
"String 4", "String 5", "String 6"};
```

- Teks Sebagai Objek String

```arduino
// string literal
String txtMsg = "Hello";

// converting a char to String
String txtMsg =  String('a');

// converting a literal to String
String txtMsg =  String("Text");

// concatenating two literals to String
String txtMsg =  String("text1" + "text2");
```

#### 9. KONDISI

- Kondisi yang Dipersingkat

```arduino
condition ? true : false;
```

- Kondisi if else

```arduino
if (variable < 10)
{
  // action A
}

if (variable < 10)
{
  // action A
}
else
{
  // action B
}

if (variable < 10)
{
  // action A
}
else if (variable >= 100)
{
  // action B
}
else
{
  // action C
}
```

- Kondisi switch case

```arduino
switch (variable) {
  case 1:
    // action A
    break;
  case 2:
    //  action B
    break;
  default: 
    // default case (optional)
}
```

#### 10. LOOPING

- FOR Loop

```arduino
for (int i=0; i <= 100; i++){
  // action
} 
```

- WHILE Loop

```arduino
variable = 0;

while(variable < 100){
  // action
  variable++;
}
```

- DO WHILE Loop

```arduino
do
{
  //action
  variable++;
} while (variable < 100);
```

#### 11. LIBRARY YANG CUKUP SERING DIGUNAKAN

```arduino
#include <Wire.h> // I2C Communication
#include <SPI.h> // SPI Communication
#include <Servo.h> // Servo Motor Control
#include <Stepper.h> // Stepper Motor Control
#include <LiquidCrystal.h> // LCD Screen Control
#include <WiFi.h> // WiFi Connection
#include <Ethernet.h> // Ethernet Connection
#include <SoftwareSerial.h> // Software Serial Communication
#include <SD.h> // Reading and writing to SD cards
```
