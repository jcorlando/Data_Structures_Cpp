#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Typedefs, Macros & Personal Definitions & Includes
#define MAXLENCOMM 1024 /* The maximum command length */
#define MAX_ARG 128     /* The maximum argument length */
#define MAXHIST 64      /* The maximum saved history */
typedef unsigned int uint;
#include "circularbuffer.c" // <-- My personal includes

int main()
{
    struct CircularBuffer commandHistory = {.size = 0, .head = 0};
    int should_run = true;    /* flag to determine when to exit program */

    while(should_run)
    {
        printf("\033[;32m");  // <-- Create Green text
        printf("osh> ");      // <-- Prompt User for Input
        fflush(stdout);       // <-- Flush I/O buffers
        printf("\033[;37m");  // <-- Revert back to White Text
        char string[MAXLENCOMM];
        char *arguments[MAX_ARG];
        fgets(string, MAXLENCOMM, stdin); // <-- Read user input from stdIn
        fflush(stdin);        // <-- Flush I/O buffers
        string[strcspn(string, "\n")] = 0; // <-- Remove User Input NewLine Character "\n"
        addEntry(&commandHistory, string);
        char *token;
        token = strtok(string, " ");
        for(uint i = 0; token != NULL; i++) {
            arguments[i] = token;
            arguments[i + 1] = NULL; // <-- Insert "NULL" as last argument
            token = strtok(NULL, " ");
        }
        if( !strcmp(arguments[0], "exit") ) { // <-- Exit if "exit" command
            should_run = false;
        }
        /* 
        *  After reading user input, the steps are:
        *  (1) fork a child process using fork()
        *  (2) the child process will invoke execvp()
        *  (3) parent will invoke wait() unless command included &
        */ 

        pid_t parent;

        if( (parent = fork()) == -1 ) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(!parent) {
            if(should_run) {
                int err = execvp(arguments[0], arguments);
                if(err == -1) {
                    printf("\nCould Not Find Program To Execute\n");
                    exit(EXIT_FAILURE);
                }
            }
            exit(EXIT_SUCCESS); // Always use exit() in child processes
        }
        else {
            // parent must wait unless "&" is added to the end of arguments vector
            pid_t wStatus;
            wait(&wStatus);

            // If Program Finished Execution Normally i.e. (Without External SIG-Kill)
            if(WIFEXITED(wStatus)) {
                int statusCode = WEXITSTATUS(wStatus); // <-- Capture Exit Status
                if(statusCode == 0) {
                    // Program Exited With A Status Code Of EXIT_SUCCESS
                } else {
                    // Program Exited With A Status Code Of EXIT_FAILURE
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
