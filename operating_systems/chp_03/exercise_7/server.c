#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/*
*  A haiku is a three-line poem in which the first line contains five syllables, the second line
*  contains seven syllables, and the third line contains five syllables. Write a haiku server that
*  listens to port 5575. When a client connects to this port, the server responds with a haiku. The
*  date client shown in Figure 3.9.3 can be used to read the quotes returned by your haiku server.
*/


// Server side C/C++ program to demonstrate Socket programming with a Haiku Response


//----- Some Defined MACROS ------!!
#define PORT 65432
#define HEADERSIZE 64
#define HAIKU "Vibrant summertime\nA lovely, cute girl games\nin spite of the truck\0"

int main()
{
    char messageToSend[] = HAIKU;


    // create the server socket
    int socket_server_fd;


    // define the server address
    // creating the address the same way I created for TCPclient
    socket_server_fd = socket(AF_INET, SOCK_STREAM, 0);


    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // calling bind function to oir specified IP and port
    bind(socket_server_fd, (struct sockaddr*) &server_address, sizeof(server_address));


    listen(socket_server_fd, 5);

    // starting the accepting
    int socket_client_fd;

    // Send the size of the message first
    // Header length in bytes
    char send_length[HEADERSIZE];
    sprintf(send_length, "%lu", sizeof(messageToSend));


    // Run in a forever super loop just like a regular server
    while (true)
    {
        // accept(socketWeAreAccepting, structuresClientIsConnectingFrom, )
        //---------------- This part is blocking ------------------
        socket_client_fd = accept(socket_server_fd, NULL, NULL);
        //---------------- This part is blocking ------------------


        // Create child process and identify each
        // parent and child process with their unique pid
        pid_t pid = fork();


        // If "CHILD" process
        if (pid == 0)
        {
            // Send the size of the message as a string in the HEADER first
            send(socket_client_fd, send_length, sizeof(send_length), 0);


            // sending the message
            // send(toWhom, Message, SizeOfMessage, FLAG);
            send(socket_client_fd, messageToSend, sizeof(messageToSend), 0);


            // close the socket
            close(socket_server_fd);


            // Always use exit() in child processes
            exit(EXIT_SUCCESS);
        }
        else
        {
            // This is used to avoid children from becoming ZOMBIE child processes
            signal(SIGCHLD, SIG_IGN);
        }

    }

    close(socket_client_fd);
    return EXIT_SUCCESS;
}
