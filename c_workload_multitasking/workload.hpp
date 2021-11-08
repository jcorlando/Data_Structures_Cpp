#ifndef WORKLOAD_H
#define WORKLOAD_H

void WORKLOAD(long &a)
{
    // Create my own PID counter to keep
    // track of each process ID number #
    uint my_pid_counter = 0;

    // Intermediate temp variable
    // to accumulate running sum
    long temp;


    // Create some file descriptors
    int fd[NUM_TASKS][2];


    // Create some pipes
    for (uint i = 0; i < NUM_TASKS; i++)  pipe(fd[i]);
    
    

    // Check to see if using more than 1 task/process
    if(NUM_TASKS > 1)
    {
        // get parent process ID and Fork first process
        pid_t ppid = getpid(); // <-- Parent pid
        pid_t pid = fork();
        if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
        if(pid == 0) my_pid_counter += 1;

        // Create the required number of additional processes
        for(uint i = 2; i < NUM_TASKS; i++)
        {
            if(pid > 0) pid = fork();
            if(pid < 0)  /**/  fprintf(stderr, "Fork Failed\n");
            if(pid == 0) my_pid_counter += 1;
        }

        // Assign variable pid to each process PID #
        pid = getpid();

        // v This gets executed in parallel v
        for( long i = 0; i < (N/NUM_TASKS); i++ )
        {
            a += 1;
        }
        // ^ This gets executed in parallel ^


        // Write to pipes / file descriptor
        for (uint i = 0; i < NUM_TASKS; i++)
        {
            if(my_pid_counter != 0) // <-- If child process
            {
                close(fd[i][0]);
                write(fd[i][1], &a, sizeof(long));
            }
        }


        // Wait for all child processes to finish
        while(wait(NULL) > 0) { ; }


        // Read from pipes / file descriptor
        // start from 1 instead of 0 to skip 1st process
        for (uint i = 1; i < NUM_TASKS; i++)
        {
            if(my_pid_counter == 0) // <-- If parent process
            {
                read(fd[i][0], &temp, sizeof(long));
                a = a + temp;
            }
        }


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
