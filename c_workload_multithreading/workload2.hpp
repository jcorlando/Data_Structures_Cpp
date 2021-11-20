#ifndef WORKLOAD2_H
#define WORKLOAD2_H


void* sum_routine2(void* param)
{
    // Allocate HEAP memory for
    // return value of thread
    long* sum2 = (long *)malloc( sizeof(long) );

    // v This gets executed in parallel v
    for( long i = 0; i < (N/NUM_THREADS); i++ )
    {
        *sum2 += 1;
    }
    // ^ This gets executed in parallel ^

    return (void*) sum2;
}


void WORKLOAD2(long &sum2)
{
    pthread_t thread[NUM_THREADS];
    long* part_sum2;

    // Create threads
    for(uint i = 0; i < NUM_THREADS; i++)
    {
        pthread_create( &(thread[i]), NULL, sum_routine2, NULL );
    }

    // Join threads
    for(uint i = 0; i < NUM_THREADS; i++)
    {
        pthread_join( thread[i], (void**) &part_sum2 );
        sum2 += *part_sum2;
    }

    // Deallocate memory for
    // return value of thread
    free(part_sum2);
}


#endif // WORKLOAD2_H
