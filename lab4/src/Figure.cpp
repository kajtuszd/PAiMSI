#include "Figure.h"


Spot Figure::getVector(Board board, Spot begin, Spot end) 
{
	Spot spot;

	spot.x = abs(begin.getX() - end.getX());
	spot.y = abs(begin.getY() - end.getY());

	return spot;
}


bool Knight::canMove(Board board, Spot begin, Spot end)
{
	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	Spot vect = this->getVector(board,begin,end);

	if(!this->isWhite())
	{
		if(end.isEmpty())
		{
			return vect.getX()*vect.getY() == 2;		
		}
		else
		{
			if(end.getFigure()->isWhite())
				return vect.getX()*vect.getY() == 2;
			else
				return false;		

		}
	}

	if(this->isWhite())
	{
		if(end.isEmpty())
		{
			return vect.getX()*vect.getY() == 2;		
		}
		else
		{
			if(!end.getFigure()->isWhite())
				return vect.getX()*vect.getY() == 2;
			else
				return false;		

		}
	}
	return false;
}

std::vector<Move> Knight::possibleMoves(Board board, Spot begin)
{
	std::vector<Move> allowedMoves;
	bool color = board.getBox(begin.x,begin.y).getFigure()->white;  // kolor ruszanego konia
	
	Spot spots[8];
	Spot spot0(begin.x+2, begin.y+1); spots[0] = spot0;
	Spot spot1(begin.x+1, begin.y+2); spots[1] = spot1;

	Spot spot2(begin.x+2, begin.y-1); spots[2] = spot2;
	Spot spot3(begin.x-1, begin.y+2); spots[3] = spot3;
	
	Spot spot4(begin.x-2, begin.y-1); spots[4] = spot4;
	Spot spot5(begin.x-1, begin.y-2); spots[5] = spot5;
	
	Spot spot6(begin.x-2, begin.y+1); spots[6] = spot6;
	Spot spot7(begin.x+1, begin.y-2); spots[7] = spot7;

	for (int i = 0; i < 8; ++i)
	{
		if(board.getBox(spots[i].x, spots[i].y).isEmpty() || board.getBox(spots[i].x, spots[i].y).getFigure()->white != color)
		{
			Move move(color,begin,spots[i]);
			allowedMoves.push_back(move);
		}

	}

	// Spot spot(begin.x+2, begin.y+1);
	// if(board.getBox(spot.x, spot.y).isEmpty() || board.getBox(spot.x, spot.y).getFigure()->color != color)
	// 	allowedMoves.push_back(spot);
	// Spot spot(begin.x+1, begin.y+2);

	// Spot spot(begin.x+2, begin.y-1);
	// Spot spot(begin.x-1, begin.y+2);
	
	// Spot spot(begin.x-2, begin.y-1);
	// Spot spot(begin.x-1, begin.y-2);
	
	// Spot spot(begin.x-2, begin.y+1);
	// Spot spot(begin.x+1, begin.y-2);

	// Move move(color, begin, spot);
	// if()
	return allowedMoves;
}


bool Rook::canMove(Board board, Spot begin, Spot end)
{
	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	if(testColsAndRows(board, begin, end))
		return true;
	else
		return false;

	return false;
}

std::vector<Move> Rook::possibleMoves(Board board, Spot begin)
{
	std::vector<Move> allowedMoves;
	return allowedMoves;
}


bool Figure::testColsAndRows(Board board, Spot begin, Spot end)
{    
    if (begin.getX() == end.getX())
    { 
        int dx = (begin.getY() < end.getY()) ? 1 : -1;

        for (int i = begin.getY() + dx; i != end.getY(); i += dx)
        {
            if(!board.getBox(begin.getX(),i).isEmpty())	
                return false;
        }
    } 
    else if (begin.getY() == end.getY()) 
    { 
        int dy = (begin.getX() < end.getX()) ? 1 : -1;

        for (int i = begin.getX() + dy; i != end.getX(); i += dy)
        {
            if(!board.getBox(i,begin.getY()).isEmpty())
                return false;
        }
    } 
    else 
    { 
        return false;
    }

    if(board.getBox(end.getX(),end.getY()).isEmpty())
    	return true;
    
    if(!board.getBox(end.getX(),end.getY()).getFigure()->isWhite() && 
    	board.getBox(begin.getX(),begin.getY()).getFigure()->isWhite())
    	return true;

    if(board.getBox(end.getX(),end.getY()).getFigure()->isWhite() && 
    	!board.getBox(begin.getX(),begin.getY()).getFigure()->isWhite())
    	return true;
    
    return false;
}


