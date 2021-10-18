CFLAGS = -std=c++17
LDFLAGS = 

main: main.cpp imageprocessing.hpp sobelfilter.hpp
	g++ $(CFLAGS) -o main main.cpp $(LDFLAGS) `pkg-config --cflags --libs opencv4`

.PHONY: run clean

run: main
	clear && ./main

clean:
	rm -f main
