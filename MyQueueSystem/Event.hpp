//
// Event.hpp
// QueueSystem
//

#ifndef Event_hpp
#define Event_hpp

#include "Random.hpp"
#define RANDOM_PARAMETER 100

struct Event {
    int occur_time;

    //-1 represents arriving event, >=0 represents leaving event, the number also represents the service window

    int event_type;

    Event* next;

    //default for arriving event, the event is random
    Event(int occur_time = Random::uniform(RANDOM_PARAMETER), int event_type = -1):occur_time(occur_time), event_time(event_type),next(nullptr){}
};

#endif /* Event_hpp */
