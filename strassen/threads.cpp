#include <iostream>
#include <thread>
#include <vector>




struct threadData
{
	int n;
	std::vector< std::vector<int> > mat1, mat2, result;

};



void PrintMatrix(std::vector< std::vector<int> > &vector, int max)
{
	for (int i = 0; i < max; ++i)
	{
		for (int j = 0; j < max; ++j)
		{
			std::cout << vector[j][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}


int findNearestPower(int number)
{
	int power = 1;
	while(power < number)
	{
		power *= 2;
	}
	return power;
}


int findLonger(int a, int b)
{
	if(a>b) return a;
	else 	return b;
}


std::vector< std::vector<int> > GenerateMatrix(int rows, int columns)
{
	int max = findLonger(rows,columns);
	int nextPower = findNearestPower(max);

	std::vector< std::vector<int> > mat;
	mat.resize(nextPower, std::vector<int>(nextPower));

	for(int i = 0; i < nextPower; ++i)
	{
		for (int j = 0; j < nextPower; ++j)
		{
			if(i<rows && j<columns)
				mat[j][i] = rand()%10;
			else
				mat[j][i] = 0;
		}
	}
	return mat;
}

std::vector< std::vector<int> > GenerateMatrix(int rows, int columns, int number)
{
	int max = findLonger(rows,columns);
	int nextPower = findNearestPower(max);

	std::vector< std::vector<int> > mat;
	mat.resize(nextPower, std::vector<int>(nextPower));

	for(int i = 0; i < nextPower; ++i)
	{
		for (int j = 0; j < nextPower; ++j)
		{
			mat[j][i] = number;
		}
	}
	return mat;
}


std::vector< std::vector<int> > add(std::vector< std::vector<int> > &mat1, std::vector< std::vector<int> > &mat2)
{
	std::vector< std::vector<int> > mat3;
	int nextPower = mat1.size();
	mat3.resize(nextPower, std::vector<int>(nextPower));

	for (int i = 0; i < mat1.size(); ++i)
	{
		for (int j = 0; j < mat1.size(); ++j)
		{
			mat3[i][j] = mat1[i][j] + mat2[i][j];	
		}
	}
	return mat3;
}


std::vector< std::vector<int> > subtract(std::vector< std::vector<int> > &mat1, std::vector< std::vector<int> > &mat2)
{
	std::vector< std::vector<int> > mat3;
	int nextPower = mat1.size();
	mat3.resize(nextPower, std::vector<int>(nextPower));
	
	for (int i = 0; i < mat1.size(); ++i)
	{
		for (int j = 0; j < mat1.size(); ++j)
		{
			mat3[i][j] = mat1[i][j] - mat2[i][j];	
		}
	}
	return mat3;
}


std::vector< std::vector<int> > multiply(std::vector< std::vector<int> > &mat2, std::vector< std::vector<int> > &mat1)
{
	std::vector< std::vector<int> > mat3;
	int nextPower = mat1.size();

	mat3.resize(nextPower, std::vector<int>(nextPower));
	
	for (int i = 0; i < mat1.size(); ++i)
	{
		for (int j = 0; j < mat1.size(); ++j)
		{
			mat3[i][j] = 0;
		}
	}

	for (int i = 0; i < mat1.size(); ++i)
	{
		for (int j = 0; j < mat1.size(); ++j)
		{
			for (int k = 0; k < mat1.size(); ++k)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return mat3;
}

void *add_Thread(void *arg)
{
	struct threadData *data = (threadData*)arg;
	for (int i = 0; i < data->n; ++i)
	{
		for (int j = 0; j < data->n; ++j)
		{
			data->result[i][j] = data->mat1[i][j] + data->mat2[i][j];
		}
	}
	pthread_exit(0);

}

void *sub_Thread(void *arg)
{
	struct threadData *data = (threadData*)arg;
	for (int i = 0; i < data->n; ++i)
	{
		for (int j = 0; j < data->n; ++j)
		{
			data->result[i][j] = data->mat1[i][j] - data->mat2[i][j];
		}
	}
	pthread_exit(0);
}





void strassen(std::vector< std::vector<int> > &mat2, std::vector< std::vector<int> > &mat1, std::vector< std::vector<int> > &result)
{
	int size = mat1.size();

	if(size == 2)
	{
		result = std::move(multiply(mat2, mat1));
	}
	else
	{
		int newSize = size/2;
		std::vector< std::vector<int> > a11, a12, a21, a22, b11, b12, b21, b22;   // multiplied matrixes
		std::vector< std::vector<int> > c11, c12, c21, c22;  // result
		std::vector< std::vector<int> > m1, m2, m3, m4, m5, m6, m7;  // operations
		std::vector< std::vector<int> > r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;  // results

		a11.resize(newSize, std::vector<int>(newSize));
		a12.resize(newSize, std::vector<int>(newSize));
		a21.resize(newSize, std::vector<int>(newSize));
		a22.resize(newSize, std::vector<int>(newSize));
		b11.resize(newSize, std::vector<int>(newSize));
		b12.resize(newSize, std::vector<int>(newSize));
		b21.resize(newSize, std::vector<int>(newSize));
		b22.resize(newSize, std::vector<int>(newSize));

		c11.resize(newSize, std::vector<int>(newSize));
		c12.resize(newSize, std::vector<int>(newSize));
		c21.resize(newSize, std::vector<int>(newSize));
		c22.resize(newSize, std::vector<int>(newSize));

		m1.resize(newSize, std::vector<int>(newSize));
		m2.resize(newSize, std::vector<int>(newSize));
		m3.resize(newSize, std::vector<int>(newSize));
		m4.resize(newSize, std::vector<int>(newSize));
		m5.resize(newSize, std::vector<int>(newSize));
		m6.resize(newSize, std::vector<int>(newSize));
		m7.resize(newSize, std::vector<int>(newSize));

		r1.resize(newSize, std::vector<int>(newSize));
		r2.resize(newSize, std::vector<int>(newSize));
		r3.resize(newSize, std::vector<int>(newSize));
		r4.resize(newSize, std::vector<int>(newSize));
		r5.resize(newSize, std::vector<int>(newSize));
		r6.resize(newSize, std::vector<int>(newSize));
		r7.resize(newSize, std::vector<int>(newSize));
		r8.resize(newSize, std::vector<int>(newSize));
		r9.resize(newSize, std::vector<int>(newSize));
		r10.resize(newSize, std::vector<int>(newSize));

		for (int i = 0; i < newSize; i++) 
		{
			for (int j = 0; j < newSize; j++) 
			{
				a11[i][j] = mat1[i][j];
				a12[i][j] = mat1[i][j+newSize];
				a21[i][j] = mat1[i+newSize][j];
				a22[i][j] = mat1[i + newSize][j + newSize];

				b11[i][j] = mat2[i][j];
				b12[i][j] = mat2[i][j+newSize];
				b21[i][j] = mat2[i+newSize][j];
				b22[i][j] = mat2[i + newSize][j + newSize];
			}
		}


		struct threadData adds[6];
		struct threadData subs[4];

		adds[0] = (struct threadData){mat1 = a11 , mat2 = a22, result = r1, n = newSize};
		adds[1] = (struct threadData){mat1 = b11 , mat2 = b22, result = r2, n = newSize};
		adds[2] = (struct threadData){mat1 = a21 , mat2 = a22, result = r3, n = newSize};
		adds[3] = (struct threadData){mat1 = a11 , mat2 = a12, result = r4, n = newSize};
		adds[4] = (struct threadData){mat1 = b11 , mat2 = b12, result = r5, n = newSize};
		adds[5] = (struct threadData){mat1 = b21 , mat2 = b22, result = r6, n = newSize};

		subs[0] = (struct threadData){mat1 = b12 , mat2 = b22, result = r7, n = newSize};
		subs[1] = (struct threadData){mat1 = b21 , mat2 = b11, result = r8, n = newSize};
		subs[2] = (struct threadData){mat1 = a21 , mat2 = a11, result = r9, n = newSize};
		subs[3] = (struct threadData){mat1 = a12 , mat2 = a22, result = r10, n = newSize};

		pthread_t adders[6];
		pthread_t subers[4];

		for (int i = 0; i < 6; ++i)
		{
			pthread_create(&adders[i], NULL, add_Thread, &adds[i]);
		}
		
		for (int i = 0; i < 4; ++i)
		{
			pthread_create(&subers[i], NULL, sub_Thread, &subs[i]);
		}

	    for (int i = 0; i < 6; i++)
	    {
	        pthread_join(adders[i], NULL);
	    }
	    
	    for (int i = 0; i < 4; i++)
	    {
      		pthread_join(subers[i], NULL);       
	    }

		/*  m1 = (a11+a22)*(b11+b22)  */

		strassen(r1,r2,m1);

		/*  m2 = (a21+a22)*b11        */

		strassen(b11,r3,m2);

		/*  m3 = a11*(b12-b22)        */
		
		strassen(r7,a11,m3);

		/*  m4 = a22*(b21-b11)        */

		strassen(r8,a22,m4);
		
 		/*  m5 = (a11+a12)*b22        */		

		strassen(b22,r4,m5);

		/*  m6 = (a21-a11)*(b11+b12)  */

		strassen(r5,r9,m6);

		/*  m7 = (a12-a22)*(b21+b22)  */

		strassen(r6,r10,m7);


		/* calculating result matrix */
		/* c11 = m1 + m4 - m5 + m7 */ 
		
		auto sum1 = std::move(add(m1,m7));
		auto sum2 = std::move(subtract(m4,m5));
		c11 = std::move(add(sum1,sum2));
	
		/* c12 = m3 + m5 */

		c12 = std::move(add(m3,m5));

		/* c21 = m2 + m4 */

		c21 = std::move(add(m2,m4));

		/* c22 = m1 + m3 - m2 + m6 */

		auto sum3 = std::move(subtract(m1,m2));
		auto sum4 = std::move(add(m3,m6));
		c22 = std::move(add(sum3,sum4));

		for (int i = 0; i < newSize ; i++) 
		{
			for (int j = 0 ; j < newSize ; j++) 
			{
				result[i][j] = c11[i][j];
				result[i][j + newSize] = c12[i][j];
				result[i + newSize][j] = c21[i][j];
				result[i + newSize][j + newSize] = c22[i][j];
			}
		}


	}

}


int main()
{

	std::vector<std::vector<int>> mat1, mat2, result;
	int columns1;
	int rows1;
	std::cout <<"Enter number of columns ";
	std::cin >> columns1;
	std::cout <<"Enter number of rows ";
	std::cin >> rows1;
	std::cout << std::endl;
	int columns2 = rows1;
	int rows2 = columns1;

	int maxNumber = findLonger(columns1,rows1);
	int nextPower = findNearestPower(maxNumber);

	mat1 = GenerateMatrix(rows1,columns1);
	mat2 = GenerateMatrix(rows2,columns2);
	result = GenerateMatrix(rows2,columns2,0);

//	unsigned int n = std::thread::hardware_concurrency();
//    std::cout << n << " concurrent threads are supported.\n";

	PrintMatrix(mat1,nextPower);
	PrintMatrix(mat2,nextPower);


	strassen(mat1,mat2,result);

	PrintMatrix(result,nextPower);



}








