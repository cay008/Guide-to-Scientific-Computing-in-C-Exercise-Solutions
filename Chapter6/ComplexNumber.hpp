#ifndef ComplexNumberHeadDef
#define ComplexNumberHeadDef

#include <iostream>

class ComplexNumber
{
	private:
		double mRealPart;
		double mImagPart;
		
	public:
		//Overridden default constructor;
		ComplexNumber();
		//Constructor
		ComplexNumber(double x, double y);
		//Method to calculate modulus of the complex number
		
		//Note that method can access all members of class, there is no needs to
		//specify an input argument of CalculateModulus and CalculateArgument
		
		double CalculateModulus() const;
		//Method to calculate argument of the complex number
		double CalculateArgument() const; 
		//Method to calculate the power of the given complex number. Returns another complex number
		ComplexNumber CalculatePower(double n) const;
		//Overloading assignment operator
		ComplexNumber& operator=(const ComplexNumber& z);
		//Overloading unary operator
		ComplexNumber operator-() const;
		//Overloading binay operator
		ComplexNumber operator+(const ComplexNumber& z) const;
		ComplexNumber operator-(const ComplexNumber& z) const;
		//Overloading stream output
		friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& z);
		
		//6.1.1 Method
		double GetRealPart() const;
		double GetImagPart() const;
		//6.1.2 Friend Function
		friend double RealPart(const ComplexNumber& objRealPart);
		friend double ImagPart(const ComplexNumber& objImagPart);
		//6.1.3 Overridden Copy Constructor
		ComplexNumber(const ComplexNumber& otherComplexNumber);
		//6.1.4 Specified Constructor
		ComplexNumber(double real_input);
		//6.1.5 Method to calculate Complex Conjugate
		ComplexNumber CalculateConjugate() const;
		//6.1.6 SetConjugate
		ComplexNumber SetConjugate();
		//6.1.7 Overloading "*" and "/" operator
		ComplexNumber operator * (const ComplexNumber& z) const;
		ComplexNumber operator / (const ComplexNumber& z) const;
		
};

#endif