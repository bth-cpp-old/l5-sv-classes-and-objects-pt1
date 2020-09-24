#include <string>

class Car {
  private:
    std::string makeAndModel;
	float maxSpeed;
	float speed;
  
	void sanityCheckSpeed(){
		if (speed < 0) speed = 0.0f;
		if (speed > maxSpeed) speed = maxSpeed;
	}
  public:
	Car() : speed(0.0f), maxSpeed(100){}
    Car(float maxSpeed) : Car() {
        if (maxSpeed > 240) maxSpeed = 240;
        if (maxSpeed < 0) maxSpeed = 100;
    }
    Car(float maxSpeed, std::string makeAndModel) : Car(maxSpeed), makeAndModel(makeAndModel){}
	void accelerate(float pedalFactor){
		speed += 10 * pedalFactor;
		sanityCheckSpeed();
	}
	void applyBreak(float pedalFactor){
		speed -= 10 * pedalFactor;
		sanityCheckSpeed();
	}
};

int main(){
    Car minVolvo242Gl(120);
    
    minVolvo242Gl.accelerate(1.0f); // Full gas!
    minVolvo242Gl.accelerate(1.0f); // Bra drag!
    minVolvo242Gl.accelerate(1.0f); // Nu börjar det gå lite fort!
    minVolvo242Gl.applyBreak(42.0f); // Rådjur!!!
    minVolvo242Gl.applyBreak(1.0f); // Puh!!! Vi överlevde!
}