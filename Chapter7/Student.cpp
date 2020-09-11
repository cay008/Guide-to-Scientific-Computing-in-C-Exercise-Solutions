#include <iostream>
#include "Student.hpp"

//Default Constructor
Student::Student()
{
	StudentName = "unspecified";
	LibraryFine = 0.0;
	TuitionFee = 0.0;
	TotalMoney = 0.0;
	CampusService = 0.0;
	StudentDivision = "undergraduate";
}

//7.1.2 Library Fine
void Student::SetLibraryFine(int FineAmount)
{
	while (FineAmount < 0)
	{
		std::cout << "Please input an non-negative number" << "\n";
		std::cin >> FineAmount;
	}
	
	LibraryFine = FineAmount;
}

double Student::GetLibraryFine()
{
	return LibraryFine;
}

//7.1.4
double Student::CalculateTotalMoney()
{
	TotalMoney = LibraryFine + TuitionFee + CampusService;
	return TotalMoney;
}


