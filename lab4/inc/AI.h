#ifndef AI_H
#define AI_H
#include "Board.h"
#include "Move.h"
#include <vector>
#include <memory>
#include <iterator>


struct TreeNode
{
	Board board;
	int value;
	int depth;
	bool isCpu;
	Move move;
	std::vector<TreeNode> sons;
	std::vector<Move> returnPossibleMoves(bool color, Board &board);

	TreeNode(int depth, Board brd, bool side, Move move);
	TreeNode(int depth, Board brd, bool side);

};


class AI
{
	
public:
	Board startboard;
	AI(Board board);

	std::vector<Move> returnPossibleMoves(bool color, Board &board);
	void printAllowedMoves(std::vector<Move> &allowedMoves, Board &board);



};



#endif