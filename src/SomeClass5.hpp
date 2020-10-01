class SomeClass {
 private:
  float piIsh;

 public:
  SomeClass(int customPi) = delete;
  SomeClass(float customPi) { piIsh = customPi; }
};