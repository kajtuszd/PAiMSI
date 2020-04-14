#include <iostream>
#include <ctime>
#include <vector>
#include "timer.h"




template<typename type>
class Quicksort
{

	std::vector<type> arrayTab;

public:

	Timer timer;
	void quicksort(int left, int right);
	void swap(type *a, type *b);
	void Quicksort_Random();
	void Quicksort_SortedToLevel(float divideParam);
	void Quicksort_ReverseOrder();
	void setArray(std::vector<type> &vec);
	std::vector<type>& getArray();


	
};


template <typename type>
void Quicksort<type>::setArray(std::vector<type> &vec)
{
	this->arrayTab = std::move(vec);

}



template <typename type>
std::vector<type>& Quicksort<type>::getArray()
{
	return this->arrayTab;
}


template<typename type>
void Quicksort<type>::quicksort(int left, int right)
{
	if(right <= left) return;
	int pivot = arrayTab[(right+left)/2];         

	int i = left;	                             			
	int j = right;                               
	bool flag = true;

	while(flag == true)
	{
		while(pivot > arrayTab[i])
			i++;

		while(pivot < arrayTab[j])
			j--;

		if(i <= j)
		{
			swap(&arrayTab[i],&arrayTab[j]);   
			i++;
			j--;
		}
		else
		{
			flag = false;
		}
	}

	if(left < j)
		quicksort(left,j);

	if(right > i)
		quicksort(i,right); 

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

	for(auto vecSize: vectorSizes)                                    
	{							                                       
		std::cout << "Array capacity: " << vecSize << std::endl;
		for(int j=0; j<sortingArraysAmount; ++j)                        
		{
			std::vector<int> vec; 									    
			vec.resize(vecSize);  									    
			std::generate(vec.begin(), vec.end(), std::rand);           
			setArray(vec);                      
			timer.start();
			quicksort(0,vecSize-1);            
			timer.end();
			timer.round();
			vec = getArray();
		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}

}




template <typename type>
void Quicksort<type>::Quicksort_SortedToLevel(float divideParam)
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
			quicksort(0,toDivide-1);
			sortedPart = getArray();

			for (int i=0; i<toDivide; ++i)
			{
				vec[i] = sortedPart[i];
			}

			setArray(vec);
			timer.start();
			quicksort(0,vecSize-1);
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
void Quicksort<type>::Quicksort_ReverseOrder()
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
			quicksort(0,vecSize-1);
			timer.end();
			timer.round();
		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}
}
