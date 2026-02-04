#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int LED = D1;
// MQTT Credentials
const char* ssid = "iPhone Affan"; // Atur SSID AP
const char* password = "12345678"; // Atur AP PSK AP
const char* mqttServer = "broker.mqtt-dashboard.com";
const char* clientID = "affandi"; // Client ID username+0001

WiFiClient espClient;
PubSubClient client(espClient);

// Parameters for using non-blocking delay
unsigned long previousMillis = 0;
const long interval = 1000;

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
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientID)) {
      Serial.println("connected");
      client.subscribe("IoT-Led-Itenas");
      Serial.println("Topic Subscribed");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      // Wait 5 seconds before retrying
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
  pinMode(LED,OUTPUT);
  digitalWrite(LED, LOW);

  setup_wifi();
  client.setServer(mqttServer, 1883); // Setting MQTT server  
  client.setCallback(callback); // Define function which will be called when a message is received.
}

void loop() {
  if (!client.connected()) { // If client is not connected
    reconnect(); // Try to reconnect
  }
  client.loop();
  unsigned long currentMillis = millis(); // Read current time
  if (currentMillis - previousMillis >= interval) { // If current time - last time > 5 sec
    previousMillis = currentMillis;
  }
}
