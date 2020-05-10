#pragma once
#include "Figure.h"

class Spot
{
	Figure figure;
	int x;
	int y;

public: 

	Spot(int x, int y, Figure fig);
	int getX(){return this->x;};
	int getY(){return this->y;};
	void setY(int y){this->y = y;};
	void setX(int x){this->x = x;};
	void setFigure(Figure f){this->figure = f;};
	Figure getFigure(){return this->figure;};





};