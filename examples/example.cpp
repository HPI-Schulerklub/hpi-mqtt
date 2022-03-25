#include "MQTT.h"

#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PSK "YOUR_WIFI_PASSWORD"
#define MQTT_SERVER "schuelerklub.hpi.uni-potsdam.de"
#define MQTT_PORT 1883
#define MQTT_DEVICE_ID "ExampleDevice"

void callback(String topic, String message) {
  Serial.println("Received Message on topic " + topic + ": " + message);
}

void setup() {
  Serial.begin(115200);

  MQTT.setup(WIFI_SSID, WIFI_PSK, MQTT_SERVER, MQTT_PORT, MQTT_DEVICE_ID, &callback);
  // Listens to all messages that start with "exampledevice/"
  MQTT.subscribe("exampledevice/#");

  // Listens to all messages that are sent on topic "living_room_lamp"
  MQTT.subscribe("living_room_lamp");
}

void loop() {
  MQTT.loop();

  delay(500);
  MQTT.publish("exampletopic/button", "Pushed");
}