#include <stdlib.h>   // exit(); EXIT_FAILURE; EXIT_SUCCESS;
#include <stdio.h>    // printf(); fprintf(); stdout; stdin; fflsuh(); fgets(); perror();
#include <unistd.h>   // fork(); execvp();
#include <string.h>   // strcpy(); strcspn(); strcmp();
#include <sys/wait.h> // pid_t; WEXITSTATUS(); WIFEXITED(); wait();
#include <fcntl.h>    // open(); 0_WRONLY; O_TRUNC; O)CREAT;

// Typedefs, Macros & Personal Definitions & Includes
#define MAXLENCOMM 1024 /* The maximum command length */
#define MAX_ARG 128     /* The maximum argument length */
#define MAXHIST 64      /* The maximum saved history */
#define false 0
#define true 1
typedef _Bool bool;
typedef unsigned int uint;
#include "circularbuffer.c" // <-- My personal includes

int main()
{
    struct CircularBuffer commandHistory = {.size = 0, .head = 0};
    int should_run = true;      /* flag to determine when to exit program */
    bool should_wait = true;    /* <-- flag to determine if Child Process should wait To Finish */
    char redirectFile[MAX_ARG];

    while(should_run)
    {
	memset(redirectFile, 0, sizeof(redirectFile));
        printf("\033[;32m");        // <-- Create Green text
        fprintf(stdout, "osh> ");   // <-- Prompt User for Input
        fflush(stdout);             // <-- Flush I/O (Output) buffers
        printf("\033[;37m");        // <-- Revert back to White Text
        char string[MAXLENCOMM];
        char *arguments[MAX_ARG];
        fgets(string, MAXLENCOMM, stdin); // <-- Read user input from stdIn
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
	
	// Child Process
        if(!parent) {
	    bool redirectOutput = false;
	    bool redirectInput = false;
	    int fd;
	    int terminal_stdout_fd;
	    int terminal_stdin_fd;
            if(should_run) {
		for(uint i = 0; i < lastIndex; i++) {
		  if( !strcmp(arguments[i], ">") ) {
		    redirectOutput = true;		    // <-- Set Output Re-direct flag to true
		    arguments[i] = NULL;		    // <-- set ">" argument string to NULL
		    strcpy(redirectFile, arguments[i + 1]); // <-- Copy Re-direct argument to "redirectFile" variable
		    arguments[i + 1] = NULL;		    // <-- Set (output) Re-direct string argument to NULL
		  }
		  if( !strcmp(arguments[i], "<") ) {
		    redirectInput = true;		      // <-- Set Input Re-direct flag to true 
		    arguments[i] = NULL;		      // <-- set "<" argument string to NULL
		    strcpy(redirectFile, arguments[i + 1]);   // <-- Copy Re-direct argument to "redirectFile" variable
		    arguments[i + 1] = NULL;		      // <-- Set (inputt) Re-direct string argument to NULL
		  }
		}

		// If (Output) Re-direct flag has been set
		if(redirectOutput) {
		  /* Create output file, GET file descriptor */
		  fd = open(redirectFile, O_WRONLY| O_TRUNC | O_CREAT, 0666);
		  /* Save current stdout for use later */
		  terminal_stdout_fd = dup(STDOUT_FILENO);
		  dup2(fd, STDOUT_FILENO);
		}

		// If (input) Re-direct flag has been set
		if(redirectInput) {
		  /* Read from input file, GET file descriptor */
		  fd = open(redirectFile, O_RDONLY);
		  /* Save current stdin for use later */
		  terminal_stdin_fd = dup(STDIN_FILENO);
		  dup2(fd, STDIN_FILENO);
		}

		// Run the Command that has been input
                int err = execvp(arguments[0], arguments);
                if(err == -1) {
		  exit(EXIT_FAILURE); // Always use exit() in child processes
                }
		if(redirectOutput) {
		  /* Restore Terminal stdout */
		  dup2(terminal_stdout_fd, STDOUT_FILENO);
		  if(close(terminal_stdout_fd) == -1) {
		    exit(EXIT_FAILURE);
		  }
		  /* Close file "fd" descriptor */
		  if(close(fd) == -1) {
		    exit(EXIT_FAILURE);
		  }
		}
		if(redirectInput) {
		  /* Restore Terminal stdin */
		  dup2(terminal_stdin_fd, STDIN_FILENO);
		  if(close(terminal_stdin_fd) == -1) {
		    exit(EXIT_FAILURE);
		  }
		  /* Close file "fd" descriptor */
		  if(close(fd) == -1) {
		    exit(EXIT_FAILURE);
		  }
		}
            }
            exit(EXIT_SUCCESS); // Always use exit() in child processes
	}

	// Parent Process
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
