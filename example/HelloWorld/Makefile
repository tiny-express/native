all:
	mkdir -p bin
	g++ -c -std=c++11 -o bin/main.o Main.cpp
	gcc -static -o bin/main bin/main.o -L/usr/local/lib libnative_static.a -lstdc++
	./bin/main