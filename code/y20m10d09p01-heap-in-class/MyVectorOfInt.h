#ifndef _MYVECTOROFINT_H_
#define _MYVECTOROFINT_H_

class MyVectorOfInt {
public:
  // create vector with 0 capacity
  MyVectorOfInt();
  // clean up any allocated heap memory
  ~MyVectorOfInt(); // destructor

  // change the size of the vector to new_size capacity
  void resize(const int& new_size);

  // returns the current capacity
  int size() const;

  // fetch a value
  const int& getValue(const int& index) const;
  
  // set a value
  void setValue(const int& index, const int& value);
  
protected:
  int *mData;
  int mSize;
  
};

#endif /* _MYVECTOROFINT_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
