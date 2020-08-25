#include <iostream>

int change_integer(int* x);

int main(int argc, char* argv[])
{
	int* x;
	x = new int;
	*x = 2;
	
	std::cout << change_integer(x) << "\n";
	
	
	delete x;
	return 0;
	
}

int change_integer(int* x)

{
	return *x += 1;
}