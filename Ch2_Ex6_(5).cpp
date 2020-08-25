#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
  double x_previous = 100.0;
  double x_next = 0.0;
  double f_x, f_x_prime, diff;
  double eps = 1.0e-16;
  diff = x_next - x_previous;
  std::cout << "x_previous      x_next \n" ;
 while (fabs(diff) >= eps)
 {
   x_previous = x_next;
   f_x = exp(x_previous) + pow(x_previous,3.0) - 5.0;
   f_x_prime = exp(x_previous) + 3.0*pow(x_previous,2.0);
   x_next = x_previous - f_x / f_x_prime;
   diff = x_next - x_previous;
   std::cout << x_previous << "          " << x_next << "\n";
   std::cout << "Difference between iterations: " << fabs(diff) << "\n";
 }
 std::cout << "------------------------------------------------------- \n";
 std::cout << "Value of f(x):" << exp(x_next) + pow(x_next, 3.0) - 5 << "\n";
 return 0;
}