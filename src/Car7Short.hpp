class Car {
  private:
    std::string makeAndModel
	float maxSpeed;
	float speed;
	...
  public:
	Car() : speed(0.0f), maxSpeed(100){}
    Car(float maxSpeed) : speed(0.0f){
        if (maxSpeed > 240) maxSpeed = 240;
        if (maxSpeed < 0) maxSpeed = 100;
    }
    Car(float maxSpeed, std::string makeAndModel)
		: speed(0.0f), makeAndModel(makeAndModel){
        if (maxSpeed > 240) maxSpeed = 240;
        if (maxSpeed < 0) maxSpeed = 100;
    }
};