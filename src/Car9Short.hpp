class Car {
 private:
  float speed;
  const float maxSpeed;
  ...

 public:
  Car(const float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed){}
  ...
};