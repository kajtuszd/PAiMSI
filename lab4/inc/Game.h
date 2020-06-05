#ifndef GAME_H
#define GAME_H
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <list>
#include "Board.h"
#include "Move.h"
#include "Figure.h"
#include "AI.h"



enum Status
{
	ACTIVE, BLACK_WIN, WHITE_WIN, RESIGNATION, STALEMATE, FORFEIT
};



class Game
{
	
	Board board;
	Status status;
	std::list<Move> movesPlayed;
	Move actualMove;
	std::vector<Spot> hereFigureCanMove;

public: 

	void initializePlayers();
	void printPlayersPieces();
	bool makeMove();
	void beginGame(){this->board.setBoard();};
	sf::Sprite getBoardSprite(){return this->board.board_spr;};
	Board getBoard(){return this->board;};
	Spot returnEnd(){return this->actualMove.getEnd();};
	void readHumanStartSpot(int x, int y);
	void readHumanEndSpot(int x, int y);
	std::vector<Spot> returnPlacesFigureCanMove(Figure *&selected);
	std::vector<sf::Vector2f> changeSpotsToVectors(std::vector<Spot> &v);
	std::vector<sf::Sprite> getGreenFrames(std::vector<sf::Vector2f> &frameVectors);
	std::vector<Spot> returnPlacesFigureCanCapture(Figure *&selected);
	std::vector<sf::Sprite> getRedFrames(std::vector<sf::Vector2f> &frameVectors);
	void readPlacesFigureCanMove(std::vector<Spot> &places);
	void doCastling(Spot &start, Spot &end, Figure *&moved);

	bool isMoveValid();
	Spot returnWhiteKingSpot();
	Spot returnBlackKingSpot();
	bool isWhiteKingChecked();
	bool isBlackKingChecked();
	std::vector<Move> returnPossibleMoves(bool color);

	void initializeAI();



};


#endif