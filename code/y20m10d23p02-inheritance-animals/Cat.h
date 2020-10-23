#ifndef _CAT_H_
#define _CAT_H_

#include "Mammal.h"
#include <string>

class Cat: public Mammal {
public:
  Cat(const std::string& color, double length);
  double getWhiskerLength() const;
  void setWhiskerLength(double length);

  void setColor(const std::string& color);
  
protected:
  double mWhiskerLength;
};

#endif /* _CAT_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
