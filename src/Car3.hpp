class Car {
  private:
	float speed;
	float maxSpeed;
	
	void sanityCheckSpeed(){
		if (speed < 0) speed = 0.0f;
		if (speed > maxSpeed) speed = maxSpeed;
	}
  public:
	Car(){
        speed = 0.0f;
        maxSpeed = 100;
    }
	Car(float p_maxSpeed){
        speed = 0.0f;
        maxSpeed = p_maxSpeed;
    }
	void accelerate(float pedalFactor){
		speed += 10 * pedalFactor;
		sanityCheckSpeed();
	}
	void applyBreak(float pedalFactor){
		speed -= 10 * pedalFactor;
	  	sanityCheckSpeed();
	}
};