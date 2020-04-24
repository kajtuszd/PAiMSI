#include "List.h"



void List::setArray(std::vector<nodeList>& list)
{ 
	this->listTab = list;
}



std::vector<nodeList>& List::getArray()
{
	return this->listTab;
}
