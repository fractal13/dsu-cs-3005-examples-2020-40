#include <iostream>
#include "fibonacci.h"

int main() {
  int n;
  int f;

  std::cout << "N? ";
  std::cin >> n;
  
  f = fibonacci(n);

  std::cout << "fib(" << n << ") = " << f << std::endl;
  
  return 0;
}
