#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80  /* The maximum length command */

int main()
{
    typedef unsigned int uint;
    int should_run = true;    /* flag to determine when to exit program */

    while(should_run)
    {
        printf("\033[;32m");  // <-- Create Green text
        printf("osh> ");      // <-- Shell Prompt
        fflush(stdout);       // <-- Flush I/O buffers
        printf("\033[;37m");  // <-- Revert back to White Text
        char string[1024];
        char *arguments[MAX_LINE];
        fgets(string, 1024, stdin);
        fflush(stdin);        // <-- Flush I/O buffers
        char *token;
        token = strtok(string, " ");
        uint lastIndex = 0;
        for(uint i = 0; token != NULL; i++) {
            token[strcspn(token, "\n")] = 0;
            arguments[i] = token;
            token = strtok(NULL, " ");
            lastIndex = i;
        }
        arguments[lastIndex + 1] = NULL;
        if( !strcmp(arguments[0], "exit") ) { // <-- Exit if "exit" command
            should_run = false;
        }
        /* 
        *  After reading user input, the steps are:
        *  (1) fork a child process using fork()
        *  (2) the child process will invoke execvp()
        *  (3) parent will invoke wait() unless command included &
        */ 

        // TODO: Add history functionality

        pid_t parent;

        if( (parent = fork()) == -1 ) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(!parent) {
            execvp(arguments[0], arguments);
            exit(EXIT_SUCCESS); // Always use exit() in child processes
        }
        else {
            // parent must wait unless "&" is added to the end of arguments vector
            wait(NULL);
        }
    }

    return EXIT_SUCCESS;
}
