#include "Dog.h"
#include "Cat.h"
#include <iostream>

int main() {
  Dog clifford("red", 10);
  Dog snoopy("white/black", 8);
  Dog bad_dog("gray", -1);
  Cat garfield("orange", 6.3);
  Cat bill("orange", -0.2);

  std::cout << "Clifford " << clifford.getColor() << std::endl;
  std::cout << "Bill " << bill.getColor() << std::endl;
  std::cout << "Bill whisker " << bill.getWhiskerLength() << std::endl;
  bill.setWhiskerLength(0.4);
  bill.setWhiskerLength(-1.0);

  snoopy.setColor("rainbow"); // Mammal::setColor()
  bill.setColor("rainbow"); // Cat::setColor()
  std::cout << "Snoopy " << snoopy.getColor() << std::endl;

  std::cout << "Bill whisker " << bill.getWhiskerLength() << std::endl;
  std::cout << "Bill " << bill.getColor() << std::endl;
  
  return 0;
}
