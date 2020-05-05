#include "List.h"

const int section_l = 99;

void List::setArray(std::vector<List::nodeList>& list)
{ 
	this->listTab = list;
}



std::vector<List::nodeList>& List::getArray()
{
	return this->listTab;
}



int List::findNumOfEdges()
{
	int size = this->listTab.size();
	int result = 0;
	while(size > 0)
	{
		size --;
		result = result+size;
	}
	return result;
}



void List::addNode(Node node, int place)
{
	listTab[place].push_back(node);
	Node second;
	second.number = place;
	second.weight = node.weight;
	int field = node.number;
	listTab[field].push_back(second);
}


bool List::isEmpty(int x, int y)
{
	for(unsigned int i = 0; i < listTab[x].size(); ++i)
	{
		if(listTab[x][i].number == y)
			return false;
	}
	return true;
}



void List::fillList(float density)
{
	int numOfEdges = findNumOfEdges();
	int edgesToGenerate = (int)numOfEdges * density;
	int size = listTab.size();

	Node node;
	int place;
	
	if(density == 1) /* faster full graph generating */
	{
		while(edgesToGenerate > 0)
		{
			for (node.number = 0; node.number < size; ++node.number)
			{
				for(place = 0; place < size; ++place)
				{
					if(isEmpty(node.number,place) && node.number != place)
					{
						node.weight = rand()%section_l+1;
						addNode(node,place);
						edgesToGenerate--;
					}
				}
			}
		}
	}
	else
	{
		while(edgesToGenerate > 0)
		{
			node.number = rand()%size;
			place = rand()%size;

			while(node.number == place)
			{
				place = rand()%size;
			}
			if(isEmpty(node.number,place))
			{
				node.weight = rand()%section_l+1;
				addNode(node,place);
				edgesToGenerate--;
			}
		}
	}
}


void List::printList()
{
	for(unsigned int i = 0; i < listTab.size(); ++i)
	{
		std::cout << i << ". ";
		for (unsigned int j = 0; j < listTab[i].size() ; ++j)
		{
			std::cout << listTab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}



int List::returnWeight(int a, int b)
{
	for (unsigned int i = 0; i < listTab[a].size(); ++i)
	{
		if(b == listTab[a][i].number)
			return listTab[a][i].weight;
	}
	return 0;
}




void List::dijkstra(int source)
{

	std::priority_queue<Node, std::vector<Node>, Comparator> pq;
	int size = listTab.size();
	std::vector<int> distances(size,INT_MAX);
	Node node(0,source);
	pq.push(node);
	distances[source] = 0;

	while(!pq.empty())
	{
		int u = pq.top().weight;
		pq.pop();

		std::vector<Node>::iterator iter;

		for(iter = listTab[u].begin(); iter!=listTab[u].end(); ++iter)
		{
			int v = (*iter).number;
			int wght = (*iter).weight;

			if(distances[v] > distances[u] + wght)
			{
				distances[v] = distances[u] + wght;
				Node vertex(distances[v],v);
				pq.push(vertex);
			}
		}
	}


/* uncomment next lines to print result */
	// std::cout << "Distances from source" << std::endl;
	// for (int j=0; j<size; ++j)
	// {
	// 	std::cout << j << ". " << distances[j] << std::endl;
	// }

}



void List::BellmanFord(int source)
{
	int size = listTab.size();
	std::vector<int> distances(size,INT_MAX);
	distances.resize(size);
	distances[source] = 0;

	for(int x=1; x<=size-1; x++)
	{
		for(unsigned int i=0; i < listTab.size(); ++i)
		{
			for (unsigned int j=0; j < listTab[i].size() ; ++j)
			{
				int u = i;
				int v = listTab[i][j].number;
				int weight = listTab[i][j].weight;

				if(distances[u] != INT_MAX && distances[v] > distances[u] + weight)
				{
					distances[v] = distances[u] + weight;
				}

			}
			
		}	
	}

	
	for (unsigned int i=0;  i < listTab.size(); ++i)
	{
		for (unsigned int j=0; j < listTab[i].size(); ++j)
		{
			int u = i;
			int v = listTab[i][j].number;
			int weight = listTab[i][j].weight;

			if(distances[u] != INT_MAX && distances[v] > distances[u] + weight)
			{
				std::cout << "Negative weight circle" << std::endl;
				return;
			}
		}
	}

/* uncomment next lines to print result */
	// for (int j=0; j<size; ++j)
	// {
	// 	std::cout << j << ". " << distances[j] << std::endl;
	// }
}



