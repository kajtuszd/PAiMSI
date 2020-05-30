#include "Player.h"


Human::Human(int points, bool color, bool humanOrCpu)
{
	this->collectedPoints = points;
	this->whiteSide = color;
	this->humanPlayer = humanOrCpu;
	this->name = "human";
}


Computer::Computer(int points, bool color, bool humanOrCpu)
{
	this->collectedPoints = points;
	this->whiteSide = color;
	this->humanPlayer = humanOrCpu;
	this->name = "computer";
}

void Player::loadRightPieces(Board &board)
{
	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			if(!board.getBox(i,j).isEmpty())
			{
				if(board.getBox(i,j).getFigure()->white == this->isWhiteSide())
				{
					this->pieces.push_back(board.getBox(i,j).getFigure());
				}

			}
		}
	}
}

void Player::printPieces(Board &board)
{
	this->pieces = std::move(board.returnFigures(this->whiteSide));
	int k = 0;
	for (std::list<Figure*>::iterator i = this->pieces.begin(); i != this->pieces.end(); ++i)
	{
		std::cout << ++k << " " << (*i)->name << " " << (*i)->white << std::endl;
	}
}



Spot Player::returnKingSpot(bool color, Board &board)
{
	Spot spot;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(!board.getBox(i,j).isEmpty())
			{
				if(board.getBox(i,j).getFigure()->name == "king" && board.getBox(i,j).getFigure()->white == color)
				{
					spot = board.getBox(i,j);
				}
			}
		}
	}

	return spot;
}


bool Player::kingChecked(Spot &kingSpot, Board &board) 
{
	bool color = kingSpot.getFigure()->white; 
	bool opposite;                    
	if(color == 1)
		opposite = 0;
	else
		opposite = 1;

	if(this->whiteSide == opposite)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if(!board.getBox(i,j).isEmpty())
				{
					if(board.getBox(i,j).getFigure()->white == opposite)
					{
						Spot actual = board.getBox(i,j);
						if(board.getBox(i,j).getFigure()->canMove(board,actual,kingSpot))
						{
							return true;
						}
					}

				}
			}
		}
		return false;
	}

	return false;
}


bool Player::fieldChecked(bool color, Spot spot ,Board &board)
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(!board.getBox(i,j).isEmpty())
			{
				if(board.getBox(i,j).getFigure()->white == color)
				{
					Spot actual = board.getBox(i,j);
					if(board.getBox(i,j).getFigure()->canMove(board, actual, board.getBox(spot.x,spot.y)))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}









