#include "Board.h"





Spot Board::getBox(int y, int x)
{
	if(x>boardLength-1 || y>boardLength-1 || x<0 || y<0)
	{
		std::cout << "Bad index" << std::endl;
	}
	return *boxes[y][x];	
}


bool Board::cleanEndField(Spot &end)
{
	if(!this->getBox(end.x,end.y).isEmpty())
	{
		this->boxes[end.x][end.y]->figure = NULL;
		return true;
	}
	this->boxes[end.x][end.y]->figure = NULL;
	return false;

}

std::vector<sf::FloatRect> Board::initializeSwapVectors()
{
	std::vector<sf::FloatRect> vectors;
	for (int i = 0; i < 4; ++i)
	{
		sf::FloatRect rect;
		rect.left = i*56;
		rect.top = 0;
		rect.width = 56;
		rect.height = 56;
		vectors.push_back(rect);
	}

	return vectors;
}

void Board::chooseFigureToSwap(Figure* &fig, int &number)
{
	sf::RenderWindow wind(sf::VideoMode(224,56),"Pawn exchange");
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<sf::FloatRect> rects = initializeSwapVectors();
	if(fig->isWhite())
	{
		if(!texture.loadFromFile("pic/black.png"))
			std::cout << "Error while opening file" << std::endl;
	}
	else
	{
		if(!texture.loadFromFile("pic/white.png"))
			std::cout << "Error while opening file" << std::endl;
	}
	sprite.setTexture(texture);

	while(wind.isOpen())
	{
		sf::Event e;
		sf::Vector2i mousePos = sf::Mouse::getPosition(wind);
		while(wind.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			{
				wind.close();
				return;
			}

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				int k = 0;
				for (std::vector<sf::FloatRect>::iterator i = rects.begin(); i != rects.end(); ++i)
				{	
					sf::Vector2f position(mousePos);
					if(i->contains(position))
					{
						number = k;
						wind.close();
						return;
					}

					k++;
				}
			}
		}

		wind.clear();
		wind.draw(sprite);
		wind.display();
		sf::sleep(sf::milliseconds(10));
	}
	wind.close();
	return;
}


int Board::rateBoard(bool cpuMove)
{
	int whitePoints = 0;
	int blackPoints = 0;

	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			if(!this->getBox(i,j).isEmpty())
			{
				if(!this->getBox(i,j).getFigure()->isWhite())
					whitePoints += this->rateField(i,j);
				else
					blackPoints += this->rateField(i,j);
			}
		}
	}

	if(cpuMove)
		return blackPoints;
	else
		return whitePoints;

}



int Board::rateField(int x, int y)
{	
	int points;
	points = this->getBox(x,y).getFigure()->points;
	return points;
}





void Board::swapPawn(Spot &spot, Figure *&f, int num)
{
	std::string name = f->name;
	bool color = f->white;
	sf::Vector2f move = f->picture.getPosition();

	delete boxes[spot.x][spot.y]->getFigure();
	boxes[spot.x][spot.y]->figure = NULL;
	if(num == 0)
	{
		if(color)
		{
			boxes[spot.x][spot.y]->figure = new Rook(true); 
		}
		else
		{
			boxes[spot.x][spot.y]->figure = new Rook(false); 
		}
	}
	if(num == 1)
	{
		if(color)
		{
			boxes[spot.x][spot.y]->figure = new Knight(true); 
		}
		else
		{
			boxes[spot.x][spot.y]->figure = new Knight(false); 
		}	
	}
	if(num == 2)
	{
		if(color)
		{
			boxes[spot.x][spot.y]->figure = new Bishop(true); 
		}
		else
		{
			boxes[spot.x][spot.y]->figure = new Bishop(false); 			
		}
	}
	if(num == 3)
	{
		if(color)
		{
			boxes[spot.x][spot.y]->figure = new Queen(true); 
		}
		else
		{
			boxes[spot.x][spot.y]->figure = new Queen(false); 			
		}		
	}

	boxes[spot.x][spot.y]->getFigure()->picture.setPosition(move);  /* ustawienie pozycji nowego sprajta */


}



