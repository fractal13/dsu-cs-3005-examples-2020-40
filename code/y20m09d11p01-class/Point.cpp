#include "Point.h"

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

double Point::getX() {
  return mX;
}

double Point::getY() {
  return mY;
}

void Point::setX(double x) {
  mX = x;
}

void Point::setY(double y) {
  mY = y;
}
