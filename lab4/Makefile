CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++14
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

__start__: sfml-app
	./sfml-app

./sfml-app: obj obj/main.o obj/Spot.o obj/Figure.o obj/Board.o \
		 obj/Move.o obj/Game.o obj/AI.o
	g++ obj/main.o obj/Spot.o obj/Figure.o obj/Board.o  \
		obj/Move.o obj/Game.o obj/AI.o -o sfml-app ${SFMLFLAGS}

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Spot.h inc/Figure.h inc/Board.h \
		 inc/Move.h inc/Game.h inc/AI.h
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp 

obj/Spot.o: src/Spot.cpp inc/Spot.h inc/Figure.h
	g++ -c ${CXXFLAGS} -o obj/Spot.o src/Spot.cpp 

obj/Figure.o: src/Figure.cpp inc/Figure.h inc/Spot.h inc/Board.h
	g++ -c ${CXXFLAGS} -o obj/Figure.o src/Figure.cpp 

obj/AI.o: src/AI.cpp inc/AI.h
	g++ -c ${CXXFLAGS} -o obj/AI.o src/AI.cpp 	

obj/Board.o: src/Board.cpp inc/Board.h inc/Figure.h inc/Spot.h inc/AI.h
	g++ -c ${CXXFLAGS} -o obj/Board.o src/Board.cpp 


obj/Move.o: src/Move.cpp inc/Move.h inc/Figure.h \
		inc/Spot.h
	g++ -c ${CXXFLAGS} -o obj/Move.o src/Move.cpp 

obj/Game.o: src/Game.cpp inc/Game.h inc/Board.h \
		inc/Figure.h inc/Move.h inc/AI.h
	g++ -c ${CXXFLAGS} -o obj/Game.o src/Game.cpp 

clear:
	rm -f obj/*.o sfml-app