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



bool Game::makeMove()
{
	Spot start = actualMove.getBegin();
	Spot end = actualMove.getEnd();

	Figure *moved = this->getBoard().getBox(start.x,start.y).getFigure();

	sf::Vector2f spritePos = moved->picture.getPosition();     
	
	Move move(moved->white,start,end);

	this->getBoard().moveFigure(move,moved);

	this->getBoard().getBox(end.x,end.y).getFigure()->picture.setPosition(spritePos);  

	if(moved->name == "king" && abs(start.x - end.x) == 2)
		this->doCastling(start,end,moved);

	return true;
}



void Game::doCastling(Spot &start, Spot &end, Figure *&moved)
{
	if(end.x == 2 && end.y == 7) // dluga roszada biala
	{
		Spot finish(3,7);
		Spot start(0,7);
		Figure* rook = this->getBoard().getBox(0,7).getFigure();
		bool color = this->getBoard().getBox(0,7).getFigure()->white;
		Move move(color,start,finish);
		this->getBoard().moveFigure(move, rook);
		rook->picture.setPosition(56*finish.x+28,56*finish.y+28);		
	}	
	if(end.x == 6 && end.y == 7) // krotka roszada biala
	{
		Spot finish(5,7);
		Spot start(7,7);
		Figure* rook = this->getBoard().getBox(7,7).getFigure();
		bool color = this->getBoard().getBox(0,7).getFigure()->white;
		Move move(color,start,finish);		
		this->getBoard().moveFigure(move, rook);
		rook->picture.setPosition(56*finish.x+28,56*finish.y+28);
	}
	if(end.x == 2 && end.y == 0) // krotka roszada czarna
	{
		Spot finish(3,0);
		Spot start(0,0);
		Figure* rook = this->getBoard().getBox(0,0).getFigure();
		bool color = this->getBoard().getBox(0,7).getFigure()->white;
		Move move(color,start,finish);		
		this->getBoard().moveFigure(move, rook);
		rook->picture.setPosition(56*finish.x+28,56*finish.y+28);
	}
	if(end.x == 6 && end.y == 0) // dluga roszada czarna
	{
		Spot finish(5,0);
		Spot start(7,0);
		Figure* rook = this->getBoard().getBox(7,0).getFigure();
		bool color = this->getBoard().getBox(0,7).getFigure()->white;
		Move move(color,start,finish);				
		this->getBoard().moveFigure(move, rook);
		rook->picture.setPosition(56*finish.x+28,56*finish.y+28);
	}

	return;
}

void Game::initializeAI()
{
	Board board(this->getBoard());
	AI opponent(board);
	std::vector<Move> vec = opponent.returnPossibleMoves(1,opponent.startboard);
	opponent.printAllowedMoves(vec,opponent.startboard);
}

std::vector<Move> Game::returnPossibleMoves(bool color)
{
	std::vector<Move> allowedMoves;
	std::vector<Move> toInsert;
	Board brd = this->getBoard();
	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			if(!brd.getBox(i,j).isEmpty())
			{
				if(brd.getBox(i,j).getFigure()->white == color)
				{
					Spot begin(i,j);
					toInsert = std::move(brd.getBox(i,j).getFigure()->possibleMoves(brd,begin));
                    allowedMoves.insert(allowedMoves.end(), toInsert.begin(), toInsert.end());
				}
			}
		}
	}
	this->getBoard().possibleMoves = std::move(allowedMoves);
	return allowedMoves;
}



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

	}

	return places;
}



void Game::readPlacesFigureCanMove(std::vector<Spot> &places)
{
	this->hereFigureCanMove = std::move(places);
}




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









