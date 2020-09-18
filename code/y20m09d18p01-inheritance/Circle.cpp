#include "Circle.h"
#include <cmath>

Circle::Circle()
  : Point(), mRadius(0.0) {
}

Circle::Circle(double x, double y, double r)
  : Point(x, y), mRadius(r) {
}

double Circle::distance() const {
  //return std::sqrt(mX * mX + mY * mY) - mRadius;
  return Point::distance() - mRadius;
}
