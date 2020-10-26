#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include <vector>

void function2() {
  std::vector<Mammal> animals;

  // Dog uses Mammal::setColor()
  Dog dog1("blue", 9);
  dog1.setColor("purple");

  // Cat uses Cat::setColor()
  Cat cat1("blue", 1.2);
  cat1.setColor("purple");

  animals.push_back(dog1);
  animals.push_back(cat1);

  std::vector<Mammal>::iterator animal;
  for(animal = animals.begin(); animal != animals.end(); animal++) {
    animal->setColor("pink");
    std::cout << "Animal: " << animal->getColor() << std::endl;
  }
  
}

void function3() {
  std::cout << "Function 3" << std::endl;
  std::vector<Mammal *> animals;

  // Dog uses Mammal::setColor()
  Dog dog1("blue", 9);
  dog1.setColor("purple");

  // Cat uses Cat::setColor()
  Cat cat1("blue", 1.2);
  cat1.setColor("purple");

  animals.push_back(&dog1);
  animals.push_back(&cat1);

  std::vector<Mammal *>::iterator animal;
  for(animal = animals.begin(); animal != animals.end(); animal++) {
    (*animal)->setColor("pink"); // compiler sees Mammal::setColor()
    std::cout << "Animal: " << (*animal)->getColor() << std::endl;
  }
  
  unsigned int i;
  for(i = 0; i < animals.size(); i++) {
    animals[i]->setColor("green"); // compiler sees Mammal::setColor()
    std::cout << "Animal: " << animals[i]->getColor() << std::endl;
  }
  
}

int main() {
  // // Dog uses Mammal::setColor()
  // Dog dog1("blue", 9);
  // dog1.setColor("purple");

  // // Cat uses Cat::setColor()
  // Cat cat1("blue", 1.2);
  // cat1.setColor("purple");

  // // Dog should be purple
  // std::cout << "Dog: " << dog1.getColor() << std::endl;
  // // Cat should be black
  // std::cout << "Cat: " << cat1.getColor() << std::endl;

  //function2();
  
  function3();

  return 0;
}
