#include "Matrix.h"



void Matrix::setArray(std::vector<std::vector<int>>& matrix)
{ 
	this->matrixTab = matrix;
}



std::vector<std::vector<int>>& Matrix::getArray()
{
	return this->matrixTab;
}


void Matrix::printMatrix()
{
	for (unsigned int i=0; i<this->matrixTab.size(); ++i)
	{
		for (unsigned int j=0; j<this->matrixTab.size(); ++j)
		{
			std::cout << matrixTab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void Matrix::addEdge(Edge e)
{
	this->matrixTab[e.begin][e.end] = e.weight;
}


bool Matrix::isEmpty(int x, int y)
{
	if(matrixTab[x][y] == 0)
		return true;
	else
		return false;
}


void Matrix::fillMatrix(float density)
{
	int numOfEdges = findNumOfEdges();
	int edgesToGenerate = (int)numOfEdges * density;

	int size = matrixTab.size();

	Edge edge;

	while(edgesToGenerate > 0)
	{
		edge.begin = rand()%size;
		edge.end = rand()%size;

		while(edge.begin==edge.end) // wykluczenie polaczenia wierzcholka z samym soba
		{
			edge.end = rand()%size;
		}

		if(isEmpty(edge.begin,edge.end))
		{
			edge.weight = rand()%9+1;
			addEdge(edge);
			edgesToGenerate--;
		}
	}
}


int Matrix::findNumOfEdges()
{
	int size = this->matrixTab.size();
	int result = 0;
	while(size > 0)
	{
		size --;
		result = result+size;
	}
	result = result*2;
	return result;
}







