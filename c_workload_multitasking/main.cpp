#include <iostream>
#include <cmath>
#include <array>
#include <chrono>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// My Macros
#define N 100000000   // <- valid values: 100000000, 1000000000 , 10000000000
#define NUM_TASKS 2   // <- valid values:     2,         4,           8

#include "workload.hpp"


int main()
{
    // Setup variables
    double cpu_time_used;
    long a = 0;
    // Setup variables


    
    // <----------Start Timer---------->
    auto start = std::chrono::high_resolution_clock::now();
    // <----------Start Timer---------->

    WORKLOAD(a);

    // <-----------Stop Timer----------->
    auto stop = std::chrono::high_resolution_clock::now();
    // <-----------Stop Timer----------->
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by function: " << duration.count() << " micro-seconds" << std::endl;

    return 0;
}
