import socket

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as my_socket:
    my_socket.bind( (HOST, PORT) )
    my_socket.listen()
    ( conn, addr ) = my_socket.accept() #<---This part is blocking
    with conn:
        print( f"Connected by {addr}" )
        while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)



