#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//-------- Some Defined MACROS --------!!
#define PORT 5575
#define HEADERSIZE 64

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
    int fd[2];

    if(pipe(fd) == -1)
    {
        printf("\n\nAn error occured opening the pipe\n");
        return EXIT_FAILURE;
    }
    



    return EXIT_SUCCESS;
}
