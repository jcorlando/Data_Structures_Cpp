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

int main(int argc, char *argv[])
{
    // Setup variables
    double cpu_time_used;
    long a;


    // v Below here is for 2nd implementation
    if( argc == 2 )
    {
        std::cin >> a;
        WORKLOAD_2(a);  //<--- This is using popen() and fscanf()
    }
    else
    {
        a = 0;
        WORKLOAD_2(a);  //<--- This is using popen() and fscanf()
    }
    // ^ Above here is for 2nd implementation
    
    
    // <----------Start Timer---------->
    // auto start = std::chrono::high_resolution_clock::now();
    // <----------Start Timer---------->
    // WORKLOAD(a);    //<--- This is using file descriptors and pipes
    // <-----------Stop Timer----------->
    // auto stop = std::chrono::high_resolution_clock::now();
    // <-----------Stop Timer----------->

    // <-----------Calculate Time----------->
    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    // <-----------Calculate Time----------->

    // std::cout << "Number of tasks: " << NUM_TASKS << std::endl;
    // std::cout << "Number of iterations: " << N << std::endl;
    // std::cout << "Time taken by function: " << duration.count() << " mili-seconds" << std::endl;
    // std::cout << "a = " << a << std::endl;

    // v Below here is for 2nd implementation
    std::cout << a << std::endl;
    // ^ Above here is for 2nd implementation

    return 0;
}
