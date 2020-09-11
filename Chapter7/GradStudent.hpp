#ifndef GradStudentHeadDef
#define GradStudentHeadDef

#include "Student.hpp"
#include <iostream>

class GradStudent : public Student
{
	public:
	//Default Constructor
	GradStudent();
	//7.1.4 Total Money Owed
	virtual double CalculateTotalMoney();
	//7.1.3 Full Time or Part Time
	std::string StudentEnrollment;
};

#endif