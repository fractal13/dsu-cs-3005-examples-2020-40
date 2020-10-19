#include <iostream>

int factorial(int n) {
  std::cout << "factorial(" << n << ")" << std::endl;
  int f;
  if(n <= 1) {
    f = 1;
  } else {
    f = n * factorial(n-1);
  }
  std::cout << "factorial(" << n << ") = " << f << std::endl;
  return f;
}
