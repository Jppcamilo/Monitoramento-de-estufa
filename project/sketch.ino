#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "ce918f0e6272473fa7f0a26b9b481604.s1.eu.hivemq.cloud";
const int mqtt_port = 8883; 
const char* mqtt_user = "RM562005";
const char* mqtt_password = "Jp281801_-";

#define DHTPIN 15
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

const int LDR_PIN = 34;

WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Conectando ao WiFi ");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexao MQTT...");
    String clientId = "ESP32-Estufa-JP-";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_password)) {
      Serial.println("Conectado ao HiveMQ com sucesso!");
    } else {
      Serial.print("Falhou, código de erro = ");
      Serial.print(client.state());
      Serial.println(". Tentando de novo em 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  
  espClient.setInsecure(); 
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();
  int luz = analogRead(LDR_PIN);

  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha ao ler dados do sensor DHT!");
    return;
  }

  Serial.print("Temp: "); Serial.print(temperatura);
  Serial.print("C | Umid: "); Serial.print(umidade);
  Serial.print("% | Luz: "); Serial.println(luz);

  client.publish("maquina1/temperatura", String(temperatura).c_str());
  client.publish("maquina1/umidade", String(umidade).c_str());
  client.publish("maquina1/luminosidade", String(luz).c_str());

  delay(5000); 
}