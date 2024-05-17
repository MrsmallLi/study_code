all: main.cpp src/pai.cc src/tree.cc
	g++ -std=c++11 -I./include main.cpp src/tree.cc src/pai.cc -o bin/canju

run: all
	./bin/canju

clean:
	rm bin/canju
