#include "Cat.h"

Cat::Cat(const std::string& color, double length)
  : Mammal("black"), mWhiskerLength(3.5) {
  setWhiskerLength(length);
  setColor(color);
}

double Cat::getWhiskerLength() const {
  return mWhiskerLength;
}

void Cat::setWhiskerLength(double length) {
  if(length >= 0.0) {
    mWhiskerLength = length;
  }
}

void Cat::setColor(const std::string& color) {
  // || is OR
  // && is AND
  if(color == "tabby" ||
     color == "black" ||
     color == "calico" ||
     color == "white" ||
     color == "orange") {
    Mammal::setColor(color);
  }
}
