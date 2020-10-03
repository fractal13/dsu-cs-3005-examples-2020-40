#include <iostream>

// global variable (can be seen anywhere), stored in the static section of memory
int g_evil = 666;

// this is OK.
const int g_good = 777;

int square(int x) {
  // variables x and s have space automatically allocated on the stack
  int s = x * x * g_evil;
  return s;
  // variables x and s's space on the stack is automatically removed
}

int circle(int x) {
  //g_good = 666; // compiler error because g_good is const.
  g_evil = 777;
  return x + g_evil;
}

int main() {
  // variable a has space automatically allocated on the stack
  int a = 3;

  a = circle(a);
  
  a = square(a);
  //std::cout << s << std::endl; // fails, because of scope of s is in square() only
  std::cout << a << std::endl;
  std::cout << g_evil << std::endl;

  return 0;
  // variable a's space on the stack is automatically removed
}
