#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "TopicList.h"

typedef void (*internal_callback_t)(char* topicBytes, byte* messageBuffer, unsigned int length);
typedef void (*external_callback_t)(String topic, String message);

class MQTTClass {
public:
  MQTTClass(void (*internal_callback)(char* topicBytes, byte* messageBuffer, unsigned int length));
  ~MQTTClass();
  void setup(const String& ssid, const String& password, const String& server, int port, const String& device_id, void (*callback_ptr)(String topic, String message));
  void loop();

  void subscribe(const String& topic);
  void publish(const String& topic, const String& message);
  void publish(const String& topic, int message);
  void publish(const String& topic, float message);

  external_callback_t get_external_callback();

private:
  void connect();
  void heartbeat();

  char* wifi_ssid;
  char* wifi_password;

  char* server;
  char* device_id;

  TopicList topics;

  internal_callback_t internal_callback;
  external_callback_t external_callback;

  WiFiClient wiFiClient;
  PubSubClient client;

  ulong last_heartbeat;
};

void mqtt_callback(char* topicBytes, byte* messageBuffer, unsigned int length);

extern MQTTClass MQTT;
