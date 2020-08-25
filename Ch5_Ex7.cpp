#include <iostream>
#include <cmath>

double CalculateNorm(double* u, int length_u, int p = 2)
{
	double sum = 0.0;
	
	for (int i = 0; i < length_u; i++)
	{
		sum += pow(fabs(u[i]), p);
	}
	
	return pow(sum, 1.0 / p);
}

int main(int argc, char* argv[])
{
	double* u = new double [3];
	int length_u = 3;
	u[0] = 1.0; u[1] = 2.0; u[2] = 3.0;
	
	double Norm_2, Norm_4;
	std::cout << "2 Norm of u is: \n";
	Norm_2 = CalculateNorm(u, length_u);
	std::cout << Norm_2 << "\n";
	std::cout << "4 Norm of u is: \n";
	Norm_4 = CalculateNorm(u, length_u, 4);
	std::cout << Norm_4 << "\n";
	
	delete[] u;
	return 0;
}