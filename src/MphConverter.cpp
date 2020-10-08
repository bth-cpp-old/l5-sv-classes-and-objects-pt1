#include <iostream>

class MphConverter {
  private:
	static float mphToKmhFactor;

  public:
	static float toKmh(float mph){
		return mph*mphToKmhFactor;
	}
};

float MphConverter::mphToKmhFactor = 1.60934;

int main(){
	std::cout<<"60 mph is "<<MphConverter::toKmh(60)<<" Kmh";
}