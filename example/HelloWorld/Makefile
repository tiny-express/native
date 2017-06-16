all:
	mkdir -p bin
	g++ -c -std=c++11 -o bin/main.o Main.cpp
	gcc -o bin/main bin/main.o /usr/local/lib/libnative.so -lstdc++
	./bin/main