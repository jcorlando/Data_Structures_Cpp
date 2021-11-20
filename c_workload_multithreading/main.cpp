#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// My Macros
#define NUM_THREADS 8   // <- Number of threads you want to create
#define N 10000000000   // <- 100000000, 1000000000, 10000000000

// Global variables for
// first implementation
long sum = 0;
pthread_mutex_t sum_mutex;

// My includes
#include "workload.hpp"
#include "workload2.hpp"

int main()
{
    // Setup variables
    double cpu_time_used;
    long sum2 = 0;

    // <----------Start Timer---------->
    auto start = std::chrono::high_resolution_clock::now();
    // <----------Start Timer---------->
    // WORKLOAD();         //<--- This is using threads and mutexes
    WORKLOAD2(sum2);    //<--- This is using threads and return values
    // <-----------Stop Timer----------->
    auto stop = std::chrono::high_resolution_clock::now();
    // <-----------Stop Timer----------->

    // <-----------Calculate Time----------->
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    // <-----------Calculate Time----------->

    std::cout << "Number of threads: " << NUM_THREADS << std::endl;
    std::cout << "Number of iterations: " << N << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " mili-seconds" << std::endl;
    // std::cout << "sum = " << sum << std::endl;
    std::cout << "sum = " << sum2 << std::endl;
    

    return 0;
}
