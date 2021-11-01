#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <math.h>

#define N 100000000   // <- valid values: 100000000, 1000000000 , 10000000000
#define NUM_TASKS 2   // <- valid values:     2,         4,           8

void* WORKLOAD(long *a)
{
  for(uint i = 0; i < (uint)log2(NUM_TASKS); i++) pid_t pid = fork();
  

  printf("pid is : %d\n", getpid());
  

  // for(long i = 0; i < N; ++i)  (*a)++;

  
  return NULL;
}

int main()
{
    // Setup variables
    clock_t start, end;
    double cpu_time_used;
    long a = 0;
    // Setup variables


    // Start timer and call function
    // start = clock();
    WORKLOAD(&a);
    // end = clock();
    // cpu_time_used = ( (double) (end - start) ) / CLOCKS_PER_SEC;
    // Start timer and call function

    // Print results
    // printf("WORKLOAD took %f seconds to execute \nThe value of a is : %ld\n", cpu_time_used, a);
    // Print results
    return 0;
}
