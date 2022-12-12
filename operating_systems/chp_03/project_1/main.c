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
    int should_run = true;      /* flag to determine when to exit program */
    bool should_wait = true;    /* <-- flag to determine if Child Process should wait To Finish */

    while(should_run)
    {
        printf("\033[;32m");        // <-- Create Green text
        fprintf(stdout, "osh> ");   // <-- Prompt User for Input
        fflush(stdout);             // <-- Flush I/O (Output) buffers
        printf("\033[;37m");        // <-- Revert back to White Text
        char string[MAXLENCOMM];
        char *arguments[MAX_ARG];
        fgets(string, MAXLENCOMM, stdin); // <-- Read user input from stdIn
        fflush(stdin);        // <-- Flush I/O (Input) buffers
        string[strcspn(string, "\n")] = 0; // <-- Remove User Input NewLine Character "\n"
        
        // Detect "!!" and empty string "" inputs <-- Handle Accordingly
        uint prevIndex;
        if( string != NULL && !strcmp(string, "!!") ) {
            if (commandHistory.size == 0) {
                fprintf(stdout, "No commands in history.\n");
                fflush(stdout);
            }
            else if ( commandHistory.head == 0 ) {
                prevIndex = MAXHIST - 1;
                strcpy(string, commandHistory.history[prevIndex]);
                fprintf(stdout, "No commands in history.\n");
                fflush(stdout);
            }
            else {
                prevIndex = commandHistory.head - 1;
                strcpy(string, commandHistory.history[prevIndex]);
                fprintf(stdout, "No commands in history.\n");
                fflush(stdout);
            }
        }
        // If Valid Input, Add Entry To History List
        else if ( strcmp(string, "") ) {
            addEntry(&commandHistory, string);
        }

        // Tokenize Input String
        uint lastIndex = 0;
        char *token;
        token = strtok(string, " ");

        // TODO: Add Functionality That Detects "<" or ">" Tokens and Handles inpu/output Re-Direction
        // TODO: Managing the redirection of both input and output will involve using the dup2() function
        // TODO: If "!!" Command detected, first print the previous command, then run

        for(uint i = 0; token != NULL; i++) {
            arguments[i] = token;
            arguments[i + 1] = NULL; // <-- Insert "NULL" as last argument
            token = strtok(NULL, " ");
            lastIndex = i;
        }

        // Detect "exit" and "&" Inputs
        if( arguments[0] != NULL && !strcmp(arguments[0], "exit") ) { // <-- Exit if "exit" command
            should_run = false;
        }
        should_wait = true;
        if( arguments[lastIndex] != NULL && !strcmp(arguments[lastIndex], "&") ) {
            should_wait = false;
            arguments[lastIndex] = NULL;
        }

        // Fork() and Execute Command In Child Process
        pid_t parent;

        if( (parent = fork()) == -1 ) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(!parent) {
            if(should_run) {
                int err = execvp(arguments[0], arguments);
                if(err == -1) {
                    exit(EXIT_FAILURE);
                }
            }
            exit(EXIT_SUCCESS); // Always use exit() in child processes
        }
        else {
            if(should_wait) {
                pid_t wStatus;
                wait(&wStatus);
                while( (wait(&wStatus)) > 0 ) { //<-- Father waits for all the child processes
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
        }
    }

    return EXIT_SUCCESS;
}
