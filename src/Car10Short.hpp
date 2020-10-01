class Car {
 private:
  float speed;
  const float maxSpeed;
  ...

 public:
  float getSpeed() const { return speed; }
  ...
};