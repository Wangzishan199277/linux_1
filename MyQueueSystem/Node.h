//
// Node.h
// QueueSystem
//

#ifndef Node_h
#define Node_h

#include "Random.hpp"

define RANDOM_PARAMETER 100;

struct Node {
    int arrive_time;
    int duration;
    struct Node *next;
 
    //THe default arrive event is 0, the event to be served is random
    Node(int arrive_time = 0, int duration = Random::uniform(RANDOM_PARAMETER)):arrive_time(arrive_time), duration(duration), next(nullptr){}
};

typedef struct Node Node;
typedef struct Node Customer;

#endif /* Node_h */
