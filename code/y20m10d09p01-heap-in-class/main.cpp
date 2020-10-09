#include "MyVectorOfInt.h"
#include <iostream>

void foo() {
  MyVectorOfInt vi;
  vi.resize(4);
}

void bar() {
  MyVectorOfInt vi;
  vi.setValue(3, 111);
}

int main() {
  foo(); foo(); foo(); foo(); foo(); foo(); foo(); foo(); foo();
  bar();
  int i;
  MyVectorOfInt vi;
  vi.resize(4);

  vi.setValue(0, 13);
  vi.setValue(1, 7);
  vi.setValue(2, 101);
  vi.setValue(3, -101);

  for(i = 0; i < vi.size(); i++) {
    std::cout << i << ": " << vi.getValue(i) << std::endl;
  }
  
  return 0;
}
