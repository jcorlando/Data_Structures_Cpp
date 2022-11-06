#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

/* 
*  Design a file-copying program named filecopy.c using ordinary pipes. This program will be passed
*  two parameters: the name of the file to be copied and the name of the destination file. The program
*  will then create an ordinary pipe and write the contents of the file to be copied to the pipe. The
*  child process will read this file from the pipe and write it to the destination file. For example,
*  if we invoke the program as follows:
*  
*  -----------------------------
*  ./filecopy input.txt copy.txt
*  -----------------------------
*  
*  the file input.txt will be written to the pipe. The child process will read the contents of this file and
*  write it to the destination file copy.txt. You may write this program using either UNIX or Windows pipes.
*/ 

int main( int argc, char* argv[] )
{
    if( argc != 3 ) {
        printf("Usage:  ./filecopy  [Input File]  [Output File]\n");
        return EXIT_FAILURE;
    }
    
    // // Open another file for writing
    // fptr2 = fopen(argv[2], "w");
    // if (fptr2 == NULL) {
    //     printf("Cannot open file %s \n", argv[2]);
    //     exit(EXIT_FAILURE);
    // }

    int fd[2];  // Pipe

    char c, string[2048];

    FILE *fptrRead, *fptrWrite;

    pid_t childpid;

    // Error Checking Pipe Creation and Fork
    if( pipe(fd) == -1 ) {
        printf("\n\nAn error occured opening the pipe 1\n");
        return EXIT_FAILURE;
    }
    if( (childpid = fork()) == -1 ) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if( childpid == 0 )  // <-- Child Process
    {
        close(fd[1]);  // Child process closes up SEND side of pipe 1

        read(fd[0], string, sizeof(string));  // Read in a string from the pipe

        // Open another file for writing
        fptrWrite = fopen(argv[2], "w");
        if (fptrWrite == NULL) {
            printf("Cannot open file %s \n", argv[2]);
            exit(EXIT_FAILURE);
        }

        // Read contents from file
        int i = 0;
        while( string[i] != '\0' && i < 2048 )
        {
            c = string[i];
            fputc(c, fptrWrite);
            i++;
        }

        close(fd[0]);  // Child process closes up RECEIVE side of pipe 1
        
        exit(EXIT_SUCCESS); // Always use exit() in child processes
    }
    else      // <-- Parent Process
    {
        close(fd[0]);  // Parent process closes up RECEIVE side of pipe 1

        // Open one file for reading
        fptrRead = fopen(argv[1], "r");
        if (fptrRead == NULL) {
            printf("Cannot open file %s \n", argv[1]);
            exit(EXIT_FAILURE);
        }

        // Read contents from file
        c = fgetc(fptrRead);
        int i = 0;
        while ( c != EOF && i < 2047 ) {
            string[i] = c;
            c = fgetc(fptrRead);
            i++;
        }
        string[i] = '\0';

        write(fd[1], string, sizeof(string));  // Send "string'\0'" through the output side of pipe

        close(fd[1]);  // Parent process closes up SEND side of pipe 1
    }

    return EXIT_SUCCESS;
}