void Board::moveFigure(Move &move, Figure *&f)   /* utworzenie calkowicie nowego obiektu */
{
	Spot end = move.getEnd();
	Spot begin = move.getBegin();
	
	delete boxes[end.x][end.y]->getFigure();      /* wyczyszczenie poczatkowego pola */
	delete boxes[begin.x][begin.y]->getFigure();  /* wyczyszczenie koncowego pola */


	if(f->name == "queen")
	{
		if(f->isWhite())
			boxes[end.x][end.y]->figure = new Queen(true);
		else
			boxes[end.x][end.y]->figure = new Queen(false);
	}
	if(f->name == "king")
	{
		if(f->isWhite())
		{
			boxes[end.x][end.y]->figure = new King(true);
			boxes[end.x][end.y]->figure->hasMoved = true;		
		}
		else
		{
			boxes[end.x][end.y]->figure = new King(false);
			boxes[end.x][end.y]->figure->hasMoved = true;			
		}
	}
	if(f->name == "bishop")
	{
		if(f->isWhite())
			boxes[end.x][end.y]->figure = new Bishop(true);
		else
			boxes[end.x][end.y]->figure = new Bishop(false);
	}
	if(f->name == "knight")
	{
		if(f->isWhite())
			boxes[end.x][end.y]->figure = new Knight(true);
		else
			boxes[end.x][end.y]->figure = new Knight(false);
	}
	if(f->name == "pawn")
	{
		if(f->isWhite())
		{
			boxes[end.x][end.y]->figure = new Pawn(true);
			boxes[end.x][end.y]->figure->hasMoved = true;
		}
		else
		{
			boxes[end.x][end.y]->figure = new Pawn(false);
			boxes[end.x][end.y]->figure->hasMoved = true;			
		}

	}
	if(f->name == "rook")
	{
		if(f->isWhite())
		{
			boxes[end.x][end.y]->figure = new Rook(true);
			boxes[end.x][end.y]->figure->hasMoved = true;
		}
		else
		{
			boxes[end.x][end.y]->figure = new Rook(false);
			boxes[end.x][end.y]->figure->hasMoved = true;
		}
	}

	boxes[begin.x][begin.y]->figure = NULL;  


}




void Board::setBoard()
{
	loadBoardPic();
	setFrames();


	boxes[0][0] = new Spot(0,0, new Rook(true));
	boxes[1][0] = new Spot(1,0, new Knight(true));
	boxes[2][0] = new Spot(2,0, new Bishop(true));
	boxes[3][0] = new Spot(3,0, new Queen(true));
	boxes[4][0] = new Spot(4,0, new King(true));
	boxes[5][0] = new Spot(5,0, new Bishop(true));
	boxes[6][0] = new Spot(6,0, new Knight(true));
	boxes[7][0] = new Spot(7,0, new Rook(true));

	boxes[0][1] = new Spot(0,1, new Pawn(true));
	boxes[1][1] = new Spot(1,1, new Pawn(true));
	boxes[2][1] = new Spot(2,1, new Pawn(true));
	boxes[3][1] = new Spot(3,1, new Pawn(true));
	boxes[4][1] = new Spot(4,1, new Pawn(true));
	boxes[5][1] = new Spot(5,1, new Pawn(true));
	boxes[6][1] = new Spot(6,1, new Pawn(true));
	boxes[7][1] = new Spot(7,1, new Pawn(true));

	boxes[0][7] = new Spot(0,7, new Rook(false));
	boxes[1][7] = new Spot(1,7, new Knight(false));
	boxes[2][7] = new Spot(2,7, new Bishop(false));
	boxes[3][7] = new Spot(3,7, new Queen(false));
	boxes[4][7] = new Spot(4,7, new King(false));
	boxes[5][7] = new Spot(5,7, new Bishop(false));
	boxes[6][7] = new Spot(6,7, new Knight(false));
	boxes[7][7] = new Spot(7,7, new Rook(false));

	boxes[0][6] = new Spot(0,6, new Pawn(false));
	boxes[1][6] = new Spot(1,6, new Pawn(false));
	boxes[2][6] = new Spot(2,6, new Pawn(false));
	boxes[3][6] = new Spot(3,6, new Pawn(false));
	boxes[4][6] = new Spot(4,6, new Pawn(false));
	boxes[5][6] = new Spot(5,6, new Pawn(false));
	boxes[6][6] = new Spot(6,6, new Pawn(false));
	boxes[7][6] = new Spot(7,6, new Pawn(false));

	for (int i=0; i<8; i++)
	{
		for(int j=2; j<6; j++)
		{
			boxes[i][j] = new Spot(i,j,NULL);
		}
	}

	setPositionsOnBoard();


}



