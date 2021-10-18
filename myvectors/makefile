CFLAGS = -std=c++17
LDFLAGS = 

main: main.cpp myvectors.hpp eigenlibvectors.hpp
	g++ $(CFLAGS) -o main main.cpp $(LDFLAGS)

.PHONY: run clean

run: main
	clear && ./main

clean:
	rm -f main
