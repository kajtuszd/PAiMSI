#ifndef MOVE_H
#define MOVE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Spot;
class Figure;

class Move
{
	bool player;
	Spot begin;
	Spot end;
	Figure *moved;

public:
	Move(){};
	Move(bool player, Spot begin, Spot end);
	Spot getBegin();
	Spot getEnd();
	void setPlayer(bool player_){this->player = player_;};
	bool getPlayer(){return this->player;};
	void setBegin(int y, int x);
	void setEnd(int y, int x);


};



#endif
