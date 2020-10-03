#include <iostream>

int line(int y) {
  int n = y*y; // 25
  int m = y+y; // 10
  int o = n*m; // 250
  return o;  // if y == 5, then return 250
}

int square(int x) {
  // variables x and s have space automatically allocated on the stack
  // if x == 3
  int t;         // ??
  std::cout << "t is " << t << std::endl;
  int s = x * x; // 9
  s += t;        // 9 + ??
  return s;      // returns 9 + ?? if x == 3
  // variables x and s's space on the stack is automatically removed
}

int main() {
  // variable a has space automatically allocated on the stack
  int a = 3;
  int b = 5;
  int c;

  c = line(b);
  std::cout << "c: " << c << std::endl;
  a = square(a);
  //std::cout << s << std::endl; // fails, because of scope of s is in square() only
  std::cout << "a: " << a << std::endl;

  return 0;
  // variable a's space on the stack is automatically removed
}
