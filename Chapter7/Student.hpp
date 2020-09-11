#ifndef StudentHeadDef
#define StudentHeadDef

class Student
{
	private:
	double LibraryFine;
	
	public:
	Student();
	std::string StudentName;
	//7.1.3 Student Division
	std::string StudentDivision;
	
	double TuitionFee, TotalMoney, CampusService;
	
	//7.1.2 Library Fine
	void SetLibraryFine(int FineAmount);
	double GetLibraryFine();

	//7.1.4
	virtual double CalculateTotalMoney();
};

#endif