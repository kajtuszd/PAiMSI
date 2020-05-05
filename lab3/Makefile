CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: Graphs
	./Graphs

./Graphs: obj obj/main.o obj/List.o obj/Matrix.o obj/Timer.o
	g++ -Wall -pedantic -std=c++11 -o Graphs obj/main.o obj/List.o obj/Matrix.o obj/Timer.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/List.h inc/Matrix.h 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp 

obj/Matrix.o: src/Matrix.cpp inc/Matrix.h 
	g++ -c ${CXXFLAGS} -o obj/Matrix.o src/Matrix.cpp 

obj/List.o: src/List.cpp inc/List.h 
	g++ -c ${CXXFLAGS} -o obj/List.o src/List.cpp 

obj/Timer.o: src/Timer.cpp inc/Timer.h 
	g++ -c ${CXXFLAGS} -o obj/Timer.o src/Timer.cpp 


clear:
	rm -f obj/*.o Graphs
