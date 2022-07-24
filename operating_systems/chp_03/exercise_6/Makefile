CFLAGS = -Wpedantic -Wall -Wextra
LDFLAGS =

server: server.c
	gcc $(CFLAGS) server.c -o server$(LDFLAGS)

client: client.c
	gcc $(CFLAGS) client.c -o client$(LDFLAGS)

.PHONY: run clean

clean:
	rm -f client server
