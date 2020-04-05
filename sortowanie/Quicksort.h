#include <iostream>
#include <ctime>
#include <vector>
#include "timer.h"


const int arrayDifTypesAmount = 5;
const int sortArraysAmount = 100;

std::array<int,arrayDifTypesAmount> vecSizes = {10000, 50000, 100000, 500000, 1000000};
//std::array<int,arrayDifTypesAmount> vecSizes = {10,20};

template<typename type>
class Quicksort
{

	std::vector<type> arrayTab;


public:

	Timer timer;
	void quicksort(int left, int right);
	int divide(int left, int right);
	void swap(type *a, type *b);
	void Quicksort_Random();
	void setArray(std::vector<type> &vec);
	std::vector<type> getArray();


	
};


template <typename type>
void Quicksort<type>::setArray(std::vector<type> &vec)
{
	this->arrayTab = vec; 
}



template <typename type>
std::vector<type> Quicksort<type>::getArray()
{
	return this->arrayTab;
}



template<typename type>
void Quicksort<type>::quicksort(int left, int right)
{
	if(left < right)
	{
		int mid = divide(left, right);  // podzielenie tablicy, znalezienie piwota
		//std::cout << "indeks piwota: "<< mid << endl;
		quicksort(left, mid-1);	     // sortowanie lewej strony
		quicksort(mid+1, right);	 // sortowanie prawej strony
	}
}



template<typename type>
int Quicksort<type>::divide(int left, int right)
{
	type pivot = arrayTab[right];      // ustawienie piwota na ostatnie miejsce w tabeli
	int i = left-1;                    // indeks najmniejszego elementu -1 (ostatniego przed zamiana)

	for (int j=left; j <= right-1; j++)      //przewijanie tablicy od poczatku
	{
		if(arrayTab[j] <= pivot)         //jezeli aktualny element jest mniejszy od piwota
		{
			i++;                               // przewijamy pierwszy element
			swap(&arrayTab[i],&arrayTab[j]);    // zamieniamy go z aktualnym 
		}
	}

	i++;
	swap(&arrayTab[i],&arrayTab[right]); // zamiana piwota z pierwszym elementem wiekszym od niego 
/*	for (int k = 0; k < arrayTab.size(); ++k)
	{
		std::cout << arrayTab[k] << " ";
	}
	std::cout << "piwot: "<< arrayTab[i] << endl;*/
	return i;
}





template<typename type>
void Quicksort<type>::swap(type *a, type *b)
{
	type temporary = *a;
	*a = *b;
	*b = temporary;
}



template<typename type>
void Quicksort<type>::Quicksort_Random()
{

	for(auto vecSize: vecSizes)                                      // generacja zmiennej przechowującej wartość z vectorSizes
	{							                                        // pętla uruchamiana dla każdej zmiennej z vectorSizes
		std::cout << "Array capacity: " << vecSize << std::endl;
		for(int j=0; j<sortArraysAmount; ++j)                        // ilosc tablic sortowanych (100)
		{
			std::vector<int> vec; 									    // deklaracja wektora 
			vec.resize(vecSize);  									    // nadanie wielkości wygenerowanemu wektorowi
			std::generate(vec.begin(), vec.end(), std::rand);           // generowanie losowych << std::endl wartości funkcją rand 
		
			for(int i=0; i<vecSize; ++i)  								// uruchomiona pętla dla każdego z rodzajów tablicy
			{															// pętla generuje randomowe elementy
				vec[i] = vec[i]%100;
			}
		//	for(int i=0; i<vecSize; ++i)  								// uruchomiona pętla dla każdego z rodzajów tablicy
		//	{															// pętla generuje randomowe elementy
		//		std::cout << i << ". "<<vec[i] << endl;
		//	}
			//std::cout << endl;
			setArray(vec);                      // ustawienie tablicy do sortowania
			timer.start();
			quicksort(0,vecSize-1);            // sortowanie
			timer.end();
			timer.round();
			vec = getArray();

		//	for(int i=0; i<vecSize; ++i)  								
		//	{															
		//		std::cout << i << ". "<<vec[i] << endl;
		//	}
			//std::cout<<endl;


		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
		//std::cout<<endl;
	}

}







