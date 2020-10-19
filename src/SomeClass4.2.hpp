#include <iostream>

class SomeClass {
 private:
  float piIsh;

 public:
  SomeClass() = default;
  SomeClass(float customPi) { piIsh = customPi; }
  void print() { std::cout << "pi: " << piIsh << "\n"; }
};