#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE 80  /* The maximum length command */

int main()
{
    // char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = true;         /* flag to determine when to exit program */

    while (should_run)
    {
        printf("\033[;32m"); // <-- Create Green text
        printf("osh> ");     // <-- Shell Prompt
        fflush(stdout);     // <-- Flush I/O buffers
        printf("\033[;37m"); // <-- Revert back to White Text
        char string[1024];
        scanf("%s", string);
        fflush(stdin);      // <-- Flush I/O buffers
        if( !strcmp(string, "exit") ) { // <-- Exit if "exit" command
            should_run = false;
        }
        /* 
        *  After reading user input, the steps are:
        *  (1) fork a child process using fork()
        *  (2) the child process will invoke execvp()
        *  (3) parent will invoke wait() unless command included &
        */ 
    }

    return EXIT_SUCCESS;
}
