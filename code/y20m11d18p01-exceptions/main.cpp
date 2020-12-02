#include <iostream>
#include <vector>
#include <stdexcept>

void fred(std::vector<int>& nums) {
  unsigned int i;
  for(i = 0; i <= nums.size(); i++) {
    std::cout << nums.at(i) << std::endl;
  }
  std::cout << "Loop ended normally." << std::endl;
}

int main() {
  std::vector<int> nums(5, -1);
  unsigned int i;

  // for(i = 0; i <= nums.size(); i++) {
  //   std::cout << nums[i] << std::endl;
  // }
  
  // std::cout << std::endl;

  // for(i = 0; i <= nums.size(); i++) {
  //   try {
  //     std::cout << nums.at(i) << std::endl;
  //   } catch(std::out_of_range& e) {
  //     std::cout << "i = " << i << " is out of range for vector of size " << nums.size() << "." << std::endl;
  //     std::cout << "What: " << e.what() << std::endl;
  //   }
  // }

  try {
    fred(nums);
  } catch(std::out_of_range& e) {
    std::cout << "Out of range for vector of size " << nums.size() << "." << std::endl;
    std::cout << "What: " << e.what() << std::endl;
  }

  std::cout << std::endl;
  std::cout << "That's all folks." << std::endl;

  return 0;
}
