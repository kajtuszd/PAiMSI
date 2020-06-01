#include "Spot.h"
#include "Move.h"



Move::Move(bool player, Spot begin, Spot end)
{
	this->player = player;
	this->begin = begin;
	this->end = end;
	this->moved = begin.getFigure();
}



void Move::setBegin(int y, int x)
{
	this->begin.x = x;
	this->begin.y = y;
}



void Move::setEnd(int y, int x)
{
	this->end.x = x;
	this->end.y = y;
}


Spot Move::getBegin(){return this->begin;}
Spot Move::getEnd(){return this->end;}
