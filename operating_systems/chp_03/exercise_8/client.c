#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
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
