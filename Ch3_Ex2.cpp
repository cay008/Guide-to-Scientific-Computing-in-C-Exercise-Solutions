#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[])
{
	std::ifstream read_file("x_and_y.dat");
	if (!read_file.is_open())
	{
		return 1;
	}
	int number_of_rows = 0;
	while (!read_file.eof())
	{
		double d1, d2, d3, d4;
		read_file >> d1 >> d2 >> d3 >> d4;
		std::cout << d1 << " " << d2 << " " << d3 << " " << d4 << "\n";
		std::cout << read_file.fail() << "\n";
		if (!read_file.fail())
		{
			number_of_rows++;
		}
	}
	std::cout << "Number of rows = " << number_of_rows << "\n";
	read_file.close();
	return 0;
}