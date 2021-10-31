#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define N 10000000000   // <- Change this between 100000000 and 10000000000
#define NUM_THREADS 2   // 

void* WORKLOAD(long *a)
{
  for (long i = 0; i < N; ++i)  (*a)++;
  return NULL;
}

int main()
{
    // Setup variables
    clock_t start, end;
    double cpu_time_used;
    long a = 0;
    // Setup variables


    start = clock();
    WORKLOAD(&a);
    end = clock();


    // Print results
    cpu_time_used = ( (double) (end - start) ) / CLOCKS_PER_SEC;
    printf("WORKLOAD took %f seconds to execute \nThe value of a is : %ld\n", cpu_time_used, a);
    // Print results
    return 0;
}
