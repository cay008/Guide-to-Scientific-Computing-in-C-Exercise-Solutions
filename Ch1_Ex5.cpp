#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	std::string Given_Name, Family_Name;
	std::cout << "Enter your Given Name";
	
	std::cin >> Given_Name;
	std::cout << "Enter your Family Name";
	
	std::cin >> Family_Name;
	std::cout << Given_Name << " " << Family_Name << "\n";
	
	return 0;
}