#ifndef WORKLOAD_H
#define WORKLOAD_H

// My Macros
#define NUM_TASKS 8     // <- Number of tasks you want to create
#define N 10000000000   // <- 100000000, 1000000000, 10000000000

void WORKLOAD(long &a)
{
    // initialize variable a=0
    a = 0;

    // Check to see if using more than 1 task/process
    if(NUM_TASKS > 1)
    {
        // Fork first process and get parent process ID
        pid_t pid = fork();
        pid_t ppid = 0; // <-- Parent pid
        if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
        if(pid > 0) ppid = getpid();

        // Create the required number of additional processes
        for(uint i = 2; i < NUM_TASKS; i++)
        {
            if(pid > 0) pid = fork();
            if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
        }

        for (long i = 0; i < (N/NUM_TASKS); i++)
        {
            a += 1;
        }


        // Combine all intermediate results using pipes
        


        // wait for all child processes to finish and Kill all child processes
        while(wait(NULL) > 0);
        if(pid != ppid) exit(0);
    }

    // execute using only 1 task/process
    else
    {
        for (long i = 0; i < N; i++)
        {
            a += 1;
        }
    }
}

#endif // WORKLOAD_H