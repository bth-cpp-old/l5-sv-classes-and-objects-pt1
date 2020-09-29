class Car {
	private:
	float speed;
	const float maxSpeed;
  	...
	Car(float maxSpeed){
		speed = 0.0f;
		this->maxSpeed = maxSpeed;
	}
	...
};