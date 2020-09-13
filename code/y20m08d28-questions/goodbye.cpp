#include <iostream>
#include "goodbye.h"

int see_ya(int count) {
  int i;
  for(i = 0; i < count; i++) {
    std::cout << "Adios!" << std::endl;
  }
  return 0;
}
