#include <DHT.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DHTPIN 23
#define DHTTYPE DHT22
#define CLIENT_ID "ESPfahmi"

const char* ssid       = "Xperia Z3 Compact"; //nama wifi
const char* password   = "0411501129"; //password
const char* mqtt_server = "broker.hivemq.com";
char kelembapan[100];

WiFiClient espClient;
PubSubClient client(espClient);

DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  client.setServer(mqtt_server, 1883);
  client.connect(CLIENT_ID, "", "");

}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  if(hum < 15){
      digitalWrite(22, LOW);
      digitalWrite(21, HIGH);
      Serial.println("\n Lampu Nyala");
  }    
  else if(hum > 40){
      digitalWrite(21, LOW);
      digitalWrite(22, HIGH);
      Serial.println("\n Kipas Nyala");
  }else{
    digitalWrite(21, HIGH);
    digitalWrite(22, HIGH);
    Serial.println("\n Dua duanya Mati");
  }
  snprintf (kelembapan, 50, "%.2f,%.2f", hum, temp);
  client.publish("/septiesp32", kelembapan);
  Serial.print("\n Kelembapan & suhu : ");
  Serial.print(kelembapan);
  delay(10000);
}
