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
*  An echo server echoes back whatever it receives from a client. For example, if a client sends
*  the server the string Hello there!, the server will respond with Hello there!
*  
*  Write an echo server using the Java networking API described in Section Sockets. This server
*  will wait for a client connection using the accept() method. When a client connection is received, the server will loop, performing the following steps:
*  
*  * Read data from the socket into a buffer.
*  * Write the contents of the buffer back to the client.
*  
*  The server will break out of the loop only when it has determined that the client has closed the connection.
*  
*  The date server of Figure 3.9.2 uses the java.io.BufferedReader class. BufferedReader extends the java.io.Reader
*  class, which is used for reading character streams. However, the echo server cannot guarantee that it will read
*  characters from clients; it may receive binary data as well. The class java.io.InputStream deals with data at the
*  byte level rather than the character level. Thus, your echo server must use an object that extends java.io.InputStream.
*  The read() method in the java.io.InputStream class returns −1 when the client has closed its end of the socket connection.
*/


// Server side C/C++ program to demonstrate a TCP Echo Server


//----- Some Defined MACROS ------!!
#define PORT 65432
#define HEADERSIZE 64
#define ECHO "This server will echo whatever string is received from the client!!!\0"

int main()
{
    char messageToSend[] = ECHO;


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
