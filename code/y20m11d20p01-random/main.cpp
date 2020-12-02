#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()

int roll_die(int sides) {
  return (std::rand() % sides) + 1;
}


int main() {
  //std::srand(71263567);
  std::srand(std::time(0));

  int d1 = roll_die(6);
  int d2 = roll_die(6);

  std::cout << "Sum: " << d1 + d2 << std::endl;
  
  return 0;
}
