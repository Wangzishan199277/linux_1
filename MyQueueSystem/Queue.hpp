//Question: Why don't we use the queue structure given by the language
//
// Queue.hpp
// QueueSystem
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <cstdlib>

#include <Event.hpp>

template<typename T>
class Queue {
public:
  Queue() {
    this->front = new T;
    if(!this->front) {
      exit(-1);
    }
    this->front->next = nullptr;
    this->rear = this->front;
  }

//We should release the memory when deleting a queue
  ~Queue() {
    this->clearQueue();
    delete this->front;
    this->front = nullptr;
    this->rear = nullptr;
  }

  void clearQueue() {
    T* temp_node;
    while(this->front->next) {
      temp_node = this->front->next;
      this->front->next = temp_node->next;
      delete temp_node;
    }
    this->front->next = nullptr;
    this->rear = this->front;
  }

//Add a node to the queue
  T* enqueue(T &node) {
    T* new_node = new T;
    if(!new_node) {
      exit(-1);
    }
    *new_node = node;
    this->rear->next = new_node;
    this->rear = new_node;
    this->front;
  }

//When we get the node, the first node is returned.
  T* dequeue() {
    if(!this->front->next) {
      return nullptr;
    }
    T* temp_node;
    temp_node = this->front->next;
    this->front->next = temp_node->next;

    if(this->rear == temp_node) {
      this->rear = this->front;
    }
    return temp_node;
  }

//When the event happens, we insert the event according to the order of time
  T* orderEnqueue(Event &event) {
    Event* temp = Event;
    if(!temp) {
      exit(-1);
    }
    *temp = event;
    if(!this->front->next) {
      this->enqueue(*temp);
      return this->front;
    }

    //Insert the event according to the order of occur time
    Event* temp_event_list = this->front;
    while(temp_event_list->next && temp_event_list->next->occur_time < event.occur_time) {
      temp_event_list = temp_event_list->next;
    }

    //Insert the event into the queue
    temp->next = temp_event_list->next;
    temp_event_list->next = temp;

    //return the head pointer
    return this->front;
  }
  int length() {
    T* temp_node;
    temp_node = this->front->next;
    int length = 0;
    while(temp_node) {
      temp_node = temp_node->next;
      ++length;
    }
    return length;
  }
private:
  T* front;
  T* rear;
};
#endif /* Queue_hpp */
