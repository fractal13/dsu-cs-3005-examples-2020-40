#include <iostream>

int fibonacci(int n) {
  std::cout << "fibonacci(" << n << ")" << std::endl;
  int f;
  if(n <= 2) {
    f = 1;
  } else {
    f = fibonacci(n-1) + fibonacci(n-2);
  }
  std::cout << "fibonacci(" << n << ") = " << f << std::endl;
  return f;
}
