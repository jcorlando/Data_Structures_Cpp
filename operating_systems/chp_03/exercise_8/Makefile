CFLAGS = -Wpedantic -Wall -Wextra
LDFLAGS =

server: server.c
	gcc $(CFLAGS) server.c -o server$(LDFLAGS)

client: client.c
	gcc $(CFLAGS) client.c -o client$(LDFLAGS)

.PHONY: run clean debugServer debugClient

clean:
	rm -f client server

debugServer: server.c
	gcc -g $(CFLAGS) server.c -o ./debug/server$(LDFLAGS)

debugClient: client.c
	gcc -g $(CFLAGS) client.c -o ./debug/client$(LDFLAGS)

