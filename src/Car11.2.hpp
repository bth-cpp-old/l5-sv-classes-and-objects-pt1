class Car {
 public:
  Car() : speed(0.0f), maxSpeed(100) {}
  Car(const float maxSpeed) : speed(0.0f), maxSpeed(maxSpeed) {}
  void accelerate(float pedalFactor);
  void applyBreak(float pedalFactor);
  float getSpeed() const;

 private:
  float speed;
  const float maxSpeed;

  void sanityCheckSpeed();
};