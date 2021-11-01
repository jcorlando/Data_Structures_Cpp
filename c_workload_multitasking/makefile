CFLAGS =
LDFLAGS = -lm

main: main.cpp 
	gcc $(CFLAGS) -o main main.cpp $(LDFLAGS)

.PHONY: run clean

run: main
	clear && ./main

clean:
	rm -f main
