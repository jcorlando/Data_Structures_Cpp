from concurrent.futures import thread
import socket
import threading
import time

from sympy import true


quoteOfTheDay = "Whoever fights monsters should see to it that in the process he does not become a monster. And if you gaze long enough into an abyss, the abyss will gaze back into you."


PORT = 6017
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)



def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected")

    connected = true
    while connected:
        msg = conn.recv()
        
        




def start():
    server.listen()
    while true:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.active_count() - 1}")




print("[Starting] server is starting")
start()



