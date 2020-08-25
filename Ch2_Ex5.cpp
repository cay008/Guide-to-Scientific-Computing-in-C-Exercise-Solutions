#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
  double A[2][2] = {{4, 10}, {1, 1}};
  double A_inv[2][2] = {{A[1][1], -A[0][1]}, {-A[1][0], A[0][0]}};
  double A_det =A[0][0]*A[1][1] - A[0][1]*A[1][0];

  assert(A_det != 0.0);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      A_inv[i][j] *= 1 / A_det;
      std::cout << A_inv[i][j] << " ";
    }
    std::cout << "\n";
  }
  return 0;
}