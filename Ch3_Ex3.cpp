#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);
	
	double x[N], y[N];
	double h = 1.0 / (N - 1.0);

	y[0] = 1.0;
	
	for (int i = 0; i < N; i++)
	{
		x[i] = i / (N - 1.0);
	}
	
	for (int i = 1; i < N; i++)
	{
		y[i] = y[i - 1]/(1 + h);
	}
	
	
	std::ofstream write_output("xy.dat");
	for (int i = 0; i < N; i++)
	{
		write_output.precision(13);
		write_output << x[i] << " " << y[i] << "\n";
	}
	
	write_output.close();
	return 0;
}