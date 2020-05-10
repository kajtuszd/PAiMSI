CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

__start__: smfl-app
	./smfl-app

./smfl-app: obj obj/main.o obj/Spot.o obj/Figure.o obj/Board.o \
		obj/Player.o obj/Move.o obj/Game.o
	g++ obj/main.o obj/Spot.o obj/Figure.o obj/Board.o obj/Player.o \
		obj/Move.o obj/Game.o -o smfl-app ${SFMLFLAGS}

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Spot.h inc/Figure.h inc/Board.h \
		inc/Player.h inc/Move.h inc/Game.h
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp 

obj/Spot.o: src/Spot.cpp inc/Spot.h inc/Figure.h
	g++ -c ${CXXFLAGS} -o obj/Spot.o src/Spot.cpp 

obj/Figure.o: src/Figure.cpp inc/Figure.h inc/Spot.h inc/Board.h
	g++ -c ${CXXFLAGS} -o obj/Figure.o src/Figure.cpp 

obj/Board.o: src/Board.cpp inc/Board.h
	g++ -c ${CXXFLAGS} -o obj/Board.o src/Board.cpp 

obj/Player.o: src/Player.cpp inc/Player.h
	g++ -c ${CXXFLAGS} -o obj/Player.o src/Player.cpp 	

obj/Move.o: src/Move.cpp inc/Move.h
	g++ -c ${CXXFLAGS} -o obj/Move.o src/Move.cpp 

obj/Game.o: src/Game.cpp inc/Game.h
	g++ -c ${CXXFLAGS} -o obj/Game.o src/Game.cpp 

clear:
	rm -f obj/*.o sfml-app