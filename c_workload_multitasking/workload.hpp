#ifndef WORKLOAD_H
#define WORKLOAD_H

// My Macros
#define NUM_TASKS 8     // <- Number of tasks you want to create
#define N 100000000     // <- 100000000, 1000000000, 10000000000

void WORKLOAD(long &a)
{
    // initialize variable a=0
    a = 0;

    // Check to see if using more than 1 task/process
    if(NUM_TASKS > 1)
    {
        // get parent process ID and Fork first process
        pid_t ppid = getpid(); // <-- Parent pid
        pid_t pid = fork();
        if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");

        // Create the required number of additional processes
        for(uint i = 2; i < NUM_TASKS; i++)
        {
            if(pid > 0) pid = fork();
            if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
        }

        // Assign variable pid to each process PID #
        pid = getpid();

        // All processes execute this in parallel
        for( long i = 0; i < (N/NUM_TASKS); i++ )
        {
            a += 1;
        }

        


        if(pid != ppid) printf("Child Process\n");
        // Wait for all child processes to finish
        while(wait(NULL) > 0);
        if(pid == ppid) printf("Parent process\n");
        


        // Terminate all child processes
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
