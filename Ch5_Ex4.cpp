#include <iostream>
#include <cmath>

double CalculateSD(double u[], int N)
{
	double SD = 0.0;
	double Mean = 0.0;
	
	for (int i = 0; i < N; i++)
	{
		Mean += u[i];
	}
	
	Mean = Mean / (double)(N);
	
	for (int i = 0; i < N; i++)
	{
		SD += pow((u[i] - Mean), 2.0);
	}
	
	SD /= (double)(N-1);
	SD = sqrt(SD);
	
	return SD;
}

int main(int argc, char* argv[])
{
	int N = 10;
	double u[N];
	double SD;
	
	
	for (int i = 0; i < N; i++)
	{
		u[i] = i;
		std::cout << i;
	}
	
	std::cout << "\n";
	
	SD = CalculateSD(u, N);
	
	std::cout << SD << "\n";
	
	return 0;
}
