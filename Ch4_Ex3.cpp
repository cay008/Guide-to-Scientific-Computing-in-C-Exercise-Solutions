#include <iostream>
int main(int argc, char* argv[])
{
	for (int j = 0; j < 1e9; j++)
	{
		double* A;
		double* B;
		
		A = new double [3];
		B = new double [3];
		
		for (int i = 0; i < 3; i++)
		{
			A[i] = (double)(i);
			B[i] = 2.0*A[i];
		}
		
		double A_dot_B;
		for (int i = 0; i < 3; i++)
		{
			A_dot_B += A[i]*B[i];
		}
		
		delete[] A;
		delete[] B;
	}
	
	return 0;
}
