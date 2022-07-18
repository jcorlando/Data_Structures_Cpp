import socket
import threading

# This example creates threads and continuously runs after each connection
# and prints the message of the day until you use Kill (PID) or CTRL-C to
# kill the process.  My suggestion is to run the program from a terminal using
# the command "python server.py &" so that it runs in the background.

#------ Broadcast address, (0.0.0.0) is used for when running on cloud server
HOST = "127.0.0.1" #<--- Standard loopback interface address (localhost) (127.0.0.1)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as my_socket:
    my_socket.bind( (HOST, PORT) )


    def handle_client(conn, addr):
        print(f"[NEW CONNECTION] {addr} connected")
        with conn:
            print( f"Connected by {addr}" )
            mesg_day = "Message of the Day!!"
            conn.sendall( mesg_day.encode() )

    def start():
        my_socket.listen()
        while True:
            ( conn, addr ) = my_socket.accept() #<---This part is blocking
            thread = threading.Thread( target=handle_client, args=(conn, addr) )
            thread.start()
            print(f"[ACTIVE CONNECTIONS] {threading.activeCount() - 1}")


    print( "[STARTING] server is starting" )
    start()

    
    