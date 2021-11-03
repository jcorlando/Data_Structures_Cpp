#include <iostream>
#include <cmath>
#include <array>
#include <chrono>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 100000000   // <- valid values: 100000000, 1000000000 , 10000000000
#define NUM_TASKS 2   // <- valid values:     2,         4,           8

void WORKLOAD(long &a)
{
  // Fork first process and get parent process ID
  pid_t pid = fork();
  pid_t ppid = 0;
  if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
  if(pid > 0) ppid = getpid();

  // Create the required number of additional processes
  for(uint i = 2; i < NUM_TASKS; i++)
  {
    if(pid == 0) pid = fork();
    if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
  }

  std::cout << "pid is : " << getpid() << std::endl;
  

  // for(long i = 0; i < N; ++i)  (*a)++;

  // Kill all child processes
  if(pid != ppid) exit(0);
}

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
