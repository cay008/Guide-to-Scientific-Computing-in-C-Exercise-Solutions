#include <iostream>
#include "ComplexNumber.hpp"
//Allocate Memeory for Complex Matrix
ComplexNumber** AllocateComplexMatrix(int rows, int cols)
{
	ComplexNumber** A;
	A = new ComplexNumber* [rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new ComplexNumber [cols];
	}
	return A;
}

//Free Memory for Complex Matrix
void FreeComplexMatrix(ComplexNumber** A, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

//Function of Calculating nth power of a matrix
ComplexNumber** ExpOfComplexMatrix(ComplexNumber** A, int size, int n) 
{
	int rows = size, cols = size;
	ComplexNumber** B = AllocateComplexMatrix(rows, cols);
	B = A;
	ComplexNumber** C = AllocateComplexMatrix(rows, cols);
	double frac_n;

	for (int pow = 0; pow < n + 1; pow++)
	{
		if (pow = 0)
		{
			for (int i = 0; i < rows; i++)
			{
				B[i][i] = 1.0;
			}
		}
		
		else if (pow = 1)
		{
			for (int i = 0; i < rows; i++)
			{
				B[i][i] = B[i][i] + A[i][i];
			}
		}
		
		else
		{
			//Calculate n!
			if (pow == 2)
			{
				frac_n = 2.0;
			}
			else
			{
				frac_n *= pow;
			}
			
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					for (int k = 0; k < cols; k++)
					{
						C[i][j] = C[i][j] + B[i][k]*A[k][j] / ComplexNumber(frac_n, 0.0);
					}
				}
			}
			B = C;
		}
	}
	
	FreeComplexMatrix(C, rows);
	return B;
}

int main(int argc, char* argv[])
{
	//Allocate Memory for Complex Matrix
	int rows = 3, cols = 3;
	ComplexNumber** A = AllocateComplexMatrix(rows, cols);
	
	//Assign this Complex Matrix
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			A[i][j] = ComplexNumber((double)(i), (double)(j));
		}
	}
	
	//Exponential of the Complex Matrix
	int n = 10; //Truncated at n = 100;
	ComplexNumber** exp_A = ExpOfComplexMatrix(A, rows, n);
	
	//Print
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0 ; j < cols; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << exp_A[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	//Free Memory
	FreeComplexMatrix(A, rows);
	FreeComplexMatrix(exp_A, rows);
	return 0;
	
}