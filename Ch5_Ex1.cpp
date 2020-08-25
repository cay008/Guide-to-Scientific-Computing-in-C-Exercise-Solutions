#include <iostream>

int value_of_integer(int* x);

int main(int argc, char* argv[])
{
	int* p_x;
	p_x = new int; 
	*p_x = 2;
	std::cout << "Value of the integer is: " << value_of_integer(p_x) << "\n";
	return 0;
}

int value_of_integer(int* x)
{
	return *x;
}