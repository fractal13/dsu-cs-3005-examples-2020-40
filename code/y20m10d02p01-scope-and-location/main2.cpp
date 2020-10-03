#include <iostream>

// global variable (can be seen anywhere), stored in the static section of memory
int g_evil = 666;

int square(int x) {
  // variables x and s have space automatically allocated on the stack
  int s = x * x * g_evil;
  return s;
  // variables x and s's space on the stack is automatically removed
}

int main() {
  // variable a has space automatically allocated on the stack
  int a = 3;

  a = square(a);
  //std::cout << s << std::endl; // fails, because of scope of s is in square() only
  std::cout << a << std::endl;
  std::cout << g_evil << std::endl;

  return 0;
  // variable a's space on the stack is automatically removed
}
