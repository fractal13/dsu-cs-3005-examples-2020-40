#include "Cat.h"

Cat::Cat(const std::string& color, double length)
  : Mammal(color), mWhiskerLength(3.5) {
  setWhiskerLength(length);
}

double Cat::getWhiskerLength() const {
  return mWhiskerLength;
}

void Cat::setWhiskerLength(double length) {
  if(length >= 0.0) {
    mWhiskerLength = length;
  }
}
