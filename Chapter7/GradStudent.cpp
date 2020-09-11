#include <iostream>
#include "GradStudent.hpp"

//Default Constructor
GradStudent::GradStudent() : Student()
{
	StudentDivision = "graduate";
	StudentEnrollment = "full-time";
}

//7.1.4 Total Money Owed
double GradStudent::CalculateTotalMoney()
{
	TotalMoney = GetLibraryFine() + CampusService;
	return TotalMoney;
}
