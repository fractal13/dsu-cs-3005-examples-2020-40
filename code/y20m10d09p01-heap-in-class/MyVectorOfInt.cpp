#include "MyVectorOfInt.h"
#include <iostream>

MyVectorOfInt::MyVectorOfInt() 
  : mData(0), mSize(0) {
}

MyVectorOfInt::~MyVectorOfInt() {
  if(mData != 0) {
    //std::cout << "deleting: " << mData << std::endl;
    delete [] mData;
    mData = 0;
  }
}

void MyVectorOfInt::resize(const int& new_size) {
  mData = new int[new_size];
  mSize = new_size;
}

int MyVectorOfInt::size() const {
  return mSize;
}

const int& MyVectorOfInt::getValue(const int& index) const {
  return mData[index];
}

const int& MyVectorOfInt::operator[](const int& index) const {
  return mData[index];
}

int& MyVectorOfInt::operator[](const int& index) {
  return mData[index];
}


void MyVectorOfInt::setValue(const int& index, const int& value) {
  if(index >= 0 && index < mSize) {
    mData[index] = value;
  }
}


