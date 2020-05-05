#include <iostream>
#include <array>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "Matrix.h"
#include "List.h"
#include "Edge.h"
#include "Timer.h"





const int graphDiffTypesAmount = 5;
const int graphDensityAmount = 4;
const int graphAmount = 100;

std::array<int,graphDiffTypesAmount> graphSizes = {10,50,100,250,500};
std::array<float,graphDensityAmount> graphDensity = {0.25, 0.5, 0.75, 1};


int main()
{

    Matrix matrix_d;
    Timer timer;

    std::cout << std::endl << std::endl;
    std::cout << "Dijkstra " << std::endl;
    std::cout << "ADJACENCY MATRIX" << std::endl << std::endl;
    for(auto graphSize : graphSizes)
    {
		std::vector<std::vector<int>> graph;
		graph.resize(graphSize, std::vector<int>(graphSize));
        std::cout << std::endl << "***** graph size *****" << graphSize << std::endl;
        for(auto density : graphDensity)
        {
            std::cout << std::endl << "---graph density--- " << density << std::endl;

            for(int i=0; i<graphAmount; i++)
            {
               matrix_d.setArray(graph);
               matrix_d.fillMatrix(density);
               timer.start();
               matrix_d.dijkstra(0);
               timer.end();
               timer.round();
            }
        
        timer.convertSecToMin();
        std::cout << std::endl;
        timer.reset();
        }
    }    

    std::cout << std::endl << std::endl;

    List list_d;

    std::cout << "ADJACENCY LIST" << std::endl << std::endl;
    
    for(auto graphSize : graphSizes)
    {
        std::vector< std::vector<Node> > adj_list;
        adj_list.resize(graphSize);
        std::cout << std::endl << "***** graph size ***** " << graphSize << std::endl;

        for(auto density : graphDensity)
        {
            std::cout << std::endl << "---graph density--- " << density << std::endl;

            for (int i=0; i<graphAmount; i++)
            {
	            list_d.setArray(adj_list);
	            list_d.fillList(density);
            	timer.start();
            	list_d.dijkstra(0);
            	timer.end();
            	timer.round();
            }

        timer.convertSecToMin();
        std::cout << std::endl;
        timer.reset();
        }
    }
	
    Matrix matrix_l;
    std::cout << std::endl << std::endl;

    std::cout << "Bellman-Ford " << std::endl << std::endl;
    std::cout << "ADJACENCY MATRIX" << std::endl << std::endl;
    for(auto graphSize : graphSizes)
    {
        std::vector<std::vector<int>> graph;
        graph.resize(graphSize, std::vector<int>(graphSize));
        std::cout << std::endl << "***** graph size *****" << graphSize << std::endl;
        for(auto density : graphDensity)
        {
            std::cout << std::endl << "---graph density--- " << density << std::endl;

            for(int i=0; i<graphAmount; i++)
            {
               matrix_l.setArray(graph);
               matrix_l.fillMatrix(density);
               timer.start();
               matrix_l.BellmanFord(0);
               timer.end();
               timer.round();
            }
        
        timer.convertSecToMin();
        std::cout << std::endl;
        timer.reset();
        }
    }

    List list_l;
    std::cout << std::endl << std::endl;

    std::cout << "ADJACENCY LIST" << std::endl << std::endl;
    
    for(auto graphSize : graphSizes)
    {
        std::vector< std::vector<Node> > adj_list;
        adj_list.resize(graphSize);
        std::cout << std::endl << "***** graph size ***** " << graphSize << std::endl;

        for(auto density : graphDensity)
        {
            std::cout << std::endl << "---graph density--- " << density << std::endl;

            for (int i=0; i<graphAmount; i++)
            {
                list_l.setArray(adj_list);
                list_l.fillList(density);
                timer.start();
                list_l.BellmanFord(0);
                timer.end();
                timer.round();
            }

        timer.convertSecToMin();
        std::cout << std::endl;
        timer.reset();

        }
    }
}

