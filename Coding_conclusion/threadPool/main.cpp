//
// main.cpp
//
#include <iostream>  //std::cout, std::endl
#include <vector>    //std::vector
#include <string>    //std::string
#include <future>    //std::future
#include <thread>    //std::chrono::seconds

#include "ThreadPool.h"

int main() {
    ThreadPool pool(4);
    std::vector<std::future<std::string>> results;
    for(int i = 0; i < 8; i++){
	results.emplace_back(
		pool.enqueue([i]{
		    std::cout << "hello " << i << std::endl;
		    std::this_thread::sleep_for(std::chrono::seconds(1));
		    std::cout << "world " << i << std::endl;
		    return std::string("---thread") + std::to_string(i) + std::string(" finished.---"); 
		    })
		);
    }
    for(auto && result: results){
	std::cout << result.get() << ' ';
    }
    std::cout << std::endl;
}
