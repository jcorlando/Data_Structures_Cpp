#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>


/*
*  Assignment : #2
*  Write a C program called time.c that determines the amount of time necessary
*  to run a command from the command line. This program will be run as "./time <command>"
*  and will report the amount of elapsed time to run the specified command. This will involve
*  using fork() and exec() functions, as well as the gettimeofday() function to determine
*  the elapsed time. It will also require the use of two different IPC mechanisms.
* -----------------------------------------------------------------------------------------------------
*  The general strategy is to fork a child process that will execute the specified command.
*  However, before the child executes the command, it will record a timestamp of the current
*  time (which we term "starting time"). The parent process will wait for the child process to
*  terminate. Once the child terminates, the parent will record the current timestamp for the
*  ending time. The difference between the starting and ending times represents the elapsed time
*  to execute the command. The example output below reports the amount of time to run the command ls:
* -----------------------------------------------------------------------------------------------------
*  The second version will use a pipe. The child will write the starting time to the pipe, and the
*  parent will read from it following the termination of the child process.  You will use the
*  gettimeofday() function to record the current timestamp. This function is passed a pointer to a
*  struct timeval object, which contains two members: tv_sec and t_usec. These represent the number of
*  elapsed seconds and microseconds since January 1, 1970 (known as the UNIX EPOCH).  For IPC between
*  the child and parent processes, the contents of the shared memory pointer can be assigned the struct
*  timeval representing the starting time. When pipes are used, a pointer to a struct timeval can be
*  written to—and read from—the pipe.
*/


// This implementation below uses pipes
int main(int argc, char **argv)
{
    // Create timeval struct that gets the Unix Epoch time value which is
    // accurate to the nearest microsecond but also has a range of years.
    // Both "PARENT" and "CHILD" will have this struct in their memory
    struct timeval start, end;

    // Create file descriptors
    int fd[2];

    // Create pipe and error check
    if (pipe(fd) == -1)
    {
        printf("\nAn error has ocurred with opening the pipen\n\n");
        return(EXIT_FAILURE);
    }

    // Create child process and identify each
    // parent and child process with their unique pid
    pid_t pid = fork();

    // If "CHILD" process
    if (pid == 0)
    {
        // Close read-end "fd[0]" of "CHILD" pipe
        close(fd[0]);

        // Set the start timer
        gettimeofday(&start, NULL);

        // Write to the start time to the "PIPE"
        write(fd[1], &start, sizeof(start));

        // Close the write-end of the pipe in the CHILD
        // process effectively closing the pipe entirely
        close(fd[1]);

        // execute 1st argument of command line with the included parameters
        execlp(argv[1], argv[1], argv[2], NULL);

        exit(EXIT_SUCCESS);
    }
    // else "PARENT" process
    else
    {
        // Close the write-end of the pipe in the PARENT process
        close(fd[1]);

        // Read from the pipe
        read(fd[0], &start, sizeof(start));

        // Wait for "CHILD" process to **FINISH**
        int child_status;
        waitpid(pid, &child_status, 0);

        // Stop the timer
        gettimeofday(&end, NULL);

        // Close the read-end "fd[0]" of the pipe in the
        // PARENT process effectively closing it entirely
        close(fd[0]);

        long delta_seconds = end.tv_sec - start.tv_sec;
        long delta_usecs = end.tv_usec - start.tv_usec;

        printf("\n Amount of elapsed time taken to execute program was : \n   seconds : %ld\n   micro-seconds : %ld\n\n", delta_seconds, delta_usecs);
    }

    return EXIT_SUCCESS;
}