bool Figure::testDiagonals(Board board, Spot begin, Spot end)
{
	if (abs(begin.getX() - end.getX()) == abs(begin.getY() - end.getY()))  /* jezeli to jest przekatna kwadratu */
	{
		int xDir = (end.getX() - begin.getX()) / (abs(end.getX() - begin.getX())); /* inkrementacja x */
		int yDir = (end.getY() - begin.getY()) / (abs(end.getY() - begin.getY())); /* inkrementacja y */

		for (int i = 1; i < abs(begin.getX() - end.getX()); i++)
		{
			if(!board.getBox(begin.getX()+xDir*i, begin.getY()+yDir*i).isEmpty())   /* jezeli nie jest puste */
				return false;
		
		}
	}
	else
	{
	    return false;
	}

	if(board.getBox(end.getX(),end.getY()).isEmpty())
    	return true;
    
    if(!board.getBox(end.getX(),end.getY()).getFigure()->isWhite() && 
    	board.getBox(begin.getX(),begin.getY()).getFigure()->isWhite())
    	return true;

    if(board.getBox(end.getX(),end.getY()).getFigure()->isWhite() && 
    	!board.getBox(begin.getX(),begin.getY()).getFigure()->isWhite())
    	return true;
    
    return false;
}



bool Queen::canMove(Board board, Spot begin, Spot end)
{

	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	if(testColsAndRows(board, begin, end) || testDiagonals(board,begin,end))
		return true;
	else
		return false;

	return false;
}

std::vector<Move> Queen::possibleMoves(Board board, Spot begin)
{
	std::vector<Move> allowedMoves;
	return allowedMoves;	
}

bool Bishop::canMove(Board board, Spot begin, Spot end)
{
	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	if(testDiagonals(board, begin, end))
		return true;
	else
		return false;

	return false;
}

std::vector<Move> Bishop::possibleMoves(Board board, Spot begin)
{
	std::vector<Move> allowedMoves;
	return allowedMoves;
}

bool Pawn::canMove(Board board, Spot begin, Spot end)
{
	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	Spot spot1 = board.getBox(begin.getX(),begin.getY()-1);
	Spot spot2 = board.getBox(begin.getX(),begin.getY()+1);

	if(!this->isWhite())
	{
		if(end.isEmpty())
		{
			if((begin.getX() == end.getX() && begin.getY()==end.getY()+1 )|| 
				(hasMoved == false && begin.getY()==end.getY()+2 && begin.getX() == end.getX() && spot1.isEmpty()))
				return true;
			else
				return false;
		}

		if(!end.isEmpty() && end.getFigure()->isWhite())
		{
			if((begin.getX() == end.getX()+1 && begin.getY() == end.getY()+1) ||
				(begin.getX() == end.getX()-1 && begin.getY() == end.getY()+1) )
				return true;
			else
				return false;

		}
	}

	if(this->isWhite())
	{
		if(end.isEmpty())
		{
			if((begin.getX() == end.getX() && begin.getY()==end.getY()-1 )|| 
				(hasMoved == false && begin.getY()==end.getY()-2 && begin.getX() == end.getX() && spot2.isEmpty() ))
				return true;
			else
				return false;
		}

		if(!end.isEmpty() && !end.getFigure()->isWhite())
		{
			if((begin.getX() == end.getX()-1 && begin.getY() == end.getY()-1) ||
				(begin.getX() == end.getX()+1 && begin.getY() == end.getY()-1) )
				return true;
			else
				return false;

		}
	}

	return false;
}


std::vector<Move> Pawn::possibleMoves(Board board, Spot begin)
{
	std::vector<Move> allowedMoves;
	return allowedMoves;
}


