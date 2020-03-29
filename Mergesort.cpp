#include <iostream>
#include <ctime>
using namespace std;

template <typename type>
void merge(type *array, int left, int mid, int right)
{
	int i,j,k;

	/* initialise sizes of new arrays */
	int left_array = mid - left + 1;
	int right_array = right - mid;
	
	/* initialise new arrays */
	type L[left_array];
	type R[right_array];

	/* filling left array */ 
	for(i=0; i<left_array; i++)
	{
		L[i] = array[left+i];
	}

	/* filling right array */ 
	for(j=0; j<right_array; j++)
	{
		R[j] = array[mid+1+j];
	}

	i=0;
	j=0;
	k = left;

	while(i<left_array && j<right_array)
	{
		if(L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<left_array)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while(j<right_array)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

template <typename type>
void mergesort(type *array, int left, int right)
{
	if(left<right)
	{
		int mid = left+(right-left)/2;
		mergesort(array,left,mid);
		mergesort(array,mid+1,right);
		merge(array,left,mid,right);
	}
}

template <typename type>
void test(int tabsize, type *array)
{
	const clock_t time1 = clock();

	mergesort(array,0,tabsize-1);

	cout << "time: " << float(clock()-time1)/CLOCKS_PER_SEC;
}


template <typename type>
void generateRandom(int tabsize, type *array)
{
	for (int i = 0; i < tabsize; i++)
	{
		array[i] = rand()%1000;
	}
}

int main()
{
	const int firstsize = 10000;
	const int secondsize = 50000;
	const int thirdsize = 100000;
	const int fourthsize = 500000;
	const int fifthsize = 1000000;

	
	cout << "Every element is random" << endl << endl;
	
	int array1[firstsize];
	int array2[secondsize];
	int array3[thirdsize];
	int array4[fourthsize];
	int array5[fifthsize];

/*
*/

	cout << "Tested array with 10.000 elements" << endl;
	generateRandom<int>(firstsize,array1);
	test<int>(firstsize,array1);
	cout << endl;

	cout << endl << "Tested array with 50.000 elements" << endl;
	generateRandom<int>(secondsize,array2);
	test<int>(secondsize,array2);
	cout << endl;


/*

	cout << endl << "Tested array with 100.000 elements" << endl;
	generateRandom<int>(thirdsize,array3);
	test<int>(thirdsize,array3);
	cout << endl;

*/
/*
	cout << endl << "Tested array with 500.000 elements" << endl;
	generateRandom<int>(fourthsize,array4);
	test<int>(fourthsize,array4);
	cout << endl;
*/
/*

	cout << endl << "Tested array with 1.000.000 elements" << endl;
	generateRandom<int>(fifthsize,array5);
	test<int>(fifthsize,array5);
*/	cout << endl <<endl;
}