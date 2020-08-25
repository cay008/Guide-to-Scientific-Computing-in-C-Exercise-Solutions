#include <iostream>
#include <cassert>

double** AllocateMatrixMemory(int rows, int cols)
{
	double** A = new double* [rows];
	
	for (int i = 0; i < rows; i++)
	{
		A[i] = new double [cols];
	}
	
	return A;
}


double* Multiply(double**A, double* u, int rows_A, int cols_A, int length_u)
{
	assert(cols_A == length_u );
	
	int length_v = rows_A;
	double* v = new double [length_v];
	
	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_A; j++)
		{
			v[i] += A[i][j]*u[j];
		}
	}
	
	return v;
}


double* Multiply(double* u, double** A, int length_u, int rows_A, int cols_A)
{
	assert(length_u == rows_A);
	
	int length_v = cols_A;
	double* v = new double [length_v];
	
	for (int j = 0; j < length_v; j++)
	{
		for (int i = 0; i < rows_A; i++)
		{
			v[j] += u[i]*A[i][j];
		}
	}
	
	return v;
}

double** Multiply(double x, double** A, int rows_A, int cols_A)
{
	double** B = AllocateMatrixMemory(rows_A, cols_A);
	
	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_A; j++)
		{
			B[i][j] = x*A[i][j];
		}
	}
	
	return B;
}

double** Multiply(double**A, double x, int rows_A, int cols_A)
{
	double** B = AllocateMatrixMemory(rows_A, cols_A);
	
	for (int i = 0; i < rows_A; i++)
	{
		for (int j = 0; j < cols_A; j++)
		{
			B[i][j] = A[i][j]*x;
		}
	}
	
	return B;
}

void FreeMatrixMemory(double** A, int rows_A)
{
	for (int i = 0; i < rows_A; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

int main(int argc, char* argv[])
{
	double x = 2.0;
	
	int length = 2;
	double* u = new double [length];
	u[0] = 2.0; u[1] = 2.0;
	double* v;
	
	int rows = 2, cols = 2;
	double** A = AllocateMatrixMemory(rows, cols);
	A[0][0] = 1.0; A[0][1] = 2.0; A[1][0] = 2.0; A[1][1] = 1.0;
	double** B = AllocateMatrixMemory(rows, cols);
	
	v = Multiply(u, A, length, rows, cols);
	std::cout << "Product Between Vector u and Matrix A is: \n";
	for (int i = 0; i < cols; i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
	
	B = Multiply(A, x, rows, cols);
	std::cout << "Product Between Matrix A and Scalar x is: \n";
	for (int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			std::cout << B[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	delete[] v;
	FreeMatrixMemory(B, rows);
	return 0;
}
