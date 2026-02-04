#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// MQTT Credentials
const char* ssid = "Kos JoJo"; // Atur SSID AP
const char* password = "Cikubar10"; // Atur AP PSK AP
const char* mqttServer = "broker.mqtt-dashboard.com";
const char* clientID = "affandi"; // Client ID username
const char* topic = "IoT-Itenas"; // Publish topic
const char* topicnd = "IoT-Ind-Itenas"; // Publish topic

#define LED D1
#define LEDnd D2
#define triggerPin D7// Pin trigger HC-SR04
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
      client.subscribe("IoT-Led-Itenas");
      Serial.println("Topic Subscribed");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      // Tunggu 5 detik sebelum mencoba lagi
      delay(5000);
    }
  }
}

// Subscribe callback
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  String data = "";
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    data += (char)payload[i];
  }
  Serial.println();
  Serial.print("Message size: ");
  Serial.println(length);
  Serial.println();
  Serial.println("-----------------------");
  Serial.println(data);

  if (String(topic) == "IoT-Led-Itenas") {
    if (data == "true") {
      Serial.println("LED");
      digitalWrite(LED, HIGH);
    }
    else {
      digitalWrite(LED, LOW);
    }
  }
}

void setup() {
  Serial.begin(115200);
  
  // Mengatur pin trigger sebagai output
  pinMode(triggerPin, OUTPUT);
  // Mengatur pin echo sebagai input
  pinMode(echoPin, INPUT);

  pinMode(LED,OUTPUT);
  pinMode(LEDnd,OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(LEDnd, LOW);
  
  setup_wifi();
  client.setServer(mqttServer, 1883); // Atur MQTT server
  client.setCallback(callback); // Define function which will be called when a message is received.
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
    
    if (jarak>=100){
      digitalWrite(LEDnd, HIGH);
      Serial.println("Lebih dari 100");
      client.publish(topicnd, "Lebih dari 100");
    }
    else{
      digitalWrite(LEDnd, LOW);
      client.publish(topicnd, "kurang dari 100");
    }
  }
}