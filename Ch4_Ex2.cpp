#include <iostream>

int main(int argc, char* argv[])
{
	int i = 1, j = 2;
	int* p_i;
	int* p_j;
	
	p_i = new int; 
	p_j = new int;
	
	*p_i = i;
	*p_j = j;
	
	i = *p_j;
	j = *p_i;
	
	std::cout << i << " " << j << "\n";
	
	delete p_i, p_j;
	return 0;
}