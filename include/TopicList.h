#pragma once

#include <Arduino.h>
#include <PubSubClient.h>

typedef struct TopicNode {
  String value;
  struct TopicNode *next;
} TopicNode;

class TopicList {
public:
  TopicList();
  void add(String topic);
  void subscribe_all(PubSubClient *client);

private:
  TopicNode *first;
};
