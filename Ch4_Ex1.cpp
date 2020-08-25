#include <iostream>

int main(int argc, char* argv[])
{
	int i = 5;
	int* p_i;
	
	p_i = &i;
	*p_i *= 5;
	
	std::cout << i << "\n";
	
	int* p_k;
	p_k = new int;
	*p_k = *p_i;
	
	std::cout << *p_k << "\n";
	
	delete p_k;
	return 0;
}