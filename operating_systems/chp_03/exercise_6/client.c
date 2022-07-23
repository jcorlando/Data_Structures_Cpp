#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


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



// Client side C/C++ program to demonstrate Socket programming


//----- Some Defined MACROS ------!!
#define PORT 65432
#define HEADER 64

int main()
{
    // Create a socket
    int socket_fd;
    // calling socket function and storing the result in the variable
    // socket( domainOfTheSocket, TypeOfTheSocket, FlagForProtocol{0 for default protocol i.e, TCP} )
    // AF_INET = constant defined in the header file for us
    // TCP vs UDP --- SOCK_STREAM for TCP
    // flag 0 for TCP (default protocol)
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);


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
    server_address.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY is for connection with 0000
    // connect returns us a response that connection is establlised or not
    int connect_status = connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));


    // check for the error with the connection
    if (connect_status == -1)
    {
        printf("There was an error making a connection to socket\n" );
        close(socket_fd);
        return EXIT_FAILURE;
    }



    // Connection has been successfully established below here

    // Header length in bytes
    char msg_length[HEADER];


    // Receive the length of the message that was sent from the server
    recv(socket_fd, &msg_length, sizeof(msg_length), 0);

    printf("Ther server sent the Message Length of : \n\n%s\n\n", msg_length);



    // recieve data from the server
    char server_response[1024];


    // recieve the data from the server
    recv(socket_fd, &server_response, sizeof(server_response), 0);

    // recieved data from the server successfully then printing the data obtained from the server

    // printf("Ther server sent the data : \n\n%s", server_response);

    // closing the socket
    close(socket_fd);

    
    return EXIT_SUCCESS;
}
