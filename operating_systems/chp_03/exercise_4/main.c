#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

/*
*  The Collatz conjecture concerns what happens when we take any positive
*  integer and apply the following algorithm:
*  
*      {  n/2      if n is even
*  n = |  
*      { 3*n + 1   if n is odd
*  
*  The conjecture states that when this algorithm is continually applied,
*  all positive integers will eventually reach 1.
* ---------------------------------------------------------------------------------
*  Write a C program using the fork() system call that generates this sequence
*  in the child process. The starting number will be provided from the command
*  line. For example, if 8 is passed as a parameter on the command line, the
*  child process will output 8, 4, 2, 1. Because the parent and child processes
*  have their own copies of the data, it will be necessary for the child to output
*  the sequence. Have the parent invoke the wait() call to wait for the child
*  process to complete before exiting the program. Perform necessary error
*  checking to ensure that a positive integer is passed on the command line.
*/

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


    // Create child process and identify each
    // parent and child process with their unique pid
    pid_t pid = fork();


    // If "CHILD" process
    if (pid == 0)
    {
        u_int64_t number = atoi(argv[1]);

        // Print first initial value
        printf("%ld ", number);

        while (number > 1)
        {
            if (number % 2 == 0) //for even numbers
                { number = number / 2; }
            
            else //------------->for odd numbers
                { number = number * 3 + 1; }
            
            printf("%ld ", number);
        }
        
        printf("\n");

        // Always use exit() in child processes
        exit(EXIT_SUCCESS);
    }

    // else "PARENT" process
    else
    {
        // Wait for "CHILD" process to **FINISH**
        int child_status;
        waitpid(pid, &child_status, 0);
    }

    
    return EXIT_SUCCESS;
}

