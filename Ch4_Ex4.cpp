#include <iostream>

int main(int argc, char* argv[])
{
	for (int k = 0; k < 1e9; k++)
	{
		double** A;
		double** B;
		double** C;
		
		int rows = 2, cols = 2;
		
		A = new double* [rows];
		B = new double* [rows];
		C = new double* [rows];
		
		for (int i = 0; i < rows; i++)
		{
			A[i] = new double [cols];
			B[i] = new double [cols];
			C[i] = new double [cols];	
		}
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				A[i][j] = (double)(j);
				B[i][j] = (double)(i);
				C[i][j] = A[i][j] + B[i][j];
			}
		}
		
		for (int i = 0; i < rows; i++)
		{
			delete[] A[i];
			delete[] B[i];
			delete[] C[i];
		}
		delete[] A;
		delete[] B;
		delete[] C;
	}
	
	return 0;
}