Q2.6.1 to Q2.6.4
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  double x = 0.0;
  double f_x, f_x_prime;
  double eps = 1.0e-12;
 for (int i = 0; i < 100; i++)
 {
   f_x = exp(x) + pow(x,3) - 5;
   f_x_prime = exp(x) + 3*pow(x,2);
   x -= f_x / f_x_prime;
   std::cout << "Value of x: " << x << "\n";
   f_x = exp(x) + pow(x,3) - 5;
   std::cout << "Value of f_x: " << f_x << "\n";
 }
 return 0;
}
