all:test
test:main.o asnode.o
	g++ main.o asnode.o -o test `pkg-config --cflags --libs gtk+-2.0` -std=c++0x
main.o:main.cpp
	g++ -c main.cpp `pkg-config --cflags --libs gtk+-2.0` -std=c++0x
asnode.o:asnode.cpp asnode.h
	g++ -c asnode.cpp -std=c++0x
clean:
	rm -f *.o test
