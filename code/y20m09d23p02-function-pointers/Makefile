all: calculator

calculator: main.o calculator.o calculator_operations.o
	g++ -o calculator main.o calculator.o calculator_operations.o

main.o: main.cpp calculator.h
	g++ -c main.cpp
calculator.o: calculator.cpp calculator.h
	g++ -c calculator.cpp
calculator_operations.o: calculator_operations.cpp calculator.h
	g++ -c calculator_operations.cpp

clean:
	-rm -f *.o *~
