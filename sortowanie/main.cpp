#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Quicksort.h"




int main()
{


	std::cout << endl << "QUICK SORT" << endl;
	Quicksort<int> quick;

	std::cout << endl << "Randomly generated" << endl << endl;
	quick.Quicksort_Random();


}