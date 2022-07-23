import socket

#------ Broadcast address, (0.0.0.0) is used for when running on cloud server
HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432  # The port used by the server

#----- Other Constants ------!!
HEADER = 64
FORMAT = 'utf-8'


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    client_socket.connect( (HOST, PORT) )


    # Receive Message Length Header
    msg_length = client_socket.recv(HEADER).decode(FORMAT)

    if msg_length:
        msg_length = int(msg_length)

        # Receive Actual Message
        msg = client_socket.recv(msg_length).decode(FORMAT)
    
    client_socket.close()


print( msg )
client_socket.close()

