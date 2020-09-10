#include <iostream>
#include "MatrixClass.hpp"

//6.2.1 Default Constructor
Matrix::Matrix()
{
	m_a00 = 0.0;
	m_a01 = 0.0; 
	m_a10 = 0.0;
	m_a11 = 0.0;
}
//6.2.2 Copy Consturctor
Matrix::Matrix(const Matrix& A)
{
	m_a00 = A.m_a00;
	m_a01 = A.m_a01;
	m_a10 = A.m_a10;
	m_a11 = A.m_a11;
}
//6.2.3 Constructor
Matrix::Matrix(double a00, double a01, double a10 ,double a11)
{
	m_a00 = a00;
	m_a01 = a01;
	m_a10 = a10;
	m_a11 = a11;
}
//6.2.4 Determinant
double Matrix::Determinant(const Matrix A) const
{
	return A.m_a00 * A.m_a11 - A.m_a01 * A.m_a10;
}
//6.2.5 Inverse
Matrix Matrix::Inverse(const Matrix A) const
{
	Matrix B;
	double det_A = Determinant(A);
	B.m_a00 = A.m_a11 / det_A;
	B.m_a01 = -A.m_a01 / det_A;
	B.m_a10 = -A.m_a10 / det_A;
	B.m_a11 = A.m_a00  / det_A;
	return B;
}
//6.2.6 Overloading assignment = operator
Matrix& Matrix::operator = (const Matrix& A)
{
	m_a00 = A.m_a00;
	m_a01 = A.m_a01;
	m_a10 = A.m_a10;
	m_a11 = A.m_a11;
}
//6.2.7 Overloading unary - operator
Matrix Matrix::operator - ()
{
	Matrix C;
	C.m_a00 = -m_a00;
	C.m_a01 = -m_a01;
	C.m_a10 = -m_a10;
	C.m_a11 = -m_a11;
	return C;
}
//6.2.8 Overloading binary + and -operator 
Matrix Matrix::operator + (const Matrix& A)
{
	Matrix C;
	C.m_a00 = m_a00 + A.m_a00;
	C.m_a01 = m_a01 + A.m_a01;
	C.m_a10 = m_a10 + A.m_a10;
	C.m_a11 = m_a11 + A.m_a11;
	return C;
}
Matrix Matrix::operator - (const Matrix& A)
{
	Matrix C;
	C.m_a00 = m_a00 - A.m_a00;
	C.m_a01 = m_a01 - A.m_a01;
	C.m_a10 = m_a10 - A.m_a10;
	C.m_a11 = m_a11 - A.m_a11;
	return C;
}
//6.2.9 Matrix Scalar Multiplication
Matrix Matrix::ScalarMatrixMultiplication(double x, Matrix A)
{
	Matrix B;
	B.m_a00 = x * A.m_a00;
	B.m_a01 = x * A.m_a01;
	B.m_a10 = x * A.m_a10;
	B.m_a11 = x * A.m_a11;
	return B;
}

/*---------------------------------------------------------------*/
std::ostream& operator << (std::ostream& output, const Matrix& A)
{
	output << A.m_a00 << " " << A.m_a01 << "\n" << A.m_a10 << " " << A.m_a11 << "\n";
}
















