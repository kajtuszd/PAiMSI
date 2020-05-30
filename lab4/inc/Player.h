#ifndef PLAYER_H
#define PLAYER_H
#include <list>
#include "Figure.h"
#include "Board.h"


class Board;

class Player
{

public:
	bool whiteSide;
	bool humanPlayer;
	int collectedPoints;
	std::list<Figure*> pieces;
	bool isWhiteSide(){return this->whiteSide == true;};
	bool isHumanPlayer(){return this->humanPlayer == true;};
	void loadRightPieces(Board &board);
	void printPieces(Board &board);
	Spot returnKingSpot(bool color, Board &board);
	bool kingChecked(Spot &kingSpot, Board &board);
	bool fieldChecked(bool color, Spot spot, Board &board);


	std::string name;


};




class Human: public Player
{

public:

	Human(int points, bool color, bool humanOrCpu);
	Human(bool whiteSide){this->whiteSide = whiteSide; this->humanPlayer = true; name = "human";};
	std::list<Figure*> returnPieces(){return this->pieces;};

};


class Computer: public Player
{

public:

	Computer(int points, bool color, bool humanOrCpu);
	Computer(bool whiteSide){this->whiteSide = whiteSide; this->humanPlayer = false; name = "computer";};
	void makemove(){std::cout << "here moves computer" << std::endl;};
	std::list<Figure*> returnPieces(){return this->pieces;};

};


#endif