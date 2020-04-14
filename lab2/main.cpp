#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Mergesort.h"
#include "Quicksort.h"
#include "timer.h"
#include "Introsort.h"




int main()
{
	float toDivide;


	std::cout << endl << "MERGE SORT" << endl;
	Mergesort<int> mergeSorting;


	std::cout << endl << "Randomly generated" << endl << endl;
	mergeSorting.Mergesort_Random();

	toDivide = 0.25;
	std::cout << endl << "25% sorted" << endl << endl;
	mergeSorting.Mergesort_SortedToLevel(toDivide);


	toDivide = 0.5;
	std::cout << endl << "50% sorted" << endl << endl;
	mergeSorting.Mergesort_SortedToLevel(toDivide);


	toDivide = 0.75;
	std::cout << endl << "75% sorted" << endl << endl;
	mergeSorting.Mergesort_SortedToLevel(toDivide);


	toDivide = 0.95;
	std::cout << endl << "95% sorted" << endl << endl;
	mergeSorting.Mergesort_SortedToLevel(toDivide);


	toDivide = 0.99;
	std::cout << endl << "99% sorted" << endl << endl;
	mergeSorting.Mergesort_SortedToLevel(toDivide);


	toDivide = 0.997;
	std::cout << endl << "99.7% sorted" << endl << endl;
	mergeSorting.Mergesort_SortedToLevel(toDivide);


	std::cout << endl << "Reverse order sorting" << endl << endl;
	mergeSorting.Mergesort_ReverseOrder();



	std::cout << endl << "QUICK SORT" << endl;
	Quicksort<int> quick;

	std::cout << endl << "Randomly generated" << endl << endl;
	quick.Quicksort_Random();


	toDivide = 0.25;
	std::cout << endl << "25% sorted" << endl << endl;
	quick.Quicksort_SortedToLevel(toDivide);

	toDivide = 0.5;
	std::cout << endl << "50% sorted" << endl << endl;
	quick.Quicksort_SortedToLevel(toDivide);


	toDivide = 0.75;
	std::cout << endl << "75% sorted" << endl << endl;
	quick.Quicksort_SortedToLevel(toDivide);

	toDivide = 0.95;
	std::cout << endl << "95% sorted" << endl << endl;
	quick.Quicksort_SortedToLevel(toDivide);

	toDivide = 0.99;
	std::cout << endl << "99% sorted" << endl << endl;
	quick.Quicksort_SortedToLevel(toDivide);

	toDivide = 0.997;
	std::cout << endl << "99,7% sorted" << endl << endl;
	quick.Quicksort_SortedToLevel(toDivide);

	std::cout << endl << "Reverse order sorting" << endl << endl;
	quick.Quicksort_ReverseOrder();



	std::cout << endl << "INTRO SORT" << endl;
	Introsort<int> intro;

	std::cout << endl << "Randomly generated" << endl << endl;
	intro.Introsort_Random();

	toDivide = 0.25;
	std::cout << endl << "25% sorted" << endl << endl;
	intro.Introsort_SortedToLevel(toDivide);

	toDivide = 0.5;
	std::cout << endl << "50% sorted" << endl << endl;
	intro.Introsort_SortedToLevel(toDivide);

	toDivide = 0.75;
	std::cout << endl << "75% sorted" << endl << endl;
	intro.Introsort_SortedToLevel(toDivide);

	toDivide = 0.95;
	std::cout << endl << "95% sorted" << endl << endl;
	intro.Introsort_SortedToLevel(toDivide);

	toDivide = 0.99;
	std::cout << endl << "99% sorted" << endl << endl;
	intro.Introsort_SortedToLevel(toDivide);

	toDivide = 0.997;
	std::cout << endl << "99,7% sorted" << endl << endl;
	intro.Introsort_SortedToLevel(toDivide);

	std::cout << endl << "Reverse order sorting" << endl << endl;
	intro.Introsort_ReverseOrder();


}