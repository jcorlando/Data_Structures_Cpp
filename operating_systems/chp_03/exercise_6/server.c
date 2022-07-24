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
*  The section on -- Communication in client-server systems - Sockets -- describes certain port
*  numbers as being well known—that is, they provide standard services. Port 17 is known as the
*  quote-of-the-day service. When a client connects to port 17 on a server, the server responds
*  with a quote for that day.
*  
*  Modify the date server shown in Figure 3.9.2 so that it delivers a quote of the day rather
*  than the current date. The quotes should be printable ASCII characters and should contain
*  fewer than 512 characters, although multiple lines are allowed. Since these well-known
*  ports are reserved and therefore unavailable, have your server listen to port 6017. The
*  date client shown in Figure 3.9.3 can be used to read the quotes returned by your server.
*/


// Server side C/C++ program to demonstrate Socket programming


//----- Some Defined MACROS ------!!
#define PORT 65432
#define HEADERSIZE 64
#define MESG_DAY "Be Strong\n But Not Rude\n\nBe Kind But\n Not Weak\n\nBe Humble\n But Not Timid\n\nUtf-8 Encoded string  ==  привет мир and emoji --> \U0001F600\0"
// #define MESG_DAY "Be Strong\n But Not Rude\n\nBe Kind But\n Not Weak\n\nBe Humble\n But Not Timid\0"

int main()
{
    char messageToSend[] = MESG_DAY;


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
