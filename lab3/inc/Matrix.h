#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <climits>

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
	void dijkstra(int source);
	int MinDistance(std::vector<int>& distance, std::vector<bool>& isFinalised);

	void BellmanFord(int src);

};