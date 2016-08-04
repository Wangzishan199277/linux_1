//
// main.cpp
// QueueSystem
//

#include "QueueSystem.hpp"

#include <iostream>
#include <cstdlib>

int main(){

    std::srand((unsigned)std::time(0));    //use the current time as the seed
    int total_service_time = 240;          //minutes
    int window_num = 4;
    int simulate_num = 10000               //simulation times
    
    QueueSystem system(total_service_time, window_num);
    system.simulate(simulate_num);
    
    std::cout << "The average time of customer stay in bank: " << system.getAverageTime() << std::endl;
    std::cout << "THe number of customer arrive bank per minute: " << system.getAvgCustomers() << std::endl;

    return 0;
}

