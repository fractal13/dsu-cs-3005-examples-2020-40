all: main

main: main.o MyVectorOfInt.o
	g++ -std=c++11 -g -Wall -o main main.o MyVectorOfInt.o

main.o: main.cpp MyVectorOfInt.h
	g++ -std=c++11 -g -Wall -c main.cpp

MyVectorOfInt.o: MyVectorOfInt.cpp MyVectorOfInt.h
	g++ -std=c++11 -g -Wall -c MyVectorOfInt.cpp

clean:
	-rm *.o main



