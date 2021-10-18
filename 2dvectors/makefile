CFLAGS = -std=c++17
LDFLAGS = 

main: main.cpp 2dvectors.hpp
	g++ $(CFLAGS) -o main main.cpp $(LDFLAGS)

.PHONY: run clean

run: main
	clear && ./main

clean:
	rm -f main
