#ifndef PhDStudentHeadDef
#define PhDStudentHeadDef

#include "GradStudent.hpp"
#include <iostream>

class PhDStudent : public GradStudent
{
	public:
	double CalculateTotalMoney();
};

#endif