#include "Spot.h"


Spot::Spot(int x, int y, Figure fig)
{
	this->setFigure(fig);
	this->setX(x);
	this->setY(y);
}