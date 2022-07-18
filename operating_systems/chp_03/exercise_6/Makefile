CFLAGS = -Wpedantic -Wall -Wextra -Werror
LDFLAGS =

client: client.c
	gcc $(CFLAGS) client.c -o client$(LDFLAGS)

.PHONY: run clean

run: client
	./client

clean:
	rm -f client
