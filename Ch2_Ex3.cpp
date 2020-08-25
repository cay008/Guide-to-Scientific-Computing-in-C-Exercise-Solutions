#include <iostream>
int main(int argc, char* argv[])
{
	int num = 0, sum_num = 0;
	while (num != -1)
	{
		if (num != -2)
		{
			std::cout << "Input an integer ";
			std::cin >> num;
			std::cout << "\n";
			if (num != -1)
			{
				sum_num += num;
				if (sum_num > 100)
				{
					std::cout << "Brekas down due to sum of these numbers exceeds 100" << "\n";
					break;
				}
			}
			std::cout << "sum of these integers " << sum_num << "\n";
		}
		else
		{
			sum_num = 0; num=0;
			std::cout << "Sun of these integers has been reset to " << sum_num << "\n";
		}

	}
	std::cout << sum_num;
	return 0;
}