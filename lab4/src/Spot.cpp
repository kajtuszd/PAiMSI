#include "Spot.h"


Spot::Spot(int x, int y, Figure *fig)
{
	this->setFigure(fig);

	this->setX(x);
	this->setY(y);
}

void Spot::setFigure(Figure *&f)
{
	this->figure = f;
}

Spot::Spot(int x, int y)
{
	this->setX(x);
	this->setY(y);
	this->figure = NULL;
}

Spot::Spot(){this->figure = NULL;}

// Spot::Spot(const Spot &s)
// {
// 	this->x = s.x;
// 	this->y = s.y;
// 	this->figure = s.figure;
// }

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

