#include <iostream>

int main() {
  std::cout << __FILE__ << ":" << __LINE__ << " Start of main" << std::endl;
  int x = 3;
  //std::cout << "x = " << x << std::endl;
  int y = 4;
  //std::cout << "y = " << y << std::endl;
  int z;
  //std::cout << "z = " << z << std::endl;

  std::cout << __FILE__ << ":" << __LINE__ << " x = " << x << " y = " << y << " z = " << z << std::endl;
  
  z = x * y;
  //std::cout << "z = " << z << std::endl;
  std::cout << __FILE__ << ":" << __LINE__ << " x = " << x << " y = " << y << " z = " << z << std::endl;

  std::cout << x << " + " << y << " = " << z << std::endl;
  
  std::cout << __FILE__ << ":" << __LINE__ << " End of main" << std::endl;
  return 0;
}
