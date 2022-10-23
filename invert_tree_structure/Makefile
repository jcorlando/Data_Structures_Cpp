C=gcc
CXX=g++
STD=c++17
CFLAGS=-Wpedantic -Wall -Wextra
LDFLAGS=-luuid

invert_tree: invert_tree.cpp
	$(CXX) -std=$(STD) $(CFLAGS) invert_tree.cpp -o invert_tree $(LDFLAGS)

.PHONY: run clean invert_tree

clean:
	rm -f invert_tree ./debug/invert_tree

