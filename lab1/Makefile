CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: DataStructures
	./DataStructures

./DataStructures: obj obj/main.o 
	g++ -o DataStructures obj/main.o 

obj:
	mkdir obj

obj/main.o: main.cpp List.cpp Stack.cpp Queue.cpp PriorityQueue.cpp Map.cpp
	g++ -c ${CXXFLAGS} -o obj/main.o main.cpp 

clear:
	rm -f obj/*.o DataStructures
