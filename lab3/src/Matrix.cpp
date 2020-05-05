#include "Matrix.h"

const int section_m = 99;

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
	this->matrixTab[e.end][e.begin] = e.weight;

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

		while(edge.begin==edge.end) 
		{
			edge.end = rand()%size;
		}

		if(isEmpty(edge.begin,edge.end))
		{
			edge.weight = rand()%section_m+1;
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
	return result;
}


/* searching for the nearest vertex */
int Matrix::MinDistance(std::vector<int>& distance, std::vector<bool>& isFinalised)
{
	int min = INT_MAX;
	int min_index;

	for (unsigned int v = 0; v < matrixTab.size(); v++)
	{
		if(isFinalised[v] == false && distance[v] <= min)
		{
			min = distance[v];
			min_index = v;
		}
	}
	return min_index;
}



void Matrix::dijkstra(int source)
{
	int size = matrixTab.size();

	/* tab holding shortest distances */
	std::vector<int> distances; 
	distances.resize(size);

	for(auto iter = distances.begin(); iter != distances.end(); ++iter)
	{
		*iter = INT_MAX;
	}

	/* tab holding information if vertex is included in tree */
	std::vector<bool> isFinalised;
	isFinalised.resize(size);

	for(auto iter = isFinalised.begin(); iter != isFinalised.end(); ++iter)
	{
		*iter = false;
	}

	distances[source] = 0;

	for (int k=0; k<size-1; k++)
	{
		int u = MinDistance(distances, isFinalised);
		isFinalised[u] = true;

		for (int count=0; count<size; count++)
		{
			if(!isFinalised[count] && matrixTab[u][count] && distances[u] != INT_MAX
				&& distances[count] > distances[u] + matrixTab[u][count])
			{
				distances[count] = distances[u] + matrixTab[u][count];
			}
		}
	}

/* uncomment next lines to print result */
	// for (int q=0; q< size; ++q)
	// {
	// 	std::cout << q << ". " << distances[q] << std::endl;
	// }



}





void Matrix::BellmanFord(int src)
{
	int size = this->matrixTab.size();
	std::vector<int> distances;
	distances.resize(size);
	for(auto iter = distances.begin(); iter!=distances.end(); ++iter)
	{
		*iter = INT_MAX;
	}

	distances[src] = 0;

	for (int x=1; x<=size-1; x++)
	{
		for (int u=0; u<size; ++u)
		{
			for (int v=0; v<size; ++v)
			{
				if (distances[u] != INT_MAX && distances[v] > distances[u] + matrixTab[u][v] && matrixTab[u][v]!=0) 
				{
	                distances[v] = distances[u] + matrixTab[u][v]; 
				}
			}
		}
	}

	for (int u = 0; u < size; ++u)
	{
		for (int v = 0; v < size; ++v)
		{
			if(distances[u] != INT_MAX && distances[v] > distances[u] + matrixTab[u][v] && matrixTab[u][v]!=0)
			{
				std::cout << "Negative weight circle" << std::endl;
				return;
			}
		}
	}

/* uncomment next lines to print result */
	// for (int count = 0; count < size; ++count)
	// {
	// 	std::cout << count << ". " << distances[count] << std::endl;
	// }
			
}

