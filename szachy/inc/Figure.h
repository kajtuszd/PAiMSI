#pragma once
#include <iostream>
#include "Board.h"
#include "Spot.h"

class Figure
{
public:
	bool killed;
	bool white; 
	virtual bool canMove(Board board, Spot begin, Spot end) = 0;
};


class Knight: public Figure
{

public:
	Knight(bool color){this->white = color; killed = false;};
	virtual bool canMove(Board board, Spot begin, Spot end);
};


/*
class King: public Figure
{

};



class Queen: public Figure
{

};



class Rook: public Figure
{

};



class Bishop: public Figure
{

};



class Pawn: public Figure
{

};*/