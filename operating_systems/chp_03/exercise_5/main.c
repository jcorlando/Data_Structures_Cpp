#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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


// My defined length of the shared memory. 65526/8 == 8192 u_int64_t digits.
// As long as the sequence doesn't exceed 8192, the memory can hold it. 
#define SHM_SIZE 65536


int main(int argc, char **argv)
{
    // Error check for only 1 command line argument passed in. 
    if ( argc != 2 )
    {
        printf("Error: Please supply only 1 Command Line argument (A positive integer only) to this program...\nThis number represents the starting iteration of the Collatz Sequence.\n");
        return EXIT_FAILURE;
    }

    // Error check for only numbers (No CHAR or STRINGS)
    // Check for negative numbers

    // Create a new char array with the length of the argument
    // array to each individual char for erroneous values
    uint argv_len = strlen(argv[1]);
    char number[argv_len];
    strcpy( number, argv[1] );

    uint i = 0;
    // Set flag for if 1st "CHAR" character is a negative number "-"
    if ( number[0] == '-' )
        { i = 1; }
    
    
    for ( ; number[i] != 0; i++ )
    {
        //if (number[i] > '9' || number[i] < '0')
        if ( !isdigit(number[i]) )
        {
            printf("Error: The value you have supplied seems to be erroneous...\nPlease supply only 1 Command Line argument (A positive integer only) to this program...\nThis number represents the starting iteration of the Collatz Sequence.\n");
            return EXIT_FAILURE;
        }
    }


    // Error check for only positive integers being passed in. 
    if ( atoi(argv[1]) < 1 )
    {
        printf("Error: The number you supplied is a Non-positive integer.\nPlease only input Positive Integers...\n");
        return EXIT_FAILURE;
    }
    //<---- End Error Checking


 
    /* shared memory file descriptor */
    int shm_fd;
 
    /* pointer to shared memory object */
    void* ptr;

    // Create child process and identify each
    // parent and child process with their unique pid
    pid_t pid = fork();


    // If "CHILD" process
    if (pid == 0)
    {
        /* create the shared memory object */
        shm_fd = shm_open("/my_shared_mem.dat", O_CREAT | O_RDWR, 0666);
    
        /* configure the size of the shared memory object */
        ftruncate(shm_fd, SHM_SIZE);
    
        /* memory map the shared memory object */
        ptr = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);


        // Calculate Collatz Sequence
        u_int64_t number = atoi(argv[1]);


        /* write to the shared memory object */
        /* and increment pointer */
        memcpy(ptr, &number, sizeof(number));
        ptr = (u_int64_t*)ptr + 1;

        // Continue Calculating Collatz Conjecture
        while (number > 1)
        {
            if (number % 2 == 0) //for even numbers
            {
                number = number / 2;
                /* write to the shared memory object */
                /* and increment pointer */
                memcpy(ptr, &number, sizeof(number));
                ptr = (u_int64_t*)ptr + 1;
            }
            
            else //------------->for odd numbers
            {
                number = number * 3 + 1;
                /* write to the shared memory object */
                /* and increment pointer */
                memcpy(ptr, &number, sizeof(number));
                ptr = (u_int64_t*)ptr + 1;
            }
        }

        // Always use exit() in child processes
        exit(EXIT_SUCCESS);
    }
    else // else "PARENT" process
    {
        // Wait for "CHILD" process to **FINISH**
        int child_status;
        waitpid(pid, &child_status, 0);

        /* open the shared memory object */
        shm_fd = shm_open("/my_shared_mem.dat", O_RDONLY, 0666);
    
        /* memory map the shared memory object */
        ptr = mmap(0, SHM_SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    
        /* read from the shared memory object */
        while ( *((u_int64_t*)ptr) != 1 )
        {
            printf("%lu ", *((u_int64_t*)ptr));
            ptr = (u_int64_t*)ptr + 1;
        }

        // Print the last value which is always 1
        printf("%lu \n", *((u_int64_t*)ptr));
    
        /* remove the shared memory object */
        shm_unlink("/my_shared_mem.dat");
    }
    
    return EXIT_SUCCESS;
}

