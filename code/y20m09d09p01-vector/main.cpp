#include <vector>
#include <iostream>

int main() {
  // numbers = []
  std::vector<int> numbers;

  // numbers.append(17)
  numbers.push_back(17);

  // print(len(numbers))
  std::cout << numbers.size() << std::endl;
  
  // resize the vector to have room for 100 items
  // for i in range(99): numbers.append(i)
  numbers.resize(100);
  int i;
  for(i = 0; i < 100; i++) {
    numbers[i] = i;
  }

  // print(numbers[50])
  std::cout << numbers[50] << std::endl;

  // print(numbers[len(numbers)-80])
  std::cout << numbers[numbers.size()-80] << std::endl;
  //std::cout << numbers[-80] << std::endl;

  return 0;
}
