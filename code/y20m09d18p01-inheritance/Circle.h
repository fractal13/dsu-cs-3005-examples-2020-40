#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Point.h"

class Circle : public Point {
public:
  Circle(); // default constructor, r=0,x=0,y=0
  Circle(double x, double y, double r);

  // from the origin
  double distance() const;

protected:
  double mRadius;
  
};


#endif /* _CIRCLE_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
