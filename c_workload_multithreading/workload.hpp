#ifndef WORKLOAD_H
#define WORKLOAD_H

void* sum_routine(void* param)
{
    // v This gets executed in parallel v
    for( long i = 0; i < (N/NUM_THREADS); i++ )
    {
        pthread_mutex_lock(&sum_mutex);
        sum += 1;
        pthread_mutex_unlock(&sum_mutex);
    }
    // ^ This gets executed in parallel ^

    pthread_exit(0);
}


void WORKLOAD()
{
    pthread_t thread[NUM_THREADS];
    pthread_mutex_init(&sum_mutex, NULL);

    // Create threads
    for(uint i = 0; i < NUM_THREADS; i++)
    {
        pthread_create( &(thread[i]), NULL, sum_routine, NULL );
    }
    // Join threads
    for(uint i = 0; i < NUM_THREADS; i++)
    {
        pthread_join( thread[i], NULL );
    }
    pthread_mutex_destroy(&sum_mutex);
}

#endif // WORKLOAD_H
