#ifndef WORKLOAD2_H
#define WORKLOAD2_H

void WORKLOAD_2(long &a)
{


    // v This gets executed in parallel v
    for( long i = 0; i < (N/NUM_TASKS); i++ )
    {
        a += 1;
    }
    // ^ This gets executed in parallel ^
    
}

#endif // WORKLOAD2_H