void Board::loadBoardPic()
{
	if(!this->board_tex.loadFromFile("pic/board.png"))
	{
		std::cout << "Error while opening file" << std::endl;
		return;
	}

	board_tex.setSmooth(true);
	this->board_spr.setTexture(board_tex);
	return;
}



sf::Sprite Board::getSprite(int x, int y)  
{
	return this->getBox(x,y).getFigure()->picture;
}




void Board::setPositionsOnBoard()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(getBox(i,j).getFigure() != NULL)
			{
				getBox(i,j).getFigure()->picture.setPosition(56*i+28,56*j+28);
			}
		}
	}
}





std::list <Figure*> Board::returnFigures()
{
	std::list <Figure*> allFigures;
	allFigures.clear();

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(this->getBox(i,j).getFigure() != NULL)
			{
				allFigures.push_back(this->getBox(i,j).getFigure());
			}
		}
	}

	return allFigures;
}


std::list <Figure*> Board::returnFigures(bool color)
{
	std::list <Figure*> colorFigures;
	colorFigures.clear();

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(this->getBox(i,j).getFigure() != NULL)
			{
				if(this->getBox(i,j).getFigure()->isWhite() == color)
				{
					colorFigures.push_back(this->getBox(i,j).getFigure());
				}
			}
		}
	}

	return colorFigures;
}


void Board::setFrames()
{
    if(!this->yellow_texture.loadFromFile("pic/yellow.png"))
    {
    	std::cout << "Error while opening file - yellow frame" << std::endl;
    	return;
    }
	
	if(!this->green_texture.loadFromFile("pic/green.png"))
	{
    	std::cout << "Error while opening file - green frame" << std::endl;
		return;
	}

    if(!this->red_texture.loadFromFile("pic/red.png"))
    {
	    std::cout << "Error while opening file - red frame" << std::endl;
	    return;
    }


	this->yellowFrame.setTexture(yellow_texture);
	this->greenFrame.setTexture(green_texture);
	this->redFrame.setTexture(red_texture); 
	
	this->yellowFrame.setScale(56.0/210.0, 56.0/208.0);
	this->redFrame.setScale(56.0/212.0, 56.0/212.0);
	this->greenFrame.setScale(56.0/211.0, 56.0/214.0);

	this->yellowFrame.setPosition(1000,1000);
	this->redFrame.setPosition(1000,1000);
	this->greenFrame.setPosition(1000,1000);

}


sf::Vector2f Board::adjustFrameSize(sf::Vector2f &vector)
{
    vector.x = vector.x - 28;
    vector.y = vector.y - 28;    
    int field_x = vector.x/56;
    int field_y = vector.y/56;
    sf::Vector2f result;
    result.x = float(field_x)*56+28;
    result.y = float(field_y)*56+28; 
    return result;
}


void Board::printFigures()
{
	std::cout << std::endl;

	for (unsigned int i = 0; i < boardLength; ++i)
	{
		for (unsigned int j = 0; j < boardLength; ++j)
		{
			if(boxes[j][i]->getFigure() == NULL) 
				std::cout << "  ";
			else
			{
				if (boxes[j][i]->getFigure()->name == "queen")
					std::cout << "q ";
				if (boxes[j][i]->getFigure()->name == "pawn")
					std::cout << "p ";
				if (boxes[j][i]->getFigure()->name == "bishop")
					std::cout << "b ";
				if (boxes[j][i]->getFigure()->name == "rook")
					std::cout << "r ";
				if (boxes[j][i]->getFigure()->name == "king")
					std::cout << "k ";
				if (boxes[j][i]->getFigure()->name == "knight")
					std::cout << "^ ";
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}


void Board::printLegend()
{
	std::cout << " Legend: " << std::endl;
	std::cout << " q - queen " << std::endl;
	std::cout << " p - pawn " << std::endl;
	std::cout << " b - bishop " << std::endl;
	std::cout << " r - rook " << std::endl;
	std::cout << " k - king " << std::endl;
	std::cout << " ^ - knight " << std::endl;
	std::cout << " Preview map: " << std::endl;	
	std::cout << " Colors are not supported  " << std::endl;
}

