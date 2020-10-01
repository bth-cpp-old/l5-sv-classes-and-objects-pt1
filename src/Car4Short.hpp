class Car {
 private:
  float speed;
  float maxSpeed;
  ...

 public:
  Car(float maxSpeed) {
    speed = 0.0f;
    this->maxSpeed = maxSpeed;
  }
  ...
  };