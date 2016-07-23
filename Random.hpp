//
// Random.hpp
// QueueSystem
//

#ifndef Random_hpp
#define Random_hpp

#include <cstdlib>
#include <cmath>

class Ranodm{
public:
    //Random numbers which have the uniform distribution between [0, max)
    static double uniform(double max = 1){
    return ((double)std::rand() / (RAND_MAX)) * max;
    }
};
#endif /* Random_hpp */
