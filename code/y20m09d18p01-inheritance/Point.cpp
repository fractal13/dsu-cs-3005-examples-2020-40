#include "Point.h"
#include <cmath>

// Point::Point(double x, double y) {
//   mX = x;
//   mY = y;
// }

Point::Point()
  : mX(0.0), mY(0.0) {
}

Point::Point(double x, double y)
  : mX(x), mY(y) {
}

double Point::getX() const {
  return mX;
}

double Point::getY() const {
  return mY;
}

void Point::setX(double x) {
  mX = x;
}

void Point::setY(double y) {
  mY = y;
}

double Point::distance() const {
  return std::sqrt(mX * mX + mY * mY);
}
