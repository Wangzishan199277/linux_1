//The end of this file  seems to be incomplete.
//
// QueueSystem.hpp
// QUeueSystem
//

#ifndef QueueSystem_hpp
#define QueueSystem_hpp

#include "Event.hpp"
#include "Queue.hpp"
#include "ServiceWindow.hpp"

class QueueSystem {

public:
  //initialize the queue system
  QueueSystem(int total_service_time, int window_num);

  //destory
  ~QueueSystem();

  //start the simulation
  void simulate(int simulate_num);

  inline double getAvgStayTime() {
    return avg_stay_time;
  }

  inline double getAvgStayTime() {
    return avg_customers;
  }

private:
  //let the queue system run for one time
  double run();

  //initialize all the parameters
  void init();

  //clear all the parameters
  void end();

  //get the index of free window
  int getIdleServiceWindow();

  //deal the arrival event of customers
  void customerArrived();

  //deal the leaving event of customers
  void customerDeparture();

  //total serving number of window
  int window_num;

  //total seving time
  int total_service_time;

  //total customer stay time
  int customer_stay_time;

  //total customer number
  int total_customer_num;

  //key components
  ServiceWindow* windows;
  Queue<Customer> customer_list;
  Queue<Event> event_list;
  Event* current_event;

  //outcome for outside use
  double avg_customers;
  double avg_stay_time;
};

