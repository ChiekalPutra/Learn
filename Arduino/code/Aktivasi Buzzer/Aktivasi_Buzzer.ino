#define Active_buzzer D0 // Tentukan pin 8 sebagai pin yang terhubung ke buzzer aktif

void setup () {
  pinMode (Active_buzzer,OUTPUT) ; // Atur mode pin buzzer aktif sebagai OUTPUT saat setup
}

void loop () {
  digitalWrite(Active_buzzer,HIGH) ; // Hidupkan buzzer aktif dengan mengatur pin menjadi HIGH
  delay (1000); // Tunggu selama 1 detik
  digitalWrite(Active_buzzer,LOW) ; // Matikan buzzer aktif dengan mengatur pin menjadi LOW
  delay (1000); // Tunggu selama 1 detik sebelum mengulangi loop
}
