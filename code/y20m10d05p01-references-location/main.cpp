#include <iostream>
class BagOfReference {
public:
  BagOfReference(int& data);
  void add(const int v);
  int& getData();

protected:
  int& mData;
};

BagOfReference::BagOfReference(int& data)
  : mData(data) {
  // mData = data; BAD
}

void BagOfReference::add(const int v) {
  mData += v;
}

int& BagOfReference::getData() {
  return mData;
}

int main() {
  int x = 0;
  BagOfReference bag(x);

  bag.add(3);

  std::cout << "x: " << x << std::endl;
  std::cout << "bag.mData: " << bag.getData() << std::endl;

  bag.getData() = 13;
  std::cout << std::endl;
  
  std::cout << "x: " << x << std::endl;
  std::cout << "bag.mData: " << bag.getData() << std::endl;

  bag.getData() -= 6;
  std::cout << std::endl;
  
  std::cout << "x: " << x << std::endl;
  std::cout << "bag.mData: " << bag.getData() << std::endl;

  return 0;
}
