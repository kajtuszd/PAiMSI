#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "Edge.h"

class Matrix
{
	std::vector<std::vector<int>> matrixTab;
	
public:

	std::vector<std::vector<int>>& getArray();
	void setArray(std::vector<std::vector<int>>& matrix);
	void printMatrix();
	void addEdge(Edge e);
	int findNumOfEdges();
	void fillMatrix(float density);
	bool isEmpty(int x, int y);




};