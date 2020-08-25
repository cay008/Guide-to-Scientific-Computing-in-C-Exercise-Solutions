#include <iostream>

void SwapNumbers_Pointers(double* p_FP1, double* p_FP2)
{
	double temp;
	temp = *p_FP1;
	*p_FP1 = *p_FP2;
	*p_FP2 = temp;
}


int main(int argc, char* argv[])
{
	double* p_FP1;
	double* p_FP2;
	
	p_FP1 = new double;
	p_FP2 = new double;
	
	*p_FP1 = 1.0;
	*p_FP2 = 2.0;
	
	std::cout << *p_FP1 << " " << *p_FP2 << "\n";
	
	SwapNumbers_Pointers(p_FP1, p_FP2);
	
	std::cout << *p_FP1 << " "<< *p_FP2 << "\n";
	
	delete p_FP1, p_FP2;
	return 0;
}