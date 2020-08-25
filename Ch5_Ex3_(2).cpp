#include <iostream>

void SwapNumbers_References(double& FP1, double& FP2)
{
	double temp;
	temp = FP1;
	FP1 = FP2;
	FP2 = temp;
}

int main(int argc, char* argv[])
{
	double FP1 = 1.0, FP2 = 2.0;
	
	std::cout << FP1 << " " << FP2 << "\n";
	
	SwapNumbers_References(FP1, FP2);
	
	std::cout << FP1 << " " << FP2 << "\n";
	
	return 0;
}