CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

__start__: sfml-app
	./sfml-app

./sfml-app: obj obj/main.o
	g++ obj/main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

obj:
	mkdir obj

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp 

clear:
	rm -f obj/*.o sfml-app
