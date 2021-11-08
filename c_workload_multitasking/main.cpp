#include <iostream>
#include <cmath>
#include <chrono>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

// My Macros
#define NUM_TASKS 4     // <- Number of tasks you want to create
#define N 100000000     // <- 100000000, 1000000000, 10000000000

// My includes
#include "workload.hpp"
#include "workload2.hpp"

int main()
{
    // Setup variables
    double cpu_time_used;
    long a = 0;
    
    // <----------Start Timer---------->
    auto start = std::chrono::high_resolution_clock::now();
    // <----------Start Timer---------->
    // WORKLOAD(a);    //<--- This is using file descriptors and pipes
    WORKLOAD_2(a);  //<--- This is using popen() and fscanf()
    // <-----------Stop Timer----------->
    auto stop = std::chrono::high_resolution_clock::now();
    // <-----------Stop Timer----------->
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Number of tasks: " << NUM_TASKS << std::endl;
    std::cout << "Number of iterations: " << N << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " mili-seconds" << std::endl;
    std::cout << "a = " << a << std::endl;

    return 0;
}
