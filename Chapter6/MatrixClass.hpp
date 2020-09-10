#ifndef MatrixHeadDef
#define MatrixHeadDef

class Matrix
{
	private:
	double m_a00, m_a01, m_a10, m_a11;
	
	public:
	//6.2.1 Default Constructor
	Matrix();
	//6.2.2 Copy Constructor
	Matrix(const Matrix& otherMatrix);
	//6.2.3 Constructor
	Matrix(double a00, double a01, double a10, double a11);
	//6.2.4 Determinant
	double Determinant(const Matrix A) const;
	//6.2.5 Inverse
	Matrix Inverse(const Matrix A) const;
	//6.2.6 Overloading assignment = operator
	Matrix& operator = (const Matrix& A);
	//6.2.7 Overloading unary - operator
	Matrix operator - ();
	//6.2.8 Overloading binary + and - operator
	Matrix operator + (const Matrix& A);
	Matrix operator - (const Matrix& A);
	//6.2.9 Method to multiple the matrix by a scalar
	Matrix ScalarMatrixMultiplication(double x, Matrix A);
	
	/*----------------------------------------------------------------------*/
	
	//Overloading stream output
	friend std::ostream& operator << (std::ostream& output, const Matrix& A);
	
};

#endif