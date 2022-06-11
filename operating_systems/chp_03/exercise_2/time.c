#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>

/*
*  Assignment : #2
*  Write a C program called time.c that determines the amount of time necessary
*  to run a command from the command line. This program will be run as "./time <command>"
*  and will report the amount of elapsed time to run the specified command. This will involve
*  using fork() and exec() functions, as well as the gettimeofday() function to determine
*  the elapsed time. It will also require the use of two different IPC mechanisms.
* -----------------------------------------------------------------------------------------------
*  The first version will have the child process write the starting time to a region of
*  shared memory before it calls exec(). After the child process terminates, the parent
*  will read the starting time from shared memory. Refer to Section POSIX shared memory
*  for details using POSIX shared memory. In that section, there are separate programs for
*  the producer and consumer. As the solution to this problem requires only a single program,
*  the region of shared memory can be established before the child process is forked, allowing
*  both the parent and child processes access to the region of shared memory.
*/

int main()
{
    // Used to identify each parent and child process
    int pid;

    // Create child process
    pid = fork();

    // If parent process, print time of day
    if (pid != 0)
    {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);
        printf("\nseconds : %ld\nmicro seconds : %ld", current_time.tv_sec, current_time.tv_usec);
    }
    
    // else child process print (pid) number
    else
        printf("\n\nI am the child process & my process id number is : %d \n\n", (int)getpid());
    
    
    return 0;
}
