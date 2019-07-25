#include <DHT.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define DHTPIN 5
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
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT); 
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
      digitalWrite(4, LOW);
      digitalWrite(2, HIGH);
      Serial.println("\n Lampu Nyala");
  }    
  else if(hum > 40){
      digitalWrite(4, LOW);
      digitalWrite(2, HIGH);
      Serial.println("\n Kipas Nyala");
  }else{
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
    Serial.println("\n Dua duanya Mati");
  }
  snprintf (kelembapan, 50, "%.2f,%.2f", hum, temp);
  client.publish("/septiesp32", kelembapan);
  Serial.print("\n Kelembapan & suhu : ");
  Serial.print(kelembapan);
  delay(10000);
}
