all: factorial fibonacci

factorial: factorial_main.o factorial.o 
	g++ -o factorial factorial_main.o factorial.o

fibonacci: fibonacci_main.o fibonacci.o 
	g++ -o fibonacci fibonacci_main.o fibonacci.o

factorial_main.o: factorial_main.cpp factorial.h
	g++ -c factorial_main.cpp

factorial.o: factorial.cpp factorial.h
	g++ -c factorial.cpp

fibonacci_main.o: fibonacci_main.cpp fibonacci.h
	g++ -c fibonacci_main.cpp

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -c fibonacci.cpp


clean:
	-rm -f factorial fibonacci
	-rm -f *.o
	-rm -f *~
