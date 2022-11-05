#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
{
    if( argc != 3 ) {
        printf("Usage:  ./filecopy  [Input File]  [Output File]\n");
        return EXIT_FAILURE;
    }

    FILE *fptr1, *fptr2;

    char c;

    // Open one file for reading
    fptr1 = fopen(argv[1], "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s \n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Open another file for writing
    fptr2 = fopen(argv[2], "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s \n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    return EXIT_SUCCESS;
}
