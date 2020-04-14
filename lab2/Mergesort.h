#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "timer.h"


const int arrayDiffTypesAmount = 5;
const int sortingArraysAmount = 100;


std::array<int,arrayDiffTypesAmount> vectorSizes = {10000, 50000, 100000, 500000, 1000000};



template<typename type>
class Mergesort
{
	std::vector<type> arrayTab;

public:

	Timer timer;
	void merge(int left, int mid, int right);
	void mergesort(int left, int right);
	void setArray(std::vector<type>& vec);
	std::vector<type>& getArray();
	void Mergesort_SortedToLevel(float divideParam);
	void Mergesort_Random();
	void Mergesort_ReverseOrder();

};



template <typename type>
void Mergesort<type>::setArray(std::vector<type>& vec)
{ 
	this->arrayTab = std::move(vec);

}



template <typename type>
std::vector<type>& Mergesort<type>::getArray()
{
	return this->arrayTab;
}



template <typename type>
void Mergesort<type>::merge(int left, int mid, int right)
{
	int i,j,k;
	int left_array = mid - left + 1;  
	int right_array = right - mid;
	type *L = new type[left_array];                 
	type *R = new type[right_array];

	for(i=0; i<left_array; i++)     	 
	{
		L[i] = arrayTab[left+i];
	}

	for(j=0; j<right_array; j++)        
	{
		R[j] = arrayTab[mid+1+j];
	}

	i=0;
	j=0;
	k = left;

	while(i<left_array && j<right_array)   
	{
		if(L[i] <= R[j])
		{
			arrayTab[k] = L[i];
			i++;
		}
		else
		{
			arrayTab[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<left_array)                 
	{
		arrayTab[k] = L[i];
		i++;
		k++;
	}
	while(j<right_array)
	{
		arrayTab[k] = R[j];
		j++;
		k++;
	}
	delete []R;
	delete []L;
}


template <typename type>
void Mergesort<type>::mergesort(int left, int right)
{
	if(left<right)
	{
		int mid = left+(right-left)/2; 
		mergesort(left,mid);
		mergesort(mid+1,right);
		merge(left,mid,right);
	}
}


template <typename type>
void Mergesort<type>::Mergesort_Random()
{

	for(auto vecSize: vectorSizes)                                      
	{							                                        
		std::cout << "Array capacity: " << vecSize << std::endl;
		for(int j=0; j<sortingArraysAmount; ++j)                        
		{
			std::vector<int> vec; 									    
			vec.resize(vecSize);  									  
			std::generate(vec.begin(), vec.end(), std::rand);           
		
			for(int i=0; i<vecSize; ++i)  								
			{														
				vec[i] = vec[i]%1000;
			}
			
			setArray(vec);
			timer.start();
			mergesort(0,vecSize-1);
			timer.end();
			timer.round();
		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}

}




template <typename type>
void Mergesort<type>::Mergesort_SortedToLevel(float divideParam)
{
	for(auto vecSize: vectorSizes)                                      
	{	

		int toDivide = divideParam*vecSize;
		std::vector<int> sortedPart;
		std::cout << "Array capacity: " << vecSize << std::endl;
		for(int j=0; j<sortingArraysAmount; ++j)                        
		{
			std::vector<int> vec; 									   
			vec.resize(vecSize);  									    
			std::generate(vec.begin(), vec.end(), std::rand);           

			sortedPart.resize(toDivide);

			for (int i=0; i<toDivide; ++i)
			{
				sortedPart[i] = vec[i];
			}
			setArray(sortedPart);
			mergesort(0,toDivide-1);
			sortedPart = getArray();

			for (int i=0; i<toDivide; ++i)
			{
				vec[i] = sortedPart[i];
			}

			setArray(vec);
			timer.start();
			mergesort(0,vecSize-1);
			timer.end();
			timer.round();
		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}
}



template <typename type>
void Mergesort<type>::Mergesort_ReverseOrder()
{
	for(auto vecSize: vectorSizes)                                      
	{							                                        
		std::cout << "Array capacity: " << vecSize << std::endl;
		for(int j=0; j<sortingArraysAmount; ++j)                        
		{
			std::vector<int> vec; 									     
			vec.resize(vecSize);  									    
			std::generate(vec.begin(), vec.end(), std::rand);            

			std::sort(vec.begin(), vec.end(), [](const int a, const int b) {return a>b; });
			
			setArray(vec);
			timer.start();
			mergesort(0,vecSize-1);
			timer.end();
			timer.round();
		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}
}



