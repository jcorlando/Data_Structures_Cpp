#include <stdio.h>
#include <stdlib.h>

/*
*  In the previous exercise, the child process must output the sequence of numbers generated
*  from the algorithm specified by the Collatz conjecture because the parent and child have
*  their own copies of the data. Another approach to designing this program is to establish
*  a shared-memory object between the parent and child processes. This technique allows
*  allows the child to write the contents of the sequence to the shared-memory object. The
*  parent can then output the sequence when the child completes. Because the memory is
*  shared, any changes the child makes will be reflected in the parent process as well.
* -------------------------------------------------------------------------------------------
*  This program will be structured using POSIX shared memory as described in Section POSIX
*  shared memory. The parent process will progress through the following steps:
*  
*  a)  Establish the shared-memory object ( shm_open(), ftruncate(), and mmap() ).
*  b)  Create the child process and wait for it to terminate.
*  c)  Output the contents of shared memory.
*  d)  Remove the shared-memory object.
* -------------------------------------------------------------------------------------------
*  One area of concern with cooperating processes involves synchronization issues. In this
*  exercise, the parent and child processes must be coordinated so that the parent does not
*  output the sequence until the child finishes execution. These two processes will be
*  synchronized using the wait() system call: the parent process will invoke wait(), which
*  will suspend it until the child process exits.
*/

int main()
{
    printf("Narbacular Drop!!\n");
    
    return EXIT_SUCCESS;
}

