C=gcc
CXX=g++
STD=c++17
CFLAGS=-Wpedantic -Wall -Wextra
LDFLAGS=

main: main.cpp
	$(CXX) -std=$(STD) $(CFLAGS) main.cpp -o invert_tree$(LDFLAGS)

.PHONY: run clean invert_tree

clean:
	rm -f invert_tree

debugMain: main.cpp
	$(CXX) -std=$(STD) -g $(CFLAGS) main.cpp -o ./debug/invert_tree$(LDFLAGS)



