#include "Spot.h"


Spot::Spot(int x, int y, Figure *fig)
{
	this->setFigure(fig);
	this->setX(x);
	this->setY(y);
}


Spot::Spot(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

bool Spot::isEmpty()
{
	if(this->figure == NULL)
		return true;
	else
		return false;
}


bool operator==(const Spot &s1, const Spot &s2)
{
	if(s1.x == s2.x && s1.y == s2.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool operator!=(const Spot &s1, const Spot &s2)
{
	return !(s1 == s2);
}

