#ifndef _POINT_H_
#define _POINT_H_

// class declaration
// header file only
class Point {
public:
  Point(); // default constructor
  Point(double x, double y);

  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);

  // from the origin
  double distance() const;
  
protected:
  double mX;
  double mY;
};
   
#endif /* _POINT_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
