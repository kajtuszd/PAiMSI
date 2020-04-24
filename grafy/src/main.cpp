#include <iostream>
#include <array>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "Matrix.h"
#include "List.h"
#include "Edge.h"
#include "Timer.h"

//const int graphDiffTypesAmount = 2;
//const int graphDensityAmount = 4;
//const int graphAmount = 2;


//std::array<int,graphDiffTypesAmount> graphSizes = {6,12};
//std::array<float,graphDensityAmount> graphDensity = {0.25, 0.5, 0.75, 1};


const int graphDiffTypesAmount = 5;
const int graphDensityAmount = 4;
const int graphAmount = 100;

std::array<int,graphDiffTypesAmount> graphSizes = {10,50,100,500,1000};
std::array<float,graphDensityAmount> graphDensity = {0.25, 0.5, 0.75, 1};


int main()
{

	Matrix matrix;
    Timer timer;


    for(auto graphSize : graphSizes)
    {
	    std::vector<std::vector<int>> graph;
	    graph.resize(graphSize, std::vector<int>(graphSize));
   //     std::cout << std::endl << "rozmiar grafu " << graphSize << std::endl;
        for(auto density : graphDensity)
        {
       // std::cout << " gestosc grafu " << density << std::endl;

            for(int i=0; i<graphAmount; i++)
            {
            //    timer.start();
                matrix.setArray(graph);
                matrix.fillMatrix(density);
            //    timer.end();
            //    timer.round();
              //  matrix.printMatrix();
              //  std::cout << std::endl;

            }
        }
    //    timer.convertSecToMin();
    //    timer.reset();


    }    
    std::cout << "koniec" << std::endl;





}