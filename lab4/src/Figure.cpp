#include "Figure.h"


Spot Figure::getVector(Board &board, Spot &begin, Spot &end) 
{
	Spot spot;

	spot.x = abs(begin.getX() - end.getX());
	spot.y = abs(begin.getY() - end.getY());

	return spot;
}


std::vector<Move> Rook::possibleMoves(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves = returnFreeColsRows(board,begin);
	return allowedMoves;
}


std::vector<Move> King::possibleMoves(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves;
	bool color = board.getBox(begin.x,begin.y).getFigure()->white;  // kolor ruszanego konia
	
	Spot spots[8];

	Spot spot0(begin.x+1, begin.y-1); spots[0] = spot0;
	Spot spot1(begin.x+1, begin.y);   spots[1] = spot1;
	Spot spot2(begin.x+1, begin.y+1); spots[2] = spot2;
	Spot spot3(begin.x,   begin.y+1); spots[3] = spot3;
	Spot spot4(begin.x,   begin.y-1); spots[4] = spot4;
	Spot spot5(begin.x-1, begin.y-1); spots[5] = spot5;
	Spot spot6(begin.x-1, begin.y);   spots[6] = spot6;
	Spot spot7(begin.x-1, begin.y+1); spots[7] = spot7;


	for (int i = 0; i < 8; ++i)
	{
		if(spots[i].x>=0 && spots[i].y>=0  && spots[i].x<8 && spots[i].y<8)
		{
			if(board.getBox(spots[i].x, spots[i].y).isEmpty() || board.getBox(spots[i].x, spots[i].y).getFigure()->white != color)
			{
				Move move(color,begin,spots[i]);
				allowedMoves.push_back(move);
			}
		}
	}

	if(isValidShortCastling(board))
	{
		if(this->isWhite())
		{
			Spot spot(6,0);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		else
		{
			Spot spot(6,7);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
	}

	if(isValidLongCastling(board))
	{
		if(this->isWhite())
		{
			Spot spot(2,0);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		else
		{
			Spot spot(2,7);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
	}

	return allowedMoves;
}



bool King::isValidShortCastling(Board &board)
{
	if(this->hasMoved)
		return false;

	if(!this->isWhite())  // jezeli jest biale
	{
		if(board.getBox(7,7).isEmpty())
			return false;
		else
		{
			if(board.getBox(7,7).getFigure()->name == "rook" && !board.getBox(7,7).getFigure()->hasMoved)
			{
				if(board.getBox(5,7).isEmpty() && board.getBox(6,7).isEmpty())
					return true;
				else
					return false;
			}
			else
				return false;
		}
	}

	if(this->isWhite())  // jezeli jest czarne
	{
		if(board.getBox(7,0).isEmpty())
			return false;
		else
		{
			if(board.getBox(7,0).getFigure()->name == "rook" && !board.getBox(7,0).getFigure()->hasMoved)
			{
				if(board.getBox(5,0).isEmpty() && board.getBox(6,0).isEmpty())
					return true;
				else
					return false;
			}
			else
				return false;
		}
	}
	return false;
}

bool King::isValidLongCastling(Board &board)
{
	if(this->hasMoved)
		return false;

	if(!this->isWhite())  // jezeli jest biale
	{
		if(board.getBox(0,7).isEmpty())
			return false;
		else
		{
			if(board.getBox(0,7).getFigure()->name == "rook" && !board.getBox(0,7).getFigure()->hasMoved)
			{
				if(board.getBox(1,7).isEmpty() && board.getBox(2,7).isEmpty() && board.getBox(3,7).isEmpty())
					return true;
				else
					return false;
			}
			else
				return false;
		}
	}

	if(this->isWhite())  // jezeli jest czarne
	{
		if(board.getBox(0,0).isEmpty())
			return false;
		else
		{
			if(board.getBox(0,0).getFigure()->name == "rook" && !board.getBox(0,0).getFigure()->hasMoved)
			{
				if(board.getBox(1,0).isEmpty() && board.getBox(2,0).isEmpty() && board.getBox(3,0).isEmpty())
					return true;
				else
					return false;
			}
			else
				return false;
		}
	}
	return false;
}



std::vector<Move> Knight::possibleMoves(Board &board, Spot &begin)
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
		if(spots[i].x>=0 && spots[i].y>=0  && spots[i].x<8 && spots[i].y<8)
		{
			if(board.getBox(spots[i].x, spots[i].y).isEmpty() || board.getBox(spots[i].x, spots[i].y).getFigure()->white != color)
			{
				Move move(color,begin,spots[i]);
				allowedMoves.push_back(move);
			}
		}
	}

	return allowedMoves;
}


std::vector<Move> Bishop::possibleMoves(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves = returnFreeDiagonals(board,begin);
	return allowedMoves;
}


std::vector<Move> Queen::possibleMoves(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves;
	std::vector<Move> vec2;

	allowedMoves = returnFreeDiagonals(board,begin);
	vec2 = returnFreeColsRows(board,begin);
	allowedMoves.insert(allowedMoves.end(), vec2.begin(), vec2.end());

	return allowedMoves;	
}




std::vector<Move> Pawn::possibleMoves(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves;
	bool color = board.getBox(begin.x,begin.y).getFigure()->white;  

	Spot spot1 = board.getBox(begin.getX(),begin.getY()-1); // do przodu czarny
	Spot spot2 = board.getBox(begin.getX(),begin.getY()+1); // do przodu bialy

	if(!board.getBox(begin.x,begin.y).getFigure()->isWhite())
	{
		if(spot1.isEmpty())
		{
			Move move(color,begin,spot1);
			allowedMoves.push_back(move);
		}
		if(begin.getX() != 7)
		{
			Spot spot3 = board.getBox(begin.getX()+1,begin.getY()-1);
			if(!spot3.isEmpty() && spot3.getFigure()->isWhite())
			{
				Move move(color,begin,spot3);
				allowedMoves.push_back(move);
			}
		}
		if(begin.getX() != 0)
		{
			Spot spot4 = board.getBox(begin.getX()-1,begin.getY()-1);
			if(!spot4.isEmpty() && spot4.getFigure()->isWhite())
			{
				Move move(color,begin,spot4);
				allowedMoves.push_back(move);
			}
		}

		if(hasMoved == false && spot1.isEmpty() && board.getBox(begin.getX(),begin.getY()-2).isEmpty())
		{
			Spot spot7 = board.getBox(begin.getX(),begin.getY()-2); // do przodu czarny
			Move move(color,begin,spot7);
			allowedMoves.push_back(move);
		}

	}
	
	if(board.getBox(begin.x,begin.y).getFigure()->isWhite())
	{
		
		if(spot2.isEmpty())
		{
			Move move(color,begin,spot2);
			allowedMoves.push_back(move);
		}
		
		if(begin.getX() != 7)
		{
			Spot spot5 = board.getBox(begin.getX()+1,begin.getY()+1);
			if(!spot5.isEmpty() && !spot5.getFigure()->isWhite())
			{
				Move move(color,begin,spot5);
				allowedMoves.push_back(move);
			}
		}
		if(begin.getX() != 0)
		{
			Spot spot6 = board.getBox(begin.getX()-1,begin.getY()+1);
			if(!spot6.isEmpty() && !spot6.getFigure()->isWhite())
			{
				Move move(color,begin,spot6);
				allowedMoves.push_back(move);
			}
		}

		if(hasMoved == false && spot2.isEmpty() && board.getBox(begin.getX(),begin.getY()+2).isEmpty())
		{
			Spot spot8 = board.getBox(begin.getX(),begin.getY()+2); // do przodu bialy
			Move move(color,begin,spot8);			
			allowedMoves.push_back(move);
		}

	}
	return allowedMoves;
}




bool Rook::canMove(Board &board, Spot &begin, Spot &end)
{
	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	if(testColsAndRows(board, begin, end))
		return true;
	else
		return false;

	return false;
}




bool Knight::canMove(Board &board, Spot &begin, Spot &end)
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




std::vector<Move> Figure::returnFreeDiagonals(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves;
	bool color = board.getBox(begin.x,begin.y).getFigure()->white;  
	bool flag = true;
	int i = begin.x;
	int j = begin.y;
	while(i>0 && j>0 && flag)
	{
		i--; j--;
		if(board.getBox(i,j).isEmpty() && flag == true)
		{
			Spot spot(i,j);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(i,j).isEmpty())
		{
			flag = false;
			if(board.getBox(i,j).getFigure()->white != color)
			{
				Spot spot(i,j);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}

	flag = true;
	i = begin.x;
	j = begin.y;
	while(i<7 && j<7 && flag)
	{
		i++; j++;
		if(board.getBox(i,j).isEmpty() && flag == true)
		{
			Spot spot(i,j);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(i,j).isEmpty())
		{
			flag = false;
			if(board.getBox(i,j).getFigure()->white != color)
			{
				Spot spot(i,j);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}

	flag = true;
	i = begin.x;
	j = begin.y;
	while(i>0 && j<7 && flag)
	{
		i--; j++;
		if(board.getBox(i,j).isEmpty() && flag == true)
		{
			Spot spot(i,j);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(i,j).isEmpty())
		{
			flag = false;
			if(board.getBox(i,j).getFigure()->white != color)
			{
				Spot spot(i,j);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}

	flag = true;
	i = begin.x;
	j = begin.y;
	while(i<7 && j>0 && flag)
	{
		i++; j--;
		if(board.getBox(i,j).isEmpty() && flag == true)
		{
			Spot spot(i,j);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(i,j).isEmpty())
		{
			flag = false;
			if(board.getBox(i,j).getFigure()->white != color)
			{
				Spot spot(i,j);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}
	return allowedMoves;
}



std::vector<Move> Figure::returnFreeColsRows(Board &board, Spot &begin)
{
	std::vector<Move> allowedMoves;
	bool color = board.getBox(begin.x,begin.y).getFigure()->white;  
	bool flag = true;
	int i = begin.x;
	while(i>0 && flag)
	{
		i--;
		if(board.getBox(i,begin.y).isEmpty() && flag == true)
		{
			Spot spot(i,begin.y);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(i,begin.y).isEmpty())
		{
			flag = false;
			if(board.getBox(i,begin.y).getFigure()->white != color)
			{
				Spot spot(i,begin.y);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}

	i = begin.x;
	flag = true;
	while(i<7 && flag)
	{
		i++;
		if(board.getBox(i,begin.y).isEmpty() && flag == true)
		{
			Spot spot(i,begin.y);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(i,begin.y).isEmpty())
		{
			flag = false;
			if(board.getBox(i,begin.y).getFigure()->white != color)
			{
				Spot spot(i,begin.y);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}

	i = begin.y;
	flag = true;
	while(i>0 && flag)
	{
		i--;
		if(board.getBox(begin.x,i).isEmpty() && flag == true)
		{
			Spot spot(begin.x,i);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(begin.x,i).isEmpty())
		{
			flag = false;
			if(board.getBox(begin.x,i).getFigure()->white != color)
			{
				Spot spot(begin.x,i);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}

	i = begin.y;
	flag = true;
	while(i<7 && flag)
	{
		i++;
		if(board.getBox(begin.x,i).isEmpty() && flag == true)
		{
			Spot spot(begin.x,i);
			Move move(color,begin,spot);
			allowedMoves.push_back(move);
		}
		if(!board.getBox(begin.x,i).isEmpty())
		{
			flag = false;
			if(board.getBox(begin.x,i).getFigure()->white != color)
			{
				Spot spot(begin.x,i);
				Move move(color,begin,spot);
				allowedMoves.push_back(move);
			}
		}
	}
	return allowedMoves;
}





bool Figure::testColsAndRows(Board &board, Spot &begin, Spot &end)
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


bool Figure::testDiagonals(Board &board, Spot &begin, Spot &end)
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



bool Queen::canMove(Board &board, Spot &begin, Spot &end)
{

	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	if(testColsAndRows(board, begin, end) || testDiagonals(board,begin,end))
		return true;
	else
		return false;

	return false;
}



bool Bishop::canMove(Board &board, Spot &begin, Spot &end)
{
	if(begin.getX() == end.getX() && begin.getY() == end.getY())
		return false;

	if(testDiagonals(board, begin, end))
		return true;
	else
		return false;

	return false;
}





bool Pawn::canMove(Board &board, Spot &begin, Spot &end)
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






bool King::canMove(Board &board, Spot &begin, Spot &end)
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








