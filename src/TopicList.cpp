#include "TopicList.h"
#include <Arduino.h>

TopicList::TopicList() {
  this->first = NULL;
}

void TopicList::add(String topic) {
  TopicNode *next = this->first;

  this->first = (TopicNode*)calloc(1, sizeof(TopicNode));
  this->first->value = topic;
  this->first->next = next;
}

void TopicList::subscribe_all(PubSubClient *client) {
  TopicNode *current = this->first;

  while (current != NULL) {
    client->subscribe(current->value.c_str());
    current = current->next;
  }
}