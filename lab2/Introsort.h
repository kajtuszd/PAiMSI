#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
#include "timer.h"



template<typename type>
class Introsort
{
	std::vector<type> arrayTab;

public:

	Timer timer;
	std::vector<type>& getArray();
	void setArray(std::vector<type>& vec);
	void insertsort(int left, int right);
	int quicksort(int left, int right);
	void swap(type &a, type &b);
	void makeMaxHeap(int heapSize, int parentIndex);
	void heapsort(int left, int right);
	type FindPivot(type &a, type &b, type &c);
	void introsort(int left, int right);
	void hybridsort(int maxDepth,int left, int right);
	int divide(int left, int right);
	void Introsort_Random();
	void Introsort_SortedToLevel(float divideParam);
	void Introsort_ReverseOrder();

};



template <typename type>
void Introsort<type>::setArray(std::vector<type>& vec)
{ 
	this->arrayTab = std::move(vec);
}


template <typename type>
std::vector<type>& Introsort<type>::getArray()
{
	return this->arrayTab;
}


template<typename type>
void Introsort<type>::insertsort(int left, int right)
{
	type current;
	int swapIndex;

	for(int i=left+1; i<right; i++)     
	{
		current = arrayTab[i];				 
		swapIndex = i;                       

		while(swapIndex > 0 && current < arrayTab[swapIndex-1])  
		{                                                          
			arrayTab[swapIndex] = arrayTab[swapIndex-1];
			swapIndex--;
		}
		arrayTab[swapIndex] = current;
	}

}

template<typename type>
type Introsort<type>::FindPivot(type &a, type &b, type &c)
{
	type x = a - b;
    type y = b - c;
    type z = a - c;
    if(x*y > 0)  return b;
    if(x*z > 0)  return c;
    return a;
}


template<typename type>
void Introsort<type>::swap(type &a, type &b)
{
	type temporary = a;
	a = b;
	b = temporary;
}


template<typename type>
void Introsort<type>::heapsort(int left, int right)
{
	int heapLength = right+1; 

	for (int i=heapLength/2 -1; i >= left; i--)
	{
		makeMaxHeap(heapLength,i);
	}

	for (int i=heapLength-1; i>left; i--)
	{
		swap(arrayTab[left],arrayTab[i]);
		heapLength --;
		makeMaxHeap(heapLength, left);
	}
}


template<typename type>
void Introsort<type>::makeMaxHeap(int heapSize, int parentInd)
{
	int parent = parentInd;
	int leftChild = parentInd*2 + 1;
	int rightChild = parentInd*2 + 2;

	if(leftChild < heapSize && arrayTab[leftChild] > arrayTab[parent])
	{
		parent = leftChild;
	}

	if(rightChild < heapSize && arrayTab[rightChild] > arrayTab[parent])
	{
		parent = rightChild;
	}

	if(parent != parentInd)
	{
		swap(arrayTab[parent],arrayTab[parentInd]);
		makeMaxHeap(heapSize,parent);
	}
}


template<typename type>
void Introsort<type>::introsort(int left, int right)
{
	int maxDepth = 2*(int)log(right-left+1);
	hybridsort(maxDepth,left,right);
}


template<typename type>
void Introsort<type>::hybridsort(int maxDepth, int left, int right)
{ 
	if(right-left+1 <= 16)
	{
		insertsort(left,right+1);  
		return;
	}
	else
	{

		if(maxDepth == 0)
		{
			heapsort(left,right); 
			return;

		}		
		else
		{	
			if(right <= left) return;

			int pivot = FindPivot(arrayTab[left], arrayTab[(right+left)/2], arrayTab[right] );
			
			if(arrayTab[left]==pivot) swap(arrayTab[left], arrayTab[(right+left)/2] );
			if(arrayTab[right]==pivot) swap(arrayTab[right], arrayTab[(right+left)/2] );
			

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
					swap(arrayTab[i],arrayTab[j]);  
					i++;
					j--;
				}
				else
				{
					flag = false;
				}
			}

			if(left < j)
				hybridsort(--maxDepth,left,j);

			if(right > i)
				hybridsort(--maxDepth,i,right);

			return;
		}

	}
}



template<typename type>
void Introsort<type>::Introsort_Random()
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
			introsort(0,vecSize-1);
			timer.end();
			timer.round();			
		}
		std::cout << endl << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}

}



template <typename type>
void Introsort<type>::Introsort_SortedToLevel(float divideParam)
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
			introsort(0,toDivide-1);
			sortedPart = getArray();

			for (int i=0; i<toDivide; ++i)
			{
				vec[i] = sortedPart[i];
			}
			setArray(vec);
			timer.start();
			introsort(0,vecSize-1);
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
void Introsort<type>::Introsort_ReverseOrder()
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
			introsort(0,vecSize-1);
			timer.end();
			timer.round();
		}
		std::cout << "Sorting time ";
		timer.convertSecToMin();
		std::cout << endl << "Average time per 1 array: " << timer.getTime()/sortingArraysAmount << " seconds"<< std::endl << std::endl;
		timer.reset();
	}
}

