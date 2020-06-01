#include "Game.h"



void Game::initializePlayers()
{
	board.setBoard();
}


void Game::readHumanStartSpot(int x, int y)
{
	this->actualMove.setBegin(x,y);
}


void Game::readHumanEndSpot(int x, int y)
{
	this->actualMove.setEnd(x,y);
}



bool Game::isMoveValid()
{
	Spot end = actualMove.getEnd();

	if(std::find(hereFigureCanMove.begin(),hereFigureCanMove.end(),end) != hereFigureCanMove.end())
	{
		this->getBoard().cleanEndField(end);
		return true;
	}
	else
	{
		return false;
	}

}


std::vector<Move> Game::returnPossibleMoves(bool color)
{
	Board brd = this->getBoard();
	std::vector<Move> possibleMoves;


	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			if(!this->getBoard().getBox(i,j).isEmpty())
			{
				if(this->getBoard().getBox(i,j).getFigure()->white == color)
				{
					Spot begin = this->getBoard().getBox(i,j);

					for (int x = 0; x < boardLength; ++x)
					{
						for (int y = 0; y < boardLength; ++y)
						{
							Spot end = this->getBoard().getBox(x,y);
							if(this->getBoard().getBox(i,j).getFigure()->canMove(brd,begin,end))
							{
								Move move(color,begin,end);
								possibleMoves.push_back(move);
							}
						
						}
					}

				}

			}
		}
	}

	return possibleMoves;
}

void Game::printPossibleMoves(bool color)
{
	int k = 1;
	std::vector<Move> mv = std::move(this->returnPossibleMoves(color));
	for (std::vector<Move>::iterator i = mv.begin(); i != mv.end(); ++i)
	{
		Spot sp;
		Spot s;
		sp = i->getBegin();
		s = i->getEnd();
		std::cout << k << "  x: "<< sp.x << "   y: "  << sp.y << "   to   " << s.x << " " << s.y << " " 
		<< this->getBoard().getBox(sp.x,sp.y).getFigure()->name << " " << this->getBoard().getBox(sp.x,sp.y).getFigure()->white << std::endl;
		k++;
	}
}



bool Game::makeMove()
{
	Spot start = actualMove.getBegin();
	Spot end = actualMove.getEnd();

	Figure *moved = this->getBoard().getBox(start.x,start.y).getFigure();
	
	this->getBoard().moveFigure(start, end, moved);

	return true;
}

/*
std::vector<Spot> Game::returnPlacesFigureCanMove(Figure *&selected)
{
	std::vector<Spot> places;

	Spot begin = this->actualMove.getBegin();

	for (int i = 0; i < boardLength; ++i) 
	{
		for (int j = 0; j < boardLength; ++j)
		{
			Spot end = this->getBoard().getBox(i,j);

			if(selected->canMove(this->getBoard(), begin, end) && end.isEmpty())
			{
				places.push_back(end);
			}
		}
	}

	return places;
}
*/
std::vector<Spot> Game::returnPlacesFigureCanMove(Figure *&selected)
{
	std::vector<Spot> places;

	Spot begin = this->actualMove.getBegin();
	Board brd = this->getBoard();
	std::vector<Move> vec = selected->possibleMoves(brd,begin);
	for (std::vector<Move>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		Spot s = i->getEnd();
		if(brd.getBox(s.x,s.y).isEmpty())
		{
			places.push_back(brd.getBox(s.x,s.y));
		}

//		places.push_back( i->getEnd() );
	}

/*	for (int i = 0; i < boardLength; ++i) 
	{
		for (int j = 0; j < boardLength; ++j)
		{
			Spot end = this->getBoard().getBox(i,j);

			if(selected->canMove(this->getBoard(), begin, end) && end.isEmpty())
			{
				places.push_back(end);
			}
		}
	}
*/
	return places;
}



void Game::readPlacesFigureCanMove(std::vector<Spot> &places)
{
	this->hereFigureCanMove = std::move(places);
}


// std::vector<Spot> Game::returnPlacesFigureCanCapture(Figure *&selected)
// {
// 	std::vector<Spot> places;

// 	Spot begin = this->actualMove.getBegin();

// 	for (int i = 0; i < boardLength; ++i) 
// 	{
// 		for (int j = 0; j < boardLength; ++j)
// 		{
// 			Spot end = this->getBoard().getBox(i,j);

// 			if(selected->canMove(this->getBoard(), begin, end) && !end.isEmpty())
// 			{
// 				places.push_back(end);
// 			}
// 		}
// 	}

// 	return places;
// }


std::vector<Spot> Game::returnPlacesFigureCanCapture(Figure *&selected)
{
	std::vector<Spot> places;
	bool color = selected->white;
	Spot begin = this->actualMove.getBegin();
	Board brd = this->getBoard();
	std::vector<Move> vec = selected->possibleMoves(brd,begin);
	for (std::vector<Move>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		Spot sp = i->getEnd();

		if(!brd.getBox(sp.x,sp.y).isEmpty())
		{
			if(brd.getBox(sp.x,sp.y).getFigure()->white != color)
			{
				places.push_back( brd.getBox(sp.x,sp.y));
			}
		}
	}
	return places;

}

std::vector<sf::Vector2f> Game::changeSpotsToVectors(std::vector<Spot> &v)
{
	std::vector<sf::Vector2f> places;

	for (std::vector<Spot>::iterator i = v.begin(); i != v.end(); ++i)
	{
		sf::Vector2f vect;
	    vect.x = i->x;
		vect.y = i->y;
		places.push_back(vect);
	}

	return places;
}


std::vector<sf::Sprite> Game::getGreenFrames(std::vector<sf::Vector2f> frameVectors)
{
	std::vector<sf::Sprite> greenFrames;

	for (std::vector<sf::Vector2f>::iterator i = frameVectors.begin(); i != frameVectors.end(); ++i)
	{
		sf::Sprite sprite = getBoard().getGreenFrame();
		sprite.setPosition(i->x*56+28, i->y*56+28);
		greenFrames.push_back(sprite);
	}

	return greenFrames;

}


std::vector<sf::Sprite> Game::getRedFrames(std::vector<sf::Vector2f> frameVectors)
{
	std::vector<sf::Sprite> redFrames;

	for (std::vector<sf::Vector2f>::iterator i = frameVectors.begin(); i != frameVectors.end(); ++i)
	{
		sf::Sprite sprite = getBoard().getRedFrame();
		sprite.setPosition(i->x*56+28, i->y*56+28);
		redFrames.push_back(sprite);
	}

	return redFrames;

}









