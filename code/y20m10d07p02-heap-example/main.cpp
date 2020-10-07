#include <iostream>

int *allocate_space(int count) {
  int *p = 0;
  p = new int[count];
  return p;
}

void deallocate_space(int *p) {
  delete [] p;
}

void assign_cubes(int *p, int count) {
  int i;
  for(i = 0; i < count; i++) {
    p[i] = i*i*i;
  }
}

void show_cubes(int *p, int count) {
  int i;
  for(i = 0; i < count; i++) {
    std::cout << i << " " << p[i] << std::endl;
  }
}

int main() {
  int *p = 0;
  p = allocate_space(10);
  assign_cubes(p, 10);
  show_cubes(p, 10);
  deallocate_space(p);
  p = 0;
  return 0;
}
