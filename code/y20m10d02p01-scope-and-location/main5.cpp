#include <iostream>


int how_many() {
  static int count = 0;
  count += 1;
  return count;
}

int square(int x) {
  // variables x and s have space automatically allocated on the stack
  int s = x * x;
  return s;
  // variables x and s's space on the stack is automatically removed
}

int main() {
  // variable a has space automatically allocated on the stack
  int a = 3;

  a = square(a);
  //std::cout << s << std::endl; // fails, because of scope of s is in square() only
  std::cout << a << std::endl;

  int i;
  int j;
  for(i = 0; i < 40; i += 3) {
    j = how_many();
    std::cout << "i: " << i << " j: " << j << std::endl;
  }

  return 0;
  // variable a's space on the stack is automatically removed
}
