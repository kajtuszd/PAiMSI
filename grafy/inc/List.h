#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"


class List
{


public:

	struct Node
	{
		int number;
		int weight;
	};

	
	using nodeList = std::vector<Node>;
	std::vector<nodeList> listTab;


	std::vector<nodeList>& getArray();
	void setArray(std::vector<nodeList>& list);


// addEdge(Edge e)
/*
robi pushbacka w odpowiednim miejscu
*/

// fillList(density)
/*
znajduje ilosc wszystkich krawedzi w zaleznosci od rozmiaru - funkcja findnumofedges z matrix
mnozy rozmiar razy density zeby uzyskac ilosc krawedzi do wygenerowania
teraz mamy ilosc krawedzi do wygenerowania
losujemy indeks w tabeli
losujemy polaczenie 
losujemy wage
sprawdzamy czy polaczenie juz istnieje
wykorzysta addEdge w petli


*/


};