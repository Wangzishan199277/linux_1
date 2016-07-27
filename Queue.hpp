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
  Queue();
  ~Queue();
  void clearQueue();
  T* enqueue(T &node);
  T* dequeue();
  T* orderEnqueue(Event &event);
  int length();
private:
  T* front;
  T* rear;
};
#endif /* Queue_hpp */
