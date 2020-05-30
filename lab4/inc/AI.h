#ifndef AI_H
#define AI_H
#include "Board.h"
#include "Move.h"
#include <vector>


struct TreeNode
{
	Board board;
	int value;
	bool isCpu;
	Move move;
	std::vector<TreeNode> sons;
};


class AI
{
	
public:
	
















};



#endif