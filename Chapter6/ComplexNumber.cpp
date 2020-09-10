#include "ComplexNumber.hpp"
#include <cmath>

ComplexNumber::ComplexNumber()
{
	mRealPart = 0.0;
	mImagPart = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y)
{
	mRealPart = x;
	mImagPart = y;
}

double ComplexNumber::CalculateModulus() const
{
	return sqrt( pow(mRealPart, 2) + pow(mImagPart, 2) );
}

double ComplexNumber::CalculateArgument() const
{
	return atan2(mImagPart, mRealPart);
}

ComplexNumber ComplexNumber::CalculatePower(double n) const
{
	ComplexNumber z;
	if (n == 0)
	{
		z.mRealPart = 1.0;
		z.mImagPart = 0.0;
	}
	else
	{
		double modulus = CalculateModulus();
		double argument = CalculateArgument()* n;
		double realpart = pow(argument, n)*cos(argument);
		double imagpart = pow(argument, n)*sin(argument);
		z.mRealPart = realpart;
		z.mImagPart = imagpart;
	}
	return z;
}

//Overloading "=" assignment operator
ComplexNumber& ComplexNumber::operator = (const ComplexNumber& z) //assignment operator is a reference to another instance of the class
{
	mRealPart = z.mRealPart;
	mImagPart = z.mImagPart;
	return *this; //"this" is a pointer to the complex number that is returned
}

//Overloading the unary "-" operator
ComplexNumber ComplexNumber::operator - () const //Original Complex Unchange
{
	ComplexNumber w;
	w.mRealPart = -mRealPart;
	w.mImagPart = -mImagPart;
	return w;
}

//Overloading the binary "+" operator
ComplexNumber ComplexNumber::operator + (const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = mRealPart + z.mRealPart;
	w.mImagPart = mImagPart + z.mImagPart;
	return w;
}

//Overloading the binary "-" operator
ComplexNumber ComplexNumber::operator - (const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = mRealPart - z.mRealPart;
	w.mImagPart = mImagPart - z.mImagPart;
	return w;
}

//Overloading the insertion << operator
//Use "friend" keyword
std::ostream& operator << (std::ostream& output, const ComplexNumber& z)
{
	output << "(" <<z.mRealPart << " ";
	if (z.mImagPart >= 0.0)
	{
		output << "+ " << z.mImagPart << "i)";
	}
	else
	{
		output << "- " << -z.mImagPart << "i)";
	}
}

//6.1.1 Method
double ComplexNumber::GetRealPart() const
{
	return mRealPart;
}

double ComplexNumber::GetImagPart() const
{
	return mImagPart;
}

//6.1.2 Friend Function
double RealPart(const ComplexNumber& objRealPart)
{
	return objRealPart.mRealPart;
}

double ImagPart(const ComplexNumber& objImagPart)
{
	return objImagPart.mImagPart;
}

//6.1.3 Overridden Copy Constructor
ComplexNumber::ComplexNumber(const ComplexNumber& otherComplexNumber)
{
	mRealPart = otherComplexNumber.GetRealPart();
	mImagPart = otherComplexNumber.GetImagPart();
}

//6.1.4 Specified Constructor
ComplexNumber::ComplexNumber(double real_input)
{
	mRealPart = real_input;
	mImagPart = 0.0;
}

//6.1.5 CalculateConjugate
ComplexNumber ComplexNumber::CalculateConjugate() const
{
	return ComplexNumber(mRealPart, -mImagPart);
}

//6.1.6 SetConjugate
ComplexNumber ComplexNumber::SetConjugate()
{
	ComplexNumber z(mRealPart, -mImagPart);
	mImagPart = z.GetImagPart();
}

//6.1.7
//Overloadig binary "*" operator
ComplexNumber ComplexNumber::operator * (const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = mRealPart * z.mRealPart - mImagPart * z.mImagPart;
	w.mImagPart = mRealPart * z.mImagPart + mImagPart * z.mRealPart;
	return w;
}
//Overloading binary "/" operator
ComplexNumber ComplexNumber::operator / (const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = (mRealPart * z.mRealPart + mImagPart * z.mImagPart) / (z.mRealPart * z.mRealPart + z.mImagPart * z.mImagPart);
	w.mImagPart = (z.mRealPart * mImagPart - mRealPart * z.mImagPart) / (z.mRealPart * z.mRealPart + z.mImagPart * z.mImagPart);
	return w;
}















