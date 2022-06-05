CFLAGS = -I /usr/include/eigen3/
LDFLAGS =

main: main.cpp
	g++ $(CFLAGS) main.cpp -o main $(LDFLAGS)

.PHONY: run clean

run: main
	./main

clean:
	rm -f main
