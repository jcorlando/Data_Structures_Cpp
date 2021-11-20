CFLAGS = -std=c++17 -pthread
LDFLAGS = -lm

main: main.cpp workload.hpp workload2.hpp
	g++ $(CFLAGS) -o main main.cpp $(LDFLAGS)

.PHONY: run clean

run: main
	clear && ./main

clean:
	rm -f main
