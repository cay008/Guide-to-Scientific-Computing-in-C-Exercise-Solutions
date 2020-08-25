#include <iostream>
#include <cassert>

double** Multiply(double** A, double** B, int rows_A, int cols_A, int rows_B, int cols_B)
{
	assert(cols_A == rows_B);
	
	double** C;
	C = new double* [rows_A];
	for (int i = 0; i < rows_A; i++)
	{
		C[i] = new double [cols_B];
	}
	
	for (int i = 0; i < rows_A; i++)
	{
		for (int k = 0; k < cols_B; k++)
		{
			for (int j = 0; j < cols_A; j++)
			{
				C[i][k] += A[i][j]*B[j][k];
			}
		}
	}
	
	return C;
}

double** AllocateMatrixMemory(int rows, int cols)
{
	double** A;
	A = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new double [cols];
	}
	
	return A;
}

void FreeMatrixMemory(double**A, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

int main(int argc, char* argv[])
{
	double** A;
	double** B;
	double** C;
	
	int rows_A = 3, cols_A = 4;
	int rows_B = 4, cols_B = 5;
	
	A = AllocateMatrixMemory(rows_A, cols_A);
	B = AllocateMatrixMemory(rows_B, cols_B);
	
	std::cout << "Matrix A: \n";  
	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_A; j++)
		{
			A[i][j] = (double)(i+j);
			std::cout << A[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	std::cout << "Matrix B: \n";
	for (int i = 0; i < rows_B; i++)
	{
		for (int j = 0; j < cols_B; j++)
		{
			B[i][j] = (double)(i+j);
			std::cout << B[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	C = Multiply(A, B, rows_A, cols_A, rows_B, cols_B);
	
	int rows_C = rows_A, cols_C = cols_B;
	
	std::cout << "Prodcut of A and B: \n"; 
	for (int i = 0; i < rows_C; i++)
	{
		for (int j = 0; j < cols_C; j++)
		{
			std::cout << C[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	FreeMatrixMemory(A, rows_A);
	FreeMatrixMemory(B, rows_B);
	FreeMatrixMemory(C, rows_C);
	return 0;
}