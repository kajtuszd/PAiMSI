#ifndef SPOT_H
#define SPOT_H

#include <cstdlib>
#include <cstddef>
#include <string>

class Figure;
class Move;

class Spot
{

public: 
	
	Figure *figure;
	int x;
	int y;

	Spot(){};
	Spot(int x, int y, Figure *fig);
	Spot(int x, int y);
	int getX(){return this->x;};
	int getY(){return this->y;};
	void setY(int y){this->y = y;};
	void setX(int x){this->x = x;};
	void setFigure(Figure *&f){this->figure = std::move(f);};
	Figure* getFigure(){return this->figure;};
	bool isEmpty();
	friend bool operator==(const Spot &s1, const Spot &s2);
	friend bool operator!=(const Spot &s1, const Spot &s2);
};

#endif