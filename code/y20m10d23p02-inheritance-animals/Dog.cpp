#include "Dog.h"

Dog::Dog(const std::string& color, int friendliness) 
  : Mammal(color), mFriendliness(10) {
  setFriendliness(friendliness);
}
int Dog::getFriendliness() const {
  return mFriendliness;
}

void Dog::setFriendliness(int friendliness) {
  if(friendliness >= 0 && friendliness <= 10) {
    mFriendliness = friendliness;
  }
}
