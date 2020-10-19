#include <iostream>
#include "factorial.h"

int main() {
  int n;
  int f;

  std::cout << "N? ";
  std::cin >> n;
  
  f = factorial(n);

  std::cout << n << "! = " << f << std::endl;
  
  return 0;
}
