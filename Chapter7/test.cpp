#include <iostream>
#include "Student.hpp"
#include "GradStudent.hpp"
#include "PhDStudent.hpp"

int main(int argc, char* argv[])
{
	Student* p_student1 = new Student;
	Student* p_student2 = new GradStudent;
	Student* p_student3 = new PhDStudent;
	
	p_student1 -> TuitionFee = 10000;
	p_student1 -> CampusService = 3000;
	p_student1 -> SetLibraryFine(400);
	
	p_student2 -> TuitionFee = 10000;
	p_student2 -> CampusService = 3000;
	p_student2 -> SetLibraryFine(400);
	
	p_student3 -> TuitionFee = 10000;
	p_student3 -> CampusService = 3000;
	p_student3 -> SetLibraryFine(400);
	
	std::cout << "Total Free of the Undergraduate Student: " << (*p_student1).CalculateTotalMoney() << "\n"
		      << "Total Fee of the Graduate Student: " << (*p_student2).CalculateTotalMoney() << "\n"
			  << "Total Fee of the PhD Student: " << (*p_student3).CalculateTotalMoney() << "\n";
			  
	delete p_student1, p_student2, p_student3;
	return 0;
}