#include "Point.h"
#include <iostream>

int main() {
  // type variable(parameters, to, constructor);
  Point p1(1.2, 4.5);
  Point p2;

  std::cout << p1.getX() << "," << p1.getY()
            << std::endl;

  p1.setX(-423.1);
  p1.setY(821.4);

  std::cout << p1.getX() << "," << p1.getY()
            << std::endl;
  
  return 0;
}
