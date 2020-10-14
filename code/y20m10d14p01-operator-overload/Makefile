#CXXFLAGS := -std=c++11 -g -Wall -Werror
CXXFLAGS := -std=c++11 -O -Wall -Werror
CXX := g++
TARGETS := main

all: $(TARGETS)

main: main.o Fraction.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -c $<

Fraction.o: Fraction.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-rm -f *.o
	-rm -f main
	-rm -f *~
