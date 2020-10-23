#ifndef _MAMMAL_H_
#define _MAMMAL_H_
#include <string>

class Mammal {
public:
  Mammal(const std::string& color);
  const std::string& getColor() const;
  void setColor(const std::string& color);
  
protected:
  std::string mFurColor;

};

#endif /* _MAMMAL_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
