#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iterator>
#include "Edge.h"


struct Node
{
	int number;
	int weight;

	void printNode(){std::cout << this->number << "," << this->weight << " ";};
	Node(){this->number = 0; this->weight=0;};
	Node(int _number, int _weight){this->number = _number; this->weight = _weight;};

	friend std::ostream& operator << (std::ostream &stream, const Node &node)
	{
		stream << node.number << "(" << node.weight <<") ";
		return stream;
	}
};


class Comparator
{
public:
	int operator() (const Node& n1, const Node& n2)
	{
		return n1.weight > n2.weight;
	}

};

class List
{


public:
	
	using nodeList = std::vector<Node>;
	std::vector<nodeList> listTab;


	std::vector<List::nodeList>& getArray();
	void setArray(std::vector<List::nodeList>& list);
	int findNumOfEdges();
	void addNode(Node node);
	void fillList(float density);
	bool isEmpty(int x, int y);
	void addNode(Node node, int place);

	void printList();
	int returnWeight(int a, int b);

	void dijkstra(int source);
	void BellmanFord(int source);


};


