#include "AI.h"


TreeNode::TreeNode(int depth, Board &brd, bool side, Move mv)
{
	board = brd;
	isCpu = side;
	move = mv;
	value = 0;

	if(depth == 0)
	{
		value = board.rateBoard(side);
	}
	else  
	{
		std::vector<Move> possibleMoves = this->returnPossibleMoves(side,board); // mozliwe miejsca
		std::cout << "doszlo nizej " << possibleMoves.size() << std::endl;

		for (std::vector<Move>::iterator i = possibleMoves.begin(); i != possibleMoves.end(); ++i)
		{
			Board copy(board); // kopia aktualnej tablicy
			Figure* figure = copy.getBox(i->getBegin().x,i->getBegin().y).getFigure(); // ruszana figura
			copy.moveFigure(*i,figure); // ruch figury na kopii
			Move toPass(*i);
			sons.emplace_back(depth-1,copy,!side,toPass); //
		}
	}
}



TreeNode::TreeNode(int depth, Board &brd, bool side)
{
	board = brd;
	isCpu = side;
	value = 0;

	if(depth == 0)
	{
		value = board.rateBoard(side);
	}
	else
	{
		std::vector<Move> possibleMoves = this->returnPossibleMoves(side,board); // mozliwe ruchy

		for (std::vector<Move>::iterator i = possibleMoves.begin(); i != possibleMoves.end(); ++i)
		{
			std::cout << "costam" << std::endl;
			Board copy(board); // kopia aktualnej tablicy
			std::cout << "costam v2" << std::endl;
			Figure* figure = copy.getBox(i->getBegin().x,i->getBegin().y).getFigure(); // ruszana figura

			copy.moveFigure(*i,figure); // ruch figury na kopii
			Move toPass(*i);
			sons.emplace_back(depth-1,copy,!side,toPass); //
		}
	}
}



AI::AI(Board &board)
{
	this->startboard = board;
	TreeNode tree(1,this->startboard,1);

	for (std::vector<TreeNode>::iterator i = tree.sons.begin(); i != tree.sons.end(); ++i)
	{
		std::cout << i->depth << " " << i->isCpu << " " << i->move.getBegin().x << " " << i->move.getBegin().y << std::endl;
	}
}



std::vector<Move> TreeNode::returnPossibleMoves(bool color, Board &board)
{
	std::vector<Move> allowedMoves;
	std::vector<Move> toInsert;
	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			if(!board.getBox(i,j).isEmpty())
			{
				if(board.getBox(i,j).getFigure()->white == color)
				{
					Spot begin(i,j);
					toInsert = std::move(board.getBox(i,j).getFigure()->possibleMoves(board,begin));
                    allowedMoves.insert(allowedMoves.end(), toInsert.begin(), toInsert.end());
				}
			}
		}
	}

	return allowedMoves;
}




std::vector<Move> AI::returnPossibleMoves(bool color, Board &board)
{
	std::vector<Move> allowedMoves;
	std::vector<Move> toInsert;
	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			if(!board.getBox(i,j).isEmpty())
			{
				if(board.getBox(i,j).getFigure()->white == color)
				{
					Spot begin(i,j);
					toInsert = std::move(board.getBox(i,j).getFigure()->possibleMoves(board,begin));
                    allowedMoves.insert(allowedMoves.end(), toInsert.begin(), toInsert.end());
				}
			}
		}
	}

	return allowedMoves;
}



void AI::printAllowedMoves(std::vector<Move> &allowedMoves, Board &board)
{
	int licznik = 0;
    for (std::vector<Move>::iterator i = allowedMoves.begin(); i != allowedMoves.end(); ++i)
    {
        Spot sp1, sp2;
        sp1 = i->getBegin();
        sp2 = i->getEnd();
        licznik ++;
        std::cout << sp1.x << " " << sp1.y << "   " << sp2.x << " " << sp2.y << "     " << i->getPlayer() << " " << board.getBox(sp1.x,sp1.y).getFigure()->name << std::endl;
    }
    std::cout << licznik << " moves available" << std::endl;
}







