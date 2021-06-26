CFLAGS = -std=c++17
LDFLAGS = 

main: main.cpp
	g++ $(CFLAGS) -o main main.cpp $(LDFLAGS)

.PHONY: run clean

run: main
	./main

clean:
	rm -f main
