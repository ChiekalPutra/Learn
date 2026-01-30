#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// MQTT Credentials
const char* ssid = "iPhone Affan"; // Atur SSID AP
const char* password = "12345678"; // Atur AP PSK AP
const char* mqttServer = "broker.mqtt-dashboard.com";
const char* clientID = "affandi"; // Client ID username
const char* topic = "IoT-Itenas"; // Publish topic

#define triggerPin D7 // Pin trigger HC-SR04
#define echoPin D8 // Pin echo HC-SR04

WiFiClient espClient;
PubSubClient client(espClient);

// Parameter untuk menggunakan non-blocking delay
unsigned long previousMillis = 0;
const long interval = 1000;
String msg = "";      // MQTT message buffer
float jarak;
long duration;

void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Ulangi sampai terhubung kembali
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // mencoba untuk terhubung
    if (client.connect(clientID)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Tunggu 5 detik sebelum mencoba lagi
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  // Mengatur pin trigger sebagai output
  pinMode(triggerPin, OUTPUT);
  // Mengatur pin echo sebagai input
  pinMode(echoPin, INPUT);

  setup_wifi();
  client.setServer(mqttServer, 1883); // Atur MQTT server
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  unsigned long currentMillis = millis(); // Membaca waktu
  if (currentMillis - previousMillis >= interval) { 
    previousMillis = currentMillis;
      
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


    Serial.print("Jarak: ");
    Serial.println(jarak);
    delay(200);

    msg = String(jarak);
    byte arrSize = msg.length() + 1;
    char msgC[arrSize];
    msg.toCharArray(msgC, arrSize);
    client.publish(topic, msgC);
  }
}