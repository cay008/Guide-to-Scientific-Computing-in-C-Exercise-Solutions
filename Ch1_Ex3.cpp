#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	double array1[3] = {1.0, 2.0, 3.0}, array2[3] = {3.0, 2.0, 1.0};
	double Scalar_Product, Euclidean_Norm1, Euclidean_Norm2 ;
	
	Scalar_Product = array1[0]*array2[0] + array1[1]*array2[1] + array1[2]*array2[2];
	Euclidean_Norm1 = pow(pow(array1[0],2) + pow(array1[1], 2) + pow(array1[2], 2) ,0.5);
	Euclidean_Norm2 = pow(pow(array2[0],2) + pow(array2[1], 2) + pow(array2[2], 2) ,0.5);
	
	std::cout << "Inner Product is " << Scalar_Product << "\n";
	std::cout << "Euclidean Norm of array1 is " << Euclidean_Norm1 << "\n";
	std::cout << "Euclidean Norm of array2 is " << Euclidean_Norm2 << "\n";
	
	return 0;
}