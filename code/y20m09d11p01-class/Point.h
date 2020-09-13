
// class declaration
// header file only
class Point {
public:
  Point(); // default constructor
  Point(double x, double y);

  double getX();
  double getY();
  void setX(double x);
  void setY(double y);
  
protected:
  double mX;
  double mY;
};
   
