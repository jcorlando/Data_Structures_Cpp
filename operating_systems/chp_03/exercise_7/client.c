#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/*
*  A haiku is a three-line poem in which the first line contains five syllables, the second line
*  contains seven syllables, and the third line contains five syllables. Write a haiku server that
*  listens to port 5575. When a client connects to this port, the server responds with a haiku. The
*  date client shown in Figure 3.9.3 can be used to read the quotes returned by your haiku server.
*/


// Client side C/C++ program to demonstrate Socket programming with a Haiku Response


//----- Some Defined MACROS ------!!
#define PORT 65432
#define HEADER 64

int main()
{
    // Create a socket
    int socket_client_fd;
    // calling socket function and storing the result in the variable
    // socket( domainOfTheSocket, TypeOfTheSocket, FlagForProtocol{0 for default protocol i.e, TCP} )
    // AF_INET = constant defined in the header file for us
    // TCP vs UDP --- SOCK_STREAM for TCP
    // flag 0 for TCP (default protocol)
    socket_client_fd = socket(AF_INET, SOCK_STREAM, 0);


    // creating network connection in order to connect to the other side
    // of the socket we need to declare connect with specifying address
    // where we want to connect to already defined struct sockaddr_in
    struct sockaddr_in server_address;
    // what type of address we are woking with
    server_address.sin_family = AF_INET;
    // for taking the port number and htons converts the port # to the
    // appropriate data type we want to write to specifying the port
    // htons : conversion functions


    // Need to use htons to convert the byte order of
    // the port number to from host order to network order

    // Function to convert between host and network byte order
    server_address.sin_port = htons(PORT);



    // structure within structure A.B.c
    // INADDR_LOOPBACK is for connection with localhost (127.0.0.1)
    // INADDR_ANY is for connection with 0000 or AKA receive any ip address
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    // connect returns us a response that connection is establlised or not
    int connect_status = connect(socket_client_fd, (struct sockaddr *) &server_address, sizeof(server_address));


    // check for the error with the connection
    if (connect_status == -1)
    {
        printf("There was an error making a connection to socket\n" );
        close(socket_client_fd);
        return EXIT_FAILURE;
    }

    // Connection has been successfully established below here



    // Header length in bytes
    char msg_length_header[HEADER];


    // Receive the length of the message that was sent as a HEADER from the server
    recv(socket_client_fd, &msg_length_header, sizeof(msg_length_header), 0);


    // Convert string message length into int message length
    uint msg_length = atoi(msg_length_header);


    // recieve data from the server
    char server_response[msg_length];


    // recieve the data from the server
    recv(socket_client_fd, &server_response, sizeof(server_response), 0);

    // recieved data from the server successfully then printing the data obtained from the server
    printf("%s\n", server_response);

    // closing the socket
    close(socket_client_fd);

    
    return EXIT_SUCCESS;
}
