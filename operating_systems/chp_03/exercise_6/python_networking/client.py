import socket

#------ Broadcast address, (0.0.0.0) is used for when running on cloud server
HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432  # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as my_socket:
    my_socket.connect( (HOST, PORT) )
    data = my_socket.recv(1024)

print( data.decode() )


