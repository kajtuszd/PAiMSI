#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <cstdlib>
#include <list>
#include <cstddef>
#include <SFML/Graphics.hpp>
#include "Spot.h"
#include "Figure.h"
#include "Move.h"




const int boardLength = 8;
const int numOfFigures = 32;
const int fieldSize = 56;
const int figureTypes = 12;
const sf::Vector2f freeSpace(28,28);


class Spot;
class Figure;
class Move;

class Board
{
	sf::Texture board_tex;

	sf::Texture red_texture;
	sf::Texture yellow_texture;
	sf::Texture green_texture;

	sf::Sprite yellowFrame;
	sf::Sprite greenFrame;
	sf::Sprite redFrame;

	Spot *boxes[boardLength][boardLength];


public:
	
	std::vector<Move> possibleMoves;

	sf::Sprite board_spr;
	void setBoard();
	Spot getBox(int y, int x);
	void moveFigure(Move &move, Figure* &f);

	void printLegend();
	sf::Sprite getSprite(int y, int x);
	void loadBoardPic();
	void adjustSprites();
	void setPositionsOnBoard();
	sf::Sprite getYellowFrame(){return this->yellowFrame;};
	sf::Sprite getGreenFrame(){return this->greenFrame;};
	sf::Sprite getRedFrame(){return this->redFrame;};
	sf::Vector2f adjustFrameSize(sf::Vector2f vector);
	void setFrames();
	std::list <Figure*> returnFigures();
	void printFigures();
	bool cleanEndField(Spot end);
	void chooseFigureToSwap(Figure* fig, int &number);
	void swapPawn(Spot &spot, Figure *&f, int num);
	std::vector<sf::FloatRect> initializeSwapVectors();
	std::list <Figure*> returnFigures(bool color);
	int rateBoard(bool cpuMove);
	int rateField(int x, int y);





};

#endif