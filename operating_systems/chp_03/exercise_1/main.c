#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
*  Assignment : #1
*  Using either a UNIX or a Linux system, write a C program that forks
*  a child process that ultimately becomes a zombie process. This
*  zombie process must remain in the system for at least 10 seconds.
*/

int main()
{
    // Used to identify each parent and child process
    int pid;

    // Create child process
    pid = fork();

    // If parent process, print (pid) number
    if (pid != 0)
        printf("\n\nI am the parent process & my process id number is : %d \n", (int)getpid());
    
    // else child process print (pid) number
    else
        printf("I am the child process & my process id number is : %d \n\n", (int)getpid());


    // If child process sleep for 10 seconds then exit.
    // This creates a zombie process because the parent is
    // still running but the child has been terminated.
    if (pid == 0)
    {
        sleep(10);
        exit(0);
    }
    else
    {
        while(1);
    }


    return 0;
}
