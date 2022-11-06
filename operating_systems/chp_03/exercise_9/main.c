#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

/* 
*  Design a program using ordinary pipes in which one process sends a string message to a second
*  process, and the second process reverses the case of each character in the message and sends it
*  back to the first process. For example, if the first process sends the message Hi There, the second
*  process will return hI tHERE. This will require using two pipes, one for sending the original
*  message from the first to the second process and the other for sending the modified message from
*  the second to the first process. You can write this program using either UNIX or Windows pipes.
*/ 

int main()
{
    int fd_1[2];  // Pipe 1
    int fd_2[2];  // Pipe 2

    int nBytes;

    char stdInBuffer[2048];
    char readBuffer[2048];

    nBytes = read(STDIN_FILENO, stdInBuffer, sizeof(stdInBuffer));  // Read in a string from stdin and the pipe

    pid_t childpid;

    // Error Checking Pipe Creation and Fork
    if( pipe(fd_1) == -1 ) {
        printf("\n\nAn error occured opening the pipe 1\n");
        return EXIT_FAILURE;
    }
    if( pipe(fd_2) == -1 ) {
        printf("\n\nAn error occured opening the pipe 2\n");
        return EXIT_FAILURE;
    }
    if( (childpid = fork()) == -1 ) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if( childpid == 0 )
    {
        close(fd_1[1]);  // Child process closes up SEND side of pipe 1
        close(fd_2[0]);  // Child process closes up RECEIVE side of pipe 2

        nBytes = read(fd_1[0], readBuffer, sizeof(readBuffer));  // Read in a string from the pipe
        printf("\nReceived string: %s\nnBytes  ==  %d\n\n", readBuffer, nBytes);
        
        for (int i = 0; i < (nBytes - 1); i++)
        {
            if ( islower(readBuffer[i]) ) {
                readBuffer[i] = toupper(readBuffer[i]); //change to uppercase
            }
            else {
                readBuffer[i] = tolower(readBuffer[i]); //else change to lowercase
            }
        }

        write(fd_2[1], readBuffer, (strlen(readBuffer)+1)); // Send "string'\0'" through the output side of pipe

        close(fd_1[0]);  // Child process closes up RECEIVE side of pipe 1
        close(fd_2[1]);  // Child process closes up SEND side of pipe 2
        
        exit(EXIT_SUCCESS); // Always use exit() in child processes
    }
    else
    {
        close(fd_1[0]);  // Parent process closes up RECEIVE side of pipe 1
        close(fd_2[1]);  // Parent process closes up SEND side of pipe 2

        char* string = stdInBuffer;

        write(fd_1[1], string, (strlen(string)+1));             // Send "string'\0'" through the output side of pipe

        nBytes = read(fd_2[0], readBuffer, sizeof(readBuffer)); // Read in a string from the pipe
        printf("\nReceived Reversed string: %s\nnBytes  ==  %d\n\n", readBuffer, nBytes);

        close(fd_1[1]);  // Parent process closes up SEND side of pipe 1
        close(fd_2[0]);  // Parent process closes up RECEIVE side of pipe 2
    }
    return EXIT_SUCCESS;
}
