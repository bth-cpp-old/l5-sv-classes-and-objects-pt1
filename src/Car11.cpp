#include "Car.hpp"

void Car::sanityCheckSpeed() {
  if (speed < 0) speed = 0.0f;
  if (speed > maxSpeed) speed = maxSpeed;
}

void Car::accelerate(float pedalFactor) {
  speed += 10 * pedalFactor;
  sanityCheckSpeed();
}

void Car::applyBreak(float pedalFactor) {
  speed -= 10 * pedalFactor;
  sanityCheckSpeed();
}

float Car::getSpeed() const { return speed; }