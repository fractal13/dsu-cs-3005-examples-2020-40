class X {
public:
  X(int& original);
protected:
  int  value;
  int& reference;
};

X::X(int& original)
  : value(1), reference(original) {
}
