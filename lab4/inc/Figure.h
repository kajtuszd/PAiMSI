#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>
#include "Board.h"
#include "Spot.h"
#include "Move.h"

class Board;
class Move;

enum Points
{
	PAWN = 20,
	KNIGHT = 60,
	BISHOP = 60,
	ROOK = 100,
	QUEEN = 180,
	KING = 1800
};



class Figure
{

public:
	

	bool killed = false;
	bool white = false; 
	bool hasMoved = false;

	Points points;
	sf::Sprite picture;
	sf::Texture tex;
	std::string name;

	Figure(){};
	void setWhite(bool &color){this->white = color;};
	bool isWhite(){return this->white == true;};
	bool isKilled(){return this->killed == true;};
	void kill(){this->killed = true;};
	Spot getVector(Board &board, Spot &begin, Spot &end);
	virtual bool canMove(Board &board, Spot &begin, Spot &end) = 0;
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin) = 0;
	std::vector<Move> returnFreeColsRows(Board &board, Spot &begin);
	std::vector<Move> returnFreeDiagonals(Board &board, Spot &begin);

	virtual ~Figure(){};
	void loadTex();
	bool testColsAndRows(Board &board, Spot &begin, Spot &end);
	bool testDiagonals(Board &board, Spot &begin, Spot &end);
	//int pointsTab[8][8];


};


class Knight: public Figure
{

public:
	Knight(bool color);
	virtual bool canMove(Board &board, Spot &begin, Spot &end);
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin);

	~Knight(){};
	


};


class Rook: public Figure
{
public: 
	Rook(bool color);
	virtual bool canMove(Board &board, Spot &begin, Spot &end);
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin);

	~Rook(){};
	
};



class King: public Figure
{

public:
	King(bool color);
	virtual bool canMove(Board &board, Spot &begin, Spot &end);
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin);
	bool isValidShortCastling(Board &board);
	bool isValidLongCastling(Board &board);

	~King(){};

};



class Queen: public Figure
{
public:
	Queen(bool color);
	virtual bool canMove(Board &board, Spot &begin, Spot &end);
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin);
	~Queen(){};
	
};



class Bishop: public Figure
{
public:
	Bishop(bool color);
	virtual bool canMove(Board &board, Spot &begin, Spot &end);
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin);
	~Bishop(){};

};



class Pawn: public Figure
{
public:
	Pawn(bool color);
	virtual bool canMove(Board &board, Spot &begin, Spot &end);
	virtual std::vector<Move> possibleMoves(Board &board, Spot &begin);
	~Pawn(){};

	
};


#endif