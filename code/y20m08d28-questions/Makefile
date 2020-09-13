
all: hello

hello.o: hello.cpp goodbye.h
	g++ -c hello.cpp

goodbye.o: goodbye.cpp goodbye.h
	g++ -c goodbye.cpp

hello: hello.o goodbye.o
	g++ -o hello hello.o goodbye.o

