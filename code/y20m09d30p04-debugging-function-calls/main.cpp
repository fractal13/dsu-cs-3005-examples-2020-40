#include <iostream>

int calculate(int a, int b) {
  return a * b;
}

int main() {
  int x = 3;
  int y = 4;
  int z;

  z = calculate(x, y);

  std::cout << x << " + " << y << " = " << z << std::endl;
  
  return 0;
}
