#ifndef _DOG_H_
#define _DOG_H_

#include "Mammal.h"
#include <string>

class Dog: public Mammal {
public:
  Dog(const std::string& color, int friendliness);
  int getFriendliness() const;
  void setFriendliness(int friendliness);

protected:
  int mFriendliness;
};

#endif /* _DOG_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
