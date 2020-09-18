point_example: main.o Point.o
	g++ -o point_example main.o Point.o

Point.o: Point.cpp Point.h
	g++ -c Point.cpp

main.o: main.cpp Point.h
	g++ -c main.cpp
