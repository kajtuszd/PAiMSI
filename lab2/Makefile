CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: Sorting
	./Sorting

./Sorting: obj obj/main.o 
	g++ -o Sorting obj/main.o 

obj:
	mkdir obj

obj/main.o: main.cpp Mergesort.h Quicksort.h Introsort.h timer.h 
	g++ -c ${CXXFLAGS} -o obj/main.o main.cpp 

clear:
	rm -f obj/*.o Sorting