bool Figure::isFieldChecked(Board board, Spot begin, Spot checked)
{
	if(begin.getFigure()->name == "king")
		return false;

	if(begin.getFigure()->isWhite()) /* jezeli figura jest biala */
	{
		for (int i = 0; i < 8; ++i)
		{                                 /* sprawdzenie kazdej figury na szachownicy */
			for (int j = 0; j < 8; ++j)
			{
				if(!board.getBox(i,j).isEmpty())     /* jezeli sprawdzane pole nie jest puste */
				{
					if(!board.getBox(i,j).getFigure()->isWhite() && board.getBox(i,j).getFigure()->name != "king" ) 
					{
						if(board.getBox(i,j).getFigure()->canMove(board, board.getBox(i,j), checked))
						{
							std::cout << " checked by " << board.getBox(i,j).getFigure()->name << std::endl;
							return true;
						}

					}

				}
			}
		}
	}

	if(!begin.getFigure()->isWhite()) /* jezeli figura jest czarna */
	{
		for (int i = 0; i < 8; ++i)
		{                                 /* sprawdzenie kazdej figury na szachownicy */
			for (int j = 0; j < 8; ++j)
			{
				if(!board.getBox(i,j).isEmpty())   /* jezeli sprawdzane pole nie jest puste */
				{
					if(board.getBox(i,j).getFigure()->isWhite() && board.getBox(i,j).getFigure()->name != "king")
					{
						if(board.getBox(i,j).getFigure()->canMove(board, board.getBox(i,j), checked))
						{
							std::cout << " checked by " << board.getBox(i,j).getFigure()->name << std::endl;
							return true;
						}

					}

				}
			}
		}
	}

	return false;

}



bool King::canMove(Board board, Spot begin, Spot end)
{

	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;
	
	
	Spot vector = getVector(board, begin, end);
	if((vector.x == 1 && vector.y == 1) || (vector.x == 0 && vector.y==1) || (vector.x == 1 && vector.y == 0))
	{
		if(end.isEmpty())
			return true;
		else
		{
			if( (board.getBox(end.x,end.y).getFigure()->isWhite() && board.getBox(begin.x,begin.y).getFigure()->isWhite()) ||
			 (!board.getBox(end.x,end.y).getFigure()->isWhite() && !board.getBox(begin.x,begin.y).getFigure()->isWhite() ))
				return false;
			else
				return true;
		} 
	}

	return false;

}

std::vector<Move> King::possibleMoves(Board board, Spot begin)
{
	std::vector<Move> allowedMoves;
	return allowedMoves;
}



void Figure::loadTex() /* funkcja wczytujaca teksture z pliku */
{
	if(!this->tex.loadFromFile("pic/figures.png"))
	{
		std::cout << "Error while opening file" << std::endl;
		return;
	}
	this->tex.setSmooth(true);
	this->picture.setTexture(this->tex);
}

Knight::Knight(bool color)
{
	this->setWhite(color); 
	killed = false; 
	points = KNIGHT;
	this->name = "knight";
	loadTex();
	if(!this->isWhite())
		this->picture.setTextureRect(sf::IntRect(56,56,56,56));
	else
		this->picture.setTextureRect(sf::IntRect(56,0,56,56));

}

Rook::Rook(bool color)
{
	this->setWhite(color); 
	killed = false; 
	points = ROOK;
	this->name = "rook";
	loadTex();
	if(!this->isWhite())
		this->picture.setTextureRect(sf::IntRect(0,56,56,56));
	else
		this->picture.setTextureRect(sf::IntRect(0,0,56,56));

}

King::King(bool color)
{
	this->setWhite(color);
	killed = false; 
	points = KING;
	this->name = "king";
	loadTex();
	if(!this->isWhite())
		this->picture.setTextureRect(sf::IntRect(4*56,56,56,56));
	else
		this->picture.setTextureRect(sf::IntRect(4*56,0,56,56));

}

Queen::Queen(bool color)
{
	this->setWhite(color); 
	killed = false;
	points = QUEEN;
	this->name = "queen";
	loadTex();
	if(!this->isWhite())
		this->picture.setTextureRect(sf::IntRect(3*56,56,56,56));
	else
		this->picture.setTextureRect(sf::IntRect(3*56,0,56,56));
}

Bishop::Bishop(bool color)
{
	this->setWhite(color); 
	killed = false; 
	points = BISHOP;
	this->name = "bishop";
	loadTex();
	if(!this->isWhite())
		this->picture.setTextureRect(sf::IntRect(2*56,56,56,56));
	else
		this->picture.setTextureRect(sf::IntRect(2*56,0,56,56));
}

Pawn::Pawn(bool color)
{
	this->setWhite(color); 
	killed = false;
	points = PAWN;
	this->name = "pawn";
	loadTex();
	if(!this->isWhite())
		this->picture.setTextureRect(sf::IntRect(5*56,56,56,56));
	else
		this->picture.setTextureRect(sf::IntRect(5*56,0,56,56));
}








