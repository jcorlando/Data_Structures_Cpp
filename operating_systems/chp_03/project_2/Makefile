CFLAGS=-std=c17 -Wpedantic -Wall -Wextra -Werror
LDFLAGS=

debug: main
	gcc $(CFLAGS) -fdiagnostics-color=always -g main.c -o ./debug/main

main: main.c
	gcc $(CFLAGS) main.c -o main $(LDFLAGS)

clean:
	rm -f main ./debug/main
