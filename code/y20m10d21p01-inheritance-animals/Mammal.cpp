#include "Mammal.h"

Mammal::Mammal(const std::string& color)
  : mFurColor(color) {
  // empty
}

const std::string& Mammal::getColor() const {
  return mFurColor;
}

void Mammal::setColor(const std::string& color) {
  mFurColor = color;
}

