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
  void setup(String ssid, String password, String server, int port, String device_id, void (*callback_ptr)(String topic, String message));
  void loop();

  void subscribe(String topic);
  void publish(String topic, String message);
  void publish(String topic, int message);
  void publish(String topic, float message);

  external_callback_t get_external_callback();

private:
  void connect();

  char* server;
  char* device_id;

  TopicList topics;

  internal_callback_t internal_callback;
  external_callback_t external_callback;

  WiFiClient wiFiClient;
  PubSubClient client;
};

void mqtt_callback(char* topicBytes, byte* messageBuffer, unsigned int length);

extern MQTTClass MQTT;