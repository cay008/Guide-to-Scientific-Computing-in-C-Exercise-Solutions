#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	int d1 = 34, d2 = 58, d3 = 57, d4 = 32, d5 = 43;
	double car_average;
	
	car_average =  ((double)(d1) + (double)(d2) + (double)(d3) + (double)(d4) + (double)(d5))/5;
	
	std::cout << car_average;

	return 0;
}