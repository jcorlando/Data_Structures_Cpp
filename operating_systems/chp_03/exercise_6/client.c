#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
*  The section on -- Communication in client-server systems - Sockets -- describes certain port
*  numbers as being well known—that is, they provide standard services. Port 17 is known as the
*  quote-of-the-day service. When a client connects to port 17 on a server, the server responds
*  with a quote for that day.
*  
*  Modify the date server shown in Figure 3.9.2 so that it delivers a quote of the day rather
*  than the current date. The quotes should be printable ASCII characters and should contain
*  fewer than 512 characters, although multiple lines are allowed. Since these well-known ports
*  are reserved and therefore unavailable, have your server listen to port 6017. The date client
*  shown in Figure 3.9.3 can be used to read the quotes returned by your server.
*/


int main()
{
    printf("\nClient Started!!\n\n");
    
    return EXIT_SUCCESS;
}
